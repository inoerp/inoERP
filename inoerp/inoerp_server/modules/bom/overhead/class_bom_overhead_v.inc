<?php

class bom_overhead_v extends dbObject {

 public static $form_class_name = "bom_overhead";
 public static $table_name = "bom_overhead_v";
 public static $primary_column = "bom_overhead_id";
 public $field_a = [
  'bom_oh_res_assignment_id',
  'resource_bom_cost_type',
  'resource_id',
  'bom_oh_rate_assignment_id',
  'bom_overhead_id',
  'rate_bom_cost_type',
  'default_basis',
  'rate',
  'overhead',
  'description',
  'org_id',
  'overhead_type',
  'absorption_ac_id',
 ];
 public $initial_search = [
  'overhead',
  'description',
  'org_id',
  'overhead_type',
 ];
 public $column = [
  'overhead',
  'description',
  'org_id',
  'overhead_type',
 ];
 public $pageTitle = " BOM Overhead - Resource & Material "; //page Title
 public $search = [
  '_update_path' => 'form.php?class_name=bom_overhead',
  '_show_update_path' => 1,
  '_view_path' => 'form.php?class_name=bom_overhead',
  '_show_view_path' => 1,
 ];
 public $bom_oh_res_assignment_id;
 public $resource_bom_cost_type;
 public $resource_id;
 public $bom_oh_rate_assignment_id;
 public $bom_overhead_id;
 public $rate_bom_cost_type;
 public $default_basis;
 public $rate;
 public $overhead;
 public $description;
 public $org_id;
 public $overhead_type;
 public $absorption_ac_id;

 public function __set($name, $value) {
  $this->$name = $value;
 }

 public function findBy_resourceId_bomCostType() {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE resource_bom_cost_type =:resource_bom_cost_type AND resource_id = :resource_id ";

  $param_a = ['resource_bom_cost_type', 'resource_id'];
  $value_a = ['resource_bom_cost_type' => $this->resource_bom_cost_type, 'resource_id' => $this->resource_id];
  $result = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? $result : false;
 }

 private function create_bom_overhead_v() {
  $sql = "
CREATE OR REPLACE VIEW bom_overhead_v
(
bom_oh_res_assignment_id,resource_bom_cost_type, resource_id,
bom_oh_rate_assignment_id, bom_overhead_id, rate_bom_cost_type, default_basis, rate ,
overhead, description, org_id, overhead_type, absorption_ac_id
)
AS
SELECT res.bom_oh_res_assignment_id,res.bom_cost_type, res.resource_id,
ora.bom_oh_rate_assignment_id, ora.bom_overhead_id, ora.bom_cost_type, ora.default_basis, ora.rate ,
bo.overhead, bo.description, bo.org_id, bo.overhead_type, bo.absorption_ac_id
FROM bom_oh_rate_assignment ora
LEFT JOIN bom_overhead bo ON bo.bom_overhead_id = ora.bom_overhead_id
LEFT JOIN bom_oh_res_assignment res ON res.bom_overhead_id = ora.bom_overhead_id
WHERE res.bom_cost_type = ora.bom_cost_type

";
 }

}

//end of po_detail class
?>