<div id ="form_header">
 <form  method="post" id="hr_compensation_element"  name="hr_compensation_element">
  <span class="heading"><?php echo gettext('Compensation Element') ?></span>
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
        <li><?php $f->l_text_field_dr_withSearch('hr_compensation_element_id') ?>
         <a name="show" href="form.php?class_name=hr_compensation_element&<?php echo "mode=$mode"; ?>" class="show document_id hr_compensation_element_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_text_field_d('element_name'); ?> </li>
        <li><?php $f->l_select_field_from_object('element_type', hr_compensation_element::compensation_element_type(), 'option_line_code', 'option_line_value', $$class->element_type, 'element_type', '', 1, $readonly1); ?> 					</li>
        <li><?php $f->l_select_field_from_object('classification', hr_compensation_element::compensation_element_class(), 'option_line_code', 'option_line_value', $$class->classification, 'classification', '', '', $readonly); ?> 					</li>
        <li><?php $f->l_select_field_from_object('category', hr_compensation_element::compensation_element_category(), 'option_line_code', 'option_line_value', $$class->category, 'category', '', 1, $readonly1); ?> 					</li>
        <li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date); ?> 	</li>
        <li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date); ?> 	</li>
        <li><?php $f->l_status_field_d('status'); ?></li>
        <li><?php $f->l_text_field_d('description'); ?> 					</li>
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
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Compensation Element Details') ?> </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Details') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Future') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_number_field_d('priority'); ?> 	</li>
       <li><?php $f->l_checkBox_field_d('recurring_cb'); ?> 	</li>
       <li><?php $f->l_checkBox_field_d('separate_check_cb'); ?> 	</li>
       <li><?php $f->l_text_field_d('frequency_months'); ?> 	</li>
       <li><?php $f->l_checkBox_field_d('standard_link_cb'); ?> 	</li>
       <li><?php $f->l_select_field_from_array('deduction_start_rule', hr_compensation_element::$deduction_start_rule_a, $$class->deduction_start_rule); ?> 	</li>
       <li><?php $f->l_select_field_from_array('deduction_rule', hr_compensation_element::$deduction_rule_a, $$class->deduction_rule); ?> 	</li>
       <li><?php $f->l_select_field_from_array('calculation_rule', hr_compensation_element::$calculation_rule_a, $$class->calculation_rule); ?> 	</li>
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