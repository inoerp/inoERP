<?php
error_reporting(-1);
ini_set('display_errors', 'On');
/**
* HybridAuth
* http://hybridauth.sourceforge.net | http://github.com/hybridauth/hybridauth
* (c) 2009-2015, HybridAuth authors | http://hybridauth.sourceforge.net/licenses.html
*/

// ------------------------------------------------------------------------
//	HybridAuth End Point
// ------------------------------------------------------------------------

require_once(__DIR__. "/Hybrid/Auth.php" );
require_once( __DIR__. "/Hybrid/Endpoint.php" );

Hybrid_Endpoint::process();
