<?php

class bom_all_v extends dbObject {
public static $form_class_name = "bom_header";
 public static $table_name = "bom_all_v";
 public static $primary_column = "bom_header_id";
 public $field_a = [
		 'bom_header_id',
		 'item_id_m',
		 'alternate_bom',
		 'org_id',
		 'bom_revision',
		 'effective_date',
		 'common_bom_item_id_m',
		 'item_number',
		 'item_description',
		 'uom_id',
		 'item_type',
		 'item_status',
		 'bom_type',
		 'costing_enabled_cb',
		 'make_buy',
		 'org',
		 'org_type',
		 'org_status',
		 'org_description',
		 'org_code',
 ];
 public $initial_search = [
		 'bom_header_id',
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
		 'bom_header_id',
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
 public $pageTitle = " BOM - Create & Update BOM "; //page Title
 public $search = [
		 '_update_path' => 'form.php?class_name=bom_header',
		 '_show_update_path' => 1,
		 '_view_path' => 'form.php?class_name=bom_header',
		 '_show_view_path' => 1,
		 '_extra_path' => array('form.php?class_name=bom_indented_bom&mode=9' => 'Indented BOM')
 ];
 public $bom_header_id;
 public $item_id_m;
 public $alternate_bom;
 public $org_id;
 public $bom_revision;
 public $effective_date;
 public $common_bom_item_id_m;
 public $item_number;
 public $item_description;
 public $uom_id;
 public $item_type;
 public $item_status;
 public $bom_type;
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

 private function create_bom_all_v() {
	$sql = "
CREATE OR REPLACE VIEW bom_all_v
(
bom_header_id, item_id_m, alternate_bom, org_id , bom_revision, effective_date, common_bom_item_id_m,
item_number, item_description, uom_id, item_type, item_status, bom_type,
costing_enabled_cb, make_buy,
org, org_type, org_status, org_description, org_code
)
AS
SELECT 
bh.bom_header_id, bh.item_id_m, bh.alternate_bom, bh.org_id , bh.bom_revision, bh.effective_date, bh.common_bom_item_id_m,
item.item_number, item.item_description, item.uom_id, item.item_type, item.item_status, item.bom_type,
item.costing_enabled_cb, item.make_buy,
org.org, org.type, org.status, org.description, org.code

FROM bom_header bh
LEFT JOIN item ON item.item_id_m = bh.item_id_m AND item.org_id = bh.org_id
LEFT JOIN org ON org.org_id = bh.org_id

";
 }

}

//end of po_detail class
?>