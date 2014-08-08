<?php

class bom_explosion extends dbOraObject {

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
 public $fields_inForm_notInDataBase = [
   "include_all_items_in_bom",
   'validate_in_new_org'
 ];
 public $super_bom_parameters = [
   'Organization' => 'search_org_name',
   'Planner Code' => 'search_planner_code',
   'List Of Items' => 'search_list_of_items',
   'Include All Items in BOM' => 'search_include_all_items_in_bom',
   'Download in text mode' => 'search_download_as_text',
   'Validate in a new Org' => 'validate_in_new_org',
 ];
 public $super_bom_details = [
   'name' => 'Super BOM - Explosion ',
   'description' => 'Roll up cost for pending or user defiled cost types',
 ];
 public $bom_id;
 public $PLANNER_CODE;
 public $ORGANIZATION_ID;
 public $END_DATE;
 public $include_all_items_in_bom;
 public $validate_in_new_org;

 public function __set($name, $value) {
  switch ($value) {
   case $value:


    break;

   default:
    $this->$name = $value;
    break;
  }
 }

 function getBOM($item_id, $org_id = '2989', $usage = '1') {
  global $dbOra;
  $sql = "
	SELECT DISTINCT( bbc.bill_item_name || '|' || bbc.component_item_name ),
 bbc.bill_item_name as Assembly, msi.description as Parent_Description,
msi.ITEM_TYPE Parent_Item_Type, msi.PLANNER_CODE Parent_Planner_code,
bbc.component_item_id Component_Item_Id,bbc.component_item_name as Component_Number,
msi_c.description as Description , bbc.quantity_per_assembly*$usage as Quantity, 
msi_c.item_type, msi_c.planner_code, bbc.organization_code, bbc.end_effective_date as END_DATE,
 bbc.organization_id, bbc.assembly_item_id
from apps.bomfg_bom_components  bbc,
apps.mtl_system_items_b msi,
apps.mtl_system_items_b msi_c
where bbc.organization_id = 63
and bbc.assembly_item_id = '{$item_id}' ";
  if (!empty($this->include_all_items_in_bom) && ($this->include_all_items_in_bom == 1)) {
   $sql .= " ";
  } else {
   $sql .= " AND bbc.end_effective_date IS NULL ";
  }
  $sql .=" and msi_c.inventory_item_id = bbc.component_item_id
and msi_c.organization_id = '{$org_id}'
and msi.organization_id = '{$org_id}'
and msi.inventory_item_id = bbc.assembly_item_id
and msi.item_type IN ('SA','PH','FG','PF')
";

  $result = $dbOra->findBySql($sql);
  return $result;
 }

 function indentedBOM($item_id, $org_id, &$ib, $usage = 1, $assembly_number = '', $PARENT_DESCRIPTION = '') {
  $ib_i = $this->getBOM($item_id, $org_id, $usage);
  foreach ($ib_i as $records) {
   if (!empty($assembly_number)) {
    $records->ASSEMBLY = $assembly_number;
    $records->PARENT_DESCRIPTION = $PARENT_DESCRIPTION;
   }
   array_push($ib, $records);
   if (($records->ITEM_TYPE == 'SA' || 'PF' || 'PH' || 'FG') && (empty($records->END_DATE))) {
    $this->indentedBOM($records->COMPONENT_ITEM_ID, $org_id, $ib, $records->QUANTITY, $records->ASSEMBLY, $records->PARENT_DESCRIPTION);
   }
  }
 }

 private function _item_type_in_new_org($segment1, $org_id) {
  $sql = " SELECT * FROM apps.mtl_system_items_b WHERE organization_id = '{$org_id}' AND segment1 = '{$segment1}' AND  ROWNUM < 2";
  $result = $this->findBySql($sql);
  return !empty($result) ? $result[0]->ITEM_TYPE : 'NOT ENLABLED';
 }

 function all_items_for_IB($org_id = '2989', $item_number_a = '', $planner_code = '') {
  global $dbOra;
  $sql = "
SELECT DISTINCT(segment1), inventory_item_id, description
from apps.mtl_system_items_b
WHERE organization_id = '{$org_id}' ";

  if (!empty($item_number_a)) {
   $in_array = '(\'' . implode('\', \'', $item_number_a) . '\')';
   $sql .= " AND SEGMENT1 IN $in_array ";
  } else {
   $sql .= " AND PLANNER_CODE = '{$planner_code}' ";
  }
  $sql .= " AND ITEM_TYPE IN('FG', 'SA') ";
  $result = $dbOra->findBySql($sql);
  return $result;
 }

 function superBOM($all_items, $org_id) {
  $ib_final = [];

  foreach ($all_items as $items) {
   $ib = [];
   $this->indentedBOM($items->INVENTORY_ITEM_ID, $org_id, $ib, 1, $items->SEGMENT1, $items->DESCRIPTION);
   $ib_final = array_merge($ib, $ib_final);
  }
  return $ib_final;
 }

 public function super_bom($parameters) {
  global $dbOra;

  $organization_id = !empty($parameters['ORGANIZATION_ID']) ? $parameters['ORGANIZATION_ID'] : false;
  $planner_code = !empty($parameters['PLANNER_CODE']) ? $parameters['PLANNER_CODE'] : false;
  $item_number = !empty($parameters['ITEM_NUMBER']) ? $parameters['ITEM_NUMBER'] : false;
  $this->include_all_items_in_bom = !empty($parameters['include_all_items_in_bom']) ? 1 : false;
  $this->validate_in_new_org = !empty($parameters['validate_in_new_org']) ? $parameters['validate_in_new_org'] : false;

  if (!empty($item_number)) {
   $item_number_a = explode(',', $item_number);
   $all_items = $this->all_items_for_IB($organization_id, $item_number_a);
  } else {
   $all_items = $this->all_items_for_IB($organization_id, '', $planner_code);
  }
  $result = $this->superBOM($all_items, $organization_id);
//	pa($result);
//	sadjasdas();
//	
  $superBom_a = [];
  /* FGI Description */
  $row_fgi_d = [];
  for ($i = 0; $i <= 4; $i++) {
   array_push($row_fgi_d, null);
  }

  $row_fgi = ['Component', 'Description', 'Type', 'Planner', 'End Date'];
  if (!empty($this->validate_in_new_org)) {
   $new_org_id = 'Org Id#' . $this->validate_in_new_org;
   array_push($row_fgi, $new_org_id);
   array_push($row_fgi_d, null);
  }
  $row_fgi_assembly_only = [];
  foreach ($result as $data) {
   if (!(in_array($data->ASSEMBLY, $row_fgi_assembly_only))) {
    array_push($row_fgi_assembly_only, $data->ASSEMBLY);
    array_push($row_fgi_d, $data->PARENT_DESCRIPTION);
   }
  }
  $row_fgi = array_merge($row_fgi, $row_fgi_assembly_only);
  array_push($superBom_a, $row_fgi);
  array_push($superBom_a, $row_fgi_d);

  /* Data */
  $row_data_component = [];
  $i = 0;
  foreach ($result as $data_c) {

   $row_data = [];
   $key = array_search($data_c->COMPONENT_NUMBER, $row_data_component);
   if ($key) {
    $com_number = $row_data_component[$key];
    array_push($row_data, $data_c->COMPONENT_NUMBER);
    array_push($row_data, $data_c->DESCRIPTION);
    array_push($row_data, $data_c->ITEM_TYPE);
    array_push($row_data, $data_c->PLANNER_CODE);
    $element_num_date = 4;
    if (empty($superBom_a[$com_number][$element_num_date]) || empty($data_c->END_DATE)) {
     $end_date = null;
    } else {
     $end_date = $data_c->END_DATE;
    }
    array_push($row_data, $end_date);

    $status_in_newOrg = $this->_item_type_in_new_org($data_c->COMPONENT_NUMBER, $this->validate_in_new_org);
    array_push($row_data, $status_in_newOrg);
    $element_num = 5;
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
    array_push($row_data, $data_c->END_DATE);
    $status_in_newOrg = $this->_item_type_in_new_org($data_c->COMPONENT_NUMBER, $this->validate_in_new_org);
    array_push($row_data, $status_in_newOrg);

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

//		pa($superBom_a);
//	sadjasdas();
  return $superBom_a;
 }

}

//end of bom class
?>