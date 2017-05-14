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
class new_content_type extends content_type {

 public static $table_name = "";
 public static $system_info = [
  'name' => 'New Content Type',
  'number' => '10031',
  'description' => 'New Content Type',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('block_content'),
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 31
 ];
 public static $Field_array = [
  'field_label',
  'field_position',
  "field_name",
  "field_num",
  "field_type",
  'option_type'
 ];
 public static $checkbox_array = [];
 public static $column_array = [];
 public static $requiredField_array = [
  "field_name",
  "field_type"
 ];
 public static $primary_column = "content_type";
 public $content_type;
 public $Field;
 Public $Type;
 public $field_name;
 public $field_num;
 public $option_type;
 public $field_option;
 public $field_label;
 public $field_position;
 public $required_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function __set($name, $value) {
  $this->$name = $value;
 }

 public function _after_save() {
//	if (count($_POST['field_name']) > 0) {
//	 $i = 0;
//	 foreach ($_POST['field_name'] as $records) {
//
//		$field_record = new new_category;
//		$field_name = trim(mysql_prep($_POST['field_name'][$i]));
//		$field_type = trim(mysql_prep($_POST['field_type'][$i]));
//		$field_num = trim(mysql_prep($_POST['field_num'][$i]));
//		$new_category = trim(mysql_prep($_POST['category']));
//		$new_fild_entry = $field_record->save_table_field($new_category, $field_name, $field_type, $field_num);
//		if ($new_fild_entry) {
//		 $newMsg = 'Record is Successfully Saved';
//		}
//		$i++;
//	 }
//	}
 }

 public static function find_fields_by_id($content_type_id) {
  global $db;
  $content_type = content_type::find_by_id($content_type_id);
  $table_name = 'c_' . $content_type->content_type;

  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql_fields = " SELECT * from all_tab_cols WHERE table_name =  '";
    $sql_fields .= strtoupper($table_name) . "'";
    $sql_fields .= " AND OWNER= '" . strtoupper(DB_NAME) . "'";
    break;

   default:
    $sql_fields = " SHOW COLUMNS FROM ";
    $sql_fields .= $table_name;
    break;
  }
  $result = self::find_by_sql($sql_fields);
  foreach ($result as &$object) {

   switch (DB_TYPE) {
    case 'ORACLE' :
     $type = $object->data_type;
     $object->field_type = $type;
     $object->field_name = $object->column_name;
     $object->field_enum = '';
     break;

    default:
     $type = $object->type;
     $type_array = explode("(", $type);
     if (is_array($type_array)) {
      $object->field_type = $type_array[0];
      if (!empty($type_array[1])) {
       $object->field_num = rtrim($type_array[1], ")");
      } else {
       $object->field_num = '';
      }
     } else {
      $object->field_type = $type;
     }
     $object->field_name = $object->field;
     $object->field_enum = '';
     break;
   }


   $ctr = content_type_reference::find_by_contentTypeId_fieldName($content_type_id, $object->field_name);
   if ($ctr) {
    $object->option_type = $ctr->option_type;
    $object->field_label = $ctr->field_label;
    $object->field_position = $ctr->field_position;
   } else {
    $object->option_type = NULL;
    $object->field_label = NULL;
    $object->field_position = NULL;
   }
  }
  return !empty($result) ? $result : false;
 }

 public function save_table_field($enum_array = "") {
  $table_exists = 0;
  global $db;
  global $dbc;
  $table_name = 'c_' . $this->content_type;

  if (!empty($enum_array)) {
   $enum_value = "";
   foreach ($enum_array as $key => $value) {
    $enum_value .="'$value',";
   }
   $enum_value = rtrim($enum_value, ",");
  }
//check for existing table name
//	$exist_query = "Select table_name from information_schema.tables where table_name= :table_name ";
  $exist_query = " SELECT TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE' "
   . " AND TABLE_SCHEMA= '" . DB_NAME . "' AND table_name= :table_name ";
  $stmt = $dbc->connection->prepare("$exist_query");
  $stmt->bindParam(':table_name', $table_name);
  try {
   $stmt->execute();
   $result = $stmt->fetchObject();
  } catch (PDOException $e) {
   $ie->page_exception = ['dbObject find existing table Error : ' => $e->getMessage()];
  }

//$new_field_name = 'field_'.$field_name;
  if (!empty($result)) {
   //check for existing columns names
   $existing_fields_array = array();

   switch (DB_TYPE) {
    case 'ORACLE' :
     $exist_column_query = " SELECT * from all_tab_cols WHERE table_name =  ";
     $exist_column_query .= strtoupper($table_name);
     break;

    default:
     $exist_column_query = " SHOW COLUMNS FROM ";
     $exist_column_query .= $table_name;
     break;
   }

   $stmt1 = $dbc->connection->prepare("$exist_column_query");
   try {
    $stmt1->execute();
    $existing_fields = $stmt1->fetchAll(PDO::FETCH_ASSOC);
   } catch (PDOException $e) {
    $ie->page_exception = ['dbObject find existing_fields_array Error : ' => $e->getMessage()];
   }
   foreach ($existing_fields as $rows) {
    $existing_fields_array[] = $rows['Field'];
   }

   if (in_array($this->field_name, $existing_fields_array)) {
    $this->msg = 50;
   } else {
    echo "<div class='message>'<br>new field_name '. $this->field_name; </div>";
    if ($this->field_type == 'option') {
     $this->field_type = 'varchar';
     $this->field_num = 256;
    }

    $sql = " ALTER TABLE " . $table_name;
    $sql .=" ADD COLUMN $this->field_name $this->field_type ";
    if (($this->field_type == 'varchar') || ($this->field_type == 'int')) {
     $sql .="(" . $this->field_num . ")";
    }
    if (($this->field_type == 'enum')) {
     $sql .="(" . $enum_value . ")";
    }
    $sql .=" DEFAULT NULL ";

    echo $sql;
    if ($db->query($sql)) {
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  } else {
   $sql = " CREATE TABLE IF NOT EXISTS " . $table_name;
   $sql .=" ( ";
   $sql .="  content_id int(12) NOT NULL , ";
   $sql .="  $this->field_name $this->field_type ";
   if (($this->field_type == 'varchar') || ($this->field_type == 'int')) {
    $sql .="(" . $this->field_num . ")";
   }
   if (($this->field_type == 'enum')) {
    $sql .="(" . $enum_value . ")";
   }
   $sql .=" DEFAULT NULL ";
   $sql .=" , ";
   $sql .= " PRIMARY KEY (`content_id`) ";
   $sql .=" ) ";
   $sql .="ENGINE=MyISAM DEFAULT CHARSET=latin1;";
//	 echo '$sql is ' . $sql;
   try {
    $dbc->connection->exec($sql);
    $this->msg = 1;
    $path = new path;
    $path->parent_id = 62;
    $path->name = $this->content_type;
    $path->path_link = "extensions/content/content.php?content_type=" . $this->content_type;
    $path->description = "Create & Update" . $this->content_type;
    $path->module = 14;
    $path->primary = 0;
    $path->save();
   } catch (Exception $e) {
    $this->msg = 0;
    echo "<br> Error in creating  table . Error @ class_new_content_type @@ " . __LINE__ . $e->getMessage();
    $dbc->rollback = 1;
   }
  }

  return $this->msg;
 }

}

//end of content_type class
?>