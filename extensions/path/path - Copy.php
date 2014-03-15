<?php include_once('../../include/basics/header.inc'); ?>
<script src="path.js"></script>

<?php
$path = new path();
$path->parent_id = "";
$path->name = "";
$path->value = "";
$path->primary="";
$path->description = "";
$path->module = "";
$msg = "";
?>

<script>
  function parentWindow(findElement)
  {
    document.getElementById("path_id").value = findElement;
    $('#form_box a.show').prop('href', 'org.php?org_id=' + findElement);
  }
</script>

<?php
if (!empty($_GET["path_id"])) {
  $path_id = $_GET["path_id"];
  $path = path::find_by_id($path_id);
}
?>

<?php
if (!empty($_POST['submit_header'])) {
  $path = new path();
  $path->path_id = trim(mysql_prep($_POST['path_id']));
  $path->name = trim(mysql_prep($_POST['name']));
  $path->parent_id = trim(mysql_prep($_POST['parent_id']));
  $path->value = trim(mysql_prep($_POST['value']));
  $path->description = trim(mysql_prep($_POST['description']));
  $path->module = trim(mysql_prep($_POST['module']));
  $path->primary = trim(mysql_prep($_POST['primary']));
  $path->time = time();
  $path->creation_time = strftime("%d-%m-%y %H:%M:%S", $path->time);
  $path->created_by = $_SESSION['user_name'];


  if (empty($path->name) || empty($path->value) || empty($path->description) || empty($path->module)) {
    $msg = "Name, Value, Description or module is empty";
  } else {
    $new_path_entry = $path->save();
    if ($new_path_entry) {
      $msg = "Path is sucessfully saved";
          }//end of path entry & msg
    else {
      $msg = "Path coundt be saved!!" . mysql_error();
    }//end of path insertion else
  }//end of path check & new path creation
  
  }//end of post

?>

<?php
if (!empty($_POST['delete'])) {

  $path_id = trim(mysql_prep($_POST['path_id']));



  if (empty($path_id)) {

    $msg = "No path is selected";
  } else {

    $path = new path();

    $path_delete = $path->path_delete($path_id);

    if ($path_delete AND (mysql_affected_rows() == 1)) {

      $msg = "Path is sucessfully deleted <br/>";

      redirect_to('paths.php');

      break;
    }//end of path entry & msg
    else {

      $msg = "Path couldn't deleted!!";

      $msg .= '<br/>' . mysql_error();
    }//end of path delete else
  }//end of path check & deletion
  


}//end of post
?>
<div id="all_contents">
<?php echo (!empty($content_left)) ? "<div id=\"content_left\"> $content_left </div>" : "" ; ?>
<div id="content_right">
 <div id="content_right_left">
<?php echo (!empty($content_top)) ? "<div id=\"content_top\"> $content_top </div>" : "" ; ?>
<div id="content">
 <div id="main"> 

<div id="structure">
  <div id="path">
    <div id="form_top">
      <ul class="form_top">
        <li> <a class="button" href="path.php">Create New</a> </li> 
        <li><input type="submit" class="button" form="path_header" name="submit_header" id="submit_header" Value="Save"></li>
<!--        <li><input type="submit" class="button" form="org_line" name="submit_line"  id="submit_line" Value="Save Line"></li>-->
        <li><input type="reset" class="button" name="reset" form="org_line" Value="Reset All"></li>
        <li> <input type="submit" class="button" form="path_header" name="delete" id="delete"
                    onclick="return confirm('Are you sure?');"     value="Delete"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
      </ul>
    </div>
    <div id ="form_header">
      <form action="path.php" method="post" size="30" id="path_header"  >
        <ul id="form_box"> 
          <li>
            <!--    Place for showing error messages-->
             <?php  if(!empty($msg)) {
               echo '<span class="error">'.$msg  .'</span>' ;
             } ?>
            <!--    End of place for showing error messages-->
          </li>
          <h9>New Option Entry! </h9>
          <li class="ncontrol"><span class="heading">Path Header </span> 
            <div class="two_column"> 
              <ul> 
                <li><label>
<!--                  <a href="find_path.php" class="popup"> 
                      <img src="<?php // echo HOME_URL; ?>themes/images/serach.png"/></a>-->
                    Path Id :</label> 
                  <input type="text" readonly name="path_id" id="path_id" maxlength="30" size="30"
                         placeholder="System Generated No" value="<?php echo htmlentities($path->path_id); ?>">
                  <a name="show" href="path.php?path_id=" class="show">Show</a>
                </li>
                <li><label>Parent Name :</label> 
                  <select name="parent_id" id="parent_id"> 
                      <option value="" ></option> 
                            <?php
                            $parent = path::find_all();
                            foreach ($parent as $record) {
                              echo '<option value="' . $record->path_id . '" ';
                              echo $record->path_id == $path->parent_id ? 'selected' : 'none ';
                              echo '>' . $record->name . '</option>';
                            }
                            ?> 
                    </select> 
                </li>
                <li><label>Path Name :</label> 
                  <input type="text" required name="name" id="email" maxlength="60" size="60"
                         placeholder="Enter a valid path" value="<?php echo htmlentities($path->name); ?>">
                </li>
                <li><label>Path Value :</label>  
                  <input type="text" required name="value" maxlength="60" id="value" size="60" 
                         placeholder="Enter path relative to site home" value="<?php echo htmlentities($path->value); ?>">
                  <!--validation message place for username-->
                </li>
                <li><label>Description  : </label> 
                  <input type="text" required name="description" maxlength="100" id="description" size="60" 
                         placeholder="Enter path descrip. Limit 100 characters" value="<?php echo htmlentities($path->description); ?>">
                </li>
                <li><label>Module : </label>
                  <Select name="module" id="module"> 
                    <option value="" ></option>   
                    <?php
                    $module = module::find_all();
                    foreach ($module as $record) {
                      echo '<option value="' . $record->module_id . '" ';
                      echo $record->module_id == $path->module ? 'selected' : 'none ';
                      echo '>' . $record->name . '</option>';
                    }
                    ?>

                  </select>
                </li>
                <li><label>Primary  : </label> 
                  <Select name="primary" id="primary" >
                    <option value="" ></option>
                    <option value="0" 
                    <?php echo $path->primary == '0' ? 'selected' : '' ; ?> >No</option>
                    <option value="1" 
                    <?php echo $path->primary == '1' ? 'selected' : '' ; ?> >Yes</option>                                   
                  </select>
                </li>
              </ul>
          </li>
        </ul>

      </form> 
    </div>      
  </div>
</div>
</div>
</div>
<?php echo (!empty($content_bottom)) ? "<div id=\"content_bottom\"> $content_bottom </div>" : "" ; ?>
 </div>
    <?php echo (!empty($content_right)) ? "<div id=\"content_right_right\"> $content_right </div>" : "" ; ?>
 </div>

</div>

<?php include_template('footer.inc') ?>
