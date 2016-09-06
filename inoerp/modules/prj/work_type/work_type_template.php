<div id ="form_all"><span class="heading"><?php echo gettext('Project Work Type') ?></span>
 <form method="post" id="prj_work_type"  name="prj_work_type">
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
       <li><?php $f->l_text_field_dr_withSearch('prj_work_type_id') ?>
        <a name="show" href="form.php?class_name=prj_work_type&<?php echo "mode=$mode"; ?>" class="show document_id prj_work_type_id"><i class='fa fa-refresh'></i></a> 
       </li>
       <li><?php $f->l_text_field_d('work_type'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></li>
       <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li>
       <li><?php $f->l_checkBox_field_d('billable_cb'); ?>   </li>


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
         $reference_table = 'prj_work_type';
         $reference_id = $$class->prj_work_type_id;
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

  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Work Type Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Control Options') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div > 
       <ul class="column header_field two_column_form"> 
        <li><?php $f->l_checkBox_field_d('unassigned_cb'); ?>         </li>
        <li><?php $f->l_checkBox_field_d('non_worked_cb'); ?>         </li>
        <li><?php $f->l_text_field_d('utilization_type'); ?></li>
        <li><?php $f->l_text_field_d('utilization_percentage'); ?></li>
        <li><?php $f->l_select_field_from_array('tp_amount_type', prj_work_type::$tp_amount_type_a , $$class->tp_amount_type ,'tp_amount_type' ); ?></li>
               <li><?php $f->l_checkBox_field_d('capitalizable_cb'); ?>   </li>
       <li><?php $f->l_checkBox_field_d('training_cb'); ?>   </li>
       <li><?php $f->l_checkBox_field_d('shadow_resource_cb'); ?>         </li>
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <!--end of tab5-->
    </div>

   </div> 
  </div> 
 </form>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="prj_work_type" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_work_type_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_work_type" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_work_type_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_work_type"></li>
 </ul>
</div>