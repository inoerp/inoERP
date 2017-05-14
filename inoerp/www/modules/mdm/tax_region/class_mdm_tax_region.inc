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
 * mdm_tax_region
 * Contains all the mdm_price_list_header information, such as - country_code, tax_region_name, description,  status, etc.
 * 
 */
class mdm_tax_region extends dbObject {

 public static $table_name = "mdm_tax_region";
 public static $module = "mdm";
 public static $primary_column = "mdm_tax_region_id";
 public static $key_column = "tax_region_name";
 public static $system_info = [
  'name' => 'Tax Region',
  'number' => '9403',
  'description' => 'Define and mainten tax region',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'mdm',
  'weight' => 3
 ];
 public $field_a = [
  'mdm_tax_region_id',
  'country_code',
  'state',
  'city',
  'tax_region_name',
  'description',
  'tax_regime',
  'tax_jurisdiction',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $initial_search = [
  'mdm_tax_region_id',
  'country_code',
  'tax_region_name'
 ];
 public $column = [
  'mdm_tax_region_id',
  'country_code',
  'state',
  'city',
  'tax_region_name',
 ];
 public $requiredField = [
  'country_code',
  'tax_region_name',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'country_code'
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=mdm_tax_region&mode=9',
  '_show_update_path' => 1,
  '_view_path' => 'form.php?class_name=mdm_tax_region&mode=2',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Tax Regions "; //page Title
 public $option_list = [
  'country_code' => 'COUNTRY',
 ]; //list of search fields wh
 public $mdm_tax_region_id;
 public $country_code;
 public $state;
 public $city;
 public $tax_region_name;
 public $description;
 public $tax_regime;
 public $tax_jurisdiction;
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

 public static function find_all_outTax_by_inv_org_id($org_id) {
  $sql = " 
	 SELECT mtc.mdm_tax_region_id, mtc.org_id, mtc.tax_region, mtc.tax_type, mtc.dr_cr,mtc.in_out,
	 mtc.description, mtc.printed_tax_name, mtc.tax_regime, mtc.tax_jurisdiction,
	 mtc.offset_tax_region, mtc.allow_adhoc_rate_cb, mtc.allow_tax_exemptions_cb, mtc.calculation_method,
	 mtc.percentage, mtc.tax_amount, mtc.tax_ac_id, mtc.status, mtc.effective_start_date,
	 mtc.effective_end_date
	 FROM mdm_tax_region mtc
	 LEFT JOIN org on org.business_org_id = mtc.org_id
	 WHERE org.org_id = '{$org_id}'
	 AND in_out = 'OUT'
	";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_all_inTax_by_inv_org_id($org_id) {
  $sql = " 
	 SELECT mtc.mdm_tax_region_id, mtc.org_id, mtc.tax_region, mtc.tax_type, mtc.dr_cr,
	 mtc.description, mtc.printed_tax_name, mtc.tax_regime, mtc.tax_jurisdiction,
	 mtc.offset_tax_region, mtc.allow_adhoc_rate_cb, mtc.allow_tax_exemptions_cb, mtc.calculation_method,
	 mtc.percentage, mtc.tax_amount, mtc.tax_ac_id, mtc.status, mtc.effective_start_date,
	 mtc.effective_end_date, org.org
	 FROM mdm_tax_region mtc
	 LEFT JOIN org on org.business_org_id = mtc.org_id
	 WHERE org.org_id = '{$org_id}'
	 AND in_out = 'IN'
	";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_all_by_countryCode($country_code) {
  $sql = " 
	 SELECT *
	 FROM mdm_tax_region
	 WHERE country_code = '{$country_code}'
	";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of mdm_tax_region class
?>