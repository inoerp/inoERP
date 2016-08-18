<?php

class ar_revenue_rule_line extends dbObject {

 public static $table_name = "ar_revenue_rule_line";
 public static $primary_column = "ar_revenue_rule_line_id";
 public static $parent_primary_column = "ar_revenue_rule_header_id";
 public static $key_column = 'period_number';
 public static $module = "ar";
 public $field_a = [
  'ar_revenue_rule_line_id',
  'ar_revenue_rule_header_id',
  'period_number',
  'percent',
  'schedule_date',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'ar_revenue_rule_header_id',
  'period_number',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "ar_revenue_rule_header_id"
 ];
 public $ar_revenue_rule_line_id;
 public $ar_revenue_rule_header_id;
 public $period_number;
 public $percent;
 public $schedule_date;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_headerId_and_buOrgId($ar_revenue_rule_header_id, $bu_org_id) {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where ar_revenue_rule_header_id= '{$ar_revenue_rule_header_id}' AND bu_org_id= '{$bu_org_id}' ";

  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of ar_revenue_rule_line class
?>