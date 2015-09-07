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
 * Lot Number
 * Contains all the locator information, such as - lot_number, org_id,  generation, quantity, etc.
 * 
 */

class inv_lot_number extends dbObject {

 public static $table_name = "inv_lot_number";
 public static $primary_column = "inv_lot_number_id";
 public static $key_column = 'item_id_m';
 public static $module = "inv";
 public static $system_info = [
  'name' => 'Lot Number',
  'number' => '2122',
  'description' => 'Item Lot Number',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 9
 ];
 public static $origination_type_a = [
  'INVENTORY' => 'Inventory',
  'WIP_COMPLETION' => 'WIP Completion',
  'RECEVING' => 'Receving',
  'SHIPMENT' => 'Shipment',
  'MANUAL' => 'Manual',
  'SYS_GEN' => 'System Generated',
 ];
 public static $lot_status = [
  'ACTIVE' => 'Active',
  'EXPIRED' => 'Expired',
 ];
 public static $expiration_action_a = [
  'NO_TRANSACTION' => 'No Transaction',
  'WARNING' => 'Warning',
  'ONLY_RTV' => 'Only Allow RTV',
  'RTV_MISC' => 'Allow RTV & Misc',
 ];
 public $field_a = [
  'inv_lot_number_id',
  'lot_number',
  'quantity',
  'item_id_m',
  'generation',
  'org_id',
  'lock_cb',
  'first_inv_transaction_id',
  'reference_key_name',
  'reference_key_value',
  'origination_type',
  'origination_date',
  'status',
  'activation_date',
  'expiration_date',
  'supplier_site_id',
  'po_header_id',
  'supplier_sn',
  'supplier_ln',
  'expiration_action',
  'item_revision',
  'parent_lot_number_id',
  'original_wip_wo_header_id',
  'last_inv_transaction_id',
  'country_of_origin',
  'description',
  'ar_customer_site_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $dateFields = [
  'activation_date',
  'expiration_date'
 ];
 public $initial_search = [
  'item_id_m',
   'org_id'
 ];
 public $fields_inForm_notInDataBase = [
  'org',
  'subinventory',
  'locator',
  'item_number',
  'item_description',
  'org_id',
  'transaction_type',
  'transaction_type_id',
  'lot_quantity',
  'org_name'
 ];
 public $requiredField = [
  'item_id_m',
  'generation',
  'org_id',
 ];
 public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
 public $prg_create_lot_number_parameters = [
  'Organization' => 'search_org_name',
  'Item Number From' => 'search_item_number_from',
  'Item Number To' => 'search_item_number_to',
  'Number of S/N' => 'search_quantity',
 ];
 public $prg_create_lot_number_details = [
  'name' => 'Create Pre Defined Lot Numbers',
  'description' => 'Create Pre Defined Lot Numbers',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Lot Number ";
 public $inv_lot_number_id;
 public $lot_number;
 public $quantity;
 public $item_id_m;
 public $generation;
 public $org_id;
 public $lock_cb;
 public $first_inv_transaction_id;
 public $reference_key_name;
 public $reference_key_value;
 public $origination_type;
 public $origination_date;
 public $status;
 public $activation_date;
 public $expiration_date;
 public $supplier_site_id;
 public $po_header_id;
 public $supplier_sn;
 public $supplier_ln;
 public $expiration_action;
 public $item_revision;
 public $parent_lot_number_id;
 public $original_wip_wo_header_id;
 public $last_inv_transaction_id;
 public $country_of_origin;
 public $description;
 public $ar_customer_site_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $item_number;
 public $item_description;
 public $lot_quantity;
 public $subinventory;
 public $locator;
 public $subinventory_id;
 public $locator_id;
 public $org_name;
 public $lot_generation;

 Public static function serail_status() {
  $option_header = option_header::find_by_name('INV_SEARIAL_STATUS');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 public function _before_save() {
  if (!empty($this->item_id_m) && !empty($this->org_id) && empty($this->inv_lot_number_id)) {
   $item_i = item::find_by_orgId_item_id_m($this->item_id_m, $this->org_id);
   if (empty($item_i->lot_generation) || ($item_i->lot_generation != 'PRE_DEFINED')) {
    echo "<br>Item lot generation is not pre-defined. You can manually generate lot number for lot pre-defined items";
    return -99;
   } else {
    $this->_update_item_starting_lot_number = 1;
   }
  } else if (empty($this->inv_lot_number_id)) {
   echo "<br>Missing Item Number or Org";
   return -99;
  }
 }

 public function _after_save() {
  if (!empty($this->inv_lot_number_id) && !empty($this->_update_item_starting_lot_number) && ($this->_update_item_starting_lot_number == 1)) {
   $item = new item();
   $item->org_id = $this->org_id;
   $item->item_id_m = $this->item_id_m;
   $item_i = $item->findBy_orgId_itemIdM();

   $item->item_id = $item_i->item_id;
   $item->lot_starting_number = !empty($item_i->lot_starting_number) ? $item_i->lot_starting_number + 1 : 1;
   $item->audit_trial();
   $item->save();
  }
 }

 public function findBy_itemIdM_OrgId_status() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE item_id_m = :item_id_m  ";
  $sql .= " AND current_org_id = :current_org_id  ";
  $value_a = ['item_id_m' => $this->item_id_m, 'org_id' => $this->org_id];
  if (!empty($this->status)) {
   $sql .= " AND status = :status  ";
   $value_a['status'] = $this->status;
  }
//
//   if (!empty($this->subinventory)) {
//    $sql .= " AND subinventory_id = :current_subinventory_id  ";
//    $value_a['current_subinventory_id'] = $this->subinventory_id;
//   }
//   if (!empty($this->current_locator_id)) {
//    $sql .= " AND current_locator_id = :current_locator_id  ";
//    $value_a['current_locator_id'] = $this->current_locator_id;
//   }
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? ($result) : false;
 }

 public function findBasic_lotInfo() {
  if (empty($this->subinventory_id)) {
   $sql = " SELECT inv_lot_number_id,    lot_number,    item_id_m,    generation, org_id , "
    . " status FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE item_id_m = :item_id_m  ";
   $sql .= " AND org_id = :org_id  ";
   $sql .= " AND status = :status  ";
   $value_a = ['item_id_m' => $this->item_id_m, 'org_id' => $this->org_id, 'status' => $this->status];
   $result = $this->findBySql($sql, $value_a);
  } else {
   $sql = " SELECT iln.inv_lot_number_id,    iln.lot_number,    iln.item_id_m,    iln.generation, iln.org_id
              FROM inv_lot_number iln,
              inv_lot_onhand lo,
              onhand 
              WHERE lo.inv_lot_number_id = iln.inv_lot_number_id
              AND onhand.onhand_id = lo.onhand_id
              AND onhand.item_id_m = '{$this->item_id_m}'
              AND onhand.subinventory_id = '{$this->subinventory_id}' ";
   $sql .= " AND iln.org_id = '{$this->org_id}'   ";
   $sql .= " AND iln.status = '{$this->status}'   ";
   if (!empty($this->locator_id)) {
    $sql .= " AND onhand.locator_id = '{$this->locator_id}'   ";
   }
   $result = self::find_by_sql($sql);
  }

  return !empty($result) ? ($result) : false;
 }

 public function prg_create_lot_number($seralized_parameters) {
  global $dbc;
  $parameters = unlotize($seralized_parameters);
  $this->message .= '<br> Starting lot number generation program';

  if (!empty($parameters['org_id'][0])) {
   $this->org_id = $org_id = $parameters['org_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $org_id;
  } else {
   $this->message .= '<br> Error! : No org id found @ cst_item_cost_header ' . __LINE__;
   return $this->message;
  }

  if (!empty($parameters['quantity'][0])) {
   $noof_lot_numbers = $parameters['quantity'][0];
   $this->message .= '<br> Entered Number Of lot Numbers are : ' . $noof_lot_numbers;
  } else {
   $this->message .= '<br>No parameter found for number of lot numbers. Using default value 1';
   $noof_lot_numbers = 1;
  }

  if (!empty($parameters['from_item_number'][0])) {
   $this->message .= "<br>Creating Serail Numbers By Item Number Range ";
   $from_item_number = $parameters['from_item_number'][0];
   if (!empty($parameters['to_item_number'][0])) {
    $to_item_number = $parameters['to_item_number'][0];
   } else {
    $to_item_number = $from_item_number;
   }
   $item = new item();
   $item_range = $item->findBy_itemNumberRange_OrgId($from_item_number, $to_item_number, $org_id);
   foreach ($item_range as $items) {
    if ($items->lot_generation != 'PRE_DEFINED') {
     $this->message .= "<br>$items->item_number is not pre defined in org_id $org_id ";
     continue;
    }

    for ($i = 0; $i < $noof_lot_numbers; $i++) {
     $isn = new inv_lot_number();
     $isn->item_id_m = $items->item_id_m;
     $isn->org_id = $org_id;
     $isn->current_org_id = $org_id;
     $isn->generation = 'PRE_DEFINED';
     $isn->status = 'DEFINED';
     $isn->origination_type = 'SYS_GEN';
     $isn->origination_date = current_time(1);
     $isn->description = 'Generated by program on' . current_time(1);
     $isn->inv_lot_number_id = null;
     $starting_lot_number = $items->lot_starting_number + $i;
     $isn->lot_number = $items->lot_prefix . $starting_lot_number;
     $isn->audit_trial();
     $isn->save();
     $dbc->confirm();
    }
    $item->lot_starting_number = !empty($items->lot_starting_number) ? $items->lot_starting_number + $i : $i + 1;
    $item->item_id = $items->item_id;
    $item->audit_trial();
    $item->save();
    $item->item_id = null;
   }
  }
  return $this->message;
 }

 public static function find_by_woHeaderId_inWIP($wo_header_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE status = 'IN_WIP' ";
  $sql .= " AND  current_wip_wo_header_id = '{$wo_header_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_allChild_bylotId($lot_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE parent_lot_number_id = '{$lot_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function create_parentChildRelation($parent_lot_id, $wo_header_id, $update_status = true) {
  $all_child_sn = self::find_by_woHeaderId_inWIP($wo_header_id);
  $csn = new inv_lot_number();
  foreach ($all_child_sn as $child_sn) {
   $csn->findBy_id($child_sn->inv_lot_number_id);
   $csn->parent_lot_number_id = $parent_lot_id;
   if ($update_status) {
    $csn->status = 'OUT_STORE';
    $csn->current_wip_wo_header_id = '';
   }
   $csn->audit_trial();
   $csn->save();
  }
 }

 public static function xxx_show_serialLot_entryForm($lot_detail_obj = '', $serial_detail_obj = '') {
  $f = new inoform();
  if (empty($lot_detail_obj)) {
   $lot_object = array(new inv_lot_number());
  } else {
   $lot_object = $lot_detail_obj;
  }
  $ret_stmt = '<table class="form_line_data_table">
                <thead> 
                <th>Lot Numbers</th>
                <th>Serial Numbers</th>
                </thead>
              <tbody class="form_data_line_tbody">
              <tr class="inv_transaction_line0" id="tab4_1">';
  $ret_stmt .= '<td class="add_detail_values0">';
  $ret_stmt .= $f->hidden_field('lot_number_id', $lot_object[0]->inv_lot_number_id);
  $ret_stmt .= $f->hidden_field('lot_generation', $lot_object[0]->lot_generation);
  $ret_stmt .='<img src="' . HOME_URL . 'themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
                <div class="class_detail_form">
                 <fieldset class="form_detail_data_fs"><legend>lot</legend>
                  <div class="tabsDetailLN">
                   <ul class="tabMain">
                    <li class="tabLink"><a href="#tabsDetailLN-1-1"> Numbers</a></li>
                   </ul>
                   <div class="tabContainer">
                    <div id="tabsDetail-1-1" class="tabContent">
                     <table class="form form_detail_data_table detail">
                      <thead>
                       <tr>
                        <th>Action</th>
                        <th>Lot Number</th>
                        <th>Quantity</th>
                       </tr>
                      </thead>
                      <tbody class="form_data_detail_tbody_ln">';
  $detailCount = 0;

  if (!empty($lot_detail_obj)) {
   $lot_object = [];
   foreach ($lot_detail_obj as $lot_detail) {
    $lot_no = new inv_lot_number();
    $lot_no->findBy_id($lot_detail->inv_lot_number_id);
    $lot_no->lot_quantity = $lot_detail->lot_quantity;
    array_push($lot_object, $lot_no);
   }
  }

  foreach ($lot_object as $lot_no) {
   $new_obj_div_class = $detailCount != 0 ? '' : '';

   $ret_stmt .=' <tr class="inv_lot_number' . $detailCount . '' . $new_obj_div_class . '">';
   $ret_stmt .=' <td>   
     <ul class="inline_action">
      <li class="add_row_detail_img1"><img  src="' . HOME_URL . 'themes/images/add.png"  alt="add new line" /></li>
      <li class="remove_row_img"><img src="' . HOME_URL . 'themes/images/remove.png" alt="remove this line" /> </li>
      <li><input type="checkbox" name="detail_id_cb" value="' . htmlentities($lot_no->inv_lot_number_id) . '"></li>  ';
//   $ret_stmt .= '<li>' . form::hidden_field('inv_transaction_id', $lot_no->inv_transaction_id) . '</li>';
   $ret_stmt .=' </ul>
   </td>
   <td>';
   $ret_stmt .= $f->text_field('lot_number', $lot_no->lot_number, '25');
   $ret_stmt .= $f->hidden_field('lot_generation', $lot_no->lot_generation);
   $ret_stmt .= '</td>';
   $ret_stmt .= '<td>' . $f->number_field('lot_quantity', $lot_no->lot_quantity, '25');
   $ret_stmt .= '</td>
   </tr>';

   $detailCount++;
  }
  $ret_stmt .= '</tbody>
  </table>
  </div>
  </div>
  </div>
  </fieldset>
  </div>
  </td>';

  if (empty($serial_detail_obj)) {
   $serial_object = array(new inv_serial_number());
  } else {
   $serial_object = $serial_detail_obj;
  }
  $ret_stmt .= '<td class="add_detail_values1">';

  $ret_stmt .= $f->hidden_field('serial_number_id', $serial_object[0]->inv_serial_number_id);
  $ret_stmt .= $f->hidden_field('serial_generation', $serial_object[0]->serial_generation);
  $ret_stmt .='<img src="' . HOME_URL . 'themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
                <div class="class_detail_form">
                 <fieldset class="form_detail_data_fs"><legend>Serial</legend>
                  <div class="tabsDetailSN">
                   <ul class="tabMain">
                    <li class="tabLink"><a href="#tabsDetailSN-1-1"> Numbers</a></li>
                   </ul>
                   <div class="tabContainer">
                    <div id="tabsDetailSN-1-1" class="tabContent">
                     <table class="form form_detail_data_table detail">
                      <thead>
                       <tr>
                        <th>Action</th>
                        <th>Serial Number</th>
                       </tr>
                      </thead>
                      <tbody class="form_data_detail_tbody_sn">';
  $detailCount_sn = 0;

  if (!empty($serial_detail_obj)) {
   $serial_object = [];
   foreach ($serial_detail_obj as $serial_detail) {
    $sn_no = new inv_serial_number();
    $sn_no->findBy_id($serial_detail->inv_serial_number_id);
    array_push($serial_object, $sn_no);
   }
  }

  foreach ($serial_object as $sn_no) {
   $new_obj_div_class = $detailCount != 0 ? '' : '';

   $ret_stmt .=' <tr class="inv_serial_number' . $detailCount_sn . '' . $new_obj_div_class . '">';
   $ret_stmt .=' <td>   
     <ul class="inline_action">
      <li class="add_row_detail_img1"><img  src="' . HOME_URL . 'themes/images/add.png"  alt="add new line" /></li>
      <li class="remove_row_img"><img src="' . HOME_URL . 'themes/images/remove.png" alt="remove this line" /> </li>
      <li><input type="checkbox" name="detail_id_cb" value="' . htmlentities($sn_no->inv_serial_number_id) . '"></li>  ';
   $ret_stmt .= '<li>' . form::hidden_field('inv_transaction_id', $sn_no->inv_transaction_id) . '</li>';
   $ret_stmt .=' </ul>
   </td>
   <td>';
   $ret_stmt .= $f->text_field('serial_number', $sn_no->serial_number, '25');
   $ret_stmt .= $f->hidden_field('serial_generation', $sn_no->serial_generation);
   $ret_stmt .= '</td></tr>';
   $detailCount_sn++;
  }
  $ret_stmt .= '</tbody>
  </table>
  </div>
  </div>
  </div>
  </fieldset>
  </div>
  </td>';

  $ret_stmt .= '</tr>
             </tbody>
            </table>';
//  echo $ret_stmt;
  return $ret_stmt;
 }

 public static function show_serialLot_entryForm($lot_detail_obj = '', $serial_detail_obj = '') {
  $f = new inoform();
  $return_a = [];
  if (empty($lot_detail_obj)) {
   $lot_object = array(new inv_lot_number());
  } else {
   $lot_object = $lot_detail_obj;
  }
  $ret_stmt_h = '<th>Lot Numbers</th>           <th>Serial Numbers</th>';
  $return_a['tab_header'] = $ret_stmt_h;
//  $ret_stmt_l = '<tr class="inv_transaction_line0" id="tab4_1">';
  $ret_stmt_l = '<td class="add_detail_values0">';
  $ret_stmt_l .= $f->hidden_field('lot_number_id', $lot_object[0]->inv_lot_number_id);
  $ret_stmt_l .= $f->hidden_field('lot_generation', $lot_object[0]->lot_generation);
  $ret_stmt_l .='<img src="' . HOME_URL . 'themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
                <div class="class_detail_form">
                 <fieldset class="form_detail_data_fs"><legend>lot</legend>
                  <div class="tabsDetailLN">
                   <ul class="tabMain">
                    <li class="tabLink"><a href="#tabsDetailLN-1-1"> Numbers</a></li>
                   </ul>
                   <div class="tabContainer">
                    <div id="tabsDetail-1-1" class="tabContent">
                     <table class="form form_detail_data_table detail">
                      <thead>
                       <tr>
                        <th>Action</th>
                        <th>Lot Number</th>
                        <th>Quantity</th>
                       </tr>
                      </thead>
                      <tbody class="form_data_detail_tbody_ln">';
  $detailCount = 0;

  if (!empty($lot_detail_obj)) {
   $lot_object = [];
   foreach ($lot_detail_obj as $lot_detail) {
    $lot_no = new inv_lot_number();
    $lot_no->findBy_id($lot_detail->inv_lot_number_id);
    $lot_no->lot_quantity = $lot_detail->lot_quantity;
    array_push($lot_object, $lot_no);
   }
  }

  foreach ($lot_object as $lot_no) {
   $new_obj_div_class = $detailCount != 0 ? '' : '';

   $ret_stmt_l .=' <tr class="inv_lot_number' . $detailCount . '' . $new_obj_div_class . '">';
   $ret_stmt_l .=' <td>   
     <ul class="inline_action">
      <li class="add_row_detail_img1"><img  src="' . HOME_URL . 'themes/images/add.png"  alt="add new line" /></li>
      <li class="remove_row_img"><img src="' . HOME_URL . 'themes/images/remove.png" alt="remove this line" /> </li>
      <li><input type="checkbox" name="detail_id_cb" value="' . htmlentities($lot_no->inv_lot_number_id) . '"></li>  ';
//   $ret_stmt .= '<li>' . form::hidden_field('inv_transaction_id', $lot_no->inv_transaction_id) . '</li>';
   $ret_stmt_l .=' </ul>
   </td>
   <td>';
   $ret_stmt_l .= $f->text_field('lot_number', $lot_no->lot_number, '25');
   $ret_stmt_l .= '</td>';
   $ret_stmt_l .= '<td>' . $f->number_field('lot_quantity', $lot_no->lot_quantity, '25');
   $ret_stmt_l .= '</td>
   </tr>';

   $detailCount++;
  }
  $ret_stmt_l .= '</tbody>
  </table>
  </div>
  </div>
  </div>
  </fieldset>
  </div>
  </td>';

  if (empty($serial_detail_obj)) {
   $serial_object = array(new inv_serial_number());
  } else {
   $serial_object = $serial_detail_obj;
  }
  $ret_stmt_l .= '<td class="add_detail_values1">';

  $ret_stmt_l .= $f->hidden_field('serial_number_id', $serial_object[0]->inv_serial_number_id);
  $ret_stmt_l .= $f->hidden_field('serial_generation', $serial_object[0]->serial_generation);
  $ret_stmt_l .='<img src="' . HOME_URL . 'themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
                <div class="class_detail_form">
                 <fieldset class="form_detail_data_fs"><legend>Serial</legend>
                  <div class="tabsDetailSN">
                   <ul class="tabMain">
                    <li class="tabLink"><a href="#tabsDetailSN-1-1"> Numbers</a></li>
                   </ul>
                   <div class="tabContainer">
                    <div id="tabsDetailSN-1-1" class="tabContent">
                     <table class="form form_detail_data_table detail">
                      <thead>
                       <tr>
                        <th>Action</th>
                        <th>Serial Number</th>
                       </tr>
                      </thead>
                      <tbody class="form_data_detail_tbody_sn">';
  $detailCount_sn = 0;

  if (!empty($serial_detail_obj)) {
   $serial_object = [];
   foreach ($serial_detail_obj as $serial_detail) {
    $sn_no = new inv_serial_number();
    $sn_no->findBy_id($serial_detail->inv_serial_number_id);
    array_push($serial_object, $sn_no);
   }
  }

  foreach ($serial_object as $sn_no) {
   $new_obj_div_class = $detailCount != 0 ? '' : '';

   $ret_stmt_l .=' <tr class="inv_serial_number' . $detailCount_sn . '' . $new_obj_div_class . '">';
   $ret_stmt_l .=' <td>   
     <ul class="inline_action">
      <li class="add_row_detail_img0"><img  src="' . HOME_URL . 'themes/images/add.png"  alt="add new line" /></li>
      <li class="remove_row_img"><img src="' . HOME_URL . 'themes/images/remove.png" alt="remove this line" /> </li>
      <li><input type="checkbox" name="detail_id_cb" value="' . htmlentities($sn_no->inv_serial_number_id) . '"></li>  ';
   $ret_stmt_l .= '<li>' . form::hidden_field('inv_transaction_id', $sn_no->inv_transaction_id) . '</li>';
   $ret_stmt_l .=' </ul>
   </td>
   <td>';
   $ret_stmt_l .= $f->text_field('serial_number', $sn_no->serial_number, '25');
   $ret_stmt_l .= '</td></tr>';
   $detailCount_sn++;
  }
  $ret_stmt_l .= '</tbody>
  </table>
  </div>
  </div>
  </div>
  </fieldset>
  </div>
  </td>';

  $return_a['tab_row_content'] = $ret_stmt_l;
//  $ret_stmt_l .= '</tr>';
//  $ret_stmt .= ' </tbody>
//            </table>';
//  echo $ret_stmt;
  return $return_a;
 }

}

//end of inv_lot_number class
?>