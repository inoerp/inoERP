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
 * cm_statement_header CLass
 * Contains all the cm_statement_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class cm_statement_header extends dbObject {

 public static $table_name = "cm_statement_header";
 public static $dependent_classes = ['cm_statement_line'];
 public static $primary_column = "cm_statement_header_id";
 public static $primary_column2 = "statement_num";
 public static $key_column = 'mdm_bank_account_id';
 public static $module = "cm";
 public static $system_info = [
		 'name' => 'Bank Statement',
		 'number' => '2301',
		 'description' => 'Create & Mainten Bank Statement',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'dependent_class' => array('cm_statement_line'),
		 'primary_entity_cb' => '',
		 'module_name' => 'cm',
		 'weight' => 1
 ];
 public $field_a = [
		 'cm_statement_header_id',
		 'mdm_bank_account_id',
		 'statement_num',
		 'status',
		 'statement_date',
		 'description',
		 'gl_date',
		 'bu_org_id',
		 'opening_balance',
		 'closing_balance',
		 'receipt',
		 'payments',
		 'doc_currency',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 "cm_statement_header_id",
		 "so_number",
		 "ar_customer_id",
 ];
 public $requiredField = [
		 'mdm_bank_account_id',
		 'statement_date',
		 'bu_org_id',
 ];
 public $search_functions = [
		 'BU Org' => 'search_business_org',
 ];
 public $profile_default = [
		 'exchange_rate_type' => 'gl_currency_conversion_type',
		 'bu_org_id' => 'org_bu_name_default',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Bank Statement "; //page Title
 public $cm_statement_header_id;
 public $mdm_bank_account_id;
 public $statement_num;
 public $status;
 public $date;
 public $description;
 public $gl_date;
 public $bu_org_id;
 public $opening_balance;
 public $closing_balance;
 public $receipt;
 public $payments;
 public $doc_currency;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

  private function _do_action() {
	switch ($this->action) {
	 case 'BOOKED':
		$this->so_status = 'BOOKED';
		break;

	 default :
		break;
	}
 }

 public function _before_save() {
	if (!empty($this->action)) {
	 $this->_do_action();
	}

	if (empty($this->so_status)) {
	 $this->so_status = 'ENTERED';
	}

	if (empty($this->cm_statement_header_id) && !empty($this->bu_org_id)) {
	 $this->_do_initial_defaults();
	}
 }

 public function _after_save() {

 }

 private function update_soNumber() {
	$sql = " UPDATE " . self::$table_name;
	$sql .= " SET so_number = '{$this->so_number}'  ";
	$sql .= " WHERE cm_statement_header_id = '{$this->cm_statement_header_id}'  ";
	try {
	 $this->runSQL($sql);
	} catch (Exception $e) {
	 echo "<br>SO Number update failed!" . $e->getMessage();
	}
 }

 public static function instantiate_extra_fields(&$array_of_objects) {
	if (count($array_of_objects) > 0) {
	 foreach ($array_of_objects as &$this_object) {
		$customer_details = supplier::find_by_id($this_object->ar_customer_id);
		$this_object->customer_name = $customer_details->customer_name;
		$this_object->customer_number = $customer_details->customer_number;
		$customer_site_details = customer_site::find_by_id($this_object->customer_site_id);
		$this_object->customer_site_name = $customer_site_details->customer_site_name;
	 }
	}
	return $array_of_objects;
 }

 Public static function so_types() {
	$option_header = option_header::find_by_name('SO_TYPE');
	$so_types = option_line::find_by_option_id($option_header->option_header_id);
	return $so_types;
 }

 Public static function so_status() {
	$option_header = option_header::find_by_name('cm_statement_STATUS');
	$so_status = option_line::find_by_option_id($option_header->option_header_id);
	return $so_status;
 }

 public function copy($cm_statement_header_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM cm_statement_header WHERE `cm_statement_header_id` = '{$cm_statement_header_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `cm_statement_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `cm_statement_header_id` = '{$cm_statement_header_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `cm_statement_header` SELECT * FROM tmptable WHERE `cm_statement_header_id` = '' ";
		if ($db->query($sql3)) {
		 $this->cm_statement_header_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }


}

//end of cm_statement_header class
?>