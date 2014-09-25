<?php

 class bom_line extends dbObject {

  public static $table_name = "bom_line";
  public static $primary_column = "bom_line_id";
  public static $parent_primary_column = "bom_header_id";
  public static $key_column = 'component_item_id_m';
  public static $module = "bom";
  public $field_a = [
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
   "ef_id",
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
   'bom_commonbom_line_id'
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   "bom_header_id"
  ];
  public $requiredField = [
   'bom_sequence',
   'routing_sequence',
   'component_item_id_m',
   'usage_quantity'
  ];
  public $bom_line_id;
  public $bom_header_id;
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
  public $time;
  public $msg;
  public $component_item_number;
  public $component_description;
  public $component_uom;
  public $bom_commonbom_line_id;

  public function _before_save() {
   if (!empty($this->bom_header_id)) {
//    pa($this);
    $bom_header = bom_header::find_by_id($this->bom_header_id);
    if (!empty($bom_header->common_bom_item_id_m)) {
     echo "<br>Common BOM, Only Unique attributes are saved";
     $cbl = new bom_commonbom_line();

     foreach ($cbl->field_a as $k => $v) {
      if (!empty($this->$v)) {
       $cbl->$v = $this->$v;
      }
     }
     $cbl_i = $cbl->findBy_bomHeaderId_lineId();
     if ($cbl_i) {
      $cbl->bom_commonbom_line_id = $cbl_i->bom_commonbom_line_id;
     }
     $cbl->audit_trial();
     $cbl->save();
     return -90;
    }
   }
  }

  public static function find_all_by_bomHeaderId($bom_headerId) {

   $sql = " Select * from ";
   $sql .= self::$table_name;
   $sql .= " WHERE bom_header_id = '{$bom_headerId}'";

   $all_bom_lines = self::find_by_sql($sql);

   return $all_bom_lines;
  }

 }

//end of inv_transaction class
?>