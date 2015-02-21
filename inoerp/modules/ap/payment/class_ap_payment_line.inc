<?php

 class ap_payment_line extends dbObject {

  public static $table_name = "ap_payment_line";
  public static $primary_column = "ap_payment_line_id";
  public static $parent_primary_column = "ap_payment_header_id";
  public static $multi_search_primary_column = "ap_payment_header_id"; //this value is used in multi search hidden value
  public static $key_column = 'amount';
  public static $module = "ap";
  public $field_a = [
   'ap_payment_line_id',
   'ap_payment_header_id',
   'ap_transaction_header_id',
   'line_number',
   'amount',
   'line_description',
   'gl_amount',
   'exchange_rate',
   'status',
   'line_source',
   'reference_type',
   'reference_key_name',
   'reference_key_value',
   'period_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'
  ];
  public $requiredField = [
   'ap_payment_header_id',
   'ap_transaction_header_id',
   'line_number'
  ];
  public $numberField = [
   'amount',
   'exchange_rate',
   'gl_amount'
  ];
  public $fields_inForm_notInDataBase = [
   "transaction_number",
   'invoiced_quantity',
   'action',
   'invoice_amount',
   'remaining_amount'
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   "ap_payment_header_id"
  ];
  public $ap_payment_line_id;
  public $ap_payment_header_id;
  public $line_number;
  public $amount;
  public $line_description;
  public $gl_amount;
  public $exchange_rate;
  public $status;
  public $line_source;
  public $reference_type;
  public $reference_key_name;
  public $reference_key_value;
  public $period_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $invoice_amount;
  public $remaining_amount;
  public $transaction_number;
  public $paid_amount;

  public function _after_save() {
   if ($this->ap_payment_line_id) {
    //update the invoice paid amount
    try {
     $this->_update_invoice_amount();
    } catch (Exception $e) {
     echo "<br>Updating transaction paid amount failed @ ap_payment_line after save" . $e->getMessage();
    }
   }
  }

  public function _before_save() {
   //if there is a line id in the form then return 10 as no changes to paid lines are allowed
   if ($this->ap_payment_line_id) {
    echo "<br>You can't update any payment line. Cancel/Viod the payment if ";
    return 10;
   }
  }

  private function _update_invoice_amount() {
   if (!empty($this->ap_transaction_header_id)) {
    $apth = new ap_transaction_header();
    $apth->findBy_id($this->ap_transaction_header_id);
    $apth->ap_transaction_header_id = $this->ap_transaction_header_id;
    $apth->paid_amount += $this->amount ;
    if ($apth->paid_amount <= $apth->header_amount) {
     if ($apth->paid_amount == $apth->header_amount) {
      $apth->payment_status = 'FULLY_PAID';
     } else {
      $apth->payment_status = 'PARTITALY_PAID';
     }
     
     $apth->audit_trial();
     $apth->save();
    } else {
     echo "<br> The Transaction# $apth->transaction_number is fully paid ";
     $this->rollback = true;
     pa($this);
    }
   }
  }

  private function _highest_line_number_from_header() {
   global $db;
   $sql = " SELECT max(line_number) as line_number FROM " . self::$table_name;
   $sql .= " WHERE ap_payment_header_id= :ap_payment_header_id ";
   $param_a = ['ap_payment_header_id'];
   $value_a = ['ap_payment_header_id' => $this->ap_payment_header_id];
   $result = $db->findBy_sql($sql, $param_a, $value_a);
   return !empty($result) ? array_pop($result) : 0;
  }

  Public static function ap_payment_line_types() {
   $option_header = option_header::find_by_name('PO_LINE_TYPE');
   $po_types = option_line::find_by_option_id($option_header->option_header_id);
   return $po_types;
  }

  public static function find_by_ap_payment_headerId($ap_payment_header_id) {
   $sql = "SELECT * FROM " . self::$table_name . " where ap_payment_header_id = '{$ap_payment_header_id}'";
   $result_array = self::find_by_sql($sql);
   return $result_array;
  }

  public function multi_select_input_fields() {
   $multi_select_input = [
    'inv_line_quantity',
    'inv_unit_price',
    'inv_line_price',
    'inv_line_type'
   ];
   return $multi_select_input;
  }

  public function multi_select_hidden_fields() {
   $multi_select_hidden = [
    'action_class_name',
    'supplier_id',
    'po_header_id',
    'ap_payment_header_id',
    'mode',
    'action',
    'po_status'
   ];

   return $multi_select_hidden;
  }

  public function copy($ap_payment_line_id) {
   global $db;
   $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM ap_payment_line WHERE `ap_payment_line_id` = '{$ap_payment_line_id}' ";
   if ($db->query($sql1)) {
    $sql2 = "  UPDATE tmptable SET `ap_payment_line_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `ap_payment_line_id` = '{$ap_payment_line_id}' ";
    if ($db->query($sql2)) {
     $sql3 = " INSERT INTO `ap_payment_line` SELECT * FROM tmptable WHERE `ap_payment_line_id` = '' ";
     if ($db->query($sql3)) {
      $this->ap_payment_line_id = $db->insert_id();
      $this->msg = 1;
     } else {
      $this->msg = 0;
     }
    }
   }
   return $this->msg;
  }

 }

//end of ap_payment_line class
?>