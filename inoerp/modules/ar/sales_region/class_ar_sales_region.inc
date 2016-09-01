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
 * ar_sales_region
 * Contains all the mdm_price_list_header information, such as - country_code, sales_region_name, description,  status, etc.
 * 
 */
class ar_sales_region extends dbObject {

 public static $table_name = "ar_sales_region";
 public static $module = "ar";
 public static $primary_column = "ar_sales_region_id";
 public static $key_column = "sales_region_name";
 public static $system_info = [
  'name' => 'Sales Region',
  'number' => '1310',
  'description' => 'Define and mainten Sales Region',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'ar',
  'weight' => 3
 ];
 public $field_a = [
  'ar_sales_region_id',
  'country_code',
  'state',
  'city',
  'sales_region_name',
  'description',
  'street',
  'mdm_tax_region_id',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'ar_sales_region_id',
  'country_code',
  'sales_region_name'
 ];

 public $requiredField = [
  'country_code',
  'sales_region_name',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'country_code'
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=ar_sales_region&mode=9',
  '_show_update_path' => 1,
  '_view_path' => 'form.php?class_name=ar_sales_region&mode=2',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Sales Regions "; //page Title
 public $option_list = [
  'country_code' => 'COUNTRY',
 ]; //list of search fields wh
 public $ar_sales_region_id;
 public $country_code;
 public $state;
 public $city;
 public $sales_region_name;
 public $description;
 public $street;
 public $mdm_tax_region_id;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function country() {
  $option_header = option_header::find_by_name('COUNTRY');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 public static function find_all_sales_by_region($org_id) {
  $sql = " 
	 SELECT mtc.ar_sales_region_id, mtc.org_id, mtc.sales_region, mtc.tax_type, mtc.dr_cr,mtc.in_out,
	 mtc.description, mtc.printed_tax_name, mtc.tax_regime, mtc.tax_jurisdiction,
	 mtc.offset_sales_region, mtc.allow_adhoc_rate_cb, mtc.allow_tax_exemptions_cb, mtc.calculation_method,
	 mtc.percentage, mtc.tax_amount, mtc.tax_ac_id, mtc.status, mtc.effective_start_date,
	 mtc.effective_end_date
	 FROM ar_sales_region mtc
	 LEFT JOIN org on org.business_org_id = mtc.org_id
	 WHERE org.org_id = '{$org_id}'
	 AND in_out = 'OUT'
	";
  $result = self::find_by_sql($sql);
  return $result;
 }

 
 public static function find_all_by_countryCode($country_code) {
  $sql = " 
	 SELECT *
	 FROM ar_sales_region
	 WHERE country_code = '{$country_code}'
	";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of ar_sales_region class
?>