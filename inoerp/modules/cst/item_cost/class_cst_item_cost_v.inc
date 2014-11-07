<?php

class cst_item_cost_v extends dbObject {

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
		 'Cost Type' => 'search_bom_cost_type',
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
standard_cost, sales_price, purchase_price, 
cst_item_cost_header_id, bom_cost_type
)
AS
SELECT  item.item_number, item.item_description, ich.item_id_m,ich.org_id, org.org,
 sum(icl.amount) as standard_cost, ich.sales_price, ich.purchase_price,
 ich.cst_item_cost_header_id, ich.bom_cost_type
from cst_item_cost_header ich
LEFT JOIN cst_item_cost_line icl ON icl.cst_item_cost_header_id = ich.cst_item_cost_header_id
LEFT JOIN item ON item.item_id_m = ich.item_id_m
LEFT JOIN org ON org.org_id = ich.org_id
GROUP BY ich.cst_item_cost_header_id
ORDER BY item.item_number

";
 }

 public function findBy_ItemId_CostType() {
	$sql = " SELECT * FROM  ";
	$sql .= self::$table_name;
	$sql .= " WHERE bom_cost_type =:bom_cost_type AND item_id_m = :item_id_m ";
	$sql .= " LIMIT 1 ";

	$param_a = ['bom_cost_type', 'item_id_m'];
	$value_a = ['bom_cost_type' => $this->bom_cost_type, 'item_id_m' => $this->item_id_m];
	$result = $this->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 public function standardCost_byItemId($item_id_m = '') {
	if (!empty($item_id_m)) {
	 $this->item_id_m = $item_id_m;
	}
	$this->bom_cost_type = 'FROZEN';
	return $this->findBy_ItemId_CostType();
 }

}

//end of ap_transaction_detail class
?>