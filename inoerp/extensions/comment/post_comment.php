<?php include_once("../../include/basics/basics.inc"); ?>
<?php
$dont_check_login = true;

$msg = array();
$extension = "comment";
$required_field_flag = 1;
$pageno = !(empty($_GET['pageno'])) ? (int) $_GET['pageno'] : 1;

if (!(empty($_GET['per_page']))) {
 if ($_GET['per_page'] == "all") {
	$per_page = "";
 } else {
	$per_page = (int) $_GET['per_page'];
 }
} else {
 $per_page = 10;
}

if (empty($table_name)) {
 $table_name = $extension;
}

$$extension = new $extension;
//$field array represents all the fields in the class
$field_array = $extension::$field_array;
//search array is used for srach fields & while condition in SQL query
$search_array = $extension::$field_array;

$requiredField_array = $extension::$requiredField_array;

if (empty($_POST)) {
 foreach ($field_array as $key => $value) {
	$$extension->$value = "";
 }

 foreach ($search_array as $key => $value) {
	if (empty($_GET[$value])) {
	 $_GET[$value] = "";
	}
 }
}

if (!empty($_SERVER['QUERY_STRING'])) {
 $query_string = htmlentities($_SERVER['QUERY_STRING']);
//  $query_string = remove_querystring_var($query_string, 'page');
 if (!empty($_GET['pageno'])) {
	$query_string = substr($query_string, 9);
 }
} else {
 $query_string = "";
}

//Column array represents all the fixed coulmns in result table
if (empty($_GET['column_array'])) {
 $column_array = $extension::$column_array;
}

$extension_id = $extension . '_id';

if (!empty($_GET[$extension_id])) {
 $$extension_id = $_GET[$extension_id];
 $$extension = $extension::find_by_id($$extension_id);
 $file = file::find_by_reference_table_and_id($table_name, $$extension_id);
 foreach ($extension::$checkbox_array as $key => $value) {
	$value_cb = $value . '_cb';
	if ((!empty($extension->$value_cb)) && ($extension->$value_cb == 1)) {
	 $$extension->$value = 1;
	} else {
	 $$extension->$value = "NULL";
	}
 }
}

//Start of Submit - for save & Update
$submit_extension = 'submit_' . $extension;

if (!empty($_POST['submit_comment'])) {

 $$extension = new $extension;

 foreach ($field_array as $key => $value) {
	if (!empty($_POST[$value])) {
	 $$extension->$value = trim(mysql_prep($_POST[$value]));
	} else {
	 $$extension->$value = "";
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


 $$extension->creation_date = current_time();
 if (!empty($_SESSION['user_id'])) {
	$$extension->created_by = $_SESSION['user_id'];
 } else {
	$$extension->created_by = '-99';
 }
 $$extension->last_update_date = $$extension->creation_date;
 $$extension->last_update_by = $$extension->created_by;

//for new locator creation the locator id should be null 

 foreach ($requiredField_array as $key => $value) {
	$required_field_flag = $required_field_flag && (!empty($$extension->$value));
 }

 if ($required_field_flag) {
	$new_entry = $$extension->save();
	if ($new_entry == 1) {
//    echo '<br/> new entry sucessful';
//            echo '<pre>';
//        print_r($$extension);
//        echo '<pre>';
	 if (count($$extension->file_id_values) > 0) {
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
	 $newMsg = 'Comment is Successfully posted';
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
 }	//end of locator check & new locator creation
 //reset all accounts to accounts from id
//  complete of for loop

 if (!empty($msg)) {
	echo '<div class="error">';
	if (is_array($msg)) {
	 foreach ($msg as $key => $value) {
		$x = $key + 1;
		echo 'Message ' . $x . ' : ' . $value . '<br />';
	 }
	} else {
	 echo '<span class="error">' . $msg . '</span>';
	}

	echo '</div>';
 }
}//end of post submit header

?>

<!--end of control file-->