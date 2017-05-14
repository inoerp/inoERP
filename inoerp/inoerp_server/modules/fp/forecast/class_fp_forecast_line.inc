<?php

 class fp_forecast_line extends dbObject {

  public static $table_name = "fp_forecast_line";
  public static $primary_column = "fp_forecast_line_id";
  public static $parent_primary_column = "fp_forecast_header_id";
  public static $key_column = 'item_id_m';
  public static $module = "po";
  public $field_a = [
   'fp_forecast_line_id',
   'fp_forecast_header_id',
   'item_id_m',
   'bucket_type',
   'start_date',
   'end_date',
   'no_of_bucket',
//		 'current',
   'original',
   'created_by',
   'creation_date',
//		 'total_current',
   'total_original',
   'fp_consumption_id',
   'last_update_by',
   'last_update_date',
  ];
  //variables used for showing data

  public $fields_inHeader_needsToBeInserted_inPOST = [
   "fp_forecast_header_id"
  ];
  public $requiredField = [
   'fp_forecast_header_id',
   'item_id_m',
   'bucket_type',
   'start_date',
   'no_of_bucket',
   'original',
  ];
  public $fields_inForm_notInDataBase = [
   'item_description',
   "item_number",
   'uom_id',
   'current',
   'total_current'
  ];
  public $fp_forecast_line_id;
  public $fp_forecast_header_id;
  public $item_id_m;
  public $bucket_type;
  public $start_date;
  public $end_date;
  public $no_of_bucket;
  public $current;
  public $original;
  public $total_current;
  public $total_original;
  public $fp_consumption_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $item_number;
  public $item_description;
  public $uom_id;

  public function _before_save() {
   if ($this->bucket_type == 'PERIOD') {
    echo "<br> Period bukcet type is not enabled";
    return -90;
   }

   if ($this->bucket_type == 'WEEKLY') {
    $this->start_date = next_monday($this->start_date);
    $this->end_date = next_monday($this->end_date);
    $end_date_obj = new DateTime($this->end_date);
    $no_of_days = $end_date_obj->diff(new DateTime($this->start_date));
    $this->no_of_bucket = ceil($no_of_days->days / 7) + 1;
   }

   if (!empty($this->original)) {
    $this->total_original = $this->no_of_bucket * $this->original;
   }
  }

  private function _create_forecast_line_date($date) {
   global $dbc;
   $fc_ld = new fp_forecast_line_date();
   $fc_ld->fp_forecast_line_id = $this->fp_forecast_line_id;
   $fc_ld->forecast_date = $date;
   $fc_ld_i = $fc_ld->findBy_lineId_date();
   if ($fc_ld_i) {
    $fc_ld->fp_forecast_line_date_id = $fc_ld_i->fp_forecast_line_date_id;
    $fc_ld->current_quantity = $fc_ld_i->current_quantity;
   } else {
    $fc_ld->fp_forecast_line_date_id = null;
    $fc_ld->current_quantity = $this->original;
   }
   $fc_ld->original_quantity = $this->original;
   $fc_ld->source = 'FORECAST';
   $fc_ld->audit_trial();
   try {
    $fc_ld->save();
   } catch (Exception $e) {
    echo "<br>Failed to update date wise forecast details. Error @fp_forecast_line @@ line " . __LINE__ . '<br>' . $e->getMessage();
    $dbc->rollback = true;
   }
  }

  public function _after_save() {
   if ($this->bucket_type == 'DAILY') {
    $this->_create_forecast_line_date($this->start_date);
   } else if ($this->bucket_type == 'WEEKLY') {
    $date_s = new DateTime($this->start_date);
    for ($i1 = 0; $i1 < $this->no_of_bucket; $i1++) {
          $this->_create_forecast_line_date($date_s->format('Y-m-d'));
          $date_s->add(new DateInterval('P7D'));
    }
   }
  }

  public function findBy_ItemId_headerId() {
   $sql = " SELECT * FROM  ";
   $sql .= self::$table_name;
   $sql .= " WHERE fp_forecast_header_id =:fp_forecast_header_id AND item_id_m = :item_id_m ";

   $param_a = ['fp_forecast_header_id', 'item_id_m'];
   $value_a = ['fp_forecast_header_id' => $this->fp_forecast_header_id, 'item_id_m' => $this->item_id_m];
   $result = $this->findBy_sql($sql, $param_a, $value_a);
   return !empty($result) ? $result : false;
  }

  public function findAll_distinctItems_ofHeader() {
   $sql = "SELECT DISTINCT(item_id_m) FROM " .
     self::$table_name;
   $sql .= " WHERE fp_forecast_header_id =:fp_forecast_header_id ";
   $param_a = ['fp_forecast_header_id'];
   $value_a = ['fp_forecast_header_id' => $this->fp_forecast_header_id];
   $result_array = $this->findBy_sql($sql, $param_a, $value_a);
   return !empty($result_array) ? $result_array : false;
  }

 }

//end of inv_transaction class
?>