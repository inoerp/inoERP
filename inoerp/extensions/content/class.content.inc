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

class content extends dbObject {

 public static $table_name = "content";
 public static $content_table_name = "";
 public static $primary_column = "content_id";
 public static $key_column = "subject";
 public static $module = "extension";
 public static $multi_select_template_path = 'extensions/content/multi_action/content_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
		 'name' => 'Content',
		 'number' => '10014',
		 'description' => 'Used for creating different type of contents. Such as Forum, Documentation, etc',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'extn',
		 'weight' => 14
 ];
 public static $content_field_array = [];
 public static $comment_status_a = [
		 1 => 'Disabled',
		 2 => 'View Only',
		 3 => 'Allow Post & View',
 ];
 public $field_a = [
		 "content_id",
		 "content_type_id",
		 "parent_id",
		 "subject",
		 "terms",
		 "published_cb",
		 "weightage",
		 "rev_enabled_cb",
		 "rev_number",
		 'show_in_fp_cb',
		 'comment_status',
		 'content_by',
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
 public $checkbox = ["published_cb",
		 "rev_enabled_cb",
		 'show_in_fp_cb'
 ];
 public $fields_inForm_notInDataBase = [
		 'url_alias',
		 'ext_url_alias_id',
		 'non_db_content_type',
		 'subscribe_cb'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public $base_encoded_array = [];
 public $requiredField = [
		 "subject",
		 'content_type_id'
 ];
 public $pageTitle = " Content ";
 public $search = [
		 '_update_path' => 'content.php?window_type=form&class_name=content',
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_view_path' => 'content.php?class_name=content',
		 '_show_view_path' => 1,
		 '_view_action_meassge' => 'Read',
 ];
 public $file_id_values;
 public $summary_characters;
 public $content_summary;
 public $content_full;
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
 public $comment_status;
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
 public $non_db_content_type;
 public $subscribe_cb;

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

 public function _before_save() {
	if (!empty($this->content)) {
	 $this->content = htmlentities($this->content);
	}

	if (!empty($this->subject)) {
	 $this->subject = htmlentities($this->subject);
	}

	if (!empty($this->non_db_content_type)) {
	 $ndbc = new $this->non_db_content_type;
	 if (method_exists($ndbc, '_before_save')) {
		return call_user_func(array($ndbc, '_before_save'), $_POST);
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
	 $table_name = DB_TYPE == 'ORACLE' ? strtoupper($class) : $class;

	 $$class = new stdClass();
	 $extra_fields = new_content_type::find_fields_by_id($content_type->content_type_id);

	 $content_field_array = content::$content_field_array;

	 foreach ($extra_fields as $records) {
		$content_field_array[] = $records->field_name;
	 }
	 $$class->content_id = $this->content_id;
	 $checkSql = " SELECT * FROM $table_name WHERE content_id = :content_id ";
//   $checkSql = ino_perPageSql_i($checkSql, 1);
	 $value_a = ['content_id' => $this->content_id];
	 $checkResult = self::find_by_sql_i($checkSql, $value_a);
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
		$sql.= $table_name;
		$sql .= " SET ";
		$sql.= $field_stmt;

		switch (DB_TYPE) {
		 case 'ORACLE' :
			$sql.= " WHERE CONTENT_ID = :CONTENT_ID ";
			break;

		 default:
			$sql.= " WHERE content_id = :content_id ";
			break;
		}
		$stmt = $dbc->connection->prepare(" $sql ");
		//Bind parameters
		foreach ($content_field_array as $key => $value) {
		 $value_post = strtolower($value);
		 if (!empty($_POST[$value_post][0])) {
			$stmt->bindvalue(":$value", htmlentities($_POST[$value_post][0]));
		 } else {
			$stmt->bindvalue(":$value", null, PDO::PARAM_INT);
		 }
		}
		try {
		 $stmt->execute();
		 $newMsg = "Record is Successfully saved in $class";
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
		 $field_values .= ':' . ($value) . ', ';
		}
		$field_values = rtrim($field_values, ', ');
//write SQL
		$sql = " INSERT INTO ";
		$sql.= $table_name;
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
			$stmt->bindParam(":$value", htmlentities($_POST[$value][0]));
		 } else {
			$stmt->bindvalue(":$value", null, PDO::PARAM_INT);
		 }
		}
		$stmt->bindParam(':content_id', $$class->content_id);

		//get next id
		switch (DB_TYPE) {
		 case 'ORACLE' :
			$next_seq = $class . '_seq.NEXTVAL';
			$sh = $dbc->connection->prepare("SELECT $next_seq AS next_seq_id FROM DUAL");
			$sh->execute();
			$nextInsertId = $sh->fetchColumn(0);
			$stmt->bindParam(":content_id", $nextInsertId);
			$$class->content_id = $nextInsertId;
			break;
		}


		try {
		 $stmt->execute();
		 if (DB_TYPE == 'MYSQL') {
			$$class->content_id = $dbc->connection->lastInsertId();
		 }
		 $newMsg = "Record is Successfully saved in $class";
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
	 $url_alias->save();
	}

	//subscribe
	if (!empty($this->subscribe_cb)) {
	 $this->_create_subscription();
	}
 }

 private function _create_subscription() {
	global $ino_user;
	$sub_i = new extn_subscribe();
	$sub_i->reference_key_name = 'content';
	$sub_i->reference_key_value = $this->content_id;
	$sub_i->user_id = $ino_user->ino_user_id;
	$sub_i->username = $ino_user->username;
	$sub_i->user_email = $ino_user->email;
	try {
	 $sub_i->save();
	} catch (Exception $e) {
//   echo $e->getMessage();
	}
 }

 Public function frontPage_contents($no_of_articles = 6, $noOfCharacters = '500') {
	$sql = " SELECT content.content_id, ct.content_type_id, content.subject, content.terms, 
	         content.created_by, content.creation_date, ct.content_type,  eua.alias as alias
					FROM content
					LEFT JOIN content_type ct ON ct.content_type_id = content.content_type_id
          LEFT JOIN ext_url_alias eua ON eua.content_id=content.content_id 
					WHERE 
					content.published_cb = 1 
					AND content.show_in_fp_cb = 1 
   AND content.content_type_id != 1 ";

	$orderby_sql = " ORDER BY  creation_date DESC, weightage DESC";
	$sql = ino_perPageOrderBySql_i($sql, $orderby_sql, $no_of_articles, 0);

	$result = $this->findBySql($sql);

	$result_a = &$result;
	if (!empty($result_a)) {
	 foreach ($result_a as $cont) {
		$cont_tableName = 'c_' . $cont->content_type;
		if (DB_TYPE == 'ORACLE') {
		 $cont_tableName = strtoupper($cont_tableName);
		}
		$sql_c = "SELECT content  AS content_summary " .
						"FROM " . $cont_tableName . " where content_id='{$cont->content_id}' ";
		$sql_c = ino_perPageSql_i($sql_c, 1);
		$result_cont = $this->findBySql($sql_c);
		if (!empty($result_cont[0])) {
		 switch (DB_TYPE) {
			case 'ORACLE' :
			 $cont->content_summary = stream_get_contents($result_cont[0]->content_summary);
			 break;

			default:
			 $cont->content_summary = ($result_cont[0]->content_summary);
			 break;
		 }
		 $cont->content_summary = substr($cont->content_summary, 0, $noOfCharacters);
		} else {
		 $cont->content_summary = '';
		}
	 }
	}


	return $result;
 }

 Public function findAll_contents($no_of_articles = '', $noOfCharacters = '100', $content_type_id = '1') {
	$sql = " SELECT content.content_id, ct.content_type_id, content.subject, content.terms, 
	         content.created_by, content.creation_date, ct.content_type, cm.no_of_comments,  eua.alias as alias,
            IFNULL(content.content_by, user.username) as username
					FROM content
          LEFT JOIN ino_user as user ON user.ino_user_id = content.created_by
					LEFT JOIN content_type ct ON ct.content_type_id = content.content_type_id 
          LEFT JOIN ext_url_alias eua ON eua.content_id=content.content_id 
          LEFT JOIN ( 
          SELECT reference_table, reference_id, count(extn_comment_id) as no_of_comments
          FROM extn_comment
          GROUP BY reference_table, reference_id
           )
          cm ON cm.reference_table = 'content' AND content.content_id = cm.reference_id
					WHERE 
					content.published_cb = '1' 
          AND content.content_type_id = '{$content_type_id}'
					 ";

	$sql .= " ORDER BY content.weightage DESC, content.creation_date DESC";
	if (!empty($no_of_articles)) {
	 $sql = ino_perPageSql_i($sql, $no_of_articles);
	}
	$result = $this->findBySql($sql);
	if (empty($result)) {
	 return false;
	}
	$result_a = &$result;
	foreach ($result_a as $cont) {
	 $cont_tableName = 'c_' . $cont->content_type;
	 $sql_c = "SELECT SUBSTRING(content,1,$noOfCharacters) AS content_summary, content " .
					 "FROM " . $cont_tableName . " where content_id='{$cont->content_id}' ";
	 $sql_c = ino_perPageSql_i($sql_c, 1);
	 $result_cont = $this->findBySql($sql_c);
	 $cont->content_summary = !empty($result_cont[0]) ? $result_cont[0]->content_summary : '';
	 $cont->content_full = !empty($result_cont[0]) ? $result_cont[0]->content : '';
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
		if (!empty($records->alias)) {
		 $page_string .= '<a href="' . HOME_URL . "content/$records->alias" . '">';
		} else {
		 $page_string .= '<a href="' . HOME_URL . 'content.php?mode=2&'
						 . 'content_id=' . $records->content_id . '&content_type_id=' . $records->content_type_id . '">';
		}

		$page_string .= gettext('Read More') . '.. </a>';
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
content.created_by, user.username , eua.alias as alias ";
	if (!empty($this->category_id)) {
	 $sql .= " , category_reference.category_reference_id, category_reference.major_category_id, "
					 . " category.category, category_reference.category_id, category_reference.reference_type  ";
	}

	$sql .= ' FROM content
LEFT JOIN ino_user as user ON user.ino_user_id = content.created_by 
LEFT JOIN content_type ct ON ct.content_type_id = content.content_type_id   
LEFT JOIN ext_url_alias eua ON eua.content_id=content.content_id 
';
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
LEFT JOIN ino_user as user ON user.ino_user_id = content.created_by 
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
	 $sql = ino_perPageSql_i($sql, $per_page, $this->_pagination->offset());
	}
	$result = $this->findBySql($sql);
	$result_a = &$result;
	if (!$result_a) {
	 return false;
	}
	foreach ($result_a as $cont) {
	 $cont_tableName = 'c_' . $cont->content_type;
	 $sql_c = "SELECT SUBSTRING(content,1,$this->_summary_noof_char) AS content_summary " .
					 "FROM " . $cont_tableName . " where content_id='{$cont->content_id}' ";
	 $sql_c = ino_perPageSql_i($sql_c, 1);
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
		$content_string .= '<div class="heading1 subject_summary">';
		$content_string .= '<i class="fa fa-remove remove-content clickable"></i>&nbsp;';
		$content_string .= substr($records->subject, 0, $this->_subject_noof_char);
		$content_string .= '<span class="more_page">';
		if (!empty($records->alias)) {
		 $link_read = HOME_URL . "content/$records->alias";
		} else {
		 $link_read = HOME_URL . 'content.php?mode=2&' . 'content_id=' . $records->content_id . '&content_type_id=' . $records->content_type_id;
		}

		$content_string .= '<a href="' . htmlspecialchars($link_read) . '">';
		$content_string .= gettext('Read More') . '.. </a>';
		$content_string .= '</span>';
		$content_string .= '</div>';
		$content_string .= '<div class="content_summary">';
		$content_string .= ino_strip_html($records->content_summary, $this->_summary_noof_char);
		$content_string .= '</div>';
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

 public function all_forum_topics() {
	$pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
	$per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
	$this->subject_noof_char = empty($this->subject_noof_char) ? 300 : $this->subject_noof_char;
	$query_string = !empty($_SERVER['QUERY_STRING']) ? htmlentities($_SERVER['QUERY_STRING']) : '';
	$content_result = $this->findAll_contents();
	$total_count_c = count($content_result);
	$pagination_c = new pagination($pageno, $per_page, $total_count_c);
	$pagination_c->setProperty('_path', 'content');
	$pagination_c->setProperty('_query_string', $query_string);
	$content_string = '<div class="table_container">';
	if ($content_result) {
	 $con_count = 0;
	 if (count($content_result) > 0) {
		$content_string .='<table id="content_list" class="table table-striped table-hover"><thead> 
						 <tr class="headerBgColor">
							<th class="post_date">' . gettext('Replies') . '</th>
							<th class="topics">' . gettext('Subject') . '</th>
							<th class="created_by">' . gettext('Created By') . '</th>
							<th class="post_date">' . gettext('Post Date') . '</th>
						 </tr>
						</thead>';
		foreach ($content_result as $recod_c_k => $recod_c) {
		 $continue_act1 = true;
		 if (($recod_c_k > ($pageno - 1) * $per_page) && ($recod_c_k <= (($pageno - 1) * $per_page) + $per_page)) {
			$continue_act1 = false;
		 }
		 if ($continue_act1) {
			continue;
		 }
		 $even_odd = ($con_count % 2 == 0) ? 'even' : 'odd';
		 $user_name = empty($recod_c->username) ? 'Anonymous\SelfWeb' : ino_getUserName_from_email($recod_c->username);
		 $content_string .= "<tr id=\"row_no$con_count\" class='new_row $even_odd'> ";
		 $content_string .= '<td class="no_of_comments"><b>';
		 $content_string .= '<span class="vs-right-margin">' . $recod_c->no_of_comments . '</span>';
		 if (!empty($recod_c->no_of_comments)) {
			$content_string .= "&nbsp;&nbsp;<i class='fa fa-comments-o'></i></b>";
		 } else {
			$content_string .= "&nbsp;&nbsp;<i class='fa fa-circle-o' title='No Replies'></i></b>";
		 }
		 $content_string .= '</td>';
		 $content_string .= "<td class='content_summary'>";
		 $content_string .= '<a class="small_popover" data-placement="right"  data-toggle="popover"  data-content="' . strip_tags($recod_c->content_full) . '"';
		 if (!empty($recod_c->alias)) {
			$content_string .= ' href="' . HOME_URL . "content/$recod_c->alias" . '">';
		 } else {
			$content_string .= ' href="' . HOME_URL . 'content.php?mode=2&'
							. 'content_id=' . $recod_c->content_id . '&content_type_id=' . $recod_c->content_type_id . '">';
		 }
		 if (!empty($recod_c->subject)) {
			$content_string .= substr(strip_tags($recod_c->subject), 0, $this->subject_noof_char);
		 } else {
			$content_string .= substr(strip_tags($recod_c->content_summary), 0, $this->subject_noof_char);
		 }
		 $content_string .= ' </a>';
		 $content_string .= '</td>';
		 $content_string .= '<td class="created_by">';
		 $content_string .= $user_name;
		 $content_string .= '</td><td class="post_date">';
		 $content_string .= date('F j, Y', strtotime($recod_c->creation_date));
		 $content_string .= '</td>';
		 $content_string .= '</tr>';
		 $con_count++;
		}
	 }

	 $content_string .='</table>';
	}
	$content_string .='</div>';
	$content_string .= '<div id="pagination">';


	$content_string .= $pagination_c->show_pagination();
	$content_string .= '</div>';
	return $content_string;
 }

 public function xxxshowForumList_byConteTypeCategory($pageno = 1, $per_page = 5, $query_string = "") {
	$content_string = " ";
	$result_category = $this->_getContent_byConteTypeCategory($pageno, $per_page, $query_string);
	$con_count = 0;
	$content_string .='<div>';
	$content_string .='<div id="tabsHeader">';
	$content_string .= '<ul class="tabMain">
     <li><a href="#tabsHeader-1">' . gettext('All Topics') . '</a></li>
      <li><a href="content.php?content_type=comment">' . gettext('All Comments') . '</a></li>
     <li><a href="#tabsHeader-2">' . gettext('Category Listing') . '</a></li>
    </ul>';
	$content_string .='<div class="tabContainer">';

	//start of first tab
	$content_string .= '<div id="tabsHeader-1" class="tabContent">';
	$all_forum_contents = $this->all_forum_topics();
	if ($all_forum_contents) {
	 $content_string .= $all_forum_contents;
	}
	$content_string .= '</div>';
	//end of first tab
	$category_listing = '<div>';
	if ($result_category) {
	 if (count($result_category) > 0) {
		$category_listing .=!empty($result[0]->category) ? '<span class="heading">' . $result_category[0]->category . '</span>' : '';
		$category_listing .='<table class="table table-striped table-hover"><thead> 
						 <tr class="headerBgColor">
							<th class="topics">' . gettext('Topics') . '</th>
							<th class="replies">' . gettext('Replies') . '</th>
							<th class="created_by">' . gettext('Created By') . '</th>
							<th class="post_date">' . gettext('Post Date') . '</th>
						 </tr>
						</thead>';
		foreach ($result_category as $records) {
		 $no_of_replies = extn_comment::count_by_reference_table_and_id('content', $records->content_id);
		 $even_odd = ($con_count % 2 == 0) ? 'even' : 'odd';
		 $category_listing .= "<tr id=\"row_no$con_count\" class='new_row $even_odd'> "
						 . " <td class='subject_summary'>";
		 $category_listing .= '<a href="' . HOME_URL . 'content.php?mode=2&'
						 . 'content_id=' . $records->content_id . '&content_type_id=' . $records->content_type_id . '">';
		 $category_listing .= substr($records->subject, 0, $this->_subject_noof_char);
		 $category_listing .= ' </a>';
		 $category_listing .= '</td>';
		 $category_listing .= '<td class="no_of_replies">';
		 $category_listing .= $no_of_replies . '</td>';
		 $category_listing .= '<td class="created_by">';
		 $category_listing .= empty($records->username) ? 'selfWeb' : ino_getUserName_from_email($records->username);
		 $category_listing .= '</td><td class="post_date">';
		 $category_listing .= $records->creation_date;
		 $category_listing .= '</td>';
		 $category_listing .= '</tr>';
		 $con_count++;
		}
	 }

	 $category_listing .='</table>';
	}
	$category_listing .='</div>';
	$category_listing .= '<div id="pagination" style="clear: both;">';
	if (!empty($this->_pagination)) {
	 $pagination_statement = $this->_pagination->show_pagination($this->_pagination, 'contents', $pageno, $query_string);
	}
	$category_listing .= $pagination_statement;
	$category_listing .= '</div>';

	//start of second tab
	$content_string .= '<div id="tabsHeader-1" class="tabContent">';
	$all_forum_contents .= $category_listing;
	$content_string .= $all_forum_contents;
	$content_string .= '</div>';
	//snd of first tab

	$content_string .= '</div>'; //end of tabs containers
	$content_string .= '</div>'; //end of tabs header
	$content_string .= '</div>';
//   $content_string .= select_per_page();

	return $content_string;
 }

 public function show_tabular_forum($category_relation_statement) {
	$content_string = " ";
	$content_string .='<div>';
	$content_string .='<div id="tabsHeader">';
	$content_string .= '<ul class="tabMain">
     <li><a href="#tabsHeader-1" class="non_ajax">' . gettext('All Topics') . '</a></li>
     <li><a href="#tabsHeader-2" class="non_ajax">' . gettext('All Comments') . '</a></li>
     <li><a href="#tabsHeader-3" class="non_ajax">' . gettext('Category Listing') . '</a></li>
    </ul>';
	$content_string .='<div class="tabContainer">';

	//start of first tab
	$content_string .= '<div id="tabsHeader-1" class="tabContent">';
	$content_string .= '<div id="forum_topics_ajax">';
	$all_forum_contents = $this->all_forum_topics();
	if ($all_forum_contents) {
	 $content_string .= $all_forum_contents;
	}
	$content_string .= '</div>';
	$content_string .= '</div>';
	//end of first tab
	//start of second tab
	$content_string .= '<div id="tabsHeader-2" class="tabContent">';
	$comment = new extn_comment();
	$content_string .= $comment->view_page();
	$content_string .= '</div>';
	//snd of second tab
	//start of third tab
	$content_string .= '<div id="tabsHeader-3" class="tabContent">';
	$content_string .= $category_relation_statement;
	$content_string .= '</div>';
	//snd of third tab

	$content_string .= '</div>'; //end of tabs containers
	$content_string .= '</div>'; //end of tabs header
	$content_string .= '</div>';
//   $content_string .= select_per_page();

	return $content_string;
 }

 public function showForumList_byConteTypeCategory($pageno = 1, $per_page = 5, $query_string = "") {
	$content_string = " ";
	$result = $this->_getContent_byConteTypeCategory($pageno, $per_page, $query_string);
	$con_count = 0;
	$content_string .='<div>';
	if ($result) {
	 if (count($result) > 0) {
		$content_string .=!empty($result[0]->category) ? '<span class="heading">' . $result[0]->category . '</span>' : '';
		$content_string .='<table class="table table-striped table-hover"><thead> 
						 <tr class="headerBgColor">
							<th class="topics">' . gettext('Topics') . '</th>
							<th class="replies">' . gettext('Replies') . '</th>
							<th class="created_by">' . gettext('Created By') . '</th>
							<th class="post_date">' . gettext('Post Date') . '</th>
						 </tr>
						</thead>';
		foreach ($result as $records) {
		 $no_of_replies = extn_comment::count_by_reference_table_and_id('content', $records->content_id);
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
		 $content_string .= empty($records->username) ? 'selfWeb' : ino_getUserName_from_email($records->username);
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
	$table_name = 'c_' . $content_type_name;

	switch (DB_TYPE) {
	 case 'ORACLE' :
		$table_name = strtoupper($table_name);
		$sql = " SELECT * FROM " . $table_name . " where content_id=:content_id ";
		break;

	 default:
		$sql = " SELECT * FROM " . $table_name . " where content_id=:content_id ";
		break;
	}
	$sql = ino_perPageSql_i($sql, 1);
	$value_a = ['content_id' => $content_id];
	$result = self::find_by_sql_i($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 public static function content_find_by_contentTypeConentId($content_type_name, $content_id) {
	$table_name = 'c_' . $content_type_name;
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$table_name = strtoupper($table_name);
		$sql = " SELECT * FROM " . $table_name . " where content_id=:content_id ";
		break;

	 default:
		$sql = " SELECT * FROM " . $table_name . " where content_id=:content_id ";
		break;
	}
	$sql = ino_perPageSql_i($sql, 1);
	$value_a = ['content_id' => $content_id];
	$result = self::find_by_sql_i($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 public static function content_summary_by_content_id($content_type_name, $content_id) {
	global $dbc;
	$table_name = 'c_' . $content_type_name;
	$sql = "SELECT SUBSTRING(content,1,2000) AS content_summary " .
					"FROM " . $table_name . " where content_id={$content_id} ";
	$sql = ino_perPageSql_i($sql, 1);
	$prepare = $dbc->connection->prepare($sql);
	$prepare->execute();
	$result_array = $prepare->fetchAll(PDO::FETCH_CLASS);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_childs_of_parent_id($parent_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where parent_id=:parent_id ";
	$value_a = ['parent_id' => $parent_id];
	$result = self::find_by_sql_i($sql, $value_a);
	return $result;
 }

 public static function find_summary_by_id($content_id) {
//	$selectFields = " SUBSTRING(content,1,$this->_summary_noof_char) AS content_summary , " .
//					implode(", ", $this->field_a);
	$sql = "SELECT * FROM "
					. self::$table_name . " 
            where content_id=:content_id ";
	$sql = ino_perPageSql_i($sql, 1);
	$value_a = ['content_id' => $content_id];
	$result_array = self::find_by_sql_i($sql, $value_a);
	return !empty($result_array) ? array_pop($result_array) : false;
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

 public static function content_summaryList_byConteTypeCategory($content_type_id, $category_id, $pageno = 1, $per_page = 5, $query_string = "", $current_url = '') {
	$content_string = " ";
	$sql = " SELECT content.content_id, content.content_type_id, content.subject, content.creation_date, content.created_by, ";
	$sql .= " category_reference.category_reference_id, category_reference.major_category_id, 
	        category_reference.category_id, category_reference.reference_type  ";
	$sql .= ' FROM content LEFT JOIN category_reference ON content.content_id = category_reference.reference_id ';
	$sql .= " WHERE content.content_type_id = :content_type_id ";
	$sql .= " AND category_reference.category_id = :category_id ";
	$sql .= " AND category_reference.reference_table = 'content' ";
	$sql .= " ORDER BY content.content_id DESC ";


	$count_sql = " SELECT COUNT(content.content_id) ";
	$count_sql .= ' FROM content LEFT JOIN category_reference ON content.content_id = category_reference.reference_id ';
	$count_sql .= " WHERE content.content_type_id = :content_type_id ";
	$count_sql .= " AND category_reference.category_id = :category_id ";
	$count_sql .= " AND category_reference.reference_table = 'content' ";

	$content_type_name = content_type::find_by_id($content_type_id)->content_type;


	if (!empty($per_page)) {

	 $total_count = self::count_all_by_sql($count_sql);

	 $pagination = new pagination($pageno, $per_page, $total_count);
	 $pagination->setProperty('_path', 'content');
	 $pagination->setProperty('_query_string', $query_string);
	 $sql = ino_perPageSql_i($sql, $per_page, $pagination->offset());
	}

	$value_a = ['content_type_id' => $content_type_id, 'category_id' => $category_id];
	$result = self::find_by_sql_i($sql, $value_a);
	if (count($result) > 0) {
	 $content_string .='<table id="summary_list" class="top_margin10 form_line_data_table"><thead> 
						 <tr>
							<th>' . gettext('Summary') . '</th>
							<th>' . gettext('Creation Date/Created By') . '</th>
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
		$content_string .= gettext('Read more') . '.. </a>';
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
	echo gettext('Read more') . '.. </a>';
	echo '</div>';
	echo '</div>';
 }

 public static function content_by_id($content_type_name, $content_id) {
	//creation of extra content
	$content_statemnt = "";
	$content_type = content_type::find_by_content_type($content_type_name);
	$extra_fields = new_content_type::find_fields_by_id($content_type->content_type_id);
	$content_field_array = self::$content_field_array;
	$fiela_label_arr = [];
	foreach ($extra_fields as $records) {
	 $content_field_array[] = strtolower($records->field_name);
	 array_push($fiela_label_arr, strtolower($records->field_label));
	}
	$extra_content = self::content_find_by_contentTypeConentId($content_type_name, $content_id);

	if ($extra_content) {
	 foreach ($content_field_array as $key => $value) {
		if (key_exists($key, $fiela_label_arr)) {
		 $field_label = $fiela_label_arr[$key];
		} else {
		 $field_label = null;
		}

		if ($value == 'content') {
		 switch (DB_TYPE) {
			case 'ORACLE' :
			 $extra_content->$value = stream_get_contents($extra_content->$value);
			 break;
		 }
		}

		if ($value != 'content_id' && !empty(trim($extra_content->$value))) {
		 if ($value == 'content') {
			$content_statemnt .= ($extra_content->$value);
		 } else {
			$content_statemnt .= '<h2 class="extra_content ' . $field_label . ' ">' . $field_label . '</h2>' . ($extra_content->$value);
		 }
		}
	 }
	}

	return $content_statemnt;
 }

 public static function content_count_by_categoryId_contentType($category_id, $content_type_name = 'documentation') {
	$count_sql = " SELECT COUNT(content.content_id) ";
	$count_sql .= ' FROM content, category_reference , content_type  ';
	$count_sql .= " WHERE content.content_type_id =  content_type.content_type_id ";
	$count_sql .= " AND category_reference.category_id = '{$category_id}' ";
	$count_sql .= " AND category_reference.reference_table = 'content' ";
	$count_sql .= " AND content.content_id = category_reference.reference_id";
	$count_sql .= " AND content_type.content_type = '{$content_type_name}' ";

	$total_count = self::count_all_by_sql($count_sql);
	return $total_count;
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
