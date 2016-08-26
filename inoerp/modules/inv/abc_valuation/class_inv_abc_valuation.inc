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
 * inv_abc_valuation
 * ABC Valuation is used to classify all the inventory items
 * Contains all the inv_abc_valuation information, such as - valuation_name, description ,  scope_org_id, etc.
 * 
 */
class inv_abc_valuation extends dbObject {

 public static $table_name = "inv_abc_valuation";
 public static $primary_column = "inv_abc_valuation_id";
 public static $dependent_classes = ['inv_abc_valuation_result'];
 public static $key_column = 'valuation_name';
 public static $module = "inv";
 public static $js_fileName_prg = 'modules/inv/abc_valuation/js/abc_valuation_extra.js';
 public static $system_info = [
  'name' => 'ABC Valuation',
  'number' => '2102',
  'description' => 'Inventory ABC Valuation',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('inv_abc_valuation_result'),
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 2
 ];
 public static $template_type = [
  'header_tab' => 1,
  'line_tab' => 2,
  'nooffields_header_tab1' => 5,
  'nooffields_line_tab1' => 6,
  'nooffields_line_tab2' => 6,
 ];
 public $field_a = [
  'inv_abc_valuation_id',
  'valuation_name',
  'scope_org_id',
  'scope_sub_inventory_id',
  'scope_org_hirearchy_id',
  'description',
  'scope_product_line',
  'criteria',
  'cost_type',
  'fp_forecast_header_id',
  'fp_mrp_header_id',
  'from_date',
  'to_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $dateFields = [
  'from_date',
  'to_date',
 ];
 public $initial_search = [
  'scope_org_id',
  'inv_abc_valuation_id',
  'valuation_name',
 ];
 public $column = [
  'inv_abc_valuation_id',
  'valuation_name',
  'scope_org_id',
  'scope_sub_inventory_id',
  'scope_org_hirearchy_id',
  'description',
 ];
 public $fields_inForm_notInDataBase = [
  'org',
  'subinventory',
 ];
 public $requiredField = [
  'valuation_name',
  'criteria',
 ];
 public $prg_abc_valuation_parameters = [
  'ABC Valuation Name' => 'search_abc_valuation_name',
  'Organization' => 'search_org_name',
 ];
 public $prg_abc_valuation_details = [
  'name' => 'ABC Valuation',
  'description' => 'New ABC Valuation',
 ];
 public $inv_abc_valuation_id;
 public $valuation_name;
 public $scope_org_id;
 public $scope_sub_inventory_id;
 public $scope_org_hirearchy_id;
 public $description;
 public $scope_product_line;
 public $criteria;
 public $cost_type;
 public $fp_forecast_header_id;
 public $fp_mrp_header_id;
 public $from_date;
 public $to_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " ABC Valuation ";
 public $message;

 Public static function abc_criteria() {
  $option_header = option_header::find_by_name('INV_ABC_CRITERIA');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 public static function find_by_valuationName_OrgId($valuation_name, $org_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE scope_org_id = '{$org_id}'  "
   . " AND valuation_name = '{$valuation_name}' AND status='active'  ";
   $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_valuationName_OrgId($valuation_name = '', $org_id = '') {
  $org_id = empty($org_id) ? $this->scope_org_id : $org_id;
  $valuation_name = empty($valuation_name) ? $this->valuation_name : $valuation_name;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE scope_org_id = '{$org_id}' AND"
   . " valuation_name = '{$valuation_name}' AND status='active'    ";
$sql = ino_perPageSql_i($sql, 1);
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 private function _create_abc_result($result_from_abc_valuation, $value_key, $qty_key = null) {
  $abc_result = new inv_abc_valuation_result();
  $abc_result->inv_abc_valuation_id = $this->inv_abc_valuation_id;
  $abc_result_i = $abc_result->findBy_parentId($this->inv_abc_valuation_id);
  if (!empty($abc_result_i)) {
   $abc_result->deleteBy_parentId($this->inv_abc_valuation_id);
  }
  $seq = 0;
  $cum_qty = 0;
  $cum_value = 0;
  foreach ($result_from_abc_valuation as $key => $data) {
   $seq++;
   $abc_result->inv_abc_valuation_result_id = null;
   $abc_result->seq_number = $seq;
   $abc_result->item_id_m = $data->item_id_m;
   $abc_result->quantity = !empty($qty_key) ? $data->$qty_key : null;
   $cum_qty += $abc_result->quantity;
   $abc_result->value = $data->$value_key;
   $cum_value += $abc_result->value;
   $abc_result->cum_quantity = $cum_qty;
   $abc_result->cum_value = $cum_value;
   $abc_result->audit_trial();
   $abc_result->save();
  }

  /* insert all the others items in the org
   * 1. First find all the items already inserted
   * 2. All the other items except those selected in 1
   */
  $inster_items_sql = " SELECT DISTINCT(item_id_m) FROM inv_abc_valuation_result ";
  $inster_items_sql .= " WHERE inv_abc_valuation_id = '{$this->inv_abc_valuation_id}' ";
  $inster_items_result = $this->findBySql($inster_items_sql);
  if (empty($inster_items_result)) {
   $this->message .= "<br> No items inserted to result . Error @class_inv_valuation_result @@ " . __LINE__;
   return;
  }
  $item_id_m = array_map(function($obj) {
   return $obj->item_id_m;
  }, $inster_items_result);

  $item_sql = " SELECT * FROM item ";
  $item_sql .= " WHERE org_id = '{$this->scope_org_id}' ";
  $item_sql .= " AND  item_id_m NOT IN ( " . "'" . implode("','", $item_id_m) . "' )";
  $item_result = $this->findBySql($item_sql);
  if (empty($item_result)) {
   return;
  }
  foreach ($item_result as $item) {
   $seq++;
   $abc_result->inv_abc_valuation_result_id = null;
   $abc_result->seq_number = $seq;
   $abc_result->item_id_m = $item->item_id_m;
   $abc_result->quantity = 0;
   $cum_qty += $abc_result->quantity;
   $abc_result->value = 0;
   $cum_value += $abc_result->value;
   $abc_result->cum_quantity = $cum_qty;
   $abc_result->cum_value = $cum_value;
   $abc_result->audit_trial();
   $abc_result->save();
  }
 }

 private function _abc_valuation_by_onhand_qty() {
  $this->message .= "<br> in _abc_valuation_by_onhand_qty";
//	foreach ($this->field_a as $key => $val) {
//	 $this->message .='<br>' . $val . ' - ' . $this->$val;
//	}
  /*
   * 1. Get all the items from onhand_v order by onhand value
   */
  $sql = " SELECT item_id_m, SUM(onhand) as onhand_sum FROM onhand_v ";
  if (!empty($this->scope_org_id)) {
   $sql .= " WHERE org_id = '{$this->scope_org_id}' ";
  } else {
   throw new Exception('<br>No org /hierrahcy id found!');
  }
  if (!empty($this->scope_sub_inventory_id)) {
   $sql .= " AND subinventory_id = '{$this->scope_sub_inventory_id}' ";
  }
  if (!empty($this->scope_product_line)) {
   $sql .= " AND product_line = '{$this->scope_product_line}' ";
  }
  $sql .= " GROUP BY item_id_m ";
  $sql .= " ORDER BY onhand_sum DESC ";

  $result = $this->findBySql($sql);
  $this->_create_abc_result($result, 'onhand_sum', 'onhand_sum');
 }

 private function _abc_valuation_by_onhand_value() {
  $this->message .= "<br> in _abc_valuation_by_onhand_value";

  /*
   * 1. Get all the items from onhand_v order by onhand value
   */
  $sql = " SELECT item_id_m, SUM(onhand) as onhand_sum , SUM(onhand_value) as onhand_value_sum FROM onhand_v ";
  if (!empty($this->scope_org_id)) {
   $sql .= " WHERE org_id = '{$this->scope_org_id}' ";
  } else {
   throw new Exception('<br>No org /hierrahcy id found!');
  }
  if (!empty($this->scope_sub_inventory_id)) {
   $sql .= " AND subinventory_id = '{$this->scope_sub_inventory_id}' ";
  }
  if (!empty($this->scope_product_line)) {
   $sql .= " AND product_line = '{$this->scope_product_line}' ";
  }
  $sql .= " GROUP BY item_id_m ";
  $sql .= " ORDER BY onhand_value_sum DESC ";

  $result = $this->findBySql($sql);
  $this->_create_abc_result($result, 'onhand_value_sum', 'onhand_sum');
 }

 private function _abc_valuation_by_standard_cost() {
  $this->message .= "<br> in _abc_valuation_by_standard_cost";

  /*
   * 1. Get all the items from cst_item_cost_v order by cost
   */
  $sql = " SELECT item_id_m, standard_cost FROM cst_item_cost_v ";
  if (!empty($this->scope_org_id)) {
   $sql .= " WHERE org_id = '{$this->scope_org_id}' ";
  } else {
   throw new Exception('<br>No org /hierrahcy id found!');
  }
  if (!empty($this->cost_type)) {
   $sql .= " AND  bom_cost_type = '{$this->cost_type}' ";
  } else {
   $sql .= " AND  bom_cost_type = 'FROZEN' ";
  }
  $sql .= " ORDER BY standard_cost DESC ";

  $result = $this->findBySql($sql);
  $this->_create_abc_result($result, 'standard_cost');
 }

 private function _abc_valuation_by_mrp_demand_qty() {
  $this->message .= "<br> in _abc_valuation_by_mrp_demand_qty";
  /*
   * 1. Get all the items from onhand_v order by onhand value
   */
  $sql = " SELECT item_id_m, SUM(quantity) as onhand_sum FROM fp_mrp_demand_v ";
  if (!empty($this->scope_org_id)) {
   $sql .= " WHERE org_id = '{$this->scope_org_id}' ";
   $sql .= " AND fp_mrp_header_id = '{$this->fp_mrp_header_id}' ";
  } else {
   throw new Exception('<br>No org /hierrahcy /MRP id found!');
  }
  if (!empty($this->scope_product_line)) {
   $sql .= " AND product_line = '{$this->scope_product_line}' ";
  }
  $sql .= " GROUP BY item_id_m ";
  $sql .= " ORDER BY onhand_sum DESC ";

  $result = $this->findBySql($sql);
  $this->_create_abc_result($result, 'onhand_sum', 'onhand_sum');
 }

 private function _abc_valuation_by_mrp_demand_value() {
  $this->message .= "<br> in _abc_valuation_by_mrp_demand_value";

  /*
   * 1. Get all the items from onhand_v order by onhand value
   */
  $sql = " SELECT item_id_m, SUM(quantity) as onhand_sum , "
   . " SUM(quantity)*IFNULL(standard_cost, 0) as onhand_value_sum FROM fp_mrp_demand_v ";
  if (!empty($this->scope_org_id)) {
   $sql .= " WHERE org_id = '{$this->scope_org_id}' ";
  } else {
   throw new Exception('<br>No org /hierrahcy id found!');
  }
  if (!empty($this->scope_product_line)) {
   $sql .= " AND product_line = '{$this->scope_product_line}' ";
  }
  $sql .= " GROUP BY item_id_m ";
  $sql .= " ORDER BY onhand_value_sum DESC ";

  $result = $this->findBySql($sql);
  $this->_create_abc_result($result, 'onhand_value_sum', 'onhand_sum');
 }

 private function _abc_valuation_by_mbmm_max_qty() {
  $this->message .= "<br> in _abc_valuation_by_mbmm_max_qty";

  $sql = " SELECT item_id_m, SUM(minmax_max_quantity) as onhand_sum FROM item ";
  if (!empty($this->scope_org_id)) {
   $sql .= " WHERE org_id = '{$this->scope_org_id}' ";
  } else {
   throw new Exception('<br>No org /hierrahcy id found!');
  }
  if (!empty($this->scope_product_line)) {
   $sql .= " AND product_line = '{$this->scope_product_line}' ";
  }
  $sql .= " GROUP BY item_id_m ";
  $sql .= " ORDER BY onhand_sum DESC ";

  $result = $this->findBySql($sql);
  $this->_create_abc_result($result, 'onhand_sum', 'onhand_sum');
 }

 private function _abc_valuation_by_mbmm_max_value() {
  $this->message .= "<br> in _abc_valuation_by_mrp_demand_value";

  /*
   * 1. Get all the items from onhand_v order by onhand value
   */
  $sql = " SELECT item.item_id_m as item_id_m, SUM(item.minmax_max_quantity) as onhand_sum , 
					 SUM(item.minmax_max_quantity)*IFNULL(cic.standard_cost, 0) as onhand_value_sum 
					 FROM item 
					 LEFT JOIN cst_item_cost_v cic ON cic.item_id_m = item.item_id_m AND item.org_id = cic.org_id
					 AND  cic.BOM_COST_TYPE = 'FROZEN' ";
  if (!empty($this->scope_org_id)) {
   $sql .= " WHERE item.org_id = '{$this->scope_org_id}' ";
  } else {
   throw new Exception('<br>No org /hierrahcy id found!');
  }
  if (!empty($this->scope_product_line)) {
   $sql .= " AND item.product_line = '{$this->scope_product_line}' ";
  }
  $sql .= " GROUP BY item.item_id_m ";
  $sql .= " ORDER BY onhand_value_sum DESC ";
  $result = $this->findBySql($sql);
  $this->_create_abc_result($result, 'onhand_value_sum', 'onhand_sum');
 }

 private function _do_abc_valuation() {
//	$inv_abc_val = new inv_abc_valuation();
  $this->findBy_id($this->inv_abc_valuation_id);
  switch ($this->criteria) {
   case 'ONHAND_QTY':
    $this->_abc_valuation_by_onhand_qty();
    break;

   case 'ONHAND_VALUE':
    $this->_abc_valuation_by_onhand_value();
    break;

   case 'STD_COST':
    $this->_abc_valuation_by_standard_cost();
    break;

   case 'MRP_DEMAND_QTY':
    $this->_abc_valuation_by_mrp_demand_qty();
    break;

   case 'MRP_DEMAND_VALUE':
    $this->_abc_valuation_by_mrp_demand_value();
    break;

   case 'MBMM_MAX_QTY':
    $this->_abc_valuation_by_mbmm_max_qty();
    break;

   case 'MBMM_MAX_VALUE':
    $this->_abc_valuation_by_mbmm_max_value();

    break;
  }
 }

 public function prg_abc_valuation($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message .= '<br> Staring ABC valuation program';

//	foreach ($parameters as $key => $val) {
//	 $this->message .='<br>' . $key . ' - ' . implode(' ; <br>', $val);
//	}
  if (!empty($parameters['inv_abc_valuation_id'][0])) {
   $inv_abc_valuation_id = $this->inv_abc_valuation_id = $parameters['inv_abc_valuation_id'][0];
   $this->message .= '<br> Entered inv_abc_valuation_id is : ' . $inv_abc_valuation_id;
  } else {
   $this->message .= '<br> No inv_abc_valuation_id found. Searhcing for valuation_name & org_id ' . __LINE__;
   if (!empty($parameters['org_id'][0])) {
    $this->scope_org_id = $org_id = $parameters['org_id'][0];
    $this->message .= '<br> Entered Org Id is : ' . $org_id;
   } else {
    $this->message .= '<br> Error! : No org id found @ class_inv_abc_valuation ' . __LINE__;
    return $this->message;
   }

   if (!empty($parameters['valuation_name'][0])) {
    $this->valuation_name = $valuation_name = $parameters['valuation_name'][0];
    $this->message .= '<br> Entered Valuation Name is : ' . $valuation_name;
   } else {
    $this->message .= '<br> Error! : No valuation name found @ class_inv_abc_valuation ' . __LINE__;
    return $this->message;
   }
   $abc_val = $this->findBy_valuationName_OrgId();
   $inv_abc_valuation_id = $this->inv_abc_valuation_id = $abc_val->inv_abc_valuation_id;
  }

  if (!empty($this->inv_abc_valuation_id)) {
   $this->message .= "<br>Using ABC valuation by  inv_abc_valuation_id  " . $this->inv_abc_valuation_id;
   try {
    $this->_do_abc_valuation();
    $this->message .= "<br>ABC Valuation is Successfullycompleted";
   } catch (Exception $e) {
    $this->message .= "<br>ABC Valuation failed!" . $e->getMessage();
   }
  }
  return $this->message;
 }

}

//end of inv_abc_valuation class
?>