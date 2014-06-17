<?php

class sd_delivery_line extends dbObject {

 public static $table_name = "sd_delivery_line";
 public static $primary_column = "sd_delivery_line_id";
 public static $parent_primary_column = "sd_delivery_header_id";
 public static $multi_select_template_path = "modules/sd/delivery/delivery_template.php";
 public static $multi_search_primary_column = "sd_delivery_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'sd_so_line_id';
 public static $module = "inv";
 public $field_a = [
		 'sd_delivery_line_id',
		 'sd_delivery_header_id',
		 'sd_so_header_id',
		 'sd_so_line_id',
		 'shipping_org_id',
		 'item_id',
		 'quantity',
		 'staging_subinventory_id',
		 'staging_locator_id',
		 'delivery_status',
		 'picking_date',
		 'actual_ship_date',
		 'reference_doc_type',
		 'reference_doc_number',
		 'line_uom_id',
		 'volume_uom_id',
		 'total_volume',
		 'weight_uom_id',
		 'total_weight',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 //variables used for showing data

 public $account = [
 ];
 public $fields_inForm_notInDataBase = [
		 'so_line_shipped_quantity',
		 'so_number',
		 'so_line_number',
		 'shipment_number',
		 'item_number',
		 'item_description',
		 'line_uom_id',
		 'ar_customer_id',
		 'ar_customer_number',
		 'ar_customer_name',
		 'ar_customer_site_id',
		 'ar_customer_site_number',
		 'ar_customer_site',
		 'action'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "sd_delivery_header_id",
		 'shipping_org_id',
		 'so_line_number',
		 'shipped_quantity',
		 'quantity'
 ];
 public $requiredField = [
		 'sd_so_header_id',
		 'sd_so_line_id',
		 'staging_subinventory_id',
		 'item_description',
		 'line_uom_id',
		 'quantity'
 ];
 public $initial_search = [
		 'sd_delivery_line_id',
		 'sd_delivery_header_id',
		 'sd_so_header_id',
		 'sd_so_line_id',
		 'shipping_org_id',
		 'item_id',
		 'picking_date',
 ];
 public $column = [
		 'sd_delivery_line_id',
		 'sd_delivery_header_id',
		 'sd_so_header_id',
		 'sd_so_line_id',
		 'shipping_org_id',
		 'item_id',
		 'quantity',
		 'staging_subinventory_id',
		 'staging_locator_id',
		 'delivery_status',
		 'picking_date',
		 'actual_ship_date',
		 'reference_doc_type',
		 'reference_doc_number',
		 'line_uom_id',
		 'volume_uom_id',
		 'total_volume',
		 'weight_uom_id',
		 'total_weight',
 ];
 public $sd_delivery_line_id;
 public $sd_delivery_header_id;
 public $sd_so_header_id;
 public $sd_so_line_id;
 public $shipping_org_id;
 public $item_id;
 public $quantity;
 public $staging_subinventory_id;
 public $staging_locator_id;
 public $delivery_status;
 public $picking_date;
 public $actual_ship_date;
 public $reference_doc_type;
 public $reference_doc_number;
 public $line_uom_id;
 public $volume_uom_id;
 public $total_volume;
 public $weight_uom_id;
 public $total_weight;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $line_number;
 public $shipment_number;
 public $item_number;
 public $uom_id;
 public $ar_customer_id;
 public $ar_customer_number;
 public $ar_customer_name;
 public $ar_customer_site_id;
 public $ar_customer_site_number;
 public $ar_customer_site_name;
 public $so_number;
 public $so_line_number;
 public $shipped_quantity;
 public $item_description;
 public $action;

 public function _before_save() {
	if (($this->action == 'REVERSE_PICKING')) {
	 echo "<br> Starting Sales Line Reverse Picking.";
	 $this->_reverse_picking();
	 return 10;
	} else if (($this->action == 'REMOVE_LINE')) {
	 echo "<br> Starting to remove the line from delivery ";
	 $this->sd_delivery_header_id = -1;
	 $this->audit_trial();
	 $this->save();
	 return 10;
	} else if (($this->action == 'ADD_LINE')) {
	 echo "<br> Starting to add the line to delivery ";
	 if (empty($this->sd_delivery_header_id) || $this->sd_delivery_header_id == -1) {
		echo "<br> Error - No Header Id found! @ sd_delivery_line @@" . __LINE__;
	 }
	 $this->audit_trial();
	 $this->save();
	 return 10;
	} else if (($this->action == 'COMPLETE_SHIPMENT')) {
	 echo "<br> Starting to complete the shipment ";
	 pa($this);
	 $this->_complete_shipment();
	 return 10;
	} else {
	 echo "<br> No Action For Line";
	 return 10;
	}
 }

 private function _reverse_picking() {
	/*
	 * 1. Update SO Line to Make it available for next picking
	 * 2. Delete the delivery line
	 * 3. No material / finance transaction - Onhand 'll remain in staging location and 
	 * needs to be manually moved back to stock through sub inventory transfer/move order
	 */
	$sol = new sd_so_line();
	$sol->findBy_id($this->sd_so_line_id);
	$sol->line_status = 'AWAITING_PICKING';
	$sol->audit_trial();
	$sol->save();
	echo "<br>Sales Order Line Status is Sucessfully Updated";
	$this->delete();
	echo "<br>Delivery Line is Sucessfully Deleted";
 }

 private function _complete_shipment() {
	/*
	 * 1. Update SO Line with the shipment qty and status
	 * 2. Inventory Trandsaction
	 * 3. Update the delivery line to SHIPPED
	 * needs to be manually moved back to stock through sub inventory transfer/move order
	 */
	$sol = new sd_so_line();
	$sol->findBy_id($this->sd_so_line_id);
	$sol->line_status = 'SHIPPED';
	$sol->shipped_quantity = $this->quantity;
	$sol->audit_trial();
	$sol->save();
	echo "<br>Sales Order Line Status is Sucessfully Updated";

	$invt = new inv_transaction();
	$invt->transaction_type_id = 15;
	$invt->org_id = $this->shipping_org_id;
	$invt->from_subinventory_id = $this->staging_subinventory_id;
	$invt->from_locator_id = $this->staging_locator_id;
	$invt->item_id = $this->item_id;
	$invt->uom_id = $this->line_uom_id;
	$invt->quantity = $this->quantity;
	$invt->reference_type = 'table';
	$invt->reference_key_name = 'sd_so_header';
	$invt->reference_key_value = $this->sd_delivery_header_id;
	$invt->reason = 'SO Shipping';
	$invt->sd_so_line_id = $this->sd_so_line_id;
	$invt->audit_trial();
	$invt->_before_submit();
	$invt->save();
	$invt->_after_save();
	echo "<br>Sales Order Line Status is Sucessfully Updated";
	
	$this->delivery_status = 'SHIPPED';
	$this->audit_trial();
	$this->save();
	echo "<br>Delivery Line Status is Sucessfully Updated";
 }

}

//end of sd_delivery_line class
?>