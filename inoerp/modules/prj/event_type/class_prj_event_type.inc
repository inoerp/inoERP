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
 * prj_event_type
 * Contains all the prj_event_type information, such as - prj_event_type, prj_event_type_id, org_id,  type, etc.
 * 
 */
class prj_event_type extends dbObject {

 public static $table_name = "prj_event_type";
 public static $primary_column = "prj_event_type_id";
 public static $key_column = 'event_type';
 public static $module = "prj";
 public static $multi_select_template_path = 'modules/prj/event_type/multi_action/prj_event_type_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Event Type',
  'number' => '6010',
  'description' => 'prj_event_type',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 17
 ];
 public $field_a = [
  'prj_event_type_id',
  'event_type',
  'description',
  'event_class',
  'revenue_category',
  'effective_from',
  'effective_to',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'event_type',
  'description',
 ];
 public $requiredField = [
  'event_type',
  'event_class',
  'revenue_category',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Event Type "; //page Title
 public $prj_event_type_id;
 public $event_type;
 public $description;
 public $event_class;
 public $revenue_category;
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

//end of prj_event_type class
?>