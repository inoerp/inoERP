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
 * sd_lead
 * Contains all the sd_quote_header information, such as - lead_number, sd_lead_id, customer info, etc
 *
 */
class sd_lead extends dbObject {

 public static $table_name = "sd_lead";
 public static $primary_column = "sd_lead_id";
 public static $key_column = 'lead_number';
 public static $dependent_classes = ['extn_contact'];
 public static $module = "sd";
      public static $system_info = [
  'name' => 'Sales Lead',
  'number' => '2305',
  'description' => 'Create & Mainten Sales Lead',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sd',
  'weight' => 5
 ];
 public static $action_a = [
  'CONVERT_OPPR' => 'Convert to Opportunity',
//  'CREATE_QUOTE' => 'Create Quote',
  'CLOSE_LEAD' => 'Close Lead',
  'CANCEL' => 'Cancel'
 ];
 public static $status_a = [
  'ENTERED' => 'Entered',
  'APPROVED' => 'Approved',
  'CANCELLED' => 'Cancelled',
  'CLOSED' => 'Closed',
  'CONVERTED_QUOTE' => 'Converted to Quote',
  'CONVERTED_OPPORTUNITY' => 'Converted to Opportunity',
 ];
 public $field_a = [
  'sd_lead_id',
  'lead_number',
  'primary_contact_id',
  'subject',
  'lead_type',
  'description',
  'details',
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
  'hr_employee_id',
  'sales_team',
  'priority',
  'campaign_id',
  'campaign_os',
  'referral_source',
  'sales_channel',
  'close_reason',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'lead_number',
  'sales_team',
 ];
 public $requiredField = [
  'lead_number',
  'subject',
 ];
 public $numberField = [
  'sd_lead_id',
  'primary_contact_id',
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
  'address_name',
  'action',
  'sales_person'
 ];
 public $sd_lead_id;
 public $lead_number;
 public $primary_contact_id;
 public $subject;
 public $lead_type;
 public $description;
 public $details;
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
 public $sales_person;
 public $hr_employee_id;
 public $sales_team;
 public $priority;
 public $campaign_id;
 public $campaign_os;
 public $referral_source;
 public $sales_channel;
 public $close_reason;
 public $status;
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
 public $action;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Sales Lead  "; //page Title

 Public static function sales_channel() {
  $option_header = option_header::find_by_name('SD_SALES_CHANNEL');
  $lines = option_line::find_by_option_id($option_header->option_header_id);
  return $lines;
 }

 Public static function lead_type() {
  $option_header = option_header::find_by_name('SD_LEAD_TYPE');
  $lines = option_line::find_by_option_id($option_header->option_header_id);
  return $lines;
 }

 private function _convert_leadToOpportunity() {
  $oppr = new sd_opportunity();
  foreach ($this->field_a as $k => $v) {
   if (property_exists($oppr, $v)) {
    if($v == 'subject' || $v == 'description'){
     $oppr->$v = $this->$v.' - As in Lead ';
    }else{
    $oppr->$v = $this->$v;
    }
    $oppr->opportunity_subject = $this->subject;
    $oppr->referral_source = 'Lead id '. $this->sd_lead_id;
    $oppr->status = 'ENTERED';
   }
  }

  try {
//   pa($oppr);
   $oppr->save();
   echo "Opportunity is Successfully Created. New Opportunity id is " . $oppr->sd_opportunity_id;
  } catch (Exception $e) {
   echo "Failed to convert the lead to opportunity. Error @ sd_lead @@ line " . __LINE__ . $e->getMessage();
  }
 }

 public function _after_save() {
  if ($this->action == 'CONVERT_OPPR') {
   try{
   $this->_convert_leadToOpportunity();
   $this->status = 'CONVERTED_OPPORTUNITY';
   pa($this);
   $this->save();
   }catch(Exception $e){
    echo "Failed to convert the lead to opportunity. Error @ sd_lead @@ line " . __LINE__ . $e->getMessage();
   }
  }
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