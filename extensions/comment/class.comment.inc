<?php

class comment extends dbObject {

 protected static $table_name = "comment";
 public static $primary_column = "comment_id";
 public static $key_column = "comment";
 public static $module = "extension";
 public $field_a = [
		 "comment_id",
		 "reference_table",
		 "reference_id",
		 "subject",
		 "comment",
		 "terms",
		 "published_cb",
		 "weightage",
		 "comment_by",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
//variables used for showing data

 public $checkbox = ["published_cb"];
 public $requiredField = [
		 "reference_table",
		 "reference_id",
		 "comment"
 ];
 public $file_id_values;
 public $summary_characters;
 public $comment_summary;
 public $comment_id;
 public $reference_table;
 public $reference_id;
 public $subject;
 public $comment;
 public $terms;
 public $published;
 public $published_cb;
 public $weightage;
 public $comment_by;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function find_by_reference_table_and_id($reference_table, $reference_id) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" WHERE reference_table = '{$reference_table}'
       AND reference_id = '{$reference_id}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function count_by_reference_table_and_id($reference_table, $reference_id) {
	global $db;
	$sql = "SELECT COUNT(*) FROM " .
					self::$table_name .
					" WHERE reference_table = '{$reference_table}'
       AND reference_id = '{$reference_id}' ";
	$result = self::count_all_by_sql($sql);
	return $result;
 }

 public static function find_summary_by_id($comment_id) {
	$selectFields = ' SUBSTRING(content,1,2000) AS content_summary , ' .
					implode(", ", self::$field_array);
	$sql = "SELECT " . $selectFields . " FROM "
					. self::$table_name . " 
            where comment_id={$comment_id} LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function all_comment_summary($comment_no, $per_comment) {
	$sql = " SELECT * FROM " . self::$table_name;
	if (!empty($per_comment)) {
	 $total_count = self::count_all();
	 $pagination = new pagination($comment_no, $per_comment, $total_count);
	 $sql .=" LIMIT {$per_comment} ";
	 $sql .=" OFFSET {$pagination->offset()}";
	}
	$result = self::find_by_sql($sql);

	foreach ($result as $records) {
	 $comment_summary = self::find_summary_by_id($records->comment_id);
	 echo '<div class="comment_summary">';
	 echo '<div class="subject_summary">';
	 echo $comment_summary->subject;
	 echo '</div>';
	 echo '<div class="content_summary">';
	 echo $comment_summary->content_summary;
	 echo '</div>';
	 echo '<div class="more_comment">';
	 echo '<a href="comments.php?comment_id=' . $comment_summary->comment_id . '">';
	 echo 'Read more.. </a>';
	 echo '</div>';
	 echo '</div>';
	}
 }

 public static function comment_summary_by_id($comment_id) {
	$comment_summary = self::find_summary_by_id($comment_id);
	echo '<div class="comment_summary">';
	echo '<div class="subject_summary">';
	echo $comment_summary->subject;
	echo '</div>';
	echo '<div class="content_summary">';
	echo $comment_summary->content_summary;
	echo '</div>';
	echo '<div class="more_comment">';
	echo '<a href="comments.php?comment_id="' . $comment_summary->comment_id . '>';
	echo 'Read more.. </a>';
	echo '</div>';
	echo '</div>';
 }

 public static function comment_list($reference_table, $reference_id, $per_page, $pageno, $query_string, $extension_id) {

	$comment_string = " ";
	$sql = "SELECT * FROM " .
					self::$table_name .
					" WHERE reference_table = '{$reference_table}'
           AND reference_id = '{$reference_id}' ";
	if (!empty($per_page)) {
	 $comment_string .= '<div id="noOfpages">';
	 $comment_string .= '<form action="" method="GET">';
	 $comment_string .= 'Show<select name="per_page">';
	 $comment_string .= '<option value="3"> 3 </option>';
	 $comment_string .= '<option value="5"> 5 </option>';
	 $comment_string .= '<option value="10"> 10 </option>';
	 $comment_string .= '<option value="20"> 20 </option>';
	 $comment_string .= '<option value="50"> 50 </option>';
	 $comment_string .= '</select>';
	 $comment_string .= '<input type="hidden" value="' . $extension_id . '" name="page_id">';
	 $comment_string .= '<input type="submit" class="button" value="Per Page" >';
	 $comment_string .= '</form>';
	 $comment_string .= '</div>';
	 $total_count = self::count_by_reference_table_and_id($reference_table, $reference_id);
	 $pagination = new pagination($pageno, $per_page, $total_count);
	 $sql .=" LIMIT {$per_page} ";
	 $sql .=" OFFSET {$pagination->offset()}";
	}
	$result = self::find_by_sql($sql);

	if (count($result) > 0) {
	 foreach ($result as $records) {
		$allow_content_update = false;
		if ((!empty($_SESSION['username'])) && ($records->created_by == $_SESSION['username'])) {
		 $allow_content_update = true;
		} elseif ((!empty($_SESSION['user_roles'])) && (in_array('admin', $_SESSION['user_roles']))) {
		 $allow_content_update = true;
		}
		$comment_file = file::find_by_reference_table_and_id('comment', $records->comment_id);
		$comment_string .= '<ul class="commentRecord">';
		$comment_string .= '<li class="header_li">';
		$comment_string .= '<ul class="header">';
		$comment_string .= '<li class="comment_by">' . $records->comment_by . '</li>';
		$comment_string .= '<li class="created_by">' . $records->created_by . '</li>';
		$comment_string .= '<li class="creation_date">' . $records->creation_date . '</li>';
		if ($allow_content_update) {
		 $comment_string .= '<li class="delete_update"><button name="delete_button" class="delete_button" value="' .
						 $records->comment_id . '" >Delete</button>';
		 $comment_string .= '<button name="update_button" class="update_button" value="' .
						 $records->comment_id . '" >Update</button> </li>';
		}
		$comment_string .= '</ul>';
		$comment_string .= '</li>';
		$comment_string .= '<li class="line_li">';
		$comment_string .= '<ul class="line">';
		$comment_string .= '<li class="subject">' . $records->subject . '</li>';
		$comment_string .= '<li class="comment">' . nl2br($records->comment) . '</li>';
		if (count($comment_file) > 0) {
		 foreach ($comment_file as $file_record) {
			$comment_string .= '<li><a href=' . HOME_URL . $file_record->file_path . $file_record->file_name . '>' . $file_record->file_name . '</a></li>';
		 }
		}
		$comment_string .= '</ul>';
		$comment_string .= '</li>';


		$comment_string .= '</ul>';
	 }
	}


	$comment_string .= '<div id="pagination" style="clear: both;">';
	if (isset($pagination) && $pagination->total_pages() > 1) {
	 if ($pagination->has_previous_page()) {
		$comment_string .= "<a href=\"pages.php?page_id=$extension_id&pageno=";
		$comment_string .= $pagination->previous_page() . '&' . $query_string;
		$comment_string .= "> &laquo; Previous </a> ";
	 }

	 for ($i = 1; $i <= $pagination->total_pages(); $i++) {
		if ($i == $pageno) {
		 $comment_string .= " <span class=\"selected\">{$i}</span> ";
		} else {
		 $comment_string .= " <a href=\"pages.php?page_id=$extension_id&pageno={$i}&" . remove_querystring_var($query_string, 'pageno');
		 $comment_string .= '">' . $i . '</a>';
		}
	 }

	 if ($pagination->has_next_page()) {
		$comment_string .= " <a href=\"pages.php?page_id=$extension_id&pageno=";
		$comment_string .= $pagination->next_page() . '&' . remove_querystring_var($query_string, 'pageno');
		$comment_string .= "\">Next &raquo;</a> ";
	 }
	}
	$comment_string .= '</div>';


	return $comment_string;
 }

}

//end of comment class
?>



