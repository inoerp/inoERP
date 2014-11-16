<?php

class cc_co_header extends dbObject {

 public static $table_name = "cc_co_header";
 public static $primary_column = "cc_co_header_id";
 public static $dependent_classes = ['cc_co_line', 'cc_co_line_value'];
 public static $key_column = 'change_number';
 public static $module = "cc";
 public $field_a = [
  'cc_co_header_id',
  'org_id',
  'change_number',
  'status',
  'security_level',
  'template_id',
  'change_type',
  'originator',
  'description',
  'reason_code',
  'product_line',
  'process_flow_header_id',
  'current_process_flow_line_id',
  'origination_date',
  'owner_user_id',
  'release_date',
  'completion_date',
  'project_task_id',
  'access_org',
  'related_changes',
  'priority',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public static $change_type_a = [
  'ECO' => 'Engineering',
  'MCO' => 'Manufacturing'
 ];
 public static $status_a = [
  'INCOMPLETE' => 'Incomplete',
  'INPROCESS' => 'In Process',
  'APPROVED' => 'APPROVED',
  'READY_FOR_RELEASE' => 'Ready for Release',
  'RELEASED' => 'Release',
  'IMPLEMENTED' => 'Implemented',
 ];
 public $initial_search = [
  'change_number'
 ];
 public $requiredField = [
  'org_id',
  'change_number',
  'template_id',
  'change_type',
 ];
 public $pageTitle = " Change Order "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $change_number;
 public $status;
 public $security_level;
 public $template_id;
 public $change_type;
 public $originator;
 public $description;
 public $reason_code;
 public $product_line;
 public $process_flow_header_id;
 public $current_process_flow_line_id;
 public $origination_date;
 public $owner_user_id;
 public $release_date;
 public $completion_date;
 public $project_task_id;
 public $access_org;
 public $related_changes;
 public $priority;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $action;
 public $prg_implement_co_parameters = [
  'Organization' => 'search_org_name',
//  'Change Order Number' => 'search_co_number',
  'Implement All' => 'search_implement_all_cb',
 ];
 public $prg_implement_co_details = [
  'name' => 'Implement Change Order',
  'description' => 'Implement ',
  'Item To' => 'search_item_number_to'
 ];

 public function _before_save() {
  if (!empty($_POST['action'][0])) {
   $this->status = $_POST['action'][0];
  }
 }

 Public static function find_all_lines_by_category($cc_co_header_id, $category = 'E_REGULAR') {
  if (empty($cc_co_header_id)) {
   return null;
  }
  $sql = " SELECT * 
       FROM cc_co_header eeh, 
       cc_co_line eel,
       hr_compensation_element hce
       WHERE eel.cc_co_header_id = eeh.cc_co_header_id
       AND eeh.cc_co_header_id = '{$cc_co_header_id}'
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

 Public static function find_all_cc_processFlow() {
  $sql = " SELECT * 
from sys_process_flow_header
WHERE module_name = 'cc'";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 Public static function find_all_basic_lines($cc_co_header_id) {
  return self::find_all_lines_by_category($cc_co_header_id, 'E_BASIC');
 }

 Public static function find_all_basic_regular_lines($cc_co_header_id) {
  return self::find_all_lines_by_category($cc_co_header_id, array('E_BASIC', 'E_REGULAR'));
 }

 public static function find_by_employeeId($employee_id) {
  $sql = " SELECT * 
       FROM cc_co_header eeh 
       WHERE eeh.employee_id = '{$employee_id}'   
        LIMIT 1
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of bom class
?>