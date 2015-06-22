<?php

 class hr_leave_transaction_header extends dbObject {

  public static $table_name = "hr_leave_transaction_header";
  public static $primary_column = "hr_leave_transaction_header_id";
  public static $dependent_classes = ['hr_leave_transaction_line'];
  public static $key_column = 'employee_id';
  public static $module = "hr";
  public $field_a = [
   'hr_leave_transaction_header_id',
   'employee_id',
   'requsted_date',
   'approved_date',
   'approved_by',
   'approved_by_employee_id',
   'leave_status',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  //variables used for showing data

  public $initial_search = [
   'hr_leave_transaction_header_id',
   'employee_id',
  ];
  public $requiredField = [
   'employee_id',
   'requsted_date',
  ];
  public $fields_inForm_notInDataBase = [
   "employee_name",
   'identification_id'
  ];
  public $pageTitle = " Apply Leave "; //page Title
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $hr_leave_transaction_header_id;
  public $employee_id;
  public $requsted_date;
  public $approved_date;
  public $approved_by;
  public $approved_by_employee_id;
  public $leave_status;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $employee_name;
 public $identification_id;
  
  public function _before_showing() {
   
  }
  
  public function _before_save(){
   if(empty($this->leave_status)){
    $this->leave_status = 'ENTERED';
   }
   
  }

//  Public static function find_all_lines_by_category($hr_leave_transaction_header_id, $category = 'E_REGULAR') {
//   if (empty($hr_leave_transaction_header_id)) {
//    return null;
//   }
//   $sql = " SELECT * 
//       FROM hr_leave_transaction_header eeh, 
//       hr_leave_transaction_line eel,
//       hr_compensation_element hce
//       WHERE eel.hr_leave_transaction_header_id = eeh.hr_leave_transaction_header_id
//       AND eeh.hr_leave_transaction_header_id = '{$hr_leave_transaction_header_id}'
//        AND hce.hr_compensation_element_id = eel.element_id
//        
//";
//   if (is_array($category)) {
//    $sql .= " AND hce.category IN " . "( '" . implode("','", $category) . "' )";
//   } else {
//    $sql .= " AND hce.category = '{$category}' ";
//   }
//   $result = self::find_by_sql($sql);
//   return !empty($result) ? $result : false;
//  }
//
//  Public static function find_all_regular_lines($hr_leave_transaction_header_id) {
//   return self::find_all_lines_by_category($hr_leave_transaction_header_id, 'E_REGULAR');
//  }
//
//  Public static function find_all_basic_lines($hr_leave_transaction_header_id) {
//   return self::find_all_lines_by_category($hr_leave_transaction_header_id, 'E_BASIC');
//  }
//
//  Public static function find_all_basic_regular_lines($hr_leave_transaction_header_id) {
//   return self::find_all_lines_by_category($hr_leave_transaction_header_id, array('E_BASIC', 'E_REGULAR'));
//  }
//
//  public static function find_by_employeeId($employee_id) {
//   $sql = " SELECT * 
//       FROM hr_leave_transaction_header eeh 
//       WHERE eeh.employee_id = '{$employee_id}'   
//        LIMIT 1
//";
//   $result = self::find_by_sql($sql);
//   return !empty($result) ? array_pop($result) : false;
//  }

 }

//end of bom class
?>