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
 * inv_count_header
 * Contains all the inv_count_header information, such as - count_name, count_type ,  org_id, etc.
 * 
 */

/** Count Logic
 * 1. Find all the items as per class , inventory_count_header - corresponding inv_abc_assigment_id
 * 2. If no count_start_date then count_srat_date = current_date + 1
 * count_end_date = count_start_date + 365
 * Example : no_of_counts_per_year = 12, 4, 1 . count_per_year_weight = 12/17, 4/7, 1/17.
 * total_no_count = no_of_item_a * 12 ;  no_of_item_b * 4 ;  no_of_item_c * 1
 * coundint_days = total_no_work_days = 365 - (2*54) = 257
 * no_of_items_to_be_counted_per_day = total_no_count_x / 257 
 * delay_days = 1;
 * if(no_of_items_to_be_counted_per_day < 1){
 * counting_days = total_no_work_days /  4 ;
 * delay_days = (total_no_work_days - counting_days)/counting_days ;
 * }
 * create sequence of items to be counted by class
 * * $count = 0;
 * for (i=0; i<=counting_days - 1;  delay_days){
 * 
  $offset = ($count) * no_of_items_to_be_counted_per_day;
 * 	$sql .=" LIMIT '{no_of_items_to_be_counted_per_day}' ";
  $sql .=" OFFSET '{$offset}' ";

 * $count = ($count == no_of_counts_per_year-1 ) ? 0 : $count++;
 *  }
 */
class inv_count_header extends dbObject {

 public static $table_name = "inv_count_header";
 public static $primary_column = "inv_count_header_id";
 public static $dependent_classes = ['inv_count_schedule'];
 public static $key_column = "count_name";
 public static $module = "inv";
 public static $system_info = [
  'name' => 'Inventory Count',
  'number' => '2104',
  'description' => 'Inventory Count',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('inv_count_schedule'),
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 4
 ];
 public static $count_type_a = [
  'CYCLE_COUNT' => 'Cycle Count',
  'PHYSICAL_INV' => 'Physical Inventory',
 ];
 public static $approval_required_a = [
  'NEVER' => 'Never',
  'ALWAYS' => 'Always',
  'OUT_OF_TOLERANCE_ALL' => 'Out of tolerance - All criteria',
  'OUT_OF_TOLERANCE_ANY' => 'Out of tolerance - Any criteria',
 ];
 public static $count_action_a = [
  'SCHDULE_COUNT' => 'Schedule Count',
  'UPDATE_COUNT' => 'Update Count',
  'DELETE_COUNT' => 'Delete All Count',
 ];
 public $field_a = [
  'inv_count_header_id',
  'count_name',
  'count_type',
  'adjustment_ac_id',
  'org_id',
  'description',
  'inv_abc_assignment_header_id',
  'approval_required',
  'quantity_variance_positive',
  'quantity_variance_negative',
  'value_variance_positive',
  'value_variance_negative',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'count_name',
  'count_type',
  'description',
  'org_id',
 ];
 public $column = [
  'inv_count_header_id',
  'count_name',
  'count_type',
  'adjustment_ac_id',
  'org_id',
  'description',
  'inv_abc_assignment_header_id',
 ];
 public $requiredField = [
  'count_name',
  'count_type',
  'adjustment_ac_id',
  'org_id',
  'inv_abc_assignment_header_id',
 ];
 public $fields_inForm_notInDataBase = [
  'abc_assignment_name',
  'count_action',
  'action',
  'multi_action_class_pc',
  'multi_action_class_pc_value',
  'action_class_name'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Inventory Count "; //page Title
 public $inv_count_header_id;
 public $count_name;
 public $count_type;
 public $adjustment_ac_id;
 public $org_id;
 public $description;
 public $count_start_date;
 public $inv_abc_assignment_header_id;
 public $approval_required;
 public $quantity_variance_positive;
 public $quantity_variance_negative;
 public $value_variance_positive;
 public $value_variance_negative;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $abc_assignment_name;
 public $count_action;
 private $_no_of_working_days;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 public $action;
 public $action_class_name;

 public function _after_save() {
   
  if (!empty($this->inv_count_header_id) && !empty($_POST['count_per_year'][0])) {
   $abc_ref = new inv_count_abc_ref();

   for ($i = 0; $i < count($_POST['assign_abc_class_value']); $i++) {
    $abc_code = $_POST['assign_abc_class_value'][$i];
//check if data exists
    $abc_ref_extsing = inv_count_abc_ref::find_by_parentId_abcCode($this->inv_count_header_id, $abc_code);
    $abc_ref->inv_count_abc_ref_id = ($abc_ref_extsing) ? $abc_ref_extsing->inv_count_abc_ref_id : null;
    $abc_ref->inv_count_header_id = $this->inv_count_header_id;
    $abc_ref->class_code = $abc_code;
    $abc_ref->count_per_year = $_POST['count_per_year'][$i];
    $abc_ref->audit_trial();
    $abc_ref->save();
   }
  }

  if (!empty($this->inv_count_header_id) && ($this->count_action == 'DELETE_COUNT')) {
   $abc_ref_existing = inv_count_abc_ref::find_by_parent_id($this->inv_count_header_id);
   if (!$abc_ref_existing) {
    return;
   }
   $count_schdule = new inv_count_schedule();
   $count_schdule->deleteBy_parentId($this->inv_count_header_id);
  }

  if (!empty($this->inv_count_header_id) && ($this->count_action == 'SCHDULE_COUNT')) {
   $abc_ref_existing = inv_count_abc_ref::find_by_parent_id($this->inv_count_header_id);
   if (!$abc_ref_existing) {
    return;
   }
//delete all existing lines
   $count_schdule = new inv_count_schedule();
   $count_schdule->deleteBy_parentId($this->inv_count_header_id);

   foreach ($abc_ref_existing as $abc_ref_obj) {
    $no_of_counts_per_year = $abc_ref_obj->count_per_year;
//    $count_start_date = new DateTime();
//    $counting_days = $no_of_working_days = 256;
    $inv_assignment_line = inv_abc_assignment_line::find_by_parentId_classCode_forCycleCount($this->inv_abc_assignment_header_id, $abc_ref_obj->class_code, $this->org_id);
    $this->_schedule_count($inv_assignment_line, $no_of_counts_per_year, $abc_ref_obj->class_code);
   }
  }

  if (!empty($this->inv_count_header_id) && ($this->count_action == 'UPDATE_COUNT')) {
   $abc_ref_existing = inv_count_abc_ref::find_by_parent_id($this->inv_count_header_id);
   if (!$abc_ref_existing) {
    return;
   }

   foreach ($abc_ref_existing as $abc_ref_obj) {
    $no_of_counts_per_year = $abc_ref_obj->count_per_year;
    $sql = "  SELECT 
              ail.inv_abc_assignment_line_id, ailinv_abc_assignment_header_id , ail.item_id_m ,
              ail.abc_class, ail.description

              FROM
              inv_abc_assignment_line ail,
              item

             WHERE ail.inv_abc_assignment_header_id= '{$this->inv_abc_assignment_header_id}' 
             AND ail.abc_class = '{$abc_ref_obj->class_code}'
             AND item.item_id_m = ail.item_id_m
             AND item.org_id = '{$this->org_id}'
             AND item.cycle_count_enabled_cb = '1'
             AND ail.item_id_m NOT IN (
                 SELECT DISTINCT(item_id_m) FROM inv_count_schedule
                 WHERE inv_count_header_id = '{$this->inv_count_header_id}'
                )
       ";
    $inv_assignment_line = self::find_by_sql($sql);
    $this->_schedule_count($inv_assignment_line, $no_of_counts_per_year, $abc_ref_obj->class_code);
   }
  }
 }

 private function _schedule_count($inv_assignment_line, $no_of_counts_per_year, $class_code) {
  $no_of_items = count($inv_assignment_line);
  $count_start_date = new DateTime('now');
  $counting_days = $no_of_working_days = 256;
  $total_item_to_be_counted = $no_of_items * $no_of_counts_per_year;
  $no_of_items_to_be_counted_per_day = ceil($total_item_to_be_counted / 257);
  $delay_days = 1;
  if ($no_of_items_to_be_counted_per_day <= 1) {
   $counting_days = ($no_of_counts_per_year * count($inv_assignment_line));
   $delay_days = floor(($no_of_working_days ) / ($counting_days + 1));
  }
// create sequence of items to be counted by class
  $count = $items_already_scheduled = 0;
  $count_schedule = new inv_count_schedule();
  $count_schedule->abc_code = $class_code;
  $count_schedule->status = 'UNCOUNTED';
  for ($i = 0; $i < $no_of_working_days - 1; $i = $i + $delay_days) {
   $count_start_date->add(new DateInterval("P$delay_days" . 'D'));
   $offset = ($count) * $no_of_items_to_be_counted_per_day;
   $items_already_scheduled += $no_of_items_to_be_counted_per_day;
   $sql = " SELECT * FROM inv_abc_assignment_line WHERE inv_abc_assignment_header_id = '{$this->inv_abc_assignment_header_id}' "
    . " AND abc_class = '{$class_code}' ";
   $sql = ino_perPageSql_i($sql, $no_of_items_to_be_counted_per_day, $offset);
   $result = $this->findBySql($sql);
   foreach ($result as $new_schedule) {
    $count_schedule->inv_count_header_id = $this->inv_count_header_id;
    $count_schedule->item_id_m = $new_schedule->item_id_m;
    $count_schedule->schedule_date = $count_start_date->format(INO_DATE_FORMAT);
    $onhand = onhand_v::find_by_itemId_orgId($count_schedule->item_id_m, $this->org_id);
    if ($onhand) {
     foreach ($onhand as $onhand_o) {
      $count_schedule->inv_count_schedule_id = null;
      $count_schedule->subinventory_id = $onhand_o->subinventory_id;
      if (!empty($onhand_o->locator_id)) {
       $count_schedule->locator_id = $onhand_o->locator_id;
      }else{
       $count_schedule->locator_id = null;
      }
      $count_schedule->save();
     }
    } else {
     echo "<br>No on hand for $count_schedule->item_id_m : $class_code";
     continue;
    }
   }

   if ($items_already_scheduled >= $no_of_items) {
    $count = $items_already_scheduled = 0;
   } else {
    $count++;
   }
  }
 }

 public function multi_select_input_fields() {
  $multi_select_input = [
   'count_entry_actio'
  ];
  return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'action_class_name',
   'mode',
   'action',
   'show_block',
  ];

  return $multi_select_hidden;
 }

}

?>