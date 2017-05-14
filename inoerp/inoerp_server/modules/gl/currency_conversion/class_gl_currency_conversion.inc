<?php

/**
 * inoERP - Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * gl_currency_conversion
 * Used for currency conversion
 * Contains all the conversion information, such as - currency_conversion_type, from_currency , to_currency etc
 * 
 */
class gl_currency_conversion extends dbObject {

 public static $table_name = "gl_currency_conversion";
 public static $module = "mdm";
 public static $primary_column = "gl_currency_conversion_id";
 public static $key_column = "rate";
 public static $system_info = [
  'name' => 'Currency Conversion',
  'number' => '1105',
  'description' => 'General Ledger Currency Conversion',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'gl',
  'weight' => 5
 ];
 public $field_a = [
  'gl_currency_conversion_id',
  'currency_conversion_type',
  'from_currency',
  'to_currency',
  'from_date',
  'to_date',
  'rate',
  'use_reverse_conversion',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'currency_conversion_type',
  'from_currency',
  'to_currency',
  'from_date',
  'to_date',
 ];
 public $column = [
  'gl_currency_conversion_id',
  'currency_conversion_type',
  'from_currency',
  'to_currency',
  'from_date',
  'to_date',
  'rate',
  'use_reverse_conversion',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'currency_conversion_type',
  'from_currency',
  'to_currency',
  'from_date',
  'rate',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'gl_currency_conversion_id'
 ];
 public $search = [
//   '_update_path' => 'form.php?class_name=gl_currency_conversion',
  '_show_update_path' => 1,
//   '_view_path' => 'form.php?class_name=gl_currency_conversion',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Currency Conversion "; //page Title
 public $gl_currency_conversion_id;
 public $currency_conversion_type;
 public $from_currency;
 public $to_currency;
 public $from_date;
 public $to_date;
 public $rate;
 public $use_reverse_conversion;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function currency_conversion_type() {
  $option_header = option_header::find_by_name('GL_CURRENCY_CONVERSION_TYPE');
  $ol = new option_line();
  return $ol->findBy_parentId($option_header->option_header_id, 'option_line_value');
 }

 public static function find_by_conversion_type($conversion_type) {
  $sql = "SELECT * FROM "
   . self::$table_name
   . " where currency_conversion_type= '{$conversion_type}'";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function profile_gl_currency_conversion_type() {
  $line_data_array = [];
  $line_data_array['line_key'] = 'option_line_code';
  $line_data_array['line_desc'] = 'option_line_value';
  $line_data_array['line_values'] = self::currency_conversion_type();
  return $line_data_array;
 }

 public static function find_rate($from_currency, $to_currency, $currency_conversion_type = 'CORP', $date = '') {
  if (empty($date)) {
   $date = current_time(true);
  }

  $sql = " SELECT * 	FROM " . self::$table_name;
  $sql .= " WHERE from_currency = '{$from_currency}' AND to_currency = '{$to_currency}' AND currency_conversion_type = '{$currency_conversion_type}' ";
  $sql .= " AND from_date <=  STR_TO_DATE('{$date}',  '%Y-%m-%d') AND ( to_date >=  STR_TO_DATE('{$date}',  '%Y-%m-%d') || to_date IS NULL || to_date = '0000-00-00' )";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $result = self::find_by_sql($sql);
  if (empty($result)) {
   $sql1 = " SELECT * 	FROM " . self::$table_name;
   $sql1 .= " WHERE to_currency = '{$from_currency}' AND from_currency = '{$to_currency}' AND currency_conversion_type = '{$currency_conversion_type}' ";
   $sql1 .= " AND from_date <=  STR_TO_DATE('{$date}',  '%Y-%m-%d') AND ( to_date >=  STR_TO_DATE('{$date}',  '%Y-%m-%d') || to_date IS NULL || to_date = '0000-00-00' )";
   switch (DB_TYPE) {
    case 'ORACLE' :
     $sql1 .= ' AND ' . ino_perPageSql(1);
     break;

    default:
     $sql1 .= ino_perPageSql(1);
     break;
   }

   $result1 = self::find_by_sql($sql1);
   if ((!empty($result1)) && !empty($result1[0]->use_reverse_conversion)) {
    $rate = 1 / ($result1[0]->rate);
   } else {
    $rate = false;
   }
  } else {
   $rate = $result[0]->rate;
  }

  return $rate;
 }

 public static function find_all_inTax_by_inv_org_id($org_id) {
  $sql = " 
	 SELECT mtc.gl_currency_conversion_id, mtc.org_id, mtc.tax_region, mtc.tax_type, mtc.dr_cr,
	 mtc.description, mtc.printed_tax_name, mtc.tax_regime, mtc.tax_jurisdiction,
	 mtc.offset_tax_region, mtc.allow_adhoc_rate_cb, mtc.allow_tax_exemptions_cb, mtc.calculation_method,
	 mtc.percentage, mtc.tax_amount, mtc.tax_ac_id, mtc.status, mtc.effective_start_date,
	 mtc.effective_end_date, org.org
	 FROM gl_currency_conversion mtc
	 LEFT JOIN org on org.business_org_id = mtc.org_id
	 WHERE org.org_id = '{$org_id}'
	 AND in_out = 'IN'
	";
  $result = self::find_by_sql($sql);
  return $result;
 }

}

//end of gl_currency_conversion class
?>