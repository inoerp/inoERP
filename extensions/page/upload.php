<?php
include_once("../../include/basics/header.inc");
echo 'created by'.$_SESSION['user_name'];
?>
<div id="structure">
 <h2>Page Upload</h2>
 <?php
 if (!empty($_POST['attach_submit'])) {

  if (isset($_FILES['attachments'])) {
   $errors = array();
   $uploaded_file_ids = array();
   $file = new file();

   foreach ($_FILES['attachments']['tmp_name'] as $key => $tmp_name) {
    $date = new DateTime();

    $file_name = $key . '_' . $date->getTimestamp() . '_' . $_FILES['attachments']['name'][$key];
    $file_size = $_FILES['attachments']['size'][$key];
    $file_tmp = $_FILES['attachments']['tmp_name'][$key];
    $file_type = $_FILES['attachments']['type'][$key];
    if ($file_size > $file::MAX_SIZE) {
     $errors[] = 'File size must be less than 2 MB';
    }

//        $query="INSERT into upload_data 
//         (`USER_ID`,`FILE_NAME`,`FILE_SIZE`,`FILE_TYPE`) 
//         VALUES('$user_id','$file_name','$file_size','$file_type'); ";
    $file_dir = HOME_DIR."/files";
    $file_path= HOME_URL."files" ;
    if (empty($errors) == true) {
     if (is_dir($file_dir) == false) {
      mkdir("$file_dir", 0700);  // Create directory if it does not exist
     }
     if (is_dir("$file_dir/" . $file_name) == false) {
      if (move_uploaded_file($file_tmp, "$file_dir/" . $file_name)) {
       
       $file->file_name = $file_name;
       $file->file_size = $file_size;
       $file->file_type = $file_type;
       $time = time();
       $file->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
       $file->created_by = $_SESSION['user_name'];
       $file->last_update_date = $file->creation_date;
       $file->last_update_by = $file->created_by;
       $new_entry=$file->save();
       if($new_entry==1){
       $msg = "File is sucessfully uploaded!";
       array_push($uploaded_file_ids, $file->file_id);
       }else{
        $msg = "File is sucessfully uploaded but record cldnt saved in database";
       }
      }
     } else {         //rename the file if another one exist
      $new_dir = "$file_dir/" . $file_name . time();
      rename($file_tmp, $new_dir);
     }
//            mysql_query($query);			
    } else {
     print_r($errors);
    }
   }
   if (empty($error)) {
    echo "$msg";
    foreach ($uploaded_file_ids as $keys => $values) {
     $file = file::find_by_id($values);
     echo '<br/>' . $values . ' is  <a href='."$file_path/". $file->file_name.'>'.$file->file_name.'</a>';
    }
   }
  }
 } else {
  echo '<br/> No Post';
 }
 ?>
 <form action=" "  method="post" id="page_header"  name="page_header" ENCTYPE="multipart/form-data">
  <div id="add_attachments"><label>Attachments : </label>
   <input type="file" id="attachments" class="attachments" name="attachments[]" multiple/>

  </div>
  <input type="text" name="file_name" />
  <input type="submit" value="attach" form="page_header" name="attach_submit">

 </form>

</div>

<?php
execution_time();
include_template('footer.inc')
?>


