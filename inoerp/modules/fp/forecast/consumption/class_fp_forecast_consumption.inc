<?php

 class fp_forecast_consumption extends dbObject {

  public static $table_name = "fp_forecast_consumption";
  public static $primary_column = "fp_forecast_consumption_id";
  public static $key_column = 'forecast_consumption';
  public static $module = "fp";
  public $field_a = [
   'fp_forecast_consumption_id',
   'org_id',
   'forecast_consumption',
   'description',
   'status',
   'bucket_type',
   'level',
   'consume_cb',
   'backward_days',
   'forward_days',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'forecast_consumption',
   'description',
  ];
  public $fields_inForm_notInDataBase = [
   'org',
  ];
  public $requiredField = [
   'org_id',
   'forecast_consumption',
  ];
  public $fp_forecast_consumption_id;
  public $org_id;
  public $forecast_consumption;
  public $description;
  public $status;
  public $bucket_type;
  public $level;
  public $consume_cb;
  public $backward_days;
  public $forward_days;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " Forecast consumption ";
  public $message;

   public static function find_by_valuationName_OrgId($valuation_name, $org_id) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE scope_org_id = '{$org_id}'  "
     . " AND valuation_name = '{$valuation_name}' AND status='active'  LIMIT 1 ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

  public function findBy_valuationName_OrgId($valuation_name = '', $org_id = '') {
   $org_id = empty($org_id) ? $this->scope_org_id : $org_id;
   $valuation_name = empty($valuation_name) ? $this->valuation_name : $valuation_name;
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE scope_org_id = '{$org_id}' AND"
     . " valuation_name = '{$valuation_name}' AND status='active'   LIMIT 1 ";

   $result = $this->findBySql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

 }

//end of fp_forecast_consumption class
?>