<?php

class option_header {
  protected static $table_name = "option_header";
	
  public static $access_level_array = [
		'system'=>'System',
		'user'=>'User',
	  'both'=>'Both'
 ];

	public static $field_array = [
		"option_header_id",
		"option_type",
		"access_level",
		"description",
		"module",
		"efid",
		"status",
		"rev_enabled",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];

	 public static $initial_search_array = [
		 "option_header_id",
		 "option_type",
		 "description",
 ];
 public static $checkbox_array = [
		 ];
 public static $column_array = [
		 "option_header_id",
		 "option_type",
		 "description",
		 "module",
		 "status "
 ];
 
 public static $base_encoded_array = [ ];
 
 public static $requiredField_array = [
    "option_type",
		"access_level",
		"description",
		"module",
 ];
 
  public static $primary_column = "option_header_id";	
	
	public $option_header_id;
  public $access_level;
  public $option_type;
  public $description;
  public $module;
  public $efid;
  public $status;
  public $rev_enabled;
  public $rev_number;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;
  public $msg;
  public static $dir = __DIR__;


	 public function __set($name, $value) {
	$this->$name = $value;
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

  public static function find_all_headers() {
    $sql = " SELECT * FROM " . self::$table_name;
    $result = self::find_by_sql($sql);
    return $result;
  }

 public static function count_all() {
	global $db;
	$sql = "SELECT COUNT(*) FROM " . self::$table_name;
	$result_set = $db->query($sql);
	$row = $db->fetch_array($result_set);
	return array_shift($row);
 }
 
 public static function count_all_by_sql($sql) {
	global $db;
	$result_set = $db->query($sql);
	$row = $db->fetch_array($result_set);
	return array_shift($row);
 }
 
	public static function find_by_id($option_header_id) {
    global $db;
    $sql = " SELECT * FROM " . self::$table_name . " where option_header_id ='{$option_header_id}' LIMIT 1";
    $result_array = self::find_by_sql($sql);
    return !empty($result_array) ? array_shift($result_array) : false;
  }
  
 public static function find_by_name($option_types) {
    global $db;
    $sql = "SELECT * FROM " . self::$table_name . " where option_type LIKE '%{$option_types}%' LIMIT 1";
    $result_array = self::find_by_sql($sql);
    return !empty($result_array) ? array_shift($result_array) : false;
  }
  
 public static function find_by_exact_name($option_types) {
    global $db;
    $sql = "SELECT * FROM " . self::$table_name . " WHERE option_type = '$option_types' LIMIT 1";
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
          CREATE TABLE IF NOT EXISTS `option_header` (
            `option_id` int(10) unsigned NOT NULL auto_increment,
            `access_level` varchar(20) NOT NULL default 'both',
            `option_type` varchar(50) NOT NULL,
            `description` varchar(200) default NULL,
            `module` varchar(50) NOT NULL default 'system',
            `efid` int(12) default NULL,
            `status` varchar(20) default NULL,
            `rev_enabled` varchar(20) default NULL,
            `rev_number` int(10) default NULL,
            `created_by` varchar(40) NOT NULL default '',
            `creation_date` varchar(50) default NULL,
            `last_update_by` varchar(40) NOT NULL default '',
            `last_update_date` varchar(50) default NULL,
            PRIMARY KEY  (`option_id`),
            UNIQUE KEY `option_type` (`option_type`)
          ) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=59 ";
    $result = $db->query($sql);

    return !empty($result) ? $result : false;
  }

  public function save() {
    if (empty($this->option_header_id)) {
      $check_option_type = $this->check_option_type();
      if ($check_option_type==0){
        $this->create();
      }else{
        $this->msg = "Option type already exists";
      }
        
    } else {
      $this->update($this->option_header_id);
      
    }
		return $this->msg;
  }
  
  private function check_option_type(){
    global $db;
    $sql = "SELECT * FROM " . self::$table_name ." where option_type='{$this->option_type}' ";
    $result_array = self::find_by_sql($sql);
    if (count($result_array)>0){
     $this->msg = 1;
    }
    else{
      $this->msg = 0;
    }
    return $this->msg;
    }

 public function create() {
	global $db;
	$field_arry_colums = array();
	$field_arry_values = array();
	foreach (self::$field_array as $key => $value) {
	 $field_arry_colums[] = sprintf("`%s`", $value);
	}
	$field_colums = implode(',', $field_arry_colums);

	foreach (self::$field_array as $key => $value) {
	 if (!empty($this->$value)) {
		$field_arry_values[] = sprintf("'%s'", $this->$value);
	 } else {
		$field_arry_values[] = 'NULL';
	 }
	}
	$field_values = implode(',', $field_arry_values);

	$sql = " INSERT INTO ";
	$sql.= self::$table_name;
	$sql.= ' ( ';
	$sql.= $field_colums;
	$sql.= ' ) ';
	$sql.= 'VALUES';
	$sql.= ' ( ';
	$sql.= $field_values;
	$sql.= ' ) ';


	if ($db->query($sql)) {
	 $this->option_header_id = $db->insert_id();
	 $this->msg = 1;
	} else {
	 $this->msg = 0;
	}
	return $this->msg;
 }

//end of create view

 public function update($option_header_id) {
	global $db;
	$field_arry_values = array();

	foreach (self::$field_array as $key => $value) {
	 if (isset($this->$value)) {
		$field_arry_values[] = sprintf("`%s` = '%s'", $value, $this->$value);
	 }
	}
	$field_values = implode(',', $field_arry_values);

	$time = time();
	$last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
	$last_update_by = $_SESSION['user_name'];

	$sql = " UPDATE ";
	$sql.= self::$table_name;
	$sql .= " SET ";
	$sql.= $field_values;
//    $sql.= "`last_update_date` = '{$last_update_date}'," ;
//    $sql.= "`last_update_by` = '{$last_update_by }'" ;
	$sql.= " WHERE `option_header_id` = '{$option_header_id}' ";

//    echo "<br/>$sql is <br/>" . $sql;

	if ($db->query($sql)) {
	 $this->msg = 2;
	} else {
	 $this->msg = 0;
	}
	return $this->msg;
 }
//end of update path

//  public function path_delete($path_id) {
//    global $db;
//    $path_id = $db->escape_value($path_id);
//    echo '<br/>pathid : ' . $path_id . '<br/>';
//
//    $sql = "DELETE FROM `path` WHERE `path_id` = '{$path_id}' ";
////      $result = mysql_query($query);
//    if ($db->query($sql)) {
//      return true;
//    } else {
//      return false;
//    }
//  }

//end of update delete

}

//end of path class
?>
