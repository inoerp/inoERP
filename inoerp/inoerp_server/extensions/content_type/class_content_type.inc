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
 * 
 *
 */
class content_type extends dbObject {

 public static $table_name = "content_type";
 public static $primary_column = "content_type_id";
 public static $key_column = "content_type";
 public static $dependent_classes = ['new_content_type', 'content_type_reference'];
 public static $module = "extension";
 public static $js_fileName = 'extensions/content_type/content_type.js';
 public static $system_info = [
  'name' => 'Content Type',
  'number' => '10030',
  'description' => 'Used for creating different type of contents. Such as Forum, Documentation, etc',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('block_content'),
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 30
 ];
 public static $comment_order_by_a = [
  'DATE_ASC' => 'Date Newest First',
  'DATE_DESC' => 'Date Oldest First',
 ];
 public $field_a = [
  "content_type_id",
  "allow_file_cb",
  "content_type",
  'read_role',
  'write_role',
  'update_role',
  "description",
  "has_subject_cb",
  "subject_label",
  "has_content_cb",
  "content_label",
  'summary_display_type',
  'allow_comment_cb',
  'comment_read_role',
  'comment_write_role',
  'comment_update_role',
  'comment_order_by',
  'comments_perpage',
  'auto_url_alias_cb',
  'show_category_onsummary_cb',
  "rev_enabled_cb",
  "rev_number",
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
//variables used for showing data

 public static $newField_array = [
  "field_label",
  "field_position",
  "field_name",
  "field_num",
  "field_type",
  "field_enum",
  "option_type"
 ];
 public $initial_search = [
  "content_type_id",
  "content_type",
  "description",
  'summary_display_type'
 ];
 public $column = [
  "content_type_id",
  "allow_file_cb",
  "content_type",
  "description",
  "subject_label",
  "content_label",
  'summary_display_type',
 ];
 public $checkbox = [
  "allow_file_cb",
  'allow_comment_cb',
  "has_subject_cb",
  "has_content_cb",
  "rev_enabled_cb",
  'show_category_onsummary_cb'
 ];
 public $fields_inForm_notInDataBase = [
  'field_num',
  'field_enum',
  'multi_action_class_pc',
  'multi_action_class_pc_value',
  'action'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public $base_encoded_array = [];
 public $requiredField = [
  "content_type",
  "description"
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " Content Types - Find All Content Types "; //page Title
// public $option_list = [
//		 'calendar_option_line_code' => 'GL_CALENDAR_NAME',
//		 'currency_code' => 'CURRENCY'
// ];
 public $category_id;
 public $content_type_id;
 public $content_type;
 public $allow_comment_cb;
 public $allow_file_cb;
 public $description;
 public $read_role;
 public $write_role;
 public $update_role;
 public $comment_read_role;
 public $comment_write_role;
 public $comment_update_role;
 public $comment_order_by;
 public $comments_perpage;
 public $has_subject_cb;
 public $has_content_cb;
 public $subject_label;
 public $content_label;
 public $summary_display_type;
 public $auto_url_alias_cb;
 public $show_category_onsummary_cb;
 public $rev_enabled_cb;
 public $rev_number;
 public $content_type_id_l;
 public $field_label;
 public $field_position;
 public $field_name;
 public $field_num;
 public $field_enum;
 public $field_type;
 public $option_type;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 public $action;

 Public static function summary_display_type() {
  $option_header = option_header::find_by_name('EXT_SUMMARY_DISPLAY_TYPE');
  $result = option_line::find_by_option_id($option_header->option_header_id);
  return $result;
 }

 Public static function content_field_type() {
  $option_header = option_header::find_by_name('EXT_CONTENT_FIELD_TYPE');
  $option_line = new option_line();
  $result = $option_line->findBy_parentId($option_header->option_header_id);
  return $result;
 }

 public function _after_save() {
  global $db;
  if ((!empty($_POST['field_name'])) && (count($_POST['field_name']) > 0)) {
   for ($i = 0; $i < count($_POST['field_name']); $i++) {
//		print_r($_POST['field_num']);
    //create or update the new content type /table
    $content_type_id = $this->content_type_id;
    $field_record = new new_content_type;
    foreach (content_type::$newField_array as $key => $values) {
     if (!empty($_POST[$values][$i])) {
      $field_record->$values = trim(mysql_prep($_POST[$values][$i]));
     } else {
      $field_record->$values = "";
     }
    }
    $enum_array = explode(",", $this->field_enum);
    $field_record->content_type = trim(mysql_prep($_POST['content_type'][0]));
//		echo "<div class='message>'<br>going for save table field $i </div>";
    $new_fild_entry = $field_record->save_table_field($enum_array);
//		echo "<div class='message>'<br>coming out of field $i </div>";
    if ($new_fild_entry) {
     $newMsg = 'Record is Successfully saved';
    }

    //create or update the field_reference_table
    $content_type_reference_record = new content_type_reference;
    foreach ($content_type_reference_record->field_a as $key => $values) {
     if (!empty($_POST[$values][$i])) {
      $content_type_reference_record->$values = trim(mysql_prep($_POST[$values][$i]));
     } else {
      $content_type_reference_record->$values = "";
     }
    }

    if (!empty($_POST['required_cb'])) {
     if (in_array($content_type_reference_record->field_name, $_POST['required_cb'])) {
      $content_type_reference_record->required_cb = 1;
     } else {
      $content_type_reference_record->required_cb = 0;
     }
    }
    $content_type_reference_record->content_type_id = $content_type_id;
    $content_type_reference_record->save();
//		echo "<div class='message>'<br>coming out after reference $i </div>";
   }
  }
 }

 public static function find_by_content_type($content_type) {
  $sql = "SELECT * FROM " . self::$table_name . " where content_type='{$content_type}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_summary_by_id($content_type_id) {
  $selectFields = ' SUBSTRING(content,1,2000) AS content_summary , ' .
   implode(", ", self::$field_array);
  $sql = "SELECT " . $selectFields . " FROM "
   . self::$table_name . " 
            where content_type_id={$content_type_id} ";
            $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function drop_column($content_name, $field_name) {
  global $dbc;
  $table_name = 'c_' . $content_name;
  $sql = " ALTER TABLE $table_name";
  $sql .=" DROP COLUMN $field_name";

  if ($dbc->ddlexecute($sql)) {
   $msg = 1;
  } else {
   $msg = 0;
  }
  return $msg;
 }

 public function drop_table($content_name) {
  global $dbc;
  $table_name = 'c_' . $content_name;
  $sql = " DROP TABLE IF EXISTS $table_name";
  if ($dbc->ddlexecute($sql)) {
   $msg = 1;
  } else {
   $msg = 0;
  }

  if ($msg == 1) {
   $content_type = self::find_by_content_type($content_name);
   $this->content_type_id = $content_type->content_type_id;
   $result = $this->delete();
   if ($result == 1) {
    $msg = 11;
   } else {
    $msg = 10;
   }
  }


  if ($msg == 11) {
   $ctype_path = new path();
   $path = $ctype_path->find_by_name($content_name);
   $result = $ctype_path->delete($path->path_id);
   if ($result == 1) {
    $msg = 111;
   } else {
    $msg = 110;
   }
  }


  return $msg;
 }

 public function multi_select_input_fields() {
  $multi_select_input = [
  ];
  return $multi_select_input;
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

 public function multi_select_verification(&$error_msg = '') {

  if (!empty($any_record)) {
   $error_msg = "<div class='error'>Content types deleted from this form wont drop the corresponding table."
    . "Use this page only to delete content type whose table doesnt exists </div>";
  }
  return $error_msg;
 }

}

//end of content_type class
?>