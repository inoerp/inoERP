<?php

class getsvgimage extends dbObject {

 public $field_a = [
  '_chart_name',
  '_chart_width',
  '_chart_height',
  '_chart_type',
  '_label',
  '_legend',
  '_legend2',
  '_draw_major_grid_x',
  '_draw_minor_grid_x',
  '_draw_major_grid_y',
  '_draw_minor_grid_y',
  '_show_elemnt_value',
  '_left_margin',
  '_right_margin',
  '_top_margin',
  '_bottom_margin',
  '_height_of_text',
  '_width_of_legend',
  '_height_of_legend',
  '_x_axis_text',
  '_y_axis_text'
 ];
 public static $chart_type_a = [
  'horizonatl_bar' => 'Horizontal Bar',
  'clustered_bar' => 'Clustered Bar',
  'stacked_bar' => 'Stacked Bar',
  'vertical_column' => 'Vertical Column',
  'clustered_column' => 'Clustered Column',
  'stacked_column' => 'Stacked Column',
  'pie' => 'Pie Chart',
  'funnel' => 'Funnel Chart',
  'donut' => 'Donut Chart',
  'line' => 'Line Graph',
 ];
 private $_chart_name;
 private $_chart_width = '350';
 private $_chart_height = '350';
 private $_chart_width_orginal;
 private $_chart_height_orginal;
 private $_chart_type = 'horizonatl_bar';
 private $_data;
 private $_max_val;
 private $_min_val;
 private $_data_count;
 private $_legend;
 private $_legend2;
 private $_label;
 private $_draw_major_grid_x = true;
 private $_draw_minor_grid_x = true;
 private $_draw_major_grid_y = true;
 private $_draw_minor_grid_y = true;
 private $_show_elemnt_value = false;
 private $_ignore_empty_value = false;
 private $_left_margin = 30;
 private $_right_margin = 0;
 private $_top_margin = 10;
 private $_bottom_margin;
 private $_height_of_text = 10;
 private $_width_of_legend = 80;
 private $_height_of_legend;
 private $_x_axis_text;
 private $_y_axis_text;
 private $_settings;
 private $_vertical_grid_end_xaxis;
 private $_width_for_xaxis_chart_label;
 private $_height_for_xaxis_chart_label;
 public $result;
 public $legend_name;
 public $legend_name2;
 public $chart_label;
 public $chart_value;

 public function setProperty($property, $value) {
  if (property_exists($this, $property)) {
   switch ($property) {
    case '_chart_width':
    case '_chart_height':
     $this->$property = !empty($value) ? $value : '350';
     break;

    case '_chart_name':
     $this->$property = !empty($value) ? ucwords(str_replace('_', ' ', $value)) : '';
     break;

    case '_draw_major_axis':
    case '_draw_minor_axis':
     $this->$property = !empty($value) ? true : false;
     break;

    case '_chart_type':
     $this->$property = !empty($value) ? $value : 'horizonatl_bar';
     break;

    case '_settings':
     if (!empty($value) && is_array($value)) {
      $this->$property = $value;
      $this->_settings();
     }
     break;

    case '_data':
     $this->_prepare_data($value);
     break;

    default:
     $this->$property = $value;
     break;
   }
  }
 }

 public function __get($property) {
  if (property_exists($this, $property)) {
   return $this->$property;
  }
 }

 private function _settings() {
  foreach ($this->field_a as $key => $field) {
   if (array_key_exists($field, $this->_settings)) {
    if (($field == '_chart_type') && is_array($this->_settings[$field])) {
     $this->$field = $this->_settings[$field][0];
    } else {
     $this->$field = $this->_settings[$field];
    }
   }
  }
 }

 public function draw_chart() {
  if (empty($this->_x_axis_text)) {
   $this->_height_of_text = 0;
   $this->_bottom_margin = 5;
  }
  $this->_chart_height_orginal = $this->_chart_height;
  $this->_chart_width_orginal = $this->_chart_width;

  switch ($this->_chart_type) {
   case 'horizonatl_bar' :
    $this->_dataRange_inDataSet();
    $final_chart = $this->_draw_horizonatl_bar();
    break;

   case 'clustered_bar' :
    $this->_dataRange_inDataSet();
    $final_chart = $this->_draw_clustered_bar();
    break;

   case 'stacked_bar' :
    $this->_dataRange_inDataSet();
    $final_chart = $this->_draw_stacked_bar();
    break;

   case 'vertical_column' :
    $this->_dataRange_inDataSet();
    $final_chart = $this->_draw_vertical_column();
    break;

   case 'clustered_column' :
    $this->_dataRange_inDataSet();
    $final_chart = $this->_draw_clustered_column();
    break;

   case 'stacked_column' :
    $final_chart = $this->_draw_stacked_column();
    break;

   case 'pie' :
    $final_chart = $this->_draw_pie();
    break;

   case 'funnel' :
    $final_chart = $this->_draw_funnel();
    break;

   case 'donut' :
    $final_chart = $this->_draw_donut();
    break;

   case 'line' :
    $this->_show_elemnt_value = true;
    $this->_dataRange_inDataSet();
    $final_chart = $this->_draw_line();
    break;
  }

  return $final_chart;
 }

 private function _prepare_data($data) {
  switch ($this->_chart_type) {
   case 'vertical_column':
   case 'horizonatl_bar':
    $this->_data = ra_conevrt_data_bar_column_wolegend($data, $this->_ignore_empty_value);
    break;

   case 'clustered_column':
   case 'stacked_column':
   case 'clustered_bar':
   case 'stacked_bar':
    foreach ($data[0] as $key => $val) {
     $this->_label = $key;
     break;
    }
    $this->_data = $data;
    break;

   case 'pie':
   case 'donut':
   case 'line':
   case 'funnel':
    $this->_data = $data;
    break;

   case 'default' :
    $this->_data = $data;
    break;
  }
 }

 private function _reset_margins() {
  if (in_array($this->_chart_type, array('pie', 'donut', 'funnel'))) {
   $this->_left_margin = $this->_right_margin = $this->_top_margin = $this->_bottom_margin = 0;
  } else {
   $this->_right_margin = $this->_top_margin = $this->_bottom_margin = 0;
   $this->_left_margin = 30;
  }
  $this->_chart_height = $this->_chart_height_orginal;
  $this->_chart_width = $this->_chart_width_orginal;
 }

 public function getSvgChart_forView() {
  $result1 = $this->result;
  $legend_name = $this->legend_name;
  $legend_name2 = $this->legend_name2;
  $chart_label = $this->chart_label;
  $chart_value = $this->chart_value;
  $this->_legend = [];
  $this->_legend2 = [];
  $this->_label = [];
  $this->_data = [];
  $return_chart = '';
  
  if(empty($this->result)){
   return false;
  }

  foreach ($this->result as $obj) {
   if (!empty($legend_name)) {
    if (!in_array($obj->$legend_name, $this->_legend)) {
     array_push($this->_legend, $obj->$legend_name);
    }
   }

   if (!empty($legend_name2)) {
    if (!in_array($obj->$legend_name2, $this->_legend2)) {
     array_push($this->_legend2, $obj->$legend_name2);
    }
   }
  }

  switch ($this->_chart_type) {
   case 'clustered_column':
   case 'stacked_column':
   case 'clustered_bar':
   case 'stacked_bar':
   case 'line':

    if (!empty($this->_legend2)) {
     foreach ($this->_legend2 as $key_3 => $val_3) {
      $this->_data = [];
      $return_chart .= "<div class='multi_chart_{$key_3}'>";
      $return_chart .= "<span class='{$this->_chart_type} view'>$val_3</span>";
      foreach ($this->result as $obj) {

       if ($obj->$legend_name2 == $val_3) {
        if ($this->_ignore_empty_value && empty($obj->$chart_value)) {
         continue;
        }
        if (!in_array($obj->$chart_label, $this->_label)) {
         array_push($this->_label, $obj->$chart_label);
         $row = [];
         $label = $row['label'] = $obj->$chart_label;
         $row['value'] = [];

         foreach ($this->_legend as $l_k => $l_v) {
          $isnull = true;
          foreach ($result1 as $result1_k => $data_obj) {
           if (($data_obj->$chart_label) == $label && ($data_obj->$legend_name == $l_v) && !empty($obj->$chart_value)) {
            $row['value'][] = $result1[$result1_k]->$chart_value;
            $isnull = false;
            break;
           }
          }
          if ($isnull) {
           $row['value'][] = null;
          }
         }
         array_push($this->_data, $row);
        }
       }
      }
      try {
       $return_chart .= $this->draw_chart();
      } catch (Exception $e) {
       $return_chart = "<br>Invalid chart type for this report.<br> Error @ class_getsvgimage @@ line " . __LINE__ . '<br>' . $e->getMessage();
      }
      $return_chart .= "</div>";
      $this->_reset_margins();
     }
    } else {
     foreach ($this->result as $obj) {
      if (!in_array($obj->$chart_label, $this->_label)) {
       array_push($this->_label, $obj->$chart_label);
       $row = [];
       $label = $row['label'] = $obj->$chart_label;
       $row['value'] = [];

       foreach ($this->_legend as $l_k => $l_v) {
        $isnull = true;
        foreach ($result1 as $result1_k => $data_obj) {
         if (($data_obj->$chart_label) == $label && ($data_obj->$legend_name == $l_v) && !empty($obj->$chart_value)) {
          $row['value'][] = $result1[$result1_k]->$chart_value;
          $isnull = false;
          break;
         }
        }
        if ($isnull) {
         $row['value'][] = null;
        }
       }
       array_push($this->_data, $row);
      }
     }
     try {
      $return_chart = $this->draw_chart();
     } catch (Exception $e) {
      $return_chart = "<br>Invalid chart type for this report.<br> Error @ class_getsvgimage @@ line " . __LINE__ . '<br>' . $e->getMessage();
     }
    }
    break;


   case 'pie':
   case 'donut':
   case 'funnel':
    if (!empty($this->_legend)) {
     $return_chart .= "<ul class='multi_charts'>";
     foreach ($this->_legend as $key_2 => $val_2) {
      $this->_data = [];
      $return_chart .= "<li class='multi_chart_{$key_2}'>";
      $return_chart .= "<span class='multi_chart_{$this->_chart_type} view'>$val_2</span>";
      foreach ($this->result as $obj) {
       if ($obj->$legend_name == $val_2 && !empty($obj->$chart_value)) {
        $this->_data[$obj->$chart_label] = $obj->$chart_value;
       }
      }
      try {
       $return_chart .= $this->draw_chart();
      } catch (Exception $e) {
       $return_chart = "<br>Invalid chart type for this report.<br> Error @ class_getsvgimage @@ line " . __LINE__ . '<br>' . $e->getMessage();
      }
      $return_chart .= "</li>";
      $this->_reset_margins();
     }
     $return_chart .= "</ul>";
    } else {
     $this->_data = [];
     foreach ($this->result as $obj) {
      $this->_data[$obj->$chart_label] = $obj->$chart_value;
     }
     try {
      $return_chart .= $this->draw_chart();
     } catch (Exception $e) {
      $return_chart = "<br>Invalid chart type for this report.<br> Error @ class_getsvgimage @@ line " . __LINE__ . '<br>' . $e->getMessage();
     }
    }
    break;

   case 'horizonatl_bar':
   case 'vertical_column':
    if (!empty($this->_legend)) {
     foreach ($this->_legend as $key_2 => $val_2) {
      $this->_data = [];
      $return_chart .= "<div class='multi_chart_{$key_2}'>";
      $return_chart .= "<span class='{$this->_chart_type} view'>$val_2</span>";
      foreach ($this->result as $obj) {
       if ($obj->$legend_name == $val_2) {
        if ($this->_ignore_empty_value && empty($obj->$chart_value)) {
         continue;
        }
        $row_data = [];
        $row_data['label'] = $obj->$chart_label;
        $row_data['value'] = $obj->$chart_value;
        array_push($this->_data, $row_data);
       }
      }
      try {
       $return_chart .= $this->draw_chart();
      } catch (Exception $e) {
       $return_chart = "<br>Invalid chart type for this report.<br> Error @ class_getsvgimage @@ line " . __LINE__ . '<br>' . $e->getMessage();
      }
      $return_chart .= "</div>";
      $this->_reset_margins();
     }
    } else {
     $this->_data = [];
     foreach ($this->result as $obj) {
      if ($this->_ignore_empty_value && empty($obj->$chart_value)) {
       continue;
      }
      $row_data = [];
      $row_data['label'] = $obj->$chart_label;
      $row_data['value'] = $obj->$chart_value;
      array_push($this->_data, $row_data);
     }
     try {
      $return_chart .= $this->draw_chart();
     } catch (Exception $e) {
      $return_chart = "<br>Invalid chart type for this report.<br> Error @ class_getsvgimage @@ line " . __LINE__ . '<br>' . $e->getMessage();
     }
    }
    break;

   default:
    break;
  }


  return $return_chart;
 }

 private function _dataRange_inDataSet() {
  $min = $max = 0;
  $data_count = 0;
  foreach ($this->_data as $arr) {
   if (is_array($arr['value'])) {
    foreach ($arr['value'] as $key => $value) {
     if ($value > $max) {
      $max = $value;
     }
     if ($value < $min) {
      $min = $value;
     }
    }
   } else {
    if ($arr['value'] > $max) {
     $max = $arr['value'];
    }
    if ($arr['value'] < $min) {
     $min = $arr['value'];
    }
   }
   $data_count++;
  }
  $this->_max_val = $max;
  $this->_min_val = $min;
  $this->_data_count = $data_count;
 }

 private function _axis_unitWidth($highest_number) {
  $ret_a = [];
  $logTenValue = (int) log10($highest_number);
  $numberFraction = (int) ($highest_number / (pow(10, $logTenValue)) );
  if (($numberFraction <= 1.1)) {
   $unit_width = 2 * (pow(10, $logTenValue - 1));
  } else if (($numberFraction > 1.1 ) && ($numberFraction < 2.8 )) {
   $unit_width = 5 * (pow(10, $logTenValue - 1));
  } elseif (($numberFraction >= 2.8 ) && ($numberFraction < 5.8 )) {
   $unit_width = 1 * (pow(10, $logTenValue));
  } else {
   $unit_width = 2 * (pow(10, $logTenValue));
  }
  $ret_a['major_axis_uw'] = $unit_width;
  $ret_a['noof_major_axis'] = ceil($highest_number / $unit_width) - 1;
  $ret_a['minor_axis_uw'] = $unit_width / 5;
  return $ret_a;
 }

 private function _draw_major_grids($max_val, $axis_type, $height_width, $axis_uv, $starting_x, $starting_y) {
  $axis_values = $this->_axis_unitWidth($max_val);
  $major_axis_uw = $axis_values['major_axis_uw'];
  $major_axis_value = $major_axis_uw;
  $axis = '';
  if ($axis_type == 'yaxis') {
   $ending_x = $starting_x + $height_width;
   for ($i = 0; $i <= $axis_values['noof_major_axis']; $i++) {
    if ($this->_draw_minor_grid_x) {
     $axis .= $this->_draw_minor_grids($axis_values['minor_axis_uw'], $axis_type, $height_width, $axis_uv, $starting_x, $starting_y);
    }
    $starting_y -= ($major_axis_uw * $axis_uv);
    $axis .= ' <line x1="' . $starting_x . '"  y1="' . $starting_y . '" x2="' . $ending_x . '"   y2="' . $starting_y . '"  class="major_grid" />';
    $xaxis_for_grid_value = $starting_x - 12;
    $axis .= '<text x="' . $xaxis_for_grid_value . '" dx="10" y="' . $starting_y . '"   class="chart_label_text" >' . $major_axis_value . '</text>';
    $major_axis_value += $major_axis_uw;
   }
  } else {
   for ($i = 0; $i <= $axis_values['noof_major_axis']; $i++) {
    if ($this->_draw_minor_grid_x) {
     $axis .= $this->_draw_minor_grids($axis_values['minor_axis_uw'], $axis_type, $height_width, $axis_uv, $starting_x, $starting_y);
    }
    $starting_x += ($major_axis_uw * $axis_uv);
    $axis .= ' <line x1="' . $starting_x . '"  y1="' . $starting_y . '" x2="' . $starting_x . '"   y2="' . $height_width . '"  class="major_grid" />';
    $yaxis_for_grid_value = $height_width + 12;
    $axis .= '<text x="' . $starting_x . '" dx="10" y="' . $yaxis_for_grid_value . '"   class="chart_label_text" >' . $major_axis_value . '</text>';
    $major_axis_value += $major_axis_uw;
   }
  }

  return $axis;
 }

 private function _draw_major_grids_data($no_of_grids, $axis_type, $height_width, $total_height_width, $starting_x, $starting_y) {
  $grid = '';
  $major_grid_gap = $total_height_width / $no_of_grids;
  if ($axis_type == 'yaxis') {
   for ($i = 0; $i < $no_of_grids; $i++) {
    if ($this->_draw_minor_grid_y) {
     $grid .= $this->_draw_minor_grids($no_of_grids, $axis_type, $height_width, $major_grid_gap, $starting_x, $starting_y);
    }
    $starting_x += $major_grid_gap;
    $grid .= ' <line x1="' . $starting_x . '"  y1="' . $starting_y . '" x2="' . $starting_x . '"   y2="0"  class="major_grid major_grid_data" />';
   }
  } else {
   for ($i = 0; $i <= $no_of_grids; $i++) {
    if ($this->_draw_minor_grid_y) {
     $grid .= $this->_draw_minor_grids($no_of_grids, $axis_type, $height_width, $major_grid_gap, $starting_x, $starting_y);
    }
    $grid .= ' <line x1="' . $starting_x . '"  y1="' . $starting_y . '" x2="' . $height_width . '"   y2="' . $starting_y . '"  class="major_grid major_grid_data" />';
    $starting_y += $major_grid_gap;
   }
  }
  return $grid;
 }

 private function _draw_vertical_grids_for_bar($unit_width, $maximum_val_accross_horizon = '') {
  $max_val = !empty($maximum_val_accross_horizon) ? $maximum_val_accross_horizon : $this->_max_val;
  $axis_values = $this->_axis_unitWidth($max_val);
  $major_axis_uw = $axis_values['major_axis_uw'];
  $minor_axis_uw = $axis_values['minor_axis_uw'];
  $major_axis_value = $major_axis_uw;

  $starting_x = $this->_left_margin + $this->_width_for_xaxis_chart_label;
  $starting_y = 0;
  $grid = '';
  for ($i = 0; $i <= $axis_values['noof_major_axis']; $i++) {
   if ($starting_x <= $this->_chart_width) {
    $starting_x_m = $starting_x;
    if ($this->_draw_minor_grid_x) {
     for ($j = 0; $j <= 3; $j++) {
      $starting_x_m += ($minor_axis_uw * $unit_width);
      $grid .= ' <line x1="' . $starting_x_m . '"  y1="' . $starting_y . '" x2="' . $starting_x_m . '"   y2="' . $this->_chart_height . '"  class="minor_grid" />';
     }
    }
    $starting_x += $major_axis_uw * $unit_width;
    $grid .= ' <line x1="' . $starting_x . '"  y1="' . $starting_y . '" x2="' . $starting_x . '"   y2="' . $this->_chart_height . '"  class="major_grid" />';
    $grid .= '<text x="' . $starting_x . '"  y="' . $this->_chart_height . '"  dy="13" class="chart_label_text" >' . number_thousand_converted($major_axis_value) . '</text>';
    $major_axis_value += $major_axis_uw;
   }
  }
  $this->_vertical_grid_end_xaxis = $starting_x;
  return $grid;
 }

 private function _draw_horizontal_grids_for_bar($no_of_elements) {
  $grid = '';
  $major_grid_gap = $this->_chart_height / $no_of_elements;
  $minor_grid_gap = $major_grid_gap / 4;
  $starting_x = $this->_left_margin + $this->_width_for_xaxis_chart_label;
  $ending_x = $this->_vertical_grid_end_xaxis;
  $starting_y = 0;
  for ($i = 0; $i <= $no_of_elements; $i++) {
   $starting_y_m = $starting_y;
   if (($this->_draw_minor_grid_y) && ($starting_y_m < $this->_chart_height)) {
    for ($j = 0; $j <= 3; $j++) {
     $starting_y_m += $minor_grid_gap;
     $grid .= ' <line x1="' . $starting_x . '"  y1="' . $starting_y_m . '" x2="' . $ending_x . '"   y2="' . $starting_y_m . '"  class="minor_grid " />';
    }
   }
   $grid .= ' <line x1="' . $starting_x . '"  y1="' . $starting_y . '" x2="' . $ending_x . '"   y2="' . $starting_y . '"  class="major_grid major_grid_data" />';
   $starting_y += $major_grid_gap;
  }
  return $grid;
 }

 private function _draw_minor_grids($minor_axis_uw, $axis_type, $height_width, $axis_uv, $starting_x, $starting_y) {
  $minor_grid = '';
  if ($axis_type == 'yaxis') {
   $ending_x = $starting_x + $height_width;
   for ($i = 0; $i <= 3; $i++) {
    $starting_y += ($minor_axis_uw * $axis_uv);
    if ($starting_y < $this->_chart_height) {
     $minor_grid .= ' <line x1="' . $starting_x . '"  y1="' . $starting_y . '" x2="' . $ending_x . '"   y2="' . $starting_y . '"  class="minor_grid" />';
    }
   }
  } else {
   for ($i = 0; $i <= 3; $i++) {
    $starting_x += ($minor_axis_uw * $axis_uv);
    if ($height_width < $this->_chart_width) {
     $minor_grid .= ' <line x1="' . $starting_x . '"  y1="' . $starting_y . '" x2="' . $starting_x . '"   y2="' . $height_width . '"  class="minor_grid" />';
    }
   }
  }
  return $minor_grid;
 }

 private function _maximum_number_of_element() {
  $count = 1;
  foreach ($this->_data as $data_row) {
   if (count($data_row['value']) > $count) {
    $count = count($data_row['value']);
   }
  }
  return $count;
 }

 private function _prepare_line() {
  $this->_width_for_xaxis_chart_label = 0;
  foreach ($this->_data as $data) {
   $value = $data['value'];
   if (is_array($value)) {
    foreach ($value as $value_k => $value_v) {
     $width_for_xaxis_chart_label_n = strlen(strval($value_v)) * 2;
     $this->_width_for_xaxis_chart_label = ($width_for_xaxis_chart_label_n > $this->_width_for_xaxis_chart_label ) ? $width_for_xaxis_chart_label_n : $this->_width_for_xaxis_chart_label;
    }
   } else {
    $width_for_xaxis_chart_label_n = strlen(strval($value)) * 2;
    $this->_width_for_xaxis_chart_label = ($width_for_xaxis_chart_label_n > $this->_width_for_xaxis_chart_label ) ? $width_for_xaxis_chart_label_n : $this->_width_for_xaxis_chart_label;
   }
  }
  $this->_left_margin += $this->_width_for_xaxis_chart_label;

  $this->_height_for_xaxis_chart_label = 0;

  $no_of_rows_for_label = ceil((120 * count($this->_data)) / $this->_chart_width);
  if($no_of_rows_for_label < 2 ){
   $no_of_rows_for_label = 2;
  }
  $this->_height_for_xaxis_chart_label = 40 * $no_of_rows_for_label;
  foreach ($this->_data as $data) {
   $value = $data['label'];
   $height_for_xaxis_chart_label_n = strlen(strval($value)) * 7;
   $this->_height_for_xaxis_chart_label = ($height_for_xaxis_chart_label_n > $this->_height_for_xaxis_chart_label ) ? $height_for_xaxis_chart_label_n : $this->_height_for_xaxis_chart_label;
  }
  $this->_bottom_margin += $this->_height_for_xaxis_chart_label;
 }

 private function _draw_line() {
  if ((empty($this->_data)) || (!is_array($this->_data))) {
   return;
  }
  $this->_prepare_line();
  $x_cordinate = $this->_left_margin;
  $max_no_of_data = $this->_maximum_number_of_element();
  $width_for_each_leg = 120;

  $this->_chart_width = $this->_chart_width - $this->_left_margin - $this->_right_margin;
  $this->_chart_height = $this->_chart_height - $this->_height_of_text - $this->_bottom_margin - $this->_height_of_legend;
  $unit_height = !empty($this->_max_val) ? ($this->_chart_height) / $this->_max_val : 1;
  $point_gap = ($this->_chart_width / ($max_no_of_data + 1));
  //$yaxis_data = ($yaix_height / 1.5);
  $no_of_label_inrow = ceil($this->_chart_width / $width_for_each_leg);


  $title_xaxis = $this->_chart_width / 2;
  $title_yaxis = $this->_chart_height + $this->_bottom_margin;
  $legend_yaxis = $this->_chart_height_orginal - $this->_bottom_margin;

  $chart = "<div class='chart_name'>" . $this->_chart_name . '</div>';
  $chart .= "<svg class='chart' width=\"$this->_chart_width_orginal\" height=\"$this->_chart_height_orginal\">";
  $chart .= ' <line x1="' . $this->_left_margin . '"  y1="0" x2="' . $this->_left_margin . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $chart .= ' <line x1="' . $this->_left_margin . '"  y1="' . $this->_chart_height . '" x2="' . $this->_chart_width_orginal . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $chart .= '<text x="' . $title_xaxis . '" y="' . $title_yaxis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . ' </text>';
  if ($this->_draw_major_grid_x) {
   $chart .=$this->_draw_major_grids($this->_max_val, 'yaxis', $this->_chart_width, $unit_height, $this->_left_margin, $this->_chart_height);
  }
  if ($this->_draw_major_grid_y) {
   $chart .=$this->_draw_major_grids_data($max_no_of_data, 'yaxis', $point_gap, $this->_chart_width, $this->_left_margin, $this->_chart_height);
  }
  $line_count = 0;

//  $data_ai = new ArrayIterator($this->_data);
//  $data_ai->seek(0);
//  while ($data_ai->valid()) {
//   $data_k = $data_ai->key();
//   $data_k_previous = $data_k - 1;
//
//   $data = $data_ai->current();
//   $data_ai->next();
//   $data_next = $data_ai->current();
//   $data_ai->seek($data_k_previous);
//   $data_last = $data_ai->current();
//   $data_ai->seek($data_k);
//
//
//   $data_count = 0;
//   $x1 = $y1 = 0;
//   $xaxis = $x_cordinate;
//   $line_class = 'line_class_' . $line_count;
//   $value_a = $data['value'];
//   $label = $data['label'];
//   foreach ($value_a as $key => $value) {
//    $xaxis += $point_gap;
//    $x2 = $xaxis;
//    $y2 = $yaxis = $this->_chart_height - ($unit_height * $value);
//    $element_title = $value . ' ( ' . $label . ')';
//    $chart .= '<g>';
//    $chart .= "<rect x=\"$xaxis\" y=\"$yaxis\" width=\"5\" height=\"5\" class=\" $key $line_class line_chart \"  />";
//    $chart .= '<title>' . $element_title . '</title>';
//    if ($data_count > 0) {
//     $chart .= "<line x1=\"$x1\" y1=\"$y1\" x2=\"$x2\" y2=\"$y2\"  class=\"$line_class line_chart line\" />";
//     $chart .= '<title>' . $element_title . '</title>';
//    }
//    $x1 = $x2;
//    $y1 = $y2;
//    if ($this->_show_elemnt_value && $data_k == 0) {
//     $yaxis_elem = $yaxis + 20;
//     $chart .= '<text x="' . $xaxis . '" y="' . $yaxis_elem . '"  dy="-4" class="chart_value_text" >' . $this->_legend[$key] . '</text>';
//    }
//    $chart .= '</g>';
//    $data_count++;
//   }
//   $line_count++;
//   $data_ai->next();
//  }

  foreach ($this->_data as $data_k => $data) {
   $data_count = 0;
   $x1 = $y1 = 0;
   $xaxis = $x_cordinate;
   $line_class = 'line_class_' . $line_count;
   $value_a = $data['value'];
   $label = $data['label'];
   foreach ($value_a as $key => $value) {
    $xaxis += $point_gap;
    $x2 = $xaxis;
    $y2 = $yaxis = $this->_chart_height - ($unit_height * $value);
    $element_title = $value . ' ( ' . $label . ')';
    $chart .= '<g>';
//    $chart .= "<rect x=\"$xaxis\" y=\"$yaxis\" width=\"5\" height=\"5\" class=\" $key $line_class line_chart \"  />";
    $chart .= '<circle cx="'.$xaxis.'" cy="'.$yaxis.'" r="3" class=" ' .$key . ' ' .$line_class .' line circle"  />';
    $chart .= '<title>' . $element_title . '</title>';
    if ($data_count > 0) {
     $chart .= "<line x1=\"$x1\" y1=\"$y1\" x2=\"$x2\" y2=\"$y2\"  class=\"$line_class line_chart line\" />";
     $chart .= '<title>' . $element_title . '</title>';
    }
    $x1 = $x2;
    $y1 = $y2;
    if ($this->_show_elemnt_value && $data_k == 0) {
     $yaxis_elem = $yaxis + 20;
     $chart .= '<text x="' . $xaxis . '" y="' . $yaxis_elem . '"  dy="-4" class="chart_value_text" >' . $this->_legend[$key] . '</text>';
    }
    $chart .= '</g>';
    $data_count++;
   }
   $line_count++;
  }
  //show labels
//  pa($this);
  $legend_x = $this->_left_margin;
  $line_count2 = 0;
  $legend_yaxis_org = $legend_yaxis;

  $label_k = 0;
  $count_of_label_rows = 0;

  foreach ($this->_data as $line_data) {
   $label_k++;
   $line_class = 'line_class_' . $line_count2;
   $legend_y_axis_rect = $legend_yaxis + 30;
   $chart .= "<g><rect x=\"$legend_x\" y=\"$legend_y_axis_rect\" width=\"10\" height=\"10\"  class=\"$line_class line_chart legend \"/>";
   $chart .= '<title>' . $line_data['label'] . '</title></g>';
   $legend_x += 15;
   $legend_y_axis_rect += 10;
   $chart .= '<g><text x="' . $legend_x . '" y="' . $legend_y_axis_rect . '"  '
    . 'class="chart_legend_title" >' . $line_data['label'] . ' </text>';
   $chart .= '<title>' . $line_data['label'] . '</title></g>';

   $legend_x += $width_for_each_leg;
   if ($label_k >= $no_of_label_inrow) {
    $label_k = 0;
    $count_of_label_rows++;
    $legend_x = $this->_left_margin;
    $legend_yaxis = $legend_yaxis_org + 25 * $count_of_label_rows;
   }

   $line_count2++;
  }

  return $chart;
 }

 private function _prepare_column() {
  /*
   * Left margina and right margin determines the total width available for chart graph & text.
   * Increase the left & right margin as per the text value in value and legend.
   * The bottom display the label. Reduce the height by the height of the text
   */

  $this->_bottom_margin = $this->_bottom_margin < 30 ? 30 : $this->_bottom_margin;
  if ((empty($this->_data)) || (!is_array($this->_data))) {
   return;
  }
  $this->_width_for_xaxis_chart_label = 0;
  foreach ($this->_data as $data) {
   $value = $data['value'];
   if (is_array($value)) {
    foreach ($value as $value_k => $value_v) {
     $width_for_xaxis_chart_label_n = strlen(strval($value_v)) * 2;
     $this->_width_for_xaxis_chart_label = ($width_for_xaxis_chart_label_n > $this->_width_for_xaxis_chart_label ) ? $width_for_xaxis_chart_label_n : $this->_width_for_xaxis_chart_label;
    }
   } else {
    $width_for_xaxis_chart_label_n = strlen(strval($value)) * 2;
    $this->_width_for_xaxis_chart_label = ($width_for_xaxis_chart_label_n > $this->_width_for_xaxis_chart_label ) ? $width_for_xaxis_chart_label_n : $this->_width_for_xaxis_chart_label;
   }
  }
  $this->_left_margin += $this->_width_for_xaxis_chart_label;

  $legne_l = 0;

  if (!empty($this->_legend)) {
   foreach ($this->_legend as $l_k => $l_v) {
    $legne_l_n = strlen($l_v) * 2;
    $legne_l = $legne_l_n > $legne_l ? $legne_l_n : $legne_l;
   }
  }
  $legne_l_value = 4 * $legne_l;
  $this->_right_margin += $legne_l_value;
  $this->_chart_width = $this->_chart_width - $this->_left_margin - $this->_right_margin;
  $this->_chart_width = $this->_chart_width - $legne_l_value;

  $this->_height_for_xaxis_chart_label = 60;
  foreach ($this->_data as $data) {
   $value = $data['label'];
   $height_for_xaxis_chart_label_n = strlen(strval($value)) * 6;
   $this->_height_for_xaxis_chart_label = ($height_for_xaxis_chart_label_n > $this->_height_for_xaxis_chart_label ) ? $height_for_xaxis_chart_label_n : $this->_height_for_xaxis_chart_label;
  }
  $this->_chart_height = $this->_chart_height - $this->_height_of_text - $this->_height_for_xaxis_chart_label;
  $this->_bottom_margin - $this->_height_of_legend;
 }

 private function _prepare_bar() {
  if ((empty($this->_data)) || (!is_array($this->_data))) {
   return;
  }
  $this->_right_margin = $this->_right_margin < 20 ? 20 : $this->_right_margin;
  $legne_l = 0;
  if (!empty($this->_legend)) {
   foreach ($this->_legend as $l_k => $l_v) {
    $legne_l_n = strlen($l_v);
    $legne_l = $legne_l_n > $legne_l ? $legne_l_n : $legne_l;
   }
  }
  $this->_width_for_xaxis_chart_label = 10 * $legne_l;
  $this->_right_margin += $this->_width_for_xaxis_chart_label;

  $this->_width_for_xaxis_chart_label = 0;
  foreach ($this->_data as $data) {
   $value = $data['label'];
   $width_for_xaxis_chart_label_n = strlen(strval($value)) * 2;
   $this->_width_for_xaxis_chart_label = ($width_for_xaxis_chart_label_n > $this->_width_for_xaxis_chart_label ) ? $width_for_xaxis_chart_label_n : $this->_width_for_xaxis_chart_label;
  }
  $this->_left_margin += $this->_width_for_xaxis_chart_label;

  $height_for_value = 0;
  foreach ($this->_data as $data) {
   $value = $data['value'];
   if (is_array($value)) {
    foreach ($value as $value_k => $value_v) {
     $height_for_value_n = strlen(strval($value_v)) * 2;
     $height_for_value = ($height_for_value_n > $height_for_value ) ? $height_for_value_n : $height_for_value;
    }
   } else {
    $height_for_value_n = strlen(strval($value)) * 2;
    $height_for_value = ($height_for_value_n > $height_for_value ) ? $height_for_value_n : $height_for_value;
   }
  }
  $this->_bottom_margin += $height_for_value;

  $this->_chart_width = $this->_chart_width - $this->_left_margin - $this->_right_margin;
  $this->_chart_height = $this->_chart_height - $this->_bottom_margin - $this->_top_margin;
 }

//hegith is x axis & width is y axis
 //grid  on x axis
 private function _draw_vertical_column() {
  if ((empty($this->_data)) || (!is_array($this->_data))) {
   return;
  }
  $this->_prepare_column();
  $no_of_elements = count($this->_data);
  $data_range = $this->_max_val - $this->_min_val;
  $unit_height = !empty($data_range) ? ($this->_chart_height) / $data_range : 0;
  $total_no_of_elemsts_with_gap = ($no_of_elements > 4 ) ? 2 * $no_of_elements : 8;
  $bar_width = $bar_gap = ($this->_chart_width / ($total_no_of_elemsts_with_gap));
  $title_xaxis = $this->_chart_width / 2;
  $title_yaxis = $this->_chart_height + $this->_bottom_margin;

  $bar = "<div class='chart_name'>" . $this->_chart_name . '</div>';
  $bar .= "<svg class='chart' width=\"$this->_chart_width_orginal\" height='$this->_chart_height_orginal'>";
  $bar .= ' <line x1="' . $this->_left_margin . '"  y1="0" x2="' . $this->_left_margin . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $bar .= ' <line x1="' . $this->_left_margin . '"  y1="' . $this->_chart_height . '" x2="' . $this->_chart_width_orginal . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $bar .= '<text x="' . $title_xaxis . '" y="' . $title_yaxis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . ' </text>';
  if ($this->_draw_major_grid_x) {
   $bar .=$this->_draw_major_grids($this->_max_val, 'yaxis', $this->_chart_width, $unit_height, $this->_left_margin, $this->_chart_height);
  }

  if ($this->_draw_major_grid_y) {
   $bar .=$this->_draw_major_grids_data($no_of_elements, 'yaxis', $bar_width, $this->_chart_width, $this->_left_margin, $this->_chart_height);
  }

  $x_cordinate = $this->_left_margin + ($bar_gap / 2);
  $data_count = 0;
  $bar_width_15 = 0.75 * $bar_width;
  foreach ($this->_data as $data) {
   $no_of_elements++;
   $data_class = 'data_class_' . $data_count;
   $value = $data['value'];
   $label = $data['label'];
   $bar_height = $unit_height * $value;
   $y_cordinate = $this->_chart_height - $bar_height;
   $bar .= "<g transform=\"translate($x_cordinate,$y_cordinate)\">";
   $bar .= "<rect width=\"$bar_width\" height=\"$bar_height\"  label=\"$label &nbsp; $value \" class=\"chart_value $data_class $label \">";
   $bar .= '<title>' . $value . '&nbsp; <br>(' . $label . ')</title>';
   $bar .= '</rect>';
   $bar .= '<text x="0"  dx="' . $bar_width_15 . '" y="' . $bar_height . '" dy="12" data-label="' . $label . '" data-value="' . $value . '" '
    . "transform=\"rotate(45 $bar_width_15,$bar_height)\"" . 'class="chart_label_text x_axis" >';
   $bar .= '<title>' . $label . '</title>';
   $bar .= $label . '</text>';
   if ($this->_show_elemnt_value) {
    $bar .= '<text x="' . $bar_width_15 . '" y="0"  dy="-4" class="chart_value_text" >' . $value . '</text>';
   }
   $bar .= '</g>';

   $x_cordinate += $bar_width + ($bar_gap);
   $data_count++;
  }

  return $bar;
 }

 private function _draw_clustered_column() {
  $this->_prepare_column();
  $data_count = 0;
  $no_of_elements = count($this->_data);
  if (empty($no_of_elements)) {
   return false;
  }
  $data_range = $this->_max_val - $this->_min_val;
  $unit_height = !empty($data_range) ? ($this->_chart_height) / $data_range : 1;
  $legend_yaxis = $this->_top_margin;

  $legend_xaxis = $this->_chart_width + $this->_left_margin;
  $title_xaxis = $this->_chart_width / 2;
  $title_yaxis = $this->_chart_height + $this->_bottom_margin;
//   $this->_chart_height -= 50;
  $bar = "<div class='chart_name'>" . $this->_chart_name . '</div>';
  $bar .= "<svg class='chart clustered_column " . $this->_chart_name . "' "
   . "width=\"$this->_chart_width_orginal\" height='$this->_chart_height_orginal'>";
  $bar .= ' <line x1="' . $this->_left_margin . '"  y1="0" x2="' . $this->_left_margin . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $bar .= ' <line x1="' . $this->_left_margin . '"  y1="' . $this->_chart_height . '" x2="' . $legend_xaxis . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $bar .= '<text x="' . $title_xaxis . '" y="' . $title_yaxis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . '  </text>';

  /* End of generic */
  $total_no_of_elements_with_gap = ($no_of_elements * count($this->_data[0]['value'])) + (2 * $no_of_elements );
  $bar_width = ($this->_chart_width / ($total_no_of_elements_with_gap));
  $bar_gap = 2 * $bar_width;
  $xaxis_data = ($bar_width / 1.5);
  if ($this->_draw_major_grid_x) {
   $bar .=$this->_draw_major_grids($this->_max_val, 'yaxis', $this->_chart_width, $unit_height, $this->_left_margin, $this->_chart_height);
  }
  if ($this->_draw_major_grid_y) {
   $bar .=$this->_draw_major_grids_data($no_of_elements, 'yaxis', $bar_width, $this->_chart_width, $this->_left_margin, $this->_chart_height);
  }

  $x_cordinate = $this->_left_margin;
  $y_cordinate = $this->_top_margin;
  $x_cordinate += ($bar_gap / 2);
  foreach ($this->_data as $data) {
   $data_count++;
   $data_class = 'data_class_' . $data_count;
   $value_a = $data['value'];
   $label = $data['label'];
   $xaxis_label_count = 1;
   foreach ($value_a as $key => $value) {
    $cluster_class = 'cluster_class_' . $key;
    $bar_height = ($unit_height * $value);
    $y_cordinate = $this->_chart_height - $bar_height;
    $xaxis_data = $bar_width + strlen(strval($value)) * 7;
    $bar .= "<g transform=\"translate($x_cordinate,$y_cordinate)\">";
    $bar .= "<rect width=\"$bar_width\" height=\"$bar_height\" class=\"$data_class $label $cluster_class\">";
    $bar .= '<title>' . $value . '&nbsp; <br>(' . $label . ')</title>';
    $bar .= '</rect>';
    if ($xaxis_label_count == 1) {
     $bar .= '<text x="0"  dx="' . $bar_width . '" y="' . $bar_height . '" dy="12" '
      . "transform=\"rotate(45 $bar_width,$bar_height)\"" . 'class="chart_label_text x_axis" >';
     $bar .= '<title>' . $label . '</title>';
     $bar .= $label . '</text>';
    }
    if ($this->_show_elemnt_value) {
     $bar .= '<text x="' . $bar_width . '" y="0"  dy="-4" class="chart_value_text" >' . $value . '</text>';
    }
    $bar .= '</g>';
    $x_cordinate += $bar_width;
    $xaxis_label_count++;
   }
   $x_cordinate += ($bar_gap);
  }

  $value_a = $this->_data[0]['value'];

  foreach ($value_a as $key => $value) {
   $cluster_class = 'cluster_class_' . $key;
   $legend_y_axis_rect = $legend_yaxis - 10;
   $bar .= "<rect x=\"$legend_xaxis\" y=\"$legend_y_axis_rect\" width=\"10\" height=\"10\" class=\" $key $cluster_class legend \"/>";
   $legend_xaxis += 15;
   $bar .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_legend_title" >' . $this->_legend[$key] . ' </text>';
   $legend_yaxis += 30;
   $legend_xaxis -= 15;
  }
  $bar .= '</svg>';
  return $bar;
 }

 private function _draw_stacked_column() {
  $this->_prepare_column();
  $data_count = 0;
  $no_of_data = count($this->_data);
  if (empty($no_of_data)) {
   return false;
  }
  $no_of_elements = count($this->_data);
  $legend_yaxis = $this->_top_margin;
  $legend_xaxis = $this->_chart_width + $this->_left_margin;
  $title_xaxis = $this->_chart_width / 2;

  $title_yaxis = $this->_chart_height + $this->_bottom_margin;
  $bar = "<div class='chart_name'>" . $this->_chart_name . '</div>';
  $bar .= "<svg class='chart clustered_column " . $this->_chart_name . "' "
   . "width=\"$this->_chart_width_orginal\" height='$this->_chart_height_orginal'>";
  $bar .= ' <line x1="' . $this->_left_margin . '"  y1="0" x2="' . $this->_left_margin . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $bar .= ' <line x1="' . $this->_left_margin . '"  y1="' . $this->_chart_height . '" x2="' . $this->_chart_width_orginal . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $bar .= '<text x="' . $title_xaxis . '" y="' . $title_yaxis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . '  </text>';

  /* End of generic */
  $total_no_of_elemsts_with_gap = 2 * $no_of_elements;
  $bar_width = ($this->_chart_width / ($total_no_of_elemsts_with_gap));
  $bar_gap = 2 * $bar_width;
  $hghest_sum_of_all_element = $this->_highest_sum_of_all_elements();
  $unit_height = !empty($hghest_sum_of_all_element) ? ($this->_chart_height ) / $hghest_sum_of_all_element : 1;

  if ($this->_draw_major_grid_x) {
   $bar .=$this->_draw_major_grids($hghest_sum_of_all_element, 'yaxis', $this->_chart_width, $unit_height, $this->_left_margin, $this->_chart_height);
  }
  if ($this->_draw_major_grid_y) {
   $bar .=$this->_draw_major_grids_data($no_of_data, 'yaxis', $bar_width, $this->_chart_width, $this->_left_margin, $this->_chart_height);
  }

  $x_cordinate = $this->_left_margin;
  $y_cordinate = $this->_top_margin;
  $x_cordinate += ($bar_gap / 4);
  foreach ($this->_data as $data) {
   $data_count++;
   $data_class = 'data_class_' . $data_count;
   $value_a = $data['value'];
   $label = $data['label'];
   $xaxis_label_count = 1;
   $bar_height_cum = 0;
   foreach ($value_a as $key => $value) {
    $cluster_class = 'cluster_class_' . $key;
    $bar_height_cum = empty($bar_height_cum) ? ($unit_height * $value) : (($unit_height * $value) + $bar_height_cum);
    $bar_height = $unit_height * $value;
    $y_cordinate = $this->_chart_height - $bar_height_cum;
    $label_xaxis_dx = $bar_gap / $no_of_elements;

    $bar .= "<g transform=\"translate($x_cordinate,$y_cordinate)\">";
    $bar .= "<rect width=\"$bar_width\" height=\"$bar_height\" class=\"$data_class $label $cluster_class\">";
    $bar .= '<title>' . $value . '&nbsp; <br>(' . $label . ')</title>';
    $bar .= '</rect>';
    if ($xaxis_label_count == 1) {
     $bar .= '<text x="0"  dx="' . $bar_width . '" y="' . $bar_height . '" dy="12" '
      . "transform=\"rotate(45 $bar_width,$bar_height)\"" . 'class="chart_label_text x_axis" >';
     $bar .= '<title>' . $label . '</title>';
     $bar .= $label . '</text>';
    }
    if ($this->_show_elemnt_value) {
     $bar .= '<text x="' . $bar_width . '" y="0"  dy="-4" class="chart_value_text" >' . $value . '</text>';
    }
    $bar .= '</g>';

    $xaxis_label_count++;
   }
   $x_cordinate += ($bar_gap);
  }

  $value_a = $this->_data[0]['value'];
  foreach ($value_a as $key => $value) {
   $cluster_class = 'cluster_class_' . $key;
   $legend_y_axis_rect = $legend_yaxis - 10;
   $bar .= "<rect x=\"$legend_xaxis\" y=\"$legend_y_axis_rect\" width=\"10\" height=\"10\" class=\" $key $cluster_class legend \"/>";
   $legend_xaxis += 15;
   $bar .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_legend_title" >' . $this->_legend[$key] . ' </text>';
   $legend_yaxis += 30;
   $legend_xaxis -= 15;
  }

  return $bar;
 }

//hegith is x axis & width is y axis
 private function _draw_horizonatl_bar() {
  if ((empty($this->_data)) || (!is_array($this->_data))) {
   return;
  }
  $this->_prepare_bar();
  $no_of_elements = count($this->_data);
  $data_range = $this->_max_val - $this->_min_val;
  if ($data_range <= 0) {
   echo "<br> Wrong data selection. No value in value field";
   return;
  }
  $unit_height = ($this->_chart_height) / $data_range;
//  $total_no_of_elemsts_with_gap = 2 * $no_of_elements;
  $total_no_of_elemsts_with_gap = ($no_of_elements > 4 ) ? 2 * $no_of_elements : 8;
  $bar_height = $bar_gap = ($this->_chart_height / ($total_no_of_elemsts_with_gap));
  $title_xaxis = $this->_chart_width - (strlen($this->_x_axis_text) * 2);
  $title_yaxis = $this->_chart_height + $this->_bottom_margin;
  $unit_width = ($this->_chart_width ) / ($data_range * 1.2);
  $legend_xaxis = $this->_chart_width + $this->_left_margin;
  $chart_strat_x_axis = $this->_width_for_xaxis_chart_label + $this->_left_margin;

  $bar = "<div class='chart_name'>" . $this->_chart_name . '</div>';
  $bar .= "<svg class='chart' width=\"$this->_chart_width_orginal\" height='$this->_chart_height_orginal'>";
  $bar .= ' <line x1="' . $chart_strat_x_axis . '"  y1="0" x2="' . $chart_strat_x_axis . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $bar .= ' <line x1="' . $chart_strat_x_axis . '"  y1="' . $this->_chart_height . '" x2="' . $legend_xaxis . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $bar .= '<text x="' . $title_xaxis . '" y="' . $title_yaxis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . ' </text>';

//x axis grid for horizonatl bars 
  if ($this->_draw_major_grid_x) {
   $bar .=$this->_draw_vertical_grids_for_bar($unit_width);
  }
//horizonatl grids for bars
  if ($this->_draw_major_grid_y) {
   $bar .=$this->_draw_horizontal_grids_for_bar($no_of_elements);
  }
  $yaxis_data = ($bar_height / 1.5);
  $data_count = 0;
  $y_cordinate = $this->_top_margin;
  $x_cordinate = $this->_left_margin + $this->_width_for_xaxis_chart_label;
  foreach ($this->_data as $data) {
   $data_count++;
   $data_class = 'data_class_' . $data_count;
   $value = $data['value'];
   $label = $data['label'];
   $bar_width = $unit_height * $value;
   $xaxis_label = 0;
   $xaxis_data = $bar_width + strlen(strval($value)) * 7;
   $bar .= "<g transform=\"translate($x_cordinate,$y_cordinate)\">";
   $bar .= "<rect width=\"$bar_width\" height=\"$bar_height\" class=\"$data_class $label\">";
   $bar .= '<title>' . $value . '&nbsp; <br>(' . $label . ')</title>';
   $bar .= '</rect>';
   $bar .= '<text x="' . $xaxis_label . '" dx="-5" y="' . $yaxis_data . '"   class="chart_label_text" >';
   $bar .= '<title>' . $label . '</title>';
   $bar .= $label . '</text>';
   $bar .= '<text x="' . $xaxis_data . '" y="' . $yaxis_data . '"   class="chart_value_text" >' . $value . '</text>';
   $bar .= '</g>';

   $y_cordinate += $bar_height + ($bar_gap);
  }

  return $bar;
 }

//hegith is x axis & width is y axis
 private function _draw_clustered_bar() {
  if ((empty($this->_data)) || (!is_array($this->_data))) {
   return;
  }
  $this->_prepare_bar();
  $no_of_elements = count($this->_data);
  $data_range = ($this->_max_val - $this->_min_val);
  if (empty($data_range)) {
   return false;
  }
  $title_xaxis = $this->_chart_width / 2;
  $title_yaxis = $this->_chart_height + $this->_bottom_margin;
  $unit_width = ($this->_chart_width ) / ($data_range * 1.4);
  $total_no_of_elemsts_with_gap = ($no_of_elements * count($this->_data[0]['value'])) + (2 * $no_of_elements );
  $bar_height = ($this->_chart_height / ($total_no_of_elemsts_with_gap));
  $bar_gap = 2 * $bar_height;
  $yaxis_data = ($bar_height / 1.5);
  $legend_yaxis = $this->_top_margin;
  $legend_xaxis = $this->_chart_width_orginal - $this->_right_margin;
  $chart_start_x_axis = $this->_width_for_xaxis_chart_label + $this->_left_margin;

  $bar = "<div class='chart_name'>" . $this->_chart_name . '</div>';
  $bar .= "<svg class='chart' width=\"$this->_chart_width_orginal\" height='$this->_chart_height_orginal'>";
  $bar .= ' <line x1="' . $chart_start_x_axis . '"  y1="0" x2="' . $chart_start_x_axis . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $bar .= ' <line x1="' . $chart_start_x_axis . '"  y1="' . $this->_chart_height . '" x2="' . $legend_xaxis . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $bar .= '<text x="' . $title_xaxis . '" y="' . $title_yaxis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . ' </text>';

//x axis grid for horizonatl bars 
  if ($this->_draw_major_grid_x) {
   $bar .=$this->_draw_vertical_grids_for_bar($unit_width);
  }
//horizonatl grids for bars
  if ($this->_draw_major_grid_y) {
   $bar .=$this->_draw_horizontal_grids_for_bar($no_of_elements);
  }

  $data_count = 0;
  $x_cordinate = $this->_left_margin + $this->_width_for_xaxis_chart_label;
  $y_cordinate = ($bar_gap / 2);
  foreach ($this->_data as $data) {
   $data_count++;
   $data_class = 'data_class_' . $data_count;
   $value_a = $data['value'];
   $label = $data['label'];
   $xaxis_label_count = 1;
   foreach ($value_a as $key => $value) {
    $cluster_class = 'cluster_class_' . $key;
    $bar_width = ($unit_width * $value);
    $xaxis_label = 0;
    $xaxis_data = $bar_width + strlen(strval($value)) * 7;
    $bar .= "<g transform=\"translate($x_cordinate,$y_cordinate)\">";
    $bar .= "<rect width=\"$bar_width\" height=\"$bar_height\" class=\"$data_class $label $cluster_class \">";
    $bar .= '<title>' . $value . '&nbsp; <br>(' . $label . ')</title>';
    $bar .= '</rect>';
    if ($xaxis_label_count == 1) {
     $bar .= '<text x="' . $xaxis_label . '" dx="-5" y="' . $yaxis_data . '"   class="chart_label_text" >';
     $bar .= '<title>' . $label . '</title>';
     $bar .= $label . '</text>';
    }
    if ($this->_show_elemnt_value) {
     $bar .= '<text x="' . $xaxis_data . '" y="' . $yaxis_data . '"   class="chart_value_text" >' . $value . '</text>';
    }
    $bar .= '</g>';
    $y_cordinate += $bar_height;
    $xaxis_label_count++;
   }
   $y_cordinate += $bar_gap;
  }

  $value_a = $this->_data[0]['value'];
  foreach ($value_a as $key => $value) {
   $cluster_class = 'cluster_class_' . $key;
   $legend_y_axis_rect = $legend_yaxis - 10;
   $bar .= "<rect x=\"$legend_xaxis\" y=\"$legend_y_axis_rect\" width=\"10\" height=\"10\" class=\" $key $cluster_class legend \"/>";
   $legend_xaxis += 15;
   $bar .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_legend_title" >' . $this->_legend[$key] . ' </text>';
   $legend_yaxis += 30;
   $legend_xaxis -= 15;
  }
  $bar .= '</svg>';

  return $bar;
 }

 private function _highest_sum_of_all_elements() {
  $hghest_sum_of_all_element = 0;
  foreach ($this->_data as $data) {
   $hghest_sum_of_element = 0;
   foreach ($data['value'] as $key => $value) {
    $hghest_sum_of_element += abs($value);
   }
   if ($hghest_sum_of_element > $hghest_sum_of_all_element) {
    $hghest_sum_of_all_element = $hghest_sum_of_element;
   }
  }

  return $hghest_sum_of_all_element;
 }

 private function _draw_stacked_bar() {
  if ((empty($this->_data)) || (!is_array($this->_data))) {
   return;
  }
  $this->_prepare_bar();
  $no_of_elements = count($this->_data);
  if (empty($no_of_elements)) {
   return false;
  }
  $title_xaxis = $this->_chart_width / 2;
  $title_yaxis = $this->_chart_height + $this->_bottom_margin;
  $legend_yaxis = $this->_top_margin;
  $legend_xaxis = $this->_chart_width_orginal - $this->_right_margin;

  $hghest_sum_of_all_element = $this->_highest_sum_of_all_elements();
  $unit_width = !empty($hghest_sum_of_all_element) ? ($this->_chart_width ) / ($hghest_sum_of_all_element * 1.4) : 1;

  $total_no_of_elemsts_with_gap = 2 * $no_of_elements;
  $bar_height = $bar_gap = ($this->_chart_height / ($total_no_of_elemsts_with_gap));
  $yaxis_data = ($bar_height / 1.5);
  $chart_start_x_axis = $this->_width_for_xaxis_chart_label + $this->_left_margin;

  $bar = "<div class='chart_name'>" . $this->_chart_name . '</div>';
  $bar .= "<svg class='chart' width=\"$this->_chart_width_orginal\" height='$this->_chart_height_orginal'>";
  $bar .= ' <line x1="' . $chart_start_x_axis . '"  y1="0" x2="' . $chart_start_x_axis . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $bar .= ' <line x1="' . $chart_start_x_axis . '"  y1="' . $this->_chart_height . '" x2="' . $legend_xaxis . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
  $bar .= '<text x="' . $title_xaxis . '" y="' . $title_yaxis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . ' </text>';

//	//x axis grid for horizonatl bars 
  if ($this->_draw_major_grid_x) {
   $bar .=$this->_draw_vertical_grids_for_bar($unit_width, $hghest_sum_of_all_element);
  }
////horizonatl grids for bars
  if ($this->_draw_major_grid_y) {
   $bar .=$this->_draw_horizontal_grids_for_bar($no_of_elements);
  }
  $data_count = 0;
  $y_cordinate = 0;
  $y_cordinate += $bar_gap;
  foreach ($this->_data as $data) {
   $x_cordinate = $this->_left_margin + $this->_width_for_xaxis_chart_label;
   $data_count++;
   $data_class = 'data_class_' . $data_count;
   $value_a = $data['value'];
   $label = $data['label'];
//	 $no_of_cluster_elemnt = count($data['value']);
   $xaxis_label_count = 1;
   foreach ($value_a as $key => $value) {
    $cluster_class = 'cluster_class_' . $key;
    $bar_width = ($unit_width * $value);
    $xaxis_label = 0;
    $xaxis_data = $bar_width + strlen(strval($value)) * 7;
    $bar .= "<g transform=\"translate($x_cordinate,$y_cordinate)\">";
    $bar .= "<rect width=\"$bar_width\" height=\"$bar_height\" class=\"$data_class $label $cluster_class \">";
    $bar .= '<title>' . $value . '&nbsp; <br>(' . $label . ')</title>';
    $bar .= '</rect>';
    if ($xaxis_label_count == 1) {
     $bar .= '<text x="' . $xaxis_label . '" dx="-5" y="' . $yaxis_data . '"   class="chart_label_text" >';
     $bar .= '<title>' . $label . '</title>';
     $bar .= $label . '</text>';
    }
    if ($this->_show_elemnt_value) {
     $bar .= '<text x="' . $xaxis_data . '" y="' . $yaxis_data . '"   class="chart_value_text" >' . $value . '</text>';
    }
    $bar .= '</g>';
    $x_cordinate += $bar_width;
    $xaxis_label_count++;
   }
   $y_cordinate += $bar_gap + $bar_height;
  }

  $value_a = $this->_data[0]['value'];
  foreach ($value_a as $key => $value) {
   $cluster_class = 'cluster_class_' . $key;
   $legend_y_axis_rect = $legend_yaxis - 10;
   $bar .= "<rect x=\"$legend_xaxis\" y=\"$legend_y_axis_rect\" width=\"10\" height=\"10\" class=\" $key $cluster_class legend \"/>";
   $legend_xaxis += 15;
   $bar .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_legend_title" >' . $this->_legend[$key] . ' </text>';
   $legend_yaxis += 30;
   $legend_xaxis -= 15;
  }
  return $bar;
 }

 private function _draw_donut() {
  $x_cordinate = $this->_left_margin;
  $y_cordinate = $this->_top_margin;
  $chart = $this->_draw_pie();
  if ($this->_chart_width > $this->_chart_height) {
   $radius = ($this->_chart_height / 2);
  } else {
   $radius = ($this->_chart_width / 2);
  }
  $cx = $x_cordinate + $radius;
  $cy = $y_cordinate + $radius;
  $radius_n = $radius / 2;
  $chart .= '<circle cx="' . $cx . '" cy="' . $cy . '" r="' . $radius_n . '" class="donut_circle" '
   . 'style="stroke: #000000; fill: #fff " /></svg>';
  return $chart;
 }

 private function _prepare_pie() {
  /*
   * Left margina and right margin determines the total width available for chart graph & text.
   * Increase the left & right margin as per the text value in value and legend.
   * The bottom display the label. Reduce the height by the height of the text
   */
  $this->_top_margin = empty($this->_top_margin) ? '30' : $this->_top_margin;
  $legne_l = 0;
  if (!empty($this->_legend)) {
   foreach ($this->_legend as $l_k => $l_v) {
    $legne_l_n = strlen($l_v);
    $legne_l = $legne_l_n > $legne_l ? $legne_l_n : $legne_l;
   }
  }
  $legne_l_value = 20 * $legne_l;
  $this->_right_margin += $legne_l_value;
  $this->_chart_width = $this->_chart_width - $this->_left_margin - $this->_right_margin;
  $this->_chart_height = $this->_chart_height - $this->_top_margin - $this->_bottom_margin;
 }

 private function _draw_pie() {
  if ((empty($this->_data)) || (!is_array($this->_data))) {
   return;
  }
  $x_cordinate = $this->_left_margin;
  $y_cordinate = $this->_top_margin;
  $this->_prepare_pie();
  $title_yaxis = 10;

  if ($this->_chart_width > $this->_chart_height) {
   $radius = ($this->_chart_height / 2);
  } else {
   $radius = ($this->_chart_width / 2);
  }
  $title_xaxis = $this->_left_margin + $radius;
  $cx = $x_cordinate + $radius;
  $cy = $y_cordinate + $radius;
  $sum_of_elements = array_sum($this->_data);
  if ($sum_of_elements <= 0) {
   echo "<br> Wrong data selection. No value in value field";
   return;
  }

  $legend_yaxis = $this->_top_margin;
  $legend_xaxis = $cx + $radius * 1.2;

  $chart = "<div class='chart_name'>" . $this->_chart_name . '</div>';
  if ($this->_chart_type != 'donut') {
   $pie_chart_height = 2.5 * $radius;
   $chart .= "<svg  preserveAspectRatio='none' class='chart pie' width=\"$this->_chart_width_orginal\" height=\"{$pie_chart_height}\">";
  } else {
   $chart .= "<svg preserveAspectRatio='none' class='chart pie' width=\"$this->_chart_width_orginal\" height=\"$this->_chart_height_orginal\">";
  }
  $chart .= '<text x="' . $title_xaxis . '" y="' . $title_yaxis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . '   </text>';

  $last_x = $radius;
  $last_y = 0;
  $cum_val = $cum_segment = 0;
  $count = 0;
  $large_arc = 0;
  $chart .= "<g transform=\"translate(0,0)\">";

  foreach ($this->_data as $key => $value) {
   $cum_val += $value;
   $div_class = 'pie_element value cluster_class_' . $count;
   if ((($value / $sum_of_elements) * 360) > 180) {
    $large_arc = 1;
   } else {
    $large_arc = 0;
   }
   $element_title = $value . ' ( ' . round($value / $sum_of_elements * 100, 1) . '% | ' . $key . ')';
   $cum_segment += ($value / $sum_of_elements) * 360;
   $last_y_m = -($last_y);
   $next_x = $radius * cos(deg2rad($cum_segment));
   $next_y = $radius * sin(deg2rad($cum_segment));
   $end_point_x = ($next_x - $last_x);
   $end_point_y = -($next_y - $last_y);
   $chart .= "<path id=\"pie_path_$count\" d=\"M$cx,$cy
	            l$last_x, $last_y_m
              a$radius,$radius 0 $large_arc,0 $end_point_x,$end_point_y z \"
          style=\"stroke:#660000; \" class=\"$div_class\"      title=\"$element_title\"       />";
   $last_x = $next_x;
   $last_y = $next_y;
   $count++;
  }
  $chart .= '</g>';
  $key_count = 0;
  foreach ($this->_data as $key => $value) {
   $cluster_class = 'pie_element cluster_class_' . $key_count;
   $legend_y_axis_rect = $legend_yaxis - 10;
   $chart .= "<rect x=\"$legend_xaxis\" y=\"$legend_y_axis_rect\" width=\"10\" height=\"10\" class=\" $key $cluster_class legend \"/>";
   $legend_xaxis += 15;
   $chart .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_pie_value " >' . round($value / $sum_of_elements * 100, 1) . '% </text>';
   $legend_xaxis += 45;
   if (strlen($key) > 15) {
    $legend_yaxis_os = 0;
    $legend_xaxis_os = 0;
    $key_a = explode(' ', $key);
    foreach ($key_a as $nl_k => $new_line) {
     $chart .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_legend_title" >' . $new_line . ' </text>';
     $legend_yaxis += 20;
     $legend_xaxis -= 60;
    }
    $legend_xaxis += 60;
   } else {
    $chart .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_legend_title" >' . $key . ' </text>';
    $legend_yaxis += 40;
    $legend_xaxis -= 60;
   }
   $key_count++;
  }
  $chart .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_pie_value" >	(Total : ' . $sum_of_elements . ')  </text>';
  if ($this->_chart_type != 'donut') {
   $chart .= '</svg>';
  }
  return $chart;
 }

 private function _prepare_funnel() {
  /*
   * Left margina and right margin determines the total width available for chart graph & text.
   * Increase the left & right margin as per the text value in value and legend.
   * The bottom display the label. Reduce the height by the height of the text
   */
  $this->_top_margin = empty($this->_top_margin) ? '30' : $this->_top_margin;
  $legne_l = 0;
  if (!empty($this->_legend)) {
   foreach ($this->_legend as $l_k => $l_v) {
    $legne_l_n = strlen($l_v);
    $legne_l = $legne_l_n > $legne_l ? $legne_l_n : $legne_l;
   }
  }

  $legne_l_value = 20 * $legne_l;
  $this->_bottom_margin += $legne_l_value;
  $this->_bottom_margin = empty($this->_bottom_margin) || ($this->_bottom_margin < 80 ) ? '80' : $this->_bottom_margin;
  $this->_chart_width = $this->_chart_width - $this->_left_margin - $this->_right_margin;
  $this->_chart_height = $this->_chart_height - $this->_top_margin - $this->_bottom_margin;
 }

 private $_funnel_end_fraction = '0.8';
 private $_show_staight_end = true;

 private function _draw_funnel() {
  if ((empty($this->_data)) || (!is_array($this->_data))) {
   return;
  }
  $legend_xaxis = $x_cordinate = $this->_left_margin;
  $y_cordinate = $this->_top_margin;
  $this->_prepare_funnel();
  $title_yaxis = 10;

  $title_xaxis = $this->_left_margin;
  $sum_of_elements = array_sum($this->_data);
  $num_of_elements = count($this->_data);
  if ($sum_of_elements <= 0) {
   echo "<br> Wrong data selection. No value in value field";
   return;
  }

  $height_of_unit_element = $this->_chart_height / ($sum_of_elements + 1 );
  $legend_yaxis = $this->_chart_height_orginal - ($this->_bottom_margin / 2);

  $chart = "<div class='chart_name'>" . $this->_chart_name . '</div>';
  if ($this->_chart_type != 'donut') {
   $funnel_chart_height = $this->_chart_height_orginal;
   $chart .= "<svg preserveAspectRatio='none' class='chart funnel' width=\"$this->_chart_width_orginal\" height=\"{$funnel_chart_height}\">";
  } else {
   $chart .= "<svg preserveAspectRatio='none' class='chart funnel' width=\"$this->_chart_width_orginal\" height=\"$this->_chart_height_orginal\">";
  }
  $chart .= '<text x="' . $title_xaxis . '" y="' . $title_yaxis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . '   </text>';

  $cum_segment = $cum_val = $width_offset = $height_offset = 0;
  $count = $count_key = 1;
  $width_for_funnel = $this->_funnel_end_fraction * $this->_chart_width;
  $unit_width_for_funnel = $width_for_funnel / $sum_of_elements;

  $x1_cordinate = $x_cordinate;
  $y1_cordinate = $y_cordinate;
  $x2_cordinate = null;
  $cum_segment_divisor = 0.5 * $num_of_elements;
  foreach ($this->_data as $key => $value) {
   $height_of_this_element = !empty($value) ? $height_of_unit_element * $value : $height_of_unit_element * 5;
   $cum_val += $value;
   $div_class = 'funnel_element value cluster_class_' . $count;
   $x1 = $x1_cordinate;
   $y1 = $y1_cordinate;
   $x2 = empty($x2_cordinate) ? $this->_chart_width - $cum_segment : $x2_cordinate;
   $y2 = $y1;
   $cum_segment = (($value) * $unit_width_for_funnel) / $cum_segment_divisor;
   $element_title = $value . ' ( ' . round($value / $sum_of_elements * 100, 1) . '% | ' . $key . ')';

   if ($this->_show_staight_end) {
    $x3 = (($count == $num_of_elements) && ($value < 0.25 * $sum_of_elements)) ? $x2 : $x2 - $cum_segment;
   }
   $y3 = $y2 + $height_of_this_element;
   if ($this->_show_staight_end) {
    $x4 = (($count == $num_of_elements) && ($value < 0.25 * $sum_of_elements)) ? $x1 : $x1 + $cum_segment;
   }

   $y4 = $y3;



   $chart .= "<polygon  class='$div_class' stroke=\"black\" stroke-width=\"1\" id=\"funnel_path_$count\"  points=\"$x1 $y1 $x2 $y2 $x3 $y3 $x4 $y4\" transform=\"\" title=\"$element_title\"  ></polygon>";
   $chart .= "<polygon class='c_$div_class' stroke=\"black\" stroke-width=\"1\" id=\"funnel_path_$count\" style=\"fill: none;\" points=\"$x1 $y1 $x2 $y2 $x3 $y3 $x4 $y4\" transform=\"\" title=\"$element_title\"></polygon>";
   $x1_cordinate = $x4;
   $y1_cordinate = $y4;
   $x2_cordinate = $x3;

   $count++;
  }



  foreach ($this->_data as $key => $value) {
   $cluster_class = 'funnel_element cluster_class_' . $count_key;
   $legend_y_axis_rect = $legend_yaxis - 10;
   $chart .= "<rect x=\"$legend_xaxis\" y=\"$legend_y_axis_rect\" width=\"10\" height=\"10\" class=\" $key $cluster_class legend \"/>";
   $legend_xaxis += 15;
   $chart .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_funnel_value " >' . round($value / $sum_of_elements * 100, 1) . '% </text>';
   $legend_xaxis += 35;
   if (strlen($key) > 15) {
    $legend_yaxis_os = 0;
    $legend_xaxis_os = 0;
    $key_a = explode(' ', $key);
    foreach ($key_a as $nl_k => $new_line) {
     $chart .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_legend_title" >' . $new_line . ' </text>';
     $legend_xaxis -= 60;
    }
    $legend_xaxis += 60;
   } else {
    $chart .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_legend_title" >' . ucfirst($key) . ' </text>';
    $legend_xaxis -= 60;
   }
   $count_key++;
   $legend_xaxis += 130;
  }
  $chart .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_funnel_value" >	(Total : ' . $sum_of_elements . ')  </text>';
  if ($this->_chart_type != 'donut') {
   $chart .= '</svg>';
  }
  return $chart;
 }

}

//end of search class
$getsvgimage = new getsvgimage();
$gsi = & $getsvgimage;
?>