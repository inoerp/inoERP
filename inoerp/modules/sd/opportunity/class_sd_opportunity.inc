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
 * sd_opportunity
 * Contains all the sd_quote_header information, such as - sd_opportunity_id, sd_lead_id, customer info, etc
 *
 */
class sd_opportunity extends dbObject {

 public static $table_name = "sd_opportunity";
 public static $primary_column = "sd_opportunity_id";
 public static $key_column = 'opportunity_subject';
 public static $module = "sd";
     public static $system_info = [
  'name' => 'Sales Opportunity',
  'number' => '2304',
  'description' => 'Create & Mainten Sales Opportunity',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sd',
  'weight' => 4
 ];
 public $action_a = [
  'CREATE_QUOTE' => 'Create Quote',
  'CLOSE_OPPORTUNITY' => 'Close Opportunity',
  'CANCEL' => 'Cancel'
 ];
 public static $status_a = [
  'ENTERED' => 'Entered',
  'APPROVED' => 'Approved',
  'CANCELLED' => 'Cancelled',
  'CLOSED' => 'Closed',
  'CONVERTED_QUOTE' => 'Converted to Quote',
 ];
 public $field_a = [
  'sd_opportunity_id',
  'sd_lead_id',
  'opportunity_number',
  'primary_contact_id',
  'opportunity_subject',
  'type',
  'description',
  'status',
  'win_probability',
  'currency',
  'forecast_amount',
  'expected_close_date',
  'last_name',
  'first_name',
  'mobile_number',
  'office_number',
  'email_id',
  'contact_website',
  'address_id',
  'contact_address',
  'fax_no',
  'timezone',
  'time_to_contact',
  'ar_customer_id',
  'ar_customer_site_id',
  'sales_person_employee_id',
  'campaign_id',
  'campaign_os',
  'sales_team',
  'referral_source',
  'sales_channel',
  'close_reason',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'opportunity_number',
  'sales_team',
 ];
 public $requiredField = [
  'opportunity_subject',
  'sd_lead_id',
 ];
 public $numberField = [
  'sd_opportunity_id',
  'primary_contact_id',
  'sd_lead_id',
  'opportunity_number',
 ];
 public $fields_inForm_notInDataBase = [
  "customer_name",
  "customer_number",
  "customer_site_name",
  "phone",
  "email",
  "website",
  "address",
  "country",
  "postal_code",
  'sales_person_employee_name',
  'address_name'
 ];
 public $sd_opportunity_id;
 public $sd_lead_id;
 public $opportunity_number;
 public $primary_contact_id;
 public $opportunity_subject;
 public $type;
 public $description;
 public $status;
 public $win_probability;
 public $currency;
 public $forecast_amount;
 public $expected_close_date;
 public $last_name;
 public $first_name;
 public $mobile_number;
 public $office_number;
 public $email_id;
 public $contact_website;
 public $address_id;
 public $contact_address;
 public $fax_no;
 public $timezone;
 public $time_to_contact;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $campaign_id;
 public $campaign_os;
 public $sales_person_employee_id;
 public $sales_team;
 public $referral_source;
 public $sales_channel;
 public $close_reason;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $phone;
 public $email;
 public $website;
 public $address;
 public $country;
 public $postal_code;
 public $sales_person_employee_name;
 public $address_name;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Sales Opportunity  "; //page Title
 
 Public static function opportunity_type() {
  $option_header = option_header::find_by_name('SD_LEAD_TYPE');
  $lines = option_line::find_by_option_id($option_header->option_header_id);
  return $lines;
 }

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