<?php

class fp_minmax_order_v extends dbObject {

 public static $form_class_name = "fp_minmax_demand";
 public static $table_name = "fp_minmax_order_v";
 public static $primary_column = "fp_minmax_demand_id";
 public static $key_column = 'item_id_m';
 public static $module = "fp";
 public $field_a = [
  'plan_name',
  'org_id',
  'planning_horizon_days',
  'org',
  'item_id_m',
  'item_number',
  'total_demand',
  'avg_daily_demand',
  'saftey_stock_quantity',
  'lead_time',
  'saftey_stock_days',
  'minmax_min_quantity',
  'fix_days_supply',
  'minmax_max_quantity',
  'multibin_fix_days_supply',
  'minmax_multibin_number',
  'minmax_multibin_size',
  'multibin_minmax_quantity',
  'forecast',
  'forecast_description',
  'fp_minmax_demand_id',
  'plan_id',
  'demand_item_id_m',
  'toplevel_demand_item_id_m',
  'demand_type',
  'source',
  'item_description',
  'top_level_item_number',
  'top_level_item_description',
  'demand_item_number',
  'demand_item_description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'forecast',
  'item_number',
  'top_level_item_number',
  'demand_item_number',
 ];
 public $column = [
  'plan_name',
  'planning_horizon_days',
  'org',
  'item_number',
  'total_demand',
  'avg_daily_demand',
  'saftey_stock_quantity',
  'lead_time',
  'saftey_stock_days',
  'minmax_min_quantity',
  'fix_days_supply',
  'minmax_max_quantity',
  'multibin_fix_days_supply',
  'minmax_multibin_number',
  'minmax_multibin_size',
  'multibin_minmax_quantity',
  'forecast',
  'top_level_item_number',
  'demand_item_number',
 ];
 public $multi_select_column = [
  'item_number',
  'minmax_min_quantity',
  'minmax_max_quantity',
  'minmax_multibin_number',
  'minmax_multibin_size',
  'multibin_minmax_quantity',
  'org',
  'fix_days_supply',
  'multibin_fix_days_supply',
  'plan_name',
  'org_id',
  'planning_horizon_days',
  'item_id_m',
  'total_demand',
  'avg_daily_demand',
  'saftey_stock_quantity',
  'lead_time',
  'saftey_stock_days',
  'forecast',
  'forecast_description',
  'fp_minmax_demand_id',
  'plan_id',
  'demand_item_id_m',
  'toplevel_demand_item_id_m',
  'demand_type',
  'source',
  'item_description',
  'top_level_item_number',
  'top_level_item_description',
  'demand_item_number',
  'demand_item_description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $search = [
//		 '_view_path' => 'form.php?class_name=fp_minmax_order',
//		 '_show_view_path' => 1,
////		 '_view_action_meassge' => 'View',
////		 '_extra_path' => '',
 ];
 public $pageTitle = " Min Max Suggestions "; //page Title
 public $search_functions = [
  'Organization' => 'search_org_name',
  'MM Planner' => 'search_minmax_planner',
  'Item Number From' => 'search_item_number_from',
  'Item Number To' => 'search_item_number_to',
  'Item Id From' => 'search_item_id_m_from',
  'Item Id To' => 'search_item_id_m_to'
 ];
 public $item_id_m;
 public $item_number;
 public $total_demand;
 public $avg_daily_demand;
 public $saftey_stock_quantity;
 public $lead_time;
 public $saftey_stock_days;
 public $minmax_min_quantity;
 public $fix_days_supply;
 public $minmax_max_quantity;
 public $multibin_fix_days_supply;
 public $minmax_multibin_number;
 public $minmax_multibin_size;
 public $multibin_minmax_quantity;
 public $forecast;
 public $forecast_description;
 public $fp_minmax_demand_id;
 public $plan_id;
 public $demand_item_id_m;
 public $toplevel_demand_item_id_m;
 public $demand_type;
 public $source;
 public $item_description;
 public $top_level_item_number;
 public $top_level_item_description;
 public $demand_item_number;
 public $demand_item_description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $overwrite_minmax_min_quantity;
 public $overwrite_minmax_max_quantity;
 public $overwrite_minmax_multibin_number;
 public $overwrite_minmax_multibin_size;

 private function create_fp_minmax_order_v() {
  $sql = "
CREATE OR REPLACE VIEW fp_minmax_order_v
(
item_number, item_description, planning_method, make_buy,
minmax_min_quantity, minmax_max_quantity, minmax_multibin_number, minmax_multibin_size, 
minimum_order_quantity, fix_lot_multiplier, 
item_id_m , onhand, open_wo, open_req , open_po, total_supply
)
AS
 SELECT item.item_number, item.item_description, item.planning_method, item.make_buy,
item.minmax_min_quantity, item.minmax_max_quantity, item.minmax_multibin_number, item.minmax_multibin_size, 
item.minimum_order_quantity, item.fix_lot_multiplier, 
onhand_wo_o.item_id_m as item_id_m , onhand_wo_o.onhand as onhand, onhand_wo_o.open_wo as open_wo,
       open_po_req_o.open_req open_req , open_po_req_o.open_po as open_po,
			(IFNULL(onhand_wo_o.onhand,0) + IFNULL(onhand_wo_o.open_wo,0) + 
			IFNULL(open_po_req_o.open_req,0) + IFNULL(open_po_req_o.open_po,0)) as total_supply
 FROM (
		SELECT onhand_wo.item_id_m as item_id_m , onhand_wo.onhand as onhand, onhand_wo.open_wo as open_wo
		FROM (
		SELECT item.item_id_m as item_id_m, oh.onhand as onhand, wwh.open_wo as open_wo
		FROM item 
		LEFT JOIN (SELECT item_id_m, sum(onhand) as onhand from onhand  GROUP BY item_id_m) oh ON oh.item_id_m = item.item_id_m
		LEFT JOIN ( SELECT item_id_m, sum(nettable_quantity - IFNULL(completed_quantity,0) - IFNULL(scrapped_quantity,0))as open_wo 
		from wip_wo_header  GROUP BY item_id_m) wwh ON wwh.item_id_m = item.item_id_m
		WHERE  item.planning_method = 'MULTI_MINMAX' OR item.planning_method = 'MINMAX'
		) onhand_wo
 )onhand_wo_o

LEFT JOIN (
						 SELECT open_po_req.item_id_m as item_id_m, open_po_req.open_req open_req , open_po_req.open_po as open_po
						FROM (
						SELECT item.item_id_m as item_id_m,  prv.open_req as open_req, pav.open_po as open_po
						FROM item 
						LEFT JOIN (SELECT item_id_m, SUM(open_quantity) as open_po from po_all_v  GROUP BY item_id_m) pav ON pav.item_id_m = item.item_id_m
						LEFT JOIN ( SELECT item_id_m, sum(quantity)as open_req from po_requisition_all_v  
						WHERE order_number IS NULL GROUP BY item_id_m) prv ON prv.item_id_m = item.item_id_m
						WHERE  item.planning_method = 'MULTI_MINMAX' OR item.planning_method = 'MINMAX'
						) open_po_req 
	)open_po_req_o 
ON onhand_wo_o.item_id_m = open_po_req_o.item_id_m

LEFT JOIN item ON item.item_id_m = open_po_req_o.item_id_m

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
  $sql .= " where plan_id = :plan_id AND item_id_m =:item_id_m ";
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
