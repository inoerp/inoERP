<?php
require_once('address.inc');
$address = new address();
$address->address_id = "";
$address->type = "";
$address->name = "";
$address->description = "";
$address->phone = "";
$address->email = "";
$address->website = "";
$address->value = "";
$address->country = "";
$address->postal_code = "";
$address->ef_id = "";
$address->status = "";
$address->rev_enabled = "";
$address->rev_number = "";
$address->created_by = "";
$address->creation_date = "";
$address->last_update_by = "";
$address->last_update_date = "";
$msg = "";
?>

<script>
  //Get adddess from child to parent window
  function getAddress(findAddress)
  {
    document.getElementById("address_id").value = findAddress;
    $('#form_box a.show').prop('href', 'address.php?address_id=' + findAddress);
  }
  
</script>

<?php
if (!empty($_GET["address_id"])) {
  $address_id = $_GET["address_id"];
  $address = address::find_by_id($address_id);
}
if ((!empty($_POST["address_id"])) && (empty($_POST['submit_header']))) {
  $address_id = $_POST["address_id"];
  $address = address::find_by_id($address_id);
}
?>

<?php
if (!empty($_POST['submit_header'])) {
  $address = new address();
  $address->address_id = trim(mysql_prep($_POST['address_id']));
  $address->type = trim(mysql_prep($_POST['type']));
  $address->name = trim(mysql_prep($_POST['name']));
  $address->description = trim(mysql_prep($_POST['description']));
  $address->phone = trim(mysql_prep($_POST['phone']));
  $address->email = trim(mysql_prep($_POST['email']));
  $address->website = trim(mysql_prep($_POST['website']));
  $address->value = trim($_POST['value']);
  $address->country = trim(mysql_prep($_POST['country']));
  $address->postal_code = trim(mysql_prep($_POST['postal_code']));
    $address->ef_id = trim(mysql_prep($_POST['ef_id']));
  $address->status = trim(mysql_prep($_POST['status']));
  $address->rev_enabled = trim(mysql_prep($_POST['rev_enabled']));
  $address->rev_number = trim(mysql_prep($_POST['rev_number']));
  $address->time = time();
  $address->creation_time = strftime("%d-%m-%y %H:%M:%S", $address->time);
  $address->created_by = $_SESSION['user_name'];


  if (empty($address->name) || empty($address->value) || empty($address->country) || empty($address->type)) {
    $msg = "Name, Value, Description or type is empty";
  } else {
    $new_address_entry = $address->save();
    if ($new_address_entry) {
      $msg = "Address is sucessfully saved";
    }//end of address entry & msg
    else {
      $msg = "Address coundt be saved!!" . mysql_error();
    }//end of address insertion else
  }//end of address check & new address creation
}//end of post


?>

<?php
$msg = "";
if (!empty($_POST['delete'])) {
  $address_id = trim(mysql_prep($_POST['address_id']));
  if (empty($address_id)) {
    $msg = "No address is selected";
  } else {
    $address = new address();
    $address_delete = $address->address_delete($address_id);
    if ($address_delete AND (mysql_affected_rows() == 1)) {
      $msg = "Path is sucessfully deleted <br/>";
      redirect_to('addresss.php');
      break;
    }//end of address entry & msg
    else {
      $msg = "Path couldn't deleted!!";
      $msg .= '<br/>' . mysql_error();
    }//end of address delete else
  }//end of address check & deletion
}//end of post
?>

<div id="structure">
  <div id="address">
    <div id="form_top">
      <ul class="form_top">
        <li> <a class="button" href="address.php">Create New</a> </li> 
        <li><input type="submit" class="button" form="address_header" name="submit_header" id="submit_header" Value="Save"></li>
<!--        <li><input type="submit" class="button" form="address_header" name="submit_line"  id="submit_line" Value="Save Line"></li>-->
        <li><input type="reset" class="button" name="reset" form="address_header" Value="Reset All"></li>
        <li> <input type="submit" class="button" form="address_header" name="delete" id="delete"
                    onclick="return confirm('Are you sure?');"     value="Delete"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
      </ul>
      <h9>Address! </h9>
    </div>
    <div id ="form_header">
      <form action="address.php" method="post" size="30" id="address_header"  >
        <ul id="form_box"> 
          <li>
            <!--    Place for showing error messages-->
           <?php if(!empty($msg)) 
           {
             echo '<span class="error">' . $msg . '</span>';
           }?>
            <!--    End of place for showing error messages-->
          </li>
          <li class="ncontrol"><span class="heading">Address </span> 
            <div class="three_column"> 
              <ul> 
                <li><label><a href="find_address.php" class="popup"> 
                      <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>
                    Address Id :</label> 
                  <input type="text" readonly name="address_id" id="address_id" maxlength="30" size="20"
                         placeholder="System Generated No" value="<?php echo htmlentities($address->address_id); ?>">
                  <a name="show" href="address.php?address_id=" class="show">
                    <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
                </li>
                <li><label>Type :</label> 
                  <select name="type" id="type" required> 
                    <option value="" ></option> 
                    <?php
                    $types = address::address_types();
                    foreach ($types as $record) {
                      echo '<option value="' . $record->option_line_code . '" ';
                      echo $record->option_line_code == $address->type ? 'selected' : 'none ';
                      echo '>' . $record->option_line_code . '</option>';
                    }
                    ?> 
                  </select> 
                </li>
                <li><label>Name :</label> 
                  <input type="text" required name="name" id="name" maxlength="40" size="20"
                         placeholder="Enter a valid address name" value="<?php echo htmlentities($address->name); ?>">
                </li>
                <li><label>Description  : </label> 
                  <input type="text" name="description" maxlength="100" id="description" size="30" 
                         placeholder="Enter address description. Limit to 100 characters" value="<?php echo htmlentities($address->description); ?>">
                </li>
                <li><label>Extra Field : </label> 
                  <input type="text" name="ef_id" value="<?php echo htmlentities($address->ef_id); ?>" 
                         maxlength="50"  size="20" id="ef_id"> 
                </li> 
                <li><label>Status : </label>
                  <Select name="status" id="status" >
                    <option value="" ></option>
                    <option value="enabled" 
                            <?php echo $address->status == 'enabled' ? 'selected' : ''; ?> >Enabled</option>
                    <option value="disabled" 
                            <?php echo $address->status == 'disabled' ? 'selected' : ''; ?> >Disabled</option>                                   
                  </select>
                </li>
                <li><label>Revision : </label>
                  <Select name="rev_enabled" id="rev_enabled" > 
                    <option value="" ></option>   
                    <option value="enabled" 
                            <?php echo $address->rev_enabled == 'enabled' ? 'selected' : ''; ?> >Enabled</option>
                    <option value="disabled" 
                            <?php echo $address->rev_enabled == 'disabled' ? 'selected' : ''; ?>>Disabled</option>                                   
                  </select>
                </li>
                <li><label>Revision No: </label> 
                  <input type="text"  name="rev_number" value="<?php echo htmlentities($address->rev_number);
                            ?>" maxlength="50" size="30" id="rev_number"> 
                </li> 
              </ul>
            </div>
            <div class="three_column"> 
              
              <ul class="address">
                <li><label>Phone  : </label> 
                  <input type="text"  name="phone" maxlength="25" id="phone" size="25" 
                         placeholder="Phone number" value="<?php echo htmlentities($address->phone); ?>">
                </li>
                <li><label>Email  : </label> 
                  <input type="text"  name="email" maxlength="50" id="postal_code" size="25" 
                         placeholder="Email address" value="<?php echo htmlentities($address->email); ?>">
                </li>
                <li><label>Web-site  : </label> 
                  <input type="text"  name="website" maxlength="50" id="country" size="25" 
                         placeholder="Official Website" value="<?php echo htmlentities($address->website); ?>">
                </li>
                <li><label>Country  : </label> 
                  <input type="text" required name="country" maxlength="50" id="country" size="25" 
                         placeholder="Country name" value="<?php echo htmlentities($address->country); ?>">
                </li>
                <li><label>Postal Code  : </label> 
                  <input type="text"  name="postal_code" maxlength="25" id="postal_code" size="25" 
                         placeholder="Postal/Zip code" value="<?php echo htmlentities($address->postal_code); ?>">
                </li>
                 <li><label>Address :</label>  
                  <textarea required name="value" id="value" cols="22" rows="3" placeholder="Enter address"> 
                    <?php echo trim(htmlentities($address->value)); ?>
                  </textarea>
                </li>
              </ul>
            </div>
          </li>
        </ul>

      </form> 
    </div>      
  </div>
</div>

<?php include_template('footer.inc') ?>