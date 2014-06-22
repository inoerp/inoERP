<?php
class session {
 private $login_flag = false;
 public $user_id;
 public $username;
 public $user_roles;
 public $orginal_page;
 public $login_status;

 function __construct() {
	session_start();
	//	session_set_cookie_params(0, '/', '.' . str_replace('www.', '', $_SERVER['HTTP_HOST']));
//	session_name('inoerp_xxfdgsu');
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
	 $_SESSION['user_roles'] = ['ANONYMOUS'];
//	 $this->assign_role_access();
	 unset($this->user_id);
	 unset($this->username);
	}
 }

 public function login_status() {
	return $this->login_flag;
 }

 public function login($user) {
	if ($user) {
	 //generate a new session id for the user
	 $_SESSION['user_roles'] = null;
	 $_SESSION['role_access'] = null;
	 $_SESSION['allowed_path_ids'] = null;
	 session_regenerate_id(true);
	 $_SESSION['user_id'] = $this->user_id = $user->user_id;
	 $_SESSION['username'] = $this->username = $user->username;
	 $_SESSION['login_status'] = $this->login_status = true;
	 $this->login_flag = true;
	 if (!empty($_SESSION['orginal_page'])) {
		$this->orginal_page = $_SESSION['orginal_page'];
	 }
	 $this->assign_role();
//	 if (!empty($this->user_roles)) {
//		$this->assign_role_access();
//	 }
	}
 }

 public function assign_role() {
	$ur = new user_role();
	$ur->user_id = $this->user_id;
	$ur_i = $ur->findBy_userId();
	$user_roles = [];
	foreach ($ur_i as $user_role) {
	 array_push($user_roles, $user_role->role_code);
	}
	$this->user_roles = $_SESSION['user_roles'] = $user_roles;
 }

// public function assign_role_access() {
//	$ra = new role_access();
//	$ra_a = [];
//	foreach ($_SESSION['user_roles'] as $key_r => $role_code) {
//	 $ra_i = $ra->findBy_roleCode($role_code);
//	 if(empty($ra_i)){
//		continue;
//	 }
//	 foreach ($ra_i as $role_access) {
//		$ra_a[$role_access->obj_class_name] = $role_access->access_level;
//	 }
//	}
//	$_SESSION['role_access'] = $ra_a;
// }

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