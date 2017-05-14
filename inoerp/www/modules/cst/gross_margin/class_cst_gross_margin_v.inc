<?php

class cst_gross_margin_v extends dbObject {

 public static $form_class_name = "item";
 public static $table_name = "cst_gross_margin_v";
 public static $primary_column = "gross_margin_id";
 public $field_a = [
  'item_number',
  'org',
  'customer_name',
  'inv_unit_price_ledgc',
  'country',
  'frozen_cost',
  'gross_profit',
  'gross_margin',
  'period_name',
  'shipping_org_id',
  'cst_item_cost_header_id',
  'address',
  'ar_transaction_header_id',
  'bu_org_id',
  'transaction_type',
  'transaction_class',
  'transaction_number',
  'ar_customer_id',
  'ar_customer_site_id',
  'document_owner',
  'description',
  'ship_to_id',
  'bill_to_id',
  'header_amount',
  'currency',
  'exchange_rate',
  'doc_currency',
  'document_number',
  'ledger_id',
  'period_id',
  'sales_person',
  'reference_key_name_ath',
  'reference_key_value_ath',
  'sd_so_header_id',
  'ar_transaction_line_id',
  'line_number',
  'item_id_m',
  'item_description',
  'inv_line_quantity',
  'inv_unit_price',
  'line_type',
  'line_description',
  'sd_so_line_id',
  'reference_key_name',
  'reference_key_value',
  'customer_number',
  'customer_site_name',
  'customer_site_number',
  'line_type_so_line',
  'unit_price',
  'ar_transaction_header_id_atl'
 ];
 public $initial_search = [
  'item_number'
 ];
 public $search_functions = [
  'Item From' => 'search_item_number_from',
  'Item To' => 'search_item_number_to',
  'Organization' => 'search_org_name',
  'Customer Name' => 'search_customer_name',
 ];
 public $pageTitle = " Gross Margin "; //page Title
 public static $search_groupBy = [
  'item_number' => 'Item Number',
  'period_name' => 'Period Name'
//		 'subinventory' => 'Subinventory',
//		 'org_id' => 'Inventory Org',
 ];
 public $search_groupBy_sum = 'gross_margin';
 public $period_name;
 public $ar_transaction_header_id;
 public $bu_org_id;
 public $transaction_type;
 public $transaction_class;
 public $transaction_number;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $document_owner;
 public $description;
 public $ship_to_id;
 public $bill_to_id;
 public $header_amount;
 public $currency;
 public $exchange_rate;
 public $doc_currency;
 public $document_number;
 public $ledger_id;
 public $period_id;
 public $sales_person;
 public $reference_key_name_ath;
 public $reference_key_value_ath;
 public $sd_so_header_id;
 public $ar_transaction_line_id;
 public $line_number;
 public $item_id_m;
 public $item_description;
 public $inv_line_quantity;
 public $inv_unit_price;
 public $line_type;
 public $line_description;
 public $sd_so_line_id;
 public $reference_key_name;
 public $reference_key_value;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $customer_site_number;
 public $line_type_so_line;
 public $unit_price;
 public $item_number;
 public $org;
 public $shipping_org_id;
 public $inv_unit_price_ledgc;
 public $address;
 public $country;
 public $cst_item_cost_header_id;
 public $frozen_cost;
 public $gross_profit;
 public $gross_margin;
 public $ar_transaction_header_id_atl;

 private function create_cst_gross_margin_v() {
  $sql = "
	 CREATE OR REPLACE VIEW cst_gross_margin_v
(
ar_transaction_header_id,  bu_org_id,  transaction_type,  transaction_class,  transaction_number,
ar_customer_id,  ar_customer_site_id,  document_owner,  description,  ship_to_id,
bill_to_id,  header_amount,  currency,exchange_rate,
doc_currency, document_number,  ledger_id,  period_id,period_name,
sales_person,reference_key_name_ath,  reference_key_value_ath,  sd_so_header_id_ath,
ar_transaction_line_id,    line_number,   item_id_m, ar_transaction_header_id_atl,
item_description,   inv_line_quantity,   inv_unit_price, 
line_type,   line_description, 
sd_so_header_id,    reference_key_name,   reference_key_value, 
customer_name, customer_number,
customer_site_name, customer_site_number,
sd_so_line_id, line_type_so_line, unit_price,
item_number, org, shipping_org_id,
inv_unit_price_ledgc, address,country, cst_item_cost_header_id,frozen_cost,
gross_profit, gross_margin
)
AS
  SELECT
  ath.ar_transaction_header_id,   ath.bu_org_id,   ath.transaction_type,   ath.transaction_class,   ath.transaction_number,
  ath.ar_customer_id,   ath.ar_customer_site_id,   ath.document_owner,   ath.description,   ath.ship_to_id,
  ath.bill_to_id,   ath.header_amount,   ath.currency, ath.exchange_rate,
  ath.doc_currency,  ath.document_number,   ath.ledger_id,   ath.period_id, gp.period_name,
  ath.sales_person, ath.reference_key_name,   ath.reference_key_value,   ath.sd_so_header_id,
  atl.ar_transaction_line_id,    atl.line_number,   atl.item_id_m, atl.ar_transaction_header_id,
  atl.item_description,   atl.inv_line_quantity,   atl.inv_unit_price, 
  atl.line_type,   atl.line_description, 
  atl.sd_so_header_id,   atl.reference_key_name,   atl.reference_key_value, 
  ar_customer.customer_name, ar_customer.customer_number,
  ar_customer_site.customer_site_name, ar_customer_site.customer_site_number,
  sdsl.sd_so_line_id, sdsl.line_type, sdsl.unit_price,
  item.item_number, org.org, sdsl.shipping_org_id,
 (atl.inv_unit_price * ath.exchange_rate ) as inv_unit_price_ledgc,
  ship_address.address,ship_address.country, cich.cst_item_cost_header_id, SUM(amount) as frozen_cost,
  (IFNULL((atl.inv_unit_price * ath.exchange_rate ), 0 ) - IFNULL(SUM(amount), 0 )) as gross_profit,
  ROUND((IFNULL((atl.inv_unit_price * ath.exchange_rate ), 0 ) - IFNULL(SUM(amount), 0 ))/IFNULL((atl.inv_unit_price * ath.exchange_rate ), 1 ) , 5)*100 as gross_margin
  
  FROM 
  ar_customer, 
  address as ship_address,
  gl_period gp,
  ar_transaction_line atl
  LEFT JOIN ar_transaction_header ath ON ath.ar_transaction_header_id = atl.ar_transaction_header_id
  LEFT JOIN ar_customer_site ON ath.ar_customer_site_id = ar_customer_site.ar_customer_site_id
  LEFT JOIN sd_so_line sdsl ON atl.sd_so_line_id = sdsl.sd_so_line_id 
  LEFT JOIN sd_so_header sdsh ON sdsh.sd_so_header_id = sdsl.sd_so_header_id
  LEFT JOIN org ON sdsl.shipping_org_id = org.org_id
  LEFT JOIN item ON sdsl.item_id_m = item.item_id_m AND item.org_id = sdsl.shipping_org_id
  LEFT JOIN cst_item_cost_header cich ON cich.item_id_m = item.item_id_m AND item.org_id = cich.org_id AND bom_cost_type = 'FROZEN'
  LEFT JOIN cst_item_cost_line cicl ON cicl.cst_item_cost_header_id = cich.cst_item_cost_header_id

  WHERE ath.ar_customer_id = ar_customer.ar_customer_id
  AND ship_address.address_id = ath.ship_to_id
  AND gp.gl_period_id = ath.period_id

 GROUP BY cst_item_cost_header_id, atl.ar_transaction_line_id
";
 }

 public function findBy_itemIdm_location() {
  $sql = "SELECT * FROM " . self::$table_name;
  $sql .= " WHERE item_id_m = '{$this->item_id_m}' ";
  if (!empty($this->org_id)) {
   $sql .= " AND org_id = '{$this->org_id}' ";
  }
  if (!empty($this->subinventory_id)) {
   $sql .= " AND subinventory_id = '{$this->subinventory_id}' ";
  }
  if (!empty($this->locator_id)) {
   $sql .= " AND locator_id = '{$this->locator_id}' ";
  }

  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_itemId_orgId($item_id, $org_id) {
  $sql = " SELECT * from cst_gross_margin_v WHERE item_id_m = '{$item_id}' "
   . " AND org_id = '{$org_id}' ";
  $result = self::find_by_sql($sql);
//    echo $sql;
//  pa($result);
  return !empty($result) ? $result : false;
 }

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

//end of po_detail class
cst_gross_margin_v::staticVar_init('search_groupBy');
?>
