<div id ="form_all"><span class="heading"><?php echo gettext('Task Type') ?></span>
 <form method="post" id="adm_task_type"  name="adm_task_type">
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
        <li><?php $f->l_text_field_dr_withSearch('adm_task_type_id') ?>
         <a name="show" href="form.php?class_name=adm_task_type&<?php echo "mode=$mode"; ?>" class="show document_id adm_task_type_id"><i class='fa fa-refresh'></i></a> 
        </li> 
        <li><?php $f->l_text_field_d('task_type'); ?></li>
        <li><?php $f->l_select_field_from_array('access_level', option_header::$access_level_a, $$class->access_level, 'access_level', '', '', $readonly); ?>					</li>
        <li><?php $f->l_text_field_d('description'); ?></li>
        <li><?php $f->l_date_fieldAnyDay('from_date', $$class->from_date); ?></li>
        <li><?php $f->l_date_fieldAnyDay('to_date', $$class->to_date); ?></li>
        <li><?php $f->l_select_field_from_object('process_flow_header_id', sys_process_flow_header::find_all(),'sys_process_flow_header_id','process_flow', $$class->process_flow_header_id,'process_flow_header_id'); ?></li>
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
         $reference_table = 'adm_task_type';
         $reference_id = $$class->adm_task_type_id;
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

  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Task Type Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div > 
       <ul class="column header_field"> 
        <li><?php $f->l_checkBox_field_d('send_notification_cb'); ?></li> 
        <li><?php $f->l_checkBox_field_d('schedule_cb'); ?></li> 
        <li><?php $f->l_select_field_from_object('effort_uom_id',uom::find_all(),'uom_id','uom_name', $$class->effort_uom_id,'effort_uom_id'); ?></li> 
        <li><?php $f->l_text_field_d('effort_value'); ?></li> 
        </li>
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
    </div>

   </div> 
  </div> 
 </form>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="adm_task_type" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="adm_task_type_id" ></li>
  <li class="form_header_id" data-form_header_id="adm_task_type" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="adm_task_type_id" ></li>
  <li class="btn1DivId" data-btn1DivId="adm_task_type"></li>
 </ul>
</div>