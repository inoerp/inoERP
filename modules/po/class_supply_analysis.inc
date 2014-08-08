<?php

class bom extends dbOraObject {

 public static $table_name = "bom";
 public static $primary_column = "bom_id";
 public $field_a = [
		 'PLANNER_CODE',
		 'ORGANIZATION_ID'
 ];
 public $initial_search = [
 ];
 public $column = [
		 'PLANNER_CODE'
 ];
 public $super_bom_parameters = [
		 'Organization' => 'search_org_name',
		 'Planner Code' => 'search_planner_code',
		 'Item Number From' => 'search_item_number_from',
		 'Item Number To' => 'search_item_number_to',
 ];
 public $super_bom_details = [
		 'name' => 'Generate Super BOM',
		 'description' => 'Roll up cost for pending or user defiled cost types',
 ];
 public $bom_id;
 public $PLANNER_CODE;
 public $ORGANIZATION_ID;

 public function __set($name, $value) {
	switch ($value) {
	 case $value:


		break;

	 default:
		$this->$name = $value;
		break;
	}
 }

 public function getBOM($item_id, $org_id = '2989', $usage = '1') {
	global $dbOra;
	$sql = "
	SELECT DISTINCT( bbc.bill_item_name || '|' || bbc.component_item_name ),
 bbc.bill_item_name as Assembly, msi.description as Parent_Description,
msi.ITEM_TYPE Parent_Item_Type, msi.PLANNER_CODE Parent_Planner_code,
bbc.component_item_id Component_Item_Id,bbc.component_item_name as Component_Number,
msi_c.description as Description , bbc.quantity_per_assembly*$usage as Quantity, 
msi_c.item_type, msi_c.planner_code, bbc.organization_code,
 bbc.organization_id, bbc.assembly_item_id
from apps.bomfg_bom_components  bbc,
apps.mtl_system_items_b msi,
apps.mtl_system_items_b msi_c
where bbc.organization_id = 63
and bbc.assembly_item_id = '{$item_id}'
AND bbc.end_effective_date IS NULL
and msi_c.inventory_item_id = bbc.component_item_id
and msi_c.organization_id = '{$org_id}'
and msi.organization_id = '{$org_id}'
and msi.inventory_item_id = bbc.assembly_item_id
";
	$result = $dbOra->findBySql($sql);
	return $result;
 }

 public function indentedBOM($item_id, $org_id, &$ib, $usage = 1, $assembly_number = '') {
	$ib_i = $this->getBOM($item_id, $org_id, $usage);
	foreach ($ib_i as $records) {
	 if (!empty($assembly_number)) {
		$records->ASSEMBLY = $assembly_number;
	 }
	 array_push($ib, $records);
	 if ($records->ITEM_TYPE == 'SA' || $records->ITEM_TYPE == 'PF' ||
					 $records->ITEM_TYPE == 'PH' || $records->ITEM_TYPE == 'FG') {
		$this->indentedBOM($records->COMPONENT_ITEM_ID, $org_id, $ib, $records->QUANTITY, $records->ASSEMBLY);
	 }
	}
 }

 public function all_items_for_IB($planner_code, $org_id = 2989) {
	global $dbOra;
	$sql = "
SELECT DISTINCT(segment1), inventory_item_id
from apps.mtl_system_items_b
WHERE PLANNER_CODE = '{$planner_code}'
AND organization_id = '{$org_id}'
AND ITEM_TYPE IN('FG') 
";
	$result = $dbOra->findBySql($sql);
	return $result;
 }

 public function superBOM($planner_code, $org_id) {
	$ib_final = [];
	$all_items = $this->all_items_for_IB($planner_code, $org_id);
	foreach ($all_items as $items) {
	 $ib = [];
	 $this->indentedBOM($items->INVENTORY_ITEM_ID, $org_id, $ib, 1, $items->SEGMENT1);
	 $ib_final = array_merge($ib, $ib_final);
	}
	return $ib_final;
 }

 public function super_bom($parameters) {
	global $dbOra;
	$organization_id = !empty($parameters['ORGANIZATION_ID']) ? $parameters['ORGANIZATION_ID'] : false;
	$planner_code = !empty($parameters['PLANNER_CODE']) ? $parameters['PLANNER_CODE'] : false;
	$result = $this->superBOM($planner_code, $organization_id);
	$superBom_a = [];

	$row_fgi = ['Component', 'Description', 'Type', 'Planner'];
	$row_fgi_assembly_only = [];
	foreach ($result as $data) {
	 if (($data->PARENT_ITEM_TYPE == 'FG') && (!(in_array($data->ASSEMBLY, $row_fgi_assembly_only)))) {
		array_push($row_fgi_assembly_only, $data->ASSEMBLY);
	 }
	}
	$row_fgi = array_merge($row_fgi, $row_fgi_assembly_only);
	array_push($superBom_a, $row_fgi);

	/* FGI Description */
	$row_fgi_d = [];
	$count = 0;
	for ($i = 0; $i <= 3; $i++) {
	 array_push($row_fgi_d, null);
	 $count++;
	}

	$total_item = count($row_fgi);
	foreach ($result as $data) {
	 if (($data->PARENT_ITEM_TYPE == 'FG') && (in_array($data->ASSEMBLY, $row_fgi_assembly_only) && ($count < $total_item) )) {
		$count ++;
		array_push($row_fgi_d, $data->PARENT_DESCRIPTION);
	 }
	}
	array_push($superBom_a, $row_fgi_d);

	/* Data */
	$row_data_component = [];
	$i = 0;
	foreach ($result as $data_c) {
	 $row_data = [];

	 if ($data_c->ITEM_TYPE != 'FG') {
		$row_data = [];
		$key = array_search($data_c->COMPONENT_NUMBER, $row_data_component);
		if ($key) {
		 $com_number = $row_data_component[$key];
		 array_push($row_data, $data_c->COMPONENT_NUMBER);
		 array_push($row_data, $data_c->DESCRIPTION);
		 array_push($row_data, $data_c->ITEM_TYPE);
		 array_push($row_data, $data_c->PLANNER_CODE);
		 $element_num = 3;
		 foreach ($row_fgi_assembly_only as $key => $val) {
			$element_num ++;
			if ($val == $data_c->ASSEMBLY) {
			 array_push($row_data, $data_c->QUANTITY + $superBom_a[$com_number][$element_num]);
			} else {
			 array_push($row_data, $superBom_a[$com_number][$element_num]);
			}
		 }
		 unset($superBom_a[$com_number]);
		} else {
		 array_push($row_data_component, $data_c->COMPONENT_NUMBER);
		 array_push($row_data, $data_c->COMPONENT_NUMBER);
		 array_push($row_data, $data_c->DESCRIPTION);
		 array_push($row_data, $data_c->ITEM_TYPE);
		 array_push($row_data, $data_c->PLANNER_CODE);
		 foreach ($row_fgi_assembly_only as $key => $val) {
			if ($val == $data_c->ASSEMBLY) {
			 array_push($row_data, $data_c->QUANTITY);
			} else {
			 array_push($row_data, null);
			}
		 }
		}

		$superBom_a[$data_c->COMPONENT_NUMBER] = $row_data;
	 }
	}
	return $superBom_a;
 }

 public function xx_super_bom($parameters) {
	global $dbOra;
	$organization_id = !empty($parameters['ORGANIZATION_ID']) ? $parameters['ORGANIZATION_ID'] : false;
	$planner_code = !empty($parameters['PLANNER_CODE']) ? $parameters['PLANNER_CODE'] : false;
	$sql = "
select  DISTINCT(CONCAT(bic.component_item_id, LEVEL)),CONNECT_BY_ROOT msi_p.segment1 Assembly, msi_p.description Parent_Description,
 msi_p.ITEM_TYPE Parent_Item_Type, msi_p.PLANNER_CODE Parent_Planner_code, msi_p.segment1 Immediate_Assembly, 
 bic.component_item_id Component_Item_Id , msi.segment1 Component_Number, msi.description Description, bic.component_quantity Quantity,
 msi.ITEM_TYPE , msi.PLANNER_CODE ,
 LEVEL
from apps.bom_bill_of_materials_v bom, 
apps.bom_inventory_components_v bic, 
apps.mtl_system_items msi,
apps.mtl_system_items msi_p
where bom.bill_sequence_id = bic.bill_sequence_id
and msi.inventory_item_id = bic.component_item_id
and msi.organization_id = '{$organization_id}'
and msi.organization_id = msi_p.organization_id
and msi_p.inventory_item_id = bom.assembly_item_id
and bom.organization_id = 63
and bic.disable_date IS NULL
start with msi_p.segment1 IN (
SELECT DISTINCT(segment1)
from apps.mtl_system_items_b
WHERE PLANNER_CODE = '{$planner_code}'
AND organization_id = '{$organization_id}'
AND ITEM_TYPE IN('FG')
)
connect by  prior bic.component_item_id = bom.assembly_item_id  and bom.organization_id = 63 
and msi_p.ITEM_TYPE IN ('SA','FG','PF','PH')
and prior bic.disable_date IS NULL
";

	$result = $dbOra->findBySql($sql);
	$superBom_a = [];

	$row_fgi = ['Component', 'Description', 'Type', 'Planner'];
	$row_fgi_assembly_only = [];
	foreach ($result as $data) {
	 if (($data->PARENT_ITEM_TYPE == 'FG') && (!(in_array($data->ASSEMBLY, $row_fgi_assembly_only)))) {
		array_push($row_fgi_assembly_only, $data->ASSEMBLY);
	 }
	}
	$row_fgi = array_merge($row_fgi, $row_fgi_assembly_only);
	array_push($superBom_a, $row_fgi);

	/* FGI Description */
	$row_fgi_d = [];
	$count = 0;
	for ($i = 0; $i <= 3; $i++) {
	 array_push($row_fgi_d, null);
	 $count++;
	}

	$total_item = count($row_fgi);
	foreach ($result as $data) {
	 if (($data->PARENT_ITEM_TYPE == 'FG') && (in_array($data->ASSEMBLY, $row_fgi_assembly_only) && ($count < $total_item) )) {
		$count ++;
		array_push($row_fgi_d, $data->PARENT_DESCRIPTION);
	 }
	}
	array_push($superBom_a, $row_fgi_d);

	/* Data */
	$row_data_component = [];
	$i = 0;
	foreach ($result as $data_c) {
	 $row_data = [];

	 if ($data_c->ITEM_TYPE != 'FG') {
		$row_data = [];
		$key = array_search($data_c->COMPONENT_NUMBER, $row_data_component);
		if ($key) {
		 $com_number = $row_data_component[$key];
		 array_push($row_data, $data_c->COMPONENT_NUMBER);
		 array_push($row_data, $data_c->DESCRIPTION);
		 array_push($row_data, $data_c->ITEM_TYPE);
		 array_push($row_data, $data_c->PLANNER_CODE);
		 $element_num = 3;
		 foreach ($row_fgi_assembly_only as $key => $val) {
			$element_num ++;
			if ($val == $data_c->ASSEMBLY) {
			 array_push($row_data, $data_c->QUANTITY + $superBom_a[$com_number][$element_num]);
			} else {
			 array_push($row_data, $superBom_a[$com_number][$element_num]);
			}
		 }
		 unset($superBom_a[$com_number]);
		} else {
		 array_push($row_data_component, $data_c->COMPONENT_NUMBER);
		 array_push($row_data, $data_c->COMPONENT_NUMBER);
		 array_push($row_data, $data_c->DESCRIPTION);
		 array_push($row_data, $data_c->ITEM_TYPE);
		 array_push($row_data, $data_c->PLANNER_CODE);
		 foreach ($row_fgi_assembly_only as $key => $val) {
			if ($val == $data_c->ASSEMBLY) {
			 array_push($row_data, $data_c->QUANTITY);
			} else {
			 array_push($row_data, null);
			}
		 }
		}

		$superBom_a[$data_c->COMPONENT_NUMBER] = $row_data;
	 }
	}
	return $superBom_a;
 }

 public function search_records($parameters = '') {
	pa($parameters);
	return null;
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
					 AND pv.vendor_id = pha.vendor_id
					AND $whereClause
					 $order_by_i
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
					 AND pv.vendor_id = pha.vendor_id
					 AND $whereClause
					 ) 
";
	$result = $this->findBySql($sql);
	return !empty($result) ? count($result) : false;
 }

}

//end of bom class
?>