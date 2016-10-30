<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * 
 *
 */
class user extends dbObject {

 public static $table_name = "user";
 public static $dependent_classes = ['user_role', 'user_password_reset', 'user_group_access'];
 public static $primary_column = "user_id";
 public static $key_column = 'username';
 public static $module = "extension";
 public static $system_info = [
  'name' => 'User',
  'number' => '10022',
  'description' => 'Create & Update User Details',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('user_role', 'user_password_reset'),
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 22
 ];
//  data base variables as stored database column name
 public $field_a = [
  "user_id",
  "username",
  "password",
  "first_name",
  "last_name",
  "email",
  'user_language',
  "phone",
  'hr_employee_id',
  'block_notif_count',
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
//variables used for showing data
 public $initial_search = [
  "user_id",
  "username",
  "first_name",
  "last_name",
  "email"
 ];
 public $column = [
  "user_id",
  "username",
  "first_name",
  "last_name",
  "email"
 ];
 public $requiredField = [
  "username",
  "first_name",
  "last_name",
  "email",
  'password'
 ];
 public $fields_inForm_notInDataBase = [
  "enteredPassword",
  "enteredRePassword",
  "employee_name",
  'identification_id'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
  '_extra_path' => array('form.php?class_name=user_role&mode=9' => 'Role')
 ];
 public $pageTitle = " User  "; //page Title
// public $option_lists = [
////		 'receipt_types' => 'AR_RECEIPT_TYPE',
////		 'po_status' => 'PO_STATUS',
// ];
// public $search_functions = [
//		 'Cost Type' => 'search_bom_cost_type',
//		  ];
 public $user_id;
 public $hr_employee_id;
 public $username;
 public $enteredPassword;
 public $enteredRePassword;
 public $password;
 Public $first_name;
 Public $last_name;
 public $user_language;
 public $phone;
 public $block_notif_count;
 Public $email;
 Public $status;
 Public $date_format;
 Public $theme;
 public $time;
 public $msg;
 public $employee_name;
 public $identification_id;

 public function _before_showing() {
  
 }

 public function _before_save() {
  if ($this->verify_user()) {
   return 1;
  } else {
   return -99;
  }
 }

 Public static function all_languages() {
  $option_header = option_header::find_by_name('SYS_LANGUAGE');
  $type = option_line::find_by_option_id($option_header->option_header_id);
  return $type;
 }

 Public function findBy_userName($username) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE username = :username LIMIT 1";
  $value_a = ['username' => $username];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 Public function findBy_employeeId($employee_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE hr_employee_id = :hr_employee_id LIMIT 1";
  $value_a = ['hr_employee_id' => $employee_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 Public static function find_by_employeeId($employee_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE hr_employee_id = '{$employee_id}' LIMIT 1";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 Public static function find_by_user_name($username) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE username = '{$username}' LIMIT 1";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 Public function findBy_eMail($email) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE email = :email LIMIT 1";
  $value_a = ['email' => $email];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 Public static function find_by_email($email) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE email = '{$email}' LIMIT 1";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 private function _codeThePassword($password) {
  return hash('sha256', crypt($password, 'xjkhrwq$@323sqjheq51234$$'));
 }

 public function authenticate($username = "", $password = "") {
  global $db;
//	$username = $db->escape_value($username);
//	$password = $db->escape_value($password);
////	$password_final = hash("sha256", $password);
  $password_final = $this->_codeThePassword($password);

  $sql = "SELECT * from user 
            WHERE username='{$username}' and password= '{$password_final}' LIMIT 1";
  $result_array = self::find_by_sql($sql);

  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public function full_name() {
  if (isset($this->first_name) && isset($this->last_name)) {
   return $this->first_name . " " . $this->last_name;
  } else {
   return "";
  }
 }

 private function _findPasswordBy_id() {
  $sql = " SELECT * FROM ";
  $sql.= static::$table_name;
  $sql.= " WHERE user_id = :primary_id ";
  $sql.= " LIMIT 1 ";
  $value_a = ['primary_id' => $this->user_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_id($id) {
  global $dbc;
  if (empty($dbc->connection)) {
   return false;
  }
  $sql = " SELECT user_id, username, first_name, last_name, email,  phone, hr_employee_id, user_language,
            block_notif_count,    created_by,    creation_date,  last_update_by,    last_update_date FROM ";
  $sql.= static::$table_name;
  $sql.= " WHERE " . static::$primary_column . "= :primary_id ";
  $sql.= " LIMIT 1 ";
  $stmt = $dbc->connection->prepare(" $sql ");
  $stmt->bindParam(':primary_id', $id);
  $stmt->setFetchMode(PDO::FETCH_INTO, $this);
  try {
   $stmt->execute();
//	 $result = $stmt->fetchObject();
   $result = $stmt->fetch();
  } catch (PDOException $e) {
   $this->msg = "No Records Found" . $e->getMessage();
  }
  if (!empty($result)) { //should not be used. Use only when a copy of the class is required
   return $result;
  } else {
   return gettext("No Records Found!");
  }
 }

 public static function check_email_userName($email, $userName) {
  global $db;
  $email = $db->escape_value($email);
  $sql = "SELECT * FROM user WHERE email='{$email}' OR username ='{$userName}'";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? true : false;
 }

 private function _check_email() {
  $sql = " SELECT * FROM user WHERE email= :email ";
  $value_a = ['email' => $this->email];
  $result_array = $this->findBySql($sql, $value_a);
  return !empty($result_array) ? true : false;
 }

 private function _check_userName() {
  $sql = " SELECT * FROM user WHERE username= :username ";
  $value_a = ['username' => $this->username];
  $result_array = $this->findBysql($sql, $value_a);
  return !empty($result_array) ? true : false;
 }

 public function verify_user() {
  //first check existing or new user 
  if (empty($this->user_id)) {
   If ($this->_check_email()) {
    echo '<div class="message error">E-mail id is already associated with an user id<br/>
     <a href="' . $_SERVER['PHP_SELF'] . '#tabsLine-3">Reset your password</a></div>';
    $returnedData = false;
   } else If ($this->_check_userName()) {
    echo '<div class="message error">Sorry, username is not available.<br/>
     Please try a different user name</div>';
    $returnedData = false;
   } elseif ($this->enteredPassword == $this->enteredRePassword) {
    $this->password = $this->_codeThePassword($this->enteredPassword);
    $returnedData = true;
   }//nonexisting user check 
  }//end of password match
  elseif ((!empty($this->user_id)) && (!empty($this->enteredPassword))) {
   if ($this->enteredPassword == $this->enteredRePassword) {
    $this->password = $this->_codeThePassword($this->enteredPassword);
    $returnedData = true;
   }
  } elseif ((!empty($this->user_id)) && (empty($this->enteredPassword))) {
   $existing_user = new user();
   $existing_user->user_id = $this->user_id;
   $existing_user_i = $existing_user->_findPasswordBy_id();
   $this->password = $existing_user_i->password;
   $returnedData = true;
  }
  return $returnedData;
 }

 public function _after_save() {
  global $si;
  if ($this->user_id) {
   $msg = "New user registration is sucessful!";
   $subject = "User Registrtion @ " . $si->site_name;
   $message = "Dear " . $this->username . '<br> your regitraton is sucessful';
//    $replyto = "From : admin@site.com";
   $to = $this->email;
   $subject = "User Reginstration @" . $si->site_name;
   $message = "<html> <body>Dear " . $this->username . ',<br><br>';
   $message .= "<p>Welcome to " . $si->site_name . ' <br>You can now access the site with your registered user '
    . ' name & password ';
   $message .='<br><br>Thanks<br>' . $si->site_name . '</body></html>';
   $from = "admin@" . $si->site_name;
   $headers = "From: $from\r\n";
   $headers .= "Content-type: text/html\r\n";
   try {
    if (mail($to, $subject, $message, $headers)) {
     $msg = "mail has been sent";
    } else {
     $msg = "mail failed!";
    }//email complete
   } catch (Exception $e) {
    echo "<br>Failed to send e-mail. Error @ class_user @@ " . __LINE__ . $e->getMessage();
   }
  }//new user registration complete
  else {
   $msg = "New user registration Failed!" . mysql_error();
  }// registraion failed
  return $this->msg;
 }

}

$ino_user = new user();
if (!empty($session->user_id)) {
 try {
  $ino_user->findBy_id($session->user_id);
 } catch (Exception $e) {
  echo "<br>Clear cache and try again. Error @user @@ line " . __LINE__ . '<br>' . $e->getMessage();
 }
}
//end of resource class
?>
