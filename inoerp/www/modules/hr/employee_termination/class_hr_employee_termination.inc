<?php

 class hr_employee_termination extends dbObject {

  public static $table_name = "hr_employee_termination";
  public static $primary_column = "hr_employee_termination_id";
  public static $key_column = 'employee_id';
  public static $module = "hr";
  public static $status_a = [
   'APPLIED' => 'Applied',
   'PENDING_APPROVAL' => 'Pending Approval',
   'PENDING_CLEARANCE' => 'Pending Clearance',
   'ACCEPTED' => 'Accepted',
   'REJECTED' => 'Rejected',
   'COMPLETED' => 'Completed'
  ];
  public $field_a = [
   'hr_employee_termination_id',
   'employee_id',
   'new_employer',
   'reason',
   'status',
   'date_of_notification',
   'projected_last_date',
   'actual_last_date',
   'accpeted_date',
   'accpeted_by_employee_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'hr_employee_termination_id',
   'employee_id',
  ];
  public $requiredField = [
   'employee_id',
  ];
  public $fields_inForm_notInDataBase = [
   "employee_name",
   "identification_id"
  ];
    
  public $hr_employee_termination_id;
  public $employee_id;
  public $new_employer;
  public $reason;
  public $date_of_notification;
  public $projected_last_date;
  public $actual_last_date;
  public $accpeted_date;
  public $accpeted_by_employee_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $employee_name;
  public $identification_id;
  
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " HR Employee termination  "; //page Title

  Public static function find_by_employeeId($employee_id) {
   $sql = " SELECT * FROM " . self::$table_name . " WHERE employee_id = '{$employee_id}' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : null;
  }
  
  public function _after_save(){
   if($this->status == 'COMPLETED' && !empty($this->employee_id)){
    $hr_em = new hr_employee();
    $hr_em->hr_employee_id = $this->employee_id;
    $hr_em->status = 'INACTIVE';
    $hr_em->person_type = 'EMPLOYEE_EX';
    try{
    $hr_em->save();
    }catch (Exception $e){
     
    }
   }
  }

 }

//end of hr_employee_termination class
?>