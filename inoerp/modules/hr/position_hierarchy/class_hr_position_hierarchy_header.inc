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
 * hr_position_hierarchy_header
 */
class hr_position_hierarchy_header extends dbObject {

 public static $table_name = "hr_position_hierarchy_header";
 public static $primary_column = "hr_position_hierarchy_header_id";
 public static $dependent_classes = ['hr_position_hierarchy_line'];
 public static $key_column = 'hierarchy_name';
 public static $module = "hr";
 public static $system_info = [
  'name' => 'Position Hierarchy',
  'number' => '3112',
  'description' => 'HR Position Hierarchy',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 21
 ];
 public $field_a = [
  'hr_position_hierarchy_header_id',
  'starting_position_id',
  'hierarchy_name',
  'description',
  'revision',
  'effective_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'hr_position_hierarchy_header_id',
  'starting_position_id',
  'hierarchy_name',
 ];
 public $column = [
  'hr_position_hierarchy_header_id',
  'starting_position_id',
  'hierarchy_name',
  'revision',
  'effective_date',
 ];
 public $requiredField = [
  'starting_position_id',
  'hierarchy_name',
  'revision',
 ];
 public $pageTitle = " Position Hierarchy - HR "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
  '_extra_path' => array('form.php?class_name=indented_position&mode=9' => 'Indented Position')
 ];
 public $prg_verify_circular_position_parameters = [
  'Organization' => 'search_org_name',
  'Starting Position' => 'search_item_number_from',
 ];
 public $prg_varify_circular_bom_details = [
  'name' => 'Verify Circular Position ',
  'description' => 'Verify if cicular Position exists',
 ];
 public $hr_position_hierarchy_header_id;
 public $starting_position_id;
 public $hierarchy_name;
 public $description;
 public $revision;
 public $effective_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function __set($name, $value) {
  $this->$name = $value;
 }

 public function _before_showing() {
  if (!empty($this->common_bom_item_id_m)) {
   $item = item::find_by_id($this->common_bom_item_id_m);
   $this->commonBom_item_number = $item->item_number;
   $this->commonBom_item_description = $item->item_description;
  } else {
   $this->commonBom_item_number = null;
   $this->commonBom_item_description = null;
  }
 }

 Public static function wip_supply_type() {
  $option_header = option_header::find_by_name('WIP_SUPPLY_TYPE');
  $wip_supply_type = option_line::find_by_option_id($option_header->option_header_id);
  return $wip_supply_type;
 }

 Public static function bom_charge_basis() {
  $option_header = option_header::find_by_name('BOM_CHARGE_BASIS');
  $bom_charge_basis = option_line::find_by_option_id($option_header->option_header_id);
  return $bom_charge_basis;
 }

 Public static function bom_overhead_type() {
  $option_header = option_header::find_by_name('BOM_OVERHEAD_TYPE');
  $bom_overhead_type = option_line::find_by_option_id($option_header->option_header_id);
  return $bom_overhead_type;
 }

 Public static function bom_schedule_option() {
  $option_header = option_header::find_by_exact_name('BOM_SCHEDULE_OPTION');
  $bom_schedule_option = option_line::find_by_option_id($option_header->option_header_id);
  return $bom_schedule_option;
 }

 public static function find_by_itemId($item_id_m) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where item_id_m= '{$item_id_m}' LIMIT 1 ";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public function findBy_itemId() {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where item_id_m= :item_id_m LIMIT 1 ";
  $param_a = ['item_id_m'];
  $value_a = ['item_id_m' => $this->item_id_m];
  $result_array = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public function findBy_orgId($org_id) {
  IF (!empty($org_id)) {
   $this->org_id = $org_id;
  }
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where org_id= :org_id ";
  $value_a = ['org_id' => $this->org_id];
  $result_array = $this->findBySql($sql, $value_a);
  return !empty($result_array) ? $result_array : false;
 }

 private function _explosion($item_id_m, &$level_array, $level = 0) {
  $boh = new hr_position_hierarchy_header();
  $boh->item_id_m = $item_id_m;
  $boh_i = $boh->findBy_itemId();
  if (empty($boh_i)) {
   return;
  }
  foreach ($boh->field_a as $key => $value) {
   if (isset($boh_i->$value)) {
    $boh->$value = $boh_i->$value;
   }
  }
  $bol = new bom_line();
  $bol_i = $bol->findBy_parentId($boh->hr_position_hierarchy_header_id);
  if (empty($bol_i)) {
   return;
  }
  if (empty($level_array[$level])) {
   $level_array[$level] = [];
  }
  foreach ($bol_i as $items) {
   foreach ($level_array as &$existing_val_arr) {
    while (($pos = array_search($items->component_item_id_m, $existing_val_arr)) !== false) {
     unset($existing_val_arr[$pos]);
    }
   }
   array_push($level_array[$level], $items->component_item_id_m);
  }
  $level++;
  foreach ($bol_i as $items) {
   $boh->item_id_m = $items->component_item_id_m;
   $boh_i = $boh->findBy_itemId();
   if (!empty($boh_i)) {
    $this->_explosion($items->component_item_id_m, $level_array, $level);
   }
  }
 }

 private function _indented_bom($item_id_m, &$level_array, $level = 0) {
  $boh = new hr_position_hierarchy_header();
  $boh->item_id_m = $item_id_m;
  $boh_i = $boh->findBy_itemId();
  if (empty($boh_i)) {
   return;
  }
  foreach ($boh->field_a as $key => $value) {
   if (isset($boh_i->$value)) {
    $boh->$value = $boh_i->$value;
   }
  }
  $bol = new bom_line();
  $bol_i = $bol->findBy_parentId($boh->hr_position_hierarchy_header_id);
  if (empty($bol_i)) {
   return;
  }
  if (empty($level_array[$level])) {
   $level_array[$level] = [];
  }
  foreach ($bol_i as $items) {
   array_push($level_array[$level], $items->component_item_id_m);
  }
  $level++;
  foreach ($bol_i as $items) {
   $boh->item_id_m = $items->component_item_id_m;
   $boh_i = $boh->findBy_itemId();
   if (!empty($boh_i)) {
    $this->_indented_bom($items->component_item_id_m, $level_array, $level);
   }
  }
 }

 //not accurate need to change the logic
 private function _varify_circular_bom($item_id_m, &$parent_ref_items) {
  array_push($parent_ref_items, $item_id_m);

  $boh = new hr_position_hierarchy_header();
  $boh->item_id_m = $item_id_m;
  $boh_i = $boh->findBy_itemId();
  if (empty($boh_i)) {
   return;
  }
  $bol = new bom_line();
  $bol_i = $bol->findBy_parentId($boh_i->hr_position_hierarchy_header_id);
  if (empty($bol_i)) {
   return;
  }

  foreach ($bol_i as $items) {
   if (array_search($items->component_item_id_m, $parent_ref_items)) {
    return $item_id_m;
   } else {
    $this->_varify_circular_bom($items->component_item_id_m, $parent_ref_items);
   }
  }
 }

 public function prg_varify_circular_bom($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $parent_ref_items = [];
  if (!empty($parameters['org_id'][0])) {
   $org_id = $parameters['org_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $org_id;
  } else {
   $this->message .= '<br> Error! : No org id found @ cst_item_cost_header ' . __LINE__;
   return $this->message;
  }

  if (isset($parameters['from_item_id_m'][0])) {
   $this->message .= "<br/>Using Item Id ";
   $from_item_id_m = $parameters['from_item_id_m'][0];
   if (!empty($parameters['to_item_id_m'][0])) {
    $to_item_id_m = $parameters['to_item_id_m'][0];
   } else {
    $to_item_id_m = $from_item_id_m;
   }
   $item = new item();
   $item_range = $item->findBy_itemIdRange($from_item_id_m, $to_item_id_m);
   foreach ($item_range as $items) {
    try {
     $item_id_m = $this->_varify_circular_bom($items->item_id_m, $parent_ref_items);
     if ($item_id_m) {
      $this->message .= "<br/>$item_id_m has circular BOM";
     } else {
      $this->message .= "<br/>No Circular BOM found";
     }
    } catch (Exception $e) {
     $this->message .= "<br/> Cicrular BOM Verification failed for Item id " . $items->item_id_m . $e->getMessage();
    }
   }
   return $this->message;
  }

  if (isset($parameters['from_item_number'][0])) {
   $from_item_number = $parameters['from_item_number'][0];
   if (!empty($parameters['to_item_number'][0])) {
    $to_item_number = $parameters['to_item_number'][0];
   } else {
    $to_item_number = $from_item_number;
   }
   $item = new item();
   $item_range = $item->findBy_itemNumberRange_OrgId($from_item_number, $to_item_number, $org_id);
   foreach ($item_range as $items) {
    try {
     $item_id_m = $this->_varify_circular_bom($items->item_id_m, $parent_ref_items);
     if ($item_id_m) {
      $this->message .= "<br/>$item_id_m has circular BOM";
     } else {
      $this->message .= "<br/>No Circular BOM found";
     }
    } catch (Exception $e) {
     $this->message .= "<br/> Cicrular BOM Verification failed for Item id " . $items->item_id_m . $e->getMessage();
    }
   }
   return $this->message;
  }
 }

 public function BOM_Explosion($item_id_m) {
  $level_array = [];
  $l = 0;
  $array_level = 'array_' . $l;
  $$array_level = [];
  array_push($$array_level, $item_id_m);
  array_push($level_array, $$array_level);
  $this->_explosion($item_id_m, $level_array, 1);
  return $level_array;
 }

 public function indented_BOM($item_id_m) {
  $level_array = [];
  $l = 0;
  $array_level = 'array_' . $l;
  $$array_level = [];
  array_push($$array_level, $item_id_m);
  array_push($level_array, $$array_level);
  $this->_indented_bom($item_id_m, $level_array, 1);
  return $level_array;
 }

}

//end of bom class
?>