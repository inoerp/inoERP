<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="mrp_header_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header"><span class="heading">MRP Planner </span>
			 <form action=""  method="post" id="fp_mrp_header"  name="fp_mrp_header">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<li><label><img class="fp_mrp_header select_popup clickable" src="<?php echo HOME_URL; ?>themes/images/serach.png">
						MRP Plan Id :</label> 
					 <?php echo form::text_field('fp_mrp_header_id', $$class->fp_mrp_header_id, '10', '', '', 'System number', 'fp_mrp_header_id', $readonly); ?>
					 <a name="show" href="form.php?class_name=fp_mrp_header" class="show fp_mrp_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li>
					<li><label>Inventory Org (1)</label>
					 <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>
					</li>
					<li><label>Plan Name (2): </label>
					 <?php $f->text_field_dm('mrp_name'); ?>
					</li>
					<li><label>Planning Horizon(Days): </label>
					 <?php  echo $f->number_field('planning_horizon_days',$$class->planning_horizon_days); ?>
					</li>
					<li><label>Description: </label>
					 <?php $f->text_field_d('description'); ?>
					</li>
					<li><label>Demand Source: </label>
					 <?php echo $f->select_field_from_object('demand_source', fp_mds_header::find_all(), 'fp_mds_header_id', 'mds_name', $$class->demand_source, '', '', 1, $readonly); ?></li>
					<li><label>Status : </label>                      
					 <?php echo form::status_field($$class->status, $readonly); ?>
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
