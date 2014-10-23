<?php

//set $allow_conversion to true when before conversion
 class convertToProd extends dbObject {

  public static $allow_conversion = false;
  
  public static $table_name = "convertToProd";
  public static $primary_column = "username";
  public static $key_column = "profile_name";
  public static $module = "sys";
  public $field_a = [
   'username',
  ];
  public $initial_search = [
   'convertToProd_id',
   'access_level',
   'profile_name',
   'description',
  ];
  public $column = [
   'convertToProd_id',
   'access_level',
   'profile_name',
   'description',
  ];
  public $requiredField = [
   'class_name',
   'access_level',
   'profile_name',
  ];
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $fields_inForm_notInDataBase = [
   "profile_level",
  ];
  public static $exclude_tables = [
   'ap_payment_terms',
   'ar_receipt_source',
   'ar_transaction_source',
   'ar_transaction_type',
   'block',
   'block_content',
   'bom_cost_type',
   'bom_department',
   'bom_department_resource_assignment',
   'bom_material_element',
   'bom_overhead',
   'bom_overhead_rate_assignment',
   'bom_overhead_resource_assignment',
   'bom_resource',
   'bom_resource_cost',
   'business',
   'category',
   'category_reference',
   'coa',
   'content_type',
   'content_type_reference',
   'engine',
   'enterprise',
   'ext_url_alias',
   'extra_field_calculated_power',
   'extra_field_grade',
   'extra_field_length',
   'extra_field_per_master_file',
   'extra_field_power_cable',
   'extra_field_serial_status',
   'form',
   'gl_calendar',
   'gl_ledger',
   'gl_period',
   'hr_approval_limit_assignment',
   'hr_approval_limit_header',
   'hr_approval_limit_line',
   'hr_approval_object',
   'hr_compensation_element',
   'hr_control',
   'hr_element_entry_header',
   'hr_element_entry_line',
   'hr_job',
   'hr_leave_type',
   'hr_payroll',
   'hr_payroll_payment_method',
   'hr_payroll_schedule',
   'hr_position',
   'hr_position_hierarchy_header',
   'hr_position_hierarchy_line',
   'inventory',
   'item_status',
   'legal',
   'mdm_tax_code',
   'mdm_tax_region',
   'mdm_tax_rule',
   'module',
   'option_detail',
   'option_header',
   'option_line',
   'org',
   'path',
   'payment_term',
   'payment_term_discount',
   'payment_term_schedule',
   'po_purchasing_control',
   'product',
   'role_access',
   'role_path',
   'sd_shipping_control',
   'site_info',
   'sys_document_sequence',
   'sys_dynamic_block_header',
   'sys_dynamic_block_line',
   'sys_extra_field',
   'sys_extra_field_instance',
   'sys_hold',
   'sys_hold_reference',
   'sys_notification_group',
   'sys_permission',
   'sys_profile_header',
   'sys_profile_line',
   'sys_role_permission',
   'sys_value_group_header',
   'sys_value_group_line',
   'system_path',
   'transaction_type',
   'uom',
   'user',
   'user_favourite',
   'user_password_reset',
   'user_role',
   'user_supplier',
   'view',
   'view_path',
   'wip_control',
  ];
  public $pageTitle = " Profiles "; //page Title
  public $convertToProd_id;
  public $access_level;
  public $profile_name;
  public $class_name;
  public $profile_level;
  public $description;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $message;
  public $convert_to_prod_mode;
  public $prg_convert_to_prod_parameters = [
   'Program Mode' => 'search_convert_to_prod_mode',
   'DB Name' => 'search_db_name',
  ];
  public $prg_convert_to_prod_details = [
   'name' => 'Convert DB from Demo to Production',
   'description' => 'Convert DB from Demo to Production',
  ];

  public function prg_convert_to_prod($seralized_parameters) {
   $parameters = unserialize($seralized_parameters);
   $this->message .= '<br> Staring Convert to Prod program ';

   if (!empty($parameters['convert_to_prod_mode'][0])) {
    $convert_to_prod_mode = $this->convert_to_prod_mode = $parameters['convert_to_prod_mode'][0];
    $this->message .= '<br> Entered convert_to_prod_mode is : ' . $convert_to_prod_mode;
   } else {
    $convert_to_prod_mode = 'TEST';
    $this->message .= '<br> No convert_to_prod_mode found. Running the program in TEST mode ' . __LINE__;
   }


   try {
    $this->convert_to_prod($convert_to_prod_mode);
    $this->message .= "<br>Convert to Prod program is sucessfully completed";
   } catch (Exception $e) {
    $this->message .= "<br>Convert to Prod program failed!" . $e->getMessage();
   }

   return $this->message;
  }

  public function convert_to_prod($mode = 'TEST') {
   global $dbc;
   $table_sql = "   select table_name
from information_schema.tables
WHERE TABLE_SCHEMA= '" . DB_NAME . "'
AND table_type = 'BASE TABLE'
 ";

   $prepare = $dbc->connection->prepare($table_sql);
   try {
    $prepare->execute();
    $result_fetchAll = $prepare->fetchAll(PDO::FETCH_COLUMN);
   } catch (Exception $e) {
//    echo "<br>Error @dbObject @@ Line " . __LINE__ . $sql;
    return false;
   }

   $this->message .= '<h2>Total no base tables in selected DB ' . DB_NAME . ' : </h2>' . count($result_fetchAll);
   $include_tables = array_diff($result_fetchAll, convertToProd::$exclude_tables);
   $include_tables = array_values($include_tables);
   $this->message .= '<h2>Total no tables updated : </h2>' . count($include_tables);

   if ($mode != 'FINAL') {
    return;
   }

   foreach ($include_tables as $key => $table_name) {
    $sql2 = " DELETE FROM  {$table_name}  ";
    $dbc->ddlexecute($sql2);
    $sql3 = "   ALTER TABLE {$table_name} auto_increment = 1 ";
    $dbc->ddlexecute($sql3);
    echo "<br> $table_name is updated";
   }
   $dbc->confirm();
  }

 }

//end of path class
?>