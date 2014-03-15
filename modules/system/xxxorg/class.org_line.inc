<?php

class org_line {

  protected static $table_name = "option_line";
  public $option_id_l;
  public $option_line_id;
  public $option_line_code;
  public $value_l;
  public $description_l;
  public $efid_l;
  public $status_l;
  public $rev_enabled_l;
  public $rev_number_l;
  public $effective_start_date;
  public $effective_end_date;
  public $created_by_l;
  public $creation_date_l;
  public $last_update_by_l;
  public $last_update_date_l;
  public $msg;
  public static $dir = __DIR__;

  public static function find_by_sql($sql = "") {
    global $db;
    $result_set = $db->query($sql);
    $object_array = array();
    while ($row = $db->fetch_array($result_set)) {
      $object_array[] = self::instantiate($row);
    }//end of while Loop
    return $object_array;
  }

  public static function find_all_lines() {
    $sql = " SELECT * FROM " . self::$table_name;
    $result = self::find_by_sql($sql);
    return $result;
  }

  public static function find_by_id($option_line_id) {
    $sql = "SELECT * FROM " . self::$table_name . " where option_line_id={$option_line_id} LIMIT 1";
    $result_array = self::find_by_sql($sql);
    return !empty($result_array) ? array_shift($result_array) : false;
  }

  public static function find_by_option_id($option_id) {
    $sql = "SELECT * FROM " . self::$table_name . " where option_id_l={$option_id}";
    $result_array = self::find_by_sql($sql);
    return $result_array;
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
             CREATE TABLE IF NOT EXISTS `option_line` (
            `option_line_id` int(10) unsigned NOT NULL auto_increment,
            `option_id_l` int(12) NOT NULL,
            `option_line_code` varchar(50) NOT NULL,
            `value_l` varchar(50) NOT NULL,
            `description_l` varchar(255) default NULL,
            `efid_l` int(12) default NULL,
            `status_l` int(2) default '1',
            `rev_enabled_l` int(2) default '0',
            `rev_number_l` int(10) default NULL,
            `effective_start_date` varchar(50) default NULL,
            `effective_end_date` varchar(50) default NULL,
            `created_by_l` varchar(40) NOT NULL default '',
            `creation_date_l` varchar(50) default NULL,
            `last_update_by_l` varchar(40) NOT NULL default '',
            `last_update_date_l` varchar(50) default NULL,
            PRIMARY KEY  (`option_line_id`),
            UNIQUE KEY `option_code` (`option_line_code`),
            KEY `option_id` (`option_id_l`)
          ) ENGINE=MyISAM  DEFAULT CHARSET=latin1 ;
          ";
    $result = $db->query($sql);
    return !empty($result) ? $result : false;
  }

  public function save() {
    if (empty($this->option_line_id)) {
      $check_option_code = $this->check_option_code();
      if ($check_option_code == 0) {
        $this->create();
      } else {
        $this->msg = "Duplicate option code";
      }
      return $this->msg;
    } else {
      $check_option_code = $this->check_option_code();
      if ($check_option_code == 0) {
        $this->update($this->option_line_id);
      } else {
        $this->update_except_code($this->option_line_id);
      }
      return $this->msg;
    }
  }

  private function check_option_code() {
    global $db;
    $sql = "SELECT * FROM " . self::$table_name . " where option_line_code='{$this->option_line_code}' ";
    $result_array = self::find_by_sql($sql);
    if (count($result_array) > 0) {
      $this->msg = 1;
    } else {
      $this->msg = 0;
    }
    return $this->msg;
  }

  public function create() {
    global $db;
    $sql = "INSERT INTO 
            option_line (
             `option_line_id` ,
              `option_id_l` ,
              `option_line_code` ,
              `value_l` ,
              `description_l` ,
              `efid_l` ,
              `status_l` ,
              `rev_enabled_l` ,
              `rev_number_l` ,
              `effective_start_date` ,
              `effective_end_date` ,
              `created_by_l` ,
              `creation_date_l` ,
              `last_update_by_l` ,
              `last_update_date_l`)
        VALUES ( NULL , '{$this->option_id_l}' , '{$this->option_line_code}', '{$this->value_l}', 
             '{$this->description_l}', '{$this->efid_l}', '{$this->status_l}', '{$this->rev_enabled_l}',
              '{$this->rev_number_l}', '{$this->effective_start_date}', '{$this->effective_end_date}', 
               '{$this->created_by_l}', '{$this->creation_date_l}', '{$this->last_update_by_l}', 
               '{$this->creation_date_l}' )";
    if ($db->query($sql)) {
      $this->option_line_id = $db->insert_id();
      $this->msg = 1;
    } else {
      $this->msg = 0;
    }
    return $this->msg;
  }

//end of create

  public function update($option_line_id) {
    global $db;

    $option_line_id = $db->escape_value($this->option_line_id);
    $option_line_code = $db->escape_value($this->option_line_code);
    $value_l = $db->escape_value($this->value_l);
    $description_l = $db->escape_value($this->description_l);
    $efid_l = $db->escape_value($this->efid_l);
    $status_l = $db->escape_value($this->status_l);
    $rev_enabled_l = $db->escape_value($this->rev_enabled_l);
    $rev_number_l = $db->escape_value($this->rev_number_l);
    $effective_start_date = $db->escape_value($this->effective_start_date);
    $effective_end_date = $db->escape_value($this->effective_end_date);
    $time = time();
    $last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
    $last_update_by = $_SESSION['user_name'];

    $sql = " UPDATE `option_line` SET 
            `option_line_code` = '{$option_line_code}',
            `value_l` = '{$value_l}',
            `description_l` = '{$description_l}',
            `efid_l` = '{$efid_l}',
            `status_l` = '{$status_l}',
            `rev_enabled_l` = '{$rev_enabled_l}',
            `rev_number_l` = '{$rev_number_l}',
            `effective_start_date` = '{$effective_start_date}',
            `effective_end_date` = '{$effective_end_date}' ,
            `last_update_by_l` = '{$last_update_by}',
            `last_update_date_l` = '{$last_update_date}' 
            WHERE `option_line_id` = '{$option_line_id}' ";
//      $result = mysql_query($query);
    if ($db->query($sql)) {
      $this->msg = 1;
    } else {
      $this->msg = 0;
    }
    return $this->msg;
  }

  public function update_except_code($option_line_id) {
    global $db;

    $option_line_id = $db->escape_value($this->option_line_id);
    $value_l = $db->escape_value($this->value_l);
    $description_l = $db->escape_value($this->description_l);
    $efid_l = $db->escape_value($this->efid_l);
    $status_l = $db->escape_value($this->status_l);
    $rev_enabled_l = $db->escape_value($this->rev_enabled_l);
    $rev_number_l = $db->escape_value($this->rev_number_l);
    $effective_start_date = $db->escape_value($this->effective_start_date);
    $effective_end_date = $db->escape_value($this->effective_end_date);
    $time = time();
    $last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
    $last_update_by = $_SESSION['user_name'];

    $sql = " UPDATE `option_line` SET 
            `value_l` = '{$value_l}',
            `description_l` = '{$description_l}',
            `efid_l` = '{$efid_l}',
            `status_l` = '{$status_l}',
            `rev_enabled_l` = '{$rev_enabled_l}',
            `rev_number_l` = '{$rev_number_l}',
            `effective_start_date` = '{$effective_start_date}',
            `effective_end_date` = '{$effective_end_date}' ,
            `last_update_by_l` = '{$last_update_by}',
            `last_update_date_l` = '{$last_update_date}' 
            WHERE `option_line_id` = '{$option_line_id}' ";
//      $result = mysql_query($query);
    if ($db->query($sql)) {
      $this->msg = 1;
    } else {
      $this->msg = 0;
    }
    return $this->msg;
  }

  
  public static function delete($option_line_id) {
    global $db;
    $option_line_id = $db->escape_value($option_line_id);
    $sql = "DELETE FROM `option_line` WHERE `option_line_id` = '{$option_line_id}' ";
    
     if ($db->query($sql)) {
      $msg = 1;
    } else {
      $msg = 0;
    }
    return $msg ;
  }

//end of update delete

  public static function path_menu() {
    global $db;
    $sql = "SELECT * FROM `path` WHERE `primary` = 1 ";
    $object = self::find_by_sql($sql);
    echo '<ul id="menu">';
    foreach ($object as $path) {
//     echo '<li><a class="sub" href="#x" tabindex="1"> 
//         <img src="click-slide/sales.png" alt="" />'. $path->name .'</a>
//         <img class="close" src="click-slide/trans.gif" alt="" />';
      $url = self::full_path($path->value);
      echo '<li>' . '<a href="' . $url . '">' . $path->name . '</a><ul>';
      $child_sql = "SELECT * FROM `path` WHERE `module` = '{$path->module}' ";
      if ($child_sql) {
        $child_object = self::find_by_sql($child_sql);
        foreach ($child_object as $child_path) {
          $child_url = self::full_path($child_path->value);
          echo '<li>' . '<a href="' . $child_url . '">' . $child_path->name . '</a></li>';
        }//end of child foreach
      }//end of if loop
      echo '</ul> </li>';
    }//end of main for each
    echo '</ul>';
  }

//end of path_menu

  public static function path_page() {
    echo '<table class="normal">
                <thead> 
                    <tr>
                    <th>Path Id</th>
                    <th>Name</th>
                    <th>Value</th>
                    <th>Description</th>
                    <th>Module</th>
                    <th>Primary</th>
                    <th>Created By</th>
                    <th>Creation Date</th>
                    <th>Last Updated By</th>
                    <th>Last Update Date</th>
                    <th>Action</th>
                    </tr>
                </thead>
                <tbody>';
    $path = path::find_all();
    foreach ($path as $record) {
      echo '<tr><td>' . $record->path_id . '</td>';
      echo '<td><a href=" ' . path::full_path($record->value) . '">' . $record->name . '</a>' . '</td>';
      echo '<td>' . $record->value . '</td> ';
      echo '<td>' . $record->description . '</td>';
      echo '<td>' . $record->module . '</td>';
      echo '<td>' . $record->primary . '</td>';
      echo '<td>' . $record->created_by . '</td>';
      echo '<td>' . $record->creation_date . '</td> ';
      echo '<td>' . $record->last_updated_by . '</td>';
      echo '<td>' . $record->last_updation_date . '</td>';
      echo '<td><a href="' . HOME_URL . 'extensions/path/path_update.php?pid=' . $record->path_id . '">Update</a></td></tr>';
    }
    echo ' </tbody> </table>';
  }

}

//end of path class
?>