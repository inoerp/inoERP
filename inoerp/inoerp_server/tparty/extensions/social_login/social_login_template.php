<?php
$config = array(
 "base_url" => "http://mywebsite.com/path/to/hybridauth/",
 "providers" => array(
  "Google" => array(
   "enabled" => true,
   "keys" => array("id" => "PUT_YOURS_HERE", "secret" => "PUT_YOURS_HERE"),
   "scope" => "https://www.googleapis.com/auth/userinfo.profile " . // optional
   "https://www.googleapis.com/auth/userinfo.email", // optional
   "access_type" => "offline", // optional
   "approval_prompt" => "force", // optional
   "hd" => "domain.com" // optional
 )));

require_once __DIR__ . '/hybridauth/hybridauth/Hybrid/Auth.php';

$hybridauth = new Hybrid_Auth($config);
$adapter = $hybridauth->authenticate("Google");
$user_profile = $adapter->getUserProfile();

?>