<?php

class onhand extends dbOraObject {

 public static $table_name = "onhand";
 protected static $view_name = "onhand_v";
 public static $primary_column = "SEGMENT1";
 public static $key_column = 'item_id';
 public static $module = "inv";
//  data base variables as stored database column name
 public $field_a = [
		 'SEGMENT1',
		 'DESCRIPTION',
		 'PRIMARY_TRANSACTION_QUANTITY',
		 'SUBINVENTORY_CODE',
		 'LOCATOR',
		 'LOCATOR_ID',
		 'INVENTORY_ITEM_ID',
 ];
 public $initial_search = [
		 'SEGMENT1',
		 'DESCRIPTION',
		 'SUBINVENTORY_CODE',
 ];
//variables used for showing data
 public $column = [
'SEGMENT1',
		 'DESCRIPTION',
		 'PRIMARY_TRANSACTION_QUANTITY',
		 'SUBINVENTORY_CODE',
		 'LOCATOR',
		 'LOCATOR_ID',
		 'INVENTORY_ITEM_ID',
 ];

  public $search_functions = [
		 'Organization' => 'search_org_name',
 ];

 public static $group_by = ["locator", "subInventory", "inventory"];
 public $SEGMENT1;
 public $DESCRIPTION;
 public $PRIMARY_TRANSACTION_QUANTITY;
 public $SUBINVENTORY_CODE;
 public $LOCATOR;
 public $LOCATOR_ID;
 public $INVENTORY_ITEM_ID;

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

 public function search_records($parameters = '') {
	$pageno = !empty($parameters['pageno']) ? $parameters['pageno'] : 1;
	$page_size = !empty($parameters['per_page']) ? $parameters['per_page'] : 10;
	$whereClause = $_GET['whereClause'];
	$search_order_by = !(empty($_GET['search_order_by'])) ? $_GET['search_order_by'] : '';
	$search_asc_desc = !(empty($_GET['search_asc_desc'])) ? $_GET['search_asc_desc'] : '';

	if ((!empty($search_order_by)) && (!empty($search_asc_desc))) {
	 if (is_array($search_order_by)) {
		$order_by = ' ORDER BY ';
		foreach ($search_order_by as $key_oby => $value_oby) {
		 if (empty($search_asc_desc[$key_oby])) {
			$search_asc_desc[$key_oby] = ' DESC ';
		 }
		 $order_by .= $value_oby . ' ' . $search_asc_desc[$key_oby] . ' ,';
		}
		$order_by_i = rtrim($order_by, ',');
	 } else {
		$order_by_i = ' ORDER BY ' . $search_order_by . ' ' . $search_asc_desc;
	 }
	}

	$sql = " 
	 SELECT * FROM (
	   SELECT tbl.*, rownum r 
		     FROM (
						 SELECT  msi.segment1, msi.DESCRIPTION, moqd.primary_transaction_quantity, moqd.transaction_uom_code,
						 moqd.subinventory_code, 
						 mil.SEGMENT1 || '.' || mil.SEGMENT2 || '.' || mil.SEGMENT3 || '.' || mil.SEGMENT4 as LOCATOR , 
						 moqd.locator_id,
						 moqd.inventory_item_id
						 FROM 
						 APPS.MTL_ONHAND_QUANTITIES_DETAIL moqd,
						 APPS.MTL_SYSTEM_ITEMS_B msi,
						 APPS.MTL_ITEM_LOCATIONS mil
						 WHERE 
						 msi.ORGANIZATION_ID = moqd.ORGANIZATION_ID
						 AND msi.inventory_item_id = moqd.inventory_item_id
						 AND mil.inventory_location_id(+) = moqd.locator_id ";
						if (!empty($whereClause)) {
						 $sql .= "	AND $whereClause";
						   }
						  $sql .= "$order_by_i
						 ) tbl
	 WHERE rownum < (($pageno * $page_size) + 1 )
	 )
	 WHERE r >= ((($pageno-1) * $page_size) + 1)
	 ";
echo "sql is $sql";
	$result = $this->findBy_sql($sql);
	return !empty($result) ? $result : false;
 }

 public function search_counts($sql = '') {
	$whereClause = $_GET['whereClause'];

	$sql = "
	 SELECT *
	 FROM (
	 SELECT msi.segment1, msi.DESCRIPTION, moqd.primary_transaction_quantity, moqd.transaction_uom_code,
	 moqd.subinventory_code,
	 mil.SEGMENT1 || '.' || mil.SEGMENT2 || '.' || mil.SEGMENT3 || '.' || mil.SEGMENT4 as LOCATOR,
	 moqd.locator_id,
	 moqd.inventory_item_id
	 FROM
	 APPS.MTL_ONHAND_QUANTITIES_DETAIL moqd,
	 APPS.MTL_SYSTEM_ITEMS_B msi,
	 APPS.MTL_ITEM_LOCATIONS mil
	 WHERE 
	 msi.ORGANIZATION_ID = moqd.ORGANIZATION_ID
	 AND msi.inventory_item_id = moqd.inventory_item_id
	 AND mil.inventory_location_id(+) = moqd.locator_id ";
							if (!empty($whereClause)) {
						 $sql .= "	AND $whereClause";
						   }
	 $sql .=")";
	$result = $this->findBySql($sql);
	return !empty($result) ? count($result) : false;
 }
 
  public function negative_onhand_records($parameters = '') {
	$pageno = !empty($parameters['pageno']) ? $parameters['pageno'] : 1;
	$page_size = !empty($parameters['per_page']) ? $parameters['per_page'] : 10;
	$whereClause = $_GET['whereClause'];
	$search_order_by = !(empty($_GET['search_order_by'])) ? $_GET['search_order_by'] : '';
	$search_asc_desc = !(empty($_GET['search_asc_desc'])) ? $_GET['search_asc_desc'] : '';

	if ((!empty($search_order_by)) && (!empty($search_asc_desc))) {
	 if (is_array($search_order_by)) {
		$order_by = ' ORDER BY ';
		foreach ($search_order_by as $key_oby => $value_oby) {
		 if (empty($search_asc_desc[$key_oby])) {
			$search_asc_desc[$key_oby] = ' DESC ';
		 }
		 $order_by .= $value_oby . ' ' . $search_asc_desc[$key_oby] . ' ,';
		}
		$order_by_i = rtrim($order_by, ',');
	 } else {
		$order_by_i = ' ORDER BY ' . $search_order_by . ' ' . $search_asc_desc;
	 }
	}

	$sql = " 
	 SELECT * FROM (
	   SELECT tbl.*, rownum r 
		     FROM (
						 SELECT  msi.segment1, msi.DESCRIPTION, moqd.primary_transaction_quantity, moqd.transaction_uom_code,
						 moqd.subinventory_code, 
						 mil.SEGMENT1 || '.' || mil.SEGMENT2 || '.' || mil.SEGMENT3 || '.' || mil.SEGMENT4 as LOCATOR , 
						 moqd.locator_id,
						 moqd.inventory_item_id
						 FROM 
						 APPS.MTL_ONHAND_QUANTITIES_DETAIL moqd,
						 APPS.MTL_SYSTEM_ITEMS_B msi,
						 APPS.MTL_ITEM_LOCATIONS mil
						 WHERE msi.ORGANIZATION_ID = moqd.ORGANIZATION_ID
						 AND msi.inventory_item_id = moqd.inventory_item_id
						 AND moqd.PRIMARY_TRANSACTION_QUANTITY < 0
						 AND mil.inventory_location_id(+) = moqd.locator_id ";
						if (!empty($whereClause)) {
						 $sql .= "	AND $whereClause";
						   }
						  $sql .= "$order_by_i
						 ) tbl
	 WHERE rownum < (($pageno * $page_size) + 1 )
	 )
	 WHERE r >= ((($pageno-1) * $page_size) + 1)
	 ";

	$result = $this->findBy_sql($sql);
	return !empty($result) ? $result : false;
 }

 public function negative_onhand_counts($sql = '') {
	$whereClause = $_GET['whereClause'];

	$sql = "
	 SELECT *
	 FROM (
	 SELECT msi.segment1, msi.DESCRIPTION, moqd.primary_transaction_quantity, moqd.transaction_uom_code,
	 moqd.subinventory_code,
	 mil.SEGMENT1 || '.' || mil.SEGMENT2 || '.' || mil.SEGMENT3 || '.' || mil.SEGMENT4 as LOCATOR,
	 moqd.locator_id,
	 moqd.inventory_item_id
	 FROM
	 APPS.MTL_ONHAND_QUANTITIES_DETAIL moqd,
	 APPS.MTL_SYSTEM_ITEMS_B msi,
	 APPS.MTL_ITEM_LOCATIONS mil
	 WHERE  msi.ORGANIZATION_ID = moqd.ORGANIZATION_ID
	 AND msi.inventory_item_id = moqd.inventory_item_id
	 AND moqd.PRIMARY_TRANSACTION_QUANTITY < 0
	 AND mil.inventory_location_id(+) = moqd.locator_id ";
							if (!empty($whereClause)) {
						 $sql .= "	AND $whereClause";
						   }
	 $sql .=")";
	$result = $this->findBySql($sql);
	return !empty($result) ? count($result) : false;
 }

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

 private function create_onhand_v() {
	$sql = "CREATE OR REPLACE VIEW onhand_v
	 (onhand_id, item_number, item_description, org_name, subinventory, locator,
	 uom_id, onhand, item_id, org_id, subinventory_id,
	 locator_id, lot_id, serial_id, reservable_onhand,
	 transactable_onhand, lot_status, serial_status,
	 secondary_uom_id, onhand_status, ef_id, created_by,
	 creation_date, last_update_by, last_update_date)
	 AS
	 SELECT onhand.onhand_id,
	 item.item_number, item.description, org.org, subinventory.subinventory, locator.locator,
	 onhand.uom_id, onhand.onhand,
	 onhand.item_id, onhand.org_id, onhand.subinventory_id,
	 onhand.locator_id, onhand.lot_id, onhand.serial_id, onhand.reservable_onhand,
	 onhand.transactable_onhand, onhand.lot_status, onhand.serial_status,
	 onhand.secondary_uom_id, onhand.onhand_status, onhand.ef_id, onhand.created_by,
	 onhand.creation_date, onhand.last_update_by, onhand.last_update_date

	 FROM onhand
	 LEFT JOIN item ON onhand.item_id = item.item_id
	 LEFT JOIN org ON onhand.org_id = org.org_id
	 LEFT JOIN subinventory ON onhand.subinventory_id = subinventory.subinventory_id
	 LEFT JOIN locator ON onhand.locator_id = locator.locator_id
	 ";
 }

 private function _validate_mandatory_fields() {
	if (empty($this->item_id)) {
	 echo "<br>Onhand Update Failed!Error @onhand - Item Id Missing" . __LINE__;
	 return -99;
	} else if (empty($this->_transaction_quantity)) {
	 echo "<br>Onhand Update Failed!Error @onhand - Transaction Quantity Missing" . __LINE__;
	 return -99;
	}
 }

 private function _update_from_onhand() {
	$from_onhand_sql = " SELECT * FROM onhand";
	$from_onhand_sql .= " WHERE item_id = '{$this->item_id}' ";
	$from_onhand_sql .= " AND org_id = '{$this->_from_org_id}' ";

	if (!empty($this->_from_subinventory_id)) {
	 $from_onhand_sql .= " AND subinventory_id = '{$this->_from_subinventory_id}' ";
	}
	if (!empty($this->_from_locator_id)) {
	 $from_onhand_sql .= " AND locator_id = '{$this->_from_locator_id}' ";
	}
	$from_onhand_sql .= " LIMIT 1 ";

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
	$this->org_id = $this->_from_org_id;
	$this->subinventory_id = $this->_from_subinventory_id;
	$this->locator_id = $this->_from_locator_id;

	try {
	 $this->audit_trial();
	 $this->save();
	 echo "<br>Onhand is Sucessfully Updated. The onhand Id is " . $this->onhand_id . ' & Onhand Value is ' . $this->onhand;
	 return 1;
	} catch (Exception $e) {
	 echo "<br>Onhand Update Failed <br> Line # " . __LINE__ . '<br>' . $e->getMessage();
	 return -99;
	}
 }

 private function _update_to_onhand() {
	$to_onhand_sql = " SELECT *  FROM onhand";
	$to_onhand_sql .= " WHERE item_id = '{$this->item_id}' ";
	$to_onhand_sql .= " AND  	org_id = '{$this->_to_org_id}' ";

	if (!empty($this->_to_subinventory_id)) {
	 $to_onhand_sql .= " AND  	subinventory_id = '{$this->_to_subinventory_id}' ";
	}
	if (!empty($this->_to_locator_id)) {
	 $to_onhand_sql .= " AND  	locator_id = '{$this->_to_locator_id}' ";
	}
	$to_onhand_sql .= " LIMIT 1 ";

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
	 echo "<br>Onhand is Sucessfully Updated. The onhand Id is " . $this->onhand_id . ' & Onhand Value is ' . $this->onhand;
	 return 1;
	} catch (Exception $e) {
	 echo "<br>Onhand Update Failed <br> Line # " . __LINE__ . '<br>' . $e->getMessage();
	 return -99;
	}
 }

 public function updateOnhand() {
//verify all the mandatory fields exists
	$mandatory_fields = $this->_validate_mandatory_fields();
	if ($mandatory_fields < 0) {
	 echo "<br>Mandatort fields are missing <br> Line # : " . __LINE__;
	 return -99;
	}

	//from org transaction update
	if (!empty($this->_from_org_id)) {
	 try {
		$this->_update_from_onhand();
//		return 1;
	 } catch (Exception $e) {
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

 public function findOnhand_byItemId($item_id = '') {
	if (!empty($item_id)) {
	 $this->item_id = $item_id;
	}
	$sql = " SELECT * FROM  ";
	$sql .= self::$table_name;
	$sql .= " WHERE item_id =:item_id ";

	$param_a = ['item_id'];
	$value_a = ['item_id' => $this->item_id];
	$result = $this->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? $result : false;
 }

}

//end of onhand class
?>