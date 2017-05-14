<?php

class cst_item_cost_v extends dbObject {

 public static $form_class_name = "cst_item_cost_header";
 public static $table_name = "cst_item_cost_v";
 public static $primary_column = "cst_item_cost_header_id";
 public $field_a = [
  'item_number',
  'item_description',
  'item_id_m',
  'org_id',
  'org',
  'standard_cost',
  'sales_price',
  'purchase_price',
  'cst_item_cost_header_id',
  'bom_cost_type'
 ];
 public $initial_search = [
  'item_number',
  'item_id_m',
  'org_id'
 ];
 public $column = [
  'item_number',
  'item_description',
  'item_id_m',
  'org_id',
  'org',
  'bom_cost_type',
  'standard_cost',
  'sales_price',
  'purchase_price',
  'cst_item_cost_header_id',
 ];
 public $search_functions = [
  'Cost Type' => 'search_bom_cost_type_nm',
  'Item From' => 'search_item_number_from',
  'Item To' => 'search_item_number_to',
  'Organization' => 'search_org_name',
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=cst_item_cost_header',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_view_path' => 'form.php?class_name=cst_item_cost_header',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Item Cost - Find & Update Item Costs "; //page Title
 public $item_number;
 public $item_description;
 public $item_id_m;
 public $org_id;
 public $org;
 public $bom_cost_type;
 public $standard_cost;
 public $sales_price;
 public $purchase_price;
 public $cst_item_cost_header_id;

 public function __set($name, $value) {
  $this->$name = $value;
 }

 private function create_cst_item_cost_v() {
  $sql = "
CREATE OR REPLACE VIEW cst_item_cost_v
(
item_number, item_description, item_id_m,org_id, org,
 sales_price, purchase_price, 
cst_item_cost_header_id, bom_cost_type, standard_cost
)
AS
SELECT item.item_number, item.item_description, cich.item_id_m as item_id_m ,cich.org_id as org_id, org.org, cich.sales_price as sales_price, 
cich.purchase_price as purchase_price, cich.cst_item_cost_header_id as cst_item_cost_header_id, 
cich.bom_cost_type as bom_cost_type , icsv.standard_cost as standard_cost
FROM cst_item_cost_header cich,
cst_item_cost_sum_v icsv,
item,
org
WHERE icsv.cst_item_cost_header_id = cich.cst_item_cost_header_id 
AND item.item_id_m = cich.item_id_m AND item.org_id = cich.org_id
AND org.org_id = cich.org_id
";
 }

 private function create_cst_item_cost_sum_v() {
  $sql = "
CREATE OR REPLACE VIEW cst_item_cost_sum_v
(
cst_item_cost_header_id, standard_cost
)
AS
    SELECT  ich.cst_item_cost_header_id cst_item_cost_header_id, sum(icl.amount) as standard_cost
    from cst_item_cost_header ich,
    cst_item_cost_line icl 
    WHERE icl.cst_item_cost_header_id = ich.cst_item_cost_header_id
    GROUP BY ich.cst_item_cost_header_id

";
 }

 public function findBy_ItemId_CostType() {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE bom_cost_type =:bom_cost_type AND item_id_m = :item_id_m ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $param_a = ['bom_cost_type', 'item_id_m'];
  $value_a = ['bom_cost_type' => $this->bom_cost_type, 'item_id_m' => $this->item_id_m];
  $result = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_ItemId_orgId_CostType($bom_cost_type = 'FROZEN') {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE bom_cost_type =:bom_cost_type AND org_id = :org_id  AND item_id_m = :item_id_m ";

  $value_a = ['bom_cost_type' => $bom_cost_type, 'org_id' => $this->org_id, 'item_id_m' => $this->item_id_m];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? ($result) : false;
 }

 public function standardCost_byItemId($item_id_m = '') {
  if (!empty($item_id_m)) {
   $this->item_id_m = $item_id_m;
  }
  $this->bom_cost_type = 'FROZEN';
  return $this->findBy_ItemId_CostType();
 }

 public static function find_cost_by_itemId_orgId($item_id, $org_id, $bom_cost_type = 'FROZEN') {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE bom_cost_type = '{$bom_cost_type}' AND org_id = '{$org_id}'  AND item_id_m = '{$item_id}' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of ap_transaction_detail class
?>