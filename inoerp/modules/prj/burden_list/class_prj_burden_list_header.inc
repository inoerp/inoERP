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
 * prj_burden_list_header
 * Contains all the prj_burden_list_header information, such as - price_list, module_name, description,  currency_code, etc.
 * 
 */
class prj_burden_list_header extends dbObject {

 public static $table_name = "prj_burden_list_header";
 public static $primary_column = "prj_burden_list_header_id";
 public static $dependent_classes = ['prj_burden_list_line'];
 public static $key_column = "burden_list";
 public static $module = "prj";
 public static $system_info = [
  'name' => 'Burden List',
  'number' => '6006',
  'description' => 'Define and Mainten Burden List',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'dependent_class' => array('prj_burden_list_line'),
  'primary_entity_cb' => '',
  'module_name' => 'mdm',
  'weight' => 2
 ];
 public $field_a = [
  'prj_burden_list_header_id',
  'burden_list',
  'prj_burden_structure_header_id',
  'description',
  'effective_from',
  'effective_to',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'burden_list',
  'prj_burden_structure_header_id',
 ];
 public $requiredField = [
  'burden_list'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Burden List "; //page Title
 public $prj_burden_list_header_id;
 public $burden_list;
 public $prj_burden_structure_header_id;
 public $description;
 public $effective_from;
 public $effective_to;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

// function __construct() {
//	global $dbc;
//	$sql_fields = " SHOW COLUMNS FROM  " . self::$table_name;
//	$prepare = $dbc->connection->prepare($sql_fields);
//	$prepare->execute();
//	$this->field_a = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
// }

 
}

//end of path class
?>
