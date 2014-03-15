<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="business_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header"><span class="heading">Business Org Header </span>
			 <form action=""  method="post" id="business"  name="business">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<li><label><img class="business select_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png">Business Org Id :</label> 
					 <?php echo form::text_field('business_id', $business->business_id, '10', '', '', 'System number', 'business_id', $readonly); ?>
					 <a name="show" href="business.php?business_id=" class="show"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li>
					<li><label>Organization :</label>
					 <?php echo form::select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $business->org_id, 'org', $readonly1); ?>
					</li>
					<li><label>Extra Field : </label>
					 <?php echo form::extra_field($business->ef_id, '10', $readonly); ?>
					</li>
					<li><label>Status : </label>
					 <?php echo form::status_field($business->status, $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::revision_enabled_field($business->rev_enabled, $readonly); ?>
					</li>
					<li><label>Revision No: </label>
					 <?php echo form::text_field('rev_number', $business->rev_number, '10', '', '', '', '', $readonly); ?>
					</li>
				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Business Org Details </span>
				 <div id="tabsLine">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Basic Info</a></li>
					 <li><a href="#tabsLine-2">Org Details</a></li>
					</ul>
					<div class="tabContainer">

					 <div id="tabsLine-1" class="tabContent">
						<div class="three_column"> 
						 <ul> 
							<li><label>Type of Business Org : </label> 
							 <input type="text" name="business_org_type" value="<?php
							 echo (!empty($business->business_org_type)) ? htmlentities($business->business_org_type) : "";
							 ?>" maxlength="50" id="business_org_type"> 
							</li> 
							<li><label>Manager : </label> 
							 <input type="text" name="manager" value="<?php
							 echo (!empty($business->manager)) ? htmlentities($business->manager) : "";
							 ?>" maxlength="50" id="manager"> 
							</li>
						 </ul> 
						</div> 
						<!--end of tab1 div three_column-->
					 </div> 
					 <!--              end of tab1-->

					 <div id="tabsLine-2" class="tabContent">
						<div class="three_column"> 
						 <ul>
							<li><label>Enterprise Name : </label> 
						 <?php  echo $f->select_field_from_object('enterprise_org_id', org::find_all_enterprise(),'org_id', 'org', $$class->enterprise_org_id,'enterprise_org_id','','', $readonly); ?>
							</li>
							</li>
							<li><label>Legal Org : </label> 
							 <?php  echo $f->select_field_from_object('legal_org_id', org::find_all_legal(),'org_id', 'org', $$class->legal_org_id,'legal_org_id','legal_org_id','', $readonly); ?></li>
							<li><label>Ledger: </label> <?php echo $f->text_field_dr('ledger'); ?></li>
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
