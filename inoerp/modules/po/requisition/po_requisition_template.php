<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="po_requisition_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
      <span class="heading">Requisition Header </span>
			<div id ="form_header">
			 <form action=""  method="post" id="po_requisition_header"  name="po_requisition_header">
				<div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Finance</a></li>
					<li><a href="#tabsHeader-3">Address Details</a></li>
					<li><a href="#tabsHeader-4">Attachments</a></li>
					<li><a href="#tabsHeader-5">Actions</a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column five_column">
						 <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="po_requisition_header_id select_popup clickable">
							 Requisition  Id : </label>
							<?php echo form::text_field('po_requisition_header_id', $po_requisition_header->po_requisition_header_id, '15', '25', '', 'System Number', 'po_requisition_header_id', $readonly) ?>
							<a name="show" href="po_requisition.php?po_requisition_header_id=" class="show po_requisition_header_id">
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label>Requisition Number : </label>
							<?php
							$f = new inoform();
							echo $f->text_field_d('po_requisition_number', 'search_data');
							?>
						 </li>
						 <li><label>BU Name(1) : </label>
							<?php echo form::select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $po_requisition_header->bu_org_id, 'bu_org_id', $readonly, '', ''); ?>
						 </li>
						 <li><label>Requisition Type(2) : </label>
							<?php echo form::select_field_from_object('po_requisition_type', po_requisition_header::po_requisition_type(), 'option_line_code', 'option_line_value', $po_requisition_header->po_requisition_type, 'po_requisition_type', $readonly, '', ''); ?>
						 </li>
						 <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="supplier_id select_popup clickable">
							 Supplier Id : </label>
							<?php echo form::text_field_dsr('supplier_id'); ?>
						 </li>
						 <li><label class="auto_complete">Supplier Name : </label><?php echo $supplier_name_stmt; ?></li>
						 <li><label class="auto_complete">Supplier Number : </label><?php echo $supplier_number_stmt; ?></li>
						 <li><label>Supplier Site : </label>
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
						 <li><label>Ef Id : </label>
							<?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
						 </li>
						 <li><label>Status : </label>                      
							<span class="button"><?php echo!empty($$class->requisition_status) ? $$class->requisition_status : ""; ?></span>
						 </li>
						 <li><label>Revision : </label>
							<?php echo form::checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?>
						 </li> 
						 <li><label>Rev Number : </label>
							<?php form::text_field_wid('rev_number'); ?>
						 </li> 
						 <li><label>Buyer : </label>
							<?php form::text_field_wid('buyer'); ?>
						 </li> 
						 <li><label>Description : </label>
							<?php form::text_field_wid('description'); ?>
						 </li> 
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-2" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label>Currency : </label>
							<?php echo!(empty($po_requisition_currency_statement)) ? $po_requisition_currency_statement : form::text_field_d('currency'); ?>
						 </li>
						 <li><label>Payment Term : </label>
							<?php echo!(empty($po_requisition_paymentTerm_statement)) ? $po_requisition_paymentTerm_statement : form::text_field_d('payment_term_id'); ?>
						 </li>
						 <li><label>Exchange Rate Type : </label>
							<?php echo form::text_field_d('exchange_rate_type'); ?>
						 </li>
						 <li><label>Exchange Rate : </label>
							<?php form::number_field_d('exchange_rate'); ?>
						 </li>
						 <li><label>Header Amount : </label>
							<?php form::number_field_d('header_amount'); ?>
						 </li>
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-3" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label>Ship To Site Id : 
							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_po_requisitionpup"></label>
							<?php echo form::text_field_d('ship_to_id'); ?>
						 </li>
						 <li><label>Ship To Site Address : </label>
							<?php echo form::text_field_d('ship_to_address'); ?>
						 </li>
						 <li><label>Bill To Site Id :
							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_po_requisitionpup"></label>
							<?php echo form::text_field_d('bill_to_id'); ?>
						 </li>
						 <li><label>Bill To Site Address :</label>
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
						 <input type="button" class="attachment_button button" value="Attachements" id="attachment_button" name="">
						 <?php echo file::attachment_statement($po_requisition_file); ?>
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
						 <li id="document_print"><label>Document Print : </label>
							<a class="button" target="_blank"
								 href="po_requisition_print.php?po_requisition_header_id=<?php echo!(empty($$class->po_requisition_header_id)) ? $$class->po_requisition_header_id : ""; ?>" >Print Requisition</a>
						 </li>
						 <li id="document_status"><label>Change Status : </label>
							<?php echo form::select_field_from_object('requisition_status', po_requisition_header::requisition_status(), 'option_line_code', 'option_line_value', $po_requisition_header->requisition_status, 'set_requisition_status', $readonly, '', ''); ?>
						 </li>
						</ul>

						<div id="comment" class="show_comments">
						</div>
					 </div>
					</div>
				 </div>

				</div>
			 </form>
			</div>

			<div id="form_line" class="form_line"><span class="heading">Requisition Lines & Shipments </span>
			 <form action=""  method="po_requisitionst" id="po_requisition_site"  name="po_requisition_line">
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">Basic</a></li>
					<li><a href="#tabsLine-2">Other Info</a></li>
					<li><a href="#tabsLine-3">Notes</a></li>
				 </ul>
				 <div class="tabContainer">
					<div id="tabsLine-1" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>Action</th>
							<th>Line Id</th>
							<th>Line#</th>
							<th>Receiving Org</th>
							<th>Type</th>
							<th>Item Number</th>
							<th>Item Description</th>
							<th>UOM</th>
							<th>Quantity</th>
							<th>Shipment Details</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($po_requisition_line_object as $po_requisition_line) {
							?>         
 						 <tr class="po_requisition_line<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($po_requisition_line->item_description); ?>"></li>           
 								<li><?php echo form::hidden_field('po_requisition_header_id', $po_requisition_header->po_requisition_header_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php form::text_field_wid2sr('po_requisition_line_id'); ?></td>
 							<td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
 							<td><?php echo $f->select_field_from_object('receving_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->receving_org_id, '', '', 1, $readonly); ?></td>
 							<td><?php echo form::select_field_from_object('line_type', po_requisition_line::po_requisition_line_types(), 'option_line_code', 'option_line_value', $$class_second->line_type, 'line_type', $readonly); ?></td>
 							<td><?php form::text_field_wid2('item_number', 'select_item_number'); ?>
 							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></td>
 							<td><?php form::text_field_wid2('item_description'); ?></td>
 							<td><?php
								echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom_id');
								?></td>
 							<td><?php form::number_field_wid2s('line_quantity'); ?></td>

 							<td class="add_detail_values"><img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
 							 <!--</td></tr>-->	
								<?php
								$po_requisition_line_id = $po_requisition_line->po_requisition_line_id;
								if (!empty($po_requisition_line_id)) {
								 $po_requisition_detail_object = po_requisition_detail::find_by_po_requisition_lineId($po_requisition_line_id);
								} else {
								 $po_requisition_detail_object = array();
								}
								if (count($po_requisition_detail_object) == 0) {
								 $po_requisition_detail = new po_requisition_detail();
								 $po_requisition_detail_object = array();
								 array_push($po_requisition_detail_object, $po_requisition_detail);
								}
								?>
              <!--						 <tr><td>-->
 							 <div class="class_detail_form">
 								<fieldset class="form_detail_data_fs"><legend>Detail Data</legend>
 								 <div class="tabsDetail">
 									<ul class="tabMain">
 									 <li class="tabLink"><a href="#tabsDetail-1-1">Basic</a></li>
 									 <li class="tabLink"><a href="#tabsDetail-2-1">Delivery</a></li>
 									 <li class="tabLink"><a href="#tabsDetail-3-1">Finance</a></li>
 									 <li class="tabLink"><a href="#tabsDetail-4-1">Status</a></li>
 									</ul>
 									<div class="tabContainer">
 									 <div id="tabsDetail-1-1" class="tabContent">
 										<table class="form form_detail_data_table detail">
 										 <thead>
 											<tr>
 											 <th>Action</th>
 											 <th>Shipment Id</th>
 											 <th>Shipment Number</th>
 											 <th>Ship To Location</th>
 											 <th>Quantity</th>
 											 <th>Need By Date</th>
 											 <th>Promise Date</th>

 											</tr>
 										 </thead>
 										 <tbody class="form_data_detail_tbody">
											 <?php
											 $detailCount = 0;
											 foreach ($po_requisition_detail_object as $po_requisition_detail) {
												$class_third = 'po_requisition_detail';
												$$class_third = &$po_requisition_detail;
												?>
												<tr class="po_requisition_detail<?php echo $count . '-' . $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
												 <td>   
													<ul class="inline_action">
													 <li class="add_row_detail_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
													 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
													 <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($po_requisition_detail->po_requisition_detail_id); ?>"></li>           
													 <li><?php echo form::hidden_field('po_requisition_line_id', $po_requisition_line->po_requisition_line_id); ?></li>
													 <li><?php echo form::hidden_field('po_requisition_header_id', $po_requisition_header->po_requisition_header_id); ?></li>

													</ul>
												 </td>
												 <td><?php form::text_field_wid3sr('po_requisition_detail_id'); ?></td>
												 <td><?php form::number_field_wid3s('shipment_number', 'detail_number'); ?></td>
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
 											 <th>Order Number</th>
 											 <th>Sub inventory</th>
 											 <th>Locator</th>
 											 <th>Requestor</th>
 											</tr>
 										 </thead>
 										 <tbody class="form_data_detail_tbody">
											 <?php
											 $detailCount = 0;
											 foreach ($po_requisition_detail_object as $po_requisition_detail) {
												$class_third = 'po_requisition_detail';
												$$class_third = &$po_requisition_detail;
												?>
												<tr class="po_requisition_detail<?php echo $count . '-' . $detailCount; ?> <?php echo $detailCount != 0 ? ' new_object' : '' ?>">
												 <td><?php form::text_field_wid3('order_number'); ?></td>
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
 											 <th>Charge Ac</th>
 											 <th>Accrual Ac</th>
 											 <th>Budget Ac</th>
 											 <th>PPV Ac</th>
 											</tr>
 										 </thead>
 										 <tbody class="form_data_detail_tbody">
											 <?php
											 $detailCount = 0;
											 foreach ($po_requisition_detail_object as $po_requisition_detail) {
												$class_third = 'po_requisition_detail';
												$$class_third = &$po_requisition_detail;
												?>
												<tr class="po_requisition_detail<?php echo $count . '-' . $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
												 <td><?php $f->ac_field_d3m('charge_ac_id'); ?></td>
												 <td><?php $f->ac_field_d3m('accrual_ac_id'); ?></td>
												 <td><?php $f->ac_field_d3('budget_ac_id'); ?></td>
												 <td><?php $f->ac_field_d3m('ppv_ac_id'); ?></td>
												</tr>
												<?php
												$detailCount++;
											 }
											 ?>
 										 </tbody>
 										</table>
 									 </div>
 									 <div id="tabsDetail-4-1" class="tabContent">
 										<table class="form form_detail_data_table detail"><lable>Quantities</lable>
 										 <thead>
 											<tr>
 											 <th>Received</th>
 											 <th>Accepted</th>
 											 <th>Delivered</th>
 											 <th>Invoiced</th>
 											 <th>Paid</th>
 											</tr>
 										 </thead>
 										 <tbody class="form_data_detail_tbody">
											 <?php
											 $detailCount = 0;
											 foreach ($po_requisition_detail_object as $po_requisition_detail) {
												$class_third = 'po_requisition_detail';
												$$class_third = &$po_requisition_detail;
												?>
												<tr class="po_requisition_detail<?php echo $count . '-' . $detailCount; ?> <?php echo $detailCount != 0 ? ' new_object' : '' ?>">
												 <td><?php form::number_field_wid3sr('received_quantity'); ?></td>
												 <td><?php form::number_field_wid3sr('accepted_quantity'); ?></td>
												 <td><?php form::number_field_wid3sr('delivered_quantity'); ?></td>
												 <td><?php form::number_field_wid3sr('invoiced_quantity'); ?></td>
												 <td><?php form::number_field_wid3sr('paid_quantity'); ?></td>
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
							<th>Unit Price</th>
							<th>Line Price</th>
							<th>Line Description</th>
							<th>Ref Doc Type</th>
							<th>Ref Number</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($po_requisition_line_object as $po_requisition_line) {
							?>         
 						 <tr class="po_requisition_line<?php echo $count ?>">
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
							<th>Comments</th>

						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($po_requisition_line_object as $po_requisition_line) {
							?>         
 						 <tr class="po_requisition_line<?php echo $count ?>">
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
