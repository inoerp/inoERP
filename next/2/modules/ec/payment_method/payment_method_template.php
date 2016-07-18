<form method="post" id="ec_payment_method"  name="ec_payment_method"><span class="heading">eCommerce Payment Method </span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Message') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('ec_payment_method_id') ?>
       <a name="show" href="form.php?class_name=ec_payment_method&<?php echo "mode=$mode"; ?>" class="show document_id ec_payment_method_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_dm('payment_method_name'); ?></li>
      <li><?php $f->l_text_field_dm('display_name'); ?></li>
      <li><?php $f->l_text_field_d('submit_button_name'); ?></li>
      <li><?php $f->l_text_field_d('type'); ?></li>
      <li><?php $f->l_text_field_d('mode'); ?></li>
      <li><?php $f->l_text_field_d('username'); ?></li>
      <li><?php $f->l_text_field_d('password'); ?></li>
      <li><?php $f->l_text_field_d('signature'); ?></li>
      <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
      <li><?php $f->l_status_field_d('status'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <?php echo form::text_area('user_message', $$class->user_message, '5', '140', '', 'Maximum 255 Characters'); ?>   
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'ec_payment_method';
       $reference_id = $$class->ec_payment_method_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
     <div> 
     </div>
    </div>
   </div>
  </div>
 </div>
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Payment Method Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('URLs') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Logo Image') ?></a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Secondary Fields') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <ul class="column two_column">
      <li><label><?php echo gettext('Confirm URL') ?></label>
       <span class="small-hint">If the link doesnt contains '?' then put a '?' at the end of the link</span>
       <?php echo form::text_area('confirm_url', $$class->confirm_url, '2', '50', '', 'Maximum 255 Characters'); ?>      </li>
      <li><label><?php echo gettext('Cancel URL') ?></label><?php echo form::text_area('cancel_url', $$class->cancel_url, '2', '50', '', 'Maximum 255 Characters'); ?>      </li>
      <li><label><?php echo gettext('Return URL') ?></label><?php echo form::text_area('return_url', $$class->return_url, '2', '50', '', 'Maximum 255 Characters'); ?>      </li>
     </ul>
    </div>
    <div id="tabsLine-2" class="tabContent">
     <div class="image"><?php echo $f->image_field('image_file_id', $$class->image_file_id, '', '', 'img-medium'); ?></div>
    </div>
    <div id="tabsLine-3" class="tabContent">
     <?php echo!empty($secondary_field_stmt) ? $secondary_field_stmt : null; ?>
    </div> 
   </div>


  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="ec_payment_method" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="ec_payment_method_id" ></li>
  <li class="form_header_id" data-form_header_id="ec_payment_method" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ec_payment_method_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ec_payment_method" ></li>
 </ul>
</div>