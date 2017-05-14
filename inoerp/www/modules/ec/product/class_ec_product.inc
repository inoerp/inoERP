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
 * ec_product
 * 
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use ec_product rev only
class ec_product extends dbObject {

 public static $table_name = "ec_product";
 public static $primary_column = "ec_product_id";
 public static $key_column = 'item_id_m';
 public static $module = "ec";
// public static $js_fileName = 'modules/inv/ec_product/js/multi_select.js';
 public static $system_info = [
     'name' => 'eComm Product',
     'number' => '4208',
     'description' => 'eCommerce Products',
     'version' => '0.1.4',
     'db_version' => '1001',
     'mod_version' => '1.1.1',
     'primary_entity_cb' => '',
     'module_name' => 'am',
     'weight' => 1
 ];
 public static $visibility_a = [
     'NOT_STAND_ALONE' => 'Not As a Sigle Product',
     'NOT_STAND_ALONE' => 'Only As a Single Product',
     'ALL' => 'Always',
     'FREE_OFFER' => 'Free Offer',
     'NONE' => 'Not Visible For Sale',
 ];
 public static $status_a = [
     'HOLD' => 'Hold',
     'ENABLED' => 'Enabled',
     'DISABLED' => 'Disabled'
 ];
 public $checkbox = [
     "physical_inventory_cb"
 ];
 public $field_a = [
     'ec_product_id',
     'item_id_m',
     'org_id',
     'product_name',
     'product_description',
     'new_date_trom',
     'new_date_to',
     'status',
     'visibility',
     'tax_code_id',
     'meta_title',
     'meta_keywords',
     'meta_description',
     'price_list_id',
     'list_price',
     'sales_price',
     'sp_from_date',
     'sp_to_date',
     'no_of_view',
     'featured_product_cb',
     'created_by',
     'creation_date',
     'last_update_by',
     'last_update_date',
 ];
 public $initial_search = [
     'product_name',
     'item_id_m',
 ];
 public $requiredField = [
     'item_id_m',
     'org_id',
     'product_name',
 ];
 public $fields_inForm_notInDataBase = [
     "item_number",
     "item_description",
 ];
 public $search = [
     '_show_update_path' => 1,
     '_update_action_meassge' => 'Update',
     '_show_view_path' => 1,
     '_view_path' => 'product.php?'
 ];
 public $pageTitle = " eComm Product "; //page Title
 public $ec_product_id;
 public $item_id_m;
 public $org_id;
 public $product_name;
 public $product_description;
 public $new_date_trom;
 public $new_date_to;
 public $status;
 public $visibility;
 public $tax_code_id;
 public $meta_title;
 public $meta_keywords;
 public $meta_description;
 public $price_list_id;
 public $list_price;
 public $sales_price;
 public $sp_from_date;
 public $sp_to_date;
 public $no_of_view;
 public $featured_product_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $item_number;
 public $item_description;

 public function findBy_ec_product_id_m($ec_product_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ec_product_id = ec_product_id_m ";
  $sql .= " AND ec_product_id = '{$ec_product_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_all_assigned_orgs($ec_product_number) {
  global $db;
  $sql = "SELECT * FROM " .
          self::$table_name .
          " where ec_product_number= '{$ec_product_number}' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }

 public static function find_by_orgId($org_id) {
  global $db;
  $sql = "SELECT * FROM " .
          self::$table_name .
          " where org_id= '{$org_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_similar_products($product_id) {
  $sql = "SELECT ec_product_id , ec.item_id_m , ec.org_id , product_name , product_description, item.item_description,
          item.image_file_id
           FROM 
           ec_product ec,
           category_reference cr,
           item
           WHERE ec.ec_product_id = cr.reference_id
           AND cr.reference_table = 'ec_product'
           AND item.item_id_m = ec.item_id_m
           AND item.org_id = ec.org_id
           AND ec.ec_product_id != '{$product_id}'
           AND cr.category_id IN (
           SELECT DISTINCT(cr.category_id)
           FROM 
           ec_product ec,
           category_reference cr
           WHERE ec.ec_product_id = cr.reference_id
           AND cr.reference_table = 'ec_product'
           AND ec.ec_product_id = '{$product_id}'
           )
 ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_all_feaured_products() {
  $sql = "SELECT ec_product_id , ec.item_id_m , ec.org_id , product_name , product_description, item.item_description,
          item.image_file_id
           FROM 
           ec_product ec,
           item
           WHERE item.item_id_m = ec.item_id_m
           AND item.org_id = ec.org_id
           AND ec.featured_product_cb = '1'
 ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_category_id($category_id, $param = '') {
  $sql = "SELECT DISTINCT(ec.ec_product_id) , ec.item_id_m , ec.org_id , ec.product_name , ec.product_description, item.item_description,
          item.image_file_id, ec.list_price, ec.sales_price
           FROM 
           ec_product ec,
           category_reference cr,
           item ";
  if (!empty($param['sys_catalog_line_id'])) {
   $sql .= ", sys_catalog_value scv";
  }
  $sql .= " WHERE ec.ec_product_id = cr.reference_id
           AND cr.reference_table = 'ec_product'
           AND item.item_id_m = ec.item_id_m
           AND item.org_id = ec.org_id
           AND cr.category_id = '{$category_id}'
 ";
  if (!empty($param['sys_catalog_line_id'])) {
   $sql .= " AND scv.reference_table = 'ec_product'  ";
   $sql .= " AND scv.reference_id = ec.ec_product_id  ";
   $line_id_a = $param['sys_catalog_line_id'];
   $line_id_val_a = $param['sys_catalog_line_id_value'];
   $line_id_val_a_str = "('" . implode("','", $line_id_val_a) . "')";
   $line_id_a_str = "('" . implode("','", $line_id_a) . "')";
   $sql .= " AND scv.line_value IN  $line_id_val_a_str  ";
   $sql .= " AND scv.sys_catalog_line_id IN  $line_id_a_str  ";
  }

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_featured_products_id($category_id) {
  $fp = self::find_by_category_id($category_id);
  if (empty($fp)) {
   $fp = self::find_all_feaured_products();
  }
  return $fp;
 }

 public static function category_menu() {
  $cat = new category();
  $all_categories_arr = $cat->category_explosion_withPCRelation('86');
//  $all_categories = category::parent_category_ofType('PRODUCT');
  $all_categories = array_pop($all_categories_arr);
//  pa($all_categories);
  $stmt = '<div id="hf-nav-1">
      <div class="hf-nav">';
  if (!empty($all_categories)) {
   foreach ($all_categories as $k1 => $v1) {
    $catg_d = category::find_by_id($k1);
    $stmt .= '<ul class="hf-menu">
          <li class="top-li p3">';
    $stmt .= '<a href="' . HOME_URL . 'product.php?category_id=' . $k1 . '" title="' . $catg_d->description . '">' . $catg_d->category . '</a>';
    if (is_array($v1)) {
     $stmt .= '<ul class="sub sub-ul">';
     foreach ($v1 as $k2 => $v2) {
      $catg_d2 = category::find_by_id($k2);
      $stmt .= '<li class="sub">';
      $stmt .= '<h2><a href="' . HOME_URL . 'product.php?category_id=' . $k2 . '" title="' . $catg_d2->description . '">' . $catg_d2->category . '</a></h2>';
      if (is_array($v2)) {
       $stmt .= '<ul>';
       foreach ($v2 as $k3 => $v3) {
        $catg_d3 = category::find_by_id($k3);
        $stmt .= '<li><a href="' . HOME_URL . 'product.php?category_id=' . $k3 . '" title="' . $catg_d3->description . '">' . $catg_d3->category . '</a></li>';
       }
       $stmt .='</ul>';
       $stmt .='</li>';
      } else {
       $stmt .='</li>';
      }
     }
     $stmt .='</ul>';
     $stmt .='</li>';
    } else {
     $stmt .='</li>';
    }
    $stmt .='</ul>';
   }
  }


  $stmt .= '</div></div>';

  return $stmt;
 }

}

//end of ec_product class
?>