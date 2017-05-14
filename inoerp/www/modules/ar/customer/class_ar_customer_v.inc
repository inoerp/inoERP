<?php

class ar_customer_v extends dbObject {

 
 public static $table_name = "ar_customer_v";
 public static $primary_column = "ar_customer_id";
 public static $form_class_name = "ar_customer";
 public static $key_column = 'customer_name';
 public static $module = "mdm";
 public $field_a = [
  'ar_customer_id',
  'customer_number',
  'customer_name',
  'ar_customer_site_id',
  'customer_site_number',
  'customer_site_name',
  'status',
  'creation_date',
  'last_update_by',
  'last_update_date',
  'site_tax_country',
  'site_tax_reg_no',
  'site_status',
  'currency',
  'payment_term_id',
 ];
 public $initial_search = [
  'customer_number',
  'customer_name',
  'customer_site_number',
  'customer_site_name',
 ];
 public $column = [
  'ar_customer_id',
  'customer_number',
  'customer_name',
  'ar_customer_site_id',
  'customer_site_number',
  'customer_site_name',
  'status',
  'creation_date',
  'last_update_by',
  'last_update_date',
  'site_tax_country',
  'site_tax_reg_no',
  'site_status',
  'currency',
  'payment_term_id',
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=ar_customer',
  '_show_update_path' => 1,
  '_view_path' => 'form.php?class_name=ar_customer',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Customer - Find All Customers "; //page Title
 public $ar_customer_id;
 public $customer_number;
 public $customer_name;
 public $ar_customer_site_id;
 public $customer_site_number;
 public $customer_site_name;
 public $status;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $site_tax_country;
 public $site_tax_reg_no;
 public $site_status;
 public $currency;
 public $payment_term_id;

 private function create_ar_customer_v() {
  $sql = "
CREATE OR REPLACE VIEW ar_customer_v
(
ar_customer_id,customer_number, customer_name ,
ar_customer_site_id, customer_site_number, customer_site_name,
status,creation_date, last_update_by, last_update_date,
 site_tax_country, site_tax_reg_no, site_status,
currency, payment_term_id)
AS
SELECT 
ac.ar_customer_id,ac.customer_number, ac.customer_name ,
acs.ar_customer_site_id, acs.customer_site_number, acs.customer_site_name,
ac.status,ac.creation_date, ac.last_update_by, ac.last_update_date,
 acs.site_tax_country, acs.site_tax_reg_no, acs.status,
acs.currency, acs.payment_term_id

FROM ar_customer ac
LEFT JOIN ar_customer_site acs ON acs.ar_customer_id = ac.ar_customer_id
";
 }

}

//end of po_detail class
?>

