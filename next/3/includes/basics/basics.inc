<?php

require_once __DIR__ . "/../functions/functions.inc";
require_once __DIR__ . '/../../define_const.inc';
const DS = DIRECTORY_SEPARATOR;

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
require_once(INC_BASICS . DS . 'settings' . DS . "dbsettings.inc");
defined('DB_SERVER') ? null : define("DB_SERVER", "");
defined('DB_USER') ? null : define("DB_USER", "");
defined('DB_PASS') ? null : define("DB_PASS", "");
defined('DB_NAME') ? null : define("DB_NAME", "");


require_once(INC_CLASS . DS . "class.session.inc");
require_once(INC_CLASS . DS . "class_dbc.inc");
require_once(INC_CLASS . DS . "trait_dbObject_t.inc");
require_once(INC_CLASS . DS . "class_dbObject.inc");
require_once(INC_PATH . DS . 'interface' . DS . "gl_int.inc");
require_once(INC_PATH . DS . 'interface' . DS . "hr_int.inc");

//require_once(INC_CLASS . DS . "class_dbc2.inc");
//require_once(INC_CLASS . DS . "class_dbObject2.inc");
require_once(INC_EXTENSIONS . DS . "site_info" . DS . "class_site_info.inc");
require_once(INC_CLASS . DS . "class.form.inc");
require_once(INC_CLASS . DS . "class_inoform.inc");
require_once(INC_EXTENSIONS . DS . "path" . DS . "class_path.inc");
require_once(INC_CLASS . DS . "class.pagination.inc");
require_once(INC_CLASS . DS . "class_inomail.inc");
require_once(INC_CLASS . DS . "class.search.inc");
require_once(INC_CLASS . DS . "class_ino_exception.inc");
require_once(INC_CLASS . DS . "class_inosave.inc");
require_once(INC_CLASS . DS . "class_downloads.inc");
require_once(INC_CLASS . DS . "class_getsvgimage.inc");
require_once(INC_EXTENSIONS . DS . "engine" . DS . "class_engine.inc");
require_once(INC_EXTENSIONS . DS . "user" . DS . "class.user.inc");
require_once(INC_EXTENSIONS . DS . "user" . DS . "class.user_role.inc");
require_once(INC_EXTENSIONS . DS . "user" . DS . "class_user_group.inc");
require_once(INC_EXTENSIONS . DS . "user" . DS . "class.user_password_reset.inc");
require_once(INC_EXTENSIONS . DS . "user" . DS . "activity" . DS . "class_user_activity_v.inc");
require_once(INC_EXTENSIONS . DS . "user" . DS . "dashboard" . DS . "class_user_dashboard_v.inc");
require_once(INC_EXTENSIONS . DS . "user" . DS . "dashboard" . DS . "config" . DS . "class_user_dashboard_config.inc");
require_once(INC_EXTENSIONS . DS . "user" . DS . "favourite" . DS . "class_user_favourite.inc");
require_once(INC_EXTENSIONS . DS . "role_access" . DS . "class_role_access.inc");
require_once(INC_EXTENSIONS . DS . "user_group_access" . DS . "class_user_group_access.inc");
require_once(INC_EXTENSIONS . DS . "role_path" . DS . "class_role_path.inc");
require_once(INC_EXTENSIONS . DS . "site_search" . DS . "class_extn_site_search.inc");
//require_once(INC_SYS . DS . "program_schedule" . DS . "class_sys_program_schedule.inc");
//require_once(INC_SYS . DS . "program" . DS . "class_sys_program.inc");
require_once(INC_SYS . DS . "option" . DS . "class.option_header.inc");
require_once(INC_SYS . DS . "option" . DS . "class.option_line.inc");
require_once(INC_SYS . DS . "option" . DS . "class.option_detail.inc");
//require_once(INC_SYSTEMS.DS."role".DS."class.role_path.inc");
//require_once(INC_SYS . DS . "value_group" . DS . "class_sys_value_group_header.inc");
//require_once(INC_SYS . DS . "value_group" . DS . "class_sys_value_group_line.inc");
require_once(INC_SYS . DS . "profile" . DS . "class_sys_profile_header.inc");
require_once(INC_SYS . DS . "profile" . DS . "class_sys_profile_line.inc");
require_once(INC_EXTENSIONS . DS . "file" . DS . "class.file.inc");
require_once(INC_EXTENSIONS . DS . "file" . DS . "class.file_reference.inc");
require_once(INC_EXTENSIONS . DS . "image" . DS . "class_extn_image.inc");
require_once(INC_EXTENSIONS . DS . "image" . DS . "class_extn_image_reference.inc");
require_once(INC_EXTENSIONS . DS . "file" . DS . "class_massupload.inc");
require_once(INC_EXTENSIONS . DS . "ino_generic" . DS . "class_ino_generic.inc");
require_once(INC_EXTENSIONS . DS . "page" . DS . "class_page.inc");
require_once(INC_EXTENSIONS . DS . "social_login" . DS . "class_extn_social_login.inc");
require_once(INC_EXTENSIONS . DS . "theme" . DS . "class_extn_theme.inc");
require_once(INC_EXTENSIONS . DS . "comment" . DS . "class.comment.inc");
require_once(INC_EXTENSIONS . DS . "block" . DS . "class_block.inc");
require_once(INC_EXTENSIONS . DS . "block" . DS . "list" . DS . "class_block_list.inc");
require_once(INC_EXTENSIONS . DS . "block" . DS . "class_block_content.inc");
require_once(INC_EXTENSIONS . DS . "block" . DS . "class_block_cache.inc");
require_once(INC_EXTENSIONS . DS . "menu" . DS . "class_extn_menu_header.inc");
require_once(INC_EXTENSIONS . DS . "menu" . DS . "class_extn_menu_line.inc");

//require_once(INC_BASICS.DS."class.dbObject.inc"); 
//load other objects
require_once(INC_ORGS . DS . "class_org.inc");
require_once(INC_ORGS . DS . "class_org_v.inc");
require_once(INC_ORGS . DS . "enterprise" . DS . "class_enterprise.inc");
require_once(INC_ORGS . DS . "legal" . DS . "class_legal.inc");
require_once(INC_ORGS . DS . "business" . DS . "class_business.inc");
require_once(INC_ORGS . DS . "inventory" . DS . "class_inventory.inc");
require_once(INC_ORGS . DS . "address" . DS . "class_address.inc");
require_once(INC_ORGS . DS . "address" . DS . "class_address_reference.inc");
require_once(INC_MODULE . DS . "gl" . DS . "coa" . DS . "class_coa.inc");
require_once(INC_MODULE . DS . "gl" . DS . "coa_combination" . DS . "class_coa_combination.inc");
require_once(INC_MODULE . DS . "gl" . DS . "payment_term" . DS . "class_payment_term.inc");
require_once(INC_MODULE . DS . "gl" . DS . "payment_term" . DS . "class_payment_term_schedule.inc");
require_once(INC_MODULE . DS . "gl" . DS . "payment_term" . DS . "class_payment_term_discount.inc");
require_once(INC_INV . DS . "item" . DS . "class_item.inc");
require_once(INC_MODULE . DS . "inv" . DS . "item" . DS . "class_ra_item.inc");
require_once(INC_MODULE . DS . "inv" . DS . "item" . DS . "class_item_select.inc");
require_once(INC_MODULE . DS . "inv" . DS . "item_relation" . DS . "class_inv_item_relation.inc");
require_once(INC_INV . DS . "onhand" . DS . "class_onhand.inc");
require_once(INC_INV . DS . "onhand" . DS . "class_onhand_v.inc");
require_once(INC_INV . DS . "subinventory" . DS . "class_subinventory.inc");
require_once(INC_INV . DS . "locator" . DS . "class_locator.inc");
require_once(INC_INV . DS . "locator" . DS . "class_locator_v.inc");
require_once(INC_INV . DS . "uom" . DS . "class_uom.inc");
require_once(INC_INV . DS . "transaction_type" . DS . "class_transaction_type.inc");
require_once(INC_MODULE . DS . 'ap' . DS . "supplier" . DS . "class_supplier.inc");
require_once(INC_MODULE . DS . 'ap' . DS . "supplier" . DS . "class_supplier_site.inc");
require_once(INC_MODULE . DS . 'ap' . DS . "supplier_bu" . DS . "class_supplier_bu.inc");
require_once(INC_MODULE . DS . 'ap' . DS . "supplier" . DS . "class_supplier_all_v.inc");
require_once(INC_MODULE . DS . "wip" . DS . "wo" . DS . "class_ra_wip.inc");
require_once(INC_MODULE . DS . "fp" . DS . "mrp_existing" . DS . "class_fp_mrp_existing_supply_v.inc");


require_once(INC_MODULE . DS . "pos" . DS . "tt_with_search" . DS . "class_pos_tt_with_search_header.inc");
require_once(INC_TPARTY . DS . "barcode" . DS . "class_ino_barcode.inc");
require_once(INC_TPARTY . DS . "extensions" . DS . "social_login" . DS . "class_social_login.inc");
//include extensions
//require_once(INC_EXTENSIONS . DS . "contact" . DS . "class_extn_contact.inc");
//require_once(INC_EXTENSIONS . DS . "contact" . DS . "class_extn_contact_reference.inc");
require_once(INC_EXTENSIONS . DS . "content_type" . DS . "class_content_type.inc");
require_once(INC_EXTENSIONS . DS . "content_type" . DS . "class_new_content_type.inc");
require_once(INC_EXTENSIONS . DS . "content_type" . DS . "class_content_type_reference.inc");
require_once(INC_EXTENSIONS . DS . "content" . DS . "class.content.inc");
require_once(INC_EXTENSIONS . DS . "category" . DS . "class_category.inc");
require_once(INC_EXTENSIONS . DS . "category_relation" . DS . "class_category_relation.inc");
require_once(INC_EXTENSIONS . DS . "category" . DS . "class_category_reference.inc");
require_once(INC_EXTENSIONS . DS . "view" . DS . "class.view.inc");
require_once(INC_EXTENSIONS . DS . "view" . DS . "result" . DS . "class_view_result.inc");
require_once(INC_EXTENSIONS . DS . "report" . DS . "class_extn_report.inc");
require_once(INC_EXTENSIONS . DS . "report" . DS . "class_extn_report_path.inc");
require_once(INC_EXTENSIONS . DS . "report" . DS . "result" . DS . "class_extn_report_result.inc");
require_once(INC_EXTENSIONS . DS . "web_tracking" . DS . "class_web_tracking.inc");
require_once(INC_EXTENSIONS . DS . "url_alias" . DS . "class_ext_url_alias.inc");
require_once(INC_EXTENSIONS . DS . "web_contact" . DS . "class_web_contact.inc");
require_once(INC_EXTENSIONS . DS . "web_mail" . DS . "class_web_mail.inc");
require_once(INC_EXTENSIONS . DS . "rating" . DS . "class_extn_rating_values.inc");
require_once(INC_EXTENSIONS . DS . "rating" . DS . "class_extn_rating_control.inc");



require_once __DIR__ . '/../../locale/gettext.inc';
$locale = (isset($_SESSION['lang'])) ? $_SESSION['lang'] : DEFAULT_LOCALE;
$encoding = 'UTF-8';
T_setlocale(LC_MESSAGES, $locale);
$domain = 'messages';
T_bindtextdomain($domain, LOCALE_DIR);
T_bind_textdomain_codeset($domain, $encoding);
T_textdomain($domain);
?>