<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Assessment') ?></span>
 <form method="post" id="lms_assessment_header"  name="lms_assessment_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f = new inoform(); $f->l_text_field_dr_withSearch('lms_assessment_header_id') ?>
       <a name="show" href="form.php?class_name=lms_assessment_header&<?php echo "mode=$mode"; ?>" class="show document_id lms_assessment_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('assessment_name'); ?></li>
			<li><?php $f->l_text_field_d('assessment_code'); ?></li>
			<li><?php $f->l_text_field_d('assessment_group'); ?></li>
			<li><?php $f->l_text_field_d('student_group'); ?></li>
			<li><?php $f->l_text_field_d('supervisor'); ?></li>
			<li><?php $f->l_text_field_d('examiner'); ?></li>
			<li><?php $f->l_select_field_from_object('grading_structure', lms_grade_struct_header::find_all(),'lms_grade_struct_header_id', 'struct_name', $$class->grading_structure ); ?></li>
			<li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date); ?></li>
			<li><?php $f->l_date_fieldAnyDay('end_date', $$class->end_date); ?></li>
			<li><?php $f->l_dateTime_field('start_time', $$class->start_time); ?></li>
			<li><?php $f->l_dateTime_field('end_time', $$class->end_time); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li>
			<li><?php $f->l_text_field_d('status'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
					 <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
					 <?php
					 $reference_table = 'lms_assessment_header';
					 $reference_id = $$class->lms_assessment_header_id;
					 ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Line Details') ?></span>
 <form method="post" id="lms_assessment_line"  name="lms_assessment_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Student Results') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Student Name') ?></th>
        <th><?php echo gettext('Attempt ') ?> #</th>
				<th><?php echo gettext('Mark') ?></th>
        <th><?php echo gettext('Grade') ?></th>
				<th><?php echo gettext('Rank') ?></th>
				<th><?php echo gettext('Percentile') ?></th>
				<th><?php echo gettext('Student Exam Id') ?></th>
				<th><?php echo gettext('Description') ?></th>
				<th><?php echo gettext('Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
					<?php $count = 0;
					foreach ($lms_assessment_line_object as $lms_assessment_line) {
					 ?>         
 			 <tr class="lms_assessment_line<?php echo $count ?>">
 				<td>
						 <?php
						 echo ino_inline_action($lms_assessment_line->lms_assessment_line_id, array('lms_assessment_header_id' => $$class->lms_assessment_header_id));
						 ?>
 				</td>
 				<td><?php $f->seq_field_d($count) ?></td>
 				<td><?php $f->text_field_wid2sr('lms_assessment_line_id', 'always_readonly'); ?></td>
 				<td><?php $f->text_field_wid2sr('student_id'); ?></td>
 				<td><?php $f->text_field_wid2('attempt_number'); ?></td>
 				<td><?php $f->text_field_wid2('student_mark'); ?></td>
 				<td><?php $f->text_field_wid2('student_grade'); ?></td>
 				<td><?php $f->text_field_wid2('rank'); ?></td>
 				<td><?php $f->text_field_wid2('percentile'); ?></td>
 				<td><?php $f->text_field_wid2('student_exam_id'); ?></td>
 				<td><?php $f->text_field_wid2('description', 'large'); ?></td>
 				<td><?php echo $f->text_field_wid2('Status'); ?></td>
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
  <li class="headerClassName" data-headerClassName="lms_assessment_header" ></li>
  <li class="lineClassName" data-lineClassName="lms_assessment_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="lms_assessment_header_id" ></li>
  <li class="form_header_id" data-form_header_id="lms_assessment_header" ></li>
  <li class="line_key_field" data-line_key_field="billing_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="lms_assessment_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="lms_assessment_header_id" ></li>
  <li class="docLineId" data-docLineId="lms_assessment_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="lms_assessment_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>