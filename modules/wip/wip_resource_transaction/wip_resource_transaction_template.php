<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="wip_resource_transaction_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<!--<form action=""  method="post" id="wip_resource_transaction_header"  name="wip_resource_transaction_header">-->
			<!--<div id ="form_header">-->
			<div id="tabsHeader">
			 <ul class="tabMain">
				<li><a href="#tabsHeader-1">Basic Info</a></li>
				<li><a href="#tabsHeader-2">Other Details</a></li>
			 </ul>
			 <div class="tabContainer"> 
				<div id="tabsHeader-1" class="tabContent">
				 <div class="large_shadow_box"> 
					<ul class="column four_column">
					 <li>
						<label><img id="wip_wo_popup" class="showPointer wip_wo_headerid_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
						 WO Header Id(1) : </label>
						<?php echo form::text_field_d('wip_wo_header_id'); ?>
						<a name="show" class="show wip_wo_headerid_show">
						 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					 </li>
					 <li><label>WO Number : </label> <?php echo form::text_field_d('wo_number'); ?></li>
					 <li><label> Inventory Org : </label>
						<?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly, '', '', 1); ?>
					 </li>
					 <li><label>Date(2) : </label>
						<?php echo form::date_fieldFromToday('transaction_date', ino_date($$class->transaction_date), 1, '', '', 1); ?>
					 </li>
					 <li><label>Transaction Type : </label>
						<?php echo form::select_field_from_object('transaction_type', wip_resource_transaction::wip_transactions(), 'option_line_code', 'option_line_value', $$class->transaction_type, 'transaction_type', 1, '', '', 1); ?>
					 </li> 
					</ul>
				 </div>
				</div>
				<div id="tabsHeader-2" class="tabContent">
				 <div class="large_shadow_box"> 
					<ul class="column six_column"> 
					 <li><label>Item Id : </label><?php form::text_field_drm('item_id'); ?></li>
					 <li><label>Item Number : </label><?php form::text_field_dr('item_number'); ?></li>
					 <li><label>Description: </label><?php form::text_field_widr('item_description'); ?></li>
					 <li><label>UOM : </label>
						<?php echo form::select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom'); ?>
					 </li>
					 <li><label>Total Quantity : </label><?php form::number_field_dr('total_quantity'); ?></li>
					 <li><label>Completed Quantity : </label><?php form::number_field_wid2sr('completed_quantity'); ?></li>
					 <li><label>SO Number : </label><?php echo form::text_field_dr('sales_order_header_id'); ?></li>               
					 <li><label>Line Number : </label><?php echo form::text_field_dr('sales_order_line_id'); ?></li>
					</ul>
				 </div>
				</div>
			 </div>
			</div>
			<!--</div>-->
			<!--</form>-->
			<div id ="form_line" class="form_line"><span class="heading"> Operation Details </span>
			 <div id="tabsLine">
				<ul class="tabMain">
				 <li><a href="#tabsLine-1">Operation</a></li>
				 <li><a href="#tabsLine-2">Future</a></li>
				</ul>
				<div class="tabContainer"> 
				 <form action=""  method="post" id="wip_resource_transaction"  name="wip_resource_transaction">
					<div id="tabsLine-1" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>Action</th>
							<th>Routing Seq</th>
							<th>Department</th>
							<th>Resource Seq</th>
							<th>Resource</th>
							<th>Quantity</th>
							<th>Required</th>
							<th>Applied</th>
							<th>Reason</th>
							<th>Reference</th>
							<th>Trnx Id</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody wip_wo_routing_line_values" >
						 <?php
						 $detailCount = 0;
						 foreach ($wip_wo_routing_detail_object as $wip_wo_routing_detail) {
							$class_third = 'wip_wo_routing_detail';
							$$class_third = &$wip_wo_routing_detail;
							?>
 						 <tr class="wip_move_transaction<?php echo $detailCount ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($wip_wo_routing_line->wip_wo_routing_line_id); ?>"></li>           
 								<li><?php echo form::hidden_field('wip_wo_header_id', $$class->wip_wo_header_id); ?></li>
 								<li><?php echo form::hidden_field('org_id', $$class->org_id); ?></li>
 								<li><?php echo form::hidden_field('transaction_type', $$class->transaction_type); ?></li>
 								<li><?php echo form::hidden_field('transaction_date', $$class->transaction_date); ?></li>
 								<li><?php echo form::hidden_field('wip_wo_routing_line_id', $$class_third->wip_wo_routing_line_id); ?></li>
 								<li><?php echo form::hidden_field('wip_wo_routing_detail_id', $$class_third->wip_wo_routing_detail_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php form::number_field_wid3sr('routing_sequence'); ?></td>
 							<td><?php echo form::select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class_third->department_id, 'department_id', 1); ?></td>
 							<td><?php form::text_field_wid3sr('resource_sequence'); ?></td>
 							<td><?php echo form::select_field_from_object('resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_third->resource_id, '', 1, 'resource_id', '', 1); ?></td>
 							<td><?php form::number_field_wids('transaction_quantity'); ?></td>
 							<td><?php form::number_field_wid3sr('required_quantity'); ?></td>
 							<td><?php form::number_field_wid3sr('applied_quantity'); ?></td>
 							<td><?php form::number_field_wid('reason'); ?></td>
 							<td><?php form::number_field_wid('reference'); ?></td>
 							<td><?php echo form::text_field_dsr('wip_resource_transaction_id'); ?></td>
 						 </tr>
							<?php
							$detailCount++;
						 }
						 ?>

						</tbody>
					 </table>


					</div> 
					<!--end of tab1-->
					<div id="tabsLine-2" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						</ul>
					 </div>
					 <div class="second_rowset">

					 </div> 
					 <!--                end of tab2 div three_column-->
					</div>
				 </form>
				</div>
			 </div>
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
