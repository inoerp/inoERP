<?php

class mdm_bank_site extends dbObject {

 public static $table_name = "mdm_bank_site";
 public static $primary_column = "mdm_bank_site_id";
 public static $key_column = 'branch_name';
 public static $module = "mdm";
 public $field_a = [
		 'mdm_bank_site_id',
		 'mdm_bank_header_id',
		 'branch_name',
		 'country',
		 'branch_number',
		 'description',
		 'branch_name_short',
		 'branch_name_alt',
		 'tax_reg_no',
		 'tax_payer_id',
		 'ifsc_code',
		 'swift_code',
		 'routing_number',
		 'iban_code',
		 'site_address_id',
		 'contact_id',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'mdm_bank_site_id',
		 'mdm_bank_header_id',
		 'branch_name',
		 'country',
		 'branch_number',
 ];
 public $column = [
		 'mdm_bank_site_id',
		 'mdm_bank_header_id',
		 'branch_name',
		 'country',
		 'branch_number',
		 'description',
		 'branch_name_short',
		 'branch_name_alt',
		 'tax_reg_no',
		 'tax_payer_id',
 ];
 public $requiredField = [
		 'mdm_bank_header_id',
		 'branch_name',
		 'country',
 ];
 public static $addressField = [
		 "site_address_id"
 ];
 public $fields_inForm_notInDataBase = [
		 'site_address_name',
		 'site_address',
		 'site_country',
		 'site_postal_code',
 ];
 public $search = [
		 '_update_path' => 'form.php?class_name=supplier',
		 '_update_action_meassge' => 'Update',
 ];
 public $pageTitle = " Bank Branches "; //page Title
 public $mdm_bank_site_id;
 public $mdm_bank_header_id;
 public $branch_name;
 public $country;
 public $branch_number;
 public $description;
 public $branch_name_short;
 public $branch_name_alt;
 public $tax_reg_no;
 public $tax_payer_id;
 public $site_address_id;
 public $ifsc_code;
 public $swift_code;
 public $routing_number;
 public $iban_code;
 public $contact_id;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $site_address_name;
 public $site_address;
 public $site_country;
 public $site_postal_code;

 Public static function ap_pay_on() {
	$option_header = option_header::find_by_name('AP_PAY_ON');
	$ap_pay_on = option_line::find_by_option_id($option_header->option_header_id);
	return $ap_pay_on;
 }

 Public static function mdm_bank_site_types() {
	$option_header = option_header::find_by_name('SUPPLIER_SITE_TYPE');
	$coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
	return $coa_account_types;
 }

 public static function find_all_sitesOfHeader_array($bank_header_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE mdm_bank_header_id = '{$bank_header_id}' ";
	$final_array = [];
	$result_array = self::find_by_sql($sql);
	if (empty($result_array)) {
	 return $final_array;
	}
	foreach ($result_array as $array) {
	 $key = $array->mdm_bank_site_id;
	 $value = $array->mdm_bank_site_id . "-" . $array->branch_name;
	 $final_array[$key] = $value;
	}
	return $final_array;
 }

 public static function find_all_sitesOfHeader($bank_header_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE mdm_bank_header_id = '{$bank_header_id}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public function _before_showing() {
	$address = new address();
	if (!empty($this->site_address_id)) {
	 $address->findBy_id($this->site_address_id);
	 $this->site_address_name = $address->address_name;
	 $this->site_address = $address->address;
	 $this->site_country = $address->country;
	 $this->site_postal_code = $address->postal_code;
	}
 }

 public function copy($mdm_bank_site_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM mdm_bank_site WHERE `mdm_bank_site_id` = '{$mdm_bank_site_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `mdm_bank_site_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `mdm_bank_site_id` = '{$mdm_bank_site_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `mdm_bank_site` SELECT * FROM tmptable WHERE `mdm_bank_site_id` = '' ";
		if ($db->query($sql3)) {
		 $this->mdm_bank_site_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

}

//end of mdm_bank_site class
?>