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
 * fp_kanban_release
 * All Kanban Release Information
 * Contains all the fp_kanban_release information, such as - fp_kanban_release_id, job_code , job_name, etc
 * 
 */
class fp_kanban_release extends dbObject {

 public static $table_name = "fp_kanban_release";
 public static $primary_column = "fp_kanban_release_id";
 public static $key_column = 'card_numbers';
 public static $module = "fp";
 public static $system_info = [
  'name' => 'Kanban Release',
  'number' => '2525',
  'description' => 'Kanban Release',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 8
 ];
 public $field_a = [
  'fp_kanban_release_id',
  'card_numbers',
  'description',
  'status',
  'no_of_cards',
  'invalid_card_numbers',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'fp_kanban_release_id',
  'description',
  'status',
 ];
 public $column = [
  'fp_kanban_release_id',
  'description',
  'status',
  'no_of_cards',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $fp_kanban_release_id;
 public $card_numbers;
 public $description;
 public $status;
 public $no_of_cards;
 public $invalid_card_numbers;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Kanban Release"; //page Title

 public function _before_save() {
  global $dbc;
  $invalid_cards = [];
  $succeful_card_count = 0;
  $this->status = 'Completed';
  if (empty($this->card_numbers)) {
   echo "<br>No valid card numbers entered";
   return -90;
  }
  $card_number_list_a = preg_split('/\s+/', $this->card_numbers);
  echo "<br>Number of entered cards : " . count($card_number_list_a);
  $this->no_of_cards =  count($card_number_list_a);
  foreach ($card_number_list_a as $k => $card_num) {
   $fp_kanban_line_i = fp_kanban_line::find_by_cardNum($card_num);
   if ($fp_kanban_line_i) {
    $fp_kanban_line = new fp_kanban_line();
    foreach ($fp_kanban_line->field_a as $f_k => $f_v) {
     $fp_kanban_line->$f_v = $fp_kanban_line_i->$f_v;
    }
    $fp_kanban_line->action = 'REPLENISH';
    try {
     $succeful_card_count++;
     $fp_kanban_line->_before_save();
     $fp_kanban_line->save();
     $fp_kanban_line->_after_save();
    } catch (Exception $e) {
     $this->status = 'Completed With Error';
     echo "<br>Failed to create supply for card # : " . $card_num;
    }
   } else {
    array_push($invalid_cards, $card_num);
   }
  }

  if (count($invalid_cards) > 0) {
   echo "<br>Number of invalid cards : " . count($invalid_cards);
   echo "<br>Invalid cards are : ";
   foreach ($invalid_cards as $k2 => $v2) {
    echo '<br>' . $v2;
   }
   $this->invalid_card_numbers = implode('|', $invalid_cards);
  }
  $this->description = $succeful_card_count .' out of ' . count($card_number_list_a) . ' are successfully replinshed' ;

 }

}

//end of fp_kanban_release class
?>