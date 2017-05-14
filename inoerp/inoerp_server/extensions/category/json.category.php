<?php include_once("../../includes/basics/basics.inc"); ?>

<div id="json_remove_category_content_type">
 <?php
 if (!empty($_GET['delete']) && $_GET['delete'] == 1) {
  if (!empty($_GET['category_id'])) {
   $category_id = $_GET['category_id'];
  } else {
   return '<br>' . gettext('No Category Selected');
  }
  $content_type_id = $_GET['content_type_id'];

  $check_category = category::find_by_category_categoryreference_table_and_id($category_id, 'content_type', $content_type_id);
  $category_reference_id = $check_category->category_reference_id;
  $cr = new category_reference();
  $cr->category_reference_id = $check_category->category_reference_id;
  $result = $cr->delete();

  if ($result == 1) {
   echo '<div>' . gettext('Category is removed!') . '</div>';
  } else {
   echo " <div>Error code: $result ! </div>";
  }
 }
 ?>
</div>

<?php include_template('footer.inc') ?>
