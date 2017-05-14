<?php

 class inv_serial_transaction extends inv_serial_number {
  public static $system_info = [
  'name' => 'Serial Transaction',
  'number' => '2136',
  'description' => 'Inventory Serial Transaction',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('inv_intorg_transfer_line'),
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 6
 ];
  
  public static $table_name = "inv_serial_transaction";
  public static $primary_column = "inv_serial_transaction_id";
  public static $parent_primary_column = "inv_serial_number_id";
  public static $key_column = "item_id_m";
  public static $module = "inv";

  public $field_a = [
   'inv_serial_transaction_id',
   'inv_transaction_id',
   'inv_serial_number_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'
  ];
  public $initial_search = [
   'inv_serial_transaction_id',
   'inv_transaction_id',
   'inv_serial_number_id',
  ];
  public $column = [
   'inv_serial_transaction_id',
   'inv_transaction_id',
   'inv_serial_number_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'
  ];
  public $requiredField = [
   'inv_transaction_id',
   'inv_serial_number_id',
  ];
  public $fields_inForm_notInDataBase = [
   'serial_number',
   'org',
   'subinventory',
   'locator',
   'item_number',
   'item_description'
  ];
  public $pageTitle = " Serial Transactions  "; //page Title
  public $inv_serial_transaction_id;
  public $inv_transaction_id;
  public $inv_serial_number_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_dat;
  public $serial_number;
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
   $result =self::find_by_sql($sql);
   return !empty($result) ? ($result) : false;
  }
  
    public static function find_by_invSerialNumberId($inv_serial_number_id) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE inv_serial_number_id = '{$inv_serial_number_id}'  ";
   $result =self::find_by_sql($sql);
   return !empty($result) ? ($result) : false;
  }

 }

//end of path class
?>