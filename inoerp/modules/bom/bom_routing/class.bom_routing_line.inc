<?php

 class bom_routing_line extends dbObject {

  public static $table_name = "bom_routing_line";
  public static $primary_column = "bom_routing_line_id";
  public static $parent_primary_column = "bom_routing_header_id";
  public static $multi_search_primary_column = "bom_routing_header_id"; //this value is used in multi search hidden value
  public static $key_column = 'routing_sequence';
  public static $module = "bom";
  public $field_a = [
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
   'ef_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date'
  ];
  public $checkbox = [
   "count_point_cb",
   'backflush_cb',
   'auto_charge_cb',
   'referenced_cb',
   'include_in_rollup_cb'
  ];
  public $requiredField = [
   'bom_routing_header_id',
   'routing_sequence',
   'department_id'
  ];
  public $fields_inForm_notInDataBase = [
   "extra_field_name",
   'extra_field_name_existing'
  ];
  public $bom_routing_line_id;
  public $bom_routing_header_id;
  public $routing_sequence;
  public $standard_operation_id;
  public $department_id;
  public $description;
  public $lead_time_percentage;
  public $count_point_cb;
  public $auto_charge_cb;
  public $effective_start_date;
  public $effective_end_date;
  public $eco_number;
  public $eco_implemented_cb;
  public $backflush_cb;
  public $yield;
  public $include_in_rollup_cb;
  public $minimum_transfer_quantity;
  public $referenced_cb;
  public $cumm_yield;
  public $ef_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;
  public $msg;
  public $extra_field_name;
  public $extra_field_name_existing;

  public function _before_save() {
   if (!empty($this->bom_routing_header_id)) {
    $brh = bom_routing_header::find_by_id($this->bom_routing_header_id);
    if (!empty($brh->common_routing_item_id_m)) {
     echo "<br>Common Routing, No unique line attributes to save";
     return -90;
    }
   }
  }

   public function _after_save() {
   $this->_update_extra_field('bom_routing_line',$this->bom_routing_line_id);
  }

  public static function find_by_routing_headerId($routing_header_id) {
   $sql = "SELECT * FROM " . self::$table_name . " where bom_routing_header_id = '{$routing_header_id}'";
   $result_array = self::find_by_sql($sql);
   return $result_array;
  }

  public static function find_by_itemId($item_id_m) {
   $routingHeaderOfItem = bom_routing_header::find_by_itemId($item_id_m);
   $bom_routing_header_id = $routingHeaderOfItem[0]->bom_routing_header_id;
   $routing_line_details = self::find_by_routing_headerId($bom_routing_header_id);
   return $routing_line_details;
  }

 }

//end of bom_routing_line class
?>