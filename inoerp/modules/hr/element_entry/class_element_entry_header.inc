<?php
/**
 * inoERP - Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * hr_element_entry_header
 * Compensation Element defines all the compensation elements used in payslip and payroll.
 * Contains all the hr_approval_limit_assignment information, such as - element_type, element_name , description, etc
 * 
 */
class hr_element_entry_header extends dbObject {

 public static $table_name = "hr_element_entry_header";
 public static $primary_column = "hr_element_entry_header_id";
 public static $dependent_classes = ['hr_element_entry_line'];
 public static $key_column = 'hr_employee_id';
 public static $module = "hr";
 public static $js_fileName = 'modules/hr/element_entry/js/multi_select.js';
 public static $system_info = [
  'name' => 'Element Entry',
  'number' => '3106',
  'description' => 'Compensation Element Entry',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hr_element_entry_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 6
 ];
 public $field_a = [
  'hr_element_entry_header_id',
  'hr_employee_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'hr_element_entry_header_id',
  'hr_employee_id',
 ];
 public $requiredField = [
  'hr_employee_id',
 ];
 public $fields_inForm_notInDataBase = [
  "employee_name",
  'identification_id',
  'multi_action_class_pc',
  'multi_action_class_pc_value',
  'action'
 ];
 public $pageTitle = " Element Entry "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $hr_element_entry_header_id;
 public $hr_employee_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $employee_name;
 public $identification_id;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 public $action;

 public function _before_save() {
  if (($this->action == 'multi_element_entry')) {
   echo "<br> Assigning elements to employees.";
   $this->_save_element_entry();
   return 10;
  }
 }

 private function _save_element_entry() {
  if (!empty($_POST['hr_employee_id'])) {
   foreach ($_POST['hr_employee_id'] as $k => $v) {
    $ee_h = new hr_element_entry_header();
    $ee_h->hr_employee_id = $v;

//check if header record exists
    $ee_h_i = $ee_h->findBy_employeeId($v);

    if ($ee_h_i) {
     $ee_h->hr_element_entry_header_id = $ee_h_i->hr_element_entry_header_id;
    } else {
     $ee_h->save();
    }

    //find all the lines from the template
    $tmp_headerID = $_POST['hr_element_entry_tpl_header_id'][$k];
    $all_template_lines = hr_element_entry_tpl_line::find_by_parent_id($tmp_headerID);
    foreach ($all_template_lines as $rec) {
     $ee_l = new hr_element_entry_line();
     $ee_l->hr_element_entry_header_id = $ee_h->hr_element_entry_header_id;
     $ee_l->element_id = $rec->element_id;
     $ee_l->element_value = $rec->element_value;
     $ee_l->end_date = $rec->end_date;
     $exiting_eel = hr_element_entry_line::find_by_parentId_elementId($ee_l->hr_element_entry_header_id, $ee_l->element_id);
     if ($exiting_eel) {
      $ee_l->hr_element_entry_line_id = $exiting_eel->hr_element_entry_line_id;
     }
     try {
      $ee_l->save();
     } catch (Exception $e) {
      echo "<br> Erorr @ class_element_entry_header @@ " . __LINE__ . $e->getMessage();
     }
    }
   }
  }
 }

 Public static function find_all_lines_by_category($hr_element_entry_header_id, $category = 'E_REGULAR') {
  if (empty($hr_element_entry_header_id)) {
   return null;
  }
  $sql = " SELECT * 
       FROM hr_element_entry_header eeh, 
       hr_element_entry_line eel,
       hr_compensation_element hce
       WHERE eel.hr_element_entry_header_id = eeh.hr_element_entry_header_id
       AND eeh.hr_element_entry_header_id = '{$hr_element_entry_header_id}'
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

 Public static function find_all_regular_lines($hr_element_entry_header_id) {
  return self::find_all_lines_by_category($hr_element_entry_header_id, 'E_REGULAR');
 }

 Public static function find_all_basic_lines($hr_element_entry_header_id) {
  return self::find_all_lines_by_category($hr_element_entry_header_id, 'E_BASIC');
 }

 Public static function find_all_basic_regular_lines($hr_element_entry_header_id) {
  return self::find_all_lines_by_category($hr_element_entry_header_id, array('E_BASIC', 'E_REGULAR'));
 }

 public static function find_by_employeeId($employee_id) {
  $sql = " SELECT * 
       FROM hr_element_entry_header eeh 
       WHERE eeh.hr_employee_id = '{$employee_id}'   
        LIMIT 1
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_employeeId($employee_id) {
  $sql = " SELECT * 
       FROM hr_element_entry_header eeh 
       WHERE eeh.hr_employee_id = '{$employee_id}'   
        LIMIT 1
";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function multi_select_input_fields() {
  $multi_select_input = [
   'template_name'
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

}

//end of bom class
?>