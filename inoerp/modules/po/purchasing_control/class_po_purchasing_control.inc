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
 * po_purchasing_control 
 */
 class po_purchasing_control extends dbObject {

  public static $table_name = "po_purchasing_control";
  public static $primary_column = "po_purchasing_control_id";
  public static $key_column = 'org_id';
  public static $module = "pur";
  public static $system_info = [
   'name' => 'Purchasing Control',
   'number' => '2201',
   'description' => 'Create & Mainten Purchaing Controls',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
   'dependent_class' => '',
   'primary_entity_cb' => '',
   'module_name' => 'po',
   'weight' => 4
  ];
  public static $approval_hierarchy_a = [
   'SUPERVISOR' => 'Next Supervisor',
   'POSITION' => 'Position Based'
  ];
  public $field_a = [
   'po_purchasing_control_id',
   'org_id',
   'payment_term_id',
   'ship_to_id',
   'bill_to_id',
   'default_inv_org_id',
   'rev_enabled',
   'rev_number',
   'po_approval_hierarchy',
   'req_approval_hierarchy',
   'tax_ac_id',
   'default_line_type',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'po_purchasing_control_id',
   'org_id',
   'payment_term_id',
   'ship_to_id',
   'bill_to_id'
  ];
  public $column = [
   'po_purchasing_control_id',
   'org_id',
   'payment_term_id',
   'ship_to_id',
   'bill_to_id'
  ];
  public $requiredField = [
   'org_id'
  ];
  public $fields_inForm_notInDataBase = [
   "ship_to_location",
   "bill_to_location"
  ];
  
   public $account = [
   "tax_ac_id",
  ];
  public $search = [
   '_show_update_path' => 1,
   '_update_action_meassge' => 'Update',
   '_show_view_path' => 1,
  ];
  public $pageTitle = " Purchasing Control "; //page Title
  public $option_lists = [
   'po_purchasing_control_org_types' => 'ORG_TYPE',
   'costing_methods' => 'COSTING_METHODS'
  ];
  public $search_functions = [
   'Business Org' => 'search_business_org',
  ];
  public $po_purchasing_control_id;
  public $org_id;
  public $payment_term_id;
  public $ship_to_id;
  public $bill_to_id;
  public $default_inv_org_id;
  public $po_approval_hierarchy;
  public $req_approval_hierarchy;
  public $default_line_type;
  public $tax_ac_id;
  public $rev_enabled;
  public $rev_number;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $ship_to_location;
  public $bill_to_location;

  public function _before_showing() {
   if (!empty($this->ship_to_id)) {
    $this->ship_to_location = address::find_by_id($this->ship_to_id)->address_name;
   } else {
    $this->ship_to_location = null;
   }

   if (!empty($this->bill_to_id)) {
    $this->bill_to_location = address::find_by_id($this->bill_to_id)->address_name;
   } else {
    $this->bill_to_location = null;
   }
  }



  public function findBy_orgId($org_id) {
   global $db;
   $sql = "SELECT * FROM po_purchasing_control where org_id=:org_id ";
   $sql = ino_perPageSql_i($sql, 1);
   $param_a = ['org_id'];
   $value_a = ['org_id' => $org_id];
   $result = $db->findBy_sql($sql, $param_a, $value_a);
   return !empty($result) ? array_pop($result) : false;
  }

  public static function find_by_org_id($org_id) {
   $sql = "SELECT * FROM po_purchasing_control where org_id='{$org_id}' ";
   $sql = ino_perPageSql_i($sql, 1);
   $result = self::find_by_sql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

 }

//end of po_purchasing_control_org class
?>
