<?php

class gl_budget_ac_line extends dbObject {

 public static $table_name = "gl_budget_ac_line";
 public static $primary_column = "gl_budget_ac_line_id";
 public static $parent_primary_column = "gl_budget_ac_header_id";
 public static $key_column = 'coa_combination_id';
 public static $module = "gl";
 public static $line_action_a = [
		 'PROCESS' => 'Process Line',
		 'CANCEL' => 'Try To Cancel',
 ];
 public $field_a = [
		 'gl_budget_ac_line_id',
		 'gl_budget_ac_header_id',
		 'coa_combination_id',
		 'type',
		 'currency',
		 'description',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $requiredField = [
		 'gl_budget_ac_header_id',
		 'coa_combination_id',
 ];
 public $gl_budget_ac_line_id;
 public $gl_budget_ac_header_id;
 public $coa_combination_id;
 public $type;
 public $currency;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;


 private function _validate_before_save() {
	$ret = 1;
	if ($this->line_status == 'SHIPPED') {
	 $ret = -90;
	 echo "<br> You cant modify any shipped sales order line ";
	}

	if ($ret > 0) {
	 $item = item::find_by_orgId_item_id_m($this->item_id_m, $this->shipping_org_id);
	 if ($item) {
		if (empty($item->customer_ordered_cb)) {
		 $ret = -90;
		 echo "<br> The item is not enabled for Sales ";
		}
	 } else {
		$ret = -90;
		echo "<br> The item is not assigned to the organization";
	 }
	}

	if ($ret > 0) {
	 if (!empty($this->kit_cb) && empty($this->bom_config_header_id)) {
		$ret = -90;
		echo "<br><div class='message'><div class='alert alert-danger'>Sales line is not saved as selected <strong>configured item has no configuration.</strong></div> "
		. "<br>Select configuration & save again.</div>";
	 } else if (empty($this->bom_config_header_id) && !empty($this->kit_cb) && !empty($this->bom_config_header_id)) {
		$this->bom_config_header_id = 1;
	 }
	}


	return $ret;
 }

 public function _before_save() {
	global $dbc;
//  pa($this); 
//  No validaion reqired as per status
	$no_val_as_per_status = false;
	if (!empty($this->line_status) && in_array($this->line_status, self::$line_status_not_to_check_pd)) {
	 $no_val_as_per_status = true;
	}

	if (!empty($this->gl_budget_ac_line_id) && !empty($this->sys_spd_header_id) && ($this->line_action == 'PROCESS') && (!$no_val_as_per_status)) {
	 $sys_spd_details = new sys_spd_header();
	 $sys_spd_details_status = null;
	 $sys_spd_details->findBy_id($this->sys_spd_header_id);
	 if ($sys_spd_details) {
		$all_process_lines = sys_process_flow_line::find_lines_fromStatus_by_headerId($sys_spd_details->process_flow_header_id, $sys_spd_details->status);
		if ($all_process_lines) {
		 foreach ($all_process_lines as $process_line) {
			if (!empty($process_line->class_name)) {
			 $action_cname = $process_line->class_name;
			 $action_mname = $process_line->method_name;
			 if (method_exists($action_cname, $action_mname)) {
				$action_result = call_user_func(array($action_cname, $action_mname), $this);
				if ($action_result == 1) {
				 $sys_spd_details_status = $process_line->line_name;
				} else {
				 $dbc->rollback = 1;
				 break;
				}
			 }
			} else {
			 $sys_spd_details_status = $process_line->line_name;
			}
		 }
		}
	 }
	 if (!empty($sys_spd_details_status) && ($sys_spd_details_status != $sys_spd_details->status)) {
		$sys_spd_details->status = $sys_spd_details_status;
		$sys_spd_details->save();
	 }

	 return 10;
	}

	if ($this->_validate_before_save() < 0) {
	 return -90;
	}

	if (!(empty($this->shipping_org_id)) && (!$no_val_as_per_status)) {
	 if (!(empty($this->item_number))) {
		$item_s = item::find_by_itemNumber_orgId($this->item_number, $this->shipping_org_id);
		$this->item_id_m = $item_s->item_id_m;
	 }
	} else {
	 echo "<br> Saving line data failed!. No shipping organization. Error @ po_line @" . __LINE__;
	 return -99;
	}

	if ((empty($this->line_status)) && (!empty($this->schedule_ship_date))) {
	 $this->line_status = $this->line_quantity < 0 ? 'AWAITING_RETURN' : 'AWAITING_PICKING';
	 echo "<div class='alert alert-info'>Line status is updated to <strong> " . $this->line_status . ".</strong></div> ";
	} else if (($this->line_status = 'ENTERED') && (!empty($this->schedule_ship_date))) {
	 $this->line_status = $this->line_quantity < 0 ? 'AWAITING_RETURN' : 'AWAITING_PICKING';
	} else if ((empty($this->line_status)) && (empty($this->schedule_ship_date))) {
	 $this->line_status = 'ENTERED';
	}

	if ((empty($this->supply_source))) {
	 $this->supply_source = 'INV';
	}
 }

 public function _after_save() {
	if ((!empty($this->line_type)) && empty($this->sys_spd_header_id) && (!empty($this->gl_budget_ac_line_id))) {
	 $line_type_details = sd_document_type::find_by_id($this->line_type);
	 if ($line_type_details && $line_type_details->process_flow_id) {
		$sys_spd = new sys_spd_header();
		$sys_spd->process_flow_header_id = $line_type_details->process_flow_id;
		$sys_spd->primary_document = 'gl_budget_ac_line';
		$sys_spd->primary_document_id = $this->gl_budget_ac_line_id;
		$sys_spd->org_id = $this->shipping_org_id;
		$sys_spd->status = 'Start';
		$sys_spd->originator = $_SESSION['username'];
		$sys_spd->owner_user_id = $_SESSION['user_id'];
		try {
		 $sys_spd->save();
		 $this->sys_spd_header_id = $sys_spd->sys_spd_header_id;
		 $this->save();
		} catch (Exception $e) {
		 echo "<br>Not able to save sys process document.Error @ line " . __LINE__ . ' of file ' . __FILE__ . '<br>' . $e->getMessage();
		}
	 } else {
		$this->sys_spd_header_id = -1;
	 }
	}
 }


 public static function find_by_orgId_itemId_ssd($org_id, $item_id_m = '', $ssd = '') {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE shipping_org_id = '{$org_id}'";
	$sql .= " AND schedule_ship_date IS NOT NULL ";
	if (!empty($item_id_m)) {
	 $sql .= " AND item_id_m = '{$item_id_m}'";
	}
	if (!empty($ssd)) {
	 $sql .= " AND schedule_ship_date >= '{$ssd}'";
	}
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? $result_array : false;
 }

}

//end of gl_budget_ac_line class
?>