<?php

class ar_receipt_all_v extends dbObject {

 public static $form_class_name = "ar_receipt_header";
 public static $table_name = "ar_receipt_all_v";
 public static $primary_column = "ar_receipt_header_id";
 public $field_a = [
		 'ar_receipt_header_id',
		 'bu_org_id',
		 'ar_receipt_source_id',
		 'receipt_number',
		 'receipt_status',
		 'header_amount',
		 'doc_currency',
		 'currency',
		 'exchange_rate_type',
		 'exchange_rate',
		 'receipt_type',
		 'document_date',
		 'document_number',
		 'ar_receipt_line_id',
		 'line_number',
		 'line_type',
		 'amount',
		 'line_description',
		 'gl_amount',
		 'customer_number',
		 'customer_name',
		 'customer_type',
		 'customer_category',
		 'customer_relationship',
		 'profile_name',
		 'customer_credit_class',
		 'ar_customer_site_id',
		 'customer_site_number',
		 'customer_site_name',
		 'customer_site_type',
 ];
 public $initial_search = [
		 'receipt_number',
		 'receipt_status',
		 'receipt_type',
		 'document_date',
		 'document_number',
		 'customer_number',
		 'customer_name',
		 'customer_type',
 ];
 public $dateField = [
		 'need_by_date',
		 'promise_date'
 ];
 public $search = [
		 '_update_path' => 'form.php?class_name=ar_receipt_header',
		 '_show_update_path' => 1,
		 '_view_path' => 'form.php?class_name=ar_receipt_header',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Receipt View  "; //page Title
// public $option_lists = [
//		 'payment_types' => 'ar_receipt_TYPE',
// ];
 public $search_functions = [
		 'Organization' => 'search_bu_name',
 ];
 public $ar_receipt_header_id;
 public $bu_org_id;
 public $ar_receipt_source_id;
 public $receipt_number;
 public $receipt_status;
 public $header_amount;
 public $doc_currency;
 public $currency;
 public $exchange_rate_type;
 public $exchange_rate;
 public $receipt_type;
 public $document_date;
 public $document_number;
 public $ar_receipt_line_id;
 public $line_number;
 public $line_type;
 public $amount;
 public $line_description;
 public $gl_amount;
 public $customer_number;
 public $customer_name;
 public $customer_type;
 public $customer_category;
 public $customer_relationship;
 public $profile_name;
 public $customer_credit_class;
 public $ar_customer_site_id;
 public $customer_site_number;
 public $customer_site_name;
 public $customer_site_type;

 private function create_ar_receipt_all_v() {
	$sql = "
CREATE OR REPLACE VIEW ar_receipt_all_v
(
ar_receipt_header_id, bu_org_id, ar_receipt_source_id, receipt_number, receipt_status,
header_amount, doc_currency, currency, exchange_rate_type, exchange_rate, 
receipt_type, document_date, document_number, 
ar_receipt_line_id, line_number, line_type, amount, line_description, gl_amount,
customer_number, customer_name, customer_type, customer_category, customer_relationship, 
profile_name, customer_credit_class,
ar_customer_site_id, customer_site_number, customer_site_name, customer_site_type
)
AS
SELECT 
arrh.ar_receipt_header_id, arrh.bu_org_id, arrh.ar_receipt_source_id, arrh.receipt_number, arrh.receipt_status,
arrh.header_amount, arrh.doc_currency, arrh.currency, arrh.exchange_rate_type, arrh.exchange_rate, 
arrh.receipt_type, arrh.document_date, arrh.document_number, 
arrl.ar_receipt_line_id, arrl.line_number, arrl.line_type, arrl.amount, arrl.line_description, arrl.gl_amount,
cust.customer_number, cust.customer_name, cust.customer_type, cust.customer_category, cust.customer_relationship, 
cust.profile_name, cust.customer_credit_class,
cust_site.ar_customer_site_id, cust_site.customer_site_number, cust_site.customer_site_name, cust_site.customer_site_type

 
FROM ar_receipt_header arrh,
ar_receipt_line arrl,
ar_transaction_header arth,
ar_customer cust,
ar_customer_site cust_site

WHERE arrh.ar_receipt_header_id = arrl.ar_receipt_header_id
AND arrl.ar_transaction_header_id = arth.ar_transaction_header_id
AND arrh.ar_customer_id = cust.ar_customer_id
AND arrh.ar_customer_site_id = cust_site.ar_customer_site_id


";
 }

}

//end of ap_transaction_detail class
?>