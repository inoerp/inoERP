<?php $pageTitle = " Subinventory - Create & Update all subinventoriess "; ?>
<?php include_once("subinventory.inc"); ?>
<?php
//$page = !(empty($_GET['page'])) ? (int) $_GET['page'] : 1;
//if (!(empty($_GET['per_page']))) {
// if ($_GET['per_page'] == "all") {
//  $per_page = "";
// } else {
//  $per_page = (int) $_GET['per_page'];
// }
//} else {
// $per_page = 10;
//}
?>
<?php
$subinventory = new subinventory;
//$field array represents all the fields in the class
$field_array = subinventory::$field_array;
foreach ($field_array as $key => $value) {
 $subinventory->$value = "";
}
$msg = "";

$result = array();
//search array is used for srach fields & while condition in SQL query
$search_array = subinventory::$field_array;
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
 $column_array = subinventory::$column_array;
}
?>

<?php
$subinventory_search = "";
if ((!empty($_POST)) OR (!empty($_GET))) {
 if (is_array($_GET['subinventory'])) {
  $subinventory_search = "";
 } else {
  if (!empty($_GET['subinventory'])) {
   $subinventory_search = $_GET['subinventory'];
  } else {
   if (!empty($_POST['subinventory']) && is_array($_POST['subinventory'])) {
    $subinventory_search = "";
   } else {
    if (!empty($_POST['subinventory'])) {
     $subinventory_search = $_POST['subinventory'];
    }
   }
  }
 }
}
?>


<?php
if (!empty($_GET["subinventory_id"])) {
 $subinventory_id = $_GET["subinventory_id"];
 $subinventory = subinventory::find_by_id($subinventory_id);

 foreach (subinventory::$account_array as $key => $value) {
  $value_id = $value . '_id';
  if (!empty($subinventory->$value_id)) {
   $account = coa_combination::find_by_id($subinventory->$value_id);
   if (count($account) != 0) {
    $subinventory->$value = $account->combination;
   } else {
    $subinventory->$value = "NULL";
   }
  }
 }

 foreach (subinventory::$checkbox_array as $key => $value) {
  $value_cb = $value . '_cb';
  if ($subinventory->$value_cb == 1) {
   $subinventory->$value = 1;
  } else {
   $subinventory->$value = "NULL";
  }
 }
//  echo '<pre>';
//  print_r($subinventory);
//  echo '<pre>';
}
?>

<?php
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
  $whereClause = "WHERE " . implode(" AND ", $whereFields);

  // And then create the SQL query itself.
  $sql = "SELECT * FROM subinventory " . $whereClause;
  $count_sql = "SELECT COUNT(*) FROM subinventory " . $whereClause;
 } else {
  $sql = "SELECT * FROM subinventory ";
  $count_sql = "SELECT COUNT(*) FROM subinventory ";
 }

 $total_count = subinventory::count_all_by_sql($count_sql);

 if (!empty($per_page)) {
  $pagination = new pagination($page, $per_page, $total_count);
  $sql .=" LIMIT {$per_page} ";
  $sql .=" OFFSET {$pagination->offset()}";
 }

 $result = subinventory::find_by_sql($sql);

 foreach ($result as $result_e) {
  foreach (subinventory::$account_array as $key => $value) {
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
  foreach (subinventory::$checkbox_array as $key => $value) {
   $value_cb = $value . '_cb';
   if ($result_e->$value_cb == 1) {
    $result_e->$value = 1;
   } else {
    $result_e->$value = "NULL";
   }
  }
 }
}
?>

<?php
$msg = array();
if (!empty($_POST['submit_subinventory']) && empty($_POST['download'])) {
// echo '<pre>';
// print_r($_POST);
// echo '<pre>';

 $count = 0;
 for ($i = 0; $i < count($_POST['subinventory']); $i++) {
  $subinventory = new subinventory;

  foreach ($field_array as $key => $value) {
   if (!empty($_POST[$value][$i])) {
    $subinventory->$value = trim(mysql_prep($_POST[$value][$i]));
   } else {
    $subinventory->$value = "";
   }
  }

  $coa_id = 7;

  foreach (subinventory::$account_array as $key => $value) {
   if (!empty($_POST[$value][$i])) {
    if (coa_combination::validate_coa_combination($coa_id, $_POST[$value][$i]) == 1) {

     $value_id = $value . '_id';
     $subinventory->$value_id = coa_combination::find_combination_id_from_combination($coa_id, $_POST[$value][$i]);
//      echo '<br /> $subinventory->$value_id is '. $subinventory->$value_id;
    } else {
     $msgNew = "Invalid " . $value;
     array_push($msg, $msgNew);
    }
   } else {
    $msgNew = $value . " is missing";
    array_push($msg, $msgNew);
   }
  }

  foreach (subinventory::$checkbox_array as $key => $value) {
   $value_cb = $value . '_cb';
   $value = $value . $count;
//   echo $value;
   if (isset($_POST[$value])) {
    $subinventory->$value_cb = 1;
   } else {
    $subinventory->$value_cb = 0;
   }
//  echo '<br />'. $value;
//  echo " The value of   of ". $_POST['subinventory'][$i] .' is ' . $subinventory->$value_cb ;
  }
  $count = $count + 1;
  $time = time();
  $subinventory->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
  $subinventory->created_by = $_SESSION['user_name'];
  $subinventory->last_update_date = $subinventory->creation_date;
  $subinventory->last_update_by = $subinventory->created_by;
//    echo '<pre>';
//    print_r($subinventory);
//    echo '<pre>';
//for new subinventory creation the subinventory id should be null 
  if (empty($subinventory->type) || empty($subinventory->subinventory) || empty($subinventory->org_id) || empty($subinventory->material_ac_id)) {
   $newMsg = "subinventory, Class or Description is Blank";
   array_push($msg, $newMsg);
  } else {
   $new_subinventory_entry = $subinventory->save();
   if ($new_subinventory_entry == 1) {
    $newMsg = 'subinventory is sucessfully saved';
    array_push($msg, $newMsg);
   }//end of subinventory entry & msg
   else {
    $newMsg = "Record coundt be saved!!" . mysql_error() .
            ' Returned Value is : ' . $new_subinventory_entry;
    array_push($msg, $newMsg);
   }//end of subinventory insertion else
  }//end of subinventory check & new subinventory creation
  //reset all accounts to accounts from id
 }
//  complete of for loop
}//end of post submit header
?>

<div id="structure">
 <div id="subinventory">
  <div id="form_top">
   <ul class="form_top">
    <li><input type="button" class="button refresh" value="Refresh" name="refresh"/> </li>
    <li> <a class="button" href="subinventory.php">New Object</a> </li>
    <li><input type="button" id="add_object" class="button" value="New Line" name="add_object"/> </li>
    <li><input type="submit" form="subinventory_header" name="submit_subinventory" id="submit_subinventory" class="button" Value="Save"></li>
    <li> <input type="button" class="button remove_row" id="remove_row" Value="Remove"></li>
    <li> <input type="submit" class="button delete" form="coa_combination_form" name="delete_row" id="delete_row" value="Delete"></li>
    <li><input type="reset" class="button" form="subinventory_header" name="reset" Value="Reset All"></li>
    <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
   </ul>
  </div>
  <!--    START OF FORM HEADER-->
  <div id ="form_header">
   <ul id="form_box"> 
    <li>   <!--    Place for showing error messages-->

     <?php
     if (!empty($msg)) {
      echo '<div id="dialog_box">';
      if (is_array($msg)) {
       foreach ($msg as $key => $value) {
        $x = $key + 1;
        echo 'Message ' . $x . ' : ' . $value . '<br />';
       }
      } else {
       echo $msg;
      }

      echo '</div>';
     }
     ?> 

     <!--    End of place for showing error messages-->
    </li>
    <!--Search form creation    -->
    <li>
     <div id="subinventory_search">
      <br>
      <form action="subinventory.php" name="search_subinventory" method="GET" class="search_box subinventory_form" id="search_subinventory">
       <ul class="search_form">                   
        <li><label>Sub Inventory Id : </label>
         <input type="text" id="subinventory_id" name="subinventory_id" value="<?php
         echo!(is_array($_GET['subinventory_id'])) ? htmlentities($_GET['subinventory_id']) : "";
         ?>" maxlength="50" >
        </li>
        <li><label>Inventory Id : </label>
         <input type="text" id="org_id" name="org_id" value="<?php
         echo!(is_array($_GET['org_id'])) ? htmlentities($_GET['org_id']) : "";
         ?>" maxlength="50" >
        </li>
        <li><label>Sub Inventory Type : </label>
         <select name="type" id="type" class="type"> 
          <option value=""> </option>
          <?php
          $type_class = subinventory::subinventory_type();
          foreach ($type_class as $key => $value) {
           echo '<option value="' . htmlentities($value->option_line_code) . '"';
           echo (($_GET['type']) == $value->option_line_code) ? " selected" : "";
           echo '>' . $value->description_l . '</option>';
          }
          ?> 
         </select>
        </li>
        <li><label>Sub Inventory: </label>
         <input type="search" name="subinventory" id="subinventory" value="<?php echo $subinventory_search; ?>"  maxlength="50" >
        </li>
        <li>
         <label>Description : </label>
         <input id="description" type="search" maxlength="50" value="<?php
         echo!(is_array($_GET['description'])) ? htmlentities($_GET['description']) : "";
         ?>" name="description">
        </li>
        <li>
        <lable>Add dynamic search criteria </lable>
        <select name="new_search_criteria" id="new_search_criteria" class="new_search_criteria"> 
         <option value=""> </option>
         <?php
         foreach ($search_array as $key => $value) {
          echo '<option value="' . htmlentities($value) . '"';
          echo '>' . $value . '</option>';
         }
         ?> 
        </select>
        </li>
        <li>
         <input type="button" class="add button" id="new_search_criteria_add" value="Add">
        </li>
        <!--          send the existing column array to POST-->
        <li><input type="hidden" name="column_array" id="column_array" value="<?php print base64_encode(serialize($column_array)) ?>" >
        </li>
       </ul>
       <ul class="add_new_search">
        <li>
        <lable>Add a new column</lable>
        <select name="new_column" id="new_column" > 
         <option value=""> </option>
         <?php
         foreach ($search_array as $key => $value) {
          echo '<option value="' . htmlentities($value) . '"';
          echo '>' . $value . '</option>';
         }
         ?> 
        </select>
        </li>
        <li>
        <lable>Records per page</lable>
        <select name="per_page" id="per_page" > 
         <option value="10">10</option>
         <option value="20" <?php echo $per_page == 20 ? " selected" : "" ?>>20</option>
         <option value="50" <?php echo $per_page == 50 ? " selected" : "" ?>>50</option>
         <option value="100" <?php echo $per_page == 100 ? " selected" : "" ?>>100</option>
         <option value="1000" <?php echo $per_page == 1000 ? " selected" : "" ?>>1000</option>
         <option value="all" <?php echo $per_page == "all" ? " selected" : "" ?>>All</option>
         <option value="1" <?php echo $per_page == "1" ? " selected" : "" ?>>1</option>
        </select>
        </li>
       </ul>
       <ul class="form_buttons">
        <li><a href="subinventory.php" class="reset button"> Reset All</a></li>
        <li><input type="submit" form="search_subinventory" name="submit_search" class="search button" value="Search"></li>

       </ul>
      </form> 

     </div>
    </li>
    <li>
     <div id="scrollElement">
      <form action="subinventory.php"  method="post" id="subinventory_header"  name="subinventory_header">
       <?php if (!empty($result)) {
        ?>
        <?php
        if (!empty($total_count)) {
         echo '<h3>Total records : ' . $total_count . '</h3>';
        }
        ?>

        <ul>
         <li class="ncontrol"><span class="heading">Sub Inventory </span> 
          <div id="tabsHeader">
           <?php echo subinventory::$tab_header ?>
           <div id="tabsHeader-1">
            <table class="form_table">
             <?php echo subinventory::$tabs_header1_tr ?>
             <tbody class="subinventory_values">
              <?php
              $count = 0;
              foreach ($result as $subinventory) {
               ?>         
               <tr id="subinventory_values<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                  <li><input type="checkbox" name="subinventory_id_cb" value="<?php echo htmlentities($subinventory->subinventory_id); ?>"></li>           
                 </ul>
                </td>
                <td>
                 <input type="text" readonly name="subinventory_id[]" 
                        value="<?php echo htmlentities($subinventory->subinventory_id); ?>" size="10"                           
                        maxlength="50" class="subinventory_id" placeholder="Sys generated number"> 
                </td>
                <td>
                 <select name="org_id[]" id="org_id" class="org_id" required> 
                  <option value=""> </option>
                  <?php
                  $inventory_org = org_header::find_all_inventory_org();
                  foreach ($inventory_org as $key => $value) {
                   echo '<option value="' . htmlentities($value->org_id) . '"';
                   echo ($subinventory->org_id == $value->org_id) ? " selected" : "";
                   echo '>' . $value->name . '</option>';
                  }
                  ?> 
                 </select>

                </td>
                <td>    
                 <select name="type[]" id="type" class="type" required> 
                  <option value=""> </option>
                  <?php
                  $type_class = subinventory::subinventory_type();
                  foreach ($type_class as $key => $value) {
                   echo '<option value="' . htmlentities($value->option_line_code) . '"';
                   echo ($subinventory->type == $value->option_line_code) ? " selected" : "";
                   echo '>' . $value->description_l . '</option>';
                  }
                  ?> 
                 </select>
                </td>
                <td>
                 <input type="text" name="subinventory[]" required value="<?php echo htmlentities($subinventory->subinventory); ?>" 
                        size="15" maxlength="150"  id="subinventory"> 
                </td>
                <td>
                 <input type="text" name="description[]" value="<?php echo htmlentities($subinventory->description); ?>" 
                        size="15" maxlength="150"  id="description"> 
                </td>
                <td>    
                 <select name="locator_control[]" id="locator_control" class="locator_control" required> 
                  <option value=""> </option>
                  <?php
                  $locator_control = subinventory::locator_control();
                  foreach ($locator_control as $key => $value) {
                   echo '<option value="' . htmlentities($value->option_line_code) . '"';
                   echo ($subinventory->locator_control == $value->option_line_code) ? " selected" : "";
                   echo '>' . $value->option_line_code . '</option>';
                  }
                  ?> 
                 </select>
                </td>
                <td>
                 <input type="checkbox" name="allow_negative_balance<?php echo $count; ?>" id="allow_negative_balance"
                        value="1"
                        <?php
                        if ($subinventory->allow_negative_balance == 1) {
                         echo " checked";
                        } else {
                         echo "";
                        }
                        ?> > 
                </td>
               </tr>
               <?php
               $count = $count + 1;
              }
              ?>
             </tbody>
            </table>
           </div>
           <div id="tabsHeader-2">
            <table class="form_table">
             <?php echo subinventory::$tabs_header2_tr ?>
             <tbody class="subinventory_values">
              <?php
              $count = 0;
              foreach ($result as $subinventory) {
               ?>         
               <tr id="subinventory_values<?php echo $count ?>">
                <td>
                 <input type="text" name="default_cost_group[]" value="<?php echo htmlentities($subinventory->default_cost_group); ?>" 
                        size="10" maxlength="150"  id="default_cost_group"> 
                </td>
                <td>
                 <input type="text" name="material_ac[]" required value="<?php echo htmlentities($subinventory->material_ac); ?>" size="20" maxlength="150"  id="material_ac"> 
                </td>
                <td>
                 <input type="text" name="material_oh_ac[]" value="<?php echo htmlentities($subinventory->material_oh_ac); ?>" 
                        size="20" maxlength="150"  id="material_oh_ac"> 
                </td>
                <td>
                 <input type="text" name="overhead_ac[]" value="<?php echo htmlentities($subinventory->overhead_ac); ?>" 
                        size="20" maxlength="150"  id="overhead_ac"> 
                </td>
                <td>
                 <input type="text" name="resource_ac[]" value="<?php echo htmlentities($subinventory->resource_ac); ?>" 
                        size="20" maxlength="150"  id="resource_ac"> 
                </td>
                <td>
                 <input type="text" name="osp_ac[]" value="<?php echo htmlentities($subinventory->osp_ac); ?>" 
                        size="20" maxlength="150"  id="osp_ac"> 
                </td>
                <td>
                 <input type="text" name="expense_ac[]" value="<?php echo htmlentities($subinventory->expense_ac); ?>" 
                        size="20" maxlength="150"  id="expense_ac"> 
                </td> 
               </tr>
               <?php
               $count = $count + 1;
              }
              ?>
             </tbody>
             <!--                  Showing a blank form for new entry-->

            </table>
           </div>
           <div id="tabsHeader-3">
            <table class="form_table">
             <?php echo subinventory::$tabs_header3_tr ?>
             <tbody class="subinventory_values">
              <?php
              $count = 0;
              foreach ($result as $subinventory) {
               ?>         
               <tr id="subinventory_values<?php echo $count ?>">
                <td>
                 <input type="text" name="ef_id[]" value="<?php echo htmlentities($subinventory->ef_id); ?>" 
                        size="15" maxlength="10"  id="ef_id"> 
                </td>
                <td>                      
                 <Select name="status[]" id="status" >
                  <option value="" ></option>
                  <option value="enabled" 
                          <?php echo $subinventory->status == 'enabled' ? ' selected' : ''; ?> >Enabled</option>
                  <option value="disabled" 
                          <?php echo $subinventory->status == 'disabled' ? ' selected' : ''; ?> >Disabled</option>                                   
                 </select>

                </td>
                <td>
                 <input type="checkbox" name="rev_enabled<?php echo $count; ?>" 
                        value="1"
                        <?php
                        if ($subinventory->rev_enabled == 1) {
                         echo " checked";
                        } else {
                         echo " ";
                        }
                        ?>>  
                </td> 
                <td>
                 <input type="text" name="rev_number<?php echo $count ?>" value="<?php echo htmlentities($subinventory->rev_number); ?>" 
                        maxlength="50" size="5"  id="rev_number" class="rev_number"> 
                </td> 

               </tr>
               <?php
               $count = $count + 1;
              }
              ?>
             </tbody>
             <!--                  Showing a blank form for new entry-->

            </table>
           </div>
          </div>
         </li>
        </ul>

       <?php } else { ?>
        <!--create empty form or a single id when search is not clicked and the id is referred from other page -->

        <ul>
         <li class="ncontrol"><span class="heading">Sub Inventory </span> 
          <div id="tabsHeader">
           <?php echo subinventory::$tab_header ?>
           <div id="tabsHeader-1">
            <table class="form_table">
             <?php echo subinventory::$tabs_header1_tr ?>
             <tbody id="subinventory_values">
              <tr id="subinventory_values0">
               <td>    
                <ul class="inline_action">
                 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                 <li><input type="checkbox" name="subinventory_id_cb" value="<?php echo htmlentities($subinventory->subinventory_id); ?>"></li>           
                </ul>
               </td>
               <td>
                <input type="text" readonly name="subinventory_id[]" 
                       value="<?php echo htmlentities($subinventory->subinventory_id); ?>" size="10"                           
                       maxlength="50" class="subinventory_id" placeholder="Sys generated number"> 
               </td>
               <td>
                <select name="org_id[]" id="org_id" required class="org_id"> 
                 <option value=""> </option>
                 <?php
                 $inventory_org = org_header::find_all_inventory_org();
                 foreach ($inventory_org as $key => $value) {
                  echo '<option value="' . htmlentities($value->org_id) . '"';
                  if (!empty($_GET['org_id'])) {
                   echo (($_GET['org_id']) == $value->org_id) ? " selected" : "";
                  } else {
                   echo $subinventory->org_id == $value->org_id ? " selected" : "";
                  }
                  echo '>' . $value->name . '</option>';
                 }
                 ?> 
                 ?> 
                </select>
               </td>
               <td>    
                <select name="type[]" id="type" required class="type"> 
                 <option value=""> </option>
                 <?php
                 $type_class = subinventory::subinventory_type();
                 foreach ($type_class as $key => $value) {
                  echo '<option value="' . htmlentities($value->option_line_code) . '"';
                  if (!empty($_GET['type'])) {
                   echo (($_GET['type']) == $value->option_line_code) ? " selected" : "";
                  } else {
                   echo ($subinventory->type == $value->option_line_code) ? " selected" : "";
                  }
                  echo '>' . $value->description_l . '</option>';
                 }
                 ?> 
                </select>
               </td>
               <td>
                <input type="text" name="subinventory[]" required value="<?php echo htmlentities($subinventory->subinventory); ?>" 
                       size="15" maxlength="150"  id="subinventory"> 
               </td>
               <td>
                <input type="text" name="description[]" value="<?php echo htmlentities($subinventory->description); ?>" 
                       size="15" maxlength="150"  id="description"> 
               </td>
               <td>    
                 <select name="locator_control[]" id="locator_control" class="locator_control" required> 
                  <option value=""> </option>
                  <?php
                  $locator_control = subinventory::locator_control();
                  foreach ($locator_control as $key => $value) {
                   echo '<option value="' . htmlentities($value->option_line_code) . '"';
                   echo ($subinventory->locator_control == $value->option_line_code) ? " selected" : "";
                   echo '>' . $value->option_line_code . '</option>';
                  }
                  ?> 
                 </select>
               </td>
               <td>
                <input type="checkbox" name="allow_negative_balance[]" 
                       value="1"  id="allow_negative_balance"
                       <?php
                       if ($subinventory->allow_negative_balance == 1) {
                        echo " checked";
                       } else {
                        echo "";
                       }
                       ?> > 
               </td>
              </tr>
             </tbody>
            </table>
           </div>
           <div id="tabsHeader-2">
            <table class="form_table">
             <?php echo subinventory::$tabs_header2_tr ?>
             <tbody id="subinventory_values">
              <tr id="subinventory_values0">
               <td>
                <input type="text" name="default_cost_group[]" value="<?php echo htmlentities($subinventory->default_cost_group); ?>" 
                       size="10" maxlength="150"  id="default_cost_group"> 
               </td>
               <td>
                <input type="text" name="material_ac[]" required value="<?php echo htmlentities($subinventory->material_ac); ?>" 
                       size="20" maxlength="150"  id="material_ac"> 
               </td>
               <td>
                <input type="text" name="material_oh_ac[]" value="<?php echo htmlentities($subinventory->material_oh_ac); ?>" 
                       size="20" maxlength="150"  id="material_oh_ac"> 
               </td>
               <td>
                <input type="text" name="overhead_ac[]" value="<?php echo htmlentities($subinventory->overhead_ac); ?>" 
                       size="20" maxlength="150"  id="overhead_ac"> 
               </td>
               <td>
                <input type="text" name="resource_ac[]" value="<?php echo htmlentities($subinventory->resource_ac); ?>" 
                       size="20" maxlength="150"  id="resource_ac"> 
               </td>
               <td>
                <input type="text" name="osp_ac[]" value="<?php echo htmlentities($subinventory->osp_ac); ?>" 
                       size="20" maxlength="150"  id="osp_ac"> 
               </td>
               <td>
                <input type="text" name="expense_ac[]" value="<?php echo htmlentities($subinventory->expense_ac); ?>" 
                       size="20" maxlength="150"  id="expense_ac"> 
               </td>
               <td>                      

              </tr>
             </tbody>
             <!--                  Showing a blank form for new entry-->

            </table>
           </div>
           <div id="tabsHeader-3">
            <table class="form_table">
             <?php echo subinventory::$tabs_header3_tr ?>
             <tbody id="subinventory_values">
              <tr id="subinventory_values0">
               <td>
                <input type="text" name="ef_id[]" value="<?php echo htmlentities($subinventory->ef_id); ?>" 
                       size="15" maxlength="10"  id="ef_id"> 
               </td>
               <td>                      
                <Select name="status[]" id="status" >
                 <option value="" ></option>
                 <option value="enabled" 
                         <?php echo $subinventory->status == 'enabled' ? ' selected' : ''; ?> >Enabled</option>
                 <option value="disabled" 
                         <?php echo $subinventory->status == 'disabled' ? ' selected' : ''; ?> >Disabled</option>                                   
                </select>

               </td>
               <td>
                <input type="checkbox" name="rev_enabled<?php echo $count; ?>" 
                       value="1"
                       <?php
                       if ($subinventory->rev_enabled == 1) {
                        echo " checked";
                       } else {
                        echo "";
                       }
                       ?> >  
               </td> 
               <td>
                <input type="text" name="rev_number[]" value="<?php echo htmlentities($subinventory->rev_number); ?>" 
                       maxlength="50" size="5"  id="rev_number" class="rev_number"> 
               </td> 
              </tr>
             </tbody>
             <!--                  Showing a blank form for new entry-->

            </table>
           </div>
          </div>
         </li>
        </ul>

       <?php }
       ?>
       <!--                 complete Showing a blank form for new entry-->
      </form>
     </div>  

    </li>
   </ul>
   <div id="pagination" style="clear: both;">
    <?php
    if (isset($pagination)) {
     if ($pagination->has_previous_page()) {
      echo "<a href=\"subinventory.php?page=";
      echo $pagination->previous_page() . '&' . $query_string;
      echo "\"> &laquo; Previous </a> ";
     }

     for ($i = 1; $i <= $pagination->total_pages(); $i++) {
      if ($i == $page) {
       echo " <span class=\"selected\">{$i}</span> ";
      } else {
       echo " <a href=\"subinventory.php?page={$i}&" . remove_querystring_var($query_string, 'page');
       echo '&submit_search=Search';
       echo '\">' . $i . '</a>';
      }
     }

     if ($pagination->has_next_page()) {
      echo " <a href=\"subinventory.php?page=";
      echo $pagination->next_page() . '&' . remove_querystring_var($query_string, 'page');
      echo '&submit_search=Search';
      echo "\">Next &raquo;</a> ";
     }
    }
    ?>
   </div>


   <!--download page creation-->
   <ul class="data_export">
    <li> <input type="submit" class="download button excel" value="<?php echo $per_page ?> Records" form="download"></li>
    <li> <input type="submit" class="download button excel" value="All Records" form="download_all"></li>
    <li> <input type="button" class="download button print" value="Print"></li>
   </ul>

   <?php
   if (!empty($sql)) {
    $subinventory_obj = subinventory::find_by_sql($sql);
    $subinventory_array = json_decode(json_encode($subinventory_obj), true);
   }
   ?>
   <!--download page form-->
   <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download" id="download">
    <input type="hidden"  name="data" value="<?php print base64_encode(serialize($subinventory_array)) ?>" >

   </form>

   <!--download page creation for all records-->
   <?php
   if (!empty($all_download_sql)) {
    $subinventory_obj_all = subinventory::find_by_sql($all_download_sql);
    $subinventory_array_all = json_decode(json_encode($subinventory_obj_all), true);
   }
   ?>
   <!--download page form-->
   <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download_all" id="download_all">
    <input type="hidden"  name="data" value="<?php print base64_encode(serialize($subinventory_array_all)) ?>" >
   </form>
   <!--download page completion-->
  </div>
  <!--END OF FORM HEADER-->  
 </div>
</div>
<!--   end of structure-->

<?php include_template('footer.inc') ?>
