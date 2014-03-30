<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="customer_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<form action=""  method="post" id="customer_bu"  name="customer_bu">
			 <div id ="form_header">
				<div class="large_shadow_box"> 
				 <ul class="column five_column">
					<li>
					 <label><img class="select header_id_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png"/ >
											 Customer BU Id : </label>
						<?php form::number_field_drs('ar_customer_bu_id') ?>
					 <a name="show" href="?ar_customer_bu_id=" class="show ar_customer_bu_id">
						<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li>
					<li>
					 <label>Customer Id : </label>
					 <span class="button"><a href="form.php?class_name=ar_customer&mode=<?php echo $mode; ?>&ar_customer_id=
																	 <?php echo $$class->ar_customer_id; ?>"><?php echo $$class->ar_customer_id; ?></a></span>
					</li>
					<?php echo form::hidden_field('ar_customer_id', $$class->ar_customer_id); ?>
					<li>
					 <label>Org Id : </label>
					 <?php form::number_field_drsm('org_id') ?>
					</li>
					<li>
					 <label>Org : </label>
					 <?php echo form::text_field_dr('org'); ?>
					</li>
					<li><label>Customer Number : </label>
					 <?php form::number_field_drs('customer_number'); ?>
					</li>               
					<li><label>Customer Name : </label>
					 <?php echo form::text_field_dr('customer_name'); ?>
					</li>
					<li><label>Ef Id : </label>
					 <?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
					</li>
					<li><label>Status : </label>                      
					 <?php echo form::status_field($$class->status, $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?>
					</li> 
					<li><label>Rev Number : </label>
					 <?php form::text_field_wid('rev_number'); ?>
					</li> 
				 </ul>
				</div>

			 </div>
			 <div id ="form_line" class="form_line"><span class="heading"> Customer BU Details </span>
				<div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Accounts</a></li>
					<li><a href="#tabsLine-2">Finance</a></li>
          <li><a href="#tabsLine-3">Profile</a></li>
					<li><a href="#tabsLine-4">Sales</a></li>
          <li><a href="#tabsLine-5">Address</a></li>
          <li><a href="#tabsLine-6">Attachments</a></li>
          <li><a href="#tabsLine-7">Contact</a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsLine-1" class="tabContent">
					 <ul class="column four_column"> 
						<li><label>Receivable Ac: </label><?php form::ac_field_d('receivable_ac_id'); ?></li>
						<li><label>Revenue Ac: </label><?php form::ac_field_d('revenue_ac_id'); ?></li>
						<li><label>Tax Ac: </label> <?php form::ac_field_d('tax_ac_id'); ?></li>
						<li><label>Freight Ac: </label> <?php form::ac_field_d('freight_ac_id'); ?></li>
						<li><label>Clearing Ac: </label> <?php form::ac_field_d('clearing_ac_id'); ?></li>
						<li><label>Unbilled Receivable Ac: </label> <?php form::ac_field_d('unbilled_receivable_ac_id'); ?></li>
						<li><label>Unearned Revenue Ac: </label> <?php form::ac_field_d('unearned_revenue_ac_id'); ?></li>
						<!--end of tab1 div three_column-->
					</div> 
					<div id="tabsLine-2" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label>Currency : </label>
							<?php echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', $readonly, '', ''); ?>
						 </li>
						 <li><label>Payment Term : </label>
							<?php echo form::select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id', $readonly, '', ''); ?>
						 </li>
						 <li><label>Finance Profile : </label> 
							<?php echo form::text_field_d('finance_profile_id'); ?>
						 </li> 
						 <li><label>Payment Method : </label> 
							<?php echo form::text_field_d('payment_method_id'); ?>
						 </li> 
						 <li><label>Bank  : </label> 
							<?php echo form::text_field_d('bank_id'); ?>
						 </li> 
						 <li><label>Bank Account : </label> 
							<?php echo form::text_field_d('bank_account_id'); ?>
						 </li> 
						</ul>
					 </div>
					</div> 
					<!--end of tab1-->
					<div id="tabsLine-3" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column">
						 <li><label>Profile : </label> 
							<?php echo form::text_field_d('profile_id'); ?>
						 </li> 
						</ul>
					 </div>
					</div>


					<div id="tabsLine-4" class="tabContent">
					 <ul class="column five_column"> 
						<li><label>Order Type : </label>
						 <?php
						 // echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', $readonly, '', ''); 
						 echo form::text_field_d('order_type_id');
						 ?>
						</li>
						<li><label>Price List : </label>
						 <?php
						 // echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', $readonly, '', ''); 
						 echo form::text_field_d('price_list_id');
						 ?>
						</li>
						<li><label>Internal Organization : </label>
						 <?php
						 // echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', $readonly, '', ''); 
						 echo form::text_field_d('internal_org_id');
						 ?>
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
					<!--end of tab5 (Manufacturing)!! start of planning -->
					<div id="tabsLine-5" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label>Site Address Id : 
							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup"></label>
							<?php echo form::text_field_d('site_address_id'); ?>
						 </li>
						</ul>
						<div class="site address_details">
						 <?php echo!empty($site_address_id) ? $site_address_id : ""; ?>
						</div>  
					 </div>
					</div>	
					<div id="tabsLine-6" class="tabContent">
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
					<!--end of tab4(purchasing)!!! start of MFG tab-->
					<div id="tabsLine-7" class="tabContent">

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
