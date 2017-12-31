<?php

class prj_burden_expenditure_v extends dbObject {

 public static $table_name = "prj_burden_expenditure_v";
 public static $form_class_name = "prj_burden_expenditure";
 public static $primary_column = "prj_burden_expenditure_id";
 public $field_a = [
  'prj_burden_expenditure_id',
  'project_number',
  'costcode',
  'costcode_description',
  'cost_base',
  'cost_base_description',
  'burden_list',
  'prj_expenditure_line_id',
  'prj_expenditure_header_id',
  'org_id',
  'prj_project_header_id',
  'prj_project_line_id',
  'prj_nlr_header_id',
  'prj_expenditure_type_header_id',
  'uom_id',
  'quantity',
  'description',
  'prj_burden_list_header_id',
  'expenditure_date',
  'prj_burden_structure_header_id',
  'prj_burden_costcode_id',
  'multiplier',
  'burden_value',
  'burden_amount',
 ];
 public $initial_search = [
  'project_number',
  'costcode',
  'costcode_description',
  'prj_expenditure_line_id'
 ];
 public $search = [
  '_view_path' => 'form.php?class_name=prj_burden_expenditure',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Burden Expenditure "; //page Title
 
 public $cost_base;
public $cost_base_description;
public $burden_list;
public $prj_expenditure_line_id;
public $prj_expenditure_header_id;
public $org_id;
public $prj_project_header_id;
public $prj_project_line_id;
public $prj_nlr_header_id;
public $prj_expenditure_type_header_id;
public $uom_id;
public $quantity;
public $description;
public $prj_burden_list_header_id;
public $expenditure_date;
public $prj_burden_structure_header_id;
public $prj_burden_costcode_id;
public $multiplier;
public $burden_value;
public $burden_amount;


 private function create_prj_expenditure_line_v() {
  $sql = "
CREATE OR REPLACE VIEW prj_expenditure_line_v
(
prj_burden_expenditure_id, project_number, costcode, costcode_description,
cost_base, cost_base_description, burden_list,
prj_expenditure_line_id,  prj_expenditure_header_id,  org_id,
prj_project_header_id,  prj_project_line_id,  prj_nlr_header_id,
prj_expenditure_type_header_id,  uom_id,  quantity ,
description, prj_burden_list_header_id, expenditure_date,
prj_burden_structure_header_id, prj_burden_costcode_id,
multiplier,burden_value , burden_amount
)
AS
SELECT 
pbe.prj_burden_expenditure_id, pph.project_number, pbc.costcode, pbc.description as costcode_description,
pbcb.cost_base, pbcb.description as cost_base_description, bplh.burden_list,
pel.prj_expenditure_line_id,   pel.prj_expenditure_header_id,   pel.org_id,
pel.prj_project_header_id,   pel.prj_project_line_id,   pel.prj_nlr_header_id,
pel.prj_expenditure_type_header_id,   pel.uom_id,   pel.quantity ,
pbe.description, pbe.prj_burden_list_header_id, pbe.expenditure_date,
pbe.prj_burden_structure_header_id, pbe.prj_burden_costcode_id,
pbe.multiplier,pbe.burden_value , pbe.burden_amount


FROM prj_burden_expenditure pbe,
prj_expenditure_line pel,
prj_project_header pph,
prj_burden_list_header bplh,
prj_burden_cost_base pbcb,
prj_burden_costcode pbc

WHERE pbe.prj_expenditure_line_id = pel.prj_expenditure_line_id
AND pbcb.prj_burden_cost_base_id = pbe.prj_burden_cost_base_id
AND pbc.prj_burden_costcode_id = pbe.prj_burden_cost_base_id
AND pph.prj_project_header_id = pel.prj_project_header_id
AND bplh.prj_burden_list_header_id = pbe.prj_burden_list_header_id


";
 }

 public function findBY_soLineId($line_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE hd_ro_line_id = :hd_ro_line_id ";
  $sql = ino_perPageSql_i($sql, 1);
  $value_a = ['hd_ro_line_id' => $line_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of so_detail class
?>