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
class path extends dbObject {

 public static $table_name = "path";
 public static $module = "extensions";
 public static $primary_column = "path_id";
 public static $key_column = "name";
 public static $system_info = [
  'name' => 'Path',
  'number' => '10018',
  'description' => 'System Paths',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 18
 ];
//  data base variables as stored database column name
 public $field_a = [
  "path_id",
  "parent_id",
  "name",
  "path_link",
  "description",
  "module_code",
  'obj_class_name',
  'mode',
  "id_column_name",
  'path_type',
  "search_path_cb",
  'display_weight',
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
 public $requiredField = [
  "name",
  "path_link",
  "module_code"
 ];
//variables used for showing data
 public $checkbox = [
  "search_path_cb",
 ];
 public $initial_search = [
  "path_id",
  "parent_id",
  "name",
  "path_link",
  "description",
  "module_code"
 ];
 public $number_fields = ['display_weight'];
 public $pageTitle = " Path - Find All Paths "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $path_id;
 public $parent_id;
 public $name;
 public $path_link;
 public $description;
 public $module_code;
 public $obj_class_name;
 public $mode;
 public $id_column_name;
 public $path_type;
 public $search_path_cb;
 public $display_weight;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $show_description = false;
 private $_path_display_type = 'menu';

 Public static function path_types() {
  $option_header = option_header::find_by_name('EXT_PATH_TYPE');
  $ol = new option_line();
  $lines = $ol->findBy_parentId($option_header->option_header_id);
  return $lines;
 }

 public static function full_path($value) {
  if ($value) {
   return HOME_URL . $value;
  } else {
   return "";
  }
 }

 public function fullPath($value) {
  if ($value) {
   return htmlspecialchars(HOME_URL . $value);
  } else {
   return "";
  }
 }

 public function findAll_pathId() {
  $sql = " SELECT path_id from path ORDER BY display_weight ASC";
  return $this->findFirstColumn_BySql_array($sql);
 }

 public function findAll_parentPathId() {
  $sql = " SELECT path_id from path where parent_id IS NULL OR parent_id = 0 ORDER BY display_weight ASC ";
  return $this->findFirstColumn_BySql_array($sql);
 }

 public function findAll_childOfPartent($parent_id) {
  $sql = "SELECT * FROM path WHERE parent_id = :parent_id ORDER BY display_weight ASC ";
  $value_a = ['parent_id' => $parent_id];
  return $this->findBySql($sql, $value_a);
 }

 public function findBy_pathIds($path_ids_array) {
  $path_ids_s = join(',', $path_ids_array);
  $sql = " SELECT * from path ";
  $sql .= " WHERE path_id IN ($path_ids_s)";
  return $this->findBySql(findBy_pathIds);
 }

 public function findAll_PathsByString($string) {
  global $dbc;
  $sql = " SELECT path.module_code as module, path.name, path.description, path.path_link 
					  FROM  path 
						WHERE path.path_link LIKE :path_link ";
  $sql .= " ORDER BY path.module_code asc, path.name asc";
  $stmt = $dbc->connection->prepare($sql);
  $string = '%' . $string . '%';
  $stmt->bindValue(':path_link', $string);
  $stmt->execute();
  $result = $stmt->fetchAll(PDO::FETCH_CLASS | PDO::FETCH_GROUP);
  return $result;
 }

 public function findAll_programPaths() {
  return $this->findAll_PathsByString('program');
 }

 public function findAll_searchPaths() {
  global $dbc;
  $sql = " SELECT path.module_code as module, path.name, path.description, path.path_link 
					  FROM  path 
						WHERE path.path_link LIKE :path_link ";
  $sql .= " ORDER BY path.module_code asc, path.name asc";
  $stmt = $dbc->connection->prepare($sql);
  $stmt->bindValue(':path_link', '%search%');
  $stmt->execute();
  $result = $stmt->fetchAll(PDO::FETCH_CLASS | PDO::FETCH_GROUP);
  return $result;
 }

 public function findAll_massUplodPaths() {
  global $dbc;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE path_link LIKE :path_link ";
  $stmt = $dbc->connection->prepare($sql);
  $stmt->bindValue(':path_link', '%massupload%');
  $stmt->execute();
  $result = $stmt->fetchAll(PDO::FETCH_CLASS);
  return $result;
 }

 public function findBy_oBjClassName_Mode($obj_class_name, $mode) {
  global $dbc;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE obj_class_name = :obj_class_name AND mode <= :mode ";
//	$sql .= " UNION SELECT * FROM ";
//	$sql .= self::$table_name;
//	$sql .= " WHERE mode IS NULL ";

  $value_a = ['obj_class_name' => $obj_class_name, 'mode' => $mode];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? $result : false;
 }

 public static function find_all_view_paths() {
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE id_column_name IS NOT NULL ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_path($path) {
  $sql = "SELECT * FROM " . self::$table_name . " where path_link=' {
	 $path
	}' LIMIT 1";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_idColumn_name($idColumn_name) {
  $sql = "SELECT * FROM " . self::$table_name . " where id_column_name=' {
	 $idColumn_name
	}' LIMIT 1";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_name($name) {
  $sql = "SELECT * FROM " . self::$table_name . " where path_link REGEXP ' {
	 $name
	}$' LIMIT 1";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 /* Can be used for checking & updating paths without mode & class name */

 private function _update_className_mode() {
  $all_data = path::find_all();
  $all_class_a = [];
  foreach ($all_data as $data) {
   $this_data = [];
   $this_data['path_id'] = $data->path_id;
   $str = $data->path_link;

   $sub_str = substr($str, strpos($str, '?') + 1, strlen($str));
   $sub_str_a = explode('&', $sub_str);
   foreach ($sub_str_a as $key => $val) {

    if (strpos($val, 'mode') !== false) {
     $val_e = explode('=', $val);
     $this_data[$val_e[0]] = $val_e[1];
    }
    if (strpos($val, 'class_name') !== false) {

     $val_e = explode('=', $val);
     $this_data[$val_e[0]] = $val_e[1];
    }
   }
   array_push($all_class_a, $this_data);
  }
  $path = new path();
  foreach ($all_class_a as $data) {
   if (!empty($data['path_id'])) {
    $path->findBy_id($data['path_id']);
    $path->mode = isset($data['mode']) ? $data['mode'] : null;
    $path->obj_class_name = isset($data['class_name']) ? $data['class_name'] : null;
    $path->audit_trial();
    $path->save();
    $dbc->confirm();
   }
  }
 }

 public static function get_path_from_url($url) {
  if ((strstr($url, 'extensions'))) {
   $path = strstr($url, 'extensions');
  } else if ((strstr($url, 'modules'))) {
   $path = strstr($url, 'modules');
  } else if ((strstr($url, 'include'))) {
   $path = strstr($url, 'include');
  } else if ((strstr($url, '/'))) {
   $final_path = substr(strrchr($url, "/"), 1);
  } else {
   $final_path = "";
  }

  if (!empty($path)) {
   $extra_path_position = strpos($path, '?');
   if (!(empty($extra_path_position))) {
    $final_path = substr($path, '0', $extra_path_position);
   } else {
    $final_path = $path;
   }
  }

  return $final_path;
 }

 public static function get_path_id_from_url($url) {
  $short_url = self::get_path_from_url($url);
  $path = self::find_by_path($short_url);
  return !empty($path->path_id) ? $path->path_id : "";
 }

 public function findBy_moduleCode($module_code, $type = '') {
  $sql = " SELECT path_id from path where  module_code = '{$module_code}'"
   . " AND (parent_id IS NULL OR parent_id = 0) ";
  $parent_ids = $this->findFirstColumn_BySql_array($sql);
  $path_sql = " SELECT path_id from path WHERE module_code = '{$module_code}' ";
  if (!empty($type)) {
   $path_sql .= " AND path_type = '{$type}' ";
  }
  $all_path_ids = $this->findFirstColumn_BySql_array($path_sql);
  $this->_path_display_type = 'panel';
  $paths = '<div id="path_by_module">' . $this->path_allpaths_block(array('parent_id_a' => $parent_ids, 'path_i_a' => $all_path_ids)) . '</div>';
  return $paths;
 }

 /*
  * 1. First find all the ids where parent_id is NULL save in main_path_a
  * 2. 
  */

 public function indented_pathMenu($allowed_parent_path_ids, &$allowed_path_ids, $divClass = '') {
  $path = new path();
  $level = 0;
  $allPaths = '<div class="menu"><ul class="block_menu  ' . $divClass . '">';
  foreach ($allowed_parent_path_ids as $path_id) {
   $path->findBy_id($path_id);
   $url = $path->fullPath($path->path_link);
   if ($this->show_description) {
    $allPaths .= "<li title=\"$path->name\" class='parent_menu expandable {$path->name} '>" . '<a href="' . $url . '">' . $path->description . '</a>';
   } else {
    $allPaths .= "<li title=\"$path->description\" class='parent_menu expandable {$path->name} '>" . '<a href="' . $url . '">' . $path->name . '</a>';
   }
   $allPaths .= '<ul class="child_menu">';
   $childs = $path->findAll_childOfPartent($path_id);
   foreach ($childs as $child_paths) {
    $key = array_search($child_paths->path_id, $allowed_path_ids);
    if ($key) {
     $url_1 = $path->fullPath($child_paths->path_link);
     if ($this->show_description) {
      $allPaths .= "<li title=\"$child_paths->name\" class='expandable {$path->name} '>" . '<a href="' . $url_1 . '">' . $child_paths->description . '</a>';
     } else {
      $allPaths .= "<li title=\"$child_paths->description\" class='expandable {$path->name} '>" . '<a href="' . $url_1 . '">' . $child_paths->name . '</a>';
     }
     $allPaths .= $this->_indented_pathMenu_Child($child_paths->path_id, $allowed_path_ids, $allPaths);
     unset($allowed_path_ids[$key]);
    }
    $allPaths .= '</li>';
   }
   $allPaths .= '</ul>';
   $allPaths .= '</li>';
  }

//  if (!empty($allowed_path_ids) && is_array($allowed_path_ids) && $allowed_path_ids[0] != '11') {
  if (!empty($allowed_path_ids) && is_array($allowed_path_ids)) {
   $allPaths .= '<li class="parent_menu expandable">' . '<a href="' . HOME_URL . '">MISC</a>';
   $allPaths .= '<ul class="child_menu">';
   foreach ($allowed_path_ids as $path_key => $path_id) {
    $child_paths = $path->findBy_id($path_id);
    $url_1 = $path->fullPath($child_paths->path_link);
    if ($this->show_description) {
     $allPaths .= "<li title=\"$child_paths->name\" class='expandable {$path->name} '>" . '<a href="' . $url_1 . '">' . $child_paths->description . '</a>';
    } else {
     $allPaths .= "<li title=\"$child_paths->description\" class='expandable {$path->name} '>" . '<a href="' . $url_1 . '">' . $child_paths->name . '</a>';
    }

    $allPaths .= $this->_indented_pathMenu_Child($child_paths->path_id, $allowed_path_ids, $allPaths);
    $allPaths .= '</li>';
   }
   $allPaths .= '</ul>';
   $allPaths .= '</li>';
  }

  $allPaths .= '</ul></div>';
  return $allPaths;
 }

 public function panel_pathMenu($allowed_parent_path_ids, &$allowed_path_ids, $divClass = '') {
  $path = new path();
  $level = 0;
  $allPaths = '<div class="panel panel-info">';
  foreach ($allowed_parent_path_ids as $path_id) {
   $path->findBy_id($path_id);
   $url = $path->fullPath($path->path_link);
   if ($this->show_description) {
    $allPaths .= "<div title=\"$path->name\" class='panel-heading {$path->name} '>" . '<a href="' . $url . '">' . $path->description . '</a></div>';
   } else {
    $allPaths .= "<div title=\"$path->description\" class='panel-heading {$path->name} '>" . '<a href="' . $url . '">' . $path->name . '</a></div>';
   }
   $allPaths .= '<div class="panel-body"><ul class="child_menu">';
   $childs = $path->findAll_childOfPartent($path_id);
   foreach ($childs as $child_paths) {
    $key = array_search($child_paths->path_id, $allowed_path_ids);
    if ($key) {
     $url_1 = $path->fullPath($child_paths->path_link);
     if ($this->show_description) {
      $allPaths .= "<li title=\"$child_paths->name\" class='expandable {$child_paths->name}'>" . '<a href="' . $url_1 . '">' . $child_paths->description . '</a>';
     } else {
      $allPaths .= "<li title=\"$child_paths->description\" class='expandable {$child_paths->name}'>" . '<a href="' . $url_1 . '">' . $child_paths->name . '</a>';
     }
     $allPaths .= $this->_indented_pathMenu_Child($child_paths->path_id, $allowed_path_ids, $allPaths);
     unset($allowed_path_ids[$key]);
    }
    $allPaths .= '</li>';
   }
   $allPaths .= '</ul>';
  }

  if (!empty($allowed_path_ids) && is_array($allowed_path_ids) && $allowed_path_ids[0] != '11') {
   if (!empty($allowed_path_ids) && is_array($allowed_path_ids)) {
    $allPaths .= '<ul>';
    $allPaths .= '<li class="parent_menu expandable misc">' . '<a href="' . HOME_URL . '">MISC</a>';
    $allPaths .= '<ul class="child_menu">';
    foreach ($allowed_path_ids as $path_key => $path_id) {
     $child_paths = $path->findBy_id($path_id);
     $url_1 = $path->fullPath($child_paths->path_link);
     if ($this->show_description) {
      $allPaths .= "<li title=\"$child_paths->name\" class='expandable  {$child_paths->name}'>" . '<a href="' . $url_1 . '">' . $child_paths->description . '</a>';
     } else {
      $allPaths .= "<li title=\"$child_paths->description\" class='expandable  {$child_paths->name}'>" . '<a href="' . $url_1 . '">' . $child_paths->name . '</a>';
     }

     $allPaths .= $this->_indented_pathMenu_Child($child_paths->path_id, $allowed_path_ids, $allPaths);
     $allPaths .= '</li>';
    }
    $allPaths .= '</ul>';
   }
  }

  $allPaths .= '</div></div>';
  return $allPaths;
 }

 private function _indented_pathMenu_Child($path_id, &$allowed_path_ids, &$allPaths) {
  $path = new path();
  $all_child = $path->findAll_childOfPartent($path_id);
  if (empty($all_child)) {
   return;
  }
  $allPaths .= '<ul>';
  foreach ($all_child as $child_paths) {

   $key = array_search($child_paths->path_id, $allowed_path_ids);
   if ($key) {
    $url = $path->fullPath($child_paths->path_link);
    $allPaths .= "<li title=\"$child_paths->description\" class='expandable {$path->name} '>" . '<a href="' . $url . '">' . $child_paths->name . '</a>';
    $allPaths .= $this->_indented_pathMenu_Child($child_paths->path_id, $allowed_path_ids, $allPaths);
    $allPaths .= '</li>';
    unset($allowed_path_ids[$key]);
   }
  }
  $allPaths .= '</ul>';
 }

 public function path_allpaths_block($param_a) {
  $path_i = empty($param_a['path_i_a']) ? $this->findAll_pathId() : $param_a['path_i_a'];
  $path_parent_ids = empty($param_a['parent_id_a']) ? $this->findAll_parentPathId() : $param_a['parent_id_a'];
  $divClass = empty($param_a['divClass']) ? '' : $param_a['divClass'];

  $allowed_path_ids_all = array_intersect($path_i, $_SESSION['allowed_path_ids']);
  $allowed_parent_path_ids = array_intersect($path_parent_ids, $_SESSION['allowed_path_ids']);
  $allowed_path_ids = array_diff($allowed_path_ids_all, $allowed_parent_path_ids);
  if (empty($allowed_path_ids)) {
   return null;
  }
  if ($this->_path_display_type == 'panel') {
   $allPaths = $this->panel_pathMenu($allowed_parent_path_ids, $allowed_path_ids, $divClass);
  } else {
   $allPaths = $this->indented_pathMenu($allowed_parent_path_ids, $allowed_path_ids, $divClass);
  }
  return $allPaths;
 }

//end of path class
}

?>