<div class="container target">
 <div class="row">
  <div class="col-sm-3">
   <h1 class=""><?php echo!empty($up->profile_name) ? $up->profile_name : ino_getUserName_from_email($user_ai->username); ?></h1>
   <div><?php echo $f->show_existing_image($user_ai->image_file_id, 'img-circle img-responsive', 1); ?></div>
   <br>

   <a class="getAjaxForm btn btn-info send_message " role="button" href="form.php?class_name=extn_emessage_header&user_id=<?php echo $user_ai->ino_user_id ?>"><?php echo gettext('Internal Message'); ?>  <i class="fa fa-wechat clickable"></i></a>
   <a target="_blank" class="contact_link btn btn-info send_email " role="button" href="form.php?class_name=web_mail&window_type=popup&<?php echo 'email=' . $user_ai->email . '&reference_table=user&reference_id=' . $ino_user->ino_user_id; ?>">
    <?php echo gettext('External eMail'); ?> <i class="fa fa-envelope-o clickable"></i></a>
  </div>
  <br><br>
  <div class="col-sm-3">
   <ul class="list-group">
    <li class="list-group-item text-muted" contenteditable="false"><?php echo gettext('Profile'); ?></li>
    <li class="list-group-item text-right"><span class="pull-left"><strong class=""><?php echo gettext('Joined'); ?></strong></span><?php echo!empty($user_ai->creation_date) ? $user_ai->creation_date : ' NA '; ?></li>
    <li class="list-group-item text-right"><span class="pull-left"><strong class=""><?php echo gettext('Last seen'); ?></strong></span> NA </li>
    <li class="list-group-item text-right"><span class="pull-left"><strong class=""><?php echo gettext('User Name'); ?></strong></span><?php echo ino_getUserName_from_email($user_ai->username) ?></li>
    <li class="list-group-item text-right"><span class="pull-left"><strong class=""><?php echo gettext('Phone'); ?></strong></span><?php echo!empty($up->phone) ? $up->phone : ' NA '; ?> </li>
   </ul>
  </div>
  <div class="col-sm-3">
   <ul class="list-group">
    <li class="list-group-item text-muted" contenteditable="false"><?php echo gettext('Social Media'); ?></li>
    <li class="list-group-item text-right"><span class="pull-left"><strong class=""><?php echo gettext('Website'); ?></strong></span><a href="<?php echo ( $up->website) ?>"><i class="fa fa-globe"></i></a></li>
    <li class="list-group-item text-right"><span class="pull-left"><strong class="">Facebook</strong></span><a href="<?php echo ( $up->facebook_page) ?>"><i class="fa fa-facebook"></i></a></li>
    <li class="list-group-item text-right"><span class="pull-left"><strong class="">Google</strong></span><a href="<?php echo ( $up->google_page) ?>"><i class="fa fa-google-plus"></i></a></li>
    <li class="list-group-item text-right"><span class="pull-left"><strong class="">Linked In</strong></span><a href="<?php echo ( $up->linkedin_page) ?>"><i class="fa fa-linkedin"></i></a></li>
   </ul>

  </div>
 </div>
 <div class="row">
  <div class="col-sm-12" contenteditable="false" style="">
   <br>
   <div class="panel panel-ino-light-grey">
    <div class="panel-heading"><?php echo!empty($up->profile_name) ? $up->profile_name : ino_getUserName_from_email($up->username); ?> @ <?php echo $site_info->site_name; ?></div>
    <div class="panel-body about-me"><?php echo!empty($up->about) ? $up->about : gettext('No User Profile'); ?></div>
   </div>
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Posts'); ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Comments'); ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <?php echo!empty($content_string) ? $content_string : false; ?>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <?php echo!empty($comment_string) ? $comment_string : false; ?>
     </div>
    </div>
   </div>

  </div>



 </div>
</div>
