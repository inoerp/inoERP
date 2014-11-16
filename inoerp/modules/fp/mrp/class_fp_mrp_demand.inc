<?php

 class fp_mrp_demand extends dbObject {

  public static $table_name = "fp_mrp_demand";
  public static $primary_column = "fp_mrp_demand_id";
  public static $parent_primary_column = "fp_mrp_header_id";
  public static $key_column = 'item_id_m';
  public static $module = "fp";
  public $field_a = [
   'fp_mrp_demand_id',
   'fp_mrp_header_id',
   'org_id',
   'item_id_m',
   'demand_date',
   'quantity',
   'demand_item_id_m',
   'toplevel_demand_item_id_m',
   'source_type',
   'primary_source_type',
   'source_header_id',
   'source_line_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'
  ];
  public $initial_search = [
   'source_type'
  ];
  public $search_functions = [
   'Organization' => 'search_org_name',
   'MRP Planner' => 'search_mrp_name',
  ];
  public $column = [
   'fp_mrp_demand_id',
   'fp_mrp_header_id',
   'org_id',
   'item_id_m',
   'demand_date',
   'quantity',
   'demand_item_id_m',
   'toplevel_demand_item_id_m',
   'source_type',
   'primary_source_type',
   'source_header_id',
   'source_line_id'
  ];
  public $requiredField = [
   'fp_mrp_header_id',
   'org_id',
   'item_id_m',
   'demand_date',
   'quantity',
  ];
  public $search = [
//		 '_show_view_path' => 1,
  ];
  public $prg_mrp_demand_calculator_parameters = [
   'Organization' => 'search_org_name',
   'MRP Planner ' => 'search_mrp_name',
  ];
  public $prg_mrp_demand_calculator_details = [
   'name' => 'MRP Demand Calculator',
   'description' => 'Calculate MRP Demands',
  ];
  public $pageTitle = " MRP Demand "; //page Title
  public $fp_mrp_demand_id;
  public $fp_mrp_header_id;
  public $org_id;
  public $item_id_m;
  public $demand_date;
  public $quantity;
  public $demand_item_id_m;
  public $toplevel_demand_item_id_m;
  public $source_type;
  public $primary_source_type;
  public $source_header_id;
  public $source_line_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;

  public function prepare_mrp_demand_calculator($fp_mrp_header_id, &$msg) {
   $mrpd = new fp_mrp_demand();
   $return = 1;
   try {
    $mrpd->deleteBy_parentId($fp_mrp_header_id);
   } catch (Exception $e) {
    $return = -99;
    $msg .= "<br>Failed to delete existing demand!. Error @ fp_mrp_header @ " . __LINE__ . $e->getMessage();
    echo $msg;
   }

   $mrpplo = new fp_mrp_planned_order();
   try {
    $mrpplo->deleteBy_parentId($fp_mrp_header_id);
   } catch (Exception $e) {
    $return = -99;
    $msg .= "<br>Failed to delete existing planned order!. Error @ fp_mrp_header @ " . __LINE__ . $e->getMessage();
    echo $msg;
   }

   $mrpexp = new fp_mrp_exception();
   try {
    $mrpexp->deleteBy_parentId($fp_mrp_header_id);
   } catch (Exception $e) {
    $return = -99;
    $msg .= "<br>Failed to delete existing exception!. Error @ fp_mrp_header @ " . __LINE__ . $e->getMessage();
    echo $msg;
   }
   return $return;
  }

  public function prg_mrp_demand_calculator($seralized_parameters) {
   $parameters = unserialize($seralized_parameters);
   $this->message = '<br> Starting MRP Demand Calculator....<br>';
   $mrph = new fp_mrp_header();

   if (!empty($parameters['org_id'][0])) {
    $org_id = $parameters['org_id'][0];
    $this->org_id = $org_id;
    $this->message .= '<br> Entered Org Id is : ' . $org_id;
   } else {
    $this->message .= '<br> Error! : No org id found @ fp_mrp_demand ' . __LINE__;
    return $this->message;
   }

   //calcuate the low level code
   $llc = new fp_mrp_lowlevel_code();
   $llc->create_lowlevel_code($org_id);


   if (!empty($parameters['fp_mrp_header_id'][0])) {
    $fp_mrp_header_id = $parameters['fp_mrp_header_id'][0];
    $this->message .= '<br> Entered MRP Header Id is : ' . $fp_mrp_header_id;
    $mrph->findBy_id($fp_mrp_header_id);
    if ($mrph->org_id != $org_id) {
     $this->message .= '<br> Error! : Entered MRP does not belong to the entered Org @ fp_mrp_demand ' . __LINE__;
     return $this->message;
    }
    $msg = '';
    $prepartion_result = $this->prepare_mrp_demand_calculator($fp_mrp_header_id, $this->message);
    if ($prepartion_result == -99) {
     echo $this->message;
     return -99;
    }
   } else {
    $this->message .= '<br> Error! : No MRP Header Id is found @ fp_mrp_header ' . __LINE__;
    return $this->message;
   }
   //if no item id/number is given
   $all_items = $llc->findAll_orderByLevel($org_id);
   $this->message .= "<br/>Using  MRP Demand Calculator for All Items ";
   foreach ($all_items as $items) {
    try {
     //all level 0 items
     $this->mrp_create_demand_and_plannedOrder($items->item_id_m, $mrph);
     //find all level 1 items - Caluclate the planned order and create new demands
     $this->message .= "<br>MRP Demand Calculator is Successfully updated for item_id_m - " . $items->item_id_m .
       ' fp_mrp_header_id : ' . $fp_mrp_header_id;
    } catch (Exception $e) {
     $this->message .= "<br>MRP Demand Calculatorp failed for Item id " . $items->item_id_m . $e->getMessage();
    }
   }
   return $this->message;
  }

  public function mrp_create_demand_and_plannedOrder($item_id_m, $mrph) {
   $mdsh = new fp_mds_header();
   $mdsh->findBy_id($mrph->demand_source);
   $mdsl = new fp_mds_line();
   $mdsl->item_id_m = $item_id_m;
   $mdsl->fp_mds_header_id = $mrph->demand_source;
   $demand_lines = $mdsl->findBy_ItemId_headerId();
   if (!empty($demand_lines)) {
    $this->mrp_create_demand_fromMDS($item_id_m, $mrph, $demand_lines, $mdsh->org_id);
   }
   $mrp_plo = new fp_mrp_planned_order();
   $mrp_plo->item_id_m = $item_id_m;
   $mrp_plo->fp_mrp_header_id = $mrph->fp_mrp_header_id;
   $all_planned_orders = $mrp_plo->create_planned_orders($item_id_m, $mrph->fp_mrp_header_id);
   if (!empty($all_planned_orders)) {
    foreach ($all_planned_orders as $planned_order) {
     $this->_mrp_demand_calculator_forComponents($item_id_m, $planned_order);
    }
   }
  }

  public function mrp_create_demand_fromMDS($item_id_m, $mrph, $demand_lines, $demand_org_id) {
   $mrpd = new fp_mrp_demand();
   foreach ($demand_lines as $demand_line) {
    $mrpd->fp_mrp_demand_id = null;
    $mrpd->org_id = $demand_org_id;
    $mrpd->item_id_m = $demand_line->item_id_m;
    $mrpd->fp_mrp_header_id = $mrph->fp_mrp_header_id;
    $mrpd->demand_date = $demand_line->demand_date;
    $mrpd->quantity = $demand_line->quantity;
    $mrpd->demand_item_id_m = $demand_line->item_id_m;
    $mrpd->toplevel_demand_item_id_m = $demand_line->item_id_m;
    $mrpd->source_type = !empty($demand_line->source_type) ? $demand_line->source_type : null;
    $mrpd->primary_source_type = $mrpd->source_type;
    $mrpd->source_header_id = $demand_line->source_header_id;
    $mrpd->source_line_id = $demand_line->source_line_id;
    $mrpd->audit_trial();
    $mrpd->save();
	   }
  }

  private function _mrp_demand_calculator_forComponents($item_id_m, $all_planned_orders) {
//	pa($all_planned_orders);
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
   $bol->effecitve_items_only = true;
   $bol->revsion_effecitve_date = $all_planned_orders->need_by_date;
   $bol_i = $bol->findBy_parentId($boh->bom_header_id);
   if (empty($bol_i)) {
    return;
   }
//	pa($bol_i);
   $mrpd_n = new fp_mrp_demand();
   foreach ($bol_i as $items) {
    $mrpd_n->fp_mrp_demand_id = null;
    $mrpd_n->org_id = $all_planned_orders->org_id;
    $mrpd_n->item_id_m = $items->component_item_id_m;
    $mrpd_n->fp_mrp_header_id = $all_planned_orders->fp_mrp_header_id;
    if (!empty($all_planned_orders->need_by_date)) {
     $item_details = item::find_by_id($mrpd_n->item_id_m);
     $total_lt = $item_details->pre_processing_lt + $item_details->processing_lt + $item_details->post_processing_lt;
     $lt = !empty($total_lt) ? $total_lt : 0;
     $ltp = 'P' . round($lt) . 'D';
     $date = new DateTime($all_planned_orders->need_by_date);
     $date->sub(new DateInterval($ltp));
     $mrpd_n->demand_date = $date->format('Y-m-d');
    }
    $mrpd_n->quantity = $all_planned_orders->quantity * $items->usage_quantity;
    $mrpd_n->demand_item_id_m = $item_id_m;
    $mrpd_n->toplevel_demand_item_id_m = $all_planned_orders->toplevel_demand_item_id_m;
    $mrpd_n->source_type = 'Dependent';
    $mrpd_n->primary_source_type = $all_planned_orders->primary_source_type;
    $mrpd_n->source_header_id = $all_planned_orders->source_header_id;
    $mrpd_n->source_line_id = $all_planned_orders->source_line_id;
    $mrpd_n->audit_trial();
//	 pa($mrpd_n);
    $mrpd_n->save();
   }
  }

  public function findBy_ItemId_HeaderId($item_id_m, $fp_mrp_header_id) {
   $sql = " SELECT * FROM " .
     self::$table_name .
     " WHERE item_id_m= :item_id_m  AND fp_mrp_header_id = :fp_mrp_header_id "
     . " ORDER BY  demand_date ASC ";
   $value_a = ['item_id_m' => $item_id_m, 'fp_mrp_header_id' => $fp_mrp_header_id];
   $result_array = $this->findBySql($sql, $value_a);
   return !empty($result_array) ? $result_array : false;
  }

 }

?>
