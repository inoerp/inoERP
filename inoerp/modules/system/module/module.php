<?php include_once("module.inc"); ?>
<?php
$module = new module();
$module->module_id = "";
$module->name = "";
$module->number = "";
$module->description = "";
$module->created_by = "";
$module->creation_date = "";
$module->last_update_by = "";
$module->last_update_date = "";
$msg = "";
?>

<!--<script src="module.js"></script>-->
<script>
  function parentWindow(findElement)
  {
    document.getElementById("module_id").value = findElement;
    $('#form_box a.show').prop('href', 'module.php?module_id=' + findElement);
  }
</script>


<?php
if (!empty($_GET["module_id"])) {
  $module_id = $_GET["module_id"];
  $module = module::find_by_id($module_id);
 }
?>

<?php
if (!empty($_POST['submit_module'])) {
  $module = new module();
  if (empty($_POST['module_id'])) {
    $module->module_id = null;
  } else {
    $module->module_id = trim(mysql_prep($_POST['module_id']));
  }
  $module->name = trim(mysql_prep($_POST['name']));
  $module->number = trim(mysql_prep($_POST['number']));
  $module->description = trim(mysql_prep($_POST['description']));
  $time = time();
  $module->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
  $module->created_by = $_SESSION['user_name'];

  if (empty($module->name) || empty($module->number) || empty($module->description)) {
    $msg = "Name, Number or Description is empty";
  } else {
    $new_module_entry = $module->save();
    if ($new_module_entry == 1) {
      $msg = 'Option is sucessfully saved';
    }//end of module entry & msg
    else {
      $msg = "Record coundt be saved!!" . mysql_error() .
              ' Returned Value is : ' . $new_module_entry;
    }//end of module insertion else
  }//end of module check & new module creation
}//end of post submit header
?>

<div id="structure">
  <div id="module">
    <div id="form_top">
      <ul class="form_top">
        <li> <a class="button" href="module.php">Create New</a> </li> 
         <li><input type="submit" form="module_header" name="submit_module" id="submit_module" class="button" Value="Save"></li>
        <li><input type="reset" class="button" form="module_header" name="reset" Value="Reset All"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
      </ul>
    </div>
    <!--Start of the module header
   First check if $module_id_l fetched from $_GET variable
   If the value exists then fetch the object from module_header table & show the object
   If the value is not set then make it zero & show a blank form-->

    <!--    START OF FORM HEADER-->
    <div id ="form_header">
      <form action="module.php"  method="post" id="module_header"  name="module_header">
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
            <!--    End of place for showing error messages-->
          </li>
          <h9>Module Page</h9>
          <li class="ncontrol"><span class="heading">Module </span>
            <div class="three_column">
              <ul>
                <li>
                  <label><a href="find_module.php" class="popup">
                      <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>
                    Module Id : </label>
                  <input type="text" readonly name="module_id" value="<?php echo htmlentities($module->module_id); ?>" 
                         maxlength="50" id="module_id" placeholder="System generated number">
                  <a name="show" href="module.php?module_id=" class="show">Show</a>
                </li>
                <li><label>Number : </label>
                  <input type="text" required name="number" value="<?php echo htmlentities($module->number); ?>" 
                         maxlength="50"  placeholder="Avoid any special characters">
                </li>
                 <li><label>Name : </label>
                  <input type="text" required name="name" value="<?php echo htmlentities($module->name); ?>" 
                         maxlength="50" placeholder="Avoid any special characters">
                </li>               
                <li><label>Description : </label>
               <input type="text" name="description" value="<?php echo htmlentities($module->description); ?>" maxlength="50" >
                </li>
               
              </ul>
            </div>
          </li>
        </ul>
      </form> 
    </div>

    <!--END OF FORM HEADER-->  
  </div>
</div>
<!--   end of structure-->

<?php include_template('footer.inc') ?>
