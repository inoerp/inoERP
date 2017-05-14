<?php

class dbc2 extends dbc {

 public $connection;
 public $rollback;

// public $pending_transaction;

 function __construct() {
  if(!(DB_SERVER)){
   return false;
  }
	try {
	 $this->connection = new PDO('mysql:host=' . DB_SERVER2 . '; dbname=' . DB_NAME2 . ';charset=utf8', DB_USER2, DB_PASS2);
	 $this->connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
//	 $this->connection->setAttribute(PDO::ATTR_PERSISTENT, true);
	 $this->connection->setAttribute(PDO::ATTR_AUTOCOMMIT, false);
    $this->rollback = false;
//	 $this->pending_transaction = true;
	 $this->connection->beginTransaction();
	} catch (PDOException $e) {
	 print "Data Base Connection Error!: <br> Modify the database settings @ includes/basics/dbsettings.php file & reload the page"
   . "<br>" . $e->getMessage() . "<br/>";
	 die();
	}
 }


}

$dbc2 = new dbc2();
?>