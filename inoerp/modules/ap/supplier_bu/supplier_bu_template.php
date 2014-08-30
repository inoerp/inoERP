<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="supplier_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<form action=""  method="post" id="supplier_bu"  name="supplier_bu">
			 <div id ="form_header">
				<div class="tabContainer no_tab"> 
				 <ul class="column five_column">
					<li>
					 <label><img class="select header_id_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png"/ >
						Supplier BU Id : </label>
					 <?php form::number_field_drs('supplier_bu_id') ?>
					 <a name="show" href="?supplier_bu_id=" class="show supplier_bu_id">
						<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li>
					<li>
					 <label>Supplier Id : </label>
					 <span class="button"><a href="form.php?class_name=supplier&mode=<?php echo $mode ?>&supplier_id=
																	 <?php echo $$class->supplier_id; ?>"><?php echo $$class->supplier_id; ?></a></span>
						<?php echo form::hidden_field('supplier_id', $$class->supplier_id); ?>
					</li>
					<li>
					 <label>Org Id : </label>
					 <?php form::number_field_drsm('org_id') ?>
					</li>
					<li>
					 <label>Org : </label>
					 <?php echo form::text_field_dr('org'); ?>
					</li>
					<li><label>Supplier Number : </label>
					 <?php form::number_field_drs('supplier_number'); ?>
					</li>               
					<li><label>Supplier Name : </label>
					 <?php echo form::text_field_dr('supplier_name'); ?>
					</li>
					<li><label>Ef Id : </label>
					 <?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
					</li>
					<li><label>Status : </label>                      
					 <?php echo form::status_field($$class->status, $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::checkBox_field('rev_enabled_cb', $supplier_bu->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?>
					</li> 
					<li><label>Rev Number : </label>
					 <?php form::text_field_wid('rev_number'); ?>
					</li> 
				 </ul>
				</div>

			 </div>
			 <div id ="form_line" class="form_line"><span class="heading"> Supplier BU Details </span>
				<div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Main</a></li>
          <li><a href="#tabsLine-2">Local Addresses</a></li>
          <li><a href="#tabsLine-3">Purchasing</a></li>
          <li><a href="#tabsLine-4">Invoice & Payment</a></li>
					<li><a href="#tabsLine-5">Attachments</a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsLine-1" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Hold New POs : </label> 
							<?php echo form::checkBox_field('new_pos_cb', $$class->new_pos_cb, 'new_pos_cb', $readonly); ?>
						 </li> 
						 <li><label>Hold All Invoices : </label> 
							<?php echo form::checkBox_field('all_invoices_cb', $$class->all_invoices_cb, 'all_invoices_cb', $readonly); ?>
						 </li> 
						 <li><label>Unmatched Invoices : </label> 
							<?php echo form::checkBox_field('unmatched_invoices_cb', $$class->unmatched_invoices_cb, 'unmatched_invoices_cb', $readonly); ?>
						 </li> 
						 <li><label>Unaccounted Invoices : </label> 
							<?php echo form::checkBox_field('unaccounted_invoices_cb', $$class->unaccounted_invoices_cb, 'unaccounted_invoices_cb', $readonly); ?>
						 </li> 
						 <li><label>Unpaid Invoices : </label> 
							<?php echo form::checkBox_field('unpaid_invoices_cb', $$class->unpaid_invoices_cb, 'unpaid_invoices_cb', $readonly); ?>
						 </li> 
						 <li><label>Hold Reason : </label> 
							<?php echo form::text_field_d('hold_reason'); ?>
						 </li> 
						 <li><label>PO Amount Limit : </label> 
							<?php echo form::number_field_d('po_amount_limit'); ?>
						 </li> 
						 <li><label>Invoice Amount Limit : </label> 
							<?php echo form::number_field_d('invoice_amount_limit'); ?>
						 </li> 
						 <li><label>Payment Amount : </label> 
							<?php echo form::number_field_d('payment_amount_limit'); ?>
						 </li> 
						</ul>
					 </div>
					 <div class="second_rowset">

					 </div>
					 <!--end of tab1 div three_column-->
					</div> 
					<div id="tabsLine-2" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label>Ship To Site Address : 
							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup"></label>
							<?php echo form::text_field_dm('org_shipto_id'); ?>
						 </li>
						 <li><label>Bill To Site Address :
							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup"></label>
							<?php echo form::text_field_dm('org_billto_id'); ?>
						 </li>
						</ul>
						<div class="shipto address_details">
						 <?php echo!empty($org_shipto_id) ? $org_shipto_id : ""; ?>
						</div> 
						<div class="billto address_details">
						 <?php echo!empty($org_billto_id) ? $org_billto_id : ""; ?>
						</div> 
					 </div>
					</div> 
					<!--end of tab1-->
					<div id="tabsLine-3" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column">
						 <li><label>Debit Memo onReturn : </label> 
							<?php echo form::checkBox_field('debit_memo_onreturn_cb', $$class->debit_memo_onreturn_cb, 'debit_memo_onreturn_cb', $readonly); ?>
						 </li> 
						 <li><label>Pay On : </label> 
							<?php echo form::text_field_d('pay_on'); ?>
						 </li> 
						 <li><label>FOB : </label> 
							<?php echo form::text_field_d('fob'); ?>
						 </li> 
						 <li><label>Freight Terms : </label> 
							<?php echo form::text_field_d('freight_terms'); ?>
						 </li> 
						 <li><label>Transportation : </label> 
							<?php echo form::text_field_d('transportation'); ?>
						 </li> 
						 <li><label>Country Of Origin : </label> 
							<?php echo form::text_field_d('country_of_origin'); ?>
						 </li> 
						</ul>
					 </div>
					 <div class="second_rowset">
						<ul class="three_column">
						 <li><label>Liability Ac: </label><?php form::ac_field_dm('liability_account_id'); ?></li>
						 <li><label>Payable Ac: </label><?php form::ac_field_dm('payable_account_id'); ?></li>
						 <li><label>Payment Discount Ac: </label> <?php form::ac_field_d('payment_discount_account_id'); ?></li>
						 <li><label>Pre Payment Ac: </label> <?php form::ac_field_d('pre_payment_account_id'); ?></li>
						</ul>
					 </div> 

					 <!--                end of tab2 div three_column-->
					</div>
					<!--end of tab3 (purchasing)!!!! start of sales tab-->

					<div id="tabsLine-4" class="tabContent">
					 <ul class="column five_column">
						<li><label>BU Bank : </label> 
						 <?php echo form::text_field_d('bu_bank_id'); ?>
						</li> 
						<li><label>BU Bank Site : </label> 
						 <?php echo form::number_field_d('bu_bank_site_id'); ?>
						</li> 
						<li><label>Tax Code : </label> 
						 <?php echo form::number_field_d('bu_tax_code'); ?>
						</li> 
						<li><label>Invoice Match Doc : </label> 
						 <?php echo form::number_field_d('invoice_match_document'); ?>
						</li> 
						<li><label>Invoice Currency : </label> 
						 <?php echo form::number_field_d('invoice_currency'); ?>
						</li>
						<li><label>Payment Priority : </label> 
						 <?php echo form::text_field_d('payment_priority'); ?>
						</li> 
						<li><label>Payment Group : </label> 
						 <?php echo form::number_field_d('payment_group'); ?>
						</li> 
						<li><label>Payment Terms : </label> 
						 <?php echo form::number_field_d('payment_terms'); ?>
						</li> 
						<li><label>Invoice Date Basis : </label> 
						 <?php echo form::number_field_d('invoice_date_basis'); ?>
						</li> 
						<li><label>Payment Date Basis: </label> 
						 <?php echo form::number_field_d('pay_date_basis'); ?>
						</li> 
						<li><label>Default Payment Method : </label> 
						 <?php echo form::number_field_d('default_payment_method'); ?>
						</li> 
						<li><label>Remittance Advice Method : </label> 
						 <?php echo form::number_field_d('remittance_advice_method'); ?>
						</li> 
						<li><label>Remittance Advice Email : </label> 
						 <?php echo form::number_field_d('remittance_advice_email'); ?>
						</li> 
					 </ul>
					</div>
					<!--end of tab5 (Manufacturing)!! start of planning -->
					<div id="tabsLine-5" class="tabContent">
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
