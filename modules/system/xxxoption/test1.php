<?php include_once("option.inc"); ?>

<div id="structure">

  <?php
  if(!empty($_POST['id'])){
    $id = $_POST['id'];
  }
  else {
    $id = 55;
  }
  $option = option_header::find_by_id("$id");
    
//  print json_encode($option);
  
  echo '<pre>';
  print_r($option);
  echo '<pre>';
  echo 'The id is retuned as' . $id;
  ?>   

</div>
<!--   end of structure-->

<?php include_template('footer.inc') ?>
