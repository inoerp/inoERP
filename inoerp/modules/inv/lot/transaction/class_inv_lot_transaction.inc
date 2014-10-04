<?php

 class inv_lot_transaction extends dbObject {

  public static $table_name = "inv_lot_transaction";
  public static $primary_column = "inv_lot_transaction_id";
  public static $parent_primary_column = "inv_lot_number_id";
  public static $key_column = "item_id_m";
  public static $module = "inv";

  public $field_a = [
   'inv_lot_transaction_id',
   'inv_transaction_id',
   'inv_lot_number_id',
   'lot_quantity',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'
  ];
  public $initial_search = [
   'inv_lot_transaction_id',
   'inv_transaction_id',
   'inv_lot_number_id',
  ];
  public $column = [
   'inv_lot_transaction_id',
   'inv_transaction_id',
   'inv_lot_number_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'
  ];
  public $requiredField = [
   'inv_transaction_id',
   'inv_lot_number_id',
   'lot_quantity'
  ];
  public $fields_inForm_notInDataBase = [
   'lot_number',
   'org',
   'subinventory',
   'locator',
   'item_number',
   'item_description'
  ];
  public $pageTitle = " lot Transactions  "; //page Title
  public $inv_lot_transaction_id;
  public $inv_transaction_id;
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


  public function _before_save() {

  }
  
  
  public static function find_by_invTransactionId($inv_transaction_id) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE inv_transaction_id = '{$inv_transaction_id}'  ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? ($result) : false;
  }
  
    public static function find_by_invlotNumberId($inv_lot_number_id) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE inv_lot_number_id = '{$inv_lot_number_id}'  ";
   $result =self::find_by_sql($sql);
   return !empty($result) ? ($result) : false;
  }

 }

//end of path class
?>