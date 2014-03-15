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

			<div id ="form_header">
			 <form action=""  method="post" id="customer"  name="customer">
				<div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">BU Assignment</a></li>
					<li><a href="#tabsHeader-3">Profile</a></li>
					<li><a href="#tabsHeader-4">Address Details</a></li>
					<li><a href="#tabsHeader-5">Attachments</a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column five_column">
						 <li>
							<label><img class="ar_customer_id_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
							 Customer Id : </label>
							<?php form::number_field_drs('ar_customer_id'); ?>
							<a name="show" href="?ar_customer_id=" class="show ar_customer_id">
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label>Customer Number : </label>
							<?php form::number_field_dm('customer_number'); ?>
							<a name="show" href="customer.php?customer_number=" class="show customer_number">
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>               
						 <li><label>Customer Name : </label>
							<?php echo form::text_field_dm('customer_name'); ?>
							<a name="show" href="customer.php?customer_name=" class="show customer_name">
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 

						 </li>
						 <li><label>Customer Type : </label>
							<?php echo form::select_field_from_object('customer_type', ar_customer::customer_types(), 'option_line_code', 'option_line_value', $$class->customer_type, 'customer_type', $readonly, '', ''); ?>
						 </li>
						 <li><label>Supplier Id : </label>
							<?php form::number_field_ds('supplier_id'); ?>
						 </li>
						 <li><label>Tax Country : </label>
							<?php echo form::select_field_from_object('tax_country', option_header::COUNTRIES(), 'option_line_code', 'option_line_value', $$class->tax_country, 'tax_country', $readonly, '', ''); ?>
						 </li>
						 <li><label>Tax Reg No : </label>
							<?php echo form::text_field_d('tax_reg_no'); ?>
						 </li>
						 <li><label>Tax Payer Id : </label>
							<?php echo form::text_field_d('tax_payer_id'); ?>
						 </li>
						 <li><label>Contact Id : </label>
							<?php echo form::text_field_d('customer_contact_id'); ?>
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
					<div id="tabsHeader-2" class="tabContent">
					 <div class="three_column right_border"> 
						<?php echo!(empty($assigned_bu_statement)) ? $assigned_bu_statement : ""; ?>
					 </div>
					</div>
					<div id="tabsHeader-3" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label>Customer Profile : </label>
							<?php echo form::text_field_dm('customer_name'); ?>
						 </li>
						 <li><label>Credit Class : </label>
							<?php echo form::select_field_from_object('customer_credit_class', ar_customer::customer_credit_class(), 'option_line_code', 'option_line_value', $$class->customer_credit_class, 'customer_credit_class', $readonly, '', ''); ?>
						 </li>
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-4" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label>Corporate Address Id : 
							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup"></label>
							<?php form::number_field_drsm('address_id'); ?>
						 </li>
						</ul>
						<div class="address_details">
						 <?php echo!empty($address_id) ? $address_id : ""; ?>
						</div>  
					 </div>
					</div>
					<div id="tabsHeader-5" class="tabContent">
					 <div> 
						<div id="show_attachment" class="show_attachment">
						 <input type="button" class="attachment_button button" value="Attachements" id="attachment_button" name="">
						 <?php echo file::attachment_statement($customer_file); ?>
						</div>
					 </div>
					</div>
				 </div>

        </div>
			 </form>
			</div>
			<div id ="form_line" class="form_line"><span class="heading"> Customer Site Details </span>
			 <form action=""  method="post" id="customer_site"  name="customer_site">
				<div class="line_before_tab"> 
				 <ul class="column five_column inline_list"> 
					<li><label>Site Id : </label> 
					 <?php // echo form::text_field('ar_customer_site_id', $$class_second->ar_customer_site_id, '15', '25', '', 'System Number', 'ar_customer_site_id', $readonly) ?>
					 <?php echo form::select_field_from_array('ar_customer_site_id', ar_customer_site::find_all_sitesOfCustomer_array($$class->ar_customer_id), $$class_second->ar_customer_site_id, 'ar_customer_site_id', $readonly); ?>
					 <a name="show" href="?ar_customer_id=&ar_customer_site_id=" class="show ar_customer_site_id">
						<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li> 
					<li class="hidden"><?php echo form::hidden_field('ar_customer_id', $$class->ar_customer_id); ?></li>
					<li><label>Site Name : </label>
					 <?php // echo form::select_field_from_object('customer_site_name', customer_site::find_all_sitesOfCustomer($$class->ar_customer_id), 'customer_site_name', 'customer_site_name', $$class_second->customer_site_name, 'customer_site_name', $readonly, '', 1); ?>
					 <?php echo form::text_field_d2m('customer_site_name'); ?>
					</li>
					<li><label>Site Number : </label>
					 <?php form::number_field_d2m('customer_site_number'); ?>
					</li>
				 </ul>
				</div>
				<div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Main</a></li>
					<li><a href="#tabsLine-2">Finance</a></li>
          <li><a href="#tabsLine-3">Profile</a></li>
					<li><a href="#tabsLine-4">Sales</a></li>
          <li><a href="#tabsLine-5">Address</a></li>
          <li><a href="#tabsLine-6">Attachments</a></li>
          <li><a href="#tabsLine-7">Contact</a></li>
				 </ul>
				 <div class="tabContainer">
					<div id="tabsLine-1" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Customer Site Type : </label>
							<?php echo form::select_field_from_object('customer_site_type', ar_customer_site::customer_site_types(), 'option_line_code', 'option_line_value', $$class_second->customer_site_type, 'customer_site_type', $readonly, '', ''); ?>
						 </li>
						 <li><label>Site Reference : </label>
							<?php echo form::text_field_d2('customer_site_ref'); ?>
						 </li>
						 <li><label>Tax Country : </label>
							<?php echo form::select_field_from_object('site_tax_country', option_header::COUNTRIES(), 'option_line_code', 'option_line_code', $$class_second->site_tax_country, 'tax_country', $readonly, '', ''); ?>
						 </li>
						 <li><label>Tax Reg No : </label>
							<?php echo form::text_field_d2('site_tax_reg_no'); ?>
						 </li>
						 <li><label>Tax Payer Id : </label>
							<?php echo form::text_field_d2('site_tax_payer_id'); ?>
						 </li>
						 <li><label>Tax code : </label>
							<?php echo form::text_field_d2('site_tax_code'); ?>
						 </li>
						</ul>
					 </div>
					 <div class="second_rowset">

					 </div>
					 <!--end of tab1 div three_column-->
					</div> 
					<!--end of tab1-->
					<div id="tabsLine-2" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Currency : </label>
							<?php echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class_second->currency, 'currency', $readonly, '', ''); ?>
						 </li>
						 <li><label>Payment Term : </label>
							<?php echo form::select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class_second->payment_term_id, 'payment_term_id', $readonly, '', ''); ?>
						 </li>
						 <li><label>Payment Method : </label> 
							<?php echo form::text_field_d2('payment_method_id'); ?>
						 </li> 
						 <li><label>Payment Method : </label> 
							<?php echo form::text_field_d2('payment_method_id'); ?>
						 </li> 
						 <li><label>Bank  : </label> 
							<?php echo form::text_field_d2('bank_id'); ?>
						 </li> 
						 <li><label>Bank Account : </label> 
							<?php echo form::text_field_d2('bank_account_id'); ?>
						 </li> 
						</ul>
					 </div>
					 <div class="second_rowset">

					 </div>
					 <!--end of tab1 div three_column-->
					</div> 
					<div id="tabsLine-3" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Status : </label>                      
							<?php echo form::status_field($$class_second->status); ?>
						 </li>
						 <li><label>Profile : </label> 
							<?php echo form::text_field_d2('profile_id'); ?>
						 </li> 
						</ul>
					 </div>
					</div>
					<div id="tabsLine-4" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Order Type : </label>
							<?php
							// echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class_second->currency, 'currency', $readonly, '', ''); 
							echo form::text_field_d2('order_type_id');
							?>
						 </li>
						 <li><label>Price List : </label>
							<?php
							// echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class_second->currency, 'currency', $readonly, '', ''); 
							echo form::text_field_d2('price_list_id');
							?>
						 </li>
						 <li><label>Internal Organization : </label>
							<?php
							// echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class_second->currency, 'currency', $readonly, '', ''); 
							echo form::text_field_d2('internal_org_id');
							?>
						 </li>
						 <li><label>FOB : </label> 
							<?php echo form::text_field_d2('fob'); ?>
						 </li> 
						 <li><label>Freight Terms : </label> 
							<?php echo form::text_field_d2('freight_terms'); ?>
						 </li> 
						 <li><label>Transportation : </label> 
							<?php echo form::text_field_d2('transportation'); ?>
						 </li> 
						 <li><label>Country Of Origin : </label> 
							<?php echo form::text_field_d2('country_of_origin'); ?>
						 </li> 
						</ul>
					 </div>
					</div>
					<!--end of tab2 (purchasing)!!!! start of sales tab-->
					<div id="tabsLine-5" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label>Site Address Id : 
							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup"></label>
							<?php echo form::text_field_d2('site_address_id'); ?>
						 </li>
						</ul>
						<div class="site address_details">
						 <?php echo!empty($site_address_id) ? $site_address_id : ""; ?>
						</div>  
					 </div>
					</div> 
					<!--                end of tab3 div three_column-->
					<!--end of tab3 (sales)!!!!start of purchasing tab-->
					<div id="tabsLine-6" class="tabContent">
					 <div id="show_attachments_site" class="show_attachment">
						<input type="button" class="attachment_button button" value="Attachements" id="site_attachment_button" name="">
						<?php echo file::attachment_statement($site_file); ?>
					 </div>
					</div>
					<!--end of tab4(purchasing)!!! start of MFG tab-->
					<div id="tabsLine-7" class="tabContent">

					</div>
					<!--end of tab5 (Manufacturing)!! start of planning -->
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
