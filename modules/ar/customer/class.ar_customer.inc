<?php

class ar_customer extends dbObject {

 protected static $table_name = 'ar_customer';
 public static $field_array = [
		 'ar_customer_id',
		 "customer_number",
		 "customer_name",
		 "supplier_id",
		 "customer_type",
		 "tax_country",
		 "tax_reg_no",
		 "tax_payer_id",
		 "address_id",
		 "customer_contact_id",
		 'customer_credit_class',
		 "ef_id",
		 "status",
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];

 public static $initial_search_array = [
		 "ar_customer_id",
		 "customer_number",
		 "customer_name",
		 "tax_country"
 ];
 public static $column_array = [
		 "ar_customer_id",
		 "customer_number",
		 "customer_name",
		 "tax_country",
		 "tax_reg_no"
 ];
 public static $account_array = [
 ];
 public static $checkbox_array = [
		 "rev_enabled_cb"
 ];
 public static $addressField_array = [
		 "address_id"
 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $requiredField_array = [
		 "customer_number",
		 "customer_name",
		 "tax_country"
 ];
 public static $otherField_array = [
 ];
 public static $primary_column = 'ar_customer_id';
 public $ar_customer_id;
 public $customer_number;
 public $customer_name;
 public $supplier_id;
 public $customer_type;
 public $tax_country;
 public $tax_reg_no;
 public $tax_payer_id;
 public $address_id;
 public $customer_contact_id;
 public $ef_id;
 public $status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $customer_credit_class;

 Public static function customer_types() {
	$option_header = option_header::find_by_name('AR_CUSTOMER_TYPE');
	$customer_types = option_line::find_by_option_id($option_header->option_header_id);
	return $customer_types;
 }

  Public static function customer_credit_class() {
	$option_header = option_header::find_by_name('AR_CUSTOMER_CREDIT_CLASS');
	$customer_credit_class = option_line::find_by_option_id($option_header->option_header_id);
	return $customer_credit_class;
 }
 
public static function find_customer_number_by_customer_number($customer_number) {
	global $db;
	$sql = "SELECT * FROM "
					. self::$table_name
					. " where customer_number LIKE '%{$customer_number}%' LIMIT 0, 30";
	$result = $db->query($sql);
	$data = array();
	if ($result && mysql_num_rows($result)) {
	 while ($row = $db->fetch_array($result)) {
		$data[] = array(
				'label' => $row['customer_number'],
				'customer_number' => $row['customer_number'],
				'ar_customer_id' => $row['ar_customer_id'],
				'description' => $row['customer_description']
		);
	 }
	}

	return $data;
 }

 public static function find_customer_number_by_customerNumber_OrgId($customer_number, $org_id) {
	global $db;
	$sql = "SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " where customer_number LIKE '%{$customer_number}%' ";
	$sql .= " AND org_id  = '{$org_id}' ";
	$result = $db->query($sql);
	$data = array();
	$return_array = array();
	if ($result && mysql_num_rows($result)) {
	 while ($row = $db->fetch_array($result)) {
		$data[] = array(
				'label' => $row['customer_number'],
				'customer_number' => $row['customer_number'],
				'ar_customer_id' => $row['ar_customer_id'],
				'description' => $row['customer_description']
		);
	 }
	}
	$return_array['jsonvalue'] = $data;

	return $data;
 }

 public static function find_ar_customer_id_from_customerNumber_OrgId($customer_number, $org_id) {
	global $db;
	$sql = "SELECT ar_customer_id FROM " .
					self::$table_name .
					" where customer_number= '{$customer_number}' " .
					" AND org_id= '{$org_id }'" .
					" LIMIT 1";

	$result = $db->query($sql);
	if ($result && mysql_num_rows($result)) {
	 while ($row = $db->fetch_array($result)) {
		$ar_customer_id = $row['ar_customer_id'];
	 }//end of while Loop
	 return $ar_customer_id;
	} else {
	 return false;
	}
 }

 public static function find_by_customerNumber_OrgId($customer_number, $org_id) {
	$ar_customer_id = self::find_ar_customer_id_from_customerNumber_OrgId($customer_number, $org_id);
	$result = self::find_by_id($ar_customer_id);
	return $result;
 }

 public static function find_all_assigned_orgs($ar_customer_id) {
	global $db;
	$sql = "SELECT * FROM " .
					'customer_bu' .
					" where ar_customer_id= '{$ar_customer_id}' ";
	$result = $db->result_array_assoc($sql);
	return $result;
 }

 public static function find_customer_by_customerName($customer_name) {
	global $db;
	$sql = "SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " where customer_name LIKE '%{$customer_name}%' ";

	$result = $db->query($sql);
	$data = array();
	$return_array = array();
	if ($result && mysql_num_rows($result)) {
	 while ($row = $db->fetch_array($result)) {
		$data[] = array(
				'label' => $row['customer_name'],
				'customer_name' => $row['customer_name'],
				'ar_customer_id' => $row['ar_customer_id'],
				'customer_number' => $row['customer_number']
		);
	 }
	}
	$return_array['jsonvalue'] = $data;

	return $data;
 }


 public function copy($ar_customer_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM customer WHERE `ar_customer_id` = '{$ar_customer_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `ar_customer_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `ar_customer_id` = '{$ar_customer_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `customer` SELECT * FROM tmptable WHERE `ar_customer_id` = '' ";
		if ($db->query($sql3)) {
		 $this->ar_customer_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

}

//end of customer class
?>