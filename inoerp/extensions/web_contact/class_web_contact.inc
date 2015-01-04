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
 * contact_form
 * Contains all the contact_form information, such as - contact_form_id, type, description,  contact_form_name, etc.
 * 
 */
class web_contact extends dbObject {

 public static $table_name = "contact_form";
 public static $primary_column = "contact_form_id";
 public static $key_column = 'contact_form_name';
 public static $module = "org";
 public static $system_info = [
  'name' => 'Address',
  'number' => '2006',
  'description' => 'Define and mainten contact_formes',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'org',
  'weight' => 6
 ];
 public $field_a = [
  "contact_form_id",
  "type",
  "contact_form_name",
  'mdm_tax_region_id',
  "description",
  "phone",
  "email",
  "website",
  "contact_form",
  "country",
  "postal_code",
  "efid",
  "status",
  "rev_enabled",
  "rev_number",
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
 public $initial_search = [
  "contact_form_name",
  "type",
  "description",
  "phone",
  "email",
  "website",
  "country",
  "postal_code"
 ];
 public $checkbox = [
  "rev_enabled",
 ];
 public $column = [
  "contact_form_id",
  "contact_form_name",
  "description",
  "phone",
  "email",
  "website",
  "country",
  "postal_code",
  'contact_form'
 ];
 public $requiredField = [
  "contact_form_name",
  "type"
 ];
 public $fields_inForm_notInDataBase = [
  "tax_region_name"
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=contact_form',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " Address - Organization Addresses "; //page Title
 public $contact_form_id;
 public $type;
 public $contact_form_name;
 public $mdm_tax_region_id;
 public $description;
 public $phone;
 public $email;
 public $website;
 public $contact_form;
 public $country;
 public $postal_code;
 public $efid;
 public $status;
 public $rev_enabled;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $tax_region_name;

 Public static function web_contact_category() {
  $option_header = option_header::find_by_name('EXT_WEB_CONTACT_CATEGORY');
  $ol = new option_line();
  $lines = $ol->findBy_parentId($option_header->option_header_id);
  return $lines;
 }

 public function entry_form($param) {
  $f = new inoform();
  $entry_form = "<h1>Contact <small>You can leave a message using the contact form below.</small></h1>";
  $entry_form .= '<div class="form-group">';
  $entry_form .= "<label for='youName'>Your Name</label>" . $f->text_field('visitor_name', '', '', 'visitor_name', 'form-control');
  $entry_form .= "</div>";
  $entry_form .= '<div class="form-group">';
  $entry_form .= "<label for='emailId'>eMail Id</label>" . $f->text_field('visitor_email', '', '', 'visitor_email', 'form-control');
  $entry_form .= "</div>";
  $entry_form .= '<div class="form-group">';
  $entry_form .= "<label for='phone'>Phone #</label>" . $f->text_field('visitor_phone_no', '', '', 'visitor_phone_no', 'form-control');
  $entry_form .= "</div>";
  $entry_form .= '<div class="form-group">';
  $entry_form .= "<label for='subject'>Subject</label>" . $f->text_field('subject', '', '', 'subject', 'form-control');
  $entry_form .= "</div>";
  $entry_form .= '<div class="form-group">';
  $entry_form .= "<label for='message'>Message</label>" . $f->text_area('message', '', '10', 'message', 'form-control');
  $entry_form .= "</div>";
  $entry_form .= '<div class="form-group">';
  $entry_form .= "<label for='message'>Select a category to help us route your request</label>"
   . $f->select_field_from_object('contact_category', self::web_contact_category(), 'option_line_code', 'description', '', 'contact_category', 'form-control');
  $entry_form .= "</div>";
  return $entry_form;
 }

 public function _before_save($param) {
  global $si;

  $to = $si->email;
  $subject = "Web Contact @ " . $si->site_name;
  $message = "<html> <body><br>Message as submited on web contact form : <br><br>";
  foreach($param as $k => $val){
   $message .= "<br> $k : $val[0]";
  }
  $message .='<br><br>Thanks<br>' . $si->site_name . '</body></html>';
  
  $from = "admin@" . $si->site_name;
  $headers = "From: $from\r\n";
  $headers .= "Content-type: text/html\r\n";
  try {
//   echo $message;
   mail($to, $subject, $message, $headers);
  } catch (Exception $e) {
   echo "<br>Failed to send e-mail.";
  }
  echo "<h1>Thank you for contacting Us.</h1>
        <h2>We’ll review the information and be in touch with you shortly.</h2> ";
  return 10;
 }

 public static function show_adrees_details_inLine(&$contact_form) {
  if (empty($contact_form)) {
   return;
  }
  $show_adrees_details = $contact_form->contact_form . '<br>' . $contact_form->postal_code . ','
   . $contact_form->country . '<br>' . $contact_form->phone
   . $contact_form->email . '<br>' . $contact_form->website;
  return $show_adrees_details;
 }

}

?>
