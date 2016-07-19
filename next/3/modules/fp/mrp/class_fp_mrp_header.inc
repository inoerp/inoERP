<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * fp_mrp_header
 * Used for material requirement planning
 * Contains all the fp_mds_header information, such as - mrp_name, description , demand_source, org_id, planning_horizon_days
 * 
 */
class fp_mrp_header extends dbObject {

 public static $table_name = "fp_mrp_header";
 public static $primary_column = "fp_mrp_header_id";
 public static $key_column = 'mrp_name';
 public static $js_fileName = 'modules/fp/mrp/js/multi_select_mrp_v.js';
 public static $module = "fp";
 public static $system_info = [
  'name' => 'MRP',
  'number' => '2506',
  'description' => 'MRP Planning',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('fp_mrp_demand', 'fp_mrp_demand_v', 'fp_mrp_existing_supply_v', 'fp_mrp_lowlevel_code', 'fp_mrp_planned_order','fp_mrp_exception'),
  'primary_entity_cb' => '',
  'module_name' => 'fp',
  'weight' => 6
 ];
 public $field_a = [
  'fp_mrp_header_id',
  'org_id',
  'mrp_name',
  'description',
  'status',
  'demand_source',
  'planning_horizon_days',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'fp_mrp_header_id',
  'mrp_name',
  'description',
  'demand_source',
 ];
 public $column = [
  'fp_mrp_header_id',
  'org_id',
  'mrp_name',
  'description',
  'status',
  'demand_source',
 ];
 public $requiredField = [
  'org_id',
  'mrp_name',
  'planning_horizon_days',
  'demand_source',
 ];
 public $fields_inForm_notInDataBase = [
  'action',
  'supplier_name',
  'supplier_site_name',
  'fp_mrp_planned_order_id',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " MRP "; //page Title
 public $fp_mrp_header_id;
 public $org_id;
 public $mrp_name;
 public $description;
 public $status;
 public $demand_source;
 public $planning_horizon_days;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $action;
 public $fp_mrp_planned_order_id;

 public function _before_save() {
  if (($this->action == 'release_planned_order')) {
   echo "<br> Releasing Planned Order";
   $this->release_planned_order();
   return 10;
  }
 }

 public function release_planned_order() {
  $mrpplo = new fp_mrp_planned_order();
  if (!empty($this->fp_mrp_planned_order_id)) {
   $mrpplo->findBy_id($this->fp_mrp_planned_order_id);
  }
  if (empty($mrpplo)) {
   return;
  } elseif ($mrpplo->order_action == 'None') {
   return;
  } elseif ($mrpplo->order_type == 'Requisition') {
   $this->_cretae_requistion($mrpplo);
   $order_type = 'Converted_' . $mrpplo->order_type;
  } elseif ($mrpplo->order_type == 'WO') {
   $this->_cretae_wo($mrpplo);
   $order_type = 'Converted_' . $mrpplo->order_type;
  } else {
   $order_type = $mrpplo->order_type;
  }
  $mrpplo->order_type = $order_type;
  $mrpplo->order_action = 'None';
  $mrpplo->audit_trial();
  $mrpplo->save();
 }

 private function _cretae_requistion($obj) {
  $po_req_interface = new po_requisition_interface();
  $org = new org_v();
  $org->findBy_id($obj->org_id);
  $item = new item();
  $item->findBy_id($obj->item_id_m);
  $leadtime = $item->pre_processing_lt + $item->post_processing_lt + $item->processing_lt;
  $itemcost = new cst_item_cost_v();
  $itemcost->item_id_m = $obj->item_id_m;
  $itemcost->bom_cost_type = 'FROZEN';
  $itemcost_i = $itemcost->findBy_ItemId_CostType();
  $sourcing_rule_id = $item->sourcing_rule_id;
  $srl = new po_sourcing_rule_line();
  $srl_i = $srl->findBy_parentId($sourcing_rule_id);

  if (!empty($srl_i)) {
   foreach ($srl_i as $sourcing_rule_line) {
    $po_req_interface->po_requisition_interface_id = null;
    $po_req_interface->supplier_id = $sourcing_rule_line->supplier_id;
    $po_req_interface->supplier_site_id = $sourcing_rule_line->supplier_site_id;
    $po_req_interface->bu_org_id = $org->business_org_id;
    $po_req_interface->po_requisition_type = 'EXTERNAL';
    $po_req_interface->line_type = 'GOODS';
    $po_req_interface->requisition_status = 'APPROVED';
    $po_req_interface->item_id_m = $obj->item_id_m;
    $po_req_interface->uom_id = $item->uom_id;
    $po_req_interface->item_description = $item->item_description;
    $po_req_interface->currency = $org->currency_code;
    $po_req_interface->receving_org_id = $obj->org_id;
    $po_req_interface->quantity = ($obj->quantity * $sourcing_rule_line->allocation) / 100;
    if (!empty($itemcost_i)) {
     $unit_price = !empty($itemcost_i->purchase_price) ? $itemcost_i->purchase_price : $itemcost_i->standard_cost;
    }
    $po_req_interface->unit_price = !empty($unit_price) ? $unit_price : '0.01';
    $po_req_interface->need_by_date = date('Y-m-d', strtotime("$leadtime days"));
    $po_req_interface->audit_trial();
    $po_req_interface->save();
   }
   return;
  }
  $po_req_interface->bu_org_id = $org->business_org_id;
  $po_req_interface->po_requisition_type = 'EXTERNAL';
  $po_req_interface->line_type = 'GOODS';
  $po_req_interface->requisition_status = 'APPROVED';
  $po_req_interface->item_id_m = $obj->item_id_m;
  $po_req_interface->uom_id = $item->uom_id;
  $po_req_interface->item_description = $item->item_description;
  $po_req_interface->currency = $org->currency_code;
  $po_req_interface->receving_org_id = $obj->org_id;
  $po_req_interface->quantity = $obj->quantity;
  if (!empty($itemcost_i)) {
   $unit_price = !empty($itemcost_i->purchase_price) ? $itemcost_i->purchase_price : $itemcost_i->standard_cost;
  }
  $po_req_interface->unit_price = !empty($unit_price) ? $unit_price : '0.01';
  $po_req_interface->need_by_date = date('Y-m-d', strtotime("$leadtime days"));
  $po_req_interface->audit_trial();
  $po_req_interface->save();
  echo "<br>Requistion is Successfully Created in interafce. po_requisition_interface_id is " . $po_req_interface->po_requisition_interface_id;
 }

 private function _cretae_wo($obj) {
  $item = new item();
  $item->findBy_id($obj->item_id_m);
  $leadtime = $item->pre_processing_lt + $item->post_processing_lt + $item->processing_lt;
  $woh = new wip_wo_header();
  $woh->org_id = $obj->org_id;
  $woh->item_id_m = $obj->item_id_m;
  $woh->wo_type = 'STANDARD';
  $woh->wip_accounting_group_id = 1;
  $woh->wo_status = 'UN_RELEASED';
  $woh->start_date = date('Y-m-d');
  $woh->completion_date = date('Y-m-d', strtotime("$leadtime days"));
  $woh->nettable_quantity = $woh->quantity = $obj->quantity;

  $woh->audit_trial();
  $woh->save();
  $woh->_after_save();
  echo "<br>WO is Successfully Created in interafce. wip_wo_header_id is " . $woh->wip_wo_header_id;
 }

 public function multi_select_input_fields() {
  $multi_select_input = [
//			'supplier_name',
//			'supplier_site_name',
  ];
  return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'action_class_name',
   'mode',
   'action',
   'show_block',
  ];

  return $multi_select_hidden;
 }

}

?>
