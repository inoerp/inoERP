<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="wip_accounting_group_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header"><span class="heading">WIP Accounting Group </span>
			 <form action=""  method="post" id="wip_accounting_group"  name="wip_accounting_group">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<li><label><img class="wip_accounting_group select_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png">Account Group Id :</label> 
					 <?php echo form::text_field('wip_accounting_group_id', $wip_accounting_group->wip_accounting_group_id, '10', '', '', 'System number', 'wip_accounting_group_id', $readonly); ?>
					 <a name="show" href="wip_accounting_group.php?wip_accounting_group_id=" class="show"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li>
					<li><label>Organization :</label>
					 <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>
					</li>
					<li><label>Account Group :</label>
					 <?php form::text_field_wid('wip_accounting_group'); ?>
					</li>
					<li><label>WO Type (2) : </label>
					 <?php echo form::select_field_from_object('wo_type', wip_wo_header::wip_wo_type(), 'option_line_id', 'option_line_code', $$class->wo_type, 'wo_type', $readonly, 'wo_type'); ?>
					</li>
					<li><label>Extra Field : </label>
					 <?php echo form::extra_field($wip_accounting_group->ef_id, '10', $readonly); ?>
					</li>
					<li><label>Status : </label>
					 <?php echo form::status_field($wip_accounting_group->status, $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::revision_enabled_field($wip_accounting_group->rev_enabled, $readonly); ?>
					</li>
					<li><label>Revision No: </label>
					 <?php echo form::text_field('rev_number', $wip_accounting_group->rev_number, '10', '', '', '', '', $readonly); ?>
					</li>
				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Business Org Details </span>
				 <div id="tabsLine">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Actual Accounts</a></li>
					 <li><a href="#tabsLine-2">Variance Accounts</a></li>
					</ul>
					<div class="tabContainer">

					 <div id="tabsLine-1" class="tabContent">
						<div> 
						 <ul class="column four_column"> 
               <li><label>Material : </label> <?php echo $f->ac_field_d('material_ac_id'); ?></li>
							<li><label>Mat OH : </label> <?php $f->ac_field_d('material_oh_ac_id'); ?></li>
							<li><label>Over Head : </label> <?php echo $f->ac_field_d('overhead_ac_id'); ?></li>
							<li><label>Resource : </label> <?php $f->ac_field_d('resource_ac_id'); ?></li>
							<li><label>OSP : </label> <?php echo $f->ac_field_d('osp_ac_id'); ?></li>
							</ul> 
						</div> 
						<!--end of tab1 div three_column-->
					 </div> 
					 <!--              end of tab1-->

					 <div id="tabsLine-2" class="tabContent">
						<div> 
						 <ul class="column four_column">
               <li><label>Material : </label> <?php echo $f->ac_field_d('var_material_ac_id'); ?></li>
							<li><label>Mat OH : </label> <?php $f->ac_field_d('var_material_oh_ac_id'); ?></li>
							<li><label>Over Head : </label> <?php echo $f->ac_field_d('var_overhead_ac_id'); ?></li>
							<li><label>Resource : </label> <?php $f->ac_field_d('var_resource_ac_id'); ?></li>
							<li><label>OSP : </label> <?php echo $f->ac_field_d('var_osp_ac_id'); ?></li>
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
