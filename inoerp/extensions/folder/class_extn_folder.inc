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
class extn_folder extends dbObject {
 /* 1. Major folder is a folder which doesnt have any parent
	* 2. Primary folder is a folder which is place holder and contains only other categories.
	* Primary categories are not avaiable for selection on any content
	* 3. Major categories does not need to a primary folder.
	* 4. Both needs to be configured properly as per the business requirements
	*/

 public static $table_name = "extn_folder";
 public static $primary_column = "extn_folder_id";
 public static $key_column = "folder";
 public static $module = "extension";
//  data base variables as stored database column name
 public static $system_info = [
		 'name' => 'folder',
		 'number' => '10011',
		 'description' => 'Create & Mainten Folder',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'extn',
		 'weight' => 11
 ];
 public static $content_relation_a = [
		 'ONLY_ONE' => 'One folder From Primary',
		 'MULTIPLE' => 'Multiple folder From Primary',
 ];
 public $field_a = [
		 "extn_folder_id",
		 "major_extn_folder_id",
		 "parent_id",
		 "folder",
		 'folder_type',
		 "description",
		 "primary_cb",
		 'content_relation',
		 'priority',
		 'image_file_id',
		 'org_id',
		 'long_description',
		 'filter_catalog_id',
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
// public static $base_encoded_array = ["content"];
//variables used for showing data

 public $checkbox = [
		 "primary_cb"
 ];
 public $initial_search = [
		 "major_extn_folder_id",
		 "extn_folder_id",
		 "parent_id",
		 "folder",
		 "description",
		 "primary_cb"
 ];
 public $requiredField = ["folder"
 ];
 public $pageTitle = " folder "; //page Title
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
		 '_extra_path' => array('form.php?class_name=folder_relation&mode=9' => 'Indented folder')
 ];
 public $folder_reference_id;
 public $extn_folder_id;
 public $major_extn_folder_id;
 public $parent_id;
 public $content_relation;
 public $folder;
 public $folder_type;
 public $description;
 public $primary_cb;
 public $priority;
 public $image_file_id;
 public $long_description;
 public $org_id;
 public $filter_catalog_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 Public static function folder_types() {
	$option_header = option_header::find_by_exact_name('EXTN_FOLDER_TYPE');
	$countries = option_line::find_by_option_id($option_header->option_header_id);
	return $countries;
 }

 public function _before_showing() {
	if (!empty($_GET['parent_id'])) {
	 $this->parent_id = $_GET['parent_id'];
	}
 }

 public function findAll_majorCategories() {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE parent_id IS NULL OR parent_id='0' OR parent_id='' ";
	$sql .= " AND primary_cb = '1' ";
	$result = $this->findBySql($sql);
	return $result;
 }

 public function findAll_minorCategories() {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE parent_id IS NOT NULL ";
	$sql .= " AND primary_cb = '1' ";
	$result = $this->findBySql($sql);
	return $result;
 }

 public function findBy_folderId() {
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where extn_folder_id = :extn_folder_id  ";
	$sql = ino_perPageSql_i($sql, 1);
	$value_a = ['extn_folder_id' => $this->extn_folder_id];
	$result_array = $this->findBySql($sql, $value_a);
	return !empty($result_array) ? array_pop($result_array) : false;
 }

 public function findAll_childOfParent($parent_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE parent_id = :parent_id ";
	$value_a = ['parent_id' => $parent_id];
	$result = $this->findBySql($sql, $value_a);
	return !(empty($result)) ? $result : false;
 }

 public $folder_view_stmt = '';

 public function full_folder_explosion_view() {
	$full_explosion = [];
	$all_major_categories = $this->findAll_majorCategories();

	$this->folder_view_stmt = '<ul id="folder_view_stmt" class="first-parent tree_view2" data-plusClass="fa-folder-close-o" data-minusClass="fa-folder-o" >';

	foreach ($all_major_categories as $folder) {
	 $this->folder_view_stmt .= '<li class="parent_menu expandable second-parent" title="Click on folder to view the next level and click on the text to view the files">';
	 $this->folder_view_stmt .= '<a href="#" data-folder_id="'.$folder->extn_folder_id.'">'.$folder->folder.'</a>';
	 $this->folder_view_stmt .= '<ul class="child_menu first-child expandable">';
	 $full_explosion[$folder->extn_folder_id] = $this->_folder_explosion_withPCRelation($folder->extn_folder_id);
	 $this->folder_view_stmt .= '</ul></li>';
	 $this->folder_view_stmt .='<li class="divider"></li>';
	}

	$this->folder_view_stmt .= '</ul>';
//	echo '$this->folder_view_stmt is '. $this->folder_view_stmt;
	echo $this->folder_view_stmt;
 }

 public function full_folder_explosion() {
	$full_explosion = [];
	$all_major_categories = $this->findAll_majorCategories();
	foreach ($all_major_categories as $folder) {
	 $full_explosion[$folder->extn_folder_id] = $this->_folder_explosion_withPCRelation($folder->extn_folder_id);
	}
	return $full_explosion;
 }

 public function folder_explosion($extn_folder_id) {
	$level_array = [];
	$l = 0;
	$array_level = 'array_' . $l;
	$$array_level = [];
	array_push($$array_level, $extn_folder_id);
	array_push($level_array, $$array_level);
	$this->_explosion($extn_folder_id, $level_array, 1);
	return $level_array;
 }

 private function _explosion($extn_folder_id, &$level_array, $level = 0) {
	$cat = new extn_folder();
	$cat_c = $cat->findAll_childOfParent($extn_folder_id);
	if (empty($cat_c)) {
	 return;
	}
	if (empty($level_array[$level])) {
	 $level_array[$level] = [];
	}
	foreach ($cat_c as $cat_new) {
	 foreach ($level_array as &$existing_val_arr) {
		while (($pos = array_search($cat_new->extn_folder_id, $existing_val_arr)) !== false) {
		 unset($existing_val_arr[$pos]);
		}
	 }
	 array_push($level_array[$level], $cat_new->extn_folder_id);
	}
	$level++;
	foreach ($cat_c as $cat_new) {
	 $cat_c = $cat->findAll_childOfParent($cat_new->extn_folder_id);
	 if (!empty($cat_c)) {
		$this->_explosion($cat_new->extn_folder_id, $level_array, $level);
	 }
	}
 }

 public function folder_explosion_withPCRelation($extn_folder_id) {
	$exploded_cat_i = $this->_folder_explosion_withPCRelation($extn_folder_id);
	$exploded_cat[$extn_folder_id] = $exploded_cat_i;
	return $exploded_cat;
 }

 private function _folder_explosion_withPCRelation($parant_cat_id) {
	$cat = new extn_folder();
	$exploded_cat = [];
	$all_childs = $cat->findAll_childOfParent($parant_cat_id);
	if (!empty($all_childs)) {
	 $all_chils_a = [];
	 foreach ($all_childs as $child_cat) {
		$child_of_child = $cat->findAll_childOfParent($child_cat->extn_folder_id);
		if (!empty($child_of_child)) {
		 $this->folder_view_stmt .= '<li class="parent_menu expandable  ">';
		 $this->folder_view_stmt .= '<a href="#" data-folder_id="'.$child_cat->extn_folder_id.'">'.$child_cat->folder.'</a>';
		 $this->folder_view_stmt .= '<ul class="child_menu expandable ">';
		 $all_chils_a[$child_cat->extn_folder_id] = $this->_folder_explosion_withPCRelation($child_cat->extn_folder_id);
		 $this->folder_view_stmt .= '</ul></li>';
		} else {
		 $this->folder_view_stmt .= '<li class="parent_menu ">';
		 $this->folder_view_stmt .= '<a href="#" data-folder_id="'.$child_cat->extn_folder_id.'">'.$child_cat->folder.'</a>';
		 $this->folder_view_stmt .= '<ul class="child_menu">';
		 $all_chils_a[$child_cat->extn_folder_id] = $child_cat->extn_folder_id;
		 $this->folder_view_stmt .= '</ul></li>';
		}
	 }
	 $exploded_cat[$parant_cat_id] = $all_chils_a;
	} else {
	 $exploded_cat[$parant_cat_id] = $parant_cat_id;
	}
	return array_pop($exploded_cat);
 }

 private function _get_next_select_option($folder_a, $selected_cat_id, $level, $disable_primary) {
	$cat = new extn_folder();
	$select_statement = '';
	foreach ($folder_a as $extn_folder_id => $folder_a) {
	 $cat->findBy_id($extn_folder_id);
	 $primary_folder = ($cat->primary_cb == 1) ? ' primary_folder ' : '';
	 $disabled = ($cat->primary_cb == 1 && $disable_primary == true) ? ' disabled ' : '';
	 $selected_cat_id_v = ($selected_cat_id == $cat->extn_folder_id) ? ' selected ' : '';
	 $select_statement .= '<option  ' . $selected_cat_id_v . $disabled . ' class="tab_' . $level . $primary_folder . '" value="' . $cat->extn_folder_id . '">' . $cat->folder . '</option>';
	 if (is_array($folder_a)) {
		$level_n = $level + 1;
		$select_statement .= $this->_get_next_select_option($folder_a, $selected_cat_id, $level_n, $disable_primary);
	 }
	}
	return $select_statement;
 }

 public function all_child_folder_select_option($field_name, $parent_cat_id = '', $selected_cat_id = '', $div_id = '', $disable_primary = true) {
	$cat = new extn_folder();
	if (empty($parent_cat_id)) {
	 $all_categories = $this->full_folder_explosion();
	} else {
	 $all_categories = $this->folder_explosion_withPCRelation($parent_cat_id);
	}
	$bracketed_name = $field_name . '[]';
	$select_statement = "<select id=\"$div_id\" class=\"select folder $field_name\" name=\"$bracketed_name\">";
	$select_statement .= '<option value=""></option>';
	$level = 0;
	foreach ($all_categories as $extn_folder_id => $folder_a) {
	 $cat->findBy_id($extn_folder_id);
	 $primary_folder = ($cat->primary_cb == 1) ? ' primary_folder ' : '';
	 $disabled = ($cat->primary_cb == 1 && $disable_primary == true) ? ' disabled ' : '';
	 $selected_cat_id_v = ($selected_cat_id == $cat->extn_folder_id) ? 'selected' : '';
	 $select_statement .= '<option ' . $selected_cat_id_v . $disabled . '   class="tab_' . $level . $primary_folder . '" value="' . $cat->extn_folder_id . '">' . $cat->folder . '</option>';
	 if (is_array($folder_a)) {
		$level_n = $level + 1;
		$select_statement .= $this->_get_next_select_option($folder_a, $selected_cat_id, $level_n, $disable_primary);
	 }
	}
	$select_statement .= '</select>';
	return $select_statement;
 }
//
// public function findBy_reference_table_and_id($reference_table, $reference_id) {
//	$sql = "SELECT folder.extn_folder_id as extn_folder_id,
//              folder.major_extn_folder_id as major_extn_folder_id,
//               folder.folder as folder, 
//               folder.parent_id as parent_id, 
//               folder.description as description,
//               folder.primary_cb as primary_cb,
//               folder_reference.folder_reference_id as folder_reference_id
//       FROM 
//       folder , folder_reference
//       WHERE folder_reference.reference_table = '{$reference_table}'
//       AND folder_reference.reference_id = '{$reference_id}'
//       AND folder.extn_folder_id = folder_reference.extn_folder_id";
//
//	$result = $this->findBySql($sql);
//	return $result;
// }
//
// private function _get_next_level_folder($folder_a, $content_type_name, $level) {
//	$cat = new extn_folder();
//	$statement = '';
//	foreach ($folder_a as $extn_folder_id => $folder_a) {
//	 $cat->findBy_id($extn_folder_id);
//	 $content_count = content::content_count_by_folderId_contentType($extn_folder_id);
//	 $statement .= "<tr class=\"level_$level\"><td class='link'>";
//	 $statement .= '<a href="' . HOME_URL . 'content.php?content_type=' .
//					 $content_type_name . '&amp;extn_folder_id=' . $extn_folder_id . '">' . $cat->folder . '</a></td>';
//	 if (!empty($content_count)) {
//		$statement .= '<td>' . $cat->description . " <span class='badge'> $content_count </span> </td>";
//	 } else {
//		$statement .= '<td>' . $cat->description . "</td>";
//	 }
//
////   $statement .= '<td>' . self::contentCount_by_folderId_contentType($extn_folder_id) . '</td>';
//	 $statement .= '</tr>';
//	 if (is_array($folder_a)) {
//		$level_n = $level + 1;
//		$statement .= $this->_get_next_level_folder($folder_a, $content_type_name, $level_n);
//	 }
//	}
//	return $statement;
// }
//
// public function show_exploded_folder($extn_folder_id, $content_type_name) {
//	$all_categories = $this->folder_explosion_withPCRelation($extn_folder_id);
//	$statement = '<div class="table_container">';
//	$statement .= "<table  class='table table-striped table-hover'>
//	        <thead>
//          <tr class='headerBgColor2'>
//           <th>" . gettext('folder') . "</th>
//           <th>" . gettext('Description') . "</th>" .
////           <th>" . gettext('Posts') . "</th>
//					"</tr>
//         </thead><tbody>
//				 ";
//
//	$cat = new extn_folder();
//	$cat->findBy_id($extn_folder_id);
//	$content_count = content::content_count_by_folderId_contentType($extn_folder_id);
//	$level = 1;
//	$statement .= "<tr class=\"level_$level\"><td class='link'>";
//	$link_cat = HOME_URL . 'content.php?content_type=' . $content_type_name . '&extn_folder_id=' . $extn_folder_id;
//	$statement .= '<a href="' . htmlspecialchars($link_cat) . '">' . $cat->folder . '</a></td>';
//	if (!empty($content_count)) {
//	 $statement .= '<td>' . $cat->description . " <span class='badge'> $content_count </span> </td>";
//	} else {
//	 $statement .= '<td>' . $cat->description . "</td>";
//	}
//
////  $statement .= '<td>' . self::contentCount_by_folderId_contentType($extn_folder_id) . '</td>';
//	$statement .= '</tr>';
//
//	foreach ($all_categories as $extn_folder_id => $folder_a) {
//	 $cat->findBy_id($extn_folder_id);
//	 if (is_array($folder_a)) {
//		$level_n = $level + 1;
//		$statement .= $this->_get_next_level_folder($folder_a, $content_type_name, $level_n);
//	 }
//	}
//	$statement .= '</tbody></table>';
//	$statement .= '</div>';
//	return $statement;
// }
//
// private function _get_next_level_folder_bookwise($folder_a, $content_type_name, $level) {
//	$cat = new extn_folder();
//	$statement = '';
//	foreach ($folder_a as $extn_folder_id => $folder_a) {
//	 $cat->findBy_id($extn_folder_id);
//	 $statement .= "<tr class=\"level_$level\"><td class='link'>";
//	 $statement .= '<a href="' . HOME_URL . 'content.php?content_type=' .
//					 $content_type_name . '&extn_folder_id=' . $extn_folder_id . '">' . $cat->folder . '</a></td>';
//	 $statement .= '<td>' . $cat->description . '</td>';
//	 $statement .= '<td>' . self::contentCount_by_folderId_contentType($extn_folder_id) . '</td>';
//	 $statement .= '<td></td>';
//	 $statement .= '</tr>';
//	 if (is_array($folder_a)) {
//		$level_n = $level + 1;
//		$statement .= $this->_get_next_level_folder($folder_a, $content_type_name, $level_n);
//	 }
//	}
//	return $statement;
// }
//
// public function show_exploded_folder_bookwise($extn_folder_id, $content_type_name) {
//	$all_categories = $this->folder_explosion_withPCRelation($extn_folder_id);
//	$statement = "<table id='forum_type_folder_list' class='normal'>
//	        <thead>
//          <tr class='headerBgColor'>
//           <th>" . gettext('folder') . "</th>
//           <th>" . gettext('Starting Chapters') . "</th>
//          </tr>
//         </thead>
//				 ";
//
//	$cat = new extn_folder();
//	$cat->findBy_id($extn_folder_id);
//	$level = 1;
//	$statement .= "<tr class=\"level_$level\"><td class='link'>";
//	$statement .= '<a href="' . HOME_URL . 'content.php?content_type=' .
//					$content_type_name . '&extn_folder_id=' . $extn_folder_id . '">' . $cat->folder . '</a></td>';
//	$statement .= '<td>' . $cat->description . '</td>';
//	$statement .= '</tr>';
//
//	foreach ($all_categories as $extn_folder_id => $folder_a) {
//	 $cat->findBy_id($extn_folder_id);
//	 if (is_array($folder_a)) {
//		$level_n = $level + 1;
//		$statement .= $this->_get_next_level_folder($folder_a, $content_type_name, $level_n);
//	 }
//	}
//	$statement .= '</table>';
//
//	return $statement;
// }

}

?>
