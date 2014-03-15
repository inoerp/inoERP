<?php include_once("../../include/basics/header.inc"); ?>

<div id="json_remove_category_content_type">
  <?php
  if(!empty($_GET['delete']) && $_GET['delete']==1 ){
   $category_id = $_GET['category_id'];
   $content_type_id = $_GET['content_type_id'];
 
   $check_category = category::find_by_category_categoryreference_table_and_id($category_id, 'content_type', $content_type_id);
   $category_reference_id= $check_category->category_reference_id;
  $result= category_reference::delete($category_reference_id);
  
  if ($result == 1) {
   echo 'Category is removed!';
  } else {
    echo " Error code: $result ! ";
  }
  }

  ?>
</div>

<div id="json_locator">
  <?php
  if(!empty($_GET['subinventory_id'])){
   $subinventory_id = $_GET['subinventory_id'];
  $locator_of_org = locator::find_all_of_subinventory($subinventory_id) ;

  if (count($locator_of_org) == 0) {
    return false;
  } else {
    foreach ($locator_of_org as $key => $value) {
      echo '<option value="' . $value->locator_id . '"';
      echo '>' . $value->locator . '</option>';
    }
  }
  }

  ?>
</div>

<?php include_template('footer.inc') ?>