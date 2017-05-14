<?php

require_once __DIR__ . "/../../../../../inoerp_server/includes/functions/functions.inc";
require_once __DIR__ . '/../../../../../inoerp_server/define_const.inc';
defined('DS') ? null : define('DS', DIRECTORY_SEPARATOR);

defined('SHOW_COTENT_LIST') ? null : define('SHOW_COTENT_LIST', 0); //show content list when requested content not found 1 for true 2 for false

/* ---------------------Dont Update anything Below-------------------------------------- */
//Basic Paths 
defined('INC_PATH') ? null : define('INC_PATH', HOME_DIR . DS . 'includes');
defined('INO_DATE_FORMAT') ? null : define('INO_DATE_FORMAT', 'Y-m-d');
defined('INO_DATE_TIME_FORMAT') ? null : define('INO_DATE_TIME_FORMAT', 'Y-m-d H:i:s');
defined('PROJECT_DIR') ? null : define('PROJECT_DIR', realpath('./'));
defined('LOCALE_DIR') ? null : define('LOCALE_DIR', HOME_DIR . '/locale');
defined('DEFAULT_LOCALE') ? null : define('DEFAULT_LOCALE', 'en_US');
defined('NUM_ROUND') ? null : define('NUM_ROUND', 5);
defined('INC_BASICS') ? null : define('INC_BASICS', INC_PATH . DS . 'basics');
defined('INC_CLASS') ? null : define('INC_CLASS', INC_PATH . DS . 'general_class');
defined('INC_MODULE') ? null : define('INC_MODULE', HOME_DIR . DS . 'modules');
defined('INC_EXTENSIONS') ? null : define('INC_EXTENSIONS', HOME_DIR . DS . 'extensions');
defined('INC_TPARTY') ? null : define('INC_TPARTY', HOME_DIR . DS . 'tparty');
defined('INC_SYSTEMS') ? null : define('INC_SYSTEMS', HOME_DIR . DS . 'modules' . DS . 'system');
defined('INC_SYS') ? null : define('INC_SYS', HOME_DIR . DS . 'modules' . DS . 'sys');
defined('INC_ORGS') ? null : define('INC_ORGS', HOME_DIR . DS . 'modules' . DS . 'org');
defined('INC_INV') ? null : define('INC_INV', HOME_DIR . DS . 'modules' . DS . 'inv');


//load core objects
require_once(INC_BASICS . DS . 'settings' . DS . "dbsettings.php");
defined('DB_SERVER') ? null : define("DB_SERVER", "");
defined('DB_USER') ? null : define("DB_USER", "");
defined('DB_PASS') ? null : define("DB_PASS", "");
defined('DB_NAME') ? null : define("DB_NAME", "");

require_once(INC_CLASS . DS . "class_dbc.inc");

 
//require_once(INC_CLASS . DS . "class.session.inc");
require_once(INC_CLASS . DS . "class.form.inc");
require_once(INC_CLASS . DS . "class_inoform.inc");

require_once __DIR__ . '/../../../../../inoerp_server/locale/gettext.inc';
$locale = (isset($_SESSION['lang'])) ? $_SESSION['lang'] : DEFAULT_LOCALE;
$encoding = 'UTF-8';
T_setlocale(LC_MESSAGES, $locale);
$domain = 'messages';
T_bindtextdomain($domain, LOCALE_DIR);
T_bind_textdomain_codeset($domain, $encoding);
T_textdomain($domain);
?>