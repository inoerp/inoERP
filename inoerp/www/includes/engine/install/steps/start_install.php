<div id="installation_header">
 <div class="page-header">
  <h1>inoERP installation <small>Start Installation  (Step 3)</small></h1>
 </div>
</div>
<?php
$proceed = true;
$dbsetting_file = '<?php ';
$dbsetting_file .= ' defined("DB_TYPE") ? null : define("DB_TYPE", "' . $_POST['db_type'][0] . '");';
$dbsetting_file .= ' defined("DB_SERVER") ? null : define("DB_SERVER", "' . $_POST['db_server'][0] . '");';
$dbsetting_file .= ' defined("DB_SID") ? null : define("DB_SID", "' . $_POST['db_sid'][0] . '");';
$dbsetting_file .= ' defined("DB_PORT") ? null : define("DB_PORT", "' . $_POST['db_port'][0] . '");';
$dbsetting_file .= ' defined("DB_USER") ? null : define("DB_USER", "' . $_POST['db_user'][0] . '");';
$dbsetting_file .= ' defined("DB_NAME") ? null : define("DB_NAME", "' . $_POST['db_name'][0] . '");';
$dbsetting_file .= ' defined("DB_PASS") ? null : define("DB_PASS", "' . $_POST['db_pass'][0] . '");';
$dbsetting_file .= ' ?>';
require_once(INC_CLASS . DS . "class_dbc.inc");

$dbc = new dbc();

try {
 switch ($_POST['db_type'][0]) {
  case 'ORACLE':
   $tns = '  
  (DESCRIPTION=
    (ADDRESS = (PROTOCOL = tcp)(HOST = ' . $_POST['db_server'][0] . ')(PORT=' . $_POST['db_port'][0] . '))
    (CONNECT_DATA=(SID=' . $_POST['db_sid'][0] . '))
  ) ';
   $this->connection = new PDO("oci:dbname=" . $tns, DB_NAME, DB_PASS);
   break;

  default:
   $dbc->connection = new PDO('mysql:host=' . $_POST['db_server'][0] . '; dbname=' . $_POST['db_name'][0] . ';charset=utf8', $_POST['db_user'][0], $_POST['db_pass'][0]);
 }

 $dbc->connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
 $dbc->connection->setAttribute(PDO::ATTR_AUTOCOMMIT, false);
} catch (PDOException $e) {
 $proceed = false;
 if ($_POST['db_type'][0] == 'ORACLE') {
  die('DB Oracle file not found. inoERP with mySQL and MariaDB are released with open source license. Contact <a href="www.inoideas.org">inoERP</a> team for Oracle database');
 }
 print "Data Base Connection Error!: "
  . "<br><span class='error'>" . $e->getMessage() . "</span><h2> Enter the correct database information</h2> ";
}


if (!update_htaccessFile()) {
 echo '<h2>Failed to update the .htaccess file. </h2>';
 echo 'You can either proceed with the installtion and manually copy the .htaccess from egnine/install folder after installtion, or <br>';
 echo 'Re-start the installation after giving write access to .htaccess file';
} else {
 $write_file_link = HOME_DIR . DS . '.htaccess';
 if (!chmod($write_file_link, 0644)) {
  echo "<br>Failed to change the access level of the .htacess file. Change the .htaccess file to 06444 mode after installation";
 }
}

if ($proceed) {

 switch ($_POST['db_type'][0]) {
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
 pa($db_version);
 //verify if any existing data exists
 $existing_tables = extn_view::count_all_tables();
 if (empty($existing_tables->table_count)) {
  $db_setting_file_path = HOME_DIR . DS . 'includes' . DS . 'basics' . DS . 'settings' . DS . 'dbsettings.php';
  $db_setting_file = fopen($db_setting_file_path, "w");
  $result = fwrite($db_setting_file, $dbsetting_file);
  if ($result > 0) {
   if (!chmod($db_setting_file_path, 0644)) {
    echo "<br>Failed to change the access level of .dbsettings file. Change the .dbsettings file to 06444 mode after installtion";
   }
   echo "<br>Make sure that the write access from inlcudes directory, basics directory, .htaccess file and dbsettings are removed<br><br>";
  } else {
   echo "<br>Database settings file creation failed!. Verify the wrtite access to inlcudes directory, basics directory and dbsettings file<br><br>";
   $proceed = false;
  }
  fclose($db_setting_file);
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