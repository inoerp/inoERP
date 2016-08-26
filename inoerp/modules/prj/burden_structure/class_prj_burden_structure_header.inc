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
 * hd_ro_header CLass
 * Contains all the prj_burden_structure_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class prj_burden_structure_header extends dbObject {

 public static $table_name = "prj_burden_structure_header";
 public static $dependent_classes = ['prj_burden_struct_costcode', 'prj_burden_struct_exptype'];
 public static $primary_column = "prj_burden_structure_header_id";
 public static $key_column = 'structure';
 public static $module = "prj";
 public static $system_info = [
  'name' => 'Burden Structure',
  'number' => '6007',
  'description' => 'Create & Mainten Burden Structure',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('prj_burden_struct_costcode', 'prj_burden_struct_exptype'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 1
 ];
 public static $structure_type_a = [
  'A' => 'Additive',
  'P' => 'Precedece',
 ];
 public $field_a = [
  'prj_burden_structure_header_id',
  'structure',
  'structure_type',
  'description',
  'allow_override_cb',
  'effective_from',
  'effective_to',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'structure',
 ];
 public $fields_inForm_notInDataBase = [
  'action',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1
 ];
 public $pageTitle = " Burden Structure "; //page Title
 public $prj_burden_structure_header_id;
 public $structure;
 public $structure_type;
 public $description;
 public $allow_override_cb;
 public $effective_from;
 public $effective_to;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;

 Public static function so_types() {
  $option_header = option_header::find_by_name('SO_TYPE');
  $so_types = option_line::find_by_option_id($option_header->option_header_id);
  return $so_types;
 }

}

//end of prj_burden_structure_header class
?>