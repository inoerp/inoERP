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
 private $_per_page;
 private $_page_no;
 private $_searching_class;
 private $_initial_search_array;
 private $_per_page_selected = [
		 1 => 'per_page_selected_1',
		 5 => 'per_page_selected_5',
		 10 => 'per_page_selected_10',
		 20 => 'per_page_selected_20',
		 50 => 'per_page_selected_50',
		 100 => 'per_page_selected_100',
		 1000 => 'per_page_selected_1000',
		 10000 => 'per_page_selected_10000',
		 50000 => 'per_page_selected_50000',
		 'all' => 'per_page_selected_all',
 ];
 //to show result
 public $primary_column_s;
 public $column_array_s = [];
 public $result = [];
 //to show form
 public $option_lists;

 public function setProperty($property, $value) {
	if (property_exists($this, $property)) {
	 switch ($property) {
		case '_show_update_path':
		 $this->$property = !empty($value) ? true : false;

		case '_show_view_path':
		 $this->$property = !empty($value) ? true : false;

		case '_form_name':
		 $this->$property = $value;

		case '_form_post_link':
		 $this->$property = $value;

		case '_view_action_meassge':
		 $this->$property = $value;

		case '_update_action_meassge':
		 $this->$property = $value;

		case '_result':
		 $this->$property = is_array($value) ? $value : false;

		case '_column_array':
		 $this->$property = is_array($value) ? $value : false;

		case '_extra_path':
		 $this->$property = is_array($value) ? $value : false;

		case '_group_by':
		 $this->$property = is_array($value) ? $value : false;

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

 public function search_result_op() {
	if (empty($this->_view_path)) {
	 $this->_view_path = 'form.php?class_name=' . $this->_searching_class;
	}
	if (empty($this->_update_path)) {
	 $this->_update_path = 'form.php?class_name=' . $this->_searching_class;
	}
	$search_result = "";
	$search_result .= "<table class=\"normal\"><thead><tr>";
	foreach ($this->column_array_s as $key => $value) {
	  $search_result .= '<th>' . ucwords(strtolower(str_replace('_', ' ', $value))). '</th>';
	}
	$search_result .= '<th>Action</th>';
	$search_result .='</tr></thead>';
	If (!empty($this->result)) {
	 $search_result .= '<tbody>';
	 foreach ($this->result as $record) {

		$search_result .='<tr>';
		foreach ($this->column_array_s as $key => $value) {
		 $search_result .= '<td>';
		 if (isset($record->$value)) {
			$search_result .= $record->$value;
		 }
		 $search_result .= '</td>';
		}
		$search_result .= '<td>';
		if ($this->_show_view_path) {
		 $search_result .= "&nbsp;&nbsp;<a href=\"$this->_view_path&mode=2&$this->primary_column_s=" . $record->{$this->primary_column_s} . '">' . $this->_view_action_meassge . '</a>';
		}
		if (!empty($this->_extra_path)) {
		 foreach ($this->_extra_path as $pathname => $pathmsg) {
			$search_result .= "&nbsp;&nbsp;<a href=\"$pathname&$this->primary_column_s=" . $record->{$this->primary_column_s} . '">' . $pathmsg . '</a>';
		 }
		}
		if ($this->_show_update_path) {
		 $search_result .= "&nbsp;&nbsp;<a href=\"$this->_update_path&mode=9&$this->primary_column_s=" . $record->{$this->primary_column_s} . '">' . $this->_update_action_meassge . '</a> ';
		}
		$search_result .= '</td></tr>';
	 }
	 $search_result .= '</tbody>';
	} else {
	 $search_result .= 'No Records Found!';
	}
	$search_result .= '</table>';

	return $search_result;
 }

 private function _add_hidden_fields() {
	$hidden_fld_stmt = "";
	if (!empty($this->_hidden_fields)) {
	 foreach ($this->_hidden_fields as $key => $value) {
		$hidden_fld_stmt .= "<input type='hidden' class=\"hidden $key\" name=\"$key\" value=\"$value\" >";
	 }
	}
	return $hidden_fld_stmt;
 }

 public function hidden_fields() {
	return $this->_add_hidden_fields();
 }

 public function search_form($class_obj) {
	$class = $this->_searching_class;
	if (property_exists($class, 'field_a')) {
	 $search_array = $class_obj->field_a;
	} else {
	 $search_array = $class::$field_array;
	}

	if (empty($_GET['column_array'])) {
	 if (property_exists($class, 'column')) {
		$column_array = $class_obj->column;
	 } else if (property_exists($class, 'column_array')) {
		$column_array = $class::$column_array;
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

	$per_page_selected_1 = "";
	$per_page_selected_5 = "";
	$per_page_selected_10 = "";
	$per_page_selected_20 = "";
	$per_page_selected_50 = "";
	$per_page_selected_100 = "";
	$per_page_selected_1000 = "";
	$per_page_selected_10000 = "";
	$per_page_selected_50000 = "";
	$per_page_selected_all = "";

	if (!empty($this->_per_page)) {
	 switch ($this->_per_page_selected) {
		case '1':
		 $per_page_selected_1 = "selected";
		 break;

		case '5':
		 $per_page_selected_5 = "selected";
		 break;

		case '10':
		 $per_page_selected_10 = "selected";
		 break;

		case '20':
		 $per_page_selected_20 = "selected";
		 break;

		case '50':
		 $per_page_selected_50 = "selected";
		 break;

		case '100':
		 $per_page_selected_100 = "selected";
		 break;

		case '1000':
		 $per_page_selected_1000 = "selected";
		 break;

		case '10000':
		 $per_page_selected_10000 = "selected";
		 break;

		case '50000':
		 $per_page_selected_50000 = "selected";
		 break;

		case 'all':
		 $per_page_selected_all = "selected";
		 break;

		default:

		 break;
	 }
	}

//start of the srach statement
	$search_form_statement = "";
	$search_form_statement .= "<form action=\"\" name=\"$this->_form_name\" method='GET' class=\"search_box $this->_form_name\" id=\"$this->_form_name\">";

	//start of first ul
	$search_form_statement .= '<ul class="search_form column four_column">';
	foreach ($this->_initial_search_array as $key => $value) {
	 if (!empty($_GET[$value]) && !(is_array($_GET[$value]))) {
		$get_value = filter_input(INPUT_GET, $value);
	 } else {
		$get_value = "";
	 }
	 $search_form_statement .= "<li><label class=\"label_$value\">". ucwords(str_replace('_', ' ', $value))." : </label>";
	 $search_form_statement .= "<input type=\"text\" name=\"$value\" class=\"$value text_search \"   size=\"15\" value=\"$get_value\" >";
	 $search_form_statement .= '</li>';
	}

	if (!empty($this->option_lists)) {
	 foreach ($this->option_lists as $key => $value) {
		$search_form_statement .= "<li><label class=\"label_$key\">". ucwords(str_replace('_', ' ', $key))." : </label>";
		$class_name = ' select_search ' . $key;
		$option_header = option_header::find_by_name($value);
		$ol = new option_line;
		$option_lines = $ol->findBy_parentId($option_header->option_header_id);
		$search_form_statement .= form::select_field_from_object($key, $option_lines, 'option_line_code', 'option_line_value', $get_value, '', '', $class_name, '', '', 1);
		$search_form_statement .= '</li>';
	 }
	}

	if (!empty($this->_search_functions)) {
	 foreach ($this->_search_functions as $key => $value) {
		$search_form_statement .= "<li><label class=\"label_$key\"> $key : </label>";
		if (method_exists($class_obj, $value)) {
		 $search_form_statement .= call_user_func(array($class_obj, $value));
		} else if (function_exists($value)) {
		 $search_form_statement .= call_user_func($value);
		}
		$search_form_statement .= '</li>';
	 }
	}

	$search_form_statement .= "<li><label>Dynamic Criteria </label>";
	$search_form_statement .= "<select name=\"new_search_criteria\" id=\"new_search_criteria\" class=\"new_search_criteria\">";
	foreach ($search_array as $key => $search_value) {
	 $search_form_statement .= '<option value="' . htmlentities($search_value) . '"';
	 $search_form_statement .= '>' . $search_value . '</option>';
	}
	$search_form_statement .= '</select>';
//	$search_form_statement .= '<li><input type="button" class="add button" id="new_search_criteria_add" value="Add"></li>';
	$search_form_statement .= "<input type=\"hidden\" name=\"column_array\" id=\"column_array\" 
 value=\"$serialzed_column_array\" class=\"hidden\" >";
	$search_form_statement .= "<input type=\"hidden\" name=\"search_class\" value=\"$class\" class=\"hidden\" ></li>";
	$search_form_statement .=$this->_add_hidden_fields();
	$search_form_statement .= "</ul>";
//end of first ul
//start of second ul
	$search_form_statement .= "<ul class=\"add_new_search form_buttons\" >";
	$search_form_statement .= "<li><label>New column</label>";
	$search_form_statement .= "<select name=\"new_column[]\" class=\"new_column\" > ";
	$search_form_statement .= "<option value=\"\"> </option>";

	foreach ($search_array as $key => $value) {
	 $search_form_statement .= '<option value="' . htmlentities($value) . '"';
	 $search_form_statement .= '>' . $value . '</option>';
	}
	$search_form_statement .= '</select></li>';

	//order by
	$search_form_statement .= "<li><label>Order By</label></li>";
	$search_form_statement .= "<li><select name=\"search_order_by[]\" class=\"search_order_by\" > ";
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
	$search_form_statement .= "<option value=\"remove\" class=\"remove remove_option\">Remove</option>";
	$search_form_statement .= '</select>';

	//ascending or descnding
	$search_form_statement .= "<select name=\"search_asc_desc[]\" class=\"search_asc_desc\" > ";
	$selected_asc = "";
	$selected_desc = "";
	if ($this->_search_asc_desc == 'asc') {
	 $selected_asc = ' selected ';
	} else {
	 $selected_desc = ' selected ';
	}
	$search_form_statement .= "<option value=\"asc\"" . $selected_asc . $selected_desc . ">Ascending</option>";
	$search_form_statement .= "<option value=\"desc\"" . $selected_asc . $selected_desc . ">Descending</option>";
	$search_form_statement .= '</select></li>';

	//Records group by
	if (!empty($this->_group_by)) {
	 $search_form_statement .= '<li><label> Group By</label>';
	 $search_form_statement .= "<select name=\"group_by\" id=\"group_by\" class='select group_by'>";
	 $search_form_statement .= "<option value='' ></option>";
	 foreach ($this->_group_by as $key => $value) {
		$search_form_statement .= "<option value=\"$key\" >$value</option>";
	 }
	 $search_form_statement .= '</select></li>';
	}

	//Records per page
	$search_form_statement .= '<li><label> Per page</label>';
	$search_form_statement .= "<select name=\"per_page\" id=\"per_page\">";

	$search_form_statement .= "<option value=\"5\" $per_page_selected_5 >5</option>";
	$search_form_statement .= "<option value=\"10\" $per_page_selected_10 >10</option>";
	$search_form_statement .= "<option value=\"20\" $per_page_selected_20 >20</option>";
	$search_form_statement .= "<option value=\"50\" $per_page_selected_50 >50</option>";
	$search_form_statement .= "<option value=\"100\" $per_page_selected_100 >100</option>";
	$search_form_statement .= "<option value=\"1000\" $per_page_selected_1000 >1000</option>";
	$search_form_statement .= "<option value=\"10000\" $per_page_selected_10000 >10000</option>";
	$search_form_statement .= "<option value=\"50000\" $per_page_selected_50000 >50000</option>";
	$search_form_statement .= "<option value=\"all\" $per_page_selected_all >All</option>";
	$search_form_statement .= "<option value=\"1\" $per_page_selected_1 >1</option>";
	$search_form_statement .= "</select></li>";
//	$search_form_statement .="</ul>";
//end of second ul
//start of form button ul
//	$search_form_statement .="<ul class=\"form_buttons\">";
	//add the hidden fields if any

	$reset_link = "$this->_form_post_link.php?class_name=$class&mode=$this->_search_mode&show_block=$this->_show_block";
	$search_form_statement .= "<li><a href=\"$reset_link\" "
					. " class=\"reset button\" id=\"search_reset_btn\" name=\"class_name\" value=\"$class\" > Reset All</a></li>";
	$search_form_statement .="<li><input type=\"hidden\" form=\"$this->_form_name\" name=\"class_name\" value=\"$class\" class=\"search class_name\" ></li>";
	$search_form_statement .="<li><input type=\"submit\" form=\"$this->_form_name\" name=\"submit_search\" class=\"search button\" value=\"Search\" id=\"search_submit_btn\"></li>";
	$search_form_statement .="</ul>";
	$search_form_statement .="</form> ";
	return $search_form_statement;
 }

 public function program_form($class_obj) {
	$class = $this->_searching_class;
	if (property_exists($class, 'field_a')) {
	 $search_array = $class_obj->field_a;
	}
//start of the srach statement
	$program_form_statement = "";
	$program_form_statement .= "<form action=\"\" name=\"$this->_form_name\" method='POST' class=\"search_box $this->_form_name\" id=\"$this->_form_name\">";

	//start of first ul
	$program_form_statement .= '<ul class="program_form">';
	if (!empty($this->_search_functions)) {
	 foreach ($this->_search_functions as $key => $value) {
		$program_form_statement .= "<li><label class=\"label_$key\"> $key : </label>";
		if (method_exists($class_obj, $value)) {
		 $program_form_statement .= call_user_func(array($class_obj, $value));
		} else if (function_exists($value)) {
		 $program_form_statement .= call_user_func($value);
		}
		$program_form_statement .= '</li>';
	 }
	}
	foreach ($this->_initial_search_array as $key => $value) {
	 if (!empty($_GET[$value]) && !(is_array($_GET[$value]))) {
		$get_value = filter_input(INPUT_GET, $value);
	 } else {
		$get_value = "";
	 }
	 $program_form_statement .= "<li><label class=\"label_$value\">". ucwords(str_replace('_', ' ', $value))." : </label>";
	 $program_form_statement .= "<input type=\"text\" name=\"$value\" class=\"$value text_search \"   size=\"15\" value=\"$get_value\" >";
	 $program_form_statement .= '</li>';
	}


	$program_form_statement .= "<li><label>Dynamic Criteria </label>";
	$program_form_statement .= "<select name=\"new_search_criteria\" id=\"new_search_criteria\" class=\"new_search_criteria\">";
	foreach ($search_array as $key => $search_value) {
	 $program_form_statement .= '<option value="' . htmlentities($search_value) . '"';
	 $program_form_statement .= '>' . $search_value . '</option>';
	}
	$program_form_statement .= '</select>';
//	$program_form_statement .= '<li><input type="button" class="add button" id="new_search_criteria_add" value="Add"></li>';
	$program_form_statement .=$this->_add_hidden_fields();
	$program_form_statement .= "</ul>";
//end of first ul
//start of form button ul
	$program_form_statement .="<ul class=\"form_buttons\">";
	//add the hidden fields if any
	$program_form_statement .= "<li><a href=\"$this->_form_post_link.php?class_name=$class&mode=$this->_search_mode&show_block=$this->_show_block\" "
					. " class=\"reset button\" id=\"search_reset_btn\" name=\"class_name\" value=\"$class\" > Reset All</a></li>";
	$program_form_statement .="<li><input type=\"hidden\" form=\"$this->_form_name\" name=\"class_name\" value=\"$class\" class=\"search class_name\" ></li>";
	$program_form_statement .="<li><input type=\"button\" form=\"$this->_form_name\" name=\"submit_program\" class=\"program button\" value=\"Submit\" id=\"save\"></li>";
	$program_form_statement .="</ul>";
	$program_form_statement .="</form> ";
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
	 $sql .=" LIMIT {$this->_per_page} ";
	 $sql .=" OFFSET {$pagination->offset()}";
	}
	$search_result = $class::find_by_sql($sql);
	$return_a['search_result'] = $search_result;
 }

}

//end of search class
$search = new search();
$s = & $search;
?>