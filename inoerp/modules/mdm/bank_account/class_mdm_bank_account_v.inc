<?php

class mdm_bank_account_v extends dbObject {

 public static $form_class_name = "mdm_bank_account";
 public static $table_name = "mdm_bank_account_v";
 public static $primary_column = "mdm_bank_account_id";
 public static $key_column = 'account_number';
 public static $module = "mdm";
 public $field_a = [
		 'mdm_bank_account_id',
		 'account_number',
		 'account_description',
		 'account_usage',
		 'account_type',
		 'bu_org_id',
		 'supplier_id',
		 'supplier_site_id',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'cash_ac_id',
		 'cash_clearing_ac_id',
		 'bank_charge_ac_id',
		 'exchange_gl_ac_id',
		 'netting_ac_cb',
		 'minimum_payment',
		 'maximum_payment',
		 'contact_id',
		 'ap_payment_method_id',
		 'mdm_bank_header_id',
		 'country',
		 'bank_name',
		 'bank_number',
		 'description',
		 'bank_name_short',
		 'bank_name_alt',
		 'tax_reg_no',
		 'tax_payer_id',
		 'branch_name',
		 'branch_country',
		 'branch_number',
		 'mdm_bank_site_id',
		 'branch_name_short',
		 'branch_name_alt',
		 'ifsc_code',
		 'swift_code',
		 'routing_number',
		 'iban_code',
		 'branch_tax_reg_no',
		 'branch_tax_payer_id',
		 'site_address_id',
		 'supplier_name', 
		 'supplier_site_name', 
		 'customer_name', 
		 'customer_number'
 ];
 public $initial_search = [
		 'account_number',
		 'bank_name',
		 'bank_number',
		 'branch_name',
		 'branch_number',
		 		 'supplier_name', 
		 'customer_name', 
 ];
 public $column = [
		 'mdm_bank_account_id',
		 'account_number',
		 'mdm_bank_header_id',
		 'country',
		 'bank_name',
		 'bank_number',
		 'description',
		 'bank_name_short',
		 'bank_name_alt',
		 'tax_reg_no',
		 'tax_payer_id',
		 'branch_name',
		 'branch_country',
		 'branch_number',
		 'mdm_bank_site_id',
		 'branch_name_short',
		 'branch_name_alt',
		 'ifsc_code',
		 'swift_code',
		 'routing_number',
		 'iban_code',
		 'branch_tax_reg_no',
		 'branch_tax_payer_id',
		 'site_address_id',
 ];
 public $option_lists = [
		 'country' => 'COUNTRY',
 ];
 public $search = [
		 '_update_path' => 'form.php?class_name=mdm_bank_account',
		 '_show_update_path' => 1,
		 '_view_path' => 'form.php?class_name=mdm_bank_account',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Bank View ";
 public $mdm_bank_header_id;
 public $account_number;
 public $country;
 public $bank_name;
 public $bank_number;
 public $description;
 public $bank_name_short;
 public $bank_name_alt;
 public $tax_reg_no;
 public $tax_payer_id;
 public $branch_name;
 public $branch_country;
 public $branch_number;
 public $mdm_bank_site_id;
 public $branch_name_short;
 public $branch_name_alt;
 public $ifsc_code;
 public $swift_code;
 public $routing_number;
 public $iban_code;
 public $branch_tax_reg_no;
 public $branch_tax_payer_id;
 public $site_address_id;

 private function create_mdm_bank_account_v() {
	$sql = "
CREATE OR REPLACE VIEW mdm_bank_account_v
(
mdm_bank_account_id, account_number,  account_description, account_usage, account_type, bu_org_id,
supplier_id,supplier_site_id, ar_customer_id, ar_customer_site_id, cash_ac_id, cash_clearing_ac_id,
bank_charge_ac_id, 	exchange_gl_ac_id,  netting_ac_cb,	minimum_payment, maximum_payment, contact_id,
ap_payment_method_id, 
mdm_bank_header_id, country, bank_name, bank_number, description, bank_name_short, bank_name_alt, 
tax_reg_no, tax_payer_id,
branch_name,branch_country,branch_number,mdm_bank_site_id,branch_name_short,branch_name_alt, 
ifsc_code,swift_code,routing_number,iban_code,branch_tax_reg_no,branch_tax_payer_id,site_address_id,
supplier_name, supplier_site_name, customer_name, customer_number
)
AS
SELECT  mba.mdm_bank_account_id,  mba.account_number,   mba.description,  mba.account_usage,  mba.account_type,  mba.bu_org_id,
 mba.supplier_id, mba.supplier_site_id,  mba.ar_customer_id,  mba.ar_customer_site_id,  mba.cash_ac_id,  mba.cash_clearing_ac_id,
 mba.bank_charge_ac_id, 	mba.exchange_gl_ac_id,   mba.netting_ac_cb,	 mba.minimum_payment,  mba.maximum_payment,  mba.contact_id,
 mba.ap_payment_method_id,
mbh.mdm_bank_header_id, mbh.country, mbh.bank_name, mbh.bank_number, mbh.description, mbh.bank_name_short, mbh.bank_name_alt, 
mbh.tax_reg_no, mbh.tax_payer_id,
mbs.branch_name, mbs.country, mbs.branch_number, mbs.mdm_bank_site_id, mbs.branch_name_short, mbs.branch_name_alt, 
mbs.ifsc_code, mbs.swift_code, mbs.routing_number, mbs.iban_code, mbs.tax_reg_no, mbs.tax_payer_id, mbs.site_address_id,
sav.supplier_name, sav.supplier_site_name, acv.customer_name, acv.customer_number

FROM 
mdm_bank_account mba
LEFT JOIN supplier_all_v sav ON mba.supplier_site_id = sav.supplier_site_id
LEFT JOIN ar_customer_v acv ON mba.ar_customer_site_id = acv.ar_customer_site_id
LEFT JOIN org_v ov ON ov.org_id = mba.bu_org_id ,
mdm_bank_header mbh,
mdm_bank_site mbs
WHERE mbs.mdm_bank_header_id =  mbh.mdm_bank_header_id
AND mbh.mdm_bank_header_id =  mba.mdm_bank_header_id
AND mbs.mdm_bank_site_id =  mba.mdm_bank_site_id

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

}

?>
