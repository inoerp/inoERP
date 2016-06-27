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
 * ar_receivable_activity
 * 
 * 
 */
class ar_receivable_activity extends dbObject {

 public static $table_name = "ar_receivable_activity";
 public static $primary_column = "ar_receivable_activity_id";
 public static $key_column = 'activity_name';
 public static $module = "ar";
 public static $system_info = [
  'name' => 'AR Receivable Activity',
  'number' => '1315',
  'description' => 'Receivable Activity',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ar',
  'weight' => 5
 ];

 const AR_ACTIVITY_TYPE_A = [
  '1' => 'Adjustment',
  '2' => 'Bank Error',
  '3' => 'Discount',
  '4' => 'Write-Off',
 ];
 
  const AR_ACCOUNT_SOURCE_A = [
  '1' => 'Invoice',
  '2' => 'Receipt',
  '3' => 'Activity',
  
 ];

 public $field_a = [
  'ar_receivable_activity_id',
  'activity_name',
  'activity_type',
  'active_cb',
  'account_source',
  'description',
  'activity_ac_id',
  'tax_code_source',
  'tax_code_id',
  'bu_org_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'activity_name',
  'activity_type',
 ];
 public $requiredField = [
  'activity_name',
  'activity_type',
  'bu_org_id',
 ];
 public $ar_receivable_activity_id;
 public $activity_name;
 public $activity_type;
 public $active_cb;
 public $account_source;
 public $description;
 public $activity_ac_id;
 public $tax_code_source;
 public $tax_code_id;
 public $bu_org_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Receivable Activity ";
 public static $header_tab_1 = [
  [
   'name' => 'activity_name',
   'field_function' => 'l_text_field_d'
  ],
  [
   'name' => 'bu_org_id',
   'field_function' => 'l_text_field_d'
  ],
  [
   'name' => 'activity_type',
   'field_function' => 'l_select_field_from_array',
   'function_parameters' => ['activity_type', self::AR_ACTIVITY_TYPE_A, 'activity_type', 'activity_type' ,'',1],
  ],
  [
   'name' => 'description',
   'field_function' => 'l_text_field_d'
  ],
//  [
//   'name' => 'username',
//   'field_function' => 'l_val_field_d',
//   'function_parameters' => ['username', 'user', 'username','','always_readonly'],
//   'hidden_fields' => ['user_id']
//  ], 
  ['name' => 'active_cb',
   'field_function' => 'l_checkBox_field_d'
  ],
//  [
//   'name' => 'user_id',
//   'field_function' => 'hidden_field_d',
//   'function_parameters' => ['user_id'],
//  ]
 ];
 public static $no_ofline_tabs = 1;
 public static $line_tab_1 = [
  'ul_class' => 'header_field column  two_column_form',
  'tab_heading' => 'Details',
  [
   'name' => 'account_source',
   'field_function' => 'l_text_field_d'
  ],
  [
   'name' => 'activity_ac_id',
   'field_function' => 'l_text_field_d'
  ],
  [
   'name' => 'tax_code_source',
   'field_function' => 'l_text_field_d'
  ],
  [
   'name' => 'tax_code',
   'field_function' => 'l_text_field_d'
  ]
 ];

 public static function find_by_buOrgId($bu_org_id) {
  $f = new inoform();
  $f->l_select_field_from_array($name, $array, $value);
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE bu_org_id = '{$bu_org_id}' AND status='active'";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public function findBy_buOrgId($bu_org_id = '') {
  $bu_org_id = empty($bu_org_id) ? $this->bu_org_id : $bu_org_id;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE bu_org_id = '{$bu_org_id}' AND status='active'";
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of ar_receivable_activity class
?>