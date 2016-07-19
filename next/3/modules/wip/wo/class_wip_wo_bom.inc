<?php

 class wip_wo_bom extends dbObject {

  public static $table_name = "wip_wo_bom";
  public static $primary_column = "wip_wo_bom_id";
  public static $parent_primary_column = "wip_wo_header_id";
  public static $key_column = 'bom_sequence';
  public static $module = "wip";
//  data base variables as stored database column name
  public $field_a = [
   'wip_wo_bom_id',
   'wip_wo_header_id',
   'bom_sequence',
   'routing_sequence',
   'component_item_id_m',
   'component_revision',
   'usage_basis',
   'usage_quantity',
   'yield',
   'wip_supply_type',
   'supply_sub_inventory',
   'supply_locator',
   'required_quantity',
   'issued_quantity',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'
  ];
//variables used for showing data
  public $fields_inForm_notInDataBase = [
   "component_item_number",
   "component_description",
   "component_uom",
   'open_quantity',
   'serial_generation',
   'serial_number',
   'inv_serial_number_id',
   'lot_generation',
   'lot_number'
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   'wip_wo_header_id'
  ];
  public $requiredField = [
   'wip_wo_header_id',
   'bom_sequence',
   'routing_sequence',
   'component_item_id_m',
   'usage_basis',
   'usage_quantity'
  ];
  public $wip_wo_bom_id;
  public $wip_wo_header_id;
  public $bom_sequence;
  public $routing_sequence;
  public $component_item_id_m;
  public $component_revision;
  public $usage_basis;
  public $usage_quantity;
  public $yield;
  public $required_quantity;
  public $issued_quantity;
  public $wip_supply_type;
  public $supply_sub_inventory;
  public $supply_locator;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;
  public $msg;
  public $component_item_number;
  public $component_description;
  public $component_uom;
  public $open_quantity;
  public $lot_number;
  public $serial_number;
  public $inv_serial_number_id;
  public $serial_number_id;
  public $serial_generation;
  public $lot_generation;
  private $_serial_type;

  public static function find_by_wip_wo_headerId($wi_wo_header_id) {
   global $db;
   $sql = "SELECT * FROM " .
     self::$table_name .
     " where wip_wo_header_id= '{$wi_wo_header_id}' ";
   $result = self::find_by_sql($sql);
   return $result;
  }

  public static function find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $routing_sequence) {
   global $db;
   $sql = "SELECT * FROM " .
     self::$table_name .
     " where wip_wo_header_id= '{$wip_wo_header_id}' 
					 AND routing_sequence= '{$routing_sequence}' ";
   $result = self::find_by_sql($sql);
   return $result;
  }

  public function findBy_woHeaderId_routingSeq() {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE wip_wo_header_id = :wip_wo_header_id ";
   $sql .= " AND routing_sequence = :routing_sequence ";

   $param_a = ['wip_wo_header_id', 'routing_sequence'];
   $value_a = ['wip_wo_header_id' => $this->wip_wo_header_id, 'routing_sequence' => $this->routing_sequence];
   $result = $this->findBy_sql($sql, $param_a, $value_a);
   return !empty($result) ? $result : false;
  }

 }

//end of wip_wo_bom class
?>