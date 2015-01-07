<div class="container">
 <div class="row">
  <div class="col-sm-8 blog-main">
   <div id="all_contents">
    <div id="content_top"></div>
    <div id="content">
     <div id="main">
      <div id="structure">
       <div id="view_content">
        <!--    START OF FORM HEADER-->
        <div class="error"></div><div id="loading"></div>
        <?php echo (!empty($show_message)) ? $show_message : ""; ?> 

        <?php form::hidden_field('content_id', $content->content_id) ?>
        <div id="content_element">
         <ul>
          <li><span class='content_heading'> <?php echo ($content->subject); ?></span></li>
          <li class="created_by"><?php
           $content_user = user::find_by_id($content->created_by);
           echo!empty($content_user) ? ($content_user->username) : '';
           ?></li>
          <li class="creation_date"><?php echo ($content->creation_date); ?></li>
          <?php
          if ($allow_content_update) {
           ?>
           <li><a href="<?php echo HOME_URL; ?>content.php?mode=9&amp;content_id=<?php echo ($content->content_id); ?>&amp;content_type=<?php echo ($content_type_name); ?>"><img src="<?php echo HOME_URL; ?>themes/images/edit.png" alt="update" /> </a></li>
          <?php } ?>
         </ul>
        </div>
        <div id="content_extra"><?php echo content::content_by_id($content_type_name, $$class->content_id); ?></div>
        <div id='content_info'>
         <ul>
          <li class="attachment_content"><label>Attachments : </label><?php echo (!empty($file)) ? file::show_file_list($file) : ""; ?></li>
          <li class="terms"><label>Tags : </label><?php echo ($content->terms); ?></li>
          <li class="categories"><label>Category : </label><?php echo!(empty($category_statement)) ? $category_statement : ""; ?></li>
         </ul>
        </div>
        <div id="content_navigation">
         <ul>
          <li class="parent_id"><label>Parent Content : </label>
           <?php echo!(empty($parent_of_content)) ? $parent_of_content : "" ?>
          </li>
          <li class="child_contents"><label>Child Content : </label>

           <?php echo '<a href="content.php?mode=9&amp;content_type=' . $content_type_name . '&amp;parent_id=' . $content->content_id . '"   
               class="button add_child_content">Add Child Content </a>'; ?>
          </li>
         </ul>
        </div>
        <div id="child_conetnt_list"><?php
         echo!(empty($childs_of_parent_id)) ? '<span class="heading">Next Read</span>' . $childs_of_parent_id : "";
         ?></div>
        <div id="comments">
         <div id="comment_list">
          <?php echo!(empty($comments) && $comment_privilage >= 2) ? $comments : ""; ?>
         </div>
         <?php
         if ($comment_privilage >= 4) {
          $reference_table = 'content';
          $reference_id = $content->content_id;
          include_once 'comment.php';
         } else {
          echo "<a href='extensions/user/user_login.php' class='comment post button'>Login To Comment </a>";
         }
         ?>
         <div id="new_comment">
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

<?php include_template('footer.inc') ?>
