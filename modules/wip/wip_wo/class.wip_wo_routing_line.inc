<?php

class wip_wo_routing_line extends dbObject {

 protected static $table_name = "wip_wo_routing_line";
//  data base variables as stored database column name
 public static $field_array = [
		 'wip_wo_routing_line_id',
		 'wip_wo_header_id',
		 'routing_sequence',
		 'department_id',
		 'description',
		 'count_point_cb',
		 'auto_charge_cb',
		 'backflush_cb',
		 'minimum_transfer_quantity',
		 'start_date',
		 'completion_date',
		 'queue_quantity',
		 'running_quantity',
		 'rejected_quantity',
		 'scrapped_quantity',
		 'tomove_quantity',
		 'completed_quantity',
		 'progress_percentage',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
//variables used for showing data
 public static $initial_search_array = [
 ];
 public static $column_array = [
 ];
 public static $account_array = [
 ];
 public static $checkbox_array = [
 ];
 public static $fields_inForm_notInDataBase = [
		 "count_point_cb",
		 'backflush_cb',
		 'auto_charge_cb',
		 'referenced_cb',
		 'include_in_rollup_cb'
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
		 'wip_wo_header_id'
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 'wip_wo_header_id',
		 'routing_sequence',
		 'department_id'
 ];
 public static $primary_column = "wip_wo_routing_line_id";
 public $wip_wo_routing_line_id;
 public $wip_wo_header_id;
 public $routing_sequence;
 public $department_id;
 public $description;
 public $lead_time_percentage;
 public $count_point_cb;
 public $auto_charge_cb;
 public $backflush_cb;
 public $minimum_transfer_quantity;
 public $start_date;
 public $completion_date;
 public $queue_quantity;
 public $running_quantity;
 public $rejected_quantity;
 public $scrapped_quantity;
 public $tomove_quantity;
 public $completed_quantity;
 public $progress_percentage;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function find_by_wip_wo_headerId($wi_wo_header_id) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where wip_wo_header_id= '{$wi_wo_header_id}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }
 
  public static function find_lastOperation_by_wip_wo_headerId($wi_wo_header_id) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where wip_wo_header_id= '{$wi_wo_header_id}' ORDER BY routing_sequence desc ";
	$result = self::find_by_sql($sql);
	
	return !empty($result[0]) ? $result[0]: false ;
 }
 
  public static function find_by_wipWoHeaderId_and_routingSequence($wi_wo_header_id, $routing_sequence) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where wip_wo_header_id= '{$wi_wo_header_id}' 
					AND routing_sequence = '{$routing_sequence}' LIMIT 1";
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_shift($result) : false ;
 }
 
   public static function find_by_wipWoHeaderId_and_fromToRoutingSequence($wi_wo_header_id, $from_routing_sequence, $to_routing_sequence) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where wip_wo_header_id= '{$wi_wo_header_id}' 
					 AND routing_sequence > '{$from_routing_sequence}'
					 AND routing_sequence < '{$to_routing_sequence}' ";
	$result = self::find_by_sql($sql);
	return $result ;
 }
 
}

//end of wip_wo_routing_line class
?>



