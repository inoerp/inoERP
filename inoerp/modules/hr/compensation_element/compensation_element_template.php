<div id ="form_header">
 <form action=""  method="post" id="hr_compensation_element"  name="hr_compensation_element">
  <span class="heading">Compensation Element</span>
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
        <li> 
         <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_compensation_element_id select_popup clickable">
          Header Id</label><?php $f->text_field_ds('hr_compensation_element_id') ?>
         <a name="show" href="form.php?class_name=hr_compensation_element&<?php echo "mode=$mode"; ?>" class="show document_id hr_compensation_element_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label>Element Name</label><?php $f->text_field_d('element_name'); ?> 					</li>
        <li><label>Type</label><?php echo $f->select_field_from_object('element_type', hr_compensation_element::compensation_element_type(), 'option_line_code', 'option_line_value', $$class->element_type, 'element_type', '', 1, $readonly1); ?> 					</li>
        <li><label>Class</label><?php echo $f->select_field_from_object('classification', hr_compensation_element::compensation_element_class(), 'option_line_code', 'option_line_value', $$class->classification, 'classification', '', '', $readonly); ?> 					</li>
        <li><label>Category</label><?php echo $f->select_field_from_object('category', hr_compensation_element::compensation_element_category(), 'option_line_code', 'option_line_value', $$class->category, 'category', '', 1, $readonly1); ?> 					</li>
        <li><label>Start Date</label><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?> 	</li>
        <li><label>End Date</label><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?> 	</li>
        <li><label>Status</label><?php $f->status_field_d('status'); ?></li>
        <li><label>Description</label><?php $f->text_field_dl('description'); ?> 					</li>
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
         $reference_table = 'hr_compensation_element';
         $reference_id = $$class->hr_compensation_element_id;
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
  <div id ="form_line" class="form_line"><span class="heading">Compensation Element Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Details</a></li>
     <li><a href="#tabsLine-2">Future</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="column four_column"> 
       <li><label>Priority :</label><?php echo $f->number_field('priority', $$class->priority); ?> 	</li>
       <li><label>Recurring :</label><?php echo $f->checkBox_field('recurring_cb', $$class->recurring_cb); ?> 	</li>
       <li><label>Separate Check :</label><?php echo $f->checkBox_field('separate_check_cb', $$class->separate_check_cb); ?> 	</li>
       <li><label>Frequency Months :</label><?php echo $f->text_field_d('frequency_months'); ?> 	</li>
       <li><label>Standard Link :</label><?php echo $f->checkBox_field('standard_link_cb', $$class->standard_link_cb); ?> 	</li>
       <li><label>Deduction Start :</label>	
        <?php echo $f->select_field_from_array('deduction_start_rule', hr_compensation_element::$deduction_start_rule_a, $$class->deduction_start_rule); ?> 	</li>
       <li><label>Deduction Rule :</label>
        <?php echo $f->select_field_from_array('deduction_rule', hr_compensation_element::$deduction_rule_a, $$class->deduction_rule); ?> 	</li>
       <li><label>Earning Rule :</label>
        <?php echo $f->select_field_from_array('calculation_rule', hr_compensation_element::$calculation_rule_a, $$class->calculation_rule); ?> 	</li>
      </ul>
     </div> 
    </div>
   </div> 
  </div> 
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_compensation_element" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_compensation_element_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_compensation_element" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_compensation_element_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_compensation_element_id" ></li>
 </ul>
</div>