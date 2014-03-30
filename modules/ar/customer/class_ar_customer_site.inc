<?php

class ar_customer_site extends dbObject {

 protected static $table_name = "ar_customer_site";
 public static $primary_column = "ar_customer_site_id";
 public static $parent_primary_column = "ar_customer_id";
 public static $key_column = 'customer_site_name';
 public static $module = "ar";
 public  $field_a = [
		 'ar_customer_site_id',
		 'ar_customer_id',
		 'customer_site_number',
		 'customer_site_name',
		 'site_tax_country',
		 'site_tax_reg_no',
		 'site_tax_payer_id',
//		 'site_tax_code',
//		 'customer_site_ref',
		 'customer_site_type',
		 'status',
//		 'profile_id',
		 'currency',
		 'payment_term_id',
//		 'finance_profile_id',
//		 'payment_method_id',
//		 'order_type_id',
//		 'price_list_id',
//		 'internal_org_id',
//		 'fob',
//		 'freight_terms',
//		 'transportation',
//		 'country_of_origin',
		 'site_address_id',
//		 'site_contact_id',
//		 'customer_site_attachement_id',
//		 'ef_id',
//		 'bank_id',
//		 'bank_account_id',
//		 'rev_enabled_cb',
//		 'rev_number',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];

 public $requiredField = [
		 "ar_customer_id",
		 "customer_site_number",
		 "customer_site_name",
 ];
 public $addressField_array = [
		 "site_address_id"
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 'ar_customer_id'
 ];

 public $ar_customer_site_id;
 public $ar_customer_id;
 public $customer_site_number;
 public $customer_site_name;
 public $site_tax_country;
 public $site_tax_reg_no;
 public $site_tax_payer_id;
 public $site_tax_code;
 public $customer_site_ref;
 public $customer_site_type;
 public $status;
 public $profile_id;
 public $currency;
 public $payment_term_id;
 public $finance_profile_id;
 public $payment_method_id;
 public $order_type_id;
 public $price_list_id;
 public $internal_org_id;
 public $fob;
 public $freight_terms;
 public $transportation;
 public $country_of_origin;
 public $site_address_id;
 public $site_contact_id;
 public $customer_site_attachement_id;
 public $ef_id;
 public $bank_id;
 public $bank_account_id;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 Public static function customer_site_types() {
	$option_header = option_header::find_by_name('CUSTOMER_SITE_TYPE');
	$coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
	return $coa_account_types;
 }

 public static function find_all_sitesOfCustomer_array($customer_id = "") {
	global $db;
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE ar_customer_id = '{$customer_id}' ";
	$final_array = [];
	$result_array = $db->find_by_sql($sql);
	foreach ($result_array as $obj	) {
	 $key = $obj->ar_customer_site_id;
	 $value = $obj->ar_customer_site_id . "-" . $obj->customer_site_name;
	 $final_array[$key] = $value;
	}

//	$result = self::find_by_sql($sql);
	return $final_array;
 }

 public static function find_all_sitesOfCustomer($customer_id = "") {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE ar_customer_id = '{$customer_id}' ";

	$result = self::find_by_sql($sql);
	return $result;
 }

 public function copy($ar_customer_site_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM customer_site WHERE `ar_customer_site_id` = '{$ar_customer_site_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `ar_customer_site_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `ar_customer_site_id` = '{$ar_customer_site_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `customer_site` SELECT * FROM tmptable WHERE `ar_customer_site_id` = '' ";
		if ($db->query($sql3)) {
		 $this->ar_customer_site_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

}

//end of customer_site class
?>