<?php

/**
 * inoERP 
 *
 * Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * fp_forecast_group 
 * Forecast group is used for grouping different forecasts for reporting and consumption purposes
 * Contains all the fp_forecast_group information, such as - forecast_group, description , consume_cb, org_id
 * 
 */
class fp_forecast_group extends dbObject {

 public static $table_name = "fp_forecast_group";
 public static $primary_column = "fp_forecast_group_id";
 public static $key_column = 'forecast_group';
 public static $module = "fp";
 public static $system_info = [
  'name' => 'Group',
  'number' => '2502',
  'description' => 'Forecast Group',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fp',
  'weight' => 2
 ];
 public $field_a = [
  'fp_forecast_group_id',
  'org_id',
  'forecast_group',
  'description',
  'status',
  'bucket_type',
  'level',
  'consume_cb',
  'backward_days',
  'forward_days',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'forecast_group',
  'description',
 ];
 public $fields_inForm_notInDataBase = [
  'org',
 ];
 public $requiredField = [
  'org_id',
  'forecast_group',
 ];
 public $fp_forecast_group_id;
 public $org_id;
 public $forecast_group;
 public $description;
 public $status;
 public $bucket_type;
 public $level;
 public $consume_cb;
 public $backward_days;
 public $forward_days;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Forecast Group ";
 public $message;
 public $date_for_consumption_ul;
 public $date_for_consumption_ll;
 public $qty_for_consumption;
 public $itemId_for_consumption;

 public static function find_all_items($fp_forecast_group_id) {
  $sql = " 
    SELECT DISTINCT(ffl.item_id_m), ffg.org_id
    FROM fp_forecast_line ffl ,
    fp_forecast_header ffh,
    fp_forecast_group ffg
    WHERE ffh.fp_forecast_header_id = ffl.fp_forecast_header_id
    AND ffh.forecast_group_id = ffg.fp_forecast_group_id
    AND ffg.fp_forecast_group_id = '{$fp_forecast_group_id}'
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

 public function find_forecastLine_forConsumption() {

  $sql = " 
    SELECT ffl.item_id_m, ffl.fp_forecast_line_id, ffl.fp_forecast_header_id, ffg.org_id
    FROM fp_forecast_line ffl ,
    fp_forecast_header ffh,
    fp_forecast_group ffg
    WHERE ffh.fp_forecast_header_id = ffl.fp_forecast_header_id
    AND ffh.forecast_group_id = ffg.fp_forecast_group_id
    AND ffg.fp_forecast_group_id = '{$this->fp_forecast_group_id}'
    AND  ffl.item_id_m = '{$this->itemId_for_consumption}'
";
 }

 public function findBy_valuationName_OrgId($valuation_name = '', $org_id = '') {
  $org_id = empty($org_id) ? $this->scope_org_id : $org_id;
  $valuation_name = empty($valuation_name) ? $this->valuation_name : $valuation_name;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE scope_org_id = '{$org_id}' AND"
   . " valuation_name = '{$valuation_name}' AND status='active'   ";

  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of fp_forecast_group class
?>