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
class role_access extends dbObject {

 public static $table_name = "role_access";
 public static $primary_column = "role_access_id";
 public static $key_column = 'obj_class_name';
 public static $module = "extensions";
 public static $system_info = [
		 'name' => 'Role Access',
		 'number' => '10019',
		 'description' => 'Define and mainten role access',
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
		 '3' => 'Write',
		 '4' => 'Update Own Content',
		 '5' => 'Update Any Content',
		 '9' => 'Update All'
 ];
 public $field_a = [
		 'role_access_id',
		 'role_code',
		 'obj_class_name',
		 'access_level',
//		 'read_only_own_content_cb',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 "role_access_id",
		 "role_code",
 ];
 public $column = [
		 'role_access_id',
		 'role_code',
		 'obj_class_name',
		 'access_level',
 ];
 public $requiredField = [
		 'role_code',
		 'obj_class_name',
		 'access_level',
 ];
 public $role_access_id;
 public $role_code;
 public $obj_class_name;
 public $access_level;
 public $read_only_own_content_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

// function __construct() {
//	self::assign_role_accesss();
// }

 function __construct() {
	if ((!empty($_SESSION['user_roles']) && empty($_SESSION['allowed_path_ids']))) {
	 $ra_a = [];
	 foreach ($_SESSION['user_roles'] as $key_r => $role_code) {
		$ra_i = $this->findBy_roleCode($role_code);
		if (empty($ra_i)) {
		 continue;
		}
		foreach ($ra_i as $role_access) {
		 $ra_a[$role_access->obj_class_name] = $role_access->access_level;
		}
	 }
	 $ra_a['user_dashboard_v'] = 2;
	 $ra_a['user_dashboard_config'] = 9;
	 $ra_a['user_favourite'] = 2;
//   $ra_a['sys_notification_user'] = 2;
	 $ra_a['user_activity_v'] = 2;
	 $_SESSION['role_access'] = $ra_a;
	 $this->assign_role_accesss_paths();
	}
 }

 public function assign_role_accesss_paths() {
	if (empty($_SESSION['allowed_path_ids']) &&
					!empty($_SESSION['user_id']) &&
					(in_array('ADMIN', $_SESSION['user_roles']))) {
	 $allowed_path_ids = [];
	 $allowed_modules = [];
	 $paths = path::find_all('display_weight');
	 foreach ($paths as $path) {
		$allowed_path_ids[] = $path->path_id;
		if (!in_array($path->module_code, $allowed_modules)) {
		 $allowed_modules[] = $path->module_code;
		}
	 }
	 $_SESSION['allowed_path_ids'] = $allowed_path_ids;
	 $_SESSION['allowed_modules'] = $allowed_modules;
	} else if (empty($_SESSION['allowed_path_ids']) &&
					(!empty($_SESSION['user_roles']))) {
	 $allowed_path_ids = [];
	 $allowed_modules = [];
	 foreach ($_SESSION['role_access'] as $obj_class_name => $mode) {
		$path = new path();
		$paths = $path->findBy_oBjClassName_Mode($obj_class_name, $mode);
		if (!empty($paths)) {
		 foreach ($paths as $path) {
			array_push($allowed_path_ids, $path->path_id);
			if (!in_array($path->module_code, $allowed_modules)) {
			 $allowed_modules[] = $path->module_code;
			}
		 }
		}
	 }
	 $_SESSION['allowed_modules'] = $allowed_modules;
	 $_SESSION['allowed_path_ids'] = $allowed_path_ids;
	}
 }

// public function check_path_access() {
//	$url = $_SERVER['REQUEST_URI'];
//	$path = path::get_path_from_url($url);
//
//	if (($path == 'index.php' || $path == 'extensions/ino_user/user_login.php' || $path == 'extensions/ino_user/user_logout.php' || $path == 'include/basics/json.basics.php')) {
//	 $path_allowed = 1;
//	} else {
//	 $path_id = path::get_path_id_from_url($url);
////		echo "<br/>path id is $path_id";
//
//	 if (!empty($_SESSION['allowed_path_ids'])) {
//		$path_allowed = in_array($path_id, $_SESSION['allowed_path_ids']);
//	 } else {
//		$path_allowed = 0;
//	 }
//	}
////	echo "<br/>path_allowed is $path_allowed";
//	return $path_allowed;
// }

 Public static function roles() {
	$option_type = option_header::find_by_name('USER_ROLES');
	$option_line = option_line::find_by_option_id($option_type->option_header_id);
	return $option_line;
 }

 public function findBy_roleCode($role_code) {
	$sql = "SELECT * FROM " . self::$table_name . " where role_code='{$role_code}' ";
	$result = $this->findBySql($sql);
	return !empty($result) ? $result : false;
 }

 public static function find_by_roleCode($role_code) {
	$sql = "SELECT * FROM " . self::$table_name . " where role_code='{$role_code}' ";
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : false;
 }

 public static function role_access_all_v() {
	global $db;
	$sql = " SELECT * FROM ";
	$sql .=" role_access AS rp , option_line  AS ol";
	$sql .=" WHERE rp.role_code = ol.option_line_id ";

	$result = $db->result_array_assoc($sql);

	return $result;
 }

 Public static function all_roles() {
	$option_header = option_header::find_by_name('USER_ROLES');
	$all_roles = option_line::find_by_option_id($option_header->option_header_id);
	return $all_roles;
 }

}

$role_access = new role_access();
$ra = &$role_access;





//global $path_access;
//
//if (!empty($_SESSION['user_id'])) {
// $path_access = -99;
//
// $role_access->assign_role_accesss();
//
////check if admin role is assigned
// if (in_array('admin', $_SESSION['user_roles'])) {
//	$path_access = 99;
// }
//
////check the role path access
// if ($path_access < 0) {
//	$path_allowed = $role_access->check_path_access();
//	if ($path_allowed) {
//	 $path_access = 1;
//	}
// }
//}
?>
