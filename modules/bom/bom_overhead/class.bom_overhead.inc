<?php
class bom_overhead extends dbObject {
 protected static $table_name = "bom_overhead";
 public static $primary_column = "bom_overhead_id";
 public static $dependent_classes = ['bom_overhead_resource_assignment', 'bom_overhead_rate_assignment'];
 public static $key_column = 'overhead';
 public static $module = "bom";
//  data base variables as stored database column name
 public $field_a = [
		 'bom_overhead_id',
		 'overhead',
		 'description',
		 'org_id',
		 'status',
		 'overhead_type',
		 'default_basis',
		 'absorption_ac_id',
		 'resource_assignment_id',
		 'rate_assignment_id',
		 'ef_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
//variables used for showing data
 public $initial_search = [
		 'bom_overhead_id',
		 'overhead',
		 'description',
		 'org_id',
		 'status',
 ];
 public $column = [
		 'bom_overhead_id',
		 'overhead',
		 'description',
		 'org_id',
		 'status',
 ];
 public $account = [
		 'absorption_ac_id'
 ];
 public $requiredField = [
		 'overhead',
		 'description',
		 'org_id'
 ];
  public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " OverHead - Create & Update OverHead "; //page Title
 public $option_list = [
//		 'calendar_option_line_code' => 'GL_CALENDAR_NAME',
 ]; //list of search fields which have options
 
 public $bom_overhead_id;
 public $overhead;
 public $description;
 public $org_id;
 public $status;
 public $overhead_type;
 public $default_basis;
 public $absorption_ac_id;
 public $resource_assignment_id;
 public $rate_assignment_id;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }

}

//end of resource class
?>