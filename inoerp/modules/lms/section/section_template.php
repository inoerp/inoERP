<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Class or Group') ?></span>
 <form method="post" id="lms_group_header"  name="lms_group_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('lms_group_header_id') ?>
       <a name="show" href="form.php?class_name=lms_group_header&<?php echo "mode=$mode"; ?>" class="show document_id lms_group_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('group_name'); ?></li>
			<li><?php $f->l_text_field_d('group_code'); ?></li>
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
					 $reference_table = 'lms_group_header';
					 $reference_id = $$class->lms_group_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Class or Group Lines') ?></span>
 <form method="post" id="lms_group_line"  name="lms_group_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Term Details') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Term Name') ?></th>
        <th><?php echo gettext('Start Date') ?></th>
				<th><?php echo gettext('End Date') ?></th>
        <th><?php echo gettext('Description') ?></th>
				<th><?php echo gettext('Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
					<?php
					$count = 0;
					foreach ($lms_group_line_object as $lms_group_line) {
					 ?>         
 			 <tr class="lms_group_line<?php echo $count ?>">
 				<td>
						 <?php
						 echo ino_inline_action($lms_group_line->lms_group_line_id, array('lms_group_header_id' => $$class->lms_group_header_id));
						 ?>
 				</td>
 				<td><?php $f->seq_field_d($count) ?></td>
 				<td><?php form::text_field_wid2sr('lms_group_line_id'); ?></td>
 				<td><?php echo $f->select_field_from_object('lms_term_id', lms_term::find_all(), 'lms_term_id', ['term_name','description'], $$class_second->lms_term_id, '', 'medium'); ?></td>
 				<td><?php echo $f->date_fieldAnyDay('term_start_date', $$class_second->term_start_date); ?></td>
 				<td><?php echo $f->date_fieldAnyDay('term_end_date', $$class_second->term_end_date); ?></td>
 				<td><?php $f->text_field_wid2('description', 'large'); ?></td>
 				<td><?php $f->text_field_wid2('status'); ?></td>
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
  <li class="headerClassName" data-headerClassName="lms_group_header" ></li>
  <li class="lineClassName" data-lineClassName="lms_group_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="lms_group_header_id" ></li>
  <li class="form_header_id" data-form_header_id="lms_group_header" ></li>
  <li class="line_key_field" data-line_key_field="lms_term_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="lms_group_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="lms_group_header_id" ></li>
  <li class="docLineId" data-docLineId="lms_group_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="lms_group_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>