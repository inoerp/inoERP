<?php
$proceed = true;
?>
<div id="installation_header">
 <div class="page-header">
  <h1>inoERP installation <small>Database Settings (Step 2)</small></h1>
 </div>
</div>
<form action=""  method="post" id="dbsettings"  name="dbsettings" >
 <div >
  <ul class="list-group">
   <li class="list-group-item"><label class="label ino-label">Database Type</label>
    <?php  echo $f->select_field_from_array('db_type', ['MYSQL' => 'MySQL / MariaDB' , 'ORACLE' => 'Oracle'], '', 'db_type', '', 1); ?></li>
   </li>
   <li class="list-group-item"><label class="label ino-label">Database Host</label><input type="text" name="db_server[]" value='localhost' maxlength="50" id="db_server" size="30"  >  </li>
   <li class="list-group-item"><label class="label ino-label">Database Port</label><input type="text" name="db_port[]" value='' maxlength="50" id="db_server" size="30"  >  </li>
   <li class="list-group-item"><label class="label ino-label">SID</label><?php echo $f->text_field('db_sid', '', '30', 'db_sid'); ?> </li>
   <li class="list-group-item"><label class="label ino-label">Database Name</label><?php echo $f->text_field('db_name', '', '30', 'db_name'); ?></li>
   <li class="list-group-item"><label class="label ino-label">Schema/User Name</label><?php echo $f->text_field('db_user', '', '30', 'db_user', '', 1); ?></li>
   <li class="list-group-item"><label class="label ino-label">Databse Password</label><input type="db_pass" name="db_pass[]" value=''  maxlength="50" id="db_pass" size="30"  ></li>
  </ul>

 </div>

 <?php
 if ($proceed) {
  echo '<div id="input-btn">';
  echo '<input type="submit" value="Save & Proceed" class="button btn-primary continue" form="dbsettings">';
  echo "&nbsp;&nbsp;&nbsp;&nbsp;<input action='action' class='button' type='button' value='Go Back' onclick='history.go(-1);' />";
  echo '</div>';
 } else {
  echo "<a href='' class='button btn-primary error'>Fix above error to proceed further</a>";
 }
 ?>
</form>     
