<?php

class inocsrf {

 private $_time = 12;
 protected static $OriginCheck = false;

 private function _create_token() {
	global $session;
	$token = inoToken();
	$_SESSION['csrf_token'] = $token;
	$_SESSION['csrf_token_time'] = time();
	$session->session_update();
	return $token;
 }

 private function _destroy_token() {
	global $session;
	$_SESSION['csrf_token'] = null;
	$_SESSION['csrf_token_time'] = null;
	$session->session_update();
	return true;
 }

 public function token_tag() {
	$token = $this->_create_token();
	return "<input type=\"hidden\" class=\"hidden\" name=\"csrf_token\" value=\"" . $token . "\">";
 }

 public function validate_toekn() {
	if (isset($_POST['csrf_token'])) {
	 $user_token = $_POST['csrf_token'];
	 $stored_token = $_SESSION['csrf_token'];
	 if ($user_token === $stored_token) {
		if ($this->_token_is_recent()) {
		 return true;
		} else {
		 throw new Exception('CSRF token has expired.');
		}
	 } else {
		throw new Exception('CSRF tokens are not matching');
	 }
	} else if (isset($_SESSION['csrf_token'])) {
	 throw new Exception('Missing CSRF form token.');
	} else {
	 return true;
	}
 }

 private function _token_is_recent() {
	$max_elapsed = 60 * 60 * $this->_time;
	if (isset($_SESSION['csrf_token_time'])) {
	 $stored_time = $_SESSION['csrf_token_time'];
	 return ($stored_time + $max_elapsed) >= time();
	} else {
	 // Remove expired token
	 $this->_destroy_token();
	 return false;
	}
 }

}

$inocsrf = new inocsrf();

//end of forma class
?>