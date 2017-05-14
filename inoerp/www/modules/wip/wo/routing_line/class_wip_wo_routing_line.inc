<?php

class wip_wo_routing_line extends dbObject {

 public static $table_name = "wip_wo_routing_line";
 public static $primary_column = "wip_wo_routing_line_id";
 public static $key_column = 'routing_sequence';
 public static $module = "wip";
//  data base variables as stored database column name
 public $field_a = [
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

 public $fields_inForm_notInDataBase = [
		 "count_point_cb",
		 'backflush_cb',
		 'auto_charge_cb',
		 'referenced_cb',
		 'include_in_rollup_cb'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 'wip_wo_header_id'
 ];
 public $requiredField = [
		 'wip_wo_header_id',
		 'routing_sequence',
//		 'department_id'
 ];
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
 
 public function _after_save(){
     //extra field update
   $this->_update_extra_field('wip_wo_routing_line',$this->wip_wo_routing_line_id);
 }

 public static function find_by_wip_wo_headerId($wi_wo_header_id) {
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where wip_wo_header_id= '{$wi_wo_header_id}' ORDER BY routing_sequence ASC ";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_lastOperation_by_wip_wo_headerId($wi_wo_header_id) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where wip_wo_header_id= '{$wi_wo_header_id}' ORDER BY routing_sequence desc ";
	$result = self::find_by_sql($sql);

	return !empty($result[0]) ? $result[0] : false;
 }

 public static function find_by_wipWoHeaderId_and_routingSequence($wi_wo_header_id, $routing_sequence) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where wip_wo_header_id= '{$wi_wo_header_id}' 
					AND routing_sequence = '{$routing_sequence}' ";
          $sql = ino_perPageSql_i($sql, 1);
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_shift($result) : false;
 }

 public function findBy_woHeaderId_routingSeq() {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE wip_wo_header_id = :wip_wo_header_id ";
	$sql .= " AND routing_sequence = :routing_sequence ";
$sql = ino_perPageSql_i($sql, 1);

	$param_a = ['wip_wo_header_id', 'routing_sequence'];
	$value_a = ['wip_wo_header_id' => $this->wip_wo_header_id, 'routing_sequence' => $this->routing_sequence];
	$result = $this->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_wipWoHeaderId_and_fromToRoutingSequence($wi_wo_header_id, $from_routing_sequence, $to_routing_sequence) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where wip_wo_header_id= '{$wi_wo_header_id}' 
					 AND routing_sequence > '{$from_routing_sequence}'
					 AND routing_sequence < '{$to_routing_sequence}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }

}

//end of wip_wo_routing_line class
?>