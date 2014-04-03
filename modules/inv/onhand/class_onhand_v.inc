<?php

class onhand_v extends dbObject {

 protected static $table_name = "onhand_v";
 public static $primary_column = "onhand_id";
 public $field_a = [
		 'onhand_id',
		 'item_number',
		 'item_description',
		 'org_name',
		 'subinventory',
		 'locator',
		 'uom_id',
		 'onhand',
		 'item_id',
		 'org_id',
		 'subinventory_id',
		 'locator_id',
		 'lot_id',
		 'serial_id',
		 'reservable_onhand',
		 'transactable_onhand',
		 'lot_status',
		 'serial_status',
		 'secondary_uom_id',
		 'onhand_status',
		 'ef_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'onhand_id',
		 'item_number',
		 'item_description',
		 'org_name',
		 'subinventory',
		 'locator',
		 'uom_id',
		 'onhand',
		 'item_id',
		 'org_id',
		 'subinventory_id',
		 'locator_id',
 ];
 public $column = [
		 'onhand_id',
		 'item_number',
		 'item_description',
		 'org_name',
		 'subinventory',
		 'locator',
		 'uom_id',
		 'onhand',
		 'item_id',
		 'org_id',
		 'subinventory_id',
		 'locator_id',
 ];
 public $dateField = [
 ];
 public $pageTitle = " Onhand - Find Inventory Onhand "; //page Title
 public $search_groupBy = [
		 'locator' => 'Locator',
		 'subinventory' => 'Sub Inventory',
		 'org_id' => 'Inventory Org',
 ];
 public $onhand_id;
 public $item_number;
 public $item_description;
 public $org_name;
 public $subinventory;
 public $locator;
 public $uom_id;
 public $onhand;
 public $item_id;
 public $org_id;
 public $subinventory_id;
 public $locator_id;
 public $lot_id;
 public $serial_id;
 public $reservable_onhand;
 public $transactable_onhand;
 public $lot_status;
 public $serial_status;
 public $secondary_uom_id;
 public $onhand_status;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 private function create_onhand_v() {
	$sql = "CREATE OR REPLACE VIEW onhand_v
(onhand_id, item_number, item_description, org_name, subinventory, locator,
uom_id,onhand, item_id, org_id, subinventory_id, 
locator_id, lot_id, serial_id, reservable_onhand, 
transactable_onhand, lot_status, serial_status,  
secondary_uom_id, onhand_status, ef_id, created_by, 
creation_date, last_update_by, last_update_date)
AS
SELECT onhand.onhand_id, 
item.item_number, item.description, org.org, subinventory.subinventory, locator.locator,
onhand.uom_id,onhand.onhand,
onhand.item_id, onhand.org_id, onhand.subinventory_id, 
onhand.locator_id, onhand.lot_id, onhand.serial_id, onhand.reservable_onhand, 
onhand.transactable_onhand, onhand.lot_status, onhand.serial_status,  
onhand.secondary_uom_id, onhand.onhand_status, onhand.ef_id, onhand.created_by, 
onhand.creation_date, onhand.last_update_by, onhand.last_update_date

FROM onhand 
LEFT JOIN item ON onhand.item_id = item.item_id
LEFT JOIN org ON onhand.org_id = org.org_id
LEFT JOIN subinventory ON onhand.subinventory_id = subinventory.subinventory_id
LEFT JOIN locator ON onhand.locator_id = locator.locator_id
";
 }

}

//end of po_detail class
?>