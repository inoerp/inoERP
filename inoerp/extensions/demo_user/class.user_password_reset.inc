<?php

class user_password_reset extends dbObject {

 public static $table_name = "user_password_reset";
 public static $parent_primary_column = "user_id";
 public static $primary_column = "user_password_reset_id";
 public static $key_column = 'user_id';
 public static $module = "extension";
//  data base variables as stored database column name
 public $field_a = [
		 "user_password_reset_id",
		 "user_id",
		 "code",
		 "status",
		 "creation_date"
 ];
 public $requiredField = [
		 "user_id",
		 "code",
		 "status",
		 "creation_date"
 ];
 public $user_password_reset_id;
 public $user_id;
 public $username;
 public $email;
 public $code;
 public $status;
 public $creation_date;
 public $time;
 public $msg;


 private function _codeThePassword($password) {
	return hash('sha256', crypt($password, 'xjkhrwq$@323sqjheq51234$$'));
 }

 public function findBy_userId($user_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE user_id = :user_id ";
	$sql .= " AND status IS NULL"
					. " ORDER BY user_password_reset_id LIMIT 1";
	$value_a = ['user_id' => $user_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 private function _findUnUsedRecord_by_user_id($user_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE user_id = :user_id ";
	$sql .= " AND status IS NULL ";
	$value_a = ['user_id' => $user_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? ($result) : false;
 }

 private function _delete_existing_records($user_id) {
	$existing_records = $this->_findUnUsedRecord_by_user_id($user_id);
	if ($existing_records) {
	 $upr_d = new user_password_reset();
	 foreach ($existing_records as $record) {
		$upr_d->user_password_reset_id = $record->user_password_reset_id;
		$upr_d->delete();
	 }
	}
 }

 public function generateResetPassword($user) {
	global $dbc;
	global $si;
	$username = $user->username;
	$email = $user->email;
	$user_id = $user->user_id;
	if ($user->user_id) {
	 $time = time();
	 //check if any unused password is available
	 $this->_delete_existing_records($user_id);
	 $code = $this->_codeThePassword($time . $username . $email);

	 $url = HOME_URL . 'extensions/user/reset_password.php?user_id=' . $user_id . '&code=' . $code;
	 $link = "<a target='_blank' href='" . $url . "'>Reset Password</a>";
	 $to = $email;
	 $subject = "New password reset request @" . $si->site_name;
	 $message = "<html> <body>Dear " . $user->username . '<br><br>';
	 $message .= "Click on the below link to reset your password<p>";
	 $message .= $link;
	 $message .='<br><br>Thanks<br>' . $si->site_name . '</body></html>';
	 $from = "admin@site.com";
	 $headers = "From: $from\r\n";
	 $headers .= "Content-type: text/html\r\n";

	 if (mail($to, $subject, $message, $headers)) {
//		$msg = "New password reset details have been Successfully sent";
		$new_password_request = new user_password_reset();
		$new_password_request->code = $code;
		$new_password_request->user_id = $user_id;
		$new_password_request->email = $email;
		$new_password_request->status = 0;
		$new_password_request->creation_date = strftime("%Y-%m-%d %H:%M:%S", $time);
		$new_password_request->user_password_reset_id = null;

		$new_password_request->save();
		$dbc->confirm();
	 } else {
		echo "Failed to send email !";
	 }//email complete
	}//new user registration complete
	else {
	 echo "<br>Sorry, Couldn't complete the password reset request!" . mysql_error();
	}// registraion failed
 }

}

//end of resource class
?>