<?php

/**
 * HybridAuth
 * http://hybridauth.sourceforge.net | http://github.com/hybridauth/hybridauth
 * (c) 2009-2015, HybridAuth authors | http://hybridauth.sourceforge.net/licenses.html
 */
// ----------------------------------------------------------------------------------------
//	HybridAuth Config file: http://hybridauth.sourceforge.net/userguide/Configuration.html
// ----------------------------------------------------------------------------------------
//return
//		array(
//			"base_url" => "http://localhost/hybridauth-git/hybridauth/",
//			"providers" => array(
//				// openid providers
//				"OpenID" => array(
//					"enabled" => true
//				),
//				"Yahoo" => array(
//					"enabled" => true,
//					"keys" => array("key" => "", "secret" => ""),
//				),
//				"AOL" => array(
//					"enabled" => true
//				),
//				"Google" => array(
//					"enabled" => true,
//					"keys" => array("id" => "", "secret" => ""),
//				),
//				"Facebook" => array(
//					"enabled" => true,
//					"keys" => array("id" => "", "secret" => ""),
//					"trustForwarded" => false
//				),
//				"Twitter" => array(
//					"enabled" => true,
//					"keys" => array("key" => "", "secret" => ""),
//					"includeEmail" => false
//				),
//				// windows live
//				"Live" => array(
//					"enabled" => true,
//					"keys" => array("id" => "", "secret" => "")
//				),
//				"LinkedIn" => array(
//					"enabled" => true,
//					"keys" => array("key" => "", "secret" => "")
//				),
//				"Foursquare" => array(
//					"enabled" => true,
//					"keys" => array("id" => "", "secret" => "")
//				),
//			),
//			// If you want to enable logging, set 'debug_mode' to true.
//			// You can also set it to
//			// - "error" To log only error messages. Useful in production
//			// - "info" To log info and error messages (ignore debug messages)
//			"debug_mode" => false,
//			// Path to file writable by the web server. Required if 'debug_mode' is not false
//			"debug_file" => "",
//);


$sl_home_url = HOME_URL . 'tparty/extensions/social_login/hybridauth/';

$providers_a = [];
$all_providers = extn_social_login::find_all();
foreach ($all_providers as $k => $sp) {
 switch ($sp->provider_name) {

  case 'Facebook':
   $providers_a['Facebook'] = ['enabled' => true, 'keys' => ['id' => $sp->slid, 'secret' => $sp->sl_secret], "trustForwarded" => false];
   break;

  case 'Google':
   $providers_a['Google'] = ['enabled' => true, 'keys' => ['id' => $sp->slid, 'secret' => $sp->sl_secret]];
   break;

  case 'Yahoo':
   $providers_a['Yahoo'] = ['enabled' => true, 'keys' => ['key' => $sp->slid, 'secret' => $sp->sl_secret]];
   break;

  default:
   break;
 }
}
return array(
 "base_url" => $sl_home_url,
 'providers' => $providers_a
);
