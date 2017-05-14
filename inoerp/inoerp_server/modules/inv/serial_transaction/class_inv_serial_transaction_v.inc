<?php

 class inv_serial_transaction_v extends dbObject {
  public static $system_info = [
  'name' => 'Serial Transaction View',
  'number' => '2140',
  'description' => 'Inventory Serial Transaction  View',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('inv_intorg_transfer_line'),
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 6
 ];
  
  public static $form_class_name = "inv_serial_transaction";
  public static $table_name = "inv_serial_transaction_v";
  public static $primary_column = "po_header_id";
  public $field_a = [
   'inv_serial_transaction_id',
   'inv_transaction_id',
   'inv_serial_number_id',
   'transaction_type_id',
   'serial_number',
   'transaction_type',
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
   'serial_number',
   'inv_serial_number_id',
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
   '_view_path' => 'form.php?class_name=inv_serial_transaction_v',
   '_show_view_path' => 1,
  ];
  public $pageTitle = " Serial Transactions "; //page Title
  public $inv_serial_transaction_id;
  public $inv_transaction_id;
  public $inv_serial_number_id;
  public $serial_number;
  public $transaction_type_id;
  public $transaction_type;
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

  private function create_inv_serial_transaction_v() {
   $sql = "
CREATE OR REPLACE VIEW inv_serial_transaction_v
(
inv_serial_transaction_id , inv_transaction_id , inv_serial_number_id,serial_number,
transaction_type_id , transaction_type , org_id , item_number , item_description, item_id_m , from_subinventory, to_subinventory, 
from_locator, to_locator, uom_id , lot_number_id , document_type ,document_number , document_id , po_header_id , po_line_id , po_detail_id,
sd_so_line_id , reason , reference_key_name , reference_key_value , description , 
from_org_id , from_subinventory_id ,to_org_id , to_subinventory_id, from_locator_id, to_locator_id
)
AS
SELECT ist.inv_serial_transaction_id , ist.inv_transaction_id , ist.inv_serial_number_id,isn.serial_number, 
it.transaction_type_id , tt.transaction_type , it.org_id , item.item_number , item.item_description, it.item_id_m , subf.subinventory, subt.subinventory, locf.locator, loct.locator, it.uom_id , it.lot_number_id , it.document_type ,it.document_number , it.document_id , it.po_header_id , it.po_line_id , it.po_detail_id,
it.sd_so_line_id , it.reason , it.reference_key_name , it.reference_key_value , it.description , 
it.from_org_id , it.from_subinventory_id ,it.to_org_id , it.to_subinventory_id, it.from_locator_id, it.to_locator_id

FROM inv_serial_transaction ist
LEFT JOIN inv_serial_number isn ON isn.inv_serial_number_id = ist.inv_serial_number_id
LEFT JOIN inv_transaction it ON it.inv_transaction_id = ist.inv_transaction_id
LEFT JOIN item ON item.item_id_m = it.item_id_m AND item.org_id = it.org_id
LEFT JOIN transaction_type tt ON tt.transaction_type_id = it.transaction_type_id 
LEFT JOIN subinventory subf ON subf.subinventory_id = it.from_subinventory_id
LEFT JOIN subinventory subt ON subt.subinventory_id = it.to_subinventory_id
LEFT JOIN locator locf ON locf.locator_id = it.from_locator_id
LEFT JOIN locator loct ON loct.locator_id = it.to_locator_id
";
  }

    public static function find_by_invTransactionId($inv_transaction_id) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE inv_transaction_id = '{$inv_transaction_id}'  ";
   $result =self::find_by_sql($sql);
   return !empty($result) ? ($result) : false;
  }
  
    public static function find_by_invSerialNumberId($inv_serial_number_id) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE inv_serial_number_id = '{$inv_serial_number_id}'  ";
   $result =self::find_by_sql($sql);
   return !empty($result) ? ($result) : false;
  }
  
 }

//end of po_detail class
?>