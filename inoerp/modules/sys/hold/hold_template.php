<div id ="form_header">
 <form action=""  method="post" id="sys_hold"  name="sys_hold"><span class="heading">System Hold </span>
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
         <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sys_hold_id select_popup clickable">
          Hold Id : </label><?php $f->text_field_dsr('sys_hold_id') ?>
        <a name="show" href="form.php?class_name=sys_hold&<?php echo "mode=$mode"; ?>" class="show document_id sys_hold_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label>Hold Name :</label><?php $f->text_field_dm('hold_name'); ?> 					</li>
        <li><label>Hold Code :</label><?php $f->text_field_dm('hold_code'); ?> 					</li>
        <li><label>Type :</label>
         <?php echo $f->select_field_from_object('hold_type', sys_hold::hold_type(), 'option_line_code', 'option_line_value', $$class->hold_type, 'hold_type', '', 1, $readonly1); ?>              </li>
        <li><label>Status : </label><?php echo form::status_field($$class->status, $readonly); ?></li>
        <li><label>Description :</label><?php $f->text_field_dl('description'); ?> 					</li>
        <li><label>Allow Manual Release :</label>  <?php echo $f->checkBox_field_d('manual_released_cb'); ?>   </li>
        <li><label>Access Level* : </label>
         <?php echo $f->select_field_from_array('access_level', option_header::$access_level_a, $$class->access_level, 'access_level', $readonly); ?>
        </li>
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