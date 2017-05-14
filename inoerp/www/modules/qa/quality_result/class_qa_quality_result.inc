<?php

/**
 * inoERP
 *
 * @copyright   2015 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * mail_form
 * Contains all the mail_form information, such as - mail_form_id, type, description,  mail_form_name, etc.
 * 
 */
class qa_quality_result extends dbObject {

 public static $key_column = 'reference_key_name';
 public static $table_name = 'qa_quality_result';
 
  public static $system_info = [
  'name' => 'Quality Result',
  'number' => '2908',
  'description' => 'Quality Result',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'qa',
  'weight' => 11
 ];
  
  
 public $field_a = [
  'reference_type',
  'reference_entity',
  'reference_key_name',
  'reference_key_value',
  'qa_cp_header_id',
 ];
 public static $common_fields_a = [
  'reference_type',
  'reference_entity',
  'reference_key_name',
  'reference_key_value',
  'qa_cp_header_id',
 ];
 public $initial_search = [
  'reference_key_name',
  'reference_key_value',
 ];
 public $search = [
  '_show_view_path' => 1,
  '_show_multifield_path' => [ 'qa_cp_header_id', 'reference_key_name', 'reference_key_value']
 ];
 public $pageTitle = " Collection Plan "; //page Title
 public $reference_type;
 public $reference_entity;
 public $reference_key_name;
 public $reference_key_value;
 public $qa_cp_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $primary_clmn;

 public function _before_save() {
  try {
   $this->_do_before_save();
   return 10;
  } catch (Exception $e) {
   echo "Exception<br>" . $e->getMessage();
   return -90;
  }
 }

 private function _do_before_save() {
  global $dbc;
//  pa($_POST);
  if (empty($_POST['reference_key_name'][0]) || empty($_POST['reference_key_value'][0])) {
   throw new Exception("Reference details are not entered. <br>Error @ " . __FILE__ . ' @@ ' . __LINE__);
  }
  $this->reference_key_name = $_POST['reference_key_name'][0];
  $this->reference_key_value = $_POST['reference_key_value'][0];
  $this->reference_type = !empty($_POST['reference_type'][0]) ? $_POST['reference_type'][0] : 'table';
  $this->reference_entity = !empty($_POST['reference_entity'][0]) ? $_POST['reference_entity'][0] : null;
  foreach ($_POST as $field_name => $field_value_a) {
   if (empty($field_value_a[0]) || in_array($field_name, qa_quality_result::$common_fields_a)) {
    continue;
   } else {
    $class = qa_ce_header::tableName_from_elementName($field_name);
    $key_column = $class . '_id';
    $value_column = $class . '_value';
//    $$class = new stdClass();
    $extra_fields = extn_view::find_columns_of_table($class);
//    pa($extra_fields);

    $checkSql = " SELECT * FROM $class WHERE reference_type = 'table' AND reference_key_name='{$this->reference_key_name}' "
     . "  AND reference_key_value='{$this->reference_key_value}' ";
     $checkSql = ino_perPageSql_i($checkSql, 1);

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
      echo "<br>Record is Successfully Saved in $class";
     } catch (PDOException $e) {
      $dbc->rollback = 1;
      echo "<br> $sql <br>";
      echo "<br>Record couldnt be saved. Error @ " . __FILE__ . ' @@ ' . __LINE__ . $e->getMessage() . "<br/>";
     }
    } else {
     $field_columns = '';
     foreach ($extra_fields as $key => $value) {
      $field_columns .= $value . ', ';
     }
     $field_columns_2 = rtrim($field_columns, ', ');

     $field_values = '';
     foreach ($extra_fields as $key1 => $value1) {
      $field_values .= ':' . $value1 . ', ';
     }
     $field_values_2 = rtrim($field_values, ', ');
//write SQL
     $sql = " INSERT INTO ";
     $sql.= $class;
     $sql.= ' ( ';
     $sql.= $field_columns_2;
     $sql.= ' ) ';
     $sql.= 'VALUES';
     $sql.= ' ( ';
     $sql.= $field_values_2;
     $sql.= ' ) ';
//		print_r($_POST);
     $stmt = $dbc->connection->prepare(" $sql ");
     //Bind parameters
     foreach ($extra_fields as $key => $value) {
      if (!empty($_POST[$value][0])) {
       $stmt->bindParam(":$value", $_POST[$value][0]);
      } else {
       $stmt->bindvalue(":$value", null, PDO::PARAM_INT);
      }
     }
     $stmt->bindvalue(':reference_type', 'table', PDO::PARAM_INT);
     $stmt->bindvalue(':reference_key_name', $this->reference_key_name, PDO::PARAM_INT);
     $stmt->bindParam(':reference_key_value', $this->reference_key_value);
     $stmt->bindParam(':reference_entity', $this->reference_entity);
     $stmt->bindParam(':reference_type', $this->reference_type);
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
//      $$class->content_id = $dbc->connection->lastInsertId();
      echo "<br>Record is Successfully Saved in $class";
     } catch (PDOException $e) {
      $dbc->rollback = 1;
      echo "<br>Record couldnt be saved. Error @ " . __FILE__ . ' @@ ' . __LINE__ . $e->getMessage() . "<br/>";
     }
    }
   }
  }
 }

 public static function find_by_fieldName_referenceDetails($field_name, $ref_key, $ref_value) {
  $table_i = qa_ce_header::tableName_from_elementName($field_name);

  $sql = " SELECT * FROM ";
  $sql .= $table_i;
  $sql .= " WHERE reference_key_name = '{$ref_key}' AND reference_key_value='{$ref_value}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 private $_search_sql;
 private $_search_count;

 public function search_records($parameters) {
  $pageno = !empty($parameters['pageno']) ? $parameters['pageno'] : 1;
  $per_page = !empty($parameters['per_page']) ? $parameters['per_page'] : 10;

  $sql = $this->_search_sql($parameters);

  if ((!empty($search_order_by)) && (!empty($search_asc_desc))) {
   if (is_array($search_order_by)) {
    $order_by = ' ORDER BY ';
    foreach ($search_order_by as $key_oby => $value_oby) {
     if (empty($search_asc_desc[$key_oby])) {
      $search_asc_desc[$key_oby] = ' DESC ';
     }
     $order_by .= $value_oby . ' ' . $search_asc_desc[$key_oby] . ' ,';
    }
    $order_by_i = rtrim($order_by, ',');
   } else {
    $order_by_i = ' ORDER BY ' . $search_order_by . ' ' . $search_asc_desc;
   }
  }
  echo $sql;
  $result = self::find_by_sql($sql);


  $s_result = self::find_by_sql($this->_search_sql);
  $this->_search_count = count($s_result);
  return !empty($s_result) ? $s_result : false;
 }

 private function _search_sql($parameters) {
  $reference_key_value = !(empty($_GET['reference_key_value'])) ? $_GET['reference_key_value'][0] : '';
  $reference_key_name = !(empty($_GET['reference_key_name'])) ? $_GET['reference_key_name'][0] : '';

  $table_sql = " SELECT TABLE_NAME from 
information_schema.tables 
where TABLE_TYPE ='BASE TABLE' 
AND table_name LIKE 'qa_ce%' ";
  $all_tables = self::find_by_sql($table_sql);

  if (empty($all_tables)) {
   return new stdClass();
  }
  $sql = "";
  $all_tables_ai = new ArrayIterator($all_tables);

  while ($all_tables_ai->valid()) {
   $table_name = $all_tables_ai->current();
   $sql .= " SELECT * FROM $table_name->table_name ";
   if (!empty($reference_key_name)) {
    $sql .= " WHERE reference_key_name = '{$reference_key_name}' ";
   }
   if (!empty($reference_key_name) && !empty($reference_key_value)) {
    $sql .= " AND reference_key_value = '{$reference_key_value}' ";
   } else if (!empty($reference_key_value)) {
    $sql .= " WHERE reference_key_value = '{$reference_key_value}' ";
   }
   $all_tables_ai->next();
   if ($all_tables_ai->valid()) {
    $sql .= " UNION ";
   }
  }
  $this->_search_sql = $sql;
  return $sql;
 }

 public function search_counts() {
  return !empty($this->_search_count) ? $this->_search_count : null;
 }

 public function search_downloads() {
  return !empty($this->_search_sql) ? self::find_by_sql($this->_search_sql) : null;
 }

}

?>