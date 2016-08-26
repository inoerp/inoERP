<?php

 class inv_item_revision extends dbObject {

  public static $table_name = "inv_item_revision";
  public static $primary_column = "inv_item_revision_id";
  public static $key_column = 'revision_name';
  public static $module = "inv";
  public $field_a = [
   'inv_item_revision_id',
   'revision_name',
   'item_id_m',
   'description',
   'org_id',
   'reason',
   'eco_number',
   'effective_start_date',
   'effective_end_date',
   'implementation_date',
   'origination_date',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  //variables used for showing data

  public $initial_search = [
   'eco_number',
  ];
  public $requiredField = [
   'revision_name',
   'item_id_m',
   'org_id',
  ];
//  public $pageTitle = " Approval Limit "; //page Title
  public $search = [
//   '_show_update_path' => 1,
//   '_show_view_path' => 1,
  ];
  public $inv_item_revision_id;
  public $revision_name;
  public $item_id_m;
  public $description;
  public $org_id;
  public $reason;
  public $eco_number;
  public $effective_start_date;
  public $effective_end_date;
  public $implementation_date;
  public $origination_date;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;

  public static function find_by_itemIdM_orgId($item_id_m, $org_id) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE item_id_m ='{$item_id_m}' AND org_id = '{$org_id}' ORDER BY effective_start_date DESC ";

   $result = self::find_by_sql($sql);

   return !empty($result) ? $result : false;
  }

  public static function find_currentRev_by_itemIdM_orgId($item_id_m, $org_id, $eff_date='') {
   $eff_date = empty($eff_date) ? current_time(1) : $eff_date;
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE item_id_m ='{$item_id_m}' AND org_id = '{$org_id}' AND '{$eff_date}' > effective_start_date "
   . " ORDER BY effective_start_date DESC  ";
   $sql = ino_perPageSql_i($sql, 1);

   $result = self::find_by_sql($sql);

   return !empty($result) ? array_pop($result) : false;
  }

 }

//end of bom class
?>