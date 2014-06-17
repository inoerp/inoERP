<?php

class locator extends subinventory {

 public static $table_name = "locator";
 public static $primary_column = "locator_id";
 public static $key_column = 'locator';
 public static $module = "inv";
 public static $multi_select_template_path = 'modules/inv/locator/multi_action/locator_template_ma.php';
//  data base variables as stored database column name
 public $field_a = [
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

 public $initial_search = [
		 "locator_id",
		 "org_id",
		 "org",
		 "subinventory",
		 "subinventory_id",
		 "locator",
 ];
 public $column = ["locator_id",
		 "org_id",
		 "subinventory_id",
		 "locator",
		 "alias",
		 "created_by",
		 "creation_date"
 ];
 public $checkbox = [
		 "rev_enabled_cb"
 ];
 public $requiredField = [
		 "org_id",
		 "subinventory_id"
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Locator - Create & Update Locators"; //page Title
// public $option_lists = [
//		 'subinventory_type' => 'SUBINVENTORY_TYPE',
//		 'locator_control' => 'LOCATOR_CONTROL',
// ];
// 
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

 public function findAll_ofSubinventory() {
	if (!empty($this->subinventory_id)) {
	 $sql = " SELECT * FROM ";
	 $sql .= self::$table_name;
	 $sql .= " WHERE subinventory_id = :subinventory_id ";

	 $param_a = ['subinventory_id'];
	 $value_a = ['subinventory_id' => $this->subinventory_id];
	 $result = $this->findBy_sql($sql, $param_a, $value_a);
	} else {
	 $result = $this;
	}
	return $result;
 }

 public static function find_all_of_subinventory($subinventory_id = "") {
	if (!empty($subinventory_id)) {
	 $sql = " SELECT * FROM ";
	 $sql .= self::$table_name;
	 $sql .= " WHERE subinventory_id = $subinventory_id ";
	 $result = self::find_by_sql($sql);
	} else {
	 $result = null_instantitae('locator');
	}
	return $result;
 }

}

?>