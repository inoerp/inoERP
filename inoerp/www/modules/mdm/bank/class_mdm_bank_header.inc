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
 * mdm_bank_header
 * Contains all the onhand information, such as - bank_name, bank_number, description,  bank_name_alt, etc.
 * 
 */
class mdm_bank_header extends dbObject {

 public static $table_name = "mdm_bank_header";
 public static $dependent_classes = ['mdm_bank_site', 'extn_contact'];
 public static $primary_column = "mdm_bank_header_id";
 public static $key_column = 'bank_name';
 public static $module = "mdm";
 public static $system_info = [
  'name' => 'Bank',
  'number' => '9401',
  'description' => 'Define and mainten banks',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'dependent_class' => array('mdm_bank_site', 'mdm_bank_account'),
  'primary_entity_cb' => '',
  'module_name' => 'mdm',
  'weight' => 1
 ];
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
  'address_id',
  'contact_id',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'country',
  'bank_name',
  'bank_number',
  'description',
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
 ];
 public $numberField = [
  'bank_number',
 ];
 public $requiredField = [
  'country',
  'bank_name',
 ];
 public $addressField = [
  "address_id"
 ];
 public $fields_inForm_notInDataBase = [
  'header_address_name',
  'header_address',
  'header_country',
  'header_postal_code',
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=mdm_bank_header',
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Banks "; //page Title
 public $mdm_bank_header_id;
 public $country;
 public $bank_name;
 public $bank_number;
 public $description;
 public $bank_name_short;
 public $bank_name_alt;
 public $tax_reg_no;
 public $tax_payer_id;
 public $address_id;
 public $contact_id;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $header_address_name;
 public $header_address;
 public $header_country;
 public $header_postal_code;

 public function _before_showing() {
  $address = new address();
  if (!empty($this->address_id)) {
   $address->findBy_id($this->address_id);
   $this->header_address_name = $address->address_name;
   $this->header_address = $address->address;
   $this->header_country = $address->country;
   $this->header_postal_code = $address->postal_code;
  }
 }

 public static function find_by_mdm_bank_header_number($mdm_bank_header_number) {
  global $db;
  $sql = "SELECT * FROM "
   . self::$table_name
   . " where mdm_bank_header_number LIKE '%{$mdm_bank_header_number}%'";
   $sql = ino_perPageSql_i($sql, 1);
  $result = $db->query($sql);
  $data = array();
  if ($result && mysql_num_rows($result)) {
   while ($row = $db->fetch_array($result)) {
    $data[] = array(
     'label' => $row['mdm_bank_header_number'],
     'mdm_bank_header_number' => $row['mdm_bank_header_number'],
     'mdm_bank_header_id' => $row['mdm_bank_header_id'],
     'description' => $row['mdm_bank_header_description']
    );
   }
  }

  return $data;
 }

 public static function find_all_assigned_orgs($mdm_bank_header_id) {
  global $db;
  $sql = "SELECT * FROM " .
   'mdm_bank_header_bu' .
   " where mdm_bank_header_id= '{$mdm_bank_header_id}' ";
  $result = $db->result_array_assoc($sql);
  return $result;
 }

 public function findBy_mdm_bank_header_name($limit = 30) {
  global $db;
  $sql = " SELECT * FROM "
   . self::$table_name
   . " where mdm_bank_header_name LIKE :mdm_bank_header_name ";
  $sql = ino_perPageSql_i($sql, $limit);
  $param_a = ['mdm_bank_header_name'];
  $mdm_bank_header_name = '%' . $this->mdm_bank_header_name . '%';
  $value_a = [ 'mdm_bank_header_name' => $mdm_bank_header_name];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !(empty($result)) ? $result : false;
 }

 public function findBy_mdm_bank_headerName_OrgId($limit = 30) {
  global $db;
//	$sql = " SELECT * FROM mdm_bank_header_all_v "
//					. " where mdm_bank_header_name LIKE :mdm_bank_header_name AND org_id = :org_id "
//					. " LIMIT $limit";
  $sql = " SELECT su.mdm_bank_header_name, su.mdm_bank_header_id, su.mdm_bank_header_number ";
  $sql .= " FROM mdm_bank_header su ";
  $sql .= " RIGHT JOIN mdm_bank_header_bu sb ON  sb.mdm_bank_header_id = su.mdm_bank_header_id ";
  $sql .= " WHERE  sb.org_id = :org_id ";
  $sql .= " AND  su.mdm_bank_header_name LIKE :mdm_bank_header_name ";

  $param_a = ['mdm_bank_header_name', 'org_id'];
  $mdm_bank_header_name = '%' . $this->mdm_bank_header_name . '%';
  $value_a = [ 'mdm_bank_header_name' => $mdm_bank_header_name, 'org_id' => $this->org_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !(empty($result)) ? $result : false;
 }

 public function searchBy_mdm_bank_header_name() {
  $result = $this->findBy_mdm_bank_header_name();
  $data = array();
  if (!empty($result)) {
   foreach ($result as $obj) {
    $data[] = array(
     'label' => $obj->mdm_bank_header_name,
     'mdm_bank_header_id' => $obj->mdm_bank_header_id,
     'mdm_bank_header_number' => $obj->mdm_bank_header_number
    );
   }
  }
  return $data;
 }

 public function searchBy_mdm_bank_headerName_orgId() {
  $result = $this->findBy_mdm_bank_headerName_OrgId();
  $data = array();
  if (!empty($result)) {
   foreach ($result as $obj) {
    $data[] = array(
     'label' => $obj->mdm_bank_header_name,
     'mdm_bank_header_id' => $obj->mdm_bank_header_id,
     'mdm_bank_header_number' => $obj->mdm_bank_header_number
    );
   }
  }
  return $data;
 }

 public function copy($mdm_bank_header_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM mdm_bank_header WHERE `mdm_bank_header_id` = '{$mdm_bank_header_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `mdm_bank_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `mdm_bank_header_id` = '{$mdm_bank_header_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `mdm_bank_header` SELECT * FROM tmptable WHERE `mdm_bank_header_id` = '' ";
    if ($db->query($sql3)) {
     $this->mdm_bank_header_id = $db->insert_id();
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  }
  return $this->msg;
 }

 private function create_mdm_bank_header_all_v() {

  $sql = "
CREATE OR REPLACE VIEW mdm_bank_header_all_v
(
mdm_bank_header_id,mdm_bank_header_number, mdm_bank_header_name ,
mdm_bank_header_site_id, mdm_bank_header_site_number, mdm_bank_header_site_name,
 mdm_bank_header_type, tax_country, created_by,
customer_id, status,
creation_date, last_update_by, last_update_date,
 mdm_bank_header_bu_id, org_id, liability_account_id,
payable_account_id, payment_discount_account_id, pre_payment_account_id,
site_tax_country, site_tax_reg_no, site_status,
currency, payment_term_id)
AS
SELECT 
su.mdm_bank_header_id,su.mdm_bank_header_number, su.mdm_bank_header_name ,
ss.mdm_bank_header_site_id, ss.mdm_bank_header_site_number, ss.mdm_bank_header_site_name,
 su.mdm_bank_header_type, su.tax_country, su.created_by,
su.customer_id, su.status,
su.creation_date, su.last_update_by, su.last_update_date,
 sb.mdm_bank_header_bu_id, sb.org_id, liability_account_id,
payable_account_id, payment_discount_account_id, pre_payment_account_id,
ss.site_tax_country, ss.site_tax_reg_no, ss.status,
ss.currency, ss.payment_term_id

FROM mdm_bank_header su
LEFT JOIN mdm_bank_header_site ss ON ss.mdm_bank_header_id = su.mdm_bank_header_id
LEFT JOIN mdm_bank_header_bu sb ON su.mdm_bank_header_id = sb.mdm_bank_header_id
";


  $sql = "
CREATE OR REPLACE VIEW po_all_v
(
po_header_id, bu_org_id, po_type, po_number, mdm_bank_header_id, mdm_bank_header_site_id, buyer, currency, header_amount, po_status,
payment_term_id,
mdm_bank_header_name, mdm_bank_header_number,
mdm_bank_header_site_name, mdm_bank_header_site_number,
payment_term, payment_term_description,
po_line_id, line_type, line_number,	item_id, item_description, line_description, line_quantity, unit_price, line_price,
item_number, uom_id, item_status,
po_detail_id, shipment_number, ship_to_id, sub_inventory_id, locator_id, requestor, quantity,
need_by_date, promise_date,
po_received_quantity, po_accepted_quantity, po_delivered_quantity, po_invoiced_quantity, po_paid_quantity,
ship_to_org, created_by, creation_date, last_update_by, last_update_date
)
AS
SELECT 
su.mdm_bank_header_id,su.mdm_bank_header_number, su.mdm_bank_header_name ,
ss.mdm_bank_header_site_id, ss.mdm_bank_header_site_number, ss.mdm_bank_header_site_name,
 su.mdm_bank_header_type, su.tax_country, su.created_by,
su.customer_id, su.tax_country, su.tax_country, su.status,
su.creation_date, su.last_update_by, su.last_update_date,
 sb.mdm_bank_header_bu_id, sb.org_id, sb.mdm_bank_header_id, liability_account_id,
payable_account_id, payment_discount_account_id, pre_payment_account_id,
ss.mdm_bank_header_id, ss.site_tax_country, ss.site_tax_reg_no, ss.status,
ss.currency, ss.payment_term_id

FROM mdm_bank_header su
LEFT JOIN mdm_bank_header_site ss ON ss.mdm_bank_header_id = su.mdm_bank_header_id
LEFT JOIN mdm_bank_header_bu sb ON su.mdm_bank_header_id = sb.mdm_bank_header_id
";
 }

}

//end of mdm_bank_header class
?>