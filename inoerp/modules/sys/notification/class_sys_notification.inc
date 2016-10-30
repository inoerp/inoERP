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
 * sys_notification
 *
 */
class sys_notification extends dbObject {

 public static $table_name = "sys_notification";
 public static $primary_column = "sys_notification_id";
 public static $key_column = 'notification_type';
 public static $module = "sys";
 public static $system_info = [
  'name' => 'Notification',
  'number' => '9104',
  'description' => 'System Notifications',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 4
 ];
 public static $status_a = [
  'OPEN' => 'Open',
  'CLOSED' => 'Closed'
 ];
 public $notification_action_a = [
  'APPROVE' => 'Approve',
  'REJECT' => 'Reject',
  'FORWARD' => 'Forward',
  'APPROVE_FORWARD' => 'Approve & Forwards',
  'MORE_INFO' => 'Request Info',
 ];
 public static $notification_type_a = [
  'APPROVAL' => 'Approval',
  'FYI' => 'Information Only',
 ];
 public $field_a = [
  'sys_notification_id',
  'notification_type',
  'notification_name',
  'from_user_id',
  'to_user_id',
  "from_user",
  'to_user',
  'to_user_id_all',
  'to_email',
  'cc_email',
  'notification_subject',
  'to_role',
  'access_key',
  'mail_status',
  'start_date',
  'end_date',
  'due_date',
  'responder',
  'responder_comment',
  'reference_key_name',
  'reference_key_value',
  'user_key_name',
  'user_key_value',
  'text_field1',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'sys_notification_id',
  'notification_type',
  'notif_message',
  'to_user_id',
  'status'
 ];

 public $fields_inForm_notInDataBase = [
  'notification_action',
  'ref_doc_stmt'
 ];
 public $requiredField = [
  'notification_type',
  'from_user_id',
 ];
 public $sys_notification_id;
 public $notification_type;
 public $notification_name;
 public $from_user_id;
 public $to_user_id;
 public $to_user_id_all;
 public $to_email;
 public $cc_email;
 public $notification_subject;
 public $to_role;
 public $access_key;
 public $mail_status;
 public $start_date;
 public $end_date;
 public $due_date;
 public $responder;
 public $responder_comment;
 public $reference_key_name;
 public $reference_key_value;
 public $user_key_name;
 public $user_key_value;
 public $text_field1;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $from_user;
 public $to_user;
 public $notification_action;
 public $ref_doc_stmt;
 public $search = [
  '_show_update_path' => 1,
  '_update_path' => 'form.php?class_name=sys_notification',
  '_view_path' => 'form.php?class_name=sys_notification',
  '_update_action_meassge' => 'Approve/Reject',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " HR notifications  "; //page Title

 Public static function notification_name() {
  $option_header = option_header::find_by_name('SYS_NOTIFICATION_NAME');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

//  public function search_pre_populate(){
//   return array('to_user_id' => $_SESSION['user_id']);
//  }

 protected function create_access_key($to_user_id, $reference_key_name, $reference_key_value) {
  $key_segment = $to_user_id . $reference_key_name . $reference_key_value;
  return hash('sha256', crypt($key_segment, 'sdsd232drnrm'));
 }

 public static function find_all_header_levels() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE level = 'HEADER' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_all_line_levels() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE level = 'LINE' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_transactionClass($class) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE type_class = '{$class}' AND status='active'";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public function _before_showing() {

  //view reference statement
  if ((!empty($this->reference_key_name)) && (!empty($this->reference_key_value))) {
   $this->ref_doc_stmt = show_reference_doc($this->reference_key_name, $this->reference_key_value);
  }
  if ($this->status == 'CLOSED') {
   $this->notification_action_a = array(null);
  }
 }

 public function _after_save() {
  if (!empty($this->to_email) && empty($this->mail_status) && !empty($this->sys_notification_id)) {
   //send mail
   $subject = $this->notification_subject;
   $message = $this->text_field1;
   $to = $this->to_email;
   $from = $this->from_user;
   $headers = "From: $from\r\n";
   $headers .= "Content-type: text/html\r\n";
   try {
    if (mail($to, $subject, $message, $headers)) {
     $this->mail_status = 'SENT';
    } else {
     $this->mail_status = 'FAILED';
    }//email complete
   } catch (Exception $e) {
    echo "<br>Failed to send e-mail. Error @ class_user @@ " . __LINE__ . $e->getMessage();
   }
   $this->audit_trial();
   $this->save_onWebForm();
  }

//       $primary_class = $this->reference_key_name;
//    $$primary_class = new $primary_class;
//    if(method_exists($$primary_class, 'notification_action')){
//     call_user_func(array($$primary_class,'notification_action'), $this);
//    }
//   
  if (!empty($this->notification_action)) {
   $primary_class = $this->reference_key_name;
   $$primary_class = new $primary_class;
   if (method_exists($$primary_class, 'notification_action')) {
    call_user_func(array($$primary_class, 'notification_action'), $this);
   }
   $this->status = 'CLOSED';
   $this->audit_trial();
   $this->update($this->sys_notification_id);
  }
 }

 public function find_openNotification_toUserId($to_user_id = '', $status = 'OPEN') {
  $to_user_id = (empty($to_user_id)) ? $_SESSION['user_id'] : $to_user_id;
  $sql = "SELECT * FROM " . self::$table_name;
  $sql .= " WHERE to_user_id = :to_user_id AND status = :status ORDER BY sys_notification_id DESC ";
  $value_a = ['to_user_id' => $to_user_id, 'status' => $status];
  $result = $this->findBySql($sql, $value_a);
  return $result;
 }

 public function all_notification_block() {
  global $ino_user;
  $default_count = !empty($ino_user->block_notif_count) ? $ino_user->block_notif_count : 8;
  $all_notifs = $this->find_openNotification_toUserId();
  $stmt = '<div class="notification_block"><ul>';
  if ($all_notifs) {
   $notif_count = 0;
   foreach ($all_notifs as $notif) {
    $notif_count++;
    if ($notif_count > $default_count) {
     break;
    }
    $stmt .= "<li><a class='notification link' href='form.php?class_name=sys_notification&mode=9&sys_notification_id=" . $notif->sys_notification_id . "'>$notif->notification_subject</a></li>";
   }
  } else {
   $stmt .= "<li>No Open Notification </li>";
  }
  $stmt .= "<li><a class='all_notification link' href='search.php?class_name=sys_notification_user'>" . gettext('View All Notifications') . "</a></li>";
  $stmt .= '</ul></div>';
  return $stmt;
 }

}

//end of sys_notification class
?>
