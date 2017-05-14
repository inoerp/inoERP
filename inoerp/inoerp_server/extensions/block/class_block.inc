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
class block extends dbObject {

 public static $table_name = "block";
 public static $primary_column = "block_id";
 public static $key_column = "title";
 public static $dependent_classes = ['block_content'];
 public static $module = "extension";
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Block',
  'number' => '10010',
  'description' => 'Create & Show Contents in Block',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('block_content'),
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 10
 ];
 public $field_a = [
  "block_id",
  "title",
  "show_title_cb",
  "position",
  "weight",
  "reference_table",
  "name",
  'reference_key_value',
  "enabled_cb",
  'cached_cb',
  'restrict_to_role',
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
 public $base_encoded_array = ["visibility"];
 //variables used for showing data

 public $checkbox = [
  "show_title_cb",
  "enabled_cb",
  "rev_enabled_cb",
  'visibility_php_cb',
  'cached_cb',
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
  "content_left_top" => "content_left_top",
  "content_right_top" => "content_right_top",
  "content_left_bottom" => "content_left_bottom",
  "content_right_bottom" => "content_right_bottom",
  "footer_top" => "footer_top",
  "footer_bottom" => "footer_bottom"
 ];
 public $requiredField = [
  "title",
  "position",
  "reference_table"
 ];
 public static $visibility_option_array = [
  1 => "show",
  2 => " hide",
  3 => "custom code"
 ];
 public $initial_search = [
  "block_id",
  "title",
  "reference_table",
  "name"
 ];
 public $column = [
  "block_id",
  "title",
  "show_title_cb",
  "position",
  "weight",
  "reference_table",
  "name",
 ];
 public $pageTitle = " Block ";
 public $search = [
  '_update_path' => 'form.php?class_name=block&custom_block=1',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_view_path' => 'form.php?class_name=block&custom_block=1',
  '_show_view_path' => 1,
  '_view_action_meassge' => 'View',
 ];
 public $block_id;
 public $title;
 public $show_title_cb;
 public $position;
 public $weight;
 public $reference_table;
 public $reference_key_value;
 public $name;
 public $enabled_cb;
 public $cached_cb;
 public $restrict_to_role;
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

 public function _before_save() {
  $vis_a = explode(chr(10), base64_decode($this->visibility));
 }

 public function _after_save() {
  global $db;
  if ((!empty($_POST['content'][0])) && (!empty($this->block_id))) {
   $block_content = new block_content;
   if ((isset($_POST['content_php_cb'][0])) && (($_POST['content_php_cb'][0]) == 1)) {
    $block_content->content_php_cb = 1;
    $block_content->content = base64_encode($_POST['content'][0]);
   } else {
    $block_content->content_php_cb = 0;
    $block_content->content = $_POST['content'][0];
   }
   $block_content->block_id = $this->block_id;
   if (!empty($_POST['block_content_id'][0])) {
    $block_content->block_content_id = $_POST['block_content_id'][0];
   }
   
   try {
    $block_content->save();
    echo "<br>Block content is sucesfully saved";
   } catch (Exception $e) {
    echo "<br>Block content couldnt be saved " . $e->getMessage();
   }
  }
 }

 public function show_blockContent_byBlockId($block_id = '') {
  $block_id = !empty($block_id) ? $block_id : $this->block_id;
  $block_i = new block();
  $block_i->findBy_id($block_id);
  if ($block_i->reference_table === 'block_content') {
   $block_content_details = block_content::find_by_block_id($block_id);
   $block_content = $block_content_details->content;
  } else {
   $class_containg_block = new $block_i->reference_table;
   $method_name = $block_i->name . '_block';
   $parameters['block_id'] = $block_i->block_id;
   $block_content = call_user_func(array($class_containg_block, $method_name), $parameters);
  }

  return $block_content;
 }

 public static function show_block_content_by_BlockId($block_id) {
  $block_i = new block();
  $block_i->findBy_id($block_id);
  if ($block_i->reference_table === 'block_content') {
   $block_content_details = block_content::find_by_block_id($block_id);
   $block_content = $block_content_details->content;
  } else if (!empty($block_i->reference_table)) {
   $class_containg_block = new $block_i->reference_table;
   $method_name = $block_i->name . '_block';
   $parameters['block_id'] = $block_i->block_id;
   $block_content = call_user_func(array($class_containg_block, $method_name), $parameters);
  } else {
   $block_content = null;
  }

  return $block_content;
 }

 public static function find_all_enabled() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE enabled_cb = 1 ";
  $sql .= " ORDER BY position, weight DESC ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public function findALL_OrderBy_positionWeight() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " ORDER BY position, weight";
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 public function findBy_blockName($name) {
  $sql = " SELECT * from block where name = :name ";
  $value_a = ['name' => $name];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
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
            where block_id={$block_id} ";
  $sql = ino_perPageSql_i($sql, 1);
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

 public function findAll_AvailableBlocks() {
  if (!empty($_SESSION['user_roles'])) {
   $roles = join(',', $_SESSION['user_roles']);
  }
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE  enabled_cb = 1 AND  ( restrict_to_role IS NULL  OR restrict_to_role = '')  ";
  if (!empty($roles)) {
   $sql .= " UNION SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE  enabled_cb = 1 ";
   $sql .= " AND restrict_to_role IN ('{$roles}')  ";
   $sql .= " ORDER BY 15 ASC  ";
  } else {
   $sql .= " ORDER BY 15 ASC  ";
  }

  $result = $this->findBySql($sql);
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
   $sql = ino_perPageSql_i($sql, $per_block, $pagination->offset());
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
   $block_string .= gettext('Show') . '<select name="per_block">';
   $block_string .= '<option value="3"> 3 </option>';
   $block_string .= '<option value="5"> 5 </option>';
   $block_string .= '<option value="10"> 10 </option>';
   $block_string .= '<option value="20"> 20 </option>';
   $block_string .= '<option value="50"> 50 </option>';
   $block_string .= '</select>';
//   $block_string .= '<input type="hidden" value="' . $extension_id . '" name="block_id">';
   $block_string .= '<input type="submit" class="button" value=\"' . gettext('Per Page') . '\" >';
   $block_string .= '</form>';
   $block_string .= '</div>';
   $total_count = self::count_all();
   $pagination = new pagination($block_no, $per_block, $total_count);
   $sql = ino_perPageSql_i($sql, $per_block, $pagination->offset());
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
    $block_string .= "> &laquo; " . gettext('Previous') . " </a> ";
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
    $block_string .= "\">" . gettext('Next') . " &raquo;</a> ";
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

}

$block1 = new block();
$blk = & $block1;
//end of block class
?>
