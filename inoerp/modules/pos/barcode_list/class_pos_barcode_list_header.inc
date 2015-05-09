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
 * pos_barcode_list_header
 * Contains all the pos_barcode_list_header information, such as - price_list, module_name, description,  currency_code, etc.
 * 
 */
class pos_barcode_list_header extends dbObject {

 public static $table_name = "pos_barcode_list_header";
 public static $primary_column = "pos_barcode_list_header_id";
 public static $dependent_classes = ['pos_barcode_list_line'];
 public static $key_column = "list_name";
 public static $module = "pos";
 public static $system_info = [
  'name' => 'Barcode List',
  'number' => '2721',
  'description' => 'Define and mainten price list',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'dependent_class' => array('pos_barcode_list_line'),
  'primary_entity_cb' => '',
  'module_name' => 'pos',
  'weight' => 2
 ];
 public $field_a = [
  'pos_barcode_list_header_id',
  'list_name',
  'description',
  'org_id',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'price_list',
 ];
 public $requiredField = [
  'list_name',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Barcode List "; //page Title
 public $pos_barcode_list_header_id;
 public $list_name;
 public $description;
 public $org_id;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function profile_pos_barcode_list_org() {
  $line_data_array = [];
  $line_data_array['line_key'] = 'org_id';
  $line_data_array['line_desc'] = 'org';
  $line_data_array['line_values'] = org::find_all_inventory();
  return $line_data_array;
 }

 private function _generate_label_forStaticLabels($data_ar) {
  $return_a = [];
  $param = get_postArray_From_jqSearializedArray($data_ar['print_parameters']);
  $sl = new bc_static_label();
  $sl->findBy_id($data_ar['bc_static_label_id']);

  $printer_i = sys_printer::find_by_id($sl->sys_printer_id);
  if (empty($sl->bc_label_format_header_id)) {
   echo "<br>bc_label_format_header_id missing!. No label generated. Error @bc_label_request @@ " . __LINE__;
   return;
  }
  $bc_lf = new bc_label_format_header();
  $bc_lf->findBy_id($sl->bc_label_format_header_id);
  $pos_barcode_list_header_id = $param['pos_barcode_list_header_id'][0];
  $list_lines = pos_barcode_list_line::find_by_parent_id($pos_barcode_list_header_id);
  $no_of_copies = !empty($sl->quanity) ? $sl->no_of_copies : 1;
  foreach ($list_lines as $item_records) {
   $no_of_labels = !empty($item_records->no_of_labels) ? $item_records->no_of_labels : $no_of_copies;
   $barcoded_str = '';
   $barcoded_str .= $item_records->item_number . '/';
   $barcoded_str .= $item_records->unit_price . '/';
   $barcoded_str .= $item_records->quantity . '/';
   $barcoded_str .= $item_records->discount_code . '/';
   $barcoded_str .= $item_records->discount_amount . '/';
   $barcoded_str .= $item_records->amount_after_discount;
   $xml_content = '';
   $xml_content .= '<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<!DOCTYPE labels SYSTEM "label.dtd">';
   $xml_content .= '<labels _FORMAT="' . $bc_lf->format_name . '" _QUANTITY="' . $no_of_labels . '" _PRINTERNAME="' . $printer_i->printer_name . '" _JOBNAME="LBL512027">
<label>';
   $xml_content .= '<variable name = "INO_POS_BC_LIST">';
   $xml_content .=!empty($barcoded_str) ? $barcoded_str : '';
   $xml_content .= '</variable>';
   $xml_content .= '</label>
</labels>
';
   array_push($return_a, $xml_content);
  }


  return $return_a;
 }
 
  private function _generate_label_forTransactions($data_obj) {
  $bc_auto = bc_label_auto_trigger::find_by_transactionTypId($data_obj->transaction_type_id);
  //get the correct association level
  $bc_auto_i = $bc_auto[0];
  $bc_lr = new bc_label_request();
  $bc_lr->sys_printer_id = $bc_auto_i->sys_printer_id;
  $bc_lr->bc_label_format_header_id = $bc_auto_i->bc_label_format_header_id;

  $printer_i = sys_printer::find_by_id($bc_lr->sys_printer_id);
  if (empty($bc_auto_i->bc_label_format_header_id)) {
   echo "<br>bc_label_format_header_id missing!. No label generated. Error @bc_label_request @@ " . __LINE__;
   return;
  }
  $bc_lf = new bc_label_format_header();
  $bc_lf->findBy_id($bc_auto_i->bc_label_format_header_id);
  $item_i = item::find_by_item_id_m($data_obj->item_id_m);
  $price = pos_transaction_header::find_POSPrice_by_ItemIdM_orgId($item_i->item_id_m, $data_obj->org_id);
  $barcoded_str = '';
  $barcoded_str .= $item_i->item_number . '/';
  $barcoded_str .= $price->unit_price.'/';
  $barcoded_str .= '1/';
  $xml_content = '';
  $xml_content .= '<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<!DOCTYPE labels SYSTEM "label.dtd">';
  $xml_content .= '<labels _FORMAT="' . $bc_lf->format_name . '" _QUANTITY="' . $data_obj->quantity . '" _PRINTERNAME="' . $printer_i->printer_name . '" _JOBNAME="LBL512027">
<label>';
  $xml_content .= '<variable name = "INO_POS_BC_LIST">';
  $xml_content .=!empty($barcoded_str) ? $barcoded_str : '';
  $xml_content .= '</variable>';
  $xml_content .= '</label>
</labels>
';
//  echo $xml_content;
  return $xml_content;
 }

 public function generate_label($data) {
  $ret_data = null;
  if (is_object($data)) {
   $ret_data = $this->_generate_label_forTransactions($data);
  } else if (is_array($data)) {
   $ret_data = $this->_generate_label_forStaticLabels($data);
  }
  return $ret_data;
 }

}

//end of path class
?>
