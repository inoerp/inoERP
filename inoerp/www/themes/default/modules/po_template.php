<div id="all_contents">
 <h2><?php echo gettext('From Default Theme') ?></h2>
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="po_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<div id ="form_header">
			 <form action=""  method="post" id="po_header"  name="po_header">
				<div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
          <li><a href="#tabsHeader-2"><?php echo gettext('Finance') ?></a></li>
					<li><a href="#tabsHeader-3"><?php echo gettext('Address Details') ?></a></li>
					<li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
					<li><a href="#tabsHeader-5"><?php echo gettext('Actions') ?></a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column four_column">
						 <li><label><?php echo gettext('BU Name') ?>(1) : </label>
							<?php echo form::select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $po_header->bu_org_id, 'bu_org_id', $readonly, '', ''); ?>
						 </li>
						 <li><label><?php echo gettext('PO Type') ?>(2) : </label>
							<?php echo form::select_field_from_object('po_type', po_header::po_types(), 'option_line_code', 'option_line_value', $po_header->po_type, 'po_type', $readonly, '', ''); ?>
						 </li>
						 <li><label><a href="../../../select.php?class_name=po_header" class="popup">
               <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>
							 <?php echo gettext('PO Header Id') ?> : </label>
							<?php echo form::text_field('po_header_id', $po_header->po_header_id, '15', '25', '', 'System Number', 'po_header_id', $readonly) ?>
							<a name="show" href="po.php?po_header_id=" class="show po_header_id">
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label><?php echo gettext('PO Number') ?> : </label>
							<?php echo form::text_field_d('po_number'); ?>
						 </li>
						 <li>
							<label>
							 <input type="button"  class="find_popup supplierId">
<!--							 <img class="supplier_id_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png"/>-->
							 <?php echo gettext('Supplier Id') ?>(3) : </label>
							<?php echo form::text_field_d('supplier_id'); ?>
						 </li>
						 <li><label class="auto_complete"><?php echo gettext('Supplier Name') ?>(3) : </label>
							<?php echo (!empty($supplier_name_statement)) ? $supplier_name_statement : form::text_field_d('supplier_name'); ?>
						 </li>
						 <li><label><?php echo gettext('Supplier Number') ?> : </label>
							<?php echo (!empty($supplier_number_statement)) ? $supplier_number_statement : form::text_field_d('supplier_number'); ?>
						 </li> 
						 <li><label><?php echo gettext('Supplier Site') ?> : </label>
							<?php
							if ((!empty($supplier_site_name_statement))) {
							 echo $supplier_site_name_statement;
							} else {
							 ?>
 							<Select name="supplier_site_id[]" class="supplier_site_id select" id="supplier_site_id" >
 							 <option value="" ></option>
 							</select> 
							<?php } ?>
						 </li>
						 <li><label><?php echo gettext('EF Id') ?> : </label>
							<?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
						 </li>
						 <li><label><?php echo gettext('Status') ?> : </label>                      
							<span class="button"><?php echo!empty($$class->po_status) ? $$class->po_status : ""; ?></span>
						 </li>
						 <li><label><?php echo gettext('Revision') ?> : </label>
							<?php echo form::checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?>
						 </li> 
						 <li><label><?php echo gettext('Rev Number') ?> : </label>
							<?php form::text_field_wid('rev_number'); ?>
						 </li> 
						 <li><label><?php echo gettext('Buyer') ?> : </label>
							<?php form::text_field_wid('buyer'); ?>
						 </li> 
						 <li><label><?php echo gettext('Description') ?> : </label>
							<?php form::text_field_wid('description'); ?>
						 </li> 
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-2" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label><?php echo gettext('Currency') ?> : </label>
							<?php echo!(empty($po_currency_statement)) ? $po_currency_statement : form::text_field_d('currency'); ?>
						 </li>
						 <li><label><?php echo gettext('Payment Term') ?> : </label>
							<?php echo!(empty($po_paymentTerm_statement)) ? $po_paymentTerm_statement : form::text_field_d('payment_term_id'); ?>
						 </li>
						 <li><label><?php echo gettext('Agreement Start Date') ?> : </label>
							<?php echo form::date_field('agreement_start_date', $$class->agreement_start_date) ?>
						 </li>
						 <li><label><?php echo gettext('Agreement End Date') ?> : </label>
							<?php echo form::date_field('agreement_end_date', $$class->agreement_start_date) ?>
						 </li>
						 <li><label><?php echo gettext('Exchange Rate Type') ?> : </label>
							<?php echo form::text_field_d('exchange_rate_type'); ?>
						 </li>
						 <li><label><?php echo gettext('Exchange Rate') ?> : </label>
							<?php form::number_field_d('exchange_rate'); ?>
						 </li>
						 <li><label><?php echo gettext('Header Amount') ?> : </label>
							<?php form::number_field_d('header_amount'); ?>
						 </li>
						 <li><label><?php echo gettext('Released Amount') ?> : </label>
							<?php form::number_field_d('released_amount'); ?>
						 </li>
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-3" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label><?php echo gettext('Ship To Site Id') ?> : 
							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup"></label>
							<?php echo form::text_field_d('ship_to_id'); ?>
						 </li>
						 <li><label><?php echo gettext('Ship To Site Address') ?> : </label>
							<?php echo form::text_field_d('ship_to_address'); ?>
						 </li>
						 <li><label><?php echo gettext('Bill To Site Id') ?> :
							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup"></label>
							<?php echo form::text_field_d('bill_to_id'); ?>
						 </li>
						 <li><label><?php echo gettext('Bill To Site Address') ?> :</label>
							<?php echo form::text_field_d('bill_to_address'); ?>
						 </li>
						</ul>
						<div class="shipto address_details">
						 <?php echo!empty($ship_to_id) ? $ship_to_id : ""; ?>
						</div> 
						<div class="billto address_details">
						 <?php echo!empty($bill_to_id) ? $bill_to_id : ""; ?>
						</div> 
					 </div>
					</div>
					<div id="tabsHeader-4" class="tabContent">
					 <div> 
						<div id="show_attachment" class="show_attachment">
						 <input type="button" class="attachment_button button" value="<?php echo gettext('Attachments') ?>" id="attachment_button" name="">
						 <?php echo extn_file::attachment_statement($po_file); ?>
						 <div id="supplier_header_level_attachement" >
						 </div>
						 <div id="supplier_line_level_attachement" >
						 </div>
						</div>
					 </div>
					</div>
					<div id="tabsHeader-5" class="tabContent">
					 <div> 
						<ul class="column four_column">
						 <li id="document_print"><label><?php echo gettext('Document Print') ?> : </label>
							<a class="button" target="_blank"
								 href="po_print.php?po_header_id=<?php echo!(empty($$class->po_header_id)) ? $$class->po_header_id : ""; ?>" ><?php echo gettext('Print PO') ?></a>
						 </li>
						 <li id="document_status"><label><?php echo gettext('Change Status') ?> : </label>
							<?php echo form::select_field_from_object('po_status', po_header::po_status(), 'option_line_code', 'option_line_value', $po_header->po_status, 'set_po_status', $readonly, '', ''); ?>
						 </li>
						 <li id="copy_header"><label><?php echo gettext('Copy Document') ?> : </label>
							<input type="button" class="button" id="copy_docHeader" value="<?php echo gettext('PO Header') ?>">
						 </li>
						 <li id="copy_line"><label></label>
							<input type="button" class="button" id="copy_docLine" value="<?php echo gettext('PO Lines') ?>">
						 </li>
						</ul>

						<div id="comment" class="shoe_comments">
						</div>
					 </div>
					</div>
				 </div>

				</div>
			 </form>
			</div>

			<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('PO Lines & Shipments') ?> </span>
			 <form action=""  method="post" id="po_site"  name="po_line">
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
					<li><a href="#tabsLine-2"><?php echo gettext('Other Info') ?></a></li>
					<li><a href="#tabsLine-3"><?php echo gettext('Notes') ?></a></li>
				 </ul>
				 <div class="tabContainer">
					<div id="tabsLine-1" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th><?php echo gettext('Action') ?></th>
							<th><?php echo gettext('Line Id') ?></th>
							<th><?php echo gettext('Line Number') ?></th>
							<th><?php echo gettext('Type') ?></th>
							<th><?php echo gettext('Item Id') ?></th>
							<th><?php echo gettext('Item Number') ?></th>
							<th><?php echo gettext('Item Description') ?></th>
							<th><?php echo gettext('UOM') ?></th>
							<th><?php echo gettext('Quantity') ?></th>
							<th><?php echo gettext('Shipment Details') ?></th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($po_line_object as $po_line) {
							?>         
 						 <tr class="po_line<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="<?php echo gettext('add new line') ?>" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="<?php echo gettext('remove this line') ?>" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($po_line->item_description); ?>"></li>           
 								<li><?php echo form::hidden_field('po_header_id', $po_header->po_header_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php form::text_field_wid2sr('po_line_id'); ?></td>
 							<!--<td><?php // form::text_field_wid2s('line_number');         ?></td>-->
 							<td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
 							<td><?php echo form::select_field_from_object('line_type', po_line::po_line_types(), 'option_line_id', 'option_line_code', $$class_second->line_type, 'line_type', $readonly); ?></td>
 							<td><?php form::text_field_wid2sr('item_id_m'); ?></td>
 							<td><?php form::text_field_wid2('item_number'); ?></td>
 							<td><?php form::text_field_wid2('item_description'); ?></td>
							<td><?php echo form::select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom', $$class_second->uom, 'uom');; ?></td>
 							<td><?php form::number_field_wid2s('line_quantity'); ?></td>

 							<td class="add_detail_values"><img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="<?php echo gettext('add detail values') ?>" />
 							 <!--</td></tr>-->	
								<?php
								$po_line_id = $po_line->po_line_id;
								if (!empty($po_line_id)) {
								 $po_detail_object = po_detail::find_by_po_lineId($po_line_id);
								} else {
								 $po_detail_object = array();
								}
								if (count($po_detail_object) == 0) {
								 $po_detail = new po_detail();
								 $po_detail_object = array();
								 array_push($po_detail_object, $po_detail);
								}
								?>
 <!--						 <tr><td>-->
 							 <div class="class_detail_form">
 								<fieldset class="form_detail_data_fs"><legend><?php echo gettext('Detail Data') ?></legend>
 								 <div class="tabsDetail">
 									<ul class="tabMain">
 									 <li class="tabLink"><a href="#tabsDetail-1-1"><?php echo gettext('Basic') ?></a></li>
 									 <li class="tabLink"><a href="#tabsDetail-2-1"><?php echo gettext('Delivery') ?></a></li>
 									 <li class="tabLink"><a href="#tabsDetail-3-1"><?php echo gettext('Finance') ?></a></li>
 									 <li class="tabLink"><a href="#tabsDetail-4-1"><?php echo gettext('Status') ?></a></li>
 									</ul>
 									<div class="tabContainer">
 									 <div id="tabsDetail-1-1" class="tabContent">
 										<table class="form form_detail_data_table detail">
 										 <thead>
 											<tr>
 											 <th><?php echo gettext('Action') ?></th>
 											 <th><?php echo gettext('Shipment Id') ?></th>
 											 <th><?php echo gettext('Shipment Number') ?></th>
 											 <th><?php echo gettext('Inventory') ?></th>
 											 <th><?php echo gettext('Ship To Location') ?></th>
 											 <th><?php echo gettext('Quantity') ?></th>
 											 <th><?php echo gettext('Need By Date') ?></th>
 											 <th><?php echo gettext('Promise Date') ?></th>

 											</tr>
 										 </thead>
 										 <tbody class="form_data_detail_tbody">
											 <?php
											 $detailCount = 0;
											 foreach ($po_detail_object as $po_detail) {
												$class_third = 'po_detail';
												$$class_third = &$po_detail;
												?>
												<tr class="po_detail<?php echo $count . '-' . $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
												 <td>   
													<ul class="inline_action">
													 <li class="add_row_detail_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="<?php echo gettext('add new line') ?>" /></li>
													 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="<?php echo gettext('remove this line') ?>" /> </li>
													 <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($po_detail->po_detail_id); ?>"></li>           
													 <li><?php echo form::hidden_field('po_line_id', $po_line->po_line_id); ?></li>
													 <li><?php echo form::hidden_field('po_header_id', $po_header->po_header_id); ?></li>

													</ul>
												 </td>
												 <td><?php form::text_field_wid3sr('po_detail_id'); ?></td>
												 <td><?php form::number_field_wid3s('shipment_number','details_number'); ?></td>
												 <!--<td><?php // echo form::text_field('shipment_number', $$class_third->shipment_number, '8', '20', 1, 'Auto no', '', $readonly, 'details_number');											 ?></td>-->
												 <td><?php echo form::select_field_from_object('ship_to_inventory', org::find_all_inventory(), 'org_id', 'org', $$class_third->ship_to_inventory, '', $readonly); ?></td>
												 <td><?php form::text_field_wid3('ship_to_location_id'); ?></td>
												 <td><?php form::number_field_wid3s('quantity'); ?></td>
												 <td><?php echo form::date_fieldFromToday('need_by_date', ino_date($$class_third->need_by_date)); ?></td>
												 <td><?php echo form::date_fieldFromToday('promise_date', ino_date($$class_third->promise_date)); ?></td>

												</tr>
												<?php
												$detailCount++;
											 }
											 ?>
 										 </tbody>
 										</table>
 									 </div>
 									 <div id="tabsDetail-2-1" class="tabContent">
 										<table class="form form_detail_data_table detail">
 										 <thead>
 											<tr>
 											 <th><?php echo gettext('Subinventory') ?></th>
 											 <th><?php echo gettext('Locator') ?></th>
 											 <th><?php echo gettext('Requestor') ?></th>
 											</tr>
 										 </thead>
 										 <tbody class="form_data_detail_tbody">
											 <?php
											 $detailCount = 0;
											 foreach ($po_detail_object as $po_detail) {
												$class_third = 'po_detail';
												$$class_third = &$po_detail;
												?>
												<tr class="po_detail<?php echo $count . '-' . $detailCount; ?> <?php echo $detailCount != 0 ? ' new_object' : '' ?>">
												 <td><?php form::text_field_wid3('sub_inventory_id'); ?></td>
												 <td><?php form::text_field_wid3('locator_id'); ?></td>
												 <td><?php form::text_field_wid3('requestor'); ?></td>
												</tr>
												<?php
												$detailCount++;
											 }
											 ?>
 										 </tbody>
 										</table>
 									 </div>
 									 <div id="tabsDetail-3-1" class="tabContent">
 										<table class="form form_detail_data_table detail">
 										 <thead>
 											<tr>
 											 <th><?php echo gettext('Charge Ac') ?></th>
 											 <th><?php echo gettext('Accrual Ac') ?></th>
 											 <th><?php echo gettext('Budget Ac') ?></th>
 											 <th><?php echo gettext('PPV Ac') ?></th>
 											</tr>
 										 </thead>
 										 <tbody class="form_data_detail_tbody">
											 <?php
											 $detailCount = 0;
											 foreach ($po_detail_object as $po_detail) {
												$class_third = 'po_detail';
												$$class_third = &$po_detail;
												?>
												<tr class="po_detail<?php echo $count . '-' . $detailCount; ?> <?php echo $detailCount != 0 ? ' new_object' : '' ?>">
												 <td><?php form::account_field3('charge_ac_id'); ?></td>
												 <td><?php form::account_field3('accrual_ac_id'); ?></td>
												 <td><?php form::account_field3('budget_ac_id'); ?></td>
												 <td><?php form::account_field3('ppv_ac_id'); ?></td>
												</tr>
												<?php
												$detailCount++;
											 }
											 ?>
 										 </tbody>
 										</table>
 									 </div>
 									 <div id="tabsDetail-4-1" class="tabContent">
 										<table class="form form_detail_data_table detail"><label><?php echo gettext('Quantities') ?></label>
 										 <thead>
 											<tr>
 											 <th><?php echo gettext('Received') ?></th>
 											 <th><?php echo gettext('Accepted') ?></th>
 											 <th><?php echo gettext('Delivered') ?></th>
 											 <th><?php echo gettext('Invoiced') ?></th>
 											 <th><?php echo gettext('Paid') ?></th>
 											</tr>
 										 </thead>
 										 <tbody class="form_data_detail_tbody">
											 <?php
											 $detailCount = 0;
											 foreach ($po_detail_object as $po_detail) {
												$class_third = 'po_detail';
												$$class_third = &$po_detail;
												?>
												<tr class="po_detail<?php echo $count . '-' . $detailCount; ?> <?php echo $detailCount != 0 ? ' new_object' : '' ?>">
												 <td><?php form::number_field_wid3s('received_quantity'); ?></td>
												 <td><?php form::number_field_wid3s('accepted_quantity'); ?></td>
												 <td><?php form::number_field_wid3s('delivered_quantity'); ?></td>
												 <td><?php form::number_field_wid3s('invoiced_quantity'); ?></td>
												 <td><?php form::number_field_wid3s('paid_quantity'); ?></td>
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

 							</td></tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
					 </table>
					</div>
					<div id="tabsLine-2" class="scrollElement tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th><?php echo gettext('Unit Price') ?></th>
							<th><?php echo gettext('Line Price') ?></th>
							<th><?php echo gettext('Line Description') ?></th>
							<th><?php echo gettext('Ref Doc Type') ?></th>
							<th><?php echo gettext('Ref Number') ?></th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($po_line_object as $po_line) {
							?>         
 						 <tr class="po_line<?php echo $count ?>">
 							<td><?php form::number_field_wid2('unit_price'); ?></td>
 							<td><?php form::number_field_wid2('line_price'); ?></td>
 							<td><?php form::text_field_wid2('line_description'); ?></td>
 							<td><?php form::text_field_wid2('reference_doc_type'); ?></td>
 							<td><?php form::text_field_wid2('reference_doc_number'); ?></td>
 						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
						<!--                  Showing a blank form for new entry-->
					 </table>
					</div>
					<div id="tabsLine-3" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th><?php echo gettext('Comments') ?></th>

						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($po_line_object as $po_line) {
							?>         
 						 <tr class="po_line<?php echo $count ?>">
 							<td></td>
 						 </tr>
							<?php
							$count = $count + 1;
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
