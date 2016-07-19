<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="org_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<span class="heading">Organization Details </span>
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="org"  name="org">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<li> 
					 <label><img src="<?php echo HOME_URL; ?>themes/default/images/serach.png" class="org_id select_popup clickable">
						Org Id : </label> 
					 <?php $f->text_field_ds('org_id') ?>
					 <a name="show" href="form.php?class_name=org" class="show org_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li> 
					<li><label>Org Type : </label> 
					 <?php echo $f->select_field_from_object('type', org::org_types(), 'option_line_code', 'option_line_value', $$class->type, 'type', '', 1, $readonly1); ?>
					</li> 
					<li><label>Org : </label> <?php $f->text_field_dm('org'); ?> </li> 
					<li><label>Code : </label> <?php $f->text_field_dm('code'); ?> </li> 
					<li><label>Enterprise : </label>
					 <?php echo $f->select_field_from_object('enterprise_org_id', $$class->findAll_enterprise(), 'org_id', 'org', $$class->enterprise_org_id, 'enterprise_org_id', '', '', $readonly1); ?></li>
					<li><label>Legal Org  : </label>
					 <?php echo $f->select_field_from_object('legal_org_id', $$class->findAll_legal(), 'org_id', 'org', $$class->legal_org_id, 'legal_org_id', '', '', $readonly1); ?></li>
					<li><label>Business Org  : </label>
					 <?php echo $f->select_field_from_object('business_org_id', $$class->findAll_business(), 'org_id', 'org', $$class->business_org_id, 'business_org_id', '', '', $readonly1); ?></li> 
					<li><label>Description : </label> <?php $f->text_field_dm('description'); ?> </li> 
					<li><label>Extra Field : </label><?php echo form::extra_field($$class->ef_id, '10', $readonly); ?></li>
					<li><label>Status : </label><?php echo form::status_field($$class->status, $readonly); ?></li>
					<li><label>Revision : </label><?php echo form::revision_enabled_field($$class->rev_enabled, $readonly); ?></li>
					<li><label>Revision No: </label><?php echo form::text_field('rev_number', $$class->rev_number, '10', '', '', '', '', $readonly); ?></li>
					<li>
					 <label>Address Id:  <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_id select_popup clickable"></label> 
					 <input type="text"  name="address_id[]" value="<?php echo htmlentities($org->address_id);
					 ?>" maxlength="50" id="address_id"> 
					</li> 
				 </ul> 
				</div>
			 </form>
			</div>


			<!--END OF FORM HEADER-->
			<div id ="form_line" class="form_line"><span class="heading">Address Details </span>
			 <ul class="address inline_list">
				<li><label>Phone  : </label> <?php $f->text_field_d2r('phone'); ?></li>
				<li><label>Email  : </label> <?php $f->text_field_d2r('website'); ?></li>
				<li><label>Web-site  : </label><?php $f->text_field_d2r('website'); ?></li>
				<li><label>Country  : </label><?php $f->text_field_d2r('country'); ?></li>
				<li><label>Postal Code  : </label> <?php $f->text_field_d2r('postal_code'); ?></li>
				<li><label>Address :</label>  
				 <textarea readonly name="address" id="address" cols="22" rows="3" placeholder="Select address Id"><?php echo trim(htmlentities($address->address)); ?></textarea>
				</li>
			 </ul>
			</div>     
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
