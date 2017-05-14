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
 * fp_urgent_card
 * Used for kanban /minmax board
 * Contains all the fp_mds_header information, such as - fp_urgent_card_id, card_details , created_by etc
 * 
 */
class fp_urgent_card extends dbObject {

 public static $table_name = "fp_urgent_card";
 public static $primary_column = "fp_urgent_card_id";
 public static $key_column = 'card_details';
 public static $module = "fp";
 public static $system_info = [
  'name' => 'Urgent Card',
  'number' => '2509',
  'description' => 'FP Urgent Card',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('fp_mds_line'),
  'primary_entity_cb' => '',
  'module_name' => 'fp',
  'weight' => 9
 ];
 public $field_a = [
  'fp_urgent_card_id',
  'card_details',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'created_by'
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=urgent_card',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " Urgent Cards "; //page Title
 public $fp_urgent_card_id;
 public $card_details;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_current_cardList() {
  $sql = "SELECT card_details from  fp_urgent_card ORDER BY fp_urgent_card_id DESC  ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result[0]->card_details : false;
 }

}

?>
