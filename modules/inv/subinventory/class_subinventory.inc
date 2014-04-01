<?php

class subinventory extends dbObject {

 protected static $table_name = "subinventory";
 public static $primary_column = "subinventory_id";
 public static $key_column = 'subinventory';
 public static $module = "inv";
 public static $multi_select_template_path = 'modules/inv/subinventory/multi_action/subinventory_template_ma.php';
//  data base variables as stored database column name
 public $field_a = [
		 "subinventory_id",
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
 public $initial_search = [
		 "subinventory",
		 "inventory_id",
		 "subinventory_id",
		 "org_id",
		 "org",
		 "description",
		 "master_org"
 ];
 public $column = ["subinventory_id",
		 "org_id",
		 "type",
		 "subinventory",
		 "description",
		 "created_by",
		 "org"
 ];
 public $account = ["material_ac_id",
		 "material_oh_ac_id",
		 "overhead_ac_id",
		 "resource_ac_id",
		 "osp_ac_id",
		 "expense_ac_id",
 ];
 public $checkbox = ["rev_enabled_cb",
		 "allow_negative_balance_cb"
 ];
 public $requiredField = [
		 "org_id",
		 "type",
		 "subinventory"
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Subinventory - Create & Update Subinventories"; //page Title
 public $option_lists = [
		 'subinventory_type' => 'SUBINVENTORY_TYPE',
		 'locator_control' => 'LOCATOR_CONTROL',
 ];
 public $subinventory_id;
 public $org;
 public $org_id;
 public $type;
 public $subinventory;
 public $description;
 public $locator_control;
 public $allow_negative_balance_cb;
 public $default_cost_group;
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
								<th>Cost Group</th>
               </tr>
              </thead>
VAR;
 public static $tabs_header2_tr = <<<'VAR'
              <thead> 
               <tr>
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

 public function findAll_ofOrgid() {
	if (!empty($this->org_id)) {
	 $sql = " SELECT * FROM ";
	 $sql .= self::$table_name;
	 $sql .= " WHERE org_id = :org_id ";

	 $param_a = ['org_id'];
	 $value_a = ['org_id' => $this->org_id];
	 $result = $this->findBy_sql($sql, $param_a, $value_a);
	} else {
	 $result = $this;
	}
	return $result;
 }

 public static function find_all_of_org_id($org_id) {
	if (!empty($org_id)) {
	 $sql = " SELECT * FROM ";
	 $sql .= self::$table_name;
	 $sql .= " WHERE org_id = :org_id ";

	 $param_a = ['org_id'];
	 $value_a = ['org_id' => $org_id];
	 $result = $this->findBy_sql($sql, $param_a, $value_a);
	} else {
	 $result = null_instantitae('subinventory');
	}
	return $result;
 }

 public static function search_add_extra_fields(&$arr) {
	$org = new org;
	if (!(is_array($arr))) {
	 return false;
	}
	foreach ($arr as &$obj) {
	 $primary_column = parent::$primary_column;
	 if (!empty($obj->$primary_column)) {
		$org_i = $org->findBy_id($obj->$primary_column);
		$obj->org = $org_i->org;
		$obj->description = $org_i->description;
	 }
	}
 }

 public function multi_select_hidden_fields() {
	$multi_select_hidden = [
			'mode',
			'show_block'
	];

	return $multi_select_hidden;
 }

}

//end of subinventory class
?>