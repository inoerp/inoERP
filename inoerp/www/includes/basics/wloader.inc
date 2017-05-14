<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


require_once (__DIR__.'/../../../inoerp_server/includes/functions/functions.inc');

$www_dir = dirname(__FILE__). '/../../';
defined('WWW_DIR') ? null : define('WWW_DIR', $www_dir);


$filepath = str_replace('\\', '/', dirname(__FILE__).'/../../');
$docroot = rtrim($_SERVER['DOCUMENT_ROOT'], '/');
$filedir = str_replace($docroot, '', $filepath);
$protocol_g = ino_protocol(); 
$home_url = $protocol_g . $_SERVER['HTTP_HOST'] . "$filedir";
defined('HOME_URL') ? null : define("HOME_URL", $home_url);

/*Applicable only for IIS server
 * 1. Comment all the above lines (from line 3 to line 11)
 * 2. Uncomment below 3 line and modify the HOME_DIR and HOME_URL value
 */
//$protocol_g = ino_protocol();
//defined('HOME_DIR') ? null : define("HOME_DIR", 'C:\inetpub\wwwroot\inoerp');
//defined('HOME_URL') ? null : define("HOME_URL", 'http://localhost/inoerp/');