<?php

 class bom_routing_v extends dbObject {

  public static $table_name = "bom_routing_v";
  public static $primary_column = "bom_routing_header_id";
  public $field_a = [
      'item_number',
   'item_description',
   'uom_id',
   'item_type',
   'item_status',
   'bom_type',
   'costing_enabled_cb',
   'make_buy',
   'org',
   'type',
   'status',
   'org_description',
   'code',
   'subinventory',
   'locator',
   'bom_routing_header_id',
   'item_id_m',
   'alternate_routing',
   'org_id',
   'routing_revision',
   'effective_date',
   'common_routing_item_id_m',
   'description',
   'completion_subinventory',
   'completion_locator',
   'ef_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'

  ];
  public $initial_search = [
   'item_id_m',
   'org_id',
   'item_number',
   'item_description',
   'org',
   'org_description',
   'code',
   'subinventory',
   'locator',
  ];
  

  public $pageTitle = " Routing - Create & Update Routing "; //page Title
  public $search = [
   '_update_path' => 'form.php?class_name=bom_routing_header',
   '_show_update_path' => 1,
   '_view_path' => 'form.php?class_name=bom_routing_header',
   '_show_view_path' => 1,
  ];
  public $bom_routing_header_id;
  public $item_id_m;
  public $alternate_routing;
  public $org_id;
  public $routing_revision;
  public $effective_date;
  public $common_routing_item_id_m;
  public $description;
  public $completion_subinventory;
  public $completion_locator;
  public $ef_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $item_number;
  public $item_description;
  public $uom_id;
  public $item_type;
  public $item_status;
  public $bom_type;
  public $costing_enabled_cb;
  public $make_buy;
  public $org;
  public $type;
  public $status;
  public $org_description;
  public $code;
  public $subinventory;
  public $locator;

  private function create_bom_routing_v() {
   $sql = "
CREATE OR REPLACE VIEW bom_routing_v
(
bom_routing_header_id, item_id_m, alternate_routing, org_id, routing_revision, 
effective_date, common_routing_item_id_m, description, completion_subinventory, 
completion_locator, ef_id, created_by, creation_date, last_update_by, last_update_date,
item_number, item_description, uom_id, item_type, item_status, bom_type,
costing_enabled_cb, make_buy,
org, type, status, org_description, code, subinventory,locator
)
AS
SELECT 
bom_routing_header_id, brh.item_id_m, brh.alternate_routing, brh.org_id, brh.routing_revision, 
brh.effective_date, brh.common_routing_item_id_m, brh.description, brh.completion_subinventory, 
brh.completion_locator, brh.ef_id, brh.created_by, brh.creation_date, brh.last_update_by, brh.last_update_date,
item.item_number, item.item_description, item.uom_id, item.item_type, item.item_status, item.bom_type,
item.costing_enabled_cb, item.make_buy,
org.org, org.type, org.status, org.description, org.code, sub.subinventory,loc.locator

FROM bom_routing_header brh
LEFT JOIN item ON item.item_id_m = brh.item_id_m AND item.org_id = brh.org_id
LEFT JOIN org ON org.org_id = brh.org_id
LEFT JOIN subinventory sub ON sub.subinventory_id = brh.completion_subinventory
LEFT JOIN locator loc ON loc.locator_id = brh.completion_locator

";
  }

 }

//end of po_detail class
?>