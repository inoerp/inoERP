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
			<span class="heading"><?php echo gettext('Organization Details') ?> </span>
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="org"  name="org">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<li> 
					 <label><img src="<?php echo HOME_URL; ?>themes/default/images/serach.png" class="org_id select_popup clickable">
						<?php echo gettext('Org Id') ?> : </label> 
					 <?php $f->text_field_ds('org_id') ?>
					 <a name="show" href="form.php?class_name=org" class="show org_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li> 
					<li><label><?php echo gettext('Org Type') ?> : </label> 
					 <?php echo $f->select_field_from_object('type', org::org_types(), 'option_line_code', 'option_line_value', $$class->type, 'type', '', 1, $readonly1); ?>
					</li> 
					<li><label><?php echo gettext('Org') ?> : </label> <?php $f->text_field_dm('org'); ?> </li> 
					<li><label><?php echo gettext('Code') ?> : </label> <?php $f->text_field_dm('code'); ?> </li> 
					<li><label><?php echo gettext('Enterprise') ?> : </label>
					 <?php echo $f->select_field_from_object('enterprise_org_id', $$class->findAll_enterprise(), 'org_id', 'org', $$class->enterprise_org_id, 'enterprise_org_id', '', '', $readonly1); ?></li>
					<li><label><?php echo gettext('Legal Org') ?>  : </label>
					 <?php echo $f->select_field_from_object('legal_org_id', $$class->findAll_legal(), 'org_id', 'org', $$class->legal_org_id, 'legal_org_id', '', '', $readonly1); ?></li>
					<li><label><?php echo gettext('Business Org') ?>  : </label>
					 <?php echo $f->select_field_from_object('business_org_id', $$class->findAll_business(), 'org_id', 'org', $$class->business_org_id, 'business_org_id', '', '', $readonly1); ?></li> 
					<li><label><?php echo gettext('Description') ?> : </label> <?php $f->text_field_dm('description'); ?> </li> 
					<li><label><?php echo gettext('Extra Field') ?> : </label><?php echo form::extra_field($$class->ef_id, '10', $readonly); ?></li>
					<li><label><?php echo gettext('Status') ?> : </label><?php echo form::status_field($$class->status, $readonly); ?></li>
					<li><label><?php echo gettext('Revision') ?> : </label><?php echo form::revision_enabled_field($$class->rev_enabled, $readonly); ?></li>
					<li><label><?php echo gettext('Revision No') ?>: </label><?php echo form::text_field('rev_number', $$class->rev_number, '10', '', '', '', '', $readonly); ?></li>
					<li>
					 <label><?php echo gettext('Address Id') ?>:  <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_id select_popup clickable"></label> 
					 <input type="text"  name="address_id[]" value="<?php echo htmlentities($org->address_id);
					 ?>" maxlength="50" id="address_id"> 
					</li> 
				 </ul> 
				</div>
			 </form>
			</div>


			<!--END OF FORM HEADER-->
			<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Address Details') ?> </span>
			 <ul class="address inline_list">
				<li><label><?php echo gettext('Phone') ?>  : </label> <?php $f->text_field_d2r('phone'); ?></li>
				<li><label><?php echo gettext('Email') ?>  : </label> <?php $f->text_field_d2r('website'); ?></li>
				<li><label><?php echo gettext('Web-site') ?>  : </label><?php $f->text_field_d2r('website'); ?></li>
				<li><label><?php echo gettext('Country') ?>  : </label><?php $f->text_field_d2r('country'); ?></li>
				<li><label><?php echo gettext('Postal Code') ?>  : </label> <?php $f->text_field_d2r('postal_code'); ?></li>
				<li><label><?php echo gettext('Address') ?> :</label>  
				 <textarea readonly name="address" id="address" cols="22" rows="3" placeholder="<?php echo gettext('Select Address Id')?>"><?php echo trim(htmlentities($address->address)); ?></textarea>
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
