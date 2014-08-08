<?php

class actual_production extends dbOraObject {

 public static $table_name = "actual_production";
 public static $primary_column = "PLANNER_CODE";
 public $field_a = [
		 'ITEM_NUMBER',
		 'DESCRIPTION',
		 'TRANSACTION_DATE',
		 'QUANTITY',
		 'USER_NAME',
		 'PLANNER_CODE',
 ];
 public $initial_search = [
		 'ITEM_NUMBER',
		 'DESCRIPTION',
		 'TRANSACTION_DATE',
		 'USER_NAME',
		 'PLANNER_CODE'
 ];
 public $column = [
		 'ITEM_NUMBER',
		 'DESCRIPTION',
		 'TRANSACTION_DATE',
		 'QUANTITY',
		 'USER_NAME',
		 ];
 public $search_functions = [
		 'Organization' => 'search_org_name',
		 'Planner Code' => 'search_planner_code',
 ];
 public $ITEM_NUMBER;
 public $DESCRIPTION;
 public $TRANSACTION_DATE;
 public $QUANTITY;
 public $USER_NAME;
 public $PLANNER_CODE;


 public function __set($name, $value) {
	switch ($value) {
	 case $value:


		break;

	 default:
		$this->$name = $value;
		break;
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
					    SELECT  
msi.SEGMENT1 as ITEM_NUMBER, msi.DESCRIPTION,  mmt.TRANSACTION_DATE ,  (mmt.PRIMARY_QUANTITY) as Quantity, fu.user_name,
msi.planner_code
from 
apps.MTL_MATERIAL_TRANSACTIONS mmt,
apps.mtl_system_items_b msi,
apps.FND_USER fu
where mmt.organization_id = 2989
and fu.user_id = mmt.created_by
and mmt.TRANSACTION_TYPE_ID = 44
and mmt.organization_id = msi.organization_id
and mmt.inventory_item_id = msi.inventory_item_id
AND msi.ITEM_TYPE = 'FG'
AND TRANSACTION_DATE > '01-JAN-2013'
					 
";
	if (!empty($whereClause)) {
	 $sql .= "	AND $whereClause";
	}
	$sql .= " $order_by_i
						 ) tbl
					 WHERE rownum < (($pageno * $page_size) + 1 )
	)
	WHERE r >= ((($pageno-1) * $page_size) + 1)
";

	$result = $this->findBy_sql($sql);
	return !empty($result) ? $result : false;
 }

 public function search_counts($sql = '') {
	$whereClause = $_GET['whereClause'];

	$sql = " 
	 SELECT * 
		     FROM (
         SELECT  
msi.SEGMENT1 as ITEM_NUMBER, msi.DESCRIPTION,  mmt.TRANSACTION_DATE ,  (mmt.PRIMARY_QUANTITY) as Quantity, fu.user_name,
msi.planner_code
from 
apps.MTL_MATERIAL_TRANSACTIONS mmt,
apps.mtl_system_items_b msi,
apps.FND_USER fu
where mmt.organization_id = 2989
and fu.user_id = mmt.created_by
and mmt.TRANSACTION_TYPE_ID = 44
and mmt.organization_id = msi.organization_id
and mmt.inventory_item_id = msi.inventory_item_id
AND msi.ITEM_TYPE = 'FG'
AND TRANSACTION_DATE > '01-JAN-2013'

";
	if (!empty($whereClause)) {
	 $sql .= "	AND $whereClause";
	}
	$sql .= ")";
	$result = $this->findBySql($sql);
	return !empty($result) ? count($result) : false;
 }

 public function search_download() {
	$whereClause = $_GET['whereClause'];

	$sql = " 
	 SELECT * 
		     FROM (
         
SELECT  
msi.SEGMENT1 as ITEM_NUMBER, msi.DESCRIPTION,  mmt.TRANSACTION_DATE ,  (mmt.PRIMARY_QUANTITY) as Quantity, fu.user_name,
msi.planner_code
from 
apps.MTL_MATERIAL_TRANSACTIONS mmt,
apps.mtl_system_items_b msi,
apps.FND_USER fu
where mmt.organization_id = 2989
and fu.user_id = mmt.created_by
and mmt.TRANSACTION_TYPE_ID = 44
and mmt.organization_id = msi.organization_id
and mmt.inventory_item_id = msi.inventory_item_id
AND msi.ITEM_TYPE = 'FG'
AND TRANSACTION_DATE > '01-JAN-2013'

";
	if (!empty($whereClause)) {
	 $sql .= "	AND $whereClause";
	}
	$sql .= ")";

	$result = $this->findBySql($sql);
	return !empty($result) ? $result : false;
 }

}

//end of actual_production class
?>