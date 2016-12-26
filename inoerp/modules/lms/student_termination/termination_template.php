<div id ="form_header">
 <form method="post" id="lms_student_termination"  name="lms_student_termination">
  <span class="heading"><?php echo gettext('Student Termination') ?></span>
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
       <li><?php $f->l_text_field_dr_withSearch('lms_student_termination_id'); ?>
        <a name="show" href="form.php?class_name=lms_student_termination&<?php echo "mode=$mode"; ?>" class="show document_id lms_student_termination_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="lms_student_id select_popup clickable">
         <?php echo gettext('Employee Id') ?></label><?php $f->text_field_ds('employee_id') ?>
       </li>
       <li><label><?php echo gettext('Name') ?></label><?php $f->text_field_d('employee_name'); ?> 					</li>
       <li><label><?php echo gettext('Id #') ?></label><?php $f->text_field_d('identification_id'); ?> 					</li>
       <li><label><?php echo gettext('Date of Notification') ?></label><?php echo $f->date_fieldAnyDay('date_of_notification', $$class->date_of_notification); ?> 					</li>
       <li><label><?php echo gettext('Reason') ?></label><?php $f->text_field_dm('reason'); ?> 					</li>
       <li><label><?php echo gettext('Status') ?></label><?php echo $f->select_field_from_array('status', lms_student_termination::$status_a, $$class->status, 'status'); ?> 					</li>
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
        $reference_table = 'lms_student_termination';
        $reference_id = $$class->lms_student_termination_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>

   </div>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Details') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Future') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div>             
       <ul class="column header_field"> 
        <li><?php $f->l_date_fieldAnyDay('projected_last_date', $$class->projected_last_date); ?> 					</li>
        <li><?php $f->l_date_fieldAnyDay('actual_last_date', $$class->actual_last_date); ?> 	
        <li><?php $f->l_date_fieldAnyDay('accpeted_date', $$class->accpeted_date); ?> 	
        <li><?php $f->l_text_field_d('accpeted_by_employee_id'); ?> 	
       </ul>
      </div> 
     </div> 
     <div id="tabsLine-2"  class="tabContent">

     </div>
    </div>
   </div> 
  </div> 
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="lms_student_termination" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="lms_student_termination_id" ></li>
  <li class="form_header_id" data-form_header_id="lms_student_termination" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="lms_student_termination_id" ></li>
  <li class="btn1DivId" data-btn1DivId="lms_student_termination_id" ></li>
 </ul>
</div>