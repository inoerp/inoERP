<?php
 if (preg_match('/(?i)msie [5-9]/', $_SERVER['HTTP_USER_AGENT'])) {
  echo ($_SERVER['HTTP_USER_AGENT']);
  echo "<h2>Sorry! Your browser is outdated and not compatible with this site!!!</h2> "
  . "Please use any modern browsers such as Firefox, Opera, Chrome, IE 10+ ";
  exit;
 }
 $dont_check_login = true;
?>
<?php
 if (file_exists('install.php')) {
  if (isset($_GET['install'])) {
   if ($_GET['install'] == 'done') {
    // Delete the insatll file after installation
    @unlink('install.php');
    // Redirect to main page
    header('location: index.php');
   }
  } else {
   header('location: install.php');
  }
  return;
 }
?>
<?php
 $content_class = true;
 $class_names[] = 'content';
?>
<?php include_once("includes/functions/loader.inc"); ?>
<link href="<?php echo HOME_URL; ?>themes/default/index.css" media="all" rel="stylesheet" type="text/css" />
<script src="<?php echo HOME_URL; ?>includes/js/jssor.slider.mini.js"></script>
<div id="all_contents">
 <div id="content_header">
  <div id="process_folw">
   <ul><li>
     <iframe width="480" height="270" src="//www.youtube.com/embed/AS8idx2Cg_U" frameborder="0" allowfullscreen></iframe>
    </li>
    <li class="release_message">
     <span class="longHeading">inoERP is an open source web based enterprise management system.
      It’s built using open source technologies and has a wide range of features suitable for running 
      various kind of  businesses.
     </span>
     <span class="heading">inoERP 1.0 Beta1</span>
     The first beta version of inoERP (inoERP 1.0 Beta1) - has been released. This version is fully functional
     but not yet ready for production usage. 
     <br><br>Read the release details <a href="content.php?mode=2&content_id=197&content_type_id=47"> here </a>
     <br><br>Download the beta version from  <a href="https://github.com/inoerp/inoerp_v1"> GitHub  </a>, or 
     <a href="https://sourceforge.net/projects/inoerp/"> Source Forge  </a>
    </li>
    <ul>
     </div>
     </div>

     <div id="summary_content">
        <?php
       $content = new content();
       echo $content->showfrontPage_contents(20, 500);
//		 echo page::front_page_summary(6); 
      ?>
     </div>
     <div id="content_bottom"></div>
     </div>
     <?php include_template('footer.inc') ?>
     <script type="text/javascript">
      $(document).ready(function() {
       //summar list
       var maxListCount = 6;
       var shownListCount = 0;
       $('ul.summary_list').on('click', '.remove', function() {
        $(this).closest('li').hide();
        shownListCount++;
        maxListCount++;
        update_summary_list(maxListCount, shownListCount);
       });
       update_summary_list(maxListCount, shownListCount);

      });
     </script>