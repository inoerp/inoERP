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
     <div id="slider1_container" style="position: relative; width: 600px;
          height: 300px; overflow: hidden;">

      <!-- Loading Screen -->
      <div u="loading" style="position: absolute; top: 0px; left: 0px;">
       <div style="filter: alpha(opacity=70); opacity:0.7; position: absolute; display: block;
            background-color: #000; top: 0px; left: 0px;width: 100%;height:100%;">
       </div>
       <div style="position: absolute; display: block; background: url(files/images/loading.gif) no-repeat center center;
            top: 0px; left: 0px;width: 100%;height:100%;">
       </div>
      </div>

      <!-- Slides Container -->
      <div u="slides" style="cursor: move; position: absolute; left: 0px; top: 0px; width: 600px; height: 300px;
           overflow: hidden;">
       <div>
        <a u=image href="#"><img src="files/images/landscape/simple_ui.gif" /></a>
        <div u=caption t="*" class="captionOrange"  style="position:absolute; left:20px; top: 30px; width:300px; height:30px;"> 
         Simple & Consistent User Interface
        </div>
       </div>
       <div>
        <a u=image href="#"><img src="files/images/landscape/easy_navigation.gif" /></a>
        <div u=caption t="*" class="captionOrange"  style="position:absolute; left:20px; top: 30px; width:300px; height:30px;"> 
         Easy Navigation - Laptop, Tablet & Mobile
        </div>
       </div>
       <div>
        <a u=image href="#"><img src="files/images/landscape/dynamic_search.gif" /></a>
        <div u=caption t="*" class="captionOrange"  style="position:absolute; left:20px; top: 30px; width:300px; height:30px;"> 
         Powerful & Dynamic Searching Capabilities
        </div>
       </div>
       <div>
        <a u=image href="#"><img src="files/images/landscape/graphical_reports.gif" /></a>
        <div u=caption t="*" class="captionOrange"  style="position:absolute; left:20px; top: 30px; width:300px; height:30px;"> 
         Text & Visual Reporting
        </div>
       </div>
      </div>

      <!-- Bullet Navigator Skin Begin -->
      <!-- jssor slider bullet navigator skin 01 -->
      <style>
       /*
       .jssorb01 div           (normal)
       .jssorb01 div:hover     (normal mouseover)
       .jssorb01 .av           (active)
       .jssorb01 .av:hover     (active mouseover)
       .jssorb01 .dn           (mousedown)
       */
       .jssorb01 div, .jssorb01 div:hover, .jssorb01 .av
       {
        filter: alpha(opacity=70);
        opacity: .7;
        overflow:hidden;
        cursor: pointer;
        border: #000 1px solid;
       }
       .jssorb01 div { background-color: gray; }
       .jssorb01 div:hover, .jssorb01 .av:hover { background-color: #d3d3d3; }
       .jssorb01 .av { background-color: #fff; }
       .jssorb01 .dn, .jssorb01 .dn:hover { background-color: #555555; }
      </style>
      <!-- bullet navigator container -->
      <div u="navigator" class="jssorb01" style="position: absolute; bottom: 16px; right: 10px;">
       <!-- bullet navigator item prototype -->
       <div u="prototype" style="POSITION: absolute; WIDTH: 12px; HEIGHT: 12px;"></div>
      </div>
      <!-- Bullet Navigator Skin End -->

      <!-- Arrow Navigator Skin Begin -->
      <style>
       /* jssor slider arrow navigator skin 05 css */
       /*
       .jssora05l              (normal)
       .jssora05r              (normal)
       .jssora05l:hover        (normal mouseover)
       .jssora05r:hover        (normal mouseover)
       .jssora05ldn            (mousedown)
       .jssora05rdn            (mousedown)
       */
       .jssora05l, .jssora05r, .jssora05ldn, .jssora05rdn
       {
        position: absolute;
        cursor: pointer;
        display: block;
        background: url(files/images/a17.png) no-repeat;
        overflow:hidden;
       }
       .jssora05l { background-position: -10px -40px; }
       .jssora05r { background-position: -70px -40px; }
       .jssora05l:hover { background-position: -130px -40px; }
       .jssora05r:hover { background-position: -190px -40px; }
       .jssora05ldn { background-position: -250px -40px; }
       .jssora05rdn { background-position: -310px -40px; }
      </style>
      <!-- Arrow Left -->
      <span u="arrowleft" class="jssora05l" style="width: 40px; height: 40px; top: 123px; left: 8px;">
      </span>
      <!-- Arrow Right -->
      <span u="arrowright" class="jssora05r" style="width: 40px; height: 40px; top: 123px; right: 8px">
      </span>

     </div>
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

     <script>
      jQuery(document).ready(function($) {
       var _SlideshowTransitions = [
        //["Rotate Overlap"]
        {$Duration: 1200, $Zoom: 11, $Rotate: -1, $Easing: {$Zoom: $JssorEasing$.$EaseInQuad, $Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInQuad}, $Opacity: 2, $Round: {$Rotate: 0.5}, $Brother: {$Duration: 1200, $Zoom: 1, $Rotate: 1, $Easing: $JssorEasing$.$EaseSwing, $Opacity: 2, $Round: {$Rotate: 0.5}, $Shift: 90}}
        //["Switch"]
        , {$Duration: 1400, $Zoom: 1.5, $FlyDirection: 1, $Easing: {$Left: $JssorEasing$.$EaseInWave, $Zoom: $JssorEasing$.$EaseInSine}, $ScaleHorizontal: 0.25, $Opacity: 2, $ZIndex: -10, $Brother: {$Duration: 1400, $Zoom: 1.5, $FlyDirection: 2, $Easing: {$Left: $JssorEasing$.$EaseInWave, $Zoom: $JssorEasing$.$EaseInSine}, $ScaleHorizontal: 0.25, $Opacity: 2, $ZIndex: -10}}
        //["Rotate Relay"]
        , {$Duration: 1200, $Zoom: 11, $Rotate: 1, $Easing: {$Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInQuad}, $Opacity: 2, $Round: {$Rotate: 1}, $ZIndex: -10, $Brother: {$Duration: 1200, $Zoom: 11, $Rotate: -1, $Easing: {$Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInQuad}, $Opacity: 2, $Round: {$Rotate: 1}, $ZIndex: -10, $Shift: 600}}
        //["Doors"]
        , {$Duration: 1500, $Cols: 2, $FlyDirection: 1, $ChessMode: {$Column: 3}, $Easing: {$Left: $JssorEasing$.$EaseInOutCubic}, $ScaleHorizontal: 0.5, $Opacity: 2, $Brother: {$Duration: 1500, $Opacity: 2}}
        //["Rotate in+ out-"]
        , {$Duration: 1500, $Zoom: 1, $Rotate: 0.1, $During: {$Left: [0.6, 0.4], $Top: [0.6, 0.4], $Rotate: [0.6, 0.4], $Zoom: [0.6, 0.4]}, $FlyDirection: 6, $Easing: {$Left: $JssorEasing$.$EaseInQuad, $Top: $JssorEasing$.$EaseInQuad, $Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInQuad}, $ScaleHorizontal: 0.3, $ScaleVertical: 0.5, $Opacity: 2, $Brother: {$Duration: 1000, $Zoom: 11, $Rotate: -0.5, $Easing: {$Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInQuad}, $Opacity: 2, $Shift: 200}}
        //["Fly Twins"]
        , {$Duration: 1500, $During: {$Left: [0.6, 0.4]}, $FlyDirection: 1, $Easing: {$Left: $JssorEasing$.$EaseInQuad, $Opacity: $JssorEasing$.$EaseLinear}, $ScaleHorizontal: 0.3, $Opacity: 2, $Outside: true, $Brother: {$Duration: 1000, $FlyDirection: 2, $Easing: {$Left: $JssorEasing$.$EaseInQuad, $Opacity: $JssorEasing$.$EaseLinear}, $ScaleHorizontal: 0.3, $Opacity: 2}}
        //["Rotate in- out+"]
        , {$Duration: 1500, $Zoom: 11, $Rotate: 0.5, $During: {$Left: [0.4, 0.6], $Top: [0.4, 0.6], $Rotate: [0.4, 0.6], $Zoom: [0.4, 0.6]}, $Easing: {$Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInQuad}, $ScaleHorizontal: 0.3, $ScaleVertical: 0.5, $Opacity: 2, $Brother: {$Duration: 1000, $Zoom: 1, $Rotate: -0.5, $Easing: {$Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInQuad}, $Opacity: 2, $Shift: 200}}
        //["Rotate Axis up overlap"]
        , {$Duration: 1200, $Rotate: -0.1, $FlyDirection: 5, $Easing: {$Left: $JssorEasing$.$EaseInQuad, $Top: $JssorEasing$.$EaseInQuad, $Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInQuad}, $ScaleHorizontal: 0.25, $ScaleVertical: 0.5, $Opacity: 2, $Brother: {$Duration: 1200, $Rotate: 0.1, $FlyDirection: 10, $Easing: {$Left: $JssorEasing$.$EaseInQuad, $Top: $JssorEasing$.$EaseInQuad, $Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInQuad}, $ScaleHorizontal: 0.1, $ScaleVertical: 0.7, $Opacity: 2}}
        //["Chess Replace TB"]
        , {$Duration: 1600, $Rows: 2, $FlyDirection: 1, $ChessMode: {$Row: 3}, $Easing: {$Left: $JssorEasing$.$EaseInOutQuart, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2, $Brother: {$Duration: 1600, $Rows: 2, $FlyDirection: 2, $ChessMode: {$Row: 3}, $Easing: {$Left: $JssorEasing$.$EaseInOutQuart, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2}}
        //["Chess Replace LR"]
        , {$Duration: 1600, $Cols: 2, $FlyDirection: 8, $ChessMode: {$Column: 12}, $Easing: {$Top: $JssorEasing$.$EaseInOutQuart, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2, $Brother: {$Duration: 1600, $Cols: 2, $FlyDirection: 4, $ChessMode: {$Column: 12}, $Easing: {$Top: $JssorEasing$.$EaseInOutQuart, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2}}
        //["Shift TB"]
        , {$Duration: 1200, $FlyDirection: 4, $Easing: {$Top: $JssorEasing$.$EaseInOutQuart, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2, $Brother: {$Duration: 1200, $FlyDirection: 8, $Easing: {$Top: $JssorEasing$.$EaseInOutQuart, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2}}
        //["Shift LR"]
        , {$Duration: 1200, $FlyDirection: 1, $Easing: {$Left: $JssorEasing$.$EaseInOutQuart, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2, $Brother: {$Duration: 1200, $FlyDirection: 2, $Easing: {$Left: $JssorEasing$.$EaseInOutQuart, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2}}
        //["Return TB"]
        , {$Duration: 1200, $FlyDirection: 8, $Easing: {$Top: $JssorEasing$.$EaseInOutQuart, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2, $ZIndex: -10, $Brother: {$Duration: 1200, $FlyDirection: 8, $Easing: {$Top: $JssorEasing$.$EaseInOutQuart, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2, $ZIndex: -10, $Shift: -100}}
        //["Return LR"]
        , {$Duration: 1200, $Delay: 40, $Cols: 6, $FlyDirection: 1, $Formation: $JssorSlideshowFormations$.$FormationStraight, $Easing: {$Left: $JssorEasing$.$EaseInOutQuart, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2, $ZIndex: -10, $Brother: {$Duration: 1200, $Delay: 40, $Cols: 6, $FlyDirection: 1, $Formation: $JssorSlideshowFormations$.$FormationStraight, $Easing: {$Top: $JssorEasing$.$EaseInOutQuart, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2, $ZIndex: -10, $Shift: -100}}
        //["Rotate Axis down"]
        , {$Duration: 1500, $Rotate: 0.1, $During: {$Left: [0.6, 0.4], $Top: [0.6, 0.4], $Rotate: [0.6, 0.4]}, $FlyDirection: 10, $Easing: {$Left: $JssorEasing$.$EaseInQuad, $Top: $JssorEasing$.$EaseInQuad, $Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInQuad}, $ScaleHorizontal: 0.1, $ScaleVertical: 0.7, $Opacity: 2, $Brother: {$Duration: 1000, $Rotate: -0.1, $FlyDirection: 5, $Easing: {$Left: $JssorEasing$.$EaseInQuad, $Top: $JssorEasing$.$EaseInQuad, $Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInQuad}, $ScaleHorizontal: 0.2, $ScaleVertical: 0.5, $Opacity: 2}}
        //["Extrude Replace"]
        , {$Duration: 1600, $Delay: 40, $Cols: 12, $During: {$Left: [0.4, 0.6]}, $SlideOut: true, $FlyDirection: 2, $Formation: $JssorSlideshowFormations$.$FormationStraight, $Assembly: 260, $Easing: {$Left: $JssorEasing$.$EaseInOutExpo, $Opacity: $JssorEasing$.$EaseInOutQuad}, $ScaleHorizontal: 0.2, $Opacity: 2, $Outside: true, $Round: {$Top: 0.5}, $Brother: {$Duration: 1000, $Delay: 40, $Cols: 12, $FlyDirection: 1, $Formation: $JssorSlideshowFormations$.$FormationStraight, $Assembly: 1028, $Easing: {$Left: $JssorEasing$.$EaseInOutExpo, $Opacity: $JssorEasing$.$EaseInOutQuad}, $ScaleHorizontal: 0.2, $Opacity: 2, $Round: {$Top: 0.5}}}
       ];

       var _CaptionTransitions = [
        //CLIP|LR
        {$Duration: 900, $Clip: 3, $Easing: $JssorEasing$.$EaseInOutCubic},
        //CLIP|TB
        {$Duration: 900, $Clip: 12, $Easing: $JssorEasing$.$EaseInOutCubic},
        //DDGDANCE|LB
        {$Duration: 1800, $Zoom: 1, $FlyDirection: 9, $Easing: {$Left: $JssorEasing$.$EaseInJump, $Top: $JssorEasing$.$EaseInJump, $Zoom: $JssorEasing$.$EaseOutQuad}, $ScaleHorizontal: 0.3, $ScaleVertical: 0.3, $Opacity: 2, $During: {$Left: [0, 0.8], $Top: [0, 0.8]}, $Round: {$Left: 0.8, $Top: 2.5}},
        //DDGDANCE|RB
        {$Duration: 1800, $Zoom: 1, $FlyDirection: 10, $Easing: {$Left: $JssorEasing$.$EaseInJump, $Top: $JssorEasing$.$EaseInJump, $Zoom: $JssorEasing$.$EaseOutQuad}, $ScaleHorizontal: 0.3, $ScaleVertical: 0.3, $Opacity: 2, $During: {$Left: [0, 0.8], $Top: [0, 0.8]}, $Round: {$Left: 0.8, $Top: 2.5}},
        //TORTUOUS|HL
        {$Duration: 1500, $Zoom: 1, $FlyDirection: 1, $Easing: {$Left: $JssorEasing$.$EaseOutWave, $Zoom: $JssorEasing$.$EaseOutCubic}, $ScaleHorizontal: 0.2, $Opacity: 2, $During: {$Left: [0, 0.7]}, $Round: {$Left: 1.3}},
        //TORTUOUS|VB
        {$Duration: 1500, $Zoom: 1, $FlyDirection: 8, $Easing: {$Top: $JssorEasing$.$EaseOutWave, $Zoom: $JssorEasing$.$EaseOutCubic}, $ScaleVertical: 0.2, $Opacity: 2, $During: {$Top: [0, 0.7]}, $Round: {$Top: 1.3}},
        //ZMF|10
        {$Duration: 600, $Zoom: 11, $Easing: {$Zoom: $JssorEasing$.$EaseInExpo, $Opacity: $JssorEasing$.$EaseLinear}, $Opacity: 2},
        //ZML|R
        {$Duration: 600, $Zoom: 11, $FlyDirection: 2, $Easing: {$Left: $JssorEasing$.$EaseInCubic, $Zoom: $JssorEasing$.$EaseInCubic}, $ScaleHorizontal: 0.6, $Opacity: 2},
        //ZML|B
        {$Duration: 600, $Zoom: 11, $FlyDirection: 8, $Easing: {$Top: $JssorEasing$.$EaseInCubic, $Zoom: $JssorEasing$.$EaseInCubic}, $ScaleVertical: 0.6, $Opacity: 2},
        //ZMS|B
        {$Duration: 700, $Zoom: 1, $FlyDirection: 8, $Easing: {$Top: $JssorEasing$.$EaseInCubic, $Zoom: $JssorEasing$.$EaseInCubic}, $ScaleVertical: 0.6, $Opacity: 2},
        //ZM*JDN|LB
        {$Duration: 1200, $Zoom: 11, $FlyDirection: 9, $Easing: {$Left: $JssorEasing$.$EaseLinear, $Top: $JssorEasing$.$EaseOutCubic, $Zoom: $JssorEasing$.$EaseInCubic}, $ScaleHorizontal: 0.8, $ScaleVertical: 0.5, $Opacity: 2, $During: {$Top: [0, 0.5]}},
        //ZM*JUP|LB
        {$Duration: 1200, $Zoom: 11, $FlyDirection: 9, $Easing: {$Left: $JssorEasing$.$EaseLinear, $Top: $JssorEasing$.$EaseInCubic, $Zoom: $JssorEasing$.$EaseInCubic}, $ScaleHorizontal: 0.8, $ScaleVertical: 0.5, $Opacity: 2, $During: {$Top: [0, 0.5]}},
        //ZM*JUP|RB
        {$Duration: 1200, $Zoom: 11, $FlyDirection: 10, $Easing: {$Left: $JssorEasing$.$EaseLinear, $Top: $JssorEasing$.$EaseInCubic, $Zoom: $JssorEasing$.$EaseInCubic}, $ScaleHorizontal: 0.8, $ScaleVertical: 0.5, $Opacity: 2, $During: {$Top: [0, 0.5]}},
        //ZM*WVR|LT
        {$Duration: 1200, $Zoom: 11, $FlyDirection: 5, $Easing: {$Left: $JssorEasing$.$EaseLinear, $Top: $JssorEasing$.$EaseInWave}, $ScaleHorizontal: 0.5, $ScaleVertical: 0.3, $Opacity: 2, $Round: {$Rotate: 0.8}},
        //ZM*WVR|RT
        {$Duration: 1200, $Zoom: 11, $FlyDirection: 6, $Easing: {$Left: $JssorEasing$.$EaseLinear, $Top: $JssorEasing$.$EaseInWave}, $ScaleHorizontal: 0.5, $ScaleVertical: 0.3, $Opacity: 2, $Round: {$Rotate: 0.8}},
        //ZM*WVR|TL
        {$Duration: 1200, $Zoom: 11, $FlyDirection: 5, $Easing: {$Left: $JssorEasing$.$EaseInWave, $Top: $JssorEasing$.$EaseLinear}, $ScaleHorizontal: 0.3, $ScaleVertical: 0.5, $Opacity: 2, $Round: {$Rotate: 0.8}},
        //ZM*WVR|BL
        {$Duration: 1200, $Zoom: 11, $FlyDirection: 9, $Easing: {$Left: $JssorEasing$.$EaseInWave, $Top: $JssorEasing$.$EaseLinear}, $ScaleHorizontal: 0.3, $ScaleVertical: 0.5, $Opacity: 2, $Round: {$Rotate: 0.8}},
        //RTT|10
        {$Duration: 700, $Zoom: 11, $Rotate: 1, $Easing: {$Zoom: $JssorEasing$.$EaseInExpo, $Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInExpo}, $Opacity: 2, $Round: {$Rotate: 0.8}},
        //RTTL|R
        {$Duration: 700, $Zoom: 11, $Rotate: 1, $FlyDirection: 2, $Easing: {$Left: $JssorEasing$.$EaseInCubic, $Zoom: $JssorEasing$.$EaseInCubic, $Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInCubic}, $ScaleHorizontal: 0.6, $Opacity: 2, $Round: {$Rotate: 0.8}},
        //RTTL|B
        {$Duration: 700, $Zoom: 11, $Rotate: 1, $FlyDirection: 8, $Easing: {$Top: $JssorEasing$.$EaseInCubic, $Zoom: $JssorEasing$.$EaseInCubic, $Opacity: $JssorEasing$.$EaseLinear, $Rotate: $JssorEasing$.$EaseInCubic}, $ScaleVertical: 0.6, $Opacity: 2, $Round: {$Rotate: 0.8}},
        //RTTS|R
        {$Duration: 700, $Zoom: 1, $Rotate: 1, $FlyDirection: 2, $Easing: {$Left: $JssorEasing$.$EaseInQuad, $Zoom: $JssorEasing$.$EaseInQuad, $Rotate: $JssorEasing$.$EaseInQuad, $Opacity: $JssorEasing$.$EaseOutQuad}, $ScaleHorizontal: 0.6, $Opacity: 2, $Round: {$Rotate: 1.2}},
        //RTTS|B
        {$Duration: 700, $Zoom: 1, $Rotate: 1, $FlyDirection: 8, $Easing: {$Top: $JssorEasing$.$EaseInQuad, $Zoom: $JssorEasing$.$EaseInQuad, $Rotate: $JssorEasing$.$EaseInQuad, $Opacity: $JssorEasing$.$EaseOutQuad}, $ScaleVertical: 0.6, $Opacity: 2, $Round: {$Rotate: 1.2}},
        //RTT*JDN|RT
        {$Duration: 1000, $Zoom: 11, $Rotate: .2, $FlyDirection: 6, $Easing: {$Left: $JssorEasing$.$EaseLinear, $Top: $JssorEasing$.$EaseOutCubic, $Zoom: $JssorEasing$.$EaseInCubic}, $ScaleHorizontal: 0.8, $ScaleVertical: 0.5, $Opacity: 2, $During: {$Top: [0, 0.5]}},
        //RTT*JDN|LB
        {$Duration: 1000, $Zoom: 11, $Rotate: .2, $FlyDirection: 9, $Easing: {$Left: $JssorEasing$.$EaseLinear, $Top: $JssorEasing$.$EaseOutCubic, $Zoom: $JssorEasing$.$EaseInCubic}, $ScaleHorizontal: 0.8, $ScaleVertical: 0.5, $Opacity: 2, $During: {$Top: [0, 0.5]}},
        //RTT*JUP|RB
        {$Duration: 1000, $Zoom: 11, $Rotate: .2, $FlyDirection: 10, $Easing: {$Left: $JssorEasing$.$EaseLinear, $Top: $JssorEasing$.$EaseInCubic, $Zoom: $JssorEasing$.$EaseInCubic}, $ScaleHorizontal: 0.8, $ScaleVertical: 0.5, $Opacity: 2, $During: {$Top: [0, 0.5]}},
        {$Duration: 1200, $Zoom: 11, $Rotate: true, $FlyDirection: 6, $Easing: {$Left: $JssorEasing$.$EaseInCubic, $Top: $JssorEasing$.$EaseLinear, $Zoom: $JssorEasing$.$EaseInCubic}, $ScaleHorizontal: 0.5, $ScaleVertical: 0.8, $Opacity: 2, $During: {$Left: [0, 0.5]}, $Round: {$Rotate: 0.5}},
        //RTT*JUP|BR
        {$Duration: 1000, $Zoom: 11, $Rotate: .2, $FlyDirection: 10, $Easing: {$Left: $JssorEasing$.$EaseInCubic, $Top: $JssorEasing$.$EaseLinear, $Zoom: $JssorEasing$.$EaseInCubic}, $ScaleHorizontal: 0.5, $ScaleVertical: 0.8, $Opacity: 2, $During: {$Left: [0, 0.5]}},
        //R|IB
        {$Duration: 900, $FlyDirection: 2, $Easing: {$Left: $JssorEasing$.$EaseInOutBack}, $ScaleHorizontal: 0.6, $Opacity: 2},
        //B|IB
        {$Duration: 900, $FlyDirection: 8, $Easing: {$Top: $JssorEasing$.$EaseInOutBack}, $ScaleVertical: 0.6, $Opacity: 2},
       ];

       var options = {
        $AutoPlay: true, //[Optional] Whether to auto play, to enable slideshow, this option must be set to true, default value is false
        $AutoPlaySteps: 1, //[Optional] Steps to go for each navigation request (this options applys only when slideshow disabled), the default value is 1
        $AutoPlayInterval: 4000, //[Optional] Interval (in milliseconds) to go for next slide since the previous stopped if the slider is auto playing, default value is 3000
        $PauseOnHover: 1, //[Optional] Whether to pause when mouse over if a slider is auto playing, 0 no pause, 1 pause for desktop, 2 pause for touch device, 3 pause for desktop and touch device, default value is 1

        $ArrowKeyNavigation: true, //[Optional] Allows keyboard (arrow key) navigation or not, default value is false
        $SlideDuration: 500, //[Optional] Specifies default duration (swipe) for slide in milliseconds, default value is 500
        $MinDragOffsetToSlide: 20, //[Optional] Minimum drag offset to trigger slide , default value is 20
        //$SlideWidth: 600,                                 //[Optional] Width of every slide in pixels, default value is width of 'slides' container
        //$SlideHeight: 300,                                //[Optional] Height of every slide in pixels, default value is height of 'slides' container
        $SlideSpacing: 0, //[Optional] Space between each slide in pixels, default value is 0
        $DisplayPieces: 1, //[Optional] Number of pieces to display (the slideshow would be disabled if the value is set to greater than 1), the default value is 1
        $ParkingPosition: 0, //[Optional] The offset position to park slide (this options applys only when slideshow disabled), default value is 0.
        $UISearchMode: 1, //[Optional] The way (0 parellel, 1 recursive, default value is 1) to search UI components (slides container, loading screen, navigator container, arrow navigator container, thumbnail navigator container etc).
        $PlayOrientation: 1, //[Optional] Orientation to play slide (for auto play, navigation), 1 horizental, 2 vertical, default value is 1
        $DragOrientation: 3, //[Optional] Orientation to drag slide, 0 no drag, 1 horizental, 2 vertical, 3 either, default value is 1 (Note that the $DragOrientation should be the same as $PlayOrientation when $DisplayPieces is greater than 1, or parking position is not 0)

        $SlideshowOptions: {//[Optional] Options to specify and enable slideshow or not
         $Class: $JssorSlideshowRunner$, //[Required] Class to create instance of slideshow
         $Transitions: _SlideshowTransitions, //[Required] An array of slideshow transitions to play slideshow
         $TransitionsOrder: 1, //[Optional] The way to choose transition to play slide, 1 Sequence, 0 Random
         $ShowLink: true                                    //[Optional] Whether to bring slide link on top of the slider when slideshow is running, default value is false
        },
        $CaptionSliderOptions: {//[Optional] Options which specifies how to animate caption
         $Class: $JssorCaptionSlider$, //[Required] Class to create instance to animate caption
         $CaptionTransitions: _CaptionTransitions, //[Required] An array of caption transitions to play caption, see caption transition section at jssor slideshow transition builder
         $PlayInMode: 1, //[Optional] 0 None (no play), 1 Chain (goes after main slide), 3 Chain Flatten (goes after main slide and flatten all caption animations), default value is 1
         $PlayOutMode: 3                                 //[Optional] 0 None (no play), 1 Chain (goes before main slide), 3 Chain Flatten (goes before main slide and flatten all caption animations), default value is 1
        },
        $BulletNavigatorOptions: {//[Optional] Options to specify and enable navigator or not
         $Class: $JssorBulletNavigator$, //[Required] Class to create navigator instance
         $ChanceToShow: 2, //[Required] 0 Never, 1 Mouse Over, 2 Always
         $AutoCenter: 0, //[Optional] Auto center navigator in parent container, 0 None, 1 Horizontal, 2 Vertical, 3 Both, default value is 0
         $Steps: 1, //[Optional] Steps to go for each navigation request, default value is 1
         $Lanes: 1, //[Optional] Specify lanes to arrange items, default value is 1
         $SpacingX: 10, //[Optional] Horizontal space between each item in pixel, default value is 0
         $SpacingY: 10, //[Optional] Vertical space between each item in pixel, default value is 0
         $Orientation: 1                                 //[Optional] The orientation of the navigator, 1 horizontal, 2 vertical, default value is 1
        },
        $ArrowNavigatorOptions: {
         $Class: $JssorArrowNavigator$, //[Requried] Class to create arrow navigator instance
         $ChanceToShow: 2                                //[Required] 0 Never, 1 Mouse Over, 2 Always
        }
       };

       var jssor_slider1 = new $JssorSlider$("slider1_container", options);
       //responsive code begin
       //you can remove responsive code if you don't want the slider scales while window resizes
       function ScaleSlider() {
        var parentWidth = jssor_slider1.$Elmt.parentNode.clientWidth;
        if (parentWidth)
         jssor_slider1.$SetScaleWidth(Math.min(parentWidth, 600));
        else
         window.setTimeout(ScaleSlider, 30);
       }

       ScaleSlider();

       if (!navigator.userAgent.match(/(iPhone|iPod|iPad|BlackBerry|IEMobile)/)) {
        $(window).bind('resize', ScaleSlider);
       }


       //if (navigator.userAgent.match(/(iPhone|iPod|iPad)/)) {
       //    $(window).bind("orientationchange", ScaleSlider);
       //}
       //responsive code end
      });
     </script>