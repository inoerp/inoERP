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
/* Privillages
 * 2. Read
 * 3. Write
 * 4. Update Own
 * 5. Update Any
 * 9. Admin
 */

class comment extends dbObject {

 public static $table_name = "comment";
 public static $primary_column = "comment_id";
 public static $key_column = "comment";
 public static $module = "extension";
 public static $system_info = [
  'name' => 'Comment',
  'number' => '10012',
  'description' => 'Comments for all type of content types and documents',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 12
 ];
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
 public $initial_search = [
  "comment_id",
  "reference_table",
  "reference_id",
  "subject",
  "comment",
 ];
 public $column = [
  "comment_id",
  "reference_table",
  "reference_id",
  "subject",
  "published_cb",
  "weightage",
  "comment_by",
 ];
 public $fields_inForm_notInDataBase = [
  'multi_action_class_pc',
  'multi_action_class_pc_value',
  'action',
  'comment_user_name',
  'subscribe_cb'
 ];
 public $pageTitle = " Comment - Create & View different Comments ";
 public $search = [
  '_view_path' => 'form.php?class_name=',
  '_show_view_path' => 1,
  '_view_action_meassge' => 'Read',
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
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 public $action;
 public $description = "User Comments";
 public $subject_noof_char = 80;
 public $subscribe_cb;

 public function _before_save() {
  if (empty(trim($this->comment))) {
   echo '<br>No comment to post';
   return -90;
  }
  if (empty($this->subject)) {
   $this->subject = htmlentities(substr($this->comment, 0, 20));
  }else{
   $this->subject = htmlentities($this->subject);
  }
  
  if (!empty($this->comment)) {
   $this->comment = htmlentities($this->comment);
  }
 }

 public function _after_save() {
  //subscribe
  if (!empty($this->subscribe_cb)) {
   $this->_create_subscription();
  }

  $this->_send_subsctiber_msg();
 }

 private function _send_subsctiber_msg() {
  $es = new extn_subscribe();
  $es->reference_key_name = $this->reference_table;
  $es->reference_key_value = $this->reference_id;
  $topic_link = HOME_URL;

  switch ($this->reference_table) {
   default:
    $topic_link .= 'content.php?content_id=' . $this->reference_id;
    break;
  }
  $es->send_message($topic_link);
 }

 private function _enable_block($block_name, $block_title) {
  $block = new block();
  $block_i = $block->findBy_blockName($block_name);
  if (!empty($block_i->block_id)) {
   return;
  }
  $block->block_id = null;
  $block->name = $block_name;
  $block->title = $block_title;
  $block->reference_table = 'comment';
  $block->audit_trial();
  $block->save();
  return;
 }

 private function _disable_block($block_name) {
  $block = new block();
  $block_i = $block->findBy_blockName($block_name);
  if (!empty($block_i->block_id)) {
   return;
  }
  $block->block_id = $block_i->block_id;
  $block->enabled_cb = 0;
  $block->audit_trial();
  $block->save();
  return;
 }

 public function _enable() {
  //cretae the block
  $this->_enable_block('comment_recent_comments', 'Recent Comments');
 }

 public function _disable() {
  //cretae the block
  $this->_disable_block('comment_recent_comments');
 }

 private function _create_subscription() {
  global $ino_user;
  $sub_i = new extn_subscribe();
  $sub_i->reference_key_name = $this->reference_table;
  $sub_i->reference_key_value = $this->reference_id;
  $sub_i->ino_user_id = $ino_user->ino_user_id;
  $sub_i->username = $ino_user->username;
  $sub_i->user_email = $ino_user->email;
  try {
   $sub_i->save();
  } catch (Exception $e) {
//   echo $e->getMessage();
  }
 }

 public function content_comment_with_reference($numbers = 10, $start_from = '') {
  $sql = " SELECT comment.comment_id, comment.subject,
	         content.content_id, content.content_type_id,
           comment.reference_table, comment.reference_id, comment.comment ,comment.published_cb, comment.creation_date,
          IFNULL(user.username, comment.comment_by) as username
					FROM comment LEFT JOIN ino_user as user ON comment.created_by = user.ino_user_id ,
            content 
					WHERE comment.reference_table = 'content'
          AND content.content_id = comment.reference_id 
					AND comment.subject IS NOT NULL AND comment.subject !='' 
          ";

  $sql .=" ORDER BY comment.comment_id DESC, comment.weightage DESC ";
  if (!empty($numbers) && !empty($start_from)) {
   $sql .= " LIMIT {$start_from} , :lmt_no_of_records  ";
   $value_a = ['lmt_no_of_records' => $numbers];
   $result = $this->findBySql($sql, $value_a);
  } else {
   $result = $this->findBySql($sql);
  }
//pa($result);echo $sql;
  return !empty($result) ? $result : false;
 }

 public function comment_recent_comments_block($param) {
  $numbers = empty($param->numbers) ? 7 : $param->numbers;
  $start_from = empty($param->start_from) ? 0 : $param->start_from;
  $this->subject_noof_char = empty($this->subject_noof_char) ? 200 : $this->subject_noof_char;
  $result = $this->content_comment_with_reference($numbers, $start_from);
  $comment_string = '';
  if (count($result) > 0) {
   $comment_string .= '<ul class="documentation_list comment">';
   $comment_string .= '<li class="all_comments"><span class="badge"><a href="' . HOME_URL . 'content.php?content_type=comment">'
    . 'All Comments <i class="fa fa-comments-o"></i></a></span></li>';
   if (empty($result)) {
    return;
   }
   foreach ($result as $records_c => $records) {
    if ($records_c >= $numbers) {
     break;
    }
    $comment_string .= '<li class="comment_subject">';
    $comment_string .= '<a href="' . HOME_URL . 'content.php?mode=2&' . 'content_id=' . $records->content_id .
     '&content_type_id=' . $records->content_type_id . '#comment_id_' . $records->comment_id . '">';
    if (!empty($records->subject)) {
     $comment_string .= substr(strip_tags($records->subject), 0, $this->subject_noof_char);
    } else {
     $comment_string .= substr(strip_tags($records->comment), 0, $this->subject_noof_char);
    }
    $comment_string .= '</a>';
    $comment_string .= '</li>';
   }
   $comment_string .= '</ul>';
  }

  return $comment_string;
 }

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

 public function view_page() {
  $pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
  $per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 20;
  $this->subject_noof_char = empty($this->subject_noof_char) ? 100 : $this->subject_noof_char;
  $query_string = !empty($_SERVER['QUERY_STRING']) ? htmlentities($_SERVER['QUERY_STRING']) : '';
  $comment_result = $this->content_comment_with_reference();
  $total_count_c = count($comment_result);
  $pagination_c = new pagination($pageno, $per_page, $total_count_c);
  $pagination_c->setProperty('_path', 'content');
  $pagination_c->setProperty('_query_string', $query_string);
  $comment_string = '<div class="table_container">';
  if ($comment_result) {
   $con_count = 0;
   if (count($comment_result) > 0) {
    $comment_string .='<table id="comment_list" class="table table-striped table-hover"><thead> 
						 <tr class="headerBgColor">
							<th class="topics">Subject</th>
							<th class="created_by">Created By</th>
							<th class="post_date">Post Date</th>
						 </tr>
						</thead>';
    foreach ($comment_result as $recod_c_k => $recod_c) {
     $continue_act1 = true;
     if (($recod_c_k >= ($pageno - 1) * $per_page) && ($recod_c_k <= (($pageno - 1) * $per_page) + $per_page)) {
      $continue_act1 = false;
     }
     if ($continue_act1) {
      continue;
     }
     $even_odd = ($con_count % 2 == 0) ? 'even' : 'odd';
     $user_name = empty($recod_c->username) ? 'Anonymous\SelfWeb' : $recod_c->username;
     $comment_string .= "<tr id=\"row_no$con_count\" class='new_row $even_odd'> "
      . " <td class='subject_summary'>";
     $comment_string .= '<a href="' . HOME_URL . 'content.php?mode=2&'
      . 'content_id=' . $recod_c->reference_id . '&content_type_id=' . $recod_c->content_type_id . '#comment_id_' . $recod_c->comment_id . '">';
     $comment_string .= "<i class='fa fa-comment'></i> &nbsp;";
     $comment_string .= substr(strip_tags($recod_c->comment), 0, $this->subject_noof_char);
     $comment_string .= ' </a>';
     $comment_string .= '</td>';
     $comment_string .= '<td class="created_by">';
     $comment_string .= $user_name;
     $comment_string .= '</td><td class="post_date">';
     $comment_string .= $recod_c->creation_date;
     $comment_string .= '</td>';
     $comment_string .= '</tr>';
     $con_count++;
    }
   }

   $comment_string .='</table>';
  }
  $comment_string .='</div>';
  $comment_string .= '<div id="pagination">';


  $comment_string .= $pagination_c->show_pagination();
  $comment_string .= '</div>';
  return $comment_string;
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

 public static function comment_list($reference_table, $reference_id, $extension_id) {
  global $f;
  $pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
  $per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
  $query_string = !empty($_SERVER['QUERY_STRING']) ? htmlentities($_SERVER['QUERY_STRING']) : '';
  $comment_string = " ";
  $sql = "SELECT comment.comment_id, comment.comment, comment.created_by,  comment.creation_date, "
   . "  comment.creation_date, IFNULL(user.username, comment.comment_by) as username, user.image_file_id as image_file_id "
   . " FROM comment left JOIN ino_user user ON user.ino_user_id = comment.created_by" .
   " WHERE reference_table = '{$reference_table}'
           AND reference_id = '{$reference_id}' ";
  if (!empty($per_page)) {
   $total_count = self::count_by_reference_table_and_id($reference_table, $reference_id);
   $pagination = new pagination($pageno, $per_page, $total_count);
   $sql .=" LIMIT {$per_page} ";
   $sql .=" OFFSET {$pagination->offset()}";
  }
  $result = self::find_by_sql($sql);

  if (count($result) > 0) {
   foreach ($result as $records) {
    $allow_content_update = false;
    if ((!empty($_SESSION['user_id'])) && ($records->created_by == $_SESSION['user_id'])) {
     $allow_content_update = true;
    } elseif ((!empty($_SESSION['user_roles'])) && (in_array('ADMIN', $_SESSION['user_roles']))) {
     $allow_content_update = true;
    }
    $comment_file = file::find_by_reference_table_and_id('comment', $records->comment_id);
    $comment_string .= "<div id=\"comment_id_$records->comment_id\" class=\"panel panel-info commentRecord\">";
    $comment_string .= '<div class="panel-heading">';
    $comment_string .= '<ul class="header_li">';
    if (!empty($records->image_file_id)) {
     $profile_image = $f->show_existing_image($records->image_file_id, 'img-vs', 1);
     $comment_string .= "<li class='user-profile-image'>$profile_image</li>";
    }
    if (!empty($records->username) && ($records->created_by != -99)) {
     $comment_string .= '<li class="comment_by"><a href="' . HOME_URL . 'form.php?class_name=user_activity_v&mode=2&user_id=' . ($records->created_by) . '">' . ino_getUserName_from_email($records->username) . '</a></li>';
    } else if (!empty($records->username)) {
     $comment_string .= '<li class="comment_by">' . ino_getUserName_from_email($records->username) . '</li>';
    } else {
     $comment_string .= '<li class="comment_by">Anonymous</li>';
    }
    $comment_string .= '<li class="creation_date">' . $records->creation_date . '</li>';
    if ($allow_content_update) {
     $comment_string .= '<li class="delete_update"><button name="delete_button" class="delete_button btn btn-danger " value="' .
      $records->comment_id . '" >Delete</button> ';
     $comment_string .= ' <button name="update_button" class="update_button btn btn-warning " value="' .
      $records->comment_id . '" >Update</button> </li>';
    }

    $comment_string .= '</ul>';
    $comment_string .= '</div>';
    $comment_string .= '<div class="comment panel-body update-comment">' . nl2br(html_entity_decode($records->comment, ENT_QUOTES ,'UTF-8'));
    if (count($comment_file) > 0) {
     foreach ($comment_file as $file_record) {
      $comment_string .= '<p><a href=' . HOME_URL . $file_record->file_path . $file_record->file_name . '>' . $file_record->file_name . '</a></p>';
     }
    }
    $comment_string .= '<span class="comment-reply"><a href="#commentForm" class="btn btn-success" role="button">Reply</a></span>';
    $comment_string .= '</div>';
    $comment_string .= '</div>';
   }
  }
  $pagination = new pagination($pageno, $per_page, $total_count);
  if (!empty($_GET['is_alias'])) {
   $pagination->setProperty('_is_alias', true);
   $pagination->setProperty('_path', thisPage_url());
  } else {
   if (strpos($_SERVER['SCRIPT_NAME'], 'content.php') !== false) {
    $pagination->setProperty('_path', 'content');
   } else if (strpos($_SERVER['SCRIPT_NAME'], 'form.php') !== false) {
    $pagination->setProperty('_path', 'form');
   }
  }


  $pagination->setProperty('_query_string', $query_string);
  $comment_string .= $pagination->show_pagination();

  return $comment_string;
 }

 public function multi_select_input_fields() {
  $multi_select_input = [
  ];
  return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'action_class_name',
   'mode',
   'action',
   'show_block',
  ];

  return $multi_select_hidden;
 }

}

//end of comment class
?>