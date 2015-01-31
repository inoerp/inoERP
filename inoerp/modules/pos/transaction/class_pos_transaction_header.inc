<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * pos_transaction_header
 * Contains all the pos_transaction_header information, such as - price_list, module_name, description,  currency_code, etc.
 * 
 */
class pos_transaction_header extends dbObject {

 public static $table_name = "pos_transaction_header";
 public static $primary_column = "pos_transaction_header_id";
 public static $dependent_classes = ['pos_transaction_line'];
 public static $key_column = "terminal_name";
 public static $module = "pos";
 public static $dont_show_save_msg = true;
 public static $system_info = [
  'name' => 'POS Transaction',
  'number' => '9402',
  'description' => 'Point Of Sale Transaction',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'dependent_class' => array('pos_transaction_line'),
  'primary_entity_cb' => '',
  'module_name' => 'pos',
  'weight' => 2
 ];
 public $field_a = [
  'pos_transaction_header_id',
  'terminal_name',
  'currency_code',
  'header_amount',
  'tax_amount',
  'discount_amount',
  'total_amount',
  'description',
  'ar_customer_id',
  'ar_customer_site_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $checkbox = [
  'allow_mutli_currency_cb'
 ];
 public $initial_search = [
  'pos_transaction_header_id',
 ];
 public $requiredField = [
  'terminal_name'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Point Of Sales "; //page Title
 public $pos_transaction_header_id;
 public $terminal_name;
 public $currency_code;
 public $header_amount;
 public $tax_amount;
 public $discount_amount;
 public $total_amount;
 public $description;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

// function __construct() {
//	global $dbc;
//	$sql_fields = " SHOW COLUMNS FROM  " . self::$table_name;
//	$prepare = $dbc->connection->prepare($sql_fields);
//	$prepare->execute();
//	$this->field_a = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
// }

 public static function profile_pos_transaction_org() {
  $line_data_array = [];
  $line_data_array['line_key'] = 'org_id';
  $line_data_array['line_desc'] = 'org';
  $line_data_array['line_values'] = org::find_all_inventory();
  return $line_data_array;
 }

}

//end of path class
?>
