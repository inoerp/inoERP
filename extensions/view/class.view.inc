<?php

class view extends dbObject{

 public static $table_name = "view";
 //  data base variables as stored database column name
 public static $field_array = [
		 "view_id",
		 "view",
		 "description",
		 "logical_settings",
		 "query",
		 "select",
		 "from",
		 "where",
		 "order_by",
		 "query_end",		 
		 "filters",
		 "display_type",
		 "page",
		 "page_title",
		 "page_header",
		 "page_footer",
		 "use_pager",
		 "contents_per_page",
		 "path",
		 "block",
		 "block_title",
		 "block_header",
		 "block_footer",
		 "block_type",
		 "block_more",
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
// public static $array_field_array =[
//		 "path"
// ];
//variables used for showing data


 public static $initial_search_array = [
		 "view_id",
		 "view",
		 "description",
 ];
 public static $checkbox_array = [
		 "rev_enabled_cb",
 ];
 public static $column_array = [
		 "rev_enabled_cb",
		 "view_id",
		 "view",
		 "description",
 ];
 public static $base_encoded_array = [
		 "logical_settings",
		 "query"
 ];
 public static $requiredField_array = [
		 "view",
		 "description",
		 "query"
 ];
 public static $primary_column = "view_id";
 public $all_table_names;
 public $view_id;
 public $view;
 public $logical_settings;
 public $description;
 public $query;
 public $select;
 public $from;
 public $where;
 public $order_by;
 public $query_end;
 public $filters;
 public $display_type;
 public $page;
 public $page_title;
 public $page_header;
 public $page_footer;
 public $use_pager;
 public $contents_per_page;
 public $path;
 public $block;
 public $block_title;
 public $block_header;
 public $block_footer;
 public $block_type;
 public $block_more;
 public $rev_number;
 public $rev_enabled_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 
  function __construct() {
	global $dbc;
	$sql_fields = " SHOW COLUMNS FROM  " . self::$table_name;
	$prepare = $dbc->connection->prepare($sql_fields);
	$prepare->execute();
	self::$field_array = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
 }

 public function __set($name, $value) {
	$this->$name = $value;
 }

   Public static function view_display_types() {
    $org_header = option_header::find_by_name('VIEW_DISPLAY_TYPE');
    $type = option_line::find_by_option_id($org_header->option_header_id);
    return $type;
  }
	
 public static function find_all_tables() {
	global $db;
	$query = " SELECT TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE'";
	$result = $db->find_by_sql($query);

	$table_name_array = array();
	foreach ($result as $object) {
	 $table_name_array [] = $object->TABLE_NAME;
	}
	return $table_name_array;
 }

 public static function find_columns_of_table($table_name) {
	global $db;
	if (!empty($table_name)) {
	 $query = "SHOW COLUMNS FROM $table_name ";
	 $result = $db->find_by_sql($query);

	 $column_name_array = array();
	 foreach ($result as $object) {
		$column_name_array [] = $object->Field;
	 }
	 return $column_name_array;
	}
 }

 public static function find_all_idColumns() {
	global $db;
	$all_id_columns_array = [];
	$all_tables = self::find_all_tables();
	foreach ($all_tables AS $key => $values) {
	 if (!empty($values)) {
		$column_name = $values . '_id';
		$query = "SHOW COLUMNS FROM $values WHERE Field = '{$column_name}' ";
		$result = $db->find_by_sql($query);
		if ((count($result) > 0) && (!empty($result[0]->Field))) {
		 $all_id_columns_array[] = $result[0]->Field;
		}
	 }
	}
	return $all_id_columns_array;
 }

 public static function result_list_in_table($sql, $view_id, $pageno = "", $per_page = "", $query_string = "") {
	$path = 'view_results';
	$view_name = 'name';
	$view_path_records_array = view_path::find_by_view_id($view_id);
	global $db;

	$count_result = $db->find_by_sql($sql);
	$page_string = " ";

	if (!empty($per_page)) {
	 $page_string .= '<div id="noOfpages">';
	 $page_string .= '<form action="" method="POST">';
	 $page_string .= 'Show<select name="per_page">';
	 $page_string .= '<option value="3"> 3 </option>';
	 $page_string .= '<option value="5"> 5 </option>';
	 $page_string .= '<option value="10"> 10 </option>';
	 $page_string .= '<option value="20"> 20 </option>';
	 $page_string .= '<option value="50"> 50 </option>';
	 $page_string .= '</select>';
	 $page_string .= '<input type="submit" class="button" value="Per Page" >';
	 $page_string .= '</form>';
	 $page_string .= '</div>';
	 $total_count = count($count_result);
	 $pagination = new pagination($pageno, $per_page, $total_count);
	 $sql .=" LIMIT {$per_page} ";
	 $sql .=" OFFSET {$pagination->offset()}";
	}
	$result = $db->result_array_assoc($sql);

	if (count($result) > 0) {
	 $outPut = "";
	 $outPut .= "<table class= \"view_table $view_name $path\" >";
	 $outPut .= "<thead><tr>";
	 $header = [];
	 foreach ($result[0] as $key => $value) {
		$header[] = $key;
		$outPut .= "<th>$key</th>";
	 }
	 $outPut .= "</tr></thead><tbody>";
	 foreach ($result as $records) {
		$outPut .= "<tr>";
		foreach ($records as $key => $value) {
		 $real_key_startpos = strpos($key, "__");
		 $length = strlen($key)- strlen($real_key_startpos);
		 $real_key = substr($key, $real_key_startpos+2, $length);
		 $real_key_count = 	$real_key.'_count';
		 $$real_key_count = 0;
		  if (!empty($view_path_records_array)) {
			foreach ($view_path_records_array as $view_path_records) {
//echo '<be>$real_key is '. $real_key . ' & $view_path_records->column_name is '. $view_path_records->column_name;		
			 if ($view_path_records->column_name == $real_key) {
				$outPut .= "<td><a href=\"".HOME_URL.$view_path_records->path.'?'.$view_path_records->column_name.'='.$value."\">$value</a></td>";
			 $$real_key_count = 1;
			 }
//			 else{
//				$outPut .= "<td>$value</td>";
//			 }
			}
			if($$real_key_count ==0){
			 if(strlen($value) > 500){
				$value = substr($value, 0, strpos(wordwrap($value, 500), "\n"));
			 }
			$outPut .= "<td>$value</td>";
			}
		 } 
		 else {
			$outPut .= "<td>$value</td>";
		 }
		}
		$outPut .= "</tr>";
	 }
	 $outPut .= "</tbody></table>";
	}

	$page_string .= $outPut;

	$page_string .= '<div id="pagination" style="clear: both;">';
	if (isset($pagination) && $pagination->total_pages() > 1) {
	 if ($pagination->has_previous_page()) {
		$page_string .= "<a href=\"$path.php?&pageno=";
		$page_string .= $pagination->previous_page() . '&' . $query_string;
		$page_string .= "\"> &laquo; Previous </a> ";
	 }

	 for ($i = 1; $i <= $pagination->total_pages(); $i++) {
		if ($i == $pageno) {
		 $page_string .= " <span class=\"selected\">{$i}</span> ";
		} else {
		 $page_string .= " <a href=\"$path.php?&pageno={$i}" . '&' . $query_string;
		 $page_string .= '">' . $i . '</a>';
		}
	 }

	 if ($pagination->has_next_page()) {
		$page_string .= " <a href=\"$path.php?&pageno=";
		$page_string .= $pagination->next_page() . '&' . $query_string;
		$page_string .= "\">Next &raquo;</a> ";
	 }
	}
	$page_string .= '</div>';

	return $page_string;
 }
 
  public static function result_list_in_paragraph($sql, $view_id, $pageno = "", $per_page = "", $query_string = "") {
	$path = 'view_results';
	$view_name = 'name';
	$view_path_records_array = view_path::find_by_view_id($view_id);
	global $db;

	$count_result = $db->result_array_assoc($sql);
	$page_string = " ";

	if (!empty($per_page)) {
	 $page_string .= '<div id="noOfpages">';
	 $page_string .= '<form action="" method="POST">';
	 $page_string .= 'Show<select name="per_page">';
	 $page_string .= '<option value="3"> 3 </option>';
	 $page_string .= '<option value="5"> 5 </option>';
	 $page_string .= '<option value="10"> 10 </option>';
	 $page_string .= '<option value="20"> 20 </option>';
	 $page_string .= '<option value="50"> 50 </option>';
	 $page_string .= '</select>';
	 $page_string .= '<input type="submit" class="button" value="Per Page" >';
	 $page_string .= '</form>';
	 $page_string .= '</div>';
	 $total_count = count($count_result);
	 $pagination = new pagination($pageno, $per_page, $total_count);
	 $sql .=" LIMIT {$per_page} ";
	 $sql .=" OFFSET {$pagination->offset()}";
	}
	$result = $db->find_by_sql($sql);

	if (count($result) > 0) {
	 $outPut = "";
	  foreach ($result as $records) {
		foreach ($records as $key => $value) {
		 $real_key_startpos = strpos($key, "__");
		 $length = strlen($key)- strlen($real_key_startpos);
		 $real_key = substr($key, $real_key_startpos+2, $length);
		 $real_key_count = 	$real_key.'_count';
		 $$real_key_count = 0;
		  if (!empty($view_path_records_array)) {
			foreach ($view_path_records_array as $view_path_records) {
//echo '<be>$real_key is '. $real_key . ' & $view_path_records->column_name is '. $view_path_records->column_name;		
			 if ($view_path_records->column_name == $real_key) {
				if(strpos($view_path_records->path, "?")){
				 $outPut .= "<p><a href=\"".HOME_URL.$view_path_records->path.'&'.$view_path_records->column_name.'='.$value."\">Read more..</a></p>";
				}else{
				$outPut .= "<p><a href=\"".HOME_URL.$view_path_records->path.'?'.$view_path_records->column_name.'='.$value."\">Read more..</a></p>";
				}
			 $$real_key_count = 1;
			 }
//			 else{
//				$outPut .= "<td>$value</td>";
//			 }
			}
			if($$real_key_count ==0){
			 			 if(strlen($value) > 500){
				$value = substr($value, 0, strpos(wordwrap($value, 500), "\n"));
			 }
			$outPut .= "<p>$value</p>";
			}
		 } 
		 else {
			$outPut .= "<p>$value</p>";
		 }
		}
		}
	 	}

	$page_string .= $outPut;

	$page_string .= '<div id="pagination" style="clear: both;">';
	if (isset($pagination) && $pagination->total_pages() > 1) {
	 if ($pagination->has_previous_page()) {
		$page_string .= "<a href=\"$path.php?&pageno=";
		$page_string .= $pagination->previous_page() . '&' . $query_string;
		$page_string .= "\"> &laquo; Previous </a> ";
	 }

	 for ($i = 1; $i <= $pagination->total_pages(); $i++) {
		if ($i == $pageno) {
		 $page_string .= " <span class=\"selected\">{$i}</span> ";
		} else {
		 $page_string .= " <a href=\"$path.php?&pageno={$i}" . '&' . $query_string;
		 $page_string .= '">' . $i . '</a>';
		}
	 }

	 if ($pagination->has_next_page()) {
		$page_string .= " <a href=\"$path.php?&pageno=";
		$page_string .= $pagination->next_page() . '&' . $query_string;
		$page_string .= "\">Next &raquo;</a> ";
	 }
	}
	$page_string .= '</div>';

	return $page_string;
 }

}

//end of view class
?>



