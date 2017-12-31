<div id ="form_header">
 <form method="post" id="lms_academic_year"  name="lms_academic_year">
  <span class="heading"><?php $f = new inoform(); echo gettext('Academic Year') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>

    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field two_column_form"> 
       <li><?php $f->l_text_field_dr_withSearch('lms_academic_year_id') ?>
        <a name="show" href="form.php?class_name=lms_academic_year&<?php echo "mode=$mode"; ?>" class="show document_id lms_academic_year_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('academic_year_name'); ?></li>
       <li><?php $f->l_text_field_d('academic_year_code'); ?></li>
       <li><?php $f->l_dateTime_field('start_date', $$class->start_date); ?></li>
			 <li><?php $f->l_dateTime_field('end_date' , $$class->end_date); ?></li>
			 <li><?php $f->l_status_field_d('status'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
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
						$reference_table = 'lms_academic_year';
						$reference_id = $$class->lms_academic_year_id;
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
  <li class="headerClassName" data-headerClassName="lms_academic_year" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="lms_academic_year_id" ></li>
  <li class="form_header_id" data-form_header_id="lms_academic_year" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="lms_academic_year_id" ></li>
  <li class="btn1DivId" data-btn1DivId="lms_academic_year_id" ></li>
 </ul>
</div>