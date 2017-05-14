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
 * inv_abc_assignment_header
 * Contains all the fp_mds_header information, such as - abc_assignment_name,  org_id, etc.
 * 
 */
class inv_abc_assignment_header extends dbObject {

 public static $table_name = "inv_abc_assignment_header";
 public static $primary_column = "inv_abc_assignment_header_id";
 public static $dependent_classes = ['inv_abc_assignment_line'];
 public static $key_column = "abc_assignment_name";
 public static $module = "inv";
 public static $system_info = [
  'name' => 'ABC Assignment',
  'number' => '2103',
  'description' => 'Item',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 3
 ];
 public static $assignment_action_a = [
  'ASSIGN_ITEMS' => 'Assign Items',
  'REMOVE_ITEMS' => 'Remove Items',
 ];
 public $field_a = [
  'inv_abc_assignment_header_id',
  'abc_assignment_name',
  'inv_abc_valuation_id',
  'org_id',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'inv_abc_assignment_header_id',
  'abc_assignment_name',
  'org_id',
 ];
 public $column = [
  'inv_abc_assignment_header_id',
  'abc_assignment_name',
  'inv_abc_valuation_id',
  'org_id',
 ];
 public $requiredField = [
  'abc_assignment_name',
  'inv_abc_valuation_id',
  'org_id',
 ];
 public $fields_inForm_notInDataBase = [
  'inv_abc_valuation_id',
  "valuation_name",
  'total_no_of_items',
  'total_value',
  'assign_abc_class_value',
  'assign_seq_number',
  'assign_value',
  'assign_item_percentage',
  'assign_value_percentage',
  'assignment_action'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " ABC Assignment "; //page Title
 public $inv_abc_assignment_header_id;
 public $abc_assignment_name;
 public $inv_abc_valuation_id;
 public $org_id;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $valuation_name;
 public $total_no_of_items;
 public $total_value;
 public $assign_abc_class_value;
 public $assign_seq_number;
 public $assign_value;
 public $assign_item_percentage;
 public $assign_value_percentage;
 public $assignment_action;

 Public static function inv_abc_codes() {
  $option_header = option_header::find_by_name('INV_ABC_CODE');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 public function _before_save() {
  if (!empty($this->inv_abc_assignment_header_id) && !empty($this->assignment_action) && ($this->assignment_action == 'ASSIGN_ITEMS')) {
   $assignment_line = new inv_abc_assignment_line();

   //delete all existing lines
   $assignment_line->deleteBy_parentId($this->inv_abc_assignment_header_id);
   $assign_seq_number_l = 0;

   for ($i = 0; $i < count($_POST['assign_seq_number']); $i++) {
    $assign_seq_number = $_POST['assign_seq_number'][$i];
    $assign_abc_class_value = $_POST['assign_abc_class_value'][$i];

    $abc_result = new inv_abc_valuation_result();
    $abc_result_i = $abc_result->findBy_parentId_SeqNumberLimit($assign_seq_number_l, $assign_seq_number, $this->inv_abc_valuation_id);
    foreach ($abc_result_i as $obj) {
     $assignment_line->inv_abc_assignment_line_id = null;
     $assignment_line->inv_abc_assignment_header_id = $this->inv_abc_assignment_header_id;
     $assignment_line->item_id_m = $obj->item_id_m;
     $assignment_line->abc_class = $assign_abc_class_value;
     $assignment_line->description = 'System Generated On ' . current_time(1);
     $assignment_line->save();
    }
    $assign_seq_number_l = $assign_seq_number;
   }
  }
 }

}

?>