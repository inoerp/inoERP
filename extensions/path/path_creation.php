<?php include_once('../../include/basics/header.inc'); ?>
<script src="path.js"></script>

<?php 
$path = new path();
$path->parent_id = "";
$path->name = "";
$path->value = "";
$path->description = "" ;
$path->module = "";
$msg="";
?>
<?php 
if(!empty($_POST['submit'])){
    $path = new path();
    $path->name =trim(mysql_prep($_POST['name']));
    $path->parent_id =trim(mysql_prep($_POST['parent_id']));
    $path->value =trim(mysql_prep($_POST['value']));
    $path->description =trim(mysql_prep($_POST['description']));
    $path->module =trim(mysql_prep($_POST['module']));
    $path->primary =trim(mysql_prep($_POST['primary']));
    $path->time=time();
    $path->creation_time = strftime("%d-%m-%y %H:%M:%S", $path->time) ;
    $path->created_by = $_SESSION['user_name'];
    

    if (empty($path->name) || empty($path->value) || empty($path->description) || empty($path->module)){
        $msg ="Name, Value, Description or module is empty";
      } else{
                $new_path_entry = $path->create_path();
                if($new_path_entry){
                    $msg = "Path is sucessfully entered";
                    echo 'Path Name is : '.$path->name;
                    echo 'Path Value is : '.$path->value;
                }//end of path entry & msg
                else{
                    $msg = "Path coundt be saved!!".mysql_error();
                }//end of path insertion else
        }//end of path check & new path creation

}//end of post

  echo '<span id="sucessfull">' . $msg .'</span>';  
?>

<div id="structure">
    <div id="path">
        <h2>New Path Entry! </h2>
        <form action="path_creation.php" method="post" id="pah_reg" size="30" name="path_reg" value="save">
        
            <!--    Place for showing error messages-->
        <span id="formerror" class="error"> </span>
        <!--    End of place for showing error messages-->
        
           <ul class="none">
               <li><label>Parent Name :</label> 
               <select name="parent_id" id="parent_id"> 
                    <option value="" ></option> 
                    <?php
                    $parent=path::find_all();
                    foreach ($parent as $record) {
                        echo '<option value="'.$record->path_id . '" ';
                        echo $record->path_id == $path->parent_id ? 'selected' : 'none ';
                        echo '>'.$record->name.'</option>';
                    }
                    ?> 
               </select> 
               </li>
               <li><label>Path Name :</label> 
               <input type="text" required name="name" id="email" maxlength="60" size="60"
                placeholder="Enter a valid path" value="<?php echo htmlentities($path->name); ?>">
               </li>
               <li><label>Path Value :</label>  
               <input type="text" required name="value" maxlength="60" id="value" size="60" 
                    placeholder="Enter path relative to site home" value="<?php echo htmlentities($path->value); ?>">
               <!--validation message place for username-->
               </li>
               <li><label>Description  : </label> 
               <input type="text" required name="description" maxlength="100" id="description" size="60" 
                     placeholder="Enter path descrip. Limit 100 characters" value="<?php echo htmlentities($path->description); ?>">
               </li>
               <li><label>Module : </label>
                  <Select name="module" id="module"> 
                    <option value="" ></option>   
                    <?php $module= module::find_all(); 
                      foreach ($module as $record){
                        echo '<option value="'.$record->module_id . '" ';
                        echo $record->module_id == $path->module ? 'selected' : 'none ';
                        echo '>'.$record->name.'</option>';
                      }
                     ?>
                                                 
                  </select>
                </li>
                <li><label>Primary  : </label> 
                    <Select name="primary" id="primary"> 
                       <option value=" "></option>
                        <option value="0">No</option>
                        <option value="1">Yes</option>
                    </select>
                 </li>
                                                
           </ul>
           <p> <input type="submit"  name="submit" class="button" value="Create New Path">
            
        </form>
        <script src="user.js"></script>   
        
    </div>
  </div>

<?php include_template('footer.inc') ?>