<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="minmax_header_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header"><span class="heading">Min Max Planner </span>
			 <form action=""  method="post" id="fp_minmax_header"  name="fp_minmax_header">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<li><label><img class="fp_minmax_header select_popup clickable" src="<?php echo HOME_URL; ?>themes/images/serach.png">
						MinMax Plan Id :</label> 
					 <?php echo $f->text_field_dr('fp_minmax_header_id'); ?>
					 <a name="show" href="form.php?class_name=fp_minmax_header" class="show fp_minmax_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li>
					<li><label>Inventory Org (1)</label>
					 <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>
					</li>
					<li><label>Plan Name (2): </label>
					 <?php $f->text_field_dm('plan_name'); ?>
					</li>
					<li><label>Planning Horizon(Days): </label>
					 <?php  echo $f->number_field('planning_horizon_days',$$class->planning_horizon_days); ?>
					</li>
					<li><label>Description: </label>
					 <?php $f->text_field_d('description'); ?>
					</li>
					<li><label>Demand Source: </label>
					 <?php echo $f->select_field_from_object('demand_source', fp_forecast_header::find_all(), 'fp_forecast_header_id', 'forecast', $$class->demand_source, '', '', 1, $readonly); ?>
					 </label>
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
