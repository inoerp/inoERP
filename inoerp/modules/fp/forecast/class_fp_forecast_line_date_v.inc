<?php

 class fp_forecast_line_date_v extends dbObject {
public static $form_class_name = "fp_forecast_header";
  public static $table_name = "fp_forecast_line_date_v";
  public static $primary_column = "fp_forecast_line_date_id";
  public static $key_column = 'item_id_m';
  public static $module = "fp";
  public $field_a = [
   'fp_forecast_line_date_id',
   'fp_forecast_line_id',
   'forecast',
   'forecast_group',
   'org',
   'item_number',
   'uom_name',
   'item_description',
   'forecast_date',
   'bucket_type',
   'original_quantity',
   'current_quantity',
   'source',
   'item_id_m',
   'uom_id'
  ];
  public $initial_search = [
   'item_number',
  ];
 
  public $pageTitle = " Forecast Details "; //page Title
  public $search_functions = [
   'Organization' => 'search_org_name',
   'Forecast ' => 'search_forecast_name',
   'Forecast Group ' => 'search_forecast_group',
  ];
  public $fp_forecast_line_date_id;
  public $fp_forecast_line_id;
  public $forecast;
  public $forecast_group;
  public $org;
  public $item_number;
  public $uom_name;
  public $item_description;
  public $forecast_date;
  public $bucket_type;
  public $original_quantity;
  public $current_quantity;
  public $source;
  public $item_id_m;
  public $uom_id;

  private function create_fp_forecast_line_date_v() {
   $sql = "
CREATE OR REPLACE VIEW fp_forecast_line_date_v
(
fp_forecast_line_date_id, fp_forecast_line_id,forecast,forecast_group,org,
item_number, uom_name,  item_description,forecast_date,bucket_type, original_quantity, current_quantity, source, item_id_m, uom_id
)
AS
SELECT
fld.fp_forecast_line_date_id, fld.fp_forecast_line_id,fh.forecast,fg.forecast_group,org.org,
item.item_number, uom.uom_name,  item.item_description,fld.forecast_date,fl.bucket_type, fld.original_quantity, fld.current_quantity, fld.source, fl.item_id_m, item.uom_id

FROM 
fp_forecast_line_date fld,
fp_forecast_line fl,
org,
fp_forecast_header fh 
LEFT JOIN fp_forecast_group fg ON fg.fp_forecast_group_id = fh.forecast_group_id,
item 
LEFT JOIN uom ON uom.uom_id = item.uom_id

WHERE fl.fp_forecast_line_id = fld.fp_forecast_line_id
AND fl.fp_forecast_header_id = fh.fp_forecast_header_id
AND item.item_id_m = fl.item_id_m
AND item.org_id = fh.org_id
AND org.org_id = fh.org_id

";
  }

 }

?>
