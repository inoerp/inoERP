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
 * ap_payment_process
 * 
 * 
 */
class ap_payment_process extends dbObject {

 public static $table_name = "ap_payment_process";
 public static $primary_column = "ap_payment_process_id";
 public static $key_column = 'payment_type';
 public static $module = "ap";
 public static $system_info = [
		 'name' => 'AR Payment Process',
		 'number' => '1311',
		 'description' => 'Payment Process',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'ar',
		 'weight' => 5
 ];
 
 public static $clearing_method_a = [
		 'DIRECT' => 'Direct',
		 'MATCHING' => 'Matching',
		 'AUTO' => 'Automatic'
 ];
 public static $template_type = [
		 'header_tab' => 1,
		 'line_tab' => 2,
		 'nooffields_header_tab1' => 5,
		 'nooffields_line_tab1' => 6,
		 'nooffields_line_tab2' => 6,
 ];
 public $field_a = [
		 'ap_payment_process_id',
		 'payment_process',
		 'payment_type',
		 'cash_ac_id',
		 'bu_org_id',
		 'description',
		 'format_class_name',
		 'format_method_name',
		 'mdm_bank_account_id',
		 'clearing_method',
		 'sync_payment_number_cb',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'payment_type',
		 'creation_method',
 ];
 public $fields_inForm_notInDataBase = [
		 'account_number',
		 'country',
		 'bank_name',
		 'bank_number',
		 'description',
		 'bank_name_short',
		 'bank_name_alt',
		 'branch_name',
		 'branch_number',
		 'ifsc_code',
		 'swift_code',
		 'routing_number',
		 'iban_code',
 ];
 public $requiredField = [
		 'payment_process',
		 'payment_type',
		 'bu_org_id',
 ];
 public $ap_payment_process_id;
 public $payment_process;
 public $payment_type;
 public $cash_ac_id;
 public $bu_org_id;
 public $description;
 public $format_class_name;
 public $format_method_name;
 public $mdm_bank_account_id;
 public $sync_payment_number_cb;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $country;
 public $account_number;
 public $bank_name;
 public $bank_number;
 public $bank_name_short;
 public $bank_name_alt;
 public $branch_name;
 public $branch_number;
 public $ifsc_code;
 public $swift_code;
 public $routing_number;
 public $iban_code;
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " AP - Payment Process ";

 public static function find_by_buOrgId($bu_org_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE bu_org_id = '{$bu_org_id}' AND status='active'";
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : false;
 }

 public function findBy_buOrgId($bu_org_id = '') {
	$bu_org_id = empty($bu_org_id) ? $this->bu_org_id : $bu_org_id;
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE bu_org_id = '{$bu_org_id}' AND status='active'";
	$result = $this->findBySql($sql);
	return !empty($result) ? $result : false;
 }

}

//end of ap_payment_process class
?>