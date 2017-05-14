<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * inv_receipt_header
 * Contains all the inv_receipt_header infointerorgtion, such as - receipt_number, transaction_type_id, org_id,  receipt_date, etc.
 * 
 */
class inv_ir_receipt_header extends inv_receipt_header {
 
  public static $system_info = [
  'name' => 'IR Receipt',
  'number' => '2135',
  'description' => 'Inter Org Receipt',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('inv_intorg_transfer_line'),
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 6
 ];
  

 public static $table_name = "inv_receipt_header";
 public static $transaction_type_id_a = [
  '33' => 'Internal Requisition Receipt'
 ];
 public $search = [
  '_show_view_path' => 1,
  '_view_path' => 'form.php?class_name=inv_ir_receipt_header',
 ];

  public $pageTitle = "IR Receipt"; //page Title
  
 private function create_inv_ir_receipt_header() {
  $sql = "
CREATE OR REPLACE VIEW inv_ir_receipt_header
(
inv_receipt_header_id,  receipt_number,   org_id,   transaction_type_id,
  receipt_date,  received_by,   carrier,   vehicle_number,   comment,   ef_id,
  created_by,   creation_date,   last_update_by,   last_update_date
)
AS
SELECT 
SELECT * FROM inv_receipt_header
WHERE transaction_type_id = '33'

";
 }

 public function multi_select_input_fields() {
  $multi_select_input = [
   'transaction_quantity',
   'subinventory_id',
   'locator_id',
  ];
  return $multi_select_input;
 }

 public function multi_select_tabs() {
  return inv_lot_number::show_serialLot_entryForm();
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'action_class_name',
   'mode',
   'action',
   'show_block',
  ];

  return $multi_select_hidden;
 }

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

inv_ir_receipt_header::staticVar_init('transaction_type_id_a');
?>
