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
 * 
 *
 */
class extn_web_tracking extends dbObject {

//protected static variables
 public static $table_name = "extn_web_tracking";
//protected variables
//public static varibales - required to be accessed with out instantitaing the class
 public static $primary_column = "extn_web_tracking_id";
 public static $key_column = "page_visited";
 public static $field_array = [];
 public static $fields_inForm_notInDataBase = [];
 public static $fields_inHeader_needsToBeInserted_inPOST = [];
//public attributes used with the class
 public static $initial_search_array = [
		 'extn_web_tracking_id',
		 'page_visited'
 ];
// public $checkbox = [
//		 
// ];
 public $column = [
		 'extn_web_tracking_id',
		 'page_visited',
		 'referrer',
		 'hostname',
		 'query_string'
 ];
// public $base_encoded = [];
 public $requiredField = [
		 'page_visited',
 ];
// public $dateFields;
//varibles required for search
 public $module_info = [
		 array(
				 "module" => "extension",
				 "class" => "extn_web_tracking",
				 "key_field" => "page_visited",
				 "primary_column" => "web_tracking_id"
		 )
 ];
 public $pageTitle = " Web Tracking - Find All Visitor Details "; //page Title
 public $view_path = "extensions/web_tracking/web_tacking_view"; //view path 
 public $option_list = [
 ]; //list of search fields which have options
 public $update_path = 'extensions/web_tracking/web_tracking'; //Path shown on serach list page to update

//
}

//end of path class
?>
