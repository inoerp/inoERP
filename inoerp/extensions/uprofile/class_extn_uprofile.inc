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
class extn_uprofile extends dbObject {

 public static $table_name = "extn_uprofile";
 public static $primary_column = "extn_uprofile_id";
 public static $key_column = 'profile_name';
 public static $module = "extensions";
 public static $allow_search = false;
 public static $system_info = [
  'name' => 'User Profile',
  'number' => '10046',
  'description' => 'Define and mainten user profile',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 29
 ];
 public $field_a = [
  'extn_uprofile_id',
  'user_id',
  'website',
  'google_page',
  'profile_name',
  'about',
  'facebook_page',
  'linkedin_page',
  'allow_private_msg_cb',
  'show_my_email_cb',
  'show_my_phone_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'user_id',
  'profile_name',
 ];
 public $requiredField = [
  'user_id',
  'profile_name',
 ];
 public $fields_inForm_notInDataBase = [
  'username'
 ];
 public $extn_uprofile_id;
 public $user_id;
 public $google_page;
 public $profile_name;
 public $about;
 public $website;
 public $facebook_page;
 public $linkedin_page;
 public $allow_private_msg_cb;
 public $show_my_email_cb;
 public $show_my_phone_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $username;
 public static $header_tab_1 = [
  [
   'name' => 'profile_name',
   'field_function' => 'l_text_field_d'
  ],
  [
   'name' => 'username',
   'field_function' => 'l_text_field_d',
   'function_parameters' => ['always_readonly'],
  ],

//  [
//   'name' => 'username',
//   'field_function' => 'l_val_field_d',
//   'function_parameters' => ['username', 'user', 'username','','always_readonly'],
//   'hidden_fields' => ['user_id']
//  ], 
  [
   'name' => 'google_page',
   'field_function' => 'l_text_field_d'
  ],
    [
   'name' => 'user_id',
   'field_function' => 'hidden_field_d',
   'function_parameters' => ['user_id' ],
  ]
 ];
 public static $no_ofline_tabs = 1;
 public static $line_tab_1 = [
  'ul_class' => 'column header_field one_column_form',
  'tab_heading' => 'About',
  [
   'name' => 'website',
   'field_function' => 'l_text_field_d'
  ],
    [
   'name' => 'facebook_page',
   'field_function' => 'l_text_field_d'
  ],
  [
   'name' => 'linkedin_page',
   'field_function' => 'l_text_field_d'
  ],
  [
   'name' => 'allow_private_msg_cb',
   'field_function' => 'l_checkBox_field_d'
  ],
  [
   'name' => 'show_my_email_cb',
   'field_function' => 'l_checkBox_field_d'
  ],
  [
   'name' => 'show_my_phone_cb',
   'field_function' => 'l_checkBox_field_d'
  ],
  [
   'name' => 'about',
   'field_function' => 'text_area'
  ]
 ];

 public function findBy_userId() {
  $sql = "SELECT * FROM " . self::$table_name . " where user_id='{$this->user_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }
 
  public static function find_by_userId($user_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where user_id='{$user_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_currentUser() {
  if ($_SESSION['user_id']) {
   $this->user_id = $_SESSION['user_id'];
   return $this->findBy_userId();
  } else {
   return false;
  }
 }

}

?>
