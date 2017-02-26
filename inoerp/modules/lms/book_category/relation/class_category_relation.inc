<?php

class category_relation extends dbObject {

 public static $table_name = "category";
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
 public $initial_search = [
		 "major_category_id",
		 "category_id",
		 "parent_id",
		 "category",
		 "description",
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
 public $category;
 public $description;
 public $primary_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

}
?>