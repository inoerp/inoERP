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



 }

//end of bom class
?>