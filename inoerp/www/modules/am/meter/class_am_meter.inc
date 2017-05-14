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
 * am_meter
 * Contains all the am_meter information, such as - am_meter, am_meter_id, org_id,  type, etc.
 * 
 */
class am_meter extends dbObject {

 public static $table_name = "am_meter";
 public static $primary_column = "am_meter_id";
 public static $key_column = 'name';
 public static $module = "am";
 public static $multi_select_template_path = 'modules/inv/am_meter/multi_action/am_meter_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Meter',
  'number' => '4106',
  'description' => 'Maintenance Meter',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'am',
  'weight' => 17
 ];
 public static $type_a = [
  'ABSOLUTE' => 'Absolute',
  'CHANGE' => 'Change'
 ];
 public static $value_change_a = [
  'ASCENDING' => 'Ascending',
  'DESCENDING' => 'Descending',
  'FLUCTUATING' => 'Fluctuating',
 ];
 public $field_a = [
  'am_meter_id',
  'org_id',
  'name',
  'type',
  'uom_id',
  'from_date',
  'to_date',
  'description',
  'value_change',
  'initial_reading',
  'initial_reading_date',
  'rate_per_day',
  'no_of_past_readings',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'name',
  'type'
 ];
 public $checkbox = [
 ];
 public $requiredField = [
  'name',
  'org_id',
  'type',
  'uom_id',
  'value_change',
  'from_date',
    'rate_per_day',
  'no_of_past_readings',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $search_functions = [
  'Organization' => 'search_org_name'
 ];
 public $pageTitle = " Meter - Create & Update Meters "; //page Title
 public $am_meter_id;
 public $org_id;
 public $name;
 public $type;
 public $uom_id;
 public $from_date;
 public $to_date;
 public $description;
 public $value_change;
 public $initial_reading;
 public $initial_reading_date;
 public $rate_per_day;
 public $no_of_past_readings;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;

 Public static function am_meter_type() {
  $option_header = option_header::find_by_exact_name('am_meter_TYPE');
  $am_meter_class = option_line::find_by_option_id($option_header->option_header_id);
  return $am_meter_class;
 }

 public function findAll_ofOrgid() {
  if (!empty($this->org_id)) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE org_id = :org_id ";
   $value_a = ['org_id' => $this->org_id];
   $result = $this->findBySql($sql, $value_a);
  } else {
   $result = $this;
  }
  return $result;
 }

 public function findBy_parameter_withOrgDetails() {
  $value_a = [];
  $sql = " SELECT si.am_meter_id,si.type,si.am_meter,si.description, org.org,org.org_id  ";
  $sql .= 'From 
            am_meter si,
            org ';
  $sql .= " WHERE si.org_id = org.org_id ";
  if (!empty($this->org_id)) {
   $sql .= " AND org.org_id = :org_id ";
   $value_a['org_id'] = $this->org_id;
  }

  if (!empty($this->am_meter_id)) {
   $sql .= " AND si.am_meter_id = :am_meter_id ";
   $value_a['am_meter_id'] = $this->am_meter_id;
  }
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? $result : false;
 }

 public static function find_all_of_org_id($org_id) {
  global $db;
  if (!empty($org_id)) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE org_id = '{$org_id}' ";
   $result = $db::find_by_sql($sql);
  } else {
   $result = null_instantitae('am_meter');
  }
  return $result;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of am_meter class
?>