<?php

class bom_routing_header extends dbObject {

 protected static $table_name = "bom_routing_header";
 public static $field_array = [
		 'bom_routing_header_id',
		 'item_id',
		 'alternate_routing',
		 'org_id',
		 'routing_revision',
		 'effective_date',
		 'common_routing_item_id',
		 'description',
		 'completion_subinventory',
		 'completion_locator',
		 'ef_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public static $initial_search_array = [
		 'bom_routing_header_id',
		 'item_id',
		 'alternate_routing',
		 'org_id'
 ];
 public static $column_array = [
		 'bom_routing_header_id',
		 'item_id',
		 'alternate_routing',
		 'org_id'
 ];
 public static $account_array = [
 ];
 public static $checkbox_array = [

 ];
 public static $addressField_array = [
 ];
 public static $fields_inForm_notInDataBase = [
		 "item_number",
		 "item_description",
		 "uom",
		 "commonRouting_item_number",
		 "commonRouting_item_description"
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 'item_id',
		 'org_id'
 ];
 public static $otherField_array = [
 ];
 public static $primary_column = "bom_routing_header_id";
 public $bom_routing_header_id;
 public $item_id;
 public $alternate_routing;
 public $org_id;
 public $routing_revision;
 public $effective_date;
 public $common_routing_item_id;
 public $description;
 public $completion_subinventory;
 public $completion_locator;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $uom;
 public $item_number;
 public $item_description;
 public $commonRouting_item_number;
 public $commonRouting_item_description;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public function _after_save() {
	
 }

 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }
 
   public static function find_by_itemId($itemId) {
	$sql = "SELECT * FROM " . self::$table_name . " where item_id = '{$itemId}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

 Public static function wip_move_step() {
	$option_header = option_header::find_by_name('WIP_MOVE_STEP');
	$wip_move_step = option_line::find_by_option_id($option_header->option_header_id);
	return $wip_move_step;
 }

 Public static function po_status() {
	$option_header = option_header::find_by_name('PO_STATUS');
	$po_status = option_line::find_by_option_id($option_header->option_header_id);
	return $po_status;
 }

//  private  function create_all_po_v(){
//  $sql="
//CREATE OR REPLACE VIEW all_po_v
//(
//bom_routing_header_id, bu_org_id, po_type, po_number, supplier_id, supplier_site_id, buyer, currency, header_amount, po_status,
//payment_term_id,
//supplier_name, supplier_number,
//supplier_site_name, supplier_site_number,
//payment_term, payment_term_description,
//po_line_id, line_type, line_number,	item_id, item_description, line_description, line_quantity, unit_price, line_price,
//item_number, uom_id, item_status,
//po_detail_id, shipment_number, ship_to_id, sub_inventory_id, locator_id, requestor, quantity,
//need_by_date, promise_date,
//po_received_quantity, po_accepted_quantity, po_delivered_quantity, po_invoiced_quantity, po_paid_quantity,
//ship_to_org
//)
//AS
//SELECT 
//bom_routing_header.bom_routing_header_id, bom_routing_header.bu_org_id, bom_routing_header.po_type, bom_routing_header.po_number, bom_routing_header.supplier_id, 
//bom_routing_header.supplier_site_id, bom_routing_header.buyer, bom_routing_header.currency, bom_routing_header.header_amount, bom_routing_header.po_status,
//bom_routing_header.payment_term_id,
//supplier.supplier_name, supplier.supplier_number,
//supplier_site.supplier_site_name, supplier_site.supplier_site_number,
//payment_term.payment_term, payment_term.description,
//po_line.po_line_id, po_line.line_type, po_line.line_number,	po_line.item_id, po_line.item_description, po_line.line_description, 
//po_line.line_quantity, po_line.unit_price, po_line.line_price,
//item.item_number, item.uom_id, item.item_status,
//po_detail.po_detail_id, po_detail.shipment_number, po_detail.ship_to_inventory, po_detail.sub_inventory_id, 
//po_detail.locator_id, po_detail.requestor, po_detail.quantity, po_detail.need_by_date, po_detail.promise_date,
//po_detail.received_quantity, po_detail.accepted_quantity, po_detail.delivered_quantity, 
//po_detail.invoiced_quantity, po_detail.paid_quantity,
//org.org
//
//FROM bom_routing_header 
//LEFT JOIN supplier ON bom_routing_header.supplier_id = supplier.supplier_id
//LEFT JOIN supplier_site ON bom_routing_header.supplier_site_id = supplier_site.supplier_site_id
//LEFT JOIN payment_term ON bom_routing_header.payment_term_id = payment_term.payment_term_id
//LEFT JOIN po_line ON bom_routing_header.bom_routing_header_id = po_line.bom_routing_header_id
//LEFT JOIN item ON po_line.item_id = item.item_id
//LEFT JOIN po_detail ON po_line.po_line_id = po_detail.po_line_id
//LEFT JOIN org ON po_detail.ship_to_inventory = org.org_id
//
//";
// }
}

//end of bom_routing_header class
?>