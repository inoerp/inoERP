<?php
ini_set("display_errors", 1);
/**
* HybridAuth
* http://hybridauth.sourceforge.net | http://github.com/hybridauth/hybridauth
* (c) 2009-2014, HybridAuth authors | http://hybridauth.sourceforge.net/licenses.html 
*/

// ------------------------------------------------------------------------
//	HybridAuth End Point
// ------------------------------------------------------------------------

require_once realpath( dirname( __FILE__ ) )  . "/Hybrid/Auth.php";
require_once realpath( dirname( __FILE__ ) )  . "/Hybrid/Endpoint.php";

Hybrid_Endpoint::process();