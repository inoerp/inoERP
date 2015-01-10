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
  'number' => '2006',
  'description' => 'Define and mainten site_search_formes',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'org',
  'weight' => 6
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

 Public static function extn_site_search_category() {
  $option_header = option_header::find_by_name('EXT_WEB_CONTACT_CATEGORY');
  $ol = new option_line();
  $lines = $ol->findBy_parentId($option_header->option_header_id);
  return $lines;
 }

 private function _get_search_data() {
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
   $this->_searched_data . "%' OR 	bank_number LIKE '%" . $this->_searched_data . "%') ";

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

  $result_stmt = "<h1>Searched Text : " . $this->_searched_data . '</h1>';
  $result_stmt .= '<table class="table ">
       <thead> 
        <tr>
         <th>Data Type</th>
         <th>Name</th>
         <th>Number</th>
         <th>Description</th>
         <th>Status</th>
         <th>Primary Id</th>
         <th>Action</th>
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
    $result_stmt .= '<td><a href="' . HOME_URL . 'form.php?mode=2&class_name=' . $result_data->class_name . '&' . $primary_column . '=' . $result_data->primary_id . '" class="btn btn-default" >View</a>';
    $result_stmt .= '<a href="' . HOME_URL . 'form.php?mode=9&class_name=' . $result_data->class_name . '&' . $primary_column . '=' . $result_data->primary_id . '" class="btn btn-default" >Update</a></td>';
   } else {
    $result_stmt .= '<td><button type="button" class="btn btn-default" >No Action</button></td>';
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
            <div class="input-group">
              <input type="text" class="form-control" name="search_text" placeholder="Data To Search...">
              <span class="input-group-btn">
                <button class="btn btn-default" type="button"  id="site_search_submit">Go!</button>
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

}

$extn_site_search = new extn_site_search();
$ss = &$extn_site_search;
?>
