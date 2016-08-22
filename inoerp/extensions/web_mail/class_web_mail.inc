<?php

/**
 * inoERP
 *
 * @copyright   2015 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * mail_form
 * Contains all the mail_form information, such as - mail_form_id, type, description,  mail_form_name, etc.
 * 
 */
class web_mail extends dbObject {

 public static $key_column = 'email_id';
 public $description;
 public $email_id;
 public $cc_email;
 public $bcc_email;
 public $subject;
 public $send_me_copy_cb;
 public $create_comment_cb;
 public $reference_table;
 public $reference_id;
 public static $after_save_message = "Mail is Successfully sent";

 public function _before_save() {
  global $si, $ino_user;
  if (!empty($_POST['email_id'][0]) && !empty($_POST['subject'][0]) && !empty($_POST['message'][0])) {
   $this->reference_table = $_POST['reference_table'][0];
   $this->reference_id = $_POST['reference_id'][0];
   echo '<div class="message">';
   $im = new inomail();
   $full_name = $ino_user->last_name . ', ' . $ino_user->first_name;
   $im->FromName = $full_name;
   $im->addAddress($_POST['email_id'][0]);
   $im->addReplyTo($ino_user->email, $full_name);
   if (!empty($_POST['send_me_copy_cb'][0])) {
    $im->addAddress($ino_user->email);
   }
   $im->Subject = $_POST['subject'][0];
   $im->Body = $_POST['message'][0];
   try {
    $im->ino_sendMail();
    if (!empty($_POST['create_comment_cb'][0])) {
     $this->_write_comment($ino_user->ino_user_id, $_POST['message'][0], $_POST['subject'][0]);
    }
    echo self::$after_save_message;
   } catch (Exception $e) {
    echo "<br>Failed to send mail. Error @ web_mail @@ line " . __LINE__ . '<br>' . $e->getMessage();
   }
   echo '</div>';
   return 10;
  } else {
   echo "<br>Failed to send mail. email/subject/message is missing <br>Error @ web_mail @@ line " . __LINE__;
   echo '</div>';
  }
 }

 protected function _write_comment($comment_by, $comment_msg, $comment_sub = '') {
  global $dbc;
  $comment = new extn_comment();
  $comment->reference_table = $this->reference_table;
  $comment->reference_id = $this->reference_id;
  $comment->comment_by = $comment_by;
  $comment->comment = 'Email Body <br> <br>' . $comment_msg;
  $comment->subject = 'Email Comment - ' . $comment_sub;
  $comment->published_cb = 1;
  $comment->save();
  $dbc->confirm();
 }

 public static function show_adrees_details_inLine(&$mail_form) {
  if (empty($mail_form)) {
   return;
  }
  $show_adrees_details = $mail_form->mail_form . '<br>' . $mail_form->postal_code . ','
   . $mail_form->country . '<br>' . $mail_form->phone
   . $mail_form->email . '<br>' . $mail_form->website;
  return $show_adrees_details;
 }

}

?>
