<?php

class locator_v extends dbObject {

 public static $form_class_name = "locator";
 public static $table_name = "locator_v";
 public static $primary_column = "locator_id";
 public static $key_column = 'locator';
 public static $module = "org";
 public $field_a = [
  'org_id',
  'locator',
  'alias',
  'locator_id',
  'subinventory',
  'subinventory_id',
  'sub_description',
  'org',
  'type',
  'code',
  'description',
  'enterprise_org_id',
  'legal_org_id',
  'business_org_id',
  'inventory_org_id',
  'address_id',
  'ledger_id',
  'ledger',
  'coa_structure_id',
  'currency_code',
 ];
 public $initial_search = [
  'org',
  'code',
  'description',
  'ledger',
 ];
 public $search = [
  '_view_path' => 'form.php?class_name=locator',
  '_show_view_path' => 1,
  '_update_path' => 'form.php?class_name=locator',
  '_show_update_path' => 1,
////		 '_extra_path' => '',
 ];
 public $option_lists = [
  'org_types' => 'ORG_TYPE'
 ];
 public $pageTitle = " Locator "; //page Title
 public $org_id;
 public $locator;
 public $alias;
 public $locator_id;
 public $subinventory;
 public $subinventory_id;
 public $sub_description;
 public $org;
 public $type;
 public $code;
 public $description;
 public $enterprise_org_id;
 public $legal_org_id;
 public $business_org_id;
 public $inventory_org_id;
 public $address_id;
 public $ledger_id;
 public $ledger;
 public $coa_structure_id;
 public $currency_code;

 private function create_locator_v() {
  $sql = "
 CREATE OR REPLACE VIEW locator_v
(
org_id,locator,alias,locator_id, subinventory, subinventory_id, sub_description, org,type,code,description,enterprise_org_id,
legal_org_id,business_org_id,inventory_org_id,address_id, ledger_id, ledger, coa_structure_id,
 currency_code
)
AS
 SELECT
 org.org_id, loca.locator, loca.alias, loca.locator_id,sub.subinventory, sub.subinventory_id, sub.description sub_description, org.org, org.type, org.code, 
 org.description, org.enterprise_org_id,  org.legal_org_id, org.business_org_id, org.inventory_org_id, 
 org.address_id, legal.ledger_id, gl.ledger, gl.coa_structure_id,
 gl.currency_code
 FROM org,
 subinventory sub ,
 locator loca,
 legal, 
 gl_ledger gl 
 WHERE sub.org_id = org.org_id
 AND loca.subinventory_id = sub.subinventory_id
 AND legal.org_id = org.legal_org_id
 AND gl.gl_ledger_id = legal.ledger_id
";
 }

 public function findBy_parameter() {
  $value_a = [];
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE org_id = :org_id ";
  $value_a['org_id'] = $this->org_id;
  if (!empty($this->subinventory_id)) {
   $sql .= " AND subinventory_id = :subinventory_id ";
   $value_a['subinventory_id'] = $this->subinventory_id;
  }
  if (!empty(trim($this->locator_id))) {
   $sql .= " AND locator_id = :locator_id ";
   $value_a['locator_id'] = $this->locator_id;
  }
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? $result : false;
 }

}

?>
