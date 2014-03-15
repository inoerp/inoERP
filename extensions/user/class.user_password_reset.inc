<?php

class user_password_reset extends dbObject {

 protected static $table_name = "user_password_reset";
//  data base variables as stored database column name
 public static $field_array = [
		 "user_password_reset_id",
		 "user_id",
		 "code",
		 "status",
		 "creation_date"
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
		 "code",
		 "status",
		 "creation_date"
 ];
 public static $primary_column = "user_password_reset_id";
 public $user_password_reset_id;
 public $user_id;
 public $username;
 public $email;
 public $code;
 public $status;
 public $creation_date;
 public $time;
 public $msg;

 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }

 private static function codeThePassword($password) {
	return hash('sha256', crypt($password, 'xjkhrwq$@323sqjheq51234$$'));
 }

 public static function findUnUsedRecord_by_user_id($user_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE user_id = '{$user_id}' ";
	$sql .= " AND status IS NULL ";
	$sql .= " LIMIT 1 ";

	$result = self::find_by_sql($sql);
	return !empty($result) ? array_shift($result) : false;
 }
 
 public static function generateResetPassword($user) {
	global $db;
		$username = $user->username;
	$email = $user->email;
	$user_id = $user->user_id;
	if ($user->user_id) {
	 $time = time();
	 //check if any unused password is available
	 $unused_password = self::findUnUsedRecord_by_user_id($user_id);
	 if ($unused_password) {
		$code = $unused_password->code;
			 } else {
		$code = self::codeThePassword($time . $username . $email);
	 }
	 $url = HOME_URL . 'extensions/user/reset_password.php?user_id=' . $user_id . '&code=' . $code;
	 $link = "<a target='_blank' href='".$url."'>Reset Password</a>";
	 $to = $email;
	 $subject = "New password reset request @" . SITE_NAME;
	 $message = "<html> <body>Dear " . $user->username . '<br><br>';
	 $message .= "Click on the below link to reset your password<p>";
	 $message .= $link;
	 $message .='<br><br>Thanks<br>' . SITE_NAME . '</body></html>';
	 $from = "admin@site.com";
	 $headers = "From: $from\r\n";
	 $headers .= "Content-type: text/html\r\n";

	 if (mail($to, $subject, $message, $headers)) {
		$msg = "New password reset details have been sucessfully sent";
		$new_password_request = new self;
		$new_password_request->code = $code;
		$new_password_request->user_id = $user_id;
		$new_password_request->email = $email;
		$new_password_request->status = 0;
		$new_password_request->creation_date = strftime("%Y-%m-%d %H:%M:%S", $time);
		if ($unused_password) {
		 $new_password_request->user_password_reset_id = $unused_password->user_password_reset_id;
		}

		$msg = $new_password_request->save();
	 } else {
		$msg = "mail failed!";
	 }//email complete
	}//new user registration complete
	else {
	 $msg = "New user registration Failed!" . mysql_error();
	}// registraion failed
	return $msg;
 }

}

//end of resource class
?>



