<?php

 class view extends dbObject {

  public static $table_name = "view";
  public static $dependent_classes = ['view_path'];
  public static $primary_column = "view_id";
  public static $key_column = 'view_name';
  public static $module = "extension";
  public static $js_fileName = 'modules/po/js/multi_select.js';
  //  data base variables as stored database column name
  public $field_a = [
   "view_id",
   "view_name",
   "description",
   "logical_settings",
   "query_v",
   "select_v",
   "from_v",
   "where_v",
   "order_by",
   "query_end",
   "filters",
   "display_type",
   "page",
   "page_title",
   "page_header",
   "page_footer",
   "use_pager",
   "contents_per_page",
   "path",
   "block",
   "block_title",
   "block_header",
   "block_footer",
   "block_type",
   "block_more",
   "rev_enabled_cb",
   "rev_number",
   "created_by",
   "creation_date",
   "last_update_by",
   "last_update_date"
  ];
// public static $array_field_array =[
//		 "path"
// ];
//variables used for showing data


  public $initial_search = [
   "view_id",
   "view_name",
   "description",
  ];
  public $checkbox = [
   "rev_enabled_cb",
  ];
  public $column = [
   "rev_enabled_cb",
   "view_id",
   "view_name",
   "description",
  ];
  public $base_encoded_array = [
   "logical_settings",
   "query_v"
  ];
  public $requiredField = [
   "view_name",
   "description",
   "query_"
  ];
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " Views "; //page Title
  public $all_table_names;
  public $view_id;
  public $view_name;
  public $logical_settings;
  public $description;
  public $query_v;
  public $select_v;
  public $from_v;
  public $where_;
  public $order_by;
  public $query_end;
  public $filters;
  public $display_type;
  public $page;
  public $page_title;
  public $page_header;
  public $page_footer;
  public $use_pager;
  public $contents_per_page;
  public $path;
  public $block;
  public $block_title;
  public $block_header;
  public $block_footer;
  public $block_type;
  public $block_more;
  public $rev_number;
  public $rev_enabled_cb;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;
  public $msg;
private $_table_schema;
  
  function __construct() {
   global $dbc;
   $sql_fields = " SHOW COLUMNS FROM  " . self::$table_name;
   $prepare = $dbc->connection->prepare($sql_fields);
   $prepare->execute();
   self::$field_array = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
   $this->_table_schema = DB_NAME;
  }

  public function _after_save() {

   if (!empty($_POST['view_path'])) {
    //check the combination of view_id & column name exists
    $path_array = $_POST['view_path'];
    foreach ($path_array as $key => $value) {
     $view_path = new view_path;
     $view_path->view_id = $view->view_id;
     $view_path->column_name = $value;
     $path_array = path::find_by_idColumn_name($value);
     $view_path->path = $path_array->value;
//		echo '<pre>';
//	print_r($view_path);
//	echo '<pre>';
     $viewId_columnName_exists_array = view_path::find_by_columnName_viewId($view_path->column_name, $view_path->view_id);
     if (!empty($viewId_columnName_exists_array) && !empty($viewId_columnName_exists_array->view_path_id)) {
      $view_path->view_path_id = $viewId_columnName_exists_array->view_path_id;
     }
     $view_path->save();
    }
   }
  }

  public function __set($name, $value) {
   $this->$name = $value;
  }

  Public static function view_display_types() {
   $org_header = option_header::find_by_name('VIEW_DISPLAY_TYPE');
   $type = option_line::find_by_option_id($org_header->option_header_id);
   return $type;
  }

  public static function find_all_tables() {
   global $db;
   $query = " SELECT TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE' "
     . " AND TABLE_SCHEMA= '".DB_NAME."' ";
   $result = $db->find_by_sql($query);

   $table_name_array = array();
   foreach ($result as $object) {
    $table_name_array [] = $object->TABLE_NAME;
   }
   return $table_name_array;
  }
  
    public static function count_all_tables() {
   global $db;
   $query = " SELECT count(TABLE_NAME) as table_count from information_schema.tables  "
     . " WHERE TABLE_SCHEMA= '".DB_NAME."' ";
   $result = $db->find_by_sql($query);
   return !empty($result) ? array_pop($result) : null ;
  }

  public static function find_all_tables_gen() {
   global $db;
   $query = " SELECT TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE' "
     . " AND TABLE_SCHEMA= '".DB_NAME."' ";
   $result = $db->find_by_sql($query);

   foreach ($result as $object) {
    yield $object->TABLE_NAME;
   }
  }

  public function findAll_tables() {
   $query = " SELECT TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE' "
     . " AND TABLE_SCHEMA= '".DB_NAME."' ";
   $result = $this->findBySql($query);
   $table_name_array = array();
   foreach ($result as $object) {
    $table_name_array [] = $object->TABLE_NAME;
   }
   return $table_name_array;
  }

  public static function find_columns_of_table($table_name) {
   global $db;
   if (!empty($table_name)) {
    $query = "SHOW COLUMNS FROM $table_name ";
    $result = $db->find_by_sql($query);

    $column_name_array = array();
    foreach ($result as $object) {
     $column_name_array [] = $object->Field;
    }
    return $column_name_array;
   }
  }

  public static function find_all_idColumns() {
   global $db;
   $all_id_columns_array = [];
   $all_tables = self::find_all_tables();
//	pa($all_tables);
   foreach ($all_tables AS $key => $values) {
    if (!empty($values)) {
     $column_name = $values . '_id';
     $query = "SHOW COLUMNS FROM $values WHERE Field = '{$column_name}' ";
     $result = $db->find_by_sql($query);
     if ((count($result) > 0) && (!empty($result[0]->Field))) {
      $all_id_columns_array[] = $result[0]->Field;
     }
    }
   }
//	pa($all_id_columns_array);
   return $all_id_columns_array;
  }

  public static function find_all_idColumns_gen() {
   $all_tables = self::find_all_tables_gen();
   foreach ($all_tables AS $key => $values) {
    if (!empty($values)) {
     $column_name = $values . '_id';
     $query = "SHOW COLUMNS FROM $values WHERE Field = '{$column_name}' ";
     $result = self::find_by_sql($query);
     if ((count($result) > 0) && (!empty($result[0]->Field))) {
      yield $result[0]->Field;
     }
    }
   }
  }

 }

//end of view class
?>