<?php

class inv_lot_onhand_v extends dbObject {

 public static $table_name = "inv_lot_onhand_v";
 public static $primary_column = "lot_number";
 public $field_a = [
  'item_number',
  'item_description',
  'lot_quantity',
  'lot_number',
  'subinventory',
  'locator',
  'onhand',
  'inv_lot_onhand_id',
  'onhand_id',
  'lot_inv_lot_number_id',
  'inv_lot_number_id',
  'org_id',
  'item_id_m',
  'subinventory_id',
  'locator_id',
 ];
 public $initial_search = [
  "item_number",
  'lot_number',
  'inv_lot_number_id',
  'item_id_m',
  'uom_id',
  'org_id',
  'subinventory_id',
  'locator_id',
 ];
 public $fields_inForm_notInDataBase = [
  'status',
  'generation',
  'origination_type',
  'origination_date',
  'activation_date',
  'current_org_id',
  'current_subinventory_id',
  'current_locator_id',
  'country_of_origin',
 ];
 public $search = [
  '_view_path' => 'form.php?class_name=inv_lot_onhand',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Lot Onhand "; //page Title
 public $inv_lot_onhand_id;
 public $onhand_id;
 public $lot_inv_lot_number_id;
 public $lot_quantity;
 public $lot_number;
 public $inv_lot_number_id;
 public $item_number;
 public $item_description;
 public $org_id;
 public $item_id_m;
 public $subinventory;
 public $subinventory_id;
 public $locator_id;
 public $locator;
 public $uom_id;
 public $onhand;
 public $generation;
 public $origination_type;
 public $origination_date;
 public $status;
 public $activation_date;
 public $current_org_id;

 private function create_inv_lot_onhand_v() {
  $sql = "
CREATE OR REPLACE VIEW inv_lot_onhand_v
(
inv_lot_onhand_id , onhand_id , lot_inv_lot_number_id, lot_quantity,
lot_number, inv_lot_number_id ,
item_number , item_description,
org_id , item_id_m ,  subinventory, locator, uom_id ,  onhand,
subinventory_id, locator_id
)
AS
SELECT ilo.inv_lot_onhand_id , ilo.onhand_id , ilo.inv_lot_number_id, ilo.lot_quantity,
iln.lot_number, iln.inv_lot_number_id ,
item.item_number , item.item_description,
oh.org_id , oh.item_id_m , 
sub.subinventory, loc.locator, oh.uom_id , oh.onhand,
oh.subinventory_id, oh.locator_id

FROM inv_lot_onhand ilo
LEFT JOIN inv_lot_number iln ON iln.inv_lot_number_id = ilo.inv_lot_number_id
LEFT JOIN onhand oh ON oh.onhand_id = ilo.onhand_id
LEFT JOIN item ON item.item_id_m = oh.item_id_m AND item.org_id = oh.org_id
LEFT JOIN subinventory sub ON sub.subinventory_id = oh.subinventory_id
LEFT JOIN locator loc ON loc.locator_id = oh.locator_id
";
 }

 public static function find_by_invonhandId($inv_onhand_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE inv_onhand_id = '{$inv_onhand_id}'  ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

 public static function find_by_invlotNumberId($inv_lot_number_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE inv_lot_number_id = '{$inv_lot_number_id}'  ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

}

//end of po_detail class
?>