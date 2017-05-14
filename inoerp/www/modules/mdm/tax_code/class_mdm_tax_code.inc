<?php
class mdm_tax_code extends dbObject {
 public static $table_name = "mdm_tax_code";
 public static $module = "mdm";
 public static $primary_column = "mdm_tax_code_id";
 public static $key_column = "tax_code";
   public static $system_info = [
  'name' => 'Tax Code',
  'number' => '9404',
  'description' => 'Define and mainten tax codes',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'mdm',
  'weight' => 4
 ];
 public static $dr_cr_a = [
		 'DR' => 'Dr',
		 'CR' => 'Cr'
 ];
 public static $in_out_a = [
		 'IN' => 'Input',
		 'OUT' => 'Output'
 ];
 public static $calculation_method_a = [
		 'PERCENTAGE' => 'Percentage',
		 'FIX_AMOUNT' => 'Fix Amount',
		 'FORMULA' => 'Formula'
 ];
 public $field_a = [
		 'mdm_tax_code_id',
		 'org_id',
		 'tax_code',
		 'tax_type',
		 'dr_cr',
		 'in_out',
		 'description',
		 'printed_tax_name',
		 'tax_regime',
		 'tax_jurisdiction',
		 'offset_tax_code',
		 'allow_adhoc_rate_cb',
		 'allow_tax_exemptions_cb',
		 'calculation_method',
		 'percentage',
		 'tax_amount',
		 'tax_ac_id',
		 'status',
		 'effective_start_date',
		 'effective_end_date',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'org_id',
		 'tax_code',
		 'tax_type',
		 'dr_cr',
		 'description',
 ];
 public $column = [
		 'org_id',
		 'tax_code',
		 'tax_type',
		 'dr_cr',
		 'in_out',
		 'description',
		 'printed_tax_name',
 ];
 public $requiredField = [
		 'org_id',
		 'tax_code',
		 'tax_type',
		 'dr_cr',
		 'calculation_method'
 ];
 public $account = [
		 'tax_ac_id'
 ];
 public $checkbox = [
		 'allow_adhoc_rate_cb',
		 'allow_tax_exemptions_cb',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 'org_id'
 ];
 public $search = [
		 '_update_path' => 'form.php?class_name=mdm_tax_code&mode=9',
		 '_show_update_path' => 1,
		 '_view_path' => 'form.php?class_name=mdm_tax_code&mode=2',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Tax Code & Rates "; //page Title
 public $option_list = [
		 'tax_type' => 'MDM_TAX_TYPE',
 ]; //list of search fields wh
 public $mdm_tax_code_id;
 public $org_id;
 public $tax_code;
 public $tax_type;
 public $dr_cr;
 public $description;
 public $printed_tax_name;
 public $tax_regime;
 public $tax_jurisdiction;
 public $in_out;
 public $offset_tax_code;
 public $allow_adhoc_rate_cb;
 public $allow_tax_exemptions_cb;
 public $calculation_method;
 public $percentage;
 public $tax_amount;
 public $tax_ac_id;
 public $status;
 public $effective_start_date;
 public $effective_end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function tax_type() {
	$option_header = option_header::find_by_name('MDM_TAX_TYPE');
	$ol = new option_line();
	$option_lines = $ol->findBy_parentId($option_header->option_header_id);
	return $option_lines;
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
 
   public static function find_all_by_buOrgId($org_id) {
	$sql = " 
	 SELECT *
	 FROM mdm_tax_code
	 WHERE org_id = '{$org_id}'
	";
	$result = self::find_by_sql($sql);
	return $result;
 }

  public static function find_all_outTax_by_bu_org_id($org_id) {
	$sql = " 
	 SELECT *
	 FROM mdm_tax_code
	 WHERE org_id = '{$org_id}'
	 AND in_out = 'OUT'
	";
	$result = self::find_by_sql($sql);
	return $result;
 }
 
   public static function find_all_inTax_by_bu_org_id($org_id) {
	$sql = " 
	 SELECT *
	 FROM mdm_tax_code
	 WHERE org_id = '{$org_id}'
	 AND in_out = 'IN'
	";
	$result = self::find_by_sql($sql);
	return $result;
 }

 
 public static function find_all_outTax_by_inv_org_id($org_id) {
	$sql = " 
	 SELECT mtc.mdm_tax_code_id, mtc.org_id, mtc.tax_code, mtc.tax_type, mtc.dr_cr,mtc.in_out,
	 mtc.description, mtc.printed_tax_name, mtc.tax_regime, mtc.tax_jurisdiction,
	 mtc.offset_tax_code, mtc.allow_adhoc_rate_cb, mtc.allow_tax_exemptions_cb, mtc.calculation_method,
	 mtc.percentage, mtc.tax_amount, mtc.tax_ac_id, mtc.status, mtc.effective_start_date,
	 mtc.effective_end_date
	 FROM mdm_tax_code mtc
	 LEFT JOIN org on org.business_org_id = mtc.org_id
	 WHERE org.org_id = '{$org_id}'
	 AND in_out = 'OUT'
	";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_all_inTax_by_inv_org_id($org_id) {
	$sql = " 
	 SELECT mtc.mdm_tax_code_id, mtc.org_id, mtc.tax_code, mtc.tax_type, mtc.dr_cr,
	 mtc.description, mtc.printed_tax_name, mtc.tax_regime, mtc.tax_jurisdiction,
	 mtc.offset_tax_code, mtc.allow_adhoc_rate_cb, mtc.allow_tax_exemptions_cb, mtc.calculation_method,
	 mtc.percentage, mtc.tax_amount, mtc.tax_ac_id, mtc.status, mtc.effective_start_date,
	 mtc.effective_end_date, org.org
	 FROM mdm_tax_code mtc
	 LEFT JOIN org on org.business_org_id = mtc.org_id
	 WHERE org.org_id = '{$org_id}'
	 AND in_out = 'IN'
	";
	$result = self::find_by_sql($sql);
	return $result;
 }

}

//end of mdm_tax_code class
?>