<?php

class page_view extends dbObject {

 public static $table_name = "page";
 public static $primary_column = "page_id";
 public static $key_column = "subject";
 public static $module = "extension";
 public $field_a = [
		 "page_id",
		 "parent_id",
		 "subject",
		 "content",
		 'content_php_cb',
		 "terms",
		 "published_cb",
		 'show_in_frontpage_cb',
		 "weightage",
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
//  data base variables as stored database column name
 public $checkbox = ["published_cb",
		 "rev_enabled_cb",
		 'show_in_frontpage_cb',
		 'content_php_cb'
 ];
 public $base_encoded_array = [
		 "content_php_cb" => "content"
 ];
 public $initial_search = [
		 "page_id",
		 "parent_id",
		 "subject",
		 "content",
		 "created_by",
 ];
//variables used for showing data
 public $column = [
		 "page_id",
		 "parent_id",
		 "subject",
		 "content",
		 'content_php_cb',
		 "terms",
		 "published_cb",
 ];
 public $requiredField = ["content"
 ];
 public $pageTitle = " Content - Create & View different contents ";
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $file_id_values;
 public $summary_characters;
 public $content_summary;
 public $page_id;
 public $parent_id;
 public $subject;
 public $content;
 public $content_php_cb;
 public $terms;
 public $published_cb;
 public $show_in_frontpage_cb;
 public $rev_enabled_cb;
 public $weightage;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;


}

//end of page class
?>



