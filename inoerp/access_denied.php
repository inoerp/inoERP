<?php
$content_class = true;
$class_names[] = 'content';
?>
<?php include_once("includes/functions/loader.inc"); ?>
<link href="<?php echo HOME_URL; ?>themes/default/index.css" media="all" rel="stylesheet" type="text/css" />
<script src="<?php echo HOME_URL; ?>includes/js/jssor.slider.mini.js"></script>
<div id="all_contents">
 <div id="content_header">

 </div>

 <div id="summary_content">
  <?php
  $content = new content();
  echo '<h1> Access denied! - You dont have enough privillage to access the requested page </h1>';
  if(!empty($_GET['message'])){
   echo $_GET['message'];
  }
//		 echo page::front_page_summary(6); 
  ?>
 </div>
 <div id="content_bottom"></div>
</div>
<?php include_template('footer.inc') ?>