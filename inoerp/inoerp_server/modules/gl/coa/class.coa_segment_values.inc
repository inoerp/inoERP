
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
 * coa_segment_values
 * 
 */
class coa_segment_values {

 public static $table_name = "coa_segment_values";
 public $coa_segment_values_id;
 public $coa_id;
 public $coa_segments;
 public $coa_structure_id;
 public $account_type;
 public $coa_name;
 public $segment_code;
 public $description;
 public $efid;
 public $status;
 public $rev_enabled;
 public $rev_number;
 public $effective_start_date;
 public $effective_end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function coa_account_types() {
  $option_header = option_header::find_by_name('COA_ACCOUNT_TYPE');
  $coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
  return $coa_account_types;
 }

 public static function find_by_sql($sql = "") {
  global $db;
  $result_set = $db->query($sql);
  $object_array = array();
  while ($row = $db->fetch_array($result_set)) {
   $object_array[] = self::instantiate($row);
  }//end of while Loop
  return $object_array;
 }

 public static function find_all() {
  $sql = " SELECT * FROM " . self::$table_name;
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_id($coa_segment_values_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where coa_segment_values_id={$coa_segment_values_id} ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_coa_id_and_segments($coa_id, $coa_segments) {
  $sql = "SELECT * FROM " . self::$table_name .
   " where coa_id={$coa_id}" .
   "  AND coa_segments LIKE '%{$coa_segments}%' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_coaid_segment_segmentcode($coa_id, $coa_segments, $segment_code) {
  global $db;
  $sql = "SELECT coa_segment_values_id FROM " . self::$table_name .
   " where coa_id={$coa_id}" .
   "  AND coa_segments LIKE '%{$coa_segments}%' " .
   "  AND segment_code = '{$segment_code}'" .
   "  AND  segment_code IS NOT NULL ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result_set = $db->query($sql);
  $object_array = array();
  while ($row = $db->fetch_array($result_set)) {
   $object_array[] = $row;
  }//end of while Loop
//    return $object_array;
  return count($object_array) == 0 ? 0 : 1;
 }

 public static function find_coa_segment_values_fields_by_id($coa_segment_values_id) {
  $sql = "SELECT balancing, cost_center, 	natural_account, inter_company,
      segment1, segment2, segment3, segment4 FROM "
   . self::$table_name . " where coa_segment_values_id={$coa_segment_values_id} ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 private static function instantiate($record) {
  $object = new self;
  foreach ($record as $attribute => $value) {
   if ($object->has_attribute($attribute)) {
    $object->$attribute = $value;
   }
  }
  return $object;
 }

 Private function has_attribute($attribute) {
  $object_vars = get_object_vars($this);
  return array_key_exists($attribute, $object_vars);
 }

 public static function install() {
  global $db;
  $sql = "
		 ";
  $result = $db->query($sql);
  return !empty($result) ? $result : false;
 }

 public function save() {
  if (empty($this->coa_segment_values_id)) {
   $this->create();
  } else {
   $this->update($this->coa_segment_values_id);
  }
  return $this->msg;
 }

 public function create() {
  global $db;
  $sql = "INSERT INTO 
                coa_segment_values (
                `coa_segment_values_id`,
				`coa_id`,
                `coa_segments`,
                `account_type`,
                `segment_code`,
				`description`,      
                `status`,
                `rev_enabled`,
                `rev_number`,
                `created_by`,
                `creation_date`,
                `last_update_by`,
                `last_update_date`)
        VALUES ( NULL , '{$this->coa_id}', '{$this->coa_segments}', '{$this->account_type}', '{$this->segment_code}', 
          '{$this->description}', '{$this->status}', '{$this->rev_enabled}',  '{$this->rev_number}',
		   '{$this->created_by}', '{$this->creation_date}','{$this->created_by}','{$this->creation_date}' )";

  if ($db->query($sql)) {
   $this->coa_segment_values_id = $db->insert_id();
   $this->msg = 1;
  } else {
   $this->msg = 0;
  }
  return $this->msg;
 }

//end of create coa_segment_values

 public function update($coa_segment_values_id) {
  global $db;
  $coa_segment_values_id = $db->escape_value($this->coa_segment_values_id);
  $description = $db->escape_value($this->description);
  $status = $db->escape_value($this->status);
  $rev_enabled = $db->escape_value($this->rev_enabled);
  $rev_number = $db->escape_value($this->rev_number);
  $time = time();
  $last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
  $last_update_by = $_SESSION['user_name'];

  $sql = " UPDATE `coa_segment_values` SET 
        `description` = '{$description}',
        `status` = '{$status}',
        `rev_enabled` = '{$rev_enabled}',
        `rev_number` = '{$rev_number}',
        `last_update_by` = '{$last_update_by}',
        `last_update_date` = '{$last_update_date}' 
        WHERE `coa_segment_values_id` = '{$coa_segment_values_id}' ";

  if ($db->query($sql)) {
   $this->msg = 1;
  } else {
   $this->msg = 0;
  }
  return $this->msg;
 }

 public function delete($coa_segment_values_id) {
  global $db;
  $coa_segment_values_id = $db->escape_value($coa_segment_values_id);
  $sql = "DELETE FROM `coa_segment_values` WHERE `coa_segment_values_id` = '{$coa_segment_values_id}' ";
  if ($db->query($sql)) {
   $msg = 1;
  } else {
   $msg = 0;
  }
  return $msg;
 }

 public static function coa_segment_values_page() {
  echo '<table class="normal">
                <thead> 
                    <tr>
                    <th>COA Segment Value Id/th>
                    <th>Segment Code </th>
                    <th>Description</th>
                    <th>Created By</th>
                    <th>Creation Date</th>
                    <th>Last Update By</th>
                    <th>Last Update Date</th>
                    <th>Action</th>
                    </tr>
                </thead>
                <tbody>';

  $coa_segment_values = coa_segment_values::find_all();
  foreach ($coa_segment_values as $record) {
   echo '<tr><td>' . $record->coa_segment_values_id . '</td>';
   echo '<td>' . $record->segment_code . '</td> ';
   echo '<td>' . $record->description . '</td>';
   echo '<td>' . $record->created_by . '</td>';
   echo '<td>' . $record->creation_date . '</td> ';
   echo '<td>' . $record->last_update_by . '</td>';
   echo '<td>' . $record->last_update_date . '</td>';
   echo '<td><a href="coa_segment_values.php?coa_segment_values_id=' . $record->coa_segment_values_id . '">Update</a></td></tr>';
  }

  echo ' </tbody> </table>';
 }

}

//end of coa_segment_values class
?>
