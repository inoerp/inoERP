<?php include_once("option.inc"); ?>
<?php
$option = new option_header();
$option->option_id = "";
$option->option_type = "";
$option->access_level = "";
$option->description = "";
$option->module = "";
$option->efid = "";
$option->status = "";
$option->rev_enabled = "";
$option->rev_number = "";
$option->creation_date = "";
$option->created_by = "";

$option_line = new option_line();
$option_line->option_id_l = "";
$option_line->option_line_code = "";
$option_line->value_l = "";
$option_line->description_l = "";
$option_line->efid_l = "";
$option_line->status_l = "";
$option_line->rev_enabled_l = "";
$option_line->rev_number_l = "";
$option_line->effective_start_date = "";
$option_line->effective_end_date = "";
$option_line->created_by_l = "";
$option_line->creation_date_l = "";
$option_line->last_update_by_l = "";
$msg = "";
?>

<!--<script src="option.js"></script>-->
<script>
    function parentWindow(findElement)
    {
        document.getElementById("option_id").value = findElement;
    }
</script>


<?php
if (!empty($_GET["option_id_l"])) {
  $option_id_l = $_GET["option_id_l"];
  $option = option_header::find_by_id($option_id_l);
  $option_line_object = option_line::find_by_option_id($option_id_l);
} else {
  $option_id_l = 0;
}
?>

<?php
if (!empty($_POST['submit_header'])) {

    $option = new option_header();
    $option->option_type = trim(mysql_prep($_POST['option_type']));
    $option->access_level = trim(mysql_prep($_POST['access_level']));
    $option->description = trim(mysql_prep($_POST['description']));
    $option->module = trim(mysql_prep($_POST['module']));
    $option->efid = trim(mysql_prep($_POST['efid']));
    $option->status = trim(mysql_prep($_POST['status']));
    $option->rev_enabled = trim(mysql_prep($_POST['rev_enabled']));
    $option->rev_number = trim(mysql_prep($_POST['rev_number']));
    $time = time();
    $option->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
    $option->created_by = $_SESSION['user_name'];

    if (empty($option->option_type) || empty($option->access_level) || empty($option->description) || empty($option->module)) {

        $msg = "Name, Value, Description or module is empty";
    } else {

        echo '$option->option_idis ' . $option->option_id;

        $new_option_entry = $option->save();

        if ($new_option_entry == 1) {
            $msg = 'Option is sucessfully entered';
            echo '<br />$option->created_by' . $option->created_by;
            echo '<br />$option->creation_date' . $option->creation_date;
            echo '$option->option_idis ' . $option->option_id;
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

    for ($i = 0; $i < count($_POST['option_line_code']); $i++) {

        $option_line = new option_line();
        $option_line->option_id_l = trim(mysql_prep($_POST['option_id_l']));
        $option_line->option_line_code = trim(mysql_prep($_POST['option_line_code'][$i]));
        $option_line->value_l = trim(mysql_prep($_POST['value_l'][$i]));
        $option_line->description_l = trim(mysql_prep($_POST['description_l'][$i]));
        $option_line->efid_l = trim(mysql_prep($_POST['efid_l'][$i]));
        $option_line->status_l = trim(mysql_prep($_POST['status_l'][$i]));
        $option_line->rev_enabled_l = trim(mysql_prep($_POST['rev_enabled_l'][$i]));
        $option_line->rev_number_l = trim(mysql_prep($_POST['rev_number_l'][$i]));
        if (isset($_POST['effective_start_date'][$i]))
        {
            $option_line->effective_start_date = trim(mysql_prep($_POST['effective_start_date'][$i]));
         }else{
             $option_line->effective_start_date = trim(mysql_prep($_POST['effective_start_date']));
         }
         
         if (isset($_POST['effective_end_date'][$i]))
        {
            $option_line->effective_end_date = trim(mysql_prep($_POST['effective_end_date'][$i]));
         }else{
             $option_line->effective_end_date = trim(mysql_prep($_POST['effective_end_date']));
         }
//        $option_line->effective_end_date = trim(mysql_prep($_POST['effective_end_date'][$i]));
        $option_line->created_by_l = $_SESSION['user_name'];
        $timel = time();
        $option_line->creation_date_l = strftime("%d-%m-%Y %H:%M:%S", $timel);
        $option_line->last_update_by_l = $_SESSION['user_name'];

        if (empty($option_line->option_line_code) || empty($option_line->value_l) || empty($option_line->description_l) || empty($option_line->option_id_l)) {
            $msg = "<br/> Code, Value or Description is empty <br />";
        } else {
            $new_option_line_entry = $option_line->create();
            if ($new_option_line_entry) {
                $msg = 'Option Line is sucessfully entered' . ' Returned Value is : ' . $new_option_line_entry;
            }//end of option_line entry & msg
            else {
                $msg = "Record coundt be saved!!" . mysql_error() .
                        ' Returned Value is : ' . $new_option_line_entry;
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
                <li class="h9">New Option Entry! </li>
                <li class="botton"><input type="submit" form="option_header" name="submit_header" Value="Save Header"></li>
                <li class="botton"><input type="submit" form="option_line" name="submit_line"  id="submit_line" Value="Save Line"></li>
                <li class="botton"><input type="reset" name="reset" form="option_line" Value="Reset All"></li>
                <li class="botton"><script>document.write('<a href="' + document.referrer + '">Go Back</a>');</script></li>
            </ul>
        </div>
    <!--Start of the option header
   First check if $option_id_l fetched from $_GET variable
   If the value exists then fetch the object from option_header table & show the object
   If the value is not set then make it zero & show a blank form-->
    <div id ="form_header">
      <form action="option.php"  method="post" id="option_header"  name="option_header">
        <ul id="form_box"> 
          <li>   <!--    Place for showing error messages-->
            <span id="formerror" class="error"> <?php echo $msg; ?> </span>
            <!--    End of place for showing error messages-->
          </li>
          <li class="ncontrol"><span class="heading">Option Header </span>
            <div class="three_column">
              <ul>
                <li>
                  <label><a href="find_option.php" class="popup">
                      <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>
                    Option Id : </label>
                  <!--                  <a href="find_option.php"  target="_blank">Find</a>-->
                  <input type="text" readonly name="option_id" value="<?php echo htmlentities($option->option_id); ?>" 
                         maxlength="50" id="option_id" placeholder="System generated number">
                  <a href="option.php?option_id=">Show</a>
                </li>
                <li><label>Option Type : </label>
                  <input type="text" required name="option_type" value="<?php echo htmlentities($option->option_type); ?>" 
                         maxlength="50" id ="option_type" placeholder="Avoid any special characters">
                </li>
                <li><label>Access Level : </label>
                  <Select name="access_level" required id="access_level" 
                          value="<?php echo htmlentities($option->access_level); ?>"> 
                    <option value="system">System</option>
                    <option value="user" Selected>User</option>
                    <option value="both">Both</option>                
                  </select> 
                </li>
                <li><label>Description : </label>
                  <input type="text" name="description" value="<?php echo htmlentities($option->description); ?>" maxlength="50" 
                         id="description">
                </li>
                <li><label>Module : </label>
                  <input type="module" required name="module" 
                         value="<?php echo htmlentities($option->module); ?>" maxlength="50" id="module">
                </li>
                <li><label>Extra Field : </label>
                  <input type="text" name="efid" value="<?php echo htmlentities($option->efid); ?>" maxlength="50" 
                         id="efid">
                </li>
                <li><label>Status : </label>
                  <Select name="status" id="status"> 
                    <option value="" ></option>   
                    <option value="enabled">Enabled</option>
                    <option value="disabled">Disabled</option>                                   
                  </select>
                </li>
                <li><label>Revision : </label>
                  <Select name="rev_enabled" id="rev_enabled"> 
                    <option value="" ></option>   
                    <option value="enabled">Enabled</option>
                    <option value="disabled">Disabled</option>                                   
                  </select>
                </li>
                <li><label>Revision No: </label>
                  <input type="text"  name="rev_number" value="<?php echo htmlentities($option->rev_number); ?>" maxlength="50" id="rev_number">
                </li>
              </ul>
            </div>
          </li>
        </ul>
      </form> 
    </div>


    <!--Start of the option line
    First check if $option_id_l fetched from $_GET variable
    If the value exists then fetch the object from database & show the object
    If the value is not set then make it zero & show a blank form-->

    <h2>Option Lines  of  <?php
      echo
      isset($option->option_type) ? $option->option_type : null;
      ?> </h2>
    <div id ="form_line">
      <form action="option.php"  method="post" id="option_line"  name="option_line">

<?php if ($option_id_l == 0) { ?>
          <ul id="form_box_line0"> 
            <div class="three_column">
              <li class="control"> <span class="heading">Option Line </span>
                <ul class="showhide">
                  <li> <label>Selected Option Type Id : </label>
                    <input type="text" required readonly name="option_id_l" 
                           value="<?php echo htmlentities($option_line->option_id_l); ?>" maxlength="50" 
                           id ="option_id_l" placeholder="Value defaults from header">
                  </li>
                  <li><label>Option Code : </label>
                    <input type="text" required name="option_line_code[]" value="<?php echo htmlentities($option_line->option_line_code); ?>" maxlength="50" 
                           id ="option_line_code" placeholder="Avoid any special characters">
                  </li>
                  <li><label>Option Value : </label>
                    <input type="text" required name="value_l[]" value="<?php echo htmlentities($option_line->value_l); ?>" maxlength="50" 
                           id ="value_l" placeholder="Value of the option">
                  </li>
                  <li><label>Description : </label>
                    <input type="text"  name="description_l[]" value="<?php echo htmlentities($option_line->description_l); ?>" maxlength="50" 
                           id="description_l">
                  </li>
                  <li><label>Extra Field : </label>
                    <input type="text"  name="efid_l[]" value="<?php echo htmlentities($option_line->efid_l); ?>" maxlength="50" 
                           id="efid_l">
                  </li>
                  <li><label>Status : </label>
                    <Select name="status_l[]" id="status_l"> 
                      <option value="" Selected></option>   
                      <option value="enabled">Enabled</option>
                      <option value="disabled">Disabled</option>                                   
                    </select>
                  </li>
                  <li><label>Revision : </label>
                    <Select name="rev_enabled_l[]" id="rev_enabled_l"> 
                      <option value="" Selected></option>   
                      <option value="enabled">Enabled</option>
                      <option value="disabled">Disabled</option>                                   
                    </select>
                  </li>
                  <li><label>Revision No: </label>
                    <input type="text"  name="rev_number_l[]" value="" maxlength="50" id="rev_number_l">
                  </li>
                  <li><label>Start Date : </label>
                    <input type="date"  name="effective_start_date" value="" 
                           maxlength="50" id="effective_start_date">
                  </li>
                  <li><label>End Date No: </label>
                    <input type="date"  name="effective_end_date" value="" 
                           maxlength="50" id="effective_end_date">
                  </li>
                </ul>
              </li>
            </div>
          </ul>
          <?php
        } else {
          $count = 0;
          foreach ($option_line_object as $option_line) {
            
          }
          ?>           
          <ul id="form_box_line<?php echo $count; ?>"> 
            <div class="three_column">
              <li class="control"> <span class="heading">Option Line </span>
                <ul class="showhide">
                  <li> <label>Selected Option Type Id : </label>
                    <input type="text" required readonly name="option_id_l" 
                           value="<?php echo htmlentities($option_line->option_id_l); ?>" maxlength="50" 
                           id ="option_id_l" placeholder="Value defaults from header">
                  </li>
                  <li><label>Option Code : </label>
                    <input type="text" required name="option_line_code[]" value="<?php echo htmlentities($option_line->option_line_code); ?>" maxlength="50" 
                           id ="option_line_code" placeholder="Avoid any special characters">
                  </li>
                  <li><label>Option Value : </label>
                    <input type="text" required name="value_l[]" value="<?php echo htmlentities($option_line->value_l); ?>" maxlength="50" 
                           id ="value_l" placeholder="Value of the option">
                  </li>
                  <li><label>Description : </label>
                    <input type="text"  name="description_l[]" value="<?php echo htmlentities($option_line->description_l); ?>" maxlength="50" 
                           id="description_l">
                  </li>
                  <li><label>Extra Field : </label>
                    <input type="text"  name="efid_l[]" value="<?php echo htmlentities($option_line->efid_l); ?>" maxlength="50" 
                           id="efid_l">
                  </li>
                  <li><label>Status : </label>
                    <Select name="status_l[]" id="status_l"> 
                      <option value="" Selected></option>   
                      <option value="enabled">Enabled</option>
                      <option value="disabled">Disabled</option>                                   
                    </select>
                  </li>
                  <li><label>Revision : </label>
                    <Select name="rev_enabled_l[]" id="rev_enabled_l"> 
                      <option value="" Selected></option>   
                      <option value="enabled">Enabled</option>
                      <option value="disabled">Disabled</option>                                   
                    </select>
                  </li>
                  <li><label>Revision No: </label>
                    <input type="text"  name="rev_number_l[]" value="" maxlength="50" id="rev_number_l">
                  </li>
                  <li><label>Start Date : </label>
                    <input type="date"  name="effective_start_date" value="" 
                           maxlength="50" id="effective_start_date">
                  </li>
                  <li><label>End Date No: </label>
                    <input type="date"  name="effective_end_date" value="" 
                           maxlength="50" id="effective_end_date">
                  </li>
                </ul>
              </li>
            </div>
          </ul>

          <?php
          $count++;
        }
        ?>
      </form> 
    </div>
    <input type="button" id="add_object" value="Add a new Line" name="add_object"/>

  </div>
</div>
<!--   end of structure-->

<?php include_template('footer.inc') ?>
