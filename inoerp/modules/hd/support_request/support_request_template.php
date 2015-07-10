<div id ="form_all"><span class="heading"><?php
  echo gettext('Support Request')
  ?></span>
 <form action=""  method="post" id="hd_support_request"  name="hd_support_request">
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
       <li><?php $f->l_text_field_dr_withSearch('hd_support_request_id') ?>
        <a name="show" href="form.php?class_name=hd_support_request&<?php echo "mode=$mode"; ?>" class="show document_id hd_support_request_id">
         <i class='fa fa-refresh'></i></a> 
       </li> 
       <li><?php $f->l_text_field_d('support_number'); ?></li>
       <li><?php
        $f->l_text_field_d('requester_username', 'username');
        echo $f->hidden_field_withCLass('requester_user_id', $$class->requester_user_id, 'user_id');
        ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="user_id select_popup clickable">
       </li>
       <li><?php $f->l_text_field_d('requester_email', 'email'); ?></li>
       <li><?php $f->l_text_field_d('requester_phone', 'phone'); ?></li>
       <li><?php $f->l_select_field_from_object('request_type', hd_support_request::sr_type(), 'option_line_code', 'option_line_value', $$class->request_type, 'request_type'); ?></li>
       <li><?php $f->l_select_field_from_object('impact', hd_support_request::sr_impact(), 'option_line_code', 'option_line_value', $$class->impact, 'impact'); ?></li>
       <li><?php $f->l_select_field_from_object('request_category', hd_support_request::sr_category(), 'option_line_code', 'option_line_value', $$class->request_category, 'request_category'); ?></li>
       <li><?php $f->l_select_field_from_array('priority', dbObject::$position_array, $$class->priority); ?></li>
       <li><?php
        $f->l_val_field_d('change_request_number',  'hd_service_request' , '' , 'service_request_number' ,'select change_request_number');
        echo $f->hidden_field_withCLass('hd_change_request_id', $$class->hd_change_request_id, 'hd_change_request_id');
        ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hd_change_request_id select_popup clickable">
       </li>
       <li><?php $f->l_text_field_d('urgency'); ?></li>
       <li><?php $f->l_select_field_from_object('escalation', hd_support_request::sr_escalation(), 'option_line_code', 'option_line_value', $$class->escalation, 'escalation'); ?></li>
       <li><?php $f->l_select_field_from_object('status', hd_support_request::sr_status(), 'option_line_code', 'option_line_value', $$class->status, 'status'); ?></li>
       <li><?php $f->l_text_field_dm('subject'); ?></li>
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
         $reference_table = 'hd_support_request';
         $reference_id = $$class->hd_support_request_id;
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

  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Request Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Description') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Assignment') ?></a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Resolution') ?></a></li>
     <li><a href="#tabsLine-4"><?php echo gettext('Closure') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <?php echo form::text_area('description', $$class->description, '5', '140', 1, '', 'description'); ?>
      <!--end of tab1 div three_column-->
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_d('assignment_group'); ?></li>
       <li><?php
        $f->l_text_field_d('assigned_username', 'username');
        echo $f->hidden_field_withCLass('assigned_to_user_id', $$class->assigned_to_user_id, 'user_id');
        ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="user_id select_popup clickable">
       </li>
      </ul>
     </div>
     <div id="tabsLine-3"  class="tabContent">
      <?php echo form::text_area('resolution_details', $$class->resolution_details, '5', '140', '', '', 'description'); ?>
     </div>
     <div id="tabsLine-4"  class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_object('close_code', hd_support_request::sr_close_code(), 'option_line_code', 'option_line_value', $$class->close_code, 'close_code'); ?></li>
       <li><?php
        $f->l_text_field_d('closed_by_username', 'username');
        echo $f->hidden_field_withCLass('closed_by_user_id', $$class->closed_by_user_id, 'user_id');
        ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="user_id select_popup clickable">
       </li>
       <li><?php $f->l_date_fieldAnyDay('closed_date', $$class->closed_date); ?></li>
      </ul>
     </div>
    </div>
   </div>

  </div> 

</form>
</div> 

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hd_support_request" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hd_support_request_id" ></li>
  <li class="form_header_id" data-form_header_id="hd_support_request" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hd_support_request_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hd_support_request" ></li>
 </ul>
</div>