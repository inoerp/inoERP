<?php
if (!empty($non_db_content_type)) {
 include_once 'nondb_content_template.inc';
 return;
}
if (!empty($_GET['window_type']) && ($_GET['window_type'] == 'form')) {
 include_once 'form_content_template.inc';
 return;
}
?>
<div class="container">
 <div class="row">
  <div class="col-md-8 col-sm-12 col-xs-12 blog-main">
   <div id="all_contents">
    <div id="content_top"></div>
    <div id="content">
     <div id="main">
      <div id="structure">
       <div id="content_divId">
        <!--    START OF FORM HEADER-->
        <div class="error"></div><div id="loading"></div>
        <span class="show_loading_small"><img alt="<?php echo gettext('Loading'); ?>..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></span>
        <?php
        echo (!empty($show_message)) ? $show_message : "";
        if (!empty($access_denied_msg)) {
         echo ino_access_denied($access_denied_msg);
        } else {
         ?>
         <!--    End of place for showing error messages-->
         <div id="form_all">
          <div id ="form_header">
           <div class='heading'> <?php echo $content_type->description; ?></div>
           <form method="post" id="content_data"  name="content_data">
            <!--create empty form or a single id when search is not clicked and the id is referred from other content -->
            <?php echo $f->hidden_field_withId('content_id', $$class->content_id); ?>
            <?php echo $f->hidden_field_withId('content_type_id', $content_type->content_type_id); ?>
            <?php echo $f->hidden_field_withId('content_type', $content_type_name); ?>
            <div class="row">
             <div class="col-sm-10 col-xs-12"><?php echo $f->text_field('subject', $$class->subject, 100, 'subject', 'extra_large', '1', '', ' Subject - Required For This Post') ?></div>
             <div class="col-sm-2">
              <a class="show2 content_id btn btn-default" role="button" href="content.php?content_id=<?php echo $$class->content_id; ?>&content_type=<?php echo $content_type_name ?>"><?php echo gettext('View') ?></a>
             </div>
            </div>

            <div id="extra_form_element">
             <?php echo!empty($form_element) ? $form_element : "" ?>
            </div>
            <!--End of Content-->
            <div id="content_element_divId" class="col-md-12" >
             <div class="hideDiv_input fa fa-plus-circle clickable"></div>
             <div class="hideDiv_input_element iinput">
              <legend class="collapsible major">
               <ul class="column header_field">
                <li><label><?php echo gettext('Front Page'); ?>?</label><?php echo form::checkBox_field_d('show_in_fp_cb'); ?></li>
                <li><label><?php echo gettext('Published'); ?></label><?php echo form::checkBox_field('published_cb', $$class->published_cb); ?></li>
                <li><label><?php echo gettext('Weight'); ?></label><?php form::text_field_ds('weightage'); ?> </li>
                <li><label><?php echo gettext('Rev Number'); ?></label><?php form::text_field_ds('rev_number'); ?></li>
                <li><label><?php echo gettext('Parent'); ?></label><?php form::text_field_ds('parent_id'); ?></li>
								<li><?php $f->l_select_field_from_array('comment_status', content::$comment_status_a, $$class->comment_status); ?></li>
                <li><label><?php echo gettext('URL Alias'); ?></label><?php echo $f->text_field('url_alias', $$class->url_alias, '40', ''); ?> 
                 <?php echo $f->hidden_field('ext_url_alias_id', $$class->ext_url_alias_id); ?>
                </li> 
                <li><label><?php echo gettext('Tags'); ?></label><?php echo $f->text_field('terms', $$class->terms, '40', ''); ?> </li>
                <li> 
                 <?php
                 if (!empty($category_select_statement_array)) {
                  foreach ($category_select_statement_array as $category_select_statement) {
                   echo '<label>' . gettext('Category') . '</label>';
                   echo $category_select_statement;
                  }
                 } else {
                  if (!empty($categories_of_content_type_select_option_array)) {
                   foreach ($categories_of_content_type_select_option_array as $records) {
                    echo '<label>' . gettext('Category') . '</label>';
                    echo $records;
                   }
                  }
                 }
								 if(!empty($_SESSION['session_token'])){
									echo $inocsrf->token_tag();
								 }
								 
                 ?>
                </li>
               </ul>
              </legend>
             </div>
            </div>

            <div id="show_attachment" class="show_attachment row">
             <div id="file_upload_form" class=" small-top-margin">
              <ul class="inRow asperWidth">
               <li class="btn btn-info active inline input_file clickable ino-100"  role="button"><input type="file" id="comment_attachments"  class="input_file_btn" name="attachments[]" multiple/>
                <i class="fa fa-paperclip clickable"></i>&nbsp;&nbsp<?php echo gettext('Select File'); ?></li>
               <li><input type="button"  role="button" value="<?php echo gettext('Attach'); ?>"  name="attach_submit" id="comment_attach_submit" class="btn btn-info active ino-80 comment_attach_submit"></li>
							  <li class="ino-70"><input name="subscribe_cb[]" class="checkBox subscribe_cb ino-10" id="subscribe_cb" value="1" type="checkbox">&nbsp; <?php echo gettext('Subscribe'); ?></li>
               <?php $user_name = isset($_SESSION['username']) ? $_SESSION['username'] : 'Anonymous'; ?>
               <li><div class="input-group">
                 <span class="input-group-addon" id="basic-addon1"><?php echo gettext('Post As'); ?> </span>
                 <input type="text" name="content_by" class="form-control content_by height-unset ino-100" placeholder="<?php echo $user_name ?>" aria-describedby="basic-addon1" >
                </div></li>
               <?php
               if ($mode == 9) {
                echo '<li><input type="button" id="save_content" role="button" name="submit_content" class="btn btn-warning ino-btn save_content submit_content ino-80" Value="' . gettext('Post') . '"></li>';
               }
               ?>

               <?php
               echo form::hidden_field('class_name', $class);
               echo $f->hidden_field_withId('upload_type', 'only_server');
               echo $f->hidden_field_withId('user_id', $ino_user->ino_user_id);
               ?>
              </ul>
              <div class="uploaded_file_details"></div>
             </div>
             <?php echo extn_file::attachment_statement($file); ?>
            </div>


           </form>
          </div> 
         </div>
        <?php }
        ?> 
       </div>
      </div>
     </div>
    </div>
    <div id='overlay'></div>
    <div id="content_bottom"></div>
   </div>
  </div>
  <div class="col-md-4 col-sm-12 col-xs-12 blog-sidebar">
   <div class="sidebar-module sidebar-module-inset">
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