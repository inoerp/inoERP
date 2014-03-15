<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="enterprise_divId">
			<div id="form_top">
			 <?php
			 $current_page_path = "enterprise.php";
			 if (empty($readonly)) {
				form::form_button($current_page_path);
				$readonly = "";
			 } else {
				$readonly = 1;
			 }
			 ?>
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="enterprise"  name="enterprise">
				<div class="large_shadow_box"><span class="heading">Enterprise Header </span>
				 <ul class="column five_column"> 
					<li><label><a href="find_enterprise.php" class="popup"> 
						 <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>Enterprise Id :</label> 
					 <?php echo form::text_field('enterprise_id', $enterprise->enterprise_id, '10', '', '', 'System number', 'enterprise_id', $readonly); ?>
					 <a name="show" href="enterprise.php?enterprise_id=" class="show"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li>
					<li><label>Organization :</label>
					 <?php echo form::select_field_from_object('org_id', org::find_all_enterprise(), 'org_id', 'org', $enterprise->org_id, 'org', $readonly); ?>
	     	</li>
					<li><label>Extra Field : </label>
					 <?php echo form::extra_field($enterprise->efid, '10', $readonly); ?>
					</li>
					<li><label>Status : </label>
					 <?php echo form::status_field($enterprise->status, $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::revision_enabled_field($enterprise->rev_enabled, $readonly); ?>
					</li>
					<li><label>Revision No: </label>
					 <?php echo form::text_field('rev_number', $enterprise->rev_number, '10', '', '', '', '', $readonly); ?>
					</li>
				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Enterprise Details </span>
				 <ul class="enterprise inline_list">
					<li><label>Designation Option  : </label>
					 <?php echo form::text_field('designation_option_header_id', $enterprise->designation_option_header_id, '30', '', '', 'Enter a valid number', 'designation_option_header_id', $readonly); ?>
					</li>
					<li><label>Type Option  : </label> 
					 <?php echo form::text_field('type_option_header_id', $enterprise->type_option_header_id, '30', '', '', '', 'type_option_header_id', $readonly); ?>
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
