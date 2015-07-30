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
  'number' => '2117',
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
  'CALCULATE' => 'Calculate Size/Card',
 ];
 public static $source_type_a = [
  'SUPPLIER' => 'Supplier',
  'SUBINV' => 'Sub Inventory',
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
  'lead_time',
  'allocation_per',
  'flm',
  'ssd',
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
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $item_number;
 public $item_description;
 public $supplier_name;
 public $supplier_site_name;

}

//end of fp_kanban_header class
?>