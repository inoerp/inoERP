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
 * inventory
 * Contains all the inventory information, such as - org_id, type, description,  code, etc.
 * 
 */
 class inventory extends org {

  public static $table_name = "inventory";
  public static $primary_column = "inventory_id";
  public static $key_column = 'org_id';
  public static $module = "org"; //same as gl_journal_source
   public static $system_info = [
  'name' => 'Inventory Org',
  'number' => '2005',
  'description' => 'Define and mainten Inventory Orgs',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'org',
  'weight' => 5
 ];
  public $field_a = [
   "inventory_id",
   "org_id",
   "type",
   "code",
   "item_master_cb",
   "master_org_id",
   "calendar",
   "locator_control",
   "allow_negative_balance_cb",
   "costing_org",
   "costing_method",
   'pos_price_list_header_id',
   "transfer_to_gl_cb",
   "default_cost_group",
   "material_ac_id",
   "material_oh_ac_id",
   "overhead_ac_id",
   "resource_ac_id",
   "expense_ac_id",
   "item_rev_enabled_cb",
   "rev_start_number",
   "lot_uniqueness",
   "lot_generation",
   "lot_prefix",
   "lot_starting_number",
   "serial_uniqueness",
   "serial_generation",
   "serial_prefix",
   "serial_starting_number",
   "atp",
   "picking_rule",
   "sourcing_rule",
   "inter_org_ppv_ac_id",
   "inter_org_receivable_ac_id",
   "inter_org_payable_ac_id",
   "inter_org_intransit_ac_id",
   "inv_ap_accrual_ac_id",
   "inv_ap_exp_accrual_ac_id",
   "inv_ppv_ac_id",
   "inv_ipv_ac_id",
   "sales_ac_id",
   "cogs_ac_id",
   'costupdate_ac_id',
   "deferred_cogs_ac_id",
   "status",
   "rev_enabled",
   "rev_number",
   "created_by",
   "creation_date",
   "last_update_by",
   "last_update_date"
  ];
  public $initial_search = [
   "inventory_id",
   "org_id",
   "org",
   "description",
   "master_org_id"
  ];
  public $checkbox = [
   "item_master_cb",
   "allow_negative_balance_cb",
   "transfer_to_gl_cb",
   "item_rev_enabled_cb"
  ];
  public $column = [
   "inventory_id",
   "org_id",
   "org",
   "description",
   "code",
   "item_master_cb",
   "master_org_id"
  ];
  public $account = [
   "material_ac_id",
   "material_oh_ac_id",
   "overhead_ac_id",
   "resource_ac_id",
   "expense_ac_id",
   "inter_org_ppv_ac_id",
   "inter_org_receivable_ac_id",
   "inter_org_payable_ac_id",
   "inter_org_intransit_ac_id",
   "inv_ap_accrual_ac_id",
   "inv_ap_exp_accrual_ac_id",
   "inv_ppv_ac_id",
   "inv_ipv_ac_id",
   "sales_ac_id",
   "cogs_ac_id",
   "deferred_cogs_ac_id",
   'costupdate_ac_id'
  ];
  public $requiredField = [
   "org_id",
  ];
  public $search = [
   '_show_update_path' => 1,
   '_update_action_meassge' => 'Update',
   '_show_view_path' => 1,
  ];
  public $pageTitle = " Inventory Org - Create & Update Diffent Inventory Orgs"; //page Title
  public $option_lists = [
   'inventory_org_types' => 'ORG_TYPE',
   'costing_methods' => 'COSTING_METHODS'
  ];
  public $inventory_id;
  public $org_id;
  public $org;
  public $description;
  public $type;
  public $code;
  public $item_master_cb;
  public $master_org_id;
  public $calendar;
  public $locator_control;
  public $allow_negative_balance_cb;
  public $costing_org;
  public $costing_method;
  public $pos_price_list_header_id;
  public $transfer_to_gl_cb;
  public $default_cost_group;
  public $material_ac_id;
  public $material_oh_ac_id;
  public $overhead_ac_id;
  public $resource_ac_id;
  public $expense_ac_id;
  public $item_rev_enabled_cb;
  public $rev_start_number;
  public $lot_uniqueness;
  public $lot_generation;
  public $lot_prefix;
  public $lot_starting_number;
  public $serial_uniqueness;
  public $serial_generation;
  public $serial_prefix;
  public $serial_starting_number;
  public $atp;
  public $picking_rule;
  public $sourcing_rule;
  public $inter_org_ppv_ac_id;
  public $inter_org_receivable_ac_id;
  public $inter_org_payable_ac_id;
  public $inter_org_intransit_ac_id;
  public $inv_ap_accrual_ac_id;
  public $inv_ap_exp_accrual_ac_id;
  public $inv_ppv_ac_id;
  public $inv_ipv_ac_id;
  public $sales_ac_id;
  public $cogs_ac_id;
  public $deferred_cogs_ac_id;
  public $costupdate_ac_id;
  public $ef_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;

  Public static function inventory_org_types() {
   $option_header = option_header::find_by_name('INVENTORY_ORG_TYPE');
   $lines = option_line::find_by_option_id($option_header->option_header_id);
   return $lines;
  }

  public static function profile_org_inv_name_default() {
   $line_data_array = [];
   $line_data_array['line_key'] = 'org_id';
   $line_data_array['line_desc'] = 'org';
   $line_data_array['line_values'] = org::find_all_inventory();
   return $line_data_array;
  }

  Public static function costing_methods() {
   $option_header = option_header::find_by_name('COSTING_METHODS');
   $lines = option_line::find_by_option_id($option_header->option_header_id);
   return $lines;
  }

  public static function find_all_item_master() {
   $sql = " SELECT * FROM " .
     self::$table_name .
     " WHERE item_master=1 ";
   $result = self::find_by_sql($sql);
   return $result;
  }

  public static function find_by_org_id($org_id) {
   $sql = " SELECT * FROM " .
     self::$table_name .
     " WHERE org_id= '{$org_id}' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

  public function findAll_itemMaster() {
   global $db;
   $sql = " SELECT * FROM " .
     self::$table_name .
     " WHERE item_master=1 ";
   $result = $db->findBy_sql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

  public function findBy_org_id($org_id) {
   global $db;
   $sql = "SELECT * FROM inventory where org_id=:org_id ";
   $sql = ino_perPageSql_i($sql, 1);
   $param_a = ['org_id'];
   $value_a = ['org_id' => $org_id];
   $result = $db->findBy_sql($sql, $param_a, $value_a);
   return !empty($result) ? array_pop($result) : false;
  }

  public function findRelatedDetail_ByOrgId($org_id = '') {
   if (!empty($org_id)) {
    $orgid = $org_id;
   } else {
    $orgid = $this->org_id;
   }
   $sql = "
   SELECT org.org , org.org_id , org.code , org.type , 
	 org.description, org.enterprise_org_id , org.legal_org_id, 
	 org.business_org_id , org.inventory_org_id , org.status, legal.ledger_id,
	 legal.legal_id, legal.legal_org_type, legal.country_of_registration, 
	 legal.balancing_segments, business.business_id, business.business_org_type, 
	 business.cash_ac_id, business.manager, gl_ledger.coa_id, gl_ledger.currency_code,gl_ledger.calendar_option_line_code   ,
   inventory.material_ac_id,    inventory.material_oh_ac_id,    inventory.overhead_ac_id,
inventory.resource_ac_id,   inventory.expense_ac_id,   inventory.inter_org_ppv_ac_id,
inventory.inter_org_receivable_ac_id,   inventory.inter_org_payable_ac_id,   inventory.inter_org_intransit_ac_id,
inventory.inv_ap_accrual_ac_id,   inventory.inv_ap_exp_accrual_ac_id,   inventory.inv_ppv_ac_id,
inventory.inv_ipv_ac_id,   inventory.sales_ac_id,   inventory.cogs_ac_id,   inventory.deferred_cogs_ac_id
   FROM  org
      LEFT JOIN inventory ON org.org_id = inventory.org_id
      LEFT JOIN legal ON legal.org_id = org.legal_org_id
      LEFT JOIN business ON business.org_id = org.business_org_id
      LEFT JOIN gl_ledger ON gl_ledger.gl_ledger_id = legal.ledger_id
   
WHERE org.org_id = '{$orgid}' 
"  ;
$sql = ino_perPageSql_i($sql, 1);
   $result = $this->findBySql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

  public static function search_add_extra_fields(&$arr) {
   $org = new org;
   if (!(is_array($arr))) {
    return false;
   }
   foreach ($arr as &$obj) {
    $primary_column = parent::$primary_column;
    if (!empty($obj->org_id)) {
     $org_i = $org->findBy_id($obj->org_id);
     $obj->org = $org_i->org;
     $obj->description = $org_i->description;
    }
   }
  }

 }

//end of inventory_org class
?>
