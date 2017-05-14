<?php

class dbObject extends dbc {

 use dbObject_t;

 public $db_name = \DB_NAME;

 function __construct() {
  global $dbc;
  if (empty($dbc->connection)) {
   exit('Data base not found. Please check the dbsettings.php file');
  } 
 }

 public function __set($name, $value) {
  $this->$name = $value;
 }

 public function __get($var) {
  if (property_exists(get_called_class(), $var)) {
   return $this->$var;
  } else {
   return false;
  }
 }

}

//end of content_type class

$dbObject = new dbObject();
$db = & $dbObject;
?>