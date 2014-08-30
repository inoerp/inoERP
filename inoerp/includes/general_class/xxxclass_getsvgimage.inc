<?php

class getsvgimage extends dbObject {

 public $field_a = [
		 '_chart_name',
		 '_chart_width',
		 '_chart_height',
		 '_chart_type',
		 '_legend',
		 '_draw_major_grid_x',
		 '_draw_minor_grid_x',
		 '_draw_major_grid_y',
		 '_draw_minor_grid_y',
		 '_show_elemnt_value',
		 '_left_margin',
		 '_right_margin',
		 '_top_margin',
		 '_gap_between_xaxis_text',
		 '_height_of_text',
		 '_width_of_legend',
		 '_height_of_legend',
		 '_x_axis_text',
		 '_y_axis_text'
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
 private $_legend;
 private $_draw_major_grid_x = true;
 private $_draw_minor_grid_x = true;
 private $_draw_major_grid_y = true;
 private $_draw_minor_grid_y = true;
 private $_show_elemnt_value;
 private $_left_margin = 30;
 private $_right_margin = 0;
 private $_top_margin = 30;
 private $_gap_between_xaxis_text = 20;
 private $_height_of_text = 20;
 private $_width_of_legend = 80;
 private $_height_of_legend = 25;
 private $_x_axis_text = 'X axis Info';
 private $_y_axis_text;
 private $_settings;

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

 private function _dataRange_inDataSet() {
	$min = $max = 0;
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
	}
	$this->_max_val = $max;
	$this->_min_val = $min;
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
	$ret_a['noof_major_axis'] = ceil($highest_number / $unit_width);
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
	 for ($i = 0; $i <= $no_of_grids; $i++) {
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

 public function draw_chart() {
	if (empty($this->_x_axis_text)) {
	 $this->_height_of_text = 0;
	 $this->_gap_between_xaxis_text = 5;
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
			pa($this);
		$final_chart = $this->_draw_pie();
		break;

	 case 'donut' :
		$final_chart = $this->_draw_donut();
		break;

	 case 'line' :
		$this->_dataRange_inDataSet();
		$final_chart = $this->_draw_line();
		break;
	}

	return $final_chart;
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

 private function _draw_line() {
	if ((empty($this->_data)) || (!is_array($this->_data))) {
	 return;
	}
	$x_cordinate = $this->_left_margin;
	$y_cordinate = $this->_top_margin;
	$max_no_of_data = $this->_maximum_number_of_element();

	$chart_width_orginal = $this->_chart_width;
	$chart_height_orginal = $this->_chart_height;
	$this->_chart_width = $this->_chart_width - $this->_left_margin - $this->_right_margin;
	$this->_chart_height = $this->_chart_height - $this->_height_of_text - $this->_gap_between_xaxis_text - $this->_height_of_legend;
	$unit_height = ($this->_chart_height) / $this->_max_val;
	$point_gap = ($this->_chart_width / ($max_no_of_data + 1));
	//$yaxis_data = ($yaix_height / 1.5);

	$title_xaxis = $this->_chart_width / 2;
	$title_yaxis = $this->_chart_height + $this->_gap_between_xaxis_text;
	$legend_yaxis = $chart_height_orginal - $this->_height_of_legend;

	$chart = "<div class='chart_name'>" . $this->_chart_name . '</div>';
	$chart .= "<svg class='chart' width=\"$chart_width_orginal\" height=\"$chart_height_orginal\">";
	$chart .= ' <line x1="' . $this->_left_margin . '"  y1="0" x2="' . $this->_left_margin . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
	$chart .= ' <line x1="' . $this->_left_margin . '"  y1="' . $this->_chart_height . '" x2="' . $chart_width_orginal . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
	$chart .= '<text x="' . $title_xaxis . '" y="' . $title_yaxis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . ' </text>';
	if ($this->_draw_major_grid_x) {
	 $chart .=$this->_draw_major_grids($this->_max_val, 'yaxis', $this->_chart_width, $unit_height, $this->_left_margin, $this->_chart_height);
	}
	if ($this->_draw_major_grid_y) {
	 $chart .=$this->_draw_major_grids_data($max_no_of_data, 'yaxis', $point_gap, $this->_chart_width, $this->_left_margin, $this->_chart_height);
	}
	$line_count = 0;
	foreach ($this->_data as $data) {
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
		$chart .= "<rect x=\"$xaxis\" y=\"$yaxis\" width=\"5\" height=\"5\" class=\" $key $line_class line_chart  \"/>";
		if ($data_count > 0) {
		 $chart .= "<line x1=\"$x1\" y1=\"$y1\" x2=\"$x2\" y2=\"$y2\"  class=\"$line_class line_chart line\"  />";
		}
		$x1 = $x2;
		$y1 = $y2;
		if ($this->_show_elemnt_value) {
		 $chart .= '<text x="' . $xaxis . '" y="' . $yaxis . '"  dy="-4" class="chart_value_text" >' . $value . '</text>';
		}
		$data_count++;
	 }
	 $line_count++;
	}

	$legend_x = $this->_left_margin;
	$line_count2 = 0;
	foreach ($this->_data as $line_data) {
	 $line_class = 'line_class_' . $line_count2;
	 $legend_y_axis_rect = $legend_yaxis - 10;
	 $chart .= "<rect x=\"$legend_x\" y=\"$legend_y_axis_rect\" width=\"10\" height=\"10\" class=\"$line_class line_chart legend \"/>";
	 $legend_x += 15;
	 $chart .= '<text x="' . $legend_x . '" y="' . $legend_yaxis . '"  class="chart_legend_title" >' . $line_data['label'] . ' </text>';
	 $legend_x += 150;
	 $line_count2++;
	}

	return $chart;
 }

 private function _prepare_column() {
	$this->_gap_between_xaxis_text = $this->_gap_between_xaxis_text < 60 ? 60 : $this->_gap_between_xaxis_text;
	if ((empty($this->_data)) || (!is_array($this->_data))) {
	 return;
	}
	$multiplying_factror = 0.1;
	while ($this->_right_margin < 80) {
	 $this->_right_margin = $multiplying_factror * $this->_chart_width;
	 $multiplying_factror += 0.02;
	}
	$this->_chart_width = $this->_chart_width - $this->_left_margin - $this->_right_margin;
	$this->_chart_height = $this->_chart_height - $this->_height_of_text -
					$this->_gap_between_xaxis_text - $this->_height_of_legend;
 }

 //hegith is x axis & width is y axis
 private function _draw_vertical_column() {
	if ((empty($this->_data)) || (!is_array($this->_data))) {
	 return;
	}
	$this->_prepare_column();
	$no_of_elements = count($this->_data);
	$data_range = $this->_max_val - $this->_min_val;
	$unit_height = ($this->_chart_height) / $data_range;
	$total_no_of_elemsts_with_gap = 2 * $no_of_elements;
	$bar_width = $bar_gap = ($this->_chart_width / ($total_no_of_elemsts_with_gap));
	$title_xaxis = $this->_chart_width / 2;
	$title_yaxis = $this->_chart_height + $this->_gap_between_xaxis_text;

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
	foreach ($this->_data as $data) {
	 $no_of_elements++;
	 $data_class = 'data_class_' . $data_count;
	 $value = $data['value'];
	 $label = $data['label'];
	 $bar_height = $unit_height * $value;
//	 $xaxis_data = $bar_width + strlen(strval($value)) * 7;
	 $y_cordinate = $this->_chart_height - $bar_height;
	 $bar .= "<g transform=\"translate($x_cordinate,$y_cordinate)\">";
	 $bar .= "<rect width=\"$bar_width\" height=\"$bar_height\" class=\"$data_class $label\"></rect>";
	 $bar .= '<text x="' . $bar_width . '"  y="' . $bar_height . '"   dy="10" class="chart_label_text" >' . $label . '</text>';
	 $bar .= '<text x="' . $bar_width . '" y="0"  dy="-4" class="chart_value_text" >' . $value . '</text>';
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
	$data_range = $this->_max_val - $this->_min_val;
	$unit_height = ($this->_chart_height) / $data_range;
	$legend_yaxis = $this->_top_margin;
	$legend_xaxis = $this->_chart_width_orginal - $this->_right_margin;
	$title_xaxis = $this->_chart_width / 2;
	$title_yaxis = $this->_chart_height + $this->_gap_between_xaxis_text;
	$bar = "<div class='chart_name'>" . $this->_chart_name . '</div>';
	$bar .= "<svg class='chart clustered_column " . $this->_chart_name . "' "
					. "width=\"$this->_chart_width_orginal\" height='$this->_chart_height_orginal'>";
	$bar .= ' <line x1="' . $this->_left_margin . '"  y1="0" x2="' . $this->_left_margin . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
	$bar .= ' <line x1="' . $this->_left_margin . '"  y1="' . $this->_chart_height . '" x2="' . $this->_chart_width_orginal . '"   y2="' . $this->_chart_height . '" style="stroke:#006600;"/>';
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
		$bar .= "<rect width=\"$bar_width\" height=\"$bar_height\" class=\"$data_class $label $cluster_class\"></rect>";
		if ($xaxis_label_count == 1) {
		 $bar .= '<text x="0"  dx="' . $bar_width . '" y="' . $bar_height . '" dy="12" '
						 . "transform=\"rotate(45 $bar_width,$bar_height)\"" . 'class="chart_label_text x_axis" >' . $label . '</text>';
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
	$no_of_elements = count($this->_data);
	$legend_yaxis = $this->_top_margin;
	$legend_xaxis = $this->_chart_width_orginal - $this->_right_margin;
	$title_xaxis = $this->_chart_width / 2;

	$title_yaxis = $this->_chart_height + $this->_gap_between_xaxis_text;
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
	$unit_height = ($this->_chart_height ) / $hghest_sum_of_all_element;

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
		$bar .= "<rect width=\"$bar_width\" height=\"$bar_height\" class=\"$data_class $label $cluster_class\"></rect>";
		$bar .= '</g>';
		if ($xaxis_label_count == 1) {
		 $bar .= '<text x="' . $x_cordinate . '" dx="' . $label_xaxis_dx . '"  y="' . $this->_chart_height . '"  dy="10" class="chart_label_text" >' . $label . '</text>';
		}
		if ($this->_show_elemnt_value) {
		 $bar .= '<text x="' . $bar_width . '" y="0"  dy="-4" class="chart_value_text" >' . $value . '</text>';
		}

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
	$left_margin = 80;
	$right_margin = 0;
	$x_cordinate = $left_margin;
	$y_cordinate = 0;
	$data_count = 0;
	$gap_between_xaxis_text = 20;
	$height_of_text = 20;
	$no_of_data = count($this->_data);

	$chart_width_orginal = $this->_chart_width;
	$xaxis_cooridnate_ep = $this->_chart_width;
	$this->_chart_width = $this->_chart_width - $left_margin - $right_margin;
	$no_of_elements = count($this->_data);

	$data_range = $this->_max_val - $this->_min_val;
	$unit_width = ($this->_chart_width * 0.9) / $data_range;
	$yaix_height = $this->_chart_height - $height_of_text - $gap_between_xaxis_text;

	$total_no_of_elemsts_with_gap = 2 * $no_of_elements;
	$bar_height = $bar_gap = ($yaix_height / ($total_no_of_elemsts_with_gap));
	$yaxis_data = ($bar_height / 1.5);

	$xaxis_title = $this->_chart_width / 2;
	$text_y_axis = $this->_chart_height - $height_of_text + $gap_between_xaxis_text;

	$bar = "<div class='chart_name'>" . $this->_chart_name . '</div>';
	$bar .= "<svg class='chart' width=\"$chart_width_orginal\" height='$this->_chart_height'>";
	$bar .= ' <line x1="' . $left_margin . '"  y1="0" x2="' . $left_margin . '"   y2="' . $yaix_height . '" style="stroke:#006600;"/>';
	$bar .= ' <line x1="' . $left_margin . '"  y1="' . $yaix_height . '" x2="' . $xaxis_cooridnate_ep . '"   y2="' . $yaix_height . '" style="stroke:#006600;"/>';
	$bar .= '<text x="' . $xaxis_title . '" y="' . $text_y_axis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . ' </text>';
	if ($this->_draw_major_grid_x) {
	 $bar .=$this->_draw_major_grids($this->_max_val, 'yaxis', $yaix_height, $unit_width, $left_margin, 0);
	}
	if ($this->_draw_major_grid_y) {
	 $bar .=$this->_draw_major_grids_data($no_of_data, 'yaxis', $chart_width_orginal, $yaix_height, $left_margin, 0);
	}
	$y_cordinate += ($bar_gap / 2);
	foreach ($this->_data as $data) {
	 $data_count++;
	 $data_class = 'data_class_' . $data_count;
	 $value = $data['value'];
	 $label = $data['label'];
	 $bar_width = $unit_width * $value;
	 $xaxis_label = 0;
	 $xaxis_data = $bar_width + strlen(strval($value)) * 7;
	 $bar .= "<g transform=\"translate($x_cordinate,$y_cordinate)\">";
	 $bar .= "<rect width=\"$bar_width\" height=\"$bar_height\" class=\"$data_class $label\"></rect>";
	 $bar .= '<text x="' . $xaxis_label . '" dx="-5" y="' . $yaxis_data . '"   class="chart_label_text" >' . $label . '</text>';
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
	$left_margin = 80;
	$right_margin = 40;
	$x_cordinate = $left_margin;
	$y_cordinate = 0;
	$data_count = 0;
	$gap_between_xaxis_text = 20;
	$height_of_text = 20;
	$height_of_legend = 40;
	$no_of_data = count($this->_data);

	$chart_width_orginal = $this->_chart_width;
	$xaxis_cooridnate_ep = $this->_chart_width;
	$this->_chart_width = $this->_chart_width - $left_margin - $right_margin;
	$no_of_elements = count($this->_data);

	$data_range = $this->_max_val - $this->_min_val;
	$unit_width = ($this->_chart_width ) / $data_range;
	$yaix_height = $this->_chart_height - $height_of_text - $gap_between_xaxis_text - $height_of_legend;

	$total_no_of_elemsts_with_gap = ($no_of_elements * count($this->_data[0]['value'])) + (2 * $no_of_elements );
	$bar_height = ($yaix_height / ($total_no_of_elemsts_with_gap));
	$bar_gap = 2 * $bar_height;
	$yaxis_data = ($bar_height / 1.5);

	$xaxis_title = $this->_chart_width / 2;
	$text_y_axis = $this->_chart_height - $height_of_text + $gap_between_xaxis_text - $height_of_legend;
	$legend_y_axis = $this->_chart_height - $height_of_text + $gap_between_xaxis_text;

	$bar = "<div class='chart_name'>" . $this->_chart_name . '</div>';
	$bar .= "<svg class='chart' width=\"$chart_width_orginal\" height='$this->_chart_height'>";
	$bar .= ' <line x1="' . $left_margin . '"  y1="0" x2="' . $left_margin . '"   y2="' . $yaix_height . '" style="stroke:#006600;"/>';
	$bar .= ' <line x1="' . $left_margin . '"  y1="' . $yaix_height . '" x2="' . $xaxis_cooridnate_ep . '"   y2="' . $yaix_height . '" style="stroke:#006600;"/>';
	$bar .= '<text x="' . $xaxis_title . '" y="' . $text_y_axis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . '  </text>';
	if ($this->_draw_major_grid_x) {
	 $bar .=$this->_draw_major_grids($this->_max_val, 'xaxis', $yaix_height, $unit_width, $left_margin, 0);
	}
	if ($this->_draw_major_grid_y) {
	 $bar .=$this->_draw_major_grids_data($no_of_data, 'xaxis', $chart_width_orginal, $yaix_height, $left_margin, 0);
	}
	$y_cordinate += $bar_gap;
	foreach ($this->_data as $data) {
	 $data_count++;
	 $data_class = 'data_class_' . $data_count;
	 $value_a = $data['value'];
	 $label = $data['label'];
	 $no_of_cluster_elemnt = count($data['value']);
	 $xaxis_label_count = 1;
	 foreach ($value_a as $key => $value) {
		$cluster_class = 'cluster_class_' . $key;
		$bar_width = ($unit_width * $value);
		$xaxis_label = 0;
		$xaxis_data = $bar_width + strlen(strval($value)) * 7;
		$bar .= "<g transform=\"translate($x_cordinate,$y_cordinate)\">";
		$bar .= "<rect width=\"$bar_width\" height=\"$bar_height\" class=\"$data_class $label $cluster_class \"></rect>";
		if ($xaxis_label_count == 1) {
		 $bar .= '<text x="' . $xaxis_label . '" dx="-5" y="' . $yaxis_data . '"   class="chart_label_text" >' . $label . '</text>';
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
	$legend_x = $left_margin;
	foreach ($value_a as $key => $value) {
	 $cluster_class = 'cluster_class_' . $key;
	 $legend_y_axis_rect = $legend_y_axis - 10;
	 $bar .= "<rect x=\"$legend_x\" y=\"$legend_y_axis_rect\" width=\"10\" height=\"10\" class=\"$data_class $label $cluster_class legend \"/>";
	 $legend_x += 15;
	 $bar .= '<text x="' . $legend_x . '" y="' . $legend_y_axis . '"  class="chart_legend_title" >' . $this->_legend[$key] . ' </text>';
	 $legend_x += ((6 * strlen($this->_legend[$key])) + 10);
	}
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
	$left_margin = 80;
	$right_margin = 40;
	$x_cordinate = $left_margin;
	$y_cordinate = 0;
	$data_count = 0;
	$gap_between_xaxis_text = 20;
	$height_of_text = 20;
	$height_of_legend = 40;
	$no_of_data = count($this->_data);

	$chart_width_orginal = $this->_chart_width;
	$xaxis_cooridnate_ep = $this->_chart_width;
	$this->_chart_width = $this->_chart_width - $left_margin - $right_margin;
	$no_of_elements = count($this->_data);

	$hghest_sum_of_all_element = $this->_highest_sum_of_all_elements();
	$unit_width = ($this->_chart_width ) / $hghest_sum_of_all_element;
	$yaix_height = $this->_chart_height - $height_of_text - $gap_between_xaxis_text - $height_of_legend;

	$total_no_of_elemsts_with_gap = 2 * $no_of_elements;
	$bar_height = $bar_gap = ($yaix_height / ($total_no_of_elemsts_with_gap));
	$yaxis_data = ($bar_height / 1.5);

	$xaxis_title = $this->_chart_width / 2;
	$text_y_axis = $this->_chart_height - $height_of_text + $gap_between_xaxis_text - $height_of_legend;
	$legend_y_axis = $this->_chart_height - $height_of_text + $gap_between_xaxis_text;

	$bar = "<div class='chart_name'>" . $this->_chart_name . '</div>';
	$bar .= "<svg class='chart' width=\"$chart_width_orginal\" height='$this->_chart_height'>";
	$bar .= ' <line x1="' . $left_margin . '"  y1="0" x2="' . $left_margin . '"   y2="' . $yaix_height . '" style="stroke:#006600;"/>';
	$bar .= ' <line x1="' . $left_margin . '"  y1="' . $yaix_height . '" x2="' . $xaxis_cooridnate_ep . '"   y2="' . $yaix_height . '" style="stroke:#006600;"/>';
	$bar .= '<text x="' . $xaxis_title . '" y="' . $text_y_axis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . '  </text>';
	if ($this->_draw_major_grid_x) {
	 $bar .=$this->_draw_major_grids($hghest_sum_of_all_element, 'xaxis', $yaix_height, $unit_width, $left_margin, 0);
	}
	if ($this->_draw_major_grid_y) {
	 $bar .=$this->_draw_major_grids_data($no_of_data, 'xaxis', $chart_width_orginal, $yaix_height, $left_margin, 0);
	}
	$y_cordinate += $bar_gap;
	foreach ($this->_data as $data) {
	 $x_cordinate = $left_margin;
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
		$bar .= "<rect width=\"$bar_width\" height=\"$bar_height\" class=\"$data_class $label $cluster_class \"></rect>";
		if ($xaxis_label_count == 1) {
		 $bar .= '<text x="' . $xaxis_label . '" dx="-5" y="' . $yaxis_data . '"   class="chart_label_text" >' . $label . '</text>';
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
	$legend_x = $left_margin;
	foreach ($value_a as $key => $value) {
	 $cluster_class = 'cluster_class_' . $key;
	 $legend_y_axis_rect = $legend_y_axis - 10;
	 $bar .= "<rect x=\"$legend_x\" y=\"$legend_y_axis_rect\" width=\"10\" height=\"10\" class=\"$data_class $label $cluster_class legend \"/>";
	 $legend_x += 15;
	 $bar .= '<text x="' . $legend_x . '" y="' . $legend_y_axis . '"  class="chart_legend_title" >' . $this->_legend[$key] . ' </text>';
	 $legend_x += ((6 * strlen($this->_legend[$key])) + 10);
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

 private function _draw_pie() {
	if ((empty($this->_data)) || (!is_array($this->_data))) {
	 return;
	}
//	$left_margin = 30;
//	$right_margin = 0;
//	$top_margin = 30;
//	$gap_between_xaxis_text = 20;
//	$height_of_text = 20;
//	$width_of_legend = 80;
	$x_cordinate = $this->_left_margin;
	$y_cordinate = $this->_top_margin;
	$chart_width_orginal = $this->_chart_width;
	$chart_height_orginal = $this->_chart_height;

	$this->_chart_width = $this->_chart_width - $this->_left_margin - $this->_right_margin - $this->_width_of_legend;
	$this->_chart_height = $this->_chart_height - $this->_top_margin - $this->_height_of_text - $this->_gap_between_xaxis_text;
	$title_yaxis = $chart_height_orginal - $this->_height_of_text;

	if ($this->_chart_width > $this->_chart_height) {
	 $radius = ($this->_chart_height / 2);
	} else {
	 $radius = ($this->_chart_width / 2);
	}
	$title_xaxis = $this->_left_margin + $radius;
	$cx = $x_cordinate + $radius;
	$cy = $y_cordinate + $radius;
	$sum_of_elements = array_sum($this->_data);

	$legend_yaxis = $this->_top_margin;
	$legend_xaxis = $cx + $radius * 1.2;

	$chart = "<div class='chart_name'>" . $this->_chart_name . '</div>';
	$chart .= "<svg class='chart pie' width=\"$chart_width_orginal\" height=\"$chart_height_orginal\">";
	$chart .= '<text x="' . $title_xaxis . '" y="' . $title_yaxis . '"     class="chart_xaxis_title" >' . $this->_x_axis_text . '   </text>';

	$last_x = $radius;
	$last_y = 0;
	$cum_val = $cum_segment = 0;
	$count = 0;
	$large_arc = 0;
	$chart .= "<g transform=\"translate(0,0)\">";

	foreach ($this->_data as $key => $value) {
	 $cum_val += $value;
	 $div_class = 'cluster_class_' . $count;
	 if ((($value / $sum_of_elements) * 360) > 180) {
		$large_arc = 1;
	 } else {
		$large_arc = 0;
	 }
	 $cum_segment += ($value / $sum_of_elements) * 360;
	 $last_y_m = -($last_y);
	 $next_x = $radius * cos(deg2rad($cum_segment));
	 $next_y = $radius * sin(deg2rad($cum_segment));
	 $end_point_x = ($next_x - $last_x);
	 $end_point_y = -($next_y - $last_y);
	 $chart .= "<path id=\"pie_path_$count\" d=\"M$cx,$cy
	            l$last_x, $last_y_m
              a$radius,$radius 0 $large_arc,0 $end_point_x,$end_point_y z \"
          style=\"stroke:#660000; \" class=\"$div_class\"/>";
	 $last_x = $next_x;
	 $last_y = $next_y;
	 $count++;
	}
	$chart .= '</g>';
	$key_count = 0;
	foreach ($this->_data as $key => $value) {
	 $cluster_class = 'cluster_class_' . $key_count;
	 $legend_y_axis_rect = $legend_yaxis - 10;
	 $chart .= "<rect x=\"$legend_xaxis\" y=\"$legend_y_axis_rect\" width=\"10\" height=\"10\" class=\" $key $cluster_class legend \"/>";
	 $legend_xaxis += 15;
	 $chart .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_pie_value" >' . round($value / $sum_of_elements * 100, 1) . '% </text>';
	 $legend_xaxis += 45;
	 $chart .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_legend_title" >' . $key . ' </text>';
	 $legend_yaxis += 40;
	 $legend_xaxis -= 60;
	 $key_count++;
	}
	$chart .= '<text x="' . $legend_xaxis . '" y="' . $legend_yaxis . '"  class="chart_pie_value" >	(Total : ' . $sum_of_elements . ')  </text>';
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