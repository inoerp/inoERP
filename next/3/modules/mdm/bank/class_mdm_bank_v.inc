<?php

class mdm_bank_v extends dbObject {
 
 public static $form_class_name = "mdm_bank_header";

 public static $table_name = "mdm_bank_v";
 public static $primary_column = "mdm_bank_header_id";
 public static $key_column = 'branch_name';
 public static $module = "mdm";
 public $field_a = [
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
 public $initial_search = [
		 'bank_name',
		 'bank_number',
		 'branch_name',
		 'branch_number',
 ];
 public $column = [
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
		 '_update_path' => 'form.php?class_name=mdm_bank_header',
		 '_show_update_path' => 1,
		 '_view_path' => 'form.php?class_name=mdm_bank_header',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Bank View ";
 
 public $mdm_bank_header_id;
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

 private function create_mdm_bank_v() {
	$sql = "
CREATE OR REPLACE VIEW mdm_bank_v
(
mdm_bank_header_id, country, bank_name, bank_number, description, bank_name_short, bank_name_alt, 
tax_reg_no, tax_payer_id,
branch_name,branch_country,branch_number,mdm_bank_site_id,branch_name_short,branch_name_alt, 
ifsc_code,swift_code,routing_number,iban_code,branch_tax_reg_no,branch_tax_payer_id,site_address_id
)
AS
SELECT mbh.mdm_bank_header_id, mbh.country, mbh.bank_name, mbh.bank_number, mbh.description, mbh.bank_name_short, mbh.bank_name_alt, 
mbh.tax_reg_no, mbh.tax_payer_id,
mbs.branch_name, mbs.country, mbs.branch_number, mbs.mdm_bank_site_id, mbs.branch_name_short, mbs.branch_name_alt, 
mbs.ifsc_code, mbs.swift_code, mbs.routing_number, mbs.iban_code, mbs.tax_reg_no, mbs.tax_payer_id, mbs.site_address_id

FROM mdm_bank_header mbh,
mdm_bank_site mbs
WHERE mbs.mdm_bank_header_id =  mbh.mdm_bank_header_id

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
