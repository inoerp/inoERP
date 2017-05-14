<!--start of page control file-->
<?php 

$msg = array();
$run_functions_after_save = 0;
$create_path = 0;

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

//$field array represents all the fields in the class
$field_array = $extension::$field_array;
//search array is used for srach fields & while condition in SQL query

$search_array = $extension::$field_array;

$requiredField_array = $extension::$requiredField_array;

//default columns to be shown on query/view page
$column_array = $extension::$column_array;

if(empty($_POST)){
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

$extension_id = $extension.'_id';

if (!empty($_GET[$extension_id])) {
 $$extension_id = $_GET[$extension_id];
 $$extension = $extension::find_by_id($$extension_id);
 $file = extn_file::find_by_reference_table_and_id($table_name, $$extension_id);
// $comment = extn_comment::find_by_reference_table_and_id($table_name, $$extension_id);
 $comments = extn_comment::comment_list($table_name,$$extension_id,$per_page,$pageno,$query_string,$$extension_id);
  
 foreach ($extension::$checkbox_array as $key => $value) {
  $value_cb = $value . '_cb';
  if ((!empty($extension->$value_cb)) && ($extension->$value_cb == 1)) {
   $$extension->$value = 1;
  } else {
   $$extension->$value = "NULL";
  }
 }
//  echo '<pre>';
//  print_r($locator);
//  echo '<pre>';
}


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
   if($noof_criteria == 0)
  {
   $newMsg = "No criteria entered";
   array_push($msg, $newMsg);
  }

 if (count($whereFields) > 0) {

  // Construct the WHERE clause by gluing the fields
  // together with a " AND " separator.
  $whereClause = " WHERE " . implode(" AND ", $whereFields);

  // And then create the SQL query itself.
  $sql = "SELECT * FROM " . $table_name  . $whereClause;
  $count_sql = "SELECT COUNT(*) FROM " . $table_name  . $whereClause;
  $all_download_sql = "SELECT * FROM  " . $table_name  . $whereClause;
 } else {
  $sql = "SELECT * FROM ". $table_name ;
  $count_sql = "SELECT COUNT(*) FROM ". $table_name;
  $all_download_sql = "SELECT * FROM  " . $table_name ;
 }

 $total_count = $extension::count_all_by_sql($count_sql);

 if (!empty($per_page)) {
  $pagination = new pagination($pageno, $per_page, $total_count);
  $sql = ino_perPageSql_i($sql, $per_page, $pagination->offset());
 }
 
 $result = $extension::find_by_sql($sql);
 
  foreach ($result as $result_e) {
  
  if(!(empty($extension::$account_array))){ 
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
  
  if(!empty($extension::$checkbox_array)){
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
}
// End of search
//Start of Submit - for save & Update
$submit_extension = 'submit_'.$extension;

if (!empty($_POST[$submit_extension]) && empty($_POST['download'])) {
    
  foreach ($field_array as $key => $value) {
   if (!empty($_POST[$value])) {
    $$extension->$value = trim(mysql_prep($_POST[$value]));
   } else {
    $$extension->$value = "";
   }
  }
  
    foreach ($content_field_array as $key => $value) {
   if (!empty($_POST[$value])) {
    $$extension->$value = trim(mysql_prep($_POST[$value]));
   } else {
    $$extension->$value = "";
   }
  }
  $$extension->content_type_id=$content_type->content_type_id;

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
  
  if(!empty($_POST['file_id_values'])){
  $$extension->file_id_values = $_POST['file_id_values'];
  $primary_column = $extension::$primary_column;
  }
  
  $time = time();
  $$extension->creation_date = strftime("%Y-%m-%d %H:%M:%S", $time);
  $$extension->created_by = $_SESSION['user_name'];
  $$extension->last_update_date = $$extension->creation_date;
  $$extension->last_update_by = $$extension->created_by;

//for new locator creation the locator id should be null 
  
   foreach ($requiredField_array as $key => $value) {
   $required_field_flag = $required_field_flag && (!empty($$extension->$value));
}

  if ($required_field_flag){
   $new_entry = $$extension->save();
   if ($new_entry == 1 or $new_entry ==2) {
    if($new_entry==1){
     $create_path = 1;
    }
//    echo '<br/> new entry sucessful';
//            echo '<pre>';
//        print_r($$extension);
//        echo '<pre>';
    $run_functions_after_save = $new_entry;
      if((!(empty($$extension->file_id_values))) && (count($$extension->file_id_values) > 0)){
//       echo '<br/> trying fileid upload';
//       echo '<br/> $primary_column is'.$primary_column;
//       echo '<br/> trying fileid $$extension->$primary_column is ' . $$extension->$primary_column;
       foreach($$extension->file_id_values as $keys =>$values){
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
    $newMsg = 'Record is Successfully saved';
    array_push($msg, $newMsg);
   }//end of locator entry & msg
   else {
    $newMsg = "Record coundt be saved!!" . mysql_error() .
            ' Returned Value is : ' . $new_entry;
    array_push($msg, $newMsg);
   }//end of locator insertion else
  }else {
   $newMsg = "One of the required field is Blank";
   array_push($msg, $newMsg);
  }  //end of locator check & new locator creation
  //reset all accounts to accounts from id
//  complete of for loop
}//end of post submit header


//getting the search extension from POST or GET
$a= $extension;
$b = $a.'_search' ;
$$b= " ";

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



?>

<!--end of control file-->