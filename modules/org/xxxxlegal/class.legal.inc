<?php

class legal extends org {

 protected static $table_name = "legal";
 public static $field_array = [
		 "legal_id",
		 "org_id",
		 "legal_org_type",
		 "registration_number",
		 "place_of_registration",
		 "country_of_registration",
		 "identification_number",
		 "ein_tin_tan",
		 "ledger_id",
		 "balancing_segments",
		 "ef_id",
		 "status",
		 "rev_enabled",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public static $initial_search_array = [
		 "legal_id",
		 "org_id",
		 "org",
		 "description"
 ];
 public static $checkbox_array = [
 ];
 public static $column_array = [
		 "legal_id",
		 "org_id",
		 "org",
		 "description"
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 "org_id"
 ];
 public static $primary_column = "legal_id";
 public $legal_id;
 public $org;
 public $description;
 public $legal_org_type;
 public $registration_number;
 public $place_of_registration;
 public $country_of_registration;
 public $identification_number;
 public $ein_tin_tan;
 public $ledger_id;
 public $balancing_segments;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;


}

//end of legal class
?>
