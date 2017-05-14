<div id ="form_header">
 <form method="post" id="sys_notification"  name="sys_notification">
  <span class="heading"><?php echo gettext('Notification') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Requirements') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_dr_withSearch('sys_notification_id') ?>
         <a name="show" href="form.php?class_name=sys_notification&<?php echo "mode=$mode"; ?>" class="show document_id sys_notification_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_text_field_dr('notification_type'); ?> 					</li>
        <li><?php $f->l_text_field_dr('from_user'); ?> 					</li>
        <li><?php $f->l_text_field_dr('to_user'); ?> 					</li>
        <li><?php $f->l_date_fieldAnyDay_r('start_date', $$class->start_date); ?> 	</li>
        <li><?php $f->l_select_field_from_array('status', sys_notification::$status_a, $$class->status, '', '', '', '', 1); ?></li>
        <li><?php $f->l_text_field_dr('notification_subject'); ?> 					</li>
        <li><?php $f->l_select_field_from_array('notification_action', $$class->notification_action_a, ''); ?></li>
       </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_dr('to_email'); ?> </li>
        <li><?php $f->l_text_field_dr('mail_status'); ?> </li>
        <li><?php $f->l_text_field_dr('responder'); ?> </li>
        <li><?php $f->l_date_fieldAnyDay_r('due_date', $$class->due_date); ?> 	</li>
        <li><?php $f->l_date_fieldAnyDay_r('end_date', $$class->end_date); ?> 	</li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'sys_notification';
         $reference_id = $$class->sys_notification_id;
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
  <div id ="form_line" class="form_line"><span class="heading">Details & References </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Notification Details') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Responder Comment') ?> </a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('References') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> <?php
       echo $$class->text_field1;
       echo $f->hidden_field('text_field1', $$class->text_field1);
       ?> 	  </div> 
     </div> 
     <div id="tabsLine-2" class="tabContent">
      <div><?php echo $f->text_area_ap(array('name' => 'responder_comment', 'value' => $$class->responder_comment, 'row_size' => '10', 'column_size' => '90')); ?>	
      </div> 
     </div> 
     <div id="tabsLine-3"  class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_dr('reference_key_name'); ?> 					</li>
        <li><?php $f->l_text_field_dr('reference_key_value'); ?> 					</li>
        <li><?php $f->l_text_field_dr('user_key_name'); ?> 					</li>
        <li><?php $f->l_text_field_dr('user_key_value'); ?> 					</li>
        <li><label><?php echo gettext('Reference Doc') ?></label><?php echo $$class->ref_doc_stmt; ?> 					</li>
        <li><?php $f->l_text_field_dr('from_user_id'); ?> 					</li>
        <li><?php $f->l_text_field_dr('to_user_id'); ?> 					</li>
        <li><?php $f->l_text_field_dr('notification_name'); ?> 					</li>
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
  <li class="headerClassName" data-headerClassName="sys_notification" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_notification_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_notification" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_notification_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_notification_id" ></li>
 </ul>
</div>