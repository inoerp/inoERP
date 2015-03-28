<?php

class extn_image_reference extends dbObject {

 public static $table_name = "extn_image_reference";
//  data base variables as stored database column name
 public $field_a = [
		 "extn_image_reference_id",
		 "extn_image_id",
		 "reference_table",
		 "reference_id",
		 'status'
 ];
 public $extn_image_reference_id;
 public $extn_image_id;
 public $reference_table;
 public $reference_id;
 public $status;

 public static $primary_column = "extn_image_reference_id";

// 
}

//end of image_reference class
?>