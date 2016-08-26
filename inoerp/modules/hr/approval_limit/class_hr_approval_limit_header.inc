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
 * hr_approval_limit_header
 * Approval limit used for various document approvals
 * Contains all the conversion information, such as - limit_name, bu_org_id , status, etc
 * 
 */
class hr_approval_limit_header extends dbObject {

 public static $table_name = "hr_approval_limit_header";
 public static $primary_column = "hr_approval_limit_header_id";
 public static $dependent_classes = ['hr_approval_limit_line'];
 public static $key_column = 'limit_name';
 public static $module = "hr";
 public static $system_info = [
  'name' => 'Approval Limit',
  'number' => '3101',
  'description' => 'HR Approval Limit',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hr_approval_limit_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 1
 ];
 public $field_a = [
  'hr_approval_limit_header_id',
  'bu_org_id',
  'limit_name',
  'description',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'hr_approval_limit_header_id',
  'limit_name',
 ];
 public $requiredField = [
  'bu_org_id',
  'limit_name',
 ];
 public $pageTitle = " Approval Limit "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $hr_approval_limit_header_id;
 public $bu_org_id;
 public $limit_name;
 public $description;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_showing() {
  
 }

 Public static function find_all_lines_by_category($hr_approval_limit_header_id, $category = 'E_REGULAR') {
  if (empty($hr_approval_limit_header_id)) {
   return null;
  }
  $sql = " SELECT * 
       FROM hr_approval_limit_header eeh, 
       hr_approval_limit_line eel,
       hr_compensation_element hce
       WHERE eel.hr_approval_limit_header_id = eeh.hr_approval_limit_header_id
       AND eeh.hr_approval_limit_header_id = '{$hr_approval_limit_header_id}'
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

 Public static function find_all_regular_lines($hr_approval_limit_header_id) {
  return self::find_all_lines_by_category($hr_approval_limit_header_id, 'E_REGULAR');
 }

 Public static function find_all_basic_lines($hr_approval_limit_header_id) {
  return self::find_all_lines_by_category($hr_approval_limit_header_id, 'E_BASIC');
 }

 Public static function find_all_basic_regular_lines($hr_approval_limit_header_id) {
  return self::find_all_lines_by_category($hr_approval_limit_header_id, array('E_BASIC', 'E_REGULAR'));
 }

 public static function find_by_employeeId($employee_id) {
  $sql = " SELECT * 
       FROM hr_approval_limit_header eeh 
       WHERE eeh.employee_id = '{$employee_id}'   
";
       $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of bom class
?>