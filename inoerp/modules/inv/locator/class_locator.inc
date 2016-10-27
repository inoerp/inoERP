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
 * Locator
 * Contains all the locator information, such as - alias, org_id,  subinventory_id, locator, etc.
 * 
 */
class locator extends subinventory {

 public static $table_name = "locator";
 public static $primary_column = "locator_id";
 public static $key_column = 'locator';
 public static $module = "inv";
 public static $multi_select_template_path = 'modules/inv/locator/multi_action/locator_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Locator',
  'number' => '2108',
  'description' => 'Inventory Transaction',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 8
 ];
 public $field_a = [
  "locator_id",
  "org_id",
  "subinventory_id",
  "locator_structure",
  "locator",
  "alias",
  'dimension_uom_id',
  'length',
  'height',
  'width',
  'x_coordinate',
  'y_coordinate',
  'z_coordinate',
  'max_units',
  'max_volume_uom_id',
  'max_volume',
  'max_weight_uom_id',
  'max_weight',
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
 
 public $numberField = [
  'max_units',
  'max_volume',
  'max_weight',
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
 public $dimension_uom_id;
 public $length;
 public $height;
 public $width;
 public $x_coordinate;
 public $y_coordinate;
 public $z_coordinate;
 public $max_units;
 public $max_volume_uom_id;
 public $max_volume;
 public $max_weight_uom_id;
 public $max_weight;
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
                <th>Subinventory</th>
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

 public function findBy_parameter() {
  $value_a = [];
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE org_id = :org_id ";
  $value_a['org_id'] = $this->org_id;
  if (!empty($this->subinventory_id)) {
   $sql .= " AND subinventory_id = :subinventory_id ";
   $value_a['subinventory_id'] = $this->subinventory_id;
  }
  if (!empty(trim($this->locator_id))) {
   $sql .= " AND locator_id = :locator_id ";
   $value_a['locator_id'] = $this->locator_id;
  }
  $result = $this->findBySql($sql, $value_a);

  return !empty($result) ? $result : false;
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
   self::${$staticvar} = self::${$staticvar} . $line;
   if($line != end($lines)) {
 	self::${$staticvar} = self::${$staticvar} . "\n";
   }
  }
 }

}

locator::staticVar_init('view_table_line_tr');
locator::staticVar_init('table_line_tr');
?>
