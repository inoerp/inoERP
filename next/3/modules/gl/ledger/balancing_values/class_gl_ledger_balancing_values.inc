<?php

class gl_ledger_balancing_values extends dbObject {

//protected static variables
 public static $module = "gl";
 public static $table_name = "gl_ledger_balancing_values";
  public static $parent_primary_column = "gl_ledger_id";
//protected variables
//public static varibales - required to be accessed with out intantiating the class
 public static $primary_column = "gl_ledger_balancing_values_id";
 public static $key_column = "gl_ledger_id";
  public $requiredField = [
		 'balancing_values'
 ];
 public $field_a = [
		 'gl_ledger_balancing_values_id',
		 'gl_ledger_id',
		 'balancing_values',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];

 
 public $description;
 public $column;
 public $gl_ledger_balancing_values_id;
 public $gl_ledger_id;
 public $balancing_values;
  public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

//public attributes used with the class

 public function findBy_ledgerId($ledgerId) {
	$dbc = new dbc();
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE gl_ledger_id = :gl_ledger_id ";
	$stmt = $dbc->connection->prepare($sql);
	$stmt->bindParam(':gl_ledger_id', $ledgerId);
	try {
	 $stmt->execute();
	 $result = $stmt->fetchAll(PDO::FETCH_CLASS | PDO::FETCH_PROPS_LATE, "gl_ledger_balancing_values");
	 return $result;
	} catch (PDOException $p) {
	 print " Execution failed! in gl ledger balancing value findBy Ledger Id: " . $e->getMessage() . "<br/>";
	}
 }
 
  public function _before_showing() {

	if (!empty($this->gl_ledger_balancing_values_id)) {
	 $org = org::find_by_id($this->org_id);
	 $this->org = $org->org;
	 $this->description = $org->description;
	}

	if (!empty($this->ledger_id)) {
	 $this->balancing_segments = '';
	 $balancing = new gl_ledger_balancing_values;
	 $balancing_details = $balancing->findBy_ledgerId($this->ledger_id);
	 foreach ($balancing_details as $objs) {
		$this->balancing_segments .= $objs->balancing_values . ' , ';
	 }
	}
 }

}

//end of path class
?>
