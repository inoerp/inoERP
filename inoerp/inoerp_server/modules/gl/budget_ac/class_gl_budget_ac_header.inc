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
 * gl_budget_ac_header CLass
 * Contains all the gl_budget_ac_header information
 *
 */
class gl_budget_ac_header extends dbObject {

 public static $table_name = "gl_budget_ac_header";
 public static $dependent_classes = ['gl_budget_ac_line'];
 public static $primary_column = "gl_budget_ac_header_id";
 public static $primary_column2 = "so_number";
 public static $key_column = 'ar_customer_id';
 public static $module = "sd";
 public static $system_info = [
		 'name' => 'Budget Account',
		 'number' => '1111',
		 'description' => 'Create & Mainten Budget Account',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'dependent_class' => array('gl_budget_ac_line'),
		 'primary_entity_cb' => '',
		 'module_name' => 'gl',
		 'weight' => 1
 ];
 public static $order_source_type_a = [
		 'MANUAL' => 'Manual',
		 'ECOMMERCE' => 'eCommerce',
		 'SERVICE' => 'Serive',
		 'INV' => 'Inventory',
		 'IR' => 'Internal Requisition',
		 'QUOTE' => 'Quote',
		 'COPY' => 'Copy',
 ];
 public $field_a = [
		 'gl_budget_ac_header_id',
		 'ac_name',
		 'description',
		 'gl_ledger_id',
		 'start_date',
		 'end_date',
		 'role_code',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 "gl_budget_ac_header_id",
		 'ac_name',
		 'description',
 ];
 public $requiredField = [
		 'ac_name',
		 'gl_ledger_id',
 ];
 public $fields_inForm_notInDataBase = [
		 'action',
		 "customer_name",
		 "customer_number",
		 'bill_to_postal_code',
		 'sales_person'
 ];
 public $fields_inDataBase_notInForm = [
		 'currency'
 ];
// public $search_functions = [
//		 'BU Org' => 'search_business_org',
// ];
// public $profile_default = [
//		 'exchange_rate_type' => 'gl_currency_conversion_type',
//		 'bu_org_id' => 'org_bu_name_default',
// ];

 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Budget Account "; //page Title
 public $gl_budget_ac_header_id;
 public $ac_name;
 public $description;
 public $gl_ledger_id;
 public $start_date;
 public $end_date;
 public $role_code;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;



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

	if (empty($this->gl_budget_ac_header_id) && !empty($this->bu_org_id)) {
	 $this->_do_initial_defaults();
	}
 }

 public function _after_save() {
	if ((!empty($this->gl_budget_ac_header_id)) && empty($this->so_number)) {
	 $gl_budget_ac_header_id = $this->gl_budget_ac_header_id;
	 $bu_org_id = $this->bu_org_id;
	 $so_number = $bu_org_id . '-' . $gl_budget_ac_header_id;
	 $this->so_number = $so_number;
	 echo '<br/> New SO number is ' . $so_number;
	 $this->update_soNumber();
	}
 }

 private function update_soNumber() {
	$sql = " UPDATE " . self::$table_name;
	$sql .= " SET so_number = '{$this->so_number}'  ";
	$sql .= " WHERE gl_budget_ac_header_id = '{$this->gl_budget_ac_header_id}'  ";
	try {
	 $this->runSQL($sql);
	} catch (Exception $e) {
	 echo "<br>SO Number update failed!" . $e->getMessage();
	}
 }


}

//end of gl_budget_ac_header class
?>