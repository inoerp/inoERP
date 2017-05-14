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
 * fp_kanban_line
 *
 */
class fp_kanban_line extends dbObject {

 public static $table_name = "fp_kanban_line";
 public static $primary_column = "fp_kanban_line_id";
 public static $parent_primary_column = "fp_kanban_header_id";
 public static $key_column = "fp_kanban_header_id";
 public static $module = "prj";
 public static $card_status_a = [
  'ACTIVE' => 'Active',
  'INACTIVE' => 'In active',
  'CANCELLED' => 'Cancelled'
 ];
 public static $supply_status_a = [
  'UNKNOWN' => 'Unknown',
  'FULL' => 'Full',
  'EMPTY' => 'Empty',
  'INPROCESS' => 'InProcess',
  'HOLD' => 'On Hold',
 ];
 public static $card_type_a = [
  'MANUAL' => 'Manual',
  'AUTO' => 'Automatic'
 ];
 public static $action_a = [
  'REPLENISH' => 'Replenish',
  'SET_FULL' => 'Full',
  'ON_HOLD' => 'On Hold',
  'CANCEL' => 'Cancelled',
 ];
 public $field_a = [
  'fp_kanban_line_id',
  'fp_kanban_header_id',
  'description',
  'card_number',
  'card_status',
  'supply_status',
  'kanban_size',
  'card_type',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'description',
  'card_number',
 ];
 public $requiredField = [
  'fp_kanban_header_id',
  'kanban_size'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $fields_inForm_notInDataBase = [
  'action'
 ];
 public $pageTitle = "Kanban Cards"; //page Title
 public $fp_kanban_line_id;
 public $fp_kanban_header_id;
 public $description;
 public $card_number;
 public $card_status;
 public $supply_status;
 public $kanban_size;
 public $card_type;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $action;

 Public static function validation_types() {
  $header = option_line::find_by_keyColumn('SYS_VALIDATION_TYPE');
  $option_line = new option_line();
  $lines = $option_line->findBy_parentId($header->option_line_id);
  return $lines;
 }

 Public static function highest_card_number() {
  $sql = " SELECT MAX(card_number) as max_number from fp_kanban_line ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result[0]->max_number : 0;
 }

 Public static function find_by_cardNum($card_num) {
  $sql = " SELECT * from fp_kanban_line WHERE  card_number = :card_number ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $value_a = ['card_number' => $card_num];
  $result = self::find_by_sql_i($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 Public static function noof_active_cards($fp_kanban_header_id) {
  $sql = " SELECT COUNT(card_number) as card_count from fp_kanban_line  WHERE fp_kanban_header_id = '{$fp_kanban_header_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result[0]->card_count : 0;
 }

 public function _after_save() {
  if (!empty($this->fp_kanban_line_id) && empty($this->card_number)) {
   $this->card_number = $this->fp_kanban_line_id;
   $this->save();
  }
 }

 public function _before_save() {
  if (!empty($this->action)) {
   $this->_do_action();
  }
 }

 private function _do_action() {

  switch ($this->action) {
   case 'SET_FULL':
    $this->supply_status = 'FULL';
    break;

   case 'ON_HOLD':
    $this->supply_status = 'HOLD';
    break;

   case 'CANCEL':
    $this->card_status = 'CANCELLED';
    break;

   case 'REPLENISH':
    $this->replenish_card($this->fp_kanban_line_id);
    break;

   default :
    break;
  }
 }

 public function replenish_card($fp_kanban_line_id) {
  $kb_d = fp_kanban_line_v::find_by_id($fp_kanban_line_id);

  switch ($kb_d->source_type) {
   case 'SUPPLIER':
    $this->_cretae_requistion($kb_d);
    break;

   case 'SUBINV':


    break;

   case 'PRODUCTION':
    $this->_cretae_wo($kb_d);
    break;

   case 'ORG':


    break;
   default:
    break;
  }
 }

 private function _cretae_requistion($obj) {
  $po_req_interface = new po_requisition_interface();
  $fin_info_of_org = org::find_financial_details_from_orgId($obj->org_id);
  if (empty($obj->supplier_id)) {
   $sourcing_rule_id = $obj->sourcing_rule_id;
   $srl = new po_sourcing_rule_line();
   $srl_i = $srl->findBy_parentId($sourcing_rule_id);
   if (!empty($srl_i)) {
    foreach ($srl_i as $sourcing_rule_line) {
     $po_req_interface->po_requisition_interface_id = null;
     $po_req_interface->supplier_id = $sourcing_rule_line->supplier_id;
     $po_req_interface->supplier_site_id = $sourcing_rule_line->supplier_site_id;
     $po_req_interface->bu_org_id = $obj->bu_org_id;
     $po_req_interface->po_requisition_type = 'EXTERNAL';
     $po_req_interface->line_type = 'GOODS';
     $po_req_interface->requisition_status = 'APPROVED';
     $po_req_interface->item_id_m = $obj->item_id_m;
     $po_req_interface->uom_id = $obj->uom_id;
     $po_req_interface->item_description = $obj->item_description;
     $po_req_interface->currency = $fin_info_of_org->currency_code;
     $po_req_interface->receving_org_id = $obj->org_id;
     $po_req_interface->quantity = ($obj->kanban_size * $sourcing_rule_line->allocation) / 100;
     $unit_price = $obj->list_price;
     $po_req_interface->unit_price = !empty($unit_price) ? $unit_price : '0.01';
     $po_req_interface->need_by_date = date('Y-m-d', strtotime("$obj->leadtime days"));
     $po_req_interface->save();
    }
    return;
   }
  }

  $po_req_interface->bu_org_id = $obj->bu_org_id;
  $po_req_interface->po_requisition_type = 'EXTERNAL';
  $po_req_interface->line_type = 'GOODS';
  $po_req_interface->requisition_status = 'APPROVED';
  $po_req_interface->item_id_m = $obj->item_id_m;
  $po_req_interface->uom_id = $obj->uom_id;
  $po_req_interface->item_description = $obj->item_description;
  $po_req_interface->currency = $fin_info_of_org->currency_code;
  $po_req_interface->receving_org_id = $obj->org_id;
  $po_req_interface->quantity = $obj->kanban_size;
  $unit_price = $obj->list_price;
  $po_req_interface->unit_price = !empty($unit_price) ? $unit_price : '0.01';
  $leadtime = !empty($obj->leadtime) ? $obj->leadtime : 1;
  $po_req_interface->need_by_date = date('Y-m-d', strtotime("$leadtime days"));
  $po_req_interface->save();
 }

 private function _cretae_wo($obj) {
  $woh = new wip_wo_header();

  $woh->org_id = $obj->org_id;
  $woh->item_id_m = $obj->item_id_m;
  $woh->wo_type = 'STANDARD';
  $woh->wip_accounting_group_id = 1;
  $woh->wo_status = 'UN_RELEASED';
  $woh->start_date = date('Y-m-d');
  $woh->completion_date = date('Y-m-d', strtotime("$obj->leadtime days"));
  $woh->nettable_quantity = $woh->quantity = $obj->kanban_size;

  $woh->save();
  $woh->_after_save();
 }

}

//end of path class
?>
