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
		 "name",
		 "parent_id",
		 "path_link",
		 "description",
		 "module_code",
		 'obj_class_name',
		 'pmode',
		 "id_column_name",
		 'path_type',
		 "search_path_cb",
		 "ino_enterprise_cb",
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
 public $option_lists = [
		 'module_code' => 'SYS_MODULE',
		 'path_type' => 'EXT_PATH_TYPE',
 ];
 public $path_id;
 public $parent_id;
 public $name;
 public $path_link;
 public $description;
 public $module_code;
 public $obj_class_name;
 public $ino_enterpriset_cb;
 public $pmode;
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
 private $_path_parent_ids = '';
 private $_allowed_path_ids = '';
 private $_show_misc_paths = true;

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
	 return htmlentities(HOME_URL . $value);
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
	$sql = " SELECT * from path , engine ";
	$sql .= " WHERE path.path_id IN ($path_ids_s)  
            AND  engine.obj_class_name = path.obj_class_name
           AND engine.enabled_cb = 1";
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
	$sql .= " WHERE obj_class_name = :obj_class_name AND pmode <= :pmode ";
//	$sql .= " UNION SELECT * FROM ";
//	$sql .= self::$table_name;
//	$sql .= " WHERE mode IS NULL ";

	$value_a = ['obj_class_name' => $obj_class_name, 'pmode' => $mode];
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
	}' ";
	$sql = ino_perPageSql_i($sql, 1);
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_idColumn_name($idColumn_name) {
	$sql = "SELECT * FROM " . self::$table_name . " where id_column_name=' {
	 $idColumn_name
	}' ";
	$sql = ino_perPageSql_i($sql, 1);
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_name($name) {
	$sql = "SELECT * FROM " . self::$table_name . " where path_link REGEXP ' {
	 $name
	}$' ";
	$sql = ino_perPageSql_i($sql, 1);
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
		$path->pmode = isset($data['mode']) ? $data['mode'] : null;
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

 public function findBy_moduleCode($module_code, $type = '', array $parent_ids = null) {
	if (empty($parent_ids)) {
	 $sql = " SELECT path_id from path where  module_code = '{$module_code}'"
					 . " AND (parent_id IS NULL OR parent_id = 0) ";
	 $parent_ids = $this->findFirstColumn_BySql_array($sql);
	} else {
	 $this->_show_misc_paths = false;
	}
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

 public function findBy_module_inAset($module, $set_of_ids = '') {
	$sql = "SELECT * FROM path WHERE module_code = :module_code ";
	if (!empty($set_of_ids)) {
	 $sql .= " AND path_id IN ('" . implode("','", $set_of_ids) . "')";
	}
	$sql .= " ORDER BY display_weight ASC ";
	$value_a = ['module_code' => $module];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? $result : false;
 }

 public function indented_pathMenu(&$allowed_path_ids, $divClass = '') {
	$path = new path();
	$level = 0;
	$allPaths = '<div class="menu"><ul class="ino-paths block_menu  ' . $divClass . '">';
	foreach ($this->_path_parent_ids as $path_id) {
//   if(!in_array($path_id, $allowed_parent_path_ids)){
//    continue;
//   }
	 $path->findBy_id($path_id);

	 $childs = $path->findAll_childOfPartent($path_id);
	 $child_ids = [];
	 foreach ($childs as $child_p) {
		array_push($child_ids, $child_p->path_id);
	 }
	 if (empty($childs) || empty(array_intersect($allowed_path_ids, $child_ids))) {
		//check if other path available for the same module code
		$other_child_paths = $this->findBy_module_inAset($path->module_code, $allowed_path_ids);
		if (!empty($other_child_paths)) {
		 $url = $path->fullPath($path->path_link);
		 $path_name = gettext($path->name);
		 $path_description = gettext($path->description);
		 if ($this->show_description) {
			$allPaths .= "<li data-enterprise=\"$path->ino_enterprise_cb\" title=\"$path_name\" data-toggle=\"tooltip\" class='parent_menu expandable {$path->name} '>" . '<a href="' . $url . '">' . $path_description . '</a>';
		 } else {
			$allPaths .= "<li data-enterprise=\"$path->ino_enterprise_cb\" title=\"$path_description\" data-toggle=\"tooltip\" class='parent_menu expandable {$path->name} '>" . '<a href="' . $url . '">' . $path_name . '</a>';
		 }
		 $allPaths .= '<ul class="child_menu">';

		 foreach ($other_child_paths as $child_paths_oth) {
			$key = array_search($child_paths_oth->path_id, $allowed_path_ids);
			$child_paths_name = gettext($child_paths_oth->name);
			$child_paths_description = gettext($child_paths_oth->description);
			if ($key) {
			 $url_1 = $path->fullPath($child_paths_oth->path_link);
			 if ($this->show_description) {
				$allPaths .= "<li data-enterprise=\"$path->ino_enterprise_cb\" title=\"$child_paths_name\" data-toggle=\"tooltip\" class='expandable {$child_paths_oth->name} '>" . '<a href="' . $url_1 . '">' . $child_paths_description . '</a>';
			 } else {
				$allPaths .= "<li data-enterprise=\"$path->ino_enterprise_cb\" title=\"$child_paths_description\" data-toggle=\"tooltip\" class='expandable {$child_paths_oth->name} '>" . '<a href="' . $url_1 . '">' . $child_paths_name . '</a>';
			 }
			 $allPaths .= $this->_indented_pathMenu_Child($child_paths_oth->path_id, $allowed_path_ids, $allPaths);
			 unset($allowed_path_ids[$key]);
			}
			$allPaths .= '</li>';
		 }
		 $allPaths .= '</ul>';
		 $allPaths .= '</li>';
		}
		continue;
	 }

	 $url = $path->fullPath($path->path_link);
	 $path_name = gettext($path->name);
	 $path_description = gettext($path->description);
	 if ($this->show_description) {
		$allPaths .= "<li data-enterprise=\"$path->ino_enterprise_cb\" title=\"$path_name\" data-toggle=\"tooltip\" class='parent_menu expandable {$path->name} '>" . '<a href="' . $url . '">' . $path_description . '</a>';
	 } else {
		$allPaths .= "<li data-enterprise=\"$path->ino_enterprise_cb\" title=\"$path_description\" data-toggle=\"tooltip\" class='parent_menu expandable {$path->name} '>" . '<a href="' . $url . '">' . $path_name . '</a>';
	 }
	 $allPaths .= '<ul class="child_menu">';

	 foreach ($childs as $child_paths) {
		$key = array_search($child_paths->path_id, $allowed_path_ids);
		$child_paths_name = gettext($child_paths->name);
		$child_paths_description = gettext($child_paths->description);
		if ($key) {
		 $url_1 = $path->fullPath($child_paths->path_link);
		 if ($this->show_description) {
			$allPaths .= "<li data-enterprise=\"$child_paths->ino_enterprise_cb\" title=\"$child_paths_name\" data-toggle=\"tooltip\" class='expandable {$child_paths->name} '>" . '<a href="' . $url_1 . '">' . $child_paths_description . '</a>';
		 } else {
			$allPaths .= "<li data-enterprise=\"$child_paths->ino_enterprise_cb\" title=\"$child_paths_description\" data-toggle=\"tooltip\" class='expandable {$child_paths->name} '>" . '<a href="' . $url_1 . '">' . $child_paths_name . '</a>';
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
	 $allPaths .= '<li class="parent_menu expandable">' . '<a href="' . HOME_URL . '">' . gettext('MISC') . '</a>';
	 $allPaths .= '<ul class="child_menu">';
	 foreach ($allowed_path_ids as $path_key => $path_id) {
		$child_paths = $path->findBy_id($path_id);
		$url_1 = $path->fullPath($child_paths->path_link);
		if ($this->show_description) {
		 $allPaths .= "<li data-enterprise=\"$child_paths->ino_enterprise_cb\" title=\"$child_paths->name\" class='expandable {$path->name} '>" . '<a href="' . $url_1 . '">' . $child_paths->description . '</a>';
		} else {
		 $allPaths .= "<li data-enterprise=\"$child_paths->ino_enterprise_cb\" title=\"$child_paths->description\" class='expandable {$path->name} '>" . '<a href="' . $url_1 . '">' . $child_paths->name . '</a>';
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

 public function panel_pathMenu(&$allowed_path_ids, $divClass = '') {
	$path = new path();
	$level = 0;
	array_unshift($allowed_path_ids, null);
	unset($allowed_path_ids[0]);
	$allPaths = '<div class="panel panel-ino-light-grey ino-paths">';
	foreach ($this->_path_parent_ids as $path_id) {
	 $path->findBy_id($path_id);
	 $url = $path->fullPath($path->path_link);
	 $p_name = $path->name;
	 $p_desc = $path->description;
	 $allPaths .= '<div class="panel-heading dashboard">';
	 $allPaths .= '<ul class=inline-list>';
	 $allPaths .= "<li title=\"My Dashboard\" >" .
					 '<a  class="ajax-link" href="' . HOME_URL . 'form.php?class_name=user_dashboard_v"> ' . gettext('Dashboard') . '  >> </a></li>';
	 if ($this->show_description) {
		$allPaths .= "<li data-enterprise=\"$path->ino_enterprise_cb\" title=\"$p_name\" class='{$path->name} '>" . '<a  class="ajax-link" href="' . $url . '">' . gettext($p_desc) . '</a></li>';
	 } else {
		$allPaths .= "<li data-enterprise=\"$path->ino_enterprise_cb\" title=\"$p_desc\" class='{$path->name} '>" . '<a  class="ajax-link" href="' . $url . '">' . gettext($p_name) . '</a></li>';
	 }
	 $allPaths .= '</ul></div>';
	 $allPaths .= '<div class="panel-body"><ul class="child_menu">';
	 $childs = $path->findAll_childOfPartent($path_id);
	 foreach ($childs as $child_paths) {
		
		$key = array_search($child_paths->path_id, $allowed_path_ids);
		$p_name_child = $child_paths->name;
		$p_desc_child = $child_paths->description;
		$fa_icon = ino_icon($child_paths->path_type);
		if ($key) {
		 $url_1 = $path->fullPath($child_paths->path_link);
		 if ($this->show_description) {
			$allPaths .= "<li  data-enterprise=\"$child_paths->ino_enterprise_cb\" title=\"$p_name_child\" class='expandable {$child_paths->name}'>" . '<a class="list-header" href="' . $url_1 . '">&nbsp;' . $fa_icon . ' &nbsp; ' . gettext($p_desc_child) . '</a>';
		 } else {
			$allPaths .= "<li  data-enterprise=\"$child_paths->ino_enterprise_cb\" title=\"$p_desc_child\" class='expandable {$child_paths->name}'>" . '<a class="list-header" href="' . $url_1 . '">&nbsp;' . $fa_icon . ' &nbsp; ' . gettext($p_name_child) . '</a>';
		 }
		 $allPaths .= $this->_indented_pathMenu_Child($child_paths->path_id, $allowed_path_ids, $allPaths);
		 unset($allowed_path_ids[$key]);
		}
		$allPaths .= '</li>';
	 }
	 $allPaths .= '</ul>';
	}


	if (!empty($allowed_path_ids) && is_array($allowed_path_ids) && !empty($allowed_path_ids['1']) && !empty($allowed_path_ids[0]) && $allowed_path_ids[0] != '11') {
	 if (!empty($allowed_path_ids) && is_array($allowed_path_ids) && ($this->_show_misc_paths)) {
		$allPaths .= '<ul>';
		$allPaths .= '<li class="parent_menu expandable misc">' . '<a href="' . HOME_URL . '">' . gettext('MISC') . '</a>';
		$allPaths .= '<ul class="child_menu">';
		foreach ($allowed_path_ids as $path_key => $path_id) {
		 
		 $child_paths = $path->findBy_id($path_id);
		 $url_1 = $path->fullPath($child_paths->path_link);
		 if ($this->show_description) {
			$allPaths .= "<li data-enterprise=\"$child_paths->ino_enterprise_cb\" title=\"$child_paths->name\" class='expandable  {$child_paths->name}'>" . '<a href="' . $url_1 . '">' . $child_paths->description . '</a>';
		 } else {
			$allPaths .= "<li data-enterprise=\"$child_paths->ino_enterprise_cb\" title=\"$child_paths->description\" class='expandable  {$child_paths->name}'>" . '<a href="' . $url_1 . '">' . $child_paths->name . '</a>';
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

 private function _indented_pathMenu_Child($path_id, &$allowed_path_ids, &$allPaths, &$list_count = 0) {
	$path = new path();

	$all_child = $path->findAll_childOfPartent($path_id);
	if (empty($all_child)) {
	 return;
	}
	$allPaths .= '<ul class="list-line-ul">';
	foreach ($all_child as $child_paths) {
	 if ($list_count % 3 == 0 && $list_count != 0) {
		$allPaths .= '</ul><ul class="list-line-ul second-level">';
	 }
	 $list_count++;
	 $key = array_search($child_paths->path_id, $allowed_path_ids);
	 $fa_icon = ino_icon($child_paths->path_type);
	 if ($key) {
		$url = $path->fullPath($child_paths->path_link);
		$path_name = gettext($child_paths->name);
		$path_description = gettext($child_paths->description);
		$allPaths .= "<li data-enterprise=\"$child_paths->ino_enterprise_cb\" title=\"$path_description\" class='expandable {$child_paths->name} '>&nbsp;&nbsp;" . '<a href="' . $url . '">' . $fa_icon . '&nbsp;' . gettext($path_name) . '</a>';
		$allPaths .= $this->_indented_pathMenu_Child($child_paths->path_id, $allowed_path_ids, $allPaths, $list_count);
		$allPaths .= '</li>';
		unset($allowed_path_ids[$key]);
	 }
	}
	$allPaths .= '</ul>';
 }

 public function path_allpaths_block($param_a) {
	$path_i = empty($param_a['path_i_a']) ? $this->findAll_pathId() : $param_a['path_i_a'];
	$this->_path_parent_ids = $path_parent_ids = empty($param_a['parent_id_a']) ? $this->findAll_parentPathId() : $param_a['parent_id_a'];
	$divClass = empty($param_a['divClass']) ? '' : $param_a['divClass'];

//  pa($path_i); pa($_SESSION['allowed_path_ids']);
	$allowed_path_ids_all = array_intersect($path_i, $_SESSION['allowed_path_ids']);
//  $allowed_parent_path_ids = array_intersect($path_parent_ids, $_SESSION['allowed_path_ids']);
	$this->_allowed_path_ids = $allowed_path_ids = array_diff($allowed_path_ids_all, $this->_path_parent_ids);
	if (empty($allowed_path_ids)) {
	 return null;
	}
	if ($this->_path_display_type == 'panel') {
	 $allPaths = $this->panel_pathMenu($allowed_path_ids, $divClass);
	} else {
	 $allPaths = $this->indented_pathMenu($allowed_path_ids, $divClass);
	}
	return $allPaths;
 }

//end of path class
}

?>
