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
class ino_user extends dbObject {

 public static $table_name = "ino_user";
 public static $dependent_classes = ['user_role', 'user_password_reset', 'user_group_access'];
 public static $primary_column = "ino_user_id";
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
 public static $debug_mode_a = [
		 '1' => 'Disable',
		 '2' => 'Enable',
		 '3' => 'Enable With Details',
 ];
//  data base variables as stored database column name
 public $field_a = [
		 "ino_user_id",
		 "username",
		 "password",
		 "first_name",
		 "last_name",
		 "email",
		 'user_language',
		 "phone",
		 'hr_employee_id',
		 'ar_customer_id',
		 'lms_student_id',
		 'supplier_id',
		 'block_notif_count',
		 'use_personal_db_cb',
		 'image_file_id',
		 'default_theme',
		 'auth_provider_id',
		 'auth_provider_name',
		 'mandatory_field_color',
		 'heading_color',
		 'content_color',
		 'bg_image_file_id',
		 'show_bg_image_cb',
		 'bg_opacity',
		 'use_personal_color_cb',
		 'debug_mode',
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
//variables used for showing data
 public $initial_search = [
		 "ino_user_id",
		 "username",
		 "first_name",
		 "last_name",
		 "email"
 ];
 public $column = [
		 "ino_user_id",
		 "username",
		 "first_name",
		 "last_name",
		 "email",
		 "phone",
		 'hr_employee_id',
		 'ar_customer_id',
		 'supplier_id',
		 'block_notif_count',
		 'use_personal_db_cb',
		 'image_file_id',
		 'default_theme',
		 'debug_mode',
 ];
 public $requiredField = [
		 "username",
		 "first_name",
		 "last_name",
		 "email"
 ];
 public $fields_inForm_notInDataBase = [
		 "enteredPassword",
		 "enteredRePassword",
		 "employee_name",
		 'identification_id',
		 'address_id',
		 'customer_name',
		 'supplier_name',
		 'notify_user_cb'
 ];
 public $checkbox = [
		 "use_personal_db_cb"
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
 public $ino_user_id;
 public $hr_employee_id;
 public $lms_student_id;
 public $username;
 public $enteredPassword;
 public $enteredRePassword;
 public $password;
 Public $first_name;
 Public $last_name;
 public $user_language;
 public $phone;
 public $block_notif_count;
 public $use_personal_db_cb;
 public $image_file_id;
 Public $email;
 Public $status;
 public $ar_customer_id;
 public $supplier_id;
 public $heading_color;
 public $content_color;
 public $mandatory_field_color;
 public $use_personal_color_cb;
 public $bg_image_file_id;
 public $show_bg_image_cb;
 public $bg_opacity;
 Public $date_format;
 Public $theme;
 public $default_theme;
 public $debug_mode;
 public $time;
 public $msg;
 public $employee_name;
 public $identification_id;
 public $address_id;
 public $customer_name;
 public $supplier_name;
 public $auth_provider_id;
 public $auth_provider_name;
 public $notify_user_cb;
 public $student_name;

 public function _before_showing() {
	
 }

 public function _before_save() {
	try {
	 $this->verify_user();
	 return 1;
	} catch (Exception $e) {
//   echo '<div role="alert" class="alert alert-warning error alert-dismissible">'
//   . '<button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>' . $e->getMessage().'</div>';
	 return -99;
	}
 }

 Public static function all_languages() {
	$option_header = option_header::find_by_name('SYS_LANGUAGE');
	if (empty($option_header)) {
	 return false;
	}
	$type = option_line::find_by_option_id($option_header->option_header_id);
	return $type;
 }

 Public function findBy_userName($username) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE username = :username ";
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$sql .= ' AND ' . ino_perPageSql(1);
		break;

	 default:
		$sql .= ino_perPageSql(1);
		break;
	}
	$value_a = ['username' => $username];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 Public function findBy_employeeId($employee_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE hr_employee_id = :hr_employee_id ";
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$sql .= ' AND ' . ino_perPageSql(1);
		break;

	 default:
		$sql .= ino_perPageSql(1);
		break;
	}
	$value_a = ['hr_employee_id' => $employee_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 Public static function find_by_employeeId($employee_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE hr_employee_id = '{$employee_id}' ";
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$sql .= ' AND ' . ino_perPageSql(1);
		break;

	 default:
		$sql .= ino_perPageSql(1);
		break;
	}
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_providerName_and_provierId() {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE auth_provider_name = :auth_provider_name AND auth_provider_id = :auth_provider_id ";
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$sql .= ' AND ' . ino_perPageSql(1);
		break;

	 default:
		$sql .= ino_perPageSql(1);
		break;
	}
	$value_a = ['auth_provider_name' => $this->auth_provider_name, 'auth_provider_id' => $this->auth_provider_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 Public static function find_by_user_name($username) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE username = '{$username}' ";
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$sql .= ' AND ' . ino_perPageSql(1);
		break;

	 default:
		$sql .= ino_perPageSql(1);
		break;
	}
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_pop($result) : false;
 }

 Public function findBy_eMail($email) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE email = :email ";
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$sql .= ' AND ' . ino_perPageSql(1);
		break;

	 default:
		$sql .= ino_perPageSql(1);
		break;
	}
	$value_a = ['email' => $email];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 Public static function find_by_email($email) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE email = '{$email}' ";
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$sql .= ' AND ' . ino_perPageSql(1);
		break;

	 default:
		$sql .= ino_perPageSql(1);
		break;
	}
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_pop($result) : false;
 }

 private function _codeThePassword($password) {
//  return hash('sha256', crypt($password, 'xjkhrwq$@323sqjheq51234$$'));
	return password_hash($password, PASSWORD_BCRYPT);
 }

 public function authenticate($username = "", $password = "") {
//  $password_final = $this->_codeThePassword($password);
	$ret = false;
	$sql = "SELECT * from ino_user 
            WHERE username=:username ";
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$sql .= ' AND ' . ino_perPageSql(1);
		break;

	 default:
		$sql .= ino_perPageSql(1);
		break;
	}
	$value_a = ['username' => $username];
	$result_array = $this->findBySql($sql, $value_a);
	if ($result_array) {
	 if (password_verify($password, $result_array[0]->password)) {
		$ret = $result_array[0];
	 } else {
		$ret = false;
	 }
	}

	return $ret;
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
	$sql.= " WHERE ino_user_id = :primary_id ";
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$sql .= ' AND ' . ino_perPageSql(1);
		break;

	 default:
		$sql .= ino_perPageSql(1);
		break;
	}
	$value_a = ['primary_id' => $this->ino_user_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_id($id) {
	global $dbc;
	if (empty($dbc->connection)) {
	 return false;
	}
	$sql = " SELECT ino_user_id, username, first_name, last_name, email,  phone, hr_employee_id, user_language,
           default_theme, debug_mode, block_notif_count,  ar_customer_id, supplier_id,  created_by,    creation_date, 
            last_update_by,    last_update_date , auth_provider_id, auth_provider_name, image_file_id, use_personal_db_cb, mandatory_field_color,
            heading_color, content_color ,  use_personal_color_cb, bg_image_file_id, show_bg_image_cb, bg_opacity FROM ";
	$sql.= static::$table_name;
	$sql.= " WHERE " . static::$primary_column . "= :primary_id ";
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$sql .= ' AND ' . ino_perPageSql(1);
		break;

	 default:
		$sql .= ino_perPageSql(1);
		break;
	}
	$stmt = $dbc->connection->prepare(" $sql ");
	$stmt->bindParam(':primary_id', $id);
	$stmt->setFetchMode(PDO::FETCH_INTO, $this);
	try {
	 $stmt->execute();
	 $result = $stmt->fetch();
//   $result = $stmt->fetchAll(PDO::FETCH_CLASS, self::$table_name);
	} catch (PDOException $e) {
	 return gettext("No Records Found!") . $e->getMessage();
	}

	return !empty($result) ? $result : null;
 }

 public static function find_by_ColumnNameVal($columnName, $columnVal, $dependent_fields = '', $hidden_fields = '') {
	$sql = "SELECT ino_user_id, username, first_name, last_name, email,  phone, hr_employee_id, user_language,
           default_theme, debug_mode, block_notif_count,  ar_customer_id, supplier_id,  created_by,    creation_date, 
            last_update_by,    last_update_date , image_file_id , use_personal_db_cb FROM " . static::$table_name . " where " . $columnName . " LIKE  '%{$columnVal}%'  ";
	$result_array = static::find_by_sql($sql);
	return !empty($result_array) ? ($result_array) : false;
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
	$returnedData = false;
	//first check existing or new user 
	if (empty($this->ino_user_id)) {
	 If ($this->_check_email()) {
		$returnedData = false;
		throw new Exception('E-mail id is already associated with an user id<br/>
     <a href="' . $_SERVER['PHP_SELF'] . '#tabsHeader-3">Reset your password</a>');
	 } else If ($this->_check_userName()) {
		$returnedData = false;
		throw new Exception('Sorry, username is not available.<br/>Please try a different user name');
	 } elseif ($this->enteredPassword == $this->enteredRePassword) {
		$this->password = $this->_codeThePassword($this->enteredPassword);
		$returnedData = true;
	 } else {
		throw new Exception('Sorry, two different passwords are entered');
	 }//nonexisting user check 
	}//end of password match
	elseif ((!empty($this->ino_user_id)) && (!empty($this->enteredPassword))) {
	 if ($this->enteredPassword == $this->enteredRePassword) {
		$this->password = $this->_codeThePassword($this->enteredPassword);
		$returnedData = true;
	 }
	} elseif ((!empty($this->ino_user_id)) && (empty($this->enteredPassword))) {
	 $existing_user = new ino_user();
	 $existing_user->ino_user_id = $this->ino_user_id;
	 $existing_user_i = $existing_user->_findPasswordBy_id();
	 $this->password = $existing_user_i->password;
	 $returnedData = true;
	}
	return $returnedData;
 }

 public function _after_save() {
	global $si;
	if ($this->ino_user_id) {
	 $msg = "New user registration is sucessful!";
	 if ($this->notify_user_cb) {
		$this->_notify_user();
	 }
	}//new user registration complete
	else {
	 $msg = "New user registration Failed!" . mysql_error();
	}// registraion failed
	//verify & create new address

	if ((!empty($_POST['addr_usage_type'][0]))) {
	 $this->_create_address();
	}
	return $this->msg;
 }

 private function _notify_user() {
	global $si;
	$subject = "User Registration @" . $si->site_name;
	$message = "<html> <body>Dear " . $this->username . ',<br><br>';
	$message .= "<p>Welcome to " . $si->site_name . ' <br>You can now access the site with your registered user '
					. ' name & password ';
	$message .='<br><br>Thanks<br>' . $si->site_name . '</body></html>';
	$im = new inomail();
	$im->FromName = $si->site_name;
	$im->addAddress($this->email, $this->username);
	$im->addReplyTo($si->email, 'User Registration');
	$im->Subject = $subject;
	$im->Body = $message;
	$im->ino_sendMail(true);
 }

 private function _create_address() {
	//create address
	$addr = new address();
	$addr->address_name = $this->username . '-' . $_POST['addr_address_name'][0];
	$addr->phone = $_POST['addr_phone'][0];
	$addr->email = $_POST['addr_email'][0];
	$addr->website = $_POST['addr_website'][0];
	$addr->country = $_POST['addr_country'][0];
	$addr->postal_code = $_POST['addr_postal_code'][0];
	$addr->usage_type = $_POST['addr_usage_type'][0];
	$addr->address = $_POST['addr_address'][0];
	try {
	 $addr->save();
	} catch (Exception $e) {
	 echo "<br>Unable to add new address. Error @ user @@ " . __LINE__ . $e->getMessage();
	}


	//created address reference
	if ($addr->address_id) {
	 $add_ref = new address_reference();
	 $add_ref->reference_table = 'ino_user';
	 $add_ref->reference_id = $this->ino_user_id;
	 $add_ref->address_id = $addr->address_id;
	 try {
		$add_ref->save();
		echo "<br> New address is Successfully added";
	 } catch (Exception $e) {
		echo "<br>Unable to add new address. Error @ user @@ " . __LINE__ . $e->getMessage();
	 }
	}
 }

}

$ino_user = new ino_user();
if (!empty($_SESSION['user_id']) && empty($_GET['ino_user_id'])) {
 try {
	$ino_user_i = $ino_user->findBy_id($_SESSION['user_id']);
	$ino_user = $ino_user_i;
 } catch (Exception $e) {
	echo "<br>Clear cache and try again. Error @user @@ line " . __LINE__ . '<br>' . $e->getMessage();
 }
}


if (!empty($ino_user) && !empty($ino_user->use_personal_color_cb)) {
 if (!empty($ino_user->mandatory_field_color)) {
	$si->mandatory_field_color = $ino_user->mandatory_field_color;
 } else {
	$si->mandatory_field_color = empty($si->mandatory_field_color) ? '#f2dcf3' : $si->mandatory_field_color;
 }

 if (!empty($ino_user->content_color)) {
	$si->content_color = $ino_user->content_color;
 } else {
	$si->content_color = empty($si->content_color) ? '#f2dcf3' : $si->content_color;
 }


 if (!empty($ino_user->heading_color)) {
	$si->heading_color = $ino_user->heading_color;
 } else {
	$si->heading_color = empty($si->heading_color) ? '#f2dcf3' : $si->heading_color;
 }
} else {
// pa($ino_user);
 $si->mandatory_field_color = empty($si->mandatory_field_color) ? '#f2dcf3' : $si->mandatory_field_color;
 $si->content_color = empty($si->content_color) ? '#e9eded' : $si->content_color;
 $si->heading_color = empty($si->heading_color) ? '#0f68a4' : $si->heading_color;
}

if (!empty($si->show_bg_image_cb) && !empty($ino_user->show_bg_image_cb)) {
 $si->bg_image_path = empty($si->bg_image_path) ? null : HOME_URL . $si->bg_image_path;

 if (!empty($ino_user->bg_image_file_id)) {
	require_once(INC_EXTENSIONS . DS . "file" . DS . "class_extn_file.inc");
	$bg_img_file = extn_file::find_by_id($ino_user->bg_image_file_id);
	if (empty($bg_img_file)) {
	 return;
	}
	$si->bg_image_path = HOME_URL . $bg_img_file->file_path . $bg_img_file->file_name;
 }
 if (!empty($ino_user->bg_opacity)) {
	$si->bg_opacity = $ino_user->bg_opacity;
 } else if (empty($si->bg_opacity)) {
	$si->bg_opacity = '0.8';
 }
} else {
 $si->bg_image_path = null;
 $si->bg_opacity = 1;
}



//end of user class
?>
