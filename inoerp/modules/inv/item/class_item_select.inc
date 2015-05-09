<?php

// public $rev_enabled_cb;  needs to be dropped - use item rev only
class item_select extends dbObject {

 public static $form_class_name = "item_select";
 public static $table_name = "item_select_v";
 public static $primary_column = "item_id_m";
 public static $key_column = 'item_number';
 public static $module = "inv";
 public $field_a = [
		 "item_id_m",
		 "item_number",
		 "item_description",
		 'product_line',
 ];
  public $initial_search = [
		 'item_id_m',
		 "item_number",
		 "item_status"
 ];
 public $column = [
 "item_id_m",
		 "item_number",
		 "item_description",
		 'product_line'
 ];
 public $pageTitle = " Item Search"; //page Title

 public $item_id_m;
 public $item_number;
 public $item_description;
 public $product_line;
 public $pre_processing_lt;
 public $post_processing_lt;
 public $processing_lt;
 public $cumulative_mfg_lt;
 public $cumulative_total_lt;
 public $lt_lot_size;
 
}

//end of item class
?>