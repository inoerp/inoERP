<?php

class ar_customer_bu extends dbObject {

 public static $table_name = "ar_customer_bu";
 public static $primary_column = "ar_customer_bu_id";
 public static $dependent_classes = ['ar_customer', 'ar_customer_site'];
 public static $key_column = 'ar_customer_id';
 public static $module = "ar";
 public static $system_info = [
  'name' => 'Customer BU',
  'number' => '1302',
  'description' => 'Customer and business unit association',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ar',
  'weight' => 2
 ];
 public $field_a = [
  'ar_customer_bu_id',
  'ar_customer_id',
  'org_id',
  'status',
  'profile_id',
  'currency',
  'payment_term_id',
  'finance_profile_id',
  'payment_method_id',
  'order_type_id',
  'price_list_id',
  'internal_org_id',
  'fob',
  'freight_terms',
  'transportation',
  'country_of_origin',
  'site_address_id',
  'site_contact_id',
  'customer_site_attachement_id',
  'ef_id',
  'bank_id',
  'bank_account_id',
  'receivable_ac_id',
  'revenue_ac_id',
  'tax_ac_id',
  'freight_ac_id',
  'clearing_ac_id',
  'unbilled_receivable_ac_id',
  'unearned_revenue_ac_id',
  'rev_enabled_cb',
  'rev_number',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $initial_search = [
  'ar_customer_bu_id',
  'ar_customer_id',
  'org_id',
  'status',
  'profile_id',
  'currency',
  'payment_term_id',
  'finance_profile_id',
  'payment_method_id',
  'order_type_id',
 ];
 public $column = [
  'ar_customer_bu_id',
  'ar_customer_id',
  'org_id',
  'status',
  'profile_id',
  'currency',
  'payment_term_id',
  'finance_profile_id',
  'payment_method_id',
  'order_type_id',
 ];
 public $account = [
  'receivable_ac_id',
  'revenue_ac_id',
  'tax_ac_id',
  'freight_ac_id',
  'clearing_ac_id',
  'unbilled_receivable_ac_id',
  'unearned_revenue_ac_id',
 ];
 public $checkbox = [
  "rev_enabled_cb"
 ];
 public $addressField = [
  'site_address_id'
 ];
 public $requiredField = [
  'ar_customer_id',
  'org_id',
 ];
 public $fields_inForm_notInDataBase = [
  "org",
  'customer_name',
  'customer_number'
 ];
 public $ar_customer_bu_id;
 public $ar_customer_id;
 public $org_id;
 public $status;
 public $profile_id;
 public $currency;
 public $payment_term_id;
 public $finance_profile_id;
 public $payment_method_id;
 public $order_type_id;
 public $price_list_id;
 public $internal_org_id;
 public $fob;
 public $freight_terms;
 public $transportation;
 public $country_of_origin;
 public $site_address_id;
 public $site_contact_id;
 public $customer_site_attachement_id;
 public $ef_id;
 public $bank_id;
 public $bank_account_id;
 public $receivable_ac_id;
 public $revenue_ac_id;
 public $tax_ac_id;
 public $freight_ac_id;
 public $clearing_ac_id;
 public $unbilled_receivable_ac_id;
 public $unearned_revenue_ac_id;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $org;
 public $customer_name;
 public $customer_number;

 public function findBy_orgId_customerId() {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where ar_customer_id= :ar_customer_id " .
   " AND org_id = :org_id ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $param_a = ['ar_customer_id', 'org_id'];
  $value_a = ['ar_customer_id' => $this->ar_customer_id, 'org_id' => $this->org_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_shift($result) : false;
 }

 public static function find_by_orgId_customerId($ar_customer_id, $org_id) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where ar_customer_id= '{$ar_customer_id}' " .
   " AND org_id = '{$org_id}' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_all_assigned_org_ids($ar_customer_id) {
  global $db;
  $sql = "SELECT org_id FROM " .
   self::$table_name .
   " where ar_customer_id= '{$ar_customer_id}' ";
  $result = $db->find_by_sql($sql);
  $assigned_inventory_orgs_array = [];

  foreach ($result as $orgs) {
   $assigned_inventory_orgs_array[] = $orgs->org_id;
  }

  return $assigned_inventory_orgs_array;
 }

 public static function validate_customerBuAssignment($ar_customer_id, $org_id) {
  global $db;
  $sql = "SELECT org_id FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ar_customer_id= '{$ar_customer_id}' ";
  $sql .= " AND org_id= '{$org_id}' ";
  $result = self::count_all_by_sql($sql);

  if ($result > 0) {
   $returnValue = 1;
  } else {
   $returnValue = 0;
  }

  return $returnValue;
 }

}

//end of customer_bu class
?>