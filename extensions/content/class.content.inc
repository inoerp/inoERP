<?php
class content extends dbObject {
 public static $table_name = "content";
 public static $content_table_name = "";
 public static $primary_column = "content_id";
 public static $key_column = "subject";
 public static $module = "extension";
//  data base variables as stored database column name
 public static $content_field_array = [];
 public $field_a = [
		 "content_type_id",
		 "content_id",
		 "parent_id",
		 "subject",
		 "terms",
		 "published_cb",
		 "weightage",
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public $initial_search = [
		 "content_type_id",
		 "content_id",
		 "subject",
		 "terms",
		 "published_cb",
		 "created_by"
 ];
 public $column = [
		 "content_type_id",
		 "content_id",
		 "subject",
		 "terms",
		 "published_cb",
		 "created_by"
 ];
 public $account = [
 ];
 public $checkbox = ["published_cb",
		 "rev_enabled_cb"
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public $base_encoded_array = [];
 public $requiredField = [
		 "subject",
		 'content_type_id'
 ];
 public $file_id_values;
 public $summary_characters;
 public $content_summary;
 public $content_id;
 public $content_type_id;
 public $parent_id;
 public $subject;
 public $content;
 public $terms;
 public $published_cb;
 public $rev_enabled_cb;
 public $weightage;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 
 private $_summary_noof_char;

 public function setProperty($property, $value) {
	if (property_exists($this, $property)) {
	 switch ($property) {
		case '_summary_noof_char':
		 if((!empty($value)) && is_numeric($value)){
		 $this->$property = $value;
		 }else{
			$this->$property = 2000;
		 }

		case '_primary_column':
		 $this->$property = !empty($value) ? $value : $this->_classname . '_id';

		default:
		 $this->$property = $value;
		 break;
	 }
	}
 }
 
 public function _after_save() {
	global $db;
	global $dbc;
	if ((!empty($this->content_type_id)) && (!empty($this->content_id))) {
	 $content_type = content_type::find_by_id($this->content_type_id);
	 $class = content::$content_table_name = 'c_' . $content_type->content_type;

	 $$class = new stdClass();
	 $extra_fields = new_content_type::find_fields_by_id($content_type->content_type_id);

	 $content_field_array = content::$content_field_array;
	 foreach ($extra_fields as $records) {
		$content_field_array[] = $records->Field;
	 }
	 $$class->content_id = $this->content_id;
	 $checkSql = " SELECT * FROM $class WHERE content_id = $this->content_id LIMIT 1";
	 $checkResult = self::find_by_sql($checkSql);
	 if (!empty($checkResult)) {
		$checkIfContentExists = true;
	 } else {
		$checkIfContentExists = false;
	 }
	 if ($checkIfContentExists) {
		//Update the existing content
		$field_stmt = '';
		foreach ($content_field_array as $key => $value) {
		 $field_stmt .= $value . ' = :' . $value . ', ';
		}
		$field_stmt = rtrim($field_stmt, ', ');
//write SQL
		$sql = " UPDATE ";
		$sql.= $class;
		$sql .= " SET ";
		$sql.= $field_stmt;
		$sql.= " WHERE content_id = :content_id ";
		$stmt = $dbc->connection->prepare(" $sql ");
		//Bind parameters
		foreach ($content_field_array as $key => $value) {
		 if (!empty($_POST[$value][0])) {
			$stmt->bindParam(":$value", $_POST[$value][0]);
		 } else {
			$stmt->bindvalue(":$value", null, PDO::PARAM_INT);
		 }
		}
		try {
		 $stmt->execute();
		 $newMsg = "Record is sucessfully saved in $class";
		} catch (PDOException $e) {
		 print "Record couldnt be saved!!: " . $e->getMessage() . "<br/>";
		}
	 } else {
		$field_colums = '';
		foreach ($content_field_array as $key => $value) {
		 $field_colums .= $value . ', ';
		}
		$field_colums = rtrim($field_colums, ', ');

		$field_values = '';
		foreach ($content_field_array as $key => $value) {
		 $field_values .= ':' . $value . ', ';
		}
		$field_values = rtrim($field_values, ', ');
//write SQL
		$sql = " INSERT INTO ";
		$sql.= $class;
		$sql.= ' ( ';
		$sql.= $field_colums;
		$sql.= ' ) ';
		$sql.= 'VALUES';
		$sql.= ' ( ';
		$sql.= $field_values;
		$sql.= ' ) ';
//		print_r($_POST);
		$stmt = $dbc->connection->prepare(" $sql ");
		//Bind parameters
		foreach ($content_field_array as $key => $value) {
		 if (!empty($_POST[$value][0])) {
			$stmt->bindParam(":$value", $_POST[$value][0]);
		 } else {
			$stmt->bindvalue(":$value", null, PDO::PARAM_INT);
		 }
		}
		$stmt->bindParam(':content_id', $$class->content_id);
		try {
		 $stmt->execute();
		 $$class->content_id = $dbc->connection->lastInsertId();
		 $newMsg = "Record is sucessfully saved in $class";
		} catch (PDOException $e) {
		 print "Record couldnt be saved!!: " . $e->getMessage() . "<br/>";
		}
	 }
	}
 }

 public static function content_find_by_id($content_type_name, $content_id) {
	global $dbc;
	$table_name = 'c_' . $content_type_name;
	$sql = "SELECT * FROM " . $table_name . " where content_id={$content_id} LIMIT 1";
	$prepare = $dbc->connection->prepare($sql);
	$prepare->execute();
	$result_array = $prepare->fetchAll(PDO::FETCH_CLASS);
	return !empty($result_array) ? array_shift($result_array) : false;
 }
 
  public static function content_summary_by_content_id($content_type_name, $content_id) {
	global $dbc;
	$table_name = 'c_' . $content_type_name;
	$sql = "SELECT SUBSTRING(content,1,2000) AS content_summary ".
					"FROM " . $table_name . " where content_id={$content_id} LIMIT 1";
	$prepare = $dbc->connection->prepare($sql);
	$prepare->execute();
	$result_array = $prepare->fetchAll(PDO::FETCH_CLASS);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_childs_of_parent_id($parent_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where parent_id='{$parent_id}'";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_summary_by_id($content_id) {
//	$selectFields = " SUBSTRING(content,1,$this->_summary_noof_char) AS content_summary , " .
//					implode(", ", $this->field_a);
	$sql = "SELECT * FROM "
					. self::$table_name . " 
            where content_id={$content_id} LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function install() {
	global $db;
	$sql = "
		 ";
	$result = $db->query($sql);
	return !empty($result) ? $result : false;
 }

 private static function content_instantiate($record) {
	$object = new self;
	foreach ($record as $attribute => $value) {
	 $object->$attribute = $value;
	}
	return $object;
 }

 public static function all_content_summary($content_no, $per_content) {
	$sql = " SELECT * FROM " . self::$table_name;
	if (!empty($per_content)) {
	 $total_count = self::count_all();
	 $pagination = new pagination($content_no, $per_content, $total_count);
	 $sql .=" LIMIT {$per_content} ";
	 $sql .=" OFFSET {$pagination->offset()}";
	}
	$result = self::find_by_sql($sql);

	foreach ($result as $records) {
	 $content_summary = self::find_summary_by_id($records->content_id);
	 echo '<div class="content_summary">';
	 echo '<div class="subject_summary">';
	 echo $content_summary->subject;
	 echo '</div>';
	 echo '<div class="content_summary">';
	 echo $content_summary->content_summary;
	 echo '</div>';
	 echo '<div class="more_content">';
	 echo '<a href="contents.php?content_id=' . $content_summary->content_id . '">';
	 echo 'Read more.. </a>';
	 echo '</div>';
	 echo '</div>';
	}
 }

//  public static function drop_column($content_name,$field_name) {
//  global $db;
//  $field_name = $db->escape_value($field_name);
//  $content_name = $db->escape_value($content_name);
//  $table_name = 'c_'.$content_name;
//          
//  $sql= "ALTER TABLE $table_name";
//  $sql .=" DROP COLUMN $field_name";
// 
//  if ($db->query($sql)) {
//   $msg = 1;
//  } else {
//   $msg = 0;
//  }
//  return $msg;
// }
// 
//   public static function drop_table($content_name) {
//  global $db;
//  $content_name = $db->escape_value($content_name);
//   
// $table_name = 'c_'.$content_name;
//  $sql =" DROP TABLE IF EXISTS $table_name";
//   if ($db->query($sql)) {
//   $msg = 1;
//  } else {
//   $msg = 0;
//  }
//  
//  if($msg ==1){
//  $content_type =content_type::find_by_content_type($content_name);
//  $result= content_type::delete($content_type->content_type_id);
//  if($result ==1){
//   $msg=11;
//  }else{
//   $msg=10;
//  }
//  }
//  
//    
//  if($msg ==11){
//  $path =path::find_by_name($content_name) ;
//  $result=path::path_delete($path->path_id);
//  if($result ==1){
//   $msg=111;
//  }else{
//   $msg=110;
//  }
//  }
//  
//  
//  return $msg;
// }

 public static function content_summary_list($content_no, $per_content, $query_string) {
	$content_string = " ";
	$sql = " SELECT * FROM " . self::$table_name;

	if (!empty($per_content)) {
	 $content_string .= '<div id="noOfcontents">';
	 $content_string .= '<form action="" method="GET">';
	 $content_string .= 'Show<select name="per_content">';
	 $content_string .= '<option value="3"> 3 </option>';
	 $content_string .= '<option value="5"> 5 </option>';
	 $content_string .= '<option value="10"> 10 </option>';
	 $content_string .= '<option value="20"> 20 </option>';
	 $content_string .= '<option value="50"> 50 </option>';
	 $content_string .= '</select>';
//   $content_string .= '<input type="hidden" value="' . $extension_id . '" name="content_id">';
	 $content_string .= '<input type="submit" class="button" value="Per Page" >';
	 $content_string .= '</form>';
	 $content_string .= '</div>';
	 $total_count = self::count_all();
	 $pagination = new pagination($content_no, $per_content, $total_count);
	 $sql .=" LIMIT {$per_content} ";
	 $sql .=" OFFSET {$pagination->offset()}";
	}
	$result = self::find_by_sql($sql);

	if (count($result) > 0) {
	 foreach ($result as $records) {
		$content_summary = self::find_summary_by_id($records->content_id);
		$content_string .= '<div class="content_summary">';
		$content_string .= '<div class="subject_summary">';
		$content_string .= $content_summary->subject;
		$content_string .= '</div>';
		$content_string .= '<div class="content_summary">';
		$content_string .= $content_summary->content_summary;
		$content_string .= '</div>';
		$content_string .= '<div class="more_content">';
		$content_string .= '<a href="contents.php?content_id=' . $content_summary->content_id . '">';
		$content_string .= 'Read more.. </a>';
		$content_string .= '</div>';
		$content_string .= '</div>';
	 }
	}

	$content_string .= '<div id="pagination" style="clear: both;">';
	if (isset($pagination) && $pagination->total_contents() > 1) {
	 if ($pagination->has_previous_content()) {
		$content_string .= "<a href=\"contents.php?contentno=";
		$content_string .= $pagination->previous_content() . '&' . $query_string;
		$content_string .= "> &laquo; Previous </a> ";
	 }

	 for ($i = 1; $i <= $pagination->total_contents(); $i++) {
		if ($i == $content_no) {
		 $content_string .= " <span class=\"selected\">{$i}</span> ";
		} else {
		 $content_string .= " <a href=\"contents.php?contentno={$i}&" . remove_querystring_var($query_string, 'contentno');
		 $content_string .= '">' . $i . '</a>';
		}
	 }

	 if ($pagination->has_next_content()) {
		$content_string .= " <a href=\"contents.php?contentno=";
		$content_string .= $pagination->next_content() . '&' . remove_querystring_var($query_string, 'contentno');
		$content_string .= "\">Next &raquo;</a> ";
	 }
	}
	$content_string .= '</div>';

	return $content_string;
 }

 public static function content_summaryList_byConteTypeCategory($content_type_id, $category_id, $pageno = 1, $per_page = 10, $query_string = "") {
	$content_string = " ";
	$sql = " SELECT content.content_id, content.content_type_id, content.subject, content.creation_date, content.created_by, ";
	$sql .= " category_reference.category_reference_id, category_reference.major_category_id, 
	        category_reference.category_id, category_reference.reference_type  ";
	$sql .= ' FROM content LEFT JOIN category_reference ON content.content_id = category_reference.reference_id ';
	$sql .= " WHERE content.content_type_id = '{$content_type_id}' ";
	$sql .= " AND category_reference.category_id = '{$category_id}' ";
	$sql .= " AND category_reference.reference_table = 'content' ";
	$sql .= " ORDER BY content.content_id DESC ";


	$count_sql = " SELECT COUNT(content.content_id) ";
	$count_sql .= ' FROM content LEFT JOIN category_reference ON content.content_id = category_reference.reference_id ';
	$count_sql .= " WHERE content.content_type_id = '{$content_type_id}' ";
	$count_sql .= " AND category_reference.category_id = '{$category_id}' ";
	$count_sql .= " AND category_reference.reference_table = 'content' ";

	$content_type_name = content_type::find_by_id($content_type_id)->content_type;


	if (!empty($per_page)) {

	 $total_count = self::count_all_by_sql($count_sql);

	 $pagination = new pagination($pageno, $per_page, $total_count);
	 $sql .=" LIMIT {$per_page} ";
	 $sql .=" OFFSET {$pagination->offset()} ";
	}

//	echo "sql is $sql ";
	$result = self::find_by_sql($sql);
//	echo '<pre>';
//	print_r($result);

	if (count($result) > 0) {
	 $content_string .='<table id="summary_list" class="top_margin10 form_line_data_table"><thead> 
						 <tr>
							<th>Summary</th>
							<th>Creation Date/Created By</th>
						 </tr>
						</thead>';

	 foreach ($result as $records) {
		$content = self::find_summary_by_id($records->content_id);
		$content_summary = self::content_summary_by_content_id($content_type_name, $records->content_id);
		$content_string .= '<tr><td colspan="2"  class="subject_summary headerBgColor">';
		$content_string .= $content->subject;
		$content_string .= '</td></tr>';
		$content_string .= '<tr><td class="content_summary">';
		$content_string .= !empty($content_summary->content_summary) ? $content_summary->content_summary : '';
		$content_string .= '<span class="more_page">';
		$content_string .= '<a href="contents.php?content_id=' . $content->content_id . '&content_type_id=' . $content_type_id . '">';
		$content_string .= 'Read more.. </a>';
		$content_string .= '</span>';
		$content_string .= '</td>';
		$content_string .= '<td class="other_info">';
		$content_string .= $records->created_by;
		$content_string .= $records->creation_date;
		$content_string .= '</td>';
		$content_string .= '</tr>';
	 }
	 $content_string .='</table>';
	}

	$content_string .= '<div id="pagination" style="clear: both;">';
	if (!empty($pagination)) {
	 $pagination_statement = $pagination->show_pagination($pagination, 'contents', $pageno, $query_string);
	}
	$content_string .= $pagination_statement;
	$content_string .= '</div>';
	$content_string .= '<div id="noOfcontents">';
	$content_string .= '<form action="" method="GET">';
	$content_string .= 'Show<select name="per_page">';
	$content_string .= '<option value="3"> 3 </option>';
	$content_string .= '<option value="5"> 5 </option>';
	$content_string .= '<option value="10"> 10 </option>';
	$content_string .= '<option value="20"> 20 </option>';
	$content_string .= '<option value="50"> 50 </option>';
	$content_string .= '</select>';
//   $content_string .= '<input type="hidden" value="' . $extension_id . '" name="content_id">';
	$content_string .= '<input type="submit" class="button" value="Per Page" >';
	$content_string .= '</form>';
	$content_string .= '</div>';

	return $content_string;
 }

 public static function content_summary_by_id($content_id) {
	$content_summary = self::find_summary_by_id($content_id);
	echo '<div class="content_summary">';
	echo '<div class="subject_summary">';
	echo $content_summary->subject;
	echo '</div>';
	echo '<div class="content_summary">';
	echo $content_summary->content_summary;
	echo '</div>';
	echo '<div class="more_content">';
	echo '<a href="contents.php?content_id="' . $content_summary->content_id . '>';
	echo 'Read more.. </a>';
	echo '</div>';
	echo '</div>';
 }

 public static function content_by_id($content_type_name, $content_id) {
	//creation of extra content
	$content_statemnt = "";
	$content_type = content_type::find_by_content_type($content_type_name);
	$extra_fields = new_content_type::find_fields_by_id($content_type->content_type_id);
	$content_field_array = self::$content_field_array;
	foreach ($extra_fields as $records) {
	 $content_field_array[] = $records->Field;
	}
	$extra_content = self::content_find_by_id($content_type_name, $content_id);
	foreach ($content_field_array as $key => $value) {
	 if ($value != 'content_id') {
		$content_statemnt .= nl2br($extra_content->$value);
	 }
	}
	return $content_statemnt;
 }

}

//end of content class
?>



