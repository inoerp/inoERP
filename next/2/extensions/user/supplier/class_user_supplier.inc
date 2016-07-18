<?php

 class user_supplier extends dbObject {

  public static $table_name = "user_supplier";
  public static $primary_column = "user_supplier_id";
  public static $key_column = 'user_id';
  public static $module = "extension";
  public $field_a = [
   'user_supplier_id',
   'user_id',
   'supplier_id',
   'supplier_site_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'user_id',
   'supplier_id',
  ];
  public $requiredField = [
   'user_id',
   'supplier_id',
  ];
  public $fields_inForm_notInDataBase = [
   "username",
   "first_name",
   "last_name",
  ];
  public $user_supplier_id;
  public $user_id;
  public $supplier_id;
  public $supplier_site_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $username;
  Public $first_name;
  Public $last_name;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " User Supplier Associations  "; //page Title

  Public static function find_by_userId($user_id) {
   $sql = " SELECT * FROM " . self::$table_name . " WHERE user_id = '{$user_id}' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

 }

//end of user_supplier class
?>