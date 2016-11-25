<?php

class search extends dbObject {

 //to find
 private $_query_string;
 private $_hidden_fields;
 private $_searching_table_name;
 private $_search_mode = 2;
 private $_show_block = 1;
//private attrbiutes - to show result
 Private $_update_path;
 Private $_show_update_path;
 Private $_show_multifield_path;
 Private $_update_action_meassge = 'Update';
 Private $_view_path;
 Private $_show_view_path;
 Private $_view_action_meassge = 'View';
 private $_extra_path = [];
 //to show form
 public $_search_functions;
 private $_form_post_link = 'search';
 private $_form_name = 'generic_search_form';
 private $_search_order_by;
 private $_search_asc_desc;
 private $_group_by;
 private $_per_page = 10;
 private $_page_no;
 private $_searching_class;
 private $_initial_search_array;
 //to show result
 public $primary_column_s;
 public $column_array_s = [];
 public $result = [];
 //to show form
 public $option_lists;
 public $access_level = null;
 private $_per_page_a = [
		 '5' => '5',
		 '10' => '10',
		 '20' => '20',
		 '50' => '50',
		 '100' => '100',
		 '1000' => '1000',
		 '10000' => '10,000',
		 'all' => 'All',
 ];
 private $_window_type = '';

 public function setProperty($property, $value) {
	if (property_exists($this, $property)) {
	 switch ($property) {
		case '_show_view_path':
		 $this->$property = !empty($value) ? true : false;
		 break;

		case '_show_update_path':
		  if (!empty($value) && !empty($this->access_level) && $this->access_level > 3) {
			$this->$property = !empty($value) ? true : false;
		 }
		 break;

		case '_result':
		case '_group_by':
		case '_column_array':
		case '_extra_path':
		 $this->$property = is_array($value) ? $value : false;
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

 private function _readPath_forComments($comment_id) {
	$cc = new extn_comment();
//	$cc->findBy_id($record->{$this->primary_column_s});
	$cc->findBy_id($comment_id);
	$class_of_comment = $cc->reference_table;
	if (property_exists($class_of_comment, 'primary_column')) {
	 $primary_col = $class_of_extn_comment::$primary_column;
	} else {
	 return;
	}
	if ($class_of_comment == 'content') {
	 $search_result = "&nbsp;&nbsp;<a href=\"content.php?class_name=$cc->reference_table&mode=2&$primary_col=" . $cc->reference_id;
	 $content_type_id_i = content::find_by_id($cc->reference_id);
	 $content_type_id = !empty($content_type_id_i) ? $content_type_id_i->content_type_id : null;
	 $content_type_i = !empty($content_type_id) ? content_type::find_by_id($content_type_id) : null;
	 $content_type = !empty($content_type_i) ? $content_type_i->content_type : null;
	 $search_result .= "&content_type=$content_type";
	} else {
	 $search_result = "&nbsp;&nbsp;<a href=\"form.php?class_name=$cc->reference_table&mode=2&$primary_col=" . $cc->reference_id;
	}
	$search_result .= '">' . gettext($this->_view_action_meassge) . '</a>';
	return $search_result;
 }

 public function search_result_op() {
	$drop_down_icon = ino_search_dropDownSettings();
	if (!empty($_GET['window_type'])) {
	 $window_type = '&window_type=' . $_GET['window_type'][0];
	} else {
	 $window_type = '';
	}
//  echo $window_type;

	if (!empty($this->_show_update_path) || !empty($this->_show_view_path) || !empty($this->_extra_path)) {
	 $show_action_msg = true;
	} else {
	 $show_action_msg = false;
	}
	if (empty($this->_view_path)) {
	 $this->_view_path = 'form.php?class_name=' . $this->_searching_class;
	}
	if (empty($this->_update_path)) {
	 $this->_update_path = 'form.php?class_name=' . $this->_searching_class;
	}
	$no_of_columns_per_tab = 9;
	$total_columns = count($this->column_array_s) + 1; //1 for action
	$no_of_tabs = ceil($total_columns / $no_of_columns_per_tab);
	$search_result = '';
	$search_result .= '<div id="tabsLine">
				 <ul class="tabMain">';
	for ($i = 0; $i < $no_of_tabs; $i++) {
	 $search_result .= "<li><a href=\"#tabsLine-$i\">Tab No $i </a></li>";
	}
	$search_result .= ' </ul>
				 <div class="tabContainer"> ';

	for ($i = 0; $i < $no_of_tabs; $i++) {
	 $search_result .= "<div id=\"tabsLine-$i\" class='tabContent'>";
	 $search_result .= "<table class=\"normal\"><thead ><tr class='ino-sort'>";
	 $search_result .= '<th>' . gettext(ucwords(str_replace('_', ' ', $this->primary_column_s))) . '</th>';
	 if ($i == 0 && $show_action_msg) {
		$search_result .= "<th>" . gettext('Action') . "<span id='copy_clipboard' title='" . gettext('Copy To Clipboard') . "'>&nbsp;&nbsp;&nbsp;<i class='fa fa-clipboard clickable'></i></span></th>";
	 }
	 $new_start = ($i * ($no_of_columns_per_tab - 1)) + $i;
	 $new_end = $new_start + ($no_of_columns_per_tab - 1);
	 for ($j = $new_start; $j <= $new_end; $j++) {
		if ($j > $total_columns - 2) {
		 break;
		}
		$search_result .= '<th class="ino-sort-element" data-field_name="' . $this->column_array_s[$j] . '">' . $drop_down_icon . gettext(ucwords(str_replace('_', ' ', $this->column_array_s[$j]))) . '</th>';
	 }
	 $search_result .='</tr></thead>';
	 If (!empty($this->result)) {
		$search_result .= '<tbody class="form_data_line_tbody search_results" >';
		$count = 0;
		foreach ($this->result as $record) {
		 $count++;
		 $tr_class = 'rowno_' . $count;
		 $search_result .="<tr class='{$tr_class}'>";
		 $primary_col_val = (!empty($record->{$this->primary_column_s})) ? $record->{$this->primary_column_s} : $count;
		 $search_result .= '<td>' . $primary_col_val . '</td>';
		 if ($i == 0 && $show_action_msg) {
			$search_result .= '<td class="search_result action">';
			if ($this->_show_view_path) {
			 if ($this->_searching_class == 'comment') {
				$search_result .= $this->_readPath_forComments($record->{$this->primary_column_s});
			 } else if ($this->_searching_class == 'content') {
				$search_result .= "&nbsp;&nbsp;<a class=\"view ino-btn2\" href=\"content.php?" . $window_type . "mode=2&content_type_id=" . $record->content_type_id . "&$this->primary_column_s=" . $record->{$this->primary_column_s} . '">' . gettext($this->_view_action_meassge) . '</a> ';
			 } else {
				$search_result .= "&nbsp;&nbsp;<a class=\"view ino-btn2\" href=\"$this->_view_path&mode=2&$this->primary_column_s=" . $record->{$this->primary_column_s} . '">' . gettext($this->_view_action_meassge) . '</a>';
			 }
			}
			if (!empty($this->_extra_path)) {
			 foreach ($this->_extra_path as $pathname => $pathmsg) {
				$search_result .= "&nbsp;&nbsp;<a class=\"extra_path ino-btn2\" "
								. "href=\"$pathname&$this->primary_column_s=" . $record->{$this->primary_column_s} . '">' . $pathmsg . '</a>';
			 }
			}
			if (!empty($this->_show_multifield_path)) {
			 $multifield_path_stmt = "&nbsp;&nbsp;<a class=\"multifield_path ino-btn2\" "
							 . "href=\"$this->_update_path";
			 foreach ($this->_show_multifield_path as $multifield_path_k => $multifield_path_v) {
				$multifield_path_stmt .= "&$multifield_path_v=" . $record->$multifield_path_v;
			 }
			 $multifield_path_stmt .= '&mode=9"> Result Data </a>';
			 $search_result .= $multifield_path_stmt;
			}
			if ($this->_show_update_path) {
			 if ($this->_searching_class == 'content') {
				$search_result .= "&nbsp;&nbsp;<a class=\"update ino-btn2\" "
								. "href=\"content.php?mode=9" . $window_type . "&content_type_id=" . $record->content_type_id . "&$this->primary_column_s=" . $record->{$this->primary_column_s} . '">' . gettext($this->_update_action_meassge) . '</a> ';
			 } else {
				$search_result .= "&nbsp;&nbsp;<a class=\"update ino-btn2\" "
								. "href=\"$this->_update_path&mode=9&$this->primary_column_s=" . $record->{$this->primary_column_s} . '">' . gettext($this->_update_action_meassge) . '</a> ';
			 }
			}
			$search_result .= '</td>';
		 }
		 $new_start = ($i * ($no_of_columns_per_tab - 1)) + $i;
		 $new_end = $new_start + ($no_of_columns_per_tab - 1);
		 for ($k = $new_start; $k <= $new_end; $k++) {
			if ($k > $total_columns - 2) {
			 break;
			}
			$col_val = $this->column_array_s[$k];
			if (isset($record->$col_val)) {
			 $search_result .= '<td>' . ucwords(str_replace('_', ' ', $record->$col_val)) . '</td>';
			} else {
			 $search_result .= '<td> </td>';
			}
		 }
		 $search_result .= '</tr>';
		}
		$search_result .= '</tbody>';
	 } else {
		$search_result .= gettext('No Records Found!');
	 }
	 $search_result .= '</table> </div>';
	}
	$search_result .= '</div> </div>';
	return $search_result;
 }

 public function select_result_op() {
	$drop_down_icon = ino_search_dropDownSettings();
	if (property_exists($this->_searching_class, 'primary_column')) {
	 $class_name = $this->_searching_class;
	 $primary_column = $class_name::$primary_column;
	} else {
	 return;
	}
	if (isset($_GET['window_type']) && $_GET['window_type'] = 'popover') {
	 $quick_select_class = 'popover_quick_select';
	} else {
	 $quick_select_class = 'quick_select';
	}

	$no_of_columns_per_tab = 9;
	$total_columns = count($this->column_array_s) + 1; //1 for action
	$no_of_tabs = ceil($total_columns / $no_of_columns_per_tab);
	$search_result = '';
	$search_result .= '<div id="tabsLine">
				 <ul class="tabMain">';
	for ($i = 0; $i < $no_of_tabs; $i++) {
	 $search_result .= "<li><a href=\"#tabsLine-$i\">Tab No $i </a></li>";
	}
	$search_result .= ' </ul>
				 <div class="tabContainer"> ';

	for ($i = 0; $i < $no_of_tabs; $i++) {
	 $search_result .= "<div id=\"tabsLine-$i\" class='tabContent'>";
	 $search_result .= "<table class=\"normal\"><thead><tr>";
	 $search_result .= '<th>' . gettext(ucwords(str_replace('_', ' ', $primary_column))) . '</th>';
	 if ($i == 0) {
		$search_result .= "<th>" . gettext('Click Select') . "</th>";
	 }
	 $new_start = ($i * ($no_of_columns_per_tab - 1)) + $i;
	 $new_end = $new_start + ($no_of_columns_per_tab - 1);
	 for ($j = $new_start; $j <= $new_end; $j++) {
		if ($j > $total_columns - 2) {
		 break;
		}
		$search_result .= '<th data-field_name="' . $this->column_array_s[$j] . '">' . $drop_down_icon . gettext(ucwords(str_replace('_', ' ', $this->column_array_s[$j]))) . '</th>';
	 }
	 $search_result .='</tr></thead>';
	 If (!empty($this->result)) {
		$search_result .= '<tbody class="form_data_line_tbody search_results" >';
		$count = 0;
		foreach ($this->result as $record) {
		 $count++;
		 $tr_class = 'rowno_' . $count;
		 $search_result .="<tr class='{$tr_class}'>";
		 $search_result .= '<td>' . $record->$primary_column . '</td>';
		 if ($i == 0) {
			$search_result .= '<td><a href="#" role="button" data-select_field="' . $primary_column . '"  data-select_field_value="' . $record->$primary_column . '"'
							. ' class=" btn btn-default ' . $primary_column . ' ' . $quick_select_class . '">' . $record->$primary_column . '</a></td>';
		 }
		 $new_start = ($i * ($no_of_columns_per_tab - 1)) + $i;
		 $new_end = $new_start + ($no_of_columns_per_tab - 1);
		 for ($k = $new_start; $k <= $new_end; $k++) {
			if ($k > $total_columns - 2) {
			 break;
			}
			$col_val = $this->column_array_s[$k];
			if (isset($record->$col_val)) {
			 $search_result .= '<td data-field_name="' . $col_val . '">' . $record->$col_val . '</td>';
			} else {
			 $search_result .= '<td data-field_name="' . $col_val . '"></td>';
			}
		 }
		 $search_result .= '</tr>';
		}
		$search_result .= '</tbody>';
	 } else {
		$search_result .= gettext('No Records Found!');
	 }
	 $search_result .= '</table> </div>';
	}
	$search_result .= '</div> </div>';
	return $search_result;
 }

 private function _add_hidden_fields() {
	$hidden_fld_stmt = "";

	if (!empty($this->_hidden_fields)) {
	 foreach ($this->_hidden_fields as $key => $value) {
		$bracketName = $key . '[]';
		$value_i = is_array($value) ? $value[0] : $value;
		$hidden_fld_stmt .= "<input type='hidden' class=\"hidden $key\" name=\"$bracketName\" value=\"$value_i\" >";
	 }
	}
	return $hidden_fld_stmt;
 }

 public function hidden_fields() {
	return $this->_add_hidden_fields();
 }

 public function search_form($class_obj) {
	global $f;
	$srch_div_cls = 'search ';
	$function_name = !empty($_GET['function_name']) ? $_GET['function_name'] : '';
	$report_name = !empty($_GET['report_name']) ? $_GET['report_name'] : '';
	if (!empty($_GET['window_type'])) {
	 $window_type = $_GET['window_type'];
	} else {
	 $window_type = '';
	}
	if (is_array($window_type)) {
	 $window_type = $window_type[0];
	}
	if (is_array($function_name)) {
	 $function_name = $function_name[0];
	}
	if (is_array($report_name)) {
	 $report_name = $report_name[0];
	}
	$class = is_array($this->_searching_class) ? $this->_searching_class[0] : $this->_searching_class;
	if (is_object($class_obj) && property_exists($class, 'field_a')) {
	 $search_array = $class_obj->field_a;
	} else {
	 $search_array = $class::$field_array;
	}

	if (empty($_GET['column_array'])) {
	 if (is_object($class_obj) && property_exists($class_obj, 'column')) {
		$column_array = $class_obj->column;
	 } else if (property_exists($class_obj, 'field_a')) {
		$column_array = $class_obj->field_a;
	 }
	} else {
	 $column_array = unserialize(base64_decode(filter_input(INPUT_GET, 'column_array')));
	}

	if (!empty($_GET['new_column'])) {
	 $new_column = filter_input(INPUT_GET, 'new_column');
	 if (!empty($new_column)) {
		foreach ($new_column as $key => $value) {
		 if ((!(is_array($value))) && (!empty($value))) {
			array_push($column_array, $value);
		 }
		}
	 }
	}
	$serialzed_column_array = base64_encode(serialize($column_array));

//start of the srach statement
	$search_form_statement = "";

	$search_form_statement .= "<span id='search_tip' class='clickable ino-btn2'>" . gettext('Searching Tips') . "</span>";
	if ((isset($_GET['window_type']) && $_GET['window_type'] == 'popover') || $this->_window_type == 'popover') {
	 $search_form_statement .= '<div class="tabContainer"> ';
	} else {
	 $search_form_statement .= "<form action=\"$this->_form_post_link.php\" name=\"$this->_form_name\" method='GET' class=\"full-width search_box $this->_form_name\" id=\"$this->_form_name\">";
	 $search_form_statement .= '<div id="tabsHeader">';
	 $search_form_statement .= '<ul class="tabMain">
     <li><a href="#tabsHeader-1">' . gettext("Search Parameters") . '</a></li>
     <li><a href="#tabsHeader-2">' . gettext('eMail Details') . '</a></li>
     <li><a href="#tabsHeader-3">' . gettext('Scheduling') . '</a></li>
    </ul>';
	 $search_form_statement .= '<div class="tabContainer"> ';
	 $search_form_statement .='<div id="tabsHeader-1" class="tabContent col-md-12">';
	}

	//start of first ul
	$search_form_statement .= '<div id="search_form_divID">';
	$search_form_statement .= '<ul class="search_form column header_field">';
	$search_form_statement .=$this->_add_hidden_fields();
	if (!empty($this->option_lists)) {
	 foreach ($this->option_lists as $key => $value) {
		if (!empty($_GET[$value]) && !(is_array($_GET[$value]))) {
		 $get_value = urldecode(filter_input(INPUT_GET, $value));
		} else if (!empty($_GET[$value]) && (is_array($_GET[$value]))) {
		 $get_value = urldecode($_GET[$value][0]);
		} else {
		 $get_value = "";
		}
		$search_form_statement .= "<li><label class=\"label_$key\">" . gettext(ucwords(str_replace('_', ' ', $key))) . "</label>";
		$class_name = " $srch_div_cls select_search " . $key;
		$option_header = option_header::find_by_name($value);
		$ol = new option_line;
		$option_lines = $ol->findBy_parentId($option_header->option_header_id);
		$search_form_statement .= $f->select_field_from_object($key, $option_lines, 'option_line_code', 'option_line_value', $get_value, $key, $class_name);
		$search_form_statement .= '</li>';
	 }
	}

	if (!empty($this->_search_functions)) {
	 foreach ($this->_search_functions as $key => $value) {
		$search_form_statement .= "<li><label class=\"label_$key\"> $key </label>";
		if (method_exists($class_obj, $value)) {
		 $search_form_statement .= call_user_func(array($class_obj, $value));
		} else if (function_exists($value)) {
		 $search_form_statement .= call_user_func($value);
		}
		$search_form_statement .= '</li>';
	 }
	}

	foreach ($this->_initial_search_array as $key => $value) {
	 $readonly_field = '  ';
	 if (!empty($_GET[$value]) && !(is_array($_GET[$value]))) {
//		$get_value = urldecode(filter_input(INPUT_GET, $value));
		$get_value = $_GET[$value];
		$readonly_field = ' readonly ';
	 } else if (!empty($_GET[$value]) && (is_array($_GET[$value]))) {
		$get_value = $_GET[$value][0];
		if (!empty($_GET[$value][0])) {
		 $readonly_field = ' readonly ';
		}
	 } else {
		$get_value = "";
		$readonly_field = '  ';
	 }
	 $bracketName = $value . '[]';
	 $search_form_statement .= "<li><label class=\"label_$value\">" . gettext(ucwords(str_replace('_', ' ', $value))) . " </label>";
	 $search_form_statement .= "<input type=\"text\" name=\"$bracketName\" $readonly_field class=\"$value text_search \"   size=\"15\" value=\"$get_value\" >";
	 $search_form_statement .= '</li>';
	}

	$search_form_statement .= "<li><label>" . gettext('Dynamic Criteria') . "</label>";
	$search_form_statement .= "<select name=\"new_search_criteria\" id=\"new_search_criteria\" class=\"new_search_criteria $srch_div_cls\">";
	foreach ($search_array as $key => $search_value) {
	 $search_form_statement .= '<option value="' . htmlentities($search_value) . '"';
	 $search_form_statement .= '>' . gettext(ucwords(str_replace('_', ' ', $search_value))) . '</option>';
	}
	$search_form_statement .= '</select>';
//	$search_form_statement .= '<li><input type="button" class="add button" id="new_search_criteria_add" value="Add"></li>';
	$search_form_statement .= "<input type=\"hidden\" name=\"column_array\" id=\"column_array\" 
 value=\"$serialzed_column_array\" class=\"hidden search\" >";
	$search_form_statement .= "<input type=\"hidden\" name=\"search_class\" value=\"$class\" class=\"$srch_div_cls hidden\" ></li>";
	$search_form_statement .= "</ul>";
//end of first ul
//start of second ul
	$search_form_statement .= "<ul class=\"add_new_search form_buttons column header_field\" >";

	//order by
	$search_form_statement .= "<li><label>" . gettext('Order By') . "</label></li>";
	$search_form_statement .= "<li><select name=\"search_order_by[]\" class=\"$srch_div_cls search_order_by\" > ";
//	$search_form_statement .= "<option value=\"\"> </option>";

	foreach ($search_array as $key => $value) {
	 if (!empty($this->_search_order_by)) {
		if ($value == $this->_search_order_by) {
		 $selected_search_order_by = ' selected ';
		} else {
		 $selected_search_order_by = ' ';
		}
	 } else {
		$selected_search_order_by = ' ';
	 }
	 $search_form_statement .= '<option value="' . htmlentities($value) . '"';
	 $search_form_statement .= $selected_search_order_by;
	 $search_form_statement .= '>' . $value . '</option>';
	}
	$search_form_statement .= "<option value=\"remove\" class=\"$srch_div_cls remove remove_option\">Remove</option>";
	$search_form_statement .= '</select>';

	//ascending or descnding
	$search_form_statement .= "<select name=\"search_asc_desc[]\" class=\"$srch_div_cls search_asc_desc\" > ";
	$selected_asc = "";
	$selected_desc = "";
	if ($this->_search_asc_desc == 'asc') {
	 $selected_asc = ' selected ';
	} else {
	 $selected_desc = ' selected ';
	}
	$search_form_statement .= "<option value=\"asc\"" . $selected_asc . $selected_desc . ">" . gettext('Ascending') . "</option>";
	$search_form_statement .= "<option value=\"desc\"" . $selected_asc . $selected_desc . ">" . gettext('Descending') . "</option>";
	$search_form_statement .= '</select></li>';

	//Records group by
	if (!empty($this->_group_by)) {
	 $search_form_statement .= '<li><label> Group By</label>';
	 $search_form_statement .= "<select name=\"group_by\" id=\"group_by\" class='$srch_div_cls group_by'>";
	 $search_form_statement .= "<option value='' ></option>";
	 foreach ($this->_group_by as $key => $value) {
		$search_form_statement .= "<option value=\"$key\" >$value</option>";
	 }
	 $search_form_statement .= '</select></li>';
	}

	//Records per page
	$search_form_statement .= '<li><label> ' . gettext('Per Page') . '</label>';
	$search_form_statement .= $f->select_field_from_array('per_page', $this->_per_page_a, $this->_per_page, 'per_page');


	$reset_link = "$this->_form_post_link.php?class_name=$class&mode=$this->_search_mode&show_block=$this->_show_block";
	$search_form_statement .="<li><input type=\"hidden\" form=\"$this->_form_name\" name=\"window_type\" value=\"$window_type\" class=\"$srch_div_cls window_type hidden\" ></li>";

	$search_form_statement .="<li><input type=\"hidden\" form=\"$this->_form_name\" name=\"function_name\" value=\"$function_name\" class=\"$srch_div_cls function_name hidden\" ></li>";
	$search_form_statement .="<li><input type=\"hidden\" form=\"$this->_form_name\" name=\"report_name\" value=\"$report_name\" class=\"$srch_div_cls report_name hidden\" ></li>";
	$search_form_statement .="<li><input type=\"hidden\" form=\"$this->_form_name\" name=\"search_class_name\" value=\"$class\" class=\"$srch_div_cls class_name hidden\" ></li>";
	$search_form_statement .="<li><input type=\"button\" form=\"$this->_form_name\" name=\"reset_class_name\" value=\"" . gettext('Reset All') . "\" class=\"$srch_div_cls reset btn btn-default\" ></li>";
	$search_form_statement .="<li><input type=\"submit\" form=\"$this->_form_name\" name=\"submit_search\" class=\"$srch_div_cls btn btn-default\" value=\"" . gettext('Search') . "\" id=\"search_submit_btn\"></li>";
	$search_form_statement .="</ul>";
	$search_form_statement .="</div>";
	if (isset($_GET['window_type']) && $_GET['window_type'] == 'popover' || $this->_window_type == 'popover') {
	 $search_form_statement .="</div> "; //end of tab1
	} else {
	 $search_form_statement .="</div> "; //end of tab1

	 $search_form_statement .= '<div id="tabsHeader-2" class="tabContent col-md-12">';
	 $search_form_statement .='<ul>';
	 $search_form_statement .= '<li><label>' . gettext('Email Address') . '</label> ' . form::text_area('email_addresses', '', '3', '120', '', gettext('Separate each email address by comma(,) or a new line')) . ' </li>';
	 $search_form_statement .='<li><label>' . gettext('Email Format') . '</label> ' . $f->select_field_from_array('email_format', dbObject::$download_format, 'excel_format') . '</li>';
	 $search_form_statement .='</ul>';
	 $search_form_statement .="</div> "; //end of tabsHeader-2

	 $search_form_statement .= '<div id="tabsHeader-3" class="tabContent col-md-12">';
	 $search_form_statement .= '<ul class="simple_column full-width">';
	 $search_form_statement .= "<li><label>" . gettext('Frequency UOM') . " </label>";
	 $search_form_statement .= $f->select_field_from_array('frequency_uom', sys_program_schedule::$frequency_uom_a, '', 'frequency_uom');
	 $search_form_statement .= '</li>';
	 $search_form_statement .= '<li><label>' . gettext('Frequency') . ' </label>';
	 $search_form_statement .= $f->text_field('frequency_value', '');
	 $search_form_statement .= '</li>';
	 $search_form_statement .= '<li><label>' . gettext('Start DateTime') . ' </label>' . $f->dateTime_field('start_date_time', '') . '</li>';
	 $search_form_statement .= '<li><label>' . gettext('Increase Date Parameter') . ' </label>' . $f->checkBox_field('increase_date_parameter_cb', '') . '</li>';
	 $search_form_statement .= '</ul>';
	 $search_form_statement .="</div> "; //end of tabsHeader-2


	 $search_form_statement .="</div> "; //end of tabcontainer
	 $search_form_statement .="</div> "; //end of tabsHeader
	 $search_form_statement .="</form> ";
	}
	return $search_form_statement;
 }

 public function program_form($class_obj) {
	global $f;
	if (!empty($_GET['program_type'])) {
	 $program_type = $_GET['program_type'];
	 $action = 'download.php ';
	 $target = '_blank';
	} else {
	 $target = $action = $program_type = '';
	}

	$class = $this->_searching_class;
	if (property_exists($class, 'field_a')) {
	 $search_array = $class_obj->field_a;
	}
//start of the srach statement
	$program_form_statement = "<div id='program_form' class='row'>";
	$program_form_statement .= "<form action=\"$action\" name=\"$this->_form_name\" "
					. " method='POST' class=\"search_box submit_program_form $this->_form_name\" target=\"$target\"  id=\"$this->_form_name\">";

	//start of first ul
	$program_form_statement .= '<fieldset class="col-md-6 parameters"><legend class="fs-default">Program Parameters</legend>';
	$program_form_statement .= '<ul class="tabContent">';
	if (!empty($this->_search_functions)) {
	 foreach ($this->_search_functions as $key => $value) {
		$program_form_statement .= "<li class='prg' id='" . $value . "' ><label class=\"label_$key\"> $key</label>";
		if (method_exists($class_obj, $value)) {
		 $program_form_statement .= call_user_func(array($class_obj, $value));
		} else if (function_exists($value)) {
		 $program_form_statement .= call_user_func($value);
		}
		$program_form_statement .= '</li>';
	 }
	}
	//show only first first parameter from initial search
	$intial_search_field_count = 0;
	foreach ($this->_initial_search_array as $key => $value) {
	 $intial_search_field_count++;
	 if ($intial_search_field_count > 1) {
		break;
	 }
	 if (!empty($_GET[$value]) && !(is_array($_GET[$value]))) {
		$get_value = filter_input(INPUT_GET, $value);
	 } else {
		$get_value = "";
	 }
	 $name_bracketed = $value . '[]';
	 $program_form_statement .= "<li id='" . $value . "' ><label class=\"label_$value\">" . gettext(ucwords(str_replace('_', ' ', $value))) . "</label>";
	 $program_form_statement .= "<input type=\"text\" name=\"$name_bracketed\" class=\"$value text_search \"   size=\"15\" value=\"$get_value\" >";
	 $program_form_statement .= '</li>';
	}

	if (!empty($program_type) && ($program_type == 'download_report')) {
	 $program_form_statement .='<li><label>' . gettext('Download Format') . '</label>' . $f->select_field_from_array('download_format', dbObject::$download_format, '') . '</li>';
	}

	$program_form_statement .= "<li><label>" . gettext('Dynamic Criteria') . "</label>";
	$program_form_statement .= "<select name=\"new_search_criteria\" id=\"new_search_criteria\" class=\"new_search_criteria\">";
	if (!empty($search_array)) {
	 foreach ($search_array as $key => $search_value) {
		$program_form_statement .= '<option value="' . htmlentities($search_value) . '"';
		$program_form_statement .= '>' . $search_value . '</option>';
	 }
	}

	$program_form_statement .= '</select>';
//	$program_form_statement .= '<li><input type="button" class="add button" id="new_search_criteria_add" value="Add"></li>';
	$program_form_statement .=$this->_add_hidden_fields();
	$program_form_statement .= "</ul>";
	$program_form_statement .= '</fieldset>';
//end of first ul
//$f = new inoform();
//start of schdule details
	$program_form_statement .= '<fieldset class="col-md-4"><legend class="fs-default">Auto-Schedule Options</legend>';
	$program_form_statement .= '<div class="hideDiv_input fa fa-plus-circle clickable"></div>';
	$program_form_statement .= '<ul class="simple_column schdule_details hideDiv_input_element">';
	$program_form_statement .= "<li><label>" . gettext('Frequency UOM') . " </label>";
	$program_form_statement .= $f->select_field_from_array('frequency_uom', sys_program_schedule::$frequency_uom_a, '', 'frequency_uom');
	$program_form_statement .= '</li>';
	$program_form_statement .= '<li><label>' . gettext('Frequency') . ' </label>';
	$program_form_statement .= $f->text_field('frequency_value', '');
	$program_form_statement .= '</li>';
	$program_form_statement .= '<li><label>' . gettext('Start DateTime') . ' </label>' . $f->dateTime_field('start_date_time', '') . '</li>';
	$program_form_statement .= '<li><label>' . gettext('Increase Date Parameter') . ' </label>' . $f->checkBox_field('increase_date_parameter_cb', '') . '</li>';
	$program_form_statement .= '</ul>';
	$program_form_statement .= '</fieldset>';

//start of form button ul
	$program_form_statement .="</div><div class='row'>";
	$program_form_statement .="<ul class=\"program form_buttons\">";
	//add the hidden fields if any
	$program_form_statement .="<li><input type=\"button\" form=\"$this->_form_name\" name=\"reset_program\" class=\"reset program btn btn-default\" value=\"" . gettext('Reset All') . "\" id=\"reset_program\"></li>";
//  $program_form_statement .= "<li><a href=\"$this->_form_post_link.php?class_name=$class&mode=$this->_search_mode&show_block=$this->_show_block\" "
//   . " class=\"reset button\" id=\"search_reset_btn\" name=\"class_name\" value=\"$class\" > Reset All</a></li>";
	$program_form_statement .="<li><input type=\"hidden\" form=\"$this->_form_name\" name=\"class_name\" value=\"$class\" class=\"search class_name hidden\" ></li>";
	if ($this->_searching_class != 'convertToProd') {
	 if (!empty($program_type) && ($program_type == 'download_report')) {
		$program_form_statement .="<li><input type=\"button\" form=\"$this->_form_name\" name=\"submit_program\" class=\"program btn btn-default\" value=\"" . gettext('Generate Report') . "\" id=\"generate_report\"></li>";
	 } else {
		$program_form_statement .="<li><input type=\"button\" form=\"$this->_form_name\" name=\"submit_program\" class=\"program btn btn-default\" value=\"" . gettext('Submit') . "\" id=\"save_program\"></li>";
	 }
	} else if (convertToProd::$allow_conversion) {
	 $program_form_statement .="<li><input type=\"button\" form=\"$this->_form_name\" name=\"submit_program\" class=\"program btn btn-default\" value=\"" . gettext('Submit') . "\" id=\"save_program\"></li>";
	} else {
	 $program_form_statement .="<li class='error'>The submit button is disabled for security reason.<br>Set allow_conversion variable to true in convertToProd class to use this program</li>";
	}
	$program_form_statement .="</ul>";
	$program_form_statement .="</form></div> ";
	return $program_form_statement;
 }

 public function find_with_pagination() {
	$return_a = [];
	$class = $this->_searching_class;
	$$class = new $class;
	$search_array = $$class->field_a;

	if (empty($_GET['column_array'])) {
	 if (property_exists($class, 'column')) {
		$column_array = $$class->column;
	 }
	} else {
	 $column_array = unserialize(base64_decode($_GET['column_array']));
	}
	if (!empty($_GET['new_column'])) {
	 $new_column = $_GET['new_column'];
	 if (!empty($new_column)) {
		foreach ($new_column as $key => $value) {
		 if ((!(is_array($value))) && (!empty($value))) {
			array_push($column_array, $value);
		 }
		}
	 }
	}

	$whereFields = array();
//to check number of criterias
	$noof_criteria = 0;
	foreach ($search_array as $key => $value) {
	 if (!empty($_GET[$value])) {
		if (strpos($value, '_id') !== false) {
		 $whereFields[] = sprintf("`%s` = %s ", $value, trim(mysql_prep($_GET[$value])));
		} else {
		 $whereFields[] = sprintf("`%s` LIKE '%%%s%%'", $value, trim(mysql_prep($_GET[$value])));
		}
		$noof_criteria++;
	 }
	}

	if (count($whereFields) > 0) {
	 $whereClause = " WHERE " . implode(" AND ", $whereFields);
	 // And then create the SQL query itself.
	 $sql = "SELECT * FROM " . $this->_searching_table_name . $whereClause;
	 $count_sql = "SELECT COUNT(*) FROM " . $this->_searching_table_nam . $whereClause;
	 $all_download_sql = "SELECT * FROM  " . $this->_searching_table_name . $whereClause;
	} else {
	 $sql = "SELECT * FROM " . $this->_searching_table_name;
	 $count_sql = "SELECT COUNT(*) FROM " . $this->_searching_table_name;
	 $all_download_sql = "SELECT * FROM  " . $this->_searching_table_name;
	}

	if ((!empty($this->_search_order_by)) && (!empty($this->_search_asc_desc))) {
	 $sql .= ' ORDER BY ' . $this->_search_order_by . ' ' . $this->_search_asc_desc;
	 $all_download_sql .= ' ORDER BY ' . $this->_search_order_by . ' ' . $this->_search_asc_desc;
	}
	$total_count = $class::count_all_by_sql($count_sql);

	if (!empty($this->_per_page)) {
	 $pagination = new pagination($this->_page_no, $this->_per_page, $total_count);
	 $pagination->setProperty('_query_string', $this->_query_string);
	 $pagination_statement = $pagination->show_pagination();
	 $return_a['pagination'] = $pagination_statement;
	 $sql = ino_perPageSql_i($sql, $this->_per_page, $pagination->offset());
	}
	$search_result = $class::find_by_sql($sql);
	$return_a['search_result'] = $search_result;
 }

}

//end of search class
$search = new search();
$s = & $search;
?>
