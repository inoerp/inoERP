<div id ="form_header">
 <form  method="post" id="hr_position"  name="hr_position">
  <span class="heading"><?php echo gettext('Position Header') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Terms') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('hr_position_id') ?>
        <a name="show" href="form.php?class_name=hr_position" class="show hr_position_id clickable">	
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('position_name'); ?></li>
       <li><?php $f->l_select_field_from_object('org_id', org::find_all(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?> 					</li>
       <li><?php $f->l_select_field_from_object('job_id', hr_job::find_all(), 'hr_job_id', 'job_name', $$class->job_id, '', 'job_id', '', $readonly); ?>              </li>
       <li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date) ?></li>
       <li><?php $f->l_date_fieldAnyDay('end_date', $$class->end_date) ?></li>
       <li><?php $f->l_status_field_d('position_status'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_d('headcount'); ?> </li>
        <li><?php $f->l_text_field_d('grade_id'); ?> </li>
        <li><?php $f->l_text_field_d('payroll_id'); ?> </li>
        <li><?php $f->l_text_field_d('salary_basis'); ?> </li>
        <li><?php $f->l_text_field_d('working_hours'); ?> </li>
        <li><?php $f->l_text_field_d('wh_frequency'); ?> </li>
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
         $reference_table = 'hr_position';
         $reference_id = $$class->hr_position_id;
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
  <div id ="form_line" class="form_line"><span class="heading">Line Data </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Details') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Future') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div><label class="text_area_label"><?php echo gettext('Position Details') ?></label><?php
       echo $f->text_area_ap(array('name' => 'position_details', 'value' => $$class->position_details,
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
  <li class="headerClassName" data-headerClassName="hr_position" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_position_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_position" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_position_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_position_id" ></li>
 </ul>
</div>