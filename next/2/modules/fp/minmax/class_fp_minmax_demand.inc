<?php

class fp_minmax_demand extends dbObject {

 public static $table_name = "fp_minmax_demand";
 public static $primary_column = "fp_minmax_demand_id";
 public static $key_column = 'item_id_m';
 public static $module = "fp";
 public $field_a = [
		 'fp_minmax_demand_id',
		 'plan_id',
		 'item_id_m',
		 'quantity',
		 'demand_item_id_m',
		 'toplevel_demand_item_id_m',
		 'demand_type',
		 'source',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'fp_minmax_demand_id',
		 'plan_id',
		 'item_id_m',
 ];
 public $column = [
		 'fp_minmax_demand_id',
		 'plan_id',
		 'item_id_m',
		 'quantity',
		 'demand_item_id_m',
		 'demand_type',
		 'source'
 ];
 public $requiredField = [
		 'plan_id',
		 'item_id_m',
 ];
 public $search = [
		 '_update_path' => 'form.php?class_name=minmax_header',
		 '_show_update_path' => 1,
//		 '_update_action_meassge' => 'Update',
//		 '_show_view_path' => 1,
////		 '_view_action_meassge' => 'View',
////		 '_extra_path' => '',
 ];
 public $pageTitle = " Min Max Demand "; //page Title
 public $search_functions = [
		 'Organization' => 'search_org_name',
		 'MM Planner' => 'search_minmax_planner',
		 'Item Number From' => 'search_item_number_from',
		 'Item Number To' => 'search_item_number_to',
		 'Item Id From' => 'search_item_id_m_from',
		 'Item Id To' => 'search_item_id_m_to'
 ];
 public $fp_minmax_demand_id;
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

}

?>
