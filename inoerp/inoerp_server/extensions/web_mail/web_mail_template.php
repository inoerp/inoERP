<?php
$mode = 2;
if (!empty($_GET['email'])) {
 $$class->email_id = $_GET['email'];
}
$reference_table = !empty($_GET['reference_table']) ? $_GET['reference_table'] : '';
$reference_id = !empty($_GET['reference_id']) ? $_GET['reference_id'] : '';
?>
<div id ="web_mail_divId">
 <form  method="post" id="web_mail"  name="web_mail">
  <span class="heading"><?php echo gettext('Web eMail') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Message') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><label><?php echo gettext('Email Id') ?></label><?php echo $f->text_field('email_id', $$class->email_id, '', 'email_id', 'email_id', 1, ''); ?></li>
       <li><label><?php echo gettext('CC Email') ?></label><?php echo $f->text_field('cc_email', $$class->cc_email, '', 'cc_email', 'cc_email', '', ''); ?></li>
       <li><label><?php echo gettext('BCC Email') ?></label><?php echo $f->text_field('bcc_email', $$class->bcc_email, '', 'bcc_email', 'bcc_email', '', ''); ?></li>
       <li><label><?php echo gettext('Subject') ?></label><?php echo $f->text_field('subject', $$class->subject, '', 'subject', 'subject', 1, ''); ?></li>
       <li><label><?php echo gettext('Copy Me') ?></label><?php echo $f->checkBox_field_d('send_me_copy_cb'); ?></li>
       <li><label><?php echo gettext('Create Note') ?></label><?php echo $f->checkBox_field_d('create_comment_cb'); ?></li>
       <?php echo $f->hidden_field_withId('reference_table', $reference_table); ?>
       <?php echo $f->hidden_field_withId('reference_id', $reference_id); ?>
      </ul>
      <div><label for='message'>Message</label><?php echo $f->text_area('message', '', '5', 'message', 'form-control', 1) ?></div>
      <div>
       <button form="web_mail" name="send_mail" id="save" class="btn btn-info active submit button">Send Mail</button>
      </div>
     </div>


     <div id="tabsHeader-2" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
    </div>
   </div>
  </div>
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="web_mail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="form_header_id" data-form_header_id="web_mail" ></li>
 </ul>
</div>