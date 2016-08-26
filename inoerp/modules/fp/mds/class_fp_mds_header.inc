<?php

/**
 * inoERP - Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * fp_mds_header
 * Used for tracking total demand i.e. Unconsumed forecast and sales order
 * Contains all the fp_mds_header information, such as - mds_name, description , fp_source_list_header_id, org_id, status
 * 
 */
class fp_mds_header extends dbObject {

 public static $table_name = "fp_mds_header";
 public static $primary_column = "fp_mds_header_id";
 public static $dependent_classes = ['fp_mds_line'];
 public static $key_column = 'mds_name';
 public static $module = "fp";
 public static $system_info = [
  'name' => 'MDS',
  'number' => '2504',
  'description' => 'MDS',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('fp_mds_line'),
  'primary_entity_cb' => '',
  'module_name' => 'fp',
  'weight' => 4
 ];
 public $field_a = [
  'fp_mds_header_id',
  'org_id',
  'mds_name',
  'description',
  'fp_source_list_header_id',
  'include_so_cb',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'fp_mds_header_id',
  'mds_name',
  'description',
  'fp_source_list_header_id',
 ];
 public $column = [
  'fp_mds_header_id',
  'org_id',
  'mds_name',
  'description',
  'fp_source_list_header_id',
  'status',
 ];
 public $checkbox = [
  "include_so_cb",
 ];
 public $requiredField = [
  'org_id',
  'mds_name',
 ];
 public $pageTitle = " MDS - Master Demand Schedule  "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $prg_load_mds_parameters = [
  'Organization' => 'search_org_name',
  'MDS Name ' => 'search_mds_name'
 ];
 public $prg_load_mds_details = [
  'name' => ' Load Master Demand Schedule ',
  'description' => ' Load/Copy/Merge Master Demand Schedule',
 ];
 public $fp_mds_header_id;
 public $org_id;
 public $mds_name;
 public $description;
 public $fp_source_list_header_id;
 public $include_so_cb;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function findBy_itemId() {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where item_id_m= :item_id_m ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $param_a = ['item_id_m'];
  $value_a = ['item_id_m' => $this->item_id_m];
  $result_array = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public function findAll_2columns() {
  $result = $this->findAll();
  $id = self::$primary_column;
  $name = self::$key_column;
  $data = array();
  if (!empty($result)) {
   foreach ($result as $obj) {
    $data[] = array(
     'label' => $obj->$name,
     'name' => $obj->$name,
     'id' => $obj->$id
    );
   }
  }
  return $data;
 }

 private function _load_so_to_mds($mds_header_obj) {
  $sol = new sd_so_line();
  $sol_i = $sol->findAll_ByOrgId($mds_header_obj->org_id, 'AWAITING_PICKING');
  $msdl = new fp_mds_line();

  foreach ($sol_i as $sales_line) {
   $msdl->fp_mds_line_id = null;
   $msdl->fp_mds_header_id = $mds_header_obj->fp_mds_header_id;
   $msdl->item_id_m = $sales_line->item_id_m;
   $msdl->quantity = $sales_line->line_quantity;
   $msdl->demand_date = $sales_line->schedule_ship_date;
   $msdl->source_type = 'Sales_Order';
   $msdl->source_header_id = $sales_line->sd_so_header_id;
   $msdl->source_line_id = $sales_line->sd_so_line_id;
   $msdl->audit_trial();
   $msdl->save();
  }
 }

 private function _load_sourceListDemand_to_mds($mds_header_obj) {
  $slh = new fp_source_list_header();
  $slh->fp_source_list_header_id = $mds_header_obj->fp_source_list_header_id;
  $slh_i = $slh->findAll_forecastLines_byHeaderId();

  $msdl = new fp_mds_line();
  foreach ($slh_i as $forecast_line) {
   $msdl->fp_mds_line_id = null;
   $msdl->fp_mds_header_id = $mds_header_obj->fp_mds_header_id;
   $msdl->item_id_m = $forecast_line->item_id_m;
   $msdl->quantity = $forecast_line->current_quantity;
   $msdl->demand_date = $forecast_line->forecast_date;
   $msdl->source_type = 'Forecast';
   $msdl->source_header_id = $forecast_line->fp_forecast_header_id;
   $msdl->source_line_id = $forecast_line->fp_forecast_line_id;
   $msdl->audit_trial();
   $msdl->save();
  }
 }

 public function prg_load_mds($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting MDS Load....<br>';
  $mdsh = new fp_mds_header();
  $mdsl = new fp_mds_line();

  if (!empty($parameters['org_id'][0])) {
   $org_id = $parameters['org_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $org_id;
  } else {
   $this->message .= '<br> Error! : No org id found @ cst_item_cost_header ' . __LINE__;
   return $this->message;
  }

  if (!empty($parameters['fp_mds_header_id'][0])) {
   $fp_mds_header_id = $parameters['fp_mds_header_id'][0];
   $mdsh->findBy_id($fp_mds_header_id);
   $this->message .= "<br>mdsh org id is " . $mdsh->org_id;
   if ($mdsh->org_id != $org_id) {
    $this->message .= '<br> Error! : Entered MDS does not belong to the entered Org @ fp_mds_header ' . __LINE__;
    return $this->message;
   }
   $mdsl->deleteBy_parentId($fp_mds_header_id);
  } else {
   $this->message .= '<br> Error! : No MDS  Header Id is found @ fp_mds_header ' . __LINE__;
   return $this->message;
  }

  /*
   * 1. Check if loading from Sales Order is enabled. If, yes find all the 
   * sales order with ship from org as org_id and load to mds
    2. Find all source lines from the MDS and load to it
   */
  if ($mdsh->include_so_cb == 1) {
   try {
    $this->_load_so_to_mds($mdsh);
    $this->message .= "<br>All Sales Orders are Successfullyloaded into MDS";
   } catch (Exception $e) {
    $this->message .= "<br>Sales Order loading to MDS failed!" . $e->getMessage();
   }
  }
  //load all the forecasts from source list
  try {
   $this->_load_sourceListDemand_to_mds($mdsh);
   $this->message .= "<br>All Demands from Source List are Successfullyloaded into MDS";
  } catch (Exception $e) {
   $this->message .= "<br>Demand Loading from Source List to MDS failed!" . $e->getMessage();
  }
  return $this->message;
 }

}

//end of mds class
?>