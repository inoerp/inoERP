<div id="pd_divId"><span class='heading'><?php echo gettext('Process Document') ?></span>
		<?php
		$template_lines_ia = new ArrayIterator($template_lines);
		?> 
 <div id ="form_header">
  <form  method="post" id="sys_pd_header"  name="sys_pd_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Other Info') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Secondary Fields') ?></a></li>
     <li><a href="#tabsHeader-5"><?php echo gettext('Notes') ?></a></li>
     <li><a href="#tabsHeader-6"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-7"><?php echo gettext('Action') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('sys_pd_header_id') ?>
        <a name="show" href="form.php?class_name=sys_pd_header&<?php echo "mode=$mode"; ?>" class="show document_id sys_pd_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('process_flow_header_id', sys_pd_header::find_all_hr_processFlow(), 'sys_process_flow_header_id', 'process_flow', $$class->process_flow_header_id, 'process_flow_header_id', '', 1, $readonly); ?></li>
       <li><?php $f->l_text_field_d('document_number'); ?></li>
       <li><?php echo $f->l_select_field_from_object('primary_document', $eng_all, 'obj_class_name', 'obj_class_name_fn', $$class->primary_document, 'primary_document', '', 1); ?></li>
			 <li><?php $f->l_text_field_d('primary_document_id'); ?></li>
       <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id'); ?>           </li>
       <li><?php $f->l_select_field_from_array('change_type', sys_pd_header::$change_type_a, $$class->change_type, 'change_type'); ?></li>
       <li><?php $f->l_text_field_dr('status'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_d('originator'); ?></li>
       <li><?php $f->l_text_field_d('owner_user_id'); ?></li>
       <li><?php $f->l_text_field_d('project_task_id'); ?></li>
       <li><?php $f->l_date_fieldAnyDay('origination_date', $$class->origination_date); ?></li>
       <li><?php $f->l_date_fieldAnyDay('release_date', $$class->release_date); ?></li>
       <li><?php $f->l_date_fieldAnyDay('completion_date', $$class->completion_date); ?></li>
       <li><?php $f->l_text_field_d('access_org'); ?></li>
       <li><?php $f->l_text_field_d('related_changes'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div class="large_shadow_box"> 
					<?php echo!empty($secondary_field_stmt) ? $secondary_field_stmt : null; ?>
      </div>
     </div>
     <div id="tabsHeader-5" class="tabContent">
      <div id="comments">
       <div id="comment_list">
					 <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
					 <?php
					 $reference_table = 'sys_pd_header';
					 $reference_id = $$class->sys_pd_header_id;
					 ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
     <div id="tabsHeader-6" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>

     <div id="tabsHeader-7" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field">
        <li><?php $f->l_select_field_from_object('action', $process_flow_line_obj, 'line_name', 'line_name', '', 'action'); ?> </li>          </li>
       </ul>

      </div>
     </div>
    </div>
   </div>
  </form>
 </div>

 <span class="heading"><?php echo gettext('Document Details') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Flow Diagram') ?></a></li>
   <li><a href="#tabsLine-2"><?php echo gettext('Process Steps') ?></a></li>
  </ul>
  <div class="tabContainer">
   <div id="tabsLine-1" class="tabContent">
			 <?php echo $$class->processFlowDiagram($process_flow_line_obj, '', $$class->status); ?>
   </div>
   <form action=""  method="post" id="process_flow_action_form"  name="process_flow_action_form">
    <div id ="form_line" class="form_line">
     <div id="tabsLine-2" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Line Id') ?></th>
         <th><?php echo gettext('Line Number') ?>#</th>
         <th><?php echo gettext('Sub Process Name') ?></th>
         <th><?php echo gettext('Type') ?></th>
         <th><?php echo gettext('Description') ?></th>
         <th><?php echo gettext('Process Actions') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
					 <?php
					 $count = 0;
					 foreach ($process_flow_line_obj as $sys_process_flow_line) {
						?>         
 				<tr class="process_flow_line<?php echo $count ?>">
 				 <td><?php
							echo ino_inline_action($sys_process_flow_line->sys_process_flow_line_id, array('sys_pd_header_id' => $$class->sys_pd_header_id));
							?>        
 				 </td>
 				 <td><?php echo $f->text_field_ap(array('name' => 'sys_process_flow_line_id', 'value' => $sys_process_flow_line->sys_process_flow_line_id, 'readonly' => true)); ?></td>
 				 <td><?php echo $f->text_field_ap(array('name' => 'line_number', 'value' => $sys_process_flow_line->line_number, 'class_name' => 'lines_number')); ?></td>
 				 <td><?php echo $f->text_field_ap(array('name' => 'line_name', 'value' => $sys_process_flow_line->line_name, 'readonly' => true, 'class_name' => 'xlarge')); ?></td>
 				 <td><?php echo $f->select_field_from_array('line_type', sys_process_flow_line::$line_type_a, $sys_process_flow_line->line_type,'','medium'); ?></td>
 				 <td><?php echo $f->text_field_ap(array('name' => 'description', 'value' => $sys_process_flow_line->description, 'readonly' => true, 'class_name' => 'xlarge')); ?></td>
 				 <td class="add_detail_values">
 					<i class="fa fa-arrow-circle-down add_detail_values_img"></i>
					 <?php
					 $sys_process_flow_line_id = $sys_process_flow_line->sys_process_flow_line_id;
					 $data_in_co_table = false;
					 if (!empty($sys_process_flow_line_id)) {
						$sys_process_flow_action_object = sys_pd_process_flow_action::find_by_headerId_pfLineId($$class->sys_pd_header_id, $sys_process_flow_line_id);
						if (empty($sys_process_flow_action_object)) {
						 $sys_process_flow_action_object = sys_process_flow_action::find_by_parent_id($sys_process_flow_line_id);
						} else {
						 $data_in_co_table = true;
						}
					 } else {
						$sys_process_flow_action_object = array(new sys_process_flow_action());
					 }
					 if (empty($sys_process_flow_action_object)) {
						$sys_process_flow_action_object = array(new sys_process_flow_action());
					 }
					 ?>
 					<div class="class_detail_form">
 					 <fieldset class="form_detail_data_fs">
 						<div class="tabsDetail">
 						 <ul class="tabMain">
 							<li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>"><?php echo gettext('Basic') ?></a></li>
 							<li class="tabLink"><a href="#tabsDetail-2-<?php echo $count ?>"><?php echo gettext('Value') ?></a></li>
 						 </ul>
 						 <div class="tabContainer">
 							<div id="tabsDetail-1-<?php echo $count ?>" class="tabContent">
 							 <table class="form form_detail_data_table detail">
 								<thead>
 								 <tr>
 									<th><?php echo gettext('Action') ?></th>
 									<th><?php echo gettext('Action Id') ?></th>
 									<th><?php echo gettext('PF Line Id') ?>#</th>
 									<th><?php echo gettext('Seq Number') ?></th>
 									<th><?php echo gettext('Action Type') ?></th>
 									<th><?php echo gettext('Role') ?></th>
 									<th><?php echo gettext('User') ?></th>
 								 </tr>
 								</thead>
 								<tbody class="form_data_detail_tbody">
										 <?php
										 $detailCount = 0;
										 foreach ($sys_process_flow_action_object as $sys_process_flow_action) {
											$class_third = 'sys_process_flow_action';
											$$class_third = &$sys_process_flow_action;
											if (empty($sys_process_flow_action->sys_pd_process_flow_action_id)) {
											 $sys_process_flow_action->sys_pd_process_flow_action_id = null;
											}
											?>
									 <tr class="sys_process_flow_action<?php echo $count . '-' . $detailCount; ?>">
										<td>   
										 <ul class="inline_action">
											<li class="add_row_detail_img"><i class="fa fa-plus-circle"></i></li>
											<li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
											<li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($sys_process_flow_action->sys_pd_process_flow_action_id); ?>"></li>           
											<li><?php echo form::hidden_field('sys_pd_header_id', $$class->sys_pd_header_id); ?></li>
										 </ul>
										</td>
										<td><?php form::text_field_wid3sr('sys_pd_process_flow_action_id'); ?></td>
										<td><?php form::text_field_wid3sr('sys_process_flow_line_id'); ?></td>
										<td><?php echo $f->number_field('action_number', $$class_third->action_number, '', '', 'detail_number'); ?></td>
										<td><?php echo $f->select_field_from_array('pf_action_type', sys_process_flow_action::$pf_action_type_a, $$class_third->pf_action_type ,'','medium'); ?></td>
										<td><?php echo $f->select_field_from_object('role_code', role_access::roles(), 'option_line_code', 'option_line_value', $$class_third->role_code, '' , 'medium'); ?></td>
										<td><?php
												echo $f->hidden_field('user_id', $$class_third->user_id);
												$$class_third->username = !empty($$class_third->user_id) ? ino_user::find_by_id($$class_third->user_id)->username : null;
												echo $f->text_field('username', $$class_third->username);
												?>
										 <img src="<?php echo HOME_URL; ?>themes/default/images/serach.png" class="user_id select_popup clickable">
										</td>
									 </tr>
									 <?php
									 $detailCount++;
									}
									?>
 								</tbody>
 							 </table>
 							</div>
 							<div id="tabsDetail-2-<?php echo $count ?>" class="tabContent">
 							 <table class="form form_detail_data_table detail">
 								<thead>
 								 <tr>
 									<th><?php echo gettext('Action Id') ?></th>
 									<th><?php echo gettext('Value') ?></th>
 									<th><?php echo gettext('Comment') ?></th>
 									<th><?php echo gettext('By User') ?></th>
 									<th><?php echo gettext('Duration') ?></th>
 									<th><?php echo gettext('Primary Object') ?></th>
 									<th><?php echo gettext('Object Id') ?></th>
 								 </tr>
 								</thead>
 								<tbody class="form_data_detail_tbody">
										 <?php
										 $detailCount = 0;
										 foreach ($sys_process_flow_action_object as $sys_process_flow_action) {
											$class_third = 'sys_process_flow_action';
											$$class_third = &$sys_process_flow_action;
											if (empty($sys_process_flow_action->sys_pd_process_flow_action_id)) {
											 $sys_process_flow_action->sys_pd_process_flow_action_id = null;
											}
											?>
									 <tr class="sys_process_flow_action<?php echo $count . '-' . $detailCount; ?>">
										<td><?php form::text_field_wid3r('sys_pd_process_flow_action_id'); ?></td>
										<td><?php
												$$class_third->field_value = empty($$class_third->field_value) ? '' : $$class_third->field_value;
												echo $f->select_field_from_array('field_value', sys_pd_process_flow_action::$value_a, $$class_third->field_value , '' ,'medium');
												?></td>
										<td><?php
												$$class_third->comment = empty($$class_third->comment) ? '' : $$class_third->comment;
												$f->text_field_wid3('comment', 'medium');
												?></td>
										<td><?php
												if (($data_in_co_table) && empty($$class_third->action_user_id)) {
												 $$class_third->action_user_id = isset($_SESSION['user_id']) ? $_SESSION['user_id'] : 0;
												} else {
												 $$class_third->action_user_id = isset($$class_third->action_user_id) ? $$class_third->action_user_id : 0;
												}
												echo $f->hidden_field('action_user_id', $$class_third->action_user_id);
												$$class_third->action_user_name = !empty($$class_third->action_user_id) ? ino_user::find_by_id($$class_third->action_user_id)->username : null;
												echo $f->text_field('action_user_name', $$class_third->action_user_name);
												?>
										</td>
										<td><?php
												$$class_third->duration = empty($$class_third->duration) ? '' : $$class_third->duration;
												form::text_field_wid3sr('duration');
												?></td>
										<td>
												<?php echo $f->select_field_from_object('object_name', $eng_all, 'obj_class_name', 'obj_class_name_fn', $$class_third->object_name, '', 'medium'); ?>
										</td>
										<td><?php form::text_field_wid3('object_primary_id'); ?></td>
									 </tr>
									 <?php
									 $detailCount++;
									}
									?>
 								</tbody>
 							 </table>
 							</div>
 						 </div>
 						</div>


 					 </fieldset>

 					</div>

 				 </td>
 				</tr>
				 <?php
				 $count = $count + 1;
				}
				?>
       </tbody>
      </table>
     </div>
    </div>
   </form>
  </div>
 </div>
 <!--END OF FORM HEADER-->
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_pd_header" ></li>
  <li class="lineClassName" data-lineClassName="sys_pd_process_flow_action" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="onlyHeaderOverLay" data-onlyHeaderOverLay="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_pd_header_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_pd_header" ></li>
  <li class="line_key_field" data-line_key_field="pf_action_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="process_flow_action_form" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_pd_header_id" ></li>
  <li class="docLineId" data-docLineId="sys_pd_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_pd_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>
