<?php
$content_class = true;
$class_names[] = 'content';
?>
<?php 
require_once __DIR__.'/includes/basics/wloader.inc';
include_once(__DIR__ . '/../inoerp_server/includes/functions/loader.inc'); ?>
<!DOCTYPE html>
<html><head>
  <link href="<?php echo THEME_URL; ?>/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>tparty/bootstrap/css/bootstrap.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>tparty/bootstrap/css/style.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>tparty/font-awesome/css/font-awesome.min.css" rel="stylesheet">
  <link href='https://fonts.googleapis.com/css?family=PT+Sans:400,400italic,700,700italic' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Lato:400,300,400italic,300italic,700,700italic,900' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Exo:400,300,600,500,400italic,700italic,800,900' rel='stylesheet' type='text/css'>
 </head>
 <body>
  <div id="all_contents">
   <div id="content_header">

   </div>

   <div id="summary_content" class="min_height_600px">
    <?php
    $content = new content();
    echo '<h1> Access denied! - You dont have enough privillage to access the requested page </h1>';
    echo '<h3><a href="' . HOME_URL . '"> Click Here to go back to home page </a></h3>';
    if (!empty($_GET['message'])) {
     echo $_GET['message'];
    }
//		 echo page::front_page_summary(6); 
    ?>
   </div>
   <div id="content_bottom"></div>
  </div>

  <?php include_template('footer.inc') ?>