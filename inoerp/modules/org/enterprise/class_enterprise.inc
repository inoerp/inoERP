<?php
/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * enterprise
 * Contains all the enterprise information, such as - org_id, type, description,  code, etc.
 * 
 */
class enterprise extends org {

 public static $table_name = "enterprise";
 public static $primary_column = "enterprise_id";
 public static $key_column = 'org_id';
 public static $module = "org"; //same as gl_journal_source
   public static $system_info = [
  'name' => 'Enterprise',
  'number' => '2002',
  'description' => 'Define and mainten Enterprise Orgs',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
 'primary_entity_cb' => '',
  'module_name' => 'org',
  'weight' => 2
 ];
 public $field_a = [
		 "enterprise_id",
		 "org_id",
		 "designation_option_header_id",
		 "type_option_header_id",
		 "status",
		 "rev_enabled",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public $initial_search = [
		 "enterprise_id",
		 "org_id",
		 "org",
		 "description"
 ];
 public $column = [
		 "enterprise_id",
		 "org_id",
		 "org",
		 "description"
 ];
 public $requiredField = [
		 "org_id",
 ];
 public $enterprise_id;
 public $org_id;
 public $designation_option_header_id;
 public $type_option_header_id;
 public $description;
 public $address_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " EnterPrise - View & Update Diffent EnterPrises"; //page Title
 
  public static function search_add_extra_fields( &$arr ){
	$org = new org;
	if(!(is_array($arr))){
	 return false;
	}
	foreach($arr as &$obj){
	 $primary_column = parent::$primary_column;
	 if(!empty($obj->$primary_column)){
		$org_i = $org->findBy_id($obj->$primary_column);
		$obj->org = $org_i->org;
		$obj->description = $org_i->description;
	 }
	}
	
 }

}

//end of enterprise class
?>
