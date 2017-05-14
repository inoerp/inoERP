<link href="<?php echo HOME_URL; ?>css/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />
<link href="<?php echo HOME_URL; ?>extensions/view/result/view.css" media="all" rel="stylesheet" type="text/css" />
<script>
 $(document).ready(function() {
  var scriptLink1 = "<?php echo HOME_URL; ?>extensions/view/result/view.js";
  var scriptLink2 = "<?php echo HOME_URL; ?>includes/js/reload.js";
  include_once(scriptLink1);
  include_once(scriptLink2);
 });</script>

<div class ="view_content image_only">
 <div class="draw_chart_data" class="scrollElement">
  <div class="svg_image">
   <?php echo!empty($svg_chart) ? $svg_chart : ""; ?>
  </div>
  <a class='more_page button' href="<?php echo HOME_URL.$$class->path; ?>">View Details</a>
 </div>
</div>
