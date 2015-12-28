<div id ="form_all"><span class="heading"><?php   echo gettext('Service Request')  ?></span>
 <form method="post" id="hd_service_request"  name="hd_service_request">
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Request Details') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Secondary') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-5"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('hd_service_request_id') ?>
        <a name="show" href="form.php?class_name=hd_service_request&<?php echo "mode=$mode"; ?>" class="show document_id hd_service_request_id">
         <i class='fa fa-refresh'></i></a> 
       </li> 
       <li><?php $f->l_text_field_d('service_request_number'); ?></li>
       <li><?php
        $f->l_text_field_d('requester_username', 'username');
        echo $f->hidden_field_withCLass('requester_user_id', $$class->requester_user_id, 'user_id');
        ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="user_id select_popup clickable">
       </li>
       <li><?php $f->l_text_field_d('requester_email', 'email'); ?></li>
       <li><?php $f->l_text_field_d('requester_phone', 'phone'); ?></li>
       <li><label class="auto_complete"><?php echo gettext('Customer Name') ?></label><?php
        echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id);
        echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', '', $readonly1);
        ?>
        <i class="ar_customer_id select_popup clickable fa fa-search"></i></li>
       <li><label class="auto_complete"><?php echo gettext('Customer Number') ?></label><?php $f->text_field_d('customer_number'); ?></li>
       <li><label><?php echo gettext('Item Number') ?></label><?php
        echo $f->hidden_field_withId('item_id_m', $$class->item_id_m);
        $f->text_field_dm('item_number', 'select_item_number');
        echo $f->hidden_field_withCLass('shippable_cb', '1', 'popup_value');
        ?><i class="select_item_number select_popup clickable fa fa-search"></i>
       </li>
       <li><label><?php echo gettext('Serial Number') ?></label><?php
        echo $f->hidden_field_withId('inv_serial_number_id', $$class->inv_serial_number_id);
        $f->text_field_dm('serial_number', 'select_serial_number');
        echo $f->hidden_field_withCLass('serial_status', 'OUT_STORE', 'popup_value');
        echo $f->hidden_field_withCLass('serial_item_id_m', $$class->item_id_m, 'item_id_m');
        ?><i class="select_serial_number select_popup clickable fa fa-search"></i>
       </li>
       <li><?php $f->l_select_field_from_object('status', hd_service_request::sr_status(), 'option_line_code', 'option_line_value', $$class->status, 'status'); ?></li>
       <li><?php $f->l_text_field_dm('problem_summary'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_select_field_from_object('request_type', hd_service_request::sr_type(), 'option_line_code', 'option_line_value', $$class->request_type, 'request_type'); ?></li>
       <li><?php $f->l_select_field_from_object('impact', hd_service_request::sr_impact(), 'option_line_code', 'option_line_value', $$class->impact, 'impact'); ?></li>
       <li><?php $f->l_select_field_from_object('request_category', hd_service_request::sr_category(), 'option_line_code', 'option_line_value', $$class->request_category, 'request_category'); ?></li>
       <li><?php $f->l_select_field_from_array('priority', dbObject::$position_array, $$class->priority); ?></li>
       <li><?php $f->l_text_field_d('urgency'); ?></li>
       <li><?php $f->l_select_field_from_object('escalation', hd_service_request::sr_escalation(), 'option_line_code', 'option_line_value', $$class->escalation, 'escalation'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> <?php echo!empty($secondary_field_stmt) ? $secondary_field_stmt : null; ?> </div>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-5" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'hd_service_request';
         $reference_id = $$class->hd_service_request_id;
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
     <li><a href="#tabsLine-1"><?php echo gettext('Problem Details') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Assignment') ?></a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Resolution') ?></a></li>
     <li><a href="#tabsLine-4"><?php echo gettext('Closure') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <?php echo form::text_area('problem_details', $$class->problem_details, '5', '140', 1, '', 'problem_details'); ?>
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
       <li><?php $f->l_select_field_from_object('close_code', hd_service_request::sr_close_code(), 'option_line_code', 'option_line_value', $$class->close_code, 'close_code'); ?></li>
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
  <li class="headerClassName" data-headerClassName="hd_service_request" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hd_service_request_id" ></li>
  <li class="form_header_id" data-form_header_id="hd_service_request" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hd_service_request_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hd_service_request" ></li>
 </ul>
</div>