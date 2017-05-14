<?php

include_once __DIR__ . '/../../tparty/PHPMailer/class.phpmailer.php';
include_once __DIR__ . '/../../tparty/PHPMailer/class.smtp.php';
include_once __DIR__ . '/../../tparty/PHPMailer/class.pop3.php';
include_once __DIR__ . '/../basics/settings/mailsettings.inc';

class inomail extends PHPMailer {

 public function ino_sendMail($igonre_error = false) {
  $this->Priority = 3; // Highest priority - Email priority (1 = High, 3 = Normal, 5 =   low)
  $this->CharSet = 'UTF-8';
  $this->Encoding = '8bit';
  $this->ContentType = 'text/html; charset=utf-8\r\n';
  $this->WordWrap = 900; // RFC 2822 Compliant for Max 998 characters per line
  IF (defined("SMTP_HOST")) {
   $this->isSMTP();                                      // Set mailer to use SMTP
   $this->Host = SMTP_HOST;  // Specify main and backup SMTP servers
   $this->SMTPAuth = true;                               // Enable SMTP authentication
   $this->Username = SMTP_USERNAME;                 // SMTP username
   $this->Password = SMTP_PASSWORD;                           // SMTP password
   $this->SMTPSecure = 'tls';                            // Enable TLS encryption, `ssl` also accepted
   $this->Port = SMTP_PORT;
   $this->SMTPAuth = true;
//   $this->SMTPDebug   = 2;  
   $this->From = SMTP_FROMEMAIL; //Your email adress 
   $this->isHTML(TRUE);
  }

  if (!$this->send() && (!$igonre_error)) {
   echo '<div role="alert" class="alert alert-warning error alert-dismissible">'
   . '<button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>'
   . gettext('Message could not be sent.');
   echo 'Mailer Error: ' . $this->ErrorInfo . '</div>';
  } else {
   $this->SmtpClose();
  }
 }

}

?>
