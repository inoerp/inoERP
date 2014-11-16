<?php

 class cc_co_template_header extends dbObject {

  public static $table_name = "cc_co_template_header";
  public static $primary_column = "cc_co_template_header_id";
  public static $dependent_classes = ['cc_co_template_line'];
  public static $key_column = 'template_name';
  public static $module = "cc";
  public $field_a = [
   'cc_co_template_header_id',
   'template_name',
   'org_id',
   'description',
   'status',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  //variables used for showing data

  public $initial_search = [
   'template_name'
  ];
  public $requiredField = [
   'template_name',
  ];
  public $pageTitle = " Change Control Template "; //page Title
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $cc_co_template_header_id;
  public $template_name;
  public $org_id;
  public $description;
  public $status;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;

  public function _before_showing() {
   
  }

  Public static function find_all_lines_by_category($cc_co_template_header_id, $category = 'E_REGULAR') {
   if (empty($cc_co_template_header_id)) {
    return null;
   }
   $sql = " SELECT * 
       FROM cc_co_template_header eeh, 
       cc_co_template_line eel,
       hr_compensation_element hce
       WHERE eel.cc_co_template_header_id = eeh.cc_co_template_header_id
       AND eeh.cc_co_template_header_id = '{$cc_co_template_header_id}'
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

  Public static function find_all_regular_lines($cc_co_template_header_id) {
   return self::find_all_lines_by_category($cc_co_template_header_id, 'E_REGULAR');
  }

  Public static function find_all_basic_lines($cc_co_template_header_id) {
   return self::find_all_lines_by_category($cc_co_template_header_id, 'E_BASIC');
  }

  Public static function find_all_basic_regular_lines($cc_co_template_header_id) {
   return self::find_all_lines_by_category($cc_co_template_header_id, array('E_BASIC', 'E_REGULAR'));
  }

  public static function find_by_employeeId($employee_id) {
   $sql = " SELECT * 
       FROM cc_co_template_header eeh 
       WHERE eeh.employee_id = '{$employee_id}'   
        LIMIT 1
";
   $result = self::find_by_sql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

 }

//end of bom class
?>