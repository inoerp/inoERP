<?php
include_once('org.inc');

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
<?php 
global $db;
$query = "SHOW COLUMNS FROM enterprise ";

//$query="Select * from information_schema.tables where table_name='enterprise'";
$result = $db->query($query);
while($rows = $db->fetch_array($result)){
  echo '<pre>';
  print_r($rows);
  echo '<pre>';
}

   
?>


<?php
$org_types = org_header::org_types();
echo '<h2>Individual Array </h2>';
for ($i = 0; $i <= 3; $i++) {
  echo '<br>' . $org_types[$i]->option_line_code;
}//foreach($org_types as $key=>$values) {//    foreach ($key as $key1=>$value1) {//        echo $key1['option_line_code'];
//    }//}
    ?> 
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
                            <img src="<?php echo HOME_URL;
                    ?>themes/images/serach.png"/></a> 
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
                          ?>" maxlength="50"                          id="name"> 
                      </li> 
                      <li><label>Enterprise : </label> 
                        <input type="text" required name="enterprise_id" value="<?php echo htmlentities($org->enterprise_id);
                          ?>"                          maxlength="50" id ="enterprise_id" placeholder="No special characters"> 
                      </li> 
                      <li><label>Legal Org : </label> 
                        <input type="text" required name="legal_id" value="<?php echo htmlentities($org->legal_id);
                          ?>"                          maxlength="50" id ="legal_id" placeholder="No special characters"> 
                      </li> 
                      <li><label>Business Org : </label> 
                        <input type="text" required name="business_id" value="<?php echo htmlentities($org->business_id);
                          ?>"                          maxlength="50" id ="business_id" placeholder="No special characters"> 
                      </li> 
                      <li><label>Description : </label> 
                        <input type="text" name="description" value="<?php echo htmlentities($org->description);
                          ?>" maxlength="50"                          id="description"> 
                      </li> 
                      <li><label>Extra Field : </label> 
                        <input type="text" name="ef_id" value="<?php echo htmlentities($org->ef_id);
                          ?>" maxlength="50"                          id="ef_id"> 
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

<!--   end of structure-->

<?php include_template('footer.inc') ?>