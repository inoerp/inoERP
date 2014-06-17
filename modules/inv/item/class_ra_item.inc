<?php

// public $rev_enabled_cb;  needs to be dropped - use item rev only
class ra_item extends dbObject {

 public static $table_name = "item";
 public static $primary_column = "item_id";
 public static $key_column = 'item_number';
 public static $module = "inv";
 public $field_a = [
		 "item_id",
		 "org_id",
		 "item_number",
		 "item_description",
		 'product_line',
		 'product_line_percentage',
		 "locator_control",
		 "long_description",
		 "uom_id",
		 "item_type",
		 "item_status",
		 "allow_negative_balance_cb"
 ];
 public $initial_search;
 public $pageTitle = " Item Analysis"; //page Title
 public $item_id;
 public $org_id;
 public $org;
 public $item_number;
 public $item_description;
 public $product_line;
 public $pre_processing_lt;
 public $post_processing_lt;
 public $processing_lt;
 public $cumulative_mfg_lt;
 public $cumulative_total_lt;
 public $lt_lot_size;
 public $ra_report_item_leadtime_byProductLine_settings = [
		 '_chart_name' => 'Item Lead Time Analysis & Improvement Opportunity',
		 '_chart_width' => '750',
		 '_chart_height' => '450',
		 '_x_axis_text' => 'Product Line',
		 '_chart_type' => 'clustered_column',
		 '_gap_between_xaxis_text' => '50',
		 '_legend' => ''
 ];
 public $ra_report_item_planning_byProductLine_settings = [
		 '_chart_name' => ' Planning Method By Product Line ',
		 '_chart_width' => '750',
		 '_chart_height' => '450',
		 '_x_axis_text' => 'Number of Items',
		 '_chart_type' => 'stacked_bar',
		 '_gap_between_xaxis_text' => '50',
		 '_left_margin' => '100',
		 '_legend' => ''
 ];
 public $ra_report_set_item_leadtime_settings = [
		 '_chart_name' => 'Item Analysis ',
		 '_chart_width' => '350',
		 '_chart_height' => '350',
		 '_chart_type' => array('horizonatl_bar', 'vertical_column', 'pie'),
		 '_legend' => ''
 ];
 public $ra_reprot_item_buyer_settings = [
		 '_chart_name' => 'Item Default Buyers',
		 '_right_margin' => '100',
		 '_chart_width' => '400',
		 '_chart_height' => '400',
		 '_chart_type' => array('donut', 'pie'),
		 '_legend' => ''
 ];
 public $ra_reprot_item_asl_usage_settings = [
		 '_chart_name' => 'Item Using ASL',
		 '_right_margin' => '100',
		 '_chart_width' => '400',
		 '_chart_height' => '400',
		 '_chart_type' => array('pie', 'donut'),
		 '_legend' => ''
 ];
 public $ra_report_set_item_leadtime = [
		 'ra_report_item_leadtime_byProductLine',
		 'ra_report_item_planning_byProductLine',
		 'ra_reprot_item_buyer',
		 'ra_reprot_item_asl_usage',

 ];

 public function ra_report_set_item_leadtime() {
	$result_a = [];
	$result_a['ra_report_item_leadtime_byProductLine'] = $this->ra_report_item_leadtime_byProductLine();
	$result_a['ra_report_item_planning_byProductLine'] = $this->ra_report_item_planning_byProductLine();
		$result_a['ra_reprot_item_buyer'] = $this->ra_reprot_item_buyer();
	$result_a['ra_reprot_item_asl_usage'] = $this->ra_reprot_item_asl_usage();
	return $result_a;
 }

 public function ra_report_item_leadtime_byProductLine() {
	$legend = [];
	$sql = " 
			SELECT product_line,
			CASE 
			WHEN  processing_lt < 10 THEN '0-9'
			WHEN  processing_lt < 20 THEN '10-19'
			WHEN  processing_lt < 30 THEN '20-29'
			WHEN  processing_lt < 40 THEN '30-39'
			WHEN  processing_lt < 50 THEN '40-49'
			WHEN  processing_lt < 70 THEN '50-69'
			WHEN  processing_lt < 90 THEN '70-89'
			ELSE '90+'
			END as Lead_Time,
			count(item_number)
			FROM
			item
			GROUP BY product_line, Lead_Time
 ";
	$result = $this->findBySql($sql);
	$result_f = ra_conevrt_data_bar_column($result, $legend);
	$this->ra_report_item_leadtime_byProductLine_settings['_legend'] = $legend;
	return !empty($result_f) ? $result_f : false;
 }

 public function ra_report_item_planning_byProductLine() {
	$legend = [];
	$sql = " 
			SELECT planning_method,product_line, count(item_number)
			FROM
			item
			GROUP BY product_line, planning_method
			Order By Product_line
 ";
	$result = $this->findBySql($sql);
	$result_f = ra_conevrt_data_bar_column($result, $legend);
	$this->ra_report_item_planning_byProductLine_settings['_legend'] = $legend;
	return !empty($result_f) ? $result_f : false;
 }

 public function ra_reprot_item_buyer() {
	$sql = " 			
	 SELECT default_buyer,count(item_number)
	 FROM item
   WHERE purchased_cb = 1
	GROUP BY default_buyer
";
	$result = $this->findBySql($sql);
	$result_f = ra_conevrt_data_pie($result);
	return !empty($result_f) ? ($result_f) : false;
 }

 public function ra_reprot_item_asl_usage() {
	$sql = " 			
	 SELECT 
	 		CASE 
			WHEN  use_asl_cb = 1 THEN 'Use ASL'
			ELSE 'NA'
			END as ASL_Usage,
   count(item_number)
	 FROM item
   WHERE purchased_cb = 1
	GROUP BY ASL_Usage
";
	$result = $this->findBySql($sql);
	$result_f = ra_conevrt_data_pie($result);
	return !empty($result_f) ? ($result_f) : false;
 }

}

//end of item class
?>