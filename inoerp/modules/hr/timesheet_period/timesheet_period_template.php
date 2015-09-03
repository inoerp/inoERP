<?php 
if(empty($$class->hr_timesheet_period_id)){
 $$class->status = 'OPEN';
}
?>
<div id ="form_all"><span class="heading"><?php echo gettext('HR Timesheet Period') ?></span>
 <form  method="post" id="hr_timesheet_period"  name="hr_timesheet_period">
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
       <li><?php $f->l_text_field_dr_withSearch('hr_timesheet_period_id'); ?>
        <a name="show" href="form.php?class_name=hr_timesheet_period&<?php echo "mode=$mode"; ?>" class="show document_id hr_timesheet_period_id"><i class='fa fa-refresh'></i></a> 
       </li>
       <li><?php $f->l_date_fieldAnyDay_m('from_date', $$class->from_date); ?></li>
       <li><?php $f->l_date_fieldAnyDay_m('to_date', $$class->to_date); ?></li>
       <li><?php $f->l_text_field_dm('timesheet_period'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_number_field_d('max_work_hour'); ?></li>
       <li><?php $f->l_number_field_d('max_billable_hour'); ?></li>
       <li><?php $f->l_select_field_from_array('status', hr_timesheet_period::$status_a,$$class->status,'status','medium' , 1); ?></li>
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
         $reference_table = 'hr_timesheet_period';
         $reference_id = $$class->hr_timesheet_period_id;
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
 </form>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_timesheet_period" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_timesheet_period_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_timesheet_period" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_timesheet_period_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_timesheet_period"></li>
 </ul>
</div>