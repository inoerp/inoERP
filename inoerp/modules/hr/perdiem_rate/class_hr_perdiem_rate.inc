<?php

class hr_perdiem_rate extends dbObject {

 public static $table_name = "hr_perdiem_rate";
 public static $module = "hr";
 public static $primary_column = "hr_perdiem_rate_id";
 public static $key_column = "hr_location_id";
 public static $system_info = [
  'name' => 'Per Diem Rate',
  'number' => '3126',
  'description' => 'Per Diem Rate',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 4
 ];
 public $field_a = [
  'hr_perdiem_rate_id',
  'hr_location_id',
  'hr_grade_id',
  'rate',
  'from_date',
  'to_date',
  'currency',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'currency',
  'description',
 ];
 public $requiredField = [
  'hr_location_id',
  'rate',
  'currency',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'hr_location_id'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Per Diem Rate "; //page Title
 public $hr_perdiem_rate_id;
 public $hr_location_id;
 public $hr_grade_id;
 public $rate;
 public $from_date;
 public $to_date;
 public $currency;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function find_by_hrLocationId($hr_location_id) {
  $sql = "SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE hr_location_id = '{$hr_location_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 Public static function find_by_hrLocationId_employeeId($hr_location_id, $emp_id = null) {
  $sql = "SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE hr_location_id = '{$hr_location_id}' ";

  if (!empty($emp_id)) {
   $emp_i = hr_employee::find_by_id($emp_id);
   $grade_id = $emp_i->grade_id;
   if (!empty($grade_id)) {
    $sql .= " AND hr_grade_id = '{$grade_id}'  ";
   }
  }
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);

  if (empty($result)) {
   $sql = "SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE hr_location_id = '{$hr_location_id}' AND hr_grade_id IS NULL  ";
   $sql = ino_perPageSql_i($sql, 1);
   $result = self::find_by_sql($sql);
  }

  return !empty($result) ? array_pop($result) : false;
 }

 public function find_all_ofyear($year) {
  global $db;
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE year= :year ";
  $param_a = ['year'];
  $value_a = ['year' => $year];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return $result;
 }

}

//end of hr_perdiem_rate class
?>