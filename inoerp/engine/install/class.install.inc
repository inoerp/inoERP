<?php
class install{
    protected static $table_name="install";
    public $path_id ;
    public $name ;
    public $value ;
    public $description ;
    public $module ;
    public $primary ;
    public $created_by ;
    public $creation_date ;
    public $last_updated_by ;
    public $last_updation_date ;
    public $time;
    public static $dir = __DIR__;

    public static function find_by_sql($sql="")
     {
       global $db;  
       $result_set= $db->query($sql);
       $object_array = array();
       while ($row = $db->fetch_array($result_set))
        {
         $object_array[]=  self::instantiate($row);
        }//end of while Loop
       return $object_array;
     }
     
     public static function find_all()
     {
       $sql =" SELECT * FROM " . self::$table_name;
       $result= self::find_by_sql($sql);
       return $result;
     }
     
     public static function find_by_id($path_id)
     {
       global $db;  
       $sql ="SELECT * FROM ". self::$table_name ." where path_id={$path_id} LIMIT 1";
       $result_array= self::find_by_sql($sql);
       return !empty($result_array) ? array_shift($result_array) : false;
     }
     
    private static function instantiate($record){
        $object = new self;
        foreach ($record as $attribute=>$value){
                if($object->has_attribute($attribute)){
                    $object->$attribute = $value;
                }
            }
        return $object;
    }
    
    Private function has_attribute($attribute){
        $object_vars = get_object_vars($this);
        return array_key_exists($attribute,$object_vars);
    }
    
    public function create_path(){
     global $db;
//     $this->name = $db->escape_value($name);
//     $this->value = $db->escape_value($value);
//     $this->description = $db->escape_value($description);
//     $this->module = $db->escape_value($module);
//     $this->time=time();
//     $this->creation_time = strftime("%d-%m-%y %H:%M:%S", $time) ;
//     $this->created_by = $_SESSION['user_name'];
     
     $sql= " INSERT INTO path (
        `path_id` ,
        `name` ,
        `value` ,
        `description` ,
        `module` ,
        `primary` ,
        `created_by` ,
        `creation_date` ,
        `last_updated_by` ,
        `last_updation_date` ,
        `TBU`
        )
        VALUES (
        NULL , '{$this->name}', '{$this->value}', '{$this->description}', 
            '{$this->module}', '{$this->primary}', '{$this->created_by}', '{$this->creation_time}',
                '{$this->created_by}', '{$this->creation_time}', NULL )";
//      $result = mysql_query($query);
     if($db->query($sql)){
         $this->path_id=$db->insert_id();
         return true;
        }else{
            return false;
        }
    }//end of create path
    
     public function path_update($path_id,$name,$value,$description,$module,$primary){
     global $db;
     $path_id = $db->escape_value($path_id);
     $name = $db->escape_value($name);
     $value = $db->escape_value($value);
     $description = $db->escape_value($description);
     $module = $db->escape_value($module);
     $time=time();
     $update_time = strftime("%d-%m-%y %H:%M:%S", $time) ;
     $updated_by = $_SESSION['user_name'];
     
      $sql= " UPDATE path SET
            `name` = '{$name}' ,
            `value` = '{$value}' ,
            `description` = '{$description}' ,
            `module` = '{$module}' ,
            `primary` = '{$primary}' ,
            `last_updated_by` = '{$updated_by}' ,
            `last_updation_date` = '{$update_time}' 
             WHERE  `path_id` = '{$path_id}' ";
//      $result = mysql_query($query);
     if($db->query($sql)){
           return true;
        }else{
            return false;
        }
    }//end of update path
   
    public function path_delete($path_id) {
     global $db;
     $path_id = $db->escape_value($path_id);
     echo '<br/>pathid : '. $path_id . '<br/>';
         
      $sql= "DELETE FROM `path` WHERE `path_id` = '{$path_id}' ";
//      $result = mysql_query($query);
     if($db->query($sql)){
           return true;
        }else{
            return false;
        }
    }//end of update delete
    
    public static function path_menu() {
     global $db;
     $sql= "SELECT * FROM `path` WHERE `primary` = 1 ";
     $object= self::find_by_sql($sql);
     echo '<ul id="menu">';
      foreach( $object as $path){
//     echo '<li><a class="sub" href="#x" tabindex="1"> 
//         <img src="click-slide/sales.png" alt="" />'. $path->name .'</a>
//         <img class="close" src="click-slide/trans.gif" alt="" />';
          $url = self::full_path($path->value);
          echo '<li>'.'<a href="'. $url .'">'.$path->name.'</a><ul>';
          $child_sql= "SELECT * FROM `path` WHERE `module` = '{$path->module}' ";
              if($child_sql){
                  $child_object= self::find_by_sql($child_sql);
                  foreach( $child_object as $child_path){
                  $child_url = self::full_path($child_path->value);
                  echo '<li>'.'<a href="'. $child_url .'">'.$child_path->name.'</a></li>';
              }//end of child foreach
             
          }//end of if loop
          echo '</ul> </li>';
          
      }//end of main for each
      echo '</ul>';
    }//end of path_menu
    
    public static function path_page(){
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
                <tbody>' ;
             
             $path = path::find_all();
              foreach($path as $record){
               echo '<tr><td>'. $record->path_id. '</td>';
               echo '<td><a href=" '. path::full_path($record->value). '">'.$record->name .'</a>' .'</td>';
               echo '<td>'. $record->value . '</td> ';
               echo '<td>'. $record->description . '</td>';
               echo '<td>'. $record->module . '</td>';
               echo '<td>'. $record->primary . '</td>';
               echo '<td>'. $record->created_by . '</td>';
               echo '<td>'. $record->creation_date . '</td> ';
               echo '<td>'. $record->last_updated_by . '</td>';
               echo '<td>'. $record->last_updation_date . '</td>';
               echo '<td><a href="'.HOME_URL.'extensions/path/path_update.php?pid='. $record->path_id .'">Update</a></td></tr>'  ;
               }
               
               echo ' </tbody> </table>';
           
    }
    
} //end of path class



?>
