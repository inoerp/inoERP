<div class="hidden"><ul id="js_files"><li>extensions/content/content.js</li></ul></div>
<div class="container">
<div id="structure">
<div id="content_divId">
 <div id="form_all">
  <div id ="form_header">
   <div class='heading'> <?php echo $content_type->description; ?></div>
   <form action=""  method="post" id="content_data"  name="content_data">
    <!--create empty form or a single id when search is not clicked and the id is referred from other content -->
    <?php echo $f->hidden_field_withId('content_id', $$class->content_id); ?>
    <?php echo $f->hidden_field_withId('content_type_id', $content_type->content_type_id); ?>
    <?php echo $f->hidden_field_withId('content_type', $content_type_name); ?>
    <div class="tabContainer">
<!--      <div><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ap_payment_header_id select_popup">
        Content Id</label>
       <?php $f->text_field_dr('content_id'); ?>
       <a name="show" href="content.php?content_id=<?php echo $$class->content_id; ?>&content_type_id=<?php echo $content_type->content_type_id; ?>&<?php echo "mode=$mode"; ?>" class="show document_id ap_payment_header_id">
        <i class="fa fa-refresh"></i></a> 
      </div>-->
      <div><label><?php echo gettext('Subject'); ?></label>
       <?php $f->text_field_d('subject'); ?>
      </div>
          
    <div id="extra_form_element">
     <?php echo !empty($form_element) ? $form_element : "" ?>
    </div>
    <!--End of Content-->
    <div id="show_attachment" class="show_attachment">
     <div id="file_upload_form">
      <ul class="inRow asperWidth">
       <li><input type="file" id="attachments" class="attachments" name="attachments[]" multiple/></li>
       <li> <input type="button" value="<?php echo gettext('Attach'); ?>" form="file_upload" name="attach_submit" id="attach_submit" class="submit button"></li>
       <li class="show_loading_small"><img alt="<?php echo gettext('Loading'); ?>..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
      </ul>
      <div class="uploaded_file_details"></div>
     </div>
     <?php echo extn_file::attachment_statement($file); ?>
    </div>
    <div id="content_element">
     <ul>
      <li> 
       <?php
       if (!empty($category_select_statement_array)) {
        foreach ($category_select_statement_array as $category_select_statement) {
         echo '<label>' . gettext('Category') . ' : </label>';
         echo $category_select_statement;
        }
       } else {
        if (!empty($categories_of_content_type_select_option_array)) {
         foreach ($categories_of_content_type_select_option_array as $records) {
          echo '<label>' . gettext('Category') . ' : </label>';
          echo $records;
         }
        }
       }
       ?>
      </li>
      </ul>
    </div>
    <?php
    if ($access_level <= 3 & $mode == 9) {
     echo '<div id="save" class="submit"><input type="button" value="' . gettext('Save Post') . '" name="submit_content" class="button"></div>';
    }
    ?>
     </div> 
   </form>
  </div> 
 </div>
</div>
 </div>
 </div>

