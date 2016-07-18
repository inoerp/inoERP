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
 * ec_cart
 * 
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use ec_cart rev only
class ec_cart extends dbObject {

 public static $table_name = "ec_cart";
 public static $primary_column = "ec_cart_id";
 public static $key_column = 'ec_product_id';
 public static $module = "ec";
// public static $js_fileName = 'modules/inv/ec_cart/js/multi_select.js';
 public static $system_info = [
  'name' => 'Cart',
  'number' => '4201',
  'description' => 'Product Cart',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ec',
  'weight' => 1
 ];
 public $field_a = [
  'ec_cart_id',
  'ec_product_id',
  'quantity',
  'price',
  'user_id',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'ec_product_id',
  'quantity',
  'price',
  'user_id',
 ];
 public $fields_inForm_notInDataBase = [
  "product_name",
  'product_description',
  'line_price',
  'sales_price'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
  '_view_path' => 'product.php?'
 ];
 public $pageTitle = " My Cart "; //page Title
 public $ec_cart_id;
 public $ec_product_id;
 public $quantity;
 public $price;
 public $user_id;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $product_name;
 public $product_description;
 public $line_price;
 public $sales_price;

 public function findBy_ec_cart_id_m($ec_cart_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ec_cart_id = ec_cart_id_m ";
  $sql .= " AND ec_cart_id = '{$ec_cart_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_all_by_userId($user_id) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where user_id = '{$user_id}' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }

}

//end of ec_cart class
?>