<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="main">
		 <div id="structure">
			<div id="contents">
			 <div id="receipt_pageId">
				<div id ="form_header">
				 <div class="error"></div><div id="loading"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>
				 <div class="show_loading_small"></div>
				 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
				</div>
				<div id="list_contents">
				 <div id="searchForm"><?php echo!(empty($search_form)) ? $search_form : ""; ?></div>
				 <?php
				 if (!empty($total_count)) {
					echo '<h3>Total records : ' . $total_count . '</h3>';
				 }
				 ?>
				 <div id="scrollElement">
					<div id="print">
					 <div id="search_result"> 
						<div id ="form_header">
						 <form action=""  method="post" id="receipt_header_form"  name="receipt_header_form">
							<!--create empty form or a single id when search is not clicked and the id is referred from other page -->
							<span class="heading">Receipt Transaction </span> 
							<table class="form_table">
							 <tr>
								<td><label>Inventory </label>
								 <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>
								</td>
								<td><label>Transaction Type </label>
								 <?php echo form::select_field_from_object('transaction_type_id', transaction_type::find_by_transactionClass('PO'), 'transaction_type_id', 'transaction_type', $$class->transaction_type_id, 'transaction_type_id', $readonly); ?>
								</td>
								<td><label>Receipt Id </label>
								 <?php echo form::text_field_d('receipt_header_id'); ?>
								</td>
								<td><label>Number </label>
								 <?php echo form::text_field_d('receipt_number'); ?>
								</td>
								<td><label>Date </label>
								<td><?php echo form::date_fieldFromToday('receipt_date', ino_date($$class->receipt_date)); ?></td>
							 </tr>
							</table>
						 </form>
						</div>
						<div id="form_line" class="form_line"><span class="heading">Receipt Lines </span>
						 <form action=""  method="post" id="receipt_line_form"  name="receipt_line_form">
							<div id="tabs">
							 <ul class="tabMain">
								<li><a href="#tabsLine-1">PO Info</a></li>
								<li><a href="#tabsLine-2">Receipt</a></li>
								<li><a href="#tabsLine-3">Supplier</a></li>
								<li><a href="#tabsLine-4">Finance</a></li>
								<li><a href="#tabsLine-5">Reference </a></li>
							 </ul>
							 <div class="tabContainer"> 
								<div id="tabsLine-1" class="tabContent">
								 <table class="form_line_data_table">
									<thead> 
									 <tr>
										<th>Action</th>
										<th>Receipt Line Id</th>
										<th>PO #</th>
										<th>Header Id</th>
										<th>Line #</th>
										<th>Line Id</th>
										<th>Shipment #</th>
										<th>Detail Id</th>
									 </tr>
									</thead>
									<tbody class="form_data_line_tbody">
									 <?php
									 $count = 0;
									 foreach ($receipt_line_object as $receipt_line) {
										$class_second = 'receipt_line';
										$$class_second = &$receipt_line;
										pa($$class_second);
										?> 
 									 <tr class="receipt_row<?php echo $count ?>">
 										<td>    
 										 <ul class="inline_action">
 											<li class="add_row_img"><input type="button"  class="add_new_line"></li>
 											<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 											<li><input type="checkbox" class="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->receipt_line_id); ?>">
 											<?php echo form::hidden_field('org_id', $$class->org_id); ?>
											<?php echo form::hidden_field('transaction_type_id', $$class->transaction_type_id); ?></li>
 										 </ul>
 										</td>
 										<td>
											<?php echo form::text_field_d2('receipt_line_id', $$class_second->receipt_line_id, '7', '20', '', 'sys no', '', 1); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2sr('po_number'); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2sr('po_header_id'); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2sr('line_number'); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2sr('po_line_id'); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2sr('shipment_number'); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2sr('po_detail_id'); ?>
 										</td>

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
										<th>Item id</th>
										<th>Item Number</th>
										<th>Item Description</th>
										<th>UOM</th>
										<th>Shipment Qty</th>
										<th>PO Received Qty</th>
										<th>New Received Qty</th>
										<th>Sub inventory</th>
										<th>Locator</th>
									 </tr>
									</thead>
									<tbody class="form_data_line_tbody">
									 <?php
									 $count = 0;
									 foreach ($receipt_line_object as $po_line) {
//										echo '<pre>';
//										print_r($po_line);
										?> 
 									 <tr class="receipt_row<?php echo $count ?>">
 										<td>
											<?php form::text_field_wid2sr('item_id'); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2('item_number'); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2('item_description'); ?>
 										</td>
 										<td>
											<?php echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $po_line->uom_id, 'uom_id'); ?>
											<?php // 	form::number_field_wid2sr('uom_id'); ?>
 										</td>
 										<td>
											<?php form::number_field_wid2sr('received_quantity'); ?>
 										</td>
 										<td>
											<?php
											echo form::number_field('po_received_quantity', $po_line->po_received_quantity, '8', '', '', '', '', '', 1);
											// echo $po_line->po_received_quantity;
//											form::number_field_wid2sr('po_received_quantity');
											?>
 										</td>
 										<td>
											<?php form::number_field_wid2s('received_quantity'); ?>
 										</td>
 										<td>
											<?php echo form::select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->subinventory_id, 'subinventory_id', $readonly); ?>
 										</td>
 										<td>
											<?php echo form::select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_second->subinventory_id), 'locator_id', 'locator', $$class_second->locator_id, 'locator_id', $readonly); ?>
 										</td>
 									 </tr>
										<?php
										$count = $count + 1;
									 }
									 ?>
									</tbody>
								 </table>
								</div>
								<div id="tabsLine-3" class="tabContent">
								 <table class="form_line_data_table">
									<thead> 
									 <tr>
										<th>Supplier Id</th>
										<th>Supplier #</th>
										<th>Supplier</th>
										<th>Site Id</th>
										<th>Site #</th>
										<th>Site </th>
									 </tr>
									</thead>
									<tbody class="form_data_line_tbody">
									 <?php
									 $count = 0;
									 foreach ($receipt_line_object as $po_line) {
										?> 
 									 <tr class="receipt_row<?php echo $count ?>">

 										<td>
											<?php form::text_field_wid2('supplier_id'); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2('supplier_number'); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2('supplier_name'); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2('supplier_site_id'); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2('supplier_site_number'); ?>
 										</td>
 										<td>
											<?php form::text_field_wid2('supplier_site_name'); ?>
 										</td>
 									 </tr>
										<?php
										$count = $count + 1;
									 }
									 ?>
									</tbody>
								 </table>
								</div>
								<div id="tabsLine-4" class="form_data_line_tbody">

								</div>
								<div id="tabsLine-5" class="form_data_line_tbody">

								</div>
							 </div>

							</div>

							<!--                 complete Showing a blank form for new entry-->
						 </form>

						</div>
					 </div>
					</div>
				 </div>
				 <div id="pagination" style="clear: both;">
					<?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
					?>
				 </div>
				</div>
			 </div>
			</div>
			<div>
			</div>
		 </div>
		 <div id="content_bottom"></div>
		</div>
		<div id="content_right_right"></div>
	 </div>
	</div>
 </div>
</div>
<?php include_template('footer.inc') ?>
