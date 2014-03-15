<div id="all_contents">
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

			<div id ="form_header"><span class="heading">Transaction Header </span>
			 <form action=""  method="post" id="ap_transaction_header"  name="ap_transaction_header">
				<div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Finance</a></li>
					<li><a href="#tabsHeader-3">Transaction Summary</a></li>
					<li><a href="#tabsHeader-4">Payments</a></li>
					<li><a href="#tabsHeader-5">Notes</a></li>
					<li><a href="#tabsHeader-6">Attachments</a></li>
					<li><a href="#tabsHeader-7">Actions</a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column five_column">
						 <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ap_transaction_header_id select_popup">
							 Transaction Id : </label>
							<?php $f->text_field_d('ap_transaction_header_id'); ?>
							<a name="show" href="po.php?ap_transaction_header_id=" class="show ap_transaction_header_id">
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label>Transaction No : </label>
							<?php $f->text_field_d('transaction_number'); ?>
						 </li>
						 <li><label>BU Name(1) : </label>
							<?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>
							<a name="show" href="form.php?class_name=ap_transaction_header" class="show bu_org_id">
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label>Ledger Name(2) : </label>
							<?php echo form::select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', $readonly1, '', '', 1); ?>
						 </li>
						 <li><label>Currency(3): </label>
							<?php echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->currency, 'currency', $readonly1, '', '', 1); ?>
						 </li>
						 <li><label>Period Name(4) : </label>
							<?php
							if (!empty($period_name_stmt)) {
							 echo $period_name_stmt;
							} else {
							 $f->text_field_d('period_id');
							}
							?>
						 </li>
						 <li><label>Transaction Type(5) : </label>
							<?php echo $f->select_field_from_object('transaction_type', ap_transaction_header::transaction_types(), 'option_line_code', 'option_line_value', $ap_transaction_header->transaction_type, 'transaction_type', '', 1, $readonly1); ?>
						 </li>
						 <li><label>PO Number : </label>                      
							<?php $f->text_field_dr('po_number'); ?>
							<a name="show" href="form.php?class_name=ap_transaction_header" id="show_po_number">
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label>Document Date : </label>
							<?php echo form::date_fieldFromToday('document_date', $$class->document_date) ?>
						 </li>
						 <li><label>Document Number : </label>
							<?php echo $f->text_field_d('document_number') ?>
						 </li>
						 <li><label><input type="button"  class="find_popup supplierId"> Supplier Id(6) : </label>
							<?php echo $f->text_field_dsrm('supplier_id'); ?>
						 </li>
						 <li><label class="auto_complete">Supplier Name(6) : </label><?php echo $supplier_name_stmt; ?></li>
						 <li><label class="auto_complete">Supplier Number(6) : </label><?php echo $supplier_number_stmt; ?></li>
						 <li><label>Supplier Site(7) : </label>
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
							<?php $f->text_field_d('ef_id'); ?>
						 </li>
						 <li><label>Doc Owner : </label>
							<?php $f->text_field_d('document_owner'); ?>
						 </li> 
						 <li><label>Approval Status : </label>                      
							<span class="button"><?php echo!empty($$class->approval_status) ? $$class->approval_status : ""; ?></span>
						 </li>
						 <li><label>Description : </label>
							<?php $f->text_field_d('description'); ?>
						 </li> 
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-2" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label>Currency : </label>
							<?php echo form::select_field_from_object('document_currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->document_currency, 'document_currency', $readonly1, '', '', 1); ?>
						 </li>
						 <li><label>Payment Term : </label>
							<?php
							echo $f->select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'payment_term_id', 1, $readonly1);
//							echo!(empty($po_paymentTerm_statement)) ? $po_paymentTerm_statement : form::text_field_d('payment_term_id'); 
							?>
						 </li>
						 <li><label>Payment Term Date : </label>
							<?php echo form::date_fieldAnyDay('payment_term_date', $$class->payment_term_date) ?>
						 </li>
						 <li><label>Pay Group : </label>
							<?php $f->text_field_d('pay_group') ?>
						 </li>
						 <li><label>Exchange Rate Type : </label>
							<?php $f->text_field_d('exchange_rate_type'); ?>
						 </li>
						 <li><label>Exchange Rate : </label>
							<?php $f->text_field_d('exchange_rate'); ?>
						 </li>
						 <li><label>Header Amount : </label>
							<?php form::number_field_dm('header_amount'); ?>
						 </li>
						 <li><label>Journal Header Id : </label>
							<?php $f->text_field_d('gl_journal_header_id'); ?>
						 </li>
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-3" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label>Payment Status : </label>                      
							<span class="button"><?php echo $f->text_field_d('payment_status'); ?></span>
						 </li>
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-4" class="tabContent">
					 <div> 

					 </div>
					</div>
					<div id="tabsHeader-5" class="tabContent">
					 <div> 
						<div id="comments">
						 <div id="comment_list">
							<?php echo!(empty($comments)) ? $comments : ""; ?>
						 </div>
						 <?php
						 $reference_table = 'ap_transaction_header';
						 $reference_id = $$class->ap_transaction_header_id;
						 include_once HOME_DIR . '/extensions/comment/comment.php';
						 ?>
						 <div id="new_comment">
						 </div>
						</div>
					 </div>
					</div>

					<div id="tabsHeader-6" class="tabContent">
					 <div> 
						<div id="show_attachment" class="show_attachment">
						 <div id="file_upload_form">
							<ul class="inRow asperWidth">
							 <li><input type="file" id="attachments" class="attachments" name="attachments[]" multiple/></li>
							 <li> <input type="button" value="Attach" form="file_upload" name="attach_submit" id="attach_submit" class="submit button"></li>
							 <li class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
							</ul>
						 </div>
						 <div id="uploaded_file_details"></div>
						 <?php echo file::attachment_statement($file); ?>
						</div>
					 </div>
					</div>

					<div id="tabsHeader-7" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label>Action</label>
							<select name="transaction_action[]" class=" select  transaction_action" id="transaction_action" >
							 <option value="" ></option>
							 <option value="CREATE_ACCOUNT" >Create Accounting</option>
							 <option value="MATCH" >Match Transaction</option>
							 <option value="PAID" >Make Payment</option>
							 <option value="VIEW_JOURNAL" >View Journal</option>
							 <option value="CANCEL" >Cancel Transaction</option>
							</select>
						 </li>
						 <li id="document_print"><label>Document Print : </label>
							<a class="button" target="_blank"
								 href="po_print.php?ap_transaction_header_id=<?php echo!(empty($$class->ap_transaction_header_id)) ? $$class->ap_transaction_header_id : ""; ?>" >Transaction</a>
						 </li>
						 <li id="document_status"><label>Change Status : </label>
							<?php echo form::select_field_from_object('approval_status', ap_transaction_header::ap_approval_status(), 'option_line_code', 'option_line_value', $ap_transaction_header->approval_status, 'set_approval_status', $readonly, '', ''); ?>
						 </li>
						 <li id="copy_header"><label>Copy Document : </label>
							<input type="button" class="button" id="copy_docHeader" value="Header">
						 </li>
						 <li id="copy_line"><label></label>
							<input type="button" class="button" id="copy_docLine" value="Lines">
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

			<div id="form_line" class="form_line"><span class="heading">Transaction Lines & Details </span>
			 <form action=""  method="post" id="po_site"  name="ap_transaction_line">
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">Basic</a></li>
					<li><a href="#tabsLine-2">Other Info</a></li>
					<li><a href="#tabsLine-3">References</a></li>
					<li><a href="#tabsLine-4">Notes</a></li>
				 </ul>
				 <div class="tabContainer">
					<div id="tabsLine-1" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>Action</th>
							<th>Line Id</th>
							<th>Line#</th>
							<th>Type</th>
							<th>Item Id</th>
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
						 foreach ($ap_transaction_line_object as $ap_transaction_line) {
							$f->readonly2 = !empty($ap_transaction_line->ap_transaction_line_id) ? true : false;
							?>         
 						 <tr class="ap_transaction_line<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($ap_transaction_line->item_description); ?>"></li>           
 								<li><?php echo form::hidden_field('ap_transaction_header_id', $ap_transaction_header->ap_transaction_header_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php form::text_field_wid2sr('ap_transaction_line_id'); ?></td>
 							<!--<td><?php // form::text_field_wid2s('line_number');                                               ?></td>-->
 							<td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
 							<td><?php echo $f->select_field_from_object('line_type', ap_transaction_line::ap_transaction_line_types(), 'option_line_code', 'option_line_value', $$class_second->line_type, '', 'line_type', '', $readonly); ?></td>
 							<td><?php $f->text_field_wid2sr('item_id'); ?></td>
 							<td><?php $f->text_field_wid2('item_number', 'select_item_number'); ?>
 							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></td>
 							<td><?php $f->text_field_wid2('item_description'); ?></td>
 							<td><?php
								echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom', $$class_second->uom_id, '', '', '', $readonly1);
								?></td>
 							<td><?php form::number_field_wid2s('inv_line_quantity'); ?></td>
 							<td class="add_detail_values"><img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
 							 <!--</td></tr>-->	
								<?php
								$ap_transaction_line_id = $ap_transaction_line->ap_transaction_line_id;
								if (!empty($ap_transaction_line_id)) {
								 $ap_transaction_detail_object = ap_transaction_detail::find_by_ap_transaction_lineId($ap_transaction_line_id);
								} else {
								 $ap_transaction_detail_object = array();
								}
								if (count($ap_transaction_detail_object) == 0) {
								 $ap_transaction_detail = new ap_transaction_detail();
								 $ap_transaction_detail_object = array();
								 array_push($ap_transaction_detail_object, $ap_transaction_detail);
								}
								?>
                                      <!--						 <tr><td>-->
 							 <div class="class_detail_form">
 								<fieldset class="form_detail_data_fs"><legend>Detail Data</legend>
 								 <div class="tabsDetail">
 									<ul class="tabMain">
 									 <li class="tabLink"><a href="#tabsDetail-1-1">Basic</a></li>
 									 <li class="tabLink"><a href="#tabsDetail-2-1">References</a></li>
 									</ul>
 									<div class="tabContainer">
 									 <div id="tabsDetail-1-1" class="tabContent">
 										<table class="form form_detail_data_table detail">
 										 <thead>
 											<tr>
 											 <th>Action</th>
 											 <th>Detail Id</th>
 											 <th>Detail# </th>
 											 <th>Type</th>
 											 <th>Account</th>
 											 <th>Period</th>
 											 <th>Amount</th>
 											 <th>Description</th>
 											</tr>
 										 </thead>
 										 <tbody class="form_data_detail_tbody">
											 <?php
											 $detailCount = 0;
											 foreach ($ap_transaction_detail_object as $ap_transaction_detail) {
												$class_third = 'ap_transaction_detail';
												$$class_third = &$ap_transaction_detail;
//												pa($ap_transaction_detail);
												?>
												<tr class="ap_transaction_detail<?php echo $count . '-' . $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
												 <td>   
													<ul class="inline_action">
													 <li class="add_row_detail_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
													 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
													 <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($ap_transaction_detail->ap_transaction_detail_id); ?>"></li>           
													 <li><?php echo form::hidden_field('ap_transaction_line_id', $ap_transaction_line->ap_transaction_line_id); ?></li>
													 <li><?php echo form::hidden_field('ap_transaction_header_id', $ap_transaction_header->ap_transaction_header_id); ?></li>

													</ul>
												 </td>
												 <td><?php $f->text_field_wid3sr('ap_transaction_detail_id'); ?></td>
												 <td><?php $f->text_field_wid3s('detail_number'); ?></td>
												 <td><?php echo form::select_field_from_object('account_type', gl_journal_line::gl_journal_line_types(), 'option_line_code', 'option_line_value', $$class_third->account_type, 'account_type', $readonly); ?></td>
												 <td><?php $f->ac_field_d3m('detail_ac_id'); ?></td>
												 <td><?php $f->text_field_wid3s('period_id') ?></td>
												 <td><?php $f->text_field_wid3s('amount'); ?></td>
												 <td><?php $f->text_field_wid3('description'); ?></td>
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
 											 <th>Ref Key Name</th>
 											 <th>Ref Key Value</th>
 											 <th>View Ref Doc</th>
 											</tr>
 										 </thead>
 										 <tbody class="form_data_detail_tbody">
											 <?php
											 $detailCount = 0;
											 foreach ($ap_transaction_detail_object as $ap_transaction_detail) {
												$class_third = 'ap_transaction_detail';
												$$class_third = &$ap_transaction_detail;
												?>
												<tr class="ap_transaction_detail<?php echo $count . '-' . $detailCount; ?> <?php echo $detailCount != 0 ? ' new_object' : '' ?>">
												 <td><?php $f->text_field_d3('reference_key_name'); ?></td>
												 <td><?php $f->text_field_d3('reference_key_value'); ?></td>
												 <td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : '' ?></td>
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
							<th>Ref Key Name</th>
							<th>Ref Key Value</th>
							<th>View Ref Doc</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($ap_transaction_line_object as $ap_transaction_line) {
							?>         
 						 <tr class="ap_transaction_line<?php echo $count ?>">
 							<td><?php form::number_field_wid2('inv_unit_price'); ?></td>
 							<td><?php form::number_field_wid2('inv_line_price'); ?></td>
 							<td><?php $f->text_field_wid2('line_description'); ?></td>
 							<td><?php $f->text_field_d2('reference_key_name'); ?></td>
 							<td><?php $f->text_field_d2('reference_key_value'); ?></td>
 							<td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : '' ?></td>
 						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
						<!--                  Showing a blank form for new entry-->
					 </table>
					</div>
					<div id="tabsLine-3" class="scrollElement tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>PO Header Id</th>
							<th>PO Line Id</th>
							<th>PO Detail Id</th>
							<th>Is Asset</th>
							<th>Asset Category</th>
							<th>Project Header Id</th>
							<th>Project Line Id</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
							 foreach ($ap_transaction_line_object as $ap_transaction_line) {
							?>         
 						 <tr class="ap_transaction_line<?php echo $count ?>">
 							<td><?php $f->text_field_wid2sr('po_header_id'); ?></td>
 							<td><?php $f->text_field_wid2sr('po_line_id'); ?></td>
 							<td><?php $f->text_field_wid2sr('po_detail_id'); ?></td>
							<td><?php form::checkBox_field('asset_cb',$$class_second->asset_cb); ?></td>
 							<td><?php $f->text_field_wid2sr('fa_asset_category_id'); ?></td>
 							<td><?php $f->text_field_wid2sr('prj_project_header_id'); ?></td>
 							<td><?php $f->text_field_wid2sr('prj_project_line_id'); ?></td>
 						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
						<!--                  Showing a blank form for new entry-->
					 </table>
					</div>
					<div id="tabsLine-4" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>Comments</th>

						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($ap_transaction_line_object as $ap_transaction_line) {
							?>         
 						 <tr class="ap_transaction_line<?php echo $count ?>">
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
	<!--<div id="content_right_right"></div>-->
 </div>

</div>

<?php include_template('footer.inc') ?>
