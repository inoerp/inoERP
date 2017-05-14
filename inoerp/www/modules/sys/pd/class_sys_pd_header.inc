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
 * sys_pd_header : Change Control Change Order
 * Change control is used for any kind of document changes such as ECO, MCO, etc
 * Contains all the sys_pd_header information, such as - change_number, description , template_id, org_id, change_type
 * 
 */
class sys_pd_header extends dbObject {

 public static $table_name = "sys_pd_header";
 public static $primary_column = "sys_pd_header_id";
 public static $dependent_classes = ['sys_pd_process_flow_action'];
 public static $key_column = 'document_number';
 public static $module = "cc";
 public static $system_info = [
  'name' => 'Change Control',
  'number' => '9441',
  'description' => 'Change Control',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('sys_pd_line', 'sys_pd_line_value'),
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => '1'
 ];
 public $field_a = [
  'sys_pd_header_id',
  'org_id',
  'document_number',
  'status',
  'security_level',
  'primary_document',
  'primary_document_id',
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
  'document_number'
 ];
 public $requiredField = [
  'org_id',
  'document_number',
 ];
 public $pageTitle = " Process Document "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $sys_pd_header_id;
 public $org_id;
 public $document_number;
 public $status;
 public $security_level;
 public $primary_document;
 public $primary_document_id;
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

 Public static function find_all_lines_by_category($sys_pd_header_id, $category = 'E_REGULAR') {
  if (empty($sys_pd_header_id)) {
   return null;
  }
  $sql = " SELECT * 
       FROM sys_pd_header eeh, 
       sys_pd_line eel,
       hr_compensation_element hce
       WHERE eel.sys_pd_header_id = eeh.sys_pd_header_id
       AND eeh.sys_pd_header_id = '{$sys_pd_header_id}'
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

 Public static function find_all_hr_processFlow() {
  $sql = " SELECT * 
from sys_process_flow_header
WHERE module_name = 'hr'";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_status($status) {
  $sql = " SELECT * 
       FROM sys_pd_header cch 
       WHERE cch.status = '{$status}'   
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 Public function processFlowDiagram($process_flow_line_obj = '', $header_id = '', $current_line = '') {
  if (empty($process_flow_line_obj) && !empty($header_id)) {
   $process_flow_line_obj = sys_process_flow_line::find_by_parent_id($header_id, 'seq_number', 'ASC');
  }

  if (empty($process_flow_line_obj)) {
   return false;
  }
  $icon = ' ';
  $diagram_stmt = '<div class="process_flow_diagram white-font-link">';
  $diagram_stmt .= '<ul class="process_flow_diagram_list">';
  $process_flow_line_obj_ai = new ArrayIterator($process_flow_line_obj);

  while ($process_flow_line_obj_ai->valid()) {
   $path_link = '';
   
   if (($process_flow_line_obj_ai->key() == 0 ) && !empty($this->primary_document)) {
    $primary_doc_class = $this->primary_document;
    if (property_exists($primary_doc_class, 'primary_column')) {
     $primary_doc_class_pri_id = $primary_doc_class::$primary_column;
     $path_link = HOME_URL . 'form.php?class_name=' . $this->primary_document . '&' . $primary_doc_class_pri_id . '=' . $this->primary_document_id;
    }
   } else {
    $pd_process_flow_action = sys_pd_process_flow_action::find_by_headerId_pfLineId($this->sys_pd_header_id, $process_flow_line_obj_ai->current()->sys_process_flow_line_id);
    
    if ($pd_process_flow_action) {
     $path_link = HOME_URL . $process_flow_line_obj_ai->current()->activity_path . '&' . $pd_process_flow_action[0]->object_name . '=' . $pd_process_flow_action[0]->object_primary_id;
    }else{
     $path_link = HOME_URL . $process_flow_line_obj_ai->current()->activity_path ;
    }
   }

   switch ($process_flow_line_obj_ai->current()->line_type) {
    case 'start' :
     $icon = '<i class="fa fa-circle-o"></i>';
     break;
    case 'end' :
     $icon = '<i class="fa fa-circle"></i>';
     break;
    case 'decision' :
     $icon = '<i class="fa fa-square-o"></i>';
     break;
    default :
     $icon = '<i class="fa fa-info-circle"></i>';
     break;
   }
   $process_count = $process_flow_line_obj_ai->key() + 1;
   $current_process = (!empty($current_line) && $current_line == $process_flow_line_obj_ai->current()->line_name ) ? 'current_processs' : '';
   $diagram_stmt .= '<li class="process  ' . $current_process . ' ' . $process_flow_line_obj_ai->current()->line_name . ' '
    . $process_flow_line_obj_ai->current()->line_type . ' "><bdi><label>';
   if (!empty($process_flow_line_obj_ai->current()->activity_path)) {
    $diagram_stmt .= '<a target="_blank" href="' . $path_link . '">';
   }
   $diagram_stmt .= $process_count . '. ' . $process_flow_line_obj_ai->current()->line_name . $icon;
   if (!empty($process_flow_line_obj_ai->current()->activity_path)) {
    $diagram_stmt .= '</a>';
   }
   $diagram_stmt .= '</label>';
   $diagram_stmt .= $process_flow_line_obj_ai->current()->description;
   $diagram_stmt .= '</bdi></li>';
   $process_flow_line_obj_ai->next();
   if ($process_flow_line_obj_ai->valid()) {
    $diagram_stmt .= '<li class="flow_coneector"><i class="fa fa-angle-double-right"></i></li>';
   }
  }

  $diagram_stmt .= '</ul>';
  $diagram_stmt .= '</div>';

  return !empty($diagram_stmt) ? $diagram_stmt : false;
 }

}

//end of bom class
?>