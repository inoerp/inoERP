<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * hd_ro_header CLass
 * Contains all the hd_svo_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class hd_svo_header extends dbObject {

 public static $table_name = "hd_svo_header";
 public static $dependent_classes = ['hd_svo_line', 'hd_svo_estimates', 'hd_svo_actuals'];
 public static $primary_column = "hd_svo_header_id";
 public static $primary_column2 = "order_number";
 public static $key_column = 'ar_customer_id';
 public static $module = "hd";
 public static $system_info = [
  'name' => 'Service Order',
  'number' => '5111',
  'description' => 'Create & Mainten Service Order',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hd_svo_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 1
 ];
 public $action_a = [
  'APPROVE' => 'Approve',
  'PRINT' => 'Print Estimates',
  'CANCEL' => 'Cancel',
  'CLOSE' => 'Close',
  'CREATE_WO' => 'Create Work Order',
  'COPY_ESTIMATES' => 'Copy Estimates to Actuals',
  'COPY_WO' => 'Copy WO Charges to Actuals',
  'PROCESS_LOGISTICS' => 'Process Logistics',
  'PROCESS_ACTUALS' => 'Process Actuals',
 ];
 public $field_a = [
  'hd_svo_header_id',
  'bu_org_id',
  'hd_service_type_header_id',
  'order_number',
  'hd_service_request_id',
  'promise_date',
  'ar_customer_id',
  'ar_customer_site_id',
  'service_person_employee_id',
  'service_team_id',
  'description',
  'ship_to_id',
  'bill_to_id',
  'item_id_m',
  'inv_serial_number_id',
  'lot_number_id',
  'price_list_header_id',
  'quantity',
  'estimate_amount',
  'doc_currency',
  'prepaid_status',
  'prepaid_amount',
  'currency',
  'payment_term_id',
  'payment_term_date',
  'warrenty_status',
  'escalation',
  'exchange_rate_type',
  'exchange_rate',
  'inventory_org_id',
  'close_date',
  'order_reference_table',
  'order_reference_id',
  'repair_status',
  'estimate_status',
  'primary_sd_so_header_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'hd_service_type_header_id',
  'order_number',
 ];
 public $requiredField = [
  'bu_org_id',
  'hd_service_type_header_id',
  'ar_customer_id',
//  'item_id_m'
 ];
 public $addressField = [
  'ship_to_id',
  'bill_to_id'
 ];
 public $fields_inForm_notInDataBase = [
  'action',
  "customer_name",
  "customer_number",
  "customer_site_name",
  "item_number",
  "item_description",
  'serial_number',
  'lot_number',
  'add_to_order'
 ];
 public $profile_default = [
  'exchange_rate_type' => 'gl_currency_conversion_type',
  'bu_org_id' => 'org_bu_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//  '_extra_path' => array('form.php?class_name=ar_transaction_header&mode=9' => 'Invoice',
//   'form.php?class_name=sd_delivery_header&mode=9' => 'Ship')
 ];
 public $pageTitle = " Service Order "; //page Title
 public $hd_svo_header_id;
 public $bu_org_id;
 public $hd_service_type_header_id;
 public $order_number;
 public $hd_service_request_id;
 public $promise_date;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $service_person;
 public $service_team_id;
 public $service_person_employee_id;
 public $description;
 public $ship_to_id;
 public $bill_to_id;
 public $item_id_m;
 public $inv_serial_number_id;
 public $lot_number_id;
 public $quantity;
 public $estimate_amount;
 public $doc_currency;
 public $prepaid_status;
 public $prepaid_amount;
 public $currency;
 public $payment_term_id;
 public $payment_term_date;
 public $warrenty_status;
 public $escalation;
 public $exchange_rate_type;
 public $exchange_rate;
 public $inventory_org_id;
 public $close_date;
 public $order_reference_table;
 public $order_reference_id;
 public $repair_status;
 public $estimate_status;
 public $price_list_header_id;
 public $primary_sd_so_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $item_number;
 public $item_description;
 public $serial_number;
 public $lot_number;
 public $add_to_order;
 private $_so_header_document_type;

 public function _before_showing() {
  $address = new address();
  if (!empty($this->ship_to_id)) {
   $address_ship_to = $address->findBy_id($this->ship_to_id);
   $this->ship_to_address_name = $address_ship_to->address_name;
   $this->ship_to_address = $address_ship_to->address;
   $this->ship_to_country = $address_ship_to->country;
   $this->ship_to_postal_code = $address_ship_to->postal_code;
   $this->ship_to_phone = $address_ship_to->phone;
  }
  if (!empty($this->bill_to_id)) {
   $address_bill_to = $address->findBy_id($this->bill_to_id);
   $this->bill_to_address_name = $address_bill_to->address_name;
   $this->bill_to_address = $address_bill_to->address;
   $this->bill_to_country = $address_bill_to->country;
   $this->bill_to_postal_code = $address_bill_to->postal_code;
   $this->bill_to_phone = $address_bill_to->phone;
  }
 }

 private function _do_action() {
  switch ($this->action) {
   case 'COPY_ESTIMATES':
    $this->copy_estimates();
    break;

   case 'PROCESS_ACTUALS':
    $this->copy_estimates();
    break;

   case 'PROCESS_LOGISTICS':
    $this->_process_logistics();
    break;

   default :
    break;
  }
 }

 public function _before_save() {
  if (!empty($this->action)) {
   $this->_do_action();
  }

  if (empty($this->so_status)) {
   $this->so_status = 'ENTERED';
  }
 }

 public function copy_estimates() {
  /* 1. Find all lines not copied - status PENDING_IMPORT.
   * 2. Copy all estimates to actuals
   * 3. Change all the estimate line status to IMPORTED.
   */
  if (empty($this->hd_svo_header_id)) {
   return -1;
  }
  $all_estimates_lines = hd_svo_estimates::find_by_headerId_and_status($this->hd_svo_header_id);
  if ($all_estimates_lines) {
   foreach ($all_estimates_lines as $k => $estimates_line) {
    $new_actuals = new hd_svo_actuals();
    foreach ($new_actuals->field_a as $k_a => $v_a) {
     if ((property_exists($estimates_line, $v_a)) && !empty($estimates_line->$v_a)) {
      $new_actuals->$v_a = $estimates_line->$v_a;
     }
    }
    $new_actuals->created_by = $new_actuals->creation_date = null;
    $new_actuals->source = 'ESTIMATES';
    $new_actuals->line_status = 'PENDING_IMPORT';
    try {
     $new_actuals->save();
     $estimate = new hd_svo_estimates();
     $estimate->findBy_id($estimates_line->hd_svo_estimates_id);
     $estimate->line_status = 'IMPORTED';
     $estimate->save();
    } catch (Exception $e) {
     echo "<br>Unable to import estimates to actuals. Error @ line " . __LINE__ . ' of file ' . __FILE__ . '<br>' . $e->getMessage();
    }
   }
  }
 }

 private function _process_logistics() {
  /* 1. Check if primary_Sd_so_header exists ? if not create a new sales order header
   * 2. Find all lines not imported - status PENDING_IMPORT & empty sd_so_line.
   * 2. Add all the lines to the sales order header
   * 3. Update the line status, sd_so_header_id and sd_so_line_id status 
   */

  $all_logistics_lines = hd_svo_line::find_by_headerId_and_status($this->hd_svo_header_id);
  if ($all_logistics_lines) {
   $ser_act_lines = hd_service_activity_line::find_by_headerId_and_buOrgId($all_logistics_lines[0]->service_activity_header_id, $this->bu_org_id);
   if ($ser_act_lines) {
    $this->_so_header_document_type = $ser_act_lines->header_type_id;
   }
  }

  if (empty($this->primary_sd_so_header_id) && !empty($this->_so_header_document_type)) {
   $this->_create_so_header();
  }
  if (empty($this->primary_sd_so_header_id)) {
   return false;
  }
  if ($all_logistics_lines) {
   $so_line_num = 0;
   foreach ($all_logistics_lines as $k => $logistics_line) {
    $so_line_num++;
    if (!empty($logistics_line->sd_so_line_id)) {
     continue;
    }
    $ser_act_line = hd_service_activity_line::find_by_headerId_and_buOrgId($logistics_line->service_activity_header_id, $this->bu_org_id);
    $so_line = new sd_so_line();
    foreach ($so_line->field_a as $k_a => $v_a) {
     if ((property_exists($logistics_line, $v_a)) && !empty($logistics_line->$v_a)) {
      $so_line->$v_a = $logistics_line->$v_a;
     }
    }
    $so_line->sd_so_header_id = $this->primary_sd_so_header_id;
    $so_line->line_status = 'ENTERED';
    $so_line->line_type = $ser_act_line->line_type_id;
    $so_line->shipping_org_id = $logistics_line->inv_org_id;
    $so_line->item_description = item::find_by_item_id_m($so_line->item_id_m)->item_description;
    try {
     if (method_exists($so_line, '_before_save')) {
      $so_line->_before_save();
     }
     $so_line->save();
     if (method_exists($so_line, '_after_save')) {
      $so_line->_after_save();
     }
     $sv_line = new hd_svo_line();
     $sv_line->findBy_id($logistics_line->hd_svo_line_id);
     $sv_line->sd_so_header_id = $so_line->sd_so_header_id;
     $sv_line->sd_so_line_id = $so_line->sd_so_line_id;
     $sv_line->line_status = 'IMPORTED';
     $sv_line->save();
//     pa($so_line);
//     pa($sv_line);
    } catch (Exception $e) {
     echo "<br>Unable to import estimates to logistic lines. Error @ line " . __LINE__ . ' of file ' . __FILE__ . '<br>' . $e->getMessage();
    }
   }
  }
 }

 public function _after_save() {
  if ((!empty($this->hd_svo_header_id)) && empty($this->order_number)) {
   $hd_svo_header_id = $this->hd_svo_header_id;
   $bu_org_id = $this->bu_org_id;
   $so_number = $bu_org_id . '-' . $hd_svo_header_id;
   $this->order_number = $so_number;
   echo '<br/> New SVO number is ' . $so_number;
   $this->update_svoNumber();
  }
 }

 private function update_svoNumber() {
  $sql = " UPDATE " . self::$table_name;
  $sql .= " SET order_number = '{$this->order_number}'  ";
  $sql .= " WHERE hd_svo_header_id = '{$this->hd_svo_header_id}'  ";
  try {
   $this->runSQL($sql);
  } catch (Exception $e) {
   echo "<br>SO Number update failed!" . $e->getMessage();
  }
 }

 private function _create_so_header() {
  global $dbc;
  $sd_so_h = new sd_so_header();
  $sd_so_h->bu_org_id = $this->bu_org_id;
  $sd_so_h->order_source_type = 'SERVICE';
  $sd_so_h->document_type = $this->_so_header_document_type;
  $sd_so_h->doc_currency = $this->doc_currency;
  $sd_so_h->currency = $this->currency;
  $sd_so_h->exchange_rate_type = $this->exchange_rate_type;
  $sd_so_h->exchange_rate = $this->exchange_rate;
  $sd_so_h->ar_customer_id = $this->ar_customer_id;
  $sd_so_h->bill_to_id = $this->bill_to_id;
  $sd_so_h->ship_to_id = $this->ship_to_id;
  $sd_so_h->ar_customer_site_id = $this->ar_customer_site_id;
  $sd_so_h->payment_term_id = $this->payment_term_id;
  $sd_so_h->payment_term_date = $this->payment_term_date;
  $sd_so_h->order_reference_table = 'hd_sv_header';
  $sd_so_h->order_reference_id = $this->hd_svo_header_id;
  try {
   if (method_exists($sd_so_h, '_before_save')) {
    $sd_so_h->_before_save();
   }
   $sd_so_h->save();
   if (method_exists($sd_so_h, '_after_save')) {
    $sd_so_h->_after_save();
   }
   $this->primary_sd_so_header_id = $sd_so_h->sd_so_header_id;
   $this->save();
  } catch (Exception $e) {
   echo "<br>Unable to create SO Header. Error @ line " . __LINE__ . " in file " . __FILE__ . '<br>' . $e->getMessage();
   $dbc->rollback = true;
  }
 }

 public static function instantiate_extra_fields(&$array_of_objects) {
  if (count($array_of_objects) > 0) {
   foreach ($array_of_objects as &$this_object) {
    $customer_details = supplier::find_by_id($this_object->ar_customer_id);
    $this_object->customer_name = $customer_details->customer_name;
    $this_object->customer_number = $customer_details->customer_number;
    $customer_site_details = customer_site::find_by_id($this_object->customer_site_id);
    $this_object->customer_site_name = $customer_site_details->customer_site_name;
   }
  }
  return $array_of_objects;
 }

 Public static function so_types() {
  $option_header = option_header::find_by_name('SO_TYPE');
  $so_types = option_line::find_by_option_id($option_header->option_header_id);
  return $so_types;
 }

 Public static function so_status() {
  $option_header = option_header::find_by_name('hd_ro_STATUS');
  $so_status = option_line::find_by_option_id($option_header->option_header_id);
  return $so_status;
 }

 public function copy($hd_svo_header_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM hd_svo_header WHERE `hd_svo_header_id` = '{$hd_svo_header_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `hd_svo_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `hd_svo_header_id` = '{$hd_svo_header_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `hd_svo_header` SELECT * FROM tmptable WHERE `hd_svo_header_id` = '' ";
    if ($db->query($sql3)) {
     $this->hd_svo_header_id = $db->insert_id();
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  }
  return $this->msg;
 }

 private function _pick_sales_order() {
  
 }

// public function save() {
//	$primary_column = static::$primary_column;
//	if (empty($this->$primary_column)) {
//	 $this->approval_status = 'Entered';
//	 $this->create();
//	} else {
//	 $this->update($this->$primary_column);
//	}
//	return $this->msg;
// }
}

//end of hd_svo_header class
?>