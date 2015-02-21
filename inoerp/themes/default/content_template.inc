<?php
if (!empty($non_db_content_type)) {
 include_once 'nondb_content_template.inc';
 return;
}
if (!empty($_GET['window_type']) && ($_GET['window_type'] == 'form') ) {
 include_once 'form_content_template.inc';
 return;
}
?>
<div class="container">
 <div class="row">
  <div class="col-sm-8 blog-main">
   <div id="all_contents">
    <div id="content_top"></div>
    <div id="content">
     <div id="main">
      <div id="structure">
       <div id="content_divId">
        <!--    START OF FORM HEADER-->
        <div class="error"></div><div id="loading"></div>
        <?php
        $f = new inoform();
        echo (!empty($show_message)) ? $show_message : "";
        ?> 
        <!--    End of place for showing error messages-->
        <div id="form_all">
         <div id ="form_header">
          <div class='heading'> <?php echo $content_type->description; ?></div>
          <form action=""  method="post" id="content_data"  name="content_data">
           <!--create empty form or a single id when search is not clicked and the id is referred from other content -->
           <?php echo $f->hidden_field_withId('content_id', $$class->content_id); ?>
           <?php echo $f->hidden_field_withId('content_type_id', $content_type->content_type_id); ?>
           <?php echo $f->hidden_field_withId('content_type', $content_type_name); ?>
           <div class="row">
            <div class="col-sm-7"><?php echo $f->text_field('subject', $$class->subject, 100, 'subject', 'extra_large', 1, '' , ' Subject - Required For This Post') ?></div>
            <div class="col-sm-1">
             <a class="show2 content_id btn btn-default" role="button" href="content.php?content_id=<?php echo $$class->content_id; ?>&content_type=<?php echo $content_type_name ?>">View</a>
            </div>
           </div>

           <div id="extra_form_element">
            <?php echo!empty($form_element) ? $form_element : "" ?>
           </div>
           <!--End of Content-->
           <div id="show_attachment" class="show_attachment">
            <div id="file_upload_form">
             <ul class="inRow asperWidth">
              <li><input type="file" id="attachments" class="attachments" name="attachments[]" multiple/></li>
              <li> <input type="button" value="Attach" form="file_upload" name="attach_submit" id="attach_submit" class="submit button"></li>
              <li class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
             </ul>
             <div class="uploaded_file_details"></div>
            </div>
            <?php echo file::attachment_statement($file); ?>
           </div>
           <div id="content_element">
            <ul>
             <li> 
              <?php
              if (!empty($category_select_statement_array)) {
               foreach ($category_select_statement_array as $category_select_statement) {
                echo '<label>Category : </label>';
                echo $category_select_statement;
               }
              } else {
               if (!empty($categories_of_content_type_select_option_array)) {
                foreach ($categories_of_content_type_select_option_array as $records) {
                 echo '<label>Category : </label>';
                 echo $records;
                }
               }
              }
              ?>
             </li>
             <li> <label>Show in Front Page : </label>
              <?php echo form::checkBox_field_d('show_in_fp_cb'); ?></li>
             <li> <label>Published : </label> 
              <?php echo form::checkBox_field('published_cb', $$class->published_cb); ?></li>
             <li><label>Weight : </label><?php form::text_field_ds('weightage'); ?> </li>
             <li><label>Rev Number : </label><?php form::text_field_ds('rev_number'); ?></li>
             <li><label>Parent : </label><?php form::text_field_ds('parent_id'); ?></li>
             <li><label>URL Alias : </label> <?php echo $f->text_field('url_alias', $$class->url_alias, '40', ''); ?> 
              <?php echo $f->hidden_field('ext_url_alias_id', $$class->ext_url_alias_id); ?>
             </li> 
             <li><label>Tags : </label> <?php echo $f->text_field('terms', $$class->terms, '40', ''); ?> </li>
            </ul>
           </div>
           <?php
           if ($access_level <= 3 & $mode == 9) {
            echo '<div id="save" class="submit"><input type="button" value="Save Post" name="submit_content" class="button"></div>';
           }
           ?>
          </form>
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

