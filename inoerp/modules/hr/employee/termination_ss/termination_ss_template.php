<div id ="form_header">
 <form  method="post" id="hr_employee_termination"  name="hr_employee_termination"><span class="heading">Employee Termination </span>
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
       <ul class="column header_field"> 
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_employee_termination_id select_popup">
          Termination Id</label><?php $f->text_field_ds('hr_employee_termination_id'); ?>
         <a name="show" href="form.php?class_name=hr_employee_termination&<?php echo "mode=$mode"; ?>" class="show document_id hr_employee_termination_id">
          <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_employee_id select_popup clickable">
          Employee Id</label><?php $f->text_field_ds('employee_id') ?>
        </li>
        <li><label>Name</label><?php $f->text_field_d('employee_name'); ?> 					</li>
        <li><label>Id #</label><?php $f->text_field_d('identification_id'); ?> 					</li>
        <li><label>Date of Notification</label><?php echo $f->date_fieldAnyDay('date_of_notification', $$class->date_of_notification); ?> 					</li>
        <li><label>Reason</label><?php $f->text_field_dm('reason'); ?> 					</li>
        <li><label>Status</label><?php echo $f->select_field_from_array('status', hr_employee_termination::$status_a, $$class->status,'status'); ?> 					</li>
       </ul>
      </div>
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
        $reference_table = 'hr_employee_termination';
        $reference_id = $$class->hr_employee_termination_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>

   </div>
  </div>
  <div id ="form_line" class="form_line"><span class="heading">Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Details</a></li>
     <li><a href="#tabsLine-2">Future</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div>             <ul class="column four_column"> 
        <li><label>Projected Last Date :</label><?php echo $f->date_fieldAnyDay('projected_last_date', $$class->projected_last_date); ?> 					</li>
        <li><label>Actual Last Date :</label><?php echo $f->date_fieldAnyDay('actual_last_date', $$class->actual_last_date); ?> 	
        <li><label>Accepted Date :</label><?php echo $f->date_fieldAnyDay('accpeted_date', $$class->accpeted_date); ?> 	
        <li><label>Accepted By :</label><?php $f->text_field_d('accpeted_by_employee_id'); ?> 	
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
  <li class="headerClassName" data-headerClassName="hr_employee_termination" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_employee_termination_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_employee_termination" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_employee_termination_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_employee_termination_id" ></li>
 </ul>
</div>