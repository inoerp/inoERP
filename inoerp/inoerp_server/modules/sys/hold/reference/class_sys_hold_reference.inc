<?php

 class sys_hold_reference extends dbObject {

  public static $table_name = "sys_hold_reference";
  public static $primary_column = "sys_hold_reference_id";
  public static $key_column = 'reference_id';
  public static $module = "sys";
  public $field_a = [
   'sys_hold_reference_id',
   'hold_code',
   'reference_table',
   'reference_id',
   'hold_applied_by',
   'hold_applied_on',
   'hold_count',
   'application_reason',
   'hold_removed_by',
   'hold_removed_on',
   'removal_reason',
  ];
  public $initial_search = [
   'hold_code',
   'reference_table',
   'reference_id',
  ];
  public $requiredField = [
   'hold_code',
   'reference_table',
   'reference_id',
  ];
  public $fields_inForm_notInDataBase = [
   'hold_id',
   'hold_name',
   'hold_type',
   'manual_released_cb',
   'access_level',
   'description',
   'release_hold_cb'
  ];
  public $sys_hold_reference_id;
  public $hold_id;
  public $reference_table;
  public $reference_id;
  public $hold_applied_by;
  public $hold_applied_on;
  public $application_reason;
  public $hold_removed_by;
  public $hold_removed_on;
  public $removal_reason;
  public $hold_count;
  public $hold_code;
  public $hold_name;
  public $hold_type;
  public $access_level;
  public $manual_released_cb;
  public $description;
  public $release_hold_cb;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " System Holds  "; //page Title

  public function _before_save() {
   
  }

  Public static function find_by_po_asl_lineId($po_asl_line_id) {
   $sql = " SELECT * FROM " . self::$table_name . " WHERE po_asl_line_id = '{$po_asl_line_id}' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : null;
  }

  public function findBy_referenceTableId($reference_table = '', $reference_id = '') {
   $reference_table = !empty($reference_table) ? $reference_table : $this->reference_table;
   $reference_id = !empty($reference_id) ? $reference_id : $this->reference_id;
   $sql = " SELECT * FROM " . self::$table_name;
   $sql .= " WHERE reference_table = :reference_table AND reference_id = :reference_id ";
   $value_a = ['reference_table' => $reference_table, 'reference_id' => $reference_id];
   $result = $this->findBySql($sql, $value_a);
//   pa($result);
   return !empty($result) ? $result : false;
  }

  public function verify_existing_hold($reference_table = '', $reference_id = '') {
   $reference_table = !empty($reference_table) ? $reference_table : $this->reference_table;
   $reference_id = !empty($reference_id) ? $reference_id : $this->reference_id;
   $sql = " SELECT * FROM " . self::$table_name;
   $sql .= " WHERE reference_table = :reference_table AND reference_id = :reference_id AND hold_removed_by IS NULL ";
   $value_a = ['reference_table' => $reference_table, 'reference_id' => $reference_id];
   $result = $this->findBySql($sql, $value_a);
//   pa($result);
   return !empty($result) ? $result : false;
  }

  public function findBy_referenceTableId_holdCode($only_open_holds = false) {
   global $dbc;
   $reference_table = !empty($reference_table) ? $reference_table : $this->reference_table;
   $reference_id = !empty($reference_id) ? $reference_id : $this->reference_id;
   $hold_code = !empty($hold_code) ? $hold_code : $this->hold_code;
   $sql = " SELECT * FROM " . self::$table_name;
   $sql .= " WHERE reference_table = :reference_table AND reference_id = :reference_id AND hold_code = :hold_code ";
   if ($only_open_holds) {
    $sql .= " AND hold_removed_by IS NULL ";
   }
   $stmt = $dbc->connection->prepare(" $sql ");
   $stmt->bindParam(':reference_table', $reference_table);
   $stmt->bindParam(':reference_id', $reference_id);
   $stmt->bindParam(':hold_code', $hold_code);
   $stmt->setFetchMode(PDO::FETCH_INTO, $this);
   try {
    $stmt->execute();
    $result = $stmt->fetch();
   } catch (PDOException $e) {
    echo "No Records Found" . $e->getMessage();
   }
   if (!empty($result)) { //should not be used. Use only when a copy of the class is required
    return $result;
   } else {
    return false;
   }
  }

  public static function find_by_referenceTableId($reference_table, $reference_id) {
   $sql = " SELECT * FROM " . self::$table_name;
   $sql .= " WHERE reference_table = '{$reference_table}' AND reference_id = '{$reference_id}' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

  public static function find_by_referenceTableId_holdCode($reference_table, $reference_id, $hold_code) {
   $sql = " SELECT * FROM " . self::$table_name;
   $sql .= " WHERE reference_table = '{$reference_table}' AND reference_id = '{$reference_id}' "
     . " AND hold_code = '{$hold_code}' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

 }

//end of sys_hold_reference class
?>