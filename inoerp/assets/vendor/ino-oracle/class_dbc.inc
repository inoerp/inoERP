<?php

class dbc {

 public $connection;
 public $rollback;

// public $pending_transaction;

 function __construct() {

  $tns = "  
  (DESCRIPTION=
    (ADDRESS = (PROTOCOL = tcp)(HOST = localhost)(PORT=1521))
    (CONNECT_DATA=(SID=orcl))
  )
       ";

  try {
   $this->connection = new PDO("oci:dbname=" . $tns, 'ino', 'Welcome1');

//   try {
//    $this->connection = oci_connect("inoerp", "Welcome1", 'localhost:1521/orcl');
//   } catch (PDOException $e) {
//    print "<h1>Oracle databse connection is not available</h1>. Please check after sometime ";
//    pa($e);
//    die();
//   }

   $this->connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
   $this->connection->setAttribute(PDO::ATTR_PERSISTENT, false);
   $this->connection->setAttribute(PDO::ATTR_AUTOCOMMIT, false);
   $this->connection->setAttribute(PDO::ATTR_CASE, PDO::CASE_LOWER);
   $this->rollback = false;
//	 $this->pending_transaction = true;
   $this->connection->beginTransaction();
  } catch (PDOException $e) {
   print "Data Base Connection Error!: " . $e->getMessage() . "<br/>";
   die();
  }
  $this->open_connection();
 }

 public function confirm() {
  if ($this->rollback) {
   $this->connection->rollBack();
  } else {
   $this->connection->commit();
  }
  $this->connection->beginTransaction();
 }

 private function open_connection() {
  
 }

//ddlexecute is used for all delete/update/drop
 public function ddlexecute($sql = '') {
  if (!empty($sql)) {
   $stmt = $this->connection->prepare($sql);
   try {
    $stmt->execute();
    return true;
   } catch (PDOException $e) {
    print "DDL failed! : " . $e->getMessage() . "<br/>";
    return false;
   }
  }
 }

 //iexecute is used for all insert operation
 public function iexecute($sql = '') {
  if (!empty($sql)) {
   $prepare = $this->connection->prepare($sql);
   try {
    $prepare->execute();
    $result = $this->connection->lastInsertId();
    return $result;
   } catch (PDOException $e) {
    print " Execution failed!: " . $e->getMessage() . "<br/>";
   }
  }
 }

 public function sexecute($sql = '') {
  if (!empty($sql)) {
   $prepare = $this->connection->prepare($sql);
   try {
    $prepare->execute();
    $result = $prepare->fetchAll(PDO::FETCH_CLASS);
    return $result;
   } catch (PDOException $e) {
    print " Execution failed!: " . $e->getMessage() . "<br/>";
   }
  }
 }

 public function close_connection() {
  $this->connection = null;
  unset($this);
 }

}

//end of content_type class
$dbc = new dbc();
?>