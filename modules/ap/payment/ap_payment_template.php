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

			<div id ="form_header"><span class="heading">Payment Header </span>
			 <form action=""  method="post" id="ap_payment_header"  name="ap_payment_header">
				<div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Finance</a></li>
					<li><a href="#tabsHeader-3">Notes</a></li>
					<li><a href="#tabsHeader-4">Attachments</a></li>
					<li><a href="#tabsHeader-5">Actions</a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column five_column">
						 <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ap_payment_header_id select_popup">
							 Payment Id : </label>
							<?php $f->text_field_d('ap_payment_header_id'); ?>
							<a name="show" href="po.php?ap_payment_header_id=" class="show ap_payment_header_id">
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label>Payment No : </label>
							<?php $f->text_field_d('payment_number'); ?>
						 </li>
						 <li><label>BU Name(1) : </label>
							<?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>
							<a name="show" href="form.php?class_name=ap_payment_header" class="show bu_org_id">
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
							<?php echo $f->select_field_from_object('payment_type', ap_payment_header::payment_types(), 'option_line_code', 'option_line_value', $ap_payment_header->payment_type, 'payment_type', '', 1, $readonly1); ?>
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
						<div id="comments">
						 <div id="comment_list">
							<?php echo!(empty($comments)) ? $comments : ""; ?>
						 </div>
						 <?php
						 $reference_table = 'ap_payment_header';
						 $reference_id = $$class->ap_payment_header_id;
						 include_once HOME_DIR . '/extensions/comment/comment.php';
						 ?>
						 <div id="new_comment">
						 </div>
						</div>
					 </div>
					</div>
					<div id="tabsHeader-4" class="tabContent">
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

					<div id="tabsHeader-5" class="tabContent">
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
								 href="po_print.php?ap_payment_header_id=<?php echo!(empty($$class->ap_payment_header_id)) ? $$class->ap_payment_header_id : ""; ?>" >Transaction</a>
						 </li>
						 <li id="document_status"><label>Change Status : </label>
							<?php echo form::select_field_from_object('approval_status', ap_payment_header::ap_approval_status(), 'option_line_code', 'option_line_value', $ap_payment_header->approval_status, 'set_approval_status', $readonly, '', ''); ?>
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

			<div id="form_line" class="form_line"><span class="heading">Payment Lines</span>
			 <form action=""  method="post" id="po_site"  name="ap_payment_line">
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">Basic</a></li>
					<li><a href="#tabsLine-2">References</a></li>
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
							<th>Transaction Id</th>
							<th>Transaction Number</th>
							<th>Payment Amount</th>
							<th>Total Amount</th>
							<th>Paid Amount</th>
							<th>Remaining Amount</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($ap_payment_line_object as $ap_payment_line) {
							$f->readonly2 = !empty($ap_payment_line->ap_payment_line_id) ? true : false;
							?>         
 						 <tr class="ap_payment_line<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($ap_payment_line->line_number); ?>"></li>           
 								<li><?php echo form::hidden_field('ap_payment_header_id', $ap_payment_header->ap_payment_header_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php form::text_field_wid2sr('ap_payment_line_id'); ?></td>
 							<td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
 							<td><?php $f->text_field_wid2sr('ap_transaction_header_id'); ?></td>
 							<td><?php $f->text_field_wid2('transaction_number', 'select_transaction_number'); ?>
 							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_transaction_number select_popup"></td>
							<td><?php !empty($$class_second->ap_payment_line_id) ? form::number_field_d2sr('amount') : $f->text_field_d2s('amount'); ?></td>
 							<td><?php $f->text_field_wid2('invoice_amount'); ?></td>
							<td><?php $f->text_field_wid2('paid_amount'); ?></td>
 							<td><?php $f->text_field_wid2('remaining_amount'); ?></td>
 						 </tr>
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
							<th>Line Description</th>
							<th>Ref Key Name</th>
							<th>Ref Key Value</th>
							<th>View Ref Doc</th>
							<th>Status</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($ap_payment_line_object as $ap_payment_line) {
							?>         
 						 <tr class="ap_payment_line<?php echo $count ?>">
 							<td><?php $f->text_field_wid2('line_description'); ?></td>
 							<td><?php $f->text_field_d2('reference_key_name'); ?></td>
 							<td><?php $f->text_field_d2('reference_key_value'); ?></td>
 							<td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : '' ?></td>
 							<td><?php $f->text_field_wid2sr('status'); ?></td>
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
						 foreach ($ap_payment_line_object as $ap_payment_line) {
							?>         
 						 <tr class="ap_payment_line<?php echo $count ?>">
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
