<div id ="form_header">
 <form  method="post" id="hr_event_header"  name="hr_event_header">
  <span class="heading"><?php echo gettext('Event') ?></span>

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
       <li><?php $f->l_text_field_dr_withSearch('hr_event_header_id') ?>
        <a name="show" href="form.php?class_name=hr_event_header&<?php echo "mode=$mode"; ?>" class="show document_id hr_event_header_id">
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
      <ul class="column header_field two_column_form"> 
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_text_field_d('location'); ?></li>
       <li><?php $f->l_text_field_d('url'); ?></li>
       <li><?php $f->l_text_field_d('privacy'); ?></li>
       <li><?php $f->l_text_field_d('event_color'); ?></li>
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
        $reference_table = 'hr_event_header';
        $reference_id = $$class->hr_event_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Event Members & Resources') ?></span>
 <form method="post" id="hr_event_line"  name="hr_event_line">
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
        <th><?php echo gettext('Line Id') ?>#</th>
        <th><?php echo gettext('User Name') ?></th>
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
       foreach ($hr_event_line_object as $hr_event_line) {
        $$class_second->username = !empty($hr_event_line->user_id) ? ino_user::find_by_id($hr_event_line->user_id)->username : '';
        ?>         
        <tr class="hr_event_line<?php echo $count ?>">
         <td><?php
          echo ino_inline_action($$class_second->hr_event_line_id, array('hr_event_header_id' => $$class->hr_event_header_id));
          ?>
         </td>
         <td><?php $f->text_field_wid2sr('hr_event_line_id'); ?></td>
         <td><?php
          $f->val_field_wid2('username', 'user', 'username', '', 'select user username');
          echo $f->hidden_field('user_id', $$class_third->user_id);
          ?><i class="select_username select_popup clickable fa fa-search"></i></td>
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
  <li class="headerClassName" data-headerClassName="hr_event_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_event_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_event_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_event_header" ></li>
  <li class="line_key_field" data-line_key_field="user_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_event_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_event_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_event_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>