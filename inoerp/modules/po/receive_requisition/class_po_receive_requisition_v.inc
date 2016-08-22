<?php

class po_receive_requisition_v extends dbObject {

 public static $form_class_name = "po_requisition_header";
 public static $table_name = "po_receive_requisition_v";
 public static $primary_column = "po_requisition_detail_id";
 public $field_a = [
  'po_requisition_detail_id',
  'po_requisition_line_id',
  'po_requisition_header_id',
  'shipment_number',
  'subinventory_id',
  'locator_id',
  'req_quantity',
  'uom_id',
  'delivered_quantity',
  'req_line_number',
  'receving_org_id',
  'item_id_m',
  'item_number',
  'item_description',
  'line_description',
  'bu_org_id',
  'po_requisition_type',
  'po_requisition_number',
  'supply_org_id',
  'requisition_status',
  'sd_so_line_id',
  'sd_so_header_id',
  'so_line_number',
  'iso_line_quantity',
  'iso_shipped_quantity',
  'so_line_status',
  'so_number',
  'document_type',
  'order_source_type',
  'so_status',
 ];
 public $initial_search = [
  'so_number',
  'item_description',
  'po_requisition_number',
  'shipment_number',
  'so_status',
  'receving_org_id'
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=inv_ir_receipt_header',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Receive',
//  '_view_path' => 'form.php?class_name=po_requisition_header',
//  '_show_view_path' => 1,
////		 '_view_action_meassge' => 'View',
//  '_extra_path' => array('form.php?class_name=po_header&mode=9' => 'receive')
 ];
 public $pageTitle = " Requisition For Receving "; //page Title
 public $po_requisition_detail_id;
 public $po_requisition_line_id;
 public $po_requisition_header_id;
 public $shipment_number;
 public $subinventory_id;
 public $locator_id;
 public $req_quantity;
 public $uom_id;
 public $delivered_quantity;
 public $req_line_number;
 public $receving_org_id;
 public $item_id_m;
 public $item_number;
 public $item_description;
 public $line_description;
 public $bu_org_id;
 public $po_requisition_type;
 public $po_requisition_number;
 public $supply_org_id;
 public $requisition_status;
 public $sd_so_line_id;
 public $sd_so_header_id;
 public $so_line_number;
 public $iso_line_quantity;
 public $iso_shipped_quantity;
 public $so_line_status;
 public $so_number;
 public $document_type;
 public $order_source_type;
 public $so_status;

 private function create_po_receive_requisition_v() {
  $sql = "
CREATE OR REPLACE VIEW po_receive_requisition_v
(
po_requisition_detail_id, po_requisition_line_id, po_requisition_header_id , shipment_number, subinventory_id, locator_id,  
req_quantity,  delivered_quantity,
req_line_number , receving_org_id, item_id_m , item_number, item_description, line_description,
bu_org_id , po_requisition_type, po_requisition_number, supply_org_id, requisition_status,
uom_id, sd_so_line_id, sd_so_header_id , so_line_number,iso_line_quantity, iso_shipped_quantity, so_line_status,
so_number, document_type,order_source_type, so_status
)
AS
SELECT prd.po_requisition_detail_id, prd.po_requisition_line_id, prd.po_requisition_header_id , prd.shipment_number, prd.subinventory_id, prd.locator_id,  
prd.quantity, prd.delivered_quantity,
prl.line_number , prl.receving_org_id, prl.item_id_m , item.item_number, prl.item_description, prl.line_description,
prh.bu_org_id , prh.po_requisition_type, prh.po_requisition_number, prh.supply_org_id, prh.requisition_status,
soline.uom_id, soline.sd_so_line_id, soline.sd_so_header_id , soline.line_number, soline.line_quantity, soline.shipped_quantity, soline.line_status,
soh.so_number, soh.document_type,soh.order_source_type, soh.so_status

FROM po_requisition_detail prd,
po_requisition_line prl,
po_requisition_header prh,
sd_so_line soline,
sd_so_header soh,
item

WHERE prh.po_requisition_header_id = prl.po_requisition_header_id
AND prh.po_requisition_header_id = prd.po_requisition_header_id
AND prl.po_requisition_line_id = prd.po_requisition_line_id
AND soline.reference_doc_number = prd.po_requisition_detail_id
AND soline.reference_doc_type = 'po_requisition_detail'
AND soline.sd_so_header_id = soh.sd_so_header_id
AND item.item_id_m = item.item_id
AND item.item_id_m = prl.item_id_m

";
 }

 public function findBy_po_requisitionDetailId() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE po_requisition_detail_id = :po_requisition_detail_id ";
  $sql = ino_perPageSql_i($sql, 1);

  $value_a = ['po_requisition_detail_id' => $this->po_requisition_detail_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_po_requisitionDetailId($po_requisition_detail_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE po_requisition_detail_id = :po_requisition_detail_id ";
  $sql = ino_perPageSql_i($sql, 1);

  $value_a = ['po_requisition_detail_id' => $po_requisition_detail_id];
  $result = self::find_by_sql_i($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of po_requisition_detail class
?>