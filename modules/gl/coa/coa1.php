<?php include_once("coa.inc"); ?>
<?php
$structures = coa::coa_structures();
$coa = new coa;
$coa->coa_id = "";
$coa->coa_structure = "";
$coa->name = "";
$coa->description = "";
$coa->balancing = "";
$coa->cost_center = "";
$coa->natural_account = "";
$coa->inter_company = "";
$coa->segment1 = "";
$coa->segment2 = "";
$coa->segment3 = "";
$coa->segment4 = "";
$coa->field1 = "";
$coa->field2 = "";
$coa->field3 = "";
$coa->field4 = "";
$coa->field5 = "";
$coa->field6 = "";
$coa->field7 = "";
$coa->field8 = "";
$coa->coa_sequence = "";
$coa->ef_id = "";
$coa->status = "";
$coa->rev_enabled = "";
$coa->rev_number = "";
$coa->created_by = "";
$coa->creation_date = "";
$coa->last_update_by = "";
$coa->last_update_date = "";
?>

<?php
if (!empty($_GET["coa_id"])) {
  $coa_id = $_GET["coa_id"];
  $coa = coa::find_by_id($coa_id);

//field values fetched from database
  $field_array = $coa->coa_sequence;
  $field = explode("-", $field_array);

//field values after header is saved but field sequence is not saved
//  Convert object to an array & then filtered out null values from array
  $coa_all_fields_object = coa::find_coa_fields_by_id($coa_id);
  $coa_all_fields_array = (array) $coa_all_fields_object;
  $coa_fields = array_filter($coa_all_fields_array);
}
?>

<?php
$msg = array();

if (!empty($_POST['submit_header'])) {
  $coa = new coa();
  if (empty($_POST['coa_id'])) {
    $coa->coa_id = null;
  } else {
    $coa->coa_id = trim(mysql_prep($_POST['coa_id']));
  }

  $coa->structure = trim(mysql_prep($_POST['coa_structure']));
  $coa->name = trim(mysql_prep($_POST['name']));
  $coa->description = trim(mysql_prep($_POST['description']));
  $coa->balancing = trim(mysql_prep($_POST['balancing']));
  $coa->cost_center = trim(mysql_prep($_POST['cost_center']));
  $coa->natural_account = trim(mysql_prep($_POST['natural_account']));
  $coa->inter_company = trim(mysql_prep($_POST['inter_company']));
  $coa->segment1 = trim(mysql_prep($_POST['segment1']));
  $coa->segment2 = trim(mysql_prep($_POST['segment2']));
  $coa->segment3 = trim(mysql_prep($_POST['segment3']));
  $coa->segment4 = trim(mysql_prep($_POST['segment4']));
  $field_array = array(trim(mysql_prep($_POST['field0'])),
      trim(mysql_prep($_POST['field1'])),
      trim(mysql_prep($_POST['field2'])),
      trim(mysql_prep($_POST['field3'])),
      trim(mysql_prep($_POST['field4'])),
      trim(mysql_prep($_POST['field5'])),
      trim(mysql_prep($_POST['field6'])),
      trim(mysql_prep($_POST['field7']))
  );
  $coa->coa_sequence = implode("-", $field_array);
  $coa->ef_id = trim(mysql_prep($_POST['ef_id']));
  $coa->status = trim(mysql_prep($_POST['status']));
  $coa->rev_enabled = trim(mysql_prep($_POST['rev_enabled']));
  $coa->rev_number = trim(mysql_prep($_POST['rev_number']));
  $time = time();
  $coa->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
  $coa->created_by = $_SESSION['user_name'];
  if (empty($coa->structure) || empty($coa->name) || empty($coa->description) || empty($coa->balancing) || empty($coa->cost_center) || empty($coa->natural_account)) {
    $msg = "Name, Type , Description or Segment value is empty";
  } else {
    $new_coa_entry = $coa->save();
    if ($new_coa_entry == 1) {
      $msg = 'Char of acccount is sucessfully saved';
    }//end of COA entry & msg
    else {
      $msg = "Record coundt be saved!!" . mysql_error() .
              ' Returned Value is : ' . $new_option_entry;
    }//end of coa insertion else
  }//end of coa check & new option creation
}//end of post submit header
?>

<div id="structure">
  <div id="coa">
    <div id="form_top">
      <ul class="form_top">
        <li> <a class="button" href="coa.php">Create New</a> </li> 
        <li><input type="submit" class="button" form="coa_form" name="submit_header" id="submit_header" Value="Save"></li>
        <li><input type="reset" class="button" name="reset" form="coa_form" Value="Reset All"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
      </ul>
      <h9> Char of accounts </h9>
    </div>
    <!--Start of the option header
   First check if $coa_id fetched from $_GET variable
   If the value exists then fetch the object from option_header table & show the object
   If the value is not set then make it zero & show a blank form-->
    <!--    START OF FORM HEADER-->
    <div id ="form_header"> 
      <form action="coa.php"  method="post" id="coa_form"  name="coa_form"> 
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
          <li class="ncontrol"><span class="heading">COA Header </span> 
            <div id="tabs">
              <ul>
                <li><a href="#tabs-1">Basic Info</a></li>
                <li><a href="#tabs-2">Segment Details</a></li>
              </ul>
              <div id="tabs-1">
                <div class="three_column"> 
                  <ul> 
                    <li> 
                      <label><a href="find_coa.php" class="popup"> 
                          <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a> 
                        COA Id : </label> 
                      <input type="text" readonly name="coa_id" value="<?php echo htmlentities($coa->coa_id); ?>"                          maxlength="50" id="coa_id" placeholder="System generated number"> 
                      <a name="show" href="coa.php?coa_id=" class="show">
                        <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
                    </li> 
                    <li><label>COA Structure : </label> 
                      <select name="coa_structure" id="coa_structure"  class="coa_structure"> 
                        <option value="" ></option> 
                        <?php
                        foreach ($structures as $records) {
                          echo '<option value="' . $records->option_id . '"';
                          echo $records->option_id == $coa->structure ? ' selected' : ' ';
                          echo '>' . $records->option_type . '</option>';
                        }
                        ?> 
                      </select> 
                    </li> 
                    <li><label>Name : </label> 
                      <input type="text" name="name" value="<?php echo htmlentities($coa->name); ?>" 
                             maxlength="50"  id="name"> 
                    </li> 
                    <li><label>Description : </label> 
                      <input type="text" name="description" value="<?php echo htmlentities($coa->description); ?>
                             " maxlength="50" id="description"> 
                    </li> 
                    <li><label>Extra Field : </label> 
                      <input type="text" name="ef_id" value="<?php echo htmlentities($coa->ef_id);
                        ?>" maxlength="50"  id="ef_id"> 
                    </li> 
                    <li><label>Status : </label>
                      <Select name="status" id="status" >
                        <option value="" ></option>
                        <option value="enabled" 
                                <?php echo $coa->status == 'enabled' ? 'selected' : ''; ?> >Enabled</option>
                        <option value="disabled" 
                                <?php echo $coa->status == 'disabled' ? 'selected' : ''; ?> >Disabled</option>                                   
                      </select>
                    </li>
                    <li><label>Revision : </label>
                      <Select name="rev_enabled" id="rev_enabled"> 
                        <option value="" ></option>   
                        <option value="enabled" 
                                <?php echo $coa->rev_enabled == 'enabled' ? 'selected' : ''; ?> >Enabled</option>
                        <option value="disabled" 
                                <?php echo $coa->rev_enabled == 'disabled' ? 'selected' : ''; ?>>Disabled</option>                                   
                      </select>
                    </li>
                    <li><label>Revision No: </label> 
                      <input type="text"  name="rev_number" value="<?php echo htmlentities($coa->rev_number);
                                ?>" maxlength="50" id="rev_number"> 
                    </li>
                  </ul> 
                </div> 
                <!--end of tab1 div three_column-->
              </div> 
              <!--              end of tab1-->

              <div id="tabs-2">
                <div class="three_column"> 
                  <ul>
                    <li><label>Balancing Segment : </label> 
                      <select name="balancing" id="balancing"  class="balancing" required> 
                        <?php
                        if (empty($coa->balancing)) {
                          echo '<option value=" " disabled selected>First select structure</option> ';
                        } else {
                          echo '<option value="' . htmlentities($coa->balancing) . '" >' .
                          htmlentities($coa->balancing) . '</option>';
                        }
                        ?> 
                      </select>
                    </li> 
                    <li><label>Cost Center : </label> 
                      <select name="cost_center" id="cost_center"  class="cost_center" required> 
                        <?php
                        if (empty($coa->cost_center)) {
                          echo '<option value=" " disabled selected>First select structure</option> ';
                        } else {
                          echo '<option value="' . htmlentities($coa->cost_center) . '" >' .
                          htmlentities($coa->cost_center) . '</option>';
                        }
                        ?> 
                      </select>
                    </li> 
                    <li><label>Account : </label> 
                      <select name="natural_account" id="natural_account"  class="natural_account" required> 
                        <?php
                        if (empty($coa->natural_account)) {
                          echo '<option value=" " disabled selected>First select structure</option> ';
                        } else {
                          echo '<option value="' . htmlentities($coa->natural_account) . '" >' .
                          htmlentities($coa->natural_account) . '</option>';
                        }
                        ?> 
                      </select>
                    </li> 
                    <li><label>Inter Company : </label> 
                      <select name="inter_company" id="inter_company"  class="inter_company" required> 
                        <?php
                        if (empty($coa->inter_company)) {
                          echo '<option value=" " disabled selected>First select structure</option> ';
                        } else {
                          echo '<option value="' . htmlentities($coa->inter_company) . '" >' .
                          htmlentities($coa->inter_company) . '</option>';
                        }
                        ?> 
                      </select>
                    </li> 
                    <li><label>Segment1 : </label> 
                      <select name="segment1" id="segment1"  class="segment1" > 
                        <?php
                        if (empty($coa->segment1)) {
                          echo '<option value="NU" selected> Not Used </option> ';
                        } else {
                          echo '<option value="' . htmlentities($coa->segment1) . '" >' .
                          htmlentities($coa->segment1) . '</option>';
                        }
                        ?> 
                      </select>
                    </li> 
                    <li><label>Segment2 : </label> 
                      <select name="segment2" id="segment2"  class="segment2" required> 
                        <?php
                        if (empty($coa->segment2)) {
                          echo '<option value="NU" selected> Not Used </option> ';
                        } else {
                          echo '<option value="' . htmlentities($coa->segment2) . '" >' .
                          htmlentities($coa->segment2) . '</option>';
                        }
                        ?> 
                      </select>
                    </li> 
                    <li><label>Segment3 : </label> 
                      <select name="segment3" id="segment3"  class="segment3" required> 
                        <?php
                        if (empty($coa->segment3)) {
                          echo '<option value="NU" selected> Not Used </option> ';
                        } else {
                          echo '<option value="' . htmlentities($coa->segment3) . '" >' .
                          htmlentities($coa->segment3) . '</option>';
                        }
                        ?> 
                      </select>
                    </li> 
                    <li><label>Segment4 : </label> 
                      <select name="segment4" id="segment4"  class="segment4" required> 
                        <?php
                        if (empty($coa->segment4)) {
                          echo '<option value="NU" selected> Not Used </option> ';
                        } else {
                          echo '<option value="' . htmlentities($coa->segment4) . '" >' .
                          htmlentities($coa->segment4) . '</option>';
                        }
                        ?> 
                      </select>
                    </li> 
                  </ul>

                </div> 
                <!--                end of tab2 div three_column-->
              </div>
              <!--end of tab2-->

            </div> 
            <!--//end of tab-->
            <div class="three_column"><span class="heading">COA Sequence </span> 
              <ul>
                <?php
                if (!empty($_GET["coa_id"])) {
                  for ($i = 0; $i < 8; $i++) {
                    echo '<li><label>Field ' . $i . ' </label><select name="field' . $i . '" class="field' . $i . '" id="field' . $i . '">';
                    if (empty($field[0])) {
                      foreach ($coa_fields as $key => $values) {
                        echo '<option value="' . htmlentities($values) . '" >' .
                        htmlentities($values) . '</option>';
                      }
                    } else {
                      echo '<option value="' . htmlentities($field[$i]) . '" >' .
                      htmlentities($field[$i]) . '</option>';
                    }

                    echo '<option value=" "></option></select>';
                  }
                } else {
                  echo '<span class="message"> First save or query a chart of account to create it\'s sequence </span>';
                }
                ?>

              </ul>
            </div>
          </li> 
        </ul> 
      </form> 
    </div>
    <!--END OF FORM HEADER-->
    <!--Start of the option line
    First check if $coa_id_l fetched from $_GET variable
    If the value exists then fetch the object from database & show the object
    If the value is not set then make it zero & show a blank form-->
  </div>
</div>

<!--   end of structure-->
<?php include_template('footer.inc') ?>