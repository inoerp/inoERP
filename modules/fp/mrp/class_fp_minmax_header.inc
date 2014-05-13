<?php

class fp_minmax_header extends dbObject {

 protected static $table_name = "fp_minmax_header";
 public static $primary_column = "fp_minmax_header_id";
 public static $dependent_classes = ['fp_minmax_line'];
 public static $key_column = 'plan_name';
 public static $module = "org";
 public $field_a = [
		 'fp_minmax_header_id',
		 'org_id',
		 'plan_name',
		 'planning_horizon_days',
		 'description',
		 'status',
		 'demand_source',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $initial_search = [
		 'fp_minmax_header_id',
		 'org_id',
		 'plan_name',
		 'description',
		 'status',
		 'demand_source',
 ];
 public $column = [
		 'fp_minmax_header_id',
		 'org_id',
		 'plan_name',
		 'planning_horizon_days',
		 'description',
		 'status',
		 'demand_source',
 ];
 public $requiredField = [
		 'org_id',
		 'plan_name',
		 'planning_horizon_days',
		 'demand_source',
 ];
 public $search = [
		 '_update_path' => 'form.php?class_name=minmax_header',
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " Min Max Planner "; //page Title
 public $prg_minmax_planner_parameters = [
		 'Organization' => 'search_org_name',
		 'Min Max Planner ' => 'search_minmax_planner',
		 'Item Number From' => 'search_item_number_from',
		 'Item Number To' => 'search_item_number_to',
		 'Item Id From' => 'search_item_id_from',
		 'Item Id To' => 'search_item_id_to'
 ];
 public $prg_minmax_planner_details = [
		 'name' => 'Min Max Demand Calculator',
		 'description' => 'Calculate the Min Max Size',
 ];
 public $prg_minmax_program_parameters = [
		 'Organization' => 'search_org_name',
		 'Min Max Type ' => 'search_minmax_type',
		 'Item Number From' => 'search_item_number_from',
		 'Item Number To' => 'search_item_number_to',
		 'Item Id From' => 'search_item_id_from',
		 'Item Id To' => 'search_item_id_to'
 ];
 public $prg_minmax_program_details = [
		 'name' => 'Min Max Demand Calculator',
		 'description' => 'Calculate the Min Max Size',
 ];
 public $fp_minmax_header_id;
 public $org_id;
 public $plan_name;
 public $planning_horizon_days;
 public $description;
 public $status;
 public $demand_source;
 public $ar_customer_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $planning_method;

 public function prepare_minmax_demand_calculator($fp_minmax_header_id) {
	$mmd = new fp_minmax_demand();
	try {
	 $mmd->deleteBy_planId($fp_minmax_header_id);
	} catch (Exception $e) {
	 echo "<br>Deleting the existing record failed!. Error @ fp_minmax_header @ " . __LINE__;
	}
 }

 public function prg_minmax_planner($seralized_parameters) {
	$parameters = unserialize($seralized_parameters);
	$this->message = '<br> Starting Min Max Planner....<br>';
	$mmh = new fp_minmax_header();

	if (!empty($parameters['org_id'][0])) {
	 $org_id = $parameters['org_id'][0];
	 $this->message .= '<br> Entered Org Id is : ' . $org_id;
	} else {
	 $this->message .= '<br> Error! : No org id found @ cst_item_cost_header ' . __LINE__;
	 return $this->message;
	}

	if (!empty($parameters['fp_minmax_header_id'][0])) {
	 $fp_minmax_header_id = $parameters['fp_minmax_header_id'][0];
	 $this->message .= '<br> Entered Min Max Header Id is : ' . $fp_minmax_header_id;
	 $mmh->findBy_id($fp_minmax_header_id);
	 if ($mmh->org_id != $org_id) {
		$this->message .= '<br> Error! : Entered Min Max does not belong to the entered Org @ fp_minmax_header ' . __LINE__;
		return $this->message;
	 }
	 $this->prepare_minmax_demand_calculator($fp_minmax_header_id);
	} else {
	 $this->message .= '<br> Error! : No Min Max Header Id is found @ fp_minmax_header ' . __LINE__;
	 return $this->message;
	}

	if (isset($parameters['item_id'][0])) {
	 $this->message .= "<br/>Using Min Max Planner by Item Id ";
	 $item_id = $parameters['item_id'][0];
	 try {
		$this->minmax_demand_calculator($item_id, $mmh);
		$this->message .= "<br/> Min Max Planner is sucessfully updated for item_id - " . $item_id .
						' bom_cost_type : ' . $fp_minmax_header_id;
	 } catch (Exception $e) {
		$this->message .= "<br/> Min Max Planner fialed for Item id " . $item_id . $e->getMessage();
	 }

	 return $this->message;
	}

	if (!empty($parameters['from_item_id'][0])) {
	 $this->message .= "<br/>Using  Min Max Planner by Item Id Range ";
	 $from_item_id = $parameters['from_item_id'][0];
	 if (!empty($parameters['to_item_id'][0])) {
		$to_item_id = $parameters['to_item_id'][0];
	 } else {
		$to_item_id = $from_item_id;
	 }
	 $item = new item();
	 $item_range = $item->findBy_itemIdRange($from_item_id, $to_item_id);
	 foreach ($item_range as $items) {
		try {
		 $this->minmax_demand_calculator($items->item_id, $mmh);
		 $this->message .= "<br>Min Max Planner is sucessfully updated for item_id - " . $items->item_id .
						 ' bom_cost_type : ' . $fp_minmax_header_id;
		} catch (Exception $e) {
		 $this->message .= "<br>Min Max Plannerp failed for Item id " . $items->item_id . $e->getMessage();
		}
	 }
	 return $this->message;
	}

	if (!empty($parameters['from_item_number'][0])) {
	 $from_item_number = $parameters['from_item_number'][0];
	 if (!empty($parameters['to_item_number'][0])) {
		$to_item_number = $parameters['to_item_number'][0];
	 } else {
		$to_item_number = $from_item_number;
	 }
	 $item = new item();
	 $item_range = $item->findBy_itemNumberRange_OrgId($from_item_number, $to_item_number, $org_id);

	 foreach ($item_range as $items) {
		try {
		 $this->minmax_demand_calculator($items->item_id, $mmh);
		 $this->message .= "<br>Min Max Planner is sucessfully updated for item_id - " . $items->item_id .
						 ' bom_cost_type : ' . $bom_cost_type;
		} catch (Exception $e) {
		 $this->message .= "<br>Min Max Plannerp failed for Item id " . $items->item_id . $e->getMessage();
		}
	 }
	 return $this->message;
	}

	//if no item id/number is given
	$fcl = new fp_forecast_line();
	$fcl->fp_forecast_header_id = $mmh->demand_source;
	$fcl_i = $fcl->findAll_distinctItems_ofHeader();
	pa($fcl_i);
	$this->message .= "<br/>Using  Min Max Planner for All Items ";
	foreach ($fcl_i as $items) {
	 try {
		$this->minmax_demand_calculator($items->item_id, $mmh);
		$this->message .= "<br>Min Max Planner is sucessfully updated for item_id - " . $items->item_id .
						' bom_cost_type : ' . $fp_minmax_header_id;
	 } catch (Exception $e) {
		$this->message .= "<br>Min Max Plannerp failed for Item id " . $items->item_id . $e->getMessage();
	 }
	}
	return $this->message;
 }

 public function minmax_demand_calculator($item_id, $mmh) {
	$fctl = new fp_forecast_line();
	$fctl->item_id = $item_id;
	$fctl->fp_forecast_header_id = $mmh->demand_source;
	$forecast_lines = $fctl->findBy_ItemId_headerId();
	if (empty($forecast_lines)) {
	 return;
	}
	$mmd = new fp_minmax_demand();
	foreach ($forecast_lines as $forecast) {
	 $mmd->fp_minmax_demand_id = null;
	 $mmd->item_id = $forecast->item_id;
	 $mmd->plan_id = $mmh->fp_minmax_header_id;
	 $mmd->quantity = $forecast->total_original;
	 $mmd->demand_item_id = $fctl->item_id;
	 $mmd->toplevel_demand_item_id = $fctl->item_id;
	 $mmd->demand_type = 'FORECAST';
	 $mmd->source = $forecast->fp_forecast_header_id;
	 $mmd->audit_trial();
	 $mmd->save();
	 $this->_minmax_demand_calculator_forComponents($item_id, $mmd);
	}
 }

 private function _minmax_demand_calculator_forComponents($item_id, $mmd) {
//	$mmd->audit_trial();
//	$mmd->save();

	$boh = new bom_header();
	$boh->item_id = $item_id;
	$boh_i = $boh->findBy_itemId();
	if (empty($boh_i)) {
	 return;
	}
	foreach ($boh->field_a as $key => $value) {
	 if (isset($boh_i->$value)) {
		$boh->$value = $boh_i->$value;
	 }
	}
	$bol = new bom_line();
	$bol_i = $bol->findBy_parentId($boh->bom_header_id);
	if (empty($bol_i)) {
	 return;
	}
	$mmd_n = new fp_minmax_demand();
	foreach ($bol_i as $items) {
	 $mmd_n->fp_minmax_demand_id = null;
	 $mmd_n->item_id = $items->component_item_id;
	 $mmd_n->plan_id = $mmd->plan_id;
	 $mmd_n->quantity = $mmd->quantity * $items->usage_quantity;
	 $mmd_n->demand_item_id = $item_id;
	 $mmd_n->toplevel_demand_item_id = $mmd->toplevel_demand_item_id;
	 $mmd_n->demand_type = 'FORECAST';
	 $mmd_n->source = $mmd->source;
	 echo ($mmd_n->item_id) . '<br>';
	 $mmd_n->audit_trial();
	 $mmd_n->save();
	 $boh->item_id = $items->component_item_id;
	 $boh_i = $boh->findBy_itemId();
	 if (!empty($boh_i)) {
		$this->_minmax_demand_calculator_forComponents($items->component_item_id, $mmd_n);
	 }
	}
 }

 private function _create_requisition_for_minmax($item_id, $planning_method = "") {
	global $db;
	$sql = "SELECT item.item_number, item.item_description, org.org,  Sum(onhand.onhand) as Onhand, 
			onhand.item_id, onhand.org_id, onhand.uom_id,
			onhand.reservable_onhand, onhand.transactable_onhand,
			item.planning_method, item.minmax_min_quantity, item.minmax_max_quantity, item.minmax_multibin_number,
			item.minmax_multibin_size, item.fix_lot_multiplier, item.minimum_order_quantity, item.maximum_order_quantity

			FROM item 
			LEFT JOIN onhand ON onhand.item_id = item.item_id
			LEFT JOIN org ON item.org_id = org.org_id
			WHERE item.item_id = :item_id ";
	if (empty($planning_method)) {
	 $sql .= " item.planning_method = 'MULTI_MINMAX' OR item.planning_method = 'MINMAX' ";
	} else {
	 $sql .= " item.planning_method = '{$planning_method}' ";
	}
	$sql .= " GROUP BY item.item_id LIMIT 1";

	$param_a = ['item_id'];
	$value_a = [ 'item_id' => $item_id];
	$result = $db->findBy_sql($sql, $param_a, $value_a);
//insert into requisition interface
 }

 public function prg_minmax_program($seralized_parameters) {
	$parameters = unserialize($seralized_parameters);
	$this->message = '<br> Starting Min Max Program....<br>';
	$mmh = new fp_minmax_header();

	if (!empty($parameters['org_id'][0])) {
	 $org_id = $parameters['org_id'][0];
	 $this->message .= '<br> Entered Org Id is : ' . $org_id;
	} else {
	 $this->message .= '<br> Error! : No org id found @ fp_minmax_header ' . __LINE__;
	 return $this->message;
	}

	if (!empty($parameters['planning_method'][0])) {
	 $planning_method = $parameters['planning_method'][0];
	 $this->message .= '<br> Entered planning method is : ' . $planning_method;
	}

	if (!empty($parameters['item_id'][0])) {
	 $this->message .= "<br/>Using Min Max program by Item Id ";
	 $item_id = $parameters['item_id'][0];
	 try {
		$this->minmax_demand_calculator($item_id, $mmh);
		$this->message .= "<br/> Min Max Planner is sucessfully updated for item_id - " . $item_id .
						' bom_cost_type : ' . $fp_minmax_header_id;
	 } catch (Exception $e) {
		$this->message .= "<br/> Min Max Planner fialed for Item id " . $item_id . $e->getMessage();
	 }
	 return $this->message;
	}

	if (!empty($parameters['from_item_id'][0])) {
	 $this->message .= "<br/>Using  Min Max Planner by Item Id Range ";
	 $from_item_id = $parameters['from_item_id'][0];
	 if (!empty($parameters['to_item_id'][0])) {
		$to_item_id = $parameters['to_item_id'][0];
	 } else {
		$to_item_id = $from_item_id;
	 }
	 $item = new item();
	 $item_range = $item->findBy_itemIdRange($from_item_id, $to_item_id);
	 foreach ($item_range as $items) {
		try {
		 $this->minmax_demand_calculator($items->item_id, $mmh);
		 $this->message .= "<br>Min Max Planner is sucessfully updated for item_id - " . $items->item_id .
						 ' bom_cost_type : ' . $fp_minmax_header_id;
		} catch (Exception $e) {
		 $this->message .= "<br>Min Max Plannerp failed for Item id " . $items->item_id . $e->getMessage();
		}
	 }
	 return $this->message;
	}

	if (!empty($parameters['from_item_number'][0])) {
	 $from_item_number = $parameters['from_item_number'][0];
	 if (!empty($parameters['to_item_number'][0])) {
		$to_item_number = $parameters['to_item_number'][0];
	 } else {
		$to_item_number = $from_item_number;
	 }
	 $item = new item();
	 $item_range = $item->findBy_itemNumberRange_OrgId($from_item_number, $to_item_number, $org_id);

	 foreach ($item_range as $items) {
		try {
		 $this->minmax_demand_calculator($items->item_id, $mmh);
		 $this->message .= "<br>Min Max Planner is sucessfully updated for item_id - " . $items->item_id .
						 ' bom_cost_type : ' . $bom_cost_type;
		} catch (Exception $e) {
		 $this->message .= "<br>Min Max Plannerp failed for Item id " . $items->item_id . $e->getMessage();
		}
	 }
	 return $this->message;
	}

	//if no item id/number is given
	$fcl = new fp_forecast_line();
	$fcl->fp_forecast_header_id = $mmh->demand_source;
	$fcl_i = $fcl->findAll_distinctItems_ofHeader();
	pa($fcl_i);
	$this->message .= "<br/>Using  Min Max Planner for All Items ";
	foreach ($fcl_i as $items) {
	 try {
		$this->minmax_demand_calculator($items->item_id, $mmh);
		$this->message .= "<br>Min Max Planner is sucessfully updated for item_id - " . $items->item_id .
						' bom_cost_type : ' . $fp_minmax_header_id;
	 } catch (Exception $e) {
		$this->message .= "<br>Min Max Plannerp failed for Item id " . $items->item_id . $e->getMessage();
	 }
	}
	return $this->message;
 }

}

?>
