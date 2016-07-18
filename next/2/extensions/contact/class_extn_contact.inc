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
 * 
 *
 */
class extn_contact extends dbObject {

 public static $table_name = "extn_contact";
 public static $primary_column = "extn_contact_id";
 public static $key_column = 'contact_name';
// public static $dependent_classes = ['extn_contact_reference'];
 public static $module = "extn";
  public static $system_info = [
  'name' => 'Contacts',
  'number' => '10013',
  'description' => 'Contacts for Persons & Entities',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 13
 ];
 public $field_a = [
  'extn_contact_id',
  'contact_name',
  'last_name',
  'first_name',
  'middle_name',
  'mobile_number',
  'office_number',
  'contact_number2',
  'email_id',
  'website',
  'email_id2',
  'fax_no',
  'timezone',
  'time_to_contact',
  'type',
  'status',
  'job_titile',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'contact_name',
  'last_name',
 ];
 public $requiredField = [
  'contact_name',
  'last_name',
 ];
 public $extn_contact_id;
 public $contact_name;
 public $last_name;
 public $first_name;
 public $middle_name;
 public $mobile_number;
 public $office_number;
 public $contact_number2;
 public $email_id;
 public $website;
 public $email_id2;
 public $fax_no;
 public $timezone;
 public $time_to_contact;
 public $type;
 public $status;
 public $job_titile;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Contact  "; //page Title


 public static function find_by_reference($ref_obj,$ref_id) {
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