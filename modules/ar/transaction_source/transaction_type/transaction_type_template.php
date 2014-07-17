<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="ar_transaction_type_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="ar_transaction_type_form"  name="ar_transaction_type_form"><span class="heading">Transaction Type </span>
				<div class="large_shadow_box tabContainer">
				 <ul class="column four_column"> 
					<li> 
					 <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ar_transaction_type_id select_popup clickable">
						Transaction Type Id : </label><?php $f->text_field_ds('ar_transaction_type_id') ?>
					 <a name="show" href="form.php?class_name=ar_transaction_type" class="show ar_transaction_type_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li>
					<li><label>BU Name : </label>
					 <?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>
					 </li>
					<li><label>Ledger Name : </label>
					 <?php echo form::select_field_from_object('legal_org_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->legal_org_id, 'legal_org_id', $readonly1, '', '', 1); ?>
					</li>
										<li><label>Transaction Class : </label>
					 <?php echo $f->select_field_from_object('transaction_class', ar_transaction_header::transaction_class(), 'option_line_code', 'option_line_value', $$class->transaction_class, 'transaction_class', '', 1, $readonly1); ?>
					</li>
					<li><label>Transaction Type :</label><?php form::text_field_wid('ar_transaction_type'); ?></li>
					<li><label>Description :</label><?php $f->text_field_wid('description'); ?> 					</li>
           <li><label>Status : </label><?php echo form::status_field($$class->status, $readonly); ?></li>
				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Transaction Type Details </span>
				 <div id="tabsLine">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Basic Info</a></li>
					 <li><a href="#tabsLine-2">Finance</a></li>
					</ul>
					<div class="tabContainer"> 
					 <div id="tabsLine-1" class="tabContent">
						<div> 
						 <ul class="column four_column"> 
							<li><label>Invoice Type :</label>
							 <?php  echo $f->select_field_from_object('invoice_type_id', ar_transaction_type::find_all(), 'ar_transaction_type_id', 'ar_transaction_type', $$class->invoice_type_id ,'invoice_type_id'); ?>
							</li>
							<li><label>Credit Memo :</label>
							 <?php echo $f->select_field_from_object('cm_type_id', ar_transaction_type::find_all(), 'ar_transaction_type_id', 'ar_transaction_type', $$class->cm_type_id ,'cm_type_id'); ?>
							</li>
							<li><label>Payment Term :</label>
							 <?php echo $f->select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'payment_term_id', 1, $readonly1); ?>
							</li>
							
						 </ul> 
						</div> 
					 </div> 
					 <div id="tabsLine-2"  class="tabContent">
						<div> 
						 <ul class="column three_column"> 
							<li><label> Receivable :</label> <?php $f->ac_field_dm('receivable_ac_id'); ?></li>
							<li><label> Revenue :</label> <?php $f->ac_field_d('revenue_ac_id'); ?></li>
							<li><label> Tax :</label> <?php $f->ac_field_d('tax_ac_id'); ?></li>
							<li><label> Freight :</label> <?php $f->ac_field_d('freight_ac_id'); ?></li>
							<li><label> Clearing :</label> <?php $f->ac_field_d('clearing_ac_id'); ?></li>
							<li><label> Un-Billed Receivable :</label> <?php $f->ac_field_d('unbilled_receivable_ac_id'); ?></li>
							<li><label> Un-Earned Revenue :</label> <?php $f->ac_field_d('unearned_revenue_ac_id'); ?></li>
						 </ul> 
						</div> 
					 </div>
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