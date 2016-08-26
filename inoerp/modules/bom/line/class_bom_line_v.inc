<?php

class bom_line_v extends dbObject {

 public static $form_class_name = "bom_header";
 public static $table_name = "bom_line_v";
 public static $primary_column = "bom_line_id";
 public $field_a = [
  'bom_header_id_h',
  'item_id_m',
  'org_id',
  'alternate_bom',
  'effective_date',
  'common_bom_item_id_m',
  'common_bom_org_id',
  'h_created_by',
  'h_creation_date',
  'h_last_update_by',
  'h_last_update_date',
  'bom_header_id',
  'bom_line_id',
  'bom_sequence',
  'routing_sequence',
  'component_item_id_m',
  'usage_basis',
  'usage_quantity',
  'auto_request_material_cb',
  'effective_start_date',
  'effective_end_date',
  'eco_number',
  'eco_implemented_cb',
  'planning_percentage',
  'yield',
  'include_in_cost_rollup_cb',
  'wip_supply_type',
  'supply_sub_inventory',
  'supply_locator',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'item_id_m',
  'org_id',
  'alternate_bom',
 ];
 public $search = [
 ];
 public $pageTitle = " BOM Lines "; //page Title
 public $bom_header_id_h;
 public $item_id_m;
 public $org_id;
 public $alternate_bom;
 public $effective_date;
 public $common_bom_item_id_m;
 public $common_bom_org_id;
 public $h_created_by;
 public $h_creation_date;
 public $h_last_update_by;
 public $h_last_update_date;
 public $bom_header_id;
 public $bom_line_id;
 public $bom_sequence;
 public $routing_sequence;
 public $component_item_id_m;
 public $usage_basis;
 public $usage_quantity;
 public $auto_request_material_cb;
 public $effective_start_date;
 public $effective_end_date;
 public $eco_number;
 public $eco_implemented_cb;
 public $planning_percentage;
 public $yield;
 public $include_in_cost_rollup_cb;
 public $wip_supply_type;
 public $supply_sub_inventory;
 public $supply_locator;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 private function create_bom_line_v() {
  $sql = "
CREATE OR REPLACE VIEW bom_line_v
(
bom_header_id_h, item_id_m, org_id, alternate_bom, effective_date,common_bom_item_id_m,
common_bom_org_id, h_created_by, h_creation_date,  h_last_update_by, h_last_update_date,
bom_header_id, bom_line_id, bom_sequence, routing_sequence, component_item_id_m, usage_basis,
usage_quantity, auto_request_material_cb, effective_start_date, effective_end_date, eco_number,
eco_implemented_cb, planning_percentage, yield, include_in_cost_rollup_cb, wip_supply_type, supply_sub_inventory,
supply_locator, created_by, creation_date, last_update_by, last_update_date
)
AS
SELECT 
bh.bom_header_id as bom_header_id_h, bh.item_id_m, bh.org_id, bh.alternate_bom, bh.effective_date,bh.common_bom_item_id_m,
bh.common_bom_org_id, bh.created_by as h_created_by, bh.creation_date as h_creation_date,  bh.last_update_by as h_last_update_by,
bh.last_update_date as h_last_update_date,
bl.bom_header_id, bl.bom_line_id, bl.bom_sequence, bl.routing_sequence, bl.component_item_id_m, bl.usage_basis,
bl.usage_quantity, bl.auto_request_material_cb, bl.effective_start_date, bl.effective_end_date, bl.eco_number,
bl.eco_implemented_cb, bl.planning_percentage, bl.yield, bl.include_in_cost_rollup_cb, 
CASE COALESCE(bl.wip_supply_type, 0)
        WHEN '0' THEN
                (
                SELECT  wip_supply_type
                FROM    item
                WHERE   item.item_id_m = bl.component_item_id_m
                        AND item.org_id = bh.org_id
                )
        ELSE
                bl.wip_supply_type
        END AS wip_supply_type,
CASE COALESCE(bl.supply_sub_inventory, 0)
        WHEN '0' THEN
                (
                SELECT  wip_supply_subinventory
                FROM    item
                WHERE   item.item_id_m = bl.component_item_id_m
                        AND item.org_id = bh.org_id
                )
        ELSE
                bl.supply_sub_inventory
        END AS supply_sub_inventory,
		CASE COALESCE(bl.supply_locator, 0)
        WHEN '0' THEN
                (
                SELECT  wip_supply_locator
                FROM    item
                WHERE   item.item_id_m = bl.component_item_id_m
                        AND item.org_id = bh.org_id
                )
        ELSE
                bl.supply_locator
        END AS supply_locator,
 bl.created_by, bl.creation_date, bl.last_update_by,
bl.last_update_date

FROM
bom_line bl,
bom_header bh
WHERE bh.bom_header_id = bl.bom_header_id
AND (bh.common_bom_item_id_m IS NULL OR  bh.common_bom_item_id_m = 0)

UNION

SELECT
bh.bom_header_id as bom_header_id_h, bhc.item_id_m, bhc.org_id, bhc.alternate_bom, bhc.effective_date,bhc.common_bom_item_id_m,
bhc.common_bom_org_id, bh.created_by as h_created_by, bh.creation_date as h_creation_date,  bh.last_update_by as h_last_update_by,
bh.last_update_date as h_last_update_date,
bl.bom_header_id, bl.bom_line_id, bl.bom_sequence, bl.routing_sequence, bl.component_item_id_m, bl.usage_basis,
bl.usage_quantity, bl.auto_request_material_cb, bl.effective_start_date, bl.effective_end_date, bl.eco_number,
bl.eco_implemented_cb, bl.planning_percentage, bl.yield, bl.include_in_cost_rollup_cb, 
CASE COALESCE(bl.wip_supply_type, 0)
        WHEN '0' THEN
                (
                SELECT  wip_supply_type
                FROM    item
                WHERE   item.item_id_m = bl.component_item_id_m
                        AND item.org_id = bh.org_id
                )
        ELSE
                bl.wip_supply_type
        END AS wip_supply_type,
CASE COALESCE(bl.supply_sub_inventory, 0)
        WHEN '0' THEN
                (
                SELECT  wip_supply_subinventory
                FROM    item
                WHERE   item.item_id_m = bl.component_item_id_m
                        AND item.org_id = bh.org_id
                )
        ELSE
                bl.supply_sub_inventory
        END AS supply_sub_inventory,
		CASE COALESCE(bl.supply_locator, 0)
        WHEN '0' THEN
                (
                SELECT  wip_supply_locator
                FROM    item
                WHERE   item.item_id_m = bl.component_item_id_m
                        AND item.org_id = bh.org_id
                )
        ELSE
                bl.supply_locator
        END AS supply_locator,
 bl.created_by, bl.creation_date, bl.last_update_by,
bl.last_update_date

FROM
bom_line bl,
bom_header bh,
bom_header bhc
WHERE bh.bom_header_id = bl.bom_header_id
AND (bhc.common_bom_item_id_m IS NOT NULL OR bhc.common_bom_item_id_m = 0)
AND bhc.common_bom_item_id_m = bh.item_id_m

";
 }

 public static function find_by_bomHeaderId($bom_headerId) {
  $sql = " Select * from ";
  $sql .= self::$table_name;
  $sql .= " WHERE bom_header_id_h = '{$bom_headerId}'";

  $all_bom_lines = self::find_by_sql($sql);
  return !empty($all_bom_lines) ? $all_bom_lines : false;
 }

 public static function find_by_bomHeaderId_revNumber($bom_headerId, $rev_num = '') {
  if (empty($rev_num)) {
   $sql = " Select * from ";
   $sql .= self::$table_name;
   $sql .= " WHERE bom_header_id_h = '{$bom_headerId}'";
  } else {
   $sql = " SELECT bl.bom_line_id, 	bl.bom_header_id, 	bl.bom_sequence, 	bl.routing_sequence, 	
     bl.component_item_id_m, 	bl.usage_basis, 	bl.usage_quantity, 	bl.auto_request_material_cb, 	
     bl.effective_start_date, 	bl.effective_end_date, 	bl.eco_number, 	bl.eco_implemented_cb, 	
     bl.planning_percentage, 	bl.yield, 	bl.include_in_cost_rollup_cb, 	bl.wip_supply_type, 	
     bl.supply_sub_inventory, 	bl.supply_locator, 	bl.ef_id, 	bl.created_by, 	bl.creation_date, 	
     bl.last_update_by, 	bl.last_update_date

     FROM      bom_line_v bl, 
       inv_item_revision iir
     WHERE  (bl.effective_end_date IS NULL OR bl.effective_end_date > iir.effective_start_date ) 
     AND bl.bom_header_id = '{$bom_headerId}' 
     AND iir.revision_name = '{$rev_num}'
     AND bl.item_id_m = iir.item_id_m
     AND bl.org_id = iir.org_id
     AND  bl.effective_start_date <= iir.effective_end_date
      ORDER BY bl.bom_sequence ASC";
  }
  $all_bom_lines = self::find_by_sql($sql);
  return !empty($all_bom_lines) ? $all_bom_lines : false;
 }

 public static function find_by_itemIdM_OrgId($item_id_m, $org_id) {
  $sql = "SELECT * FROM " . self::$table_name . " "
   . " where item_id_m = '{$item_id_m}' "
   . " AND org_id = '{$org_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_itemIdM_OrgId_revNumber($item_id_m, $org_id, $rev_number = '') {
  if (empty($rev_number)) {
   $sql = "SELECT * FROM " . self::$table_name . " "
    . " where item_id_m = '{$item_id_m}' "
    . " AND org_id = '{$org_id}' AND bl.effective_end_date IS NULL ";
  } else {
   $sql = " SELECT bl.bom_line_id, 	bl.bom_header_id, 	bl.bom_sequence, 	bl.routing_sequence, 	
     bl.component_item_id_m, 	bl.usage_basis, 	bl.usage_quantity, 	bl.auto_request_material_cb, 	
     bl.effective_start_date, 	bl.effective_end_date, 	bl.eco_number, 	bl.eco_implemented_cb, 	
     bl.planning_percentage, 	bl.yield, 	bl.include_in_cost_rollup_cb, 	bl.wip_supply_type, 	
     bl.supply_sub_inventory, 	bl.supply_locator, 		bl.created_by, 	bl.creation_date, 	
     bl.last_update_by, 	bl.last_update_date

     FROM      bom_line_v bl, 
       inv_item_revision iir
     WHERE  (bl.effective_end_date IS NULL OR bl.effective_end_date > iir.effective_start_date ) 
     AND bl.item_id_m = '{$item_id_m}' 
     AND iir.revision_name = '{$rev_number}'
     AND bl.item_id_m = iir.item_id_m
     AND bl.org_id = iir.org_id
     AND bl.org_id = '{$org_id}'
     AND  bl.effective_start_date <= iir.effective_end_date
    ORDER BY bl.bom_sequence ASC";
  }

  $result = self::find_by_sql($sql);


  return !empty($result) ? $result : false;
 }

 public function findBy_poDetailId() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE po_detail_id = :po_detail_id ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $param_a = ['po_detail_id'];
  $value_a = ['po_detail_id' => $this->po_detail_id];
  $result = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of inv_transaction class
?>