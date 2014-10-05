<?php
$$class->document_type = 'Work Order';

if (!empty($_GET["transaction_type_id"])) {
 $$class->transaction_type_id = $_GET['transaction_type_id'];
}

if (!empty($_GET['wip_wo_header_id'])) {
 $wip_wo_header_id = htmlentities($_GET["wip_wo_header_id"]);
 $wip_wo = wip_wo_header::find_by_id($wip_wo_header_id);
} else if (!empty($_GET["wo_number"])) {
 $wo_number = $_GET["wo_number"];
 $wip_wo = wip_wo_header::find_by_woNumber($wo_number);
 $wip_wo_header_id = $wip_wo->wip_wo_header_id;
}

if (!empty($wip_wo_header_id)) {
 $last_wo_routing_line = wip_wo_routing_line::find_lastOperation_by_wip_wo_headerId($wip_wo_header_id);
 $$class->org_id = $wip_wo->org_id;
 $$class->wip_wo_header_id = $wip_wo_header_id;
 $$class->document_id = $wip_wo_header_id;
 $$class->wo_number = $wip_wo->wo_number;
 $$class->document_number = $wip_wo->wo_number;
 $$class->item_id_m = $wip_wo->item_id_m;
 $$class->reference = 'wip_wo_header_id';
 $$class->total_quantity = $wip_wo->quantity;
 $item = item::find_by_orgId_item_id_m($$class->item_id_m, $$class->org_id);
 $$class->item_number = $item->item_number;
 $$class->item_description = $item->item_description;
 $$class->serial_generation = $item->serial_generation;
 $$class->lot_generation = $item->lot_generation;
 $$class->uom_id = $item->uom_id;
 }

if ((!empty($wip_wo_header_id)) && (!empty($$class->transaction_type_id))) {
 if ($$class->transaction_type_id == 11) {
	$$class->to_subinventory_id = $wip_wo->completion_sub_inventory;
	$$class->to_locator_id = $wip_wo->completion_locator;
	if ((!empty($last_wo_routing_line)) && (!empty($last_wo_routing_line->tomove_quantity))) {
	 $$class->available_quantity = $last_wo_routing_line->tomove_quantity;
	} else {
	 $$class->available_quantity = 0;
	}
 } elseif ($$class->transaction_type_id == 13) {
	$$class->from_subinventory_id = $wip_wo->completion_sub_inventory;
	$$class->from_locator_id = $wip_wo->completion_locator;
	$$class->available_quantity = $wip_wo->completed_quantity;
 }
}

if(empty($$class->transaction_type_id)){
 $$class->transaction_type_id = 11;
}

?>
