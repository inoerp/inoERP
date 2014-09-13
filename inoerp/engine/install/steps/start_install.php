<div id="installation_header"><h1>inoERP installation : </h1><h2> Start Installation (Step 3) </h2></div>
<?php
 $proceed = true;
 $dbsetting_file = '<?php ';
 $dbsetting_file .= ' defined("DB_SERVER") ? null : define("DB_SERVER", "' . $_POST['db_server'][0] . '");';
 $dbsetting_file .= ' defined("DB_USER") ? null : define("DB_USER", "' . $_POST['db_user'][0] . '");';
 $dbsetting_file .= ' defined("DB_NAME") ? null : define("DB_NAME", "' . $_POST['db_name'][0] . '");';
 $dbsetting_file .= ' defined("DB_PASS") ? null : define("DB_PASS", "' . $_POST['db_pass'][0] . '");';
 $dbsetting_file .= ' ?>';

 $dbc = new dbc();
 try {
  $dbc->connection = new PDO('mysql:host=' . $_POST['db_server'][0] . '; dbname=' . $_POST['db_name'][0] . ';charset=utf8', $_POST['db_user'][0], $_POST['db_pass'][0]);
  $dbc->connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
  $dbc->connection->setAttribute(PDO::ATTR_AUTOCOMMIT, false);
 } catch (PDOException $e) {
  $proceed = false;
  print "Data Base Connection Error!: "
    . "<br><span class='error'>" . $e->getMessage() . "</span><h2> Enter the correct database information</h2> ";
 }

 if ($proceed) {
  //verify if any existing data exists
  $existing_tables = view::count_all_tables();
  if (empty($existing_tables->table_count)) {
   $db_setting_file = fopen(HOME_DIR . DS . 'includes' . DS . 'basics' . DS . 'dbsettings.inc', "w");
   $result = fwrite($db_setting_file, $dbsetting_file);
   if ($result > 0) {
    echo "<br>Database settings file is sucessfully created. Remove the write access from inlcudes directory, basics directory and dbsettings<br><br>";
   } else {
    echo "<br>Database settings file creation failed!. Verify the wrtite access to inlcudes directory, basics directory and dbsettings file<br><br>";
    $proceed = false;
   }
   fclose($db_setting_file);
  }else{
   echo "<br>Selected database has ". $existing_tables->table_count. ' number of tables. Remove all tables before proceeding further';
   $proceed = false;
  }
 }

 if (!$proceed) {
  require_once 'dbsettings.php';
  echo "<a href='' class='button btn-primary error'>Fix above error to proceed further</a>";
  return;
 }
?>

<form action="" name="import_db" id="import_db" method="get">
 <ul class="list-unstyled">
  <li><label>DB Instance Type</label>
<?php $f = new inoform();
 echo $f->select_field_from_array('db_type', $db_type_a, ''); ?></li>

   <?php echo $f->hidden_field_withId('action', 'complete_install'); ?>
  <li><input type="submit" class="button" id='complete_install' value="Start Installation" ></li>
 </ul>
</form>
<div id="progress_message" class="message">
 <div id="progress" class="message"></div><div id="information" class="message"></div>
</div>     