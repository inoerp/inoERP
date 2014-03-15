<?php

class block_content extends dbObject{

 protected static $table_name2 = "block_content";
//  data base variables as stored database column name
 public static $field_array = [
     "block_id",
     "info",
     "content",
     "created_by",
     "creation_date",
     "last_update_by",
     "last_update_date"
 ];
//variables used for showing data

 public static $checkbox_array = [
 ];
 public static $column_array = [];
 public static $requiredField_array = [
     "info",
     "content"
 ];
 public static $primary_column = "block_id";
 public $block_id;
 public $info;
 public $content;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function __set($name, $value) {
  $this->$name = $value;
 }

public static function find_summary_by_id($block_id) {
  $selectFields = ' SUBSTRING(content,1,2000) AS content_summary , ' .
          implode(", ", self::$field_array);
  $sql = "SELECT " . $selectFields . " FROM "
          . self::$table_name2 . " 
            where block_id={$block_id} LIMIT 1";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function all_block_summary($block_no, $per_block) {
  $sql = " SELECT * FROM " . self::$table_name2;
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
  $sql = " SELECT * FROM " . self::$table_name2;
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



