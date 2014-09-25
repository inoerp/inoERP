<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="wip_move_transaction_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<form action=""  method="post" id="wip_move_transaction"  name="wip_move_transaction">
			 <div id ="form_header">
				<div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Sales Order</a></li>
         </ul>
				 <div class="tabContainer"> 
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column four_column">
						 <li>
							<label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="wip_wo_header_id select_popup clickable">
               WO Header Id(1) : </label> <?php echo $f->text_field_dsr('wip_wo_header_id'); ?>
							<a name="show" class="show wip_wo_headerid_show"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label>WO Number : </label>
							<?php echo form::text_field_d('wo_number'); ?>
						 </li>
						 <li>
							<label> Inventory Org : </label>
							<?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly, '', '', 1); ?>
						 </li>
						 <li><label>Date(2) : </label>
							<?php echo form::date_fieldFromToday('transaction_date', ino_date($$class->transaction_date), 1); ?>
						 </li>
						 <li><label>Transaction Type : </label>
							<?php echo form::select_field_from_object('transaction_type', wip_move_transaction::wip_transactions(), 'option_line_code', 'option_line_value', $$class->transaction_type, 'transaction_type', $readonly, '', '', 1); ?>
						 </li> 
						 <li>
							<label> Move Transaction Id : </label>
							<?php echo form::text_field_dsr('wip_move_transaction_id'); ?>
						 </li>
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-2" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column five_column">
						 <li><label>SO Number : </label><?php echo form::text_field_d('sales_order_header_id'); ?></li>               
						 <li><label>Line Number : </label><?php echo form::text_field_d('sales_order_line_id'); ?></li>
						</ul>
					 </div>
					</div>
				 </div>
        </div>
			 </div>
			 <div id ="form_line" class="form_line"><span class="heading"> Operation Details </span>
				<div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Operation</a></li>
          <li><a href="#tabsLine-2">Scrap</a></li>
         </ul>
				 <div class="tabContainer"> 
					<div id="tabsLine-1" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column six_column"> 
						 						 <li><label>Item Id : </label>
							<?php form::text_field_drm('item_id_m'); ?>
						 </li>
						 <li><label>Item Number : </label>
							<?php form::text_field_dr('item_number'); ?>
						 </li>
						 <li><label>Description: </label>
							<?php form::text_field_widr('item_description'); ?>
						 </li>
						 <li><label>UOM : </label>
							<?php echo $f->select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom_id','uom_id'); ?>
						 </li>
						 <li><label>Total Quantity : </label>
							<?php form::number_field_dr('total_quantity'); ?>
						 </li>
						 	 <li><label>Completed Quantity : </label>
													 <?php form::number_field_wid2s('completed_quantity'); ?>
						 </li>

						</ul>
					 </div>
					 <div class="second_rowset">

						<table class="form_line_data_table"><span class="heading">Quantity Status</span>
						 <thead> 
							<tr>
							 <th>Sequence</th>
							 <th>Department</th>
							 <th>Description</th>
							 <th>Queue</th>
							 <th>Running</th>
							 <th>Rejected</th>
							 <th>Scrapped</th>
							 <th>To Move</th>
							 
							</tr>
						 </thead>
						 <tbody class="form_data_line_tbody wip_wo_routing_line_values" >
							<?php
							$count = 0;
							foreach ($wip_wo_routing_line_object as $wip_wo_routing_line) {
							 ?>         
 							<tr class="wip_wo_routing<?php echo $count ?>">
 							 <td><?php form::number_field_wid2sr('routing_sequence'); ?></td>
 							 <td><?php echo $f->select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class_second->department_id, '', '', '', 1); ?></td>
 							 <td><?php form::text_field_wid2r('description'); ?></td>
 							 <td><?php form::number_field_wid2sr('queue_quantity'); ?></td>
 							 <td><?php form::number_field_wid2sr('running_quantity'); ?></td>
 							 <td><?php form::number_field_wid2sr('rejected_quantity'); ?></td>
 							 <td><?php form::number_field_wid2sr('scrapped_quantity'); ?></td>
 							 <td><?php form::number_field_wid2sr('tomove_quantity'); ?></td>
 							 
 							</tr>
							 <?php
							 $count = $count + 1;
							}
							?>
						 </tbody>
						</table>

					 </div>
					 						<ul class="column six_column"> 
						 <li><label>From Seq : </label>
							<?php echo!empty($routing_line_details) ? form::select_field_from_object('from_routing_sequence', $routing_line_details, 'routing_sequence', 'routing_sequence', $$class->from_routing_sequence, 'from_routing_sequence', $readonly,'', '', 1) : form::text_field_ds('from_routing_sequence'); ?>
						 </li>
						 <li><label>From Step : </label>
							<?php echo form::select_field_from_object('from_operation_step', bom_routing_header::wip_move_step(), 'option_line_code', 'option_line_value', $$class->from_operation_step, 'from_operation_step', $readonly, '', '', 1); ?>
						 </li>
						 <li><label>Available Qty: </label>
							<?php form::number_field_drs('available_quantity'); ?>
						 </li>
						 <li><label>Move Qty: </label>
							<?php form::number_field_dm('move_quantity'); ?>
						 </li>
						 <li><label>To Seq : </label>
							<?php echo!empty($routing_line_details) ? form::select_field_from_object('to_routing_sequence', $routing_line_details, 'routing_sequence', 'routing_sequence', $$class->to_routing_sequence, 'to_routing_sequence', $readonly,'', '', 1) : form::text_field_ds('from_routing_sequence'); ?>
						 </li>
						 <li><label>To Step : </label>
							<?php echo form::select_field_from_object('to_operation_step', bom_routing_header::wip_move_step(), 'option_line_code', 'option_line_value', $$class->to_operation_step, 'to_operation_step', $readonly, '', '', 1); ?>
						 </li>
						</ul>
					 <!--end of tab1 div three_column-->
					</div> 
					<!--end of tab1-->
					<div id="tabsLine-2" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Reason : </label> 
							<?php form::text_field_d('reason'); ?>
						 </li>
						 <li><label>Reference : </label> 
							<?php form::text_field_d('reference'); ?>
						 </li>
						 <li><label>Scrap Ac: </label><?php form::account_field('scrap_account_id'); ?></li>
						 </ul>
					 </div>
					 <div class="second_rowset">

					 </div> 
					 <!--                end of tab2 div three_column-->
					</div>
				 </div>
        </div>
			 </div> 
			</form>

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
