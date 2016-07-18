<?php

 class po_asl_document extends dbObject {

  public static $table_name = "po_asl_document";
  public static $primary_column = "po_asl_document_id";
  public static $key_column = 'po_asl_line_id';
  public static $module = "po";
  public static $document_type_a = [
   'po_line' => 'Blanket Purchase Agreement'
  ];
  public $field_a = [
   'po_asl_document_id',
   'po_asl_line_id',
   'document_type',
//   'document_header_id',
   'document_line_id',
   'start_date',
   'end_date',
   'priority',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'po_asl_line_id',
   'document_type',
   'document_line_id',
  ];
  public $requiredField = [
   'po_asl_line_id',
   'document_type',
   'document_line_id',
  ];
  public $po_asl_document_id;
  public $po_asl_line_id;
  public $document_type;
//  public $document_header_id;
  public $document_line_id;
  public $start_date;
  public $end_date;
  public $priority;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " PO ASL Document  "; //page Title

  Public static function find_by_po_asl_lineId($po_asl_line_id) {
   $sql = " SELECT * FROM " . self::$table_name . " WHERE po_asl_line_id = '{$po_asl_line_id}' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : null;
  }

 }

//end of po_asl_document class
?>