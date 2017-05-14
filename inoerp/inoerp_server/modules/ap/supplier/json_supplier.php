<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php
 if ((!empty($_REQUEST['action'])) && ($_REQUEST['action'] = 'search')) {
  if (empty($_REQUEST['term'])) {
   exit;
  }
  $supplier_name = $_REQUEST['term'];
  if (!empty($_REQUEST['primary_column1'])) {
   $primary_column1 = $_REQUEST['primary_column1'];
  }
  $supplier = new supplier();
  $supplier->supplier_name = $supplier_name;
  if (!empty($primary_column1)) {
   $supplier->org_id = $primary_column1;
   $data = $supplier->searchBy_supplierName_orgId();
  } else {
   $data = $supplier->searchBy_supplier_name();
  }
// JSON data
  echo json_encode($data);
  flush();

  //return from this file
  return;
 }
?>
<?php
 if ((!empty($_GET['supplier_id'])) && !empty($_GET['find_supplier_details'])) {
  $supplier_id = $_GET['supplier_id'];
  $data = [];
  $all_site = supplier_site::find_all_sitesOfSupplier($supplier_id);
  $data['supplier_site_id'] = $f->select_field_from_object('supplier_site_id', supplier_site::find_all_sitesOfSupplier($supplier_id), 'supplier_site_id', 'supplier_site_name', '', 'supplier_site_id');
  $supplier_details = supplier::find_by_id($supplier_id);
  $supplier_file = extn_file::find_by_reference_table_and_id('supplier', $supplier_id);
  $data = array_merge($data,(array)$supplier_file, (array)$supplier_details);
  if (count($supplier_details) == 0) {
   return false;
  } else {
   echo header('Content-Type: application/json');
   echo json_encode($data);
  }
 }
?>
<?php
 if ((!empty($_GET['supplier_id'])) && (!empty($_GET['org_id'])) && !empty($_GET['find_supplier_bu_details'])) {
  $supplier_id = $_GET['supplier_id'];
  $org_id = $_GET['org_id'];
  $sbu = new supplier_bu();
  $supplier_bu_assigment = $sbu->findBy_orgId_supplierId($org_id, $supplier_id);
  if (count($supplier_bu_assigment) == 0) {
   return false;
  } else {
   echo header('Content-Type: application/json');
   echo json_encode($supplier_bu_assigment);
  }
 }
?>
<?php
 if ((!empty($_GET['supplier_site_id'])) && ($_GET['find_site_details'] = 1)) {
  $supplier_site_id = $_GET['supplier_site_id'];
  $supplier_site_details = supplier_site::find_by_id($supplier_site_id);
  if (count($supplier_site_details) == 0) {
   return false;
  } else {
   echo header('Content-Type: application/json');
   echo json_encode($supplier_site_details);
  }
 }
?>
