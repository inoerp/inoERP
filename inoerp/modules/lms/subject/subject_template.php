<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Subject') ?></span>
 <form method="post" id="lms_subject_header"  name="lms_subject_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Overview') ?></a></li>
		<li><a href="#tabsHeader-3"><?php echo gettext('Objectives') ?></a></li>
		<li><a href="#tabsHeader-4"><?php echo gettext('Structure') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('lms_subject_header_id') ?>
       <a name="show" href="form.php?class_name=lms_subject_header&<?php echo "mode=$mode"; ?>" class="show document_id lms_subject_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('subject_name'); ?></li>
			<li><?php $f->l_text_field_d('subject_code'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li>
			<li><?php $f->l_text_field_d('status'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
		 <div><label class="text_area_label"><?php echo gettext('Overview') ?></label>
				 <?php echo $f->text_area_ap(array('name' => 'overview', 'value' => $$class->overview, 'row_size' => '10', 'column_size' => '90')); ?> 	
		 </div> 
    </div>
    <div id="tabsHeader-3" class="tabContent">
		 <div><label class="text_area_label"><?php echo gettext('Objectives') ?></label>
				 <?php echo $f->text_area_ap(array('name' => 'objectives', 'value' => $$class->objectives, 'row_size' => '10', 'column_size' => '90')); ?> 	
		 </div> 
    </div>
		<div id="tabsHeader-4" class="tabContent">
		 <div><label class="text_area_label"><?php echo gettext('Structure') ?></label>
				 <?php echo $f->text_area_ap(array('name' => 'structure', 'value' => $$class->structure, 'row_size' => '10', 'column_size' => '90')); ?> 	
		 </div> 
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
					 <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
					 <?php
					 $reference_table = 'lms_subject_header';
					 $reference_id = $$class->lms_subject_header_id;
					 ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Service Type Lines') ?></span>
 <form action=""  method="post" id="lms_subject_line"  name="lms_subject_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Order Type') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Chapter Name') ?></th>
        <th><?php echo gettext('Suggested Reading') ?></th>
        <th><?php echo gettext('Description') ?></th>
				<th><?php echo gettext('Graded ?') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
					<?php
					$f = new inoform();
					$count = 0;
					foreach ($lms_subject_line_object as $lms_subject_line) {
					 ?>         
 			 <tr class="lms_subject_line<?php echo $count ?>">
 				<td>
						 <?php
						 echo ino_inline_action($lms_subject_line->lms_subject_line_id, array('lms_subject_header_id' => $$class->lms_subject_header_id));
						 ?>
 				</td>
 				<td><?php $f->seq_field_d($count) ?></td>
 				<td><?php form::text_field_wid2sr('lms_subject_line_id'); ?></td>
				<td><?php echo $f->select_field_from_object('lms_chapter_id', lms_chapter::find_all(), 'lms_chapter_id', 'chapter_name', $$class_second->lms_chapter_id , '' , 'xlarge'); ?></td>
 				<td><?php $f->text_field_wid2('suggested_reading' , 'xlarge'); ?></td>
 				<td><?php $f->text_field_wid2('description' ,'xlarge'); ?></td>
				<td><?php $f->checkBox_field_wid2('graded_cb'); ?></td>
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
  <li class="headerClassName" data-headerClassName="lms_subject_header" ></li>
  <li class="lineClassName" data-lineClassName="lms_subject_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="lms_subject_header_id" ></li>
  <li class="form_header_id" data-form_header_id="lms_subject_header" ></li>
  <li class="line_key_field" data-line_key_field="lms_chapter_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="lms_subject_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="lms_subject_header_id" ></li>
  <li class="docLineId" data-docLineId="lms_subject_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="lms_subject_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>