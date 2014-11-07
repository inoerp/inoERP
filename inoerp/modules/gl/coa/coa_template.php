<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="coa_structure_id">
		 <div id="coa_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id="form_all">
			 <form action=""  method="post" id="coa"  name="coa">
				<div id ="form_header">
				 <div id="tabsHeader">
					<div class="large_shadow_box"><span class="heading"></span>
					 <ul class="column four_column">
						<li>
						 <label><img id="coa_popup" class="showPointer popup" src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
							COA Id : </label>
						 <?php echo form::number_field_drs('coa_id'); ?>
						 <a name="show" class="show coa_id_show">
							<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						</li>
						<li><label>Structure : </label>
						 <?php echo form::select_field_from_object('coa_structure_id', coa::coa_structures(), 'option_header_id', 'option_type', $$class->coa_structure_id, 'coa_structure_id', $readonly1); ?>
						 <a name="show" class="show coa_structure_show">
							<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						</li>
						<li><label>Description : </label>
						 <?php echo form::text_field_d('description'); ?>
						</li>
						<li><label>Ef Id : </label>
						 <?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
						</li>
						<li><label>Status : </label>                      
						 <?php echo form::status_field($$class->status, $readonly); ?>
						</li>
						<li><label>Revision : </label>
						 <?php echo form::revision_enabled_field('rev_enabled_cb'); ?>
						</li>
						<li><label>Revision No: </label> 
						 <?php echo form::number_field_drs('rev_number'); ?>
						</li>
					 </ul>
					</div>

				 </div>
				</div>
				<div id ="form_line" class="form_line"><span class="heading"> Chart of Account Details </span>
				 <div id="tabsLine">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Qualifiers</a></li>
					 <li><a href="#tabsLine-2">Display</a></li>
					</ul>
					<div class="tabContainer"> 
					 <div id="tabsLine-1" class="tabContent">
						<div class="first_rowset"> 
						 <ul class="column five_column"> 
							<li><label>Balancing Segment : </label>
							 <?php echo form::select_field_from_object('balancing', coa::coa_segments_by_optionHeaderId($$class->coa_structure_id), 'option_line_id', 'option_line_code', $$class->balancing, 'balancing', $readonly1); ?>
							</li>
							<li><label>Cost Center : </label>
							 <?php echo form::select_field_from_object('cost_center', coa::coa_segments_by_optionHeaderId($$class->coa_structure_id), 'option_line_id', 'option_line_code', $$class->cost_center, 'cost_center', $readonly1); ?>
							</li>
							<li><label>Account : </label>
							 <?php echo form::select_field_from_object('natural_account', coa::coa_segments_by_optionHeaderId($$class->coa_structure_id), 'option_line_id', 'option_line_code', $$class->natural_account, 'natural_account', $readonly1); ?>
							</li>
							<li><label>Inter company : </label>
							 <?php echo form::select_field_from_object('inter_company', coa::coa_segments_by_optionHeaderId($$class->coa_structure_id), 'option_line_id', 'option_line_code', $$class->inter_company, 'inter_company', $readonly1); ?>
							</li>
						 </ul>
						</div>
						<!--end of tab1 div three_column-->
					 </div> 
					 <!--end of tab1-->
					 <div id="tabsLine-2" class="tabContent">
						<?php echo $dispaly_statement; ?>
					 </div>
					 <!--end of tab2 (purchasing)!!!! start of sales tab-->
					</div>
				 </div>
				</div> 
			 </form>
			</div>
			<!--END OF FORM -->
		 </div>
		</div>
		<!--   end of coa_structure_id-->
	 </div>
	 <div id="content_bottom"></div>
	</div>
	<div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
