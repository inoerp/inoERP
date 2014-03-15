<?php

class category extends dbObject {

 protected static $table_name = "category";
 public static $primary_column = "category_id";
 public static $key_column = "category";
 public static $module = "extension";
//  data base variables as stored database column name
 public $field_a = [
		 "category_id",
		 "major_category_id",
		 "parent_id",
		 "category",
		 "description",
		 "primary_cb",
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
 public $column = [
		 "major_category_id",
		 "category_id",
		 "parent_id",
		 "category",
		 "description",
		 "primary_cb"
 ];
 public $requiredField = ["category"
 ];
 public $category_reference_id;
 public $category_id;
 public $major_category_id;
 public $parent_id;
 public $category;
 public $description;
 public $primary_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function __set($name, $value) {
	$this->$name = $value;
 }


 public static function find_by_reference_table_and_id($reference_table, $reference_id) {
	global $db;

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
       LIMIT 1";

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
       LIMIT 1";

	$result = self::find_by_sql($sql);
	return !empty($result) ? array_shift($result) : false;
 }

 public static function find_summary_by_id($category_id) {
	$selectFields = ' SUBSTRING(content,1,2000) AS content_summary , ' .
					implode(", ", self::$field_array);
	$sql = "SELECT " . $selectFields . " FROM "
					. self::$table_name . " 
            where category_id={$category_id} LIMIT 1";
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
	$sql .= " LIMIT 1 ";
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
	 $sql .= " LIMIT 0,1 ";

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
           <th>Category</th>
           <th>Description</th>
           <th>Posts</th>
					 <th>Last Post</th>
          </tr>
         </thead>
				 ";
	foreach ($all_categories_object as $major_category) {
	 $statement .= '<tr class="first"><td class="first"><a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' .
					 $content_type_name . '&category_id=' . $major_category['category_id'] . '">' . $major_category['category'] . '</a></td>
            <td>' . $major_category['description'] . '</td>
             <td>' . self::contentCount_by_categoryId_contentType($major_category['category_id']) . '</td><td></td></tr>';
	 if (!empty($major_category['child'])) {

		foreach ($major_category['child'] as $child1) {
		 $statement .= '<tr class="second"><td class="second"><a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' .
						 $content_type_name . '&category_id=' . $child1['category_id'] . '">' . $child1['category'] . '</td>
              <td>' . $child1['description'] . '</td>
                 <td>' . self::contentCount_by_categoryId_contentType($child1['category_id']) . '</td><td></td></tr>';
		 if (!empty($child1['child'])) {
			foreach ($child1['child'] as $child2) {
			 $statement .= '<tr class="third"><td class="third"><a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' .
							 $content_type_name . '&category_id=' . $child2['category_id'] . '">' . $child2['category'] . '</td>
                <td>' . $child2['description'] . '</td>
                <td></td>' . self::contentCount_by_categoryId_contentType($child2['category_id']) . '<td></td></tr>';
			 if (!empty($child2['child'])) {
				foreach ($child2['child'] as $child3) {
				 $statement .= '<tr class="four"><td class="four"><a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' .
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
	 $count += $result;
	}
	return $count;
 }

 public static function contentCount_by_categoryId_contentType($category_id, $content_type = 'content') {
	$count = 0;
	$sql = " SELECT COUNT(category_reference_id) FROM category_reference ";
	$sql .= " WHERE category_id = '{$category_id}'  ";
	$sql .= " AND reference_table = '{$content_type}'  ";
	$result = self::count_all_by_sql($sql);
	$count += $result;

	return $count;
 }

 public static function breadCrum_by_category_contentType($category_id, $content_type) {
	$bcElements = [];
	$category = self::find_by_id($category_id);
//	$parent_of_category = self::parent_of_child($category->parent_id);
	if (self::is_major_category($category->category_id)) {
	 $linkFor_parent = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
					 '&category_id=' . $category->category_id . '">' . $category->category . '</a>';
	 array_push($bcElements, $linkFor_parent);
	} else {
	 $linkFor_parent = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
					 '&category_id=' . $category->category_id . '">' . $category->category . '</a>';
	 array_push($bcElements, $linkFor_parent);
	 $category1 = self::find_by_id($category->parent_id);
	 if (self::is_major_category($category1->category_id)) {
		$linkFor_parent1 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
						'&category_id=' . $category1->category_id . '">' . $category1->category . '</a>';
		array_push($bcElements, $linkFor_parent1);
	 } else {
		$linkFor_parent1 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
						'&category_id=' . $category1->category_id . '">' . $category1->category . '</a>';
		array_push($bcElements, $linkFor_parent1);
		$category2 = self::find_by_id($category1->parent_id);
		if (self::is_major_category($category2->category_id)) {
		 $linkFor_parent2 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
						 '&category_id=' . $category2->category_id . '">' . $category2->category . '</a>';
		 array_push($bcElements, $linkFor_parent2);
		} else {
		 $linkFor_parent2 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
						 '&category_id=' . $category2->category_id . '">' . $category2->category . '</a>';
		 array_push($bcElements, $linkFor_parent2);
		 $category3 = self::find_by_id($category2->parent_id);
		 if (self::is_major_category($category3->category_id)) {
			$linkFor_parent3 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
							'&category_id=' . $category3->category_id . '">' . $category3->category . '</a>';
			array_push($bcElements, $linkFor_parent3);
		 } else {
			$linkFor_parent3 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
							'&category_id=' . $category3->category_id . '">' . $category3->category . '</a>';
			array_push($bcElements, $linkFor_parent3);
			$category4 = self::find_by_id($category3->parent_id);
			if (self::is_major_category($category4->category_id)) {
			 $linkFor_parent4 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
							 '&category_id=' . $category4->category_id . '">' . $category4->category . '</a>';
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
	$bc_statement = '<a href="' . HOME_URL . '">Home</a>' . $bc_statement;
	return $bc_statement;
 }

}
?>



