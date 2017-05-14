<?php

 class cc_co_line extends dbObject {

  public static $table_name = "cc_co_line";
  public static $primary_column = "cc_co_line_id";
  public static $parent_primary_column = "cc_co_header_id";
  public static $key_column = 'item_id_m';
  public static $module = "cc";
  public static $value_type_a = [
   'TEXT' => 'Text',
   'SELECT' => 'Select',
   'MULTI_SELECT' => 'Multi Select',
   'TEXT_AREA' => 'Text Area',
   'CHECK_BOX' => 'Check Box',
  ];
  public $field_a = [
   'cc_co_line_id',
   'cc_co_header_id',
   'item_id_m',
   'item_description',
   'new_revision',
   'status',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   "cc_co_header_id"
  ];
  public $requiredField = [
   'cc_co_header_id',
   'item_id_m',
  ];
  public $fields_inFormr_notinDataBase = [
   "field_name",
   'item_number',
  ];
  public $cc_co_line_id;
  public $cc_co_header_id;
  public $item_id_m;
  public $item_description;
  public $new_revision;
  public $status;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $item_number;

  public function _after_save() {
   global $dbc;
//   pa($this);
//   pa($_POST);

   if (empty($_POST['template_id'][0])) {
    return;
   }
   $templ_lines = cc_co_template_line::find_by_parent_id($_POST['template_id'][0]);

   foreach ($templ_lines as $obj) {
    $field_name_id = $obj->field_name . '_valueId';
//    pa($obj);
    if (!empty($_POST[$obj->field_name][0])) {
     $co_lv = new cc_co_line_value();
     $co_lv->cc_co_line_id = $this->cc_co_line_id;
     $co_lv->cc_co_template_line_id = $obj->cc_co_template_line_id;
     $co_lv->field_value = isset($_POST[$obj->field_name][0]) ? $_POST[$obj->field_name][0] : null;
     $co_lv->cc_co_line_value_id = !empty($_POST[$field_name_id][0]) ? $_POST[$field_name_id][0] : null;
     try {
      $co_lv->save();
     } catch (Exception $e) {
      $dbc->rollback = true;
      echo "<br>Failed to save the values. Error @ cc_co_line @@ " . __LINE__ . $e->getMessage();
     }
    } else if (substr($obj->field_name, -3) == '_cb') {
     $co_lv = new cc_co_line_value();
     $co_lv->cc_co_line_id = $this->cc_co_line_id;
     $co_lv->cc_co_template_line_id = $obj->cc_co_template_line_id;
     $co_lv->field_value = false;
     $co_lv->cc_co_line_value_id = !empty($_POST[$field_name_id][0]) ? $_POST[$field_name_id][0] : null;
     try {
      $co_lv->save();
     } catch (Exception $e) {
      $dbc->rollback = true;
      echo "<br>Failed to save the values. Error @ cc_co_line @@ " . __LINE__ . $e->getMessage();
     }
    }
   }

//   pa($templ_lines);
   return;
  }

  
public static   function co_field_stmt($field_object, $lin_val_obj) {
  global $f;
  $f = new inoform();
  $field_value = !empty($lin_val_obj->field_value) ? $lin_val_obj->field_value : '';
  $field_value_id = !empty($lin_val_obj->cc_co_line_value_id) ? $lin_val_obj->cc_co_line_value_id : '';
//  pa($field_object);
  $field_stmt = '';
  $field_name_id = $field_object->field_name . '_valueId';
  switch ($field_object->value_type) {
   case 'SELECT':
   case 'OPTION_LIST' :
    if (!empty($field_object->list_values)) {
     $arr = explode(',', unserialize($field_object->list_values));
     $arr = array_combine($arr, $arr);
     $field_stmt .= $f->select_field_from_array($field_object->field_name, $arr, $field_value);
    } else if (!empty($field_object->list_value_option_type)) {
     $field_stmt .= $f->select_field_from_object($field_object->field_name, option_line::find_by_parent_id($field_object->list_value_option_type), 'option_line_code', 'option_line_value', $field_value);
    } else {
     $field_stmt .= $f->text_field($field_object->field_name, $field_value);
    }
    break;

   case 'BOOLEAN' :
   case 'CHECK_BOX' :
    $field_stmt .= $f->checkBox_field($field_object->field_name, $field_value);
    break;

   case 'FILE' :
    $field_object_file_name = $field_object->field_name . '_file';
    $file_details = extn_file::find_by_fieldName_referenceTable_and_id($field_object->field_name, 'cc_co_line', $field_value);
    $field_stmt .= ino_attachement($file_details, $field_object_file_name);
    $field_stmt .= $f->hidden_field($field_object->field_name, $field_value);
    break;

   default :
    $field_stmt .= $f->text_field($field_object->field_name, $field_value);
    break;
  }
  $field_stmt .= $f->hidden_field($field_name_id, $field_value_id);
  $field_stmt .= '';

  return $field_stmt;
 }
 }

//end of inv_transaction class
?>