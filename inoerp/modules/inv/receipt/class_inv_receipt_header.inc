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
class inv_receipt_header extends dbObject {

 public static $table_name = "inv_receipt_header";
 public static $dependent_classes = ['inv_receipt_line', 'po_all_v'];
 public static $primary_column = "inv_receipt_header_id";
 public static $primary_column2 = "receipt_number";
 public static $key_column = 'org_id';
 public static $module = "inv"; //same as gl_journal_source
 public static $gl_journal_category = "INV_RECEIVING";
 public static $js_fileName = 'modules/inv/receipt/extra/extra_inv_receipt.js';
  public static $system_info = [
  'name' => 'INV Receipt',
  'number' => '2126',
  'description' => 'Inventory Receipt',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('inv_receipt_line'),
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 12
 ];
public static $transaction_type_id_a = [
// '4' => 'PO Receipt',
 '5' => 'PO Delivery',
 '21' => 'PO Return'
];

public $action_a = [
 'CREATE_ACCOUNT' => 'Create Accounting',
 'ADD_LINES' => 'Add Lines',
 'PRINT_TRAVELLER' => 'Print Traveller'
];
  
 public $field_a = [
  "inv_receipt_header_id",
  "receipt_number",
  "org_id",
  "transaction_type_id",
  "receipt_date",
  "received_by",
  "carrier",
  "vechile_number",
  "comment",
  "ef_id",
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
//variables used for showing data

 public $initial_search = [
  "inv_receipt_header_id",
  "receipt_number",
  "org_id",
  "org",
  "receipt_date",
  "received_by",
  "transaction_type_id",
 ];

 public $fields_inForm_notInDataBase = [
  "org",
  'multi_action_class_pc',
  'multi_action_class_pc_value',
  'action'
 ];
 public $requiredField = [
  "org_id",
  "receipt_date"
 ];
 public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
 public $search = [
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Inventory Receipt"; //page Title
 public $option_lists = [
  'inv_transaction_class' => 'TRANSACTION_TYPE_CLASS'
 ];
 public $inv_receipt_header_id;
 public $receipt_number;
 public $org_id;
 public $transaction_type_id;
 public $receipt_date;
 public $received_by;
 public $carrier;
 public $vehicle_number;
 public $comments;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 public $action;

 public function _before_save() {
//  pa($this);
//  pa($_POST);
  if (($this->action == 'multi_receipt' || $this->action == 'po_receipt')) {
   echo "<br> Starting Receipt.";
   $this->_po_multi_receipt();
   return 10;
  }
 }

 private function _po_multi_receipt() {
  if (!empty($_POST['line_id_cb'])) {
   $this->transaction_type_id = 5;
   $this->receipt_date = current_time(true);
   try {
    $this->save();
    $this->_after_save();
   } catch (Exception $e) {
    echo "<br>Failed to save the receipt header. Error @ inv_receipt_header @@ " . __LINE__ . '<br>' . $e->getMessage();
   }
   $line_num = 1;
   foreach ($_POST['line_id_cb'] as $k => $v) {
    $inv_rl = new inv_receipt_line();
    $inv_rl->inv_receipt_header_id = $this->inv_receipt_header_id;
    $inv_rl->transaction_type_id = $this->transaction_type_id;
    $inv_rl->line_number = $line_num;
    $line_num++;
    $inv_rl->subinventory_id = $_POST['subinventory_id'][$k];
    $inv_rl->locator_id = $_POST['locator_id'][$k];
    $inv_rl->item_id_m = $_POST['item_id_m'][$k];
    $inv_rl->revision_name = $_POST['revision_name'][$k];
    $inv_rl->line_description = $_POST['item_description'][$k];
    $inv_rl->uom_id = $_POST['uom_id'][$k];
    $inv_rl->transaction_quantity = $_POST['transaction_quantity'][$k];
    $inv_rl->ref_doc_type = 'po_header';
    $inv_rl->ref_doc_number = $_POST['po_number'][$k];
    $inv_rl->po_header_id = $_POST['po_header_id'][$k];
    $inv_rl->po_line_id = $_POST['po_line_id'][$k];
    $inv_rl->po_detail_id = $_POST['po_detail_id'][$k];
    $inv_rl->org_id = $this->org_id;
    try {
     $inv_rl->save();
      $inv_rl->_after_save();
    } catch (Error $e) {
     echo "<br>Failed to save the receipt header. Error @ inv_receipt_header @@ " . __LINE__ . '<br>' . $e->getMessage();
    }
   }
  }
 }

 public function _after_save() {
  if ((!empty($this->inv_receipt_header_id)) && empty($this->receipt_number)) {
   $inv_receipt_header_id = $this->inv_receipt_header_id;
   $org_id = $this->org_id;
   $this->receipt_number = $org_id . '-' . $inv_receipt_header_id;
   echo '<br/> System created reecipt number is ' . $this->receipt_number;
   $this->save();
  }

  return $this->msg;
 }
 
 public static function bc_label_data(){
  
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

inv_receipt_header::staticVar_init('transaction_type_id_a');
?>
