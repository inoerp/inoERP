<div id ="form_header">
 <form method="post" id="lms_fee_struct_header"  name="lms_fee_struct_header">
  <span class="heading"><?php echo gettext('Fee Structure') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('lms_fee_struct_header_id') ?>
        <a name="show" href="form.php?class_name=lms_fee_struct_header&<?php echo "mode=$mode"; ?>" class="show document_id lms_fee_struct_header_id">
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
 <span class="heading"><?php echo gettext('Fee Structure Lines') ?></span>
 <form  method="post" id="lms_fee_struct_line"  name="lms_fee_struct_line">
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
        <th><?php echo gettext('Element Name') ?></th>
        <th><?php echo gettext('Element Value') ?></th>
        <th><?php echo gettext('Inactive Date') ?></th>
        <th><?php echo gettext('Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
					<?php
					$count = 0;
					foreach ($lms_fee_struct_line_object as $lms_fee_struct_line) {
					 ?>         
 			 <tr class="lms_fee_struct_line<?php echo $count ?>">
 				<td><?php
						 echo ino_inline_action($$class_second->lms_fee_struct_line_id, array('lms_fee_struct_header_id' => $$class->lms_fee_struct_header_id));
						 ?></td>
 				<td><?php $f->text_field_wid2sr('lms_fee_struct_line_id'); ?></td>
 				<td><?php echo $f->select_field_from_object('lms_fee_element_id', lms_fee_element::find_all(), 'lms_fee_element_id', array('element_name', 'description'), $$class_second->lms_fee_element_id, '', 'medium', 1, $readonly); ?></td>
 				<td><?php $f->text_field_wid2m('element_value'); ?></td>
 				<td><?php echo $f->date_fieldFromToday('end_date', $$class_second->end_date); ?></td>
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
  <li class="headerClassName" data-headerClassName="lms_fee_struct_header" ></li>
  <li class="lineClassName" data-lineClassName="lms_fee_struct_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="lms_fee_struct_header_id" ></li>
  <li class="form_header_id" data-form_header_id="lms_fee_struct_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="lms_fee_struct_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="lms_fee_struct_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="lms_fee_struct_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>