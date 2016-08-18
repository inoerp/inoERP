<?php

class bc_label_request extends dbObject {

 public static $table_name = "bc_label_request";
 public static $primary_column = "bc_label_request_id";
 public static $key_column = "association_level_value";
 public static $module = "sys";
 public static $system_info = [
  'name' => 'Label Requst',
  'number' => '9203',
  'description' => 'Barcode label request',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'bc',
  'weight' => 3
 ];
 public $field_a = [
  'bc_label_request_id',
  'transaction_type_id',
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
 ];
 public $requiredField = [
  'bc_label_format_header_id',
  'label_content',
 ];
 public $pageTitle = " Barcode Label Request "; //page Title
 public $bc_label_request_id;
 public $transaction_type_id;
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
 public $quanity = 1;

 public function findBy_transactionId_associationLevel($header_id, $assoc_level) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE transaction_type_id = :header_id AND association_level = :association_level ";

  $value_a = ['transaction_type_id' => $header_id, 'association_level' => $assoc_level];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? $result : false;
 }

 public static function find_by_transactionId_associationLevel($transaction_type_id, $assoc_level = '') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE transaction_type_id = '{$transaction_type_id}' ";
  if (!empty($assoc_level)) {
   $sql .= "  AND association_level = '{$assoc_level}' ";
  }

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public function generate_label($data_obj) {
  if (empty($this->bc_label_format_header_id)) {
   echo "<br>bc_label_format_header_id missing!. No label generated. Error @bc_label_request @@ " . __LINE__;
   return;
  }
  $bc_lf = new bc_label_format_header();
  $bc_lf->findBy_id($this->bc_label_format_header_id);
  $bc_lfl_i = bc_label_format_line::find_by_parent_id($this->bc_label_format_header_id);

  $xml_content = '<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<!DOCTYPE labels SYSTEM "label.dtd">';
  $xml_content .= '<labels _FORMAT="' . $bc_lf->format_name . '" _QUANTITY="' . $this->quanity . '" _PRINTERNAME="SNG_ZM400_1" _JOBNAME="LBL512027">
<label>';

//  pa($data_obj);

  foreach ($bc_lfl_i as $line) {
   $sys_field_name = $line->sys_field_name;
//   echo " <br> $sys_field_name ";
   $xml_content .= '<variable name = "' . $line->field_name . '">';
   $xml_content .=!empty($data_obj->$sys_field_name) ? $data_obj->$sys_field_name : '';
   $xml_content .= '</variable>';
  }
  $xml_content .= '</label>
</labels>
';

  return $xml_content;
 }

 public function print_XMLlabel($xml_content) {
  $comment = new extn_comment();
  $comment->reference_table = 'bc_label_label_request';
  $comment->reference_id = 'bc_label_label_request';

  if (empty($this->sys_printer_id)) {
   $comment->comment = '<br>No printer found!';
   $comment->save();
   return;
  }

  $printer = new sys_printer();
  $printer->findBy_id($this->sys_printer_id);

  if (!($sock = socket_create(AF_INET, SOCK_STREAM, 0))) {
   $errorcode = socket_last_error();
   $errormsg = socket_strerror($errorcode);
   $comment->comment = "<br>Couldn't create socket: [$errorcode] $errormsg \n";
   $comment->save();
   return;
  }

//Connect socket to remote server
  if (!socket_connect($sock, $printer->ip_address, $printer->port_number)) {
   $errorcode = socket_last_error();
   $errormsg = socket_strerror($errorcode);
   $comment->comment = "<br>Couldn't connect : [$errorcode] $errormsg \n";
   $comment->save();
   return;
  }



//$message = "GET / HTTP/1.1\r\n\r\n";
//Send the message to the server
  if (!socket_send($sock, $xml_content, strlen($xml_content), 0)) {
   $errorcode = socket_last_error();
   $errormsg = socket_strerror($errorcode);
   $comment->comment = "<br>Couldn't send data : [$errorcode] $errormsg \n";
   $comment->save();
   return;
  }
 }

}

?>