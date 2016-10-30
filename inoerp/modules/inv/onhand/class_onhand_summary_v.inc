<?php

 class onhand_summary_v extends dbObject {

  public static $form_class_name = "item";
  public static $table_name = "onhand_summary_v";
  public static $primary_column = "onhand_id";
  public $field_a = [
   'onhand_id',
   'item_number',
   'item_description',
   'org_name',
   'subinventory',
   'locator',
   'uom_id',
   'onhand',
   'item_id_m',
   'org_id',
   'subinventory_id',
   'locator_id',
   'lot_id',
   'serial_id',
   'reservable_onhand',
   'transactable_onhand',
   'lot_status',
   'serial_status',
   'secondary_uom_id',
   'onhand_status',
   'ef_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'onhand_id',
   'item_number',
   'item_description',
   'org_name',
   'subinventory',
   'locator',
   'uom_id',
   'onhand',
   'item_id_m',
   'org_id',
   'subinventory_id',
   'locator_id',
  ];
  public $column = [
   'onhand_id',
   'item_number',
   'item_description',
   'org_name',
   'subinventory',
   'locator',
   'uom_id',
   'onhand',
   'item_id_m',
   'org_id',
   'subinventory_id',
   'locator_id',
  ];
  public $dateField = [
  ];
  public $pageTitle = " Onhand - Find Inventory Onhand "; //page Title
  public $search_groupBy = [
   'locator' => 'Locator',
   'subinventory' => 'Subinventory',
   'org_id' => 'Inventory Org',
  ];
  public $onhand_id;
  public $item_number;
  public $item_description;
  public $org_name;
  public $subinventory;
  public $locator;
  public $uom_id;
  public $onhand;
  public $item_id_m;
  public $org_id;
  public $subinventory_id;
  public $locator_id;
  public $lot_id;
  public $serial_id;
  public $reservable_onhand;
  public $transactable_onhand;
  public $lot_status;
  public $serial_status;
  public $secondary_uom_id;
  public $onhand_status;
  public $ef_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;

  public function __set($name, $value) {
   $this->$name = $value;
  }

  private function create_onhand_summary_v() {
   $sql = "
	 CREATE OR REPLACE VIEW onhand_summary_v
(onhand_id, item_number, item_description, org_name, 
uom_id,onhand, item_id_m, org_id, reservable_onhand, 
transactable_onhand
)
AS
SELECT onhand.onhand_id, item.item_number, item.item_description, 
org.org, onhand.uom_id, Sum(onhand.onhand),
onhand.item_id_m, onhand.org_id,  onhand.reservable_onhand, 
onhand.transactable_onhand
FROM onhand 
LEFT JOIN item ON onhand.item_id_m = item.item_id_m and item.org_id = onhand.org_id
LEFT JOIN org ON onhand.org_id = org.org_id
GROUP BY onhand.item_id_m, onhand.org_id
";
  }

  public function findBy_itemIdm_location() {
   $sql = "SELECT * FROM " . self::$table_name;
   $sql .= " WHERE item_id_m = '{$this->item_id_m}' ";
   if (!empty($this->org_id)) {
    $sql .= " AND org_id = '{$this->org_id}' ";
   }
   if (!empty($this->subinventory_id)) {
    $sql .= " AND subinventory_id = '{$this->subinventory_id}' ";
   }
   if (!empty($this->locator_id)) {
    $sql .= " AND locator_id = '{$this->locator_id}' ";
   }
   
   $sql = ino_perPageSql_i($sql, 1);

   $result = $this->findBySql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

  public static function staticVar_init($staticvar) {
   foreach (self::${$staticvar} as $key => $value) {
    self::${$staticvar}[$key] = gettext($value);
   }
  }
 
 }

//end of po_detail class
 dbObject::staticVar_init('search_groupBy');
?>
