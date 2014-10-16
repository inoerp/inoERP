<?php

 class fp_forecast_consumption extends dbObject {

  public static $table_name = "fp_forecast_consumption";
  public static $primary_column = "fp_forecast_consumption_id";
  public static $key_column = 'fp_forecast_line_id';
  public static $module = "fp";
  public $field_a = [
   'fp_forecast_consumption_id',
   'fp_forecast_group_id',
   'fp_forecast_line_id',
   'sd_so_line_id',
   'quantity',
   'reason',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public static $consume_orders_a = [
   'all_orders' => 'All Sales Orders',
   'unconsumed_orders' => 'Unconsumed Orders',
   'orders_from_date' => 'Orders From Date',
  ];
  public $initial_search = [
   'fp_forecast_line_id',
   'fp_forecast_consumption_id',
   'sd_so_line_id',
  ];
  public $fields_inForm_notInDataBase = [
   'org',
   'sd_so_header_id',
   'so_number',
   'consume_orders',
   'user_entered_date',
   'use_sys_date_cb',
   'offset_days'
  ];
  public $requiredField = [
   'org_id',
   'fp_forecast_line_id',
   'sd_so_line_id',
  ];
  public $fp_forecast_consumption_id;
  public $fp_forecast_group_id;
  public $fp_forecast_line_id;
  public $sd_so_line_id;
  public $quantity;
  public $reason;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $consume_orders;
  public $user_entered_date;
  public $date_from;
  public $offset_days;
  private $_org_id;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " Forecast consumption ";
  public $message;
  public $prg_forecast_consumption_parameters = [
   'Organization' => 'search_org_name',
   'Forecast Group' => 'search_forecast_group',
   'Consume Orders' => 'search_consume_orders',
   'Start Date' => 'search_date',
   'Offset Days' => 'search_offset_days',
  ];
  public $prg_forecast_consumption_details = [
   'name' => 'Forecast Consumption',
   'description' => 'Manual Forecast Consumption',
  ];

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

  private function _consume_all_orders_ofitem($all_lines) {
   
  }

  private function _do_forecast_consumption() {
   /* Find all items available for consumption
    * For each item find out all the sales order line as per entered parameters
    * Consume each SO as per forecast. If sufficient forecast found then over consume it - for reporting
    */
   $all_forecasted_items = fp_forecast_group::find_all_items($this->fp_forecast_group_id);
   if (!empty($this->date_from)) {
    $date_from = new DateTime($this->date_from);
    if (!empty($this->offset_days)) {
     $date_from->add(new DateInterval('P' . $this->offset_days . 'D'));
    }
    $this->date_from = $date_from->format('Y-m-d');
   }
   foreach ($all_forecasted_items as $item_d) {
    $all_lines = sd_so_line::find_by_itemId_orgId_ssd($this->_org_id, $this->date_from);
    switch ($this->consume_orders) {
     case 'all_orders' :
      $this->_consume_all_orders_ofitem($all_lines);
      break;

     case 'unconsumed_orders' :
      break;

     case 'orders_from_date' :
      break;

     case 'default' :
      break;
    }
   }
  }

  public function prg_forecast_consumption($seralized_parameters) {
   $parameters = unserialize($seralized_parameters);
   $this->message .= '<br> Staring Forecast Consumption ';

   if (!empty($parameters['fp_forecast_group_id'][0])) {
    $fp_forecast_group_id = $this->fp_forecast_group_id = $parameters['fp_forecast_group_id'][0];
    $this->message .= '<br> Entered fp_forecast_group_id is : ' . $fp_forecast_group_id;
   } else {
    $this->message .= '<br> No fp_forecast_group_id found. Using default forecast group of the org & org_id ' . __LINE__;
    if (!empty($parameters['org_id'][0])) {
     $this->_org_id = $org_id = $parameters['org_id'][0];
     $this->message .= '<br> Entered Org Id is : ' . $org_id;
    } else {
     $this->message .= '<br> Error! : No org id found @ fp_forecast_consumption @@ ' . __LINE__;
     return $this->message;
    }
   }

   if (!empty($parameters['consume_orders'][0])) {
    $this->consume_orders = $parameters['consume_orders'][0];
    $this->message .= '<br> Entered consume_orders value is : ' . $consume_orders;
    if ($this->consume_orders == 'orders_from_date') {
     if (!empty($parameters['user_entered_date'][0])) {
      $this->date_from = $parameters['user_entered_date'][0];
      $this->message .= '<br> Using user eneted date for  consumption ' . $date_from;
     } else {
      $this->date_from = current_time(1);
      $this->message .= '<br> Using sys date for  consumption ' . $date_from;
     }
     if (!empty($parameters['offset_days'][0])) {
      $this->offset_days = $parameters['offset_days'][0];
      $this->message .= '<br> Offset days value ' . $offset_days;
     }
    }
   }

   try {
    $this->_do_forecast_consumption();
    $this->message .= "<br>Forecast consumption is sucessfully completed";
   } catch (Exception $e) {
    $this->message .= "<br>Forecast consumption failed!" . $e->getMessage();
   }

   return $this->message;
  }

 }

//end of fp_forecast_consumption class
?>