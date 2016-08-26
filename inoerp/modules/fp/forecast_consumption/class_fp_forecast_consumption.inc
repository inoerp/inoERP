<?php

/**
 * inoERP 
 *
 * Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * fp_forecast_consumption 
 * Forecast conumption us used to track the total demand and remaining forecast
 * Contains all fp_forecast_consumption information, such as - fp_forecast_consumption_id, fp_forecast_group_id , quantity, sd_so_line_id
 * 
 */
class fp_forecast_consumption extends dbObject {

 public static $table_name = "fp_forecast_consumption";
 public static $primary_column = "fp_forecast_consumption_id";
 public static $key_column = 'fp_forecast_line_id';
 public static $module = "fp";
 public static $system_info = [
  'name' => 'Forecast Consumption',
  'number' => '2503',
  'description' => 'Forecast Consumption',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fp',
  'weight' => 3
 ];
 public $field_a = [
  'fp_forecast_consumption_id',
  'fp_forecast_group_id',
  'fp_forecast_line_date_id',
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
  'sd_so_line_id',
 ];
 public $fp_forecast_consumption_id;
 public $fp_forecast_group_id;
 public $fp_forecast_line_id;
 public $fp_forecast_line_date_id;
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
 private $_forward_days;
 private $_backward_days;
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
  'Forecast Start Date' => 'search_date',
  'Offset Days' => 'search_offset_days',
 ];
 public $prg_forecast_consumption_details = [
  'name' => 'Forecast Consumption',
  'description' => 'Manual Forecast Consumption',
 ];

 public static function find_consumedQty_bySoLineId_groupId($sd_so_line_id, $fp_forecast_group_id) {
  $sql = " SELECT SUM(quantity) total_consumed FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE sd_so_line_id = '{$sd_so_line_id}' "
   . " AND quantity > 0  "
   . " AND fp_forecast_group_id = '{$fp_forecast_group_id}'  ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_overConsumedQty_bySoLineId_groupId($sd_so_line_id, $fp_forecast_group_id) {
  $sql = " SELECT SUM(quantity) total_consumed FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE sd_so_line_id = '{$sd_so_line_id}' "
   . " AND quantity < 0  "
   . " AND fp_forecast_group_id = '{$fp_forecast_group_id}'  ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_valuationName_OrgId($valuation_name, $org_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE scope_org_id = '{$org_id}'  "
   . " AND valuation_name = '{$valuation_name}' AND status='active'  ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_valuationName_OrgId($valuation_name = '', $org_id = '') {
  $org_id = empty($org_id) ? $this->scope_org_id : $org_id;
  $valuation_name = empty($valuation_name) ? $this->valuation_name : $valuation_name;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE scope_org_id = '{$org_id}' AND"
   . " valuation_name = '{$valuation_name}' AND status='active'  ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 private function _consume_updateLineDate($fp_forecast_line_id, $fp_forecast_line_date_id, $sd_so_line_id, $qty) {
  global $dbc;
  $fpc = new fp_forecast_consumption();
  $fld = new fp_forecast_line_date();
  $fpc->fp_forecast_group_id = $this->fp_forecast_group_id;
  $fpc->fp_forecast_line_id = $fp_forecast_line_id;
  $fpc->fp_forecast_line_date_id = $fp_forecast_line_date_id;
  $fpc->sd_so_line_id = $sd_so_line_id;
  $fpc->quantity = $qty;
  $fpc->audit_trial();

  $fld->findBy_id($fp_forecast_line_date_id);
  $fld->current_quantity = $fld->current_quantity - $qty;
  $fld->audit_trial();
  try {
   pa($fpc);
   $fpc->save();
   $fld->save();
  } catch (Exception $e) {
   $dbc->rollback = true;
   $this->message .= "<br>Failed to update forecast consumption . Error @ fp_forecast_consumption @@ line " . __LINE__ . '<br>' . $e->getMessage();
  }
 }

 private function _find_and_remove_connsumption($so_line, $qty_tobe_removed) {
  $return_b = false;
  //find forecast on date
  $fct_on_date = fp_forecast_line_date::find_by_ItemId_groupId_date($so_line->item_id_m, $this->fp_forecast_group_id, $so_line->schedule_ship_date);
  if ($fct_on_date) {
   foreach ($fct_on_date as $fct_line_date) {
    //nothing to consume...continue
    if (empty($fct_line_date->original_quantity)) {
     continue;
    }
    //remove as available
    if (($fct_line_date->original_quantity >= abs($qty_tobe_removed))) {
     $this->_consume_updateLineDate($fct_line_date->fp_forecast_line_id, $fct_line_date->fp_forecast_line_date_id, $so_line->sd_so_line_id, $qty_tobe_removed);
     $return_b = true;
    } else {
     $qty_tobe_removed += $fct_line_date->original_quantity;
     $this->_consume_updateLineDate($fct_line_date->fp_forecast_line_id, $fct_line_date->fp_forecast_line_date_id, $so_line->sd_so_line_id, -$fct_line_date->original_quantity);
    }
   }
  }

  if ($return_b) {
   return;
  }

  //backward consumption
  $ssd1 = new DateTime($so_line->schedule_ship_date);
  $ssd1->sub(new DateInterval('P' . $this->_backward_days . 'D'));
  $ssd_l = $ssd1->format('Y-m-d');
  $fct_before_date1 = fp_forecast_line_date::find_by_ItemId_groupId_dateRange($so_line->item_id_m, $this->fp_forecast_group_id, $ssd_l, $so_line->schedule_ship_date);
  if ($fct_before_date1) {
   foreach ($fct_before_date1 as $fct_line_date1) {
    //nothing to consume...continue
    if (empty($fct_line_date1->original_quantity)) {
     continue;
    }
    //consume as available
    if (($fct_line_date1->original_quantity >= abs($qty_tobe_removed))) {
     $this->_consume_updateLineDate($fct_line_date1->fp_forecast_line_id, $fct_line_date->fp_forecast_line_date_id, $so_line->sd_so_line_id, $qty_tobe_removed);
     $return_b = true;
    } else {
     $qty_tobe_removed += $fct_line_date1->original_quantity;
     $this->_consume_updateLineDate($fct_line_date1->fp_forecast_line_id, $fct_line_date->fp_forecast_line_date_id, $so_line->sd_so_line_id, -$fct_line_date1->original_quantity);
    }
   }
  }

  if ($return_b) {
   return;
  }

  //forward consumption
  $ssd2 = new DateTime($so_line->schedule_ship_date);
  $ssd2->add(new DateInterval('P' . $this->_forward_days . 'D'));
  $ssd_u = $ssd2->format('Y-m-d');
  $fct_after_date = fp_forecast_line_date::find_by_ItemId_groupId_dateRange($so_line->item_id_m, $this->fp_forecast_group_id, $so_line->schedule_ship_date, $ssd_u);
  if ($fct_after_date) {
   foreach ($fct_after_date as $fct_line_date2) {
    //nothing to consume...continue
    if (empty($fct_line_date2->original_quantity)) {
     continue;
    }
    //consume as available
    if (!($fct_line_date2->original_quantity >= abs($qty_tobe_removed))) {
     $this->_consume_updateLineDate($fct_line_date2->fp_forecast_line_id, $fct_line_date2->fp_forecast_line_date_id, $so_line->sd_so_line_id, $qty_tobe_removed);
     $return_b = true;
    } else {
     $qty_tobe_removed += $fct_line_date2->original_quantity;
     $this->_consume_updateLineDate($fct_line_date2->fp_forecast_line_id, $fct_line_date2->fp_forecast_line_date_id, $so_line->sd_so_line_id, -$fct_line_date2->current_quantity);
    }
   }
  }
 }

 private function _consume_all_orders_ofitem($all_lines) {
  /*
   * For each SO line, find if there is any forecast_line_date entry for the item & date combination.
   * If found, create the consumption details ; If sufficient forecast not found then over consume it - for reporting.
   * Update Consume_quantity the forecast_line_date
   */
  global $dbc;
  if (!$all_lines) {
   return;
  }
  foreach ($all_lines as $so_line) {

   $cont_loop = false;
   $existing_consumed_qty = self::find_consumedQty_bySoLineId_groupId($so_line->sd_so_line_id, $this->fp_forecast_group_id);
   if ($existing_consumed_qty) {
    $qty_tobe_consumed = $so_line->line_quantity - $existing_consumed_qty->total_consumed;
    if ($qty_tobe_consumed == 0) {
     continue;
    }
    if ($qty_tobe_consumed < 0) {
     $this->_find_and_remove_connsumption($so_line, $qty_tobe_consumed);
     continue;
    }
   } else {
    $qty_tobe_consumed = $so_line->line_quantity;
   }
   if ($cont_loop) {
    continue;
   }

   //find forecast on date
   $fct_on_date = fp_forecast_line_date::find_by_ItemId_groupId_date($so_line->item_id_m, $this->fp_forecast_group_id, $so_line->schedule_ship_date);
   if ($fct_on_date) {
    foreach ($fct_on_date as $fct_line_date) {
     //nothing to consume...continue
     if (!($fct_line_date->current_quantity > 0)) {
      continue;
     }
     //consume as available
     if (($fct_line_date->current_quantity >= $qty_tobe_consumed)) {
      $this->_consume_updateLineDate($fct_line_date->fp_forecast_line_id, $fct_line_date->fp_forecast_line_date_id, $so_line->sd_so_line_id, $qty_tobe_consumed);
      $cont_loop = true;
      continue;
     } else {
      $qty_tobe_consumed = $qty_tobe_consumed - $fct_line_date->current_quantity;
      $this->_consume_updateLineDate($fct_line_date->fp_forecast_line_id, $fct_line_date->fp_forecast_line_date_id, $so_line->sd_so_line_id, $fct_line_date->current_quantity);
     }
    }
   }

   if ($cont_loop) {
    continue;
   }

   //backward consumption
   $ssd1 = new DateTime($so_line->schedule_ship_date);
   $ssd1->sub(new DateInterval('P' . $this->_backward_days . 'D'));
   $ssd_l = $ssd1->format('Y-m-d');
   $fct_before_date1 = fp_forecast_line_date::find_by_ItemId_groupId_dateRange($so_line->item_id_m, $this->fp_forecast_group_id, $ssd_l, $so_line->schedule_ship_date);
   if ($fct_before_date1) {
    foreach ($fct_before_date1 as $fct_line_date1) {
     //nothing to consume...continue
     if (!($fct_line_date1->current_quantity > 0)) {
      continue;
     }
     //consume as available
     if (($fct_line_date1->current_quantity >= $qty_tobe_consumed)) {
      $this->_consume_updateLineDate($fct_line_date1->fp_forecast_line_id, $fct_line_date->fp_forecast_line_date_id, $so_line->sd_so_line_id, $qty_tobe_consumed);
      $cont_loop = true;
      continue;
     } else {
      $qty_tobe_consumed = $qty_tobe_consumed - $fct_line_date1->current_quantity;
      $this->_consume_updateLineDate($fct_line_date1->fp_forecast_line_id, $fct_line_date->fp_forecast_line_date_id, $so_line->sd_so_line_id, $fct_line_date1->current_quantity);
     }
    }
   }

   if ($cont_loop) {
    continue;
   }

   //forward consumption
   $ssd2 = new DateTime($so_line->schedule_ship_date);
   $ssd2->add(new DateInterval('P' . $this->_forward_days . 'D'));
   $ssd_u = $ssd2->format('Y-m-d');
   $fct_after_date = fp_forecast_line_date::find_by_ItemId_groupId_dateRange($so_line->item_id_m, $this->fp_forecast_group_id, $so_line->schedule_ship_date, $ssd_u);
   if ($fct_after_date) {
    foreach ($fct_after_date as $fct_line_date2) {
     //nothing to consume...continue
     if (!($fct_line_date2->current_quantity > 0)) {
      continue;
     }
     //consume as available
     if (($fct_line_date2->current_quantity >= $qty_tobe_consumed)) {
      $this->_consume_updateLineDate($fct_line_date2->fp_forecast_line_id, $fct_line_date2->fp_forecast_line_date_id, $so_line->sd_so_line_id, $qty_tobe_consumed);
      $cont_loop = true;
      continue;
     } else {
      $qty_tobe_consumed = $qty_tobe_consumed - $fct_line_date2->current_quantity;
      $this->_consume_updateLineDate($fct_line_date2->fp_forecast_line_id, $fct_line_date2->fp_forecast_line_date_id, $so_line->sd_so_line_id, $fct_line_date2->current_quantity);
     }
    }
   }

   if ($cont_loop) {
    continue;
   }

   //over consumption
   $fc_oc = new fp_forecast_consumption();
   $existing_oc = self::find_overConsumedQty_bySoLineId_groupId($so_line->sd_so_line_id, $this->fp_forecast_group_id);
   if ($existing_oc) {
    $fc_oc->quantity = -($qty_tobe_consumed - abs($existing_oc->total_consumed));
   } else {
    $fc_oc->quantity = -($qty_tobe_consumed);
   }
   if ($fc_oc->quantity == 0) {
    continue;
   }
   $fc_oc->fp_forecast_group_id = $this->fp_forecast_group_id;
   $fc_oc->sd_so_line_id = $so_line->sd_so_line_id;
   $fc_oc->audit_trial();
   try {
    $fc_oc->save();
   } catch (Exception $e) {
    $dbc->rollback = true;
    $this->message .= "<br>Failed to update forecast over consumption . Error @ fp_forecast_consumption @@ line " . __LINE__ . '<br>' . $e->getMessage();
   }
  }
 }

 private function _do_forecast_consumption() {
  /* Find all items available for consumption
   * For each item find out all the sales order line as per entered parameters
   * 
   */
  $all_forecasted_items = fp_forecast_group::find_all_items($this->fp_forecast_group_id);
  $fp_forecast_group_i = fp_forecast_group::find_by_id($this->fp_forecast_group_id);
  $this->_backward_days = $fp_forecast_group_i->backward_days;
  $this->_forward_days = $fp_forecast_group_i->forward_days;
  if (!empty($this->date_from)) {
   $date_from = new DateTime($this->date_from);
   if (!empty($this->offset_days)) {
    $date_from->add(new DateInterval('P' . $this->offset_days . 'D'));
   }
   $this->date_from = $date_from->format('Y-m-d');
  }
  foreach ($all_forecasted_items as $item_d) {

   switch ($this->consume_orders) {
    case 'all_orders' :
     $all_lines = sd_so_line::find_by_orgId_itemId_ssd($this->_org_id, $item_d->item_id_m);
     $this->_consume_all_orders_ofitem($all_lines);
     break;

    case 'orders_from_date' :
     $all_lines = sd_so_line::find_by_orgId_itemId_ssd($this->_org_id, $item_d->item_id_m, $this->date_from);
     $this->_consume_all_orders_ofitem($all_lines);
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
  }

  if (!empty($parameters['org_id'][0])) {
   $this->_org_id = $org_id = $parameters['org_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $org_id;
  } else if (!empty($this->fp_forecast_group_id)) {
   $this->_org_id = $org_id = fp_forecast_group::find_by_id($fp_forecast_group_id)->org_id;
   $this->message .= '<br> Error! : No org entered. Using org_id from forecast group';
  }

  if (!empty($parameters['consume_orders'][0])) {
   $this->consume_orders = $parameters['consume_orders'][0];
   $this->message .= '<br> Entered consume_orders value is : ' . $this->consume_orders;
   if ($this->consume_orders == 'orders_from_date') {
    if (!empty($parameters['user_entered_date'][0])) {
     $this->date_from = $parameters['user_entered_date'][0];
     $this->message .= '<br> Using user eneted date for  consumption ' . $this->date_from;
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
   $this->message .= "<br>Forecast consumption is Successfullycompleted";
  } catch (Exception $e) {
   $this->message .= "<br>Forecast consumption failed!" . $e->getMessage();
  }

  return $this->message;
 }

}

//end of fp_forecast_consumption class
?>