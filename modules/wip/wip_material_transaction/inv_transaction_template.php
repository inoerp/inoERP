<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="inv_transaction_divId">
			<div id="inv_transaction_searchId">
			</div>
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action="inv_transaction.php"  method="post" id="inv_transaction"  name="inv_transaction">
        <!--create empty form or a single id when search is not clicked and the id is referred from other page -->
        <span class="heading">WIP Material Transaction </span> 
        <table class="form_table">
         <tr>
					<td>
					 <label><img id="wip_wo_popup" class="showPointer wip_wo_headerid_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
						WO Header Id(1) : </label>
					 <?php echo form::text_field_d('wip_wo_header_id'); ?>
					</td>
					<td><label>WO Number : </label>
					 <?php echo form::text_field_d('wo_number'); ?>
					</td>
					<td><lable>Inventory Org </lable>
				 <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>
         </td>
         <td><lable>Transaction Type </lable>
				 <?php
				 echo!(empty($id_array)) ? form::select_field_from_object('transaction_type_id', transaction_type::find_some_byIdArray($id_array), 'transaction_type_id', 'transaction_type', $$class->transaction_type_id, 'transaction_type_id', $readonly) :
								 form::select_field_from_object('transaction_type_id', transaction_type::find_all(), 'transaction_type_id', 'transaction_type', $$class->transaction_type_id, 'transaction_type_id', $readonly);
				 ?>
				 <a name="show" class="show wip_wo_headerid_show">
					<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
         </td>
         </tr>
        </table>
        <div id="tabs">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">General Info</a></li>
					<li><a href="#tabsLine-2">Transfer Info</a></li>
          <li><a href="#tabsLine-3">Reference Info</a></li>
          <li><a href="#tabsLine-4">Finance Info</a></li>
         </ul>
				 <div class="tabContainer"> 
					<div id="tabsLine-1" class="tabContent">
					 <table class="form_table">
						<thead> 
						 <tr>
							<th>Action</th>
							<th>BOM Seq</th>
							<th>BOM Id</th>
							<th>Item Id</th>
							<th>Item Number</th>
							<th>Item Description</th>
							<th>UOM</th>
							<th>Quantity</th>
							<th>Transaction Id</th>
						 </tr>
						</thead>
						<tbody class="inv_transaction_values">
						 <tr class="inv_transaction_row0" id="tab1_1">
							<td>    
							 <ul class="inline_action">
								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->bom_sequence); ?>"></li>           
							 </ul>
							</td>
							<td><?php echo !empty($bom_sequence_stament) ? $bom_sequence_stament : form::text_field_wid2s('bom_sequence'); ?></td>
							<td><?php form::text_field_wid2sm('wip_wo_bom_id'); ?></td>
							<td>
							 <?php form::text_field_wids('item_id'); ?>
							</td>
							<td>
							 <?php form::text_field_drm('item_number'); ?>
							</td>
							<td>
							 <?php form::text_field_dr('item_description'); ?>
							</td>
							<td>
							 <?php echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom', $$class->uom_id, '', $readonly); ?>
							</td>
							<td>
							 <?php form::text_field_widsm('quantity'); ?>
							</td>
							<td>
							 <?php echo form::text_field_dsr('inv_transaction_id'); ?>
							</td>
						 </tr>
						</tbody>
					 </table>
					</div>
					<div id="tabsLine-2" class="tabContent">
					 <table class="form_table">
						<thead> 
						 <tr>
							<th>From SubInv</th>
							<th>From Locator </th>
							<th>To SubInv</th>
							<th>To Locator</th>
							<th>Lot</th>
							<th>Serial</th>
							<th>Ef Id</th>
						 </tr>
						</thead>
						<tbody class="inv_transaction_values">
						 <tr class="inv_transaction_row0 transfer_info" id="tab2_1">
							<td>
							 <?php echo form::select_field_from_object('from_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->from_subinventory_id, '', $readonly, 'subinventory_id'); ?>
							</td>
							<td>
							 <?php echo form::select_field_from_object('from_locator_id', locator::find_all_of_subinventory($$class->from_subinventory_id), 'locator_id', 'locator', $$class->from_locator_id, '', $readonly, 'subinventory_id'); ?>
							</td>
							<td>
							 <?php echo form::select_field_from_object('to_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->to_subinventory_id, '', $readonly, 'subinventory_id'); ?>
							</td>
							<td>
							 <?php echo form::select_field_from_object('to_locator_id', locator::find_all_of_subinventory($$class->to_subinventory_id), 'locator_id', 'locator', $$class->to_locator_id, '', $readonly, 'subinventory_id'); ?>
							</td>
							<td>
							 <?php form::text_field_wid('lot_number'); ?>
							</td>
							<td>
							 <?php form::text_field_wid('serial_number'); ?>
							</td>
							<td>
							 <?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
							</td>
						 </tr>
						</tbody>
					 </table>
					</div>
					<div id="tabsLine-3" class="tabContent">
					 <table class="form_table">
						<thead> 
						 <tr>
							<th>Document Type</th>
							<th>Doc. Number</th>
							<th>Doc. Id</th>
							<th>Reason</th>
							<th>Reference</th>
							<th>Description</th>
							<th>View Document</th>
						 </tr>
						</thead>
						<tbody class="inv_transaction_values">
						 <tr class="inv_transaction_row0" id="tab3_1">
							<td><?php form::text_field_wid('document_type'); ?>							</td>
							<td><?php form::text_field_wid('document_number'); ?> 							</td>
							<td><?php form::text_field_wid('document_id'); ?>							</td>
							<td><?php form::text_field_wid('reason'); ?>							</td>
							<td><?php form::text_field_wid('reference'); ?>							</td>
							<td><?php form::text_field_wid('description'); ?>							</td>
							<td><?php echo!(empty($view_doc_statement)) ? $view_doc_statement : ''; ?>							</td>

						 </tr>
						</tbody>
					 </table>
					</div>
					<div id="tabsLine-4" class="tabContent">
					 <table class="form_table">
						<thead> 
						 <tr>
							<th>Account</th>
							<th>Unit Cost</th>
							<th>Costed Amount</th>
							<th>Transferred To GL<th>
						 </tr>
						</thead>
						<tbody class="inv_transaction_values">
						 <tr class="inv_transaction_row0" id="tab4_1">
							<td>
							 <?php form::account_field('account_id'); ?>
							</td>
							<td>
							 <?php form::text_field_wid('unit_cost'); ?>
							</td>
							<td>
							 <?php form::text_field_wid('costed_amount'); ?>
							</td>
							<td>
							 <?php echo form::checkBox_field('transfer_to_gl_cb', $$class->transfer_to_gl_cb, 'transfer_to_gl_cb', $readonly); ?>
							</td> 

						 </tr>
						</tbody>
					 </table>
					</div>
				 </div>

        </div>

        <!--                 complete Showing a blank form for new entry-->
       </form>

			</div>
			<!--END OF FORM HEADER-->
			<div id="pagination" style="clear: both;">
			 <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
			 ?>
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
