<?php

 class fp_source_list_header extends dbObject {

  public static $table_name = "fp_source_list_header";
  public static $primary_column = "fp_source_list_header_id";
  public static $dependent_classes = ['fp_source_list_line'];
  public static $key_column = 'source_list';
  public static $module = "fp";
   public static $system_info = [
  'name' => 'Source List',
  'number' => '2508',
  'description' => 'Source List',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('fp_source_list_line'),
  'primary_entity_cb' => '',
  'module_name' => 'fp',
  'weight' => 8
 ];
  public $field_a = [
   'fp_source_list_header_id',
   'org_id',
   'source_list',
   'description',
   'status',
   'source_list_type',
   'ar_customer_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'
  ];
  //variables used for showing data

  public $initial_search = [
   'fp_source_list_header_id',
   'org_id',
   'source_list',
   'description',
   'status',
  ];
  public $column = [
   'fp_source_list_header_id',
   'org_id',
   'source_list',
   'description',
   'status',
   'source_list_type',
  ];
  public $requiredField = [
   'fp_source_list_header_id',
   'source_list',
   'source_list_type',
  ];
  public $fields_inForm_notInDataBase = [
  ];
  public $pageTitle = " Source List - Forecast & Planning  "; //page Title
  public $search = [
   '_show_update_path' => 1,
   '_update_action_meassge' => 'Update',
   '_show_view_path' => 1,
  ];
  public $option_lists = [
   'source_list_type' => 'PO_TYPE',
   'po_status' => 'PO_STATUS',
  ];
  public $fp_source_list_header_id;
  public $org_id;
  public $source_list;
  public $description;
  public $status;
  public $source_list_type;
  public $ar_customer_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;

  Public static function source_list_type() {
   $option_header = option_header::find_by_name('FP_SOURCE_LIST_TYPE');
   $ol = option_line::find_by_option_id($option_header->option_header_id);
   return $ol;
  }

  public static function find_by_sourceListType($lisType) {
   global $db;
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE source_list_type = :source_list_type";
   $value_a = ['source_list_type' => $lisType];
   $result = $db->findBySql($sql, $value_a);
   return !empty($result) ? $result : false;
  }

  public static function find_all_demandPlan() {
   return self::find_by_sourceListType('DEMAND_PLAN');
  }

  public function findAll_forecastLines_byHeaderId($header_id = '') {
   if (!empty($header_id)) {
    $this->fp_source_list_header_id = $header_id;
   }
   $srll = new fp_source_list_line();
   $srll_i = $srll->findBy_parentId($this->fp_source_list_header_id);

   $count = 1;
   foreach ($srll_i as $forecast) {
    if (!empty($forecast)) {
//		$fcl = new fp_forecast_line();
//		$fcl_i = $fcl->findBy_parentId($forecast->source_list_id);
     $fcl_i = fp_forecast_line_date::find_by_forecastHeaderId($forecast->source_list_id);
     if ($count == 1) {
      $all_demand = $fcl_i;
     } else {
      $all_demand = array_merge($all_demand, $fcl_i);
     }
    }
    $count++;
   }
   return $all_demand;
  }

 }

//end of source_list class
?>