<?php

class mdm_discount_line extends dbObject {

 public static $table_name = "mdm_discount_line";
 public static $primary_column = "mdm_discount_line_id";
 public static $parent_primary_column = "mdm_discount_header_id";
 public static $key_column = 'element_name';
 public static $module = "mdm";
 public $field_a = [
		 'mdm_discount_line_id',
		 'mdm_discount_header_id',
		 'condition_type',
		 'element_set',
		 'element_name',
		 'element_value',
		 'compare_type',
		 'compare_value',
		 'status',
		 'close_bracket',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 
 
 
   public static $bracket_close_a = [
		 'CLOSE' => ')',
		  ];
	 
 public $fields_intpl_header_needsToBeInserted_inPOST = [
		 "mdm_discount_header_id"
 ];
 public $requiredField = [
		 'mdm_discount_header_id',
		 'element_name',
		 'compare_value',
 ];
// public $fields_inFormr_notinDataBase = [
//		 "monetary_value"
// ];

 public $mdm_discount_line_id;
 public $mdm_discount_header_id;
 public $condition_type;
 public $element_set;
 public $element_name;
 public $element_value;
 public $compare_type;
 public $compare_value;
 public $status;
 public $close_bracket;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function find_monetary_value_by_id($mdm_discount_line_id, $element_id = '', $element_value = '') {
	if (empty($mdm_discount_line_id)) {
	 return null;
	}
	if (empty($element_id) || empty($element_value)) {
	 $ele_entry_tpl_line = self::find_by_id($mdm_discount_line_id);
	 $element_id = $ele_entry_tpl_line->element_id;
	 $element_value = $ele_entry_tpl_line->element_value;
	}
	$ele_details = hr_compensation_element::find_by_id($element_id);
	$amount = null;

	switch ($ele_details->calculation_rule) {
	 case 'FLAT' :
		$amount = $element_value;
		break;

	 case 'P_BASIC' :
		$total_amount = 0;
		$this_details = self::find_by_id($mdm_discount_line_id);
		$all_basic_tpl_lines = mdm_discount_header::find_all_basic_tpl_lines($this_details->mdm_discount_header_id);
		foreach ($all_basic_tpl_lines as $tpl_lines) {
		 $total_amount += $tpl_lines->element_value;
		}
		$amount = ($total_amount * $this_details->element_value) / 100;
		break;

	 case 'P_REGULAR' :
		$total_amount = 0;
		$this_details = self::find_by_id($mdm_discount_line_id);
		$all_basic_tpl_lines = mdm_discount_header::find_all_regular_tpl_lines($this_details->mdm_discount_header_id);
		foreach ($all_basic_tpl_lines as $tpl_lines) {
		 $total_amount += $tpl_lines->element_value;
		}
		$amount = ($total_amount * $this_details->element_value) / 100;
		break;

	 case 'P_BASIC_REGULAR' :
		$total_amount = 0;
		$this_details = self::find_by_id($mdm_discount_line_id);
		$all_basic_tpl_lines = mdm_discount_header::find_all_regular_tpl_lines($this_details->mdm_discount_header_id);
		foreach ($all_basic_tpl_lines as $tpl_lines) {
		 $total_amount += $tpl_lines->element_value;
		}
		$amount = ($total_amount * $this_details->element_value) / 100;
		break;

	 case 'default' :
		break;
	}
	return $amount;
 }

}

//end of inv_transaction class
?>