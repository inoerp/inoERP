<?php

class fp_kanban_demand_v extends dbObject {

 public static $form_class_name = "fp_kanban_demand";
 public static $table_name = "fp_kanban_demand_v";
 public static $primary_column = "fp_kanban_demand_id";
 public static $key_column = 'item_id_m';
 public static $module = "fp";
 public $field_a = [
  'plan_name',
  'org_id',
  'planning_horizon_days',
  'org',
  'item_number',
  'item_description',
  'top_level_item_number',
  'top_level_item_description',
  'quantity',
  'forecast',
  'forecast_description',
  'fp_kanban_demand_id',
  'plan_id',
  'item_id_m',
  
  'demand_item_id_m',
  'toplevel_demand_item_id_m',
  'demand_type',
  'source',
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
 public $requiredField = [
  'plan_id',
  'item_id_m',
 ];
 public $search = [
  '_view_path' => 'form.php?class_name=fp_kanban_demand',
//		 '_show_view_path' => 1,
////		 '_view_action_meassge' => 'View',
////		 '_extra_path' => '',
 ];
 public $pageTitle = " Kanban Demand "; //page Title
 public $search_functions = [
  'Organization' => 'search_org_name',
  'Kanban Planner' => 'search_kanban_planner',
  'Item Number From' => 'search_item_number_from',
  'Item Number To' => 'search_item_number_to',
  'Item Id From' => 'search_item_id_m_from',
  'Item Id To' => 'search_item_id_m_to'
 ];
 public $fp_kanban_demand_v_id;
 public $plan_id;
 public $item_id_m;
 public $quantity;
 public $demand_item_id_m;
 public $toplevel_demand_item_id_m;
 public $demand_type;
 public $source;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function deleteBy_planId($plan_id) {
  $dbc = new dbc();
  $sql = " DELETE FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE  plan_id = :plan_id ";
  $stmt = $dbc->connection->prepare($sql);
  $stmt->bindParam(':plan_id', $plan_id);
//	echo '<div class="message"><br/>$sql is : ' . $sql . ' and primary column is' . $this->$primary_column . '</div>';
  try {
   $stmt->execute();
   $dbc->connection->commit();
   $this->msg = 1;
   echo "<div class='message'>Records are Successfullydeleted.</div>";
  } catch (PDOException $e) {
   $this->msg = 0;
   echo "<div class='message'>failing for sql is $sql</div>";
   echo "Record could not be updated !!: " . $e->getMessage();
  }
  return $this->msg;
 }

 private function create_fp_kanban_demand_v() {
  $sql = "
CREATE OR REPLACE VIEW fp_kanban_demand_v
(
plan_name, org_id, planning_horizon_days, org, 	 
forecast,forecast_description, 
	 fp_kanban_demand_id, plan_id, item_id_m, quantity,demand_item_id_m,
		 toplevel_demand_item_id_m, demand_type, source,
		 item_number, item_description, 
		top_level_item_number , top_level_item_description,
		 demand_item_number ,demand_item_description,
		 	 created_by, 		 creation_date, 		 last_update_by, 		 last_update_date
)
AS
 SELECT 
mmh.plan_name, mmh.org_id, mmh.planning_horizon_days, org.org, 	 
fh.forecast,fh.description as forecast_description, 
	 fmd.fp_kanban_demand_id, fmd.plan_id, fmd.item_id_m, fmd.quantity,fmd.demand_item_id_m,
		 fmd.toplevel_demand_item_id_m, fmd.demand_type, fmd.source,
		 item.item_number, item.item_description, 
		 item2.item_number as top_level_item_number , item2.item_description as top_level_item_description,
		 item3.item_number as demand_item_number , item3.item_description as demand_item_description,
		 fmd.created_by, 		 fmd.creation_date, 		 fmd.last_update_by, 		 fmd.last_update_date
		 
	
   FROM fp_kanban_demand fmd
	 LEFT JOIN fp_kanban_planner_header mmh ON mmh.fp_kanban_planner_header_id = fmd.plan_id
	 LEFT JOIN fp_forecast_header fh ON fh.fp_forecast_header_id = fmd.source
	 LEFT JOIN item ON item.item_id_m = fmd.item_id_m
	 LEFT JOIN item item2 ON item2.item_id_m = fmd.toplevel_demand_item_id_m
	 LEFT JOIN item item3 ON item3.item_id_m = fmd.demand_item_id_m
	 LEFT JOIN org ON org.org_id = mmh.org_id

";
 }

}

?>
