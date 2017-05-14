<?php
/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */
 class po_asl_line extends dbObject {

  public static $table_name = "po_asl_line";
  public static $primary_column = "po_asl_line_id";
  public static $parent_primary_column = "po_asl_header_id";
  public static $key_column = 'po_asl_header_id';
  public static $module = "po";
  public $field_a = [
   'po_asl_line_id',
   'po_asl_header_id',
   'supplier_id',
   'supplier_site_id',
   'mfg_part_number',
   'manufacturer',
   'business_type',
   'description',
   'release_method',
   'min_order_quantity',
   'fix_lot_multiplier',
   'country_of_origin',
   'status',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  //variables used for showing data
  public static $release_method_a = [
   'MANUAL' => 'Manual',
   'AUTO_RELEASE' => 'Auto Release',
   'AUTO_APPROVE' => 'Auto Rlease & Approve'
  ];
  public $fields_inForm_notInDataBase = [
   "supplier_name",
   "supplier_number",
   "supplier_site_name",
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   "po_asl_header_id"
  ];
  public $requiredField = [
   'po_asl_header_id',
   'supplier_id',
  ];
  public $po_asl_line_id;
  public $po_asl_header_id;
  public $supplier_id;
  public $supplier_site_id;
  public $mfg_part_number;
  public $manufacturer;
  public $business_type;
  public $description;
  public $release_method;
  public $min_order_quantity;
  public $fix_lot_multiplier;
  public $country_of_origin;
  public $status;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;

  Public static function po_sourcing_type() {
   $option_header = option_header::find_by_name('PO_SOURCING_TYPE');
   $ol = option_line::find_by_option_id($option_header->option_header_id);
   return $ol;
  }

 }

//end of inv_transaction class
?>