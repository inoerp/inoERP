<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="address_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header"><span class="heading">Address Header </span>
			 <form action=""  method="post" id="address"  name="address">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<li><label><img class="address select_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png">
						Address Id :</label> 
					 <?php echo form::text_field('address_id', $address->address_id, '10', '', '', 'System number', 'address_id', $readonly); ?>
					 <a name="show" href="address.php?address_id=" class="show address_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li>
					<li><label>Type :</label> 
					 <?php echo form::select_field_from_object('type', address::address_types(), 'option_line_code', 'option_line_code', $address->type, 'type', $readonly); ?>
					</li>
					<li><label>Address Name :</label> 
					 <?php echo form::text_field('address_name', $address->address_name, '20', '', '', 'Enter a valid address name', 'address_name', $readonly); ?>
					</li>
					<li><label><img class="tax_region_id select_popup clickable" src="<?php echo HOME_URL; ?>themes/images/serach.png">
						Tax Region :</label> 
					 <?php $f->text_field_d('tax_region_name') ?>
					</li>
					<li><label>Description  : </label> 
					 <?php echo form::text_field('description', $address->description, '20', '250', '', 'Limit to 100 characters', 'description', $readonly); ?>
					</li>
					<li><label>Extra Field : </label>
					 <?php echo form::extra_field($address->efid, '10', $readonly); ?>
					</li>
					<li><label>Status : </label>
					 <?php echo form::status_field($address->status, $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::revision_enabled_field($address->rev_enabled, $readonly); ?>
					</li>
					<li><label>Revision No: </label>
					 <?php echo form::text_field('rev_number', $address->rev_number, '10', '', '', '', '', $readonly); ?>
					</li>
				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Address Details </span>
				 <ul class="address inline_list">
					<li><label>Phone  : </label>
					 <?php echo form::text_field('phone', $address->phone, '30', '', '', 'Enter a valid number', 'phone', $readonly); ?>
					</li>
					<li><label>Email  : </label> 
					 <?php echo form::text_field('email', $address->email, '30', '', '', 'Enter a valid email', 'email', $readonly); ?>
					</li>
					<li><label>Web-site  : </label> 
					 <?php echo form::text_field('website', $address->website, '30', '', '', 'Enter a valid website', 'website', $readonly); ?>
					</li>
					<li><label>Country  : </label>
					 <?php echo form::text_field('country', $address->country, '30', '', '', 'Enter a valid country', 'country', $readonly); ?>
					</li>
					<li><label>Postal Code  : </label>
					 <?php echo form::text_field('postal_code', $address->postal_code, '30', '', '', 'Enter a postal_code', 'postal_code', $readonly); ?>
					</li>
					<li><label>Address :</label>  
					 <?php echo form::text_area('address', $address->address, '3', '22', '', 'Complete Address', 'address', $readonly); ?>
					</li>
				 </ul>
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
