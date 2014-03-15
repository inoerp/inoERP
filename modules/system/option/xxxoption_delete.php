<?php
include_once("option.inc");
$msg = "";
?>

<?php
if (!empty($_GET["option_line_id"])) {
  $option_line_id = $_GET["option_line_id"];
  $option_line = option_line::find_by_id($option_line_id);
}
?>

<?php
if (!empty($_POST['submit_delete'])) {
  $option_line = new option_line();
  $option_line->option_line_id = trim(mysql_prep($_POST['option_line_id']));
  $option_line->option_id_l=trim(mysql_prep($_POST['option_id_l']));
  $option = option_header::find_by_id($option_line->option_id_l);
  if ($option->access_level == 'system') {
    $msg = "You can delete this record. <br />This option code belongs to a system option type" ;
  } else {
    $option_delete = option_line::delete($option_line->option_line_id);
    if ($option_delete == 1) {
      $option_line->option_id_l = "";
      $option_line->option_line_id = "";
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
      $msg = "Option code is sucessfully deleted";
    } else {
      $msg = "Option code deletion failed!!";
    }
  }
}
?>

<div id="structure">
  <div id="option">
    <div id="form_top">
      <ul class="form_top">
        <li class="h9">Delete Option! </li>
        <li class="botton"><input type="submit" form="option_delete" name="submit_delete" id="submit_delete" 
                                  Value="Confirm Delete"></li>
        <li class="botton"><a href="option.php">Option Page</a></li>
        <li class="botton"><script>document.write('<a href="' + document.referrer + '">Go Back</a>');</script></li>
      </ul>
    </div>

    <!--Start of the option header
   First check if $option_id_l fetched from $_GET variable
   If the value exists then fetch the object from option_header table & show the object
   If the value is not set then make it zero & show a blank form-->

    <!--    START OF FORM HEADER-->
    <div id ="form_header">
      <form action="option_delete.php"  method="post" id="option_delete"  name="option_delete">
        <ul id="form_box"> 
          <li>   <!--    Place for showing error messages-->
            <span id="formerror" class="error"> <?php
//                      if (is_array($msg)) {
//                         foreach ($msg as $key => $value) {
//                           $x = $key + 1;
//                          echo 'Record ' . $x . ' : ' . $value .'<br />'  ;
//                        }
//                      } else {
//                        echo $msg;
//                      }
echo $msg;
?> </span>
            <!--    End of place for showing error messages-->
          </li> <li>

            <ul id="form_box_line0"> 
              <div class="three_column">
                <li class="control"> <span class="heading">Option Line </span>
                  <ul class="showhide">
                    <li> <label>Selected Option Type Id : </label>
                      <input type="text" required readonly name="option_id_l" 
                             value="<?php echo htmlentities($option_line->option_id_l); ?>" maxlength="50" 
                             id ="option_id_l" placeholder="Value defaults from header">
                    </li>
                    <li> <label>Option Line Id : </label>
                      <input type="text" required readonly name="option_line_id"  class ="option_line_id"
                             value="<?php echo htmlentities($option_line->option_line_id); ?>" maxlength="50" 
                             id ="option_line_id" placeholder="Sys generated no">
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
          </li>
      </form> 
    </div>

  </div>
</div>
<!--   end of structure-->

<?php include_template('footer.inc') ?>