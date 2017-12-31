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
 * prj_burden_costcode
 * Contains all the prj_burden_costcode information, such as - prj_burden_costcode, prj_burden_costcode_id, org_id,  type, etc.
 * 
 */
class prj_burden_costcode extends dbObject {

 public static $table_name = "prj_burden_costcode";
 public static $primary_column = "prj_burden_costcode_id";
 public static $key_column = 'costcode';
 public static $module = "prj";
 public static $multi_select_template_path = 'modules/prj/burden_costcode/multi_action/prj_burden_costcode_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Burden Cost Code',
  'number' => '6005',
  'description' => 'prj_burden_costcode',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 17
 ];
 public $field_a = [
  'prj_burden_costcode_id',
  'costcode',
  'description',
  'prj_exependiture_type_id',
  'effective_from',
  'effective_to',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'costcode',
  'description',
 ];
 public $requiredField = [
  "costcode",
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Burdden Cost Code"; //page Title
 public $prj_burden_costcode_id;
 public $costcode;
 public $description;
 public $prj_exependiture_type_id;
 public $effective_from;
 public $effective_to;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of prj_burden_costcode class
?>