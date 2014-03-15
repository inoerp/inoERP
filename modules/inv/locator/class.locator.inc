<?php

class locator extends subinventory {

 protected static $table_name = "locator";
//  data base variables as stored database column name
 public static $field_array = [
		 "locator_id",
		 "org_id",
		 "subinventory_id",
		 "locator_structure",
		 "locator",
		 "alias",
		 "ef_id",
		 "status",
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
//variables used for showing data

 public static $initial_search_array = [
		 "locator_id",
		 "org_id",
		 "org",
		 "subinventory",
		 "subinventory_id",
		 "locator",
 ];
 public static $column_array = ["locator_id",
		 "org_id",
		 "subinventory_id",
		 "locator",
		 "alias",
		 "created_by",
		 "creation_date"
 ];
 public static $checkbox_array = [
		 "rev_enabled_cb"
 ];
 
  public static $requiredField_array = [
		 "org_id",
		 "subinventory_id"
 ];
	
 public static $primary_column = "locator_id";
 public $locator_id;
 public $org_id;
 public $org;
 public $subinventory;
 public $subinventory_id;
 public $locator_structure;
 public $locator;
 public $alias;
 public $ef_id;
 public $status;
 public $rev_enabled_cb;
 public $rev_enabled;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public static $view_table_line_tr = <<<'VAR'
              <thead> 
               <tr>
                <th>Action</th>
                <th>Inventory</th>
                <th>SubInventory</th>
                <th>Structure</th>
                <th>Locator Id</th>
                <th>Locator </th>
                <th>Alias</th>
                <th>EF Id</th>
                <th>Status</th>
               </tr>
              </thead>
VAR;
 public static $table_line_tr = <<<'VAR'
              <thead> 
               <tr>
                <th>Action</th>
                <th>Locator Id</th>
                <th>Locator </th>
                <th>Alias</th>
                <th>EF Id</th>
                <th>Status</th>
                <th>Rev Enabled</th>
                <th>Rev Number</th>
               </tr>
              </thead>
VAR;

 Public static function locator_structure() {
	$option_header = option_header::find_by_name('LOCATOR_STRUCTURE');
	$locator_class = option_line::find_by_option_id($option_header->option_header_id);
	$loc_structure = "";
	foreach ($locator_class as $key => $value) {
	 $loc_structure .= ($value->option_line_code) . '-';
	}
	return substr($loc_structure, 0, -1);
 }

 public static function find_all_of_subinventory($subinventory_id="") {
	if(!empty($subinventory_id)){
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE subinventory_id = $subinventory_id ";
	$result = self::find_by_sql($sql);
	}else{

$result = null_instantitae('locator');
	}
	return $result;
 }

}
?>