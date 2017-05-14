<?php

 class po_rfq_line extends dbObject {

  public static $table_name = "po_rfq_line";
  public static $primary_column = "po_rfq_line_id";
  public static $parent_primary_column = "po_rfq_header_id";
  public static $key_column = 'item_description';
  public static $module = "po";
  public $checkbox = [
   "rev_enabled_cb",
   'hold_cb'
  ];
  public $field_a = [
   'po_rfq_header_id',
   'po_rfq_line_id',
   'line_number',
   'mfg_part_number',
   'manufacturer',
   'item_id_m',
   'item_description',
   'minimum_quantity',
   'maximum_quantity',
   'unit_price',
   'target_price',
   'line_description',
   'uom_id',
   'status',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'po_rfq_header_id',
   'mfg_part_number',
   'manufacturer',
   'item_id_m',
   'item_description',
  ];
  public $numberField = [
   'minimum_quantity',
   'maximum_quantity',
   'target_price',
  ];
  public $requiredField = [
   'po_rfq_header_id',
   'item_description',
  ];
  public $fields_inForm_notInDataBase = [
   "po_rfq_number",
   "item_number",
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   "po_rfq_header_id"
  ];
  public $po_rfq_header_id;
  public $po_rfq_line_id;
  public $line_number;
  public $mfg_part_number;
  public $manufacturer;
  public $item_id_m;
  public $item_description;
  public $minimum_quantity;
  public $maximum_quantity;
  public $target_price;
  public $unit_price;
  public $line_type;
  public $line_description;
  public $uom_id;
  public $status;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $item_number;

  public function _before_save() {
//   pa($_POST);
  }

  public function _after_save() {
   
  }

  private function _update_hold() {
   $hold_value = 0;
   $hold_ref = new sys_hold_reference();
   $hold_ref->reference_table = 'po_rfq_line';
   $hold_ref->reference_id = $this->po_rfq_line_id;
   $agreement_requirements = self::find_agreement_requirements_by_lineId($this->bpa_line_id);
//   pa($agreement_requirements);
   $hold_ref->hold_code = 'po_rfq_LINE_OVER_RELEASED_QTY';
   if (($agreement_requirements) && ($agreement_requirements->released_quantity + $this->line_quantity) > $agreement_requirements->agreed_quantity) {
    if (!$hold_ref->findBy_referenceTableId_holdCode(true)) {
     $application_reason = 'Released quantity is more than aggreed quantity';
     $this->_put_onHold('po_rfq_LINE_OVER_RELEASED_QTY', $application_reason);
    }
    $hold_value = 1;
   }

   if (($this->hold_cb == 1) && ($hold_value == 0) && !empty($this->po_rfq_line_id)) {
    $hold_ref->findBy_referenceTableId_holdCode(true);
    if (!empty($hold_ref->sys_hold_reference_id)) {
     $hold_ref->removal_reason = 'Quantity variance is removed';
     $this->_remove_Hold($hold_ref);
     $hold_value = 0;
    }
   }

   $hold_ref->hold_code = 'po_rfq_LINE_OVER_RELEASED_AMNT';
   if (($agreement_requirements) && ($agreement_requirements->released_amount + $this->line_price) > $agreement_requirements->agreed_amount) {
    if (!$hold_ref->findBy_referenceTableId_holdCode(true)) {
     $application_reason = 'Released amount is more than aggreed amount';
     $this->_put_onHold('po_rfq_LINE_OVER_RELEASED_AMNT', $application_reason);
    }
    $hold_value = 1;
   }

   if (($this->hold_cb == 1) && ($hold_value == 0) && !empty($this->po_rfq_line_id)) {
    $hold_ref->findBy_referenceTableId_holdCode(true);
    if (!empty($hold_ref->sys_hold_reference_id)) {
     $hold_ref->removal_reason = 'Amount variance is removed';
     $this->_remove_Hold($hold_ref);
     $hold_value = 0;
    }
   }
   $this->hold_cb = $hold_value;
  }

  private function _remove_Hold(&$obj) {
   $obj->hold_removed_by = $_SESSION['username'];
   $obj->hold_removed_on = current_time(true);
   $obj->save();
  }

  private function _put_onHold($hold_code, $application_reason) {
   $hold_ref = new sys_hold_reference();
   $hold_ref->hold_code = $hold_code;
   $hold_ref->reference_table = 'po_rfq_line';
   $hold_ref->reference_id = $this->po_rfq_line_id;
   $hold_ref->hold_applied_by = $_SESSION['username'];
   $hold_ref->hold_applied_on = current_time(true);
   $hold_ref->application_reason = $application_reason;
   $hold_ref->save();
  }

  public function _before_delete() {
   $detail_line_exists = po_rfq_requirement::find_by_parent_id($this->po_rfq_header_id);
   if ($detail_line_exists) {
    echo "<br>Delete is not allowed as PO Detail Lines exists!. First delete detail lines and then try again ";
    return -99;
   } else {
    return 1;
   }
  }

  Public static function po_rfq_line_types() {
   $option_header = option_header::find_by_name('po_rfq_LINE_TYPE');
   $po_rfq_types = option_line::find_by_option_id($option_header->option_header_id);
   return $po_rfq_types;
  }

  public static function find_by_po_rfq_headerId($po_rfq_header_id) {
   $sql = "SELECT * FROM " . self::$table_name . " where po_rfq_header_id = '{$po_rfq_header_id}'";
   $result_array = self::find_by_sql($sql);
   return $result_array;
  }

  public static function find_by_poHeaderId_itemId($po_rfq_header_id, $item_id) {
   $sql = "SELECT * FROM " . self::$table_name . " where po_rfq_header_id = '{$po_rfq_header_id}' AND item_id_m = '{$item_id}' ";
   $sql = ino_perPageSql_i($sql, 1);
   $result = self::find_by_sql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

 }

//end of po_rfq_line class
?>