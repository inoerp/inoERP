<?php

class fp_minmax_suggestion_v extends dbObject {

 public static $form_class_name = "fp_minmax_demand";
 public static $table_name = "fp_minmax_suggestion_v";
 public static $primary_column = "fp_minmax_demand_id";
 public static $key_column = 'item_id_m';
 public static $module = "fp";
 public $field_a = [
  'fp_minmax_header_id',
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
//		 '_view_path' => 'form.php?class_name=fp_minmax_suggestion',
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
 public $fp_minmax_header_id;
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

 private function create_fp_minmax_suggestion_v() {
  $sql = "
CREATE OR REPLACE VIEW fp_minmax_suggestion_v
(
fp_minmax_header_id, plan_name,org_id,planning_horizon_days,  org, item_id_m,item_number,
total_demand, avg_daily_demand, saftey_stock_quantity, lead_time , saftey_stock_days,
 minmax_min_quantity, fix_days_supply, minmax_max_quantity, 
multibin_fix_days_supply,minmax_multibin_number, minmax_multibin_size, multibin_minmax_quantity,
forecast, forecast_description, 
 fp_minmax_demand_id, plan_id,  demand_item_id_m, toplevel_demand_item_id_m, demand_type, source, item_description, 
top_level_item_number , top_level_item_description, demand_item_number , demand_item_description,
		 created_by, 		 creation_date, 		 last_update_by, 		 last_update_date
)
AS
 SELECT  mmh.fp_minmax_header_id, mmh.plan_name, mmh.org_id, mmh.planning_horizon_days,  org.org, fmd.item_id_m,item.item_number,
 SUM(fmd.quantity) as total_demand,SUM(fmd.quantity)/mmh.planning_horizon_days as avg_daily_demand,
 item.saftey_stock_quantity, 
 (item.pre_processing_lt + item.post_processing_lt + item.processing_lt) as lead_time , item.saftey_stock_days,
 
 ((item.pre_processing_lt + item.post_processing_lt + item.processing_lt + IFNULL(item.saftey_stock_days,0)) * 
 (SUM(fmd.quantity)/mmh.planning_horizon_days)) + IFNULL(item.saftey_stock_quantity,0)  as minmax_min_quantity,
 item.fix_days_supply, 
 
 if(item.fix_days_supply * (SUM(fmd.quantity)/mmh.planning_horizon_days) > 
  ((item.pre_processing_lt + item.post_processing_lt + item.processing_lt + IFNULL(item.saftey_stock_days,0)) * 
 (SUM(fmd.quantity)/mmh.planning_horizon_days)) + IFNULL(item.saftey_stock_quantity,0) ,
 item.fix_days_supply * (SUM(fmd.quantity)/mmh.planning_horizon_days), 
    ((item.pre_processing_lt + item.post_processing_lt + item.processing_lt + IFNULL(item.saftey_stock_days,0)) * 1.5 *
 (SUM(fmd.quantity)/mmh.planning_horizon_days)) +IFNULL(item.saftey_stock_quantity,0)
 ) as minmax_max_quantity, 
 
 IFNULL(item.fix_days_supply, 30) as multibin_fix_days_supply, 
 CEIL((IFNULL((item.pre_processing_lt + item.post_processing_lt + item.processing_lt),0)/
  IFNULL(item.fix_days_supply, 30))) + 1 as minmax_multibin_number,
  
	( ((item.pre_processing_lt + item.post_processing_lt + item.processing_lt + IFNULL(item.saftey_stock_days,0)) * 
 (SUM(fmd.quantity)/mmh.planning_horizon_days)) + IFNULL(item.saftey_stock_quantity,0))/( CEIL((IFNULL((item.pre_processing_lt + item.post_processing_lt + item.processing_lt),0)/
  IFNULL(item.fix_days_supply, 30)))) as minmax_multibin_size,
  
		(((item.pre_processing_lt + item.post_processing_lt + item.processing_lt + IFNULL(item.saftey_stock_days,0)) * 
 (SUM(fmd.quantity)/mmh.planning_horizon_days)) + IFNULL(item.saftey_stock_quantity,0)) + 1 as multibin_minmax_quantity,
 fh.forecast,fh.description as forecast_description, 
	 fmd.fp_minmax_demand_id, fmd.plan_id,  fmd.demand_item_id_m,
		 fmd.toplevel_demand_item_id_m, fmd.demand_type, fmd.source,
		  item.item_description, 
		 item2.item_number as top_level_item_number , item2.item_description as top_level_item_description,
		 item3.item_number as demand_item_number , item3.item_description as demand_item_description,
		 fmd.created_by, 		 fmd.creation_date, 		 fmd.last_update_by, 		 fmd.last_update_date
		 
	
   FROM fp_minmax_demand fmd
	 LEFT JOIN fp_minmax_header mmh ON mmh.fp_minmax_header_id = fmd.plan_id
	 LEFT JOIN fp_forecast_header fh ON fh.fp_forecast_header_id = fmd.source
	 LEFT JOIN item ON item.item_id_m = fmd.item_id_m
	 LEFT JOIN item item2 ON item2.item_id_m = fmd.toplevel_demand_item_id_m AND item2.item_id_m = item2.item_id
	 LEFT JOIN item item3 ON item3.item_id_m = fmd.demand_item_id_m AND item3.item_id_m = item3.item_id
	 LEFT JOIN org ON org.org_id = mmh.org_id
	 GROUP BY fmd.item_id_m

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
