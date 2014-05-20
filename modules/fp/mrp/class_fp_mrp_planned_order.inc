<?php

class fp_mrp_planned_order extends dbObject {

 protected static $table_name = "fp_mrp_planned_order";
 public static $primary_column = "fp_mrp_planned_order_id";
 public static $parent_primary_column = "fp_mrp_header_id";
 public static $key_column = 'item_id';
 public static $module = "fp";
 public $field_a = [
		 'fp_mrp_planned_order_id',
		 'fp_mrp_header_id',
		 'order_type',
		 'item_id',
		 'quantity',
		 'need_by_date',
		 'supplier_id',
		 'supplier_site_id',
		 'demand_item_id',
		 'toplevel_demand_item_id',
		 'source_type',
		 'primary_source_type',
		 'source_header_id',
		 'source_line_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'source_type'
 ];
 public $column = [
		 'fp_mrp_planned_order_id',
		 'fp_mrp_header_id',
		 'order_type',
		 'item_id',
		 'quantity',
		 'need_by_date',
		 'supplier_id',
		 'supplier_site_id',
		 'demand_item_id',
		 'toplevel_demand_item_id',
		 'source_type',
		 'primary_source_type',
		 'source_header_id',
		 'source_line_id',
 ];
 public $requiredField = [
		 'fp_mrp_header_id',
		 'order_type',
		 'item_id',
		 'quantity',
		 'need_by_date'
 ];
 public $search = [
//		 '_show_view_path' => 1,
 ];
 public $prg_mrp_create_planned_order_parameters = [
		 'Organization' => 'search_org_name',
		 'MRP Planner ' => 'search_mrp_name'
 ];
 public $prg_mrp_demand_calculator_details = [
		 'name' => 'MRP Create Planned Orders ',
		 'description' => ' Create Planned Orders ',
 ];
 public $pageTitle = " MRP Planned Orders "; //page Title
 public $fp_mrp_planned_order_id;
 public $fp_mrp_header_id;
 public $order_type;
 public $item_id;
 public $need_by_date;
 public $quantity;
 public $demand_item_id;
 public $toplevel_demand_item_id;
 public $source_type;
 public $primary_source_type;
 public $source_header_id;
 public $source_line_id;
 public $supplier_id;
 public $supplier_site_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function create_planned_orders($item_id, $fp_mrp_header_id) {
	$mrpd = new fp_mrp_demand();
	$mrp_d = $mrpd->findBy_ItemId_HeaderId($item_id, $fp_mrp_header_id);
	if (empty($mrp_d)) {
	 return;
	}

	$mrpexsup = new fp_mrp_existing_supply_v();
	$mrp_supp = $mrpexsup->findBy_ItemId($item_id);
	$onhand = 0;
	if (!empty($mrp_supp)) {
	 foreach ($mrp_supp as $supp) {
		if ($supp->document_type == 'Onhand') {
		 $onhand = $supp->quantity;
		 break;
		}
	 }
	}

	$planned_order_a = [];
	foreach ($mrp_d as $demand) {
	 if ($onhand >= $demand->quantity) {
		$onhand -= $demand->quantity;
		continue;
	 }
	 if ($onhand > 0) {
		$order_quantity = $demand->quantity - $onhand;
		$onhand = 0;
	 } else {
		$order_quantity = $demand->quantity;
	 }
	 $plo = new fp_mrp_planned_order();
	 $plo->fp_mrp_planned_order_id = null;
	 $plo->fp_mrp_header_id = $demand->fp_mrp_header_id;
	 $plo->item_id = $demand->item_id;
	 $item = item::find_by_id($plo->item_id);
	 $plo->order_type = ($item->make_buy == 'Make') ? 'WO' : 'Requisition';
	 $plo->quantity = $order_quantity;
	 $plo->need_by_date = $demand->demand_date;
	 $plo->demand_item_id = $demand->demand_item_id;
	 $plo->toplevel_demand_item_id = $demand->toplevel_demand_item_id;
	 $plo->source_type = $demand->source_type;
	 $plo->primary_source_type = $demand->primary_source_type;
	 $plo->source_header_id = $demand->source_header_id;
	 $plo->source_line_id = $demand->source_line_id;
	 array_push($planned_order_a, $plo);
//	 $plo->audit_trial();
	 $plo->save();
	}

	return !empty($planned_order_a) ? $planned_order_a : false;
 }

}

?>
