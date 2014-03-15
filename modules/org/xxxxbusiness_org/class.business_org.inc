<?php

class business_org extends org {
  protected static $table_name = "business_org";
	
	public static $field_array = [
		 "business_id",
		 "org_id",
		 "business_org_type",
		 "manager",
		 "efid",
		 "status",
		 "rev_enabled",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public static $initial_search_array = [
		 "business_id",
		 "org_id",
		 "org",
		 "description"
 ];
 public static $checkbox_array = [
 ];
 public static $column_array = [
		 "business_id",
		 "org_id",
		 "org",
		 "description"
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 "org_id",
 ];
 public static $primary_column = "business_id";
 
  public $business_id;
  public $description;
  public $business_org_type;
  public $manager;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;

}

//end of business_org class
?>
