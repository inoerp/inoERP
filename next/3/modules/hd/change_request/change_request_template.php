 <!-- 
 inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 
 This Source Code Form is subject to the terms of the Mozilla Public
   - License, v. 2.0. If a copy of the MPL was not distributed with this
   - file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 -->
 <div id ="form_all"><span class="heading"><?php echo gettext('Change Request') ?></span>
 <form method="post" id="hd_change_request"  name="hd_change_request">
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
       <li><?php $f->l_text_field_dr_withSearch('hd_change_request_id') ?>
        <a name="show" href="form.php?class_name=hd_change_request&<?php echo "mode=$mode"; ?>" class="show document_id hd_change_request_id">
         <i class='fa fa-refresh'></i></a> 
       </li> 
       <li><?php $f->l_text_field_d('request_number'); ?></li>
       <li><?php
        $f->l_text_field_d('requester_username', 'username');
        echo $f->hidden_field_withCLass('requester_user_id', $$class->requester_user_id, 'user_id');
        ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="user_id select_popup clickable">
       </li>
       <li><?php $f->l_text_field_d('requester_email', 'email'); ?></li>
       <li><?php $f->l_text_field_d('requester_phone', 'phone'); ?></li>
       <li><?php $f->l_select_field_from_object('request_type', hd_change_request::cr_type(), 'option_line_code', 'option_line_value', $$class->request_type, 'request_type'); ?></li>
       <li><?php $f->l_select_field_from_object('impact', hd_support_request::sr_impact(), 'option_line_code', 'option_line_value', $$class->impact, 'impact'); ?></li>
       <li><?php $f->l_select_field_from_object('request_category', hd_support_request::sr_category(), 'option_line_code', 'option_line_value', $$class->request_category, 'request_category'); ?></li>
       <li><?php $f->l_select_field_from_array('priority', dbObject::$position_array, $$class->priority); ?></li>
       <li><?php
        $f->l_text_field_d('support_number');
        echo $f->hidden_field_withCLass('hd_support_request_id', $$class->hd_support_request_id, 'hd_support_request_id');
        ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hd_support_request_id select_popup clickable">
       </li>
       <li><?php $f->l_text_field_d('hd_change_request_id'); ?></li>
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
         $reference_table = 'hd_change_request';
         $reference_id = $$class->hd_change_request_id;
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
     <li><a href="#tabsLine-2"><?php echo gettext('Change Plan') ?></a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Review Info') ?></a></li>
     <li><a href="#tabsLine-4"><?php echo gettext('Activity Details') ?></a></li>
     <li><a href="#tabsLine-5"><?php echo gettext('Secondary') ?></a></li>
    </ul>

    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <?php echo form::text_area('description', $$class->description, '5', '140', 1, '', 'description'); ?>
      <!--end of tab1 div three_column-->
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <ul class="column fixed_field"> 
       <li><Label>Change Plan</Label>
        <?php echo form::text_area('change_plan', $$class->change_plan, '5', '150', '', '', 'change_plan'); ?></li>
       <li><Label>Communication Plan</Label>
        <?php echo form::text_area('communication_plan', $$class->communication_plan, '5', '150', '', '', 'communication_plan'); ?></li>
       <li><Label>Rollback Plan</Label>
        <?php echo form::text_area('rollback_plan', $$class->rollback_plan, '5', '150', '', '', 'rollback_plan'); ?></li>
       <li><Label>Test Plan</Label>
        <?php echo form::text_area('test_paln', $$class->test_paln, '5', '150', '', '', 'test_paln'); ?></li>
       <li><Label>Test Results</Label>
        <?php echo form::text_area('test_results', $$class->test_results, '5', '150', '', '', 'test_results'); ?></li>
      </ul>
     </div>
     <div id="tabsLine-3"  class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_d('assignment_group'); ?></li>
       <li><?php
        $f->l_text_field_d('assigned_username', 'username');
        echo $f->hidden_field_withCLass('assigned_to_user_id', $$class->assigned_to_user_id, 'user_id');
        ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="user_id select_popup clickable">
       </li>
       <li><?php
        $f->l_text_field_d('technical_approver_username', 'username');
        echo $f->hidden_field_withCLass('technical_approver', $$class->technical_approver, 'user_id');
        ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="user_id select_popup clickable">
       </li>
       <li><?php
        $f->l_text_field_d('functional_approver_username', 'username');
        echo $f->hidden_field_withCLass('functional_approver', $$class->functional_approver, 'user_id');
        ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="user_id select_popup clickable">
       </li>
       <li><?php
        $f->l_text_field_d('dba_approver_username', 'username');
        echo $f->hidden_field_withCLass('dba_approver', $$class->dba_approver, 'user_id');
        ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="user_id select_popup clickable">
       </li>
      </ul>
     </div>
     <div id="tabsLine-4"  class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_date_fieldAnyDay('planned_start_date', $$class->planned_start_date); ?></li>
       <li><?php $f->l_date_fieldAnyDay('planned_end_date', $$class->planned_end_date); ?></li>
       <li><?php $f->l_date_fieldAnyDay('work_start_date', $$class->work_start_date); ?></li>
       <li><?php $f->l_date_fieldAnyDay('work_end_date', $$class->work_end_date); ?></li>
       <li><?php
        $f->l_text_field_d('work_completed_by_username', 'username');
        echo $f->hidden_field_withCLass('work_completed_by', $$class->work_completed_by, 'user_id');
        ?>
        <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="user_id select_popup clickable">
       </li>
      </ul>
     </div>
     <div id="tabsLine-5" class="tabContent">
      <?php echo!empty($secondary_field_stmt) ? $secondary_field_stmt : null; ?>
     </div>
    </div>
   </div>

  </div> 

</form>
</div> 

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hd_change_request" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hd_change_request_id" ></li>
  <li class="form_header_id" data-form_header_id="hd_change_request" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hd_change_request_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hd_change_request" ></li>
 </ul>
</div>