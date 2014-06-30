<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="process_flow_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<div id ="form_header"><span class="heading">Process Flow Header </span>
			 <form action=""  method="post" id="process_flow_header"  name="process_flow_header">
				<div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column three_column">
						 <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="process_flow_header_id select_popup clickable">
							 Prolow Id : </label>
							<?php echo form::text_field('sys_process_flow_header_id', $$class->sys_process_flow_header_id, '15', '25', '', 'System Number', 'sys_process_flow_header_id', $readonly) ?>
							<a name="show" href="form.php?class_name=sys_process_flow_header" class="show sys_process_flow_header_id">	
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
						 </li>
						 <li><label>Process Flow : </label><?php
							$f = new inoform();
							$f->text_field_dm('process_flow');
							?> </li>
						 <li><label>Description: </label><?php $f->text_field_dl('description'); ?></li>
						 <li><label>Type : </label>
							<?php echo $f->select_field_from_array('type', sys_process_flow_header::$type_a ,$$class->type); ?></li>
						 <li><label>Status : </label><?php echo form::status_field($$class->status, $readonly); ?></li>
						 <li><label>Modules : </label>
							<?php echo $f->select_field_from_object('module_name', option_header::modules(), 'option_line_code', 'option_line_value', $$class->module_name, 'module_name', '', 1, $readonly) ?></li>
						</ul>
					 </div>
					</div>
				 </div>

				</div>
			 </form>
			</div>

			<div id="form_line" class="form_line"><span class="heading">Process Flow Lines </span>
			 <form action=""  method="post" id="process_flow_line"  name="process_flow_line">
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">Main</a></li>
					<li><a href="#tabsLine-2">Decision</a></li>
					<li><a href="#tabsLine-3">Flow Diagram</a></li>
				 </ul>
				 <div class="tabContainer">
					<div id="tabsLine-1" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>Action</th>
							<th>Line Id</th>
							<th>Seq Number</th>
							<th>Line Name</th>
							<th>Type</th>
							<th>Description</th>
							<th>Class Name</th>
							<th>Method Name</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($sys_process_flow_line_object as $sys_process_flow_line) {
							?>         
 						 <tr class="process_flow_line<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->sys_process_flow_line_id); ?>"></li>           
 								<li><?php echo form::hidden_field('sys_process_flow_header_id', $$class->sys_process_flow_header_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php $f->text_field_wid2sr('sys_process_flow_line_id'); ?></td>
 							<td><?php $f->text_field_wid2s('seq_number'); ?></td>
 							<td><?php $f->text_field_wid2('line_name'); ?></td>
 							<td><?php echo $f->select_field_from_array('line_type', sys_process_flow_line::$line_type_a, $$class_second->line_type); ?></td>
 							<td><?php $f->text_field_wid2l('description'); ?></td>
 							<td><?php $f->text_field_wid2('class_name'); ?></td>
 							<td><?php $f->text_field_wid2('method_name'); ?></td>
						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
					 </table>
					</div>
					<div id="tabsLine-2" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>Next Id On Pass</th>
							<th>Next Id If Fail</th>
							<th>Next Id On Return</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($sys_process_flow_line_object as $sys_process_flow_line) {
							?>         
 						 <tr class="process_flow_line<?php echo $count ?>">
 							<td><?php $f->text_field_wid2('next_line_id_pass'); ?></td>
							<td><?php $f->text_field_wid2('next_line_id_fail'); ?></td>
 							<td><?php $f->text_field_wid2('next_line_id_onreturn'); ?></td>
 						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
					 </table>
					</div>
					<div id="tabsLine-3" class="scrollElement tabContent">

					</div>
				 </div>
				</div>
			 </form>
			</div>

			<!--END OF FORM HEADER-->
		 </div>
		</div>
		<!--   end of structure-->
	 </div>
	 <div id="content_bottom"></div>
	</div>
	<div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
