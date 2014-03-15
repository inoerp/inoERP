<?php $pageTitle = " UOM - Create & Update all UOMs "; ?>
<?php include_once("uom.inc"); ?>

<?php
$uom = new uom;
$field_array = uom::$field_array;
foreach ($field_array as $key => $value) {
  $uom->$value = "";
}
$msg = "";
?>


<?php
if (!empty($_GET["uom_id"])) {
  $uom_id = $_GET["uom_id"];
  $uom = uom::find_by_id($uom_id);
}
?>

<?php
$msg = array();
if (!empty($_POST['submit_uom'])) {
  $uom = new uom;
  if (empty($_POST['uom_id'])) {
    $uom->uom_id = null;
  } else {
    $uom->uom_id = trim(mysql_prep($_POST['uom_id']));
  }

  foreach ($field_array as $key => $value) {
    if (isset($_POST[$value])) {
      $uom->$value = trim(mysql_prep($_POST[$value]));
    } else {
      $uom->$value = "";
    }
  }
//  $uom->class = trim(mysql_prep($_POST['uom_class']));
//  echo '<br/> uom_class is : '. trim(mysql_prep($_POST['uom_class']));
  if (isset($_POST['primary'])) {
    $uom->$value = 1;
  } else {
    $uom->$value = 0;
  }

  $time = time();
  $uom->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
  $uom->created_by = $_SESSION['user_name'];
  $uom->last_update_date = $uom->creation_date;
  $uom->last_update_by = $uom->created_by;

//for new uom creation the uom id should be null 

  if (empty($uom->uom) || empty($uom->class) || empty($uom->description) || empty($uom->primary_uom)) {
    $newMsg = "UOM, Class or Description is Blank";
    array_push($msg, $newMsg);
  } else {
    $new_uom_entry = $uom->save();
    if ($new_uom_entry == 1) {
      $newMsg = 'UOM is sucessfully saved';
      array_push($msg, $newMsg);
    }//end of uom entry & msg
    else {
      $newMsg = "Record coundt be saved!!" . mysql_error() .
              ' Returned Value is : ' . $new_uom_entry;
      array_push($msg, $newMsg);
    }//end of uom insertion else
  }//end of uom check & new uom creation
  //reset all accounts to accounts from id
}//end of post submit header
?>

<div id="structure">
  <div id="uom">
    <div id="form_top">
      <ul class="form_top">
        <li><input type="button" class="button refresh" value="Refresh" name="refresh"/> </li>
        <li> <a class="button" href="uom.php">New Object</a> </li> 
        <li><input type="submit" form="uom_header" name="submit_uom" id="submit_uom" class="button" Value="Save"></li>
        <li> <input type="button" class="button remove_row" id="remove_row" Value="Remove"></li>
        <li> <input type="submit" class="button delete" form="coa_combination_form" name="delete_row" id="delete_row" value="Delete"></li>
        <li><input type="reset" class="button" form="uom_header" name="reset" Value="Reset All"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
      </ul>
    </div>
    <!--Start of the uom header
   First check if $inventory_id_l fetched from $_GET variable
   If the value exists then fetch the object from uom_header table & show the object
   If the value is not set then make it zero & show a blank form-->

    <!--    START OF FORM HEADER-->
    <div id ="form_header"><div id="scrollElement">
      <form action="uom.php"  method="post" id="uom_header"  name="uom_header">
        <ul id="form_box"> 
          <li>   <!--    Place for showing error messages-->
<?php
if (!empty($msg)) {
  echo '<span class="error">';
  if (is_array($msg)) {
    foreach ($msg as $key => $value) {
      $x = $key + 1;
      echo 'Message ' . $x . ' : ' . $value . '<br />';
    }
  } else {
    echo $msg;
  }
}
echo '</span>';
?> 
            <!--    End of place for showing error messages-->
          </li>
          <li>
            <ul>
              <li class="ncontrol"><span class="heading">Unit of measures </span> 
                <div>
                  <table class="form_table">
                    <thead> 
                      <tr>
                        <th>Action</th>
                        <th>UOM Id</th>
                        <th>UOM</th>
                        <th>Class</th>
                        <th>Description</th>
                        <th>Primary</th>
                        <th>Primary UOM</th>
                        <th>Operator</th>
                        <th>Primary Relation</th>
                        <th>EF Id</th>
                        <th>Status</th>
                        <th>Rev Enabled</th>
                        <th>Rev#</th>
                      </tr>
                    </thead>
                    <tbody id="uom_values">
                      <tr>
                        <td>    
                          <ul class="inline_action">
                            <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                            <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                            <li><input type="checkbox" name="uom_id_cb" value="<?php echo htmlentities($uom->uom_id); ?>"></li>           
                          </ul>
                        </td>
                        <td>
                          <input type="text" readonly name="uom_id" 
                                 value="<?php echo htmlentities($uom->uom_id); ?>" size="10"                           
                                 maxlength="50" class="uom_id" placeholder="Sys generated number"> 
                        </td>
                        <td>    
                          <input type="text" name="uom" value="<?php echo htmlentities($uom->uom); ?>" 
                                 size="10" maxlength="10"  id="uom"> 
                        </td>
                        <td>    
                         <select name="class" id="class" class="class"> 
                        <option value="" ></option> 
                        <?php
                        $class = uom::uom_class();
                        foreach ($class as $records) {
                          echo '<option value="' . $records->option_line_id . '"';
                          echo $records->option_line_id == $uom->class ? ' selected' : ' ';
                          echo '>' . $records->option_line_code . '</option>';
                        }
                        ?> 
                      </select> 
                        </td>
                        <td>
                          <input type="text" name="description" value="<?php echo htmlentities($uom->description); ?>" 
                                 size="15" maxlength="150"  id="description"> 
                        </td>
                        <td>
                          <input type="checkbox" name="primary" 
                                 value="<?php echo (empty($uom->primary)) ? "1" : ""; ?>"  id="primary"
                            <?php
                            if ($uom->rev_enabled == 1) {
                              echo " checked";
                            } else {
                              echo "";
                            }
                            ?> > 
                        </td>
                        <td>
                          <input type="text" name="primary_uom" value="<?php echo htmlentities($uom->primary_uom); ?>" 
                                 size="10" maxlength="150"  id="primary_uom"> 
                        </td>
                        <td>  
                          <input type="image"  src="<?php echo HOME_URL; ?>themes/images/multiply.png" alt="multiply"/> 
                        </td>
                        <td>
                          <input type="text" name="primary_relation" value="<?php echo htmlentities($uom->primary_relation); ?>" 
                                 size="10" maxlength="150"  id="primary_relation"> 
                        </td>
                        <td>
                          <input type="text" name="ef_id" value="<?php echo htmlentities($uom->ef_id); ?>" 
                                 size="5" maxlength="10"  id="ef_id"> 
                        </td>
                        <td>                      
                          <Select name="status" id="status" >
                            <option value="" ></option>
                            <option value="enabled" 
                            <?php echo $uom->status == 'enabled' ? 'selected' : ''; ?> >Enabled</option>
                            <option value="disabled" 
                            <?php echo $uom->status == 'disabled' ? 'selected' : ''; ?> >Disabled</option>                                   
                          </select>

                        </td>
                        <td>
                          <input type="checkbox" name="rev_enabled" 
                                 value="<?php echo (empty($uom->rev_enabled)) ? "1" : ""; ?>"  id="rev_enabled"
                            <?php
                            if ($uom->rev_enabled == 1) {
                              echo " checked";
                            } else {
                              echo "";
                            }
                            ?> >  
                        </td> 
                        <td>
                          <input type="text" name="rev_number" value="<?php echo htmlentities($uom->rev_number); ?>" 
                                 maxlength="50" size="5"  id="rev_number" class="rev_number"> 
                        </td> 
                      </tr>
                    </tbody>
                    <!--                  Showing a blank form for new entry-->

                  </table>
                </div>

              </li>
            </ul>
          </li>
        </ul>
      </form> 
    </div>
    </div>
    <!--END OF FORM HEADER-->  
  </div>
</div>
<!--   end of structure-->

<?php include_template('footer.inc') ?>
