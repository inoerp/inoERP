<?php

class mdm_price_list_header extends dbObject {

 public static $table_name = "mdm_price_list_header";
 public static $primary_column = "mdm_price_list_header_id";
 public static $dependent_classes = ['mdm_price_list_line'];
 public static $key_column = "price_list";
 public static $module = "mdm";
 public static $module_a = [
		 'PO' => 'Purchasing',
		 'SD' => 'Sales & Distribution'
 ];
 public $field_a = [
		 'mdm_price_list_header_id',
		 'price_list',
		 'module_name',
		 'currency_code',
		 'description',
		 'status',
		 'allow_mutli_currency_cb',
		 'currency_conversion_type',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 
 public $checkbox = [
		 'allow_mutli_currency_cb'
 ];
 public $initial_search = [
		 'mdm_price_list_header_id',
		 'price_list',
		 'module_name',
		 'currency_code',
 ];
 public $column = [
		 'mdm_price_list_header_id',
		 'price_list',
		 'module_name',
		 'currency_code',
		 'description',
		 'status',
 ];
 public $requiredField = [
		 'price_list',
		 'module_name',
		 'currency_code',
		 'status',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Price List "; //page Title
 public $mdm_price_list_header_id;
 public $price_list;
 public $module_name;
 public $currency_code;
 public $description;
 public $status;
 public $allow_mutli_currency_cb;
 public $currency_conversion_type;
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

 public function __set($name, $value) {
	$this->$name = $value;
 }

 Public static function validation_types() {
	$header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
	$option_line = new option_line();
	$lines = $option_line->findBy_parentId($header->option_header_id);
	return $lines;
 }

}

//end of path class
?>
