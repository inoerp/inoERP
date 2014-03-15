<?php

class business extends org {

 protected static $table_name = "business";
 public static $primary_column = "business_id";
 public static $key_column = 'org_id';
 public static $module = "org";
 
 public $field_a = [
		 "business_id",
		 "org_id",
		 "business_org_type",
		 "manager",
		 "ef_id",
		 "status",
		 'enterprise_org_id',
		 'legal_org_id',
		 "rev_enabled",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public $initial_search = [
		 "business_id",
		 "org_id",
		 "org",
		 "description"
 ];

 public $column = [
		 "business_id",
		 "org_id",
		 "org",
		 "description"
 ];
 
 public $requiredField = [
		 "org_id",
 ];
 
  public $fields_inForm_notInDataBase = [
		'ledger'
 ];
 
  public $search = [
		 '_update_path' => 'form.php?class_name=business',
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " Organization - Business Org "; //page Title
 
 public $business_id;
 public $description;
 public $business_org_type;
 public $ef_id;
 public $manager;
 public $enterprise_org_id;
 public $legal_org_id;
 public $ledger;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 
  public function _before_showing() {
	 	if (!empty($this->legal_org_id)) {
//	 echo "<br> legal org ". $this->legal_org_id;
	 $legal_org = legal::find_by_orgId($this->legal_org_id);
//	 pa($legal_org);
	 $ledger_id = $legal_org->ledger_id;
	 $ledger = new gl_ledger();
	 $ledger_i = $ledger->findBy_id($ledger_id);
	 $this->ledger = $ledger_i->ledger;
	}

 }

}

//end of business class
?>
