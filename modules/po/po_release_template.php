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
				<div class="large_shadow_box"> 
				 <ul class="column five_column">
					<li>
					 <label>Supplier BU Id : </label>
					 <?php echo form::text_field('supplier_bu_id', $supplier_bu->supplier_bu_id, '15', '25', '', 'System Number', 'header_id', 1) ?>
					</li>
					<li>
					 <label>Supplier Id : </label>
					 <?php echo form::text_field('supplier_id', $supplier_bu->supplier_id, '15', '25', '', 'System Number', 'supplier_id', 1) ?>
					</li>
					<li>
					 <label>Org Id : </label>
					 <?php echo form::text_field('org_id', $supplier_bu->org_id, '15', '25', '', 'System Number', 'org_id', 1) ?>
					</li>
					<li>
					 <label>Org : </label>
					 <?php echo form::text_field_d('org'); ?>
					</li>
					<li><label>Supplier Number : </label>
					 <?php echo form::text_field_d('supplier_number'); ?>
					</li>               
					<li><label>Supplier Name : </label>
					 <?php echo form::text_field_d('supplier_name'); ?>
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
						 <?php echo form::text_field_d('org_shipto_id'); ?>
            </li>
						<li><label>Bill To Site Address :
							<img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup"></label>
						 <?php echo form::text_field_d('org_billto_id'); ?>
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
						 <?php echo form::number_field_d('fob'); ?>
            </li> 
						<li><label>Freight Terms : </label> 
						 <?php echo form::number_field_d('freight_terms'); ?>
            </li> 
						<li><label>Transportation : </label> 
						 <?php echo form::number_field_d('transportation'); ?>
            </li> 
						<li><label>Country Of Origin : </label> 
						 <?php echo form::number_field_d('country_of_origin'); ?>
            </li> 
					 </ul>
					</div>
					<div class="second_rowset">
					 <ul class="three_column">
            <li><label>Liability Ac: </label><?php form::account_field('liability_account_id'); ?></li>
            <li><label>Payable Ac: </label><?php form::account_field('payable_account_id'); ?></li>
            <li><label>Payment Discount Ac: </label> <?php form::account_field('payment_discount_account_id'); ?></li>
            <li><label>Pre Payment Ac: </label> <?php form::account_field('pre_payment_account_id'); ?></li>
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
					<div id="show_attachments" class="show_attachment">
					 <input type="button" class="attachment_button button" value="Attachements" id="attachment_button" name="">
					 <?php echo file::attachment_statement($supplier_bu_file); ?>
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
