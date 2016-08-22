<?php

class fp_reports extends dbObject {

 public static $table_name = "onhand_summary_v";
 public static $primary_column = "onhand_id";
 public $field_a = [
  'item_number',
  'item_description',
  'org',
  'onhand',
  'reservable_onhand',
  'transactable_onhand',
  'open_po_qty',
  'po_qty',
  'po_received_qty',
  'onhand_id',
  'item_id_m',
  'org_id',
 ];
 public $initial_search = [
  'item_number',
 ];
 public $dateField = [
 ];
 public $pageTitle = " Forecast & Planning Reports "; //page Title
 public $onhand_id;
 public $item_number;
 public $item_description;
 public $org;
 public $uom_id;
 public $onhand;
 public $item_id_m;
 public $org_id;
 public $reservable_onhand;
 public $transactable_onhand;
 public $po_qty;
 public $po_received_qty;
 public $open_po_qty;
 public $search_functions = [
  'Inventory Org' => 'search_org_name'
 ];
 public $prg_update_description_details = [
  'name' => 'Update Account Combination Description',
  'description' => 'Run update Description program',
 ];
 public $prg_balance_sheet_details = [
  'name' => 'Generate Balance Sheet',
  'description' => 'Generate Balance Sheet',
 ];
 public $prg_balance_sheet_parameters = [
  'Period Name' => 'search_gl_period_name',
  'Show Details' => 'search_show_details_cb',
  'Legal Org' => 'search_legal_org_name_m'
 ];
 public $prg_income_statement_details = [
  'name' => 'Generate Income Statement',
  'description' => 'Generate Income Statement',
 ];
 public $prg_income_statement_parameters = [
  'Period Name' => 'search_gl_period_name',
  'Show Details' => 'search_show_details_cb',
  'Legal Org' => 'search_legal_org_name_m'
 ];

 private function create_supply_analysis_v() {
  $sql = "
	 CREATE OR REPLACE VIEW fp_supply_analysis_v
(
onhand_id, item.item_number, item.item_description, org.org, uom_id, Sum(onhand) as onhand, 
item_id_m, org_id,  reservable_onhand, transactable_onhand, po_qty,  po_received_qty,  open_qty
)
AS
SELECT onhand.onhand_id, item.item_number, item.item_description, 
org.org, onhand.uom_id, Sum(onhand.onhand) as onhand,
onhand.item_id_m, onhand.org_id,  onhand.reservable_onhand, 
onhand.transactable_onhand, open_po.po_qty,  open_po.po_received_qty,  open_po.open_qty
FROM onhand 
LEFT JOIN item ON onhand.item_id_m = item.item_id_m and item.org_id = onhand.org_id
LEFT JOIN org ON onhand.org_id = org.org_id
LEFT JOIN (
SELECT SUM(pd.quantity) as po_qty,
SUM(pd.received_quantity) as po_received_qty, 
SUM(pd.quantity) - IFNULL(SUM(pd.received_quantity),0) as open_qty,
pl.item_id_m, pl.receving_org_id

FROM po_detail pd,
po_line pl,
po_header ph
WHERE 
pd.received_quantity < pd.quantity
AND pl.po_line_id = pd.po_line_id
AND ph.po_header_id = pl.po_header_id
AND ph.po_status = 'APPROVED'
GROUP BY item_id_m, receving_org_id
) as open_po ON open_po.item_id_m = item.item_id_m and item.org_id = open_po.receving_org_id
GROUP BY onhand.item_id_m, onhand.org_id
";
 }

 public function supply_analysis($params) {
  $ret_a = [
   'name' => 'Supply Analysis Report',
   'description' => 'Supply Analysis Report',
  ];
  return $ret_a;
 }

 public function supply_analysis_search_records($parameters = '') {
  $pageno = !empty($parameters['pageno']) ? $parameters['pageno'] : 1;
  $per_page = !empty($parameters['per_page']) ? $parameters['per_page'] : 10;
  $whereClause = $_GET['whereClause'];
  $search_order_by = !(empty($_GET['search_order_by'])) ? $_GET['search_order_by'] : '';
  $search_asc_desc = !(empty($_GET['search_asc_desc'])) ? $_GET['search_asc_desc'] : '';

  if ((!empty($search_order_by)) && (!empty($search_asc_desc))) {
   if (is_array($search_order_by)) {
    $order_by = ' ORDER BY ';
    foreach ($search_order_by as $key_oby => $value_oby) {
     if (empty($search_asc_desc[$key_oby])) {
      $search_asc_desc[$key_oby] = ' DESC ';
     }
     $order_by .= $value_oby . ' ' . $search_asc_desc[$key_oby] . ' ,';
    }
    $order_by_i = rtrim($order_by, ',');
   } else {
    $order_by_i = ' ORDER BY ' . $search_order_by . ' ' . $search_asc_desc;
   }
  }

  $sql = $this->_supply_analysis_sql($parameters);
//  $sql .= " $order_by_i ";
  if (!empty($per_page)) {
   $offset = ($pageno - 1 ) * $per_page;
   $offset_i = $offset <= 0 ? 1 : $offset;
//   $sql .=" LIMIT {$per_page} ";
//   $sql .=" OFFSET {$offset_i} ";

   $per_page_sql = ino_perPageSql($per_page, $offset_i);
   if (!empty($per_page_sql)) {
    switch (DB_TYPE) {
     case 'ORACLE' :
      if (stripos($sql, 'WHERE') !== false) {
       $sql .= ' AND ' . $per_page_sql . ' ' . $order_by_i;
      } else {
       $sql .= ' WHERE ' . $per_page_sql . ' ' . $order_by_i;
      }
      break;

     default:
      $sql .= $order_by_i . '  ' . $per_page_sql;
      break;
    }
   }
  }

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public function supply_analysis_search_counts($parameters = '') {

  $sql = $this->_supply_analysis_sql($parameters);

  $result = self::find_by_sql($sql);
  return !empty($result) ? count($result) : false;
 }

 public function supply_analysis_search_downloads($parameters = '') {
  return $this->_supply_analysis_sql($parameters);
 }

 private function _supply_analysis_sql($parameters = '') {
  $whereClause = $_GET['whereClause'];
  $sql = "SELECT onhand.onhand_id, item.item_number, item.item_description, 
org.org, onhand.uom_id, Sum(onhand.onhand) as onhand,
onhand.item_id_m, onhand.org_id,  onhand.reservable_onhand, 
onhand.transactable_onhand, open_po.po_qty,  open_po.po_received_qty,  open_po.open_qty as open_po_qty
FROM onhand 
LEFT JOIN item ON onhand.item_id_m = item.item_id_m and item.org_id = onhand.org_id
LEFT JOIN org ON onhand.org_id = org.org_id
LEFT JOIN (
SELECT SUM(pd.quantity) as po_qty,
SUM(pd.received_quantity) as po_received_qty, 
SUM(pd.quantity) - IFNULL(SUM(pd.received_quantity),0) as open_qty,
pl.item_id_m, pl.receving_org_id

FROM po_detail pd,
po_line pl,
po_header ph
WHERE 
pd.received_quantity < pd.quantity
AND pl.po_line_id = pd.po_line_id
AND ph.po_header_id = pl.po_header_id
AND ph.po_status = 'APPROVED'
GROUP BY item_id_m, receving_org_id
) as open_po ON open_po.item_id_m = item.item_id_m and item.org_id = open_po.receving_org_id ";
  //  if (!empty($whereClause)) {
//   $sql .= "	$whereClause ";
//  }
  $sql .= " GROUP BY onhand.item_id_m, onhand.org_id ";

  return $sql;
 }

}

//end of po_detail class
?>