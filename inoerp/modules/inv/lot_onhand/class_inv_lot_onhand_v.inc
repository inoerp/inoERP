<?php

 class inv_lot_onhand_v extends dbObject {

  public static $table_name = "inv_lot_onhand_v";
  public static $primary_column = "po_header_id";
  public $field_a = [
   'inv_lot_onhand_id',
   'inv_onhand_id',
   'inv_lot_number_id',
   'onhand_type_id',
   'lot_number',
   'onhand_type',
   'org_id',
   'item_number',
   'item_description',
   'item_id_m',
   'from_subinventory',
   'to_subinventory',
   'from_locator',
   'to_locator',
   'uom_id',
   'lot_number_id',
   'document_type',
   'document_number',
   'document_id',
   'po_header_id',
   'po_line_id',
   'po_detail_id',
   'sd_so_line_id',
   'reason',
   'reference_key_name',
   'reference_key_value',
   'description',
   'from_org_id',
   'from_subinventory_id',
   'to_org_id',
   'to_subinventory_id',
   'from_locator_id',
   'to_locator_id',
  ];
  public $initial_search = [
   "item_number",
   'lot_number',
   'inv_lot_number_id',
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
   '_view_path' => 'form.php?class_name=inv_lot_onhand_v',
   '_show_view_path' => 1,
  ];
  public $pageTitle = " lot onhands "; //page Title
  public $inv_lot_onhand_id;
  public $inv_onhand_id;
  public $inv_lot_number_id;
  public $lot_number;
  public $onhand_type_id;
  public $onhand_type;
  public $org_id;
  public $item_number;
  public $item_description;
  public $item_id_m;
  public $from_subinventory;
  public $to_subinventory;
  public $from_locator;
  public $to_locator;
  public $uom_id;
  public $lot_number_id;
  public $document_type;
  public $document_number;
  public $document_id;
  public $po_header_id;
  public $po_line_id;
  public $po_detail_id;
  public $sd_so_line_id;
  public $reason;
  public $reference_key_name;
  public $reference_key_value;
  public $description;
  public $from_org_id;
  public $from_subinventory_id;
  public $to_org_id;
  public $to_subinventory_id;
  public $from_locator_id;
  public $to_locator_id;
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
inv_lot_onhand_id , inv_onhand_id , inv_lot_number_id,lot_number,
onhand_type_id , onhand_type , org_id , item_number , item_description, item_id_m , from_subinventory, to_subinventory, 
from_locator, to_locator, uom_id , lot_number_id , document_type ,document_number , document_id , po_header_id , po_line_id , po_detail_id,
sd_so_line_id , reason , reference_key_name , reference_key_value , description , 
from_org_id , from_subinventory_id ,to_org_id , to_subinventory_id, from_locator_id, to_locator_id
)
AS
SELECT ist.inv_lot_onhand_id , ist.inv_onhand_id , ist.inv_lot_number_id,isn.lot_number, 
it.onhand_type_id , tt.onhand_type , it.org_id , item.item_number , item.item_description, it.item_id_m , subf.subinventory, subt.subinventory, locf.locator, loct.locator, it.uom_id , it.lot_number_id , it.document_type ,it.document_number , it.document_id , it.po_header_id , it.po_line_id , it.po_detail_id,
it.sd_so_line_id , it.reason , it.reference_key_name , it.reference_key_value , it.description , 
it.from_org_id , it.from_subinventory_id ,it.to_org_id , it.to_subinventory_id, it.from_locator_id, it.to_locator_id

FROM inv_lot_onhand ist
LEFT JOIN inv_lot_number isn ON isn.inv_lot_number_id = ist.inv_lot_number_id
LEFT JOIN inv_onhand it ON it.inv_onhand_id = ist.inv_onhand_id
LEFT JOIN item ON item.item_id_m = it.item_id_m AND item.org_id = it.org_id
LEFT JOIN onhand_type tt ON tt.onhand_type_id = it.onhand_type_id 
LEFT JOIN subinventory subf ON subf.subinventory_id = it.from_subinventory_id
LEFT JOIN subinventory subt ON subt.subinventory_id = it.to_subinventory_id
LEFT JOIN locator locf ON locf.locator_id = it.from_locator_id
LEFT JOIN locator loct ON loct.locator_id = it.to_locator_id
";
  }

    public static function find_by_invonhandId($inv_onhand_id) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE inv_onhand_id = '{$inv_onhand_id}'  ";
   $result =self::find_by_sql($sql);
   return !empty($result) ? ($result) : false;
  }
  
    public static function find_by_invlotNumberId($inv_lot_number_id) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE inv_lot_number_id = '{$inv_lot_number_id}'  ";
   $result =self::find_by_sql($sql);
   return !empty($result) ? ($result) : false;
  }
  
 }

//end of po_detail class
?>