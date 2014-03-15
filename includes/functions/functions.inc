<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function autoLoadFromCwd($className) {
 $filename = getcwd() . DS . 'class_' . $className . ".inc";
 if (is_readable($filename)) {
	require $filename;
 }
}

function autoLoadModules($className) {
 $paths = explode('_', $className);
 $path = $paths[0] . '/';
 $path .= $paths[1] . '/';
 $filename = getcwd() . "/modules/" . $path . 'class_' . $className . ".inc";
 if (is_readable($filename)) {
	require $filename;
 } else {
	$filename = getcwd() . "/../../" . $path . 'class_' . $className . ".inc";
	if (is_readable($filename)) {
	 require $filename;
	}
 }
}

function show_reference_doc($class_name, $primar_column_value) {
 $primary_column = $class_name::$primary_column;
 if((!empty($class_name)) && (!empty($primar_column_value)) && (!empty($primary_column))){
 return '<a href=\'form.php?class_name='. $class_name . '&gl_journal_header_id=' . $primar_column_value. '&mode=2\'>View Reference Doc</a>';
 }else{
	return false;
 }
}

function autoLoadExtensions($className) {
 $paths = explode('_', $className);
// foreach($paths as $key=>$value){
//	$path .= $key>0 ? str_replace('.inc', '', $value).'/' : null;
// }
 $path = $paths[0] . '/';
 $path .= $paths[1] . '/';
 $filename = getcwd() . "/extensions/" . $path . 'class_' . $className . ".inc";
 if (is_readable($filename)) {
	require $filename;
 } elseif (is_readable("../../extensions/" . $path . 'class_' . $className . ".inc")) {
	require "/extensions/" . $path . 'class_' . $className . ".inc";
 }
}

spl_autoload_register("autoLoadFromCwd");
spl_autoload_register("autoLoadModules");
spl_autoload_register("autoLoadExtensions");

function pa($array = "") {
 echo '<div class="message">Printing array/object <pre>';
 print_r($array);
 echo '</pre></div>';
}

function get_dbColumns($table_name) {
 if (!empty($table_name)) {
	global $dbc;
	$sql_fields = " SHOW COLUMNS FROM  " . $table_name;
	$prepare = $dbc->connection->prepare($sql_fields);
	try{
	$prepare->execute();
	}catch(Exception $e){
	 echo " $table_name not found. Error on functions @L72 ". $e->getMessage();
	}
	
	$fields = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
	return $fields;
 }
}

function find_by_sql($sql = "") {
 global $dbc;
 $prepare = $dbc->connection->prepare($sql);
 $prepare->execute();
 $result_fetchAll = $prepare->fetchAll(PDO::FETCH_CLASS);
 return $result_fetchAll;
}

//search function with $_GET criterias
function ino_getSearch() {
 $whereFields = array();
 if (!empty($_GET['submit_search']) && (!empty($_GET['search_class']))) {
	$class = $_GET['search_class'];
	$$class = new $class;
	$per_page = (int) $_GET['per_page'];
	$pageno = !(empty($_GET['pageno'])) ? (int) $_GET['pageno'] : 1;
	$column_array = $class::$column_array;
	$search_array = $class::$search_array;
	$table_name = $class::$table_name;
	$key_column = (isset($class::$key_column)) ? $class::$key_column : false;

	if (!empty($_GET['new_column'])) {
	 $new_column = $_GET['new_column'];
	 array_push($column_array, $new_column);
	}
//to check number of criterias
	$noof_criteria = 0;
	foreach ($search_array as $key => $value) {
	 if (!empty($_GET[$value])) {
		if (strpos($value, '_id') !== false) {
		 $whereFields[] = sprintf("`%s` = %s ", $value, trim(mysql_prep($_GET[$value])));
		} else {
		 $whereFields[] = sprintf("`%s` LIKE '%%%s%%'", $value, trim(mysql_prep($_GET[$value])));
		}
		$noof_criteria++;
	 }
	}

	if (count($whereFields) > 0) {
// Construct the WHERE clause by gluing the fields - together with a " AND " separator.
	 $whereClause = " WHERE " . implode(" AND ", $whereFields);
// And then create the SQL query itself.
	 $sql = "SELECT * FROM " . $table_name . $whereClause;
	 $count_sql = "SELECT COUNT(*) FROM " . $table_name . $whereClause;
	} else {
	 $sql = "SELECT * FROM " . $table_name;
	 $count_sql = "SELECT COUNT(*) FROM " . $table_name;
	}

	if ($key_column) {
	 $sql .= ' ORDER BY ' . $key_column . ' ' . 'DESC';
	}

	$total_count = $class::count_all_by_sql($count_sql);

	if (!empty($per_page)) {
	 global $pagination;
	 $pagination = new pagination($pageno, $per_page, $total_count);
	 $sql .=" LIMIT {$per_page} ";
	 $sql .=" OFFSET {$pagination->offset()}";
	}

	echo "<br><br><br>sql is $sql";
	$search_result = $class::find_by_sql($sql);
	return !(empty($search_result)) ? $search_result : false;
 }
}

function array_shift2($array) {
 $x = array_shift($array);
 return array_shift($x);
}

function null_instantitae($className) {
 $class = new $className;
 foreach ($class::$field_array as $key => $value) {
	$class->$value = "";
 }
 return $class;
}

function remove_querystring_var($url, $key) {
 $url = preg_replace('/(.*)(\?|&)' . $key . '=[^&]+?(&)(.*)/i', '$1$2$4', $url . '&');
 $url = substr($url, 0, -1);
 return $url;
}

function thisPage_url() {
 $current_page = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);
 $protocol = 'http' . (!empty($_SERVER['HTTPS']) ? 's' : '');
 $root = $protocol . '://' . $_SERVER['SERVER_NAME'];
 $current_path = $root . $current_page;
 if (!empty($_GET['class_name'])) {
	$current_path .= '?class_name=' . $_GET['class_name'];
 }
 if ((!empty($_GET['mode'])) && (empty($_GET['class_name']))) {
	$current_path .= '?mode=' . $_GET['mode'];
 } else if (!empty($_GET['mode'])) {
	$current_path .= '&mode=' . $_GET['mode'];
 }
 return $current_path;
}

function ino_print_error($error = "") {
 if (!empty($error)) {
	foreach ($error as $key => $value) {
	 echo "<br/> $key : $value ";
	}
 }
}

function ino_date($date, $format = 'Y-m-d') {
 if (empty($date)) {
	return NUll;
 } elseif ($date == '0000-00-00') {
	return NUll;
 } else {
	return date($format, strtotime($date));
 }
}

function current_time($only_date = "") {
 $time = time();
 if ($only_date) {
	return strftime("%Y-%m-%d", $time);
 } else {
	return strftime("%Y-%m-%d %H:%M:%S", $time);
 }
}

function ino_eval($string) {
 ob_start();
 echo eval($string);
 $evaled_string = ob_get_contents();
 ob_end_clean();
 return $evaled_string;
}

//function ino_eval($string) {
// $verify_code = substr($string, 0, 2);
// if ($verify_code == '<?') {
//	ob_start();
//	$string_value = substr($string, 5, strlen($string));
//	print eval($string_value);
//	$evaled_string = ob_get_contents();
//	ob_end_clean();
// } else {
//	$evaled_string = $string;
// }
//
// return $evaled_string;
//}

function include_template($template = "") {
 defined('THEME_DIR') ? null : define('THEME_DIR', DS . 'themes' . DS . 'default');
 is_readable(THEME_DIR . DS . 'header.inc');
 require_once(INC_BASICS . DS . $template);
}

function ino_include($theme_dir, $template = "") {
 $include_path = false;
 if (is_readable("$theme_dir/$template")) {
	$include_path = "$theme_dir/$template";
 } elseif (is_readable("$theme_dir/modules/$template")) {
	$include_path = "$theme_dir/modules/$template";
 } elseif (is_readable("$theme_dir/extensions/$template")) {
	$include_path = "$theme_dir/extensions/$template";
 } elseif (is_readable("$template")) {
	$include_path = "$template";
 } else {
	$error = "No template found! for $template in $theme_dir ";
	throw new Exception($error);
 }
 return $include_path;
}

function include_find_page() {
 require_once(INC_BASICS . DS . "find_page.inc");
}

function current_dir_path() {
 $path = dirname($_SERVER[PHP_SELF]);
 $position = strrpos($path, '/');
 $url_wo_file = substr($path, 1, $position);
 $dir_path = 'http://' . $_SERVER['SERVER_NAME'] . '/' . $url_wo_file;
 return $dir_path;
}

function redirect_to($location = NULL) {
 if ($location != NULL) {
	header("Location: {$location}");
	exit;
 }
}

function query_result_issue($result) {
 if (!$result) {
	die("Data base error " . mysql_error());
 }
}

function mysql_prep($value) {
 return $value;
}

function ino_showDecimal($number, $decimal = '.') {
 if ((!empty($number))) {
	$exploded_number = explode($decimal, $number);
	if ((!empty($exploded_number[1])) && ((int) $exploded_number[1] > 0 )) {
	 $final_number = rtrim(number_format($exploded_number[0]) . $decimal . $exploded_number[1], '0');
//	 echo ' in 1 ';
	} else {
//	 echo ' in 2 ';
	 $final_number = number_format($exploded_number[0]);
	};
 } else {
//	echo ' in 3 ';
	$final_number = $number;
 }
// echo "$number is $final_number ";
 return $final_number;
}

//moved to insave class as save_class needs to be deleted
function saveClass($module, $class, $key_field, $primary_column) {
 global $ie;
 $submit_class = 'submit_' . $class;
 if (!empty($_POST[$submit_class]) && empty($_POST['download'])) {
	$count = 0;
	for ($i = 0; $i < count($_POST[$key_field]); $i++) {
	 $primary_column = $class::$primary_column;
	 $$class = new $class;
	 if ((empty($_POST['item_id'][$i])) && (!empty($_POST['item_number'][$i])) && (!empty($_POST['org_id']))) {
		$$class->item_id = item::find_item_id_from_itemNumber_OrgId($_POST['item_number'][$i], $_POST['org_id']);
	 }

	 foreach ($class::$field_array as $key => $value) {
		if (!empty($_POST[$value][$i])) {
		 $$class->$value = $_POST[$value][$i];
		} else {
		 $$class->$value = NULL;
		}
	 }

	 if (!empty($$class->dateFields)) {
		foreach ($$class->dateFields as $key => $value) {
		 if (!empty($_POST[$value][$i])) {
			$$class->$value = date('Y-m-d', strtotime($_POST[$value][$i]));
		 } else {
			$$class->$value = NUll;
		 }
		}
	 }

	 if (!empty($class::$fields_inForm_notInDataBase)) {
		foreach ($class::$fields_inForm_notInDataBase as $key => $value) {
		 $$class->$value = "";
		}
	 }

	 if (!empty($class::$fields_inHeader_needsToBeInserted_inPOST)) {
		foreach ($class::$fields_inHeader_needsToBeInserted_inPOST as $key => $value) {
		 if (!empty($_POST[$value][$i])) {
			$$class->$value = mysql_prep($_POST[$value][$i]);
		 } else {
			$$class->$value = $_POST[$value][0];
		 }
		}
	 }

	 if (!empty($$class->base_encoded_array)) {
		foreach ($$class->base_encoded_array as $key => $value) {
		 if (!empty($_POST[$value][$i])) {
			$$class->$value = base64_encode($_POST[$value][$i]);
		 } else {
			$$class->$value = "";
		 }
		}
	 }

	 if (!empty($$class->checkbox)) {
		foreach ($$class->checkbox as $key => $value) {
		 if (isset($value)) {
			$valueCount = $value;
		 } else {
			$valueCount = $value . $count;
		 }
		 if (isset($_POST[$valueCount])) {
			$$class->$value = 1;
		 } else {
			$$class->$value = 0;
		 }
		 unset($value);
		}
	 }

	 if (!empty($_POST['file_id_values'])) {
		$$class->file_id_values = $_POST['file_id_values'];
	 }

	 if (!empty($_POST['category_id'])) {
		$posted_category_ids = array();
		foreach ($_POST['category_id'] as $records) {
		 $posted_category_ids[] = $records;
		}
		if ($class == 'content_type') {
		 $category_reference_type = "1";
		} else {
		 $category_reference_type = "2";
		}
	 }

	 if (method_exists($$class, '_before_submit')) {
		$$class->_before_submit();
	 }

	 $time = time();
	 $$class->creation_date = strftime("%Y-%m-%d %H:%M:%S", $time);
	 if ((isset($_SESSION)) && (!empty($_SESSION['username']))) {
		$$class->created_by = $_SESSION['username'];
	 } else {
		$$class->created_by = 'selfWeb';
	 }
	 $$class->last_update_date = $$class->creation_date;
	 $$class->last_update_by = $$class->created_by;

	 echo "<pre>";
	 print_r($$class);
	 $required_field_flag = true;
	 foreach ($$class->requiredField as $key => $value) {
		$required_field_flag = $required_field_flag && (!empty($$class->$value));
		if (empty($$class->$value)) {
		 echo "<br/> Mandatory $value is missing";
		}
	 }

	 if ($required_field_flag) {
		try {
		 $result = $$class->save();
		 $error = [ 'Save result :!' => $result];
		 array_push($ie->message, $error);
		 $new_entry = true;
		} catch (Exception $e) {
		 $new_entry = false;
		 $$ie->page_exception = ['dbObject findBy id Error : ' => $e->getMessage()];
		}
		if ($new_entry) {
		 if (method_exists($$class, '_after_save')) {
			$$class->_after_save();
		 }
		 if ((!(empty($$class->file_id_values))) && (count($$class->file_id_values) > 0)) {
			foreach ($$class->file_id_values as $keys => $values) {
			 $file_reference = new file_reference;
			 $file_reference->file_id = $values;
			 $file_reference->status = 'show';
			 $file_reference->reference_table = $class;
			 $file_reference->reference_id = $$class->$primary_column;
			 $file_reference->save();
			}
		 }
//delete files
		 if (!empty($_POST['delete_file'])) {
			foreach ($_POST['delete_file'] as $key => $file_reference_id) {
			 file_reference::delete($file_reference_id);
			}
		 }
//hide files..change status to hide
		 if (!empty($_POST['[hide_file'])) {
			foreach ($_POST['[hide_file'] as $key => $file_reference_id) {
			 $file_ref = file_reference::find_by_id($file_reference_id);
			 $file_reference = new file_reference;
			 foreach (file_reference::$field_array as $key => $value) {
				if (!empty($file_ref->$value)) {
				 $file_reference->$value = $file_ref->$value;
				}
			 }
			 $file_reference->status = 'hide';
			}
			$file_reference->save();
		 }

//     add Categories in categoegory reference table
		 if ((!(empty($posted_category_ids))) && ($class != 'category') && (count($posted_category_ids) > 0)) {
			foreach ($posted_category_ids as $keys => $values) {
			 if (!empty($values)) {
				$category_reference = new category_reference;
				$category_reference->major_category_id = category::find_major_category_id($values);
				$category_reference->category_id = $values;
				$category_reference->reference_type = $category_reference_type;
				$category_reference->reference_table = $class;
				$category_reference->reference_id = $$class->$primary_column;
				$check_category = category_reference::check_majorCategory_in_categoryReference($category_reference->major_category_id, $class, $category_reference->reference_id);

				if (($check_category)) {
				 $category_reference->category_reference_id = $check_category->category_reference_id;
				} else {
				 $category_reference->category_reference_id = "";
				}
				if ($values == 'remove') {
				 $category_reference->delete($category_reference->category_reference_id);
				} else {
				 $category_reference->save();
				}
			 }
			}
		 }
		}//end of after save functions
	 } else {
		$error = [ 'Input Error!' => 'Mandatory Fields are missing. '];
		array_push($ie->page_exception, $error);
	 }
	 $count++;
	}
	return $$class;
//  complete of for loop
 }
}

function get_postArray_From_jqSearializedArray($serialezed_postedArray) {
 $nameArray = [];
 $valueArray = [];
 $postArray = [];
 foreach ($serialezed_postedArray as $array_var) {
	$name = str_replace("[]", "", $array_var['name']);
	$value = $array_var['value'];
	if (!(in_array($name, $nameArray))) {
	 array_push($nameArray, $name);
	}
	array_push($valueArray, array($name => $value));
 }

 foreach ($nameArray as $key => $value) {
	$$value = array();
	foreach ($valueArray as $finalArray) {
	 if (array_key_exists($value, $finalArray)) {
		array_push($$value, $finalArray[$value]);
	 }
	}
	$postArray[$value] = $$value;
 }
 return $postArray;
}

function content_view_statement($extension_obj, $extension) {
 if (!empty($extension::$view_fields)) {
	$view_filed_array = $extension::$view_fields;
	$content_view_statement = "<ul id=\"content_view_ulid\">";
	foreach ($view_filed_array as $key => $value) {
	 $content_view_statement .= "<li class=\"content_details $value \"><ul class=\"content_details_inner_ul\">";
	 $content_view_statement .= "<li class=\"key \">$value</li>";
	 $object_value = $extension_obj->{$value};
	 $content_view_statement .= "<li class=\"value \">$object_value</li>";
	 $content_view_statement .= "</ul></li>";
	}
	$content_view_statement .= "</ul>";
 } else {
	$content_view_statement = "<ul id=\"content_view_ulid\">";
	foreach ($extension_obj as $key => $values) {
	 $content_view_statement .= "<li class=\"content_details $key \"><ul class=\"content_details_inner_ul\">";
	 $content_view_statement .= "<li class=\"key \">$key</li>";
	 $content_view_statement .= "<li class=\"value \">$values</li>";
	 $content_view_statement .= "</ul></li>";
	}
	$content_view_statement .= "</ul>";
 }
 return $content_view_statement;
}

//function to be called by json_saveLineData, json_saveLineData2 & json_saveLineData3
function json_save_line($module, $class, $keyField, $primaryColumn, $linedata) {
// echo "<br><br><br>primaryColumn is $primaryColumn";
 if (!empty($linedata)) {
	$postArray = get_postArray_From_jqSearializedArray($linedata);
	$submit_button = 'submit_' . $class;
	$postArray[$submit_button] = '1';

//			echo "<pre>";
//		print_r($_POST);

	if (!empty($_POST['detailData'])) {
	 $_posted_detail_line = $_POST['detailData'];
	}
	$_POST = $postArray;

	if ((!empty($_POST[$keyField])) && (!empty($_POST[$keyField][0]))) {
	 $$class = saveClass($module, $class, $keyField, $primaryColumn);

	 $$primaryColumn = $$class->$primaryColumn;

	 if ((!empty($$class)) && (count($$class) > 1)) {
		echo '<div class="message">Data is sucessfully saved! </div>';
		echo '<ul id="linids">';
		foreach ($$class as $array) {
		 echo '<li class="' . $array->$keyField . '">' . $array->$primaryColumn . '</li>';
		}
		echo '</ul>';
	 } elseif (!empty($$class->$primaryColumn)) {
		echo '<div class="message">Data is sucessfully saved! </div>';
		echo '<div id="headerId">' . $$class->$primaryColumn . '</div>';
	 } else {
		global $ie_array_page;
		global $ie;
		echo '<div class="message"> Error Code - F01! </div> ';
		if (!empty($ie_array_page)) {
		 echo $ie->show_pageErrors($ie_array_page);
		}
	 }
	}
 }
}

//function used to save 2nd form (1st line form of line) where multile forms with multiple lines are used 
//ex : Paymet term schdule form
//saves forms with multiple lines but without details - ex BOM
function json_saveLineData($module, $class, $keyField, $primaryColumn) {
 if (!empty($_POST['lineData'])) {
	$linedata = $_POST['lineData'];
	json_save_line($module, $class, $keyField, $primaryColumn, $linedata);
 }
}

//function used to save 3nd form (2nd line form of line) where multile forms with multiple lines are used 
//ex : Paymet term discount form
function json_saveLineData2($module, $class, $keyField, $primaryColumn) {
 if (!empty($_POST['lineData2'])) {
	$linedata = $_POST['lineData2'];
	json_save_line($module, $class, $keyField, $primaryColumn, $linedata);
 }
}

//function to save both line & detail data
function json_saveLineDetail($module, $class, $keyField, $primaryColumn, $class2, $keyField2, $primaryColumn2) {
 if (!empty($_POST['lineData'])) {
	$linedata = $_POST['lineData'];
	if (!empty($linedata)) {
	 $postArray = get_postArray_From_jqSearializedArray($linedata);
	 $submit_button = 'submit_' . $class;
	 $postArray[$submit_button] = '1';

	 if (!empty($_POST['detailData'])) {
		$_posted_detail_line = $_POST['detailData'];
	 }

	 $_POST = $postArray;
	 if ((!empty($_POST[$keyField])) && (!empty($_POST[$keyField][0]))) {
		$$class = saveClass($module, $class, $keyField, $primaryColumn);
		$$primaryColumn = $$class->$primaryColumn;

		if ((!empty($$class)) && (count($$class) > 1)) {
		 echo '<div class="message">Data is sucessfully saved! </div>';
		 echo '<ul id="linids">';
		 foreach ($$class as $array) {
			echo '<li class="' . $array->$keyField . '">' . $array->$primaryColumn . '</li>';
		 }
		 echo '</ul>';
		} elseif (!empty($$class->$primaryColumn)) {
		 echo '<div class="message">Data is sucessfully saved! </div>';
		 echo '<div id="headerId">' . $$class->$primaryColumn . '</div>';
		} else {
		 echo ' Error code:  ! ';
		}
	 }


	 if (!empty($_posted_detail_line)) {
		$postDetailArray = get_postArray_From_jqSearializedArray($_posted_detail_line);
		$submit_button = 'submit_' . $class2;
		$postDetailArray[$submit_button] = '1';

		$_POST = $postDetailArray;

//		echo "<pre>";
//		print_r($_POST);
		if ((!empty($_POST[$keyField2])) && (!empty($_POST[$keyField2][0]))) {
		 $detail_lineID_array = [];
		 array_push($detail_lineID_array, $$class->$primaryColumn);
		 $_POST[$primaryColumn] = $detail_lineID_array;

		 $$class2 = saveClass($module, $class2, $keyField2, $primaryColumn2);
		 if ((count($$class2)) > 0) {
			echo '<div class="message">Detail line is sucessfully saved! </div>';
			foreach ($$class2 as $key => $details) {
			 if ($key != $class2) {
				echo '<div class="option_detailId">' . $details->$primaryColumn2 . '</div>';
			 }
			}
		 } else {
			global $ie_array_page;
			global $ie;
			echo '<div class="message"> Error Code - F01! </div> ';
			if (!empty($ie_array_page)) {
			 echo $ie->show_pageErrors($ie_array_page);
			}
		 }
		}
	 }
	}
 }
}

//json functions
function json_save($module, $class, $keyField, $primaryColumn, $primaryColumn2 = "") {
 if (!empty($_POST['headerData'])) {
	$postArray = get_postArray_From_jqSearializedArray($_POST['headerData']);
	$submit_button = 'submit_' . $class;
	$postArray[$submit_button] = '1';
	$_POST = $postArray;
//	echo '<div class="message"> <pre>';
//	print_r($_POST);
//	echo '</div>';

	if ($class == 'user') {
	 $_POST = user::user_verification_update($_POST);
	}


	if (!empty($_POST)) {
	 $$class = saveClass($module, $class, $keyField, $primaryColumn);
	}

	if ((!empty($$class)) && (count($$class) > 1)) {
	 echo '<div class="message">Data is sucessfully saved! </div>';
	 echo '<ul id="linids">';
	 foreach ($$class as $array) {
		echo '<li class="' . $array->$keyField . '">' . $array->$primaryColumn . '</li>';
	 }
	 echo '</ul>';
	} elseif (!empty($$class->$primaryColumn)) {
	 echo '<div class="message">Data is sucessfully saved!  ' . $primaryColumn . ' is </div> ';
	 echo '<div id="headerId">' . $$class->$primaryColumn . '</div>';
	 if (!empty($primaryColumn2)) {
		echo '<div id="headerId2">' . $$class->$primaryColumn2 . '</div>';
	 }
	} else {
	 global $ie_array_page;
	 global $ie;
	 echo '<div class="message"> Error Code - F02! </div> ';
	 if (!empty($ie_array_page)) {
		echo $ie->show_pageErrors($ie_array_page);
	 }
	}
 }
}

//Dont use it
function json_saveSingleLine($module, $class, $keyField, $primaryColumn, $header_id) {
 if (!empty($_POST['lineData'])) {
	$postArray = get_postArray_From_jqSearializedArray($_POST['lineData']);
	$submit_button = 'submit_' . $class;
	$postArray[$submit_button] = '1';
	$postArray[$header_id] = $_POST['header_id'];
	$_POST = $postArray;

//	echo '<pre>';
//	print_r($_POST);

	$$class = saveClass($module, $class, $keyField, $primaryColumn);

	if ((!empty($$class)) && (count($$class) > 1)) {
	 echo '<div class="message">Data is sucessfully saved! </div>';
	 echo '<ul id="linids">';
	 foreach ($$class as $array) {
		echo '<li class="' . $array->$keyField . '">' . $array->$primaryColumn . '</li>';
	 }
	 echo '</ul>';
	} elseif (!empty($$class->$primaryColumn)) {
	 echo '<div class="message">Data is sucessfully saved! </div>';
	 echo '<div id="headerId">' . $$class->$primaryColumn . '</div>';
	} else {
	 global $ie_array_page;
	 global $ie;
	 echo '<div class="message"> Error Code - F03! </div> ';
	 if (!empty($ie_array_page)) {
		echo $ie->show_pageErrors($ie_array_page);
	 }
	}
 }
}

function json_delete($class, $lineName = "") {
 if (!empty($_GET['delete']) && $_GET['delete'] == 1) {

	if (!empty($_GET['line_id'])) {
	 $delete_id = $_GET['line_id'];
	} elseif (!empty($_GET['detail_id'])) {
	 $delete_id = $_GET['detail_id'];
	} elseif (!empty($_GET[$lineName])) {
	 $delete_id = $_GET[$lineName];
	} else {
	 $delete_id = "";
	}

	if (!empty($delete_id)) {
	 $result = $class::delete($delete_id);
	} else {
	 $result = "Id to delete is not found";
	}

	if ($result == 1) {
	 echo 'Line is deleted!';
	} else {
	 global $ie_array_page;
	 global $ie;
	 echo '<div class="message"> Error Code - F04! </div> ';
	 if (!empty($ie_array_page)) {
		echo $ie->show_pageErrors($ie_array_page);
	 }
	}
 }
}

function add_new_search_criteria() {
 if (!empty($_GET["new_search_criteria"])) {
	$new_search_criteria = $_GET["new_search_criteria"];
	$new_search_criteria_statment = "<li><label> $new_search_criteria  : </label>";
	$new_search_criteria_statment .= "<input type=\"search\" name=\"$new_search_criteria\" id=\"$new_search_criteria\" 
           value=\"\"  maxlength=\"50\" >";
	echo "$new_search_criteria_statment";
 }
}

function execution_time() {
 $start_time = $_SERVER["REQUEST_TIME"];
 echo "<br />Execution time :" . (microtime(true) - $start_time) . "</br>";
}

function array2csv(array &$array) {
 if (count($array) == 0) {
	return null;
 }
 ob_start();
 $df = fopen("php://output", 'w');
 fputcsv($df, array_keys(reset($array)));
 foreach ($array as $row) {
	fputcsv($df, $row);
 }
 fclose($df);
 return ob_get_clean();
}

function download_send_headers($filename) {
 header("Pragma: public");
 header("Expires: 0");
 header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
 header("Content-Type: application/force-download");
 header("Content-Type: application/octet-stream");
 header("Content-Type: application/download");
 header("Content-Disposition: attachment;filename={$filename}");
 header("Content-Transfer-Encoding: binary");
}

?>
