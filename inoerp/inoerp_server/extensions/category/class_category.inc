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
class category extends dbObject {
 /* 1. Major category is a category which doesnt have any parent
  * 2. Primary Category is a category which is place holder and contains only other categories.
  * Primary categories are not avaiable for selection on any content
  * 3. Major categories does not need to a primary category.
  * 4. Both needs to be configured properly as per the business requirements
  */

 public static $table_name = "category";
 public static $primary_column = "category_id";
 public static $key_column = "category";
 public static $module = "extension";
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Category',
  'number' => '10011',
  'description' => 'Create & Mainten Categories',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 11
 ];
 public static $content_relation_a = [
  'ONLY_ONE' => 'One Category From Primary',
  'MULTIPLE' => 'Multiple Category From Primary',
 ];
 public $field_a = [
  "category_id",
  "major_category_id",
  "parent_id",
  "category",
  'category_type',
  "description",
  "primary_cb",
  'content_relation',
  'priority',
  'image_file_id',
  'content_block_id',
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
  "major_category_id",
  "category_id",
  "parent_id",
  "category",
  "description",
  "primary_cb"
 ];

 public $requiredField = ["category"
 ];
 public $pageTitle = " Category "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
  '_extra_path' => array('form.php?class_name=category_relation&mode=9' => 'Indented Category')
 ];
 public $category_reference_id;
 public $category_id;
 public $major_category_id;
 public $parent_id;
 public $content_relation;
 public $category;
 public $category_type;
 public $description;
 public $primary_cb;
 public $priority;
 public $image_file_id;
 public $long_description;
 public $content_block_id;
 public $filter_catalog_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 Public static function category_types() {
  $option_header = option_header::find_by_exact_name('EXTN_CATEGORY_TYPE');
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

 public function findBy_categoryId() {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where category_id = :category_id  ";
  $sql = ino_perPageSql_i($sql, 1);
  $value_a = ['category_id' => $this->category_id];
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

 public function full_category_explosion() {
  $full_explosion = [];
  $all_major_categories = $this->findAll_majorCategories();
  foreach ($all_major_categories as $category) {
   $full_explosion[$category->category_id] = $this->_category_explosion_withPCRelation($category->category_id);
  }
  return $full_explosion;
 }

 public function category_explosion($category_id) {
  $level_array = [];
  $l = 0;
  $array_level = 'array_' . $l;
  $$array_level = [];
  array_push($$array_level, $category_id);
  array_push($level_array, $$array_level);
  $this->_explosion($category_id, $level_array, 1);
  return $level_array;
 }

 private function _explosion($category_id, &$level_array, $level = 0) {
  $cat = new category();
  $cat_c = $cat->findAll_childOfParent($category_id);
  if (empty($cat_c)) {
   return;
  }
  if (empty($level_array[$level])) {
   $level_array[$level] = [];
  }
  foreach ($cat_c as $cat_new) {
   foreach ($level_array as &$existing_val_arr) {
    while (($pos = array_search($cat_new->category_id, $existing_val_arr)) !== false) {
     unset($existing_val_arr[$pos]);
    }
   }
   array_push($level_array[$level], $cat_new->category_id);
  }
  $level++;
  foreach ($cat_c as $cat_new) {
   $cat_c = $cat->findAll_childOfParent($cat_new->category_id);
   if (!empty($cat_c)) {
    $this->_explosion($cat_new->category_id, $level_array, $level);
   }
  }
 }

 public function category_explosion_withPCRelation($category_id) {
  $exploded_cat_i = $this->_category_explosion_withPCRelation($category_id);
  $exploded_cat[$category_id] = $exploded_cat_i;
  return $exploded_cat;
 }

 private function _category_explosion_withPCRelation($parant_cat_id) {
  $cat = new category();
  $exploded_cat = [];
  $all_childs = $cat->findAll_childOfParent($parant_cat_id);
  if (!empty($all_childs)) {
   $all_chils_a = [];
   foreach ($all_childs as $child_cat) {
    $child_of_child = $cat->findAll_childOfParent($child_cat->category_id);
    if (!empty($child_of_child)) {
     $all_chils_a[$child_cat->category_id] = $this->_category_explosion_withPCRelation($child_cat->category_id);
    } else {
     $all_chils_a[$child_cat->category_id] = $child_cat->category_id;
    }
   }
   $exploded_cat[$parant_cat_id] = $all_chils_a;
  } else {
   $exploded_cat[$parant_cat_id] = $parant_cat_id;
  }
  return array_pop($exploded_cat);
 }

 private function _get_next_select_option($category_a, $selected_cat_id, $level, $disable_primary) {
  $cat = new category();
  $select_statement = '';
  foreach ($category_a as $category_id => $category_a) {
   $cat->findBy_id($category_id);
   $primary_category = ($cat->primary_cb == 1) ? ' primary_category ' : '';
   $disabled = ($cat->primary_cb == 1 && $disable_primary == true) ? ' disabled ' : '';
   $selected_cat_id_v = ($selected_cat_id == $cat->category_id) ? ' selected ' : '';
   $select_statement .= '<option  ' . $selected_cat_id_v . $disabled . ' class="tab_' . $level . $primary_category . '" value="' . $cat->category_id . '">' . $cat->category . '</option>';
   if (is_array($category_a)) {
    $level_n = $level + 1;
    $select_statement .=$this->_get_next_select_option($category_a, $selected_cat_id, $level_n, $disable_primary);
   }
  }
  return $select_statement;
 }

 public function all_child_category_select_option($field_name, $parent_cat_id = '', $selected_cat_id = '', $div_id = '', $disable_primary = true) {
  $cat = new category();
  if (empty($parent_cat_id)) {
   $all_categories = $this->full_category_explosion();
  } else {
   $all_categories = $this->category_explosion_withPCRelation($parent_cat_id);
  }
  $bracketed_name = $field_name . '[]';
  $select_statement = "<select id=\"$div_id\" class=\"select category $field_name\" name=\"$bracketed_name\">";
  $select_statement .= '<option value=""></option>';
  $level = 0;
  foreach ($all_categories as $category_id => $category_a) {
   $cat->findBy_id($category_id);
   $primary_category = ($cat->primary_cb == 1) ? ' primary_category ' : '';
   $disabled = ($cat->primary_cb == 1 && $disable_primary == true) ? ' disabled ' : '';
   $selected_cat_id_v = ($selected_cat_id == $cat->category_id) ? 'selected' : '';
   $select_statement .= '<option ' . $selected_cat_id_v . $disabled . '   class="tab_' . $level . $primary_category . '" value="' . $cat->category_id . '">' . $cat->category . '</option>';
   if (is_array($category_a)) {
    $level_n = $level + 1;
    $select_statement .=$this->_get_next_select_option($category_a, $selected_cat_id, $level_n, $disable_primary);
   }
  }
  $select_statement .='</select>';
  return $select_statement;
 }

 public function findBy_reference_table_and_id($reference_table, $reference_id) {
  $sql = "SELECT category.category_id as category_id,
              category.major_category_id as major_category_id,
               category.category as category, 
               category.parent_id as parent_id, 
               category.description as description,
               category.primary_cb as primary_cb,
               category_reference.category_reference_id as category_reference_id
       FROM 
       category , category_reference
       WHERE category_reference.reference_table = '{$reference_table}'
       AND category_reference.reference_id = '{$reference_id}'
       AND category.category_id = category_reference.category_id";

  $result = $this->findBySql($sql);
  return $result;
 }

 private function _get_next_level_category($category_a, $content_type_name, $level) {
  $cat = new category();
  $statement = '';
  foreach ($category_a as $category_id => $category_a) {
   $cat->findBy_id($category_id);
   $content_count = content::content_count_by_categoryId_contentType($category_id);
   $statement .= "<tr class=\"level_$level\"><td class='link'>";
   $statement .= '<a href="' . HOME_URL . 'content.php?content_type=' .
    $content_type_name . '&amp;category_id=' . $category_id . '">' . $cat->category . '</a></td>';
   if(!empty($content_count)){
    $statement .= '<td>' . $cat->description ." <span class='badge'> $content_count </span> </td>";
   }else{
    $statement .= '<td>' . $cat->description ."</td>";
   }
   
//   $statement .= '<td>' . self::contentCount_by_categoryId_contentType($category_id) . '</td>';
   $statement .= '</tr>';
   if (is_array($category_a)) {
    $level_n = $level + 1;
    $statement .=$this->_get_next_level_category($category_a, $content_type_name, $level_n);
   }
  }
  return $statement;
 }

 public function show_exploded_category($category_id, $content_type_name) {
  $all_categories = $this->category_explosion_withPCRelation($category_id);
  $statement = '<div class="table_container">';
  $statement .= "<table  class='table table-striped table-hover'>
	        <thead>
          <tr class='headerBgColor2'>
           <th>" . gettext('Category') . "</th>
           <th>" . gettext('Description') . "</th>" .
//           <th>" . gettext('Posts') . "</th>
   "</tr>
         </thead><tbody>
				 ";

  $cat = new category();
  $cat->findBy_id($category_id);
  $content_count = content::content_count_by_categoryId_contentType($category_id);
  $level = 1;
  $statement .= "<tr class=\"level_$level\"><td class='link'>";
  $link_cat = HOME_URL . 'content.php?content_type=' . $content_type_name . '&category_id=' . $category_id;
  $statement .= '<a href="' . htmlspecialchars($link_cat) . '">' . $cat->category . '</a></td>';
  if(!empty($content_count)){
   $statement .= '<td>' . $cat->description . " <span class='badge'> $content_count </span> </td>";
  }else{
   $statement .= '<td>' . $cat->description . "</td>";
  }
  
//  $statement .= '<td>' . self::contentCount_by_categoryId_contentType($category_id) . '</td>';
  $statement .= '</tr>';

  foreach ($all_categories as $category_id => $category_a) {
   $cat->findBy_id($category_id);
   if (is_array($category_a)) {
    $level_n = $level + 1;
    $statement .=$this->_get_next_level_category($category_a, $content_type_name, $level_n);
   }
  }
  $statement .= '</tbody></table>';
  $statement .= '</div>';
  return $statement;
 }

 private function _get_next_level_category_bookwise($category_a, $content_type_name, $level) {
  $cat = new category();
  $statement = '';
  foreach ($category_a as $category_id => $category_a) {
   $cat->findBy_id($category_id);
   $statement .= "<tr class=\"level_$level\"><td class='link'>";
   $statement .= '<a href="' . HOME_URL . 'content.php?content_type=' .
    $content_type_name . '&category_id=' . $category_id . '">' . $cat->category . '</a></td>';
   $statement .= '<td>' . $cat->description . '</td>';
   $statement .= '<td>' . self::contentCount_by_categoryId_contentType($category_id) . '</td>';
   $statement .= '<td></td>';
   $statement .= '</tr>';
   if (is_array($category_a)) {
    $level_n = $level + 1;
    $statement .=$this->_get_next_level_category($category_a, $content_type_name, $level_n);
   }
  }
  return $statement;
 }

 public function show_exploded_category_bookwise($category_id, $content_type_name) {
  $all_categories = $this->category_explosion_withPCRelation($category_id);
  $statement = "<table id='forum_type_category_list' class='normal'>
	        <thead>
          <tr class='headerBgColor'>
           <th>" . gettext('Category') . "</th>
           <th>" . gettext('Starting Chapters') . "</th>
          </tr>
         </thead>
				 ";

  $cat = new category();
  $cat->findBy_id($category_id);
  $level = 1;
  $statement .= "<tr class=\"level_$level\"><td class='link'>";
  $statement .= '<a href="' . HOME_URL . 'content.php?content_type=' .
   $content_type_name . '&category_id=' . $category_id . '">' . $cat->category . '</a></td>';
  $statement .= '<td>' . $cat->description . '</td>';
  $statement .= '</tr>';

  foreach ($all_categories as $category_id => $category_a) {
   $cat->findBy_id($category_id);
   if (is_array($category_a)) {
    $level_n = $level + 1;
    $statement .=$this->_get_next_level_category($category_a, $content_type_name, $level_n);
   }
  }
  $statement .= '</table>';

  return $statement;
 }

 public static function find_by_reference_table_and_id($reference_table, $reference_id) {
  global $db;

  $sql = "SELECT category.category_id as category_id,category.priority,
              category.major_category_id as major_category_id,
               category.category as category, 
               category.parent_id as parent_id, 
               category.description as description,
               category.primary_cb as primary_cb,
               category_reference.category_reference_id as category_reference_id
       FROM 
       category , category_reference
       WHERE category_reference.reference_table = '{$reference_table}'
       AND category_reference.reference_id = '{$reference_id}'
       AND category.category_id = category_reference.category_id";

  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_category_categoryreference_table_and_id($values, $reference_table, $reference_id) {
  global $db;

  $sql = "SELECT category.category_id as category_id, 
               category.category as category, 
               category.parent_id as parent_id, 
               category.description as description,
               category.primary_cb as primary_cb,
               category_reference.category_reference_id as category_reference_id
       FROM 
       category , category_reference
       WHERE category_reference.category_id = '{$values}'
       AND category_reference.reference_table = '{$reference_table}' 
       AND category_reference.reference_id = '{$reference_id}'
       AND category.category_id = category_reference.category_id
       ";
       $sql = ino_perPageSql_i($sql, 1);

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_shift($result) : false;
 }

 public static function check_category_in_categoryReference($major_category_id, $category_id, $reference_table, $reference_id) {
  global $db;

  $sql = "SELECT category.category_id as category_id, 
               category.category as category, 
               category.parent_id as parent_id, 
               category.description as description,
               category.primary_cb as primary_cb,
               category_reference.category_reference_id as category_reference_id
       FROM 
       category , category_reference
       WHERE category_reference.category_id = '{$category_id}'
       AND category_reference.major_category_id = '{$major_category_id}'
       AND category_reference.reference_table = '{$reference_table}' 
       AND category_reference.reference_id = '{$reference_id}'
       AND category.category_id = category_reference.category_id
       ";
       $sql = ino_perPageSql_i($sql, 1);

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_shift($result) : false;
 }

 public static function find_summary_by_id($category_id) {
  $selectFields = ' SUBSTRING(content,1,2000) AS content_summary , ' .
   implode(", ", self::$field_array);
  $sql = "SELECT " . $selectFields . " FROM "
   . self::$table_name . " 
            where category_id={$category_id} ";
            $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function major_categories() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE parent_id IS NULL ";
  $sql .= " AND primary_cb = '1' ";

  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function parent_category_ofType($category_type = '') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE parent_id IS NULL ";
  $sql .= " AND primary_cb = '1' ";
  $sql .= " AND category_type = '{$category_type}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function minor_categories() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE parent_id IS NOT NULL ";
  $sql .= " AND primary_cb = '1' ";

  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_categoryId($category_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE category_id ='{$category_id}' ";
  $sql = ino_perPageSql_i($sql, 1);
//	echo "sql1 is $sql ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_shift($result) : false;
 }

 public static function is_major_category($category_id) {
  $category = self::find_by_categoryId($category_id);
//	echo "sql2 is  " .print_r($category);
  if ((!empty($category)) && empty($category->parent_id) && ($category->primary_cb == 1)) {
   return true;
  } else {
   return false;
  }
 }

 public static function is_minor_category($category_id) {
  $category = self::find_by_categoryId($category_id);
  if ((!empty($category)) && !empty($category->parent_id) && ($category->primary_cb == 1)) {
   return true;
  } else {
   return false;
  }
 }

 public static function child_of_parent($parent_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE parent_id ='{$parent_id}' ";
  $result = self::find_by_sql($sql);
  return !(empty($result)) ? $result : false;
 }

 public static function child_of_parent_woparent($parent_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE parent_id ='{$parent_id}' ";
  $sql .= " AND category_id !='{$parent_id}' ";
  $result = self::find_by_sql($sql);
  return !(empty($result)) ? $result : false;
 }

 public static function child_of_parent_woparent_array($parent_id) {
  global $db;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE parent_id ='{$parent_id}' ";
  $sql .= " AND category_id !='{$parent_id}' ";
  $result = $db->result_array_assoc($sql);
  return !(empty($result)) ? $result : false;
 }

 public static function parent_of_child($child_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE category_id='{$child_id}' ";

  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_major_category_id($category_id = "") {
  //convert to procedure
  $category_details = self::find_by_id($category_id);
  $parent_id = $category_details->parent_id;
  if (empty($parent_id)) {
   $major_category_id = $category_details->category_id;
  } else {
   $category_details2 = self::find_by_id($parent_id);
   $parent_id2 = $category_details2->parent_id;
   if (empty($parent_id2)) {
    $major_category_id = $category_details2->category_id;
   } else {
    $category_details3 = self::find_by_id($parent_id2);
    $parent_id3 = $category_details3->parent_id;
    if (empty($parent_id3)) {
     $major_category_id = $category_details3->category_id;
    } else {
     $category_details4 = self::find_by_id($parent_id3);
     $parent_id4 = $category_details4->parent_id;
     if (empty($parent_id4)) {
      $major_category_id = $category_details4->category_id;
     } else {
      $category_details5 = self::find_by_id($parent_id4);
      $parent_id5 = $category_details5->parent_id;
      if (empty($parent_id5)) {
       $major_category_id = $category_details5->category_id;
      } else {
       $category_details6 = self::find_by_id($parent_id5);
       $parent_id6 = $category_details6->parent_id;
       if (empty($parent_id6)) {
        $major_category_id = $category_details5->category_id;
       }
      }
     }
    }
   }
  }

  return $major_category_id;
 }

 public static function all_child_categories_wohirearchy_depthControl($category_id, &$array, $depth = 5) {
  $category = self::find_by_id($category_id);
  array_push($array, $category);
//find all child categories
  $child_category = self::child_of_parent_woparent($category->category_id);
  if ($depth > 0) {
   if (!empty($child_category)) {
    foreach ($child_category as $newCategory) {
     if ($newCategory->category_id) {
      $depth--;
      self::all_child_categories_wohirearchy($newCategory->category_id, $array, $depth);
     }
    }
   }
  }
  return $array;
 }

 public static function all_child_categories_wohirearchy($category_id, &$array) {
  $category = self::find_by_id($category_id);
  array_push($array, $category);
//find all child categories
  $child_category = self::child_of_parent_woparent($category->category_id);
  if (count($child_category) > 0) {
   if (!empty($child_category)) {
    foreach ($child_category as $newCategory) {
     if ($newCategory->category_id) {
      self::all_child_categories_wohirearchy($newCategory->category_id, $array);
     }
    }
   }
  }
  return $array;
 }

 //not working
 public static function all_child_categories_withHirearchy($firstCategory_id, $category_id, &$array) {
  $category = self::find_by_id_array($category_id);
  if ($firstCategory_id == $category_id) {
   $array[] = &$category;
  }
//find all child categories
  $child_category = self::child_of_parent_woparent_array($category['category_id']);

  $category['child'] = [];

  if (!empty($child_category)) {
   foreach ($child_category as $newCategory) {
    if ($newCategory['category_id']) {
     array_push($category['child'], $newCategory);
     $array = array_merge($array, $category);
     self::all_child_categories_withHirearchy($firstCategory_id, $newCategory['category_id'], $array);
    }
   }
  }
  return $array;
 }

 public static function all_child_categories($category = "") {
  $result_array = array();

  if (empty($category)) {
   $all_major_categories = self::major_categories();
  } else {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE category ='{$category}' ";
   $sql = ino_perPageSql_i($sql, 1);

   $all_major_categories = self::find_by_sql($sql);
  }

  if ($all_major_categories) {
   foreach ($all_major_categories as $recodrsl0) {
    $array_recodrsl0 = (array) $recodrsl0;
    //check if there is any child category
    $child_categories_l1 = self::child_of_parent($recodrsl0->category_id);
    if ($child_categories_l1) {
     $array_recodrsl1_final = array();
     foreach ($child_categories_l1 as $recordsl1) {
      $array_recodrsl1 = (array) $recordsl1;
      $child_categories_l2 = self::child_of_parent($recordsl1->category_id);
      if ($child_categories_l2) {
       $array_recodrsl2_final = array();
       foreach ($child_categories_l2 as $recordsl2) {
        $array_recodrsl2 = (array) $recordsl2;
        $child_categories_l3 = self::child_of_parent($recordsl2->category_id);
        if ($child_categories_l3) {
         $array_recodrsl3_final = array();
         foreach ($child_categories_l3 as $recordsl3) {
          $array_recodrsl3 = (array) $recordsl3;
          $array_recodrsl3_final[] = $array_recodrsl3;
         }
         $array_recodrsl2 = &$array_recodrsl2;
         $array_recodrsl2["child"] = $array_recodrsl3_final;
        }
        $array_recodrsl2_final[] = $array_recodrsl2;
       }
       $array_recodrsl1 = &$array_recodrsl1;
       $array_recodrsl1["child"] = $array_recodrsl2_final;
      }
      $array_recodrsl1_final[] = $array_recodrsl1;
     }
     $array_recodrsl0 = &$array_recodrsl0;
     $array_recodrsl0["child"] = $array_recodrsl1_final;
    }
    $result_array = &$result_array;
    array_push($result_array, $array_recodrsl0);
   }
  }
  return $result_array;
 }

 public static function all_child_category_select_options($category = "") {
  $all_categories = self::all_child_categories($category);

//  var_dump($all_categories);
  $select_statement = "";

  foreach ($all_categories as $major_category) {
   $select_statement .= '<option class="one_tab" value="' . $major_category['category_id'] . '">' . $major_category['category'] . '</option>';
   if (!empty($major_category['child'])) {
    foreach ($major_category['child'] as $child1) {
     $select_statement .= '<option class="two_tab" value="' . $child1['category_id'] . '">-' . $child1['category'] . '</option>';
     if (!empty($child1['child'])) {
      foreach ($child1['child'] as $child2) {
       $select_statement .= '<option class="three_tab" value="' . $child2['category_id'] . '">--' . $child2['category'] . '</option>';
       if (!empty($child2['child'])) {
        foreach ($child2['child'] as $child3) {
         $select_statement .= '<option class="four_tab" value="' . $child3['category_id'] . '">---' . $child3['category'] . '</option>';
        }
       }
      }
     }
    }
   }
  }

  return $select_statement;
 }

 public static function print_category_relations_content($all_categories_object, $content_type_name) {
  $statement = "<table id='category_list' class='normal'>
	        <thead>
          <tr>
           <th>" . gettext('Category') . "</th>
           <th>" . gettext('Description') . "</th>
           <th>" . gettext('Posts') . "</th>
	   <th>" . gettext('Last Post') . "</th>
          </tr>
         </thead>
				 ";
  foreach ($all_categories_object as $major_category) {
   $statement .= '<tr class="first"><td class="first"><a href="' . HOME_URL . 'content.php?content_type=' .
    $content_type_name . '&category_id=' . $major_category['category_id'] . '">' . $major_category['category'] . '</a></td>
            <td>' . $major_category['description'] . '</td>
             <td>' . self::contentCount_by_categoryId_contentType($major_category['category_id']) . '</td><td></td></tr>';
   if (!empty($major_category['child'])) {

    foreach ($major_category['child'] as $child1) {
     $statement .= '<tr class="second"><td class="second"><a href="' . HOME_URL . 'content.php?content_type=' .
      $content_type_name . '&category_id=' . $child1['category_id'] . '">' . $child1['category'] . '</td>
              <td>' . $child1['description'] . '</td>
                 <td>' . self::contentCount_by_categoryId_contentType($child1['category_id']) . '</td><td></td></tr>';
     if (!empty($child1['child'])) {
      foreach ($child1['child'] as $child2) {
       $statement .= '<tr class="third"><td class="third"><a href="' . HOME_URL . 'content.php?content_type=' .
        $content_type_name . '&category_id=' . $child2['category_id'] . '">' . $child2['category'] . '</td>
                <td>' . $child2['description'] . '</td>
                <td></td>' . self::contentCount_by_categoryId_contentType($child2['category_id']) . '<td></td></tr>';
       if (!empty($child2['child'])) {
        foreach ($child2['child'] as $child3) {
         $statement .= '<tr class="four"><td class="four"><a href="' . HOME_URL . 'content.php?content_type=' .
          $content_type_name . '&category_id=' . $child3['category_id'] . '">' . $child3['category'] . '</td>
                <td>' . $child3['description'] . '</td>
                               <td>' . self::contentCount_by_categoryId_contentType($child3['category_id']) . '</td><td></td></tr>';
        }
       }
      }
     }
    }
   }
  }
  $statement .= "</table>";
  return $statement;
 }

 public static function contentCountAll_by_categoryId_contentType($category_id, $content_type = 'content') {
  $count = 0;
  $a = [];
  $all_child_categoris = self::all_child_categories_wohirearchy($category_id, $a);
  foreach ($all_child_categoris as $category) {
   $category_id = $category->category_id;
   $sql = " SELECT COUNT(category_reference_id) FROM category_reference ";
   $sql .= " WHERE category_id = '{$category_id}'  ";
   $sql .= " AND reference_table = '{$content_type}'  ";

   $result = self::count_all_by_sql($sql);
   $count = $result;
  }
  return $count;
 }

 public static function contentCount_by_categoryId_contentType($category_id, $content_type = 'content') {
  $sql = " SELECT COUNT(category_reference_id) as count_t FROM category_reference ";
  $sql .= " WHERE category_id = '{$category_id}'  ";
  $sql .= " AND reference_table = '{$content_type}'  ";
  $sql .= " UNION SELECT COUNT(cr.category_reference_id) as count_t FROM category_reference cr, category cat ";
  $sql .= " WHERE cat.parent_id = '{$category_id}'  ";
  $sql .= " AND cr.reference_table = '{$content_type}'  ";
  $sql .= " AND cr.category_id = cat.category_id  ";
  $sql .= " UNION SELECT COUNT(cr.category_reference_id) as count_t FROM category_reference cr ";
  $sql .= " WHERE cr.major_category_id = '{$category_id}'  ";
  $sql .= " AND cr.reference_table = '{$content_type}'  ";

  $result = self::find_by_sql($sql);
  $count_v = 0;
  if (!empty($result)) {
   foreach ($result as $r) {
    $count_v += $r->count_t;
   }
  }
  return $count_v;
 }

 public static function breadCrum_by_category_contentType($category_id, $content_type) {
  $bcElements = [];
  $category = self::find_by_id($category_id);
//	$parent_of_category = self::parent_of_child($category->parent_id);
  if (self::is_major_category($category->category_id)) {
   $linkFor_parent = '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type .
    '&amp;category_id=' . $category->category_id . '">' . $category->category . '</a>';
   array_push($bcElements, $linkFor_parent);
  } else {
   $linkFor_parent = '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type .
    '&amp;category_id=' . $category->category_id . '">' . $category->category . '</a>';
   array_push($bcElements, $linkFor_parent);
   $category1 = self::find_by_id($category->parent_id);
   if (self::is_major_category($category1->category_id)) {
    $linkFor_parent1 = '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type .
     '&amp;category_id=' . $category1->category_id . '">' . $category1->category . '</a>';
    array_push($bcElements, $linkFor_parent1);
   } else {
    $linkFor_parent1 = '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type .
     '&amp;category_id=' . $category1->category_id . '">' . $category1->category . '</a>';
    array_push($bcElements, $linkFor_parent1);
    $category2 = self::find_by_id($category1->parent_id);
    if (self::is_major_category($category2->category_id)) {
     $linkFor_parent2 = '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type .
      '&amp;category_id=' . $category2->category_id . '">' . $category2->category . '</a>';
     array_push($bcElements, $linkFor_parent2);
    } else {
     $linkFor_parent2 = '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type .
      '&amp;category_id=' . $category2->category_id . '">' . $category2->category . '</a>';
     array_push($bcElements, $linkFor_parent2);
     $category3 = self::find_by_id($category2->parent_id);
     if (self::is_major_category($category3->category_id)) {
      $linkFor_parent3 = '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type .
       '&amp;category_id=' . $category3->category_id . '">' . $category3->category . '</a>';
      array_push($bcElements, $linkFor_parent3);
     } else {
      $linkFor_parent3 = '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type .
       '&amp;category_id=' . $category3->category_id . '">' . $category3->category . '</a>';
      array_push($bcElements, $linkFor_parent3);
      $category4 = self::find_by_id($category3->parent_id);
      if (self::is_major_category($category4->category_id)) {
       $linkFor_parent4 = '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type .
        '&amp;category_id=' . $category4->category_id . '">' . $category4->category . '</a>';
       array_push($bcElements, $linkFor_parent4);
      }
     }
    }
   }
  }
//end of category class
  $bc_statement = '';
  foreach ($bcElements as $key => $value) {
   $bc_statement = '>>' . $value . $bc_statement;
  }
  $bc_statement = '<a class="home_link non_ajax" href="' . HOME_URL . '">' . gettext('Home') . '</a>' . $bc_statement;
  return $bc_statement;
 }

 public static function breadCrum_by_category($category_id, &$element_a = '', $content_type = '') {
  if (empty($category_id)) {
   $bc_statement = '<ol class="ino-breadcrumb"><li><a class="home_link non_ajax" href="' . HOME_URL . '">' . gettext('Home') . '</a></li></ol>';
   return $bc_statement;
  }

  if (empty($element_a)) {
   $element_a = [];
  }
  $category = self::find_by_id($category_id);
//	$parent_of_category = self::parent_of_child($category->parent_id);
  if (self::is_major_category($category->category_id)) {
   if (!empty($content_type)) {
    $linkFor_parent = '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type .
     '&amp;category_id=' . $category->category_id . '">' . $category->category . '</a>';
   } else {
    $linkFor_parent = '<a href="' . HOME_URL . 'product.php?category_id=' . $category->category_id . '">' . $category->category . '</a>';
   }
   array_push($element_a, $linkFor_parent);
   //end of category class
   $element_a_r = array_reverse($element_a);
   $bc_statement = '<ol class="ino-breadcrumb"><li><a href="' . HOME_URL . '">' . gettext('Home') . '</a></li>';
   foreach ($element_a_r as $key => $value) {
    $bc_statement .= '<li>' . $value . '</li>';
   }
   $bc_statement .= '</ol>';
   echo $bc_statement;
  } else {
   if (!empty($content_type)) {
    $linkFor_parent = '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type .
     '&amp;category_id=' . $category->category_id . '">' . $category->category . '</a>';
   } else {
    $linkFor_parent = '<a class="ino-bradcrum-link" href="' . HOME_URL . 'product.php?category_id=' . $category->category_id . '">' . $category->category . '</a>';
   }
   array_push($element_a, $linkFor_parent);
   $category1 = self::find_by_id($category->parent_id);
   self::breadCrum_by_category($category1->category_id, $element_a, $content_type);
  }
 }

 public static function category_stmt($category) {
  $stmt = '<ul class="category-stmt">';
  foreach ($category as $cat) {
   $stmt .= '<li class="inline"><button type="button" class="btn btn-default delete-category"  title="' . $cat->description . '" '
    . ' data-category_reference_id="' . $cat->category_reference_id . '" >';
   $stmt .= '<i class="fa fa-remove"></i> &nbsp;&nbsp;';
   $stmt .= $cat->category;
   $stmt .='</button></li>';
  }
  $stmt .= '</ul>';
  return $stmt;
 }

}

?>
