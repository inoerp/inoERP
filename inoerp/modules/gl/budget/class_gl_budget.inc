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
 * gl_budget
 * Contains all the sd_quote_header information, such as - lead_number, gl_budget_id, customer info, etc
 *
 */
class gl_budget extends dbObject {

 public static $table_name = "gl_budget";
 public static $primary_column = "gl_budget_id";
 public static $key_column = 'budget_name';
 public static $module = "gl";
 public static $system_info = [
		 'name' => 'Budget',
		 'number' => '1110',
		 'description' => 'Create & Mainten GL Budget',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'gl',
		 'weight' => 5
 ];
 public static $status_a = [
		 'CONVERT_OPPR' => 'Convert to Opportunity',
//  'CREATE_QUOTE' => 'Create Quote',
		 'CLOSE_LEAD' => 'Close Lead',
		 'CANCEL' => 'Cancel'
 ];
 public $field_a = [
		 'gl_budget_id',
		 'ledger_id',
		 'budget_name',
		 'description',
		 'status',
		 'created_on',
		 'frozen_date',
		 'first_period_id',
		 'current_period_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $initial_search = [
		 'ledger_id',
		 'budget_name',
 ];
 public $requiredField = [
		 'ledger_id',
		 'budget_name',
 ];
 public $fields_inForm_notInDataBase = [
		 "freeze_cb",
 ];
 public $gl_budget_id;
 public $ledger_id;
 public $budget_name;
 public $description;
 public $status;
 public $created_on;
 public $frozen_date;
 public $first_period_id;
 public $current_period_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $freeze_cb;
 public $action;
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " GL Budget  "; //page Title

 public static function find_by_reference($ref_obj, $ref_id) {
	$sql = " SELECT cont.extn_contact_id,cont.contact_name, cont.last_name, cont.first_name, cont.middle_name, 
   cont.mobile_number, cont.office_number, cont.contact_number2, cont.email_id, cont.website, cont.email_id2,
   cont.fax_no, cont.timezone, cont.time_to_contact, cont.type, cont.status, cont.job_titile, 
   cont.created_by, cont.creation_date, cont.last_update_by, cont.last_update_date, cr.extn_contact_reference_id, 
   cr.extn_contact_id, cr.status, cr.reference_type, cr.reference_table, cr.reference_id, cr.created_by, 
   cr.creation_date, cr.last_update_by, cr.last_update_date 

FROM extn_contact cont,
extn_contact_reference cr 

WHERE cr.extn_contact_id = cont.extn_contact_id
AND cr.reference_table = '{$ref_obj}'
 AND cr.reference_id = '{$ref_id}'
";

	$result = self::find_by_sql($sql);
//  echo $sql; pa($result);
	return !empty($result) ? ($result) : false;
 }

}

//end of extn_contact class
?>