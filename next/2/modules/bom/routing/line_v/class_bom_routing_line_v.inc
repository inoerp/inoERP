<?php

 class bom_routing_line_v extends dbObject {
public static $form_class_name = "bom_routing_header";
  public static $table_name = "bom_routing_line_v";
  public static $primary_column = "bom_routing_line_id";
  public $field_a = [
   'bom_routing_header_id_h',
   'item_id_m',
   'alternate_routing',
   'org_id',
   'routing_revision',
   'effective_date',
   'common_routing_item_id_m',
   'description_h',
   'completion_subinventory',
   'completion_locator',
   'bom_routing_line_id',
   'bom_routing_header_id',
   'routing_sequence',
   'standard_operation_id',
   'department_id',
   'description',
   'count_point_cb',
   'auto_charge_cb',
   'backflush_cb',
   'minimum_transfer_quantity',
   'lead_time_percentage',
   'effective_start_date',
   'effective_end_date',
   'eco_number',
   'eco_implemented_cb',
   'include_in_rollup_cb',
   'referenced_cb',
   'yield',
   'cumm_yield',
  ];
  public $initial_search = [
   'item_id_m',
   'alternate_routing',
   'org_id',
  ];
  public $search = [
  ];
  public $pageTitle = " ROuting Lines "; //page Title
  public $bom_routing_header_id_h;
  public $item_id_m;
  public $alternate_routing;
  public $org_id;
  public $routing_revision;
  public $effective_date;
  public $common_routing_item_id_m;
  public $description_h;
  public $completion_subinventory;
  public $completion_locator;
  public $bom_routing_line_id;
  public $bom_routing_header_id;
  public $routing_sequence;
  public $standard_operation_id;
  public $department_id;
  public $description;
  public $count_point_cb;
  public $auto_charge_cb;
  public $backflush_cb;
  public $minimum_transfer_quantity;
  public $lead_time_percentage;
  public $effective_start_date;
  public $effective_end_date;
  public $eco_number;
  public $eco_implemented_cb;
  public $include_in_rollup_cb;
  public $referenced_cb;
  public $yield;
  public $cumm_yield;

  private function create_bom_routing_line_v() {
   $sql = "
CREATE OR REPLACE VIEW bom_routing_line_v
(
bom_routing_header_id_h, item_id_m, alternate_routing, org_id, routing_revision, 
effective_date, common_routing_item_id_m, description_h, completion_subinventory, 
completion_locator,
bom_routing_line_id, bom_routing_header_id, routing_sequence, standard_operation_id,
department_id, description, count_point_cb, auto_charge_cb, backflush_cb,
minimum_transfer_quantity, lead_time_percentage, effective_start_date,
effective_end_date, eco_number, eco_implemented_cb, include_in_rollup_cb,
referenced_cb, yield, cumm_yield
)
AS
SELECT 
brh.bom_routing_header_id as bom_routing_header_id_h, brh.item_id_m, brh.alternate_routing, brh.org_id, brh.routing_revision, 
brh.effective_date, brh.common_routing_item_id_m, brh.description as description_h, brh.completion_subinventory, 
brh.completion_locator,
brl.bom_routing_line_id, brl.bom_routing_header_id, brl.routing_sequence, brl.standard_operation_id,
brl.department_id, brl.description, brl.count_point_cb, brl.auto_charge_cb, brl.backflush_cb,
brl.minimum_transfer_quantity, brl.lead_time_percentage, brl.effective_start_date,
brl.effective_end_date, brl.eco_number, brl.eco_implemented_cb, brl.include_in_rollup_cb,
brl.referenced_cb, brl.yield, brl.cumm_yield

FROM bom_routing_header brh,
bom_routing_line brl

WHERE brh.bom_routing_header_id = brl.bom_routing_header_id
AND (brh.common_routing_item_id_m IS NULL OR  brh.common_routing_item_id_m = 0)

UNION

SELECT 
brhc.bom_routing_header_id as bom_routing_header_id_h, brhc.item_id_m, brhc.alternate_routing, brhc.org_id, brhc.routing_revision, 
brhc.effective_date, brhc.common_routing_item_id_m, brhc.description as description_h, brhc.completion_subinventory, 
brhc.completion_locator,
brl.bom_routing_line_id, brl.bom_routing_header_id, brl.routing_sequence, brl.standard_operation_id,
brl.department_id, brl.description, brl.count_point_cb, brl.auto_charge_cb, brl.backflush_cb,
brl.minimum_transfer_quantity, brl.lead_time_percentage, brl.effective_start_date,
brl.effective_end_date, brl.eco_number, brl.eco_implemented_cb, brl.include_in_rollup_cb,
brl.referenced_cb, brl.yield, brl.cumm_yield

FROM bom_routing_header brh,
bom_routing_header brhc,
bom_routing_line brl

WHERE brh.bom_routing_header_id = brl.bom_routing_header_id
AND (brhc.common_routing_item_id_m IS NOT NULL OR brhc.common_routing_item_id_m = 0)
AND brhc.common_routing_item_id_m = brh.item_id_m
";
  }

  public static function find_by_routing_headerId($routing_header_id) {
   $sql = "SELECT * FROM " . self::$table_name . " where bom_routing_header_id = '{$routing_header_id}'";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

  public static function find_by_itemIdM_OrgId($item_id_m, $org_id) {
   $sql = "SELECT * FROM " . self::$table_name . " "
     . " where item_id_m = '{$item_id_m}' "
     . " AND org_id = '{$org_id}' "
     . " ORDER BY routing_sequence ASC";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

  public static function find_by_itemId($item_id_m) {
   $routingHeaderOfItem = bom_routing_header::find_by_itemId($item_id_m);
   $bom_routing_header_id = $routingHeaderOfItem[0]->bom_routing_header_id;
   $routing_line_details = self::find_by_routing_headerId($bom_routing_header_id);
   return $routing_line_details;
  }

 }

//end of inv_transaction class
?>