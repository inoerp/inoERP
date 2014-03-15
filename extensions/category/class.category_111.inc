<?php

class category {

 protected static $table_name = "category";
//  data base variables as stored database column name
 public static $field_array = [
     "category_id",
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

 public static function find_by_sql($sql = "") {
  global $db;
  $result_set = $db->query($sql);
  $object_array = array();
  while ($row = $db->fetch_array($result_set)) {
   $object_array[] = self::instantiate($row);
  }//end of while Loop
  return $object_array;
 }

 public static function find_all() {
  $sql = " SELECT * FROM " . self::$table_name;
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function count_all() {
  global $db;
  $sql = "SELECT COUNT(*) FROM " . self::$table_name;
  $result_set = $db->query($sql);
  $row = $db->fetch_array($result_set);
  return array_shift($row);
 }

 public static function count_all_by_sql($sql) {
  global $db;
  $result_set = $db->query($sql);
  $row = $db->fetch_array($result_set);
  return array_shift($row);
 }

 public static function find_by_id($category_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where category_id={$category_id} LIMIT 1";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_reference_table_and_id($reference_table, $reference_id) {
  global $db;

  $sql = "SELECT category.category_id as category_id, 
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

 public static function find_summary_by_id($category_id) {
  $selectFields = ' SUBSTRING(content,1,2000) AS content_summary , ' .
          implode(", ", self::$field_array);
  $sql = "SELECT " . $selectFields . " FROM "
          . self::$table_name . " 
            where category_id={$category_id} LIMIT 1";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 private static function instantiate($record) {
  $object = new self;
  foreach ($record as $attribute => $value) {
   if ($object->has_attribute($attribute)) {
    $object->$attribute = $value;
   }
  }
  return $object;
 }

 Private function has_attribute($attribute) {
  $object_vars = get_object_vars($this);
  return array_key_exists($attribute, $object_vars);
 }

 public static function install() {
  global $db;
  $sql = "
		 ";
  $result = $db->query($sql);
  return !empty($result) ? $result : false;
 }

 public function save() {
  if (empty($this->category_id)) {
   $this->create();
  } else {
   $this->update($this->category_id);
  }
  return $this->msg;
 }

 public function create() {
  global $db;
  $field_arry_colums = array();
  $field_arry_values = array();
  foreach (self::$field_array as $key => $value) {
   $field_arry_colums[] = sprintf("`%s`", $value);
  }
  $field_colums = implode(',', $field_arry_colums);

  foreach (self::$field_array as $key => $value) {
   if (!empty($this->$value)) {
    $field_arry_values[] = sprintf("'%s'", $this->$value);
   } else {
    $field_arry_values[] = 'NULL';
   }
  }
  $field_values = implode(',', $field_arry_values);

  $sql = " INSERT INTO ";
  $sql.= self::$table_name;
  $sql.= ' ( ';
  $sql.= $field_colums;
  $sql.= ' ) ';
  $sql.= 'VALUES';
  $sql.= ' ( ';
  $sql.= $field_values;
  $sql.= ' ) ';


  if ($db->query($sql)) {
   $this->category_id = $db->insert_id();
   $this->msg = 1;
  } else {
   $this->msg = 0;
  }
  return $this->msg;
 }

 public function update($category_id) {
  global $db;
  $field_arry_values = array();

  foreach (self::$field_array as $key => $value) {
   if (isset($this->$value)) {
    $field_arry_values[] = sprintf("`%s` = '%s'", $value, $this->$value);
   }
  }
  $field_values = implode(',', $field_arry_values);

  $time = time();
  $last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
  $last_update_by = $_SESSION['user_name'];

  $sql = " UPDATE ";
  $sql.= self::$table_name;
  $sql .= " SET ";
  $sql.= $field_values;
//    $sql.= "`last_update_date` = '{$last_update_date}'," ;
//    $sql.= "`last_update_by` = '{$last_update_by }'" ;
  $sql.= " WHERE `category_id` = '{$category_id}' ";

//    echo "<br/>$sql is <br/>" . $sql;

  if ($db->query($sql)) {
   $this->msg = 1;
  } else {
   $this->msg = 0;
  }
  return $this->msg;
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

 public static function child_of_parent($parent_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE parent_id ='{$parent_id}' ";

  $result = self::find_by_sql($sql);
  return $result;
 }

// public static function child_categories($category) {
//  $sql = " SELECT * FROM ";
//  $sql .= self::$table_name;
//  $sql .= " WHERE category ='{$category}' ";
//  $sql .= " LIMIT 0,1 ";
//
//  $result = self::find_by_sql($sql);
//
//  if ($result) {
//   foreach ($result as $recodrsl0) {
//    $array_recodrsl0 = (array) $recodrsl0;
//    //check if there is any child category
//    $child_categories_l1 = self::child_of_parent($result[0]->category_id);
//    if ($child_categories_l1) {
//     foreach ($child_categories_l1 as $recordsl1) {
//      $array_recodrsl1 = (array) $recordsl1;
//      $child_categories_l2 = self::child_of_parent($recordsl1->category_id);
//      if ($child_categories_l2) {
//       foreach ($child_categories_l2 as $recordsl2) {
//        $array_recodrsl2 = (array) $recordsl2;
//        $child_categories_l3 = self::child_of_parent($recordsl2->category_id);
//        if ($child_categories_l3) {
//         foreach ($child_categories_l3 as $recordsl3) {
//          $array_recodrsl3 = (array) $recordsl3;
//          $array_recodrsl2 = &$array_recodrsl2;
//          array_push($array_recodrsl2, $array_recodrsl3);
//         }
//        }
//         $array_recodrsl1 = &$array_recodrsl1;
//         array_push($array_recodrsl1, $array_recodrsl2);
//        }
//       }
//       $array_recodrsl0 = &$array_recodrsl0;
//       array_push($array_recodrsl0, $array_recodrsl1);
//      }
//     }
//    }
//   }
//
//
//   return $array_recodrsl0;
//  
// }

 public static function all_child_categories_old($category = "") {
  $result_array = array();

  if ($category == "") {
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
     foreach ($child_categories_l1 as $recordsl1) {
      $array_recodrsl1 = (array) $recordsl1;
      $child_categories_l2 = self::child_of_parent($recordsl1->category_id);
      if ($child_categories_l2) {
       foreach ($child_categories_l2 as $recordsl2) {
        $array_recodrsl2 = (array) $recordsl2;
        $child_categories_l3 = self::child_of_parent($recordsl2->category_id);
        if ($child_categories_l3) {
         foreach ($child_categories_l3 as $recordsl3) {
          $array_recodrsl3 = (array) $recordsl3;
          $array_recodrsl2 = &$array_recodrsl2;
          array_push($array_recodrsl2, $array_recodrsl3);
         }
        }
        $array_recodrsl1 = &$array_recodrsl1;
        array_push($array_recodrsl1, $array_recodrsl2);
       }
      }
      $array_recodrsl0 = &$array_recodrsl0;
      array_push($array_recodrsl0, $array_recodrsl1);
     }
    }
    $result_array = &$result_array;
    array_push($result_array, $array_recodrsl0);
   }
  }


  return $result_array;
 }

 public static function all_child_categories($category = "") {
  $result_array = array();

  if ($category == "") {
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
//      $child_categories_l2 = self::child_of_parent($recordsl1->category_id);
//      if ($child_categories_l2) {
//       foreach ($child_categories_l2 as $recordsl2) {
//        $array_recodrsl2 = (array) $recordsl2;
//        $child_categories_l3 = self::child_of_parent($recordsl2->category_id);
//        if ($child_categories_l3) {
//         foreach ($child_categories_l3 as $recordsl3) {
//          $array_recodrsl3 = (array) $recordsl3;
//          array_merge_recursive($array_recodrsl3, $array_recodrsl3);
//         }
//         $array_recodrsl2 = &$array_recodrsl2;
//         $array_recodrsl2["child"] = $array_recodrsl3;
//        }
//        array_merge_recursive($array_recodrsl2, $array_recodrsl2);
//        array_push($array_recodrsl2, $array_recodrsl2);
//       }
//       $array_recodrsl1 = &$array_recodrsl1;
//       $array_recodrsl1["child"] = $array_recodrsl2;
//      }
      $array_recodrsl1_final[]=$array_recodrsl1;
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

// public static function category_summary_list($category_no, $per_category, $query_string) {
//  $category_string = " ";
//  $sql = " SELECT * FROM " . self::$table_name;
//  if (!empty($per_category)) {
//   $category_string .= '<div id="noOfcategorys">';
//   $category_string .= '<form action="" method="GET">';
//   $category_string .= 'Show<select name="per_category">';
//   $category_string .= '<option value="3"> 3 </option>';
//   $category_string .= '<option value="5"> 5 </option>';
//   $category_string .= '<option value="10"> 10 </option>';
//   $category_string .= '<option value="20"> 20 </option>';
//   $category_string .= '<option value="50"> 50 </option>';
//   $category_string .= '</select>';
////   $category_string .= '<input type="hidden" value="' . $extension_id . '" name="category_id">';
//   $category_string .= '<input type="submit" class="button" value="Per Page" >';
//   $category_string .= '</form>';
//   $category_string .= '</div>';
//   $total_count = self::count_all();
//   $pagination = new pagination($category_no, $per_category, $total_count);
//   $sql .=" LIMIT {$per_category} ";
//   $sql .=" OFFSET {$pagination->offset()}";
//  }
//  $result = self::find_by_sql($sql);
//
//  if (count($result) > 0) {
//   foreach ($result as $records) {
//    $category_summary = self::find_summary_by_id($records->category_id);
//    $category_string .= '<div class="category_summary">';
//    $category_string .= '<div class="subject_summary">';
//    $category_string .= $category_summary->subject;
//    $category_string .= '</div>';
//    $category_string .= '<div class="content_summary">';
//    $category_string .= ino_eval($category_summary->content_summary);
//    $category_string .= '</div>';
//    $category_string .= '<div class="more_category">';
//    $category_string .= '<a href="categorys.php?category_id=' . $category_summary->category_id . '">';
//    $category_string .= 'Read more.. </a>';
//    $category_string .= '</div>';
//    $category_string .= '</div>';
//   }
//  }
//
//  $category_string .= '<div id="pagination" style="clear: both;">';
//  if (isset($pagination) && $pagination->total_categorys() > 1) {
//   if ($pagination->has_previous_category()) {
//    $category_string .= "<a href=\"categorys.php?categoryno=";
//    $category_string .= $pagination->previous_category() . '&' . $query_string;
//    $category_string .= "> &laquo; Previous </a> ";
//   }
//
//   for ($i = 1; $i <= $pagination->total_categorys(); $i++) {
//    if ($i == $category_no) {
//     $category_string .= " <span class=\"selected\">{$i}</span> ";
//    } else {
//     $category_string .= " <a href=\"categorys.php?categoryno={$i}&" . remove_querystring_var($query_string, 'categoryno');
//     $category_string .= '">' . $i . '</a>';
//    }
//   }
//
//   if ($pagination->has_next_category()) {
//    $category_string .= " <a href=\"categorys.php?categoryno=";
//    $category_string .= $pagination->next_category() . '&' . remove_querystring_var($query_string, 'categoryno');
//    $category_string .= "\">Next &raquo;</a> ";
//   }
//  }
//  $category_string .= '</div>';
//
//  return $category_string;
// }
//
// public static function category_summary_by_id($category_id) {
//  $category_summary = self::find_summary_by_id($category_id);
//  echo '<div class="category_summary">';
//  echo '<div class="subject_summary">';
//  echo $category_summary->subject;
//  echo '</div>';
//  echo '<div class="content_summary">';
//  echo $category_summary->content_summary;
//  echo '</div>';
//  echo '<div class="more_category">';
//  echo '<a href="categorys.php?category_id="' . $category_summary->category_id . '>';
//  echo 'Read more.. </a>';
//  echo '</div>';
//  echo '</div>';
// }
//
// public static function category_page() {
//  echo '<table class="normal"><thead><tr>';
//  foreach (self::$field_array as $key => $value) {
//   echo '<th>' . $value . '</th>';
//  }
//  echo '</tr></thead><tbody>';
//
//  $category = self::find_all();
////    echo '<pre>';
////    print_r($category);
////    echo '<pre>';
//  foreach ($category as $record) {
//   echo '<tr>';
//   foreach (self::$field_array as $key => $value) {
//    echo '<td>' . $record->$value . '</td>';
//   }
//   echo '</tr>';
//  }
//  echo ' </tbody> </table>';
// }
//
// public static function category_allcategorys_block() {
//  global $db;
//  $allCategorys = "";
//
//  $allCategorys .= '<div class="category_block">';
//  //beging of ul1
//  $allCategorys .= '<ul class="block_category_block">';
//  $sql = "SELECT * FROM `category` WHERE parent_id='0' ";
//  if ($sql) {
//   $object = self::find_by_sql($sql);
//   foreach ($object as $category) {
//    $url = self::full_category($category->value);
//    //begin of Li1
//    $allCategorys .= '<li class="parent_category_block expandable">' . '<a href="' . $url . '">' . $category->name . '</a>';
//    //next level category values
//    $child_sql = "SELECT * FROM `category` WHERE `parent_id` = '{$category->category_id}' ";
//    $child_object = self::find_by_sql($child_sql);
//    //beging of ul2
//    $allCategorys .= '<ul class="child_category_block">';
//    if (COUNT($child_object) > 0) {
//     foreach ($child_object as $child_category) {
//      $child_url = self::full_category($child_category->value);
//      //begin of Li2
//      $allCategorys .= '<li class="expandable">' . '<a href="' . $child_url . '">' . $child_category->name . '</a>';
//
//      //second level category_blocks
//      $child_sql2 = "SELECT * FROM `category` WHERE `parent_id` = '{$child_category->category_id}' ";
//      $child_object2 = self::find_by_sql($child_sql2);
//      if (COUNT($child_object2) > 0) {
//       //beging of ul3
//       $allCategorys .= '<ul>';
//       foreach ($child_object2 as $child_category) {
//        $child_url = self::full_category($child_category->value);
//        //begin  of Li3
//        $allCategorys .= '<li  class="expandable">' . '<a href="' . $child_url . '">' . $child_category->name . '</a>';
//
//        //third level category_blocks
//        $child_sql3 = "SELECT * FROM `category` WHERE `parent_id` = '{$child_category->category_id}' ";
//        $child_object3 = self::find_by_sql($child_sql3);
//        if (COUNT($child_object3) > 0) {
//         //beging of ul4
//         $allCategorys .= '<ul>';
//         foreach ($child_object3 as $child_category) {
//          $child_url = self::full_category($child_category->value);
//          //begin & end of Li4
//          $allCategorys .= '<li  class="expandable">' . '<a href="' . $child_url . '">' . $child_category->name . '</a></li>';
//         }
//         $allCategorys .= '</ul>';
//         //end of ul4
//        }
//        $allCategorys .= '</li> ';
//        //end of Li3
//       }
//       $allCategorys .= '</ul>';
//       //end of ul3
//      }
//      $allCategorys .= '</li> ';
//      //end of Li2
//     }
//    }//end of child foreach
//    $allCategorys .= '</ul>';
//    //end of ul2
//    $allCategorys .= '</li>';
//    //end of Li1
//   }
//  }
//  $allCategorys .= '</ul> ';
//  //end of ul
//  $allCategorys .= '</div> ';
//
//  return $allCategorys;
// }
}

//end of category class
?>



