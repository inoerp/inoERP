<?php require_once WWW_DIR.'/vendor/HTMLPurifier/library/HTMLPurifier.auto.php';
$config = HTMLPurifier_Config::createDefault();
$purifier = new HTMLPurifier($config);
?>
<div class="container" id="content_<?php echo $content->content_id; ?>">
 <div class="row">
  <div class="col-md-8 col-xs-12 col-sm-12 blog-main">
   <div id="all_contents">
    <div id="content_top"></div>
    <div id="content">
     <div id="main">
      <div id="structure">
       <div id="view_content" class="<?php echo $content_type_name; ?>">
        <!--    START OF FORM HEADER-->

        <?php echo (!empty($show_message)) ? $show_message : ""; ?> 

        <?php form::hidden_field('content_id', $content->content_id) ?>
        <div id="content_element">
         <ul>
          <li><span class='content_heading'> <?php echo ($content->subject); ?></span></li>
          <li class="created_by f-right"><?php
           $content_user = ino_user::find_by_id($content->created_by);
           if (!empty($content_user)) {
            echo '<a href="' . HOME_URL . 'form.php?class_name=user_activity_v&mode=2&user_id=' . ($content->created_by) . '">' . ino_getUserName_from_email($content_user->username) . '</a>';
            $profile_image = $f->show_existing_image($content_user->image_file_id, 'img-vs');
            if (!empty($profile_image)) {
             echo "&nbsp; $profile_image";
            }
           }
           ?></li>
          <li class="creation_date"><?php echo ($content->creation_date); ?></li>
          <?php
          if ($allow_content_update) {
           ?>
           <li><a href="<?php echo HOME_URL; ?>content.php?mode=9&amp;content_id=<?php echo ($content->content_id); ?>&amp;content_type=<?php echo ($content_type_name); ?>"><img src="<?php echo HOME_URL; ?>themes/images/edit.png" alt="<?php echo gettext('Update'); ?>" /> </a></li>
          <?php } ?>
         </ul>
        </div>
        <div id="content_extra"><?php
         $cont_html =  content::content_by_id($content_type_name, $content->content_id);
//         echo nl2br(($cont_html));
				          echo nl2br($purifier->purify(html_entity_decode($cont_html , ENT_QUOTES,'UTF-8')));
         ?></div>
        <div id="after_content_extra">
         <div id="content_navigation" class="parent-child-nav">
          <ul>
           <li class="parent_id">
            <?php echo!(empty($parent_of_content)) ? $parent_of_content . ' <i class="fa fa-level-up fa-2x"></i>' : "" ?>
           </li>
           <li class="child_contents">
            <?php echo '<a href="' . HOME_URL . 'content.php?mode=9&amp;content_type=' . $content_type_name . '&amp;parent_id=' . $content->content_id . '"   
               class="button add_child_content">Add Child Content &nbsp;&nbsp;<i class="fa fa-file-text-o fa-2x"></i></a>'; ?>
           </li>
          </ul>
         </div>
         <div id='content_info'>
          <ul>
           <li class="attachment_content"><?php echo (!empty($file)) ? '<label>' . gettext('Attachments') . ' : </label>' . extn_file::show_file_list($file) : ""; ?></li>
           <li class="terms"><?php echo!empty($content->terms) ? '<label>' . gettext('Tags') . ' : </label>' . ($content->terms) : ''; ?></li>
           <li class="categories"><?php echo!(empty($category_statement)) ? '<label>' . gettext('Category') . ' : </label>' . $category_statement : ""; ?></li>
          </ul>
         </div>
         <div id="child_conetnt_list"><?php
          echo!(empty($childs_of_parent_id)) ? '<span class="heading">' . gettext('Next Read') . '</span>' . $childs_of_parent_id : "";
          ?></div>
         <div id="comments">
          <div id="comment_list">
           <?php echo (!(empty($comments)) && $comment_privilage >= 2 && $content->comment_status > 1) ? $comments : ""; ?>
          </div>
          <?php
          if ($comment_privilage >= 4 && $content->comment_status == 3) {
           $reference_table = 'content';
           $reference_id = $content->content_id;
           include_once __DIR__ . '/../../comment.php';
          } else if(empty($content->comment_status) || $content->comment_status < 3) {
           echo "<j  class='comment post button btn btn-info active btn-lg' role='button' id='commentForm'> " . gettext('Comment is disabled') . " </j>";
          }else {
           echo "<a href='" . HOME_URL . "extensions/ino_user/user_login.php' class='comment post button btn btn-info active btn-lg' role='button' id='commentForm'>" . gettext('Login To Comment') . " </a>";
          }
          ?>
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
  <div class="col-md-4 col-sm-12 col-xs-12 blog-sidebar">
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

<?php include_template('footer.inc') ?>
