<?php
$msg = array();
$module = 'inv_transaction';
//the field used for counting number of post records
$key_field='item_number';
$required_field_flag = 1;

$page = !(empty($_GET['page'])) ? (int) $_GET['page'] : 1;

if (!(empty($_GET['per_page']))) {
 if ($_GET['per_page'] == "all") {
  $per_page = "";
 } else {
  $per_page = (int) $_GET['per_page'];
 }
} else {
 $per_page = 10;
}

$$module = new $module;
//$field array represents all the fields in the class
$field_array = $module::$field_array;
//search array is used for srach fields & while condition in SQL query
$search_array = $module::$field_array;
//default columns to be shown on query/view page
$column_array = $module::$column_array;
//required fields arrray
$required_array = $module::$required_array;

foreach ($field_array as $key => $value) {
 $$module->$value = "";
}

foreach ($search_array as $key => $value) {
 if (empty($_GET[$value])) {
  $_GET[$value] = "";
 }
}

if (!empty($_SERVER['QUERY_STRING'])) {
 $query_string = $_SERVER['QUERY_STRING'];
//  $query_string = remove_querystring_var($query_string, 'page');
 if (!empty($_GET['page'])) {
  $query_string = substr($query_string, 7);
 }
} else {
 $query_string = "";
}

//Column array represents all the fixed coulmns in result table
if (empty($_GET['column_array'])) {
 $column_array = $module::$column_array;
}

$module_id = $module.'_id';

if (!empty($_GET[$module_id])) {
 $$module_id = $_GET[$module_id];
 $$module = $module::find_by_id($$module_id);

 foreach ($module::$checkbox_array as $key => $value) {
  $value_cb = $value . '_cb';
  if ((!empty($module->$value_cb)) && ($module->$value_cb == 1)) {
   $$module->$value = 1;
  } else {
   $$module->$value = "NULL";
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

 foreach ($search_array as $key => $value) {
  if (!empty($_GET[$value])) {
   $whereFields[] = sprintf("`%s` LIKE '%%%s%%'", $value, trim(mysql_prep($_GET[$value])));
  } else {
   $msg = "No criteria entered";
  }
 }

 if (count($whereFields) > 0) {

  // Construct the WHERE clause by gluing the fields
  // together with a " AND " separator.
  $whereClause = " WHERE " . implode(" AND ", $whereFields);

  // And then create the SQL query itself.
  $sql = "SELECT * FROM " . $module  . $whereClause;
  $count_sql = "SELECT COUNT(*) FROM " . $module  . $whereClause;
  $all_download_sql = "SELECT * FROM  " . $module  . $whereClause;
 } else {
  $sql = "SELECT * FROM ". $module ;
  $count_sql = "SELECT COUNT(*) FROM ". $module;
  $all_download_sql = "SELECT * FROM  " . $module ;
 }

 $total_count = $module::count_all_by_sql($count_sql);

 if (!empty($per_page)) {
  $pagination = new pagination($page, $per_page, $total_count);
  $sql .=" LIMIT {$per_page} ";
  $sql .=" OFFSET {$pagination->offset()}";
 }

 $result = $module::find_by_sql($sql);

 foreach ($result as $result_e) {
  
  if(!(empty($module::$account_array))){ 
     foreach ($module::$account_array as $key => $value) {
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
  
  if(!empty($module::$checkbox_array)){
  foreach ($module::$checkbox_array as $key => $value) {
   $value_cb = $value . '_cb';
   if ($result_e->$value_cb == 1) {
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
$submit_module = 'submit_'.$module;

if (!empty($_POST[$submit_module]) && empty($_POST['download'])) {

 $count = 0;
 
 for ($i = 0; $i< count($_POST[$key_field]); $i++ ) {
  $$module = new $module;
  
//  echo '<h2>showing post elements </h2>';
//     echo '<pre>';
// print_r($_POST);
// echo '<pre>';

 
  foreach ($field_array as $key => $value) {
   if (!empty($_POST[$value][$i])) {
    $$module->$value = trim(mysql_prep($_POST[$value][$i]));
   } else {
    $$module->$value = "";
   }
  }

   $$module->org_id = trim(mysql_prep($_POST['org_id'][0]));
   $$module->transaction_type_id = trim(mysql_prep($_POST['transaction_type_id'][0]));
//  echo '<h2> item id </h2>';
// echo item::find_item_id_from_itemNumber_OrgId($_POST['item_number'][$i], $_POST['org_id'][0]);
 
 $$module->item_id = item::find_item_id_from_itemNumber_OrgId($_POST['item_number'][$i], $_POST['org_id'][0]);
//  echo '<h2> module item id </h2>'. $$module->item_id ;
  
 if(!empty($_POST['item_number'][$i]) && (!empty($_POST['org_id'][0]))){
   $$module->item_id = item::find_item_id_from_itemNumber_OrgId($_POST['item_number'][$i], $_POST['org_id'][0]);
  }

  $coa_id = 7;

if(!empty($module::$account_array)){
  foreach ($module::$account_array as $key => $value) {
   if (!empty($_POST[$value][$i])) {
    if (coa_combination::validate_coa_combination($coa_id, $_POST[$value][$i]) == 1) {
     $value_id = $value . '_id';
     $$module->$value_id = coa_combination::find_combination_id_from_combination($coa_id, $_POST[$value][$i]);
//      echo '<br /> $locator->$value_id is '. $locator->$value_id;
    } else {
     $msgNew = "Invalid " . $value;
     array_push($msg, $msgNew);
    }
   } else {
    $msgNew = $value . " is missing";
    array_push($msg, $msgNew);
   }
  } 
}


  foreach ($module::$checkbox_array as $key => $value) {
   $value_cb = $value . '_cb';
   $value = $value . $count;
//   echo $value;
   if (isset($_POST[$value])) {
    $$module->$value_cb = 1;
   } else {
    $$module->$value_cb = 0;
   }
//  echo '<br />'. $value;
//  echo " The value of   of ". $_POST['locator'][$i] .' is ' . $locator->$value_cb ;
  }
  $count = $count + 1;
  $time = time();
  $$module->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
  $$module->created_by = $_SESSION['user_name'];
  $$module->last_update_date = $$module->creation_date;
  $$module->last_update_by = $$module->created_by;
//  
//  echo '<h2>showing array elements </h2>';
//    echo '<pre>';
//    print_r($_POST);
//    echo '<pre>';
//for new locator creation the locator id should be null 

  
  foreach ($required_array as $key => $value) {
   $required_field_flag = $required_field_flag && (!empty($$module->$value));
}

$update_result = onhand::update_onhand($$module->item_id, $$module->org_id, $$module->uom_id,$$module->quantity,
        $$module->from_org_id, $$module->from_subinventory_id, $$module->from_locator_id,
        $$module->to_org_id, $$module->to_subinventory_id, $$module->to_locator_id,
        $$module->lot_number, $$module->serial_number);


array_push($msg, $update_result);

   if ($required_field_flag){
   $new_entry = $$module->save();
   if ($new_entry == 1) {
    $newMsg = 'Record is sucessfully saved';
    array_push($msg, $newMsg);
   }//end of locator entry & msg
   else {
    $newMsg = "Record coundt be saved!!" . mysql_error() .
            ' Returned Value is : ' . $new_entry;
    array_push($msg, $newMsg);
   }//end of locator insertion else
  }else{
     $newMsg = "One of the required field is Blank";
     array_push($msg, $newMsg);
  }
  
 }
//  complete of for loop
}//end of post submit header


//getting the search module from POST or GET
$a= $module;
$b = $a.'_search' ;
$$b= " ";

if (!((empty($_POST[$module])) AND (empty($_GET[$module])))) {
 if (is_array($_GET[$module])) {
  $$b = "";
 } else {
  if (!empty($_GET[$module])) {
   $$b = $_GET[$module];
  } else {
   if (!empty($_POST[$module]) && is_array($_POST[$module])) {
    $$b = "";
   } else {
    if (!empty($_POST[$module])) {
     $$b = $_POST[$module];
    }
   }
  }
 }
}
//End of geetting search module
                                             

?>
