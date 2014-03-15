<?php

class user extends dbObject {

 protected static $table_name = "user";
//  data base variables as stored database column name
 public static $field_array = [
		 "user_id",
		 "username",
		 "password",
		 "first_name",
		 "last_name",
		 "email",
		 "phone",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
//variables used for showing data
 public static $initial_search_array = [
		 "user_id",
		 "username",
		 "first_name",
		 "last_name",
		 "email"
 ];
 public static $column_array = [
		 "user_id",
		 "username",
		 "first_name",
		 "last_name",
		 "email"
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
		 "password",
		 "username",
		 "first_name",
		 "last_name",
		 "email"
 ];
 public static $primary_column = "user_id";
 public $user_id;
 public $username;
 public $enteredPassword;
 public $enteredRePassword;
 public $password;
 Public $first_name;
 Public $last_name;
 public $phone;
 Public $email;
 Public $status;
 Public $laguage;
 Public $date_format;
 Public $theme;
 public $time;
 public $msg;

 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }

 Public static function find_by_username($username) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE username = '{$username}' LIMIT 1";
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_shift($result) : false;
 }

 Public static function find_by_email($email) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE email = '{$email}' LIMIT 1";
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_shift($result) : false;
 }

 private static function codeThePassword($password) {
	return hash('sha256', crypt($password, 'xjkhrwq$@323sqjheq51234$$'));
 }

 public static function authenticate($username = "", $password = "") {
	global $db;
//	$username = $db->escape_value($username);
//	$password = $db->escape_value($password);
////	$password_final = hash("sha256", $password);
	$password_final = self::codeThePassword($password);

	$sql = "Select user_id, username from user 
            WHERE username='{$username}' and password= '{$password_final}' LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public function full_name() {
	if (isset($this->first_name) && isset($this->last_name)) {
	 return $this->first_name . " " . $this->last_name;
	} else {
	 return "";
	}
 }

 public static function check_email_userName($email, $userName) {
	global $db;
	$email = $db->escape_value($email);
	$sql = "SELECT * FROM user WHERE email='{$email}' OR username ='{$userName}'";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? true : false;
 }

 public static function check_email($email) {
	global $db;
	$email = $db->escape_value($email);
	$sql = "SELECT * FROM user WHERE email='{$email}' ";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? true : false;
 }

 public static function check_userName($userName) {
	global $db;
	$userName = $db->escape_value($userName);
	$sql = "SELECT * FROM user WHERE username ='{$userName}'";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? true : false;
 }

 public static function user_verification_update($user_details) {
	if (!empty($user_details)) {
	 $username = trim(mysql_prep($user_details['username'][0]));
	 $password = trim(mysql_prep($user_details['enteredPassword'][0]));
	 $repassword = trim(mysql_prep($user_details['enteredRePassword'][0]));
	 $email = trim(mysql_prep($user_details['email'][0]));
	 if (!empty($user_details['user_id'][0])) {
		$userid = trim(mysql_prep($user_details['user_id'][0]));
	 } else {
		$userid = false;
	 }

	 //first check existing or new user 
	 if (empty($userid)) {
//		$existing_user_check = self::check_email_userName($email, $username);
		If (self::check_email($email)) {
		 echo '<div class="message error">E-mail id is already associated with an user id<br/>
     <a href="'.$_SERVER['PHP_SELF'].'#tabsLine-3">Reset your password</a></div>';
		 $returnedData = false;
		} else If (self::check_userName($username)) {
		 echo '<div class="message error">Sorry, username is not available.<br/>
     Please try a differnt user name</div>';
		 $returnedData = false;
		} elseif ($password == $repassword) {
		 $password_final = self::codeThePassword($password);
//			echo " password is $password  & password_final is $password_final, user name $username, email $email";
		 $user_details['password'][0] = $password_final;
		 $returnedData = $user_details;
		}//nonexisting user check 
	 }//end of password match
	 elseif ((!empty($userid)) && (!empty($password))) {
//		 echo " <br>in 4 ";
		if ($password == $repassword) {
//		 echo " <br>in 5 ";
		 $password_final = self::codeThePassword($password);
		 $user_details['password'][0] = $password_final;
		 $returnedData = $user_details;
		}
	 } elseif ((!empty($userid)) && (empty($password))) {
//		echo " <br>in 6 ";
		$password_final = self::find_by_id($userid)->password;
		$user_details['password'][0] = $password_final;
		$returnedData = $user_details;
	 }
	}

//		 	 	  echo '<div class="message"> <pre>';
//	print_r($returnedData);
//	echo '</div>';

	return $returnedData;
 }

 public function _after_save() {
	global $db;
	if ($this->user_id) {
	 $msg = "New user registration is sucessful!";
	 $to = $this->email;
	 $subject = "User Registrtion @" . SITE_NAME;
	 $message = "Dear " . $this->username . '<br> your regitraton is sucessful';
	 $replyto = "From : admin@site.com";

	 if (mail($to, $subject, $message)) {
		$msg = "mail has been sent";
	 } else {
		$msg = "mail failed!";
	 }//email complete
	}//new user registration complete
	else {
	 $msg = "New user registration Failed!" . mysql_error();
	}// registraion failed
	return $this->msg;
 }

}

//end of resource class
?>



