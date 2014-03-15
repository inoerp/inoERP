<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="bom_material_element_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id="form_all">
			 <form action=""  method="post" id="bom_material_element"  name="bom_material_element">
				<div id ="form_header">
				 <div id="tabsHeader">
					<div class="large_shadow_box"><span class="heading"></span>
					 <ul class="column four_column">
						<li>
						 <label><img id="bom_material_element_popup" class="showPointer bom_material_element_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
							Material Element Id : </label>
						 <?php echo form::text_field_d('bom_material_element_id'); ?>
						 <a name="show" class="show bom_material_element_id_show">
							<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						</li>
						<li><label>Inventory : </label>
						 <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>
						</li>
						<li><label>Material Element : </label>
						 <?php echo form::text_field_d('material_element'); ?>
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
					 </ul>
					</div>

				 </div>
				</div>
				<div id ="form_line" class="form_line"><span class="heading"> Material Element Details </span>
				 <div id="tabsLine">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Details</a></li>
					 <li><a href="#tabsLine-2">Future</a></li>
					</ul>
					<div class="tabContainer"> 
					 <div id="tabsLine-1" class="tabContent">
						<div class="first_rowset"> 
						 <ul class="column five_column"> 
							<li><label>Default Basis : </label>
							 <?php echo form::select_field_from_object('default_basis', bom_header::bom_charge_basis(), 'option_line_id', 'option_line_code', $$class->default_basis, 'default_basis', $readonly); ?>
							</li>
						 </ul>
						</div>
						<div class="second_rowset">
						 <ul class="three_column">

						 </ul>
						</div>
						<!--end of tab1 div three_column-->
					 </div> 
					 <!--end of tab1-->
					 <div id="tabsLine-2" class="tabContent">
						<div class="first_rowset"> 
						 <ul class="column five_column"> 
						 </ul>
						</div>
						<div class="second_rowset">

						</div> 
						<!--                end of tab2 div three_column-->
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
		<!--   end of structure-->
	 </div>
	 <div id="content_bottom"></div>
	</div>
	<div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
