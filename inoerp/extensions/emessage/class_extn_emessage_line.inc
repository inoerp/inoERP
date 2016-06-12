<?php

class extn_emessage_line extends dbObject {

 public static $table_name = "extn_emessage_line";
 public static $primary_column = "extn_emessage_line_id";
 public static $parent_primary_column = "extn_emessage_header_id";
 public static $key_column = 'text_message';
 public static $module = "extn";
 public $field_a = [
  'extn_emessage_line_id',
  'extn_emessage_header_id',
  'from_user_id',
  'to_user_id',
  'text_message',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'extn_emessage_header_id',
  'from_user_id',
  'to_user_id',
  'text_message',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "extn_emessage_header_id"
 ];
 public $extn_emessage_line_id;
 public $extn_emessage_header_id;
 public $from_user_id;
 public $to_user_id;
 public $text_message;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of extn_emessage_line class
?>