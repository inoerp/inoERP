<div id ="form_header">
 <form method="post" id="mdm_discount_header"  name="mdm_discount_header">
  <span class="heading"><?php echo gettext('Discount Header') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
		<li><a href="#tabsHeader-2"><?php echo gettext('Formula') ?></a></li>
		<li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
		<li><a href="#tabsHeader-4"><?php echo gettext('Notes') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f = new inoform();
$f->l_text_field_dr_withSearch('mdm_discount_header_id')
?>
        <a name="show" href="form.php?class_name=mdm_discount_header&<?php echo "mode=$mode"; ?>" class="show document_id mdm_discount_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('discount_name'); ?></li>
			 <li><?php $f->l_text_field_d('discount_code'); ?></li>
			 
			 <li><?php $f->l_select_field_from_array('module_code', mdm_price_list_header::$module_a, $$class->module_code, 'module_code', '', '', $readonly); ?></li>
			 
			 <li><?php $f->l_select_field_from_array('discount_type' , mdm_discount_header::$discount_type_a, $$class->discount_type); ?></li>
			 <li><?php $f->l_number_field('discount_percentage' , $$class->discount_percentage); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
			 <li><?php $f->l_checkBox_field_d('check_condition_cb'); ?></li>
			 <li><?php $f->l_status_field_d('status'); ?></li>
      </ul>
     </div>
    </div>
		<div id="tabsHeader-2" class="tabContent">
		 <div> 
			<ul class="column header_field">
			 <li><?php $f->l_text_area_d('discount_formula'); ?></li>
			</ul>
		 </div>
		</div>
		<div id="tabsHeader-3" class="tabContent">
		 <div> <?php echo ino_attachement($file) ?> </div>
		</div>
		<div id="tabsHeader-4" class="tabContent">
		 <div> 
			<div id="comments">
			 <div id="comment_list">
<?php echo!(empty($comments)) ? $comments : ""; ?>
			 </div>
			 <div id ="display_comment_form">
					 <?php
					 $reference_table = 'mdm_price_list_header';
					 $reference_id = $$class->mdm_price_list_header_id;
					 ?>
			 </div>
			 <div id="new_comment">
			 </div>
			</div>
		 </div>
		</div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line">
 <span class="heading"><?php echo gettext('Discount Lines') ?></span>
 <form  method="post" id="mdm_discount_line"  name="mdm_discount_line">
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
        <th><?php echo gettext('Condition Type') ?></th>
        <th><?php echo gettext('Class Name') ?></th>
        <th><?php echo gettext('Field Name') ?></th>
        <th><?php echo gettext('Compare Type') ?></th>
				<th><?php echo gettext('Value') ?></th>
				<th><?php echo gettext('End Condition') ?></th>
				<th><?php echo gettext('Line Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
					<?php
					$count = 0;
					foreach ($mdm_discount_line_object as $mdm_discount_line) {
					 ?>         
 			 <tr class="mdm_discount_line<?php echo $count ?>">
 				<td><?php
					echo ino_inline_action($$class_second->mdm_discount_line_id, array('mdm_discount_header_id' => $$class->mdm_discount_header_id));
					?></td>
 				<td><?php $f->text_field_wid2sr('mdm_discount_line_id', 'always_readonly'); ?></td>
				<td><?php echo $f->select_field_from_array('condition_type', dbObject::$condition_type_a, $$class_second->condition_type, '', 'medium', 1, $readonly); ?></td>
				<td><?php $f->text_field_wid2m('element_set'); ?></td>
				<td><?php $f->text_field_wid2m('element_name'); ?></td>
				<td><?php echo $f->select_field_from_array('compare_type', dbObject::$control_type_a, $$class_second->compare_type, '' , 'medium', 1, $readonly); ?></td>
				<td><?php $f->text_field_wid2m('compare_value'); ?></td>
				<td><?php echo $f->select_field_from_array('close_bracket', mdm_discount_line::$bracket_close_a ,  $$class_second->close_bracket); ?></td>
				<td><?php echo $f->status_field_d2('status', 'medium'); ?></td>
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
  <li class="headerClassName" data-headerClassName="mdm_discount_header" ></li>
  <li class="lineClassName" data-lineClassName="mdm_discount_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="mdm_discount_header_id" ></li>
  <li class="form_header_id" data-form_header_id="mdm_discount_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="mdm_discount_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="mdm_discount_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="mdm_discount_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>