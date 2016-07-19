<?php

 /*
  * textfields
  * numberfields
  * accounfields
  * textarea
  */

 class ino_install {

  public static $table_name = "engine";
  public static $module = "sys";
  public static $primary_column = "engine_id";
  public static $key_column = "obj_class_name";
  //  data base variables as stored database column name
  public $field_a = [
   "ino_install_id",
   "form_name",
   "description",
   "class_name",
   "created_by",
   "creation_date",
   "last_update_by",
   "last_update_date"
  ];
  public $initial_search = [
   "ino_install_id",
   "form_name",
   "description",
   "class_name",
  ];
  public $column = [
   "ino_install_id",
   "form_name",
   "description",
   "class_name",
  ];
  public $numberField = [
  ];
  public $requiredField = [
   "form_name",
   "description",
   "class_name",
  ];
  public $search = [
   '_update_path' => 'form.php?class_name=ino_install',
   '_show_update_path' => 1,
   '_update_action_meassge' => 'Update',
   '_show_view_path' => 1,
  ];
  public $pageTitle = " Install inoERP "; //page Title
  public $option_lists = [
//		 'supplier_type' => 'SUPPLIER_TYPE',
  ];
  public $ino_install_id;
  public $_form_name;
  public $_description;
  public $_class_name;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;
  public $msg;
  public $current_page_path = "";
  public $readonly;
  public $readonly1;
  public $readonly2;
  public $readonly3;
  public $readonly4;

 }

?>