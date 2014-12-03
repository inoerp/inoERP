<?php

class bc_static_label extends dbObject {

 public static $table_name = "bc_static_label";
 public static $primary_column = "bc_static_label_id";
 public static $key_column = "label_type";
 public static $module = "bc";
 public static $label_type_a = [
  'GENERIC' => 'Generic',
  'ORG' => 'Organization',
  'INV' => 'Inventory',
  'SUBINV' => 'Sub Inventory',
  'LOCATOR' => 'Locator',
  'ITEM' => 'Item'
 ];
 public $field_a = [
  'bc_static_label_id',
  'label_type',
  'bc_label_format_header_id',
  'status',
  'label_content',
  'sys_printer_id',
  'output_file_path',
  'file_name',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'bc_label_format_header_id',
  'label_type',
 ];
 public $requiredField = [
  'label_type',
  'bc_label_format_header_id',
 ];
 public $pageTitle = " Barcode Static Label"; //page Title
 public $bc_static_label_id;
 public $label_type;
 public $bc_label_format_header_id;
 public $status;
 public $label_content;
 public $sys_printer_id;
 public $output_file_path;
 public $file_name;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function findBy_transactionId_associationLevel($header_id, $assoc_level) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE transaction_type_id = :header_id AND association_level = :association_level ";

  $value_a = ['transaction_type_id' => $header_id, 'association_level' => $assoc_level];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? $result : false;
 }

 public function generate_label($data_obj) {
  if (empty($this->bc_label_format_header_id)) {
   echo "<br>bc_label_format_header_id missing!. No label generated. Error @bc_static_label @@ " . __LINE__;
   return;
  }
  $bc_lf = new bc_label_format_header();
  $bc_lf->findBy_id($this->bc_label_format_header_id);
  $bc_lfl_i = bc_label_format_line::find_by_parent_id($this->bc_label_format_header_id);

  $xml_content = '<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<!DOCTYPE labels SYSTEM "label.dtd">';
  $xml_content .= '<labels _FORMAT="' . $bc_lf->format_name . '" _QUANTITY="' . $this->quanity . '" _PRINTERNAME="SNG_ZM400_1" _JOBNAME="LBL512027">
<label>';

  foreach ($bc_lfl_i as $line) {
   $field_name = $line->sys_field_name;
   $xml_content .= '<variable name = "' . $field_name . '">';
   $xml_content .=!empty($data_obj->$field_name) ? $data_obj->$field_name : '';
   $xml_content .= '</variable>';
  }
  $xml_content .= '</label>
</labels>
';

  return $xml_content;
 }

}

?>