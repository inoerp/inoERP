<?php
$extension = 'category';
$key_field = 'category';
//$primary_column = "category_id";
$categoryTitle = " category - Create & update content type ";
$required_field_flag = 1;
?>
<?php include_once('../../include/basics/header.inc'); ?>
<script src="category.js"></script>

<?php

$all_categories = category::all_child_categories();

if (!empty($msg)) {
 $show_message = '<div id="dialog_box">';
  foreach ($msg as $key => $value) {
   $x = $key + 1;
   $show_message .= 'Message ' . $x . ' : ' . $value . '<br />';
  }
 $show_message .= '</div>';
}

if((!empty($run_functions_after_save)) && ($run_functions_after_save == 1)){
 
      if (count($_POST['field_name']) > 0) {
       $i=0;
      foreach ($_POST['field_name'] as $records) {
       
       $field_record = new new_category;
       $field_name = trim(mysql_prep($_POST['field_name'][$i]));
       $field_type = trim(mysql_prep($_POST['field_type'][$i]));
       $field_num = trim(mysql_prep($_POST['field_num'][$i]));
       $new_category = trim(mysql_prep($_POST['category']));
       $new_fild_entry = $field_record->save_table_field($new_category, $field_name, $field_type, $field_num);
             if($new_fild_entry){
        $newMsg = 'Record is sucessfully saved';
       }
       $i++;
      }
      
     }
}

?>

<?php require_once('category_relation_template.php') ?>
