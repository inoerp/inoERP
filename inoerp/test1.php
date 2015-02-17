<?php 
// define constants
define('PROJECT_DIR', realpath('./'));
define('LOCALE_DIR', 'C:\smartview\www\inoerp\locale');
define('DEFAULT_LOCALE', 'hi_IN');

require_once('locale/gettext.inc');

$supported_locales = array('en_US', 'hi_IN', 'de_CH','es_ES');
$encoding = 'UTF-8';

$locale = (isset($_GET['lang']))? $_GET['lang'] : DEFAULT_LOCALE;

//var_dump($locale);die();

// gettext setup
T_setlocale(LC_MESSAGES, $locale);
// Set the text domain as 'messages'
$domain = 'messages';
bindtextdomain($domain, LOCALE_DIR);
// bind_textdomain_codeset is supported only in PHP 4.2.0+
if (function_exists('bind_textdomain_codeset'))
bind_textdomain_codeset($domain, $encoding);
textdomain($domain);

echo gettext("HELLO_WORLD");

?>