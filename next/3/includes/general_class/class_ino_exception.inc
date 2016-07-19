<?php

class ino_exception extends dbObject {
 /* File exception are stored in server as log files
  * DB Exceptions are stored in data base table exceptions
  * page Exceptions are shown to user on web page
  */

 public $page_exception = [];
 public $file_exception = [];
 public $db_exception = [];
 public $message = [];
 public $exception_type = [
  1 => 'page',
  2 => 'file',
  3 => 'db'];
// protected static $table_name = "exception";
 public static $initial_search_array = [
  'exception_id',
  'exception',
  'module',
  'description'
 ];
 public static $column_array = [
  'exception_id',
  'exception',
  'module',
  'description'
 ];
 public static $account_array = [
 ];
 public static $checkbox_array = [
  'rev_enabled_cb',
 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $requiredField_array = [
  'exception',
  'module',
  'description'
 ];
 public static $primary_column = 'exception_id';
 public static $field_array = [];
 public $user_exp = [];
 public $exception_id;
 public $description;
 public $module;
 public $type;
 public $status;
 public $rev_enabled;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;

 function __construct() {
  if (isset($this->user_exp)) {
   unset($this->user_exp);
  }
 }

 public function show_pageErrors($ie_array_page = '') {
  if (!empty($ie_array_page)) {
   $show_message = '<ul class="page_error">';
   $error_count = 1;
   foreach ($ie_array_page as $error) {
    $show_message .= '<li>Error ' . $error_count . ' : ' . $error->description . ' <br> ' . $error->message . '</li>';
   }
   $show_message .= '</ul>';
   $error_count ++;
  }
  return !empty($show_message) ? $show_message : false;
 }

}

$ino_exception = new ino_exception();
$ie = &$ino_exception;
?>