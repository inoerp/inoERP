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
 * sys_process_flow_header
 *
 */
class sys_process_flow_header extends dbObject {

 public static $table_name = "sys_process_flow_header";
 public static $primary_column = "sys_process_flow_header_id";
 public static $dependent_classes = ['sys_process_flow_line', 'sys_process_flow_action'];
 public static $key_column = "process_flow";
 public static $module = "sys";
 public static $system_info = [
  'name' => 'Process Flow',
  'number' => '9445',
  'description' => 'Create & Mainten Process Flow',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('sys_process_flow_line', 'sys_process_flow_action'),
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 7
 ];
 public static $type_a = [
  'APPROVAL' => 'Approval',
  'DOCUMENT' => 'Document',
  'SYS_DOCUMENT' => 'System Document'
 ];
 public $field_a = [
  'sys_process_flow_header_id',
  'process_flow',
  'module_name',
  'status',
  'type',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'sys_process_flow_header_id',
  'process_flow',
  'module_name'
 ];
 public $requiredField = [
  'process_flow',
  'module_name'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Process Flow Header ";
 public $sys_process_flow_header_id;
 public $process_flow;
 public $type;
 public $module_name;
 public $status;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function validation_types() {
  $header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
  $option_line = new option_line();
  $lines = $option_line->findBy_parentId($header->option_header_id);
  return $lines;
 }

 Public static function find_by_type($type='SYS_DOCUMENT') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= "  WHERE type =  '{$type}'
         ORDER BY process_flow ASC
";
  
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 Public static function processFlowActions_by_headerId($header_id) {
  $sql = " SELECT line_name, sys_process_flow_line_id 
     FROM sys_process_flow_header fh,
     sys_process_flow_line fl
     
    WHERE fh.sys_process_flow_header_id = fl.sys_process_flow_header_id
    AND fh.sys_process_flow_header_id = '{$header_id}'
     
ORDER BY seq_number ASC
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 Public static function xxprocessFlowDiagram($process_flow_line_obj = '', $header_id = '', $current_line = '') {
  if (empty($process_flow_line_obj) && !empty($header_id)) {
   $process_flow_line_obj = sys_process_flow_line::find_by_parent_id($header_id, 'seq_number', 'ASC');
  }

  if (empty($process_flow_line_obj)) {
   return false;
  }
  $diagram_stmt = '<div class="process_flow_diagram">';
  $diagram_stmt .= '<ul class="process_flow_diagram_list">';
  $process_flow_line_obj_ai = new ArrayIterator($process_flow_line_obj);
  while ($process_flow_line_obj_ai->valid()) {
   $process_count = $process_flow_line_obj_ai->key() + 1;
   $current_process = (!empty($current_line) && $current_line == $process_flow_line_obj_ai->current()->line_name ) ? 'current_processs' : '';
   $diagram_stmt .= '<li class="process  ' . $current_process . ' ' . $process_flow_line_obj_ai->current()->line_name . ' '
    . $process_flow_line_obj_ai->current()->line_type . ' "><bdi><label>'
    . $process_count . '. ' . $process_flow_line_obj_ai->current()->line_name . '</label>';
   $diagram_stmt .= $process_flow_line_obj_ai->current()->description;
   $diagram_stmt .= '</bdi></li>';
   $process_flow_line_obj_ai->next();
   if ($process_flow_line_obj_ai->valid()) {
    $diagram_stmt .= '<li class="flow_coneector"></li>';
   }
  }

  $diagram_stmt .= '</ul>';
  $diagram_stmt .= '</div>';

  return !empty($diagram_stmt) ? $diagram_stmt : false;
 }

 Public static function processFlowDiagram($process_flow_line_obj = '', $header_id = '', $current_line = '') {
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
    $diagram_stmt .= '<a target="_blank" href="' . HOME_URL . $process_flow_line_obj_ai->current()->activity_path . '">';
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

//end of path class
?>