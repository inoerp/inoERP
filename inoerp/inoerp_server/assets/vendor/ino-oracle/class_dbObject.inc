<?php

set_time_limit(0);

class dbObject extends dbc {

// protected static $table_name = "";
//  data base variables as stored database column name
 public static $field_array = [];
//variables used for showing data

 public $initial_search = [];
 public $checkbox = [];
//  public $column = [];
 public $requiredField = [];
 public static $position_array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0];
 public static $control_type_a = [
  'EQUAL' => '=',
  'NE' => '!=',
  'GT' => '>',
  'GTE' => '>=',
  'LT' => '<',
  'LTE' => '<=',
 ];
 public static $db_control_type_a = [
  '=' => '=',
  '!=' => '!=',
  '>' => '>',
  '>=' => '>=',
  '<' => '<',
  '<=' => '<=',
  'LIKE' => ' LIKE ',
  'IS_NULL' => 'IS NULL',
  'IS_NOT_NULL' => 'IS NOT NULL ',
  'LEFT_JOIN' => 'LEFT JOIN',
 ];
 public static $sort_fields_values_a = [
  'ASC' => 'Ascending',
  'DESC' => 'Descending',
  'REMOVE' => 'Remove'
 ];
 public static $list_type_a = [
  'ORDERED' => 'Ordered List',
  'UNORDERED' => 'Unordered List',
 ];
 public static $download_format = [
  'excel_format' => 'Excel',
  'text_format' => 'Text',
  'pdf_format' => 'PDF',
  'pdf_format_list' => 'PDF List',
  'xml_format' => 'XML',
  'worddoc_format' => 'Word Doc',
 ];
 public static $key_column = '';
 public static $parent_primary_column = null;
 public $time;
 public $msg;
 public $conn;
 public $field_a = [];
 public $file_id_values;
 public static $audit_trial = [ 'created_by', 'creation_date', 'last_update_by', 'last_update_date',];

 function __construct() {
  foreach ($this->field_a as $k => $v) {
   if (property_exists($this, $k)) {
    $this->$k = null;
   }
  }
 }

 function query($sql) {
  global $dbc;
  if (!empty($sql)) {
   $prepare = $dbc->connection->prepare($sql);
   try {
    $prepare->execute();
    $result = $prepare->fetchAll(PDO::FETCH_CLASS);
    return $result;
   } catch (PDOException $e) {
    print " Execution failed! in dbObject Query: " . $e->getMessage() . "<br/>";
   }
  }
 }

 public function runSQL($sql, $value_a = '') {
  global $dbc;
  if (empty($dbc->connection)) {
   return false;
  }
  $stmt = $dbc->connection->prepare(" $sql ");
  if (!empty($value_a)) {
   foreach ($value_a as $key => $value) {
    if (!empty($value)) {
     if ($key == 'lmt_no_of_records' OR $key == 'lmt_start_from') {
      $stmt->bindValue(":$key", $value, PDO::PARAM_INT);
     } else {
      $stmt->bindValue(":$key", $value);
     }
    } else {
     $stmt->bindValue(":$key", NULL);
    }
   }
  }
  try {
   $stmt->execute();
  } catch (PDOException $e) {
   echo "Below Query Failed to Execute!: <br>" . $sql . '<br>Error : <br>' . $e->getMessage();
   return 0;
  }
 }

 public function findBy_sql($sql, $param_a = '', $value_a = '') {
  global $dbc;
  if (empty($dbc->connection)) {
   return false;
  }
  $stmt = $dbc->connection->prepare(" $sql ");
  if (!empty($param_a)) {
   foreach ($param_a as $key => $param) {
    if (!empty($value_a[$param])) {
     $stmt->bindValue(":$param", $value_a[$param]);
    } else {
     $stmt->bindValue(":$param", NULL);
    }
   }
  }
  try {
   $stmt->execute();
   $result = $stmt->fetchAll(PDO::FETCH_CLASS);
   return $result;
  } catch (PDOException $e) {
//    echo "Record couldnt be fetched !!: " . $e->getMessage();
   return 0;
  }
 }

 public function findBySql($sql, $value_a = '') {
  global $dbc;
  if (empty($dbc->connection)) {
   return false;
  }
  $stmt = $dbc->connection->prepare(" $sql ");
  if (!empty($value_a)) {
   foreach ($value_a as $key => $value) {
    if (!empty($value)) {
     if ($key == 'lmt_no_of_records' OR $key == 'lmt_start_from') {
      $stmt->bindValue(":$key", $value, PDO::PARAM_INT);
     } else {
      $stmt->bindValue(":$key", $value);
     }
    } else {
     $stmt->bindValue(":$key", NULL);
    }
   }
  }
  try {
   $stmt->execute();
   $result = $stmt->fetchAll(PDO::FETCH_CLASS);
   return $result;
  } catch (PDOException $e) {
//    echo "Record couldnt be fetched !!: " . $e->getMessage();
   return 0;
  }
 }

 protected function write_comment($comment_by, $comment_msg, $comment_sub = '') {
  $comment = new extn_comment();
  $comment->reference_table = static::$table_name;
  $pc = static::$primary_column;
  $comment->reference_id = $this->$pc;
  $comment->comment_by = $comment_by;
  $comment->comment = $comment_msg;
  $comment->subject = $comment_sub;
  $comment->published_cb = 1;
  $comment->save();
 }

 public function findBySql_array($sql = "") {
  $dbc;
  if (empty($dbc->connection)) {
   $dbc = new dbc();
  }
  $prepare = $dbc->connection->prepare($sql);
  $prepare->execute();
  $result = $prepare->fetchAll(PDO::FETCH_NUM);
  return $result;
 }

 public function findFirstColumn_BySql_array($sql = "") {
  global $dbc;
  if (empty($dbc->connection)) {
   $dbc = new dbc();
  }
  $prepare = $dbc->connection->prepare($sql);
  $prepare->execute();
  $result = $prepare->fetchAll(PDO::FETCH_COLUMN);
  return $result;
 }

 /* End of public functions and start of public static functions  */

 public static function show_column_from_table($tableName = "") {
  global $dbc;
  $sql = " SHOW COLUMNS FROM $tableName ";
  $prepare = $dbc->connection->prepare($sql);
  $prepare->execute();
  $result_fetchAll = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
  return $result_fetchAll;
 }

 public static function show_allColumn_from_table($tableName = "") {
  global $dbc;
  $sql = " SHOW COLUMNS FROM $tableName ";
  $prepare = $dbc->connection->prepare($sql);
  $prepare->execute();
  $result_fetchAll = $prepare->fetchAll(PDO::FETCH_CLASS);
  return $result_fetchAll;
 }

 public static function show_table_details($tableName = "") {
  global $dbc;
  $sql = " SHOW COLUMNS FROM $tableName ";
  $prepare = $dbc->connection->prepare($sql);
  $prepare->execute();
  $result_fetchAll = $prepare->fetchAll(PDO::FETCH_CLASS);
  return $result_fetchAll;
 }

 public static function find_by_sql($sql = "") {
  global $dbc;
  $conn = $dbc->connection;
  try {
   $qry = $conn->query($sql);
   $result_fetchAll = $qry->fetchAll(PDO::FETCH_CLASS);
   return $result_fetchAll;
  } catch (Exception $e) {
//    echo "<br>Error @dbObject @@ Line " . __LINE__ . $sql;
   return false;
  }
 }

 public static function find_by_sql_i($sql, $value_a = '') {
  global $dbc;
  if (empty($dbc->connection)) {
   return false;
  }
  $stmt = $dbc->connection->prepare(" $sql ");
  if (!empty($value_a)) {
   foreach ($value_a as $key => $value) {
    if (!empty($value)) {
     if ($key == 'lmt_no_of_records' OR $key == 'lmt_start_from') {
      $stmt->bindValue(":$key", $value, PDO::PARAM_INT);
     } else {
      $stmt->bindValue(":$key", $value);
     }
    } else {
     $stmt->bindValue(":$key", NULL);
    }
   }
  }
  try {
   $stmt->execute();
   $result = $stmt->fetchAll(PDO::FETCH_CLASS);
   return $result;
  } catch (PDOException $e) {
//    echo "Record couldnt be fetched !!: " . $e->getMessage();
   return 0;
  }
 }


  public static function find_by_sql_array($sql = "") {
  global $dbc;
  $conn = $dbc->connection;
  try {
   $qry = $conn->query($sql);
   $result_fetchAll = $qry->fetchAll(PDO::FETCH_NUM);
   return $result_fetchAll;
  } catch (Exception $e) {
//    echo "<br>Error @dbObject @@ Line " . __LINE__ . $sql;
   return false;
  }
 }

 public static function find_by_sql_all($sql = "") {
  global $dbc;
  $prepare = $dbc->connection->prepare($sql);
  $prepare->execute();
  $result_fetchAll = $prepare->fetchAll();
  return $result_fetchAll;
 }

 public static function find_all($order_by = '', $asc_desc = 'ASC') {
  $sql = " SELECT * FROM " . static::$table_name;
  if (!empty($order_by)) {
   $sql .= " ORDER BY $order_by $asc_desc ";
  }
  $result = static::find_by_sql($sql);
  return $result;
 }

 public static function find_few($no_of_records = 2) {
  $sql = " SELECT * FROM " . static::$table_name . " AND ROWNUM = $no_of_records ";
  $result = static::find_by_sql($sql);
  return $result;
 }

 public static function find_some_byIdArray($id_array) {
  $result_array = [];
  foreach ($id_array as $key => $value) {
   $result = static::find_by_id($value);
   array_push($result_array, $result);
  }
  return $result_array;
 }

 public static function count_all() {
  $sql = "SELECT COUNT(*) FROM " . static::$table_name;
  $result = static::find_by_sql_array($sql);
  return !empty($result) ? array_shift2($result) : false;
 }

 public static function count_all_by_sql($sql) {
//   echo "sql is $sql";
  $result = static::find_by_sql_array($sql);
  return !empty($result) ? array_shift2($result) : false;
 }

 public static function find_by_id($id) {
  global $ie;
  global $dbc;
  $sql = " SELECT * FROM ";
  $sql.= static::$table_name;
  $sql.= " WHERE " . static::$primary_column . "= :primary_id ";
  $sql.= " AND ROWNUM = 1 ";
  $stmt = $dbc->connection->prepare(" $sql ");
  $stmt->bindValue(':primary_id', $id);
  try {
   $stmt->execute();
   $result = $stmt->fetchAll(PDO::FETCH_CLASS, static::$table_name);
  } catch (PDOException $e) {
   $result = null;
   $ie->page_exception = ['dbObject findBy id Error : ' => $e->getMessage()];
   echo "Record not found !!: " . $e->getMessage();
  }
//  pa($result);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_id_gl($id, $gl = '>=') {
  global $ie;
  global $dbc;
  $sql = " SELECT * FROM ";
  $sql.= static::$table_name;
  $sql.= " WHERE " . static::$primary_column . ' ' . $gl . " :primary_id ";
  $stmt = $dbc->connection->prepare(" $sql ");
  $stmt->bindParam(':primary_id', $id);
  try {
   $stmt->execute();
   $result = $stmt->fetchAll(PDO::FETCH_CLASS);
  } catch (PDOException $e) {
   $ie->page_exception = ['dbObject findBy id Error : ' => $e->getMessage()];
   echo "Record couldnt be saved!!: " . $e->getMessage();
  }
  return !empty($result) ? $result : false;
 }

 public function findAll_singleRecord_db() {
  $sql = " SELECT * FROM  ";
  $sql .= static::$table_name;
  $sql .= " WHERE rownum <=1 ";

  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : $this;
 }

 public static function find_by_fieldVal(array $dieldVal_a, $order_by = '', $asc_desc = 'ASC') {
  global $ie;
  global $dbc;
  $sql = " SELECT * FROM ";
  $sql.= static::$table_name;
  if (count($dieldVal_a) == 1) {
   foreach ($dieldVal_a as $k => $v) {
    $sql.= " WHERE " . $k . "= '{$v}' ";
   }
  } else if (count($dieldVal_a) > 1) {
   $k_count = 1;
   foreach ($dieldVal_a as $k => $v) {
    $v2 = ($v == 'NULL') ? NULL : $v;
    if ($k_count == 1) {
     if (!empty($v)) {
      if (!empty($v2)) {
       $sql.= " WHERE " . $k . "= '{$v2}' ";
      } else {
       $sql.= " WHERE " . $k . " IS NULL ";
      }
     }
    } else if (!empty($v)) {

     if (!empty($v2)) {
      $sql.= " AND " . $k . "= '{$v2}' ";
     } else {
      $sql.= " AND " . $k . " IS NULL ";
     }
    }
    $k_count++;
   }
  }
// echo $sql;
  if (!empty($order_by)) {
   $sql .= " ORDER BY $order_by $asc_desc ";
  }
  $stmt = $dbc->connection->prepare(" $sql ");
  try {
   $stmt->execute();
   $result = $stmt->fetchAll(PDO::FETCH_CLASS);
  } catch (PDOException $e) {
   $ie->page_exception = ['dbObject findBy id Error : ' => $e->getMessage()];
   echo "Record couldnt be saved!!: " . $e->getMessage();
  }
  return !empty($result) ? $result : false;
 }

 public function findAll() {
  global $ie;
  global $dbc;
  $sql = " SELECT * FROM ";
  $sql.= static::$table_name;
  $stmt = $dbc->connection->prepare(" $sql ");
  try {
   $stmt->execute();
   $result = $stmt->fetchAll(PDO::FETCH_CLASS);
  } catch (PDOException $e) {
   $this->msg = "No Records Found" . $e->getMessage();
  }
  return !empty($result) ? $result : false;
 }

 public function findBy_id($id) {
  global $ie;
  global $dbc;
  $sql = " SELECT * FROM ";
  $sql.= static::$table_name;
  $sql.= " WHERE " . static::$primary_column . "= :primary_id ";
  $sql.= " AND ROWNUM = 1 ";
  $stmt = $dbc->connection->prepare(" $sql ");
  $stmt->bindParam(':primary_id', $id);
  $stmt->setFetchMode(PDO::FETCH_INTO, $this);
  try {
   $stmt->execute();
//	 $result = $stmt->fetchObject();
   $result = $stmt->fetch();
  } catch (PDOException $e) {
   $this->msg = "No Records Found" . $e->getMessage();
  }

  return !empty($result) ? $result : false;
 }

 public function findBy_parentId($id, $order_by_field = '', $order_by_seq = '') {
  global $dbc;
  $order_by_field = empty($order_by_field) ? static::$primary_column : $order_by_field;
  $order_by_seq = empty($order_by_seq) ? 'ASC' : $order_by_seq;
  if (empty($id)) {
   return false;
  }
  $sql = " SELECT * FROM ";
  $sql.= static::$table_name;
  $sql.= " WHERE " . static::$parent_primary_column . " = :primary_id ";
  if (!empty($order_by_field)) {
   $sql.= " ORDER BY {$order_by_field}  ";
   $sql.= " $order_by_seq ";
  }

  $stmt = $dbc->connection->prepare(" $sql ");
  $stmt->bindParam(':primary_id', $id);
  try {
   $stmt->execute();
   $result = $stmt->fetchAll(PDO::FETCH_CLASS);
  } catch (PDOException $e) {
   echo "dbObject findBy parent id Error @dbOject @line " . __LINE__ . $e->getMessage();
   echo " sql is $sql";
  }
  return !empty($result) ? $result : false;
 }

 public static function find_by_parent_id($id, $order_by_field = '', $order_by_seq = 'ASC') {
  $order_by_field = empty($order_by_field) ? static::$key_column : $order_by_field;
  if (empty($id)) {
   return false;
  }
  $sql = " SELECT * FROM ";
  $sql.= static::$table_name;
  $sql.= " WHERE " . static::$parent_primary_column . " = '{$id}' ";
  if (!empty($order_by_field)) {
   $sql.= " ORDER BY {$order_by_field}  ";
   $sql.= " {$order_by_seq} ";
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_id_array($id) {
  global $dbc;
  $sql = "SELECT * FROM " . static::$table_name . " where " . static::$primary_column . " ='{$id}'  AND ROWNUM = 1";
  $result_array = static::find_by_sql_array($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_keyColumn($columnName_val) {
  $sql = "SELECT * FROM " . static::$table_name . " where " . static::$key_column . " ='{$columnName_val}'  AND ROWNUM = 1";
  $result_array = static::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public static function find_by_ColumnNameVal($columnName, $columnVal, $dependent_fields = '', $hidden_fields = '') {
  $sql = "SELECT * FROM " . static::$table_name . " where " . $columnName . " LIKE  '%{$columnVal}%'  ";
  if (!empty($dependent_fields)) {
   foreach ($dependent_fields as $k => $v) {
    if (!empty($k) && !empty($v)) {
     $sql .= " AND $k = '{$v}' ";
    }
   }
  }

  if (!empty($hidden_fields)) {
   foreach ($hidden_fields as $k1 => $v1) {
    if (!empty($k1) && !empty($v1)) {
     $sql .= " AND $k1 = '{$v1}' ";
    }
   }
  }
//  echo $sql;
  $result_array = static::find_by_sql($sql);
  return !empty($result_array) ? ($result_array) : false;
 }

 public static function find_by_oneColumn(array $colmn_details_ap) {
  if (!empty($colmn_details_ap['column_name'])) {
   $column_name = $colmn_details_ap['column_name'];
  } else {
   return null;
  }
  $column_val = !empty($colmn_details_ap['column_value']) ? $colmn_details_ap['column_value'] : null;
  $sql = "SELECT * FROM " . static::$table_name . " where " . $column_name . " ='{$column_val}'  ";
  $result_array = static::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

 public static function find_by_keyColumn_all($columnName_val) {
  $sql = "SELECT * FROM " . static::$table_name . " where " . static::$key_column . " ='{$columnName_val}' ";
  $result_array = static::find_by_sql($sql);
  return !empty($result_array) ? ($result_array) : false;
 }

 public static function find_by_keyColumn_array($columnName_val) {
  global $dbc;
  $sql = "SELECT * FROM " . static::$table_name . " where " . static::$columnName . " ='{$columnName_val}'  AND ROWNUM = 1";
  $result_array = static::find_by_sql_array($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 private static function instantiate($record) {
  $object = new static;
  foreach ($record as $attribute => $value) {
   if ($object->has_attribute($attribute)) {
    $object->$attribute = $value;
   }
  }
  return $object;
 }

 Private function has_attribute($attribute) {
  $object_vars = get_object_vars($this);
  return array_key_exists($attribute, $object_vars);
 }

 public function set_module_default() {
  if (property_exists($this, 'module_defaults')) {
   foreach ($this->module_defaults as $key => $value) {
    if (empty($this->$key)) {
     $this->$key = $value;
    }
   }
  }
 }

 public function validate_requiredField() {
  global $dbc;
  $required_field_flag = true;
  foreach ($this->requiredField as $key => $value) {
   $required_field_flag = $required_field_flag && (isset($this->$value));
   if (empty($this->$value)) {
    echo "<div class='message'> Mandatory $value is missing </div> ";
    $required_field_flag = false;
    break;
   }
  }
  if (!$required_field_flag) {
   $dbc->rollback = true;
  }
  return $required_field_flag;
 }

 public function audit_trial() {
  if (empty($this->creation_date)) {
   $this->creation_date = current_time();
  }
  if (empty($this->created_by)) {
   if ((isset($_SESSION)) && (!empty($_SESSION['user_id']))) {
    $this->created_by = $_SESSION['user_id'];
   } else {
    $this->created_by = '-99';
   }
  }
  $this->last_update_date = current_time();
  if ((isset($_SESSION)) && (!empty($_SESSION['user_id']))) {
   $this->last_update_by = $_SESSION['user_id'];
  } else {
   $this->last_update_by = '-99';
  }
 }

 public function save() {
  $primary_column = static::$primary_column;
  if (empty($this->$primary_column)) {
   $this->create();
  } else {
   $this->update_changesOnly($this->$primary_column);
  }
  return $this->msg;
 }

 public function save_onWebForm() {
  $primary_column = static::$primary_column;
  if (empty($this->$primary_column)) {
   $this->create();
  } else {
   $this->update($this->$primary_column);
  }
  return $this->msg;
 }

 public function create() {
  global $dbc;
  $parent_class_name = get_called_class();
  if (property_exists($parent_class_name, 'primary_column')) {
   $primary_column = static::$primary_column;
  }
  if (property_exists($this, 'field_a')) {
   $field_array = $this->field_a;
  } else {
   $field_array = static::$field_array;
  }

  $field_colums = '';
  foreach ($field_array as $key => $value) {
   $field_colums .= $value . ', ';
  }
  $field_colums = rtrim($field_colums, ', ');

  $field_values = '';
  foreach ($field_array as $key => $value) {
   $field_values .= ':' . $value . ', ';
  }
  $field_values = rtrim($field_values, ', ');
//write SQL
  $sql = " INSERT INTO ";
  $sql.= static::$table_name;
  $sql.= ' ( ';
  $sql.= $field_colums;
  $sql.= ' ) ';
  $sql.= 'VALUES';
  $sql.= ' ( ';
  $sql.= $field_values;
  $sql.= ' ) ';
  $stmt = $dbc->connection->prepare(" $sql ");


  //Bind parameters
  foreach ($field_array as $key => $value) {
   if (in_array($value, self::$audit_trial)) {
    continue;
   }
   if (!empty($this->$value)) {
    $stmt->bindParam(":$value", $this->$value);
   } else {
    $stmt->bindvalue(":$value", null, PDO::PARAM_INT);
   }
  }

  //get next id
  $next_seq = static::$table_name . '_seq.NEXTVAL';
  $sh = $dbc->connection->prepare("SELECT $next_seq AS next_seq_id FROM DUAL");
  $sh->execute();
  $nextInsertId = $sh->fetchColumn(0);
  $stmt->bindParam(":$primary_column", $nextInsertId);

  if (in_array('created_by', $field_array)) {
   $last_update_date = current_time(1, 'ORACLE');
   if (!empty($_SESSION['user_id'])) {
    $last_update_by = $_SESSION['user_id'];
   } else {
    $last_update_by = '99';
   }
   $stmt->bindParam(':created_by', $last_update_by);
   $stmt->bindParam(':last_update_by', $last_update_by);

   $stmt->bindvalue(":creation_date", $last_update_date);
   $stmt->bindvalue(":last_update_date", $last_update_date);
  }


  try {
   $stmt->execute();
   if (!empty($nextInsertId)) {
    $this->$primary_column = $nextInsertId;
   }
   $this->msg = 1;
  } catch (PDOException $e) {
   $this->msg = 0;
   $dbc->rollback = 1;
   echo "<br>Record couldnt be saved. Error @ " . basename(__FILE__) . ' @@line' . __LINE__ . '<br>' . $e->getMessage() . "<br>";
  }
  return $this->msg;
 }

//update function
 public function update($id) {
  global $dbc;
  if (property_exists($this, 'field_a')) {
   $field_array = $this->field_a;
  } else {
   $field_array = static::$field_array;
  }

  if (property_exists($this, 'fields_inDataBase_notInForm')) {
   $field_array = array_diff($field_array, $this->fields_inDataBase_notInForm);
  }

  $field_stmt = '';

  foreach ($field_array as $key => $value) {
   if (in_array($value, array('created_by', 'creation_date'))) {
    continue;
   }
   $field_stmt .= strtoupper($value) . ' = :' . $value . ', ';
  }

  $field_stmt_f = rtrim($field_stmt, ', ');
//write SQL
  $sql = " UPDATE ";
  $sql.= static::$table_name;
  $sql .= " SET ";
  $sql.= $field_stmt_f;
  $sql.= " WHERE " . strtoupper(static::$primary_column) . "= :primary_id ";

  $stmt = $dbc->connection->prepare(" $sql ");
  //Bind parameters
  foreach ($field_array as $key => $value) {
   if (in_array($value, self::$audit_trial)) {
    continue;
   }
   if (!empty($this->$value)) {
    $stmt->bindParam(":$value", $this->$value);
   } else {
    $stmt->bindvalue(":$value", null, PDO::PARAM_INT);
   }
  }

  if (in_array('last_update_by', $field_array)) {
   $last_update_date = current_time(1, 'ORACLE');
   if (!empty($_SESSION['user_id'])) {
    $last_update_by = $_SESSION['user_id'];
   } else {
    $last_update_by = '-99';
   }
   $stmt->bindParam(':last_update_by', $last_update_by);
   $stmt->bindvalue(":last_update_date", $last_update_date);
  }
  $stmt->bindParam(':primary_id', $id);
  try {
   $stmt->execute();
   $this->msg = 1;
  } catch (PDOException $e) {
   $this->msg = 0;
   $dbc->rollback = 1;
   echo "<div class='message'>failing for sql is $sql</div>";
   echo "<br>Record couldnt be updated!!: Error Code : DBO01 . Error @dbObject @@ Line " . __LINE__ . '<br>' . $e->getMessage() . "<br>";
  }
  return $this->msg;
 }

 public function update_changesOnly($id) {
  global $dbc;
  $bind_params_a = [];
  if (property_exists($this, 'field_a')) {
   $field_array = $this->field_a;
  }

  if (property_exists($this, 'fields_inDataBase_notInForm')) {
   $field_array = array_diff($field_array, $this->fields_inDataBase_notInForm);
  }

  $field_stmt = '';
  foreach ($field_array as $key => $value) {
   if (in_array($value, array('created_by', 'creation_date'))) {
    continue;
   }
   if (isset($this->$value)) {
    $field_stmt .= $value . ' = :' . $value . ', ';
    array_push($bind_params_a, $value);
   }
  }
  $field_stmt_f = rtrim($field_stmt, ', ');
//write SQL
  $sql = " UPDATE ";
  $sql.= static::$table_name;
  $sql .= " SET ";
  $sql.= $field_stmt_f;
  $sql.= " WHERE " . static::$primary_column . "= :primary_id ";
  $stmt = $dbc->connection->prepare(" $sql ");


//Bind parameters
  foreach ($field_array as $key => $value) {
   if (in_array($value, self::$audit_trial)) {
    continue;
   }
   if (isset($this->$value)) {
    $stmt->bindParam(":$value", $this->$value);
   }
  }

  if (in_array('last_update_by', $bind_params_a)) {
   $last_update_date = current_time(1, 'ORACLE');
   if (!empty($_SESSION['user_id'])) {
    $last_update_by = $_SESSION['user_id'];
   } else {
    $last_update_by = '-99';
   }
   $stmt->bindParam(':last_update_by', $last_update_by);
   $stmt->bindParam(':last_update_date', $last_update_date);
  }
  $stmt->bindParam(':primary_id', $id);

  try {
   $stmt->execute();
   $this->msg = 1;
  } catch (PDOException $e) {
   $this->msg = 0;
   $dbc->rollback = 1;
   echo "<div class='message'>failing for sql is $sql</div>";
   echo "<br>Record couldnt be updated!!: Error Code : DBO01 . Error @dbObject @@ Line " . __LINE__ . '<br>' . $e->getMessage() . "<br>";
  }
  return $this->msg;
 }

 public function save_singeRecord_db() {
  global $dbc;

  if (property_exists($this, 'field_a')) {
   $field_array = $this->field_a;
  }
  $field_stmt = '';
  foreach ($field_array as $key => $value) {
   if (in_array($value, array('created_by', 'creation_date'))) {
    continue;
   }
   $field_stmt .= $value . ' = :' . $value . ', ';
  }
  $field_stmt_f = rtrim($field_stmt, ', ');
//write SQL
  $sql = " UPDATE ";
  $sql.= static::$table_name;
  $sql .= " SET ";
  $sql.= $field_stmt_f;
  $stmt = $dbc->connection->prepare(" $sql ");
//Bind parameters
  foreach ($field_array as $key => $value) {
   if (in_array($value, self::$audit_trial)) {
    continue;
   }
   $stmt->bindParam(":$value", $this->$value);
  }

  if (in_array('last_update_by', $field_array)) {
   $last_update_date = current_time();
   if (!empty($_SESSION['user_id'])) {
    $last_update_by = $_SESSION['user_id'];
   } else {
    $last_update_by = '-99';
   }
   $stmt->bindParam(':last_update_by', $last_update_by);
   $stmt->bindParam(':last_update_date', $last_update_date);
  }

  try {
   $stmt->execute();
   $this->msg = 1;
  } catch (PDOException $e) {
   $this->msg = 0;
   echo "<div class='message'>failing for sql is $sql</div>";
   echo "Record could not be updated !!: " . $e->getMessage();
  }
  return $this->msg;
 }

 public function delete($show_msg = true) {
  global $dbc;
  $primary_column = static::$primary_column;
  $sql = " DELETE FROM ";
  $sql .= static::$table_name;
  $sql .= " WHERE  ";
  $sql .= $primary_column . "= :primary_column ";

  $stmt = $dbc->connection->prepare($sql);
  $stmt->bindParam(':primary_column', $this->$primary_column);
  echo '<div class="alert alert-danger alert-dismissible" role="alert">
       <button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>';
  try {
   $stmt->execute();
   $this->msg = 1;
   if($show_msg){
       echo "<div class='message'>Record is Successfully deleted.</div>";
   }
   
   $dbc->confirm();
  } catch (PDOException $e) {
   $this->msg = 0;
   $dbc->rollback = 1;
   echo "<div class='message'>failing for sql is $sql</div>";
   echo "<br>Record couldnt be deleted!!: Error Code : DBO02 . Error @dbObject @@ Line " . __LINE__ . '<br>' . $e->getMessage() . "<br>";
  }
  echo '</div>';
  return $this->msg;
 }

 public function deleteBy_parentId($id) {
  if (empty($id)) {
   return false;
  }
  $dbc = new dbc();
  $sql = " DELETE FROM  ";
  $sql.= static::$table_name;
  $sql.= " WHERE " . static::$parent_primary_column . "= :primary_id ";
  $stmt = $dbc->connection->prepare($sql);
  $stmt->bindParam(':primary_id', $id);
  echo '<div class="alert alert-danger alert-dismissible" role="alert">
       <button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>';
  try {
   $stmt->execute();
//	 $dbc->connection->commit();
   $this->msg = 1;
   $dbc->confirm();
   echo "<div class='message'>Records are Successfully deleted.</div>";
  } catch (PDOException $e) {
   $this->msg = 0;
   $dbc->rollback = 1;
   echo "<div class='message'>failing for sql is $sql</div>";
   echo "<br>Record couldnt be deleted !!: Error Code : DBO02 . Error @dbObject @@ Line " . __LINE__ . '<br>' . $e->getMessage() . "<br>";
  }
  echo '</div>';
  return $this->msg;
 }

 protected function deleteBy_orgId($org_id) {
  if (empty($id)) {
   return false;
  }
  $dbc = new dbc();
  $sql = " DELETE FROM  ";
  $sql.= static::$table_name;
  $sql.= " WHERE org_id = :org_id ";
  $stmt = $dbc->connection->prepare($sql);
  $stmt->bindParam(':org_id', $org_id);
  echo '<div class="alert alert-danger alert-dismissible" role="alert">
       <button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>';
  try {
   $stmt->execute();
//	 $dbc->connection->commit();
   $this->msg = 1;
   $dbc->confirm();
   echo "<div class='message'>Records are Successfully deleted.</div>";
  } catch (PDOException $e) {
   $dbc->rollback = 1;
   $this->msg = 0;
   echo "<div class='message'>failing for sql is $sql</div>";
   echo "<br>Record couldnt be deleted!!: Error Code : DBO02 . Error @dbObject @@ Line " . __LINE__ . '<br>' . $e->getMessage() . "<br>";
  }
  echo '</div>';
  return $this->msg;
 }

 public function _update_extra_field($reference_key_name, $reference_key_value, $reference_type = 'table') {
  global $dbc;
  if (!empty($_POST['sys_extra_field_id'])) {
   foreach ($_POST['sys_extra_field_id'] as $k => $v) {
    if (empty($v)) {
     continue;
    }
    $ef_i = new sys_extra_field_instance();
    foreach ($ef_i->field_a as $key => $value) {
     if (isset($_POST[$value][$k])) {
      $ef_i->$value = $_POST[$value][$k];
     }
    }
    if (!empty($ef_i->list_values)) {
     $list_values = explode(',', $ef_i->list_values);
     $ef_i->list_values = serialize($list_values);
    }
    $ef_i->sys_extra_field_id = $v;
    $ef_i->reference_type = $reference_type;
    $ef_i->reference_key_name = $reference_key_name;
    $ef_i->reference_key_value = $reference_key_value;
    try {
     $ef_i->save();
    } catch (Exception $e) {
     $dbc->rollback = true;
     echo "<br>Failed to save extra field data. Error @ bom_routing_line @@ line " . __LINE__ . $e->getMessage();
    }
   }
  }
 }

 public function _update_secondary_field($reference_key_name, $reference_key_value, $reference_type = 'table') {
  global $dbc;
  if (!empty($_POST['sys_secondary_field_id'])) {
   foreach ($_POST['sys_secondary_field_id'] as $k => $v) {
    if (empty($v)) {
     continue;
    }
    $ef_i = new sys_secondary_field_inst();
    foreach ($ef_i->field_a as $key => $value) {
     if (isset($_POST[$value][$k])) {
      $ef_i->$value = $_POST[$value][$k];
     }
    }
    if (!empty($ef_i->list_values)) {
     $list_values = explode(',', $ef_i->list_values);
     $ef_i->list_values = serialize($list_values);
    }
    $ef_i->sys_secondary_field_id = $v;
    $ef_i->reference_type = $reference_type;
    $ef_i->reference_key_name = $reference_key_name;
    $ef_i->reference_key_value = $reference_key_value;
    $ef_i->audit_trial();
    try {
     $ef_i->save();
    } catch (Exception $e) {
     $dbc->rollback = true;
     echo "<br>Failed to save secondary field data. Error @ bom_routing_line @@ line " . __LINE__ . $e->getMessage();
    }
   }
  }
 }

 public function _save_secondary_field($secondary_fields_a, $ref_key_val) {
  global $dbc;
//   pa($secondary_fields_a);
//   pa($_POST);
  foreach ($secondary_fields_a as $sf) {
   if (empty($_POST[$sf->sys_field_name])) {
    continue;
   }
   $class = 'sf_' . $sf->sys_field_name;
   $key_column = $class . '_id';
   $value_column = $class . '_value';
   $field_name = $sf->sys_field_name;
   $$class = new stdClass();
   $secondary_fields = extn_view::find_columns_of_table($class);
//    pa($secondary_fields);
   //check if record already exists
   $checkSql = " SELECT * FROM $class WHERE reference_type = 'table' AND reference_key_name='{$sf->reference_key_name}' "
    . "  AND reference_key_value='{$ref_key_val}' AND ROWNUM = 1";

   $checkResult = self::find_by_sql($checkSql);

   //if $checkResult is not empty update the existing data else create record
   if (!empty($checkResult)) {
    $key_column_value = $checkResult[0]->$key_column;
    if (empty($_POST['file_id_values'][0]) && ($checkResult[0]->$value_column == $_POST[$field_name][0])) {
     continue;
    } else if (!empty($_POST['file_id_values'][0]) && ($checkResult[0]->$value_column == $_POST['file_id_values'][0])) {
     continue;
    }
    //Update the existing content
    $field_stmt = '';
    $field_stmt .= " $value_column = :$value_column ,";
    $field_stmt .= ' last_update_date = :last_update_date ,';
    $field_stmt .= ' last_update_by = :last_update_by ';

//write SQL
    $sql = " UPDATE ";
    $sql.= $class;
    $sql .= " SET ";
    $sql.= $field_stmt;
    $sql.= " WHERE $key_column = '{$key_column_value}' ";
    $stmt = $dbc->connection->prepare(" $sql ");
    //Bind parameters
    if (empty($_POST['file_id_values'][0])) {
     $stmt->bindParam(":$value_column", $_POST[$field_name][0]);
    } else {
     $stmt->bindParam(":$value_column", $_POST['file_id_values'][0]);
    }
    $stmt->bindvalue(':last_update_date', current_time(), PDO::PARAM_INT);
    $stmt->bindvalue(':last_update_by', $_SESSION['username'], PDO::PARAM_INT);
    try {
     $stmt->execute();
     echo "<br>Record is Successfully saved in $class";
    } catch (PDOException $e) {
     $dbc->rollback = 1;
     echo "<br> $sql <br>";
     echo "<br>Record couldnt be saved. Error @wip_wo_work_bench_line @@ Line " . __LINE__ . $e->getMessage() . "<br/>";
    }
   } else {
    $field_colums = '';
    foreach ($secondary_fields as $key => $value) {
     $field_colums .= $value . ', ';
    }
    $field_colums = rtrim($field_colums, ', ');

    $field_values = '';
    foreach ($secondary_fields as $key1 => $value1) {
     $field_values .= ':' . $value1 . ', ';
    }
    $field_values = rtrim($field_values, ', ');
//write SQL
    $sql = " INSERT INTO ";
    $sql.= $class;
    $sql.= ' ( ';
    $sql.= $field_colums;
    $sql.= ' ) ';
    $sql.= 'VALUES';
    $sql.= ' ( ';
    $sql.= $field_values;
    $sql.= ' ) ';
//		print_r($_POST);
    $stmt = $dbc->connection->prepare(" $sql ");
    //Bind parameters
    foreach ($secondary_fields as $key => $value) {
     if (!empty($_POST[$value][0])) {
      $stmt->bindParam(":$value", $_POST[$value][0]);
     } else {
      $stmt->bindvalue(":$value", null, PDO::PARAM_INT);
     }
    }
    $stmt->bindvalue(':reference_type', 'table', PDO::PARAM_INT);
    $stmt->bindvalue(':reference_key_name', $sf->reference_key_name, PDO::PARAM_INT);
    $stmt->bindParam(':reference_key_value', $ref_key_val);
    if (empty($_POST['file_id_values'][0])) {
     $stmt->bindParam(":$value_column", $_POST[$field_name][0]);
    } else {
     $stmt->bindParam(":$value_column", $_POST['file_id_values'][0]);
    }
    $stmt->bindvalue(':creation_date', current_time(), PDO::PARAM_INT);
    $stmt->bindvalue(':created_by', $_SESSION['username'], PDO::PARAM_INT);
    $stmt->bindvalue(':last_update_date', current_time(), PDO::PARAM_INT);
    $stmt->bindvalue(':last_update_by', $_SESSION['username'], PDO::PARAM_INT);


    try {
     $stmt->execute();
     $$class->content_id = $dbc->connection->lastInsertId();
     echo "<br>Record is Successfully saved in $class";
    } catch (PDOException $e) {
     $dbc->rollback = 1;
     echo "<br>Record couldnt be saved. Error @wip_wo_work_bench_line @@ Line " . __LINE__ . $e->getMessage() . "<br/>";
    }
   }
  }
 }

 public function get_dbColumns($table_name, $con = '') {
  global $dbc;
  if (empty($con)) {
   $con = $dbc;
  }

  if (!empty($table_name)) {
   $sql_fields = " SHOW COLUMNS FROM  " . $table_name;
   $prepare = $con->connection->prepare($sql_fields);
   try {
    $prepare->execute();
   } catch (Exception $e) {
    echo " $table_name not found. Error on functions @L72 " . $e->getMessage();
   }

   $fields = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
   return !empty($fields) ? ($fields) : false;
  }
 }

 function get_dbColumns_valIndex($table_name, $con = '') {
  global $dbc;
  if (empty($con)) {
   $con = $dbc;
  }

  if (!empty($table_name)) {
   $sql_fields = " SHOW COLUMNS FROM  " . $table_name;
   $prepare = $con->connection->prepare($sql_fields);
   try {
    $prepare->execute();
   } catch (Exception $e) {
    echo " $table_name not found. Error on functions @L72 " . $e->getMessage();
   }

   $fields = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
//   $fields = sort($fields);
   return !empty($fields) ? array_combine($fields, $fields) : false;
  }
 }

 public static function find_all_tables_array($db_name = DB_NAME) {
  global $db;
  $query = " SELECT TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE' "
   . " AND TABLE_SCHEMA= '" . $db_name . "' ";
  $result = $db->find_by_sql($query);

  $table_name_array = array();
  foreach ($result as $object) {
   $table_name_array [] = $object->table_name;
  }
  return $table_name_array;
 }

 public static function find_all_tables($db_name = DB_NAME) {
  global $db;
  $query = " SELECT TABLE_NAME from information_schema.tables  "
   . " where TABLE_TYPE ='BASE TABLE' AND TABLE_SCHEMA= '" . $db_name . "' ";
  $result = $db->find_by_sql($query);
  return $result;
 }

 public function find_all_views($db_name = DB_NAME) {
  global $db;
  $query = " SELECT * from information_schema.views  "
   . " where  TABLE_SCHEMA= '" . $db_name . "' ";
  $result = $db->find_by_sql($query);
  return $result;
 }

 public static function find_all_tables_and_views($db_name = DB_NAME) {
  global $db;
  $query = " SELECT TABLE_NAME from information_schema.tables  "
   . " where TABLE_SCHEMA= '" . $db_name . "' ";
  $result = $db->find_by_sql($query);
  return $result;
 }

 public static function count_all_tables($db_name = DB_NAME) {
  global $db;
  $query = " SELECT count(TABLE_NAME) as table_count from information_schema.tables  "
   . " WHERE TABLE_SCHEMA= '" . $db_name . "' ";
  $result = $db->find_by_sql($query);
  return !empty($result) ? array_pop($result) : null;
 }

 public static function find_all_tables_gen($db_name = DB_NAME) {
  global $db;
  $query = " SELECT TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE' "
   . " AND TABLE_SCHEMA= '" . $db_name . "' ";
  $result = $db->find_by_sql($query);

  foreach ($result as $object) {
   yield $object->table_name;
  }
 }

 public function findAll_tables($db_name = DB_NAME) {
  $query = " SELECT TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE' "
   . " AND TABLE_SCHEMA= '" . $db_name . "' ";
  $result = $this->findBySql($query);
  $table_name_array = array();
  foreach ($result as $object) {
   $table_name_array [] = $object->table_name;
  }
  return $table_name_array;
 }

 public static function find_columns_of_table($table_name) {
  global $db;
  if (!empty($table_name)) {
   $query = "SHOW COLUMNS FROM $table_name ";
   $result = $db->find_by_sql($query);

   $column_name_array = array();
   foreach ($result as $object) {
    $column_name_array [] = $object->field;
   }
   return $column_name_array;
  }
 }

 public static function find_columns_of_table_obj($table_name) {
  global $db;
  if (!empty($table_name)) {
   $query = "SHOW COLUMNS FROM $table_name ";
   $result = $db->find_by_sql($query);
   return $result;
  }
 }

 protected function _do_initial_defaults() {
  global $dbc;
  $fin_details = org::find_financial_details_from_orgId($this->bu_org_id);
  if ($fin_details) {
   $this->currency = $fin_details->currency_code;
  } else {
   $dbc->rollback = true;
   echo "<br>Setup in complete. No currency found. Error @ " . basename(__FILE__) . ' @@ line ' . __LINE__;
  }
 }

}

//end of content_type class

$dbObject = new dbObject();
$db = & $dbObject;
?>