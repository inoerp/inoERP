<?php

class prj_milestone extends dbObject {

 public static $table_name = "prj_milestone";
 public static $primary_column = "prj_milestone_id";
 public static $parent_primary_column = "prj_project_header_id";
 public static $key_column = 'prj_project_line_id';
 public static $module = "prj";
 public static $status_a = [
  'ENTERED' => 'Entered',
  'APPROVED' => 'Approved',
  'BILLED' => 'Billed',
 ];
 public $field_a = [
  'prj_milestone_id',
  'prj_project_header_id',
  'prj_project_line_id',
  'status',
  'comment',
  'signoff_cb',
  'revenue_amount',
  'invoice_amount',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'prj_project_line_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "prj_project_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  'task_number',
  'task_description',
  'project_number',
  'project_description'
 ];
 public $prj_milestone_id;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $status;
 public $comment;
 public $signoff_cb;
 public $revenue_amount;
 public $invoice_amount;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $project_number;
 public $project_description;

 public static function find_by_projectHeaderId($project_header_id) {
  $sql = " SELECT   pm.prj_milestone_id,   pm.prj_project_header_id,   pm.prj_project_line_id,
		  pm.status,   pm.comment,   pm.signoff_cb,   pm.created_by,   pm.creation_date, pm.revenue_amount, pm.invoice_amount,
		  pm.last_update_by,   pm.last_update_date,
      ppl.task_number, ppl.description as task_description
      FROM prj_milestone pm,
      prj_project_line ppl
		  WHERE pm.prj_project_header_id= '{$project_header_id}'  
       AND  pm.prj_project_line_id = ppl.prj_project_line_id
         
		  UNION
		  SELECT NULL as prj_milestone_id, ppl.prj_project_header_id, ppl.prj_project_line_id,  NULL as status,  NULL as comment, 	
      NULL as signoff_cb,  NULL as created_by,  NULL as creation_date, NULL as revenue_amount, NULL as invoice_amount,		 
      NULL as last_update_by, NULL as last_update_date,
      ppl.task_number, ppl.description as task_description
		  FROM 
          prj_project_line ppl
		  WHERE ppl.prj_project_header_id= '{$project_header_id}'   
       AND ppl.milestone_cb = '1'
		  AND ppl.prj_project_line_id NOT IN (
		  SELECT DISTINCT(prj_project_line_id)
		  FROM prj_milestone
		  )


		  ";
      
  $result = self::find_by_sql($sql);
//  echo $sql;


  return !empty($result) ? $result : false;
 }

}

//end of prj_milestone class
?>