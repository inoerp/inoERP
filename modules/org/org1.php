<?php include_once("org.inc"); ?>
<?php
//set the option id of option line as 0
//@required : To create line form for new entry
//@required : To create line form where only header is entered
$org_types = org_header::org_types();
$org_id_l = 0;
$org = new org_header;
$org->org_id = "";
$org->org_type = "";
$org->name = "";
$org->description = "";
$org->enterprise_id = "";
$org->legal_id = "";
$org->business_id = "";
$org->organization_id = "";
$org->ef_id = "";
$org->legal_id = "";
$org->status = "";
$org->rev_enabled = "";
$org->rev_number = "";
$org->created_by = "";
$org->creation_date = "";
$org->last_update_by = "";
$org->last_update_date = "";
?>
<!--<script src="option.js"></script>-->
<script>
  function parentWindow(findElement)
  {
    document.getElementById("org_id").value = findElement;
    $('#form_box a.show').prop('href', 'org.php?org_id_l=' + findElement);
  }
</script>
<?php
//if (!empty($_GET["org_id"])) {
//  $org_id = $_GET["org_id"];
//  $org = option_header::find_by_id($org_id);
//  $org_line_object = option_line::find_by_option_id($org_id_l);
//  if (count($org_line_object) == 0) {
//    $org_id_l = 0;
//  }
//} else {
//  $org_id_l = 0;
//}
?>
<?php
if (!empty($_POST['submit_header'])) {
  $org = new option_header();
  if (empty($_POST['org_id'])) {
    $org->org_id = null;
  } else {
    $org->org_id = trim(mysql_prep($_POST['org_id']));
  }
  $org->org_type = trim(mysql_prep($_POST['org_type']));
  $org->name = trim(mysql_prep($_POST['name']));
  $org->description = trim(mysql_prep($_POST['description']));
  
  switch($org->org_type){
    case "ENTERPRISE":
          $org->enterprise_id = '';
          $org->legal_id = ''; 
          $org->business_id = '';
          $org->inventory_id = '';
      break;
    
        case "LEGAL_ORG":
          $org->enterprise_id = trim(mysql_prep($_POST['enterprise_id']));
          $org->legal_id = ''; 
          $org->business_id = '';
          $org->inventory_id = '';
      break;
    
        case "BUSINESS_ORG":
          $org->enterprise_id = trim(mysql_prep($_POST['enterprise_id']));
          $org->legal_id = trim(mysql_prep($_POST['legal_id'])); 
          $org->business_id = '';
          $org->inventory_id = '';
      break;
    
        case "INVENTORY_ORG":
          $org->enterprise_id = trim(mysql_prep($_POST['enterprise_id']));
          $org->legal_id = trim(mysql_prep($_POST['legal_id'])); 
          $org->business_id = trim(mysql_prep($_POST['business_id']));
          $org->inventory_id = '';
      break;
    
    default:
          $org->enterprise_id = trim(mysql_prep($_POST['enterprise_id']));
          $org->legal_id = trim(mysql_prep($_POST['legal_id'])); 
          $org->business_id = trim(mysql_prep($_POST['business_id']));
          $org->inventory_id = trim(mysql_prep($_POST['inventory_id']));
      break;
  }

  $org->ef_id = trim(mysql_prep($_POST['ef_id']));
  $org->status = trim(mysql_prep($_POST['status']));
  $org->rev_enabled = trim(mysql_prep($_POST['rev_enabled']));
  $org->rev_number = trim(mysql_prep($_POST['rev_number']));
  $time = time();
  $org->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
  $org->created_by = $_SESSION['user_name'];
  if (empty($org->org_type) || empty($org->name) || empty($org->description) ) {
    $msg = "Name, Type , Description or module is empty";
  } else {
//    echo '$org->option_idis ' . $org->option_id;
    $new_option_entry = $org->save();
    if ($new_option_entry == 1) {
      $msg = 'Option is sucessfully saved';
//            echo '<br />$org->created_by' . $org->created_by;
//            echo '<br />$org->creation_date' . $org->creation_date;
//            echo '$org->option_idis ' . $org->option_id;
    }//end of option entry & msg
    else {
      $msg = "Record coundt be saved!!" . mysql_error() .
              ' Returned Value is : ' . $new_option_entry;
    }//end of option insertion else
  }//end of option check & new option creation
}//end of post submit header
?>
<?php
if (!empty($_POST['submit_line'])) {
  $msg = array();
  for ($i = 0; $i < count($_POST['option_line_code']); $i++) {
    $org_line = new option_line();
    $org_line->option_id_l = trim(mysql_prep($_POST['option_id_l']));
    $org_line->option_line_id = trim(mysql_prep($_POST['option_line_id'][$i]));
    $org_line->option_line_code = trim(mysql_prep($_POST['option_line_code'][$i]));
    $org_line->value_l = trim(mysql_prep($_POST['value_l'][$i]));
    $org_line->description_l = trim(mysql_prep($_POST['description_l'][$i]));
    $org_line->efid_l = trim(mysql_prep($_POST['efid_l'][$i]));
    $org_line->status_l = trim(mysql_prep($_POST['status_l'][$i]));
    $org_line->rev_enabled_l = trim(mysql_prep($_POST['rev_enabled_l'][$i]));
    $org_line->rev_number_l = trim(mysql_prep($_POST['rev_number_l'][$i]));
    if (isset($_POST['effective_start_date'][$i])) {
//      $enterd_effective_start_date = $_POST['effective_start_date'][$i];
//      $date = new DateTime($enterd_effective_start_date);
//      $org_line->effective_start_date = $date->format("d-m-Y");
      $org_line->effective_start_date = trim(mysql_prep($_POST['effective_start_date'][$i]));
    } else {
      $enterd_effective_start_date = $_POST['effective_start_date'];
      $org_line->effective_start_date = date("d-m-Y", strtotime($enterd_effective_start_date));
    }
    if (isset($_POST['effective_end_date'][$i])) {
      $org_line->effective_end_date = trim(mysql_prep($_POST['effective_end_date'][$i]));
    } else {
      $org_line->effective_end_date = trim(mysql_prep($_POST['effective_end_date']));
    }
    $org_line->created_by_l = $_SESSION['user_name'];
    $timel = time();
    $org_line->creation_date_l = strftime("%d-%m-%Y %H:%M:%S", $timel);
    $org_line->last_update_by_l = $_SESSION['user_name'];
    if (empty($org_line->option_line_code) || empty($org_line->value_l) || empty($org_line->description_l) || empty($org_line->option_id_l)) {
      $msg = "<br/> Code, Value or Description is empty <br />
              Entered option_line_code is " . "$org_line->option_line_code" .
              "Entered description_l is " . "$org_line->description_l" .
              "Entered option_id_l is " . "$org_line->option_id_l" .
              "Entered value_l is " . "$org_line->value_l";
    } else {
      $new_option_line_entry = $org_line->save();
      if ($new_option_line_entry == 1) {
        $new_msg = 'Option Line is sucessfully saved';
        array_push($msg, $new_msg);
      }//end of option_line entry & msg
      else {
        $new_msg = "No changes/record coundt be saved!!" . mysql_error() . ' Returned Value is :no change/ ' . $new_option_line_entry;
        array_push($msg, $new_msg);
      }//end of option_line insertion else
    }//end of option_line check & new option_line creation
  }
//    echo '<span class="message">' . $msg . '</span>';
}//end of post submit line
?>
<div id="structure">
  <div id="option">
    <div id="form_top">
      <ul class="form_top">
        <li><h9>New Option Entry! </h9></li>
        <li> <a class="button" href="org.php">Create New</a> </li> 
        <li><input type="submit" class="button" form="org_header" name="submit_header" id="submit_header" Value="Save Header"></li>
        <li><input type="submit" class="button" form="org_line" name="submit_line"  id="submit_line" Value="Save Line"></li>
        <li><input type="reset" class="button" name="reset" form="org_line" Value="Reset All"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
      </ul>
    </div>
    <!--Start of the option header
   First check if $org_id_l fetched from $_GET variable
   If the value exists then fetch the object from option_header table & show the object
   If the value is not set then make it zero & show a blank form-->
    <!--    START OF FORM HEADER-->
    <div id ="form_header"> 
      <form action="org.php"  method="post" id="org_header"  name="org_header"> 
        <ul id="form_box"> 
          <li> 
            <!--    Place for showing error messages--> 
            <span id="formerror" class="error"> 
            </span> 
            <!--    End of place for showing error messages--> 
          </li> 
          <li class="ncontrol"><span class="heading">Org Header </span> 
            <div class="three_column"> 
              <ul> 
                <li> 
                  <label><a href="find_org.php" class="popup"> 
                      <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a> 
                    Org Id : </label> 
                  <input type="text" readonly name="org_id" value="<?php echo htmlentities($org->org_id);
?>"                          maxlength="50" id="org_id" placeholder="System generated number"> 
                  <a name="show" href="org.php?org_id_l=" class="show">Show</a> 
                </li> 
                <li><label>Org Type : </label> 
                  <select name="org_type" id="org_type" > 
                    <option value="" ></option> 
                    <?php
                    for ($i = 0; $i <= 3; $i++) {
                      echo '<option value="' . $org_types[$i]->option_line_code . '">' . $org_types[$i]->option_line_code . '</option>';
                    }
                    ?> 
                  </select> 
                </li> 
                <li><label>Name : </label> 
                  <input type="text" name="name" value="<?php echo htmlentities($org->description);
                    ?>" maxlength="50"  id="name"> 
                </li> 
                <li><label>Enterprise : </label> 
                  <input type="text" required name="enterprise_id" value="<?php echo htmlentities($org->enterprise_id);
                    ?>"  maxlength="50" id ="enterprise_id" placeholder="No special characters"> 
                </li> 
                <li><label>Legal Org : </label> 
                  <input type="text" required name="legal_id" value="<?php echo htmlentities($org->legal_id);
                    ?>"   maxlength="50" id ="legal_id" placeholder="No special characters"> 
                </li> 
                <li><label>Business Org : </label> 
                  <input type="text" required name="business_id" value="<?php echo htmlentities($org->business_id);
                    ?>" maxlength="50" id ="business_id" placeholder="No special characters"> 
                </li> 
                <li><label>Description : </label> 
                  <input type="text" name="description" value="<?php echo htmlentities($org->description);
                    ?>" maxlength="50" id="description"> 
                </li> 
                <li><label>Extra Field : </label> 
                  <input type="text" name="ef_id" value="<?php echo htmlentities($org->ef_id);
                    ?>" maxlength="50"  id="ef_id"> 
                </li> 
                <li><label>Status : </label> 
                  <Select name="status" id="status" > 
                    <option value="" ></option> 
                    <option value="" >TEST 01</option> 
                  </select> 
                </li> 
                <li><label>Revision : </label> 
                  <Select name="rev_enabled" id="rev_enabled"> 
                    <option value="" ></option> 
                    <option value="" >TEST 01</option> 
                  </select> 
                </li> 
                <li><label>Revision No: </label> 
                  <input type="text"  name="rev_number" value="<?php echo htmlentities($org->rev_number);
                    ?>" maxlength="50" id="rev_number"> 
                </li> 
              </ul> 
            </div> 
          </li> 
        </ul> 
      </form> 
    </div>
    <!--END OF FORM HEADER-->
    <!--Start of the option line
    First check if $org_id_l fetched from $_GET variable
    If the value exists then fetch the object from database & show the object
    If the value is not set then make it zero & show a blank form-->
    <h2>Option Lines  of  <?php echo isset($org->option_type) ? $org->option_type : null; ?> </h2>
    <div id ="form_line">
      <form action="option.php"  method="post" id="option_line"  name="option_line">
        <?php if ($org_id_l == 0) { ?>
          <ul id="form_box_line0"> 
            <div class="three_column">
              <li class="control"> <span class="heading">Option Line </span>
                <ul class="showhide">
                  <li> <label>Selected Option Type Id : </label>
                    <input type="text" required readonly name="option_id_l" 
                           value="<?php echo htmlentities($org_line->option_id_l); ?>" maxlength="50" 
                           id ="option_id_l" placeholder="Value defaults from header">
                  </li>
                  <li> <label>Option Line Id : </label>
                    <input type="text" required readonly name="option_line_id[]"  class ="option_line_id"
                           value="<?php echo htmlentities($org_line->option_line_id); ?>" maxlength="50" 
                           id ="option_line_id" placeholder="Sys generated no">
                  </li>
                  <li><label>Option Code : </label>
                    <input type="text" required name="option_line_code[]" value="<?php echo htmlentities($org_line->option_line_code); ?>" maxlength="50" 
                           id ="option_line_code" placeholder="Avoid any special characters">
                  </li>
                  <li><label>Option Value : </label>
                    <input type="text" required name="value_l[]" value="<?php echo htmlentities($org_line->value_l); ?>" maxlength="50" 
                           id ="value_l" placeholder="Value of the option">
                  </li>
                  <li><label>Description : </label>
                    <input type="text"  name="description_l[]" value="<?php echo htmlentities($org_line->description_l); ?>" maxlength="50" 
                           id="description_l">
                  </li>
                  <li><label>Extra Field : </label>
                    <input type="text"  name="efid_l[]" value="<?php echo htmlentities($org_line->efid_l); ?>" maxlength="50" 
                           id="efid_l">
                  </li>
                  <li><label>Status : </label>
                    <Select name="status_l[]" id="status_l"> 
                      <option value="" ></option>   
                      <option value="enabled" <?php
          echo
          $org_line->status_l == 'enabled' ? 'selected' : '';
          ?> >Enabled</option>
                      <option value="disabled" <?php
                      echo
                      $org_line->status_l == 'disabled' ? 'selected' : '';
                      ?> >Disabled</option>                                   
                    </select>
                  </li>
                  <li><label>Revision : </label>
                    <Select name="rev_enabled_l[]" id="rev_enabled_l"> 
                      <option value="" ></option>   
                      <option value="enabled"  <?php
                              echo
                              $org_line->rev_enabled_l == 'enabled' ? 'selected' : '';
                              ?> >Enabled</option>
                      <option value="disabled" <?php
                    echo
                    $org_line->rev_enabled_l == 'disabled' ? 'selected' : '';
                    ?> >Disabled</option>                                   
                    </select>
                  </li>
                  <li><label>Revision No : </label>
                    <input type="text"  name="rev_number_l[]" value="" maxlength="50" id="rev_number_l">
                  </li>
                  <li><label>Start Date : </label>
                    <input type="date"  name="effective_start_date[]"  
                           value="<?php echo htmlentities($org_line->effective_start_date); ?>"
                           maxlength="50" id="effective_start_date">
                  </li>
                  <li><label>End Date : </label>
                    <input type="date"  name="effective_end_date[]" 
                           value="<?php echo htmlentities($org_line->effective_end_date); ?>"
                           maxlength="50" id="effective_end_date">
                  </li>
                </ul>
              </li>
            </div>
          </ul>
          <?php
        } else {
          $count = 0;
          foreach ($org_line_object as $org_line) {
            ?>
            <ul id="form_box_line<?php echo $count; ?>"> 
              <div class="three_column">
                <li class="control"> <span class="heading">Option Line 
                    <span class="deleteButton"><a href="option_delete.php?option_line_id=<?php echo htmlentities($org_line->option_line_id); ?>">Quick Delete</a> </span></span>
                  <ul class="showhide">
                    <li> <label>Selected Option Type Id : </label>
                      <input type="text" required readonly name="option_id_l" 
                             value="<?php echo htmlentities($org_line->option_id_l); ?>" maxlength="50" 
                             id ="option_id_l" placeholder="Value defaults from header">
                    </li>
                    <li> <label>Option Line Id : </label>
                      <input type="text" required readonly name="option_line_id[]" class ="option_line_id"
                             value="<?php echo htmlentities($org_line->option_line_id); ?>" maxlength="50" 
                             id ="option_line_id" placeholder="Sys generated no">
                    </li>
                    <li><label>Option Code : </label>
                      <input type="text" required name="option_line_code[]" value="<?php echo htmlentities($org_line->option_line_code); ?>" maxlength="50" 
                             id ="option_line_code" placeholder="Avoid any special characters">
                    </li>
                    <li><label>Option Value : </label>
                      <input type="text" required name="value_l[]" value="<?php echo htmlentities($org_line->value_l); ?>" maxlength="50" 
                             id ="value_l" placeholder="Value of the option">
                    </li>
                    <li><label>Description : </label>
                      <input type="text"  name="description_l[]" value="<?php echo htmlentities($org_line->description_l); ?>" maxlength="50" 
                             id="description_l">
                    </li>
                    <li><label>Extra Field : </label>
                      <input type="text"  name="efid_l[]" value="<?php echo htmlentities($org_line->efid_l); ?>" maxlength="50" 
                             id="efid_l">
                    </li>
                    <li><label>Status : </label>
                      <Select name="status_l[]" id="status_l"> 
                        <option value="" ></option>   
                        <option value="enabled" <?php
                        echo
                        $org_line->status_l == 'enabled' ? 'selected' : '';
                        ?> >Enabled</option>
                        <option value="disabled" <?php
                        echo
                        $org_line->status_l == 'disabled' ? 'selected' : '';
                        ?> >Disabled</option>                                    
                      </select>
                    </li>
                    <li><label>Revision : </label>
                      <Select name="rev_enabled_l[]" id="rev_enabled_l"> 
                        <option value="" ></option>
                        <option value="enabled"  <?php
                        echo
                        $org_line->rev_enabled_l == 'enabled' ? 'selected' : '';
                        ?> >Enabled</option>
                        <option value="disabled" <?php
                        echo
                        $org_line->rev_enabled_l == 'disabled' ? 'selected' : '';
                        ?> >Disabled</option>  
                      </select>
                    </li>
                    <li><label>Revision No : </label>
                      <input type="text"  name="rev_number_l[]" value="" maxlength="50" id="rev_number_l">
                    </li>
                    <li><label>Start Date : </label>
                      <input type="date"  name="effective_start_date[]" 
                             value="<?php echo htmlentities($org_line->effective_start_date); ?>"
                             maxlength="50" id="effective_start_date">
                    </li>
                    <li><label>End Date : </label>
                      <input type="date"  name="effective_end_date[]" 
                             value="<?php echo htmlentities($org_line->effective_end_date); ?>"
                             maxlength="50" id="effective_end_date">
                    </li>
                  </ul>
                </li>
              </div>
            </ul>
    <?php
    $count++;
  }
}
?>
      </form> 
    </div>
    <input type="button" id="add_object" value="Add a new Line" name="add_object"/>
  </div>
</div>
<!--   end of structure-->
<?php include_template('footer.inc') ?>