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
class extn_social_login extends dbObject {

 public static $table_name = "extn_social_login";
 public static $module = "extensions";
 public static $primary_column = "extn_social_login_id";
 public static $key_column = "provider_name";
 public static $system_info = [
  'name' => 'extn_social_login',
  'number' => '10033',
  'description' => 'Social Login',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 18
 ];
//  data base variables as stored database column name
 public $field_a = [
  'extn_social_login_id',
  'provider_name',
  'enabled_cb',
  'sl_key',
  'description',
  'slid',
  'sl_secret',
  'sl_scope',
  'display_weight',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  "provider_name"
 ];
//variables used for showing data
 public $checkbox = [
  "enabled_cb",
 ];
 public $initial_search = [
  'provider_name'
 ];
 public $number_fields = ['display_weight'];
 public $pageTitle = " Social Login"; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1
 ];
 public $extn_social_login_id;
 public $provider_name;
 public $enabled_cb;
 public $sl_key;
 public $description;
 public $slid;
 public $sl_secret;
 public $sl_scope;
 public $display_weight;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $show_description = false;

 Public static function sl_stmt() {
  $sl_exnt_details = engine::find_by_className('extn_social_login');
  
  if (empty($sl_exnt_details) || ($sl_exnt_details->enabled_cb != 1)) {
   return false;
  }
  $all_providers = self::find_all();
  
  if (empty($all_providers)) {
   return false;
  }
  $stmt = '<fieldset>
          <ul>
           <li>' . gettext( 'Connect With' ) . '</li>';

  foreach ($all_providers as $k => $sp) {

   switch ($sp->provider_name) {
    case 'Facebook':
     $stmt .='<li><a class="btn btn-default" role="button" '
      . 'href="' . HOME_URL . 'extensions/ino_user/user_login.php?provider=facebook"><i class="fa fa-facebook-square"></i> Facebook</a></li>';
     break;

    case 'Google':
     $stmt .='<li><a class="btn btn-default" role="button" '
      . 'href="' . HOME_URL . 'extensions/ino_user/user_login.php?provider=google"><i class="fa fa-google-plus-square"></i> Google</a></li>';
     break;

    default:
     break;
   }
  }
  $stmt .='</ul>
         </fieldset>';
  return $stmt;
 }

//end of extn_social_login class
}

?>
