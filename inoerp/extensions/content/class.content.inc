<?php

 /* Privillages
  * 2. Read
  * 3. Write
  * 4. Update Own
  * 5. Update Any
  * 9. Admin
  */

 class content extends dbObject {

  public static $table_name = "content";
  public static $content_table_name = "";
  public static $primary_column = "content_id";
  public static $key_column = "subject";
  public static $module = "extension";
//  data base variables as stored database column name
  public static $system_info = [
   'name' => 'Content',
   'number' => '91112',
   'description' => 'Used for creating differnt type of contents. Such as Forum, Documentation, etc',
   'version' => '1.1.1.3',
   'db_version' => '1001',
   'mod_version' => '1.1.x-1.1',
   'dependent_class' => '',
   'primary_entity_cb' => '',
   'module_name' => 'extensions',
   'weight' => '12'
  ];
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
   'show_in_fp_cb',
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
   "rev_enabled_cb",
   'show_in_fp_cb'
  ];
  public $fields_inForm_notInDataBase = [
   'url_alias',
   'ext_url_alias_id'
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
  ];
  public $base_encoded_array = [];
  public $requiredField = [
   "subject",
   'content_type_id'
  ];
  public $pageTitle = " Simple & Effective Enterprise Management System ";
  public $search = [
   '_update_path' => 'content.php?class_name=content',
   '_show_update_path' => 1,
   '_update_action_meassge' => 'Update',
   '_view_path' => 'content.php?class_name=content',
   '_show_view_path' => 1,
   '_view_action_meassge' => 'Read',
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
  public $show_in_fp_cb;
  public $rev_enabled_cb;
  public $weightage;
  public $rev_number;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;
  public $msg;
  public $url_alias;
  public $ext_url_alias_id;
  private $_summary_noof_char = '500';
  private $_subject_noof_char = '60';
  private $_pagination;

  public function setProperty($property, $value) {
   if (property_exists($this, $property)) {
    switch ($property) {
     case '_summary_noof_char':
      if ((!empty($value)) && is_numeric($value)) {
       $this->$property = $value;
      } else {
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

  public function _before_showing() {
   global $mode;
   //check if url alias exists when in mode = 9
   if (($mode == 9) && !empty($this->content_id)) {
    $url_alis_a = ext_url_alias::find_by_contentId($this->content_id);
    if ($url_alis_a) {
     $this->url_alias = $url_alis_a->alias;
     $this->ext_url_alias_id = $url_alis_a->ext_url_alias_id;
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

   //url alias
   if ((!empty($content_type)) && (!empty($this->url_alias) || $content_type->auto_url_alias_cb == 1 )) {
    $url_alias = new ext_url_alias();
    $url_alias->alias = !empty($this->url_alias) ? convert_to_url($this->url_alias) : convert_to_url($this->subject);
    $url_alias->content_id = $this->content_id;
    $url_alias->original_url = "content_id=$this->content_id&content_type=$content_type->content_type";
    $url_alias->ext_url_alias_id = !empty($this->ext_url_alias_id) ? $this->ext_url_alias_id : null;
    $url_alias->audit_trial();
    $url_alias->save();
   }
  }

  Public function frontPage_contents($no_of_articles = 6, $noOfCharacters = '500') {
   $sql = " SELECT content.content_id, ct.content_type_id, content.subject, content.terms, 
	         content.created_by, content.creation_date, ct.content_type
					FROM content
					LEFT JOIN content_type ct ON ct.content_type_id = content.content_type_id 
					WHERE 
					content.published_cb = 1 
					AND content.show_in_fp_cb = 1 ";
   $sql .=" ORDER BY weightage DESC, creation_date DESC";
   $sql .= " LIMIT {$no_of_articles} ";
   $result = $this->findBySql($sql);
   $result_a = &$result;
   foreach ($result_a as $cont) {
    $cont_tableName = 'c_' . $cont->content_type;
    $sql_c = "SELECT SUBSTRING(content,1,$noOfCharacters) AS content_summary " .
      "FROM " . $cont_tableName . " where content_id='{$cont->content_id}' LIMIT 1";
    $result_cont = $this->findBySql($sql_c);
    $cont->content_summary = !empty($result_cont[0]) ? $result_cont[0]->content_summary : '';
   }

   return $result;
  }

  public function showfrontPage_contents($no_of_articles = 6, $noOfCharacters = '500', $subject_no_of_char = '55') {
   $result = $this->frontPage_contents($no_of_articles, $noOfCharacters);
   $page_string = '';
   $con_count = 0;
   if (count($result) > 0) {
    $page_string .= '<ul class="summary_list">';
    foreach ($result as $records) {
     $con_count++;
     $page_string .= "<li class=\"front_page_summary count_$con_count\">";
     $page_string .= '<span class="heading1 subject_summary">';
     $page_string .= '<img src="' . HOME_URL . 'themes/default/images/remove.png" class="remove" width="12px" height="12px">&nbsp;';
     $page_string .= substr($records->subject, 0, $subject_no_of_char);
     $page_string .= '<span class="more_page">';
     $page_string .= '<a href="' . HOME_URL . 'content.php?mode=2&'
       . 'content_id=' . $records->content_id . '&content_type_id=' . $records->content_type_id . '">';
     $page_string .= 'Read More.. </a>';
     $page_string .= '</span>';
     $page_string .= '</span>';
     $page_string .= '<span class="content_summary">';
     $page_string .= $records->content_summary;
     $page_string .= '</span>';
     $page_string .= '</li>';
    }
    $page_string .= '</ul>';
   }
   return $page_string;
  }

  private function _getContent_byConteTypeCategory($pageno, $per_page, $query_string) {
   $sql = " 
SELECT content.content_id, content.content_type_id, content.subject, ct.content_type, content.creation_date, 
content.created_by, user.username  ";
   if (!empty($this->category_id)) {
    $sql .= " , category_reference.category_reference_id, category_reference.major_category_id, "
      . " category.category, category_reference.category_id, category_reference.reference_type  ";
   }

   $sql .= ' FROM content
LEFT JOIN user ON user.user_id = content.created_by 
LEFT JOIN content_type ct ON ct.content_type_id = content.content_type_id   ';
   if (!empty($this->category_id)) {
    $sql .= " , category_reference LEFT JOIN category ON category.category_id = category_reference.category_id ";
   }
   $sql .= " WHERE content.content_type_id = '{$this->content_type_id}' ";

   if (!empty($this->category_id)) {
    $sql .= " AND  category_reference.category_id = '$this->category_id'
AND category_reference.reference_table = 'content' 
AND content.content_id = category_reference.reference_id  ";
   }
   $sql .= " ORDER BY content.content_id DESC ";

   $count_sql = " SELECT COUNT(content.content_id) ";
   $count_sql .= ' FROM content
LEFT JOIN user ON user.user_id = content.created_by 
LEFT JOIN content_type ct ON ct.content_type_id = content.content_type_id   ';
   if (!empty($this->category_id)) {
    $count_sql .= " , category_reference LEFT JOIN category ON category.category_id = category_reference.category_id ";
   }
   $count_sql .= " WHERE content.content_type_id = '{$this->content_type_id}' ";

   if (!empty($this->category_id)) {
    $count_sql .= " AND  category_reference.category_id = '$this->category_id'
AND category_reference.reference_table = 'content' 
AND content.content_id = category_reference.reference_id  ";
   }

   if (!empty($per_page)) {
    $total_count = self::count_all_by_sql($count_sql);
    $this->_pagination = new pagination($pageno, $per_page, $total_count);
    $this->_pagination->setProperty('_path', 'content');
    $this->_pagination->setProperty('_query_string', $query_string);
    $sql .=" LIMIT {$per_page} ";
    $sql .=" OFFSET {$this->_pagination->offset()} ";
   }
   $result = $this->findBySql($sql);
   $result_a = &$result;
   if (!$result_a) {
    return false;
   }
   foreach ($result_a as $cont) {
    $cont_tableName = 'c_' . $cont->content_type;
    $sql_c = "SELECT SUBSTRING(content,1,$this->_summary_noof_char) AS content_summary " .
      "FROM " . $cont_tableName . " where content_id='{$cont->content_id}' LIMIT 1";
    $result_cont = $this->findBySql($sql_c);
    $cont->content_summary = !empty($result_cont[0]) ? $result_cont[0]->content_summary : '';
   }
   return $result;
  }

  public function showSummaryList_byConteTypeCategory($pageno = 1, $per_page = 5, $query_string = "") {
   $content_string = " ";
   $result = $this->_getContent_byConteTypeCategory($pageno, $per_page, $query_string);
   $con_count = 0;
   if ($result) {
    $content_string .= '<ul class="summary_list">';
    foreach ($result as $records) {
     $con_count++;
     $content_string .= "<li class=\"front_page_summary count_$con_count\">";
     $content_string .= '<span class="heading1 subject_summary">';
     $content_string .= '<img src="' . HOME_URL . 'themes/default/images/remove.png" class="remove" width="12px" height="12px">&nbsp;';
     $content_string .= substr($records->subject, 0, $this->_subject_noof_char);
     $content_string .= '<span class="more_page">';
     $content_string .= '<a href="' . HOME_URL . 'content.php?mode=2&'
       . 'content_id=' . $records->content_id . '&content_type_id=' . $records->content_type_id . '">';
     $content_string .= 'Read More.. </a>';
     $content_string .= '</span>';
     $content_string .= '</span>';
     $content_string .= '<span class="content_summary">';
     $content_string .= substr($records->content_summary, 0, $this->_summary_noof_char);
     $content_string .= '</span>';
     $content_string .= '</li>';
    }
    $content_string .= '</ul>';
   }

   $content_string .= '<div id="pagination" style="clear: both;">';
   if (!empty($this->_pagination)) {
    $pagination_statement = $this->_pagination->show_pagination($this->_pagination, 'contents', $pageno, $query_string);
   }
   $content_string .= $pagination_statement;
   $content_string .= '</div>';
//   $content_string .= select_per_page();

   return $content_string;
  }

  public function showForumList_byConteTypeCategory($pageno = 1, $per_page = 5, $query_string = "") {
   $content_string = " ";
   $result = $this->_getContent_byConteTypeCategory($pageno, $per_page, $query_string);
   $con_count = 0;
   $content_string .='<div class="table_container">';
   if ($result) {
    if (count($result) > 0) {
     $content_string .=!empty($result[0]->category) ? '<span class="heading">' . $result[0]->category . '</span>' : '';
     $content_string .='<table id="forum_list" class="top_margin10 form_line_data_table"><thead> 
						 <tr class="headerBgColor">
							<th class="topics">Topics</th>
							<th class="replies">Replies</th>
							<th class="created_by">Created By</th>
							<th class="post_date">Post Date</th>
						 </tr>
						</thead>';
     foreach ($result as $records) {
      $no_of_replies = comment::count_by_reference_table_and_id('content', $records->content_id);
      $even_odd = ($con_count % 2 == 0) ? 'even' : 'odd';
      $content_string .= "<tr id=\"row_no$con_count\" class='new_row $even_odd'> "
        . " <td class='subject_summary'>";
      $content_string .= '<a href="' . HOME_URL . 'content.php?mode=2&'
        . 'content_id=' . $records->content_id . '&content_type_id=' . $records->content_type_id . '">';
      $content_string .= substr($records->subject, 0, $this->_subject_noof_char);
      $content_string .= ' </a>';
      $content_string .= '</td>';
      $content_string .= '<td class="no_of_replies">';
      $content_string .= $no_of_replies . '</td>';
      $content_string .= '<td class="created_by">';
      $content_string .= $records->username;
      $content_string .= '</td><td class="post_date">';
      $content_string .= $records->creation_date;
      $content_string .= '</td>';
      $content_string .= '</tr>';
      $con_count++;
     }
    }

    $content_string .='</table>';
   }
   $content_string .='</div>';
   $content_string .= '<div id="pagination" style="clear: both;">';
   if (!empty($this->_pagination)) {
    $pagination_statement = $this->_pagination->show_pagination($this->_pagination, 'contents', $pageno, $query_string);
   }
   $content_string .= $pagination_statement;
   $content_string .= '</div>';
//   $content_string .= select_per_page();

   return $content_string;
  }

  public function findAll_parantContent_of_categoryId($category_id) {
   $sql = "SELECT content.content_id, content.subject, content.content_type_id FROM 
	         content, category_reference cr
					 where content.parent_id IS NULL 
					 AND cr.reference_table = 'content'
					 AND cr.reference_id = content.content_id
					 AND cr.category_id = :category_id   ";
   $value_a = ['category_id' => $category_id];
   $result = $this->findBySql($sql, $value_a);
   return !empty($result) ? $result : false;
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
   $sql = "SELECT SUBSTRING(content,1,2000) AS content_summary " .
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
    echo '<a href="' . HOME_URL . 'content.php?content_id=' . $content_summary->content_id . '">';
    echo 'Read more.. </a>';
    echo '</div>';
    echo '</div>';
   }
  }

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
     $content_string .= '<a href="' . HOME_URL . 'content.php?content_id=' . $content_summary->content_id . '">';
     $content_string .= 'Read more.. </a>';
     $content_string .= '</div>';
     $content_string .= '</div>';
    }
   }

   $content_string .= '<div id="pagination" style="clear: both;">';
   if (isset($pagination) && $pagination->total_contents() > 1) {
    if ($pagination->has_previous_content()) {
     $content_string .= "<a href=\"" . HOME_URL . "content.php?contentno=";
     $content_string .= $pagination->previous_content() . '&' . $query_string;
     $content_string .= "> &laquo; Previous </a> ";
    }

    for ($i = 1; $i <= $pagination->total_contents(); $i++) {
     if ($i == $content_no) {
      $content_string .= " <span class=\"selected\">{$i}</span> ";
     } else {
      $content_string .= " <a href=\"" . HOME_URL . "content.php?contentno={$i}&" . remove_querystring_var($query_string, 'contentno');
      $content_string .= '">' . $i . '</a>';
     }
    }

    if ($pagination->has_next_content()) {
     $content_string .= " <a href=\"" . HOME_URL . "content.php?contentno=";
     $content_string .= $pagination->next_content() . '&' . remove_querystring_var($query_string, 'contentno');
     $content_string .= "\">Next &raquo;</a> ";
    }
   }
   $content_string .= '</div>';

   return $content_string;
  }

  public static function content_summaryList_byConteTypeCategory($content_type_id, $category_id, $pageno = 1, $per_page = 5, $query_string = "", $current_url = '') {
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
    $pagination->setProperty('_path', 'content');
    $pagination->setProperty('_query_string', $query_string);
    $sql .=" LIMIT {$per_page} ";
    $sql .=" OFFSET {$pagination->offset()} ";
   }

   $result = self::find_by_sql($sql);
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
     $content_string .=!empty($content_summary->content_summary) ? $content_summary->content_summary : '';
     $content_string .= '<span class="more_page">';
     $content_string .= '<a href="' . HOME_URL . 'content.php?content_id=' . $content->content_id . '&content_type_id=' . $content_type_id . '">';
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
//   $content_string .= select_per_page();

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
   echo '<a href="' . HOME_URL . 'content.php?content_id="' . $content_summary->content_id . '>';
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
   if($extra_content){
       foreach ($content_field_array as $key => $value) {
    if ($value != 'content_id') {
     $content_statemnt .= nl2br($extra_content->$value);
    }
   }
   }

   return $content_statemnt;
  }

 }

//end of content class
 /* SQL Snippets
  * Delete contents from content which doesnt belong to any content type
  * $sql = "
  * DELETE FROM content WHERE content_id NOT IN(
   SELECT a.contentId FROM
   (
   SELECT content.content_id as contentId
   FROM content,
   c_content
   WHERE content.content_id = c_content.content_id
   UNION
   SELECT content.content_id
   FROM content,
   c_forum
   WHERE content.content_id = c_forum.content_id
   UNION
   SELECT content.content_id
   FROM content,
   c_documentation
   WHERE content.content_id = c_documentation.content_id
   ) a
   )
  * "
  * 
  * 
  * DELETE FROM Category reference
  * DELETE FROM category_reference WHERE 
   category_reference_id NOT IN(
   SELECT a.category_reference_id from (
   SELECT category_reference_id,reference_table FROM
   category_reference cr,
   content
   WHERE cr.reference_table = 'content'
   AND cr.reference_id = content.content_id
   UNION
   SELECT category_reference_id,reference_table FROM
   category_reference cr,
   content
   WHERE cr.reference_table != 'content'
   )a
   )
  */
?>