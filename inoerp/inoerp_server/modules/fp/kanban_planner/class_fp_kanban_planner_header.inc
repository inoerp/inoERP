<?php
/**
 * inoERP - Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * fp_kanban_planner_header
 * Used for min max planning
 * Contains all the fp_mds_header information, such as - mds_name, description , fp_source_list_header_id, org_id, status
 * 
 */
class fp_kanban_planner_header extends dbObject {

 public static $table_name = "fp_kanban_planner_header";
 public static $primary_column = "fp_kanban_planner_header_id";
 public static $key_column = 'plan_name';
 public static $module = "fp";
  public static $system_info = [
  'name' => 'Min Max',
  'number' => '2512',
  'description' => 'Min Max Planning & Size calculation',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('fp_kanban_planner_line','fp_kanban_planner_demand','fp_kanban_planner_demand_v','fp_kanban_planner_order_v','fp_kanban_planner_suggestion_v'),
  'primary_entity_cb' => '',
  'module_name' => 'fp',
  'weight' => 5
 ];
 public $field_a = [
		 'fp_kanban_planner_header_id',
		 'org_id',
		 'plan_name',
		 'planning_horizon_days',
		 'description',
		 'status',
		 'demand_source',
  'size_roundup',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $initial_search = [
		 'fp_kanban_planner_header_id',
		 'org_id',
		 'plan_name',
		 'description',
		 'status',
		 'demand_source',
 ];

 public $requiredField = [
		 'org_id',
		 'plan_name',
		 'planning_horizon_days',
		 'demand_source',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Kanban Planner "; //page Title
 public $prg_kanban_planner_parameters = [
		 'Organization' => 'search_org_name',
		 'Kanban Planner ' => 'search_kanban_planner',
		 'Item Number From' => 'search_item_number_from',
		 'Item Number To' => 'search_item_number_to',
		 'Item Id From' => 'search_item_id_m_from',
		 'Item Id To' => 'search_item_id_m_to'
 ];
 public $prg_kanban_planner_details = [
		 'name' => 'Kanban Demand Calculator',
		 'description' => 'Calculate the Kanban Size',
 ];
 public $prg_kanban_program_parameters = [
		 'Organization' => 'search_org_name',
		 'Min Max Type ' => 'search_kanban_type',
		 'Item Number From' => 'search_item_number_from',
		 'Item Number To' => 'search_item_number_to',
		 'Item Id From' => 'search_item_id_m_from',
		 'Item Id To' => 'search_item_id_m_to'
 ];
 public $prg_kanban_program_details = [
		 'name' => 'Create Supply as per kanban Program',
		 'description' => 'Create Supply as per kanban Program',
 ];
 public $fp_kanban_planner_header_id;
 public $org_id;
 public $plan_name;
 public $planning_horizon_days;
 public $description;
 public $status;
 public $size_roundup;
 public $demand_source;
 public $ar_customer_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $planning_method;
 public $order_quantity;
 public $total_order_quantity;

 public function prepare_kanban_demand_calculator($fp_kanban_planner_header_id) {
	$kbd = new fp_kanban_demand();
	try {
	 $kbd->deleteBy_planId($fp_kanban_planner_header_id);
	} catch (Exception $e) {
	 echo "<br>Deleting the existing record failed!. Error @ fp_kanban_planner_header @ " . __LINE__;
	}
 }

 public function prg_kanban_planner($seralized_parameters) {
	$parameters = unserialize($seralized_parameters);
	$this->message = '<br> Starting Min Max Planner....<br>';
	$kbh = new fp_kanban_planner_header();

	if (!empty($parameters['org_id'][0])) {
	 $org_id = $parameters['org_id'][0];
	 $this->message .= '<br> Entered Org Id is : ' . $org_id;
	} else {
	 $this->message .= '<br> Error! : No org id found @ cst_item_cost_header ' . __LINE__;
	 return $this->message;
	}

	if (!empty($parameters['fp_kanban_planner_header_id'][0])) {
	 $fp_kanban_planner_header_id = $parameters['fp_kanban_planner_header_id'][0];
	 $this->message .= '<br> Entered Kanban Header Id is : ' . $fp_kanban_planner_header_id;
	 $kbh->findBy_id($fp_kanban_planner_header_id);
	 if ($kbh->org_id != $org_id) {
		$this->message .= '<br> Error! : Entered Kanban Header Id does not belong to the entered Org @ fp_kanban_planner_header ' . __LINE__;
		return $this->message;
	 }
	 $this->prepare_kanban_demand_calculator($fp_kanban_planner_header_id);
	} else {
	 $this->message .= '<br> Error! : No Min Max Header Id is found @ fp_kanban_planner_header ' . __LINE__;
	 return $this->message;
	}

	if (isset($parameters['item_id_m'][0])) {
	 $this->message .= "<br/>Using Min Max Planner by Item Id ";
	 $item_id_m = $parameters['item_id_m'][0];
	 try {
		$this->kanban_demand_calculator($item_id_m, $kbh);
		$this->message .= "<br/> Min Max Planner is Successfullyupdated for item_id_m - " . $item_id_m .
						' bom_cost_type : ' . $fp_kanban_planner_header_id;
	 } catch (Exception $e) {
		$this->message .= "<br/> Min Max Planner fialed for Item id " . $item_id_m . $e->getMessage();
	 }

	 return $this->message;
	}

	if (!empty($parameters['from_item_id_m'][0])) {
	 $this->message .= "<br/>Using  Min Max Planner by Item Id Range ";
	 $from_item_id_m = $parameters['from_item_id_m'][0];
	 if (!empty($parameters['to_item_id_m'][0])) {
		$to_item_id_m = $parameters['to_item_id_m'][0];
	 } else {
		$to_item_id_m = $from_item_id_m;
	 }
	 $item = new item();
	 $item_range = $item->findBy_itemIdRange($from_item_id_m, $to_item_id_m);
	 foreach ($item_range as $items) {
		try {
		 $this->kanban_demand_calculator($items->item_id_m, $kbh);
		 $this->message .= "<br>Min Max Planner is Successfullyupdated for item_id_m - " . $items->item_id_m .
						 ' bom_cost_type : ' . $fp_kanban_planner_header_id;
		} catch (Exception $e) {
		 $this->message .= "<br>Min Max Plannerp failed for Item id " . $items->item_id_m . $e->getMessage();
		}
	 }
	 return $this->message;
	}

	if (!empty($parameters['from_item_number'][0])) {
	 $from_item_number = $parameters['from_item_number'][0];
	 if (!empty($parameters['to_item_number'][0])) {
		$to_item_number = $parameters['to_item_number'][0];
	 } else {
		$to_item_number = $from_item_number;
	 }
	 $item = new item();
	 $item_range = $item->findBy_itemNumberRange_OrgId($from_item_number, $to_item_number, $org_id);

	 foreach ($item_range as $items) {
		try {
		 $this->kanban_demand_calculator($items->item_id_m, $kbh);
		 $this->message .= "<br>Kanban Planner is Successfully updated for item_id_m - " . $items->item_id_m ;
		} catch (Exception $e) {
		 $this->message .= "<br>Kanban Plannerp failed for Item id " . $items->item_id_m . $e->getMessage();
		}
	 }
	 return $this->message;
	}

	//if no item id/number is given
	$fcl = new fp_forecast_line();
	$fcl->fp_forecast_header_id = $kbh->demand_source;
	$fcl_i = $fcl->findAll_distinctItems_ofHeader();
//	pa($fcl_i);
	$this->message .= "<br/>Using  Min Max Planner for All Items ";
	foreach ($fcl_i as $items) {
	 try {
		$this->kanban_demand_calculator($items->item_id_m, $kbh);
		$this->message .= "<br>Min Max Planner is Successfullyupdated for item_id_m - " . $items->item_id_m .
						' bom_cost_type : ' . $fp_kanban_planner_header_id;
	 } catch (Exception $e) {
		$this->message .= "<br>Min Max Plannerp failed for Item id " . $items->item_id_m . $e->getMessage();
	 }
	}
	return $this->message;
 }

 public function kanban_demand_calculator($item_id_m, $mmh) {
	$fctl = new fp_forecast_line();
	$fctl->item_id_m = $item_id_m;
	$fctl->fp_forecast_header_id = $mmh->demand_source;
	$forecast_lines = $fctl->findBy_ItemId_headerId();
	if (empty($forecast_lines)) {
	 return;
	}
	$mmd = new fp_kanban_demand();
	foreach ($forecast_lines as $forecast) {
	 $mmd->fp_kanban_demand_id = null;
	 $mmd->item_id_m = $forecast->item_id_m;
	 $mmd->plan_id = $mmh->fp_kanban_planner_header_id;
	 $mmd->quantity = $forecast->total_original;
	 $mmd->demand_item_id_m = $fctl->item_id_m;
	 $mmd->toplevel_demand_item_id_m = $fctl->item_id_m;
	 $mmd->demand_type = 'FORECAST';
	 $mmd->source = $forecast->fp_forecast_header_id;
	 $mmd->audit_trial();
	 $mmd->save();
	 $this->_kanban_demand_calculator_forComponents($item_id_m, $mmd);
	}
 }

 private function _kanban_demand_calculator_forComponents($item_id_m, $mmd) {
//	$mmd->audit_trial();
//	$mmd->save();

	$boh = new bom_header();
	$boh->item_id_m = $item_id_m;
	$boh_i = $boh->findBy_itemId();
	if (empty($boh_i)) {
	 return;
	}
	foreach ($boh->field_a as $key => $value) {
	 if (isset($boh_i->$value)) {
		$boh->$value = $boh_i->$value;
	 }
	}
	$bol = new bom_line();
	$bol_i = $bol->findBy_parentId($boh->bom_header_id);
	if (empty($bol_i)) {
	 return;
	}
	$mmd_n = new fp_kanban_demand();
	foreach ($bol_i as $items) {
	 $mmd_n->fp_kanban_demand_id = null;
	 $mmd_n->item_id_m = $items->component_item_id_m;
	 $mmd_n->plan_id = $mmd->plan_id;
	 $mmd_n->quantity = $mmd->quantity * $items->usage_quantity;
	 $mmd_n->demand_item_id_m = $item_id_m;
	 $mmd_n->toplevel_demand_item_id_m = $mmd->toplevel_demand_item_id_m;
	 $mmd_n->demand_type = 'FORECAST';
	 $mmd_n->source = $mmd->source;
	 $mmd_n->audit_trial();
	 $mmd_n->save();
	 $boh->item_id_m = $items->component_item_id_m;
	 $boh_i = $boh->findBy_itemId();
	 if (!empty($boh_i)) {
		$this->_kanban_demand_calculator_forComponents($items->component_item_id_m, $mmd_n);
	 }
	}
 }

 private function _get_kanban_attributes($item_id_m) {
	global $db;
	$sql = "
				 SELECT item.item_number, item.item_description, item.planning_method, item.make_buy, item.uom_id,
				 item.sourcing_rule_id,
				 org_v.org_id, org_v.currency_code, org_v.business_org_id, cic.standard_cost, cic.purchase_price,
				 item.kanban_min_quantity, item.kanban_max_quantity, item.kanban_multibin_number, item.kanban_multibin_size, 
				 item.minimum_order_quantity, item.fix_lot_multiplier, 
				 onhand_wo_o.item_id_m as item_id_m , onhand_wo_o.onhand as onhand, onhand_wo_o.open_wo as open_wo,
								open_po_req_o.open_req open_req , open_po_req_o.open_po as open_po, open_po_req_o.open_req_intf as open_req_intf,
							 (IFNULL(onhand_wo_o.onhand,0) + IFNULL(onhand_wo_o.open_wo,0) + IFNULL(open_po_req_o.open_req_intf,0) +
							 IFNULL(open_po_req_o.open_req,0) + IFNULL(open_po_req_o.open_po,0)) as total_supply,
							 (IFNULL(item.pre_processing_lt,0) + IFNULL(item.post_processing_lt,0) + 
							 IFNULL(item.processing_lt,0)) as leadtime
					FROM (
						 SELECT onhand_wo.item_id_m as item_id_m , onhand_wo.onhand as onhand, onhand_wo.open_wo as open_wo
						 FROM (
						 SELECT item.item_id_m as item_id_m, oh.onhand as onhand, wwh.open_wo as open_wo
						 FROM item 
						 LEFT JOIN (SELECT item_id_m, sum(onhand) as onhand from onhand  GROUP BY item_id_m) oh ON oh.item_id_m = item.item_id_m
						 LEFT JOIN ( SELECT item_id_m, sum(nettable_quantity - IFNULL(completed_quantity,0) - IFNULL(scrapped_quantity,0))as open_wo 
						 from wip_wo_header  GROUP BY item_id_m) wwh ON wwh.item_id_m = item.item_id_m
						 WHERE  item.planning_method = 'MULTI_kanban' OR item.planning_method = 'kanban'
						 ) onhand_wo
					)onhand_wo_o

				 LEFT JOIN (
											SELECT open_po_req.item_id_m as item_id_m, open_po_req.open_req open_req , open_po_req.open_po as open_po,
											open_po_req.open_req_intf as open_req_intf
										 FROM (
										 SELECT item.item_id_m as item_id_m,  prv.open_req as open_req, pav.open_po as open_po, 
										 proi.open_req_intf as open_req_intf
										 FROM item 
										 LEFT JOIN (SELECT item_id_m, SUM(open_quantity) as open_po from po_all_v  GROUP BY item_id_m) pav ON pav.item_id_m = item.item_id_m
										 LEFT JOIN ( SELECT item_id_m, sum(quantity)as open_req from po_requisition_all_v WHERE order_number = '' OR order_number IS NULL GROUP BY item_id_m) prv ON prv.item_id_m = item.item_id_m
										 LEFT JOIN ( SELECT item_id_m, sum(quantity)as open_req_intf from po_requisition_interface GROUP BY item_id_m) proi ON proi.item_id_m = item.item_id_m
										 WHERE  item.planning_method = 'MULTI_kanban' OR item.planning_method = 'kanban'
										 ) open_po_req 
					 )open_po_req_o 
				 ON onhand_wo_o.item_id_m = open_po_req_o.item_id_m
				 LEFT JOIN item ON item.item_id_m = open_po_req_o.item_id_m
				 LEFT JOIN org_v ON org_v.org_id = item.org_id
				 LEFT JOIN cst_item_cost_v cic ON cic.item_id_m = item.item_id_m
				 WHERE item.item_id_m = :item_id_m 
				 AND cic.bom_cost_type = 'FROZEN';
";
  
    switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

	$param_a = ['item_id_m'];
	$value_a = [ 'item_id_m' => $item_id_m];
	$result = $db->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? array_pop($result) : false;
//insert into requisition interface
 }

 private function _create_supply_for_kanban($item_id_m) {
	if (isset($all_attributes)) {
	 unset($all_attributes);
	}
	$all_attributes = $this->_get_kanban_attributes($item_id_m);
	if (!$all_attributes) {
	 return;
	}
	$all_attributes->total_order_quantity = null;
	if ($all_attributes->total_supply > $all_attributes->kanban_min_quantity) {
	 $all_attributes->order_quantity = null;
	 return $all_attributes;
	}

	//for min max
	if ($all_attributes->planning_method == 'kanban') {
	 if (!empty($all_attributes->kanban_max_quantity)) {
		$all_attributes->order_quantity = $all_attributes->kanban_max_quantity - $all_attributes->total_supply;
	 } else if ($all_attributes->total_supply < 0) {
		$all_attributes->order_quantity = abs($all_attributes->total_supply);
	 } else {
		$all_attributes->order_quantity = null;
	 }
	 if ($all_attributes->order_quantity < $all_attributes->minimum_order_quantity) {
		$all_attributes->order_quantity = $all_attributes->minimum_order_quantity;
	 }
	 if ($all_attributes->fix_lot_multiplier > 1) {
		$reminder = fmod($all_attributes->order_quantity, $all_attributes->fix_lot_multiplier);
		$all_attributes->order_quantity +=!empty($reminder) ? ($all_attributes->fix_lot_multiplier - $reminder) : 0;
	 }
	 $all_attributes->total_order_quantity = $all_attributes->order_quantity;
	 if ($all_attributes->make_buy == 'Buy') {
		//cretae requisition
		$this->_cretae_requistion($all_attributes);
	 } else if ($all_attributes->make_buy == 'Make') {
		//cretae Work Order
		$this->_cretae_wo($all_attributes);
	 }
	 return $all_attributes;
	} // for multi min max
	else if ($all_attributes->planning_method == 'MULTI_kanban') {
	 if (!empty($all_attributes->kanban_max_quantity)) {
		$required_quantity = $all_attributes->kanban_max_quantity - $all_attributes->total_supply;
		$all_attributes->order_quantity = $all_attributes->kanban_multibin_size;
	 } else if ($all_attributes->total_supply < 0) {
		$all_attributes->order_quantity = abs($all_attributes->total_supply);
	 } else {
		$all_attributes->order_quantity = null;
	 }

	 if ($all_attributes->order_quantity < $all_attributes->minimum_order_quantity) {
		$all_attributes->order_quantity = $all_attributes->minimum_order_quantity;
	 }

	 if ($all_attributes->fix_lot_multiplier > 1) {
		$reminder = fmod($all_attributes->order_quantity, $all_attributes->fix_lot_multiplier);
		$all_attributes->order_quantity +=!empty($reminder) ? $reminder : 0;
	 }

	 if ((!empty($all_attributes->order_quantity)) && (($all_attributes->order_quantity) > 0) && (!empty($required_quantity))) {
		$no_of_orders = ceil($required_quantity / $all_attributes->order_quantity);
	 } else if ((!empty($all_attributes->order_quantity)) && (($all_attributes->order_quantity) > 0)) {
		$no_of_orders = 1;
	 } else {
		$no_of_orders = 0;
	 }
  $all_attributes->total_order_quantity = $no_of_orders * $all_attributes->order_quantity;
	 if ($all_attributes->make_buy == 'Buy') {
		//cretae requisition
		while ($no_of_orders > 0) {
		 $this->_cretae_requistion($all_attributes);
		 $no_of_orders--;
		}
	 } else if ($all_attributes->make_buy == 'Make') {
		//cretae Work Order
		while ($no_of_orders > 0) {
		 $this->_cretae_wo($all_attributes);
		 $no_of_orders--;
		}
	 }
	 return $all_attributes;
	}
 }

 private function _cretae_requistion($obj) {
	$po_req_interface = new po_requisition_interface();
	$sourcing_rule_id = $obj->sourcing_rule_id;
	$srl = new po_sourcing_rule_line();
	$srl_i = $srl->findBy_parentId($sourcing_rule_id);
	if (!empty($srl_i)) {
	 foreach ($srl_i as $sourcing_rule_line) {
		$po_req_interface->po_requisition_interface_id = null;
		$po_req_interface->supplier_id = $sourcing_rule_line->supplier_id;
		$po_req_interface->supplier_site_id = $sourcing_rule_line->supplier_site_id;
		$po_req_interface->bu_org_id = $obj->business_org_id;
		$po_req_interface->po_requisition_type = 'EXTERNAL';
		$po_req_interface->line_type = 'GOODS';
		$po_req_interface->requisition_status = 'APPROVED';
		$po_req_interface->item_id_m = $obj->item_id_m;
		$po_req_interface->uom_id = $obj->uom_id;
		$po_req_interface->item_description = $obj->item_description;
		$po_req_interface->currency = $obj->currency_code;
		$po_req_interface->receving_org_id = $obj->org_id;
		$po_req_interface->quantity = ($obj->order_quantity * $sourcing_rule_line->allocation) / 100;
		$unit_price = !empty($obj->purchase_price) ? $obj->purchase_price : $obj->standard_cost;
		$po_req_interface->unit_price = !empty($unit_price) ? $unit_price : '0.01';
		$po_req_interface->need_by_date = date('Y-m-d', strtotime("$obj->leadtime days"));
		$po_req_interface->audit_trial();
		$po_req_interface->save();
	 }
	 return;
	}
	$po_req_interface->bu_org_id = $obj->business_org_id;
	$po_req_interface->po_requisition_type = 'EXTERNAL';
	$po_req_interface->line_type = 'GOODS';
	$po_req_interface->requisition_status = 'APPROVED';
	$po_req_interface->item_id_m = $obj->item_id_m;
	$po_req_interface->uom_id = $obj->uom_id;
	$po_req_interface->item_description = $obj->item_description;
	$po_req_interface->currency = $obj->currency_code;
	$po_req_interface->receving_org_id = $obj->org_id;
	$po_req_interface->quantity = $obj->order_quantity;
	$unit_price = !empty($obj->purchase_price) ? $obj->purchase_price : $obj->standard_cost;
	$po_req_interface->unit_price = !empty($unit_price) ? $unit_price : '0.01';
	$po_req_interface->need_by_date = date('Y-m-d', strtotime("$obj->leadtime days"));
	$po_req_interface->audit_trial();
	$po_req_interface->save();
 }

 private function _cretae_wo($obj) {
	$woh = new wip_wo_header();

	$woh->org_id = $obj->org_id;
	$woh->item_id_m = $obj->item_id_m;
	$woh->wo_type = 'STANDARD';
	$woh->wip_accounting_group_id = 1;
	$woh->wo_status = 'UN_RELEASED';
	$woh->start_date = date('Y-m-d');
	$woh->completion_date = date('Y-m-d', strtotime("$obj->leadtime days"));
	$woh->nettable_quantity = $woh->quantity = $obj->order_quantity;

	$woh->audit_trial();
	$woh->save();
	$woh->_after_save();
 }

 public function prg_kanban_program($seralized_parameters) {
	$output_a = [];
	$parameters = unserialize($seralized_parameters);
	$this->message = '<br> Starting Min Max Program....<br>';

	if (!empty($parameters['org_id'][0])) {
	 $org_id = $parameters['org_id'][0];
	 $this->message .= '<br> Entered Org Id is : ' . $org_id;
	} else {
	 $this->message .= '<br> Error! : No org id found @ fp_kanban_planner_header ' . __LINE__;
	 return $this->message;
	}

	if (!empty($parameters['planning_method'][0])) {
	 $planning_method = $parameters['planning_method'][0];
	 $this->message .= '<br> Entered planning method is : ' . $planning_method;
	}

	if (!empty($parameters['item_id_m'][0])) {
	 $this->message .= "<br/>Using Min Max program by Item Id ";
	 $item_id_m = $parameters['item_id_m'][0];
	 try {
		$op = $this->_create_supply_for_kanban($item_id_m);
		array_push($output_a, $op);
		$this->message .= "<br/> Min Max Planner is Successfullyupdated for item_id_m - " . $item_id_m;
	 } catch (Exception $e) {
		$this->message .= "<br/> Min Max Planner fialed for Item id " . $item_id_m . $e->getMessage();
	 }
	 return $this->message;
	}

	if (!empty($parameters['from_item_id_m'][0])) {
	 $this->message .= "<br/>Using  Min Max Planner by Item Id Range ";
	 $from_item_id_m = $parameters['from_item_id_m'][0];
	 if (!empty($parameters['to_item_id_m'][0])) {
		$to_item_id_m = $parameters['to_item_id_m'][0];
	 } else {
		$to_item_id_m = $from_item_id_m;
	 }
	 $item = new item();
	 $item_range = $item->findBy_itemIdRange($from_item_id_m, $to_item_id_m);
	 foreach ($item_range as $items) {
		try {
		 $op = $this->_create_supply_for_kanban($items->item_id_m);
		 array_push($output_a, $op);
		 $this->message .= "<br>Min Max Program is Successfullyupdated for item_id_m - " . $items->item_id_m;
		} catch (Exception $e) {
		 $this->message .= "<br>Min Max Program failed for Item id " . $items->item_id_m . $e->getMessage();
		}
	 }
	 return $this->message;
	}

	if (!empty($parameters['from_item_number'][0])) {
	 $from_item_number = $parameters['from_item_number'][0];
	 if (!empty($parameters['to_item_number'][0])) {
		$to_item_number = $parameters['to_item_number'][0];
	 } else {
		$to_item_number = $from_item_number;
	 }
	 $item = new item();
	 $item_range = $item->findBy_itemNumberRange_OrgId($from_item_number, $to_item_number, $org_id);

	 foreach ($item_range as $items) {
		try {
		 $op = $this->_create_supply_for_kanban($items->item_id_m);
		 array_push($output_a, $op);
		 $this->message .= "<br>Min Max Planner is Successfullyupdated for item_id_m - " . $items->item_id_m;
		} catch (Exception $e) {
		 $this->message .= "<br>Min Max Program failed for Item id " . $items->item_id_m . $e->getMessage();
		}
	 }
	 return $this->message;
	}

	//if no item id/number is given
	$item = new item();
	$item_i = $item->findAll_kanban_ofOrgId($org_id);
	$this->message .= "<br/>Using  Min Max Planner for All Items ";
	foreach ($item_i as $items) {
	 try {
		$op = $this->_create_supply_for_kanban($items->item_id_m);
		if (!empty($op)) {
		 array_push($output_a, $op);
		}
		$this->message .= "<br>Min Max Program is Successfullyupdated for item_id_m - " . $items->item_id_m;
	 } catch (Exception $e) {
		$this->message .= "<br>Min Max Plannerp failed for Item id " . $items->item_id_m . $e->getMessage();
	 }
	}

	$return_array = [$this->message, $output_a];

	return $return_array;
 }

}

?>
