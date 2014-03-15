<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="business_org_divId">
			<div id="form_top">
			 <?php
			 $current_page_path = "business_org.php";
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
			 <form action=""  method="post" id="business_org"  name="business_org">
				<div class="large_shadow_box"><span class="heading">Business Org Header </span>
				 <ul class="column five_column"> 
					<li><label><a href="find_business_org.php" class="popup"> 
						 <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>Business Org Id :</label> 
					 <?php echo form::text_field('business_id', $business_org->business_id, '10', '', '', 'System number', 'business_id', $readonly); ?>
					 <a name="show" href="business_org.php?business_id=" class="show"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li>
					<li><label>Organization :</label>
					 <?php echo form::select_field_from_object('org_id', org::find_all_business_org(), 'org_id', 'org', $business_org->org_id, 'org', $readonly); ?>
					</li>
					<li><label>Extra Field : </label>
					 <?php echo form::extra_field($business_org->efid, '10', $readonly); ?>
					</li>
					<li><label>Status : </label>
					 <?php echo form::status_field($business_org->status, $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::revision_enabled_field($business_org->rev_enabled, $readonly); ?>
					</li>
					<li><label>Revision No: </label>
					 <?php echo form::text_field('rev_number', $business_org->rev_number, '10', '', '', '', '', $readonly); ?>
					</li>
				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Business Org Details </span>
				 <div id="tabs">
					<ul>
					 <li><a href="#tabs-1">Basic Info</a></li>
					 <li><a href="#tabs-2">Org Details</a></li>
					</ul>
					<div id="tabs-1">
					 <div class="three_column"> 
						<ul> 
						 <li><label>Type of Business Org : </label> 
							<input type="text" name="business_org_type" value="<?php
							echo (!empty($business_org->business_org_type)) ? htmlentities($business_org->business_org_type) : "";
							?>" maxlength="50" id="business_org_type"> 
						 </li> 
						 <li><label>Manager : </label> 
							<input type="text" name="manager" value="<?php
							echo (!empty($business_org->manager)) ? htmlentities($business_org->manager) : "";
							?>" maxlength="50" id="manager"> 
						 </li>
						</ul> 
					 </div> 
					 <!--end of tab1 div three_column-->
					</div> 
					<!--              end of tab1-->

					<div id="tabs-2">
					 <div class="three_column"> 
						<ul>
						 <li><label>Enterprise Name : </label> 
							<input type="text" name="name" value="<?php echo htmlentities($business_org->org); ?>" 
										 maxlength="50"  id="name"> 
						 </li>
						 <li><label>Legal Org : </label> 
							<input type="text" name="name" value="<?php echo htmlentities($business_org->org); ?>" 
										 maxlength="50"  id="name"> 
						 </li>
						 <li><label>Ledger : </label> 
							<input type="text" name="name" value="<?php echo htmlentities($business_org->org); ?>" 
										 maxlength="50"  id="name"> 
						 </li>
						</ul>

					 </div> 
					 <!--                end of tab2 div three_column-->
					</div>
					<!--end of tab2-->

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
