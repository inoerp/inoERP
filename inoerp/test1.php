<!DOCTYPE html>
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <meta name="keywords" content="ERP,PHP ERP,Open Source ERP ">
  <title>TEST DOcumentation - inoERP!</title>
  <link rel="shortcut icon" type="image/x-icon" href="files/favicon.ico">
  <link href="" media="all" rel="stylesheet" type="text/css" />
  <link href="http://localhost/inoerp/themes/default/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="http://localhost/inoerp/themes/default/menu.css" media="all" rel="stylesheet" type="text/css" />
  <link href="http://localhost/inoerp/themes/default/jquery.css" media="all" rel="stylesheet" type="text/css" />
      <link href="http://localhost/inoerp/extensions/content/content.css" media="all" rel="stylesheet" type="text/css" />
      <link href="http://localhost/inoerp/tparty/bootstrap/css/bootstrap.css" rel="stylesheet">
  <!-- Styles -->
  <link href="http://localhost/inoerp/tparty/bootstrap/css/style.css" rel="stylesheet">
  <!-- Carousel Slider -->
  <link href="http://localhost/inoerp/tparty/font-awesome/css/font-awesome.min.css" rel="stylesheet">
  <link href='https://fonts.googleapis.com/css?family=PT+Sans:400,400italic,700,700italic' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Lato:400,300,400italic,300italic,700,700italic,900' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Exo:400,300,600,500,400italic,700italic,800,900' rel='stylesheet' type='text/css'>
  <script src="http://localhost/inoerp/includes/js/jquery-2.0.3.min.js"></script>
  <script src="http://localhost/inoerp/includes/js/jquery-ui.min.js"></script>
  <script src="http://localhost/inoerp/tparty/bootstrap/js/bootstrap.min.js"></script>
  <script src="http://localhost/inoerp/tparty/bootstrap/js/menu.js"></script>
  <script src="http://localhost/inoerp/includes/js/custom/tinymce/tinymce.min.js"></script>
  <script src="http://localhost/inoerp/includes/js/save.js"></script>
  <script src="http://localhost/inoerp/includes/js/custom_plugins.js"></script>
  <script src="http://localhost/inoerp/includes/js/basics.js"></script>
      <script src="http://localhost/inoerp/extensions/content/content.js"></script>
    
 </head>
 <body>
  <div id="fb-root"></div>
  <script>(function (d, s, id) {
    var js, fjs = d.getElementsByTagName(s)[0];
    if (d.getElementById(id))
     return;
    js = d.createElement(s);
    js.id = id;
    js.src = "//connect.facebook.net/en_GB/sdk.js#xfbml=1&version=v2.0";
    fjs.parentNode.insertBefore(js, fjs);
   }(document, 'script', 'facebook-jssdk'));</script>

  <div id="topbar" class="clearfix">
   <div class="container">
    <div id = "header_top" class = "clear"></div>    <div class="col-xs-6 col-sm-4 col-md-4">
                <div class="social-icons">
       <span class="fb-like" data-href="https://www.facebook.com/inoerp" data-layout="button_count" data-action="like" data-show-faces="false" data-share="false"></span>
       <span><a  href="https://github.com/inoerp/inoERP" title="gitHUB"><i class="fa fa-github clickable"></i></a></span>
       <span><a  href="#" title="inoerp"><i class="fa fa-skype clickable skype"></i></a></span>
      </div><!-- end social icons -->
     
    </div><!-- end columns --><!-- end columns -->
    <div class="col-lg-8 col-md-8 col-sm-8 col-xs-8">
       <div class="topmenu">
      <div class="topbar-login">
               <div class="dropdown">
         <button class="btn btn-default dropdown-toggle" type="button" id="menu1" data-toggle="dropdown"><i class="fa fa-user"> </i> Inoerp          <span class="caret"></span></button>
         <ul class="dropdown-menu" role="menu" aria-labelledby="menu1">
          <!--<li role="presentation" class="dropdown-header">Dropdown header 1</li>-->
          <li role="presentation"><a role="menuitem" tabindex="-1" href="http://localhost/inoerp/"><i class="fa fa-home"></i> Home</a></li>
          <li role="presentation"><a role="menuitem" tabindex="-1" href="http://localhost/inoerp/form.php?class_name=user&mode=9&user_id=34"> My Details</a></li>
          <li role="presentation"><a role="menuitem" class="pull-right" tabindex="-1" href="http://localhost/inoerp/form.php?class_name=user_activity_v&amp;mode=2&amp;user_id=34"><i class="fa fa-tasks"></i> Activities</a></li>
          <li role="presentation"><a role="menuitem" class="pull-right" tabindex="-1" href="http://localhost/inoerp/search.php?class_name=sys_notification_user"><i class="fa fa-bell-slash-o"></i> Notification</a></li>
          <li role="presentation"><a role="menuitem"  tabindex="-1" href="http://localhost/inoerp/form.php?class_name=user_dashboard_v&amp;mode=2&amp;user_id=34"><i class="fa fa-dashboard"></i> Dashboard</a></li>
          <li role="presentation"><a role="menuitem"  tabindex="-1" href="http://localhost/inoerp/form.php?class_name=user_dashboard_config&amp;mode=9&amp;user_id=34"><i class="fa fa-cog"></i> Configure</a></li>
          <li role="presentation" class="divider"></li>
          <li role="presentation"><a role="menuitem"  tabindex="-1" href="http://localhost/inoerp/extensions/user/user_logout.php"><i class="fa fa-sign-out"></i> LogOut</a></li>
         </ul>
        </div>

              </div>

     </div>
   </div><!-- end container -->
  </div><!-- end topbar -->

  <header id="header-style-1">
   <div class="container">
    <nav class="navbar yamm navbar-default">
     <div class="navbar-header">
      <img src="http://localhost/inoerp/files/logo.png" class="logo_image" alt="logo"/>
      <a href="http://localhost/inoerp/" class="navbar-brand">inoERP</a>
     </div><!-- end navbar-header -->
     <div id="navbar-collapse-1" class="navbar-collapse collapse navbar-right">
      <ul class="nav nav-pills">
       <li><a href="http://localhost/inoerp/">Home <div class="arrow-up"></div></a></li>
       <li><a href="http://inoideas.org/content/demo" >DEMO <div class="arrow-up"></div></a></li>
       <li><a href="https://github.com/inoerp/inoERP" >Download <div class="arrow-up"></div></a></li>
       <li class="active"><a href="http://localhost/inoerp/content.php?mode=9&content_type=forum&category_id=7" ><i class="fa fa-comments-o"></i> Ask a Question <div class="arrow-up"></div></a></li>
       <li><a href="http://localhost/inoerp/content.php?content_type=documentation&amp;category_id=30">Documentation <div class="arrow-up"></div></a></li><!-- end standard drop down -->
       <li><a href="http://localhost/inoerp/content.php?content_type=forum&amp;category_id=1">Forum <div class="arrow-up"></div></a></li>
       <li><a href="http://localhost/inoerp/content.php?mode=2&amp;content_id=197&amp;content_type_id=47">About <div class="arrow-up"></div></a> </li><!-- end drop down -->
      </ul><!-- end navbar-nav -->
     </div><!-- #navbar-collapse-1 -->			
    </nav><!-- end navbar yamm navbar-default -->
   </div><!-- end container -->
  </header><!-- end header-style-1 -->

  <div id="header_bottom"></div>
  <div class="container"><div class='ajax_content'><a href="http://localhost/inoerp/">Home</a>>><a href="http://localhost/inoerp/content.php?content_type=documentation&amp;category_id=30">Documentation</a>>><a href="http://localhost/inoerp/content.php?content_type=documentation&amp;category_id=32">Snippets</a>>> <a class="new_post btn btn-info active" href="http://localhost/inoerp/content.php?mode=9&amp;content_type=documentation&amp;category_id=32"> New Post</a></div><div class="container" id="content_236">
 <div class="row">
  <div class="col-sm-8 blog-main">
   <div id="all_contents">
    <div id="content_top"></div>
    <div id="content">
     <div id="main">
      <div id="structure">
       <div id="view_content" class="documentation">
        <!--    START OF FORM HEADER-->
        <div class="error"></div><div id="loading"></div>
         

                <div id="content_element">
         <ul>
          <li><span class='content_heading'> TEST DOcumentation</span></li>
          <li class="created_by">inoerp</li>
          <li class="creation_date">2014-10-20 11:26:53</li>
                     <li><a href="http://localhost/inoerp/content.php?mode=9&amp;content_id=236&amp;content_type=documentation"><img src="http://localhost/inoerp/themes/images/edit.png" alt="update" /> </a></li>
                   </ul>
        </div>
        <div id="content_extra"><p>sdfsdfsdf</p></div>
        <div id="after_content_extra">
        <div id='content_info'>
         <ul>
          <li class="attachment_content"><label>Attachments : </label></li>
          <li class="terms"><label>Tags : </label></li>
          <li class="categories"><label>Category : </label><a href="content.php?content_type=documentation&amp;category_id=32">Snippets</a> &nbsp; &nbsp; </li>
         </ul>
        </div>
        <div id="content_navigation">
         <ul>
          <li class="parent_id"><label>Parent Content : </label>
                     </li>
          <li class="child_contents"><label>Child Content : </label>

           <a href="content.php?mode=9&amp;content_type=documentation&amp;parent_id=236"   
               class="button add_child_content">Add Child Content </a>          </li>
         </ul>
        </div>
        <div id="child_conetnt_list"></div>
        <div id="comments">
         <div id="comment_list">
           <div id="comment_id_283" class="panel panel-info commentRecord"><div class="panel-heading"><ul class="header_li"><li class="comment_by"><a href="http://localhost/inoerp/form.php?class_name=user_activity_v&mode=2&user_id=34">inoerp</a></li><li class="creation_date">2014-11-03 03:37:41</li><li class="delete_update"><button name="delete_button" class="delete_button btn btn-danger " value="283" >Delete</button>  <button name="update_button" class="update_button btn btn-warning " value="283" >Update</button> </li><li"><a href="#commentForm" class="comment-reply btn btn-default" role="button">Reply</a></li><li class="update-comment"></li></ul></div><div class="comment panel-body"><p>sdfsfsd</p>
<p>dsfsd</p>
<p> </p></div></div><div class='page_nos pagination'> <span class="selected">1</span>  <a href="content.php?pageno=1&amp;TEST-DOcumentation">Last</a> </div><div class="noOfcontents">Show<select name="per_page" class="per_page small"><option value="3"  > 3 </option><option value="5" > 5 </option><option value="10"  selected > 10 </option><option value="20" > 20 </option><option value="50" > 50 </option></select><a name="content_per_page" href="/inoerp/content.php?" class="content_per_page button">Per Page</a></div>         </div>
         <div id="commentForm">
 <script src="http://localhost/inoerp/extensions/comment/comment.js"></script> 
 <div id="commentForm_witoutjs">
  <div id="output">
  </div>
  <!--    START OF FORM HEADER-->
  <div class="comment_error"></div><div id="comment_loading"></div>
 
  <form action="http://localhost/inoerp/extensions/comment/post_comment.php"  method="post" class="comment"  name="comment" >
   <!--create empty form or a single id when search is not clicked and the id is referred from other comment -->
   <div class="hidden"><input type="hidden"
                              name="comment_id" value="">
   </div>
   <div class="hidden"><input type="hidden" name="reference_table" 
                              value="content">
   </div>
   <div class="hidden"><input type="hidden" name="reference_id" 
                              value="236">
   </div>
   <span class="show_loading_small"><img alt="Loading..." src="http://localhost/inoerp/themes/images/small_loading.gif"/></span>
   <div id="commentId" class="row"><label>Comment</label>
    <textarea name="comment" class="mediumtext" rows="30" cols="80"> </textarea>

   </div>
   <div id="file_upload_form" class="row small-top-margin">
    <ul class="inRow asperWidth">
     <li class="btn btn-info active inline input_file clickable"  role="button"><input type="file" id="comment_attachments"  class="input_file_btn" name="attachments[]" multiple/>
      <i class="fa fa-paperclip clickable"></i>&nbsp;&nbsp;Select File</li>
     <li><input type="button"  role="button" value="Attach"  name="attach_submit" id="comment_attach_submit" class="btn btn-info active comment_attach_submit"></li>
     <li><input type="text" name="comment_by[]" value="inoerp" 
	 maxlength="256" size="" class="textfield  comment_by" placeholder=""  required id="comment_by"  title=""  data-toggle="tooltip"></li>
     <li><input type="button" role="button" name="submit_comment" class="btn btn-warning ino-btn submit_comment" Value="Post"></li>
     <input type="hidden" name="class_name[]" value="content" class="hidden class_name" ><input type="hidden" id="upload_type" name="upload_type[]" value="only_server" class="hidden upload_type" >     
    </ul>
    <div class="uploaded_file_details"></div>
   </div>
   <div id="uploaded_file_details">		</div>
<div id="existing_attachment_list"><ul class='first_level'></ul></div>  </form>
 </div>
 <!--END OF FORM HEADER-->  
</div>
<!--   end of structure-->
         <div id="new_comment">
         </div>
        </div>
        </div>
       </div>
      </div>
     </div>
    </div>
    <div id="content_bottom"></div>
   </div>
  </div>
  <div class="col-sm-4 blog-sidebar">
   <div class="sidebar-module ">
    <div id="content_left"></div>
   </div>
   <div class="sidebar-module">
    <div id="content_right"></div>
   </div>

   <div class="sidebar-module">
    <div id="content_right_right"></div>
   </div>
  </div>
 </div>
</div>

<!--footer content-->
<div id="comment_form" class="none">
 </div>

<div class="make-bg-full">
 <div class="calloutbox-full-mini nocontainer">
  <div class="long-twitter">
   <p class="lead"><i class="fa fa-star"></i>
    All inoERP code is Copyright by the Original Authors as mentioned on COPYRIGHT.txt file.
    <br>inoERP is an open Source software; you can redistribute it and/or modify
    it under the terms of the Mozilla Public License Version 2.0 </p>
  </div>
 </div><!-- end calloutbox -->
</div><!-- make bg -->

<div id="footer-style-1">
 <div class="container">
  <div id="footer_top"></div>
 </div>
</div>
<div id="copyrights">
 <div class="container">
  <div class="col-lg-5 col-md-6 col-sm-12">
   <div class="copyright-text">
    <p>
     <span class="developed_by">Copyright @ 2014 inoERP - <a href='http://inoideas.org'>Powered By inoCMS </a></span>                    </p>
   </div><!-- end copyright-text -->
  </div><!-- end widget -->
  <div class="col-lg-7 col-md-6 col-sm-12 clearfix">
   <div class="footer-menu">
    <ul class="menu">
     <li class="active"><a href="#">Terms of Use</a></li>
     <li><a href="#">Site Maps</a></li>
     <li><a href="https://github.com/inoerp/inoERP/releases">Releases</a></li>
     <li><a href="https://www.mozilla.org/MPL/2.0/">MPL 2</a></li>
     <li><a href="#">Cookie Preferences</a></li>

    </ul>
   </div>
  </div><!-- end large-7 --> 
 </div><!-- end container -->
</div><!-- end copyrights -->

<input type="hidden" id="home_url" name="home_url[]" value="http://localhost/inoerp/" class="hidden home_url" />
</body>
</html>