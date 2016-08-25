<?php

 class bom_commonbom_line extends dbObject {

  public static $table_name = "bom_commonbom_line";
  public static $primary_column = "bom_commonbom_line_id";
  public static $parent_primary_column = "bom_header_id";
  public static $key_column = 'bom_line_id';
  public static $module = "bom";
  public $field_a = [
   'bom_commonbom_line_id',
   'bom_header_id',
   'bom_line_id',
   'routing_sequence',
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
  //variables used for showing data
  public $fields_inForm_notInDataBase = [
   "component_item_number",
   "component_description",
   "component_uom",
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   "bom_header_id"
  ];
  public $requiredField = [
   'bom_header_id',
   'bom_line_id',
  ];
  public $bom_commonbom_line_id;
  public $bom_header_id;
  public $bom_line_id;
  public $routing_sequence;
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
  public $msg;
  public $component_item_number;
  public $component_description;
  public $component_uom;

  public function _before_save() {
   if (!empty($this->bom_header_id)) {
    $bom_header = bom_header::find_by_id($this->bom_header_id);
    if (!empty($bom_header->common_bom_item_id_m)) {
     echo "<br>Common BOM, No line is saved";
     return -90;
    }
   }
  }

  public static function find_all_by_bomHeaderId($bom_headerId) {

   $sql = " Select * from ";
   $sql .= self::$table_name;
   $sql .= " WHERE bom_header_id = '{$bom_headerId}'";

   $all_bom_commonbom_lines = self::find_by_sql($sql);

   return $all_bom_commonbom_lines;
  }

  public static function find_by_bomHeaderId_lineId($bom_headerId, $line_id) {
   $sql = " Select * from ";
   $sql .= self::$table_name;
   $sql .= " WHERE bom_header_id = '{$bom_headerId}' AND  bom_line_id = '{$line_id}' LIMIT 1 ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

  
    public function findBy_bomHeaderId_lineId() {
   $sql = " Select * from ";
   $sql .= self::$table_name;
   $sql .= " WHERE bom_header_id = :bom_header_id  AND  bom_line_id = :bom_line_id LIMIT 1 ";
   $value_a = ['bom_header_id' => $this->bom_header_id , 'bom_line_id' => $this->bom_line_id];
   $result = $this->findBySql($sql, $value_a);
   return !empty($result) ? array_pop($result) : false;
  }
  
 }

//end of inv_transaction class
?>