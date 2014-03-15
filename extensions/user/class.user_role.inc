<?php

class user_role extends user {

 protected static $table_name = "user_role";
//  data base variables as stored database column name
 public static $field_array = [
		 "user_role_id",
		 "user_id",
		 "role_id"
 ];
//variables used for showing data
 public static $initial_search_array = [

 ];
 public static $column_array = [

 ];
 public static $account_array = [
 ];
 public static $checkbox_array = [

 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 "user_id",
		 "role_id"
 ];
 public static $primary_column = "user_role_id";
 public $user_id;
 public $user_role_id;
 public $role_id;
 public $time;
 public $msg;

public static function find_by_userId($user_id){
 $sql = " SELECT * FROM ";
 $sql .= self::$table_name;
 $sql .= " WHERE user_id='{$user_id}' ";
 $result = self::find_by_sql($sql);
 return $result;
 
}

}

//end of user_role class
?>



