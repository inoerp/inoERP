<?php

class hr_team_line extends dbObject {

 public static $table_name = "hr_team_line";
 public static $primary_column = "hr_team_line_id";
 public static $parent_primary_column = "hr_team_header_id";
 public static $key_column = 'member_employee_id';
 public static $module = "hr";
 public static $responsibility_a = [
  '1' => 'Member',
  '2' => 'Lead',
  '3' => 'Manager',
  '99' => 'Admin',
 ];
 public $field_a = [
  'hr_team_line_id',
  'hr_team_header_id',
  'member_employee_id',
  'role',
  'responsibility',
  'region',
  'start_date',
  'end_date',
  'objective',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hr_team_header_id"
 ];
 public $requiredField = [
  'member_employee_id'
 ];
 public $fields_inFormr_notinDataBase = [
  "member_employee_name"
 ];
 public $number_fields = [
  'hr_team_line_id',
  'hr_team_header_id',
  'member_employee_id',
 ];
 public $hr_team_line_id;
 public $hr_team_header_id;
 public $member_employee_id;
 public $role;
 public $responsibility;
 public $region;
 public $start_date;
 public $end_date;
 public $objective;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $member_employee_name;

 public static function find_by_parentId_elementId($headerId, $elementId) {
  $sql = " SELECT * 
       FROM hr_team_line eel 
       WHERE eel.hr_team_header_id = '{$headerId}'   
        AND eel.element_id = '{$elementId}'
";
        $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of inv_transaction class
?>