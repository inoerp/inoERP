<form  method="post" id="hr_event_header"  name="hr_event_header">
 <span class="heading"><?php echo gettext('Event') ?></span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic'); ?></a></li>
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
   </div>
  </div>
 </div>

 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Event Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basics') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Details') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field two_column_form"> 
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_text_field_d('location'); ?></li>
       <li><?php $f->l_text_field_d('url'); ?></li>
       <li><?php $f->l_text_field_d('privacy'); ?></li>
       <li><?php $f->l_text_field_d('event_color'); ?></li>
      </ul>
     </div>
    </div> 
    <div id="tabsLine-2" class="tabContent">
     <div class="first_rowset"> 
      <?php echo $f->text_area('event_details', $$class->event_details, '10', '', '', '', '', '', '', '170'); ?>
     </div>
    </div> 
   </div>
  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_event_header" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_event_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_event_header" ></li>
 </ul>

 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_event_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_event_header" ></li>
 </ul>
</div>