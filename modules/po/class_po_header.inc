<?php

 class po_header extends dbObject {

  public static $table_name = "po_header";
  public static $dependent_classes = ['po_line', 'po_detail'];
  public static $primary_column = "po_header_id";
  public static $primary_column2 = "po_number";
  public static $key_column = 'supplier_id';
  public static $module = "po";
  public static $js_fileName = 'modules/po/js/multi_select.js';
  public static $system_info = [
   'name' => 'Purchasing',
   'number' => '2210',
   'description' => 'Create & Mainten Purchase Order & Related documents/transactions',
   'version' => '1.1.1.3',
   'db_version' => '1001',
   'mod_version' => '1.1.x-1.1',
   'dependent_class' => array('po_line', 'po_detail'),
   'primary_entity_cb' => '',
   'module_name' => 'po',
   'weight' => 1
  ];
  public $checkbox = [
   "rev_enabled_cb"
  ];
  public static $action_a = [
   'PRINT' => 'Print',
   'APPROVE' => 'Approve',
   'VIEW_HISTORY' => 'View History',
   'CANCEL' => 'Cancel',
   'RECEIVE' => 'Receive',
  ];
  public $field_a = [
   'po_header_id',
   'bu_org_id',
   'po_type',
   'po_number',
   'supplier_id',
   'supplier_site_id',
   'buyer',
   "description",
   'ship_to_id',
   'bill_to_id',
   'header_amount',
   'price_list_header_id',
   'currency',
   'doc_currency',
   'payment_term_id',
   'agreement_start_date',
   'aggrement_end_date',
   'exchange_rate_type',
   'exchange_rate',
   'released_amount',
   "ef_id",
   "po_status",
   "rev_enabled_cb",
   "rev_number",
   "created_by",
   "creation_date",
   "last_update_by",
   "last_update_date"
  ];
  public $profile_default = [
   'exchange_rate_type' => 'gl_currency_conversion_type',
   'bu_org_id' => 'org_bu_name_default',
   'ship_to_id' => 'ship_to_address_default',
   'bill_to_id' => 'bill_to_address_default'
  ];
  public $initial_search = [
   "po_header_id",
   "po_number",
   "supplier_id",
   "supplier_name",
   "supplier_number",
   "supplier_site_name",
   "buyer"
  ];
  public $column = [
   "po_header_id",
   "po_number",
   "po_status",
   "supplier_id",
   "creation_date",
   "buyer"
  ];
  public $requiredField = [
   'supplier_id',
   'supplier_site_id',
   'ship_to_id',
   'bill_to_id',
   'currency',
   'payment_term_id'
  ];
  public $addressField = [
   'ship_to_id',
   'bill_to_id'
  ];
  public $fields_inForm_notInDataBase = [
   "supplier_name",
   "supplier_number",
   "supplier_site_name",
   "ship_to_address",
   "bill_to_address",
   'multi_action_class_pc',
   'multi_action_class_pc_value',
   'action',
   'ship_to_phone',
   'ship_to_email',
   'ship_to_address',
   'ship_to_country',
   'ship_to_postal_code',
   'bill_to_phone',
   'bill_to_email',
   'bill_to_address',
   'bill_to_country',
   'bill_to_postal_code',
  ];
  public $search = [
   '_show_update_path' => 1,
   '_update_action_meassge' => 'Update PO',
   '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
   '_extra_path' => array('form.php?class_name=ap_transaction_header&mode=9' => 'Invoice',
    'form.php?class_name=receipt_header&mode=9' => 'Receive')
  ];
  public $pageTitle = " PO - Purchase Orders "; //page Title
  public $option_lists = [
   'po_type' => 'PO_TYPE',
   'po_status' => 'PO_STATUS',
  ];
  public $po_header_id;
  public $bu_org_id;
  public $po_type;
  public $po_number;
  public $supplier_id;
  public $supplier_site_id;
  public $buyer;
  public $description;
  public $ship_to_id;
  public $bill_to_id;
  public $header_amount;
  public $price_list_header_id;
  public $currency;
  public $doc_currency;
  public $payment_term_id;
  public $agreement_start_date;
  public $aggrement_end_date;
  public $exchange_rate_type;
  public $exchange_rate;
  public $released_amount;
  public $ef_id;
  public $po_status;
  public $rev_enabled_cb;
  public $rev_number;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;
  public $msg;
  public $supplier_name;
  public $supplier_number;
  public $supplier_site_name;
  public $ship_to_address;
  public $bill_to_address;
  public $multi_action_class_pc;
  public $multi_action_class_pc_value;
  public $action;
  public $bill_to_address_name;
  public $ship_to_phone;
  public $ship_to_address_name;
  public $ship_to_country;
  public $ship_to_postal_code;
  public $bill_to_phone;
  public $bill_to_country;
  public $bill_to_postal_code;

  public function __set($name, $value) {
   switch ($value) {
    case $value:


     break;

    default:
     $this->$name = $value;
     break;
   }
  }

  public function _before_save() {
   if ((empty($this->po_header_id)) && empty($this->po_status)) {
    $this->po_status = 'ENTERED';
   }

   if (($this->action == 'convert_requisition')) {
    echo "<br> saving before PO SAVE";
    $this->_convert_requisition_toPO();
    return 10;
   }
  }

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

  private function _convert_requisition_toPO_header($i, &$PO_cretaed) {
   global $dbc;
   $poh = new po_header();
   $poh->bu_org_id = $_POST['bu_org_id'][$i];
   $poh->po_type = 'STANDARD';
   $poh->supplier_id = $_POST['supplier_id'][$i];
   $poh->supplier_site_id = $_POST['supplier_site_id'][$i];
   $poh->ship_to_id = $_POST['receving_org_id'][$i];
   $poh->bill_to_id = $_POST['receving_org_id'][$i];
   $poh->supplier_id = $_POST['supplier_id'][$i];
   $poh->currency = $_POST['currency'][$i];
   $poh->payment_term_id = $_POST['payment_term_id'][$i];
   if (empty($poh->payment_term_id)) {
    $poh->payment_term_id = supplier_site::find_by_id($poh->supplier_site_id)->payment_term_id;
   }
   if (empty($poh->payment_term_id)) {
    $poh->payment_term_id = po_purchasing_control::find_by_org_id($poh->bu_org_id)->payment_term_id;
   }
   $poh->audit_trial();
   $poh->save();
   echo "<br> PO header is succefully created. Header Id - " . $poh->po_header_id;
   $dbc->confirm();
   $record_saved = ['supplier_id' => $poh->supplier_id,
    'supplier_site_id' => $poh->supplier_site_id,
    'po_header_id' => $poh->po_header_id];
   array_push($PO_cretaed, $record_saved);
   return $poh->po_header_id;
  }

  private function _convert_requisition_toPO() {
   global $dbc;
   if (empty($_POST)) {
    return;
   }
   $PO_cretaed = [];
   $line_number = 0;
   for ($i = 0; $i < count($_POST['po_requisition_detail_id']); $i++) {
    $line_number ++;
    $po_header_id = null;
    foreach ($PO_cretaed as $po_recods) {
     if (array_search($_POST['supplier_site_id'][$i], $po_recods)) {
      $po_header_id = $po_recods['po_header_id'];
      $line_number++;
      break;
     }
    }
    if (empty($po_header_id)) {
     $po_header_id = $this->_convert_requisition_toPO_header($i, $PO_cretaed);
    }
    if (!empty($po_header_id)) {
     $po_rd = new po_requisition_detail();
     $po_rd->findBy_id($_POST['po_requisition_detail_id'][$i]);
     if (!empty($po_rd->order_number)) {
      continue;
     }
     $pol = new po_line();
     $pol->line_number = $line_number;
     $pol->line_type = 'GOODS';
     $pol->po_header_id = $po_header_id;
     $pol->receving_org_id = $_POST['receving_org_id'][$i];
     $pol->item_id_m = $_POST['item_id_m'][$i];
     $item = new item();
     $item->findBy_id($pol->item_id_m);
     $pol->item_description = $item->item_description;
     $pol->uom_id = $item->uom_id;
     $pol->line_quantity = $_POST['line_quantity'][$i];
     $pol->unit_price = $_POST['unit_price'][$i];
     $pol->line_price = $pol->line_quantity * $pol->unit_price;
     $pol->reference_doc_type = 'po_requisition_details';
     $pol->reference_doc_number = $_POST['po_requisition_detail_id'][$i];
     $pol->audit_trial();
     $pol->save();
     echo "<br> PO Line is succefully created. Line Id - " . $pol->po_line_id;

     $pod = new po_detail();
     $pod->po_header_id = $po_header_id;
     $pod->po_line_id = $pol->po_line_id;
     $pod->shipment_number = 1;
     $pod->need_by_date = $_POST['need_by_date'][$i];
     $inv = new inventory();
     $inv_i = $inv->findBy_org_id($pol->receving_org_id);
     //ac id needs to be modified to req accounts
     $pod->charge_ac_id = $inv_i->material_ac_id;
     $pod->accrual_ac_id = $inv_i->inv_ap_accrual_ac_id;
     $pod->ppv_ac_id = $inv_i->inv_ppv_ac_id;
     $pod->audit_trial();
     $pod->save();
     echo "<br> PO Detail is succefully created. Detail Id - " . $pod->po_detail_id;

     $po_rd->order_number = $po_header_id;
     $po_rd->audit_trial();
     $po_rd->save();
    }
   }
  }

  public function _after_save() {
   global $db;
   echo '<br/> entered PO number is ' . $this->po_number;
   if ((!empty($this->po_header_id)) && empty($this->po_number)) {
    $po_header_id = $this->po_header_id;
    $bu_org_id = $this->bu_org_id;
    $po_number = $bu_org_id . '-' . $po_header_id;
    echo '<br/> New PO number is ' . $po_number;
    $this->msg = $this->update_poNumber($po_header_id, $po_number);
   }

   return $this->msg;
  }

  private function update_poNumber($po_header_id, $po_number) {
   global $dbc;
   $sql = " UPDATE " . self::$table_name;
   $sql .= " SET po_number = '{$po_number}'  ";
   $sql .= " WHERE po_header_id = '{$po_header_id}'  ";
   try {
    $dbc->ddlexecute($sql);
    $this->po_number = $po_number;
   } catch (Exception $e) {
    $this->msg = 0;
    echo "<br>Error in updating PO number" . $e->getMessage();
   }
  }

  public static function instantiate_extra_fields(&$array_of_objects) {
   if (count($array_of_objects) > 0) {
    foreach ($array_of_objects as &$this_object) {
     $supplier_details = supplier::find_by_id($this_object->supplier_id);
     $this_object->supplier_name = $supplier_details->supplier_name;
     $this_object->supplier_number = $supplier_details->supplier_number;
     $supplier_site_details = supplier_site::find_by_id($this_object->supplier_site_id);
     $this_object->supplier_site_name = $supplier_site_details->supplier_site_name;
    }
   }
   return $array_of_objects;
  }

  Public static function po_types() {
   $option_header = option_header::find_by_name('PO_TYPE');
   $po_types = option_line::find_by_option_id($option_header->option_header_id);
   return $po_types;
  }

  Public static function po_status() {
   $option_header = option_header::find_by_name('PO_STATUS');
   $po_status = option_line::find_by_option_id($option_header->option_header_id);
   return $po_status;
  }

  public function copy($po_header_id) {
   global $db;
   $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM po_header WHERE `po_header_id` = '{$po_header_id}' ";
   if ($db->query($sql1)) {
    $sql2 = "  UPDATE tmptable SET `po_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `po_header_id` = '{$po_header_id}' ";
    if ($db->query($sql2)) {
     $sql3 = " INSERT INTO `po_header` SELECT * FROM tmptable WHERE `po_header_id` = '' ";
     if ($db->query($sql3)) {
      $this->po_header_id = $db->insert_id();
      $this->msg = 1;
     } else {
      $this->msg = 0;
     }
    }
   }
   return $this->msg;
  }

  public function save() {
   $primary_column = static::$primary_column;
   if (empty($this->$primary_column)) {
    $this->po_status = 'Entered';
    $this->create();
   } else {
    $this->update($this->$primary_column);
   }
   return $this->msg;
  }

  //multi select used for req to PO conversion

  public function multi_select_input_fields() {
   $multi_select_input = [
    'select_supplier_name',
    'supplier_site_name'
   ];
   return $multi_select_input;
  }

  public function multi_select_hidden_fields() {
   $multi_select_hidden = [
    'action_class_name',
    'mode',
    'action',
    'show_block',
   ];

   return $multi_select_hidden;
  }

 }

//end of po_header class
?>