<?php

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
  public static $js_fileName = 'extensions/comment/comment.js';
  public static $system_info = [
   'name' => 'Comment',
   'number' => '91113',
   'description' => 'Comments for all type of content types and documents',
   'version' => '1.1.1.3',
   'db_version' => '1001',
   'mod_version' => '1.1.x-1.1',
   'dependent_class' => '',
   'primary_entity_cb' => '',
   'module_name' => 'extensions',
   'weight' => '13'
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
   'action'
  ];
  public $pageTitle = " Comment - Create & View differnt Comments ";
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

  public function _before_save() {
   if (empty($this->subject)) {
    $this->subject = substr($this->comment, 0, 50);
   }
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

  public function comment_recent_comments_block($param) {
   $numbers = empty($param->numbers) ? 10 : $param->numbers;
   $start_from = empty($param->start_from) ? 1 : $param->start_from;
   $sql = " SELECT comment.comment_id, comment.subject,
	         content.content_id, content.content_type_id
					FROM comment
					LEFT JOIN content ON content.content_id = comment.reference_id 
					WHERE comment.reference_table = 'content'
					AND comment.subject IS NOT NULL AND comment.subject !='' ";
   $sql .=" ORDER BY comment.weightage DESC, comment.creation_date DESC ";
   $sql .= " LIMIT :lmt_start_from , :lmt_no_of_records  ";
   $value_a = ['lmt_no_of_records' => $numbers, 'lmt_start_from' => $start_from];

   $result = $this->findBySql($sql, $value_a);
   $comment_string = '';
   if (count($result) > 0) {
    $comment_string .= '<ul class="documentation_list comment">';
    foreach ($result as $records) {
     $comment_string .= '<li class="comment_subject">';
     $comment_string .= '<a href="' . HOME_URL . 'content.php?mode=2&' . 'content_id=' . $records->content_id .
       '&content_type_id=' . $records->content_type_id . '#comment_id_' . $records->comment_id . '">';
     $comment_string .= $records->subject . '</a>';
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
   $pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
   $per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
   $query_string = !empty($_SERVER['QUERY_STRING']) ? $_SERVER['QUERY_STRING'] : '';
   $comment_string = " ";
   $sql = "SELECT comment.comment_id, comment.comment, comment.created_by,  comment.creation_date, "
     . "  comment.creation_date, user.username  "
     . " FROM comment left JOIN user ON user.user_id = comment.created_by" .
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
     $comment_string .= "<ul id=\"comment_id_$records->comment_id\" class=\"commentRecord\">";
     $comment_string .= '<li class="header_li">';
     $comment_string .= '<ul class="header">';
     if(!empty($records->username)){
     $comment_string .= '<li class="comment_by"><a href="'.HOME_URL.'form.php?class_name=user_activity_v&mode=2&user_id='.($records->created_by) .'">' . ($records->username) . '</a></li>';
     }else{
      $comment_string .= '<li class="comment_by">selfWeb</li>';
     }
     $comment_string .= '<li class="creation_date">' . $records->creation_date . '</li>';
     if ($allow_content_update) {
      $comment_string .= '<li class="delete_update"><button name="delete_button" class="delete_button button " value="' .
        $records->comment_id . '" >Delete</button>';
      $comment_string .= '<button name="update_button" class="update_button button" value="' .
        $records->comment_id . '" >Update</button> </li>';
     }
     $comment_string .= '</ul>';
     $comment_string .= '</li>';
     $comment_string .= '<li class="line_li">';
     $comment_string .= '<ul class="line">';
//		$comment_string .= '<li class="subject">' . $records->subject . '</li>';
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


   $pagination = new pagination($pageno, $per_page, $total_count);
   if (strpos($_SERVER['SCRIPT_NAME'], 'content.php') !== false) {
    $pagination->setProperty('_path', 'content');
   } else if (strpos($_SERVER['SCRIPT_NAME'], 'form.php') !== false) {
    $pagination->setProperty('_path', 'form');
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