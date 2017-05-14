<div id ="form_header">
 <form method="post" id="lms_grade_struct_header"  name="lms_grade_struct_header">
  <span class="heading"><?php echo gettext('Grade Structure') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('lms_grade_struct_header_id') ?>
        <a name="show" href="form.php?class_name=lms_grade_struct_header&<?php echo "mode=$mode"; ?>" class="show document_id lms_grade_struct_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('struct_name'); ?></li>
			 <li><?php $f->l_text_field_d('struct_code'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
      </ul>
     </div>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line">
 <span class="heading"><?php echo gettext('Grade Structure Lines') ?></span>
 <form  method="post" id="lms_grade_struct_line"  name="lms_grade_struct_line">
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
        <th><?php echo gettext('Grade Code') ?></th>
        <th><?php echo gettext('From Score') ?></th>
        <th><?php echo gettext('To Score') ?></th>
        <th><?php echo gettext('Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
					<?php
					$count = 0;
					foreach ($lms_grade_struct_line_object as $lms_grade_struct_line) {
					 ?>         
 			 <tr class="lms_grade_struct_line<?php echo $count ?>">
 				<td><?php
						 echo ino_inline_action($$class_second->lms_grade_struct_line_id, array('lms_grade_struct_header_id' => $$class->lms_grade_struct_header_id));
						 ?></td>
 				<td><?php $f->text_field_wid2sr('lms_grade_struct_line_id'); ?></td>
 				<td><?php $f->text_field_wid2m('grade_code'); ?></td>
				<td><?php $f->text_field_wid2m('from_score'); ?></td>
				<td><?php $f->text_field_wid2m('to_score'); ?></td>
 				<td><?php $f->text_field_wid2l('description'); ?></td>
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
  <li class="headerClassName" data-headerClassName="lms_grade_struct_header" ></li>
  <li class="lineClassName" data-lineClassName="lms_grade_struct_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="lms_grade_struct_header_id" ></li>
  <li class="form_header_id" data-form_header_id="lms_grade_struct_header" ></li>
  <li class="line_key_field" data-line_key_field="grade_code" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="lms_grade_struct_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="lms_grade_struct_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="lms_grade_struct_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>