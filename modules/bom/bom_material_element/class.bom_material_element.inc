<?php

class bom_material_element extends dbObject {

 protected static $table_name = "bom_material_element";
 public static $key_column = 'material_element';
 public static $primary_column = "bom_material_element_id";
 public static $module = "bom";
//  data base variables as stored database column name
 public $field_a = [
		 'bom_material_element_id',
		 'material_element',
		 'description',
		 'org_id',
		 'status',
		 'default_basis',
		 'ef_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
//variables used for showing data
 public $initial_search = [
		 'bom_material_element_id',
		 'material_element',
		 'description',
		 'org_id',
		 'status'
 ];
 public $column = [
		 'bom_material_element_id',
		 'material_element',
		 'description',
		 'org_id',
		 'status'
 ];
 public $requiredField = [
		 'material_element',
		 'description',
		 'org_id'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Material Element - Create & Update BOM Material Element "; //page Title
 
 public $bom_material_element_id;
 public $material_element;
 public $description;
 public $org_id;
 public $status;
 public $default_basis;
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