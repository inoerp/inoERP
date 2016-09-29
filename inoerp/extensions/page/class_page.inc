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
 * 
 *
 */
class page extends dbObject {

 public static $table_name = "page";
 public static $primary_column = "page_id";
 public static $key_column = "subject";
 public static $module = "extension";
  public static $system_info = [
  'name' => 'Page',
  'number' => '10017',
  'description' => 'Simple Content Page',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 17
 ];
 public $field_a = [
		 "page_id",
		 "parent_id",
		 "subject",
		 "content",
		 'content_php_cb',
		 "terms",
		 "published_cb",
		 'show_in_frontpage_cb',
		 "weightage",
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
//  data base variables as stored database column name
 public $checkbox = ["published_cb",
		 "rev_enabled_cb",
		 'show_in_frontpage_cb',
		 'content_php_cb'
 ];
 public $base_encoded_array = [
		"content"
 ];
 public $initial_search = [
		 "page_id",
		 "parent_id",
		 "subject",
		 "content",
		 "created_by",
 ];
//variables used for showing data
 public $column = [
		 "page_id",
		 "parent_id",
		 "subject",
		 "content",
		 'content_php_cb',
		 "terms",
		 "published_cb",
 ];
 public $requiredField = ["content"
 ];
 public $pageTitle = " Content - Create & View different contents ";
 public $search = [
		  '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_view_path' => 'form.php?class_name=page_view',
		 '_show_view_path' => 1,
		 '_view_action_meassge' => 'Read',
 ];
 public $file_id_values;
 public $summary_characters;
 public $content_summary;
 public $page_id;
 public $parent_id;
 public $subject;
 public $content;
 public $content_php_cb;
 public $terms;
 public $published_cb;
 public $show_in_frontpage_cb;
 public $rev_enabled_cb;
 public $weightage;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 Public static function page_structure() {
	$option_header = option_header::find_by_name('LOCATOR_STRUCTURE');
	$page_class = option_line::find_by_option_id($option_header->option_id);
	return $page_class;
 }

 public static function all_page_summary($page_no, $per_page) {
	$sql = " SELECT * FROM " . self::$table_name;
	if (!empty($per_page)) {
	 $total_count = self::count_all();
	 $pagination = new pagination($page_no, $per_page, $total_count);
   $sql = ino_perPageSql_i($sql, $per_page, $pagination->offset());
	}
	$result = self::find_by_sql($sql);

	foreach ($result as $records) {
	 $page_summary = self::find_summary_by_id($records->page_id);
	 echo '<div class="page_summary">';
	 echo '<div class="subject_summary">';
	 echo $page_summary->subject;
	 echo '</div>';
	 echo '<div class="content_summary">';
	 echo $page_summary->content_summary;
	 echo '</div>';
	 echo '<div class="more_page">';
	 echo '<a href="pages.php?page_id=' . $page_summary->page_id . '">';
	 echo 'Read more.. </a>';
	 echo '</div>';
	 echo '</div>';
	}
 }

 public static function find_summary_by_id($page_id, $string_length = 2000) {
	$selectFields = " SUBSTRING(content, 1, $string_length) AS content_summary , " .
					implode(", ", self::$field_array);
	$sql = "SELECT " . $selectFields . " FROM "
					. self::$table_name . "
            where page_id={$page_id} LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function front_page_summary($numerOfartciles = 6, $stringlength = 500) {
	$page_string = " ";
	$sql = " SELECT * FROM " . self::$table_name;
	$sql .=" WHERE published_cb = 1 AND  show_in_frontpage_cb = 1";
	$sql .=" ORDER BY creation_date DESC";
	$sql .= " LIMIT {$numerOfartciles} ";
	$result = self::find_by_sql($sql);

	if (count($result) > 0) {
	 $page_string .= '<ul class="summary_list">';
	 foreach ($result as $records) {
		$page_summary = self::find_by_id($records->page_id);
		$page_string .= '<li class="front_page_summary">';
		$page_string .= '<span class="headerBgColor subject_summary">';
		$page_string .= $page_summary->subject;
		$page_string .= '</span>';
		$page_string .= '<span class="content_summary">';
		if ($page_summary->content_php_cb) {
		 $page_string .= substr(ino_eval($page_summary->content), 1, $stringlength);
		} else {
		 $page_string .= substr($page_summary->content, 1, $stringlength);
		}
		$page_string .= '</span>';
		$page_string .= '<span class="more_page">';
		$page_string .= '<a href="' . HOME_URL . 'extensions/page/pages.php?page_id=' . $page_summary->page_id . '">';
		$page_string .= 'Read more.. </a>';
		$page_string .= '</span>';
		$page_string .= '</li>';
	 }
	 $page_string .= '</ul>';
	}

	return $page_string;
 }

 public static function page_summary_list($page_no, $per_page, $query_string) {
	$page_string = " ";
	$sql = " SELECT * FROM " . self::$table_name;
	if (!empty($per_page)) {
	 $page_string .= '<div id="noOfpages">';
	 $page_string .= '<form action="" method="POST">';
	 $page_string .= gettext('Show') . '<select name="per_page">';
	 $page_string .= '<option value="3"> 3 </option>';
	 $page_string .= '<option value="5"> 5 </option>';
	 $page_string .= '<option value="10"> 10 </option>';
	 $page_string .= '<option value="20"> 20 </option>';
	 $page_string .= '<option value="50"> 50 </option>';
	 $page_string .= '</select>';
//   $page_string .= '<input type="hidden" value="' . $extension_id . '" name="page_id">';
	 $page_string .= '<input type="submit" class="button" value=\"' . gettext('Per Page') . '\" >';
	 $page_string .= '</form>';
	 $page_string .= '</div>';
	 $total_count = self::count_all();
	 $pagination = new pagination($page_no, $per_page, $total_count);
	 $sql .=" LIMIT {$per_page} ";
	 $sql .=" OFFSET {$pagination->offset()}";
	}
	$result = self::find_by_sql($sql);

	if (count($result) > 0) {
	 foreach ($result as $records) {
		$page_summary = self::find_summary_by_id($records->page_id);
		$page_string .= '<div class="page_summary">';
		$page_string .= '<div class="subject_summary">';
		$page_string .= $page_summary->subject;
		$page_string .= '</div>';
		$page_string .= '<div class="content_summary">';
		$page_string .= ino_eval($page_summary->content_summary);
		$page_string .= '</div>';
		$page_string .= '<div class="more_page">';
		$page_string .= '<a href="pages.php?page_id=' . $page_summary->page_id . '">';
		$page_string .= 'Read more.. </a>';
		$page_string .= '</div>';
		$page_string .= '</div>';
	 }
	}

	$page_string .= '<div id="pagination" style="clear: both;">';
	if (isset($pagination) && $pagination->total_pages() > 1) {
	 if ($pagination->has_previous_page()) {
		$page_string .= "<a href=\"pages.php?pageno=";
		$page_string .= $pagination->previous_page() . '&' . $query_string;
		$page_string .= "> &laquo; " . gettext('Previous') . " </a> ";
	 }

	 for ($i = 1; $i <= $pagination->total_pages(); $i++) {
		if ($i == $page_no) {
		 $page_string .= " <span class=\"selected\">{$i}</span> ";
		} else {
		 $page_string .= " <a href=\"pages.php?pageno={$i}&" . remove_querystring_var($query_string, 'pageno');
		 $page_string .= '">' . $i . '</a>';
		}
	 }

	 if ($pagination->has_next_page()) {
		$page_string .= " <a href=\"pages.php?pageno=";
		$page_string .= $pagination->next_page() . '&' . remove_querystring_var($query_string, 'pageno');
		$page_string .= "\">" . gettext('Next') . " &raquo;</a> ";
	 }
	}
	$page_string .= '</div>';

	return $page_string;
 }

 public static function page_summary_by_id($page_id) {
	$page_summary = self::find_summary_by_id($page_id);
	echo '<div class="page_summary">';
	echo '<div class="subject_summary">';
	echo $page_summary->subject;
	echo '</div>';
	echo '<div class="content_summary">';
	echo $page_summary->content_summary;
	echo '</div>';
	echo '<div class="more_page">';
	echo '<a href="pages.php?page_id="' . $page_summary->page_id . '>';
	echo 'Read more.. </a>';
	echo '</div>';
	echo '</div>';
 }

 public static function page_page() {
	echo '<table class="normal"><thead><tr>';
	foreach (self::$field_array as $key => $value) {
	 echo '<th>' . $value . '</th>';
	}
	echo '</tr></thead><tbody>';

	$page = self::find_all();
//    echo '<pre>';
//    print_r($page);
//    echo '<pre>';
	foreach ($page as $record) {
	 echo '<tr>';
	 foreach (self::$field_array as $key => $value) {
		echo '<td>' . $record->$value . '</td>';
	 }
	 echo '</tr>';
	}
	echo ' </tbody> </table>';
 }

}

//end of page class
?>
