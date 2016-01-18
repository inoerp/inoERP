<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * 
 *
 */
class extn_rating_values extends dbObject {

 public static $table_name = "extn_rating_values";
 public static $primary_column = "extn_rating_values_id";
 public static $key_column = "extn_rating_values";
 public static $module = "extension";
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'extn_rating_values',
  'number' => '10035',
  'description' => 'View & Update Rating',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 11
 ];
 public $field_a = [
  'extn_rating_values_id',
  'reference_table',
  'reference_id',
  'rating',
  'vote_time',
  'ip_address',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
// public static $base_encoded_array = ["content"];
//variables used for showing data

 public $initial_search = [
  "reference_table"
 ];
 public $requiredField = [
  'reference_table',
  'reference_id',
  'rating',
 ];
 public $pageTitle = " Rating Values "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $extn_rating_values_id;
 public $reference_table;
 public $reference_id;
 public $rating;
 public $vote_time;
 public $ip_address;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;

 public function findAll_majorCategories() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE parent_id IS NULL OR parent_id='0' OR parent_id='' ";
  $sql .= " AND primary_cb = '1' ";
  $result = $this->findBySql($sql);
  return $result;
 }

 public static function find_by_reference_table_and_id($reference_table, $reference_id) {
  global $db;

  $sql = "SELECT extn_rating_values.extn_rating_values_id as extn_rating_values_id,extn_rating_values.priority,
              extn_rating_values.major_extn_rating_values_id as major_extn_rating_values_id,
               extn_rating_values.extn_rating_values as extn_rating_values, 
               extn_rating_values.parent_id as parent_id, 
               extn_rating_values.description as description,
               extn_rating_values.primary_cb as primary_cb,
               extn_rating_values_reference.extn_rating_values_reference_id as extn_rating_values_reference_id
       FROM 
       extn_rating_values , extn_rating_values_reference
       WHERE extn_rating_values_reference.reference_table = '{$reference_table}'
       AND extn_rating_values_reference.reference_id = '{$reference_id}'
       AND extn_rating_values.extn_rating_values_id = extn_rating_values_reference.extn_rating_values_id";

  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_reference($reference_table, $reference_id) {
  $sql = "SELECT count(extn_rating_values_id) as rating_count , SUM(rating) as rating_value "
   . " FROM " .
   self::$table_name .
   " where reference_id= '{$reference_id}' AND reference_table= '{$reference_table}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

?>