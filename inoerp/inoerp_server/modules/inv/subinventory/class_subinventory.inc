<?php
/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * subinventory
 * Contains all the subinventory information, such as - subinventory, subinventory_id, org_id,  type, etc.
 * 
 */
class subinventory extends dbObject {

 public static $table_name = "subinventory";
 public static $primary_column = "subinventory_id";
 public static $key_column = 'subinventory';
 public static $module = "inv";
 public static $multi_select_template_path = 'modules/inv/subinventory/multi_action/subinventory_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Subinventory',
  'number' => '2121',
  'description' => 'Subinventory',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 17
 ];
 public $field_a = [
  "subinventory_id",
  "org_id",
  "type",
  "subinventory",
  "description",
  "locator_control",
  "allow_negative_balance_cb",
  "default_cost_group",
  'shipment_pick_priority',
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
  "subinventory_id",
  "description",
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
 public $search_functions = [
  'Organization' => 'search_org_name'
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
 public $shipment_pick_priority;
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
                <th>Subinventory Id</th>
                <th>Inventory Id</th>
                <th>Subinventory Type</th>
                <th>Subinventory</th>
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
                <th>Overhead</th>
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

 public function _before_showing() {
  if (!empty($this->org_id)) {
   $this->org = org::find_by_id($this->org_id)->org;
  }
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

 public function findBy_parameter_withOrgDetails() {
  $value_a = [];
  $sql = " SELECT si.subinventory_id,si.type,si.subinventory,si.description, org.org,org.org_id  ";
  $sql .= 'From 
            subinventory si,
            org ';
  $sql .= " WHERE si.org_id = org.org_id ";
  if (!empty($this->org_id)) {
   $sql .= " AND org.org_id = :org_id ";
   $value_a['org_id'] = $this->org_id;
  }

  if (!empty($this->subinventory_id)) {
   $sql .= " AND si.subinventory_id = :subinventory_id ";
   $value_a['subinventory_id'] = $this->subinventory_id;
  }
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? $result : false;
 }

 public static function find_all_of_org_id($org_id) {
  global $db;
  if (!empty($org_id)) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE org_id = '{$org_id}' ";
   $result = $db::find_by_sql($sql);
  } else {
   $result = null_instantitae('subinventory');
  }
  return $result;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

 public static function staticVar_init($staticvar) {
  $lines = explode("\n", self::${$staticvar});
  self::${$staticvar} = '';
  foreach ($lines as $key => $line) {
   if(strpos($line,'<th>') !== FALSE) {
 	$left = substr($line,0,strpos($line,'>')+1);
 	$text = trim(rtrim(trim(substr($line,strpos($line,'>')+1,strpos($line,'/')-strpos($line,'>')-2)),'#'));
 	$right = substr($line,strpos($line,'/')-1);
 	if(substr(trim(substr($line,strpos($line,'>')+1,strpos($line,'/')-strpos($line,'>')-2)),-1) == '#') {
 	 $line =  $left . gettext($text) . '#' . $right;
 	} else {
 	 $line =  $left . gettext($text) . $right;
 	}
   }
   if(strpos($line,'<li>') !== FALSE) {
   	$left = substr($line,0,strpos($line,'">')+2);
   	$text = substr($line,strpos($line,'">')+2,strpos($line,'/')-strpos($line,'">')-3);
   	$right = substr($line,strpos($line,'/')-1);
   	if(substr(trim(substr($line,strpos($line,'>')+1,strpos($line,'/')-strpos($line,'>')-2)),-1) == '#') {
   	 $line =  $left . gettext($text) . '#' . $right;
   	} else {
   	 $line =  $left . gettext($text) . $right;
   	}
   }
   self::${$staticvar} = self::${$staticvar} . $line;
   if($line != end($lines)) {
    self::${$staticvar} = self::${$staticvar} . "\n";
   }
  }
 }

}

//end of subinventory class
subinventory::staticVar_init('tab_header');
subinventory::staticVar_init('tabs_header1_tr');
subinventory::staticVar_init('tabs_header2_tr');
subinventory::staticVar_init('tabs_header3_tr');
?>
