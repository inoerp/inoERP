<?php
$sys_catalog_header_id_h = $reference_table_h = $reference_id_h = null;
if (!empty($_GET['sys_catalog_header_id'])) {
 if (is_array($_GET['sys_catalog_header_id'])) {
  $sys_catalog_header_id_h = $_GET['sys_catalog_header_id'][0];
 } else {
  $sys_catalog_header_id_h = $_GET['sys_catalog_header_id'];
 }
}

if (!empty($_GET['reference_table'])) {
 if (is_array($_GET['reference_table'])) {
  $reference_table_h = $_GET['reference_table'][0];
 } else {
  $reference_table_h = $_GET['reference_table'];
 }
}

if (!empty($_GET['reference_id'])) {
 if (is_array($_GET['reference_id'])) {
  $reference_id_h = $_GET['reference_id'][0];
 } else {
  $reference_id_h = $_GET['reference_id'];
 }
}

if (empty($sys_catalog_value_object) && !empty($sys_catalog_header_id_h)) {
 $sys_catalog_value_object = sys_catalog_line::find_by_parent_id($sys_catalog_header_id_h);
 if (!empty($sys_catalog_value_object)) {
  foreach ($sys_catalog_value_object as &$sys_catalog_value1) {
   $sys_catalog_value1->sys_catalog_value_id = null;
   $sys_catalog_value1->line_value = null;
   $sys_catalog_value1->reference_table = null;
   $sys_catalog_value1->reference_id = null;
  }
 }
}

if (!empty($reference_table_h) && !empty($reference_id_h) && !empty($sys_catalog_header_id_h)) {
// $sys_catalog_value_object_e = sys_catalog_value::find_by_reference_table_and_id($reference_table_h, $reference_id_h, $sys_catalog_header_id_h);
 if (!empty($sys_catalog_value_object)) {
  foreach ($sys_catalog_value_object as &$sys_catalog_value2) {
   $sys_cat_val = sys_catalog_value::find_by_referenceTable_referenceId_lineId($reference_table_h, $reference_id_h,$sys_catalog_value2->sys_catalog_line_id);
   if($sys_cat_val){
   $sys_catalog_value2->sys_catalog_value_id = $sys_cat_val->sys_catalog_value_id;
   $sys_catalog_value2->line_value = $sys_cat_val->line_value;
   $sys_catalog_value2->reference_table = $sys_cat_val->reference_table;
   $sys_catalog_value2->reference_id = $sys_cat_val->reference_id;
   }else{
   $sys_catalog_value2->sys_catalog_value_id = null;
   $sys_catalog_value2->line_value = null;
   $sys_catalog_value2->reference_table = null;
   $sys_catalog_value2->reference_id = null;
   }
   
  }
 }
}


if (empty($sys_catalog_value_object)) {
 $sys_catalog_value_object = array(new sys_catalog_line);
 if (!empty($sys_catalog_value_object)) {
  foreach ($sys_catalog_value_object as &$sys_catalog_value1) {
   $sys_catalog_value1->sys_catalog_value_id = null;
   $sys_catalog_value1->line_value = null;
   $sys_catalog_value1->reference_table = null;
   $sys_catalog_value1->reference_id = null;
  }
 }
}

$catalog_i = null;
if (!empty($sys_catalog_header_id_h)) {
 $sys_catalog_header = sys_catalog_header::find_by_id($sys_catalog_header_id_h);
 $catalog_i = $sys_catalog_header->catalog;
}
?>
