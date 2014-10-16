<?php

 class fp_forecast_line_date extends dbObject {

  public static $table_name = "fp_forecast_line_date";
  public static $primary_column = "fp_forecast_line_date_id";
  public static $parent_primary_column = "fp_forecast_line_id";
  public static $key_column = 'fp_forecast_line_id';
  public static $module = "fp";
  public $field_a = [
   'fp_forecast_line_date_id',
   'fp_forecast_line_id',
   'forecast_date',
   'original_quantity',
   'current_quantity',
   'source',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  //variables used for showing data
  
    public $initial_search = [
   'fp_forecast_line_id',
  ];

  public $requiredField = [
   'fp_forecast_line_id',
   'forecast_date',
   'original_quantity',
   'current_quantity',
  ];
  public $fields_inForm_notInDataBase = [
   'item_description',
   "item_number",
   'uom_id',
  ];
  public $fp_forecast_line_date_id;
  public $fp_forecast_line_id;
  public $forecast_date;
  public $original_quantity;
  public $current_quantity;
  public $source;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $item_number;
  public $item_description;
  public $uom_id;

  public function findBy_lineId_date() {
   $sql = " SELECT * FROM  ";
   $sql .= self::$table_name;
   $sql .= " WHERE fp_forecast_line_id =:fp_forecast_line_id AND forecast_date = :forecast_date LIMIT 1 ";

   $param_a = ['fp_forecast_line_id', 'forecast_date'];
   $value_a = ['fp_forecast_line_id' => $this->fp_forecast_line_id, 'forecast_date' => $this->forecast_date];
   $result = $this->findBy_sql($sql, $param_a, $value_a);
   return !empty($result) ? array_pop($result) : false;
  }

  public function findAll_distinctItems_ofHeader() {
   $sql = "SELECT DISTINCT(item_id_m) FROM " .
     self::$table_name;
   $sql .= " WHERE fp_forecast_header_id =:fp_forecast_header_id ";
   $param_a = ['fp_forecast_header_id'];
   $value_a = ['fp_forecast_header_id' => $this->fp_forecast_header_id];
   $result_array = $this->findBy_sql($sql, $param_a, $value_a);
   return !empty($result_array) ? $result_array : false;
  }

 }

//end of inv_transaction class
?>