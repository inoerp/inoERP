<?php

class fp_mrp_demand_v extends dbObject {

 protected static $table_name = "fp_mrp_demand_v";
 public static $primary_column = "fp_mrp_demand_id";
 public static $key_column = 'item_id';
 public static $module = "fp";
 public $field_a = [
		 'plan_name',
		 'org_id',
		 'planning_horizon_days',
		 'org',
		 'forecast',
		 'forecast_description',
		 'fp_mrp_demand_id',
		 'fp_mrp_header_id',
		 'item_id',
		 'quantity',
		 'demand_item_id',
		 'toplevel_demand_item_id',
		 'demand_type',
		 'source',
		 'item_number',
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
		 'forecast',
		 'item_number',
		 'quantity',
		 'top_level_item_number',
		 'demand_item_number',
		 'fp_mrp_demand_id',
		 'created_by',
		 'creation_date'
 ];
 public $requiredField = [
		 'fp_mrp_header_id',
		 'item_id',
 ];
 public $search = [
		 '_view_path' => 'form.php?class_name=fp_mrp_demand',
//		 '_show_view_path' => 1,
////		 '_view_action_meassge' => 'View',
////		 '_extra_path' => '',
 ];
 public $pageTitle = " Min Max Demand "; //page Title
 public $search_functions = [
		 'Organization' => 'search_org_name',
		 'MM Planner' => 'search_mrp_planner',
		 'Item Number From' => 'search_item_number_from',
		 'Item Number To' => 'search_item_number_to',
		 'Item Id From' => 'search_item_id_from',
		 'Item Id To' => 'search_item_id_to'
 ];
 public $fp_mrp_demand_v_id;
 public $fp_mrp_header_id;
 public $item_id;
 public $quantity;
 public $demand_item_id;
 public $toplevel_demand_item_id;
 public $demand_type;
 public $source;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function deleteBy_planId($fp_mrp_header_id) {
	$dbc = new dbc();
	$sql = " DELETE FROM  ";
	$sql .= self::$table_name;
	$sql .= " WHERE  fp_mrp_header_id = :fp_mrp_header_id ";
	$stmt = $dbc->connection->prepare($sql);
	$stmt->bindParam(':fp_mrp_header_id', $fp_mrp_header_id);
//	echo '<div class="message"><br/>$sql is : ' . $sql . ' and primary column is' . $this->$primary_column . '</div>';
	try {
	 $stmt->execute();
	 $dbc->connection->commit();
	 $this->msg = 1;
	 echo "<div class='message'>Records are sucessfully deleted.</div>";
	} catch (PDOException $e) {
	 $this->msg = 0;
	 echo "<div class='message'>failing for sql is $sql</div>";
	 echo "Record could not be updated !!: " . $e->getMessage();
	}
	return $this->msg;
 }

 private function create_fp_mrp_demand_v() {
	$sql = "
CREATE OR REPLACE VIEW fp_mrp_demand_v
(
plan_name, org_id, planning_horizon_days, org, 	 
forecast,forecast_description, 
	 fp_mrp_demand_id, fp_mrp_header_id, item_id, quantity,demand_item_id,
		 toplevel_demand_item_id, demand_type, source,
		 item_number, item_description, 
		top_level_item_number , top_level_item_description,
		 demand_item_number ,demand_item_description,
		 	 created_by, 		 creation_date, 		 last_update_by, 		 last_update_date
)
AS
 SELECT 
mrph.mrp_name, mrph.org_id, mrph.planning_horizon_days, org.org, 	 
	 fmd.fp_mrp_demand_id, fmd.fp_mrp_header_id, fmd.item_id, fmd.quantity,fmd.demand_item_id,
		 fmd.toplevel_demand_item_id, fmd.source_type, fmd.primary_source_type, fmd.source_header_id, fmd.source_line_id,
		 fh.forecast as order_number ,fmd.source_line_id as order_line, 
		 item.item_number, item.item_description, 
		 item2.item_number as top_level_item_number , item2.item_description as top_level_item_description,
		 item3.item_number as demand_item_number , item3.item_description as demand_item_description,
		 fmd.created_by, 		 fmd.creation_date, 		 fmd.last_update_by, 		 fmd.last_update_date
		 
	
   FROM fp_mrp_demand fmd
	 LEFT JOIN fp_mrp_header mrph ON mrph.fp_mrp_header_id = fmd.fp_mrp_header_id
	 LEFT JOIN fp_forecast_header fh ON fh.fp_forecast_header_id = fmd.source_header_id
	 LEFT JOIN item ON item.item_id = fmd.item_id
	 LEFT JOIN item item2 ON item2.item_id = fmd.toplevel_demand_item_id
	 LEFT JOIN item item3 ON item3.item_id = fmd.demand_item_id
	 LEFT JOIN org ON org.org_id = mrph.org_id
	 
WHERE fmd.primary_source_type = 'Forecast'

UNION

 SELECT 
mrph.mrp_name, mrph.org_id, mrph.planning_horizon_days, org.org, 	 
	 fmd.fp_mrp_demand_id, fmd.fp_mrp_header_id, fmd.item_id, fmd.quantity,fmd.demand_item_id,
		 fmd.toplevel_demand_item_id, fmd.source_type, fmd.primary_source_type, fmd.source_header_id, fmd.source_line_id,
		 ssh.so_number as order_number ,soline.line_number as order_line, 
		 item.item_number, item.item_description, 
		 item2.item_number as top_level_item_number , item2.item_description as top_level_item_description,
		 item3.item_number as demand_item_number , item3.item_description as demand_item_description,
		 fmd.created_by, 		 fmd.creation_date, 		 fmd.last_update_by, 		 fmd.last_update_date
		 
	
   FROM fp_mrp_demand fmd
	 LEFT JOIN fp_mrp_header mrph ON mrph.fp_mrp_header_id = fmd.fp_mrp_header_id
	 LEFT JOIN sd_so_header ssh ON ssh.sd_so_header_id = fmd.source_header_id
	 LEFT JOIN sd_so_line soline ON soline.sd_so_line_id = fmd.source_line_id
	 LEFT JOIN item ON item.item_id = fmd.item_id
	 LEFT JOIN item item2 ON item2.item_id = fmd.toplevel_demand_item_id
	 LEFT JOIN item item3 ON item3.item_id = fmd.demand_item_id
	 LEFT JOIN org ON org.org_id = mrph.org_id
	 
WHERE fmd.primary_source_type = 'Sales_Order';

";
 }

}

?>
