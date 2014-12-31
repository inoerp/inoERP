<div id ="form_header">
 <form action=""  method="post" id="hr_leave_type"  name="hr_leave_type"><span class="heading">Leave Type </span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic Info</a></li>
     <li><a href="#tabsHeader-2">Attachments</a></li>
     <li><a href="#tabsHeader-3">Notes</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column four_column"> 
        <li> 
         <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_leave_type_id select_popup clickable">
          Leave Type Id : </label><?php $f->text_field_ds('hr_leave_type_id') ?>
         <a name="show" href="form.php?class_name=hr_leave_type&<?php echo "mode=$mode"; ?>" class="show document_id hr_leave_type_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label>Leave Type :</label><?php $f->text_field_dm('leave_type'); ?> 
        <li><label>Category  :</label>
         <?php echo $f->select_field_from_object('leave_category', hr_leave_type::leave_category(), 'option_line_code', 'option_line_value', $$class->leave_category, 'leave_category', '', 1, $readonly1) ?></li>
        <li><label>Status : </label><?php echo form::status_field($$class->status, $readonly); ?> </li>
        <li><label>Description :</label><?php $f->text_field_dl('description'); ?> 	</li>
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
  <div id ="form_line" class="form_line"><span class="heading">Details  </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Details</a></li>
     <li><a href="#tabsLine-2">Future</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="column four_column"> 
       <li><label>Allow Carry Forward :</label><?php $f->checkBox_field_d('allow_carry_forward_cb'); ?> 					</li>
       <li><label>Auto Convert Salary :</label><?php $f->checkBox_field_d('auto_convert_salary_cb'); ?> 					</li>
       <li><label>Allow Advance :</label><?php $f->checkBox_field_d('allow_advance_cb'); ?> 					</li>
       <li><label>Leave w/o Pay :</label><?php $f->checkBox_field_d('lwp_cb'); ?> 					</li>
       <li><label>Carry Forward/Year :</label><?php $f->text_field_d('carry_forward_per_year'); ?> 					</li>
       <li><label>Max. Accumulation :</label><?php $f->text_field_d('maximum_accumulation'); ?> 					</li>
       <li><label>Default Reason :</label><?php $f->text_field_dl('default_reason'); ?> 					</li>
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