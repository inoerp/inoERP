<?php

class subinventory extends org {

 protected static $table_name = "subinventory";
//  data base variables as stored database column name
 public static $field_array = ["subinventory_id",
		 "org_id",
		 "type",
		 "subinventory",
		 "description",
		 "locator_control",
		 "allow_negative_balance_cb",
		 "default_cost_group",
		 "material_ac_id",
		 "material_oh_ac_id",
		 "overhead_ac_id",
		 "resource_ac_id",
		 "osp_ac_id",
		 "expense_ac_id",
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
			"subinventory",
		 "inventory_id",
			"subinventory_id",
		 "org_id",
		 "org",
		 "description",
		 "master_org"
 ];
	
 public static $column_array = ["subinventory_id",
		 "org_id",
		 "type",
		 "subinventory",
		 "description",
		 "created_by",
		 "org"
 ];
 public static $account_array = ["material_ac_id",
		 "material_oh_ac_id",
		 "overhead_ac_id",
		 "resource_ac_id",
		 "osp_ac_id",
		 "expense_ac_id",
 ];
 public static $checkbox_array = ["rev_enabled_cb",
		 "allow_negative_balance_cb"
 ];
 public static $base_encoded_array = [];
 
 public static $requiredField_array = [
		 "org_id",
		 "type",
		 "subinventory"
 ];
 
  public static $primary_column = "subinventory_id";
	
 public $subinventory_id;
public $org;
 public $org_id;
 public $type;
 public $subinventory;
 public $description;
 public $locator_control;
//public $allow_negative_balance;
 public $allow_negative_balance_cb;
 public $default_cost_group;
//public $material_ac;
//public $material_oh_ac;
//public $overhead_ac;
//public $resource_ac;
//public $osp_ac;
//public $expense_ac;
 public $material_ac_id;
 public $material_oh_ac_id;
 public $overhead_ac_id;
 public $resource_ac_id;
 public $osp_ac_id;
 public $expense_ac_id;
 public $ef_id;
 public $status;
//public $rev_enabled;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 Public static $tab_header = <<<'VAR'
            <ul class="tabMain">
             <li><a href="#tabsLine-1">Mandatory</a></li>
             <li><a href="#tabsLine-2">Account</a></li>
             <li><a href="#tabsLine-3">Other Info</a></li>
            </ul>
VAR;
 public static $tabs_header1_tr = <<<'VAR'
              <thead> 
               <tr>
                <th>Action</th>
                <th>Sub Inventory Id</th>
                <th>Inventory Id</th>
                <th>Sub Inventory Type</th>
                <th>Sub Inventory</th>
                <th>Description</th>
                <th>Locator Control</th>
                <th>Negative Balance</th>
               </tr>
              </thead>
VAR;
 public static $tabs_header2_tr = <<<'VAR'
              <thead> 
               <tr>
                <th>Cost Group</th>
                <th>Material</th>
                <th>MOH</th>
                <th>Over Head</th>
                <th>Resource</th>
                <th>OSP</th>
                <th>Expense</th>
               </tr>
              </thead>
VAR;
 public static $tabs_header3_tr = <<<'VAR'
              <thead> 
               <tr>
                <th>EF Id</th>
                <th>Status</th>
                <th>Rev Enabled</th>
                <th>Rev Number</th>
               </tr>
              </thead>
VAR;

 Public static function subinventory_type() {
	$option_header = option_header::find_by_exact_name('SUBINVENTORY_TYPE');
	$subinventory_class = option_line::find_by_option_id($option_header->option_header_id);
	return $subinventory_class;
 }

 Public static function locator_control() {
	$option_header = option_header::find_by_exact_name('LOCATOR_CONTROL');
	$locator_control = option_line::find_by_option_id($option_header->option_header_id);
	return $locator_control;
 }
 
  public static function find_all_of_org_id($org_id) {
	 if(!empty($org_id)){
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE org_id = $org_id ";
	$result = self::find_by_sql($sql);
	 }else{
		$result = null_instantitae('subinventory');
	 }
	return $result;
 }


}

//end of subinventory class
?>