<div id ="form_header">
 <form method="post" id="lms_chapter"  name="lms_chapter">
  <span class="heading"><?php echo gettext('Chapter') ?></span>
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
       <li><?php $f->l_text_field_dr_withSearch('lms_chapter_id') ?>
        <a name="show" href="form.php?class_name=lms_chapter&<?php echo "mode=$mode"; ?>" class="show document_id lms_chapter_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_dm('chapter_name'); ?></li>
       <li><?php $f->l_text_field_d('chapter_code'); ?></li>
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
						$reference_table = 'lms_chapter';
						$reference_id = $$class->lms_chapter_id;
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
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Chapter Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Overview') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Topics') ?> </a></li>
		 <li><a href="#tabsLine-3"><?php echo gettext('References') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div><?php
					echo $f->text_area_ap(array('name' => 'overview', 'value' => $$class->overview,
							'row_size' => '10', 'column_size' => '90'));
					?> 	
      </div> 
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div><?php
					echo $f->text_area_ap(array('name' => 'topics', 'value' => $$class->topics,
							'row_size' => '10', 'column_size' => '90'));
					?> 	
      </div> 
     </div>
		 <div id="tabsLine-3"  class="tabContent">
      <div><?php
					echo $f->text_area_ap(array('name' => 'reference', 'value' => $$class->reference,
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
  <li class="headerClassName" data-headerClassName="lms_chapter" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="lms_chapter_id" ></li>
  <li class="form_header_id" data-form_header_id="lms_chapter" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="lms_chapter_id" ></li>
  <li class="btn1DivId" data-btn1DivId="lms_chapter_id" ></li>
 </ul>
</div>