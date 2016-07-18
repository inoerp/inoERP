<?php

class hr_position_hierarhcy_v extends dbObject {

 public static $table_name = "hr_position_hierarhcy_v";
 public static $primary_column = "hr_position_hierarhcy_header_id";
 public $field_a = [
		 'hr_position_hierarhcy_header_id',
		 'item_id_m',
		 'alternate_hr_position_hierarhcy',
		 'org_id',
		 'hr_position_hierarhcy_revision',
		 'effective_date',
		 'common_hr_position_hierarhcy_item_id_m',
		 'item_number',
		 'item_description',
		 'uom_id',
		 'item_type',
		 'item_status',
		 'hr_position_hierarhcy_type',
		 'costing_enabled_cb',
		 'make_buy',
		 'org',
		 'org_type',
		 'org_status',
		 'org_description',
		 'org_code',
 ];
 public $initial_search = [
		 'hr_position_hierarhcy_header_id',
		 'item_id_m',
		 'org_id',
		 'item_number',
		 'item_description',
		 'item_type',
		 'item_status',
		 'org',
		 'org_type',
		 'org_code',
 ];
 public $column = [
		 'hr_position_hierarhcy_header_id',
		 'item_id_m',
		 'org_id',
		 'item_number',
		 'item_description',
		 'item_type',
		 'item_status',
		 'org',
		 'org_type',
		 'org_code',
 ];
 public $pageTitle = " hr_position_hierarhcy - Create & Update hr_position_hierarhcy "; //page Title
 public $search = [
		 '_update_path' => 'form.php?class_name=hr_position_hierarhcy_header',
		 '_show_update_path' => 1,
		 '_view_path' => 'form.php?class_name=hr_position_hierarhcy_header',
		 '_show_view_path' => 1,
		 '_extra_path' => array('form.php?class_name=indented_hr_position_hierarhcy&mode=9' => 'Indented hr_position_hierarhcy')
 ];
 public $hr_position_hierarhcy_header_id;
 public $item_id_m;
 public $alternate_hr_position_hierarhcy;
 public $org_id;
 public $hr_position_hierarhcy_revision;
 public $effective_date;
 public $common_hr_position_hierarhcy_item_id_m;
 public $item_number;
 public $item_description;
 public $uom_id;
 public $item_type;
 public $item_status;
 public $hr_position_hierarhcy_type;
 public $costing_enabled_cb;
 public $make_buy;
 public $org;
 public $org_type;
 public $org_status;
 public $org_description;
 public $org_code;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 private function create_hr_position_hierarhcy_v() {
	$sql = "
CREATE OR REPLACE VIEW hr_position_hierarhcy_v
(
hr_position_hierarhcy_header_id, item_id_m, alternate_hr_position_hierarhcy, org_id , hr_position_hierarhcy_revision, effective_date, common_hr_position_hierarhcy_item_id_m,
item_number, item_description, uom_id, item_type, item_status, hr_position_hierarhcy_type,
costing_enabled_cb, make_buy,
org, org_type, org_status, org_description, org_code
)
AS
SELECT 
bh.hr_position_hierarhcy_header_id, bh.item_id_m, bh.alternate_hr_position_hierarhcy, bh.org_id , bh.hr_position_hierarhcy_revision, bh.effective_date, bh.common_hr_position_hierarhcy_item_id_m,
item.item_number, item.item_description, item.uom_id, item.item_type, item.item_status, item.hr_position_hierarhcy_type,
item.costing_enabled_cb, item.make_buy,
org.org, org.type, org.status, org.description, org.code

FROM hr_position_hierarhcy_header bh
LEFT JOIN item ON item.item_id_m = bh.item_id_m
LEFT JOIN org ON org.org_id = bh.org_id

";
 }

}

//end of po_detail class
?>