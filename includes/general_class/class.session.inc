<?php

class session {

 private $login_flag = false;
 public $user_id;
 public $username;
 public $userroles;
 public $orginal_page;
 public $login_status;

 function __construct() {
	session_start();
	if (isset($_SESSION['orginal_page'])) {
	 $this->orginal_page = $_SESSION['orginal_page'];
	}
	$this->check_login();
 }

 private function check_login() {
	if (isset($_SESSION['user_id'])) {
	 $this->login_flag = true;
	 $this->user_id = $_SESSION['user_id'];
	 $this->username = $_SESSION['username'];
	} else {
	 $this->login_flag = false;
	 unset($this->user_id);
	 unset($this->username);
	}
 }

 public function login_status() {
	return $this->login_flag;
 }

 public function login($user) {
	if ($user) {
	 $_SESSION['user_id'] = $this->user_id = $user->user_id;
	 $_SESSION['username'] = $this->username = $user->username;
	 $_SESSION['login_status'] = $this->login_status = true;
	 $this->login_flag = true;
	 $this->orginal_page = $_SESSION['orginal_page'];
	 $this->assign_role($this->user_id);
	}
 }
 
 public function assign_role($user_id){
	$user_roles = [];
	$user_role_ids = [];
	$all_user_roles = user_role::find_by_userId($user_id);
		foreach ($all_user_roles as $user_role){
	 $user_role_ids[] = $user_role->role_id;
	 $option_code = option_line::find_by_id($user_role->role_id);
	 $user_roles[] = $option_code->option_line_code;
	}
	$this->userroles= $_SESSION['user_roles']= $user_roles;
	$_SESSION['user_role_ids']= $user_role_ids;
	
 }

 public function logout() {
	unset($_SESSION['user_id']);
	unset($this->user_id);
	unset($this->username);
	$this->login_flag = false;
 }

 public function redirect_login() {

	if (!$this->login_flag) {
	 $_SESSION['orginal_page'] = $_SERVER["HTTP_HOST"] . $_SERVER["REQUEST_URI"];
	 $this->orginal_page = $_SESSION['orginal_page'];
	 redirect_to(HOME_URL . "extensions/user/user_login.php");
	}
 }

}

$session = new session();
?>