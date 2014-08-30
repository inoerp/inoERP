<?php $pageTitle = " Create COA combination "; ?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="coa_combination.js"></script>

<?php
$msg = "";
$coa_combination_count = 0;

$coa_combination = new coa_combination;
$coa_combination->coa_id = "";
$coa_combination->coa_structure_id = "";
$coa_combination->coa_name = "";
$coa_combination->coa_combination_id = "";
$coa_combination->coa_sequence = "";
$coa_combination->balancing = "";
$coa_combination->cost_center = "";
$coa_combination->natural_account = "";
$coa_combination->inter_company = "";
$coa_combination->segment1 = "";
$coa_combination->segment2 = "";
$coa_combination->segment3 = "";
$coa_combination->segment4 = "";
$coa_combination->combination = "";
$coa_combination->description = "";
$coa_combination->ef_id = "";
$coa_combination->status = "";
$coa_combination->rev_enabled = "";
$coa_combination->rev_number = "";
$coa_combination->effective_start_date = "";
$coa_combination->effective_end_date = "";
$coa_combination->created_by = "";
$coa_combination->creation_date = "";
$coa_combination->last_update_by = "";
$coa_combination->last_update_date = "";
?>  

<?php
if (!empty($_GET["coa_id"])) {
  $coa_id = $_GET["coa_id"];

  $coa = coa::find_by_id($coa_id);
  $coa_combination = new coa_combination;
  $coa_combination->coa_id = $coa->coa_id;
  $coa_combination->coa_structure_id = $coa->structure;
  $coa_combination->coa_name = $coa->name;
  $coa_combination->coa_sequence = $coa->coa_sequence;

//Get the code combination sequence.
//Find out all hypens(-)
//Echo the pattern on the basis of number of hypens

  if (!empty($coa_combination->coa_sequence)) {
    $fields = explode("-", $coa_combination->coa_sequence);
    $NU_count = 0;
    foreach ($fields as $keys => $value) {
      if ($value == 'NU') {
        $NU_count = $NU_count + 1;
      }
    }
    $pattern_count = count($fields) - $NU_count;

    switch ($pattern_count) {
      case 8:
        $pattern = "[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}$";
        break;

      case 7:
        $pattern = "[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}$";
        break;

      case 6:
        $pattern = "[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}$";
        break;

      case 5:
        $pattern = "[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}$";
        break;

      default :
        $pattern = "[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}\-[a-zA-Z0-9]{2,}$";
        break;
    }
  }

  $coa_combination_object = coa_combination::find_coa_combination_by_coa_id($coa_id);

  if (count($coa_combination_object) == 0) {
    $coa_combination_count = 0;
  } else {
    $coa_combination_count = count($coa_combination_object);
  }
// echo '<pre>';
//  print_r($coa_combination_object);
//  echo '<pre>';
}
?>

<?php
$msg;
$all_errors = array();

if (!empty($_POST['submit_header'])) {

  $column_name_array = array("balancing", "cost_center", "natural_account", "inter_company",
      "segment1", "segment2", "segment3", "segment4");
  $sucessfull_records = 0;

  for ($i = 0; $i < count($_POST['combination']); $i++) {
    $error = array();
    $coa_combination = new coa_combination();
    if (empty($_POST['coa_combination_id'])) {
      $coa_combination->coa_combination_id = null;
    } else {
      $coa_combination->coa_combination_id = trim(mysql_prep($_POST['coa_combination_id'][$i]));
    }
    $coa_combination->coa_id = trim(mysql_prep($_POST['coa_id']));
    $coa_combination->coa_structure_id = trim(mysql_prep($_POST['coa_structure_id']));
    $coa_combination->coa_name = trim(mysql_prep($_POST['coa_name']));

    $coa_combination->combination = trim(mysql_prep($_POST['combination'][$i]));
    //explode the segment code to differnt fields
    if (!empty($coa_combination->combination)) {
      $fields = explode("-", $coa_combination->combination);

//find out the segments for this coa id
      $coa = coa::find_by_id($coa_combination->coa_id);
      $coa_squence = explode("-", $coa->coa_sequence);
      $coa_squence = array_map('trim', $coa_squence);


      $coa_column_names = coa::find_coa_fields_by_id_array($coa_combination->coa_id);
      
      
//      for ($j=0; $j=5; $j++){
//       if((!empty($fields[$j])) &&
//        (coa_segment_values::find_by_coaid_segment_segmentcode($coa_combination->coa_id, $coa_squence[$j],$fields[$j]) ==1))
//        {
//        $coa_column_name =  array_search($coa_squence[$j], $coa_column_names);
//          $coa_combination->$column_name_array[$coa_column_name] = $fields[$j];
//       }
////       else{
////         $error_msg = $fields[$j].' '. $coa_squence[$j] .' doesnt exists';
////        array_push($error, $error_msg );
////      }
//      }
      
    if((!empty($fields[0])) &&
        (coa_segment_values::find_by_coaid_segment_segmentcode($coa_combination->coa_id, $coa_squence[0],$fields[0]) ==1))
        {
        $coa_column_name =  array_search($coa_squence[0], $coa_column_names);
        $coa_combination->$column_name_array[$coa_column_name] = $fields[0];
       }
       else{
         $error_msg = $fields[0].' '. $coa_squence[0] .' doesnt exists';
        array_push($error, $error_msg );
      }

      if((!empty($fields[1])) &&
        (coa_segment_values::find_by_coaid_segment_segmentcode($coa_combination->coa_id, $coa_squence[1],$fields[1]) ==1))
        {
        $coa_column_name =  array_search($coa_squence[1], $coa_column_names);
        $coa_combination->$column_name_array[$coa_column_name] = $fields[1];
       }
       else{
         $error_msg = $fields[1].' '. $coa_squence[1] .' doesnt exists';
        array_push($error, $error_msg );
      }
      
      if((!empty($fields[2])) &&
        (coa_segment_values::find_by_coaid_segment_segmentcode($coa_combination->coa_id, $coa_squence[2],$fields[2]) ==1))
        {
        $coa_column_name =  array_search($coa_squence[2], $coa_column_names);
        $coa_combination->$column_name_array[$coa_column_name] = $fields[2];
       }
       else{
         $error_msg = $fields[2].' '. $coa_squence[2] .' doesnt exists';
        array_push($error, $error_msg );
      }
      
      if((!empty($fields[3])) &&
        (coa_segment_values::find_by_coaid_segment_segmentcode($coa_combination->coa_id, $coa_squence[3],$fields[3]) ==1))
        {
        $coa_column_name =  array_search($coa_squence[3], $coa_column_names);
        $coa_combination->$column_name_array[$coa_column_name] = $fields[3];
       }
       else{
         $error_msg = $fields[3].' '. $coa_squence[3] .' doesnt exists';
        array_push($error, $error_msg );
      }
      
      if((!empty($fields[4])) &&
        (coa_segment_values::find_by_coaid_segment_segmentcode($coa_combination->coa_id, $coa_squence[4],$fields[4]) ==1))
        {
        $coa_column_name =  array_search($coa_squence[4], $coa_column_names);
        $coa_combination->$column_name_array[$coa_column_name] = $fields[4];
       }
       else{
         $error_msg = $fields[4].' '. $coa_squence[4] .' doesnt exists';
        array_push($error, $error_msg );
      }
      
      if((!empty($fields[5])) &&
        (coa_segment_values::find_by_coaid_segment_segmentcode($coa_combination->coa_id, $coa_squence[5],$fields[5]) ==1))
        {
        $coa_column_name =  array_search($coa_squence[5], $coa_column_names);
        $coa_combination->$column_name_array[$coa_column_name] = $fields[5];
       }
       else{
         $error_msg = $fields[5].' '. $coa_squence[5] .' doesnt exists';
        array_push($error, $error_msg );
      }
      
      if((!empty($fields[6])) &&
        (coa_segment_values::find_by_coaid_segment_segmentcode($coa_combination->coa_id, $coa_squence[6],$fields[6]) ==1))
        {
        $coa_column_name =  array_search($coa_squence[6], $coa_column_names);
        $coa_combination->$column_name_array[$coa_column_name] = $fields[6];
       }
       else{
         if(isset($fields[6])){
         $error_msg = $fields[6].' '. $coa_squence[6] .' doesnt exists';
        array_push($error, $error_msg );
         }
      }
      
      if((!empty($fields[7])) &&
        (coa_segment_values::find_by_coaid_segment_segmentcode($coa_combination->coa_id, $coa_squence[7],$fields[7]) ==1))
        {
        $coa_column_name =  array_search($coa_squence[7], $coa_column_names);
        $coa_combination->$column_name_array[$coa_column_name] = $fields[7];
       }
       else{
         if(isset($fields[6])){
         $error_msg = $fields[7].' '. $coa_squence[7] .' doesnt exists';
        array_push($error, $error_msg );
         }
      }
      
//      !empty($fields[1]) ? $coa_combination->cost_center = $fields[2] : $coa_combination->cost_center = "";
//      !empty($fields[2]) ? $coa_combination->natural_account = $fields[2] : $coa_combination->natural_account = "";
//      !empty($fields[3]) ? $coa_combination->inter_company = $fields[3] : $coa_combination->inter_company = "";
//      !empty($fields[4]) ? $coa_combination->segment1 = $fields[4] : $coa_combination->segment1 = "";
//      !empty($fields[5]) ? $coa_combination->segment2 = $fields[5] : $coa_combination->segment2 = "";
//      !empty($fields[6]) ? $coa_combination->segment3 = $fields[6] : $coa_combination->segment3 = "";
//      !empty($fields[7]) ? $coa_combination->segment4 = $fields[7] : $coa_combination->segment4 = "";
//    
    }

    //enter error to all errors
    $all_errors = array_merge($all_errors, $error);

    $coa_combination->description = trim(mysql_prep($_POST['description'][$i]));
    $coa_combination->status = trim(mysql_prep($_POST['status'][$i]));
    if (isset($_POST['effective_start_date'][$i])) {
      $coa_combination->effective_start_date = trim(mysql_prep($_POST['effective_start_date'][$i]));
    } else {
      $enterd_effective_start_date = $_POST['effective_start_date'];
      $coa_combination->effective_start_date = date("d-m-Y", strtotime($enterd_effective_start_date));
    }

    if (isset($_POST['effective_end_date'][$i])) {
      $coa_combination->effective_end_date = trim(mysql_prep($_POST['effective_end_date'][$i]));
    } else {
      $coa_combination->effective_end_date = trim(mysql_prep($_POST['effective_end_date']));
    }
    $time = time();
    $coa_combination->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
    $coa_combination->created_by = $_SESSION['user_name'];
    if (empty($coa_combination->coa_id) || empty($coa_combination->combination) ||
            empty($coa_combination->balancing) || empty($coa_combination->cost_center) ||
            empty($coa_combination->natural_account) || empty($coa_combination->inter_company) || count($error) >= 1) {
      $msg = $coa_combination->balancing . "Segment Code, COA id or Description is empty";
//      echo '<pre>';
//      print_r($coa_combination);
//      echo '<pre>';

    } else {
      $new_coa_combination_entry = $coa_combination->save();
      if ($new_coa_combination_entry == 1) {
        $sucessfull_records = $sucessfull_records + 1;
        $msg = $sucessfull_records . ' records are sucessfully saved';
      }//end of COA entry & msg
      else {
        $msg = "Record coundt be saved!!" . mysql_error() .
                ' Returned Value is : ' . $new_option_entry;
      }//end of coa_combination insertion else
    }//end of coa_combination check & new option creation

    unset($error);
  }
}//end of post submit header
?>

<div id="structure">
  <div id="coa_combination">
    <div id="form_top">
      <ul class="form_top">
        <li><input type="button" class="button refresh" value="Refresh" name="refresh"/> </li>
        <li> <a class="button" href="coa_combination.php">New Object</a> </li> 
        <li><input type="button" id="add_object" class="button" value="New Line" name="add_object"/> </li>
        <li><input type="submit" class="button" form="coa_combination_form" name="submit_header" id="submit_header" Value="Save"></li>
        <li> <input type="button" class="button remove_row" id="remove_row" Value="Remove"></li> 
        <li> <input type="submit" class="button delete" form="coa_combination_form" name="delete_row" id="delete_row" value="Delete"></li> 
        <li><input type="reset" class="button" name="reset" form="coa_combination_form" Value="Reset All"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
      </ul>
      <h9> Chart of account combinations </h9>
    </div>
    <!--Start of the option header
   First check if $coa_combination_id fetched from $_GET variable
   If the value exists then fetch the object from option_header table & show the object
   If the value is not set then make it zero & show a blank form-->
    <!--    START OF FORM HEADER-->
    <div id ="form_main"> 
      <form action="coa_combination.php"  method="post" id="coa_combination_form"  name="coa_combination_form"> 
        <ul id="form_box"> 
          <li>   <!--    Place for showing error messages-->
<?php
if (!empty($msg)) {
  echo '<span id="formerror" class="error">';
  if (count($all_errors) > 0) {
    foreach ($all_errors as $key => $value) {
       echo 'Record has error : ' . $value . '<br />';
    }
  }

  if (is_array($msg)) {
    foreach ($msg as $key => $value) {
      $x = $key + 1;
      echo 'Record ' . $x . ' : ' . $value . '<br />';
    }
  } else {
    echo $msg;
  }
  echo '</span>';
}
?> 
            <div id="loading"><img alt="Loading..." 
                                   src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>
            <!--    End of place for showing error messages-->
          </li>
          <li class="ncontrol"><span class="heading">COA Combination Header </span> 
            <div class="three_column"> 
              <ul id="form_header"> 
                <li> 
                  <label><a href="find_coa_combination.php" class="popup"> 
                      <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a> 
                    COA Id : </label> 
                  <input type="text" readonly name="coa_id" 
                         value="<?php echo htmlentities($coa_combination->coa_id); ?>" size="15"                           
                         maxlength="50" id="coa_id" placeholder="System generated number"> 
                  <a name="show" href="coa_combination.php?coa_id=" class="show">
                    <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
                </li> 
                <li><label>COA Structure Id: </label> 
                  <input type="text" name="coa_structure_id" 
                         value="<?php echo htmlentities($coa_combination->coa_structure_id); ?>" 
                         maxlength="50" size="15" id="coa_structure_id"> 
                </li> 
                <li><label>COA Name : </label> 
                  <input type="text" name="coa_name" value="<?php echo htmlentities($coa_combination->coa_name); ?>" 
                         maxlength="50" size="15" id="coa_name"> 
                </li>
                <br>
                <li><label>COA Sequence : </label> 
                  <input type="text" name="coa_sequence" value="<?php echo htmlentities($coa_combination->coa_sequence); ?>" 
                         placeholder ="select & refresh COA Id" maxlength="50" size="150" id="coa_sequence"> 
                </li> 
              </ul>
              <!--end of form header-->
            </div> 
            <!--end of tab div three_column-->
          </li>

          <!--end of Li header-->
          <li class="ncontrol"><span class="heading">COA Segment Value Line </span> 
            <div>
              <table class="form_table">
                <thead> 
                  <tr>
                    <th>Action</th>
                    <th>Combination Id</th>
                    <th>COA Code combination</th>
                    <th>Description</th>
                    <th>Status</th>
                    <th>Start Date</th>
                    <th>End Date</th>
                  </tr>
                </thead>

                <!--//check if $coa_combination_count == 0 then show a blank form-->
<?php if ($coa_combination_count == 0) {
  ?>
                  <tbody id="segment_code_values">
                    <tr id="segment_code_values0">
                      <td>    
                        <ul>
                          <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                          <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                          <li><input type="checkbox" name="segment_code_cb[]" value="<?php echo htmlentities($coa_combination->coa_combination_id); ?>"></li>           
                        </ul>
                      </td>
                      <td>
                        <input type="text" readonly name="coa_combination_id[]" 
                               value="<?php echo htmlentities($coa_combination->coa_combination_id); ?>" size="15"                           
                               maxlength="50" class="coa_combination_id" placeholder="Sys generated number"> 
                      </td>
                      <td>    
                        <input type="text" name="combination[]" value="<?php echo htmlentities($coa_combination->combination); ?>" 
                               size="40" maxlength="250"  id="combination"
  <?php
  if (!empty($pattern))
    echo ' pattern="' . $pattern . '"';
  else {
    echo 'disabled';
  }
  ?>
                      </td>
                      <td>
                        <input type="text" name="description[]" value="<?php echo htmlentities($coa_combination->description); ?>" 
                               size="15" maxlength="150"  id="description"> 
                      </td>
                      <td>                      
                        <Select name="status[]" id="status" >
                          <option value="" ></option>
                          <option value="enabled" 
  <?php echo $coa_combination->status == 'enabled' ? 'selected' : ''; ?> >Enabled</option>
                          <option value="disabled" 
  <?php echo $coa_combination->status == 'disabled' ? 'selected' : ''; ?> >Disabled</option>                                   
                        </select>

                      </td>
                      <td>
                        <input type="date" name="effective_start_date[]" value="<?php echo htmlentities($coa_combination->effective_start_date); ?>" 
                               maxlength="50"  size="15" id="effective_start_date" class="date"> 
                      </td> 
                      <td>
                        <input type="date" name="effective_end_date[]" value="<?php echo htmlentities($coa_combination->effective_end_date); ?>" 
                               maxlength="50" size="15"  id="effective_end_date" class="date"> 
                      </td> 
                    </tr>
                  </tbody>
                  <!--                  Showing a blank form for new entry-->
  <?php
} else {
  echo '<tbody id="segment_code_values">';
  $count = 0;
  foreach ($coa_combination_object as $coa_combination) {
    ?>
                    <!--//end of showing blank form-->

                    <tr id="segment_code_values<?php echo $count ?>" class="remove_row" class="add_row_img">
                      <td>
                        <ul>
                          <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                          <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                          <li><input type="checkbox" name="segment_code_cb[]" value="<?php echo htmlentities($coa_combination->coa_combination_id + 1); ?>"></li>           
                        </ul>
                      </td>
                      <td>
                        <input type="text" readonly name="coa_combination_id[]" 
                               value="<?php echo htmlentities($coa_combination->coa_combination_id); ?>" size="15"                           
                               maxlength="50" class="coa_combination_id" placeholder="Sys generated number"> 
                      </td>
                      <td>    
                        <input type="text" name="combination[]" value="<?php echo htmlentities($coa_combination->combination); ?>" 
                               size="40" maxlength="250"  id="combination"
    <?php
    if (!empty($pattern))
      echo ' pattern="' . $pattern . '"';
    else {
      echo 'disabled';
    }
    ?>
                      </td>
                      <td>
                        <input type="text" name="description[]" value="<?php echo htmlentities($coa_combination->description); ?>" 
                               size="15" maxlength="150"  id="description"> 
                      </td>
                      <td>                      
                        <Select name="status[]" id="status" >
                          <option value="" ></option>
                          <option value="enabled" 
    <?php echo $coa_combination->status == 'enabled' ? 'selected' : ''; ?> >Enabled</option>
                          <option value="disabled" 
    <?php echo $coa_combination->status == 'disabled' ? 'selected' : ''; ?> >Disabled</option>                                   
                        </select>

                      </td>
                      <td>
                        <input type="date" name="effective_start_date[]" value="<?php echo htmlentities($coa_combination->effective_start_date); ?>" 
                               maxlength="50"  size="15" id="effective_start_date" class="date"> 
                      </td> 
                      <td>
                        <input type="date" name="effective_end_date[]" value="<?php echo htmlentities($coa_combination->effective_end_date); ?>" 
                               maxlength="50" size="15"  id="effective_end_date" class="date"> 
                      </td> 
                    </tr>

    <?php
    $count++;
  }
  echo '</tbody>';
}
?>

              </table>
            </div>

          </li>
          <!--end of Li Line-->
        </ul>
      </form> 
    </div>
  </div>
</div>

<!--   end of structure-->
<?php include_template('footer.inc') ?>