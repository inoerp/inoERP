<div id ="form_header">
 <form  method="post" id="hr_approval_object"  name="hr_approval_object">
  <span class="heading"><?php echo gettext('Approval Object') ?> </span>
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
        <li><?php $f->l_text_field_dr_withSearch('hr_approval_object_id') ?>
         <a name="show" href="form.php?class_name=hr_approval_object&<?php echo "mode=$mode"; ?>" class="show document_id hr_approval_object_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_text_field_d('object_code'); ?> </li>
        <li><?php $f->l_text_field_d('object_name'); ?> </li>
        <li><?php $f->l_select_field_from_array('value_type', hr_approval_object::$value_type_a, $$class->value_type); ?> 					</li>
        <li><?php $f->l_select_field_from_array('return_type', hr_approval_object::$return_type_a, $$class->return_type); ?> 					</li>
        <li><?php $f->l_text_field_d('description'); ?> 					</li>
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
         $reference_table = 'hr_approval_object';
         $reference_id = $$class->hr_approval_object_id;
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
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Object Value') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div><label class="text_area_label"><?php echo gettext('Object Value') ?></label><?php
       echo $f->text_area_ap(array('name' => 'object_value', 'value' => $$class->object_value,
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
  <li class="headerClassName" data-headerClassName="hr_approval_object" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_approval_object_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_approval_object" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_approval_object_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_approval_object_id" ></li>
 </ul>
</div>