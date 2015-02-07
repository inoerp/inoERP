<div id ="form_header">
 <form action=""  method="post" id="hr_job"  name="hr_job"><span class="heading">Job </span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic Info</a></li>
     <li><a href="#tabsHeader-2">Requirements</a></li>
     <li><a href="#tabsHeader-3">Attachments</a></li>
     <li><a href="#tabsHeader-4">Notes</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li> 
         <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_job_id select_popup clickable">
          job Id</label><?php $f->text_field_ds('hr_job_id') ?>
         <a name="show" href="form.php?class_name=hr_job&<?php echo "mode=$mode"; ?>" class="show document_id hr_job_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label>Job Name</label><?php $f->text_field_d('job_name'); ?></li>
        <li><label>Job Code</label><?php $f->text_field_d('job_code'); ?></li>
        <li><label>Start Date</label><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?></li>
        <li><label>End Date</label><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?></li>
        <li><label>Position Type</label><?php echo $f->select_field_from_object('position_type', hr_job::job_position_type(), 'option_line_code', 'option_line_value', $$class->position_type, '', 'position_type', '', $readonly); ?></li>
        <li><label>Status</label><?php echo form::status_field($$class->status, $readonly); ?></li>
        <li><label>Description</label><?php $f->text_field_dl('description'); ?></li>
        <li><label>Functional Area</label><?php echo $f->select_field_from_object('functional_area', hr_job::job_functional_area(), 'option_line_code', 'option_line_value', $$class->functional_area, '', 'functional_area', '', $readonly); ?></li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><label>Education</label><?php $f->text_field_dl('min_education'); ?> 					</li>
        <li><label>Experience</label><?php $f->text_field_dl('min_experience'); ?> 					</li>
        <li><label>Technology</label><?php $f->text_field_dl('technology'); ?> 					</li>
        <li><label>Skill Set</label><?php $f->text_field_dl('skillset'); ?> 					</li>
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
  <div id ="form_line" class="form_line"><span class="heading">job Details & Responsibility </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Job Details</a></li>
     <li><a href="#tabsLine-2">Responsibility</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div><label class="text_area_label">Job Details  :</label><?php
       echo $f->text_area_ap(array('name' => 'job_details', 'value' => $$class->job_details,
        'row_size' => '10', 'column_size' => '90'));
       ?> 	
      </div> 
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div><label class="text_area_label">Primary Responsibility  :</label><?php
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