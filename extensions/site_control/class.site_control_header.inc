<?php

class site_control_header extends dbObject {

 protected static $table_name = "site_control_header";
 public static $field_array = [
		 'site_control_header_id',
		 'default_home_page',
		 'site_name',
		 'email',
		 'footer_message',
		 'anonymous_user',
		 'anonymous_user_role',
		 'basic_user_role',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 //variables used for showing data

 public static $initial_search_array = [
 ];
 public static $column_array = [
 ];
 public static $account_array = [
 ];
 public static $checkbox_array = [
 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $requiredField_array = [
		 'site_name',
		 'email'
 ];
 public static $primary_column = "site_control_header_id";
 public $site_control_header_id;
 public $default_home_page;
 public $site_name;
 public $email;
 public $footer_message;
 public $anonymous_user;
 public $anonymous_user_role;
 public $basic_user_role;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function _before_showing() {

 }

 public function _before_submit() {
 }


 Public static function wip_supply_type() {
	$option_header = option_header::find_by_name('WIP_SUPPLY_TYPE');
	$wip_supply_type = option_line::find_by_option_id($option_header->option_header_id);
	return $wip_supply_type;
 }


}

//end of bom class
?>



