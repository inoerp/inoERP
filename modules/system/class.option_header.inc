<?php

class option_header {

  protected static $table_name = "option_header";
  public $option_id;
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

  public static function full_path($value) {
    if ($value) {
      return HOME_URL . $value;
    } else {
      return "";
    }
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

  public static function find_by_id($option_id) {
    global $db;
    $sql = "SELECT * FROM " . self::$table_name . " where option_id={$option_id} LIMIT 1";
    $result_array = self::find_by_sql($sql);
    return !empty($result_array) ? array_shift($result_array) : false;
  }
  
    public static function find_by_name($option_types) {
    global $db;
    $sql = "SELECT * FROM " . self::$table_name . " where option_type='{$option_types}' LIMIT 1";
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
    if (empty($this->option_id)) {
      $check_option_type = $this->check_option_type();
      if ($check_option_type==0){
        $this->create();
      }else{
        $this->msg = "Option type already exists";
      }
        return $this->msg;
    } else {
      $this->update($this->option_id);
      return $this->msg;
    }
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
    $sql_header = "INSERT INTO 
                option_header (
                `option_id`,
                `option_type`,
                `access_level`,
                `description`,
                `module`,
                `efid`,
                `status`,
                `rev_enabled`,
                `rev_number`,
                `created_by`,
                `creation_date`,
                `last_update_by`,
                `last_update_date`)
        VALUES ( NULL , '{$this->option_type}', '{$this->access_level}', '{$this->description}', 
            '{$this->module}', '{$this->efid}', '{$this->status}', '{$this->rev_enabled}', 
              '{$this->rev_number}', '{$this->created_by}', '{$this->creation_date}',
                '{$this->created_by}', '{$this->creation_date}' )";

    if ($db->query($sql_header)) {
      $this->option_id = $db->insert_id();
      $this->msg = 1;
    } else {
      $this->msg = 0;
    }

    return $this->msg;
  }

//end of create

  public function update($option_id) {
    global $db;
    $option_id = $db->escape_value($this->option_id);
    $description = $db->escape_value($this->description);
    $module = $db->escape_value($this->module);
    $efid = $db->escape_value($this->efid);
    $status = $db->escape_value($this->status);
    $rev_enabled = $db->escape_value($this->rev_enabled);
    $rev_number = $db->escape_value($this->rev_number);
    $time = time();
    $last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
    $last_update_by = $_SESSION['user_name'];

    $sql = " UPDATE `option_header` SET 
          `description` = '{$description}',
          `module` = '{$module}',
          `efid` = '{$efid}',
          `status` = '{$status}',
          `rev_enabled` = '{$rev_enabled}',
          `rev_number` = '{$rev_number}',
          `last_update_by` = '{$last_update_by}',
          `last_update_date` = '{$last_update_date}' 
          WHERE `option_id` = '{$option_id}' ";
//      $result = mysql_query($query);
    if ($db->query($sql)) {
      $this->msg = 1;
    } else {
      $this->msg = 0;
    }

    return $this->msg;
  }

//end of update path

  public function path_delete($path_id) {
    global $db;
    $path_id = $db->escape_value($path_id);
    echo '<br/>pathid : ' . $path_id . '<br/>';

    $sql = "DELETE FROM `path` WHERE `path_id` = '{$path_id}' ";
//      $result = mysql_query($query);
    if ($db->query($sql)) {
      return true;
    } else {
      return false;
    }
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
