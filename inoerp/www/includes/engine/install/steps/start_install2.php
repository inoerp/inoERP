<div id="installation_header">
 <div class="page-header">
  <h1>inoERP installation <small>Start Installation  (Step 3)</small></h1>
 </div>
</div>
<?php
$proceed = true;
require_once(INC_BASICS . DS . "basics.inc");


$dbc = new dbc();


if ($proceed) {

 switch (DB_TYPE) {
  case 'ORACLE':
   $ora_db_file = HOME_DIR . DS . "assets" . DS . "vendor" . DS . "ino-oracle" . DS . "class_dbObject.inc";
   if (file_exists($ora_db_file)) {
    require_once($ora_db_file);
   } else {
    die('DB Oracle file not found. inoERP with mySQL and MariaDB are released with open source license. Contact inoERP team for Oracle database');
   }
   break;

  default:
   require_once(INC_CLASS . DS . "trait_dbObject_t.inc");
   require_once(INC_CLASS . DS . "class_dbObject.inc");
 }

require_once(INC_EXTENSIONS . DS . "view" . DS . "class_extn_view.inc");

 //erify db version
 $db_version = $dbc->connection->getAttribute(PDO::ATTR_CLIENT_VERSION);
 echo '<h2>DB Version is</h2>';
 print_r($db_version);
 echo '<p>';
 //verify if any existing data exists
 $existing_tables = extn_view::count_all_tables();
 if (empty($existing_tables->table_count)) {
  echo "<br>Database connection was successful <br>Selected database has no tables<br>You can proceed with installation" ;
 } else {
  echo "<br>Selected database has " . $existing_tables->table_count . ' number of tables. Remove all tables before proceeding further';
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
  <h2> You can convert a demo instance to a production instance after the installation</h2>
  <li><label>DB Instance Type</label>
   <?php
   $f = new inoform();
   echo $f->select_field_from_array('db_type', $db_type_a, '');
   ?></li>

  <?php echo $f->hidden_field_withId('action', 'complete_install'); ?>
  <li><input type="submit" class="button" id='complete_install' value="Start Installation" ></li>
 </ul>
</form>
<div id="progress_message" class="message">
 <div id="progress" class="message"></div><div id="information" class="message"></div>
</div>     