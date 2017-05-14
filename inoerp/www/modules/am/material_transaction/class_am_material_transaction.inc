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
 * am_material_transaction 
 *
 */
class am_material_transaction extends inv_transaction {

 public static $table_name = "inv_transaction";
 public static $primary_column = "inv_transaction_id";
 public static $key_column = 'item_id_m';
 public static $module = "am";
 public static $system_info = [
  'name' => 'AM Material Transaction',
  'number' => '4105',
  'description' => 'AM Work Order Material Transaction',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'am',
  'weight' => 3
 ];
 public static $transaction_type_id_a = [
  '24' => 'WO Issue',
  '25' => 'WO Return',
 ];
 
 //variables used for showing data

 public $initial_search = [
  "inv_transaction_id",
  "transaction_type_id",
  'inv_transaction_class',
  'status',
  "item_id_m",
  "org_id",
  "item_number",
  "creation_date",
  "document_type",
  "document_number"
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "org_id",
  "transaction_type_id"
 ];
 public $requiredField = [
  "item_number",
  "uom_id",
  "quantity",
  "org_id",
  "item_id_m",
  "transaction_type_id"
 ];
 public $search = [
  '_show_view_path' => 1,
 ];
 public $pageTitle = " WIP Material Transaction"; //page Title
 public $option_lists = [
//  'inv_transaction_class' => 'TRANSACTION_TYPE_CLASS'
 ];
 public $fields_inForm_notInDataBase = [
  "account_id",
  'item_description',
  'am_wo_bom_id',
  'am_wo_header_id',
  'bom_sequence'
 ];
 public $am_wo_bom_id;
 public $bom_sequence;
 public $am_wo_header_id;

}

//end of inv_transaction class
?>