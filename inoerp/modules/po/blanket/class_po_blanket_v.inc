<?php

 class po_blanket_v extends dbObject {
  
  public static $form_class_name = "po_header";

  public static $table_name = "po_blanket_v";
  public static $primary_column = "po_header_id";
  public $field_a = [
   'po_header_id',
   'bu_org_id',
   'po_type',
   'po_number',
   'release_number',
   'supplier_id',
   'supplier_site_id',
   'buyer',
   'currency',
   'header_amount',
   'po_status',
   'payment_term_id',
   'agreement_start_date',
   'agreement_end_date',
   'supplier_name',
   'supplier_number',
   'supplier_site_name',
   'supplier_site_number',
   'payment_term',
   'payment_term_description',
   'po_line_id',
   'line_type',
   'po_line_number',
   'item_id_m',
   'item_description',
   'line_description',
   'line_quantity',
   'unit_price',
   'line_price',
   'item_number',
   'uom_id',
   'item_status',
   'po_detail_id',
   'shipment_number',
   'receving_org_id',
   'subinventory_id',
   'locator_id',
   'requestor',
   'quantity',
   'open_quantity',
   'received_quantity',
   'need_by_date',
   'promise_date',
   'receving_org',
   'charge_ac_id',
   'accrual_ac_id',
   'budget_ac_id',
   'ppv_ac_id',
  ];
  public $initial_search = [
   "po_number",
   'po_type',
   "supplier_number",
   "receving_org_id",
   "item_number",
   'po_status'
  ];
  public $search_session_field = [
   "receving_org_id",
   'po_status'
  ];
  public $column = [
   'po_number',
   'po_status',
      'po_type',
   'supplier_name',
   'po_line_number',
   'shipment_number',
   'item_number',
   'quantity',
   'open_quantity',
   'received_quantity',
   'unit_price',
   'line_price',
   'uom_id',
   'po_header_id',
   'item_status',
   'po_detail_id',
   'supplier_site_name',
   'receving_org_id',
   'subinventory_id',
   'locator_id',
   'requestor',
   'item_id_m',
   'item_description',
   'line_description',
   'line_quantity',
   'supplier_number',
   'supplier_site_number',
   'currency',
   'header_amount',
   'bu_org_id',
   'supplier_id',
   'supplier_site_id',
   'buyer',
   'payment_term_id',
   'payment_term',
   'payment_term_description',
   'po_line_id',
   'line_type',
   'need_by_date',
   'promise_date',
   'receving_org',
   'charge_ac_id',
   'accrual_ac_id',
   'budget_ac_id',
   'ppv_ac_id',
  ];
  public $multi_select_column = [
   'unit_price',
   'line_quantity',
   'po_number',
   'po_line_number',
   'shipment_number',
   'quantity',
   'received_quantity',
   'open_quantity',
   'accepted_quantity',
   'delivered_quantity',
   'invoiced_quantity',
   'paid_quantity',
   'supplier_id',
   'supplier_site_id',
   'supplier_name',
   'supplier_number',
   'supplier_site_name',
   'supplier_site_number',
   'item_number',
   'item_description',
   'item_id_m',
   'uom_id',
   'po_header_id',
   'po_line_id',
   'po_detail_id',
   'po_status'
  ];
  public $dateField = [
   'need_by_date',
   'promise_date'
  ];
  public $search = [
   '_update_path' => 'form.php?class_name=po_release',
   '_show_update_path' => 1,
   '_update_action_meassge' => 'Update',
   '_view_path' => 'form.php?class_name=po_release',
   '_show_view_path' => 1,
   '_extra_path' => array('form.php?class_name=ap_transaction_header&mode=9' => 'Invoice',
    'form.php?class_name=inv_receipt_header&mode=9' => 'Receive')
  ];
  public $pageTitle = " PO - Find All Purchase Order Headers "; //page Title
  public $option_lists = [
   'po_type' => 'PO_TYPE',
   'po_status' => 'PO_STATUS',
  ];
  public $ra_open_po_by_supplier_parameters = [
   'Organization' => 'search_org_name',
   'Number of Suppliers' => 'search_no_of_suppliers',
  ];
  public $ra_open_po_by_supplier_settings = [
   '_chart_name' => 'Open PO By Supplier',
   '_x_axis_text' => 'Supplier',
   '_chart_type' => array('clustered_column', 'clustered_bar'),
   '_legend' => ''
  ];
  public $ra_po_purchase_type_usage_settings = [
   '_chart_name' => 'Purchase Type Usage',
   '_x_axis_text' => 'PO Type',
   '_right_margin' => '100',
   '_chart_width' => '400',
   '_chart_height' => '400',
   '_chart_type' => array('pie', 'clustered_bar'),
   '_legend' => ''
  ];
  public $ra_report_set_purchasing_analysis_settings = [
   '_chart_name' => 'Purchasing Analysis',
   '_chart_width' => '350',
   '_chart_height' => '350',
   '_x_axis_text' => 'Supplier',
   '_chart_type' => array('clustered_column', 'clustered_bar'),
   '_legend' => ''
  ];
  public $ra_report_set_purchasing_analysis = [
   'ra_open_po_by_supplier',
   'ra_po_purchase_type_usage',
  ];
  public $po_header_id;
  public $bu_org_id;
  public $po_type;
  public $po_number;
  public $release_number;
  public $supplier_id;
  public $supplier_site_id;
  public $buyer;
  public $currency;
  public $header_amount;
  public $po_status;
  public $payment_term_id;
  public $agreement_start_date;
  public $agreement_end_date;
  public $supplier_name;
  public $supplier_number;
  public $supplier_site_name;
  public $supplier_site_number;
  public $payment_term;
  public $payment_term_description;
  public $po_line_id;
  public $line_type;
  public $po_line_number;
  public $item_id_m;
  public $item_description;
  public $line_description;
  public $line_quantity;
  public $unit_price;
  public $line_price;
  public $item_number;
  public $uom_id;
  public $item_status;
  public $po_detail_id;
  public $shipment_number;
  public $receving_org_id;
  public $subinventory_id;
  public $locator_id;
  public $requestor;
  public $quantity;
  public $open_quantity;
  public $need_by_date;
  public $promise_date;
  public $receving_org;
  //extra fields
  public $receipt_line_id;
  public $received_quantity;
  public $charge_ac_id;
  public $accrual_ac_id;
  public $budget_ac_id;
  public $ppv_ac_id;


  private function create_po_blanket_v() {
   $sql = "
CREATE OR REPLACE VIEW po_blanket_v
(
po_header_id, bu_org_id, po_type, po_number, release_number, supplier_id, supplier_site_id, buyer, currency, header_amount, po_status,
payment_term_id,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
payment_term, payment_term_description,
agreement_start_date,agreement_end_date,
po_line_id, line_type, po_line_number,	item_id_m, item_description, line_description, line_quantity, unit_price, line_price,
item_number, uom_id, item_status,
po_detail_id, shipment_number, receving_org_id, subinventory_id, locator_id, requestor, 
quantity,received_quantity, open_quantity,
need_by_date, promise_date,
 accepted_quantity, delivered_quantity, invoiced_quantity, paid_quantity,
charge_ac_id, accrual_ac_id,budget_ac_id, ppv_ac_id,
receving_org, created_by, creation_date, last_update_by, last_update_date
)
AS
SELECT 
po_header.po_header_id, po_header.bu_org_id, po_header.po_type, po_header.po_number, po_header.release_number, po_header.supplier_id, 
po_header.supplier_site_id, po_header.buyer, po_header.currency, po_header.header_amount, po_header.po_status,
po_header.payment_term_id,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
payment_term.payment_term, payment_term.description,
po_header.agreement_start_date,po_header.agreement_end_date,
po_line.po_line_id, po_line.line_type, po_line.line_number,	po_line.item_id_m, po_line.item_description, po_line.line_description, 
po_line.line_quantity, po_line.unit_price, po_line.line_price,
item.item_number, item.uom_id, item.item_status,
po_detail.po_detail_id, po_detail.shipment_number, po_line.receving_org_id, po_detail.subinventory_id, 
po_detail.locator_id, po_detail.requestor, 
po_detail.quantity, IFNULL(po_detail.received_quantity,0), po_detail.quantity - IFNULL(po_detail.received_quantity,0), 
po_detail.need_by_date, po_detail.promise_date,
 po_detail.accepted_quantity, po_detail.delivered_quantity, 
po_detail.invoiced_quantity, po_detail.paid_quantity,
po_detail.charge_ac_id, po_detail.accrual_ac_id,po_detail.budget_ac_id, po_detail.ppv_ac_id,
org.org,
po_header.created_by, po_header.creation_date, po_header.last_update_by, po_header.last_update_date

FROM po_header 
LEFT JOIN supplier ON po_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON po_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON po_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN po_line ON po_header.po_header_id = po_line.po_header_id
LEFT JOIN item ON po_line.item_id_m = item.item_id_m AND item.org_id = po_line.receving_org_id
LEFT JOIN po_detail ON po_line.po_line_id = po_detail.po_line_id
LEFT JOIN org ON po_line.receving_org_id = org.org_id
WHERE po_header.po_type IN ( 'BLANKET', 'BLANKET_RELEASE')
";
  }

  public static function find_all_by_poHeaderId($po_header_id) {
   $sql = " SELECT * FROM " . self::$table_name;
   $sql .= " WHERE po_header_id = '{$po_header_id}' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

  public static function find_all_by_poLineId($po_line_id) {
   $sql = " SELECT * FROM " . self::$table_name;
   $sql .= " WHERE po_line_id = '{$po_line_id}' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

  public static function find_all_active_bpa($bu_org_id = '', $supplier_site_id = '', $item_id_m='') {
   $sql = " SELECT *  FROM po_blanket_v pobv ";
   $sql .= " WHERE pobv.po_type = 'BLANKET' AND pobv.release_number IS NULL ";
   $sql .= " AND pobv.po_status = 'APPROVED' ";
   if (!empty($bu_org_id)) {
    $sql .= " AND pobv.bu_org_id = '{$bu_org_id}' ";
   }
   if (!empty($supplier_site_id)) {
    $sql .= " AND pobv.supplier_site_id = '{$supplier_site_id}' ";
   }

   if (!empty($item_id_m)) {
    $sql .= " AND pobv.item_id_m = '{$item_id_m}' ";
   }
   $sql .= " AND ( pobv.agreement_end_date IS NULL ||  pobv.agreement_end_date < CURDATE()) ";
//   echo "sql is $sql";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

  public function findBy_poDetailId() {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE po_detail_id = :po_detail_id ";
   $sql = ino_perPageSql_i($sql, 1);

   $param_a = ['po_detail_id'];
   $value_a = ['po_detail_id' => $this->po_detail_id];
   $result = $this->findBy_sql($sql, $param_a, $value_a);
   return !empty($result) ? array_pop($result) : false;
  }

  public function ra_report_set_purchasing_analysis() {
   $result_a = [];
   $result_a['ra_open_po_by_supplier'] = $this->ra_open_po_by_supplier();
   $result_a['ra_po_purchase_type_usage'] = $this->ra_po_purchase_type_usage();
   return $result_a;
  }

  public function ra_open_po_by_supplier() {
   $legend = [];
   $sql = " SELECT supplier_name, sum(quantity) as 'All', 
					sum(open_quantity) as 'Open'  FROM ";
   $sql .= self::$table_name;
   $sql .= " GROUP BY supplier_name ";
   $sql .= " ORDER BY quantity desc ";
   $sql = ino_perPageSql_i($sql, 5);
   $result = $this->findBySql($sql);
   $result_f = ra_conevrt_data($result, 'supplier_name', $legend);
   $this->ra_open_po_by_supplier_settings['_legend'] = $legend;
   return !empty($result_f) ? ($result_f) : false;
  }

  public function ra_po_purchase_type_usage() {
   $legend = [];
   $sql = " SELECT po_status, sum(quantity) FROM ";
   $sql .= self::$table_name;
   $sql .= " GROUP BY po_status ";
   $sql .= " ORDER BY quantity desc ";
   $sql = ino_perPageSql_i($sql, 1);
   $result = $this->findBySql($sql);
   $result_f = ra_conevrt_data_pie($result);
   return !empty($result_f) ? ($result_f) : false;
  }

 }
?>