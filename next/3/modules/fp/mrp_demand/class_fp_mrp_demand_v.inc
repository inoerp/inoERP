<?php

class fp_mrp_demand_v extends dbObject {

 public static $form_class_name = "fp_mrp_header";
 public static $table_name = "fp_mrp_demand_v";
 public static $primary_column = "fp_mrp_demand_id";
 public static $key_column = 'item_id_m';
 public static $module = "fp";
 public $field_a = [
		 'fp_mrp_demand_id',
		 'fp_mrp_header_id',
		 'mrp_name',
		 'org_id',
		 'item_id_m',
		 'demand_date',
		 'quantity',
		 'demand_item_id_m',
		 'toplevel_demand_item_id_m',
		 'source_type',
		 'primary_source_type',
		 'source_header_id',
		 'source_line_id',
		 'item_number',
		 'item_description',
		 'planner',
		 'product_line',
		 'standard_cost',
		 'sales_price',
		 'purchase_price',
 ];
 public $initial_search = [
		 'item_number',
		 'fp_mrp_header_id',
		 'planner',
		 'product_line',
 ];
 public $column = [
		 'fp_mrp_demand_id',
		 'fp_mrp_header_id',
		 'mrp_name',
		 'org_id',
		 'item_id_m',
		 'demand_date',
		 'quantity',
		 'demand_item_id_m',
		 'toplevel_demand_item_id_m',
		 'source_type',
		 'primary_source_type',
		 'source_header_id',
		 'source_line_id',
		 'item_number',
		 'item_description',
		 'planner',
		 'product_line',
		 'standard_cost',
		 'sales_price',
		 'purchase_price',
 ];
 public $requiredField = [

 ];
 public $search = [

 ];
 public $pageTitle = " MRP Demand View "; //page Title
 public $search_functions = [
		 'Organization' => 'search_org_name',
    'MRP Planner ' => 'search_mrp_name',
 ];
public $fp_mrp_demand_id;
public $fp_mrp_header_id;
public $mrp_name;
public $org_id;
public $item_id_m;
public $demand_date;
public $quantity;
public $demand_item_id_m;
public $toplevel_demand_item_id_m;
public $source_type;
public $primary_source_type;
public $source_header_id;
public $source_line_id;
public $item_number;
public $item_description;
public $planner;
public $product_line;
public $standard_cost;
public $sales_price;
public $purchase_price;


 private function create_fp_mrp_demand_v() {
	$sql = "
CREATE OR REPLACE VIEW fp_mrp_demand_v
(
fp_mrp_demand_id, fp_mrp_header_id, mrp_name, org_id, item_id_m, demand_date, quantity,  
demand_item_id_m, toplevel_demand_item_id_m, source_type, primary_source_type, source_header_id, 
source_line_id, item_number, item_description, planner, product_line,
standard_cost, sales_price, purchase_price

)
AS
SELECT fmd.fp_mrp_demand_id, fmd.fp_mrp_header_id,fmh.mrp_name, fmd.org_id, fmd.item_id_m, fmd.demand_date, fmd.quantity,  
fmd.demand_item_id_m, fmd.toplevel_demand_item_id_m, fmd.source_type, fmd.primary_source_type, fmd.source_header_id, 
fmd.source_line_id, item.item_number, item.item_description, item.planner, item.product_line,
cic.standard_cost, cic.sales_price, cic.purchase_price
FROM fp_mrp_demand fmd
LEFT JOIN item ON item.item_id_m = fmd.item_id_m AND item.org_id = fmd.org_id
LEFT JOIN cst_item_cost_v cic ON cic.item_id_m = fmd.item_id_m AND cic.org_id = cic.org_id AND cic.bom_cost_type = 'FROZEN',
fp_mrp_header fmh
WHERE fmh.fp_mrp_header_id = fmd.fp_mrp_header_id
";
 }

}

?>
