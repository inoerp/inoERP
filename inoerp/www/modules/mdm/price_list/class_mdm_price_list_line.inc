<?php

class mdm_price_list_line extends dbObject {

 public static $table_name = "mdm_price_list_line";
 public static $primary_column = "mdm_price_list_line_id";
 public static $parent_primary_column = "mdm_price_list_header_id";
 public static $key_column = "line_type";
 public static $module = "mdm";
 public static $line_type_a = [
  'ITEM' => 'Item',
  'DEFAULT' => 'Default',
  'CATEGORY' => 'Catefory'];
 public $field_a = [
  'mdm_price_list_line_id',
  'mdm_price_list_header_id',
  'line_type',
  'org_id',
  'item_id_m',
  'uom_id',
  'unit_price',
  'formula',
  'effective_start_date',
  'effective_end_date',
  'use_price_break_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $initial_search = [
  'mdm_price_list_line_id',
  'mdm_price_list_header_id',
  'line_type',
  'item_id_m',
 ];
 public $column = [
  'mdm_price_list_line_id',
  'mdm_price_list_header_id',
  'line_type',
  'item_id_m',
 ];
 public $requiredField = [
  'mdm_price_list_header_id',
  'line_type',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "mdm_price_list_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  "item_number",
  'item_description',
 ];
 public $pageTitle = " Price List Line "; //page Title
 public $mdm_price_list_line_id;
 public $mdm_price_list_header_id;
 public $line_type;
 public $org_id;
 public $item_id_m;
 public $uom_id;
 public $unit_price;
 public $formula;
 public $effective_start_date;
 public $effective_end_date;
 public $use_price_break_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $item_number;
 public $item_description;
 public $quantity;
 public $price_date;

 public static function find_all_lines() {
  $sql = " SELECT * FROM " . self::$table_name;
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_header_id($id) {
  $vgl = new mdm_price_list_line();
  return $vgl->findBy_parentId($id);
 }

 public static function find_by_optionId_lineCode($header_id, $code) {
  $sql = "SELECT * FROM " . self::$table_name .
   " where code={$code} AND mdm_price_list_header_id={$header_id}  ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_push($result) : $result;
 }

 public function _before_save() {
  if (!(empty($this->item_number)) && empty($this->item_id_m)) {
   $item_s = item::find_by_itemNumber_fromMasterOrg($this->item_number);
   $this->item_id_m = $item_s->item_id_m;
  }
 }

 public static function priceBy_headerId_ItemId($item_id_m, $price_date, $mdm_price_list_header_id = '1') {
  $sql = " 
	 SELECT *
		FROM mdm_price_list_line 
		WHERE  mdm_price_list_header_id = '{$mdm_price_list_header_id}'
		AND item_id_m = '{$item_id_m}'
		AND effective_start_date < '{$price_date}'
		AND(effective_end_date IS NULL OR effective_end_date > '{$price_date}')
";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function priceBy_itemDetails() {
  $sql = " 
	 
   SELECT mdm_price_list_line_id, item_id_m, mdm_price_list_header_id, uom_id, unit_price
		FROM mdm_price_list_line 
		WHERE  mdm_price_list_header_id = '{$this->mdm_price_list_header_id}'
		AND item_id_m = '{$this->item_id_m}'
		AND effective_start_date < '{$this->price_date}'
		AND(effective_end_date IS NULL OR effective_end_date > '{$this->price_date}')
    AND use_price_break_cb IS NULL
";
  $sql = ino_perPageSql_i($sql, 1);
  $sql.= "
    UNION
    SELECT pll.mdm_price_list_line_id, pll.item_id_m, pll.mdm_price_list_header_id, pll.uom_id, pld.unit_price
		FROM mdm_price_list_line  pll,
         mdm_price_list_detail pld
    WHERE pll.mdm_price_list_line_id = pld.mdm_price_list_line_id
		AND  pll.mdm_price_list_header_id = '{$this->mdm_price_list_header_id}'
		AND pll.item_id_m = '{$this->item_id_m}'
		AND pld.effective_start_date < '{$this->price_date}'
		AND(pld.effective_end_date IS NULL OR pld.effective_end_date > '{$this->price_date}')
     AND pld.qty_from <= '{$this->quantity}'
		AND(pld.qty_to IS NULL OR pld.qty_to >= '{$this->quantity}')
    AND pll.use_price_break_cb IS NOT NULL
";
    $sql = ino_perPageSql_i($sql, 1);

//    echo $sql;
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function priceBy_headerId_orgId_ItemId($price_date) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE mdm_price_list_header_id = '{$this->mdm_price_list_header_id}' ";
  $sql .= " AND item_id_m = '{$this->item_id_m}' ";
  $sql .= " AND org_id = '{$this->org_id}' ";
  $sql .= " AND $this->effective_start_date < '{$price_date}' ";
  $sql .= " AND $this->effective_end_date > '{$price_date}' ";
  $sql .= " OR $this->effective_end_date IS NULL ";

  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function getPrice($price_date) {
  if (!empty($this->org_id)) {
   $result = $this->priceBy_headerId_orgId_ItemId($price_date);
  }
 }

}

//end of path class
?>