<?php

class fp_mrp_v extends dbObject {

 public static $form_class_name = "fp_mrp_header";
 public static $table_name = "fp_mrp_v";
 public static $primary_column = "fp_mrp_planned_order_id";
 public static $key_column = 'item_id_m';
 public static $module = "fp";
 public $field_a = [
  'mrp_name',
  'org',
  'org_id',
  'item_number',
  'item_description',
  'demand_item_number',
  'demand_item_description',
  'toplevel_demand_item_number',
  'toplevel_demand_item_desc',
  'sourcing_rule_id',
  'fp_mrp_planned_order_id',
  'fp_mrp_header_id',
  'order_type',
  'order_action',
  'item_id_m',
  'quantity',
  'need_by_date',
  'supplier_id',
  'supplier_site_id',
  'demand_item_id_m',
  'toplevel_demand_item_id_m',
  'source_type',
  'primary_source_type',
  'source_header_id',
  'source_line_id',
  'so_number',
  'forecast',
  'sales_order_line',
 ];
 public $initial_search = [
  'order_type',
 ];
 public $column = [
  'mrp_name',
  'org',
  'item_number',
  'item_description',
  'demand_item_number',
  'toplevel_demand_item_number',
  'quantity',
  'need_by_date',
  'so_number',
  'forecast',
  'sales_order_line',
 ];
 public $multi_select_column = [
  'mrp_name',
  'org',
  'item_number',
  'item_description',
  'order_type',
  'order_action',
  'quantity',
  'need_by_date',
  'demand_item_number',
  'demand_item_description',
  'toplevel_demand_item_number',
  'toplevel_demand_item_desc',
  'source_type',
  'so_number',
  'forecast',
  'sales_order_line',
  'sourcing_rule_id',
  'fp_mrp_planned_order_id',
  'fp_mrp_header_id',
  'org_id',
  'item_id_m',
  'demand_item_id_m',
  'toplevel_demand_item_id_m',
  'primary_source_type',
  'source_header_id',
  'source_line_id',
  'supplier_id',
  'supplier_site_id',
 ];
 public $search = [
 ];
 public $pageTitle = " MRP Work Bench "; //page Title
 public $search_functions = [
  'Organization' => 'search_org_name',
  'MRP Planner' => 'search_mrp_name',
  'Item Number From' => 'search_item_number_from',
  'Item Number To' => 'search_item_number_to',
  'Item Id From' => 'search_item_id_m_from',
  'Item Id To' => 'search_item_id_m_to'
 ];
 public $mrp_name;
 public $item_number;
 public $item_description;
 public $demand_item_number;
 public $demand_item_description;
 public $toplevel_demand_item_number;
 public $toplevel_demand_item_desc;
 public $sourcing_rule_id;
 public $fp_mrp_planned_order_id;
 public $fp_mrp_header_id;
 public $order_type;
 public $order_action;
 public $item_id_m;
 public $quantity;
 public $need_by_date;
 public $supplier_id;
 public $supplier_site_id;
 public $demand_item_id_m;
 public $toplevel_demand_item_id_m;
 public $source_type;
 public $primary_source_type;
 public $source_header_id;
 public $source_line_id;
 public $so_number;
 public $forecast;
 public $sales_order_line;
 public $org;
 public $org_id;

 private function create_fp_mrp_v() {
  $sql = "
CREATE OR REPLACE VIEW fp_mrp_v
(
mrp_name,org_id, org, 
item_number,item_description, demand_item_number, demand_item_description, toplevel_demand_item_number, 
toplevel_demand_item_desc,sourcing_rule_id,
fp_mrp_planned_order_id, fp_mrp_header_id,order_type, order_action, item_id_m, quantity, 
need_by_date,supplier_id,supplier_site_id,demand_item_id_m,toplevel_demand_item_id_m, 
source_type,primary_source_type,source_header_id,source_line_id,
so_number, forecast, sales_order_line
)
AS
 SELECT 
 fmh.mrp_name,fmh.org_id, org.org,
 item.item_number, item.item_description, item2.item_number as demand_item, 
 item2.item_description as demand_item_description, item3.item_number as toplevel_demand_item_number, 
 item3.item_description as toplevel_demand_item_desc, item.sourcing_rule_id,
 fmd.fp_mrp_planned_order_id,  fmd.fp_mrp_header_id, fmd.order_type,  fmd.order_action,fmd.item_id_m,  fmd.quantity, 
 fmd.need_by_date, fmd.supplier_id, fmd.supplier_site_id, fmd.demand_item_id_m, fmd.toplevel_demand_item_id_m, 
 fmd.source_type, fmd.primary_source_type, fmd.source_header_id,fmd.source_line_id,
 ssh.so_number, ffh.forecast, soline.line_number as sales_order_line


FROM fp_mrp_planned_order fmd
LEFT JOIN fp_mrp_header fmh ON fmh.fp_mrp_header_id = fmd.fp_mrp_header_id
LEFT JOIN item  ON item.item_id_m = fmd.item_id_m
LEFT JOIN item item2  ON item2.item_id_m = fmd.demand_item_id_m
LEFT JOIN item item3  ON item3.item_id_m = fmd.toplevel_demand_item_id_m
LEFT JOIN sd_so_header ssh ON ssh.sd_so_header_id = fmd.source_header_id AND fmd.primary_source_type = 'Sales_Order'
LEFT JOIN fp_forecast_header ffh ON ffh.fp_forecast_header_id = fmd.source_header_id AND fmd.primary_source_type = 'Forecast'
LEFT JOIN sd_so_line soline ON soline.sd_so_line_id = fmd.source_line_id AND fmd.primary_source_type = 'Sales_Order'
LEFT JOIN org ON org.org_id = fmh.org_id
ORDER BY item.item_number, fmd.need_by_date;

";
 }

 public function findBy_planId($plan_id = '') {
  global $db;
  if (!empty($plan_id)) {
   $this->plan_id = $plan_id;
  }
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " where plan_id = :plan_id ";
  $param_a = ['plan_id'];
  $value_a = ['plan_id' => $this->plan_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !(empty($result)) ? $result : false;
 }

 public function findBy_planId_itemId() {
  global $db;
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " where plan_id = :plan_id AND item_id_m =:item_id_m  ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $param_a = ['plan_id', 'item_id_m'];
  $value_a = ['plan_id' => $this->plan_id, 'item_id_m' => $this->item_id_m];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !(empty($result)) ? array_pop($result) : false;
 }

}

?>
