<div id ="form_header">
 <form method="post" id="sys_hold"  name="sys_hold">
  <span class="heading"><?php echo gettext('System Hold') ?></span>
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
        <li><?php $f->l_text_field_dr_withSearch('sys_hold_id') ?>
         <a name="show" href="form.php?class_name=sys_hold&<?php echo "mode=$mode"; ?>" class="show document_id sys_hold_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_text_field_dm('hold_name'); ?> 					</li>
        <li><?php $f->l_text_field_dm('hold_code'); ?> 					</li>
        <li><?php $f->l_select_field_from_object('hold_type', sys_hold::hold_type(), 'option_line_code', 'option_line_value', $$class->hold_type, 'hold_type', '', 1, $readonly1); ?>              </li>
        <li><?php $f->l_status_field_d('status'); ?></li>
        <li><?php $f->l_text_field_d('description'); ?> 					</li>
        <li><?php $f->l_checkBox_field_d('manual_released_cb'); ?>   </li>
        <li><?php $f->l_select_field_from_array('access_level', option_header::$access_level_a, $$class->access_level, 'access_level', $readonly); ?>        </li>
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
         $reference_table = 'sys_hold';
         $reference_id = $$class->sys_hold_id;
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
  <li class="headerClassName" data-headerClassName="sys_hold" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_hold_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_hold" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_hold_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_hold_id" ></li>
 </ul>
</div>