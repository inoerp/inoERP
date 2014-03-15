<?php include_once("../../include/basics/header.inc"); ?>

<div id="new_search_criteria">
  <?php
  if (!empty($_GET["new_search_criteria"])) {
    $new_search_criteria = $_GET["new_search_criteria"];
     }
  ?>
  <li><label><?php echo $new_search_criteria ;?> : </label>
    <input type="search" name="<?php echo $new_search_criteria ;?>" id="<?php echo $new_search_criteria ;?>" 
           value="" 
           maxlength="50" >
  </li>
</div>

<div id="json_delete_fileds">
  <?php
  if(!empty($_GET['delete']) && $_GET['delete']==1 ){
   $content_name = $_GET['content_name'];
   $field_name = $_GET['field_name'];
 
  $result=  content::drop_column($content_name,$field_name);
  
  if ($result == 1) {
   echo 'Comment is deleted!';
  } else {
    return false;
  }
  }

  ?>
</div>

<div id="json_filed_names">
  <?php
  if(!empty($_GET['tableName']) && $_GET['get_fieldName']==1 ){
   $tableName = $_GET['tableName'];
    
  $column_names=  view::find_columns_of_table($tableName);
  
    if (count($column_names) == 0) {
    return false;
  } else {
	 echo '<Select class="table_fields">';
    foreach ($column_names as $key => $value) {
      echo '<option class="table_fields_options" value="' . $value. '"';
      echo '>' . $value. '</option>';
    }
    echo '<option value="remove" class="remove_option" >Remove Field</option>';
		echo '</select>';
  }
  
  
  }

  ?>
</div>




<?php include_template('footer.inc') ?>