<?php

class file_reference extends file {

 protected static $table_name = "file_reference";
//  data base variables as stored database column name
 public static $field_array = ["file_reference_id",
		 "file_id",
		 "reference_table",
		 "reference_id",
		 'status'
 ];
 public $file_reference_id;
 public $file_id;
 public $reference_table;
 public $reference_id;
 public $status;

 public static $primary_column = "file_reference_id";

// 
}

//end of file_reference class
?>



