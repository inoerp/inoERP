<div id ="form_header">
 <form action=""  method="post" id="sys_program_schedule"  name="sys_program_schedule">
  <span class="heading">Program Schedule </span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php
       $f = new inoform();
       echo gettext('Basic Info')
       ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('sys_program_schedule_id') ?>
        <a name="show" href="form.php?class_name=sys_program_schedule&<?php echo "mode=$mode"; ?>" class="show document_id sys_program_schedule_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_dm('program_name'); ?> 					</li>
       <li><?php $f->l_text_field_dm('program_class_name'); ?> 					</li>
       <li><?php $f->l_text_field_d('module_name'); ?> 					</li>
       <li><?php $f->l_select_field_from_array('frequency_uom', sys_program_schedule::$frequency_uom_a, $$class->frequency_uom, 'frequency_uom', '', 1); ?> 					</li>
       <li><?php $f->l_text_field_d('frequency_value'); ?> 					</li>
       <li><?php $f->l_dateTime_field('start_date_time', $$class->start_date_time); ?> 					</li>
       <li><?php $f->l_checkBox_field_d('one_time_cb'); ?> 					</li>
       <li><?php $f->l_checkBox_field_d('increase_date_parameter_cb'); ?> 					</li>
       <li><?php $f->l_text_field_d('description'); ?> 					</li>
       <li><?php $f->l_status_field_d('status'); ?> 					</li>
       <li><?php $f->l_text_field_d('output_path'); ?> 					</li>
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
         $reference_table = 'sys_program_schedule';
         $reference_id = $$class->sys_program_schedule_id;
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
  <span class="heading"><?php echo gettext('Other Details') ?></span>
  <div id ="form_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Entered Parameters') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Day Calendar') ?></a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Date Calendar') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <?php echo form::text_area('parameter', $$class->parameter, '10', '150', '', '', '', 1); ?>
     </div>
     <div id="tabsLine-2" class="tabContent">
      <?php echo form::text_area('parameter', $$class->parameter, '10', '150', '', '', '', 1); ?>
     </div>
     <div id="tabsLine-3" class="tabContent">
      <?php echo form::text_area('parameter', $$class->parameter, '10', '150', '', '', '', 1); ?>
     </div>
    </div>
   </div>
  </div>
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_program_schedule" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_program_schedule_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_program_schedule" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedadeId" data-docHedadeId="sys_program_schedule_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_program_schedule_id" ></li>
 </ul>
</div>