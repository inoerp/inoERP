<?php

class category extends dbObject {

 protected static $table_name = "category";
//  data base variables as stored database column name
 public static $field_array = [
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

 public static $checkbox_array = [
		 "primary_cb"
 ];
 public static $column_array = [
		 "major_category_id",
		 "category_id",
		 "parent_id",
		 "category",
		 "description",
		 "primary_cb"
 ];
 public static $requiredField_array = ["category"
 ];
 public static $primary_column = "category";
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
//
//  public static function find_by_sql($sql = "") {
//    global $db;
//    $result_set = $db->query($sql);
//    $object_array = array();
//    while ($row = $db->fetch_array($result_set)) {
//      $object_array[] = self::instantiate($row);
//    }//end of while Loop
//    return $object_array;
//  }
//
//  public static function find_all() {
//    $sql = " SELECT * FROM " . self::$table_name;
//    $result = self::find_by_sql($sql);
//    return $result;
//  }
//
//  public static function count_all() {
//    global $db;
//    $sql = "SELECT COUNT(*) FROM " . self::$table_name;
//    $result_set = $db->query($sql);
//    $row = $db->fetch_array($result_set);
//    return array_shift($row);
//  }
//
//  public static function count_all_by_sql($sql) {
//    global $db;
//    $result_set = $db->query($sql);
//    $row = $db->fetch_array($result_set);
//    return array_shift($row);
//  }
//
//  public static function find_by_id($category_id) {
//    $sql = "SELECT * FROM " . self::$table_name . " where category_id={$category_id} LIMIT 1";
//    $result_array = self::find_by_sql($sql);
//    return !empty($result_array) ? array_shift($result_array) : false;
//  }

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
       AND category.category_id = category_reference.category_id ";

//			 echo "sql is $sql";
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

//  private static function instantiate($record) {
//    $object = new self;
//    foreach ($record as $attribute => $value) {
//      if ($object->has_attribute($attribute)) {
//        $object->$attribute = $value;
//      }
//    }
//    return $object;
//  }
//
//  Private function has_attribute($attribute) {
//    $object_vars = get_object_vars($this);
//    return array_key_exists($attribute, $object_vars);
//  }
//
//  public static function install() {
//    global $db;
//    $sql = "
//		 ";
//    $result = $db->query($sql);
//    return !empty($result) ? $result : false;
//  }
//
//  public function save() {
//    if (empty($this->category_id)) {
//      $this->create();
//    } else {
//      $this->update($this->category_id);
//    }
//    return $this->msg;
//  }
//
//  public function create() {
//    global $db;
//    $field_arry_colums = array();
//    $field_arry_values = array();
//    foreach (self::$field_array as $key => $value) {
//      $field_arry_colums[] = sprintf("`%s`", $value);
//    }
//    $field_colums = implode(',', $field_arry_colums);
//
//    foreach (self::$field_array as $key => $value) {
//      if (!empty($this->$value)) {
//        $field_arry_values[] = sprintf("'%s'", $this->$value);
//      } else {
//        $field_arry_values[] = 'NULL';
//      }
//    }
//    $field_values = implode(',', $field_arry_values);
//
//    $sql = " INSERT INTO ";
//    $sql.= self::$table_name;
//    $sql.= ' ( ';
//    $sql.= $field_colums;
//    $sql.= ' ) ';
//    $sql.= 'VALUES';
//    $sql.= ' ( ';
//    $sql.= $field_values;
//    $sql.= ' ) ';
//
//
//    if ($db->query($sql)) {
//      $this->category_id = $db->insert_id();
//      $this->msg = 1;
//    } else {
//      $this->msg = 0;
//    }
//    return $this->msg;
//  }
//
//  public function update($category_id) {
//    global $db;
//    $field_arry_values = array();
//
//    foreach (self::$field_array as $key => $value) {
//      if (isset($this->$value)) {
//        $field_arry_values[] = sprintf("`%s` = '%s'", $value, $this->$value);
//      }
//    }
//    $field_values = implode(',', $field_arry_values);
//
//    $time = time();
//    $last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
//    $last_update_by = $_SESSION['user_name'];
//
//    $sql = " UPDATE ";
//    $sql.= self::$table_name;
//    $sql .= " SET ";
//    $sql.= $field_values;
////    $sql.= "`last_update_date` = '{$last_update_date}'," ;
////    $sql.= "`last_update_by` = '{$last_update_by }'" ;
//    $sql.= " WHERE `category_id` = '{$category_id}' ";
//
////    echo "<br/>$sql is <br/>" . $sql;
//
//    if ($db->query($sql)) {
//      $this->msg = 1;
//    } else {
//      $this->msg = 0;
//    }
//    return $this->msg;
//  }

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
	return $result;
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

 public static function breadCrum_by_category_contentType($category_id, $content_type) {
	$bc_statement = '<a href="' . HOME_URL . '">Home</a>';
	$category = self::parent_of_child($category_id);
	$parent_of_category = self::parent_of_child($category->parent_id);
	if (self::is_major_category($parent_of_category->parent_id)) {
	 $linkFor_parent = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
					 '&category_id=' . $parent_of_category->category_id . '">' . $parent_of_category->category . '</a>';
	 $bc_statement .= ">>$linkFor_parent";
	} else {
	 $linkFor_parent = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
					 '&category_id=' . $parent_of_category->category_id . '">' . $parent_of_category->category . '</a>';
	 $bc_statement .= ">>$linkFor_parent";
	 $category1 = self::parent_of_child($parent_of_category->category_id);
	 $parent1_of_category = self::parent_of_child($category1->parent_id);
	 if (self::is_major_category($parent1_of_category->parent_id)) {
		$linkFor_parent1 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
						'&category_id=' . $parent1_of_category->category_id . '">' . $parent1_of_category->category . '</a>';
		$bc_statement .= ">>$linkFor_parent1";
	 } else {
		$linkFor_parent1 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
						'&category_id=' . $parent1_of_category->category_id . '">' . $parent1_of_category->category . '</a>';
		$bc_statement .= ">>$linkFor_parent1";
		$category2 = self::parent_of_child($parent1_of_category->category_id);
		$parent2_of_category = self::parent_of_child($parent1_of_category->parent_id);
		if (self::is_major_category($parent2_of_category->parent_id)) {
		 $linkFor_parent2 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
						 '&category_id=' . $parent2_of_category->category_id . '">' . $parent2_of_category->category . '</a>';
		 $bc_statement .= ">>$linkFor_parent2";
		} else {
		 $linkFor_parent2 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
						 '&category_id=' . $parent2_of_category->parent_id . '">' . $parent2_of_category->parent_id . '</a>';
		 $bc_statement .= ">>$linkFor_parent2";
		 $parent3_of_category = self::parent_of_child($parent2_of_category->category_id);
		 if (self::is_major_category($parent3_of_category->parent_id)) {
			$linkFor_parent3 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
							'&category_id=' . $parent3_of_category->parent_id . '">' . $parent3_of_category->parent_id . '</a>';
			$bc_statement .= ">>$linkFor_parent3";
		 } else {
			$linkFor_parent3 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
							'&category_id=' . $parent3_of_category->parent_id . '">' . $parent3_of_category->parent_id . '</a>';
			$bc_statement .= ">>$linkFor_parent3";
			$parent4_of_category = self::parent_of_child($parent3_of_category->category_id);
			if (self::is_major_category($parent4_of_category->parent_id)) {
			 $linkFor_parent4 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
							 '&category_id=' . $parent4_of_category->parent_id . '">' . $parent4_of_category->parent_id . '</a>';
			 $bc_statement .= ">>$linkFor_parent4";
			} else {
			 $linkFor_parent4 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
							 '&category_id=' . $parent4_of_category->parent_id . '">' . $parent4_of_category->parent_id . '</a>';
			 $bc_statement .= ">>$linkFor_parent4";
			 $parent5_of_category = self::parent_of_child($parent4_of_category->category_id);
			 if (self::is_major_category($parent5_of_category->parent_id)) {
				$linkFor_parent5 = '<a href="' . HOME_URL . 'extensions/content/contents.php?content_type=' . $content_type .
								'&category_id=' . $parent5_of_category->parent_id . '">' . $parent5_of_category->parent_id . '</a>';
				$bc_statement .= ">>$linkFor_parent5";
			 }
			}
		 }
		}
	 }
	}
	return $bc_statement;
 }

}

//end of category class
?>



