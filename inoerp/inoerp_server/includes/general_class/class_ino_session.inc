<?php

class ino_session extends dbObject {

 private $login_flag = false;
 private $_session_token;
 public $user_id;
 public $username;
 public $user_roles;
 public $orginal_page;
 public $login_status;
 public static $table_name = "ino_session";
 public static $primary_column = "ino_session_id";
 public static $key_column = 'ino_user_id';
 public static $module = "sys";
 public $field_a = [
		 'ino_session_id',
		 'ino_user_id',
		 'session_token',
		 'php_session_id',
		 'hostname',
		 'session_data',
		 'creation_date',
		 'created_by',
		 'last_update_by',
		 'last_update_date',
 ];
 public $ino_session_id;
 public $ino_user_id;
 public $session_token;
 public $php_session_id;
 public $hostname;
 public $session_data;
 public $creation_date;
 public $created_by;
 public $last_update_by;
 public $last_update_date;

 public function __construct() {
	session_set_save_handler(
					array($this, "session_open"), array($this, "session_close"), array($this, "session_read"), array($this, "session_write"), array($this, "session_destroy"), array($this, "session_gc")
	);
 }

 public function check_login() {
	if (isset($_SESSION['user_id'])) {
	 $ino_sess_i = ino_session::find_by_keyColumn($_SESSION['user_id']);
	 if ((!empty($ino_sess_i)) && (isset($_SESSION['session_token'])) && ($ino_sess_i->session_token == $_SESSION['session_token']) && (HOME_URL == $ino_sess_i->hostname)) {
		$this->login_flag = true;
		foreach ($this->field_a as $k => $v) {
		 $this->$v = $ino_sess_i->$v;
		}
	 } else {
//    $this->logout();
	 }
	} else {
	 $this->login_flag = false;
	 $_SESSION['user_roles'] = ['ANONYMOUS'];
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
	 //session_regenerate_id(true);
	 $_SESSION['user_id'] = $_SESSION['ino_user_id'] = $this->user_id = $user->ino_user_id;
	 $_SESSION['username'] = $this->username = $user->username;
	 $_SESSION['login_status'] = $this->login_status = true;
	 if (!empty($_POST['user_language'][0])) {
		$_SESSION['lang'] = $_POST['user_language'][0];
	 } else if (!empty($user->user_language)) {
		$_SESSION['lang'] = $user->user_language;
	 } else {
		$_SESSION['lang'] = DEFAULT_LOCALE;
	 }
	 $this->login_flag = true;
	 if (!empty($_SESSION['orginal_page'])) {
		$this->orginal_page = $_SESSION['orginal_page'];
	 }
	 $this->assign_role();
	 $this->_assign_user_groups();

	 $this->_session_token = md5(uniqid(mt_srand(), true));
	 $_SESSION['session_token'] = $this->_session_token;

	 //create session details
	 try {
		$this->_create_sesssion(true);
	 } catch (Exception $e) {
		echo $e->getMessage();
	 }

//   pa($this); pa($_SESSION); echo 'session name '. session_name() . ' - ' . session_id();sdfsfds();
	}
 }

 private function _create_sesssion($new_session = false) {
	global $dbc;

	if (empty($this->user_id) && empty($_SESSION['user_id'])) {
	 return false;
	}

	if (!$new_session) {
	 return false;
	}

	$ino_see = new ino_session();
	$ino_see->ino_user_id = $this->user_id;

	//delete if session exists
	$exist_session = $this->find_by_keyColumn($this->user_id);
	if ($exist_session) {
	 $ino_see->ino_session_id = $exist_session->ino_session_id;
	 $ino_see->delete(false);
	 
	 	$ino_see = new ino_session();
	$ino_see->ino_user_id = $this->user_id;
	}

	$ino_see->php_session_id = session_id();
	$ino_see->session_token = $this->_session_token;
	$_SESSION['session_token'] = $ino_see->session_token;
	$ino_see->hostname = HOME_URL;
	$ino_see->session_data = serialize($_SESSION);
	try {
	 $ino_see->save();
	 $dbc->confirm();
	} catch (Exception $e) {
	 throw new Exception('Unable to create session', 'INO_SESSION_01');
	}
 }

 public function assign_role() {
	$ur = new user_role();
	$ur->ino_user_id = $this->user_id;
	$ur_i = $ur->findBy_userId();
	$user_roles = [];
	$_SESSION['is_admin'] = false;
	foreach ($ur_i as $user_role) {
	 array_push($user_roles, $user_role->role_code);
	 $_SESSION['is_admin'] = ($user_role->role_code == 'ADMIN') ? true : $_SESSION['is_admin'];
	}
	$this->user_roles = $_SESSION['user_roles'] = $user_roles;
 }

 private function _assign_user_groups() {
	$user_group_access_all = user_group_access::find_by_user_id($_SESSION['user_id']);
	if (empty($user_group_access_all)) {
	 $_SESSION['user_org_access'] = null;
	 return;
	}
	$user_org_access_a = [];
	foreach ($user_group_access_all as $user_group_access) {
	 $org_id = $user_group_access->org_id;
	 $user_org_access_a[$org_id] = $user_group_access->access_level;
	}
	$_SESSION['user_org_access'] = $user_org_access_a;
 }

 public function logout() {
//  unset($_SESSION['user_id']);
	unset($_SESSION);
	unset($this->user_id);
	unset($this->username);
	$this->login_flag = false;
 }

 public function redirect_login() {
	if (!$this->login_flag) {
	 $_SESSION['orginal_page'] = $_SERVER["HTTP_HOST"] . $_SERVER["REQUEST_URI"];
	 $this->orginal_page = $_SESSION['orginal_page'];
	 redirect_to(HOME_URL . "extensions/ino_user/user_login.php");
	}
 }

 /* PHP SESSION Handler */

 private function _session_delete_cookie($name, $secure = NULL) {
	global $is_https;
	if (isset($_COOKIE[$name]) || (!$is_https && $secure === TRUE)) {
	 $params = session_get_cookie_params();
	 if ($secure !== NULL) {
		$params['secure'] = $secure;
	 }
	 setcookie($name, '', time() - 4200, $params['path'], $params['domain'], $params['secure'], $params['httponly']);
	 unset($_COOKIE[$name]);
	}
 }

 public function session_open() {
	return true;
 }

 public function session_close() {
	return true;
 }

 public function session_update() {
	global $dbc;
	$current_ses = ino_session::find_by_ColumnNameVal('session_token', $_SESSION['session_token']);
	if ($current_ses) {
	 $current_ses_i = $current_ses[0];
	 $ino_sess_i = new ino_session();
	 foreach($ino_sess_i->field_a as $k => $v){
		$ino_sess_i->$v = $current_ses_i->$v;
	 }
	 $ino_sess_i->session_data = serialize($_SESSION);
	 $ino_sess_i->save();
	 $dbc->confirm();
	} else {
	 
	 throw new Exception('Session not found in database');
	}
 }

 public function session_read($php_sid) {

	$user_a = $this->find_by_ColumnNameVal('php_session_id', $php_sid);

	if ($user_a) {
	 $user_i = $user_a[0];
	} else {
	 return false;
	}

	if ($user_i && $user_i->ino_user_id > 0 && !empty($php_sid)) {
	 // This is done to unserialize the data member of $user.
	 $user_i->session_data = unserialize($user_i->session_data);
	 $_SESSION = $user_i->session_data;
	} elseif ($user_i) {
	 $this->redirect_login();
	} else {
	 $this->logout();
	}


	return true;
 }

 public function session_write() {
	try {
	 $this->_create_sesssion();
	 return true;
	} catch (Exception $e) {
	 return false;
	}
 }

 public function session_destroy($php_sid) {
	$ino_see = new ino_session();
//  $ino_see->ino_user_id = $this->user_id;
	//delete if session exists
	$user_a = $this->find_by_ColumnNameVal('php_session_id', $php_sid);
	if ($user_a) {
	 $user_i = $user_a[0];
	}

	if ($user_i) {
	 $ino_see->ino_session_id = $user_i->ino_session_id;
	 $ino_see->delete();
	}

	$_SESSION = array();
//  $user = ino_anonymous_user();
	// Unset the session cookies.
	$this->_session_delete_cookie(session_name());
 }

 function session_gc($lifetime) {
	return TRUE;
 }

}

$session = new ino_session();
$secure = false; //change it as per your settings
ini_set('session.use_only_cookies', 1);
ini_set('session.entropy_file', '/dev/urandom');
ini_set('session.entropy_length', '512');

$cookieParams = session_get_cookie_params();
session_set_cookie_params($cookieParams["lifetime"], $cookieParams["path"], $cookieParams["domain"], $secure, true);
session_name('INOERP123123');
session_start();

if (isset($_SESSION['orginal_page'])) {
 $session->orginal_page = $_SESSION['orginal_page'];
}
if (!isset($_SESSION['recent_visit'])) {
 $_SESSION['recent_visit'] = [];
} else if (!is_array($_SESSION['recent_visit'])) {
 $_SESSION['recent_visit'] = [];
}
$session->check_login();
$is = &$session;
?>