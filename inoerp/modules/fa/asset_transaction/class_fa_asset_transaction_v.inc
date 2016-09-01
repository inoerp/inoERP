<?php

class fa_asset_transaction_v extends dbObject {

 public static $form_class_name = "fa_asset_transaction_v";
 public static $table_name = "fa_asset_transaction_v";
 public static $primary_column = "fa_asset_transaction_id";
 public static $system_info = [
  'name' => 'Asset Transaction View',
  'number' => '1414',
  'description' => 'Fixed Asset Transaction View',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fa',
  'weight' => 6
 ];
 public $field_a = [
  'fa_asset_transaction_id',
  'asset_number',
  'tag_number',
  'serial_number',
  'key_number',
  'asset_description',
  'asset_book_name',
  'bu_org_id',
  'type',
  'book_description',
  'primary_fa_asset_book_id',
  'fa_asset_id',
  'fa_asset_book_info_id',
  'fa_asset_book_id',
  'transaction_type',
  'quantity',
  'amout',
  'gl_journal_header_id',
  'gl_journal_line_id',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
  'manufacturer',
  'model_number',
  'warrranty_number',
  'lease_number',
  'physical_inventory_cb',
 ];
 public $initial_search = [
  "asset_number",
  'asset_description',
  'asset_book_name',
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
  '_view_path' => 'form.php?class_name=fa_asset_transaction_v',
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Asset Transactions"; //page Title
 public $fa_asset_transaction_id;
 public $fa_asset_id;
 public $fa_asset_book_info_id;
 public $fa_asset_book_id;
 public $transaction_type;
 public $quantity;
 public $amout;
 public $gl_journal_header_id;
 public $gl_journal_line_id;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $asset_number;
 public $tag_number;
 public $serial_number;
 public $key_number;
 public $asset_description;
 public $manufacturer;
 public $model_number;
 public $warrranty_number;
 public $lease_number;
 public $physical_inventory_cb;
 public $asset_book_name;
 public $bu_org_id;
 public $type;
 public $primary_fa_asset_book_id;
 public $book_description;

 private function create_fa_asset_transaction_v() {
  $sql = "
CREATE OR REPLACE VIEW fa_asset_transaction_v
(
fa_asset_transaction_id, fa_asset_id, fa_asset_book_info_id, fa_asset_book_id,
transaction_type, quantity, amout, gl_journal_header_id, gl_journal_line_id,
description, created_by, creation_date, last_update_by,  last_update_date,
asset_number,  tag_number, serial_number, key_number, asset_description, manufacturer,
model_number, warrranty_number, lease_number, physical_inventory_cb, 
asset_book_name, bu_org_id, type, primary_fa_asset_book_id, book_description
)
AS
SELECT
fat.fa_asset_transaction_id, fat.fa_asset_id, fat.fa_asset_book_info_id, fat.fa_asset_book_id,
fat.transaction_type, fat.quantity, fat.amout, fat.gl_journal_header_id, fat.gl_journal_line_id,
fat.description, fat.created_by, fat.creation_date, fat.last_update_by,  fat.last_update_date,
ast.asset_number,  ast.tag_number, ast.serial_number, ast.key_number, ast.description as asset_description, ast.manufacturer,
ast.model_number, ast.warrranty_number, ast.lease_number, ast.physical_inventory_cb, 
fab.asset_book_name, fab.bu_org_id, fab.type, fab.primary_fa_asset_book_id, fab.description

from fa_asset_transaction fat,
fa_asset ast,
fa_asset_book fab

WHERE ast.fa_asset_id = fat.fa_asset_id
AND fab.fa_asset_book_id = fat.fa_asset_book_id

";
 }

 public static function find_by_assetId($fa_asset_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE fa_asset_id = :fa_asset_id ";
  $value_a = ['fa_asset_id' => $fa_asset_id];
  $result = self::find_by_sql_i($sql, $value_a);

//  $sql .= " WHERE fa_asset_id = '{$fa_asset_id}'  ";
//  $result = self::find_by_sql($sql);

  return !empty($result) ? ($result) : false;
 }

 public static function find_by_invSerialNumberId($fa_asset_number_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE fa_asset_number_id = '{$fa_asset_number_id}'  ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

}

//end of po_detail class
?>