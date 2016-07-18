<?php

class dbObject2 extends dbc2 {
 use dbObject_t;
 public $db_name = \DB_NAME2;
 function __construct() {
//	if (!empty(static::$table_name)) {
////	 echo '<br> table name '. static::$table_name;
//	 global $dbc;
//	 $sql_fields = " SHOW COLUMNS FROM  " . static::$table_name;
//	 $prepare = $dbc->connection->prepare($sql_fields);
//	 $prepare->execute();
//	 $fields = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
//	 static::$field_array = $fields;
//	 foreach ($fields as $key => $value) {
//		$this->$value = '';
//	 }
//	}
 }

 public function __set($name, $value) {
  $this->$name = $value;
 }

 public function get($var) {
  if (property_exists(get_called_class(), $var)) {
   return $this->$var;
  } else {
   return false;
  }
 }
}

?>