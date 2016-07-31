<?php

class fp_kanban_line_v extends dbObject {

 public static $form_class_name = "fp_kanban_line";
 public static $table_name = "fp_kanban_line_v";
 public static $primary_column = "fp_kanban_line_id";
 public static $key_column = 'item_id_m';
 public static $module = "fp";
 public $field_a = [
  'fp_kanban_line_id',
  'fp_kanban_header_id',
  'description',
  'card_number',
  'card_status',
  'supply_status',
  'kanban_size',
  'card_type',
  'org_id',
  'kbh_description',
  'item_id_m',
  'effective_from',
  'effective_to',
  'subinventory_id',
  'locator_id',
  'source_type',
  'supplier_id',
  'supplier_site_id',
  'from_org_id',
  'from_subinventory_id',
  'from_locator_id',
  'item_number',
  'item_description',
  'uom_id',
  'list_price',
  'sourcing_rule_id',
  'subinventory',
  'locator',
  'org',
  'bu_org_id',
  'lead_time'
 ];
 public $initial_search = [
  'card_number',
  'item_number',
  'subinventory',
  'locator',
 ];

 
  public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update Card',
   '_update_path' => 'form.php?class_name=fp_kanban_header',
 ];
  
 public $pageTitle = " Kanban Cards "; //page Title
 public $search_functions = [
  'Organization' => 'search_org_name',
  'Item Number From' => 'search_item_number_from',
  'Item Number To' => 'search_item_number_to',
 ];
 public $fp_kanban_line_id;
 public $fp_kanban_header_id;
 public $description;
 public $card_number;
 public $card_status;
 public $supply_status;
 public $kanban_size;
 public $card_type;
 public $org_id;
 public $kbh_description;
 public $item_id_m;
 public $effective_from;
 public $effective_to;
 public $subinventory_id;
 public $locator_id;
 public $source_type;
 public $supplier_id;
 public $supplier_site_id;
 public $from_org_id;
 public $from_subinventory_id;
 public $from_locator_id;
 public $item_number;
 public $item_description;
 public $uom_id;
 public $list_price;
 public $sourcing_rule_id;
 public $subinventory;
 public $locator;
 public $org;
 public $bu_org_id;
 public $lead_time;

 private function create_fp_kanban_line_v() {
  $sql = "
CREATE OR REPLACE VIEW fp_kanban_line_v
(
fp_kanban_line_id,   fp_kanban_header_id,   description,   card_number,   card_status,
supply_status,   kanban_size,   card_type, 
org_id,  kbh_description,   item_id_m,
effective_from,   effective_to,  subinventory_id,   locator_id,
source_type,   supplier_id,   supplier_site_id,   from_org_id,
from_subinventory_id,   from_locator_id,
item_number, item_description, uom_id, list_price, sourcing_rule_id, lead_time,
subinventory,locator,org, bu_org_id
)
AS
SELECT
kbl.fp_kanban_line_id,   kbl.fp_kanban_header_id,   kbl.description,   kbl.card_number,   kbl.card_status,
kbl.supply_status,   kbl.kanban_size,   kbl.card_type, 
kbh.org_id,  kbh.description,   kbh.item_id_m,
kbh.effective_from,   kbh.effective_to,  kbh.subinventory_id,   kbh.locator_id,
kbh.source_type,   kbh.supplier_id,   kbh.supplier_site_id,   kbh.from_org_id,
kbh.from_subinventory_id,   kbh.from_locator_id,
item.item_number, item.item_description, item.uom_id, item.list_price, item.sourcing_rule_id,
IFNULL(item.pre_processing_lt,0) + IFNULL(processing_lt,0) as lead_time,
sub.subinventory, locator.locator, org.org, org.business_org_id 
FROM
fp_kanban_line kbl,
item,
subinventory sub,
org,
fp_kanban_header kbh
LEFT JOIN locator ON locator.locator_id = kbh.locator_id

WHERE kbh.fp_kanban_header_id = kbl.fp_kanban_header_id
AND item.item_id_m = kbh.item_id_m
AND item.org_id = kbh.org_id
AND org.org_id = kbh.org_id
AND sub.subinventory_id = kbh.subinventory_id

";
 }

}

?>
