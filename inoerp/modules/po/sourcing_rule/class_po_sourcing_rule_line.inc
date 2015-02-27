<?php
/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

class po_sourcing_rule_line extends dbObject {

 public static $table_name = "po_sourcing_rule_line";
 public static $primary_column = "po_sourcing_rule_line_id";
 public static $parent_primary_column = "po_sourcing_rule_header_id";
 public static $key_column = 'sourcing_type';
 public static $module = "po";
 public $field_a = [
		 'po_sourcing_rule_line_id',
		 'po_sourcing_rule_header_id',
		 'sourcing_type',
		 'source_from_org_id',
		 'supplier_id',
		 'supplier_site_id',
		 'allocation',
		 'rank',
		 'transit_time',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 //variables used for showing data
 public $fields_inForm_notInDataBase = [
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "po_sourcing_rule_header_id"
 ];
 public $requiredField = [
		 'po_sourcing_rule_header_id',
		 'sourcing_type',
 ];
 public $po_sourcing_rule_line_id;
 public $po_sourcing_rule_header_id;
 public $sourcing_type;
 public $source_from_org_id;
 public $supplier_id;
 public $supplier_site_id;
 public $allocation;
 public $rank;
 public $transit_time;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $supplier_name;
 public $supplier_site_name;
 
  Public static function po_sourcing_type() {
	$option_header = option_header::find_by_name('PO_SOURCING_TYPE');
	$ol = option_line::find_by_option_id($option_header->option_header_id);
	return $ol;
 }


}

//end of inv_transaction class
?>