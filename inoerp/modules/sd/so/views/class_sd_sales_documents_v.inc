<?php

class sd_sales_documents_v extends dbObject {

 public static $form_class_name = "sd_so_header";
 public static $table_name = "sd_sales_documents_v";
 public static $primary_column = "sd_so_header_id";
 public $field_a = [
  'document_id',
  'docuemnt_number',
  'sales_team',
  'creation_date',
  'document_type',
  'status',
 ];
 public $initial_search = [
  'docuemnt_number',
  'docuemnt_type',
 ];
// 
// public $search = [
//		 '_update_path' => 'form.php?class_name=sd_so_header',
//		 '_show_update_path' => 1,
//		 '_view_path' => 'form.php?class_name=sd_so_header',
//		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'Sales ',
//		 '_extra_path' => array('form.php?class_name=ar_transaction_header&mode=9' => 'Invoice',
//				 'form.php?class_name=sd_delivery_header&mode=9' => 'Ship')
// ];
 public $pageTitle = " Sales Documents "; //page Title
 public $document_id;
public $docuemnt_number;
public $sales_team;
public $creation_date;
public $document_type;
public $status;


 private function create_sd_sales_documents_v() {
  $sql = "
CREATE OR REPLACE VIEW sd_sales_documents_v
(
document_id,  docuemnt_number, sales_team, creation_date , document_type, status
)
AS
 SELECT sd_lead_id AS document_id, lead_number AS docuemnt_number, sales_team AS sales_team,
creation_date AS creation_date, 'lead' AS document_type, status
FROM 
sd_lead

UNION

SELECT sd_opportunity_id AS document_id, opportunity_number AS docuemnt_number, sales_team AS sales_team,
creation_date AS creation_date, 'opportunity' AS document_type, status
FROM 
sd_opportunity

UNION

SELECT sd_quote_header_id AS document_id, quote_number AS docuemnt_number, 'Quote' AS sales_team,
creation_date AS creation_date, 'quote' AS document_type, status
FROM 
sd_quote_header

UNION

SELECT sd_so_header_id AS document_id, so_number AS docuemnt_number, 'SO' AS sales_team,
creation_date AS creation_date, 'Sales Order' AS document_type, so_status AS status
FROM 
sd_so_header


";
 }

 public function findBY_soLineId($line_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE sd_so_line_id = :sd_so_line_id ";
  $sql = ino_perPageSql_i($sql, 1);
  $value_a = ['sd_so_line_id' => $line_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of so_detail class
?>