<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="option">
      <!--    START OF FORM HEADER-->
      <div id ="form_header">
       <form action=""  method="post" id="option_header"  name="option_header">
        <ul id="form_box"> 
         <li>   <!--    Place for showing error messages-->
          <div class="error"></div><div id="loading"></div>
          <div class="show_loading_small"></div>
					<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
          <!--    End of place for showing error messages-->
         </li>
         <li class="ncontrol">
          <div class="three_column large_shadow_box"><span class="heading">Option Header </span>
           <ul>
            <li>
             <label><a href="find_option.php" class="popup">
               <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>
              Option Id : </label>
						 <?php echo form::text_field('option_header_id', $option_header->option_header_id, '10', '', '', 'System number', 'option_header_id'); ?>
             <a name="show" href="option.php?option_header_id=" class="show option_header_id">
              <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
            </li>
            <li><label>Option Type* : </label>
						 <?php echo form::text_field('option_type', $option_header->option_type, '20', '', 'required', 'No special characters', 'option_type'); ?>
            </li>
            <li><label>Access Level* : </label>
						 <?php echo form::select_field_from_array('access_level', option_header::$access_level_array, $option_header->access_level, 'access_level'); ?>
            </li>
            <li><label>Description : </label>
						 <?php echo form::text_field('description', $option_header->description, '20'); ?>
            </li>
            <li><label>Module* : </label>
						 <?php echo form::select_field_from_object('module', module::find_all(), 'module_id', 'name', $option_header->module, 'module'); ?>
            </li>
            <li><label>Assignment : </label>
						 <?php echo form::select_field_from_object('option_assignments', option_header::option_assignments(), 'option_line_code', 'option_line_value', $option_header->option_assignments, 'option_assignments'); ?>
            </li>
            <li><label>Extra Field : </label>
						 <?php echo form::extra_field($option_header->efid); ?>
            </li>
            <li><label>Status : </label>
						 <?php echo form::status_field($option_header->status); ?>
            </li>
            <li><label>Revision : </label>
						 <?php echo form::revision_enabled_field($option_header->rev_enabled); ?>
            </li>
            <li><label>Revision No: </label>
						 <?php echo form::text_field('rev_number', $option_header->rev_number, '10'); ?>
            </li>
           </ul>
          </div>
         </li>
        </ul>
       </form> 
      </div>
      <!--END OF FORM HEADER-->
      <div id ="form_line" class="form_line"><span class="heading">Option Line </span>
       <form action=""  method="post" id="option_line"  name="option_line">
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">Basic</a></li>
					<li><a href="#tabsLine-2">Effectivity</a></li>
				 </ul>
				 <div class="tabContainer">
					<div id="tabsLine-1" class="tabContent">
					 <table class="form form_line_data_table">
						<thead>
						 <tr>
							<th>Action</th>
							<th>Line Id</th>
							<th>Option Code</th>
							<th>Value</th>
							<th>Description</th>
							<th>Value Group</th>
							<th class="add_detail_values_header">Details</th>
						 </tr>
						</thead>
						<tbody id="form_data_line_tbody" class="form_data_line_tbody">
						 <?php
						 $linecount = 0;
						 foreach ($option_line_object as $option_line) {
							?>
 						 <tr class="option_line<?php echo $linecount; ?>">

 							<td>   
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($option_line->option_line_id); ?>"></li>           
 								<li><?php echo form::hidden_field('option_header_id', $option_header->option_header_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php echo form::text_field('option_line_id', $option_line->option_line_id, '8', '12', '', 'System number', ''); ?></td>
 							<td><?php echo form::text_field('option_line_code', $option_line->option_line_code, 'required', '30', '50', 'No special characters', ''); ?></td>
 							<td><?php echo form::text_field('option_line_value', $option_line->option_line_value, '10'); ?></td>
 							<td><?php echo form::text_field('description', $option_line->description, '20'); ?></td>
 							<td>	<?php echo form::select_field_from_object('value_group_id', sys_value_group_header::find_all(), 'sys_value_group_header_id', 'value_group', $$class_second->value_group_id, '', $readonly, '', ''); ?></td>
 							<td class="add_detail_values"><img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
								<?php
								$option_line_id = $option_line->option_line_id;
								if (!empty($option_line_id)) {
								 $option_detail_object = option_detail::find_by_option_line_id($option_line_id);
								} else {
								 $option_detail_object = array();
								}
								if (count($option_detail_object) == 0) {
								 $option_detail = new option_detail();
								 $option_detail_object = array();
								 array_push($option_detail_object, $option_detail);
								}
								?>
 							 <div class="class_detail_form">
 								<fieldset class="form_detail_data_fs"><legend>Detail Data</legend>
 								 <table class="form form_detail_data_table detail">
 									<thead>
 									 <tr>
 										<th>Action</th>
 										<th>Detail Id</th>
 										<th>Value</th>
 										<th>Description</th>
 										<th>E Field</th>
 										<th>Status</th>
 										<th>Revision</th>
 										<th>Rev #</th>
 										<th>Start Date</th>
 										<th>End Date</th>
 									 </tr>
 									</thead>
 									<tbody class="form_data_detail_tbody">
										<?php
										$detailCount = 0;
										foreach ($option_detail_object as $option_detail) {
										 ?>
										 <tr class="option_detail_tr<?php echo $detailCount; ?>">
											<td>   
											 <ul class="inline_action">
												<li class="add_row_detail_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
												<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
												<li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($option_detail->option_detail_id); ?>"></li>           
												<li><?php echo form::hidden_field('option_line_id', $option_line->option_line_id); ?></li>
												<li><?php echo form::hidden_field('option_header_id', $option_header->option_header_id); ?></li>

											 </ul>
											</td>
											<td><?php echo form::text_field('option_detail_id', $option_detail->option_detail_id, '8', '12', '', 'System number', 'option_line_id'); ?></td>
											<td><?php echo form::text_field('option_detail_value', $option_detail->option_detail_value, 'required', '20', '50', 'No special characters', ''); ?></td>
											<td><?php echo form::text_field('description', $option_detail->description, '20'); ?></td>
											<td><?php echo form::extra_field($option_detail->efid, '5'); ?></td>
											<td><?php echo form::status_field($option_detail->status); ?></td>
											<td><?php echo form::revision_enabled_field($option_detail->rev_enabled); ?></td>
											<td><?php echo form::text_field('rev_number', $option_detail->rev_number, '5'); ?></td>
											<td><?php echo form::date_field('effective_start_date', $option_detail->effective_start_date, '10', '', '', ''); ?></td>
											<td><?php echo form::date_field('effective_end_date', $option_detail->effective_end_date, '10', '', '', ''); ?></td>
										 </tr>
										 <?php
										 $detailCount++;
										}
										?>
 									</tbody>
 								 </table>

 								</fieldset>

 							 </div>

 							</td>

 						 </tr>
							<?php
							$linecount++;
						 }
						 ?>
						</tbody>
					 </table>
					</div>
					<div id="tabsLine-2" class="scrollElement tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>E Field</th>
							<th>Status</th>
							<th>Start Date</th>
							<th>End Date</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $linecount = 0;
						 foreach ($option_line_object as $option_line) {
							?>         
 						 <tr class="option_line<?php echo $linecount ?>">
 							<td><?php echo form::extra_field($option_line->efid, '5'); ?></td>
 							<td><?php echo form::status_field($option_line->status); ?></td>
 							<td><?php echo form::date_field('effective_start_date', $option_line->effective_start_date, '10', '', '', ''); ?></td>
 							<td><?php echo form::date_field('effective_end_date', $option_line->effective_end_date, '10', '', '', ''); ?></td>
 						 </tr>
							<?php
							$linecount++;
						 }
						 ?>
						</tbody>
						<!--                  Showing a blank form for new entry-->
					 </table>
					</div>
				 </div>
				</div>
       </form> 
      </div>

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
