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
class user_dashboard_config extends dbObject {

 public static $table_name = "user_dashboard_config";
 public static $primary_column = "user_dashboard_config_id";
 public static $key_column = 'report_id';
 public static $module = "extensions";
 public static $system_info = [
  'name' => 'Dashboard Config',
  'number' => '10028',
  'description' => 'Dashboard Config',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 28
 ];
 public static $config_level_a = [
  'USER' => 'User',
  'ROLE' => 'Role',
  'GLOBAL' => 'Global'
 ];
 public static $report_type_a = [
  'block' => 'Block',
  'view' => 'View'
 ];
 public $field_a = [
  'user_dashboard_config_id',
  'config_level',
  'user_role',
  'user_id',
  'report_group',
  'report_type',
  'report_id',
  'priority',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'user_id',
  'report_group',
  'report_type',
 ];
 public $requiredField = [
  'report_group',
  'report_type',
  'report_id',
 ];
 public $fields_inForm_notInDataBase = [
  'username'
 ];
 public $user_dashboard_config_id;
 public $config_level;
 public $user_id;
 public $user_role;
 public $report_group;
 public $report_type;
 public $report_id;
 public $priority;
 public $fav_group;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $username;

 Public static function report_group() {
  $option_type = option_header::find_by_name('USER_REPORT_GROUP');
  $option_line = option_line::find_by_option_id($option_type->option_header_id);
  return $option_line;
 }

 public function findBy_userId() {
  $sql = "SELECT * FROM " . self::$table_name . " where user_id='{$this->user_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 public function findBy_currentUser() {
  if ($_SESSION['user_id']) {
   $this->user_id = $_SESSION['user_id'];
   return $this->findBy_userId();
  } else {
   return false;
  }
 }

 public function show_currentUser_fav() {
  $favs = $this->findBy_currentUser();
  if (!$favs) {
   return false;
  }
  $fav_stmt = '<ul id="favourite">';
  $count = 0;
  foreach ($favs as $links) {
   $divClass = ($count % 2 ) == 0 ? 'even' : 'odd';
   $fav_stmt .= '<li class="' . $divClass . '">';
   if (!empty($links->path_id)) {
    $path = path::find_by_id($links->path_id);
    $fav_stmt .= '<a href="' . HOME_URL . $path->path_link . '">' . $links->fav_name . '</a>';
   } else {
    $fav_stmt .= '<a href="http://' . $links->external_link . '">' . $links->fav_name . '</a>';
   }
   $fav_stmt .= '</li>';
  }
  $fav_stmt .= '</ul>';
  return $fav_stmt;
 }

 public static function find_by_userId($user_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where user_id='{$user_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_roleAndGlobal_configs() {
  $sql = "SELECT * FROM " . self::$table_name . " where config_level IN ('GLOBAL', 'ROLE') ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

?>
