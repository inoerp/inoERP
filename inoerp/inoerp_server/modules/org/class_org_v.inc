<?php

class org_v extends dbObject {

 public static $form_class_name = "org";
 public static $table_name = "org_v";
 public static $primary_column = "org_id";
 public static $key_column = 'org';
 public static $module = "org";
 public $field_a = [
		 'org_id',
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
 public $column = [
		 'org_id',
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
 public $search = [
		 '_view_path' => 'form.php?class_name=org',
		 '_show_view_path' => 1,
		 '_update_path' => 'form.php?class_name=org',
		 '_show_update_path' => 1,
////		 '_extra_path' => '',
 ];
 public $option_lists = [
		 'org_types' => 'ORG_TYPE'
 ];
 public $pageTitle = " Org - All type of organizations "; //page Title
 public $org_id;
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

 private function create_org_v() {
	$sql = "
 CREATE OR REPLACE VIEW org_v
(
org_id,org,type,code,description,enterprise_org_id,
legal_org_id,business_org_id,inventory_org_id,address_id, ledger_id, ledger, coa_structure_id,
 currency_code
)
AS
  SELECT
 org.org_id, org.org, org.type, org.code, org.description, org.enterprise_org_id,
 org.legal_org_id, org.business_org_id, org.inventory_org_id, org.address_id, legal.ledger_id, gl.ledger, gl.coa_structure_id,
 gl.currency_code
 FROM org
 LEFT JOIN legal ON legal.org_id = org.legal_org_id
 LEFT JOIN gl_ledger gl ON gl.gl_ledger_id = legal.ledger_id
";
 }

// public function findBy_planId($plan_id = '') {
//	global $db;
//	if (!empty($plan_id)) {
//	 $this->plan_id = $plan_id;
//	}
//	$sql = " SELECT * FROM " . self::$table_name;
//	$sql .= " where plan_id = :plan_id ";
//	$param_a = ['plan_id'];
//	$value_a = ['plan_id' => $this->plan_id];
//	$result = $db->findBy_sql($sql, $param_a, $value_a);
//	return !(empty($result)) ? $result : false;
// }

}

?>
