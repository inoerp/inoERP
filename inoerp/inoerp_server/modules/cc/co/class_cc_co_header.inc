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
 * cc_co_header : Change Control Change Order
 * Change control is used for any kind of document changes such as ECO, MCO, etc
 * Contains all the cc_co_header information, such as - change_number, description , template_id, org_id, change_type
 * 
 */
class cc_co_header extends dbObject {

 public static $table_name = "cc_co_header";
 public static $primary_column = "cc_co_header_id";
 public static $dependent_classes = ['cc_co_line', 'cc_co_line_value'];
 public static $key_column = 'change_number';
 public static $module = "cc";
 public static $system_info = [
  'name' => 'Change Control',
  'number' => '9301',
  'description' => 'Change Control',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('cc_co_line', 'cc_co_line_value'),
  'primary_entity_cb' => '',
  'module_name' => 'cc',
  'weight' => '1'
 ];
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

 public static function find_by_status($status) {
  $sql = " SELECT * 
       FROM cc_co_header cch 
       WHERE cch.status = '{$status}'   
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 private function _implement_co($co_change_number) {
  $coh = self::find_by_keyColumn($co_change_number);
  $all_co_lines = cc_co_line::find_by_parent_id($coh->cc_co_header_id);

  foreach ($all_co_lines as $co_line) {
   $item = new item();
   $item_i = $item->find_by_orgId_item_id_m($co_line->item_id_m, $coh->org_id);
   $co_line_values = cc_co_line_value::find_by_parent_id($co_line->cc_co_line_id);
   $item->item_id = $item_i->item_id;
   foreach ($co_line_values as $line_value) {
    $cc_co_template_line = cc_co_template_line::find_by_id($line_value->cc_co_template_line_id);
    $filed_name = $cc_co_template_line->field_name;
    $item->$filed_name = $line_value->field_value;
   }
   $item->update_changesOnly($item->item_id);
  }

  $co_header = new self;
  $co_header->findBy_id($coh->cc_co_header_id);
  $co_header->status = 'IMPLEMENTED';
  $co_header->save();
 }

 public function prg_implement_co($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting change order implementation program';

  if (!empty($parameters['org_id'][0])) {
   $org_id = $parameters['org_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $org_id;
  } else {
   $this->message .= '<br> Error! : No org id found @ cc_co_header ' . __LINE__;
   return $this->message;
  }

  if (!empty($parameters['implement_all_cb'][0])) {
   $all_changes = self::find_by_status('IMPLEMENT');
   foreach ($all_changes as $co_header) {
    try {
     $this->_implement_co($co_header->change_number);
     $this->message .= '<br/>Change order # ' . $co_header->change_number . ' is Successfullyimplemented ';
    } catch (Exception $e) {
     $this->message .= '<br/>Change order # ' . $co_header->change_number . ' failed to implement ' . $e->getMessage();
    }
   }
  } else if (isset($parameters['change_number'][0])) {
   $this->message .= "<br/>Starting implementation of CO# " . $parameters['change_number'][0];
   try {
    $this->_implement_co($parameters['change_number'][0]);
    $this->message .= '<br/>Change order # ' . $parameters['change_number'][0] . ' is Successfullyimplemented ';
   } catch (Exception $e) {
    $this->message .= '<br/>Change order # ' . $parameters['change_number'][0] . ' failed to implement ' . $e->getMessage();
   }
  }
  return $this->message;
 }

}

//end of bom class
?>