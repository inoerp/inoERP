<?php

//set $allow_conversion to true when before conversion
class sys_db_update extends dbObject {

 public static $allow_up_date = true;
// public static $table_name = "db_update";
 public static $primary_column = "username";
 public static $key_column = "profile_name";
 public static $module = "sys";
 public $db_update_mode;
 public $message = '';
 public $prg_db_update_parameters = [
  'Program Mode' => 'search_program_mode',
  'New Version DB' => 'search_db_name',
  'Old Version DB' => 'search_db_name_old',
 ];
 public $prg_db_update_details = [
  'name' => 'Update Database from Old to New Version',
  'description' => 'Update Database from Old to New Version',
 ];

 public function prg_db_update($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message .= '<br> Staring Update Database program ';

  if (!empty($parameters['program_mode'][0])) {
   $program_mode = $this->db_update_mode = $parameters['program_mode'][0];
   $this->message .= '<br> Entered db_update is : ' . $program_mode;
  } else {
   $program_mode = 'TEST';
   $this->message .= '<br> No program_mode found. Running the program in TEST mode ' . __LINE__;
  }


  try {
   $this->update_db($program_mode);
   $this->message .= "<br>Update DB program is sucessfully completed";
  } catch (Exception $e) {
   $this->message .= "<br>Update DB program failed!" . $e->getMessage();
  }
  return $this->message;
 }

 public function update_db($mode = 'TEST') {
  global $dbc;
  global $db;
  global $db2;

  $tables_in_db1 = $db->find_all_tables();
  $tables_in_db2 = $db->find_all_tables(DB_NAME2);
  $tables_in_db1_ar = ino_arrayObj_to_array($tables_in_db1, 'TABLE_NAME');
  $tables_in_db2_ar = ino_arrayObj_to_array($tables_in_db2, 'TABLE_NAME');

  $this->message .= "<br> count in DB 1 " . count($tables_in_db1_ar);
  $this->message .= "<br> count in DB 2 " . count($tables_in_db2_ar);

  $new_tables = array_diff($tables_in_db1_ar, $tables_in_db2_ar);
  $this->message .= "<br>No of new tables " . count($new_tables);

  $delete_tables = array_diff($tables_in_db2_ar, $tables_in_db1_ar);
  $this->message .= "<br>No of new tables to be deleted " . count($delete_tables);
  $no_of_tables_updated = 0;
//create table if doesnt exists . Sync table structure if exists
  foreach ($tables_in_db1_ar as $k => $table_name) {
   if (in_array($table_name, $tables_in_db2_ar)) {
    $comp_result = $this->_ino_isSame_tablesInTwoDataBases($table_name);

    if ($comp_result == 'DIFFERENT') {
     $no_of_tables_updated++;
     $this->message .= "<br>Updating table  $table_name  : ";
     if ($mode == 'FINAL') {
      $this->_ino_update_table_in_oldDB($table_name);
     }
    }
   } else {
    $this->message .= "<br>$table_name does not exist in old DB. Creating table Table";
    if ($mode == 'FINAL') {
     $this->_ino_create_table_in_oldDB($table_name);
    }
   }
  }

  $this->message .= "<br>No of new tables updated " . $no_of_tables_updated;

  if (!empty($delete_tables)) {
   foreach ($delete_tables as $k => $tbl_name_drop) {
    $this->message .= "<br>$tbl_name_drop is not required. Tryig to drp the table";
    if ($mode == 'FINAL') {
     $this->_ino_drop_table_in_oldDB($tbl_name_drop);
    }
   }
  }

  //update views
  $this->_ino_create_views_in_oldDB($mode);
  
  return $this->message;
 }

 private function _ino_update_table_in_oldDB($tbl_name) {
  global $db;
  $dbc2 = new dbc2();
  $table_name = ".$tbl_name";
  $new_db_table = DB_NAME . $table_name;
  $old_db_table_temp = DB_NAME2 . $table_name . '_temp';
  $old_db_table = DB_NAME2 . $table_name;
  $sql = " CREATE TABLE $old_db_table_temp LIKE $new_db_table ";
  $dbc2->ddlexecute($sql);
  $dbc2->confirm();

  $columns = $db->get_dbColumns($tbl_name);
  $inst_str = implode(',', $columns);
  $sql_inst = " INSERT INTO $old_db_table_temp ($inst_str) "
   . " SELECT $inst_str FROM $old_db_table ";
  $dbc2->ddlexecute($sql_inst);
  $dbc2->confirm();

  $sql3 = " DROP TABLE $old_db_table ";
  $dbc2->ddlexecute($sql3);
  $dbc2->confirm();

  $sql4 = " RENAME TABLE $old_db_table_temp TO $old_db_table ";
  $dbc2->ddlexecute($sql4);
  $dbc2->confirm();

  echo "<div class='alert alert-sucess'>$old_db_table is sucessfully updated</div>";
 }

 private function _ino_isSame_tablesInTwoDataBases($tbl1) {
  $db = new dbObject();
  $sql = " SELECT IF(COUNT(1)>0,'DIFFERENT','SAME') comp_result FROM
(
    SELECT
        column_name,ordinal_position,
        data_type,column_type,COUNT(1) rowcount
    FROM information_schema.columns
    WHERE
    (
        (table_schema='" . DB_NAME . "' AND table_name='{$tbl1}') OR
        (table_schema='" . DB_NAME2 . "' AND table_name='{$tbl1}')
    )
    AND table_name = '{$tbl1}'
    GROUP BY
        column_name,ordinal_position,
        data_type,column_type
    HAVING COUNT(1)=1
) A;
";
  $result = $db->find_by_sql($sql);
  return !empty($result) ? $result[0]->comp_result : false;
 }

 private function _ino_comparetables_inTwoDataBases($tbl1) {
  $db = new dbObject();
  $sql = " SELECT column_name,ordinal_position,data_type,column_type FROM
(
    SELECT
        column_name,ordinal_position,
        data_type,column_type,COUNT(1) rowcount
    FROM information_schema.columns
    WHERE
    (
        (table_schema='" . DB_NAME . "' AND table_name='{$tbl1}') OR
        (table_schema='" . DB_NAME2 . "' AND table_name='{$tbl1}')
    )
    AND table_name = '{$tbl1}'
    GROUP BY
        column_name,ordinal_position,
        data_type,column_type
    HAVING COUNT(1)=1
) A;
";
  $result = $db->find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 private function _ino_create_table_in_oldDB($tbl_name) {
  $dbc2 = new dbc2();
  $table_name = ".$tbl_name";
  $new_db_table = DB_NAME . $table_name;
  $old_db_table = DB_NAME2 . $table_name;
  $sql = " CREATE TABLE $old_db_table LIKE $new_db_table ";
  $dbc2->ddlexecute($sql);
  $dbc2->confirm();
  echo "<div class='alert alert-sucess'>$old_db_table is sucessfully created</div>";
 }

 private function _ino_create_views_in_oldDB($mode = 'TEST') {
  $db = new dbObject();
  $views_in_db1 = $db->find_all_views();
  if ($mode == 'FINAL') {
   foreach ($views_in_db1 as $obj) {
    $dbc2 = new dbc2();
    $sql = "
 CREATE or REPLACE 
 ALGORITHM = UNDEFINED
 VIEW {$obj->TABLE_NAME}
 AS {$obj->VIEW_DEFINITION} ";
    $dbc2->ddlexecute($sql);
    $dbc2->confirm();
   }
  }

  $this->message .= "<br>No of views created / replaced " . count($views_in_db1);
 }

 private function _ino_drop_table_in_oldDB($tbl_name) {
  $dbc2 = new dbc2();
  $table_name = ".$tbl_name";
  $drop_db_table = DB_NAME2 . $table_name;
  $sql = " DROP TABLE $drop_db_table ";
  echo $sql;
  $dbc2->ddlexecute($sql);
  $dbc2->confirm();
  echo "<div class='alert alert-sucess'>$drop_db_table is sucessfully dropped</div>";
 }

}

//end of path class
?>