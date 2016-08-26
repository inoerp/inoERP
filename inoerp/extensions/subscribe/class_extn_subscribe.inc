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
class extn_subscribe extends dbObject {

 public static $table_name = "extn_subscribe";
 public static $module = "sys";
 public static $primary_column = "extn_subscribe_id";
 public static $key_column = "reference_key_name";
 public static $system_info = [
  'name' => 'extn_subscribe',
  'number' => '10039',
  'description' => 'System extn_subscribe',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 1
 ];
 public $field_a = [
  'extn_subscribe_id',
  'reference_key_name',
  'reference_key_value',
  'user_email',
  'user_id',
  'username',
  'unsubscribe_reason',
  'enabled_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'reference_key_name',
  'reference_key_value',
  'user_email',
 ];
 public $requiredField = [
  'reference_key_name',
  'reference_key_value',
  'user_email',
 ];
 public $checkbox = [
  "enabled_cb"
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Subscribe "; //page Title
 public $extn_subscribe_id;
 public $reference_key_name;
 public $reference_key_value;
 public $user_email;
 public $user_id;
 public $username;
 public $unsubscribe_reason;
 public $enabled_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_save() {
  
 }

 public function send_message($topic_link = '') {
  /*
   * 1. Find all registered subscribers
   * 2. Send message to the subscribers
   */
  global $si;
  global $si;
  if (empty($this->reference_key_name) || empty($this->reference_key_value)) {
   throw new Exception('reference_key_name or reference_key_value is missing ');
  }

  $all_subscribers = $this->_find_all_subscibers();
  if ($all_subscribers) {
   foreach ($all_subscribers as $subscriber) {
    $subject = "New Comment @" . $si->site_name;
    $message = "<html> <body>Dear " . $subscriber->username . ',<br><br>';
    $message .= "<p>A new comment is posted to your subscribed topic on <a href='" . HOME_URL . "'>" . $si->site_name . '</a>'
     . ' <br>You can read the comment by visiting below link <br> ';
    $message .= '<a href="' . $topic_link . '">' . $topic_link . '</a><br>';
    $message .= '<br>You can unsubscribe to this topic in my account section of '. $si->site_name . '<br>';
    $message .='<br><br>Thanks<br>' . $si->site_name . '</body></html>';
    $noreply = 'noreply@noreply.org';
    $im = new inomail();
    $im->FromName = $si->site_name;
    $im->addAddress($subscriber->user_email, $subscriber->username);
    $im->addReplyTo($noreply, 'No Reply');
    $im->Subject = $subject;
    $im->Body = $message;
    $im->ino_sendMail();
   }
  }
 }

 private function _find_all_subscibers() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE reference_key_name = :reference_key_name and  reference_key_value = :reference_key_value ";
  $value_a = ['reference_key_name' => $this->reference_key_name, 'reference_key_value' => $this->reference_key_value];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? $result : false;
 }

 public function findBy_subscribeName($subscribe_name) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE subscribe_name = :subscribe_name ";
  $sql = ino_perPageSql_i($sql, 1);

  $value_a = ['obj_class_name' => $subscribe_name];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_subscribeName($subscribe_name) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE subscribe_name = '{$subscribe_name}' ";
  $sql = ino_perPageSql_i($sql, 1);

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_default_subscribe() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE default_cb = 1 ";
  $sql = ino_perPageSql_i($sql, 1);

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_all_enabled_subscribe() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE enabled_cb = 1 ";

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of extn_subscribe class
?>