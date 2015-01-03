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

class contact_form extends dbObject {

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

 public function _before_save(){
	if(!empty($this->tax_region_name)){
	 $this->mdm_tax_region_id = mdm_tax_region::find_by_keyColumn($this->tax_region_name)->mdm_tax_region_id;
	}
 }
 
  public function _before_showing(){
	if(!empty($this->mdm_tax_region_id)){
	 $this->tax_region_name = mdm_tax_region::find_by_id($this->mdm_tax_region_id)->tax_region_name;
	}
 }
 
 Public static function contact_form_types() {
	$option_header = option_header::find_by_name('ADDRESS_TYPE');
	$type = option_line::find_by_option_id($option_header->option_header_id);
	return $type;
 }

   public static function profile_ship_to_contact_form_default() {
   $line_data_array = [];
   $line_data_array['line_key'] = 'contact_form_id';
   $line_data_array['line_desc'] = 'contact_form_name';
   $line_data_array['line_values'] = contact_form::find_all();
   return $line_data_array;
  }
  
     public static function profile_bill_to_contact_form_default() {
   $line_data_array = [];
   $line_data_array['line_key'] = 'contact_form_id';
   $line_data_array['line_desc'] = 'contact_form_name';
   $line_data_array['line_values'] = contact_form::find_all();
   return $line_data_array;
  }
  
 public static function find_by_contact_form_name($contact_form_name) {
	$sql = "SELECT * FROM " . self::$table_name . " where contact_form_name REGEXP '{$contact_form_name}$' LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 protected static function contact_form_field(&$contact_form, $field_name) {
	$field_statement = form::text_field($field_name, $contact_form->$field_name, '20', '', '', '', $field_name, 1);
	return $field_statement;
 }

 public static function show_adrees_details(&$contact_form = "") {
	$show_adrees_details = "";
	$show_adrees_details .= "<ul class=\"contact_form inline_list\">";
	$show_adrees_details .= "<li><label>Phone  : </label>" . self::contact_form_field($contact_form, 'phone') . "</li>";
	$show_adrees_details .= "<li><label>Email  : </label>" . self::contact_form_field($contact_form, 'email') . "</li>";
	$show_adrees_details .= "<li><label>Web-site  : </label>" . self::contact_form_field($contact_form, 'website') . "</li>";
	$show_adrees_details .= "<li><label>Country  : </label>" . self::contact_form_field($contact_form, 'country') . "</li>";
	$show_adrees_details .= "<li><label>Postal Code  : </label>" . self::contact_form_field($contact_form, 'postal_code') . "</li>";
	$show_adrees_details .= "<li><label>Address :</label>" . form::text_area('contact_form', $contact_form->contact_form) . "</li>";
	$show_adrees_details .= "</ul>";
	return $show_adrees_details;
 }

 public static function show_adrees_details_inLine(&$contact_form) {
	if (empty($contact_form)){
	 return ;
	}
	$show_adrees_details = $contact_form->contact_form . '<br>' . $contact_form->postal_code . ','
					. $contact_form->country . '<br>' . $contact_form->phone
					. $contact_form->email . '<br>' . $contact_form->website;
	return $show_adrees_details;
 }

}

?>
