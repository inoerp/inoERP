<div id ="form_header">
 <form method="post" id="lms_term"  name="lms_term">
  <span class="heading"><?php echo gettext('Term') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>

    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('lms_term_id') ?>
        <a name="show" href="form.php?class_name=lms_term&<?php echo "mode=$mode"; ?>" class="show document_id lms_term_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('term_name'); ?></li>
       <li><?php $f->l_text_field_d('term_code'); ?></li>
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
						$reference_table = 'lms_term';
						$reference_id = $$class->lms_term_id;
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
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Other Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Term') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div><?php
					echo $f->text_area_ap(array('name' => 'overview', 'value' => $$class->overview,
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
  <li class="headerClassName" data-headerClassName="lms_term" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="lms_term_id" ></li>
  <li class="form_header_id" data-form_header_id="lms_term" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="lms_term_id" ></li>
  <li class="btn1DivId" data-btn1DivId="lms_term_id" ></li>
 </ul>
</div>