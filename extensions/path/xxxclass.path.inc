<?php

class path {

  protected static $table_name = "path";
//  data base variables as stored database column name
  public static $field_array = [
      "path_id",
      "parent_id",
      "name",
      "value",
      "description",
      "module",
      "primary_cb",
      "created_by",
      "creation_date",
      "last_update_by",
      "last_update_date"
  ];
//variables used for showing data
   public static $checkbox_array = [
     "primary_cb",
 ];
  public static $column_array = [
      "path_id",
      "parent_id",
      "name",
      "value",
      "description",
      "module",
  ];
  public static $requiredField_array = [
      "name",
      "value",
      "module"
        ];
  public static $primary_cb_column = "path_id";
  public $path_id;
  public $parent_id;
  public $name;
  public $value;
  public $description;
  public $module;
  public $primary_cb;
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

  public static function count_all_by_sql($sql) {
    global $db;
    $result_set = $db->query($sql);
    $row = $db->fetch_array($result_set);
    return array_shift($row);
  }

  public static function count_all() {
    global $db;
    $sql = "SELECT COUNT(*) FROM " . self::$table_name;
    $result_set = $db->query($sql);
    $row = $db->fetch_array($result_set);
    return array_shift($row);
  }

  public static function find_all() {
    $sql = " SELECT * FROM " . self::$table_name;
    $result = self::find_by_sql($sql);
    return $result;
  }

  public static function find_by_id($path_id) {
    $sql = "SELECT * FROM " . self::$table_name . " where path_id={$path_id} LIMIT 1";
    $result_array = self::find_by_sql($sql);
    return !empty($result_array) ? array_shift($result_array) : false;
  }

  public static function find_by_name($name) {
    $sql = "SELECT * FROM " . self::$table_name . " where value REGEXP '{$name}$' LIMIT 1";
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

  public function save() {
    if (empty($this->path_id)) {
      $this->create();
    } else {
      $this->update($this->path_id);
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
   $this->content_id = $db->insert_id();
    $this->msg = 1;
  } else {
   $this->msg = 0;
  }
  return $this->msg;
 }

//end of create path

 public function update($path_id) {
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
  $sql.= " WHERE `path_id` = '{$path_id}' ";

//    echo "<br/>$sql is <br/>" . $sql;

  if ($db->query($sql)) {
   $this->msg = 2;
  } else {
   $this->msg = 0;
  }
  return $this->msg;
 }
  
//end of update path

  public static function path_delete($path_id) {
    global $db;
    $path_id = $db->escape_value($path_id);
//        echo '<br/>pathid : ' . $path_id . '<br/>';

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
    $sql = "SELECT * FROM `path` WHERE `primary_cb` = 1 ";
    $object = self::find_by_sql($sql);
    echo '<ul id="menu">';
    foreach ($object as $path) {
//     echo '<li><a class="sub" href="#x" tabindex="1"> 
//         <img src="click-slide/sales.png" alt="" />'. $path->name .'</a>
//         <img class="close" src="click-slide/trans.gif" alt="" />';
      $url = self::full_path($path->value);
      echo '<li>' . '<a href="' . $url . '">' . $path->name . '</a><ul>';
      $child_sql = "SELECT * FROM `path` WHERE `parent_id` = '{$path->path_id}' ";
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
                    <th>Parent</th>
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
      echo '<td>' . $record->parent_id . '</td>';
      echo '<td><a href=" ' . path::full_path($record->value) . '">' . $record->name . '</a>' . '</td>';
      echo '<td>' . $record->value . '</td> ';
      echo '<td>' . $record->description . '</td>';
      echo '<td>' . $record->module . '</td>';
      echo '<td>' . $record->primary_cb . '</td>';
      echo '<td>' . $record->created_by . '</td>';
      echo '<td>' . $record->creation_date . '</td> ';
      echo '<td>' . $record->last_updated_by . '</td>';
      echo '<td>' . $record->last_updation_date . '</td>';
      echo '<td><a href="' . HOME_URL . 'extensions/path/path.php?path_id=' . $record->path_id . '">Update</a></td></tr>';
    }

    echo ' </tbody> </table>';
  }

  public static function path_block_realted_to_module() {
    global $db;
    $r_url = trim($_SERVER['REQUEST_URI']);
    $r_url_expl = explode("/", $r_url);

    if (array_search('modules', $r_url_expl)) {
      $search = array_search('modules', $r_url_expl);
      $search++;
      $search_val = $r_url_expl[$search];
    } elseif (array_search('extensions', $r_url_expl)) {
      $search = array_search('extensions', $r_url_expl);
      $search = $search + 1;
      $search_val = $r_url_expl[$search];
    } else {
      $search_val = null;
    }

    if (!empty($search_val)) {
      $sql = "SELECT * FROM " . self::$table_name . " where value LIKE '%$search_val%' LIMIT 1";
    }

    $result = $db->query($sql);
    while ($row = $db->fetch_array($result)) {
      $module = $row['module'];
    }
//serach of paths if there is any
    if (!empty($module)) {
      echo '<div class="menu">';
      echo '<ul id="block_menu">';
      $sql = "SELECT * FROM `path` WHERE `module` = '{$module}' and parent_id='0' ";
      if ($sql) {
        $object = self::find_by_sql($sql);
        foreach ($object as $path) {
          $url = self::full_path($path->value);
          echo '<li class="parent_menu expandable">' . '<a href="' . $url . '">' . $path->name . '</a>';
          $child_sql = "SELECT * FROM `path` WHERE `parent_id` = '{$path->path_id}' ";
          $child_object = self::find_by_sql($child_sql);
          echo '<ul class="child_menu ">';
          foreach ($child_object as $child_path) {
            $child_url = self::full_path($child_path->value);
            echo '<li class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a></li>';
          }
          echo '</ul></li> ';
        }//end of child foreach
        echo '</ul> ';
        echo '</div> ';
      }
    }
//end of menu..if no path found then leave blank
  }

  public static function path_block() {
    global $db;

    echo '<div class="menu">';
    //beging of ul1
    echo '<ul id="block_menu">';
    $sql = "SELECT * FROM `path` WHERE parent_id='0' ";
    if ($sql) {
      $object = self::find_by_sql($sql);
      foreach ($object as $path) {
        $url = self::full_path($path->value);
        //begin of Li1
        echo '<li class="parent_menu expandable">' . '<a href="' . $url . '">' . $path->name . '</a>';
        //next level path values
        $child_sql = "SELECT * FROM `path` WHERE `parent_id` = '{$path->path_id}' ";
        $child_object = self::find_by_sql($child_sql);
        //beging of ul2
        echo '<ul class="child_menu">';
        if (COUNT($child_object) > 0) {
          foreach ($child_object as $child_path) {
            $child_url = self::full_path($child_path->value);
            //begin of Li2
            echo '<li class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';

            //second level menus
            $child_sql2 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
            $child_object2 = self::find_by_sql($child_sql2);
            if (COUNT($child_object2) > 0) {
              //beging of ul3
              echo '<ul>';
              foreach ($child_object2 as $child_path) {
                $child_url = self::full_path($child_path->value);
                //begin  of Li3
                echo '<li class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';

                //third level menus
                $child_sql3 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
                $child_object3 = self::find_by_sql($child_sql3);
                if (COUNT($child_object3) > 0) {
                  //beging of ul4
                  echo '<ul>';
                  foreach ($child_object3 as $child_path) {
                    $child_url = self::full_path($child_path->value);
                    //begin & end of Li4
                    echo '<li class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a></li>';
                  }
                  echo '</ul>';
                  //end of ul4
                }
                echo '</li> ';
                //end of Li3
              }
              echo '</ul>';
              //end of ul3
            }
            echo '</li> ';
            //end of Li2
          }
        }//end of child foreach
        echo '</ul>';
        //end of ul2
        echo '</li>';
        //end of Li1
      }
    }
    echo '</ul> ';
    //end of ul
    echo '</div> ';
  }

  public static function path_allpaths_block() {
    global $db;
    $allPaths = "";

    $allPaths .= '<div class="menu">';
    //beging of ul1
    $allPaths .= '<ul class="block_menu">';
    $sql = "SELECT * FROM `path` WHERE parent_id='0' ";
    if ($sql) {
      $object = self::find_by_sql($sql);
      foreach ($object as $path) {
        $url = self::full_path($path->value);
        //begin of Li1
        $allPaths .= '<li class="parent_menu expandable">' . '<a href="' . $url . '">' . $path->name . '</a>';
        //next level path values
        $child_sql = "SELECT * FROM `path` WHERE `parent_id` = '{$path->path_id}' ";
        $child_object = self::find_by_sql($child_sql);
        //beging of ul2
        $allPaths .= '<ul class="child_menu">';
        if (COUNT($child_object) > 0) {
          foreach ($child_object as $child_path) {
            $child_url = self::full_path($child_path->value);
            //begin of Li2
            $allPaths .= '<li class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';

            //second level menus
            $child_sql2 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
            $child_object2 = self::find_by_sql($child_sql2);
            if (COUNT($child_object2) > 0) {
              //beging of ul3
              $allPaths .= '<ul>';
              foreach ($child_object2 as $child_path) {
                $child_url = self::full_path($child_path->value);
                //begin  of Li3
                $allPaths .= '<li  class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a>';

                //third level menus
                $child_sql3 = "SELECT * FROM `path` WHERE `parent_id` = '{$child_path->path_id}' ";
                $child_object3 = self::find_by_sql($child_sql3);
                if (COUNT($child_object3) > 0) {
                  //beging of ul4
                  $allPaths .= '<ul>';
                  foreach ($child_object3 as $child_path) {
                    $child_url = self::full_path($child_path->value);
                    //begin & end of Li4
                    $allPaths .= '<li  class="expandable">' . '<a href="' . $child_url . '">' . $child_path->name . '</a></li>';
                  }
                  $allPaths .= '</ul>';
                  //end of ul4
                }
                $allPaths .= '</li> ';
                //end of Li3
              }
              $allPaths .= '</ul>';
              //end of ul3
            }
            $allPaths .= '</li> ';
            //end of Li2
          }
        }//end of child foreach
        $allPaths .= '</ul>';
        //end of ul2
        $allPaths .= '</li>';
        //end of Li1
      }
    }
    $allPaths .= '</ul> ';
    //end of ul
    $allPaths .= '</div> ';

    return $allPaths;
  }

//end of menu..if no path found then leave blank
//end of path class
}

?>
