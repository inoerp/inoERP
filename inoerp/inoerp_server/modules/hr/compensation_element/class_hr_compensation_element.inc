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
 * hr_compensation_element
 * Compensation Element defines all the compensation elements used in payslip and payroll.
 * Contains all the hr_approval_limit_assign information, such as - element_type, element_name , description, etc
 * 
 */
 class hr_compensation_element extends dbObject {

  public static $table_name = "hr_compensation_element";
  public static $primary_column = "hr_compensation_element_id";
  public static $key_column = 'element_name';
  public static $module = "hr";
   public static $system_info = [
  'name' => 'Compensation Element',
  'number' => '3105',
  'description' => 'Compensation Element',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 5
 ];
  public $field_a = [
   'hr_compensation_element_id',
   'element_type',
   'start_date',
   'element_name',
   'classification',
   'description',
   'category',
   'end_date',
   'priority',
   'recurring_cb',
   'deduction_start_rule',
   'calculation_rule',
   'separate_check_cb',
   'frequency_months',
   'standard_link_cb',
   'deduction_rule',
   'status',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public static $calculation_rule_a = [
   'FLAT' => 'Flat Amount',
   'P_BASIC' => '% Of Basic',
   'P_REGULAR' => '% Of Regular',
   'P_BASIC_REGULAR' => '% Of Basic & Regular',
   'HOUR_RATE' => 'Hour Rate',
  ];
  public static $deduction_rule_a = [
   'FLAT' => 'Flat Amount',
   'P_BASIC' => '% Of Basic',
   'P_TOTAL' => '% Of Total',
   'P_TOTAL_TAX' => '% Of Total Taxable',
   'REFERRAL_TABLE' => 'Referral Table',
  ];
  public static $deduction_start_rule_a = [
   'ON_ENTRY' => 'On Entry',
   'AFTER_EARNING' => 'After Earning',
  ];
  public $initial_search = [
   'hr_compensation_element_id',
   'element_name',
   'description',
  ];
  public $requiredField = [
   'element_type',
   'start_date',
   'element_name',
  ];
  public $checkbox = [
   'recurring_cb',
   'separate_check_cb',
   'standard_link_cb',
  ];
  public $hr_compensation_element_id;
  public $element_type;
  public $start_date;
  public $element_name;
  public $classification;
  public $description;
  public $category;
  public $end_date;
  public $priority;
  public $recurring_cb;
  public $deduction_start_rule;
  public $calculation_rule;
  public $separate_check_cb;
  public $frequency_months;
  public $standard_link_cb;
  public $deduction_rule;
  public $status;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " HR Compensation Element  "; //page Title

  Public static function compensation_element_type() {
   $option_header = option_header::find_by_name('HR_COMPENSATION_ELEMENT_TYPE');
   $ol = new option_line();
   $option_lines = $ol->findBy_parentId($option_header->option_header_id);
   return $option_lines;
  }

  Public static function compensation_element_class() {
   $option_header = option_header::find_by_name('HR_COMPENSATION_ELEMENT_CLASS');
   $ol = new option_line();
   $option_lines = $ol->findBy_parentId($option_header->option_header_id);
   return $option_lines;
  }

  Public static function compensation_element_category() {
   $option_header = option_header::find_by_name('HR_COMPENSATION_ELEMENT_CATEGORY');
   $ol = new option_line();
   $option_lines = $ol->findBy_parentId($option_header->option_header_id);
   return $option_lines;
  }

  public function _before_save(){
   if(!empty($this->category) && !empty($this->calculation_rule)){
    if(($this->category == 'E_BASIC' || $this->category == 'E_REGULAR' ) && ($this->calculation_rule != 'FLAT')){
     echo "<br>Regular & Basic salary elements can have only flat amounts";
     return -99;
    }
   }
  }

 }

//end of hr_compensation_element class
?>