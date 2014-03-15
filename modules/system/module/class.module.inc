<?php

class module extends dbObject {
  protected static $table_name = "module";
  public $module_id;
  public $name;
  public $number;
  public $description;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $time;

//  public static function find_by_sql($sql = "") {
//    global $db;
//    $result_set = $db->query($sql);
//    $object_array = array();
//    while ($row = $db->fetch_array($result_set)) {
//      $object_array[] = self::instantiate($row);
//    }//end of while Loop
//    return $object_array;
//  }
//
//  public static function find_all() {
//    $sql = " SELECT * FROM " . self::$table_name;
//    $result = self::find_by_sql($sql);
//    return $result;
//  }
//
//  public static function find_by_id($module_id) {
//    $sql = "SELECT * FROM " . self::$table_name . " where module_id={$module_id} LIMIT 1";
//    $result_array = self::find_by_sql($sql);
//    return !empty($result_array) ? array_shift($result_array) : false;
//  }
//
//  private static function instantiate($record) {
//    $object = new self;
//    foreach ($record as $attribute => $value) {
//      if ($object->has_attribute($attribute)) {
//        $object->$attribute = $value;
//      }
//    }
//    return $object;
//  }
//
//  Private function has_attribute($attribute) {
//    $object_vars = get_object_vars($this);
//    return array_key_exists($attribute, $object_vars);
//  }

  public static function install() {
    global $db;
    $sql = "
		CREATE TABLE IF NOT EXISTS `module` (
		  `module_id` int(12) NOT NULL auto_increment,
		  `number` int(12) NOT NULL,
		  `name` varchar(50) NOT NULL,
		  `description` varchar(200) default NULL,
		  `created_by` varchar(100) default NULL,
		  `creation_date` varchar(50) default NULL,
		  `last_update_by` varchar(100) default NULL,
		  `last_update_date` varchar(50) default NULL,
		  PRIMARY KEY  (`module_id`),
		  UNIQUE KEY `number` (`number`,`name`)
		) ENGINE=MyISAM  DEFAULT CHARSET=latin1 ";
    $result = $db->query($sql);
    return !empty($result) ? $result : false;
  }

  public function save() {
    if (empty($this->module_id)) {
      $this->create();
    } else {
      $this->update($this->module_id);
    }
    return $this->msg;
  }

  public function create() {
    global $db;
    $sql_header = "INSERT INTO module (
					  `module_id`, 
					  `number`, 
					  `name`, 
					  `description`, 
					  `created_by`, 
					  `creation_date`, 
					  `last_update_by`, 
					  `last_update_date`) 
  VALUES( NULL , '{$this->number}', '{$this->name}', '{$this->description}', 
         '{$this->created_by}', '{$this->creation_date}', '{$this->created_by}', 
		 '{$this->creation_date}' )";

    if ($db->query($sql_header)) {
      $this->option_id = $db->insert_id();
      $this->msg = 1;
    } else {
      $this->msg = 0;
    }
    return $this->msg;
  }

//end of create module

  public function update($module_id) {
    global $db;
    $module_id = $db->escape_value($this->module_id);
    $number = $db->escape_value($this->number);
    $name = $db->escape_value($this->name);
    $description = $db->escape_value($this->description);
    $time = time();
    $last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
    $last_update_by = $_SESSION['user_name'];

    $sql = " UPDATE `module` SET 
			`number` = '{$number}', 
			`name` = '{$name}', 
			`description` = '{$description}', 
			`last_update_by`= '{$last_update_by}', 
			`last_update_date`= '{$last_update_date}'
			 WHERE `module_id` = '{$module_id}' ";

    if ($db->query($sql)) {
      $this->msg = 1;
    } else {
      $this->msg = 0;
    }
    return $this->msg;
  }

//end of update module
//  public function module_delete($module_id) {
//    global $db;
//    $module_id = $db->escape_value($module_id);
//    echo '<br/>moduleid : ' . $module_id . '<br/>';
//
//    $sql = "DELETE FROM `module` WHERE `module_id` = '{$module_id}' ";
////      $result = mysql_query($query);
//    if ($db->query($sql)) {
//      return true;
//    } else {
//      return false;
//    }
//  }
//end of update delete

  public static function module_menu() {
    global $db;
    $sql = "SELECT * FROM `module` WHERE `primary` = 1 ";
    $object = self::find_by_sql($sql);
    echo '<ul id="menu">';
    foreach ($object as $module) {
//     echo '<li><a class="sub" href="#x" tabindex="1"> 
//         <img src="click-slide/sales.png" alt="" />'. $module->name .'</a>
//         <img class="close" src="click-slide/trans.gif" alt="" />';
      $url = self::full_module($module->value);
      echo '<li>' . '<a href="' . $url . '">' . $module->name . '</a><ul>';
      $child_sql = "SELECT * FROM `module` WHERE `module` = '{$module->module}' ";
      if ($child_sql) {
        $child_object = self::find_by_sql($child_sql);
        foreach ($child_object as $child_module) {
          $child_url = self::full_module($child_module->value);
          echo '<li>' . '<a href="' . $child_url . '">' . $child_module->name . '</a></li>';
        }//end of child foreach
      }//end of if loop
      echo '</ul> </li>';
    }//end of main for each
    echo '</ul>';
  }

//end of module_menu

  public static function module_page() {
    echo '<table class="normal">
                <thead> 
                    <tr>
                    <th>Module Id</th>
                    <th>Number</th>
					<th>Name</th>
                    <th>Description</th>
                    <th>Created By</th>
                    <th>Creation Date</th>
                    <th>Last Update By</th>
                    <th>Last Update Date</th>
                    <th>Action</th>
                    </tr>
                </thead>
                <tbody>';

    $module = module::find_all();
    foreach ($module as $record) {
      echo '<tr><td>' . $record->module_id . '</td>';
      echo '<td>' . $record->number . '</td> ';
      echo '<td>' . $record->name . '</td> ';
      echo '<td>' . $record->description . '</td>';
      echo '<td>' . $record->created_by . '</td>';
      echo '<td>' . $record->creation_date . '</td> ';
      echo '<td>' . $record->last_update_by . '</td>';
      echo '<td>' . $record->last_update_date . '</td>';
      echo '<td><a href="module.php?module_id=' . $record->module_id . '">Update</a></td></tr>';
    }

    echo ' </tbody> </table>';
  }

}

//end of module class
?>
