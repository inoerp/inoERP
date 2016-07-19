<?php

class fp_forecast_over_consumption_v extends dbObject {

 public static $form_class_name = "fp_forecast_header";
 public static $table_name = "fp_forecast_over_consumption_v";
 public static $primary_column = "fp_forecast_over_consumption_id";
 public static $key_column = 'sd_so_line_id';
 public static $module = "fp";
 public $field_a = [
  'forecast_group',
  'org',
  'so_number',
  'line_number',
  'item_number',
  'uom_name',
  'item_description',
  'schedule_ship_date',
  'quantity',
  'item_id_m',
  'uom_id',
  'fp_forecast_consumption_id',
  'sd_so_line_id',
  'sd_so_header_id',
 ];
 public $initial_search = [
  'item_number',
 ];
 public $pageTitle = " Forecast Details "; //page Title
 public $search_functions = [
  'Organization' => 'search_org_name',
  'Forecast Group ' => 'search_forecast_group',
 ];
 public $forecast_group;
 public $org;
 public $so_number;
 public $line_number;
 public $item_number;
 public $uom_name;
 public $item_description;
 public $schedule_ship_date;
 public $quantity;
 public $item_id_m;
 public $uom_id;
 public $fp_forecast_consumption_id;
 public $sd_so_line_id;
 public $sd_so_header_id;

 private function create_fp_forecast_over_consumption_v() {
  $sql = "
      CREATE OR REPLACE VIEW fp_forecast_over_consumption_v
      (
      forecast_group, org, so_number, line_number,
      item_number, uom_name,  item_description,schedule_ship_date,
      quantity,item_id_m, uom_id,fp_forecast_consumption_id, sd_so_line_id,
      sd_so_header_id
      )
      AS
      SELECT
      fg.forecast_group,org.org,sosh.so_number, sosl.line_number,
      item.item_number, uom.uom_name,  item.item_description,sosl.schedule_ship_date,
      foc.quantity,sosl.item_id_m, item.uom_id,foc.fp_forecast_consumption_id, foc.sd_so_line_id,
      sosl.sd_so_header_id

      FROM 
      fp_forecast_consumption foc,
      fp_forecast_group fg,
      sd_so_line sosl,
      sd_so_header sosh,
      org,
      item 
      LEFT JOIN uom ON uom.uom_id = item.uom_id

      WHERE foc.sd_so_line_id = sosl.sd_so_line_id
      AND fg.fp_forecast_group_id = foc.fp_forecast_group_id
      AND item.item_id_m = sosl.item_id_m
      AND item.org_id = sosl.shipping_org_id
      AND org.org_id = sosl.shipping_org_id
      AND sosh.sd_so_header_id = sosl.sd_so_header_id
      AND foc.quantity < 0
";
 }

}

?>
