<?php

class block extends dbObject {

 protected static $table_name = "block";
//  data base variables as stored database column name
 public static $field_array = [
		 "block_id",
		 "title",
		 "show_title_cb",
		 "position",
		 "weight",
		 "reference_table",
		 "name",
		 "enabled_cb",
		 "visibility",
		 "visibility_option",
		 'visibility_php_cb',
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public static $base_encoded_array = ["visibility"];
 //variables used for showing data

 public static $checkbox_array = [
		 "show_title_cb",
		 "enabled_cb",
		 "rev_enabled_cb",
		 'visibility_php_cb'
 ];
 public static $position_array = [
		 "header_top" => 'header_top',
		 "header_bottom" => 'header_bottom',
		 "navinagtion_top" => "navinagtion_top",
		 "navinagtion_bottom" => "navinagtion_bottom",
		 "content_top" => "content_top",
		 "content_bottom" => "content_bottom",
		 "content_left" => "content_left",
		 "content_right_right" => "content_right_right",
		 "footer_top" => "footer_top",
		 "footer_bottom" => "footer_bottom"
 ];
 public static $column_array = [];
 public static $requiredField_array = [
		 "title",
		 "position",
		 "reference_table"
 ];
 public static $visibility_option_array = [
		 1 => "show",
		 2 =>" hide",
		 3 => "custom code" 
 ];
 public static $primary_column = "block_id";
 public $block_id;
 public $title;
 public $show_title_cb;
 public $position;
 public $weight;
 public $reference_table;
 public $name;
 public $enabled_cb;
 public $rev_enabled_cb;
 public $visibility_option;
 public $visibility;
 public $visibility_php_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $info;
 public $content;
 public $content_php_cb;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public function _after_save() {

	global $db;
	if ((!empty($_POST['content'][0])) && (!empty($this->block_id))) {
	 $block_content = new block_content;
	 if ((isset($_POST['content_php_cb'][0])) && (($_POST['content_php_cb'][0]) == 1)) {
		$block_content->content_php_cb = 1;
		$block_content->content = base64_encode($_POST['content'][0]);
	 } else {
		$block_content->content_php_cb = NULL;
		$block_content->content = $_POST['content'][0];
	 }
	 $block_content->block_id = $this->block_id;
	 if (!empty($_POST['block_content_id'][0])) {
		$block_content->block_content_id = $_POST['block_content_id'][0];
	 }
	 $time = time();
	 $block_content->creation_date = strftime("%d-%m-%y %H:%M:%S", $time);
	 $block_content->created_by = $_SESSION['username'];
	 $block_content->last_update_date = $block_content->creation_date;
	 $block_content->last_update_by = $block_content->created_by;
	 $save = $block_content->save();
	 if ($save) {
		$return = 1;
		echo "<br>Block content sucesfully saved";
	 } else {
		echo "<br>Block content couldnt be saved";
		$return = 0;
	 }

	 return $return;
	}
 }

 public static function find_all_enabled() {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE enabled_cb = 1 ";
	$sql .= " ORDER BY position, weight DESC ";
	$result = self::find_by_sql($sql);
	return $result;
 }

 Public static function block_structure() {
	$option_header = option_header::find_by_name('LOCATOR_STRUCTURE');
	$block_class = option_line::find_by_option_id($option_header->option_id);
	return $block_class;
 }

 public static function find_summary_by_id($block_id) {
	$selectFields = ' SUBSTRING(content,1,2000) AS content_summary , ' .
					implode(", ", self::$field_array);
	$sql = "SELECT " . $selectFields . " FROM "
					. self::$table_name . " 
            where block_id={$block_id} LIMIT 1";
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

 Public static function assign_blocks() {
	$position_array_values = array();
	$all_block = array();
	$header_top = "";
	$header_bottom = "";
	$navinagtion_top = "";
	$navinagtion_bottom = "";
	$content_top = "";
	$content_bottom = "";
	$content_left = "";
	$content_right_right = "";
	$footer_top = "";
	$footer_bottom = "";

	$all_active_blocks = self::find_all_enabled();
	$block_count = 0;
	foreach ($all_active_blocks as $records) {
//	 echo '<pre>';
//	 print_r($records);
	 $block_count++;
	 $class_name = $records->reference_table;

	 if (($class_name == 'path') && (!empty($records->name))) {
		$function_name = $records->reference_table . '_' . $records->name . '_block';
		$block_content = $class_name::$function_name();
	 } else {
		if (count(block_content::find_by_id($records->block_id)) > 0) {
		 $custom_block = block_content::find_by_block_id($records->block_id);
		 if (!empty($custom_block)) {
			if (($custom_block->content_php_cb) == 1) {
			 $block_content_deocded = base64_decode($custom_block->content);
			 $block_content = ino_eval($block_content_deocded);
			} else {
			 $block_content = $custom_block->content;
			}
		 }
		}
	 }
	 if ($records->show_title_cb == 1) {
		$block_title = $records->title;
	 } else {
		$block_title = "";
	 }

	 $block_visibility_option = $records->visibility_option;
	 $block_visibility = $records->visibility;

	 foreach (self::$position_array as $key => $value) {
		if ($records->position == $value) {
		 $position_array_values[] = [
				 'position' => $value,
				 'title' => $block_title,
				 'content' => $block_content,
				 'visibility_option' => $block_visibility_option,
				 'block_visibility' => $block_visibility,
				 'reference_table' => $class_name
		 ];
		}
	 }
	}

	return $position_array_values;
 }

 public static function all_block_summary($block_no, $per_block) {
	$sql = " SELECT * FROM " . self::$table_name;
	if (!empty($per_block)) {
	 $total_count = self::count_all();
	 $pagination = new pagination($block_no, $per_block, $total_count);
	 $sql .=" LIMIT {$per_block} ";
	 $sql .=" OFFSET {$pagination->offset()}";
	}
	$result = self::find_by_sql($sql);

	foreach ($result as $records) {
	 $block_summary = self::find_summary_by_id($records->block_id);
	 echo '<div class="block_summary">';
	 echo '<div class="subject_summary">';
	 echo $block_summary->subject;
	 echo '</div>';
	 echo '<div class="content_summary">';
	 echo $block_summary->content_summary;
	 echo '</div>';
	 echo '<div class="more_block">';
	 echo '<a href="blocks.php?block_id=' . $block_summary->block_id . '">';
	 echo 'Read more.. </a>';
	 echo '</div>';
	 echo '</div>';
	}
 }

 public static function block_summary_list($block_no, $per_block, $query_string) {
	$block_string = " ";
	$sql = " SELECT * FROM " . self::$table_name;
	if (!empty($per_block)) {
	 $block_string .= '<div id="noOfblocks">';
	 $block_string .= '<form action="" method="GET">';
	 $block_string .= 'Show<select name="per_block">';
	 $block_string .= '<option value="3"> 3 </option>';
	 $block_string .= '<option value="5"> 5 </option>';
	 $block_string .= '<option value="10"> 10 </option>';
	 $block_string .= '<option value="20"> 20 </option>';
	 $block_string .= '<option value="50"> 50 </option>';
	 $block_string .= '</select>';
//   $block_string .= '<input type="hidden" value="' . $extension_id . '" name="block_id">';
	 $block_string .= '<input type="submit" class="button" value="Per Page" >';
	 $block_string .= '</form>';
	 $block_string .= '</div>';
	 $total_count = self::count_all();
	 $pagination = new pagination($block_no, $per_block, $total_count);
	 $sql .=" LIMIT {$per_block} ";
	 $sql .=" OFFSET {$pagination->offset()}";
	}
	$result = self::find_by_sql($sql);

	if (count($result) > 0) {
	 foreach ($result as $records) {
		$block_summary = self::find_summary_by_id($records->block_id);
		$block_string .= '<div class="block_summary">';
		$block_string .= '<div class="subject_summary">';
		$block_string .= $block_summary->subject;
		$block_string .= '</div>';
		$block_string .= '<div class="content_summary">';
		$block_string .= $block_summary->content_summary;
		$block_string .= '</div>';
		$block_string .= '<div class="more_block">';
		$block_string .= '<a href="blocks.php?block_id=' . $block_summary->block_id . '">';
		$block_string .= 'Read more.. </a>';
		$block_string .= '</div>';
		$block_string .= '</div>';
	 }
	}

	$block_string .= '<div id="pagination" style="clear: both;">';
	if (isset($pagination) && $pagination->total_blocks() > 1) {
	 if ($pagination->has_previous_block()) {
		$block_string .= "<a href=\"blocks.php?blockno=";
		$block_string .= $pagination->previous_block() . '&' . $query_string;
		$block_string .= "> &laquo; Previous </a> ";
	 }

	 for ($i = 1; $i <= $pagination->total_blocks(); $i++) {
		if ($i == $block_no) {
		 $block_string .= " <span class=\"selected\">{$i}</span> ";
		} else {
		 $block_string .= " <a href=\"blocks.php?blockno={$i}&" . remove_querystring_var($query_string, 'blockno');
		 $block_string .= '">' . $i . '</a>';
		}
	 }

	 if ($pagination->has_next_block()) {
		$block_string .= " <a href=\"blocks.php?blockno=";
		$block_string .= $pagination->next_block() . '&' . remove_querystring_var($query_string, 'blockno');
		$block_string .= "\">Next &raquo;</a> ";
	 }
	}
	$block_string .= '</div>';

	return $block_string;
 }

 public static function block_summary_by_id($block_id) {
	$block_summary = self::find_summary_by_id($block_id);
	echo '<div class="block_summary">';
	echo '<div class="subject_summary">';
	echo $block_summary->subject;
	echo '</div>';
	echo '<div class="content_summary">';
	echo $block_summary->content_summary;
	echo '</div>';
	echo '<div class="more_block">';
	echo '<a href="blocks.php?block_id="' . $block_summary->block_id . '>';
	echo 'Read more.. </a>';
	echo '</div>';
	echo '</div>';
 }

 public static function block_block() {
	echo '<table class="normal"><thead><tr>';
	foreach (self::$field_array as $key => $value) {
	 echo '<th>' . $value . '</th>';
	}
	echo '</tr></thead><tbody>';

	$block = self::find_all();
//    echo '<pre>';
//    print_r($block);
//    echo '<pre>';
	foreach ($block as $record) {
	 echo '<tr>';
	 foreach (self::$field_array as $key => $value) {
		echo '<td>' . $record->$value . '</td>';
	 }
	 echo '</tr>';
	}
	echo ' </tbody> </table>';
 }

}

//end of block class
?>



