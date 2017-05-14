<?php

// public $rev_enabled_cb;  needs to be dropped - use item rev only
class ra_wip extends dbObject {

 public static $table_name = "wip_wo_header";
 public static $primary_column = "wip_wo_header_id";
 public static $primary_column2 = "wo_number";
 public static $key_column = 'item_id_m';
 public static $module = "wip";
//  data base variables as stored database column name
 public $field_a = [
		 'wip_wo_header_id',
		 'item_id_m',
		 'wo_number',
		 'org_id',
		 'wip_accounting_group_id',
		 'wo_type',
		 'wo_status',
		 'start_date',
		 'completion_date',
		 'quantity',
		 'nettable_quantity',
		 'completed_quantity',
		 'scrapped_quantity',
		 'closed_date',
 ];
//variables used for showing data
 public $initial_search = [
 ];
 public $pageTitle = " WIP Analysis "; //page Title
 public $wip_wo_header_id;
 public $item_id_m;
 public $wo_number;
 public $org_id;
 public $wip_accounting_group_id;
 public $wo_type;
 public $wo_status;
 public $start_date;
 public $released_date;
 public $completion_date;
 public $first_unit_completed_date;
 public $last_unit_completed_date;
 public $quantity;
 public $nettable_quantity;
 public $completed_quantity;
 public $scrapped_quantity;
 public $schedule_group;
 public $closed_date;
 public $ra_report_wip_value_byItem_settings = [
		 '_chart_name' => 'WIP Value By Item',
		 '_x_axis_text' => 'WIP Value',
		 '_left_margin' => '80',
 ];
 public $ra_report_wip_onhand_byItem_settings = [
		 '_chart_name' => 'WIP Onhand By Item',
		 '_x_axis_text' => 'WIP Quantity',
		 '_left_margin' => '80',
 ];
 public $ra_report_wip_pastDue_orders_settings = [
		 '_chart_name' => 'Past Due Work Orders',
		 '_right_margin' => '100',
		 '_legend' => '',
		 '_chart_width' => '750',
		 '_chart_height' => '450',
		 '_x_axis_text' => 'Past Due Days',
		 '_chart_type' => 'clustered_column',
 ];
 public $ra_report_set_wip_settings = [
		 '_chart_name' => 'Item Analysis ',
		 '_chart_width' => '450',
		 '_chart_height' => '350',
		 '_chart_type' => 'horizonatl_bar',
		 '_legend' => ''
 ];
 public $ra_report_set_wip = [
		 'ra_report_wip_value_byItem',
		 'ra_report_wip_onhand_byItem'
 ];

 public function ra_report_set_wip() {
	$result_a = [];
	$result_a['ra_report_wip_value_byItem'] = $this->ra_report_wip_value_byItem();
	$result_a['ra_report_wip_onhand_byItem'] = $this->ra_report_wip_onhand_byItem();
	$result_a['ra_report_wip_pastDue_orders'] = $this->ra_report_wip_pastDue_orders();
//	$result_a['ra_reprot_item_asl_usage'] = $this->ra_reprot_item_asl_usage();
	return $result_a;
 }

 public function ra_report_wip_pastDue_orders() {
	$legend = [];
	$sql = " 
SELECT item.item_number,
			CASE 
			WHEN  (DATEDIFF(CURDATE(), wh.completion_date)) < 5 THEN '0-4'
			WHEN  (DATEDIFF(CURDATE(), wh.completion_date)) < 10 THEN '5-9'
			WHEN  (DATEDIFF(CURDATE(), wh.completion_date)) < 15 THEN '10-14'
			WHEN  (DATEDIFF(CURDATE(), wh.completion_date)) < 30 THEN '15-29'
			WHEN  (DATEDIFF(CURDATE(), wh.completion_date)) < 60 THEN '31-59'
			ELSE '60+'
			END as Past_Due,
			SUM(wh.quantity - wh.completed_quantity) as 'Remaining_Quantity'
			FROM
			wip_wo_header wh
            LEFT JOIN item ON item.item_id_m = wh.item_id_m
			WHERE wh.wo_status = 'RELEASED'
			GROUP BY wh.item_id_m, Past_Due
 ";
  $sql = ino_perPageSql_i($sql, 8);
	$result = $this->findBySql($sql);
	$result_f = ra_conevrt_data_bar_column($result, $legend);
	$this->ra_report_wip_pastDue_orders_settings['_legend'] = $legend;
	return !empty($result_f) ? $result_f : false;
 }

 public function ra_report_wip_value_byItem() {
	$sql1 = " 
		SELECT cic.item_number, 
		IFNULL(cic.standard_cost, 0.01)*Sum(wh.quantity - wh.completed_quantity) as 'Remaining_Value'

		FROM wip_wo_header wh
		LEFT JOIN cst_item_cost_v cic ON cic.item_id_m = wh.item_id_m AND cic.bom_cost_type='FROZEN'
		WHERE wo_status = 'RELEASED'
		GROUP BY wh.item_id_m
		ORDER BY Remaining_Value DESC
		LIMIT 8
	";
	$result1 = $this->findBySql($sql1);
	return !empty($result1) ? $result1 : false;
 }

 public function ra_report_wip_onhand_byItem() {
	$sql1 = " 
		 SELECT item.item_number, Sum(wh.quantity - wh.completed_quantity) as 'Remaining_Quantity'

		 FROM wip_wo_header wh
		 LEFT JOIN item ON item.item_id_m = wh.item_id_m
		 WHERE wo_status = 'RELEASED'
		 GROUP BY wh.item_id_m
		 ORDER BY Remaining_Quantity DESC
		 LIMIT 8
	";
	$result1 = $this->findBySql($sql1);
	return !empty($result1) ? $result1 : false;
 }

}

//end of item class
?>