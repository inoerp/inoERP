<?php

class path extends dbObject {

 protected static $table_name = "path";
 public static $module = "extensions";
 public static $primary_column = "path_id";
 public static $key_column = "name";
//  data base variables as stored database column name
 public $field_a = [
		 "path_id",
		 "parent_id",
		 "name",
		 "path_link",
		 "description",
		 "module_id",
		 "id_column_name",
		 "primary_cb",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public $requiredField = [
		 "name",
		 "path_link",
		 "module_id"
 ];
//variables used for showing data
 public $checkbox = [
		 "primary_cb",
 ];
 public $column = [
		 "path_id",
		 "parent_id",
		 "name",
		 "path_link",
		 "description",
		 "module_id",
 ];
 public $initial_search = [
		 "path_id",
		 "parent_id",
		 "name",
		 "path_link",
		 "description",
		 "module_id"
 ];
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
 public $module_id;
 public $id_column_name;
 public $primary_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function full_path($value) {
	if ($value) {
	 return HOME_URL . $value;
	} else {
	 return "";
	}
 }

 public function findAll_searchPaths() {
	global $dbc;
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE path_link LIKE :path_link ";
	$stmt = $dbc->connection->prepare($sql);
	$stmt->bindValue(':path_link', '%search%');
	$stmt->execute();
	$result = $stmt->fetchAll(PDO::FETCH_CLASS);
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

// public static function find_by_sql($sql = "") {
//	global $db;
//	$result_set = $db->query($sql);
//	$object_array = array();
//	while ($row = $db->fetch_array($result_set)) {
//	 $object_array[] = self::instantiate($row);
//	}//end of while Loop
//	return $object_array;
// }
//
// public static function count_all_by_sql($sql) {
//	global $db;
//	$result_set = $db->query($sql);
//	$row = $db->fetch_array($result_set);
//	return array_shift($row);
// }
//
// public static function count_all() {
//	global $db;
//	$sql = "SELECT COUNT(*) FROM " . self::$table_name;
//	$result_set = $db->query($sql);
//	$row = $db->fetch_array($result_set);
//	return array_shift($row);
// }
//
// public static function find_all() {
//	$sql = " SELECT * FROM " . self::$table_name;
//	$result = self::find_by_sql($sql);
//	return $result;
// }

 public static function find_all_view_paths() {
	$sql = " SELECT * FROM " . self::$table_name;
	$sql .= " WHERE id_column_name IS NOT NULL ";
	$result = self::find_by_sql($sql);
	return $result;
 }

// public static function find_by_id($path_id) {
//	$sql = "SELECT * FROM " . self::$table_name . " where path_id={$path_id} LIMIT 1";
//	$result_array = self::find_by_sql($sql);
//	return !empty($result_array) ? array_shift($result_array) : false;
// }

 public static function find_by_path($path) {
	$sql = "SELECT * FROM " . self::$table_name . " where path_link='{$path}' LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_idColumn_name($idColumn_name) {
	$sql = "SELECT * FROM " . self::$table_name . " where id_column_name='{$idColumn_name}' LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_name($name) {
	$sql = "SELECT * FROM " . self::$table_name . " where path_link REGEXP '{$name}$' LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
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

 public static function path_menu() {
	$sql = "SELECT * FROM `path` WHERE `primary_cb` = 1 ";
	$object = self::find_by_sql($sql);
	echo '<ul id="menu" class="topBottomBG">';
	foreach ($object as $path) {
	 $url = self::full_path($path->path_link);
	 echo '<li>' . '<a href="' . $url . '">' . $path->name . '</a><ul>';
	 $child_sql = "SELECT * FROM `path` WHERE `parent_id` = '{$path->path_id}' ";
	 if ($child_sql) {
		$child_object = self::find_by_sql($child_sql);
		foreach ($child_object as $child_path) {
		 $child_url = self::full_path($child_path->path_link);
		 echo '<li>' . '<a href="' . $child_url . '">' . $child_path->name . '</a></li>';
		}//end of child foreach
	 }//end of if loop
	 echo '</ul> </li>';
	}//end of main for each
	echo '</ul>';
 }

//end of path_menu

 public static function path_page() {
	echo '<table class="normal">
                <thead> 
                    <tr>
                    <th>Path Id</th>
                    <th>Parent</th>
                    <th>Name</th>
                    <th>Value</th>
                    <th>Description</th>
                    <th>Module</th>
                    <th>Primary</th>
                    <th>Created By</th>
                    <th>Creation Date</th>
                    <th>Last Updated By</th>
                    <th>Last Update Date</th>
                    <th>Action</th>
                    </tr>
                </thead>
                <tbody>';

	$path = path::find_all();
	foreach ($path as $record) {
	 echo '<tr><td>' . $record->path_id . '</td>';
	 echo '<td>' . $record->parent_id . '</td>';
	 echo '<td><a href=" ' . path::full_path($record->path_link) . '">' . $record->name . '</a>' . '</td>';
	 echo '<td>' . $record->path_link . '</td> ';
	 echo '<td>' . $record->description . '</td>';
	 echo '<td>' . $record->module . '</td>';
	 echo '<td>' . $record->primary_cb . '</td>';
	 echo '<td>' . $record->created_by . '</td>';
	 echo '<td>' . $record->creation_date . '</td> ';
	 echo '<td>' . $record->last_updated_by . '</td>';
	 echo '<td>' . $record->last_updation_date . '</td>';
	 echo '<td><a href="' . HOME_URL . 'extensions/path/path.php?path_id=' . $record->path_id . '">Update</a></td></tr>';
	}

	echo ' </tbody> </table>';
 }

 public static function path_block_realted_to_module() {
	global $db;
	$r_url = trim($_SERVER['REQUEST_URI']);
	$r_url_expl = explode("/", $r_url);

	if (array_search('modules', $r_url_expl)) {
	 $search = array_search('modules', $r_url_expl);
	 $search++;
	 $search_val = $r_url_expl[$search];
	} elseif (array_search('extensions', $r_url_expl)) {
	 $search = array_search('extensions', $r_url_expl);
	 $search = $search + 1;
	 $search_val = $r_url_expl[$search];
	} else {
	 $search_val = null;
	}

	if (!empty($search_val)) {
	 $sql = "SELECT * FROM " . self::$table_name . " where path_link LIKE '%$search_val%' LIMIT 1";
	}

	$result = $db->query($sql);
	while ($row = $db->fetch_array($result)) {
	 $module = $row['module'];
	}
//serach of paths if there is any
	if (!empty($module)) {
	 echo '<div class="menu">';
	 echo '<ul id="block_menu">';
	 $sql = "SELECT * FROM `path` WHERE `module` = '{$module}' and parent_id='0' ";
	 if ($sql) {
		$object = self::find_by_sql($sql);
		foreach ($object as $path) {
		 $url = self::full_path($path->path_link);
		 echo '<li class="parent_menu expandable">' . '<a href="' . $url . '">' . $path->name . '</a>';
		 $child_sql = "SELECT * FROM `path` WHERE `parent_id` = '{$path->path_id}' ";
		 $child_object = self::find_by_sql($child_sql);
		 echo '<ul class="child_menu ">';
		 foreach ($child_object as $child_path) {
			$child_url = self::full_path($child_path->path_link);
			echo '<li class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a></li>';
		 }
		 echo '</ul></li> ';
		}//end of child foreach
		echo '</ul> ';
		echo '</div> ';
	 }
	}
//end of menu..if no path found then leave blank
 }

 public static function path_block() {
	global $db;

	echo '<div class="menu">';
	//beging of ul1
	echo '<ul id="block_menu">';
	$sql = "SELECT * FROM `path` WHERE parent_id='0' ";
	if ($sql) {
	 $object = self::find_by_sql($sql);
	 foreach ($object as $path) {
		$url = self::full_path($path->path_link);
		//begin of Li1
		echo '<li class="parent_menu expandable">' . '<a href="' . $url . '">' . $path->name . '</a>';
		//next level path values
		$child_sql = "SELECT * FROM `path` WHERE `parent_id` = '{$path->path_id}' ";
		$child_object = self::find_by_sql($child_sql);
		//beging of ul2
		echo '<ul class="child_menu">';
		if (COUNT($child_object) > 0) {
		 foreach ($child_object as $child_path) {
			$child_url = self::full_path($child_path->path_link);
			//begin of Li2
			echo '<li class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';

			//second level menus
			$child_sql2 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
			$child_object2 = self::find_by_sql($child_sql2);
			if (COUNT($child_object2) > 0) {
			 //beging of ul3
			 echo '<ul>';
			 foreach ($child_object2 as $child_path) {
				$child_url = self::full_path($child_path->path_link);
				//begin  of Li3
				echo '<li class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';

				//third level menus
				$child_sql3 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
				$child_object3 = self::find_by_sql($child_sql3);
				if (COUNT($child_object3) > 0) {
				 //beging of ul4
				 echo '<ul>';
				 foreach ($child_object3 as $child_path) {
					$child_url = self::full_path($child_path->path_link);
					//begin & end of Li4
					echo '<li class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a></li>';
				 }
				 echo '</ul>';
				 //end of ul4
				}
				echo '</li> ';
				//end of Li3
			 }
			 echo '</ul>';
			 //end of ul3
			}
			echo '</li> ';
			//end of Li2
		 }
		}//end of child foreach
		echo '</ul>';
		//end of ul2
		echo '</li>';
		//end of Li1
	 }
	}
	echo '</ul> ';
	//end of ul
	echo '</div> ';
 }

 public static function path_allpaths_block_o() {
	global $db;
	$allPaths = "";
	$allPaths .= '<div class="menu">';
	//beging of ul1
	$allPaths .= '<ul class="block_menu">';
	$sql = "SELECT * FROM `path` WHERE parent_id='0' ";
	if ($sql) {
	 $object = self::find_by_sql($sql);
	 foreach ($object as $path) {
		$url = self::full_path($path->path_link);
		//begin of Li1
		$allPaths .= '<li class="parent_menu expandable">' . '<a href="' . $url . '">' . $path->name . '</a>';
		//next level path values
		$child_sql = "SELECT * FROM `path` WHERE `parent_id` = '{$path->path_id}' ";
		$child_object = self::find_by_sql($child_sql);
		//beging of ul2
		$allPaths .= '<ul class="child_menu">';
		if (COUNT($child_object) > 0) {
		 foreach ($child_object as $child_path) {
			$child_url = self::full_path($child_path->path_link);
			//begin of Li2
			$allPaths .= '<li class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';

			//second level menus
			$child_sql2 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
			$child_object2 = self::find_by_sql($child_sql2);
			if (COUNT($child_object2) > 0) {
			 //beging of ul3
			 $allPaths .= '<ul>';
			 foreach ($child_object2 as $child_path) {
				$child_url = self::full_path($child_path->path_link);
				//begin  of Li3
				$allPaths .= '<li  class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';

				//third level menus
				$child_sql3 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
				$child_object3 = self::find_by_sql($child_sql3);
				if (COUNT($child_object3) > 0) {
				 //beging of ul4
				 $allPaths .= '<ul>';
				 foreach ($child_object3 as $child_path) {
					$child_url = self::full_path($child_path->path_link);
					//begin & end of Li4
					$allPaths .= '<li  class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';
					//fourth level menus
					$child_sql4 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
					$child_object4 = self::find_by_sql($child_sql4);
					if (COUNT($child_object4) > 0) {
					 //beging of ul5
					 $allPaths .= '<ul>';
					 foreach ($child_object4 as $child_path) {
						$child_url = self::full_path($child_path->path_link);
						//begin & end of Li5
						$allPaths .= '<li  class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';
						//fifth level menus
						$child_sql5 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
						$child_object5 = self::find_by_sql($child_sql5);
						if (COUNT($child_object5) > 0) {
						 //beging of ul6
						 $allPaths .= '<ul>';
						 foreach ($child_object5 as $child_path) {
							$child_url = self::full_path($child_path->path_link);
							//begin & end of Li6
							$allPaths .= '<li  class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a></li>';
						 }
						 $allPaths .= '</ul>';
						 //end of ul6
						}
						$allPaths .= '</li> ';
						//end of Li5
					 }
					 $allPaths .= '</ul>';
					 //end of ul5
					}
					$allPaths .= '</li> ';
					//end of Li4
				 }
				 $allPaths .= '</ul>';
				 //end of ul4
				}
				$allPaths .= '</li> ';
				//end of Li3
			 }
			 $allPaths .= '</ul>';
			 //end of ul3
			}
			$allPaths .= '</li> ';
			//end of Li2
		 }
		}//end of child foreach
		$allPaths .= '</ul>';
		//end of ul2
		$allPaths .= '</li>';
		//end of Li1
	 }
	}
	$allPaths .= '</ul> ';
	//end of ul
	$allPaths .= '</div> ';

	return $allPaths;
 }

 public static function path_allpaths_block() {
	global $db;
	print_r($_SESSION);
	if (!empty($_SESSION['allowed_path_ids'])) {
	 $pathids_for_user = $_SESSION['allowed_path_ids'];
	} else {
	 $pathids_for_user = [];
	}


	$allPaths = "";
	$allPaths .= '<div class="menu">';
	//beging of ul1
	$allPaths .= '<ul class="block_menu">';
	$sql = "SELECT * FROM `path` WHERE parent_id=0 || parent_id IS NULL ";
	if ($sql) {
	 $object = self::find_by_sql($sql);
	 foreach ($object as $path) {
		$url = self::full_path($path->path_link);
		//begin of Li1
		if (in_array($path->path_id, $pathids_for_user)) {
		 $allPaths .= '<li class="parent_menu expandable">' . '<a href="' . $url . '">' . $path->name . '</a>';
		}
		//next level path values
		$child_sql = "SELECT * FROM `path` WHERE `parent_id` = '{$path->path_id}' ";
		$child_object = self::find_by_sql($child_sql);
		//beging of ul2
		$allPaths .= '<ul class="child_menu">';
		if (COUNT($child_object) > 0) {
		 foreach ($child_object as $child_path) {
			$child_url = self::full_path($child_path->path_link);
			//begin of Li2
			if (in_array($child_path->path_id, $pathids_for_user)) {
			 $allPaths .= '<li class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';
			}
			//second level menus
			$child_sql2 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
			$child_object2 = self::find_by_sql($child_sql2);
			if (COUNT($child_object2) > 0) {
			 //beging of ul3
			 $allPaths .= '<ul>';
			 foreach ($child_object2 as $child_path) {
				$child_url = self::full_path($child_path->path_link);
				//begin  of Li3
				if (in_array($child_path->path_id, $pathids_for_user)) {
				 $allPaths .= '<li  class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';
				}
				//third level menus
				$child_sql3 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
				$child_object3 = self::find_by_sql($child_sql3);
				if (COUNT($child_object3) > 0) {
				 //beging of ul4
				 $allPaths .= '<ul>';
				 foreach ($child_object3 as $child_path) {
					$child_url = self::full_path($child_path->path_link);
					//begin & end of Li4
					if (in_array($child_path->path_id, $pathids_for_user)) {
					 $allPaths .= '<li  class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';
					}
					//fourth level menus
					$child_sql4 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
					$child_object4 = self::find_by_sql($child_sql4);
					if (COUNT($child_object4) > 0) {
					 //beging of ul5
					 $allPaths .= '<ul>';
					 foreach ($child_object4 as $child_path) {
						$child_url = self::full_path($child_path->path_link);
						//begin & end of Li5
						if (in_array($child_path->path_id, $pathids_for_user)) {
						 $allPaths .= '<li  class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';
						}//fifth level menus
						$child_sql5 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
						$child_object5 = self::find_by_sql($child_sql5);
						if (COUNT($child_object5) > 0) {
						 //beging of ul6
						 $allPaths .= '<ul>';
						 foreach ($child_object5 as $child_path) {
							$child_url = self::full_path($child_path->path_link);
							//begin & end of Li6
							if (in_array($child_path->path_id, $pathids_for_user)) {
							 $allPaths .= '<li  class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a></li>';
							}
						 }
						 $allPaths .= '</ul>';
						 //end of ul6
						}
						$allPaths .= '</li> ';
						//end of Li5
					 }
					 $allPaths .= '</ul>';
					 //end of ul5
					}
					$allPaths .= '</li> ';
					//end of Li4
				 }
				 $allPaths .= '</ul>';
				 //end of ul4
				}
				$allPaths .= '</li> ';
				//end of Li3
			 }
			 $allPaths .= '</ul>';
			 //end of ul3
			}
			$allPaths .= '</li> ';
			//end of Li2
		 }
		}//end of child foreach
		$allPaths .= '</ul>';
		//end of ul2
		$allPaths .= '</li>';
		//end of Li1
	 }
	}
	$allPaths .= '</ul> ';
	//end of ul
	$allPaths .= '</div> ';

	return $allPaths;
 }

//end of menu..if no path found then leave blank
//end of path class
}

?>
