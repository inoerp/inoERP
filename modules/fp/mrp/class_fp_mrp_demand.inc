<?php

class fp_mrp_demand extends dbObject {

 protected static $table_name = "fp_mrp_demand";
 public static $primary_column = "fp_mrp_demand_id";
 public static $parent_primary_column = "fp_mrp_header_id";
 public static $key_column = 'item_id';
 public static $module = "fp";
 public $field_a = [
		 'fp_mrp_demand_id',
		 'fp_mrp_header_id',
		 'item_id',
		 'demand_date',
		 'quantity',
		 'demand_item_id',
		 'toplevel_demand_item_id',
		 'source_type',
		 'primary_source_type',
		 'source_header_id',
		 'source_line_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $initial_search = [
		 'source_type'
 ];
 public $search_functions = [
		 'Organization' => 'search_org_name_onevalue',
		 'MRP Planner ' => 'search_mrp_name_onevalue',
//		 'Item Number From' => 'search_item_number_from',
//		 'Item Number To' => 'search_item_number_to',
//		 'Item Id From' => 'search_item_id_from',
//		 'Item Id To' => 'search_item_id_to'
 ];
 public $column = [
		 'fp_mrp_demand_id',
		 'fp_mrp_header_id',
		 'item_id',
		 'demand_date',
		 'quantity',
		 'demand_item_id',
		 'toplevel_demand_item_id',
		 'source_type',
		 'primary_source_type',
		 'source_header_id',
		 'source_line_id'
 ];
 public $requiredField = [
		 'fp_mrp_header_id',
		 'item_id',
		 'demand_date',
		 'quantity',
 ];
 public $search = [
//		 '_show_view_path' => 1,
 ];
 public $prg_mrp_demand_calculator_parameters = [
		 'Organization' => 'search_org_name',
		 'MRP Planner ' => 'search_mrp_name',
 ];
 public $prg_mrp_demand_calculator_details = [
		 'name' => 'MRP Demand Calculator',
		 'description' => 'Calculate MRP Demands',
 ];
 public $pageTitle = " MRP Demand "; //page Title
 public $fp_mrp_demand_id;
 public $fp_mrp_header_id;
 public $item_id;
 public $demand_date;
 public $quantity;
 public $demand_item_id;
 public $toplevel_demand_item_id;
 public $source_type;
 public $primary_source_type;
 public $source_header_id;
 public $source_line_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function prepare_mrp_demand_calculator($fp_mrp_header_id) {
	$mrpd = new fp_mrp_demand();
	try {
	 $mrpd->deleteBy_parentId($fp_mrp_header_id);
	} catch (Exception $e) {
	 echo "<br>Deleting the existing record failed!. Error @ fp_mrp_header @ " . __LINE__;
	}
 }

 public function prg_mrp_demand_calculator($seralized_parameters) {
	$parameters = unserialize($seralized_parameters);
	$this->message = '<br> Starting MRP Demand Calculator....<br>';
	$mrph = new fp_mrp_header();

	if (!empty($parameters['org_id'][0])) {
	 $org_id = $parameters['org_id'][0];
	 $this->message .= '<br> Entered Org Id is : ' . $org_id;
	} else {
	 $this->message .= '<br> Error! : No org id found @ fp_mrp_demand ' . __LINE__;
	 return $this->message;
	}

	//calcuate the low level code
	$llc = new fp_mrp_lowlevel_code();
	$llc->create_lowlevel_code($org_id);

	if (!empty($parameters['fp_mrp_header_id'][0])) {
	 $fp_mrp_header_id = $parameters['fp_mrp_header_id'][0];
	 $this->message .= '<br> Entered MRP Header Id is : ' . $fp_mrp_header_id;
	 $mrph->findBy_id($fp_mrp_header_id);
	 if ($mrph->org_id != $org_id) {
		$this->message .= '<br> Error! : Entered MRP does not belong to the entered Org @ fp_mrp_demand ' . __LINE__;
		return $this->message;
	 }
	 $this->prepare_mrp_demand_calculator($fp_mrp_header_id);
	} else {
	 $this->message .= '<br> Error! : No MRP Header Id is found @ fp_mrp_header ' . __LINE__;
	 return $this->message;
	}
	//if no item id/number is given
	$all_items = $llc->findAll_orderByLevel($org_id);
	$this->message .= "<br/>Using  MRP Demand Calculator for All Items ";
	foreach ($all_items as $items) {
	 try {
		//all level 0 items
		$this->mrp_create_demand_and_plannedOrder($items->item_id, $mrph);
		//find all level 1 items - Caluclate the planned order and create new demands
		$this->message .= "<br>MRP Demand Calculator is Successfully updated for item_id - " . $items->item_id .
						' fp_mrp_header_id : ' . $fp_mrp_header_id;
	 } catch (Exception $e) {
		$this->message .= "<br>MRP Demand Calculatorp failed for Item id " . $items->item_id . $e->getMessage();
	 }
	}
	return $this->message;
 }

 public function mrp_create_demand_and_plannedOrder($item_id, $mrph) {
	$mdsl = new fp_mds_line();
	$mdsl->item_id = $item_id;
	$mdsl->fp_mds_header_id = $mrph->demand_source;
	$demand_lines = $mdsl->findBy_ItemId_headerId();
	if (!empty($demand_lines)) {
	 $this->mrp_create_demand_fromMDS($item_id, $mrph, $demand_lines);
	 }
	$mrpd = new fp_mrp_demand();
	$mrp_plo = new fp_mrp_planned_order();
	$all_planned_orders = $mrp_plo->create_planned_orders($item_id, $mrph->fp_mrp_header_id);
	if(!empty($all_planned_orders)){
	 foreach($all_planned_orders as $planned_order){
	$this->_mrp_demand_calculator_forComponents($item_id, $planned_order);
	 }
 }
 }

 public function mrp_create_demand_fromMDS($item_id, $mrph, $demand_lines) {
	$mrpd = new fp_mrp_demand();
	foreach ($demand_lines as $demand_line) {
	 $mrpd->fp_mrp_demand_id = null;
	 $mrpd->item_id = $demand_line->item_id;
	 $mrpd->fp_mrp_header_id = $mrph->fp_mrp_header_id;
	 $mrpd->demand_date = $demand_line->demand_date;
	 $mrpd->quantity = $demand_line->quantity;
	 $mrpd->demand_item_id = $demand_line->item_id;
	 $mrpd->toplevel_demand_item_id = $demand_line->item_id;
	 $mrpd->source_type = !empty($demand_line->source_type) ? $demand_line->source_type : null;
	 $mrpd->primary_source_type = $mrpd->source_type;
	 $mrpd->source_header_id = $demand_line->source_header_id;
	 $mrpd->source_line_id = $demand_line->source_line_id;
	 $mrpd->audit_trial();
	 $mrpd->save();
	}
 }

 private function _mrp_demand_calculator_forComponents($item_id, $all_planned_orders) {
	pa($all_planned_orders);
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
	pa($bol_i);
	$mrpd_n = new fp_mrp_demand();
	foreach ($bol_i as $items) {
	 $mrpd_n->fp_mrp_demand_id = null;
	 $mrpd_n->item_id = $items->component_item_id;
	 $mrpd_n->fp_mrp_header_id = $all_planned_orders->fp_mrp_header_id;
	 if (!empty($all_planned_orders->need_by_date)) {
		$item_details = item::find_by_id($mrpd_n->item_id);
		$total_lt = $item_details->pre_processing_lt + $item_details->processing_lt + $item_details->post_processing_lt;
		$lt = !empty($total_lt) ? $total_lt : 0;
		$ltp = 'P' . round($lt) . 'D';
		$date = new DateTime($all_planned_orders->need_by_date);
		$date->sub(new DateInterval($ltp));
		$mrpd_n->demand_date = $date->format('Y-m-d');
	 }
	 $mrpd_n->quantity = $all_planned_orders->quantity * $items->usage_quantity;
	 $mrpd_n->demand_item_id = $item_id;
	 $mrpd_n->toplevel_demand_item_id = $all_planned_orders->toplevel_demand_item_id;
	 $mrpd_n->source_type = 'Dependent';
	 $mrpd_n->primary_source_type = $all_planned_orders->primary_source_type;
	 $mrpd_n->source_header_id = $all_planned_orders->source_header_id;
	 $mrpd_n->source_line_id = $all_planned_orders->source_line_id;
	 $mrpd_n->audit_trial();
	 $mrpd_n->save();
	}
 }

 public function findBy_ItemId_HeaderId($item_id, $fp_mrp_header_id) {
	$sql = " SELECT * FROM " .
					self::$table_name .
					" WHERE item_id= :item_id  AND fp_mrp_header_id = :fp_mrp_header_id "
					. " ORDER BY  demand_date ASC ";
	$value_a = ['item_id' => $item_id, 'fp_mrp_header_id' => $fp_mrp_header_id];
	$result_array = $this->findBySql($sql, $value_a);
	return !empty($result_array) ? $result_array : false;
 }

}

?>
