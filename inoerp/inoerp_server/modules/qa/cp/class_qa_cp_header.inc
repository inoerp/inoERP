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
 * qa_cp_header
 *
 */
class qa_cp_header extends dbObject {

 public static $table_name = "qa_cp_header";
 public static $primary_column = "qa_cp_header_id";
 public static $dependent_classes = ['qa_cp_line'];
 public static $key_column = "plan_name";
 public static $module = "qa";
 public static $system_info = [
  'name' => 'Collection Plan',
  'number' => '2902',
  'description' => 'Quality Collection Plan',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'qa',
  'weight' => 11
 ];
 public $field_a = [
  'qa_cp_header_id',
  'plan_name',
//  'org_id',
  'effective_from',
  'description',
  'effective_to',
  'plan_type',
  'qa_specification_header_id',
  'specification_type',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'plan_name',
 ];
 public $requiredField = [
  'plan_name',
  'plan_type',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 
 ];
 
  public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
 public $pageTitle = " Collection Plan "; //page Title
 public $qa_cp_header_id;
 public $plan_name;
 public $org_id;
 public $effective_from;
 public $description;
 public $effective_to;
 public $plan_type;
 public $qa_specification_header_id;
 public $specification_type;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

// Public static function validation_types() {
//  $header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
//  $option_line = new option_line();
//  $lines = $option_line->findBy_parentId($header->option_header_id);
//  return $lines;
// }
}

//end of path class
?>