<div id="installation_header">
 <div class="page-header">
  <h1>inoERP installation <small>Complete Installation  (Step 4)</small></h1>
 </div>
</div>
<?php
require_once(INC_CLASS . DS . "trait_dbObject_t.inc");
require_once(INC_CLASS . DS . "class_dbObject.inc");
require_once(INC_EXTENSIONS . DS . "view" . DS . "class_extn_view.inc");

/**
 * Loads an SQL stream into the database one command at a time.
 *
 * @params $sqlfile The file containing the mysql-dump data.
 * @params $connection Instance of a PDO Connection Object.
 * @return boolean Returns true, if SQL was imported successfully.
 * @throws Exception
 */
function importSQL($sqlfile, $connection) {
 $queries = getQueriesFromSQLFile($sqlfile);
 $count = 0;
 $total = count($queries);
 foreach ($queries as $query) {
  if (strpos($query, 'DEFINER=`root`@`localhost`') !== false) {
   str_replace('DEFINER=`root`@`localhost`', ' ', $query);
  }
  $count++;
  try {
   $connection->connection->exec($query);
   $_SESSION['progress_percentage'] = round($count / 600);
   // Calculate the percentation
   $percent = intval($count / $total * 100);
   $percent = ($percent <= 100) ? $percent : '100';
   $percent_p = $percent . '%';

   // Javascript for updating the progress bar and information
   echo '<script language="javascript">
     document.getElementById("progress").innerHTML="<div style=\"width:' . $percent_p . ';background-color:rgba(144, 238, 144, 0.51);\">' . $percent . '&nbsp; % Completed.</div>";
    document.getElementById("information").innerHTML="' . $count . ' row(s) processed.";
    </script>';
// This is for the buffer achieve the minimum size in order to flush data
   echo str_repeat(' ', 1024 * 64);
// Send output to browser immediately
   flush();

//// Sleep one second so we can see the delay
//    sleep(1);
  } catch (Exception $e) {
   echo "<span class='error'>" . $e->getMessage() . "<br /> <p>The sql is: $query</p></span>";
  }
 }

 return true;
}

/**
 * getQueriesFromSQLFile parses a sql file and extracts all queries
 * for further processing with pdo execute.
 *
 * - strips off all comments, sql notes, empty lines from an sql file
 * - trims white-spaces
 * - filters the sql-string for sql-keywords
 * - replaces the db_prefix
 *
 * @param $file sqlfile
 * @return array Trimmed array of sql queries, ready for insertion into db.
 */
function getQueriesFromSQLFile($sqlfile) {
 if (is_readable($sqlfile) === false) {
  throw new Exception($sqlfile . 'does not exist or is not readable.');
 }

 # read file into array
 $file = file($sqlfile);

 # import file line by line
 # and filter (remove) those lines, beginning with an sql comment token
 $file = array_filter($file, create_function('$line', 'return strpos(ltrim($line), "--") !== 0;'));

 # and filter (remove) those lines, beginning with an sql notes token
 $file = array_filter($file, create_function('$line', 'return strpos(ltrim($line), "/*") !== 0;'));

 # this is a whitelist of SQL commands, which are allowed to follow a semicolon
 $keywords = array(
  'ALTER', 'CREATE', 'DELETE', 'DROP', 'INSERT',
  'REPLACE', 'SELECT', 'SET', 'TRUNCATE', 'UPDATE', 'USE'
 );

 # create the regular expression for matching the whitelisted keywords
 $regexp = sprintf('/\s*;\s*(?=(%s)\b)/s', implode('|', $keywords));

 # split there
 $splitter = preg_split($regexp, implode("\r\n", $file));

 # remove trailing semicolon or whitespaces
 $splitter = array_map(create_function('$line', 'return preg_replace("/[\s;]*$/", "", $line);'), $splitter);

 # remove empty lines
 return array_filter($splitter, create_function('$line', 'return !empty($line);'));
}
?>
<div id="progress_message" class="message">
 <div id="progress" class="message"></div><div id="information" class="message"></div>
</div>
<?php
// Temporary variable, used to store current query
$templine = '';
if ($_GET['db_type'][0] == 'production') {
 $filename = __DIR__ .'/../inoerp_prod.sql';
} else {
 $filename = __DIR__ .'/../inoerp.sql';
}

try {
 importSQL($filename, $dbc);
 // Tell user that the process is completed
 echo '<script language="javascript">document.getElementById("information").innerHTML="Process completed"</script>';
 echo '<ul class="list-unstyled list-group row">';
 echo "<li class=' alert-success list-group-item' >All tables have been Successfully imported</li>";
 echo "<li class=' alert-success list-group-item' >Verify that the file install.php is removed from home directory. If not, delete it.</li>";
 echo "<li class=' alert-success list-group-item' ><a href='" . HOME_URL . "'>Go to the home page </a> & Login to the system  with default user name/password :inoerp/inoerp and reset the password.</li>";

 echo '</ul>';
 unlink('install.php');
} catch (Exception $e) {
 echo '      <div class="jumbotron">
        <h1>Below errors occured during installation</h1>';

 echo "<br>Tables import fialed" . $e->getMessage() . '</div>';
}
?>
     