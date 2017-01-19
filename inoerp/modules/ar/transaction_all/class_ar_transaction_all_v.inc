<?php

class ar_transaction_all_v extends dbObject {

 public static $form_class_name = "ar_transaction_header";
 public static $table_name = "ar_transaction_all_v";
 public static $primary_column = "ar_transaction_header_id";
 public $field_a = [
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
  'receipt_amount',
  'tax_amount',
  'currency',
  'doc_currency',
  'receivable_ac_id',
  'payment_term_id',
  'exchange_rate_type',
  'exchange_rate',
  'transaction_status',
  'document_date',
  'document_number',
  'ledger_id',
  'trnx_period_id',
  'payment_term_date',
  'sales_person',
  'receipt_method',
  'approval_status',
  'receipt_status',
  'trnx_reference_type',
  'trnx_reference_key_name',
  'trnx_reference_key_value',
  'trnx_sd_so_header_id',
  'ar_transaction_line_id',
  'line_number',
  'item_id_m',
  'item_description',
  'inv_line_quantity',
  'inv_unit_price',
  'tax_code_id',
  'so_tax_amount',
  'gl_inv_line_price',
  'gl_tax_amount',
  'inv_line_price',
  'trnx_line_type',
  'line_description',
  'asset_cb',
  'uom_id',
  'status',
  'line_source',
  'sd_so_header_id',
  'trnx_sd_so_line_id',
  'sd_so_detail_id',
  'period_id',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'customer_name',
  'customer_number',
  'customer_site_name',
  'customer_site_number',
  'sd_so_line_id',
  'line_type',
  'so_line_number',
  'kit_cb',
  'kit_configured_cb',
  'bom_config_header_id',
  'wip_wo_header_id',
  'line_quantity',
  'picked_quantity',
  'shipped_quantity',
  'unit_price',
  'line_price',
  'line_status',
  'requested_date',
  'promise_date',
  'schedule_ship_date',
  'actual_ship_date',
  'item_number',
  'item_uom_id',
  'item_status',
  'org',
  'shipping_org_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
  'address',
  'country',
  'postal_code',
  'phone',
  'email',
  'website',
  'address_b',
  'country_b',
  'postal_code_b',
  'phone_b',
  'email_b',
  'website_b',
  'payment_term',
  'payment_term_description'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1
 ];
 
   public $search_functions = [
  'Organization' => 'search_bu_name',
 ];
	
 public $pageTitle = " AR Transaction "; //page Title
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
 public $receipt_amount;
 public $tax_amount;
 public $currency;
 public $doc_currency;
 public $receivable_ac_id;
 public $payment_term_id;
 public $exchange_rate_type;
 public $exchange_rate;
 public $transaction_status;
 public $document_date;
 public $document_number;
 public $ledger_id;
 public $trnx_period_id;
 public $payment_term_date;
 public $sales_person;
 public $receipt_method;
 public $approval_status;
 public $receipt_status;
 public $trnx_reference_type;
 public $trnx_reference_key_name;
 public $trnx_reference_key_value;
 public $trnx_sd_so_header_id;
 public $ar_transaction_line_id;
 public $line_number;
 public $item_id_m;
 public $item_description;
 public $inv_line_quantity;
 public $inv_unit_price;
 public $tax_code_id;
 public $so_tax_amount;
 public $gl_inv_line_price;
 public $gl_tax_amount;
 public $inv_line_price;
 public $trnx_line_type;
 public $line_description;
 public $asset_cb;
 public $uom_id;
 public $status;
 public $line_source;
 public $sd_so_header_id;
 public $trnx_sd_so_line_id;
 public $sd_so_detail_id;
 public $period_id;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $customer_site_number;
 public $sd_so_line_id;
 public $line_type;
 public $so_line_number;
 public $kit_cb;
 public $kit_configured_cb;
 public $bom_config_header_id;
 public $wip_wo_header_id;
 public $line_quantity;
 public $picked_quantity;
 public $shipped_quantity;
 public $unit_price;
 public $line_price;
 public $line_status;
 public $requested_date;
 public $promise_date;
 public $schedule_ship_date;
 public $actual_ship_date;
 public $item_number;
 public $item_uom_id;
 public $item_status;
 public $org;
 public $shipping_org_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $address;
 public $country;
 public $postal_code;
 public $phone;
 public $email;
 public $website;
 public $address_b;
 public $country_b;
 public $postal_code_b;
 public $phone_b;
 public $email_b;
 public $website_b;
 public $payment_term; 
 public $payment_term_description;

 private function create_ar_transaction_all_v() {
  $sql = "
CREATE OR REPLACE VIEW ar_transaction_all_v
(
 ar_transaction_header_id,  bu_org_id,  transaction_type,  transaction_class,  transaction_number,
 ar_customer_id,  ar_customer_site_id,  document_owner,  description,  ship_to_id,
 bill_to_id,  header_amount,  receipt_amount,  tax_amount,  currency,
 doc_currency,  receivable_ac_id,  payment_term_id,  exchange_rate_type,  exchange_rate,
 transaction_status,  document_date,  document_number,  ledger_id,  trnx_period_id,
 payment_term_date,  sales_person,  receipt_method,  approval_status,  receipt_status,
 trnx_reference_type,  trnx_reference_key_name,  trnx_reference_key_value,  trnx_sd_so_header_id,
 ar_transaction_line_id,   line_number,  item_id_m,
 item_description,  inv_line_quantity,  inv_unit_price,  tax_code_id,
 so_tax_amount,  gl_inv_line_price,  gl_tax_amount,  inv_line_price,  trnx_line_type,
 line_description,  asset_cb,  uom_id,  status,  line_source,
 sd_so_header_id,  trnx_sd_so_line_id,  sd_so_detail_id,  period_id,
 reference_type,  reference_key_name,  reference_key_value, 
  customer_name, customer_number,
  customer_site_name, customer_site_number,
  sd_so_line_id, line_type, so_line_number,	 
  kit_cb, kit_configured_cb, bom_config_header_id,	wip_wo_header_id, 
  line_quantity,
  picked_quantity, shipped_quantity, unit_price, line_price, line_status,
  requested_date, promise_date , schedule_ship_date ,actual_ship_date,
  item_number, item_uom_id, item_status,
  org, shipping_org_id,
  created_by, creation_date, last_update_by, last_update_date,
  address,country,postal_code,phone,email,website,
  address_b, country_b, postal_code_b,   phone_b, email_b, website_b,
  payment_term, payment_term_description
)
AS
  SELECT
  ath.ar_transaction_header_id,   ath.bu_org_id,   ath.transaction_type,   ath.transaction_class,   ath.transaction_number,
  ath.ar_customer_id,   ath.ar_customer_site_id,   ath.document_owner,   ath.description,   ath.ship_to_id,
  ath.bill_to_id,   ath.header_amount,   ath.receipt_amount,   ath.tax_amount,   ath.currency,
  ath.doc_currency,   ath.receivable_ac_id,   ath.payment_term_id,   ath.exchange_rate_type,   ath.exchange_rate,
  ath.transaction_status,   ath.document_date,   ath.document_number,   ath.ledger_id,   ath.period_id,
  ath.payment_term_date,   ath.sales_person,   ath.receipt_method,   ath.approval_status,   ath.receipt_status,
  ath.reference_type,   ath.reference_key_name,   ath.reference_key_value,   ath.sd_so_header_id,
  atl.ar_transaction_line_id,    atl.line_number,   atl.item_id_m,
  atl.item_description,   atl.inv_line_quantity,   atl.inv_unit_price,   atl.tax_code_id,
  atl.tax_amount,   atl.gl_inv_line_price,   atl.gl_tax_amount,   atl.inv_line_price,   atl.line_type,
  atl.line_description,   atl.asset_cb,   atl.uom_id,   atl.status,   atl.line_source,
  atl.sd_so_header_id,   atl.sd_so_line_id,   atl.sd_so_detail_id,   atl.period_id,
  atl.reference_type,   atl.reference_key_name,   atl.reference_key_value, 
  ar_customer.customer_name, ar_customer.customer_number,
  ar_customer_site.customer_site_name, ar_customer_site.customer_site_number,
  sdsl.sd_so_line_id, sdsl.line_type, sdsl.line_number,	
  sdsl.kit_cb, sdsl.kit_configured_cb, sdsl.bom_config_header_id,	sdsl.wip_wo_header_id, 
  sdsl.line_quantity,
  sdsl.picked_quantity, sdsl.shipped_quantity, sdsl.unit_price, sdsl.line_price, sdsl.line_status,
  sdsl.requested_date, sdsl.promise_date , sdsl.schedule_ship_date ,sdsl.actual_ship_date,
  item.item_number, item.uom_id, item.item_status,
  org.org, sdsl.shipping_org_id,
  sdsl.created_by, sdsl.creation_date, sdsl.last_update_by, sdsl.last_update_date,
  ship_address.address,ship_address.country,ship_address.postal_code,ship_address.phone,ship_address.email,ship_address.website,
  bill_address.address as address_b,bill_address.country as country_b,bill_address.postal_code as postal_code_b,
  bill_address.phone as phone_b,bill_address.email as email_b,bill_address.website as website_b,
  payment_term.payment_term, payment_term.description
  FROM 
  ar_customer, 
  address as ship_address,
  address as bill_address,
  ar_transaction_line atl
  LEFT JOIN ar_transaction_header ath ON ath.ar_transaction_header_id = atl.ar_transaction_header_id
  LEFT JOIN ar_customer_site ON ath.ar_customer_site_id = ar_customer_site.ar_customer_site_id
  LEFT JOIN payment_term ON ath.payment_term_id = payment_term.payment_term_id
  LEFT JOIN sd_so_line sdsl ON atl.sd_so_line_id = sdsl.sd_so_line_id 
  LEFT JOIN sd_so_header sdsh ON sdsh.sd_so_header_id = sdsl.sd_so_header_id
  LEFT JOIN  org ON sdsl.shipping_org_id = org.org_id
  LEFT JOIN item ON sdsl.item_id_m = item.item_id_m AND item.org_id = sdsl.shipping_org_id

  WHERE ath.ar_customer_id = ar_customer.ar_customer_id
  AND ship_address.address_id = ath.ship_to_id
  AND bill_address.address_id = ath.bill_to_id


";
 }

}

//end of so_detail class
?>