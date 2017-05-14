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
 * inv_lot_onhand
 * 
 */
 class inv_lot_onhand extends inv_lot_number {

  public static $table_name = "inv_lot_onhand";
  public static $primary_column = "inv_lot_onhand_id";
  public static $parent_primary_column = "inv_lot_number_id";
  public static $key_column = "item_id_m";
  public static $module = "inv";
   public static $system_info = [
  'name' => 'Lot Onhand',
  'number' => '2110',
  'description' => 'Item Lot Onhand',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 10
 ];
  public $field_a = [
   'inv_lot_onhand_id',
   'onhand_id',
   'lot_quantity',
   'inv_lot_number_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'
  ];
  public $initial_search = [
   'inv_lot_onhand_id',
   'onhand_id',
   'inv_lot_number_id',
  ];
  public $column = [
   'inv_lot_onhand_id',
   'onhand_id',
   'inv_lot_number_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'
  ];
  public $requiredField = [
   'onhand_id',
   'inv_lot_number_id',
   'lot_quantity'
  ];
  public $fields_inForm_notInDataBase = [
   'lot_number',
   'org',
   'subinventory',
   'locator',
   'item_number',
   'item_description',
   'org_name'
  ];
  public $pageTitle = " lot onhands  "; //page Title
  public $inv_lot_onhand_id;
  public $onhand_id;
  public $inv_lot_number_id;
  public $lot_quantity;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_dat;
  public $lot_number;
  public $org;
  public $subinventory;
  public $locator;
  public $item_number;
  public $item_description;
  public $org_name;

  public function _before_save() {
   
  }

  public function findBy_lotID_invOnhandId() {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE onhand_id = :onhand_id AND inv_lot_number_id = :inv_lot_number_id ";
   $sql = ino_perPageSql_i($sql, 1);
   $value_a = ['onhand_id' => $this->onhand_id, 'inv_lot_number_id' => $this->inv_lot_number_id];
   $result = $this->findBySql($sql, $value_a);
   return !empty($result) ? array_pop($result) : false;
  }

  public static function find_by_lotID_invOnhandId($onhand_id, $inv_lot_number_id) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE onhand_id = '{$onhand_id}' AND inv_lot_number_id = '{$inv_lot_number_id}' ";
   $sql = ino_perPageSql_i($sql, 1);
   $result = self::find_by_sql($sql);
   return !empty($result) ? ($result) : false;
  }

  public static function find_by_invlotNumberId($inv_lot_number_id) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE inv_lot_number_id = '{$inv_lot_number_id}'  ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? ($result) : false;
  }

  public static function find_by_OnhandId($onhand_id) {
   $sql = " SELECT * FROM 
      inv_lot_onhand ilo,
      onhand_v,
      inv_lot_number iln
      WHERE onhand_v.onhand_id = ilo.onhand_id
      AND iln.inv_lot_number_id = ilo.inv_lot_number_id

";
   $sql .= " AND onhand_v.onhand_id = '{$onhand_id}' ";
   $result = self::find_by_sql($sql);
      return !empty($result) ? ($result) : false;
  }
  
  

 }

//end of path class
?>