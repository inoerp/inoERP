<?php

class po_requisition_interface extends dbObject {

 protected static $table_name = "po_requisition_interface";
 public static $primary_column = "po_requisition_interface_id";
 public static $key_column = 'bu_org_id';
 public static $module = "po";
 public $field_a = [
		 'po_requisition_interface_id',
		 'bu_org_id',
		 'po_requisition_type',
		 'ship_to_inventory',
		 'supplier_id',
		 'supplier_site_id',
		 'buyer',
		 'description',
		 'line_type',
		 'item_id',
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
		 'item_id',
		 'need_by_date',
		 'reference_key_value',
		 'requisition_status',
 ];
 public $column = [
		 'po_requisition_interface_id',
		 'bu_org_id',
		 'po_requisition_type',
		 'ship_to_inventory',
		 'supplier_id',
		 'supplier_site_id',
		 'buyer',
		 'description',
		 'line_type',
		 'item_id',
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
 ];
 public $requiredField = [
		 'bu_org_id',
		 'ship_to_inventory',
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
		 'Organization' => 'search_org_name',
 ];
 public $prg_import_requisition_details = [
		 'name' => 'Import Requisitions ',
		 'description' => 'Import Requisitions from interface ',
 ];
 public $po_requisition_interface_id;
 public $bu_org_id;
 public $po_requisition_type;
 public $ship_to_inventory;
 public $supplier_id;
 public $supplier_site_id;
 public $buyer;
 public $description;
 public $line_type;
 public $item_id;
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

 public function findBy_importGroup() {
	global $dbc;
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name ;
	$sql .= " ORDER BY bu_org_id, po_requisition_type, supplier_id ";
	$stmt = $dbc->connection->prepare(" $sql ");
	try {
	 $stmt->execute();
	 $result = $stmt->fetchAll(PDO::FETCH_CLASS);
	} catch (PDOException $e) {
	 $this->msg = "No Records Found" . $e->getMessage();
	}
	return !empty($result) ? $result : false;
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
	$output_a = [];
	$parameters = unserialize($seralized_parameters);
	$this->message = '<br> Starting to Import Requisition....<br>';

	//if no item id/number is given
	$all_lines = $this->findAll();

	$return_array = [$this->message, $output_a];

	return $return_array;
 }

}

//end of po_requisition_interface class
?>