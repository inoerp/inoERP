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
 * business
 * Contains all the business information, such as - org_id, type, description,  code, etc.
 * 
 */
class business extends org {

 public static $table_name = "business";
 public static $primary_column = "business_id";
 public static $key_column = 'org_id';
 public static $module = "org";
 public static $system_info = [
  'name' => 'Business Org',
  'number' => '2004',
  'description' => 'Define and mainten Business Orgs',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'org',
  'weight' => 4
 ];
 public $field_a = [
  "business_id",
  "org_id",
  "business_org_type",
  "manager",
  "ef_id",
  "status",
  'enterprise_org_id',
  'legal_org_id',
  "rev_enabled",
  "rev_number",
  'cash_ac_id',
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
 public $initial_search = [
  "business_id",
  "org_id",
  "org",
  "description"
 ];
 public $account = [
  'cash_ac_id'
 ];

 public $requiredField = [
  "org_id",
 ];
 public $fields_inForm_notInDataBase = [
  'ledger'
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=business',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " Organization - Business Org "; //page Title
 public $business_id;
 public $description;
 public $business_org_type;
 public $ef_id;
 public $manager;
 public $enterprise_org_id;
 public $legal_org_id;
 public $ledger;
 public $cash_ac_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;

 public function _before_showing() {
  if (!empty($this->legal_org_id)) {
//	 echo "<br> legal org ". $this->legal_org_id;
   $legal_org = legal::find_by_orgId($this->legal_org_id);
//	 pa($legal_org);
   $ledger_id = $legal_org->ledger_id;
   $ledger = new gl_ledger();
   $ledger_i = $ledger->findBy_id($ledger_id);
   $this->ledger = $ledger_i->ledger;
  }
 }

 public static function profile_org_bu_name_default() {
  $line_data_array = [];
  $line_data_array['line_key'] = 'org_id';
  $line_data_array['line_desc'] = 'org';
  $line_data_array['line_values'] = org::find_all_business();
  return $line_data_array;
 }

 public static function find_by_orgId($org_id) {
  global $db;
  $sql = "SELECT * FROM " . self::$table_name . " 
      where org_id={$org_id}  ";
      $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public function findBy_orgId() {
  global $db;
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE org_id= :org_id ";
  $sql = ino_perPageSql_i($sql, 1);
  $param_a = ['org_id'];
  $value_a = ['org_id' => $this->org_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function search_add_extra_fields(&$arr) {
  $org = new org;
  if (!(is_array($arr))) {
   return false;
  }
  foreach ($arr as &$obj) {
   $primary_column = self::$primary_column;
   if (!empty($obj->org_id)) {
    $org_i = $org->findBy_id($obj->org_id);
    if ($org_i) {
     $obj->org = $org_i->org;
     $obj->description = $org_i->description;
    } else {
     $obj->org = null;
     $obj->description = null;
    }
   }
  }
 }

}

//end of business class
?>
