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
 * Onhand
 * Contains all the onhand information, such as - item_id_m, lot_number, org_id,  onhand quantity, etc.
 * 
 */
class onhand extends dbObject {

 public static $table_name = "onhand";
 protected static $view_name = "onhand_v";
 public static $primary_column = "onhand_id";
 public static $key_column = 'item_id_m';
 public static $module = "inv";
 public static $system_info = [
  'name' => 'Onhand',
  'number' => '2111',
  'description' => 'Inventory Onhand',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 11
 ];
//  data base variables as stored database column name
 public $field_a = [
  'onhand_id',
  'item_id_m',
  'revision_name',
  'org_id',
  'subinventory_id',
  'locator_id',
  'lot_id',
  'serial_id',
  'onhand',
  'reservable_onhand',
  'transactable_onhand',
  'lot_status',
  'serial_status',
  'uom_id',
  'secondary_uom_id',
  'onhand_status',
  'ef_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  "org_id",
  "subinventory_id",
  "locator_id",
  "uom_id",
  "onhand_id",
  "item_id_m",
 ];
//variables used for showing data
 public $column = [
  "item_number",
  "item_description",
  "org_name",
  "subinventory",
  "locator",
  "uom",
  "onhand",
  "sum_onhand",
  "onhand_id",
  "item_id_m",
 ];
// public static $checkbox_array =["rev_enabled"                                 
//                                 ];

 public static $group_by = ["locator", "subInventory", "inventory"];
 public $sum_onhand;
 public $onhand_id;
 public $item_id_m;
 public $revision_name;
 public $org_id;
 public $subinventory_id;
 public $locator_id;
 public $lot_id;
 public $item_number;
 public $item_description;
 public $org_name;
 public $subinventory;
 public $locator;
 public $uom_id;
 public $serial_id;
 public $onhand;
 public $reservable_onhand;
 public $transactable_onhand;
 public $lot_status;
 public $serial_status;
 public $uom;
 public $secondary_uom_id;
 public $onhand_status;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $onhand_id_from;
 public $onhand_id_to;
 private $_from_org_id;
 private $_from_subinventory_id;
 private $_from_locator_id;
 private $_to_org_id;
 private $_to_subinventory_id;
 private $_to_locator_id;
 private $_transaction_quantity;

 public function setProperty($property, $value) {
  if (property_exists($this, $property)) {
   switch ($property) {
    case '_show_update_path':
     $this->$property = !empty($value) ? true : false;

    case '_result':
     $this->$property = is_array($value) ? $value : false;


    default:
     $this->$property = $value;
     break;
   }
  }
 }

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
                <th>Rev Enabled</th>
                <th>Rev Number</th>
               </tr>
              </thead>
VAR;

//Public static function onhand_structure() {
//    $option_header = option_header::find_by_name('LOCATOR_STRUCTURE');
//    $onhand_class = option_line::find_by_option_id($option_header->option_id);
//    return $onhand_class;
//  }

 public static function find_all_v() {
  $sql = " SELECT * FROM " . self::$view_name;
  $result = self::find_by_sql($sql);
  return $result;
 }

 public function findBy_itemIdm_location() {
  $sql = "SELECT * FROM " . self::$table_name;
  $sql .= " WHERE item_id_m = '{$this->item_id_m}' ";
  if (!empty($this->revision_name)) {
   $sql .= " AND revision_name = '{$this->revision_name}' ";
  }

  if (!empty($this->org_id)) {
   $sql .= " AND org_id = '{$this->org_id}' ";
  }
  if (!empty($this->subinventory_id)) {
   $sql .= " AND subinventory_id = '{$this->subinventory_id}' ";
  }
  if (!empty($this->locator_id)) {
   $sql .= " AND locator_id = '{$this->locator_id}' ";
  }

  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 private function create_onhand_v() {
  $sql = "
   CREATE OR REPLACE VIEW onhand_v
(onhand_id, item_number, item_description, org_name, subinventory, locator,
uom_id,onhand, item_id_m, org_id, subinventory_id, 
locator_id, lot_id, serial_id, reservable_onhand, 
transactable_onhand, lot_status, serial_status,  
secondary_uom_id, onhand_status, ef_id, created_by, 
creation_date, last_update_by, last_update_date)
AS
SELECT onhand.onhand_id, 
item.item_number, item.item_description, org.org, subinventory.subinventory, locator.locator,
onhand.uom_id,onhand.onhand,
onhand.item_id_m, onhand.org_id, onhand.subinventory_id, 
onhand.locator_id, onhand.lot_id, onhand.serial_id, onhand.reservable_onhand, 
onhand.transactable_onhand, onhand.lot_status, onhand.serial_status,  
onhand.secondary_uom_id, onhand.onhand_status, onhand.ef_id, onhand.created_by, 
onhand.creation_date, onhand.last_update_by, onhand.last_update_date

FROM onhand 
LEFT JOIN item ON onhand.item_id_m = item.item_id_m
LEFT JOIN org ON onhand.org_id = org.org_id
LEFT JOIN subinventory ON onhand.subinventory_id = subinventory.subinventory_id
LEFT JOIN locator ON onhand.locator_id = locator.locator_id;
";
 }

 private function _validate_mandatory_fields() {
  if (empty($this->item_id_m)) {
   echo "<br>Onhand Update Failed!Error @onhand - Item Id Missing" . __LINE__;
   $this->rollback = true;
   return -99;
  } else if (empty($this->_transaction_quantity)) {
   echo "<br>Onhand Update Failed!Error @onhand - Transaction Quantity Missing" . __LINE__;
   $this->rollback = true;
   return -99;
  }
 }

 private function _update_from_onhand() {
  global $dbc;
  $from_onhand_sql = " SELECT * FROM onhand";
  $from_onhand_sql .= " WHERE item_id_m = '{$this->item_id_m}' ";
  if (!empty($this->revision_name)) {
   $from_onhand_sql .= " AND revision_name = '{$this->revision_name}' ";
  }
  $from_onhand_sql .= " AND  	org_id = '{$this->_from_org_id}' ";

  if (!empty($this->_from_subinventory_id)) {
   $from_onhand_sql .= " AND  subinventory_id = '{$this->_from_subinventory_id}' ";
  }
  if (!empty($this->_from_locator_id)) {
   $from_onhand_sql .= " AND locator_id = '{$this->_from_locator_id}' ";
  }

  switch (DB_TYPE) {
   case 'ORACLE' :
    $from_onhand_sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $from_onhand_sql .= ino_perPageSql(1);
    break;
  }

  $from_onhand_result_a = $this->findBy_sql($from_onhand_sql);
  $from_onhand_result = !empty($from_onhand_result_a) ? array_pop($from_onhand_result_a) : false;
  if ($from_onhand_result) {
   $this->onhand = $from_onhand_result->onhand - $this->_transaction_quantity;
   $this->reservable_onhand = $from_onhand_result->reservable_onhand - $this->_transaction_quantity;
   $this->transactable_onhand = $from_onhand_result->transactable_onhand - $this->_transaction_quantity;
   $this->onhand_id = $from_onhand_result->onhand_id;
  } else {
   $this->onhand = -($this->_transaction_quantity);
   $this->reservable_onhand = -($this->_transaction_quantity);
   $this->transactable_onhand = -($this->_transaction_quantity);
   $this->onhand_id = null;
  }

  if ($this->onhand < 0) {
   $item_i = item::find_by_orgId_item_id_m($this->item_id_m, $this->_from_org_id);
   if (empty($item_i->allow_negative_balance_cb)) {
//    pa($item_i);
    echo "<br>Negative balance is not allowed for the item";
    $dbc->rollback = true;
    return -99;
   } else {
    $sub_i = subinventory::find_by_id($this->_from_subinventory_id);
    if (empty($sub_i->allow_negative_balance_cb)) {
     echo "<br>Negative balance is not allowed for the from subinventory";
     $dbc->rollback = true;
     return -99;
    }
   }
  }
  $this->org_id = $this->_from_org_id;
  $this->subinventory_id = $this->_from_subinventory_id;
  $this->locator_id = $this->_from_locator_id;

  try {
   $this->audit_trial();
   $this->save();
   $this->onhand_id_from = $this->onhand_id;
   echo "<br>On Hand is Successfully Updated. The on hand Id is " . $this->onhand_id . ' & On Hand Value is ' . $this->onhand;
   return 1;
  } catch (Exception $e) {
   $dbc->rollback = true;
   echo "<br>Onhand Update Failed <br> Line # " . __LINE__ . '<br>' . $e->getMessage();
   return -99;
  }
 }

 private function _update_to_onhand() {
  global $dbc;
  $to_onhand_sql = " SELECT *  FROM onhand";
  $to_onhand_sql .= " WHERE item_id_m = '{$this->item_id_m}' ";
  if (!empty($this->revision_name)) {
   $item_j = item::find_by_orgId_item_id_m($this->item_id_m, $this->_to_org_id);
   if (!empty($item_j->onhand_with_rev_cb)) {
    $to_onhand_sql .= " AND revision_name = '{$this->revision_name}' ";
   } else {
    $this->revision_name = null;
   }
  }
  $to_onhand_sql .= " AND  	org_id = '{$this->_to_org_id}' ";

  if (!empty($this->_to_subinventory_id)) {
   $to_onhand_sql .= " AND  	subinventory_id = '{$this->_to_subinventory_id}' ";
  }
  if (!empty($this->_to_locator_id)) {
   $to_onhand_sql .= " AND  	locator_id = '{$this->_to_locator_id}' ";
  }

  switch (DB_TYPE) {
   case 'ORACLE' :
    $to_onhand_sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $to_onhand_sql .= ino_perPageSql(1);
    break;
  }

  $to_onhand_result_a = $this->findBy_sql($to_onhand_sql);
  $to_onhand_result = !empty($to_onhand_result_a) ? array_pop($to_onhand_result_a) : false;
  if ($to_onhand_result) {
   $this->onhand = $to_onhand_result->onhand + $this->_transaction_quantity;
   $this->reservable_onhand = $to_onhand_result->reservable_onhand + $this->_transaction_quantity;
   $this->transactable_onhand = $to_onhand_result->transactable_onhand + $this->_transaction_quantity;
   $this->onhand_id = $to_onhand_result->onhand_id;
  } else {
   $this->onhand = $this->_transaction_quantity;
   $this->reservable_onhand = $this->_transaction_quantity;
   $this->transactable_onhand = $this->_transaction_quantity;
   $this->onhand_id = null;
  }
  $this->org_id = $this->_to_org_id;
  $this->subinventory_id = $this->_to_subinventory_id;
  $this->locator_id = $this->_to_locator_id;

  try {
   $this->audit_trial();
   $this->save();
   $this->onhand_id_to = $this->onhand_id;
   echo "<br>On Hand is Successfully Updated. The on hand Id is " . $this->onhand_id . ' & On Hand Value is ' . $this->onhand;
   return 1;
  } catch (Exception $e) {
   $dbc->rollback = true;
   echo "<br>Onhand Update Failed <br> Line # " . __LINE__ . '<br>' . $e->getMessage();
   return -99;
  }
 }

 public function updateOnhand() {
  global $dbc;
//verify all the mandatory fields exists
  $mandatory_fields = $this->_validate_mandatory_fields();
  if ($mandatory_fields < 0) {
   echo "<br>Mandatort fields are missing <br> Line # : " . __LINE__;
   $dbc->rollback = true;
   return -99;
  }

  //from org transaction update
  if (!empty($this->_from_org_id)) {
   try {
    $this->_update_from_onhand();
//		return 1;
   } catch (Exception $e) {
    $dbc->rollback = true;
    echo "<br>From Onhand Update Failed <br> Line # " . __LINE__ . '<br>' . $e->getMessage();
    return -99;
   }
  }

  //to org transaction update
  if (!empty($this->_to_org_id)) {
   try {
    $this->_update_to_onhand();
//		return 1;
   } catch (Exception $e) {
    $dbc->rollback = true;
    echo "<br>From Onhand Update Failed <br> Line # " . __LINE__ . '<br>' . $e->getMessage();
    return -99;
   }
  }

  //with in org transaction update
  if ((!empty($this->org_id)) && (empty($this->_from_org_id)) && (empty($this->_to_org_id))) {
   if (!empty($this->_from_subinventory_id)) {
    $this->_from_org_id = $this->org_id;
    try {
     $this->_update_from_onhand();
    } catch (Exception $e) {
     echo "<br>From Onhand Update Failed <br> Line # " . __LINE__ . '<br>' . $e->getMessage();
     return -99;
    }
   }
   if (!empty($this->_to_subinventory_id)) {
    $this->_to_org_id = $this->org_id;
    try {
     $this->_update_to_onhand();
    } catch (Exception $e) {
     echo "<br>From Onhand Update Failed <br> Line # " . __LINE__ . '<br>' . $e->getMessage();
     return -99;
    }
   }
  }
  return 1;
 }

 public function findOnhand_byItemId($item_id_m = '', $revision_name = '') {
  if (!empty($item_id_m)) {
   $this->item_id_m = $item_id_m;
  }
  if (!empty($revision_name)) {
   $this->revision_name = $revision_name;
  }
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE item_id_m = '{$this->item_id_m}' ";
  if (!empty($this->revision_name)) {
   $sql .= " AND revision_name = '{$this->revision_name}' ";
  }

  $result = $this->findBy_sql($sql);
  return !empty($result) ? $result : false;
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

//end of onhand class
onhand::staticVar_init('view_table_line_tr');
?>
