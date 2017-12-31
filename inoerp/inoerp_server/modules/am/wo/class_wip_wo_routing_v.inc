<?php

class am_wo_routing_v extends dbObject {

 public static $table_name = "wip_wo_routing_v";
 public static $primary_column = "wip_wo_routing_detail_id";
 public $field_a = [
  'item_number',
  'item_description',
  'uom_id',
  'item_id_m',
  'wo_number',
  'org_id',
  'wip_accounting_group_id',
  'quantity',
  'completed_quantity',
  'routing_sequence',
  'department_id',
  'wip_wo_routing_detail_id',
  'wip_wo_routing_line_id',
  'wip_wo_header_id',
  'resource_sequence',
  'resource_id',
  'resource_usage',
  'resource_schedule',
  'required_quantity',
  'applied_quantity',
  'charge_type',
 ];
 public $initial_search = [
  'item_number',
  'item_id_m',
  'wo_number',
  'org_id',
  'routing_sequence',
  'wip_wo_routing_detail_id',
  'wip_wo_routing_line_id',
  'wip_wo_header_id',
  'resource_sequence',
  'resource_id',
 ];
 public $column = [
  'item_number',
  'item_id_m',
  'wo_number',
  'org_id',
  'routing_sequence',
  'wip_wo_routing_detail_id',
  'wip_wo_routing_line_id',
  'wip_wo_header_id',
  'resource_sequence',
  'resource_id',
  'required_quantity',
  'applied_quantity',
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=wip_wo_header',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_view_path' => 'form.php?class_name=wip_wo_header',
  '_show_view_path' => 1,
//		 '_extra_path' => array('form.php?class_name=ap_transaction_header&mode=9' => 'Invoice',
//				 'form.php?class_name=receipt_header&mode=9' => 'Receive')
 ];
 public $pageTitle = " WIP WO - Find All Work Order Routings "; //page Title
 public $option_lists = [
  'po_type' => 'PO_TYPE',
  'po_status' => 'PO_STATUS',
 ];
 public $item_number;
 public $item_description;
 public $uom_id;
 public $item_id_m;
 public $wo_number;
 public $org_id;
 public $wip_accounting_group_id;
 public $quantity;
 public $completed_quantity;
 public $routing_sequence;
 public $department_id;
 public $wip_wo_routing_detail_id;
 public $wip_wo_routing_line_id;
 public $wip_wo_header_id;
 public $resource_sequence;
 public $resource_id;
 public $resource_usage;
 public $resource_schedule;
 public $required_quantity;
 public $applied_quantity;
 public $charge_type;

 public function __set($name, $value) {
  $this->$name = $value;
 }

 private function create_wip_wo_routing_v() {
  $sql = "
CREATE OR REPLACE VIEW wip_wo_routing_v
(
item_number, item_description, uom_id, item_id_m, wo_number, org_id, wip_accounting_group_id, quantity, completed_quantity,
routing_sequence, department_id, wip_wo_routing_detail_id, wip_wo_routing_line_id, wip_wo_header_id,
resource_sequence, resource_id,resource_usage,resource_schedule,required_quantity, applied_quantity, 
charge_type
)
AS
SELECT item.item_number, item.item_description, item.uom_id,
wwh.item_id_m, wwh.wo_number, wwh.org_id, wwh.wip_accounting_group_id, wwh.quantity, wwh.completed_quantity,
wwrl.routing_sequence,wwrl.department_id,
wwrd.wip_wo_routing_detail_id, wwrd.wip_wo_routing_line_id, wwrd.wip_wo_header_id,wwrd.resource_sequence,wwrd.resource_id,wwrd.resource_usage,wwrd.resource_schedule,wwrd.required_quantity, wwrd.applied_quantity, wwrd.charge_type
FROM wip_wo_routing_detail wwrd
LEFT JOIN wip_wo_routing_line wwrl ON wwrl.wip_wo_routing_line_id = wwrd.wip_wo_routing_line_id
LEFT JOIN wip_wo_header wwh ON wwh.wip_wo_header_id = wwrd.wip_wo_header_id
LEFT JOIN item ON item.item_id_m = wwh.item_id_m and item.org_id = wwh.org_id 

";
 }

 public function findBy_woHeaderId() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE wip_wo_header_id = :wip_wo_header_id ";

  $param_a = ['wip_wo_header_id'];
  $value_a = ['wip_wo_header_id' => $this->wip_wo_header_id];
  $result = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? $result : false;
 }

 public function findBy_woHeaderId_routingSeq() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE wip_wo_header_id = :wip_wo_header_id ";
  $sql .= " AND resource_sequence = :resource_sequence ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $param_a = ['wip_wo_header_id', 'resource_sequence'];
  $value_a = ['wip_wo_header_id' => $this->wip_wo_header_id, 'resource_sequence' => $this->resource_sequence];
  $result = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_woRoutingDetailId() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE wip_wo_routing_detail_id = :wip_wo_routing_detail_id ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $param_a = ['wip_wo_routing_detail_id'];
  $value_a = ['wip_wo_routing_detail_id' => $this->wip_wo_routing_detail_id];
  $result = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of po_detail class
?>