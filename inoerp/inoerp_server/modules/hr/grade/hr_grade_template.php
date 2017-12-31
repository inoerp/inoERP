<div id ="form_all"><span class="heading"><?php echo gettext('HR Grade') ?></span>
 <form  method="post" id="hr_grade"  name="hr_grade">
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
       <li><?php $f->l_text_field_dr_withSearch('hr_grade_id'); ?>
        <a name="show" href="form.php?class_name=hr_grade&<?php echo "mode=$mode"; ?>" class="show document_id hr_grade_id"><i class='fa fa-refresh'></i></a> 
       </li>
       <li><?php $f->l_text_field_d('grade'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_text_field_d('rank'); ?></li>
       <li><?php $f->l_select_field_from_object('hr_element_entry_tpl_header_id', hr_element_entry_tpl_header::find_all(),'hr_element_entry_tpl_header_id' ,'template_name',$$class->hr_element_entry_tpl_header_id,'hr_element_entry_tpl_header_id','medium' , 1); ?></li>
       <li><?php $f->l_text_field_d('alt_name'); ?></li>
       <li><?php $f->l_text_field_d('alt_description'); ?></li>
       <li><?php $f->l_date_fieldAnyDay('inactive_date', $$class->inactive_date); ?></li>
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
         $reference_table = 'hr_grade';
         $reference_id = $$class->hr_grade_id;
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
 </form>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_grade" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_grade_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_grade" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_grade_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_grade"></li>
 </ul>
</div>