<?php

class onhand_v extends dbObject {

 public static $form_class_name = "item";
 public static $table_name = "onhand_v";
 public static $primary_column = "onhand_id";
 public $field_a = [
  'onhand_id',
  'item_number',
  'item_description',
  'org_name',
  'subinventory',
  'locator',
  'uom_id',
  'onhand',
  'reservable_onhand',
  'reserved_quantity',
  'item_id_m',
  'serial_generation',
  'lot_generation',
  'revision_name',
  'org_id',
  'subinventory_id',
  'locator_id',
  'lot_id',
  'serial_id',
  'transactable_onhand',
  'lot_status',
  'serial_status',
  'secondary_uom_id',
  'onhand_status',
  'ef_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'onhand_id',
//  'item_number',
  'item_description',
  'subinventory',
  'locator',
//  'uom_id',
  'onhand',
//  'item_id_m',
//  'org_id',
  'subinventory_id',
  'locator_id',
 ];
 public $search_functions = [
  'Item' => 'search_item_number',
  'Organization' => 'search_org_name',
 ];
 public $dateField = [
 ];
 public $pageTitle = " Onhand - Find Inventory Onhand "; //page Title
 public $search = [
  '_view_path' => 'form.php?class_name=inv_onhand_serial',
  '_show_view_path' => 1,
  '_view_action_meassge' => 'Serial Numbers',
  '_extra_path' => array('form.php?class_name=inv_lot_onhand&mode=2' => 'Lot Numbers')
 ];
 public static $search_groupBy = [
  'item_number' => 'Item Number'
//		 'locator' => 'Locator',
//		 'subinventory' => 'Subinventory',
//		 'org_id' => 'Inventory Org',
 ];
 public $search_groupBy_sum = 'onhand';
 public $ra_onhand_by_subinventoryType_parameters = [
  'Result Limit' => 'ra_result_limit',
  'Chart Type' => 'ra_chart_type',
 ];
 public $ra_onhand_by_subinventoryType_settings = [
  '_chart_name' => 'Onhand Quantity By Subinventory Type',
  '_x_axis_text' => 'Onhand Quantity',
 ];
 public $ra_onhand_value_by_subinventoryType_settings = [
  '_chart_name' => 'Onhand Value By Subinventory Type',
  '_x_axis_text' => 'Onhand Value',
 ];
 public $ra_onhand_by_productLine_settings = [
  '_chart_name' => 'Onhand Quantity By Product Line',
  '_x_axis_text' => 'Onhand Quantity',
 ];
 public $ra_onhand_value_by_productLine_settings = [
  '_chart_name' => 'Onhand Value By Product Line',
  '_x_axis_text' => 'Onhand Value',
 ];
 public $ra_onhand_by_productLine_subinventoryType_settings = [
  '_chart_name' => 'Onhand By Product Line Subinventory Type',
  '_chart_width' => '750',
  '_chart_height' => '450',
  '_x_axis_text' => 'Onhand Quantity',
  '_chart_type' => 'clustered_column',
  '_gap_between_xaxis_text' => '50',
  '_legend' => ''
 ];
 public $ra_report_set_onhand_by_subinventoryType_settings = [
  '_chart_name' => 'On Hand By Subinventory Type',
  '_chart_width' => '350',
  '_chart_height' => '350',
  '_x_axis_text' => 'Sub Invnetory Type',
  '_chart_type' => array('horizonatl_bar', 'vertical_column', 'pie'),
  '_legend' => ''
 ];
 public $ra_report_set_onhand_by_subinventoryType = [
  'ra_onhand_by_subinventoryType',
  'ra_onhand_value_by_subinventoryType',
  'ra_onhand_by_productLine',
  'ra_onhand_value_by_productLine',
  'ra_onhand_by_productLine_subinventoryType'
 ];
 public $onhand_id;
 public $item_number;
 public $item_description;
 public $serial_generation;
 public $lot_generation;
 public $product_line;
 public $org_name;
 public $subinventory;
 public $subinventory_type;
 public $locator;
 public $uom_id;
 public $onhand;
 public $item_id_m;
 public $revision_name;
 public $org_id;
 public $subinventory_id;
 public $locator_id;
 public $lot_id;
 public $serial_id;
 public $reservable_onhand;
 public $reserved_quantity;
 public $transactable_onhand;
 public $lot_status;
 public $serial_status;
 public $secondary_uom_id;
 public $onhand_status;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 private function create_onhand_v() {
  $sql = "
		 CREATE OR REPLACE VIEW onhand_v
(onhand_id, item_number, item_description, product_line, lot_generation,serial_generation,
org_name, subinventory, locator,
uom_id,onhand, reservable_onhand,  reserved_quantity, standard_cost, onhand_value,
item_id_m, revision_name, org_id, subinventory_id, subinventory_type,
locator_id, lot_id, serial_id, 
transactable_onhand, lot_status, serial_status,  
secondary_uom_id, onhand_status, ef_id, created_by, 
creation_date, last_update_by, last_update_date)
AS
SELECT onhand.onhand_id, 
item.item_number, item.item_description, item.product_line, item.lot_generation,item.serial_generation,
org.org, subinventory.subinventory, locator.locator,
onhand.uom_id,onhand.onhand, onhand.onhand - IFNULL(SUM(ir.demand_quantity) , 0) as  reservable_onhand,
SUM(ir.demand_quantity) as reserved_quantity,
cic.standard_cost, (onhand.onhand * cic.standard_cost) as onhand_value,
onhand.item_id_m, onhand.revision_name, onhand.org_id, onhand.subinventory_id, subinventory.type,
onhand.locator_id, onhand.lot_id, onhand.serial_id,
onhand.transactable_onhand, onhand.lot_status, onhand.serial_status,  
onhand.secondary_uom_id, onhand.onhand_status, onhand.ef_id, onhand.created_by, 
onhand.creation_date, onhand.last_update_by, onhand.last_update_date

FROM onhand 
LEFT JOIN item ON onhand.item_id_m = item.item_id_m AND item.org_id = onhand.org_id
LEFT JOIN org ON onhand.org_id = org.org_id
LEFT JOIN subinventory ON onhand.subinventory_id = subinventory.subinventory_id
LEFT JOIN locator ON onhand.locator_id = locator.locator_id
LEFT JOIN cst_item_cost_v cic ON cic.item_id_m = onhand.item_id_m AND cic.bom_cost_type='FROZEN' AND cic.org_id = onhand.org_id
LEFT JOIN inv_reservation ir ON ir.item_id_m = onhand.item_id_m AND ir.org_id = onhand.org_id
AND ir.subinventory_id = onhand.subinventory_id AND (ir.locator_id = onhand.locator_id || onhand.locator_id IS NULL )

GROUP BY onhand.item_id_m, onhand.org_id, onhand.subinventory_id, onhand.locator_id
";
 }

 public function findBy_itemIdm_location() {
  $sql = "SELECT * FROM " . self::$table_name;
  $sql .= " WHERE item_id_m = '{$this->item_id_m}' ";
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

 public static function find_by_itemId_orgId($item_id, $org_id) {
  $sql = " SELECT * from onhand_v WHERE item_id_m = '{$item_id}' "
   . " AND org_id = '{$org_id}' ";
  $result = self::find_by_sql($sql);
//    echo $sql;
//  pa($result);
  return !empty($result) ? $result : false;
 }

 public static function find_by_itemIdM_orgId_subInventoryId($item_id, $org_id, $subinventory_id) {
  $sql = " SELECT * from onhand_v WHERE item_id_m = '{$item_id}' "
   . " AND org_id = '{$org_id}' "
   . " AND subinventory_id = '{$subinventory_id}' ";
  $result = self::find_by_sql($sql);
//  echo $sql;
  return !empty($result) ? $result : false;
 }

 public function ra_report_set_onhand_by_subinventoryType() {
  $result_a = [];
  $result_a['ra_onhand_by_subinventoryType'] = $this->ra_onhand_by_subinventoryType();
  $result_a['ra_onhand_value_by_subinventoryType'] = $this->ra_onhand_value_by_subinventoryType();
  $result_a['ra_onhand_by_productLine'] = $this->ra_onhand_by_productLine();
  $result_a['ra_onhand_value_by_productLine'] = $this->ra_onhand_value_by_productLine();
  $result_a['ra_onhand_by_productLine_subinventoryType'] = $this->ra_onhand_by_productLine_subinventoryType();
  return $result_a;
 }

 public function ra_onhand_by_subinventoryType($limit_no = "5") {
  $sql = " SELECT subinventory_type, SUM(onhand) as 'Onhand'
				FROM ";
  $sql .= self::$table_name;
  $sql .= " GROUP BY subinventory_type ";
//  $sql .= " ORDER BY onhand desc ";
  $sql = ino_perPageSql_i($sql, $limit_no);
  $result = $this->findBySql($sql);
//	$ret_result = ra_conevrt_data_woarray($result, 'subinventory_type', $legend);
//	$settings = &$this->ra_onhand_by_subinventoryType_settings;
//	$settings['legend'] = $legend;
  return !empty($result) ? $result : false;
 }

 public function ra_onhand_value_by_subinventoryType() {
  $sql1 = " SELECT subinventory_type, SUM(onhand_value) as 'onhand_value'
				FROM ";
  $sql1 .= self::$table_name;
  $sql1 .= " GROUP BY subinventory_type ";
//  $sql1 .= " ORDER BY onhand_value desc ";
  $sql = ino_perPageSql_i($sql, 5);
  $result1 = $this->findBySql($sql1);
  return !empty($result1) ? $result1 : false;
 }

 public function ra_onhand_by_productLine($limit_no = "5") {
  $sql = " SELECT product_line, SUM(onhand) as 'Onhand' FROM ";
  $sql .= self::$table_name;
  $sql .= " GROUP BY product_line ";
//  $sql .= " ORDER BY onhand_value desc ";
  $sql = ino_perPageSql_i($sql, $limit_no);
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 public function ra_onhand_value_by_productLine($limit_no = "5") {
  $sql = " SELECT product_line, SUM(onhand_value) as 'Onhand Value' FROM ";
  $sql .= self::$table_name;
  $sql .= " GROUP BY product_line ";
//  $sql .= " ORDER BY onhand_value desc ";
  $sql = ino_perPageSql_i($sql, $limit_no);
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 public function ra_onhand_by_productLine_subinventoryType() {
  $legend = [];
  $sql = " SELECT  subinventory_type, product_line , SUM(onhand)
	  FROM onhand_v
		GROUP BY subinventory_type, product_line
		";
  $result = $this->findBySql($sql);
  $result_f = ra_conevrt_data_bar_column($result, $legend);
  $this->ra_onhand_by_productLine_subinventoryType_settings['_legend'] = $legend;
  return !empty($result_f) ? $result_f : false;
 }

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

//end of po_detail class
 onhand_v::staticVar_init('search_groupBy');
?>
