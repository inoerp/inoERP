<?php

class wip_wo_header extends dbObject {

 protected static $table_name = "wip_wo_header";
 public static $dependent_classes = ['wip_wo_routing_line', 'wip_wo_routing_detail', 'wip_wo_bom'];
 public static $primary_column = "wip_wo_header_id";
 public static $primary_column2 = "wo_number";
 public static $key_column = 'item_id';
 public static $module = "wip";
//  data base variables as stored database column name
 public $field_a = [
		 'wip_wo_header_id',
		 'item_id',
		 'wo_number',
		 'org_id',
		 'wip_accounting_group_id',
		 'wo_type',
		 'wo_status',
		 'start_date',
		 'completion_date',
		 'quantity',
		 'nettable_quantity',
		 'reference_bom_item_id',
		 'reference_routing_item_id',
		 'bom_exploded_cb',
		 'routing_exploded_cb',
		 'completion_sub_inventory',
		 'completion_locator',
		 'completed_quantity',
		 'scrapped_quantity',
		 'released_date',
		 'first_unit_completed_date',
		 'last_unit_completed_date',
		 'schedule_group',
		 'build_sequence',
		 'line',
		 'scheduling_priority',
		 'closed_date',
		 'ef_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
//variables used for showing data
 public $initial_search = [
		 'wip_wo_header_id',
		 'item_id',
		 'wo_number',
		 'org_id',
		 'wo_type',
		 'start_date',
		 'wo_status'
 ];
 public $column = [
		 'wip_wo_header_id',
		 'item_id',
		 'wo_number',
		 'org_id',
		 'wo_type',
		 'start_date',
		 'wo_status'
 ];
 public $checkbox = [
		 'bom_exploded_cb',
		 'routing_exploded_cb'
 ];
 public $fields_inForm_notInDataBase = [
		 'remaining_quantity',
		 "item_number",
		 "item_description",
		 "uom",
		 'processing_lt'
 ];
 public $requiredField = [
		 'item_id',
		 'org_id',
		 'wip_accounting_group_id',
		 'wo_type',
		 'start_date',
		 'quantity',
		 'nettable_quantity'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
		 '_extra_path' => array('form.php?class_name=wip_move_transaction&mode=9' => 'Move',
				 'form.php?class_name=wip_materail_transaction&mode=9' => 'Material Tnx',
				 'form.php?class_name=wip_resource_transaction&mode=9' => 'Resource Tnx',)
 ];
 public $pageTitle = " WO - WIP Work Order "; //page Title
 public $option_lists = [
		 'wip_wo_type' => 'WIP_WO_TYPE',
		 'wip_wo_status' => 'WIP_WO_STATUS',
 ];
 public $wip_wo_header_id;
 public $item_id;
 public $wo_number;
 public $org_id;
 public $wip_accounting_group_id;
 public $wo_type;
 public $wo_status;
 public $start_date;
 public $released_date;
 public $completion_date;
 public $first_unit_completed_date;
 public $last_unit_completed_date;
 public $quantity;
 public $nettable_quantity;
 public $reference_bom_item_id;
 public $reference_routing_item_id;
 public $bom_exploded_cb;
 public $routing_exploded_cb;
 public $completion_sub_inventory;
 public $completion_locator;
 public $completed_quantity;
 public $scrapped_quantity;
 public $schedule_group;
 public $build_sequence;
 public $line;
 public $scheduling_priority;
 public $closed_date;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $remaining_quantity;
 public $item_number;
 public $item_description;
 public $uom;
 public $processing_lt;

 Public static function wip_wo_type() {
	$option_header = option_header::find_by_name('WIP_WO_TYPE');
	$wo_type = option_line::find_by_option_id($option_header->option_header_id);
	return $wo_type;
 }

 Public static function wip_wo_status() {
	$option_header = option_header::find_by_name('WIP_WO_STATUS');
	$wo_status = option_line::find_by_option_id($option_header->option_header_id);
	return $wo_status;
 }

 Public static function find_by_woNumber($wo_number) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE wo_number = '{$wo_number}' LIMIT 1";

	$result = self::find_by_sql($sql);

	return !empty($result) ? array_shift($result) : false;
 }

 public function _after_save() {
	global $db;
	if ((!empty($this->wip_wo_header_id)) && empty($this->wo_number)) {
	 $wip_wo_header_id = $this->wip_wo_header_id;
	 $org_id = $this->org_id;
	 $wo_number = $org_id . '-' . $wip_wo_header_id;
	 $this->msg = $this->update_woNumber($wip_wo_header_id, $wo_number);
	}

	//copy the BOM
	if ((!empty($this->item_id)) && (empty($this->bom_exploded_cb))) {
	 $wip_wo_header_id1 = $this->wip_wo_header_id;
	 $boh = new bom_header();
	 $boh->item_id = $this->item_id;
	 $boh_i = $boh->findBy_itemId();

	 $bol = new bom_line();
	 $bol->bom_header_id = $boh_i->bom_header_id;
	 $bol_i = $bol->findBy_parentId($bol->bom_header_id);

	 foreach ($bol_i as $bom_line) {
		$wip_wo_bom = new wip_wo_bom();
//		$routing_sequence_value = 10;
		foreach ($wip_wo_bom->field_a as $key => $value) {
		 if (!empty($bom_line->$value)) {
			$wip_wo_bom->$value = $bom_line->$value;
			if ($value == 'routing_sequence') {
			 $routing_of_bom = bom_routing_line::find_by_itemId($this->item_id);
			 foreach ($routing_of_bom as $routing_lines) {
				if ($routing_lines->bom_routing_line_id == $bom_line->$value) {
				 $routing_sequence_value = $routing_lines->routing_sequence;
				}
			 }
			 $wip_wo_bom->$value = $routing_sequence_value;
			}
		 } else {
			$wip_wo_bom->$value = NULL;
		 }
		}
		$wip_wo_bom->required_quantity = $bom_line->usage_quantity * $this->quantity;
		$wip_wo_bom->wip_wo_header_id = $wip_wo_header_id1;
		$wip_wo_bom->audit_trial();
		try {
		 $wip_wo_bom->save();
		 $this->bom_exploded_cb = 1;
		 $this->save();
		 echo "<br> BOM is sucessfully copied";
		} catch (Exception $e) {
		 echo "<br> System failed to copy the BOM!" . __LINE__ . $e->getMessage();
		}
	 }
	}

	//end of Copy BOM
	//copy the Routing
	if ((!empty($this->item_id)) && (empty($this->routing_exploded_cb))) {
	 $wip_wo_header_id2 = $this->wip_wo_header_id;
	 $brh = new bom_routing_header();
	 $brh->item_id = $this->item_id;
	 $brh_i = $brh->findBy_itemId();
	 $brl = new bom_routing_line();
	 $brl_i = $brl->findBy_parentId($brh_i->bom_routing_header_id);

	 $routingSeqCount = 0;
	 foreach ($brl_i as $routing_line) {
		$routing_line_id = $routing_line->bom_routing_line_id;
		$brd = new bom_routing_detail();
		$brd_i = $brd->findBy_parentId($routing_line_id);
		//insert the routing line in WO_Routing_Line
		$wip_wo_routing_line = new wip_wo_routing_line();
		foreach ($wip_wo_routing_line->field_a as $key => $value) {
		 if (!empty($routing_line->$value)) {
			$wip_wo_routing_line->$value = $routing_line->$value;
		 } else {
			$wip_wo_routing_line->$value = NULL;
		 }
		}//end of for line value assignment

		if ($routingSeqCount == 0) {
		 $wip_wo_routing_line->queue_quantity = $this->quantity;
		}
		$routingSeqCount++;
		$wip_wo_routing_line->wip_wo_header_id = $wip_wo_header_id2;
		$wip_wo_routing_line->audit_trial();
		try {
		 $wip_wo_routing_line->save();
		 echo "<br> Routing is sucessfully copied !";
		 foreach ($brd_i as $routing_details) {
			$wip_wo_routing_detail = new wip_wo_routing_detail();
			foreach ($brd->field_a as $key => $value) {
			 if (!empty($routing_details->$value)) {
				$wip_wo_routing_detail->$value = $routing_details->$value;
			 } else {
				$wip_wo_routing_detail->$value = NULL;
			 }
			}//end of for detail line value assignment

			$wip_wo_routing_detail->required_quantity = $this->quantity * $routing_details->resource_usage;
			$wip_wo_routing_detail->wip_wo_header_id = $wip_wo_header_id2;
			$wip_wo_routing_detail->wip_wo_routing_line_id = $wip_wo_routing_line->wip_wo_routing_line_id;
			$wip_wo_routing_detail->audit_trial();
			try {
			 $wip_wo_routing_detail->save();
			 echo "<br> Routing details are sucessfully copied !";
			} catch (Exception $e) {
			 echo "<br> System failed to copy the Routing Details!" . __LINE__ . $e->getMessage();
			}
		 }
		} catch (Exception $e) {
		 echo "<br> System failed to copy the Routing!" . __LINE__ . $e->getMessage();
		}
	 }//end of each routing line insertion
	 $this->routing_exploded_cb = 1;
	 $this->save();
	}//end of routing copy
 }

 private function update_woNumber($wip_wo_header_id, $wo_number) {
	global $dbc;
	$sql = " UPDATE " . self::$table_name;
	$sql .= " SET wo_number = '{$wo_number}'  ";
	$sql .= " WHERE wip_wo_header_id =  '{$wip_wo_header_id }' ";
	try {
	 $dbc->ddlexecute($sql);
	 $this->wo_number = $wo_number;
	 return true;
	} catch (Exception $e) {
	 echo "<br> WIP WO Number Update Failed" . $e->getMessage();
	 return false;
	}
 }

 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }

}

//end of resource class
?>



