<?php
/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */
 class po_quote_detail extends dbObject {

  public static $table_name = "po_quote_detail";
  public static $primary_column = "po_quote_detail_id";
  public static $parent_primary_column = "po_quote_line_id";
  public static $key_column = 'po_rfq_detail_id';
  public static $module = "po";
  public $field_a = [
   'po_quote_detail_id',
   'po_quote_header_id',
   'po_quote_line_id',
   'po_rfq_detail_id',
   'requirement_value',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'po_quote_detail_id',
   'po_quote_header_id',
   'po_quote_line_id',
   'po_rfq_detail_id',
  ];
  public $requiredField = [
   'po_quote_header_id',
   'po_quote_line_id',
   'po_rfq_detail_id',
  ];
  public $fields_inForm_notInDataBase = [  
   'po_rfq_header_id',
   'requirement_number',
   'requirement_name',
   'max_evaludation_points',
   'description',
   'requirement_type',
   'target_value',
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   'po_quote_line_id',
   'po_quote_header_id'
  ];
  public $po_quote_detail_id;
  public $po_quote_header_id;
  public $po_quote_line_id;
  public $po_rfq_detail_id;
  public $requirement_value;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $po_rfq_header_id;
  public $po_rfq_line_id;
  public $reference_table;
  public $reference_id;
  public $max_evaludation_points;
  public $requirement_number;
  public $requirement_name;
  public $description;
  public $requirement_type;
  public $target_value;

  public static function find_by_lineId_rfqDetailId($po_quote_line_id, $po_rfq_detail_id) {
   $sql = "SELECT * FROM " . self::$table_name . " where po_quote_line_id = '{$po_quote_line_id}'"
   . " AND po_rfq_detail_id = '{$po_rfq_detail_id}' ";
   $sql = ino_perPageSql_i($sql, 1);
   $result_array = self::find_by_sql($sql);
   return !empty($result_array) ?  array_pop($result_array) : false;
  }

 
  public function _before_delete() {
   if (!empty($this->received_quantity) || !empty($this->accepted_quantity) || !empty($this->delivered_quantity) ||
     !empty($this->invoiced_quantity) || !empty($this->paid_quantity)) {
    echo "<br>Delete is not allowed as transaction exists for the PO Detail Lines. ";
    return -99;
   } else {
    return 1;
   }
  }

  }

//end of po_quote_detail class
?>