<?php require_once __DIR__.'/../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../inoerp_server/includes/basics/basics.inc');


 if ((!empty($_GET['bu_org_id'])) && (!empty($_GET['find_bpa_list']))) {
  $bu_org_id = !empty($_GET['bu_org_id']) ? ($_GET['bu_org_id']) : null;
  $supplier_site_id = !empty($_GET['supplier_site_id']) ? ($_GET['supplier_site_id']) : null;
  $item_id_m = !empty($_GET['item_id_m']) ? ($_GET['item_id_m']) : null;
  $bpa_list = po_blanket_v::find_all_active_bpa($bu_org_id, $supplier_site_id, $item_id_m);
  echo header('Content-Type: application/json');
  echo json_encode(($bpa_list));
 }

 if ((!empty($_GET['po_header_id'])) && (!empty($_GET['find_bpa_details']))) {
  $bpa_details = po_all_v::find_by_id($_GET['po_header_id']);
  echo header('Content-Type: application/json');
  echo json_encode(($bpa_details));
 }

 if ((!empty($_GET['find_bpa_line_details'])) && (!empty($_GET['po_line_id']))) {
  $bpa_line_details_a = po_all_v::find_all_by_poLineId($_GET['po_line_id']);
  $bpa_line_details = $bpa_line_details_a[0];
  echo header('Content-Type: application/json');
  echo json_encode(($bpa_line_details));
 }
?>