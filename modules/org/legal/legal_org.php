<?php include_once("legal_org.inc"); ?>
<?php
$legal_org = new legal_org();
$legal_org->legal_id = "";
$legal_org->org_id = "";
$legal_org->name = "";
$legal_org->description = "";
$legal_org->address_id = "";
$msg = "";
?>


<?php
if (!empty($_GET["legal_id"])) {
  $legal_id = $_GET["legal_id"];
  $legal_org = legal_org::find_by_id($legal_id);
  $org = org_header::find_by_legal_id($legal_id);
  $legal_org->org_id = $org->org_id;
  $legal_org->name = $org->name ;
  $legal_org->description = $org->description;
  $legal_org->address_id = $org->address_id ;
}
?>

<?php
if (!empty($_POST['submit_legal_org'])) {
//  echo '<pre>';
//  print_r($_POST);
//  echo '<pre>';
  
  $legal_org = new legal_org();
  if (empty($_POST['legal_id'])) {
    $legal_org->legal_id = null;
  } else {
    $legal_org->legal_id = trim(mysql_prep($_POST['legal_id']));
  }
  
  $legal_org->org_id = trim(mysql_prep($_POST['org_id']));
  $legal_org->name = trim(mysql_prep($_POST['org_name']));
  $legal_org->description = trim(mysql_prep($_POST['description']));
  $legal_org->address_id = trim(mysql_prep($_POST['address_id']));
  $legal_org->legal_org_type = trim(mysql_prep($_POST['legal_org_type']));
  $legal_org->registration_number = trim(mysql_prep($_POST['registration_number']));
  $legal_org->place_of_registration = trim(mysql_prep($_POST['place_of_registration']));
  $legal_org->country_of_registration = trim(mysql_prep($_POST['country_of_registration']));
  $legal_org->identification_number = trim(mysql_prep($_POST['identification_number']));
  $legal_org->ein_tin_tan = trim(mysql_prep($_POST['ein_tin_tan']));
  $legal_org->ledger_id = trim(mysql_prep($_POST['ledger_id']));
  $legal_org->balancing_segments = trim(mysql_prep($_POST['balancing_segments']));
  $time = time();
  $legal_org->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
  $legal_org->created_by = $_SESSION['user_name'];

  if (empty($legal_org->name) || empty($legal_org->legal_id)) {
    $msg = "Name or Legal Id is empty";
  } else {
    $new_legal_org_entry = $legal_org->update($legal_org->legal_id);
    if ($new_legal_org_entry == 1) {
      $msg = 'Enterprise is sucessfully saved';
    }//end of legal_org entry & msg
    else {
      $msg = "Record coundt be saved!!" . mysql_error() .
              ' Returned Value is : ' . $new_legal_org_entry;
    }//end of legal_org insertion else
  }//end of legal_org check & new legal_org creation
}//end of post submit header
?>

<div id="structure">
  <div id="legal_org">
    <div id="form_top">
      <ul class="form_top">
        <li><input type="button" class="button refresh" value="Refresh" name="refresh"/> </li>
        <li> <a class="button" href="legal_org.php">New Object</a> </li> 
        <li><input type="submit" form="legal_org_header" name="submit_legal_org" id="submit_legal_org" class="button" Value="Save"></li>
        <li> <input type="button" class="button remove_row" id="remove_row" Value="Remove"></li>
        <li> <input type="submit" class="button delete" form="coa_combination_form" name="delete_row" id="delete_row" value="Delete"></li>
        <li><input type="reset" class="button" form="legal_org_header" name="reset" Value="Reset All"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
      </ul>
    </div>
    <!--Start of the legal_org header
   First check if $legal_id_l fetched from $_GET variable
   If the value exists then fetch the object from legal_org_header table & show the object
   If the value is not set then make it zero & show a blank form-->

    <!--    START OF FORM HEADER-->
    <div id ="form_header">
      <form action="legal_org.php"  method="post" id="legal_org_header"  name="legal_org_header">
        <ul id="form_box"> 
          <li>   <!--    Place for showing error messages-->
             <?php
            if(!empty($msg)){
              echo '<span class="error">';
              if (is_array($msg)) {
                foreach ($msg as $key => $value) {
                  $x = $key + 1;
                  echo 'Record ' . $x . ' : ' . $value . '<br />';
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
                <li class="ncontrol"><span class="heading">Legal Org Header </span>
                  <div class="three_column"> 
                  <ul>
                    <li>
                      <label><a href="find_legal_org.php" class="popup">
                          <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>
                        Legal Org Id : </label>
                      <input type="text" readonly name="legal_id" value="<?php echo htmlentities($legal_org->legal_id); ?>" 
                             maxlength="50" id="legal_id" placeholder="System generated number">
                      <a name="show" href="legal_org.php?legal_id=" class="show">
                        <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
                    </li>
                    <li><label>Org Id : </label>
                      <input type="text" readonly name="org_id" value="<?php echo htmlentities($legal_org->org_id); ?>"  maxlength="50" >
                    </li>  
                    <li><label>Name : </label>
                      <input type="text" readonly name="org_name" value="<?php echo htmlentities($legal_org->name); ?>" 
                             maxlength="50" >
                    </li>               
                    <li><label>Description : </label>
                      <input type="text" readonly name="description" value="<?php echo htmlentities($legal_org->description); ?>" maxlength="50" >
                    </li>
                    <li><label>Address Id : </label>
                      <input type="text" readonly name="address_id" id="address_id" value="<?php echo htmlentities($legal_org->address_id); ?>" 
                             maxlength="50" >
                    </li>
                    </ul>
                    </div>
                </li>
                <li class="ncontrol"><span class="heading">Legal Org Line </span> 
                  <div id="tabs">
                    <ul>
                      <li><a href="#tabs-1">Basic Info</a></li>
                      <li><a href="#tabs-2">Ledger Details</a></li>
                    </ul>
                    <div id="tabs-1">
                      <div class="three_column"> 
                        <ul> 
                          <li><label>Type of Legal Org : </label> 
                            <input type="text" name="legal_org_type" value="<?php echo htmlentities($legal_org->legal_org_type); ?>
                                   " maxlength="50" id="legal_org_type"> 
                          </li> 
                          <li><label>Registration Number : </label> 
                            <input type="text" name="registration_number" value="<?php echo htmlentities($legal_org->registration_number); ?>
                                   " maxlength="50" id="registration_number"> 
                          </li>
                         <li><label>Place of Registration : </label> 
                            <input type="text" name="place_of_registration" value="<?php echo htmlentities($legal_org->place_of_registration); ?>
                                   " maxlength="50" id="place_of_registration"> 
                          </li> 
                          <li><label>Country of Registration : </label> 
                            <input type="text" name="country_of_registration" value="<?php echo htmlentities($legal_org->country_of_registration); ?>
                                   " maxlength="50" id="country_of_registration"> 
                          </li>
                          <li><label>Identification No : </label> 
                            <input type="text" name="identification_number" value="<?php echo htmlentities($legal_org->identification_number); ?>
                                   " maxlength="50" id="identification_number"> 
                          </li>
                          <li><label>EIN/TIN/TAN : </label> 
                            <input type="text" name="ein_tin_tan" value="<?php echo htmlentities($legal_org->ein_tin_tan); ?>
                                   " maxlength="50" id="ein_tin_tan"> 
                          </li> 
                          </ul> 
                      </div> 
                      <!--end of tab1 div three_column-->
                    </div> 
                    <!--              end of tab1-->

                    <div id="tabs-2">
                      <div class="three_column"> 
                        <ul>
                          <li> 
                            <label><a href="find_ledger.php" class="popup"> 
                                <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a> 
                              Ledger Id : </label> 
                            <input type="text" name="ledger_id" value="<?php echo htmlentities($legal_org->ledger_id); ?>"                          maxlength="50" id="legal_id" placeholder="System generated number"> 
                            <a name="show" href="legal_org.php?legal_id=" class="show">
                              <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
                          </li> 
                           <li><label>Calendar : </label> 
                            <input type="text" name="name" value="<?php echo htmlentities($legal_org->name); ?>" 
                                   maxlength="50"  id="name"> 
                          </li>
                           <li><label>Currency : </label> 
                            <input type="text" name="name" value="<?php echo htmlentities($legal_org->name); ?>" 
                                   maxlength="50"  id="name"> 
                          </li>
                          <li><label>COA Name : </label> 
                            <input type="text" name="name" value="<?php echo htmlentities($legal_org->name); ?>" 
                                   maxlength="50"  id="name"> 
                          </li> 
                           </li>
                          <li><label>Balancing Segments : </label> 
                            <input type="text" name="balancing_segments" value="<?php echo htmlentities($legal_org->balancing_segments); ?>" 
                                   maxlength="50"  id="balancing_segments"> 
                          </li> 

                        </ul>

                      </div> 
                      <!--                end of tab2 div three_column-->
                    </div>
                    <!--end of tab2-->

                  </div> 
                  <!--//end of tab-->
                </li> 
              </ul>
          </li>
        </ul>
      </form> 
    </div>

    <!--END OF FORM HEADER-->  
  </div>
</div>
<!--   end of structure-->

<?php include_template('footer.inc') ?>
