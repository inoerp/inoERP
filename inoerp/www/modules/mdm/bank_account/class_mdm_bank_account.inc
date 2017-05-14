<?php
/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * mdm_bank_account
 * Contains all the onhand information, such as - bank_name, bank_number, description,  bank_name_alt, etc.
 * 
 */
 class mdm_bank_account extends dbObject {

  public static $table_name = "mdm_bank_account";
  public static $primary_column = "mdm_bank_account_id";
  public static $key_column = 'account_number';
  public static $module = "mdm";
  public static $account_usage_a = [
   'INTERNAL' => 'Internal',
   'SUPPLIER' => 'Supplier',
   'CUSTOMER' => 'Customer',
  ];
  public $field_a = [
   'mdm_bank_account_id',
   'mdm_bank_header_id',
   'mdm_bank_site_id',
   'account_number',
			'currency_code',
   'description',
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
   'hr_cash_ac_id',
   'hr_cash_clearing_ac_id',
   'hr_bank_charge_ac_id',
   'hr_exchange_gl_ac_id',
   'netting_ac_cb',
   'minimum_payment',
   'maximum_payment',
   'contact_id',
   'ap_payment_method_id',
   'status',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'mdm_bank_account_id',
   'mdm_bank_header_id',
   'mdm_bank_site_id',
   'account_number',
   'description'
  ];
  public $checkbox = [
   "netting_ac_cb",
  ];
  public $column = [
   'mdm_bank_account_id',
   'mdm_bank_header_id',
   'mdm_bank_site_id',
   'account_number',
   'description',
  ];
  public $fields_inForm_notInDataBase = [
   'country',
   'bank_name',
   'bank_number',
   'description',
   'bank_name_short',
   'bank_name_alt',
   'branch_name',
   'branch_number',
   'ifsc_code',
   'swift_code',
   'routing_number',
   'iban_code',
   "customer_name",
   "customer_number",
   "customer_site_name",
   'supplier_name',
   'supplier_number'
  ];
  public $account = [
   'cash_ac_id',
   'cash_clearing_ac_id',
   'bank_charge_ac_id',
   'exchange_gl_ac_id',
  ];
  public $number_fields = [
   'minimum_payment',
   'maximum_payment',
  ];
  public $requiredField = [
   'mdm_bank_header_id',
   'mdm_bank_site_id',
   'account_number',
   'account_usage',
   'account_type',
  ];
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " Bank Accounts"; //page Title
  public $option_lists = [
   'account_type' => 'MDM_BANK_ACCOUNT_TYPE',
  ];
  public $mdm_bank_account_id;
  public $mdm_bank_header_id;
  public $mdm_bank_site_id;
  public $account_number;
  public $description;
  public $account_usage;
  public $account_type;
	public $currency_code;
  public $bu_org_id;
  public $supplier_id;
  public $supplier_site_id;
  public $ar_customer_id;
  public $ar_customer_site_id;
  public $cash_ac_id;
  public $cash_clearing_ac_id;
  public $bank_charge_ac_id;
  public $exchange_gl_ac_id;
   public $hr_cash_ac_id;
  public $hr_cash_clearing_ac_id;
  public $hr_bank_charge_ac_id;
  public $hr_exchange_gl_ac_id;
  public $netting_ac_cb;
  public $minimum_payment;
  public $maximum_payment;
  public $contact_id;
  public $ap_payment_method_id;
  public $status;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $country;
  public $bank_name;
  public $bank_number;
  public $bank_name_short;
  public $bank_name_alt;
  public $branch_name;
  public $branch_number;
  public $ifsc_code;
  public $swift_code;
  public $routing_number;
  public $iban_code;
  public $customer_name;
  public $customer_number;
  public $customer_site_name;
  public $supplier_name;
  public $supplier_number;
  public $supplier_site_name;

  Public static function bank_account_type() {
   $option_header = option_header::find_by_name('MDM_BANK_ACCOUNT_TYPE');
   $lines = option_line::find_by_option_id($option_header->option_header_id);
   return $lines;
  }

  public function findBy_org_id($org_id) {
   global $db;
   $sql = "SELECT * FROM mdm_bank_account where org_id=:org_id ";
   $sql = ino_perPageSql_i($sql, 1);
   $param_a = ['org_id'];
   $value_a = ['org_id' => $org_id];
   $result = $db->findBy_sql($sql, $param_a, $value_a);
   return !empty($result) ? array_pop($result) : false;
  }

  public function findRelatedDetail_ByOrgId($org_id = '') {
   global $db;
   if (!empty($org_id)) {
    $orgid = $org_id;
   } else {
    $orgid = $this->org_id;
   }
   $sql = " SELECT org.org , org.org_id , org.code , org.type , 
	 org.description, org.enterprise_org_id , org.legal_org_id, 
	 org.business_org_id , org.mdm_bank_account_org_id , org.status, legal.ledger_id,
	 legal.legal_id, legal.legal_org_type, legal. country_of_registration, 
	 legal.balancing_segments, business.business_id, business.business_org_type, 
	 business.cash_ac_id, business.manager ";

   $sql .= " FROM  org
      LEFT JOIN mdm_bank_account ON org.org_id = mdm_bank_account.org_id
      LEFT JOIN legal ON legal.org_id = org.legal_org_id
      LEFT JOIN business ON business.org_id = org.business_org_id ";

   $sql .= " WHERE org.org_id = :org_id LIMIT 1";

   $value_a = ['org_id' => $orgid];
   $result = $db->findBySql($sql, $value_a);
   return !empty($result) ? array_pop($result) : false;
  }

 }

//end of mdm_bank_account_org class
?>
