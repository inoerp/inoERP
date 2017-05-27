<?php
 $table_column_name = [];
 $show_field_stmt = '';
 if (!empty($view->select_v)) {
  $table_names = [];
  $table_name_a = explode(',', $view->select_v);
  foreach ($table_name_a as $record_a) {
   $record_a = trim(substr($record_a, 0, strpos($record_a, 'AS') - 1));
   $show_field_stmt .= '<li class="draggable_element ui-state-default ui-draggable">';
   $show_field_stmt .= $f->text_field_ap(array('name' => 'showField_buttons', 'value' => $record_a, 'class_name' => 'showField_buttons '. $record_a));
   $show_field_stmt .= '</li>';
   $strpos_of_bracket_start = strpos($record_a, '(');
   if ($strpos_of_bracket_start !== false) {
    $record_a = substr($record_a, $strpos_of_bracket_start + 1, strpos($record_a, ')'));
   }
   $record_a_exp = explode('.', $record_a);
   array_push($table_column_name, $record_a);
   if (!array_key_exists($record_a_exp[0], $table_names)) {
    $table_names[$record_a_exp[0]] = array();
    $table_names[$record_a_exp[0]][] = rtrim($record_a_exp[1], ')');
   } else {
    $table_names[$record_a_exp[0]][] = rtrim($record_a_exp[1], ')');
   }
  }
 }
$cond_stmt ='';
 if (!empty($$class->from_v)) {
  $from_v_a = explode('ON', $$class->from_v);
  
  if (!empty($from_v_a)) {
   foreach ($from_v_a as $k => $v) {
    if (strpos($v, '=') !== false) {
     $v_a = explode('=', $v);
     $cond_stmt .= '<tr class="condition_row">';
     $cond_stmt .= '<td class="condition_row_parameter ui-droppable">';
     $cond_stmt .= '<ul><li class="draggable_element ui-state-default ui-draggable">';
     $cond_stmt .= $f->text_field_ap(array('name' => 'showField_buttons', 'value' => trim($v_a[0]), 'class_name' => $v_a[0]));
     $cond_stmt .= '</li></ul>';
     $cond_stmt .= '</td>';
     $cond_stmt .= '<td class="condition_row_condition">';
     $cond_stmt .= '<ul>';
     $cond_stmt .= '<li>' . $f->select_field_from_array('condition_operator_type', extn_view::$condition_operator_type_a, 'database') . '</li>';
     $cond_stmt .= '<li>' . $f->select_field_from_array('condition_operator', dbObject::$db_control_type_a, 'LEFT_JOIN') . '</li>';
     $cond_stmt .= '</td>';
     $cond_stmt .= '<td class="condition_row_value ui-droppable">';
     $cond_stmt .= '<ul><li class="draggable_element ui-state-default ui-draggable">';
     $left_j_p = strpos(trim($v_a[1]), 'LEFT JOIN');
     if ($left_j_p !== false) {
      $cond_value = substr(trim($v_a[1]), 0, $left_j_p);
     } else {
      $cond_value = trim($v_a[1]);
     }
     $cond_stmt .= $f->text_field_ap(array('name' => 'showField_buttons', 'value' => $cond_value, 'class_name' => $v_a[1]));
     $cond_stmt .= '</li></ul>';
     $cond_stmt .= '</td>';
     $cond_stmt .= '</tr>';
    } else {
     continue;
    }
   }
  }
 }



 $cond_stmt = '';
 if (!empty($$class->from_v)) {
  $from_v_a = explode('ON', $$class->from_v);
  if (!empty($from_v_a)) {
   foreach ($from_v_a as $k => $v) {
    if (strpos($v, '=') !== false) {
     $v_a = explode('=', $v);
     $cond_stmt .= '<tr class="condition_row">';
     $cond_stmt .= '<td class="condition_row_parameter ui-droppable">';
     $cond_stmt .= '<ul><li class="draggable_element ui-state-default ui-draggable">';
     $cond_stmt .= $f->text_field_ap(array('name' => 'showField_buttons', 'value' => trim($v_a[0]), 'class_name' => $v_a[0]));
     $cond_stmt .= '</li></ul>';
     $cond_stmt .= '</td>';
     $cond_stmt .= '<td class="condition_row_condition">';
     $cond_stmt .= '<ul>';
     $cond_stmt .= '<li>' . $f->select_field_from_array('condition_operator_type', extn_view::$condition_operator_type_a, 'database') . '</li>';
     $cond_stmt .= '<li>' . $f->select_field_from_array('condition_operator', dbObject::$db_control_type_a, 'LEFT_JOIN') . '</li>';
     $cond_stmt .= '</td>';
     $cond_stmt .= '<td class="condition_row_value ui-droppable">';
     $cond_stmt .= '<ul><li class="draggable_element ui-state-default ui-draggable">';
     $left_j_p = strpos(trim($v_a[1]), 'LEFT JOIN');
     if ($left_j_p !== false) {
      $cond_value = substr(trim($v_a[1]), 0, $left_j_p);
     } else {
      $cond_value = trim($v_a[1]);
     }
     $cond_stmt .= $f->text_field_ap(array('name' => 'showField_buttons', 'value' => $cond_value, 'class_name' => $v_a[1]));
     $cond_stmt .= '</li></ul>';
     $cond_stmt .= '</td>';
     $cond_stmt .= '</tr>';
    } else {
     continue;
    }
   }
  }
 }

 if (!empty($$class->where_v)) {
  $where_v_a = explode('AND', $$class->where_v);
  if (!empty($where_v_a)) {
   foreach ($where_v_a as $k => $v) {
    $v_a = explode(' ', trim($v));
    $cond_stmt .= '<tr class="condition_row">';
    $cond_stmt .= '<td class="condition_row_parameter ui-droppable">';
    $cond_stmt .= '<ul><li class="draggable_element ui-state-default ui-draggable">';
    $cond_stmt .= $f->text_field_ap(array('name' => 'showField_buttons', 'value' => trim($v_a[0]), 'class_name' => $v_a[0]));
    $cond_stmt .= '</li></ul>';
    $cond_stmt .= '</td>';
    $cond_stmt .= '<td class="condition_row_condition">';
    $cond_stmt .= '<ul>';
    $cond_stmt .= '<li>' . $f->select_field_from_array('condition_operator_type', extn_view::$condition_operator_type_a, 'database') . '</li>';
    $cond_stmt .= '<li>' . $f->select_field_from_array('condition_operator', dbObject::$db_control_type_a, trim($v_a[1])) . '</li>';
    $cond_stmt .= '</td>';
    $cond_stmt .= '<td class="condition_row_value ui-droppable">';
    $cond_stmt .= '<ul><li class="draggable_element ui-state-default ui-draggable">';
    $cond_value = str_replace("'", '', $v_a[2]);
    $cond_stmt .= $f->text_field_ap(array('name' => 'showField_buttons', 'value' => $cond_value));
    $cond_stmt .= '</li></ul>';
    $cond_stmt .= '</td>';
    $cond_stmt .= '</tr>';
   }
  }
 }

 $orderby_stmt = '';
 if (!empty($$class->order_by)) {
  $order_by_a = explode(',', $$class->order_by);
  if (!empty($order_by_a)) {
   foreach ($order_by_a as $k => $ov) {
    $ov_a = explode(' ', $ov);
    $orderby_stmt .= '<tr class="sort_fields_row">';
    $orderby_stmt .= '<td class="sort_fields_field_value ui-droppable">';
    $orderby_stmt .= '<ul><li class="draggable_element ui-state-default ui-draggable">';
    $orderby_stmt .= $f->text_field_ap(array('name' => 'sortField_buttons', 'value' => trim($ov_a[0]), 'class_name' => ' showField_buttons ' . $ov_a[0]));
    $orderby_stmt .= '</li></ul>';
    $orderby_stmt .= '</td>';
    $orderby_stmt .= '<td class="sort_fields_sortBy">';
    $orderby_stmt .= '<ul>';
    $orderby_stmt .= '<li>' . $f->select_field_from_array('sort_fields_values', dbObject::$sort_fields_values_a, trim($ov_a[1])) . '</li>';
    $orderby_stmt .= '</td>';
    $orderby_stmt .= '</tr>';
   }
  }
 }

 $groupBy_stmt = '';
 if (!empty($$class->group_by_v)) {
  $group_by_v_a = explode(',', $$class->group_by_v);
  if (!empty($group_by_v_a)) {
   foreach ($group_by_v_a as $k => $ov) {
    $groupBy_stmt .= '<tr class="group_by_row">';
    $groupBy_stmt .= '<td class="group_by_fields ui-droppable">';
    $groupBy_stmt .= '<ul><li class="draggable_element ui-state-default ui-draggable">';
    $groupBy_stmt .= $f->text_field_ap(array('name' => 'showField_buttons', 'value' => trim($ov), 'class_name' => $ov));
    $groupBy_stmt .= '</li></ul>';
    $groupBy_stmt .= '</td>';
    $orderby_stmt .= '</tr>';
   }
  }
 }

 $column_list = [];
 if (!empty($$class->select_v)) {
  $select_v = explode(',', $$class->select_v);
  if (!empty($select_v)) {
   foreach ($select_v as $k2 => $v2) {
    if (strpos($v2, 'AS') !== false) {
     $v_a = explode('AS', $v2);
     $colmn_v = trim($v_a[1]);
     $column_list[$colmn_v] = $colmn_v;
    }
   }
  }
 }

 if (!empty($$class->path_id)) {
  $$class->parent_id = path::find_by_id($$class->path_id)->parent_id;
 }
?>
