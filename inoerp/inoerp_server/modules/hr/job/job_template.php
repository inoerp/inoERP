<div id ="form_header">
 <form  method="post" id="hr_job"  name="hr_job">
  <span class="heading"><?php echo gettext('Job') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Basics-2') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
     
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('hr_job_id') ?>
        <a name="show" href="form.php?class_name=hr_job&<?php echo "mode=$mode"; ?>" class="show document_id hr_job_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('job_name'); ?></li>
       <li><?php $f->l_text_field_d('job_code'); ?></li>
       <li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date) ?></li>
       <li><?php $f->l_date_fieldAnyDay('end_date', $$class->end_date) ?></li>
       <li><?php $f->l_select_field_from_object('position_type', hr_job::job_position_type(), 'option_line_code', 'option_line_value', $$class->position_type, 'position_type', '', '', $readonly); ?></li>
       <li><?php $f->l_status_field_d('status'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_select_field_from_object('functional_area', hr_job::job_functional_area(), 'option_line_code', 'option_line_value', $$class->functional_area, '', 'functional_area', '', $readonly); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
       <ul class="column header_field">
        <li><?php $f->l_select_field_from_array('job_usage', hr_job::$usage_a, $$class->job_usage); ?></li>
        <li><?php $f->l_select_field_from_object('group_hr_job_id', hr_job::find_all(), 'hr_job_id', 'job_name', $$class->group_hr_job_id, 'group_hr_job_id', '', '', $readonly); ?></li>
        <li><?php $f->l_text_field_d('min_education'); ?></li>
        <li><?php $f->l_text_field_d('min_experience'); ?></li>
        <li><?php $f->l_text_field_d('technology'); ?></li>
        <li><?php $f->l_text_field_d('skillset'); ?></li>
        <li><?php $f->l_select_field_from_array('job_level', range(0,50), $$class->job_level , 'job_level'); ?></li>
       </ul>
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
         $reference_table = 'hr_job';
         $reference_id = $$class->hr_job_id;
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
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Job Details & Responsibility') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Job Details') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Responsibility') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div><label class="text_area_label"><?php echo gettext('Job Details') ?></label><?php
       echo $f->text_area_ap(array('name' => 'job_details', 'value' => $$class->job_details,
        'row_size' => '10', 'column_size' => '90'));
       ?> 	
      </div> 
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div><label class="text_area_label"><?php echo gettext('Primary Responsibility') ?></label><?php
       echo $f->text_area_ap(array('name' => 'primary_responsibility', 'value' => $$class->primary_responsibility,
        'row_size' => '10', 'column_size' => '90'));
       ?> 	
      </div> 
     </div>
    </div>
   </div> 
  </div> 
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_job" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_job_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_job" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_job_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_job_id" ></li>
 </ul>
</div>
