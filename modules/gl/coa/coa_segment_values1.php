<?php include_once("coa.inc"); ?>
<?php
$msg ="";
$coa_segment_values_count = 0;

$coa_account_types = coa_segment_values::coa_account_types();
$coa_segment_values = new coa_segment_values;
$coa_segment_values->coa_segment_values_id = "";
$coa_segment_values->coa_id = "";
$coa_segment_values->coa_segments = "";
$coa_segment_values->account_type = "";
$coa_segment_values->coa_name = "";
$coa_segment_values->coa_structure_id = "";
$coa_segment_values->segment_code = "";
$coa_segment_values->description = "";
$coa_segment_values->efid = "";
$coa_segment_values->status = "";
$coa_segment_values->rev_enabled = "";
$coa_segment_values->rev_number = "";
$coa_segment_values->effective_start_date = "";
$coa_segment_values->effective_end_date = "";
$coa_segment_values->created_by = "";
$coa_segment_values->creation_date = "";
$coa_segment_values->last_update_by = "";
$coa_segment_values->last_update_date = "";
?>  

<?php
if (!empty($_GET["coa_id"]) && !empty($_GET["coa_segments"])) {
  $coa_id = $_GET["coa_id"];
  $coa_segments = $_GET["coa_segments"];

  $coa = coa::find_by_id($coa_id);
  $coa_segment_values = new coa_segment_values;
  $coa_segment_values->coa_id = $coa->coa_id;
  $coa_segment_values->coa_structure_id = $coa->structure;
  $coa_segment_values->coa_name = $coa->name;
  $coa_segment_values->coa_segments = $coa_segments;

  $coa_segment_values_object = coa_segment_values::find_by_coa_id_and_segments($coa_id, $coa_segments);

  if (count($coa_segment_values_object) == 0) {
    $coa_segment_values_count = 0;
  } else {
    $coa_segment_values_count = count($coa_segment_values_object);
  }
// echo '<pre>';
//  print_r($coa_segment_values_object);
//  echo '<pre>';
}
?>

<?php
if (!empty($_POST['delete_row'])) {

//echo '<pre>';
//print_r($_POST);
//echo '<pre>';

  for ($i = 0; $i < count($_POST['coa_segment_values_id']); $i++) {

    if (isset($_POST['segment_code_cb'][$i])) {
      $delete_coa_segment_values_id = $_POST['segment_code_cb'][$i] - 1;
      $delete = $coa_segment_values->delete($delete_coa_segment_values_id);
      if ($delete == 1) {
        $msg = $_POST['segment_code'][$i] . ' is sucessfully deleted';
      }//end of COA delete
      else {
        $msg = "Record coundt be delete!!" . mysql_error() .
                ' Returned Value is : ' . $delete;
      }
    }
    
  }//end of for loop

  $coa_segment_values = new coa_segment_values();
  $coa_segment_values->coa_id = trim(mysql_prep($_POST['coa_id']));
  $coa_segment_values->coa_structure_id = trim(mysql_prep($_POST['coa_structure_id']));
  $coa_segment_values->coa_name = trim(mysql_prep($_POST['coa_name']));
  $coa_segment_values->coa_segments = trim(mysql_prep($_POST['coa_segments']));
}//end of delete
?>

<?php
$msg;

if (!empty($_POST['submit_header'])) {

  for ($i = 0; $i < count($_POST['segment_code']); $i++) {
    $coa_segment_values = new coa_segment_values();
    if (empty($_POST['coa_segment_values_id'])) {
      $coa_segment_values->coa_segment_values_id = null;
    } else {
      $coa_segment_values->coa_segment_values_id = trim(mysql_prep($_POST['coa_segment_values_id'][$i]));
    }
    $coa_segment_values->coa_id = trim(mysql_prep($_POST['coa_id']));
    $coa_segment_values->coa_structure_id = trim(mysql_prep($_POST['coa_structure_id']));
    $coa_segment_values->coa_name = trim(mysql_prep($_POST['coa_name']));
    $coa_segment_values->coa_segments = trim(mysql_prep($_POST['coa_segments']));
    if (isset($_POST['account_type'][$i])){
    $coa_segment_values->account_type = trim(mysql_prep($_POST['account_type'][$i]));
    }else{
      $coa_segment_values->account_type = 0;
    }
        $coa_segment_values->segment_code = trim(mysql_prep($_POST['segment_code'][$i]));
    $coa_segment_values->description = trim(mysql_prep($_POST['description'][$i]));
    $coa_segment_values->status = trim(mysql_prep($_POST['status'][$i]));
    if (isset($_POST['effective_start_date'][$i])) {
      $coa_segment_values->effective_start_date = trim(mysql_prep($_POST['effective_start_date'][$i]));
    } else {
      $enterd_effective_start_date = $_POST['effective_start_date'];
      $coa_segment_values->effective_start_date = date("d-m-Y", strtotime($enterd_effective_start_date));
    }

    if (isset($_POST['effective_end_date'][$i])) {
      $coa_segment_values->effective_end_date = trim(mysql_prep($_POST['effective_end_date'][$i]));
    } else {
      $coa_segment_values->effective_end_date = trim(mysql_prep($_POST['effective_end_date']));
    }
    $time = time();
    $coa_segment_values->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
    $coa_segment_values->created_by = $_SESSION['user_name'];
    if (empty($coa_segment_values->coa_id) || empty($coa_segment_values->coa_segments)) {
      $msg = "Segment Code, Type or Description 
      value is empty";
    } else {
      $new_coa_segment_values_entry = $coa_segment_values->save();
      if ($new_coa_segment_values_entry == 1) {
        $msg = 'Records are sucessfully saved';
      }//end of COA entry & msg
      else {
        $msg = "Record coundt be saved!!" . mysql_error() .
                ' Returned Value is : ' . $new_option_entry;
      }//end of coa_segment_values insertion else
    }//end of coa_segment_values check & new option creation
    
  }
}//end of post submit header
?>

<div id="structure">
  <div id="coa_segment_values">
    <div id="form_top">
      <ul class="form_top">
        <li><input type="button" class="button refresh" value="Refresh" name="refresh"/> </li>
        <li> <a class="button" href="coa_segment_values.php">New Object</a> </li> 
        <li><input type="button" id="add_object" class="button" value="New Line" name="add_object"/> </li>
        <li><input type="submit" class="button" form="coa_segment_values_form" name="submit_header" id="submit_header" Value="Save"></li>
        <li> <input type="button" class="button remove_row" id="remove_row" Value="Remove"></li> 
        <li> <input type="submit" class="button delete" form="coa_segment_values_form" name="delete_row" id="delete_row" value="Delete"></li> 
        <li><input type="reset" class="button" name="reset" form="coa_segment_values_form" Value="Reset All"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
      </ul>
      <h9> COA Segment Values </h9>
    </div>
    <!--Start of the option header
   First check if $coa_segment_values_id fetched from $_GET variable
   If the value exists then fetch the object from option_header table & show the object
   If the value is not set then make it zero & show a blank form-->
    <!--    START OF FORM HEADER-->
    <div id ="form_main"> 
      <form action="coa_segment_values.php"  method="post" id="coa_segment_values_form"  name="coa_segment_values_form"> 
        <ul id="form_box"> 
          <li>   <!--    Place for showing error messages-->
            <span id="formerror" class="error"> <?php
              if (is_array($msg)) {
                foreach ($msg as $key => $value) {
                  $x = $key + 1;
                  echo 'Record ' . $x . ' : ' . $value . '<br />';
                }
              } else {
                echo $msg;
              }
              ?> </span>
            <div id="loading"><img alt="Loading..." 
                                   src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>
            <!--    End of place for showing error messages-->
          </li>
          <li class="ncontrol"><span class="heading">COA Segment Value Header </span> 
            <div class="three_column"> 
              <ul id="form_header"> 
                <li> 
                  <label><a href="find_coa.php" class="popup"> 
                      <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a> 
                    COA Id : </label> 
                  <input type="text" readonly name="coa_id" 
                         value="<?php echo htmlentities($coa_segment_values->coa_id); ?>" size="15"                           
                         maxlength="50" id="coa_id" placeholder="System generated number"> 

                </li> 
                <li><label>COA Structure Id: </label> 
                  <input type="text" name="coa_structure_id" 
                         value="<?php echo htmlentities($coa_segment_values->coa_structure_id); ?>" 
                         maxlength="50" size="15" id="coa_structure_id"> 
                </li> 
                <li><label>COA Name : </label> 
                  <input type="text" name="coa_name" value="<?php echo htmlentities($coa_segment_values->coa_name); ?>" 
                         maxlength="50" size="15" id="coa_name"> 
                </li> 
                <li><label>Account Segments : </label> 
                  <select name="coa_segments" id="coa_segments"  class="coa_segments"> 
                    <?php
                    if (empty($coa_segment_values->coa_segments)) {
                      echo '<option value="" >First select the COA</option>';
                    } else {
                      echo '<option value="' . htmlentities($coa_segment_values->coa_segments) . '" >'
                      . htmlentities($coa_segment_values->coa_segments) . '</option>';
                    }
                    ?>
                  </select> 
                  <a name="show" href="coa_segment_values.php?" class="show">
                    <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
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
                    <th>Segment Id</th>
                    <th>Segment Code</th>
                    <th>Description</th>
                    <th>Account Type</th>
                    <th>Status</th>
                    <th>Start Date</th>
                    <th>End Date</th>
                  </tr>
                </thead>

                <!--//check if $coa_segment_values_count == 0 then show a blank form-->
                <?php if ($coa_segment_values_count == 0) {
                  ?>
                  <tbody id="segment_code_values">
                    <tr id="segment_code_values0">
                      <td>    
                        <ul>
                          <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                          <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                          <li><input type="checkbox" name="segment_code_cb[]" value="<?php echo htmlentities($coa_segment_values->coa_segment_values_id); ?>"></li>           
                        </ul>
                      </td>
                      <td>
                        <input type="text" readonly name="coa_segment_values_id[]" 
                               value="<?php echo htmlentities($coa_segment_values->coa_segment_values_id); ?>" size="15"                           
                               maxlength="50" class="coa_segment_values_id" placeholder="Sys generated number"> 
                      </td>
                      <td>    
                        <input type="text" name="segment_code[]" value="<?php echo htmlentities($coa_segment_values->segment_code); ?>" 
                               size="15" maxlength="10"  id="segment_code"> 
                      </td>
                      <td>
                        <input type="text" name="description[]" value="<?php echo htmlentities($coa_segment_values->description); ?>" 
                               size="15" maxlength="150"  id="description"> 
                      </td>
                      <td class="account_type_td" >
                        <select name="account_type[]"  class="account_type" disabled> 
                          <option value="" ></option>

                        </select> 
                      </td>
                      <td>                      
                        <Select name="status[]" id="status" >
                          <option value="" ></option>
                          <option value="enabled" 
                                  <?php echo $coa_segment_values->status == 'enabled' ? 'selected' : ''; ?> >Enabled</option>
                          <option value="disabled" 
                                  <?php echo $coa_segment_values->status == 'disabled' ? 'selected' : ''; ?> >Disabled</option>                                   
                        </select>

                      </td>
                      <td>
                        <input type="date" name="effective_start_date[]" value="<?php echo htmlentities($coa_segment_values->effective_start_date); ?>" 
                               maxlength="50"  size="15" id="effective_start_date" class="date"> 
                      </td> 
                      <td>
                        <input type="date" name="effective_end_date[]" value="<?php echo htmlentities($coa_segment_values->effective_end_date); ?>" 
                               maxlength="50" size="15"  id="effective_end_date" class="date"> 
                      </td> 
                    </tr>
                  </tbody>
<!--                  Showing a blank form for new entry-->
                  <?php
                } else {
                  echo '<tbody id="segment_code_values">';
                  $count = 0;
                  foreach ($coa_segment_values_object as $coa_segment_values) {
                    ?>
                    <!--//end of showing blank form-->

                    <tr id="segment_code_values<?php echo $count ?>" class="remove_row" class="add_row_img">
                      <td>
                        <ul>
                          <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                          <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                          <li><input type="checkbox" name="segment_code_cb[]" value="<?php echo htmlentities($coa_segment_values->coa_segment_values_id + 1); ?>"></li>           
                        </ul>
                      </td>
                      <td>
                        <input type="text" readonly name="coa_segment_values_id[]" 
                               value="<?php echo htmlentities($coa_segment_values->coa_segment_values_id); ?>" size="15"                           
                               maxlength="50" class="coa_segment_values_id" placeholder="Sys generated number"> 
                      </td>
                      <td>    
                        <input type="text" name="segment_code[]" value="<?php echo htmlentities($coa_segment_values->segment_code); ?>" 
                               size="15" maxlength="10"  id="segment_code"> 
                      </td>
                      <td>
                        <input type="text" name="description[]" value="<?php echo htmlentities($coa_segment_values->description); ?>" 
                               size="15" maxlength="150"  id="description"> 
                      </td>
                      <td class="account_type_td" >
                        <select name="account_type[]" class="account_type" disabled> 
                          
                          <?php
                          if (empty($coa_segment_values->account_type)) {
                            echo '<option value="" ></option> ';
                            foreach ($coa_account_types as $records) {
                              echo '<option value="' . $records->option_line_code . '">' . $records->description_l . '</option>';
                            }
                          } else {
                            echo '<option value="';
                            foreach ($coa_account_types as $records) {
                              if ($records->option_line_code == $coa_segment_values->account_type)
                                echo $records->option_line_code . '">' . $records->description_l;
                            }
                            echo '</option>';
                          }
                          ?> 
                        </select> 
                      </td>
                      <td>                      
                        <Select name="status[]" id="status" >
                          <option value="" ></option>
                          <option value="enabled" 
                                  <?php echo $coa_segment_values->status == 'enabled' ? 'selected' : ''; ?> >Enabled</option>
                          <option value="disabled" 
                                  <?php echo $coa_segment_values->status == 'disabled' ? 'selected' : ''; ?> >Disabled</option>                                   
                        </select>

                      </td>
                      <td>
                        <input type="date" name="effective_start_date[]" value="<?php echo htmlentities($coa_segment_values->effective_start_date); ?>" 
                               maxlength="50"  size="15" id="effective_start_date" class="date"> 
                      </td> 
                      <td>
                        <input type="date" name="effective_end_date[]" value="<?php echo htmlentities($coa_segment_values->effective_end_date); ?>" 
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