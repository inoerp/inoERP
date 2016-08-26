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
 * hr_leave_entitlement_header
 * All Leave Entitlements
 * Contains all the hr_leave_entitlement_header information, such as - entitlement_name, status , description, etc
 * 
 */
class hr_leave_entitlement_header extends dbObject {

 public static $table_name = "hr_leave_entitlement_header";
 public static $primary_column = "hr_leave_entitlement_header_id";
 public static $dependent_classes = ['hr_leave_entitlement_line'];
 public static $key_column = 'entitlement_name';
 public static $module = "hr";
 public static $system_info = [
  'name' => 'Leave Entitlement',
  'number' => '3204',
  'description' => 'HR Leave Entitlement',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 13
 ];
 public $field_a = [
  'hr_leave_entitlement_header_id',
  'entitlement_name',
  'description',
  'status',
  'job_id',
  'position_id',
  'employee_id',
  'leave_group',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'hr_leave_entitlement_header_id',
  'entitlement_name',
 ];
 public $requiredField = [
  'entitlement_name',
 ];
 public $pageTitle = " Entitlement Details "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $hr_leave_entitlement_header_id;
 public $entitlement_name;
 public $description;
 public $status;
 public $job_id;
 public $position_id;
 public $employee_id;
 public $leave_group;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_showing() {
  
 }

 Public static function find_all_lines_by_category($hr_leave_entitlement_header_id, $category = 'E_REGULAR') {
  if (empty($hr_leave_entitlement_header_id)) {
   return null;
  }
  $sql = " SELECT * 
       FROM hr_leave_entitlement_header eeh, 
       hr_leave_entitlement_line eel,
       hr_compensation_element hce
       WHERE eel.hr_leave_entitlement_header_id = eeh.hr_leave_entitlement_header_id
       AND eeh.hr_leave_entitlement_header_id = '{$hr_leave_entitlement_header_id}'
        AND hce.hr_compensation_element_id = eel.element_id
        
";
  if (is_array($category)) {
   $sql .= " AND hce.category IN " . "( '" . implode("','", $category) . "' )";
  } else {
   $sql .= " AND hce.category = '{$category}' ";
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 Public static function find_all_regular_lines($hr_leave_entitlement_header_id) {
  return self::find_all_lines_by_category($hr_leave_entitlement_header_id, 'E_REGULAR');
 }

 Public static function find_all_basic_lines($hr_leave_entitlement_header_id) {
  return self::find_all_lines_by_category($hr_leave_entitlement_header_id, 'E_BASIC');
 }

 Public static function find_all_basic_regular_lines($hr_leave_entitlement_header_id) {
  return self::find_all_lines_by_category($hr_leave_entitlement_header_id, array('E_BASIC', 'E_REGULAR'));
 }

 public static function find_by_employeeId($employee_id) {
  $sql = " SELECT * 
       FROM hr_leave_entitlement_header eeh 
       WHERE eeh.employee_id = '{$employee_id}'   
";
       $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of bom class
?>