<?php

class po_requisition_interface extends dbObject {

 public static $table_name = "po_requisition_interface";
 public static $primary_column = "po_requisition_interface_id";
 public static $key_column = 'bu_org_id';
 public static $module = "po";
 public $field_a = [
		 'po_requisition_interface_id',
		 'bu_org_id',
		 'po_requisition_type',
		 'receving_org_id',
		 'supplier_id',
		 'supplier_site_id',
		 'buyer',
		 'description',
		 'line_type',
		 'item_id_m',
  'bpa_po_line_id',
		 'item_description',
		 'currency',
		 'uom_id',
		 'quantity',
		 'unit_price',
		 'need_by_date',
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
		 'requisition_status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'po_requisition_interface_id',
		 'po_requisition_type',
		 'buyer',
		 'item_id_m',
		 'need_by_date',
		 'reference_key_value',
		 'requisition_status',
 ];
// public $column = [
//		 'po_requisition_interface_id',
//		 'bu_org_id',
//		 'po_requisition_type',
//		 'receving_org_id',
//		 'supplier_id',
//		 'supplier_site_id',
//		 'buyer',
//		 'description',
//		 'line_type',
//		 'item_id_m',
//		 'item_description',
//		 'currency',
//		 'uom_id',
//		 'quantity',
//		 'unit_price',
//		 'need_by_date',
//		 'reference_type',
//		 'reference_key_name',
//		 'reference_key_value',
//		 'requisition_status',
// ];
 public $requiredField = [
		 'bu_org_id',
		 'receving_org_id',
		 'po_requisition_type',
		 'line_type',
		 'item_description',
		 'currency',
		 'quantity',
		 'unit_price',
		 'need_by_date',
		 'requisition_status',
 ];
 public $fields_inForm_notInDataBase = [
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
		 "ship_to_address",
		 "bill_to_address"
 ];
 public $search = [
//		 '_show_update_path' => 1,
//		 '_update_action_meassge' => 'Update',
 ];
 public $pageTitle = " Requistion Interface - PO "; //page Title
 public $option_lists = [
		 'po_requisition_type' => 'PO_REQUISITION_TYPE',
		 'requisition_status' => 'PO_STATUS',
 ];
 public $prg_import_requisition_parameters = [
		 'Business Org' => 'search_business_org',
 ];
 public $prg_import_requisition_details = [
		 'name' => 'Import Requisitions ',
		 'description' => 'Import Requisitions from interface ',
 ];
 public $po_requisition_interface_id;
 public $bu_org_id;
 public $po_requisition_type;
 public $receving_org_id;
 public $supplier_id;
 public $supplier_site_id;
 public $buyer;
 public $description;
 public $line_type;
 public $item_id_m;
 public $bpa_po_line_id;
 public $item_description;
 public $currency;
 public $uom_id;
 public $quantity;
 public $unit_price;
 public $need_by_date;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $requisition_status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $supplier_name;
 public $supplier_number;
 public $supplier_site_name;
 public $ship_to_address;
 public $bill_to_address;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;

 public function __set($name, $value) {
	switch ($value) {
	 case $value:


		break;

	 default:
		$this->$name = $value;
		break;
	}
 }

 public function _after_save() {
	
 }

 public function _countAllWith_supplierSiteId($bu_orgId = '') {
	$bu_org_id = !empty($bu_orgId) ? $bu_orgId : $this->bu_org_id;
	$sql = "SELECT DISTINCT(supplier_site_id) FROM " . static::$table_name;
	$sql .= " WHERE bu_org_id = :bu_org_id ";
	$value_a = ['bu_org_id' => $bu_org_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? ($result) : false;
 }

 public function findAllBy_requisitionType($bu_org_id, $po_requisition_type) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE bu_org_id = :bu_org_id AND  po_requisition_type = :po_requisition_type";
	$value_a = ['bu_org_id' => $bu_org_id, 'po_requisition_type' => $po_requisition_type];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? $result : false;
 }

 private function _findBy_supplier_site_id($supplier_site_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE supplier_site_id = :supplier_site_id";
	$value_a = ['supplier_site_id' => $supplier_site_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? $result : false;
 }

 private function _importAndDelete_fromInterface($obj) {
	global $dbc;
	$req_header = new po_requisition_header();
	$req_header->bu_org_id = $obj[0]->bu_org_id;
	$req_header->po_requisition_type = $obj[0]->po_requisition_type;
	$req_header->currency = $obj[0]->currency;
	if (isset($obj[0]->supplier_id)) {
	 $req_header->supplier_id = $obj[0]->supplier_id;
	}
	if (isset($obj[0]->supplier_site_id)) {
	 $req_header->supplier_site_id = $obj[0]->supplier_site_id;
	}
	$req_header->requisition_status = 'APPROVED';
	$req_header->audit_trial();
	$req_header->save();
	$req_header->_after_save();

	$line_number = 0;
	foreach ($obj as $new_req_line) {
	 $line_number++;
	 $req_line = new po_requisition_line();
	 $req_line->po_requisition_header_id = $req_header->po_requisition_header_id;
	 $req_line->line_number = $line_number;
	 $req_line->receving_org_id = $new_req_line->receving_org_id;
	 $req_line->line_type = $new_req_line->line_type;
	 $req_line->item_id_m = $new_req_line->item_id_m;
	 $req_line->item_description = $new_req_line->item_description;
	 $req_line->line_quantity = $new_req_line->quantity;
	 $req_line->unit_price = $new_req_line->unit_price;
	 $req_line->line_price = $req_line->line_quantity * $req_line->unit_price;
	 $req_line->uom_id = $new_req_line->uom_id;
	 $req_line->audit_trial();
	 $req_line->save();

	 $req_detail = new po_requisition_detail();
	 $req_detail->po_requisition_header_id = $req_header->po_requisition_header_id;
	 $req_detail->po_requisition_line_id = $req_line->po_requisition_line_id;
	 $req_detail->shipment_number = 1;
	 $req_detail->need_by_date = $new_req_line->need_by_date;

	 $inv = new inventory();
	 $inv_i = $inv->findBy_org_id($req_line->receving_org_id);
	 //ac id needs to be modified to req accounts
	 $req_detail->charge_ac_id = $inv_i->material_ac_id;
	 $req_detail->accrual_ac_id = $inv_i->inv_ap_accrual_ac_id;
	 $req_detail->ppv_ac_id = $inv_i->inv_ppv_ac_id;
	 $req_detail->audit_trial();
	 $req_detail->save();
	 echo "<br> Requistion Detail is succefully created. Detail Id - " . $req_detail->po_requisition_detail_id;

	 $pori = new po_requisition_interface();
	 $pori->findBy_id($new_req_line->po_requisition_interface_id);
	 $pori->delete();
	}
 }

 Public static function po_requisition_type() {
	$option_header = option_header::find_by_name('PO_REQUISITION_TYPE');
	$po_requisition_types = option_line::find_by_option_id($option_header->option_header_id);
	return $po_requisition_types;
 }

 Public static function requisition_status() {
	$option_header = option_header::find_by_name('PO_STATUS');
	$po_requisition_status = option_line::find_by_option_id($option_header->option_header_id);
	return $po_requisition_status;
 }

 public function prg_import_requisition($seralized_parameters) {
	/* 1. First Import all lines with supplier site id
	  2. Import all External lines
	  3. Import all Internal Lines */
	$output_a = [];
	$parameters = unserialize($seralized_parameters);
	$this->message = '<br> Starting to Import Requisition....<br>';

	if (!empty($parameters['bu_org_id'][0])) {
	 $bu_org_id = $parameters['bu_org_id'][0];
	 $this->message .= '<br> Entered Bu org Id is : ' . $bu_org_id;
	} else {
	 $this->message .= '<br> Error! : No BU org id found @ po_requisition_interface ' . __LINE__;
	 return $this->message;
	}

//	1. Lines with supplier site id
	$interfaceLines_withSupplier = $this->_countAllWith_supplierSiteId($bu_org_id);
	if ($interfaceLines_withSupplier) {
	 foreach ($interfaceLines_withSupplier as $interfaceLines) {
		$interface_lines = $this->_findBy_supplier_site_id($interfaceLines->supplier_site_id);
		try {
		 $this->_importAndDelete_fromInterface($interface_lines);
		 $this->message .= "<br>All line with supplier site id are Successfullyimported. Count is " . count($interface_lines);
		} catch (Exception $e) {
		 $this->message .= "<br>Import Failed for lines with out supplier site id. Count is " . count($interface_lines);
		}
	 }
	}

	//2. All External Lines
	$all_external_lines = $this->findAllBy_requisitionType($bu_org_id, 'EXTERNAL');
	if ($all_external_lines) {
	 try {
		$this->_importAndDelete_fromInterface($all_external_lines);
		$this->message .= "<br>All line without supplier site id are Successfullyimported. Count is " . count($all_external_lines);
	 } catch (Exception $e) {
		$this->message .= "<br>Import Failed for lines with out supplier site id. Count is " . count($all_external_lines);
	 }
	}

	//3. All Internal Lines
	$all_internal_lines = $this->findAllBy_requisitionType($bu_org_id, 'INTERNAL');
	if ($all_internal_lines) {
	 try {
		$this->_importAndDelete_fromInterface($all_internal_lines);
		$this->message .= "<br>All Interanl lines are Successfullyimported. Count is " . count($all_external_lines);
	 } catch (Exception $e) {
		$this->message .= "<br>Import Failed for Internal Lines. Count is " . count($all_external_lines);
	 }
	}

	return $this->message;
 }

}

//end of po_requisition_interface class
?>