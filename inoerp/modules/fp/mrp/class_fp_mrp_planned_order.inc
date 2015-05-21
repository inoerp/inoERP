<?php

class fp_mrp_planned_order extends dbObject {

 public static $table_name = "fp_mrp_planned_order";
 public static $primary_column = "fp_mrp_planned_order_id";
 public static $parent_primary_column = "fp_mrp_header_id";
 public static $key_column = 'item_id_m';
 public static $module = "fp";
 public $field_a = [
		 'fp_mrp_planned_order_id',
		 'org_id',
		 'fp_mrp_header_id',
		 'order_type',
		 'order_action',
		 'item_id_m',
		 'quantity',
		 'need_by_date',
		 'supplier_id',
		 'supplier_site_id',
		 'demand_item_id_m',
		 'toplevel_demand_item_id_m',
		 'source_type',
		 'primary_source_type',
		 'source_header_id',
		 'source_line_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'source_type'
 ];
 public $column = [
		 'fp_mrp_planned_order_id',
		 'fp_mrp_header_id',
		 'org_id',
		 'order_type',
		 'order_action',
		 'item_id_m',
		 'quantity',
		 'need_by_date',
		 'supplier_id',
		 'supplier_site_id',
		 'demand_item_id_m',
		 'toplevel_demand_item_id_m',
		 'source_type',
		 'primary_source_type',
		 'source_header_id',
		 'source_line_id',
 ];
 public $requiredField = [
		 'fp_mrp_header_id',
		 'org_id',
		 'order_type',
		 'item_id_m',
		 'quantity',
		 'need_by_date'
 ];
 public $search = [
//		 '_show_view_path' => 1,
 ];
 public $prg_mrp_create_planned_order_parameters = [
		 'Organization' => 'search_org_name',
		 'MRP Planner ' => 'search_mrp_name'
 ];
 public $prg_mrp_create_planned_order_details = [
		 'name' => 'MRP Create Planned Orders ',
		 'description' => ' Create Planned Orders ',
 ];
 
 public $pageTitle = " MRP Planned Orders "; //page Title
 public $fp_mrp_planned_order_id;
 public $fp_mrp_header_id;
 public $org_id;
 public $order_type;
 public $order_action;
 public $item_id_m;
 public $need_by_date;
 public $quantity;
 public $demand_item_id_m;
 public $toplevel_demand_item_id_m;
 public $source_type;
 public $primary_source_type;
 public $source_header_id;
 public $source_line_id;
 public $supplier_id;
 public $supplier_site_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 private function _create_exception($exception_type, $exception_msg, $detailed_message, $org_id) {
	$excp = new fp_mrp_exception();
	$excp->org_id = $org_id;
	$excp->fp_mrp_header_id = $this->fp_mrp_header_id;
	$excp->item_id_m = $this->item_id_m;
	$excp->exception_type = $exception_type;
	$excp->exception_message = $exception_msg;
	$excp->detailed_message = $detailed_message;
	$excp->audit_trial();
//	pa($excp);
	$excp->save();
 }

 private function _mergeDemand_byFDS($mrp_d, $fds) {
	$today = new dateTime();
	$demand_batch_date = new dateTime();
	$demand_batch_date->add(new DateInterval('P' . $fds . 'D'));
	$final_demand_a = [];
	$current_batch_demand = [];
	foreach ($mrp_d as $demand) {
	 $demand_date = new DateTime($demand->demand_date);
	 if ($today > $demand_date) {
		if (( $demand->primary_source_type == 'Forecast' ) || ($demand->source_type == 'Forecast')) {
		 continue;
		}
	 }
	 if ($demand_date < $demand_batch_date) {
		if (empty($current_batch_demand)) {
		 $current_batch_demand = $demand;
		} else {
		 $current_batch_demand->quantity += $demand->quantity;
		 $current_batch_demand->source_type = 'Mix';
		 $current_batch_demand->primary_source_type = 'Mix';
		}
		array_push($final_demand_a, $current_batch_demand);
	 } else {
		if (!empty($current_batch_demand)) {
		 array_push($final_demand_a, $current_batch_demand);
		 unset($current_batch_demand);
		}
		while (($demand_date < $demand_batch_date)) {
		 $demand_batch_date->add(new DateInterval('P' . $fds . 'D'));
		}
		if (empty($current_batch_demand)) {
		 $current_batch_demand = $demand;
		} else {
		 $current_batch_demand->quantity += $demand->quantity;
		 $current_batch_demand->source_type = 'Mix';
		 $current_batch_demand->primary_source_type = 'Mix';
		}
	 }
	}

	return $final_demand_a;
 }

 public function modify_orderQuantity_asPerModifiers($item_id_m, $quantity) {
	$item = new item();
	$item->findBy_id($item_id_m);
	if (!empty($item->minimum_order_quantity)) {
	 if ($quantity < $item->minimum_order_quantity) {
		$quantity = $item->minimum_order_quantity;
	 }
	}

	if ((!empty($item->fix_lot_multiplier)) && ($item->fix_lot_multiplier > 1)) {
	 $reminder = fmod($quantity, $item->fix_lot_multiplier);
	 $quantity +=!empty($reminder) ? ($item->fix_lot_multiplier - $reminder) : 0;
	}
	return $quantity;
 }

 public function create_planned_orders($item_id_m, $fp_mrp_header_id) {
	$mrpd = new fp_mrp_demand();
	$item = new item();
	$item->findBy_id($item_id_m);
	$mrp_d = $mrpd->findBy_ItemId_HeaderId($item_id_m, $fp_mrp_header_id);
	if (empty($mrp_d)) {
	 return;
	}
//	echo "<h2>Demand </h2>";
//	pa($mrp_d);
	$mrpexsup = new fp_mrp_existing_supply_v();

	$mrp_supp = $mrpexsup->findBy_ItemId($item_id_m);
//		echo "<h2>Supply </h2>";
//	pa($mrp_supp);
	$onhand = 0;
	$open_wo_q = 0;
	$open_po_q = 0;
	$open_req_q = 0;
	$total_open_q = 0;
	if (!empty($mrp_supp)) {
	 foreach ($mrp_supp as $supp) {
		if ($supp->document_type == 'Onhand') {
		 $onhand = $supp->quantity;
		 break;
		}
	 }
	}
	$today = new DateTime();
	$planned_order_a = [];
	$last_demand_date = new DateTime();
	$last_demand_date->sub(new DateInterval('P1Y'));

	if (!empty($item->fix_days_supply)) {
	 $mrp_d_f = $this->_mergeDemand_byFDS($mrp_d, $item->fix_days_supply);
	 echo "<br> Trying to Merge demand as per FDS for " . $item->item_number;
	} else {
	 $mrp_d_f = $mrp_d;
	 echo "<br> No Merging of demand for " . $item->item_number;
	}
	
		foreach ($mrp_d_f as $demand) {
	 $demand_date = new DateTime($demand->demand_date);
	 //ignore past due forecasts and raise past due exception for sales orders
	 if ($today > $demand_date) {
		if (( $demand->primary_source_type == 'Forecast' ) || ($demand->source_type == 'Forecast')) {
		 continue;
		} else {
		 $msg = "Item $item->item_number (id : $item_id_m) is past due";
		 $detailed_msg = "Item $item->item_number (id : $item_id_m) is past due "
						 . " Demand date was $demand->demand_date ";
		 $this->_create_exception('PAST_DUE', $msg, $detailed_msg, $demand->org_id);
		}
	 }
	 if ($onhand >= $demand->quantity) {
		$onhand -= $demand->quantity;
		continue;
	 } else if ($onhand > 0) {
		$demand->quantity = $demand->quantity - $onhand;
		$onhand = 0;
	 } else if ($onhand < 0) {
		$demand->quantity = $demand->quantity - $onhand;
		$onhand = 0;
	 }
	 //verify if open WO/WO/Requisition between last demand date & current demand date is more than demand quantity
	 if (!empty($mrp_supp)) {
		foreach ($mrp_supp as $supp) {
		 $supp_date = new DateTime($supp->supply_date);
		 if (($supp->document_type != 'Onhand') && ($last_demand_date <= $supp_date ) && ( $supp_date < $demand_date)) {
			$total_open_q += $supp->quantity;
		 }
		}
	 }
	 if ($total_open_q >= $demand->quantity) {
		$total_open_q -= $demand->quantity;
		continue;
	 } else if ($total_open_q > 0) {
		$demand->quantity = $demand->quantity - $total_open_q;
		$total_open_q = 0;
	 }

	 $order_quantity = $demand->quantity;
	 //modify the $order_quantity as per FLM & MOQ
    $order_quantity_m = $this->modify_orderQuantity_asPerModifiers($item_id_m, $order_quantity);
		$total_open_q += $order_quantity_m - $order_quantity;

	 $plo = new fp_mrp_planned_order();
	 $plo->fp_mrp_planned_order_id = null;
	 $plo->fp_mrp_header_id = $demand->fp_mrp_header_id;
	 $plo->org_id = $demand->org_id;
	 $plo->item_id_m = $demand->item_id_m;
	 $item = item::find_by_id($plo->item_id_m);
	 $plo->order_type = ($item->make_buy == 'Make') ? 'WO' : 'Requisition';
	 $plo->order_action = 'Release';
	 $plo->quantity = $order_quantity_m;
	 $plo->need_by_date = $demand->demand_date;
	 $plo->demand_item_id_m = $demand->demand_item_id_m;
	 $plo->toplevel_demand_item_id_m = $demand->toplevel_demand_item_id_m;
	 $plo->source_type = $demand->source_type;
	 $plo->primary_source_type = $demand->primary_source_type;
	 $plo->source_header_id = $demand->source_header_id;
	 $plo->source_line_id = $demand->source_line_id;
	 array_push($planned_order_a, $plo);
	 $plo->audit_trial();
	 $plo->save();
	 $last_demand_date = $demand_date;
	 unset($order_quantity);
	 //verify if need by date is beyond the lead time - if not, raise compressed LT exception
	 $need_by_date = new DateTime($plo->need_by_date);
	 $daysToNeedBy = $today->diff($need_by_date)->format('%R%a');
	 $total_lt = $item->processing_lt + $item->pre_processing_lt + $item->post_processing_lt;
	 $compression_days = $total_lt - $daysToNeedBy;
	 if (($compression_days) > 0) {
		$msg = 'Planned Order (Id : ' . $plo->fp_mrp_planned_order_id . ') is compressed';
		$detail_msg = " Planned Order (Id :  " . $plo->fp_mrp_planned_order_id . " for Item " .
						$item->item_number . " (id : $item_id_m) is compressed by  $compression_days " .
						'  days as on MRP run date';
		$this->_create_exception('COMPRESSED_LT', $msg, $detail_msg, $demand->org_id);
	 }
	}

	if (($total_open_q + $onhand) > 0) {
	 $tonhand = $total_open_q + $onhand;
	 $msg = 'Exccess for Item# ' . $item->item_number;
	 $detail_msg = "Item $item->item_number (id : $item_id_m) is expected to have "
					 . " $tonhand excess material in the planning horizon ";
	 $this->_create_exception('EXCESS', $msg, $detail_msg, $mrp_d[0]->org_id);
	}
  	return !empty($planned_order_a) ? $planned_order_a : false;
 }

}

?>
