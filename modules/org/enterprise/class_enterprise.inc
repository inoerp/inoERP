<?php

class enterprise extends org {

 public static $table_name = "enterprise";
 public static $primary_column = "enterprise_id";
 public static $key_column = 'org_id';
 public static $module = "org"; //same as gl_journal_source
 public $field_a = [
		 "enterprise_id",
		 "org_id",
		 "designation_option_header_id",
		 "type_option_header_id",
		 "efid",
		 "status",
		 "rev_enabled",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public $initial_search = [
		 "enterprise_id",
		 "org_id",
		 "org",
		 "description"
 ];
 public $column = [
		 "enterprise_id",
		 "org_id",
		 "org",
		 "description"
 ];
 public $requiredField = [
		 "org_id",
 ];
 public $enterprise_id;
 public $org_id;
 public $designation_option_header_id;
 public $type_option_header_id;
 public $description;
 public $address_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " EnterPrise - View & Update Diffent EnterPrises"; //page Title
 
  public static function search_add_extra_fields( &$arr ){
	$org = new org;
	if(!(is_array($arr))){
	 return false;
	}
	foreach($arr as &$obj){
	 $primary_column = parent::$primary_column;
	 if(!empty($obj->$primary_column)){
		$org_i = $org->findBy_id($obj->$primary_column);
		$obj->org = $org_i->org;
		$obj->description = $org_i->description;
	 }
	}
	
 }

}

//end of enterprise class
?>
