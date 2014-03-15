<?php include_once("coa.inc"); ?>
<?php
$coa_account_types = coa_segment_values::coa_account_types();
$coa_segment_values = new coa_segment_values;
$coa_segment_values->coa_segment_values_id = "";
$coa_segment_values->coa_id = "";
$coa_segment_values->account_type = "";
$coa_segment_values->name = "";
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

<script>
  function getCoaSegmentValuesId(coa_segment_valuesId)
  {
    document.getElementById("coa_segment_values_id").value = coa_segment_valuesId;
    $('#form_box a.show').prop('href', 'coa_segment_values.php?coa_segment_values_id=' + coa_segment_valuesId);
  }

</script>
<?php
if (!empty($_GET["coa_segment_values_id"])) {
  $coa_segment_values_id = $_GET["coa_segment_values_id"];
  $coa_segment_values = coa_segment_values::find_by_id($coa_segment_values_id);

////field values fetched from database
//  $field_array = $coa_segment_values->coa_segment_values_sequence;
//  $field = explode("-", $field_array);
//
////field values after header is saved but field sequence is not saved
////  Convert object to an array & then filtered out null values from array
//  $coa_segment_values_all_fields_object = coa_segment_values::find_coa_segment_values_fields_by_id($coa_segment_values_id);
//  $coa_segment_values_all_fields_array = (array) $coa_segment_values_all_fields_object;
//  $coa_segment_values_fields = array_filter($coa_segment_values_all_fields_array);
}
?>

<?php
$msg = array();

if (!empty($_POST['submit_header'])) {
  $coa_segment_values = new coa_segment_values();
  if (empty($_POST['coa_segment_values_id'])) {
    $coa_segment_values->coa_segment_values_id = null;
  } else {
    $coa_segment_values->coa_segment_values_id = trim(mysql_prep($_POST['coa_segment_values_id']));
  }
  $coa_segment_values->coa_id = trim(mysql_prep($_POST['$coa_id']));
  $coa_segment_values->account_type = trim(mysql_prep($_POST['$account_type']));
  $coa_segment_values->segment_code = trim(mysql_prep($_POST['$segment_code']));
  $coa_segment_values->description = trim(mysql_prep($_POST['description']));
  $coa_segment_values->ef_id = trim(mysql_prep($_POST['ef_id']));
  $coa_segment_values->status = trim(mysql_prep($_POST['status']));
  $coa_segment_values->rev_enabled = trim(mysql_prep($_POST['rev_enabled']));
  $coa_segment_values->rev_number = trim(mysql_prep($_POST['rev_number']));
  $time = time();
  $coa_segment_values->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
  $coa_segment_values->created_by = $_SESSION['user_name'];
  if (empty($coa_segment_values->structure) || empty($coa_segment_values->name) || empty($coa_segment_values->description) || empty($coa_segment_values->balancing) || empty($coa_segment_values->cost_center) || empty($coa_segment_values->natural_account)) {
    $msg = "Segment Code, Type or Description 
      value is empty";
  } else {
    $new_coa_segment_values_entry = $coa_segment_values->save();
    if ($new_coa_segment_values_entry == 1) {
      $msg = 'Char of acccount is sucessfully saved';
    }//end of COA entry & msg
    else {
      $msg = "Record coundt be saved!!" . mysql_error() .
              ' Returned Value is : ' . $new_option_entry;
    }//end of coa_segment_values insertion else
  }//end of coa_segment_values check & new option creation
}//end of post submit header
?>

<div id="structure">
  <div id="coa_segment_values">
    <div id="form_top">
      <ul class="form_top">
        <li><h9> COA Segment Values </h9></li>
        <li> <a class="button" href="coa_segment_values.php">Create New</a> </li> 
        <li><input type="submit" class="button" form="coa_segment_values_form" name="submit_header" id="submit_header" Value="Save"></li>
        <li><input type="reset" class="button" name="reset" form="coa_segment_values_form" Value="Reset All"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
      </ul>
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
                  <label><a href="find_coa_segment_values.php" class="popup"> 
                      <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a> 
                    COA Id : </label> 
                  <input type="text" readonly name="coa_segment_values_id" 
                         value="<?php echo htmlentities($coa_segment_values->coa_segment_values_id); ?>" size="15"                           maxlength="50" id="coa_segment_values_id" placeholder="System generated number"> 
                  <a name="show" href="coa_segment_values.php?coa_segment_values_id=" class="show">
                    <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
                </li> 
                <li><label>COA Name : </label> 
                  <input type="text" name="coa_name" value="<?php echo htmlentities($coa_segment_values->coa_name); ?>" 
                         maxlength="50" size="15" id="coa_name"> 
                </li> 
                <li><label>Account Segment : </label> 
                  <select name="account_type" id="account_type"  class="account_type"> 
                    <option value="" >TEST 001</option> 

                  </select> 
                </li> 
              </ul>
              <!--end of form header-->
            </div> 
            <!--end of tab div three_column-->
          </li>

          <!--end of Li header-->
          <li class="ncontrol"><span class="heading">COA Segment Value Line </span> 
            <div id="segment_code_values">
              <ul id="segment_code_values0">
                <div class="eight_column"> 
                  <li><label>Segment Code : </label> 
                    <input type="text" name="segment_code" value="<?php echo htmlentities($coa_segment_values->segment_code); ?>" 
                           size="15" maxlength="50"  id="segment_code"> 
                  </li> 
                  <li><label>Description  : </label> 
                    <input type="text" name="description" value="<?php echo htmlentities($coa_segment_values->description); ?>" 
                           size="15" maxlength="150"  id="description"> 
                  </li> 
                  <li><label>Account Type : </label> 
                    <select name="account_type" id="account_type"  class="account_type"> 
                      <option value="" ></option> 
                      <?php
                      foreach ($coa_account_types as $records) {
                        echo '<option value="' . $records->option_line_code . '">' . $records->description_l . '</option>';
                      }
                      ?> 
                    </select> 
                  </li> 
                  <li><label>Status : </label> 
                    <input type="text" name="status" value="<?php echo htmlentities($coa_segment_values->status); ?>" 
                           maxlength="50" size="15" id="status"> 
                  </li> 
                  <li><label>Start date : </label> 
                    <input type="date" name="effective_start_date" value="<?php echo htmlentities($coa_segment_values->effective_start_date); ?>" 
                           maxlength="50"  size="15" id="effective_start_date" class="date"> 
                  </li> 
                  <li><label>End date : </label> 
                    <input type="date" name="effective_end_date" value="<?php echo htmlentities($coa_segment_values->effective_end_date); ?>" 
                           maxlength="50" size="15"  id="effective_end_date" class="date"> 
                  </li>                   
                </div> 
              </ul>



            </div>
            <input type="button" id="add_object" class="button" value="Add a new Line" name="add_object"/>
          </li>
          <!--end of Li Line-->
        </ul>
      </form> 
    </div>
  </div>
</div>

<!--   end of structure-->
<?php include_template('footer.inc') ?>