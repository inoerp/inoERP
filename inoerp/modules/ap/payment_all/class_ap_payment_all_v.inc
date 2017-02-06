<?php

class ap_payment_all_v extends dbObject {

 public static $form_class_name = "ap_payment_header";
 public static $table_name = "ap_payment_all_v";
 public static $primary_column = "ap_payment_header_id";
 public $field_a = [
		 'ap_payment_header_id',
		 'bu_org_id',
		 'payment_type',
		 'payment_number',
		 'supplier_id',
		 'supplier_site_id',
		 'from_bank_header_id',
		 'header_amount',
		 'currency',
		 'document_number',
		 'payment_status',
		 'gl_journal_header_id',
		 'ap_payment_line_id',
		 'line_number',
		 'amount',
		 'line_description',
		 'line_status',
		 'ap_transaction_header_id',
		 'transaction_type',
		 'transaction_number',
		 'hr_employee_id',
		 'apth_currency',
		 'apth_header_amount',
		 'transaction_status',
		 'paid_amount',
		 'apth_payment_status',
		 'supplier_name',
		 'supplier_number',
		 'supplier_site_name',
		 'supplier_site_number',
 ];
 public $initial_search = [
		 'payment_number',
		 'transaction_number',
		 'supplier_name',
		 'supplier_number',
		 'supplier_site_name',
 ];
 public $dateField = [
		 'need_by_date',
		 'promise_date'
 ];
 public $search = [
		 '_update_path' => 'form.php?class_name=ap_payment_header',
		 '_show_update_path' => 1,
		 '_view_path' => 'form.php?class_name=ap_payment_header',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " AP Payment View  "; //page Title
 public $option_lists = [
		 'payment_types' => 'AP_PAYMENT_TYPE',
 ];
 public $search_functions = [
		 'Organization' => 'search_bu_name',
 ];
 public $ap_payment_header_id;
 public $bu_org_id;
 public $payment_type;
 public $payment_number;
 public $supplier_id;
 public $supplier_site_id;
 public $from_bank_header_id;
 public $header_amount;
 public $currency;
 public $hr_employee_id;
 public $payment_status;
 public $gl_journal_header_id;
 public $ap_payment_line_id;
 public $line_number;
 public $amount;
 public $line_description;
 public $line_status;
 public $ap_transaction_header_id;
 public $transaction_type;
 public $transaction_number;
 public $document_owner;
 public $apth_currency;
 public $apth_header_amount;
 public $transaction_status;
 public $paid_amount;
 public $apth_payment_status;
 public $supplier_name;
 public $supplier_number;
 public $supplier_site_name;
 public $supplier_site_number;

 private function create_ap_payment_all_v() {
	$sql = "
CREATE OR REPLACE VIEW ap_payment_all_v
(
ap_payment_header_id, bu_org_id, payment_type,
payment_number, supplier_id, supplier_site_id, from_bank_header_id,
header_amount,  currency, document_number, payment_status, gl_journal_header_id,
ap_payment_line_id, line_number, amount, line_description, line_status,
ap_transaction_header_id, transaction_type, transaction_number,
hr_employee_id, apth_currency, apth_header_amount, transaction_status,
paid_amount,apth_payment_status,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number
)
AS
SELECT 
apph.ap_payment_header_id, apph.bu_org_id, apph.payment_type,
apph.payment_number, apph.supplier_id, apph.supplier_site_id, apph.from_bank_header_id,
apph.header_amount,  apph.currency, apph.document_number, apph.payment_status, apph.gl_journal_header_id,
appl.ap_payment_line_id, appl.line_number, appl.amount, appl.line_description, appl.line_status,
apth.ap_transaction_header_id, apth.transaction_type, apth.transaction_number,
apth.hr_employee_id, apth.currency, apth.header_amount, apth.transaction_status,
apth.paid_amount, apth.payment_status,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number

FROM ap_payment_header apph,
ap_payment_line appl,
ap_transaction_header apth,
supplier,
supplier_site

WHERE apph.ap_payment_header_id = appl.ap_payment_header_id
AND appl.ap_transaction_header_id = apth.ap_transaction_header_id
AND apph.supplier_id = supplier.supplier_id
AND apph.supplier_site_id = supplier_site.supplier_site_id


";
 }

}

//end of ap_transaction_detail class
?>