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
class user_group_access extends dbObject {

 public static $table_name = "user_group_access";
 public static $primary_column = "user_group_access_id";
 public static $key_column = 'org_id';
 public static $module = "extensions";
 public static $system_info = [
  'name' => 'User Group Access',
  'number' => '10044',
  'description' => 'Define and mainten user froup access',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 19
 ];
//  data base variables as stored database column name
 public static $access_map = [
  '2' => 'Read',
//  '3' => 'Write',
//  '4' => 'Update Own Content',
//  '5' => 'Update Any Content',
  '9' => 'Update All'
 ];
 public $field_a = [
  'user_group_access_id',
  'user_group_code',
  'org_id',
  'access_level',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  "user_group_access_id",
  "user_group_code",
 ];
 public $requiredField = [
  'user_group_code',
  'org_id',
  'access_level',
 ];
 public $user_group_access_id;
 public $user_group_code;
 public $org_id;
 public $access_level;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

// function __construct() {
//	self::assign_user_group_accesss();
// }
// function __construct() {
//  if ((!empty($_SESSION['user_roles']) && empty($_SESSION['allowed_path_ids']))) {
//   $ra_a = [];
//   foreach ($_SESSION['user_roles'] as $key_r => $role_code) {
//    $ra_i = $this->findBy_roleCode($role_code);
//    if (empty($ra_i)) {
//     continue;
//    }
//    foreach ($ra_i as $user_group_access) {
//     $ra_a[$user_group_access->obj_class_name] = $user_group_access->access_level;
//    }
//   }
//   $ra_a['user_dashboard_v'] = 2;
//   $ra_a['user_dashboard_config'] = 9;
//   $ra_a['user_favourite'] = 2;
////   $ra_a['sys_notification_user'] = 2;
//   $ra_a['user_activity_v'] = 2;
//   $_SESSION['user_group_access'] = $ra_a;
//   $this->assign_user_group_accesss_paths();
//  }
// }

 public function assign_user_group_accesss_paths() {
  if (empty($_SESSION['allowed_path_ids']) &&
   !empty($_SESSION['user_id']) &&
   (in_array('ADMIN', $_SESSION['user_roles']))) {
   $paths = path::find_all('display_weight');
   $allowed_path_ids = [];
   foreach ($paths as $path) {
    $allowed_path_ids[] = $path->path_id;
   }
   $_SESSION['allowed_path_ids'] = $allowed_path_ids;
  } else if (empty($_SESSION['allowed_path_ids']) &&
   (!empty($_SESSION['user_roles']))) {
   $allowed_path_ids = [];

   foreach ($_SESSION['user_group_access'] as $obj_class_name => $mode) {
    $path = new path();
    $paths = $path->findBy_oBjClassName_Mode($obj_class_name, $mode);
    if (!empty($paths)) {
     foreach ($paths as $path) {
      $allowed_path_ids[] = $path->path_id;
     }
    }
   }
   $_SESSION['allowed_path_ids'] = $allowed_path_ids;
  }
 }

 public function findBy_groupCode($group_code) {
  $sql = "SELECT * FROM " . self::$table_name . " where user_group_code='{$group_code}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_groupCode($group_code) {
  $sql = "SELECT * FROM " . self::$table_name . " where user_group_code='{$group_code}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_user_id($user_id) {
  $sql = " SELECT ug.ino_user_id, ug.user_group_code, uga.org_id, uga.access_level 
   FROM user_group ug, ino_user, user_group_access uga 
   WHERE ino_user.ino_user_id = ug.ino_user_id 
   AND uga.user_group_code = ug.user_group_code
    AND ino_user.ino_user_id = '{$user_id}'
 ";


  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function user_group_access_all_v() {
  global $db;
  $sql = " SELECT * FROM ";
  $sql .=" user_group_access AS rp , option_line  AS ol";
  $sql .=" WHERE rp.role_code = ol.option_line_id ";

  $result = $db->result_array_assoc($sql);

  return $result;
 }

 Public static function user_groups() {
  $option_header = option_header::find_by_name('USER_GROUPS');
  $all_roles = option_line::find_by_option_id($option_header->option_header_id);
  return $all_roles;
 }

}

?>
