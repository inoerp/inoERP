<?php
if (!empty($extension)) {
 $msg = array();
 $extension_exists = 0;
 $create_path = 0;
 $run_functions_after_save = "";
 $search_result = "";
 $extensionClassArray = [
		 "path",
		 "page",
		 "blog",
		 "forum",
		 "issue_tracker",
		 "content_type",
		 "block",
		 "category",
		 "content",
		 "view",
		 "user",
		 "user_role"
//     "block_content"
 ];



//Dont delete
//$url = $_SERVER['REQUEST_URI'];
//$ulr_vars = explode("/", $url);
//$extension="";
//
//foreach ($ulr_vars as $key => $value){
// if(in_array($value, $extensionClassArray)){
//  $extension = $value;
//  //  break;
// }
//}


 if (in_array($extension, $extensionClassArray)) {
	$extension_exists = 1;
 }

 $pageno = !(empty($_GET['pageno'])) ? (int) $_GET['pageno'] : 1;


 $query_string = htmlentities($_SERVER['QUERY_STRING']);
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

 //remove double & from query strinf
 if (!empty($query_string)) {
	if (strpos($query_string, '&&') !== false) {
	 $query_string = str_replace('&&', '&', $query_string);
	}
 }

 //---------1. End of page, per_page & query steing modififications-------------------

 if (!empty($extension) && ($extension_exists == 1)) {

//  check if table name exists.
//          If table name doesnt exists then table name is same as extension namespace
//           else extension name will be same as table name
//           Normally table name shall be same extension name (same as class name).
//           But extensions such as block which contains two table name (& thus two class)might have diff template files

	$class_name = $extension;

	if (empty($table_name)) {
	 $table_name = $extension;
	} else {
	 $extension = $table_name;
	}

	$$extension = new $extension;

//$field array represents all the fields in the class
	$field_array = $extension::$field_array;

	if (!empty($extension::$array_field_array)) {
	 $array_field_array = $extension::$array_field_array;
	}
	if (isset($extension::$base_encoded_array)) {
	 $base_encoded_array = $extension::$base_encoded_array;
	}
//search array is used for srach fields & while condition in SQL query
	if (!empty($extension::$initial_search_array)) {
	 $initial_search_array = $extension::$initial_search_array;
	}

	$search_array = $extension::$field_array;


	$requiredField_array = $extension::$requiredField_array;
	//default columns to be shown on query/view page
	$column_array = $extension::$column_array;
	//Column array represents all the fixed coulmns in result table
	if (empty($_GET['column_array'])) {
	 $column_array = $extension::$column_array;
	}

//	------------------------2.1 end of array assingments------------------------------------------

	if (empty($_POST)) {
	 foreach ($field_array as $key => $value) {
		$$extension->$value = "";
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

	$extension_id = $extension . '_id';

	if (!empty($_GET[$extension_id])) {
	 $$extension_id = $_GET[$extension_id];
//   echo '<br><br>$table_name, $$extension_id'. $table_name. $$extension_id;
	 $$extension = $extension::find_by_id($$extension_id);
	 $file = extn_file::find_by_reference_table_and_id($table_name, $$extension_id);

	 if ($extension != 'category') {
		$category = category::find_by_reference_table_and_id($table_name, $$extension_id);
	 }
	 $comments = extn_comment::comment_list($table_name, $$extension_id, $per_page, $pageno, $query_string, $$extension_id);

	 foreach ($extension::$checkbox_array as $key => $value) {
//  $value_cb = $value . '_cb';
//  echo "<br/> cb of $value is  $extension->$value";
		if ((!empty($$extension->$value)) && ($$extension->$value == 1)) {
		 $$extension->$value = 1;
		} else {
		 $$extension->$value = "NULL";
		}
	 }
	}

	//for contentes only
	if (!empty($_GET['content_type'])) {
	 $content_type_name = $_GET['content_type'];
	 $content_type = content_type::find_by_content_type($content_type_name);
	 content::$content_table_name = 'c_' . $content_type_name;

	 $extra_fields = new_content_type::find_fields_by_id($content_type->content_type_id);
	 $$extension->content_type_id = $content_type->content_type_id;
//echo '<br> $$extension->content_type_id is '. $content_type->content_type_id ;

	 $content_field_array = content::$content_field_array;
	 foreach ($extra_fields as $records) {
		$content_field_array[] = $records['Field'];
	 }
	}

	//	--------------2.2 End of value assignment on GET POST value -------------------------
//Creation of serach query
	$whereFields = array();
	if (!empty($_GET['submit_search'])) {
	 if (!empty($_GET['new_column'])) {
		$new_column = $_GET['new_column'];
		array_push($column_array, $new_column);
	 }
//to check number of criterias
	 $noof_criteria = 0;
	 foreach ($search_array as $key => $value) {
		if (!empty($_GET[$value])) {
		 $whereFields[] = sprintf("`%s` LIKE '%%%s%%'", $value, trim(mysql_prep($_GET[$value])));
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

	 $total_count = $extension::count_all_by_sql($count_sql);

	 if (!empty($per_page)) {
		$pagination = new pagination($pageno, $per_page, $total_count);
		$sql .=" LIMIT {$per_page} ";
		$sql .=" OFFSET {$pagination->offset()}";
	 }

	 $search_result = $extension::find_by_sql($sql);

	 foreach ($search_result as $result_e) {

		if (!(empty($extension::$account_array))) {
		 foreach ($extension::$account_array as $key => $value) {
			$value_id = $value . '_id';
			if (!empty($result_e->$value_id)) {
			 $account = coa_combination::find_by_id($result_e->$value_id);
			 if (count($account) != 0) {
				$result_e->$value = $account->combination;
			 } else {
				$result_e->$value = "NULL";
			 }
			}
		 }
		}

		if (!empty($extension::$checkbox_array)) {
		 foreach ($extension::$checkbox_array as $key => $value) {
			$value_cb = $value . '_cb';
			if ($result_e->$value == 1) {
			 $result_e->$value = 1;
			} else {
			 $result_e->$value = "NULL";
			}
		 }
		}
	 }

	 if(empty($view_path)){
		$view_path = "";
	 }
	 if (!empty($search_result)) {
//		$search_result = search::search_result($extension, $column_array, $result, $primary_column);
			$search_result_statement = search::search_result($extension, $column_array, $search_result, $primary_column, $view_path);
	 }
	 
	}
// End of search
//	--------------3. End of Search query & result -------------------------
//Start of Submit - for save & Update
	$submit_extension = 'submit_' . $extension;
//	 	 	 	 		 if(!empty($_POST)){
//	echo '<br/> POST in extn funsion';
// echo '<pre>';
// print_r($_POST);
// echo '<pre>';
// }
//echo "submit_extension is $submit_extension";
	if (!empty($_POST[$submit_extension]) && empty($_POST['download'])) {

	 $$extension = new $extension;
	 
	 	 foreach ($field_array as $key => $value) {
		if (!empty($_POST[$value])) {
		 if(!(is_array($_POST[$value]))){
		 $$extension->$value = trim(mysql_prep($_POST[$value]));
		 }else{
			$$extension->$value = trim(mysql_prep($_POST[$value][0]));
		 }
		} else {
		 $$extension->$value = "";
		}
	 }
	 


	 //applicable only for user extension
	 if ($extension == 'ino_user') {
				if ($_POST['enteredRePassword'][0] == $_POST['enteredPassword'][0]) {
//		 		 $user->password = hash("sha256", $_POST['enteredPassword'][0]);
				 $user->password = crypt($_POST['enteredPassword'][0], 'xjkhrwq$@323sqjheq51234$$');
				 
				 		 $existing_user_check = $user->check_email($user->email);
		 If ($existing_user_check) {
			$required_field_flag = 0;
			$newMsg = "Entered e-mail id is already associated with an user id<br/>
     Enter a different user id";
			array_push($msg, $newMsg);
		 }
		} else {
		 	 $required_field_flag = 0;
		 $newMsg = 'Two different passwords are entered';
		 array_push($msg, $newMsg);
		}
	 }

	 if (!empty($base_encoded_array)) {
		foreach ($base_encoded_array as $key => $value) {
		 if (!empty($_POST[$value])) {
			$$extension->$value = base64_encode($_POST[$value]);
		 } else {
			$$extension->$value = "";
		 }
		}
	 }

	 foreach ($extension::$checkbox_array as $key => $value) {
		$value_cb = $value . '_cb';
		//   echo $value;
		if (isset($_POST[$value])) {
		 $$extension->$value_cb = 1;
		} else {
		 $$extension->$value_cb = 0;
		}
//  echo '<br />'. $value;
//  echo " The value of   of ". $_POST['locator'][$i] .' is ' . $locator->$value_cb ;
	 }

	 if (!empty($_POST['file_id_values'])) {
		$$extension->file_id_values = $_POST['file_id_values'];
		$primary_column = $extension::$primary_column;
	 }

	 //begining of category details
	 if (!empty($_POST['category_id'])) {
		$posted_category_ids = array();
		foreach ($_POST['category_id'] as $records) {
		 $posted_category_ids[] = $records;
		}
//             echo '<pre>';
//             print_r($posted_category_ids);
//             echo '<pre>';

		$primary_column = $extension::$primary_column;
		if ($extension == 'content_type') {
		 $category_reference_type = "1";
		} else {
		 $category_reference_type = "2";
		}
	 }
//end of category details
	 $time = time();
	 $$extension->creation_date = strftime("%Y-%m-%d %H:%M:%S", $time);
	 $$extension->created_by = $_SESSION['username'];
	 $$extension->last_update_date = $$extension->creation_date;
	 $$extension->last_update_by = $$extension->created_by;

//   echo 'Checking Data-----------------------------------';
	 if (!empty($content_type->content_type_id)) {
		$$extension->content_type_id = $content_type->content_type_id;
	 }
//
	 

// echo '<br/>$required_field_flag is '.$required_field_flag;

	 foreach ($requiredField_array as $key => $value) {
		$required_field_flag = $required_field_flag && (!empty($$extension->$value));
		
	 }

	 

	 if ($required_field_flag) {

		$new_entry = $$extension->save();
		if ($new_entry == 1 or $new_entry == 2) {
		 if ($new_entry == 1) {
			$create_path = 1;
		 }
//    echo '<br/> new entry sucessful';
//            echo '<pre>';
//        print_r($$extension);
//        echo '<pre>';
		 $run_functions_after_save = $new_entry;
		 if ((!(empty($$extension->file_id_values))) && (count($$extension->file_id_values) > 0)) {
//       echo '<br/> trying fileid upload';
//       echo '<br/> $primary_column is'.$primary_column;
//       echo '<br/> trying fileid $$extension->$primary_column is ' . $$extension->$primary_column;
			foreach ($$extension->file_id_values as $keys => $values) {
			 $file_reference = new file_reference;
			 $file_reference->file_id = $values;
			 $file_reference->reference_table = $table_name;
			 $file_reference->reference_id = $$extension->$primary_column;
//        echo '<pre>';
//        print_r($file_reference);
//        echo '<pre>';
			 $file_reference->save();
			}
		 }

//     add Categories in categoegory reference table

		 if ((!(empty($posted_category_ids))) && ($extension != 'category') && (count($posted_category_ids) > 0)) {
			foreach ($posted_category_ids as $keys => $values) {
			 $category_reference = new category_reference;
			 $category_reference->major_category_id = category::find_major_category_id($values);
			 $category_reference->category_id = $values;
			 $category_reference->reference_type = $category_reference_type;
			 $category_reference->reference_table = $table_name;
			 $category_reference->reference_id = $$extension->$primary_column;

//       echo '------------$category_reference-----------------';
//       echo '<pre>';
//       print_r($category_reference);
//       echo '<pre>';

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

		 $newMsg = 'Record is Successfully saved';
		 array_push($msg, $newMsg);
		}//end of locator entry & msg
		else {
		 $newMsg = "Record coundt be saved!!" . mysql_error() .
						 ' Returned Value is : ' . $new_entry;
		 array_push($msg, $newMsg);
		}//end of locator insertion else
	 } else {
		$newMsg = "One of the required field is Blank";
		array_push($msg, $newMsg);
	 } //end of locator check & new locator creation
	 //reset all accounts to accounts from id
//  complete of for loop
	}//end of post submit header
//	------------------------------4. End of POST Submit ------------------------------------------------
	$a = $extension;
	$b = $a . '_search';
	$$b = " ";

	if (!((empty($_POST[$extension])) AND (empty($_GET[$extension])))) {
	 if ((!(empty($_GET[$extension]))) && (is_array($_GET[$extension]))) {
		$$b = "";
	 } else {
		if (!empty($_GET[$extension])) {
		 $$b = $_GET[$extension];
		} else {
		 if (!empty($_POST[$extension]) && is_array($_POST[$extension])) {
			$$b = "";
		 } else {
			if (!empty($_POST[$extension])) {
			 $$b = $_POST[$extension];
			}
		 }
		}
	 }
	}
//End of geetting search extension
 }
}
?>


<?php ?>