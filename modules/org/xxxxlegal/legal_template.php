<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="legal_divId">
			<div id="form_top">
			 <?php
			 $current_page_path = "legal.php";
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
			 <form action=""  method="post" id="legal"  name="legal">
				<div class="large_shadow_box"><span class="heading">Legal Org Header </span>
				 <ul class="column five_column"> 
					<li><label><a href="find_legal.php" class="popup"> 
						 <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>Legal Org Id :</label> 
					 <?php echo form::text_field('legal_id', $legal->legal_id, '10', '', '', 'System number', 'legal_id', $readonly); ?>
					 <a name="show" href="legal.php?legal_id=" class="show"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li>
					<li><label>Organization :</label>
					 <?php echo form::select_field_from_object('org_id', org::find_all_legal(), 'org_id', 'org', $legal->org_id, 'org', $readonly); ?>
					</li>
					<li><label>Extra Field : </label>
					 <?php echo form::extra_field($legal->ef_id, '10', $readonly); ?>
					</li>
					<li><label>Status : </label>
					 <?php echo form::status_field($legal->status, $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::revision_enabled_field($legal->rev_enabled, $readonly); ?>
					</li>
					<li><label>Revision No: </label>
					 <?php echo form::text_field('rev_number', $legal->rev_number, '10', '', '', '', '', $readonly); ?>
					</li>
				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Legal Org Details </span>
				 <div id="tabs">
					<ul>
					 <li><a href="#tabs-1">Basic Info</a></li>
					 <li><a href="#tabs-2">Ledger Details</a></li>
					</ul>
					<div id="tabs-1">
					 <div class="three_column"> 
						<ul> 
						 <li><label>Type of Legal Org : </label>
							<?php form::text_field_d('legal_org_type'); ?>
						 </li> 
						 <li><label>Registration Number : </label> 
							<?php form::text_field_d('registration_number'); ?>
						 </li>
						 <li><label>Place of Registration : </label> 
							<?php form::text_field_d('place_of_registration'); ?>
						 </li> 
						 <li><label>Country of Registration : </label> 
							<?php form::text_field_d('country_of_registration'); ?>
						 </li>
						 <li><label>Identification No : </label> 
							<?php form::text_field_d('identification_number'); ?>
						 </li>
						 <li><label>EIN/TIN/TAN : </label>
							<?php form::text_field_d('ein_tin_tan'); ?>
						 </li> 
						</ul> 
					 </div> 
					 <!--end of tab1 div three_column-->
					</div> 
					<!--              end of tab1-->

					<div id="tabs-2">
					 <div class="three_column"> 
						<ul>
						 <li> 
							<label>Ledger Id : </label> 
							<?php form::text_field_d('ledger_id'); ?>
						 </li> 
						 <li><label>Balancing Segments : </label> 
							<?php form::text_field_d('balancing_segments'); ?>
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
