<?php

//exit the file if request is coming through loader
if (!empty($continue)) {
 return;
}
global $db;
global $dbc;
global $msg;
global $ie_array_page;
$msg = [];
$module_exists = 0;
$run_functions_after_save = "";
$required_field_flag = 1;
$moduleArray = [
		"inventory",
		"subinventory",
		"locator",
		"onhand",
		"option",
		"role",
		"org",
		"address",
		"enterprise",
		"ap",
		'ar',
		"po",
		"gl",
		"bom",
		"wip",
		'user',
		'site_control',
		'extension',
		'sys'
];


$pageno = !(empty($_GET['pageno'])) ? (int) $_GET['pageno'] : 1;

//search order by
$search_order_by = !(empty($_GET['search_order_by'])) ? $_GET['search_order_by'] : '';
$search_asc_desc = !(empty($_GET['search_asc_desc'])) ? $_GET['search_asc_desc'] : '';

$query_string = $_SERVER['QUERY_STRING'];
//per page details
if (!empty($_POST['per_page'])) {
 if (strpos($query_string, 'per_page') !== false) {
	$per_page_value = $_GET['per_page'];
	$per_page_string = '&per_page=' . $per_page_value;
	$new_query_string = str_replace($per_page_string, "", $query_string);
	$query_string = $new_query_string;
	$per_page = (int) $_POST['per_page'];
 } else {
	$per_page = (int) $_POST['per_page'];
 }
 $query_string .= '&per_page=' . $per_page;
 if (strpos($query_string, 'pageno') !== false) {
	$pageno_value = $_GET['pageno'];
	$pageno_string = '&pageno=' . $pageno_value;
	$new_query_string1 = str_replace($pageno_string, "", $query_string);
//	 $_SERVER['QUERY_STRING']=$new_query_string1;
	$query_string = $new_query_string1;
	//	$_SERVER['QUERY_STRING'] = $query_string;
 }
 $pageno = 1;
} elseif (!(empty($_GET['per_page']))) {
 if ($_GET['per_page'] == "all") {
	$per_page = "";
 } else {
	$per_page = (int) $_GET['per_page'];
 }
}

if (empty($per_page)) {
 $per_page = 10;
}

//page number details
if (!empty($query_string)) {
 if (strpos($query_string, 'pageno') !== false) {
	$pageno_value = $_GET['pageno'];
	$pageno_string = 'pageno=' . $pageno_value;
	$new_query_string1 = str_replace($pageno_string, "", $query_string);
//	 $_SERVER['QUERY_STRING']=$new_query_string1;
	$query_string = $new_query_string1;
 }
}

//remove double & from query string
if (!empty($query_string)) {
 if (strpos($query_string, '&&') !== false) {
	$query_string = str_replace('&&', '&', $query_string);
 }
}
//---------1. End of page, per_page & query setting modififications-------------------

if (in_array($module, $moduleArray)) {
 $module_exists = 1;
}
if (!empty($class) && ($module_exists == 1)) {
//$newMsg = 'Checking module exists';
//			 array_push($msg, $newMsg);
 $class_name = $class;

 if (empty($table_name)) {
	$table_name = $class;
 }

 $$class = new $class;

//$field array represents all the fields in the class
 $field_array = $class::$field_array;
 if (!empty($class::$array_field_array)) {
	$array_field_array = &$class::$array_field_array;
 }
 if (!empty($class::$account_array)) {
	$account_field_array = &$class::$account_array;
 }

 if (!empty($class::$checkbox_array)) {
	$checkbox_field_array = $class::$checkbox_array;
 }

 if (isset($class::$dateField_array)) {
	$date_fields = $class::$dateField_array;
 }

 if (isset($class::$base_encoded_array)) {
	$base_encoded_array = $class::$base_encoded_array;
 }

 if (isset($class::$fields_inForm_notInDataBase)) {
	$fields_inForm_notInDataBase = $class::$fields_inForm_notInDataBase;
 }

 if (isset($class::$fields_inHeader_needsToBeInserted_inPOST)) {
	$fields_inHeader_needsToBeInserted_inPOST = $class::$fields_inHeader_needsToBeInserted_inPOST;
 }

//search array is used for srach fields & while condition in SQL query
 if (!empty($class::$initial_search_array)) {
	$initial_search_array = $class::$initial_search_array;
 }
//search array is used for srach fields & while condition in SQL query
 $search_array = $class::$field_array;
//
// $column_array = $class::$column_array;
// //Column array represents all the fixed coulmns in result table
// if (empty($_GET['column_array'])) {
//	$column_array = $class::$column_array;
// }

 if (!empty($class::$requiredField_array)) {
	$requiredField_array = &$class::$requiredField_array;
 }


//	--------------2.1 End of array assingments-------------------------
//	$newMsg = 'Assigning array values';
//			 array_push($msg, $newMsg);
 if (empty($_POST)) {
	foreach ($field_array as $key => $value) {
	 $$class->$value = "";
	}

	foreach ($field_array as $key => $value) {
	 $$class->$value = "";
	}

	if (!empty($fields_inForm_notInDataBase)) {
	 foreach ($fields_inForm_notInDataBase as $key => $value) {
		$$class->$value = "";
	 }
	}

	foreach ($search_array as $key => $value) {
	 if (empty($_GET[$value])) {
		$_GET[$value] = "";
	 }
	}
 }

 //get the primary_id value of the class object
 $class_id = $class . '_id';
 if (!empty($_GET[$class_id])) {
	$$class_id = $_GET[$class_id];
 } elseif (!empty($_POST[$class_id][0])) {
	$$class_id = $_POST[$class_id][0];
 }


 if (!empty($$class_id)) {
	$$class = $class::find_by_id($$class_id);
	$file = file::find_by_reference_table_and_id($table_name, $$class_id);
	$comments = comment::comment_list($table_name, $$class_id, $per_page, $pageno, $query_string, $$class_id);
	if ($class != 'category') {
	 $category = category::find_by_reference_table_and_id($table_name, $$class_id);
	}

	if ((!empty($$class->$primary_column)) && (!empty($class::$addressField_array))) {
	 foreach ($class::$addressField_array as $key => $value) {
		if (!empty($$class->$value)) {
		 $address = address::find_by_id($$class->$value);
		} else {
		 $address = new address();
		}
		$$value = address::show_adrees_details($address);
	 }
	}

	if (method_exists($$class, '_before_showing')) {
	 $$class->_before_showing();
	}
 }

//	--------------2.2 End of value assignment on GET POST value -------------------------
//Creation of serach query
 $whereFields = array();
 if (!empty($_GET['submit_search']) && ($_GET['search_class'] === $class)) {

	if (empty($_GET['column_array'])) {
	 $column_array = $$class->column;
	} else {
	 $column_array = unserialize(base64_decode($_GET['column_array']));
	}

	if (!empty($_GET['new_column'])) {
	 $new_column = $_GET['new_column'];
	 if (!empty($new_column)) {
		foreach ($new_column as $key => $value) {
		 if ((!(is_array($value))) && (!empty($value))) {
			array_push($column_array, $value);
		 }
		}
	 }
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
	if ($noof_criteria == 0) {
	 $newMsg = "No criteria entered";
	 array_push($msg, $newMsg);
	}

	if (count($whereFields) > 0) {

	 // Construct the WHERE clause by gluing the fields
	 // together with a " AND " separator.
	 $whereClause = " WHERE " . implode(" AND ", $whereFields);

	 // And then create the SQL query itself.
	 $sql = "SELECT * FROM " . $table_name . $whereClause;
	 $count_sql = "SELECT COUNT(*) FROM " . $table_name . $whereClause;
	 $all_download_sql = "SELECT * FROM  " . $table_name . $whereClause;
	} else {
	 $sql = "SELECT * FROM " . $table_name;
	 $count_sql = "SELECT COUNT(*) FROM " . $table_name;
	 $all_download_sql = "SELECT * FROM  " . $table_name;
	}

	if ((!empty($search_order_by)) && (!empty($search_asc_desc))) {
	 $sql .= ' ORDER BY ' . $search_order_by . ' ' . $search_asc_desc;
	 $all_download_sql .= ' ORDER BY ' . $search_order_by . ' ' . $search_asc_desc;
	}

	$total_count = $class::count_all_by_sql($count_sql);

	if (!empty($per_page)) {
	 global $pagination;
	 $pagination = new pagination($pageno, $per_page, $total_count);
	 $sql .=" LIMIT {$per_page} ";
	 $sql .=" OFFSET {$pagination->offset()}";
	}

	$search_result = find_by_sql($sql);

	foreach ($search_result as $result_e) {
	 if (!(empty($class::$account_array))) {
		foreach ($class::$account_array as $key => $value) {
		 $value_id = $value . '_id';
		 if (!empty($result_e->$value_id)) {
			$account = coa_combination::find_by_id($result_e->$value_id);
			if (count($account) != 0) {
			 $result_e->$value = $account->combination;
			} else {
			 $result_e->$value = NULL;
			}
		 }
		}
	 }

	 if (!empty($class::$checkbox_array)) {
		foreach ($class::$checkbox_array as $key => $value) {
//			 $value_cb = $value . '_cb';
		 if ($result_e->$value == 1) {
			$result_e->$value = 1;
		 } else {
			$result_e->$value = NULL;
		 }
		}
	 }
	}

	if (empty($view_path)) {
	 $view_path = "";
	}

	if (empty($path)) {
	 $path = $class;
	}

	if (empty($update_path)) {
	 $update_path = "";
	}

	global $search_result_statement;
	if (!empty($search_result)) {
	 $search_result_statement = search::search_result($path, $column_array, $search_result, $primary_column, $view_path, $update_path);
//		 $return_value['search_result'] = $search_result;
	}
 }
// End of search
//	--------------3. End of Search query & result -------------------------
//Start of Submit - for save & Update
//	$newMsg = 'Starting submit';
//	array_push($msg, $newMsg);
//	unset($msg);

 $submit_class = 'submit_' . $class;

//	if (!empty($_POST)) {
//	echo '$_POST[$key_field] is'.$key_field ;
//	echo '$_POST[$key_field] is'. $_POST[$key_field];
//	}

 if (!empty($_POST[$submit_class]) && empty($_POST['download'])) {

	$count = 0;
	for ($i = 0; $i < count($_POST[$key_field]); $i++) {
	 $$class = new $class;
	 if ((empty($_POST['item_id'][$i])) && (!empty($_POST['item_number'][$i])) && (!empty($_POST['org_id']))) {
		$$class->item_id = item::find_item_id_from_itemNumber_OrgId($_POST['item_number'][$i], $_POST['org_id']);
	 }

	 foreach ($field_array as $key => $value) {
		if (!empty($_POST[$value][$i])) {
//		 echo "<br> value is $value";
		 $$class->$value = mysql_prep($_POST[$value][$i]);
		} else {
		 $$class->$value = NULL;
		}
	 }

	 if (!empty($date_fields)) {
		foreach ($date_fields as $key => $value) {
		 if (!empty($_POST[$value][$i])) {
			$$class->$value = mysql_prep(date('Y-m-d', strtotime($_POST[$value][$i])));
		 } else {
			$$class->$value = NULL;
		 }
		}
	 }


	 if (!empty($fields_inHeader_needsToBeInserted_inPOST)) {
		foreach ($fields_inHeader_needsToBeInserted_inPOST as $key => $value) {
		 if (!empty($_POST[$value][$i])) {
			$$class->$value = mysql_prep($_POST[$value][$i]);
		 } else {
			$$class->$value = $_POST[$value][0];
		 }
		}
	 }

	 if (!empty($base_encoded_array)) {
		foreach ($base_encoded_array as $key => $value) {
		 if (!empty($_POST[$value][$i])) {
			$$class->$value = base64_encode($_POST[$value][$i]);
		 } else {
			$$class->$value = "";
		 }
		}
	 }

	 foreach ($class::$checkbox_array as $key => $value) {
//			$value_cb = $value . '_cb';
		if (isset($value)) {
		 $valueCount = $value;
		} else {
		 $valueCount = $value . $count;
		}
//   echo $value;
		if (isset($_POST[$valueCount])) {
		 $$class->$value = 1;
		} else {
		 $$class->$value = 0;
		}
//	   echo "<br/> $value value is ".$$class->$value;
		unset($value);
	 }

	 if (!empty($_POST['file_id_values'])) {
		$$class->file_id_values = $_POST['file_id_values'];
		$primary_column = $class::$primary_column;
	 }

	 //begining of category details
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

	 $primary_column = $class::$primary_column;

	 $time = time();
	 $$class->creation_date = strftime("%Y-%m-%d %H:%M:%S", $time);
	 if (!empty($_SESSION['username'])) {
		$$class->created_by = $_SESSION['username'];
	 } else {
		$$class->created_by = 'selfWeb';
	 }
	 $$class->last_update_date = $$class->creation_date;
	 $$class->last_update_by = $$class->created_by;

	 foreach ($requiredField_array as $key => $value) {
		$required_field_flag = $required_field_flag && (!empty($$class->$value));
		if (empty($$class->$value)) {
		 echo "<br/> Mandatory $value is missing ";
		}
	 }

	 if ($required_field_flag) {
		try {
		 $new_entry = $$class->save();
		} catch (Exception $e) {
		 $new_entry = false;
		 $ie = new ino_exception();
		 $ie->description = 'MYSQL Error!';
		 $ie->message = $e->getMessage();
		 $ie_array_page[] = $ie;
		}
		//			 echo '<pre>';
//	 print_r($$class);
		if ($new_entry == 1 or $new_entry == 2 or is_array($new_entry)) {
		 $run_functions_after_save = $new_entry;

		 if (method_exists($$class, '_after_save')) {
			$$class->_after_save();
		 }

//			  echo "<br/> run_functions_after_save : $run_functions_after_save";

		 if ((!(empty($$class->file_id_values))) && (count($$class->file_id_values) > 0)) {
			foreach ($$class->file_id_values as $keys => $values) {
			 $file_reference = new file_reference;
			 $file_reference->file_id = $values;
			 $file_reference->status = 'show';
			 $file_reference->reference_table = $table_name;
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
				$category_reference->reference_table = $table_name;
				$category_reference->reference_id = $$class->$primary_column;
				$check_category = category_reference::check_majorCategory_in_categoryReference($category_reference->major_category_id, $table_name, $category_reference->reference_id);

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

		 $newMsg = 'Record is sucessfully saved';
		 unset($msg);
		 $msg = array();
		 array_push($msg, $newMsg);
		 array_push($msg, $new_entry);
//			 echo '<br>$new_entry : '. $new_entry;
		}//end of locator entry & msg
	 } else {
		$newMsg = "One of the required field is Blank";
		array_push($msg, $newMsg);
		$ie = new ino_exception();
		$ie->description = 'Input Error!';
		$ie->message = 'Mandatory Field Error!';
		$ie_array_page[] = $ie;
	 }
	 //reset all accounts to accounts from id
//		 $return_value['class'][$$class->$primary_column] = $$class;
	 $pre_loading_output[] = $$class;
	 $count++;
	}
//  complete of for loop
 }//end of post submit header
//	------------------------------4. End of POST Submit ------------------------------------------------
}

if (!empty($pre_loading_output) && count($pre_loading_output) > 1) {
 $returnval = $pre_loading_output;
} else {
 $returnval = $$class;
}
?>
