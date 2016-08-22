<?php

class extn_emessage_line extends dbObject {

 public static $table_name = "extn_emessage_line";
 public static $primary_column = "extn_emessage_line_id";
// public static $parent_primary_column = "extn_emessage_header_id";
 public static $key_column = 'text_message';
 public static $module = "extn";
 public $field_a = [
  'extn_emessage_line_id',
  'extn_emessage_header_id',
  'from_user_id',
  'user_id',
  'text_message',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'extn_emessage_header_id',
  'from_user_id',
  'user_id',
  'text_message',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "extn_emessage_header_id"
 ];
 public static $chat_mode_a = [
  'on' => 'Switche On',
  'off' => 'Switche Off'
 ];
 public $extn_emessage_line_id;
 public $extn_emessage_header_id;
 public $from_user_id;
 public $user_id;
 public $text_message;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_save() {
  if (empty($this->extn_emessage_header_id)) {
   if (!empty($_POST['user_id'][0])) {
    $msg_h = new extn_emessage_header();
    $msg_h->user_id = $_POST['user_id'][0];
    $msg_h->from_user_id = $_POST['from_user_id'][0];
    $msg_h->getnset_user_id_comb();
    $msg_h->save();
    $this->extn_emessage_header_id = $msg_h->extn_emessage_header_id;
   }
  }
 }

 Public static function find_by_parent_id_k($extn_emessage_header_id, $extn_emessage_line_id = '') {
  $sql = " SELECT  * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE extn_emessage_header_id='{$extn_emessage_header_id}' ";
  if (!empty($extn_emessage_line_id)) {
   $sql .= " AND extn_emessage_line_id < '{$extn_emessage_line_id}' ";
  }
  $sql .= " ORDER BY extn_emessage_line_id DESC ";
  $sql = ino_perPageSql_i($sql, 30);

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : ' ';
 }

}

//end of extn_emessage_line class
?>