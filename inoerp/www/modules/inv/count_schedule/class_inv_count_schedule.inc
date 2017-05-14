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
 * inv_count_schedule
 * Contains all the inv_count_entries information, such as - item_id_m, inv_count_header_id,  org_id, subinventory_id, etc.
 * 
 */
class inv_count_schedule extends dbObject {

 public static $table_name = "inv_count_schedule";
 public static $primary_column = "inv_count_schedule_id";
 public static $parent_primary_column = "inv_count_header_id";
 public static $key_column = "item_id_m";
 public static $module = "inv";
 public static $system_info = [
  'name' => 'Count Schedul ',
  'number' => '2106',
  'description' => 'Inventory Count Schedules',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 6
 ];
 public static $status_a = [
  'UNCOUNTED' => 'Un Counted',
  'PENDING_APPROVAL' => 'Pending Approval',
  'APPROVED' => 'Approved',
  'COMPLETE' => 'Complete',
 ];
 public $field_a = [
  'inv_count_schedule_id',
  'inv_count_header_id',
  'item_id_m',
  'subinventory_id',
  'locator_id',
  'lot_number',
  'serial_number',
  'schedule_date',
  'zero_count_cb',
  'status',
  'description',
  'abc_code',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'inv_count_schedule_id',
  'inv_count_header_id',
  'item_id_m',
  'org_id',
  'schedule_date',
  'status',
 ];
 public $column = [
  'inv_count_schedule_id',
  'inv_count_header_id',
  'item_id_m',
  'org_id',
  'schedule_date',
  'status',
 ];
 public $requiredField = [
  'inv_count_header_id',
  'item_id_m',
  'subinventory_id',
  'schedule_date',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "inv_count_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  "item_number",
  'item_description',
 ];
 public $search = [
 ];
 public $pageTitle = " Count Schedule  "; //page Title
 public $inv_count_schedule_id;
 public $inv_count_header_id;
 public $item_id_m;
 public $org_id;
 public $subinventory_id;
 public $locator_id;
 public $lot_number;
 public $serial_number;
 public $schedule_date;
 public $zero_count_cb;
 public $abc_code;
 public $status;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $item_number;
 public $item_description;

 public static function find_by_header_id($id) {
  $vgl = new inv_count_schedule();
  return $vgl->findBy_parentId($id);
 }

 public static function find_by_headerId_date_status($header_id, $date, $status = 'UNCOUNTED') {
  $sql = " SELECT * from inv_count_schedule ";
  $sql .= " WHERE inv_count_header_id = '{$header_id}' ";
  $sql .= " AND status = '{$status}' ";
  if (!empty($date)) {
   $sql .= " AND schedule_date <= '{$date}' ";
  }

  $result = self::find_by_sql($sql);
//  echo $sql; pa($result);
  return !empty($result) ? $result : false;
 }

 public function _before_save() {
  if (!(empty($this->item_number)) && empty($this->item_id_m)) {
   $item_s = item::find_by_itemNumber_fromMasterOrg($this->item_number);
   $this->item_id_m = $item_s->item_id_m;
  }
 }

}

//end of path class
?>