<?php
$home_dir = dirname(__FILE__);
$filepath    = str_replace('\\', '/', dirname(__FILE__));
$docroot = rtrim($_SERVER['DOCUMENT_ROOT'], '/');
$filedir = str_replace($docroot, '', $filepath);
$home_url =  "http://".$_SERVER['HTTP_HOST']."$filedir/";

defined('HOME_DIR')  ? null : define('HOME_DIR', $home_dir);
defined('HOME_URL')  ? null : define("HOME_URL", $home_url);
?>
