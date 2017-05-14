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
 * fp_kanban_header
 * Contains all the fp_kanban_header information, such as - fp_kanban_header, fp_kanban_header_id, org_id,  type, etc.
 * 
 */
class fp_kanban_header extends dbObject {

 public static $table_name = "fp_kanban_header";
 public static $primary_column = "fp_kanban_header_id";
 public static $key_column = 'item_id_m';
 public static $dependent_classes = ['fp_kanban_line'];
 public static $module = "fp";
 public static $multi_select_template_path = 'modules/fp/kanban/multi_action/fp_kanban_header_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Kanban Routing',
  'number' => '2511',
  'description' => 'fp_kanban_header',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fp',
  'weight' => 17
 ];
 public $action_a = [
  'CREATE_CARD' => 'Create Card',
  'UPDATE_CARD' => 'Create/Update Card',
 ];
 public static $card_generate_mode_a = [
  'CREATE_NEW_CARD' => 'Create New Card',
  'UPDATE_CARD' => 'Update Existing Card',
  'CREATE_UPDATE' => 'Create & Update'
 ];
 public static $source_type_a = [
  'SUPPLIER' => 'Supplier',
  'SUBINV' => 'Subinventory',
  'PRODUCTION' => 'Production',
  'ORG' => 'Organization',
  'LOGICAL' => 'Logical'
 ];
 public static $calculate_a = [
  'CARD' => 'Number of Cards',
  'CARD_SIZE' => 'Card Size'
 ];
 public $field_a = [
  'fp_kanban_header_id',
  'org_id',
  'description',
  'item_id_m',
  'effective_from',
  'effective_to',
  'subinventory_id',
  'locator_id',
  'source_type',
  'supplier_id',
  'supplier_site_id',
  'from_org_id',
  'from_subinventory_id',
  'from_locator_id',
  'planning_only_cb',
  'auto_request_cb',
  'calculate',
  'card_size',
  'noof_card',
  'moq',
  'size_roundup',
  'lead_time',
  'allocation_per',
  'flm',
  'ssd',
  'rfid_reference',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'description',
  'item_id_m',
 ];
 public $checkbox = [
  'planning_only_cb',
  'auto_request_cb',
 ];
 public $requiredField = [
  'item_id_m',
  'org_id',
  'subinventory_id',
  'source_type',
 ];
 public $fields_inForm_notInDataBase = [
  "item_number",
  "item_description",
  "supplier_name",
  "supplier_number",
  "supplier_site_name",
  'multibin_kanban_quantity',
  'overwrite_kanban_multibin_number',
  'overwrite_kanban_multibin_size',
  'kanban_multibin_number',
  'kanban_multibin_size',
  'action',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $search_functions = [
  'Organization' => 'search_org_name'
 ];
 public $pageTitle = " Kanban Route "; //page Title
 public $fp_kanban_header_id;
 public $org_id;
 public $description;
 public $item_id_m;
 public $effective_from;
 public $effective_to;
 public $subinventory_id;
 public $locator_id;
 public $source_type;
 public $supplier_id;
 public $supplier_site_id;
 public $from_org_id;
 public $from_subinventory_id;
 public $from_locator_id;
 public $planning_only_cb;
 public $auto_request_cb;
 public $calculate;
 public $card_size;
 public $noof_card;
 public $moq;
 public $lead_time;
 public $allocation_per;
 public $flm;
 public $ssd;
 public $size_roundup;
 public $rfid_reference;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $action;
 public $item_number;
 public $item_description;
 public $supplier_name;
 public $supplier_site_name;
 public $multibin_kanban_quantity;
 public $overwrite_kanban_multibin_number;
 public $overwrite_kanban_multibin_size;
 public $kanban_multibin_number;
 public $kanban_multibin_size;
 public $prg_generate_card_parameters = [
  'Organization' => 'search_org_name',
  'Item Number From' => 'search_item_number_from',
  'Item Number To' => 'search_item_number_to',
  'Item Id From' => 'search_item_id_m_from',
  'Item Id To' => 'search_item_id_m_to',
  'Mode' => 'search_kanban_card_generate_mode',
 ];
 public $prg_generate_card_details = [
  'name' => 'Kanban Card Update ',
  'description' => 'Update Kanban Card Details ',
 ];

 public function _before_save() {
  if (!empty($this->action)) {
   if ($this->action == 'update_kanban') {
    $this->_update_kanban();
    return 10;
   }
  }
 }

 private function _update_kanban() {
  $kh = new fp_kanban_header();
  $kh->findBy_id($this->fp_kanban_header_id);

  if (!empty(trim($this->overwrite_kanban_multibin_number))) {
   $kh->noof_card = $this->overwrite_kanban_multibin_number;
  } else if (!empty(trim($this->kanban_multibin_number))) {
   $kh->noof_card = $this->kanban_multibin_number;
  }

  if (!empty(trim($this->overwrite_kanban_multibin_size))) {
   $kh->card_size = $this->overwrite_kanban_multibin_size;
  } else if (!empty(trim($this->kanban_multibin_size))) {
   $kh->card_size = $this->kanban_multibin_size;
  }
//  pa($this);
//  pa($kh);
  $kh->save();
 }

 public function create_new_card($kanban_header_id) {
  global $dbc;
  $kbh = new fp_kanban_header();
  $kbh->findBy_id($kanban_header_id);
  $no_of_cards = !empty($kbh->noof_card) ? $kbh->noof_card : 2;

  $no_of_act_cards = fp_kanban_line::noof_active_cards($kanban_header_id);
  if ($no_of_act_cards >= $no_of_cards) {
   $this->message = '<br> No new card required. No of existing active cards = ' . $no_of_act_cards . ' and no of requured cards ' . $no_of_cards;
   return true;
  }
  for ($i = $no_of_act_cards; $i < $no_of_cards; $i++) {
   $kbl = new fp_kanban_line();
   $kbl->fp_kanban_header_id = $kbh->fp_kanban_header_id;
   $kbl->description = "Auto Generated Card";
   $kbl->card_status = "ACTIVE";
   $kbl->supply_status = "NEW";
   $size_roundup = !empty($kbh->size_roundup) ? ($kbh->size_roundup ) : 0;
   $kbl->kanban_size = round($kbh->card_size, $size_roundup);
   $kbl->card_type = $kbh->source_type;
   $kbl->save();
   $kbl->_after_save();
  }
 }

 public function update_card($fp_kanban_line_id) {
  $kbl = new fp_kanban_line();
  $kbl->findBy_id($fp_kanban_line_id);
  $kbh = new fp_kanban_header();
  $kbh->findBy_id($kbl->fp_kanban_header_id);
  $size_roundup = !empty($kbh->size_roundup) ? ($kbh->size_roundup ) : 0;
  $kbl->kanban_size = round($kbh->card_size, $size_roundup);
  $kbl->card_type = $kbh->source_type;
  $kbl->save();
 }

 Public static function all_kanbans_for_itemOrg($item_id_m, $org_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE item_id_m = '{$item_id_m}' AND org_id='{$org_id}' ";

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : null;
 }

 private function _verify_create_update_card($fp_kanban_header_id, $card_gen_mode) {
  switch ($card_gen_mode) {
   case 'CREATE_NEW_CARD' :
    $this->create_new_card($fp_kanban_header_id);
    break;

   case 'UPDATE_CARD' :
    $all_existing_cards = fp_kanban_line::find_by_parent_id($fp_kanban_header_id);
    if (!empty($all_existing_cards)) {
     foreach ($all_existing_cards as $ex_card) {
      $this->update_card($ex_card->fp_kanban_line_id);
     }
    }
    break;

   case 'CREATE_UPDATE' :
    $all_existing_cards = fp_kanban_line::find_by_parent_id($fp_kanban_header_id);
    if (!empty($all_existing_cards)) {
     foreach ($all_existing_cards as $ex_card) {
      $this->update_card($ex_card->fp_kanban_line_id);
     }
    }
    $this->create_new_card($fp_kanban_header_id);
    break;

   default :
    break;
  }
 }

 public function prg_generate_card($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting Kanban Card Generation Program....<br>';
//  pa($parameters);

  $card_gen_mode = !empty($parameters['from_item_id_m'][0]) ? $parameters['from_item_id_m'][0] : 'CREATE_UPDATE';
  $this->message = '<br> Using card generation mode ' . $card_gen_mode;

  if (!empty($parameters['org_id'][0])) {
   $org_id = $parameters['org_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $org_id;
  } else {
   $this->message .= '<br> Error! : No org id found @ item ' . __LINE__;
   return $this->message;
  }

  if (!empty($parameters['from_item_id_m'][0])) {
   $this->message .= "<br/>Using  Kanban Card Generation Program for Item Id Range ";
   $from_item_id = $parameters['from_item_id_m'][0];
   if (!empty($parameters['to_item_id_m'][0])) {
    $to_item_id = $parameters['to_item_id_m'][0];
   } else {
    $to_item_id = $from_item_id;
   }
   $item = new item();
   $item_range = $item->findBy_itemIdRange($from_item_id, $to_item_id);
   foreach ($item_range as $item_record) {
    $all_kanbans_for_item = self::all_kanbans_for_itemOrg($item_record->item_id_m, $org_id);
    foreach ($all_kanbans_for_item as $kanban) {
     $this->_verify_create_update_card($kanban->fp_kanban_header_id, $card_gen_mode);
    }
   }
   return $this->message;
  }

  if (!empty($parameters['from_item_number'][0])) {
   $this->message .= "<br/>Using  Kanban Card Generation Program by Item Number Range ";
   $from_item_number = $parameters['from_item_number'][0];
   if (!empty($parameters['to_item_number'][0])) {
    $to_item_number = $parameters['to_item_number'][0];
   } else {
    $to_item_number = $from_item_number;
   }
   $item = new item();
   $item_range = $item->findBy_itemNumberRange_OrgId($from_item_number, $to_item_number, $org_id);
   foreach ($item_range as $item_record) {
    $all_kanbans_for_item = self::all_kanbans_for_itemOrg($item_record->item_id_m, $org_id);
    foreach ($all_kanbans_for_item as $kanban) {
     $this->_verify_create_update_card($kanban->fp_kanban_header_id, $card_gen_mode);
    }
   }
   return $this->message;
  }

  //if no item id/number is given
  $this->message .= "<br/>Generating/Updating kanban card for all Items ";
  $item = new item();
  $item->org_id = $org_id;
  $item_range = $item->findAll_ofOrgId();
  foreach ($item_range as $item_record) {
   $all_kanbans_for_item = self::all_kanbans_for_itemOrg($item_record->item_id_m, $org_id);
   if (!$all_kanbans_for_item) {
    continue;
   }
   foreach ($all_kanbans_for_item as $kanban) {
    $this->_verify_create_update_card($kanban->fp_kanban_header_id, $card_gen_mode);
   }
  }

  return $this->message;
 }

 public function multi_select_input_fields() {
  $multi_select_input = [

   'overwrite_kanban_multibin_number',
   'overwrite_kanban_multibin_size'
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

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

//end of fp_kanban_header class
fp_kanban_header::staticVar_init('source_type_a');
?>
