<?php
 $proceed = true;
?>
<div id="installation_header"><h1>inoERP installation : </h1><h2> Database Settings (Step 2) </h2></div>
<form action=""  method="post" id="dbsettings"  name="dbsettings">
<div >
  <ul class="list-unstyled">
  <li><label>Database Host  : </label> 
   <input type="text" name="db_server[]" value='localhost' maxlength="50" id="db_server" size="30"  >
  </li>
  <li><label>Database Name :</label>	<?php echo $f->text_field('db_name', '', '30', 'db_name', '', 1); ?></li>
  <li><label>Database User Name :</label>	<?php echo $f->text_field('db_user', '', '30', 'db_user', '', 1); ?></li>
  <li><label>Databse Password  : </label> 
   <input type="db_pass" name="db_pass[]" value=''  maxlength="50" id="db_pass" size="30"  >
  </li>
 </ul>
  
</div>

<?php
 if ($proceed) {
  echo '<input type="submit" value="Save & Proceed" class="button btn-primary continue" form="dbsettings">';
  echo "&nbsp;&nbsp;&nbsp;&nbsp;<input action='action' class='button' type='button' value='Go Back' onclick='history.go(-1);' />";
 } else {
  echo "<a href='' class='button btn-primary error'>Fix above error to proceed further</a>";
 }
?>
</form>     
