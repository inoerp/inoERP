<?php

class ar_unpaid_transaction_v extends dbObject {
public static $form_class_name = "ar_transaction_header";
 public static $table_name = "ar_unpaid_transaction_v";
 public static $primary_column = "ar_transaction_header_id";
 public static $key_column = 'transaction_number';
 public static $module = "ar";
 public $field_a = [
  'ar_transaction_header_id',
  'bu_org_id',
  'transaction_class',
  'transaction_number',
  'header_amount',
  'tax_amount',
  'exchange_rate',
  'receipt_amount',
  'remaing_amount',
  'currency',
  'doc_currency',
  'document_date',
  'document_number',
  'gl_journal_header_id',
  'ledger_id',
  'sd_so_header_id',
  'ar_customer_id',
  'ar_customer_site_id',
  'customer_name',
  'customer_number',
  'customer_site_name',
  'customer_site_number',
  'so_number',
  'org'
 ];
 public $initial_search = [
  'ar_transaction_header_id',
  'ar_customer_id',
  'transaction_number',
  'customer_name',
  'so_number',
 ];
 public $search_functions = [
  'Business Org' => 'search_business_org',
 ];
 public $search = [
//		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Unpaid AR Transactions "; //page Title
 public $ar_transaction_header_id;
 public $bu_org_id;
 public $transaction_class;
 public $transaction_number;
 public $header_amount;
 public $tax_amount;
 public $exchange_rate;
 public $receipt_amount;
 public $remaing_amount;
 public $currency;
 public $doc_currency;
 public $document_date;
 public $document_number;
 public $gl_journal_header_id;
 public $ledger_id;
 public $sd_so_header_id;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $customer_site_number;
 public $so_number;
 public $org;

 private function create_ar_unpaid_transaction_v() {
  $sql = "
CREATE OR REPLACE VIEW ar_unpaid_transaction_v
(
ar_transaction_header_id, bu_org_id, transaction_class, transaction_number,  header_amount,
tax_amount, receipt_amount, exchange_rate, remaing_amount,
currency, doc_currency,document_date, document_number, gl_journal_header_id,ledger_id,sd_so_header_id,ar_customer_id, ar_customer_site_id,
customer_name,customer_number,customer_site_name,customer_site_number, so_number,
org
)
AS
SELECT arth.ar_transaction_header_id, arth.bu_org_id, arth.transaction_class, arth.transaction_number,  
arth.header_amount,arth.tax_amount,arth.exchange_rate, arth.receipt_amount, 
IFNULL(arth.header_amount, 0) - IFNULL(arth.receipt_amount, 0) as remaing_amount,
arth.currency, arth.doc_currency,arth.document_date, arth.document_number, arth.gl_journal_header_id,
arth.ledger_id,arth.sd_so_header_id,arth.ar_customer_id, arth.ar_customer_site_id,
arc.customer_name,arc.customer_number,arcs.customer_site_name,arcs.customer_site_number, sosh.so_number,
org.org
FROM ar_transaction_header arth
LEFT JOIN sd_so_header sosh ON arth.sd_so_header_id = sosh.sd_so_header_id,
ar_customer arc,
ar_customer_site arcs,
org

WHERE 
arth.ar_customer_id = arc.ar_customer_id
AND arth.ar_customer_site_id = arcs.ar_customer_site_id
AND arth.ar_customer_id = arcs.ar_customer_id
AND org.org_id = arth.bu_org_id
AND IFNULL(arth.header_amount, 0) > IFNULL(arth.receipt_amount, 0)
AND arth.transaction_class IN ('INVOICE','DEPOSIT','CHARGE_BACK','PREPAYMENT','DEBIT_MEMO')
";
 }

 public function findBy_ItemId($item_id_m) {
  $sql = " SELECT * FROM " .
   self::$table_name .
   " WHERE item_id_m= :item_id_m "
   . " ORDER BY  supply_date ASC ";
  $value_a = ['item_id_m' => $item_id_m];
  $result_array = $this->findBySql($sql, $value_a);
  return !empty($result_array) ? $result_array : false;
 }

 public static function find_by_transactionId($ar_transaction_header_id) {
  $sql = "SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE   ar_transaction_header_id = '{$ar_transaction_header_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

}

?>
