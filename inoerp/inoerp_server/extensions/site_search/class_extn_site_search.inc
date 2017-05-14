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
 * site_search_form
 * Contains all the site_search_form information, such as - site_search_form_id, type, description,  site_search_form_name, etc.
 * 
 */
class extn_site_search extends dbObject {

 public static $table_name = "site_search_form";
 public static $primary_column = "site_search_form_id";
 public static $key_column = 'site_search_form_name';
 public static $module = "org";
 public static $system_info = [
  'name' => 'Site Search',
  'number' => '10038',
  'description' => 'Define and mainten site_search_formes',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'org',
  'weight' => 6
 ];
 public static $search_document_list_a = [
  'all' => '&#xf103; All Elements',
  'address' => '&#xf0c9; Address',
  'ap_payment_header' => '&#xf0d6; AP Payment',
  'ap_transaction_header' => '&#xf05a; AP Invoice',
  'ar_transaction_header' => '&#xf05a; AR Invoice',
  'ar_receipt_header' => '&#xf0d6; AR Receipt',
  'mdm_bank_header' => '&#xf19c; Bank',
  'bc_label_format_header' => '&#xf080; Barcode',
  'bom_header' => '&#xf0e8; Bills Of Material',
  'cc_co_header' => '&#xf147; Change Order',
  'ar_customer' => '&#xf19c; Customer',
  'gl_calendar' => '&#xf073; GL Calendar',
  'gl_journal_header' => '&#xf02d; Journal',
  'inv_transaction' => '&#xf0ae; Inventory Transactions',
  'item' => '&#xf02c; Item',
  'org' => '&#xf19c; Org',
  'po_header' => '&#xf0f6; Purchase Order',
  'inv_receipt_header' => '&#xf096; PO Receipt',
  'all_bom_routing_v' => '&#xf085; Routing',
  'sd_so_header' => '&#xf07a; Sales Order',
  'sd_delivery_header' => '&#xf0d1; Sales Delivery',
  'supplier' => '&#xf19c; Supplier',
  'user' => '&#xf0f0; User',
 ];
 public $field_a = [
  "site_search_form_id",
  "type",
  "site_search_form_name",
  'mdm_tax_region_id',
  "description",
  "phone",
  "email",
  "website",
  "site_search_form",
  "country",
  "postal_code",
  "efid",
  "status",
  "rev_enabled",
  "rev_number",
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
 public $initial_search = [
  "site_search_form_name",
  "type",
  "description",
  "phone",
  "email",
  "website",
  "country",
  "postal_code"
 ];
 public $checkbox = [
  "rev_enabled",
 ];
 public $column = [
  "site_search_form_id",
  "site_search_form_name",
  "description",
  "phone",
  "email",
  "website",
  "country",
  "postal_code",
  'site_search_form'
 ];
 public $requiredField = [
  "site_search_form_name",
  "type"
 ];
 public $fields_inForm_notInDataBase = [
  "tax_region_name"
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=site_search_form',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " Address - Organization Addresses "; //page Title
 public $site_search_form_id;
 public $type;
 public $site_search_form_name;
 public $mdm_tax_region_id;
 public $description;
 private $_searched_data;
 private $_searched_document;

 Public static function extn_site_search_category() {
  $option_header = option_header::find_by_name('EXT_WEB_CONTACT_CATEGORY');
  $ol = new option_line();
  $lines = $ol->findBy_parentId($option_header->option_header_id);
  return $lines;
 }

 private function _get_search_data() {
  $sql = "";

  switch ($this->_searched_document) {
   case 'address':
    $sql = " ( SELECT 'address' as class_name, address_name as name , phone as number ,  description, status, 	address_id as primary_id , 'Address' as data_type "
     . " FROM 	address WHERE address_name LIKE '%" .
     $this->_searched_data . "%' OR 	phone LIKE '%" . $this->_searched_data . "%') ";
    break;

   case 'ap_payment_header':
    $sql = " ( SELECT 'ap_payment_header' as class_name, 	payment_type as name , payment_number as number ,  description, payment_status, 	ap_payment_header_id as primary_id , 'AP Payment' as data_type "
     . " FROM 	ap_payment_header WHERE 	payment_number LIKE '%" .
     $this->_searched_data . "%' OR 	description LIKE '%" . $this->_searched_data . "%') ";
    break;

   case 'ar_transaction_header':
    $sql = " ( SELECT 'ar_transaction_header' as class_name, 	transaction_type as name , transaction_number as number ,  description, transaction_status, 	ar_transaction_header_id as primary_id , 'AR Transaction' as data_type "
     . " FROM 	ar_transaction_header WHERE 	transaction_number LIKE '%" .
     $this->_searched_data . "%' OR 	description LIKE '%" . $this->_searched_data . "%') ";
    break;

   case 'ap_transaction_header':
    $sql = " ( SELECT 'ap_transaction_header' as class_name, 	transaction_type as name , transaction_number as number ,  description, 	payment_status, 	ap_transaction_header_id as primary_id , 'AP Transaction' as data_type "
     . " FROM 	ap_transaction_header WHERE 	transaction_number LIKE '%" .
     $this->_searched_data . "%' OR 	description LIKE '%" . $this->_searched_data . "%') ";
    break;

   case 'ar_receipt_header':
    $sql = " ( SELECT 'ar_receipt_header' as class_name, 	receipt_type as name , receipt_number as number ,  description, receipt_status, 	ar_receipt_header_id as primary_id , 'AR Receipt' as data_type "
     . " FROM 	ar_receipt_header WHERE 	receipt_number LIKE '%" .
     $this->_searched_data . "%' OR 	description LIKE '%" . $this->_searched_data . "%') ";
    break;

   case 'mdm_bank_header':
    $sql = " (SELECT 'mdm_bank_header' as class_name, bank_name as name , bank_number as number ,  description, status, mdm_bank_header_id	 as primary_id , 'Bank' as data_type"
     . " FROM 	mdm_bank_header WHERE  bank_name LIKE '%" .
     $this->_searched_data . "%' OR 	bank_number LIKE '%" . $this->_searched_data . "%')  ";
    break;

   case 'supplier':
    $sql = " (SELECT 'supplier' as class_name, supplier_name as name , supplier_number as number ,  supplier_type as description, status, supplier_id as primary_id , 'Supplier' as data_type "
     . " FROM 	supplier WHERE supplier_name LIKE '%" .
     $this->_searched_data . "%' OR supplier_number LIKE '%" . $this->_searched_data . "%')  ";
    break;

   case 'ar_customer':
    $sql = " (SELECT 'ar_customer' as class_name, customer_name as name , customer_number as number ,  customer_type as description, status, ar_customer_id as primary_id, 'Customer' as data_type "
     . " FROM 	ar_customer WHERE customer_name LIKE '%" .
     $this->_searched_data . "%' OR customer_number LIKE '%" . $this->_searched_data . "%')   ";
    break;

   case 'item':
    $sql = " (SELECT 'item' as class_name, product_line as name , item_number as number ,  	item_description as description, item_status as status, 	item_id_m as primary_id , 'Item' as data_type "
     . " FROM 	item WHERE item_number LIKE '%" .
     $this->_searched_data . "%' OR 	item_description LIKE '%" . $this->_searched_data . "%')    ";
    break;

   case 'org':
    $sql = " (SELECT 'org' as class_name, org as name , code as number ,  description, status, 	org_id as primary_id , 'Org' as data_type "
     . " FROM 	org WHERE org LIKE '%" .
     $this->_searched_data . "%' OR 	org_id LIKE '%" . $this->_searched_data . "%')  ";
    break;

   case 'bc_label_format_header':
    $sql = "     (SELECT 'bc_label_format_header' as class_name, 	format_name as name , 	bc_label_format_header_id as number ,  	description as description, 'NA' as status, bc_label_format_header_id as primary_id , 'Label Format' as data_type "
     . " FROM 	bc_label_format_header WHERE 	format_name LIKE '%" .
     $this->_searched_data . "%' OR 	bc_label_format_header_id LIKE '%" . $this->_searched_data . "%')   ";
    break;

   case 'bom_header':
    $sql = " (SELECT 'bom_header' as class_name, 	bom_revision as name , item_id_m as number ,  		alternate_bom as description, 'NA' as status, bom_header_id as primary_id , 'Bills Of Material' as data_type "
     . " FROM 	bom_header WHERE 	item_id_m LIKE '%" .
     $this->_searched_data . "%' OR 	alternate_bom LIKE '%" . $this->_searched_data . "%')    ";
    break;

   case 'cc_co_header':
    $sql = " (SELECT 'cc_co_header' as class_name, 	change_type as name , change_number as number ,  		alternate_bom as description,  status, cc_co_header_id as primary_id , 'Change Order' as data_type "
     . " FROM 	cc_co_header WHERE 	change_number LIKE '%" .
     $this->_searched_data . "%' OR 	change_type LIKE '%" . $this->_searched_data . "%')    ";
    break;

   case 'gl_calendar':
    $sql = " (SELECT 'gl_calendar' as class_name, 	name  , number ,  		calendar_type as description,  'NA' as status, gl_calendar_id as primary_id , 'Calendar' as data_type "
     . " FROM 	gl_calendar WHERE 	name LIKE '%" .
     $this->_searched_data . "%' OR 	calendar_type LIKE '%" . $this->_searched_data . "%')    ";
    break;

   case 'gl_journal_header':
    $sql = " (SELECT 'gl_journal_header' as class_name, journal_name as	name  , gl_journal_header_id as number , description,  status, gl_journal_header_id as primary_id , 'Calendar' as data_type "
     . " FROM 	gl_journal_header WHERE 	journal_name LIKE '%" .
     $this->_searched_data . "%' OR 		description LIKE '%" . $this->_searched_data . "%')    ";
    break;

   case 'inv_transaction':
    $sql = " (SELECT 'inv_transaction' as class_name, document_type as	name  , 	inv_transaction_id as number , description,  status, inv_transaction_id as primary_id , 'Inv Transaction' as data_type "
     . " FROM 	inv_transaction WHERE 	description LIKE '%" .
     $this->_searched_data . "%' OR 			inv_transaction_id LIKE '%" . $this->_searched_data . "%')    ";
    break;

   case 'po_header':
    $sql = " (SELECT 'po_header' as class_name, 	po_type as	name  , 	po_number as number , description,  po_status, po_header_id as primary_id , 'Purchase Order' as data_type "
     . " FROM 	po_header WHERE 		po_number LIKE '%" .
     $this->_searched_data . "%' OR 			description LIKE '%" . $this->_searched_data . "%')    ";
    break;

   case 'inv_receipt_header':
    $sql = "    (SELECT 'inv_receipt_header' as class_name, 		comment as	name  , 	receipt_number as number , 'NA',  status, inv_receipt_header_id as primary_id , 'Inv Receipt' as data_type "
     . " FROM 	inv_receipt_header WHERE 			comment LIKE '%" .
     $this->_searched_data . "%' OR 			receipt_number LIKE '%" . $this->_searched_data . "%')    ";
    break;

   case 'all_bom_routing_v':
    $sql = "    (SELECT 'inv_receipt_header' as class_name, 			item_description as	name  , 		item_number as number , 'NA',  status, bom_routing_header_id as primary_id , 'Routing' as data_type "
     . " FROM 	all_bom_routing_v WHERE 			item_description LIKE '%" .
     $this->_searched_data . "%' OR 			item_number LIKE '%" . $this->_searched_data . "%')    ";
    break;

   case 'sd_so_header':
    $sql = " (SELECT 'inv_receipt_header' as class_name, 			document_type as	name  , 		so_number as number , line_description,  status, sd_so_header_id as primary_id , 'Sales Order' as data_type "
     . " FROM 	sd_so_all_v  WHERE 			so_number LIKE '%" .
     $this->_searched_data . "%' OR 			line_description LIKE '%" . $this->_searched_data . "%')    ";
    break;

   case 'sd_delivery_header':
    $sql = " (SELECT 'inv_receipt_header' as class_name, 			sd_delivery_header_id as	name  , 		delivery_number as number , comment,  status, sd_delivery_header_id as primary_id , 'Sales Delivery' as data_type "
     . " FROM 	sd_delivery_header  WHERE 				delivery_number LIKE '%" .
     $this->_searched_data . "%' OR 			comment LIKE '%" . $this->_searched_data . "%')    ";
    break;

   case 'supplier':
    $sql = " (SELECT 'supplier' as class_name, 			supplier_name as	name  , 		supplier_number as number , 	supplier_type,  status, supplier_id as primary_id , 'Supplier' as data_type "
     . " FROM 	supplier  WHERE 				supplier_name LIKE '%" .
     $this->_searched_data . "%' OR 			supplier_number LIKE '%" . $this->_searched_data . "%')    ";
    break;

   case 'user':
    $sql = " (SELECT 'user' as class_name, 			username as	name  , 		hr_employee_id as number , 	last_name,  status, user_id as primary_id , 'User' as data_type "
     . " FROM 	user  WHERE 				username LIKE '%" .
     $this->_searched_data . "%' OR 			last_name LIKE '%" . $this->_searched_data . "%')    ";
    break;


   default:
    $sql = "(SELECT 'ar_customer' as class_name, customer_name as name , customer_number as number ,  customer_type as description, status, ar_customer_id as primary_id, 'Customer' as data_type "
     . " FROM 	ar_customer WHERE customer_name LIKE '%" .
     $this->_searched_data . "%' OR customer_number LIKE '%" . $this->_searched_data . "%') 
           UNION
           (SELECT 'supplier' as class_name, supplier_name as name , supplier_number as number ,  supplier_type as description, status, supplier_id as primary_id , 'Supplier' as data_type "
     . " FROM 	supplier WHERE supplier_name LIKE '%" .
     $this->_searched_data . "%' OR supplier_number LIKE '%" . $this->_searched_data . "%') 
               UNION
           (SELECT 'address' as class_name, address_name as name , phone as number ,  description, status, 	address_id as primary_id , 'Address' as data_type "
     . " FROM 	address WHERE address_name LIKE '%" .
     $this->_searched_data . "%' OR 	phone LIKE '%" . $this->_searched_data . "%') 
                   UNION
           (SELECT 'item' as class_name, product_line as name , item_number as number ,  	item_description as description, item_status as status, 	item_id_m as primary_id , 'Item' as data_type "
     . " FROM 	item WHERE item_number LIKE '%" .
     $this->_searched_data . "%' OR 	item_description LIKE '%" . $this->_searched_data . "%') 
                   UNION
           (SELECT 'org' as class_name, org as name , code as number ,  description, status, 	org_id as primary_id , 'Org' as data_type "
     . " FROM 	org WHERE org LIKE '%" .
     $this->_searched_data . "%' OR 	org_id LIKE '%" . $this->_searched_data . "%') 
           UNION
             (SELECT 'mdm_bank_header' as class_name, bank_name as name , bank_number as number ,  description, status, mdm_bank_header_id	 as primary_id , 'Bank' as data_type"
     . " FROM 	mdm_bank_header WHERE  bank_name LIKE '%" .
     $this->_searched_data . "%' OR 	bank_number LIKE '%" . $this->_searched_data . "%') 
     UNION
     ( SELECT 'ap_payment_header' as class_name, 	payment_type as name , payment_number as number ,  description, payment_status, 	ap_payment_header_id as primary_id , 'AP Payment' as data_type "
     . " FROM 	ap_payment_header WHERE 	payment_number LIKE '%" .
     $this->_searched_data . "%' OR 	description LIKE '%" . $this->_searched_data . "%')  
     UNION 
      ( SELECT 'ar_transaction_header' as class_name, 	transaction_type as name , transaction_number as number ,  description, transaction_status, 	ar_transaction_header_id as primary_id , 'AR Transaction' as data_type "
     . " FROM 	ar_transaction_header WHERE 	transaction_number LIKE '%" .
     $this->_searched_data . "%' OR 	description LIKE '%" . $this->_searched_data . "%')
    UNION 
     ( SELECT 'ar_receipt_header' as class_name, 	receipt_type as name , receipt_number as number ,  description, receipt_status, 	ar_receipt_header_id as primary_id , 'AR Receipt' as data_type "
     . " FROM 	ar_receipt_header WHERE 	receipt_number LIKE '%" .
     $this->_searched_data . "%' OR 	description LIKE '%" . $this->_searched_data . "%')
    UNION
    (SELECT 'bc_label_format_header' as class_name, 	format_name as name , bc_label_format_header_id as number ,  	description, 'NA' as status, bc_label_format_header_id as primary_id , 'Label Format' as data_type "
     . " FROM 	bc_label_format_header WHERE 	format_name LIKE '%" .
     $this->_searched_data . "%' OR 	bc_label_format_header_id LIKE '%" . $this->_searched_data . "%')
    UNION
    (SELECT 'bom_header' as class_name, 	bom_revision as name , item_id_m as number ,  		alternate_bom as description, 'NA' as status, bom_header_id as primary_id , 'Bills Of Material' as data_type "
     . " FROM 	bom_header WHERE 	item_id_m LIKE '%" .
     $this->_searched_data . "%' OR 	alternate_bom LIKE '%" . $this->_searched_data . "%') 
      UNION
    (SELECT 'cc_co_header' as class_name, 	change_type as name , change_number as number ,  		description,  status, cc_co_header_id as primary_id , 'Change Order' as data_type "
     . " FROM 	cc_co_header WHERE 	change_number LIKE '%" .
     $this->_searched_data . "%' OR 	description LIKE '%" . $this->_searched_data . "%')
      UNION
      (SELECT 'gl_calendar' as class_name, 	name  , number ,  		calendar_type as description,  'NA' as status, gl_calendar_id as primary_id , 'Calendar' as data_type "
     . " FROM 	gl_calendar WHERE 	name LIKE '%" .
     $this->_searched_data . "%' OR 	calendar_type LIKE '%" . $this->_searched_data . "%') 
      UNION
      (SELECT 'gl_journal_header' as class_name, journal_name as	name  , gl_journal_header_id as number , description,  status, gl_journal_header_id as primary_id , 'Calendar' as data_type "
     . " FROM 	gl_journal_header WHERE 	journal_name LIKE '%" .
     $this->_searched_data . "%' OR 		description LIKE '%" . $this->_searched_data . "%') 
      UNION
      (SELECT 'inv_transaction' as class_name, document_type as	name  , 	inv_transaction_id as number , description,  status, inv_transaction_id as primary_id , 'Inv Transaction' as data_type "
     . " FROM 	inv_transaction WHERE 	description LIKE '%" .
     $this->_searched_data . "%' OR 			inv_transaction_id LIKE '%" . $this->_searched_data . "%') 
    UNION
     (SELECT 'po_header' as class_name, 	po_type as	name  , 	po_number as number , description,  po_status, po_header_id as primary_id , 'Purchase Order' as data_type "
     . " FROM 	po_header WHERE 		po_number LIKE '%" .
     $this->_searched_data . "%' OR 			description LIKE '%" . $this->_searched_data . "%') 
   UNION
   (SELECT 'inv_receipt_header' as class_name, 		comment as	name  , 	receipt_number as number , 'NA',  status, inv_receipt_header_id as primary_id , 'Inv Receipt' as data_type "
     . " FROM 	inv_receipt_header WHERE 			comment LIKE '%" .
     $this->_searched_data . "%' OR 			receipt_number LIKE '%" . $this->_searched_data . "%') 
  UNION      
  (SELECT 'inv_receipt_header' as class_name, 			item_description as	name  , 		item_number as number , description ,  status, bom_routing_header_id as primary_id , 'Routing' as data_type "
     . " FROM 	bom_routing_v WHERE 			item_description LIKE '%" .
     $this->_searched_data . "%' OR 			item_number LIKE '%" . $this->_searched_data . "%') 
      UNION
      (SELECT 'sd_so_all_v' as class_name, 			document_type as	name  , 		so_number as number , line_description,  so_status, sd_so_header_id as primary_id , 'Sales Order' as data_type "
     . " FROM 	sd_so_all_v  WHERE 			so_number LIKE '%" .
     $this->_searched_data . "%' OR 			line_description LIKE '%" . $this->_searched_data . "%')
      UNION
      (SELECT 'inv_receipt_header' as class_name, 			sd_delivery_header_id as	name  , 		delivery_number as number , comment,  status, sd_delivery_header_id as primary_id , 'Sales Delivery' as data_type "
     . " FROM 	sd_delivery_header  WHERE 				delivery_number LIKE '%" .
     $this->_searched_data . "%' OR 			comment LIKE '%" . $this->_searched_data . "%')
      UNION
      (SELECT 'supplier' as class_name, 			supplier_name as	name  , 		supplier_number as number , 	supplier_type,  status, supplier_id as primary_id , 'Supplier' as data_type "
     . " FROM 	supplier  WHERE 				supplier_name LIKE '%" .
     $this->_searched_data . "%' OR 			supplier_number LIKE '%" . $this->_searched_data . "%') 
      UNION
      (SELECT 'ino_user' as class_name, 			username as	name  , 		hr_employee_id as number , 	last_name,  status, user_id as primary_id , 'User' as data_type "
     . " FROM 	user  WHERE 				username LIKE '%" .
     $this->_searched_data . "%' OR 			last_name LIKE '%" . $this->_searched_data . "%')  

";

    break;
  }



//  echo $sql;

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 private function _format_search_result($result) {
  $pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
  $per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
  $total_count = count($result);
  $pagination = new pagination($pageno, $per_page, $total_count);
  $pagination->setProperty('_path', 'content');
  $position = ($pageno - 1) * $per_page;

  $result_stmt = "<h1>" . gettext('Searched Text') . " : " . $this->_searched_data . '<small> ( Use any <a href="search.php">advanced search </a> for filter & data export ) </smal></h1>';
  $result_stmt .= '<table class="table ">
       <thead> 
        <tr>
         <th>' . gettext('Data Type') . '</th>
         <th>' . gettext('Name') . '</th>
         <th>' . gettext('Number') . '</th>
         <th>' . gettext('Description') . '</th>
         <th>' . gettext('Status') . '</th>
         <th>' . gettext('Primary Id') . '</th>
         <th>' . gettext('Action') . '</th>
        </tr>
       </thead>
       <tbody class="search_result" >';
  $count = 0;
  $result_ai = new ArrayIterator($result);
  $result_ai->seek($position);
  while ($result_ai->valid()) {
   $result_data = $result_ai->current();
   $result_stmt .= "<tr class='search_result{$count}'>";
   $result_stmt .= "<td>$result_data->data_type</td>";
   $result_stmt .= "<td>$result_data->name</td>";
   $result_stmt .= "<td>$result_data->number</td>";
   $result_stmt .= "<td>$result_data->description</td>";
   $result_stmt .= "<td>$result_data->status</td>";
   $result_stmt .= "<td>$result_data->primary_id</td>";
   if (!empty($result_data->primary_id) && property_exists($result_data->class_name, 'primary_column')) {
    $result_data_className = $result_data->class_name;
    $primary_column = $result_data_className::$primary_column;
    $result_stmt .= '<td><a href="' . HOME_URL . 'form.php?mode=2&class_name=' . $result_data->class_name . '&' . $primary_column . '=' . $result_data->primary_id . '" class="btn btn-default" >' . gettext('View') . '</a>';
    $result_stmt .= '<a href="' . HOME_URL . 'form.php?mode=9&class_name=' . $result_data->class_name . '&' . $primary_column . '=' . $result_data->primary_id . '" class="btn btn-default" >' . gettext('Update') . '</a></td>';
   } else {
    $result_stmt .= '<td><button type="button" class="btn btn-default" >' . gettext('No Action') . '</button></td>';
   }
   $result_ai->next();
   if ($result_ai->key() == $position + $per_page) {
    break;
   }
   $count = $count + 1;
  }

  $result_stmt .= '</tbody></table>';
  $result_stmt .= $pagination->show_pagination();
  return $result_stmt;
 }

 public function site_search_result($param = '') {
  $f = new inoform();
  $result_data_stmt = '';
  $entry_form = '<div id="site_search_content">';
  if (!empty($param['search_text'])) {
   $this->_searched_data = $param['search_text'];
   $this->_searched_document = $param['search_document_list'];
   $result_data = $this->_get_search_data();
   if (!empty($result_data)) {
//    pa($result_data);
    $result_data_stmt = $this->_format_search_result($result_data);
   } else {
    $result_data_stmt = '<h2>No Data Found!</h2>';
   }
  }
  $entry_form .= '<br>' . $result_data_stmt . '</div>';
  return $entry_form;
 }

 public function entry_form($param = '') {
  $f = new inoform();
  $result_data_stmt = '';
  $entry_form = '<div id="site_search_content">';
//  $content_type = is_array($param['content_type']) ? $param['content_type'][0] : $param['content_type'];
  if (!empty($param['search_text'])) {
   $this->_searched_data = $param['search_text'];
   $this->_searched_document = $param['search_document_list'];
   $result_data = $this->_get_search_data();
   if (!empty($result_data)) {
//    pa($result_data);
    $result_data_stmt = $this->_format_search_result($result_data);
   } else {
    $result_data_stmt = '<h2>No Data Found!</h2>';
   }
  }
//  $entry_form = "<h1>Site Search</h1>";
  $entry_form .= '<form class="navbar-form navbar-right site_search" method="GET" 
               id="site_search"  name="site_search"  action="' . HOME_URL . 'content.php">';
  $entry_form .= $f->hidden_field_withId('content_type', 'extn_site_search');
  $entry_form .= '<div class="col-lg-12">
            <div class="input-group">';
  $entry_form .= '<span class="input-group-btn left-side">'
   . $f->select_field_from_array('search_document_list', self::$search_document_list_a, 'all', '', 'form-control fa-select') . '</span>';
  $entry_form .= ' <input type="text" class="form-control search-element" name="search_text" placeholder="' . gettext('Data To Search...') . '">
              <span class="input-group-btn">
                <button class="btn btn-default" type="button"  id="site_search_submit">' . gettext('Go!') . '</button>
              </span>
            </div>
            </div>';

  $entry_form .= '</form>';
  $entry_form .= '<br>' . $result_data_stmt . '</div>';
  return $entry_form;
 }

 public function _before_save($param) {
  global $si;

  $to = $si->email;
  $subject = "Web Contact @ " . $si->site_name;
  $message = "<html> <body><br>Message as submited on web site_search form : <br><br>";
  foreach ($param as $k => $val) {
   $message .= "<br> $k : $val[0]";
  }
  $message .='<br><br>Thanks<br>' . $si->site_name . '</body></html>';

  $from = "admin@" . $si->site_name;
  $headers = "From: $from\r\n";
  $headers .= "Content-type: text/html\r\n";
  try {
//   echo $message;
   mail($to, $subject, $message, $headers);
  } catch (Exception $e) {
   echo "<br>Failed to send e-mail.";
  }
  echo "<h1>Thank you for site_searching Us.</h1>
        <h2>We’ll review the information and be in touch with you shortly.</h2> ";
  return 10;
 }

 public static function show_adrees_details_inLine(&$site_search_form) {
  if (empty($site_search_form)) {
   return;
  }
  $show_adrees_details = $site_search_form->site_search_form . '<br>' . $site_search_form->postal_code . ','
   . $site_search_form->country . '<br>' . $site_search_form->phone
   . $site_search_form->email . '<br>' . $site_search_form->website;
  return $show_adrees_details;
 }

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = substr($value,0,strpos($value,";")+2) . gettext(substr($value,strpos($value,";")+2));
  }
 }

}

extn_site_search::staticVar_init('search_document_list_a');
$extn_site_search = new extn_site_search();
$ss = &$extn_site_search;
?>
