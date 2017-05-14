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
 * Contains all the inv_receipt_header information, such as - receipt_number, transaction_type_id, org_id,  receipt_date, etc.
 * 
 */
class inv_rma_receipt_header extends inv_receipt_header {
 
 public static $transaction_type_id_a = [
 '23' => 'RMA Delivery'
];
  
 
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

inv_rma_receipt_header::staticVar_init('transaction_type_id_a');
?>
