<div id ="form_all"><span class="heading"><?php echo gettext('Student Attendance') ?></span>
 <form  method="post" id="lms_attendance"  name="lms_attendance">
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field two_column_form"> 
       <li><?php $f->l_text_field_dr_withSearch('lms_attendance_id'); ?>
        <a name="show" href="form.php?class_name=lms_attendance&<?php echo "mode=$mode"; ?>" class="show document_id lms_attendance_id"><i class='fa fa-refresh'></i></a> 
       </li>
       <li><?php $f->l_date_fieldAnyDay_m('date', $$class->date); ?></li>
       <li><label><?php echo gettext('Punch In') ?></label><?php echo $f->dateTime_field('punch_in', $$class->punch_in); ?></li>
       <li><?php $f->l_text_field_d('punch_in_note'); ?></li>
       <li><label>Punch Out</label><?php echo $f->dateTime_field('punch_out', $$class->punch_out); ?></li>
       <li><?php $f->l_text_field_d('punch_out_note'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_text_field_dr('hr_employee_id'); ?></li>
       <li><?php $f->l_text_field_dr('employee_name'); ?></li>
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
         $reference_table = 'lms_attendance';
         $reference_id = $$class->lms_attendance_id;
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
  <li class="headerClassName" data-headerClassName="lms_attendance" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="lms_attendance_id" ></li>
  <li class="form_header_id" data-form_header_id="lms_attendance" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="lms_attendance_id" ></li>
  <li class="btn1DivId" data-btn1DivId="lms_attendance"></li>
 </ul>
</div>