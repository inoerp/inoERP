<?php

class user_group extends ino_user {

 public static $table_name = "user_group";
 public static $parent_primary_column = "ino_user_id";
 public static $primary_column = "user_group_id";
 public static $key_column = 'ino_user_id';
 public static $module = "extension";
 public static $system_info = [
 ];
//  data base variables as stored database column name
 public $field_a = [
		 "user_group_id",
		 "ino_user_id",
		 "user_group_code",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public $requiredField = [
		 "ino_user_id",
		 "user_group_code"
 ];
 public $ino_user_id;
 public $user_group_id;
 public $user_group_code;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function find_by_userId($user_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE ino_user_id='{$user_id}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public function findBy_userId() {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE ino_user_id= :ino_user_id ";
	$value_a = ['ino_user_id' => $this->ino_user_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? $result : false;
 }
 
 public function _after_save(){
  
 }

}

//end of user_group class
?>