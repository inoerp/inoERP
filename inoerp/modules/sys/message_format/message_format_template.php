<form   method="post" id="sys_message_format"  name="sys_message_format"><span class="heading"><?php echo gettext('Message Format') ?> </span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('sys_message_format_id') ?>
       <a name="show" href="form.php?class_name=sys_message_format&<?php echo "mode=$mode"; ?>" class="show document_id sys_message_format_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_dm('format_name'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php $f->l_text_field_dm('message_subject'); ?></li>
      <li><?php $f->l_text_field_d('content_type'); ?></li>
      <li><?php $f->l_text_field_d('cc_email'); ?></li>
      <li><?php $f->l_text_field_d('from_name'); ?></li>
      <li><?php $f->l_text_field_d('from_email'); ?></li>
      <li><?php $f->l_text_field_d('reply_to'); ?></li>
      <li><?php $f->l_checkBox_field_d('use_smtp_cb'); ?></li>
      <li><?php $f->l_select_field_from_array('content_type', sys_message_format::$content_type_a, $$class->content_type); ?></li>
      <li><?php $f->l_status_field_d('status'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'sys_message_format';
       $reference_id = $$class->sys_message_format_id;
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
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Message Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Body') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Secondary Fields') ?></a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Message Codes') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <?php echo form::text_area('message_body', $$class->message_body, '5', '140', '', ' '); ?>   
    </div>
    <div id="tabsLine-2" class="tabContent">
     <?php echo!empty($secondary_field_stmt) ? $secondary_field_stmt : null; ?>
    </div>
    <div id="tabsLine-3" class="tabContent">
     <ul class='column two_column'>
      <li><label><?php echo gettext('Any Data') ?>: </label> {{table_name.field_name}}</li>
      <li><label><?php echo gettext('User Name') ?> : </label> {{user.username}}</li>
      <li><label><?php echo gettext('User Id') ?> : </label> {{user.user_id}}</li>
      <li><label><?php echo gettext('User Email') ?> : </label> {{user.email}}</li>
      <li><label><?php echo gettext('Site Name') ?> : </label> {{site_info.site_name}}</li>
      <li><label><?php echo gettext('Site eMail') ?> : </label> {{site_info.email}}</li>
     </ul>
    </div> 
   </div>


  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_message_format" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_message_format_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_message_format" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_message_format_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_message_format" ></li>
 </ul>
</div>
