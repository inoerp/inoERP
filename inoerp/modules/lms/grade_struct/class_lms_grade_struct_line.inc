<?php

class lms_grade_struct_line extends dbObject {

 public static $table_name = "lms_grade_struct_line";
 public static $primary_column = "lms_grade_struct_line_id";
 public static $parent_primary_column = "lms_grade_struct_header_id";
 public static $key_column = 'grade_code';
 public static $module = "lms";
 public $field_a = [
		 'lms_grade_struct_line_id',
		 'lms_grade_struct_header_id',
		 'from_score',
		 'to_score',
		 'grade_code',
		 'description',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $fields_intpl_header_needsToBeInserted_inPOST = [
		 "lms_grade_struct_header_id"
 ];
 public $requiredField = [
		 'lms_grade_struct_header_id',
		 'grade_code'
 ];
 public $fields_inFormr_notinDataBase = [
		 "monetary_value"
 ];
 public $lms_grade_struct_line_id;
 public $lms_grade_struct_header_id;
 public $from_score;
 public $to_score;
 public $grade_code;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function find_monetary_value_by_id($lms_grade_struct_line_id, $element_id = '', $element_value = '') {
	if (empty($lms_grade_struct_line_id)) {
	 return null;
	}
	if (empty($element_id) || empty($element_value)) {
	 $ele_entry_tpl_line = self::find_by_id($lms_grade_struct_line_id);
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
		$this_details = self::find_by_id($lms_grade_struct_line_id);
		$all_basic_tpl_lines = lms_grade_struct_header::find_all_basic_tpl_lines($this_details->lms_grade_struct_header_id);
		foreach ($all_basic_tpl_lines as $tpl_lines) {
		 $total_amount += $tpl_lines->element_value;
		}
		$amount = ($total_amount * $this_details->element_value) / 100;
		break;

	 case 'P_REGULAR' :
		$total_amount = 0;
		$this_details = self::find_by_id($lms_grade_struct_line_id);
		$all_basic_tpl_lines = lms_grade_struct_header::find_all_regular_tpl_lines($this_details->lms_grade_struct_header_id);
		foreach ($all_basic_tpl_lines as $tpl_lines) {
		 $total_amount += $tpl_lines->element_value;
		}
		$amount = ($total_amount * $this_details->element_value) / 100;
		break;

	 case 'P_BASIC_REGULAR' :
		$total_amount = 0;
		$this_details = self::find_by_id($lms_grade_struct_line_id);
		$all_basic_tpl_lines = lms_grade_struct_header::find_all_regular_tpl_lines($this_details->lms_grade_struct_header_id);
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