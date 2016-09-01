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
 * extn_emessage_header CLass
 * Contains all the extn_emessage_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class extn_emessage_header extends dbObject {

 public static $table_name = "extn_emessage_header";
 public static $dependent_classes = ['extn_emessage_line'];
 public static $primary_column = "extn_emessage_header_id";
 public static $key_column = 'user_id1';
 public static $module = "extn";
 public static $system_info = [
  'name' => 'E Message',
  'number' => '10041',
  'description' => 'Create & Mainten Message',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('extn_emessage_line'),
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 1
 ];
 public $field_a = [
  'extn_emessage_header_id',
  'from_user_id',
  'user_id',
  'user_id_comb',
  'user_deleted_cb',
  'from_user_deleted_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'from_user_id',
  'user_id',
 ];
 public $requiredField = [
  'from_user_id',
  'user_id',
  'user_id_comb',
 ];
 public $fields_inForm_notInDataBase = [
  'action',
  'user_name',
  'from_user_name'
 ];
// public $search = [
//  '_show_update_path' => 1,
//  '_show_view_path' => 1
// ];
 public $pageTitle = " Message "; //page Title
 public $extn_emessage_header_id;
 public $from_user_id;
 public $user_id;
 public $user_id_comb;
 public $user_deleted_cb;
 public $from_user_deleted_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $user_name;

 private function _create_user_id_comb() {
  $this->user_id_comb = $this->from_user_id > $this->user_id ? $this->from_user_id . '-' . $this->user_id : $this->user_id . '-' . $this->from_user_id;
 }
 
 public function getnset_user_id_comb(){
  if(empty($this->user_id_comb)){
   $this->_create_user_id_comb();
  }
  return $this->user_id_comb;
 }

 Public static function primary_service_type() {
  $option_header = option_header::find_by_name('HD_PRI_SERVICE_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function find_msg_listing($user_id) {
  $sql = " SELECT  eeh.user_id, eeh.extn_emessage_header_id, eeh.user_id_comb, user.username, user.image_file_id
FROM extn_emessage_header eeh,
ino_user as user
WHERE user.ino_user_id = eeh.user_id
AND eeh.from_user_id = '{$user_id}'
 
UNION
SELECT  eeh.from_user_id, eeh.extn_emessage_header_id, eeh.user_id_comb, user.username, user.image_file_id
FROM extn_emessage_header eeh,
ino_user as user
WHERE user.ino_user_id = eeh.from_user_id 
AND eeh.user_id = '{$user_id}' ";
//echo $sql;
  $result = self::find_by_sql($sql);
   return !empty($result) ? $result : ' ';
 }

}

//end of extn_emessage_header class
?>