<?php

class po_open_orders extends dbOraObject {

 public static $table_name = "po_open_orders";
 public static $primary_column = "po_open_orders_id";
 public $field_a = [
		 'PO_HEADER_ID',
		 'PO_LINE_ID',
		 'PO_NUMBER',
		 'LINE_NUM',
		 'VENDOR_NAME',
		 'QUANTITY',
		 'QUANTITY_RECEIVED',
		 'REMAINING_QTY',
		 'NEED_BY_DATE',
		 'SHIP_TO_ORGANIZATION_ID',
		 'ITEM_ID',
		 'ITEM_DESCRIPTION',
		 'UNIT_PRICE',
		 'CLOSED_DATE',
		 'CANCEL_FLAG',
		 'VENDOR_ID',
		 'VENDOR_SITE_ID',
 ];
 public $initial_search = [
		 'PO_NUMBER',
		 'LINE_NUM',
		 'VENDOR_NAME',
		 'REMAINING_QTY',
		 'NEED_BY_DATE',
		 'ITEM_DESCRIPTION',
 ];
 public $column = [
		 'PO_NUMBER',
		 'LINE_NUM',
		 'VENDOR_NAME',
		 'QUANTITY',
		 'QUANTITY_RECEIVED',
		 'REMAINING_QTY',
		 'NEED_BY_DATE',
		 'SHIP_TO_ORGANIZATION_ID',
		 'ITEM_ID',
		 'ITEM_DESCRIPTION',
 ];
 public $po_open_orders_id;
 public $PO_HEADER_ID;
 public $PO_LINE_ID;
 public $PO_NUMBER;
 public $LINE_NUM;
 public $VENDOR_NAME;
 public $QUANTITY;
 public $QUANTITY_RECEIVED;
 public $REMAINING_QTY;
 public $NEED_BY_DATE;
 public $SHIP_TO_ORGANIZATION_ID;
 public $ITEM_ID;
 public $ITEM_DESCRIPTION;
 public $UNIT_PRICE;
 public $CLOSED_DATE;
 public $CANCEL_FLAG;
 public $VENDOR_ID;
 public $VENDOR_SITE_ID;

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
           SELECT DISTINCT(concat(pla.po_line_id, pll.line_location_id)) uniq_id,
					 pha.po_header_id po_header_id, pla.po_line_id po_line_id,
					 pha.segment1 as po_number, pla.line_num line_num, pv.vendor_name vendor_name,
					 pll.quantity quantity, pll.quantity_received quantity_received,
					 (pll.quantity - pll.quantity_received) as remaining_qty,
					 pll.need_by_date need_by_date, pll.ship_to_organization_id ship_to_organization_id,
					 pla.item_id item_id,pla.item_description item_description,pla.quantity line_quantity,
					 pla.unit_price unit_price,  pha.closed_date header_closed_date, 
					 pla.closed_date line_closed_date, pha.cancel_flag header_cancel_flag,  
					 pla.cancel_flag line_cancel_flag, pha.vendor_id VENDOR_ID, pha.vendor_site_id vendor_site_id
			
					 FROM 
					 apps.PO_HEADERS_ALL pha,
					 apps.PO_LINES_ALL pla,
					 apps.PO_LINE_LOCATIONS_ALL pll,
					 apps.mtl_system_items_b msi,
					 apps.PO_VENDORS pv

					 WHERE pha.org_id= '2965'
					 AND pla.po_header_id = pha.po_header_id
					 AND pll.po_header_id = pha.po_header_id
					 AND pll.po_line_id = pla.po_line_id
					 AND pla.closed_date IS NULL
					 AND pla.cancel_flag IS NULL 
					 AND msi.inventory_item_id(+) = pla.item_id
					 AND pv.vendor_id = pha.vendor_id";
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
           SELECT DISTINCT(concat(pla.po_line_id, pll.line_location_id)) uniq_id,
					 pha.po_header_id po_header_id, pla.po_line_id po_line_id,
					 pha.segment1 as po_number, pla.line_num line_num, pv.vendor_name vendor_name,
					 pll.quantity quantity, pll.quantity_received quantity_received,
					 (pll.quantity - pll.quantity_received) as remaining_qty,
					 pll.need_by_date need_by_date, pll.ship_to_organization_id ship_to_organization_id,
					 pla.item_id item_id,pla.item_description item_description,pla.quantity line_quantity,
					 pla.unit_price unit_price,  pha.closed_date header_closed_date, 
					 pla.closed_date line_closed_date, pha.cancel_flag header_cancel_flag,  
					 pla.cancel_flag line_cancel_flag, pha.vendor_id vendor_id, pha.vendor_site_id vendor_site_id
			
					 FROM 
					 apps.PO_HEADERS_ALL pha,
					 apps.PO_LINES_ALL pla,
					 apps.PO_LINE_LOCATIONS_ALL pll,
					 apps.mtl_system_items_b msi,
					 apps.PO_VENDORS pv

					 WHERE pha.org_id= '2965'
					 AND pla.po_header_id = pha.po_header_id
					 AND pll.po_header_id = pha.po_header_id
					 AND pll.po_line_id = pla.po_line_id
					 AND pla.closed_date IS NULL
					 AND pla.cancel_flag IS NULL 
					 AND msi.inventory_item_id(+) = pla.item_id
					 AND pv.vendor_id = pha.vendor_id";
					 if (!empty($whereClause)) {
						$sql .= "	AND $whereClause";
					 }
	$sql .= ")";
	$result = $this->findBySql($sql);
	return !empty($result) ? count($result) : false;
 }

}

//end of po_open_orders class
?>