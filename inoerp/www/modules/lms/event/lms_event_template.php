<div id ="form_header">
 <form  method="post" id="lms_event_header"  name="lms_event_header">
  <span class="heading"><?php echo gettext('Class / Event Schedule') ?></span>

  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic'); ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Basic-2'); ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Details'); ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('lms_event_header_id') ?>
        <a name="show" href="form.php?class_name=lms_event_header&<?php echo "mode=$mode"; ?>" class="show document_id lms_event_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_dm('title'); ?></li>
       <li><?php $f->l_date_fieldAnyDay_m('start_date', $$class->start_date); ?></li>
       <li><?php $f->l_select_field_from_array('start_time', inoform::$time_a, $$class->start_time); ?></li>
       <li><?php $f->l_date_fieldAnyDay_m('end_date', $$class->end_date); ?></li>
       <li><?php $f->l_select_field_from_array('end_time', inoform::$time_a, $$class->end_time); ?></li>
       <li><?php $f->l_text_field_dr('username'); ?></li>
       <li><?php $f->l_text_field_dr('first_name'); ?></li>
       <li><?php $f->l_text_field_dr('last_name'); ?></li>
       <li><?php echo $f->hidden_field_withId('user_id', $$class->user_id); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_text_field_d('location'); ?></li>
       <li><?php $f->l_text_field_d('url'); ?></li>
       <li><?php $f->l_text_field_d('privacy'); ?></li>
       <li><?php $f->l_text_field_d('event_color'); ?></li>
			 <li><?php $f->l_select_field_from_array('frequency_uom', lms_event_header::$frequencey_umo_a, $$class->frequency_uom) ?></li>
			 <li><?php echo $f->l_number_field('frequncy_val', $$class->frequncy_val); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div class="first_rowset"> 
				 <?php echo $f->text_area('event_details', $$class->event_details, '10', '', '', '', '', '', '', '150'); ?>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
					 <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
					 <?php
					 $reference_table = 'lms_event_header';
					 $reference_id = $$class->lms_event_header_id;
					 ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('CLass Members & Resources') ?></span>
 <form method="post" id="lms_event_line"  name="lms_event_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
				<th><?php echo gettext('Class or Group') ?></th>
        <th><?php echo gettext('Student Name') ?></th>
        <th><?php echo gettext('Resource') ?></th>
        <th><?php echo gettext('Required') ?></th>
        <th><?php echo gettext('Status') ?></th>
        <th><?php echo gettext('Actual') ?></th>
        <th><?php echo gettext('Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
					<?php
					$count = 0;
					$f = new inoform();
					foreach ($lms_event_line_object as $lms_event_line) {
					 $$class_second->username = !empty($lms_event_line->user_id) ? ino_user::find_by_id($lms_event_line->user_id)->username : '';
					 ?>         
 			 <tr class="lms_event_line<?php echo $count ?>">
 				<td><?php
						 echo ino_inline_action($$class_second->lms_event_line_id, array('lms_event_header_id' => $$class->lms_event_header_id));
						 ?>
 				</td>
 				<td><?php $f->text_field_wid2sr('lms_event_line_id', 'always_readonly'); ?></td>
				<td><?php echo $f->select_field_from_object('lms_group_header_id', lms_group_header::find_all(), 'lms_group_header_id' ,'group_name' , $$class_second->lms_group_header_id , '', 'medium'); ?></td>
 				
 				<td><?php
						 echo $f->val_field('first_name', $$class_second->first_name, '', '', 'vf_select_student_name first_name', '', '', 'lms_student_v', 'employee_name');
						 echo $f->hidden_field_withCLass('lms_student_id', $$class_second->lms_student_id, 'lms_student_id');
						 ?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></td>
 				<td><?php $f->text_field_wid2('resource_id'); ?></td>
 				<td><?php $f->checkBox_field_wid2('required_cb'); ?></td>
 				<td><?php $f->text_field_wid2('expected_status'); ?></td>
 				<td><?php $f->text_field_wid2('actual_status'); ?></td>
 				<td><?php $f->text_field_wid2('description'); ?></td>
 			 </tr>
				<?php
				$count = $count + 1;
			 }
			 ?>
      </tbody>
     </table>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="lms_event_header" ></li>
  <li class="lineClassName" data-lineClassName="lms_event_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="lms_event_header_id" ></li>
  <li class="form_header_id" data-form_header_id="lms_event_header" ></li>
  <li class="line_key_field" data-line_key_field="user_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="lms_event_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="lms_event_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="lms_event_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>