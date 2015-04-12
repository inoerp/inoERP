<div id ="form_header">
 <form action=""  method="post" id="extn_contact"  name="extn_contact">
  <span class="heading">Contact </span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('extn_contact_id') ?>
        <a name="show" href="form.php?class_name=extn_contact&<?php echo "mode=$mode"; ?>" class="show document_id extn_contact_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_dm('contact_name'); ?> 					</li>
       <li><?php $f->l_text_field_dm('last_name'); ?> 					</li>
       <li><?php $f->l_text_field_d('first_name'); ?> 					</li>
       <li><?php $f->l_text_field_d('middle_name'); ?> 					</li>
       <li><?php $f->l_text_field_d('email_id'); ?> 					</li>
       <li><?php $f->l_text_field_d('job_titile'); ?> 					</li>
       <li><?php $f->l_text_field_d('type'); ?> 					</li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'extn_contact';
         $reference_id = $$class->extn_contact_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
    </div>

   </div>
  </div>
  <span class="heading"><?php echo gettext('Other Details') ?></span>
  <div id ="form_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Numbers') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Others') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_d('mobile_number'); ?> 					</li>
        <li><?php $f->l_text_field_d('office_number'); ?> 					</li>
        <li><?php $f->l_text_field_d('contact_number2'); ?> 					</li>
        <li><?php $f->l_text_field_d('fax_no'); ?> 					</li>
       </ul>
     </div>
     <div id="tabsLine-2" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field">
        <li><?php $f->l_text_field_d('email_id2'); ?> 					</li>
        <li><?php $f->l_text_field_d('timezone'); ?> 					</li>
        <li><?php $f->l_text_field_d('time_to_contact'); ?> 					</li>
       </ul>
      </div>
     </div>
    </div>

   </div>
  </div>
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="extn_contact" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="extn_contact_id" ></li>
  <li class="form_header_id" data-form_header_id="extn_contact" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedadeId" data-docHedadeId="extn_contact_id" ></li>
  <li class="btn1DivId" data-btn1DivId="extn_contact_id" ></li>
 </ul>
</div>