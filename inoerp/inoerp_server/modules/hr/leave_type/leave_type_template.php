<div id ="form_header">
 <form method="post" id="hr_leave_type"  name="hr_leave_type">
  <span class="heading"><?php echo gettext('Leave Type') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_dr_withSearch('hr_leave_type_id') ?>
         <a name="show" href="form.php?class_name=hr_leave_type&<?php echo "mode=$mode"; ?>" class="show document_id hr_leave_type_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_text_field_dm('leave_type'); ?> 
        <li><?php $f->l_select_field_from_object('leave_category', hr_leave_type::leave_category(), 'option_line_code', 'option_line_value', $$class->leave_category, 'leave_category', '', 1, $readonly1) ?></li>
        <li><?php $f->l_status_field_d('status'); ?> </li>
        <li><?php $f->l_text_field_d('description'); ?> 	</li>
       </ul>
      </div>
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
         $reference_table = 'hr_leave_type';
         $reference_id = $$class->hr_leave_type_id;
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
  <div id ="form_line" class="form_line">
   <span class="heading"><?php echo gettext('Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Details') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Future') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="column four_column"> 
       <li><?php $f->l_checkBox_field_d('allow_carry_forward_cb'); ?> 					</li>
       <li><?php $f->l_checkBox_field_d('auto_convert_salary_cb'); ?> 					</li>
       <li><?php $f->l_checkBox_field_d('allow_advance_cb'); ?> 					</li>
       <li><?php $f->l_checkBox_field_d('lwp_cb'); ?> 					</li>
       <li><?php $f->l_text_field_d('carry_forward_per_year'); ?> 					</li>
       <li><?php $f->l_text_field_d('maximum_accumulation'); ?> 					</li>
       <li><?php $f->l_text_field_d('default_reason'); ?> 					</li>
      </ul>
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
  <li class="headerClassName" data-headerClassName="hr_leave_type" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_leave_type_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_leave_type" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_leave_type_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_leave_type_id" ></li>
 </ul>
</div>