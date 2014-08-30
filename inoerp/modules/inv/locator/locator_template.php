<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="locator_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header"><span class="heading">Locator </span>
			 <form action=""  method="post" id="locator"  name="locator">
				<div class="large_shadow_box">
				 <ul class="column four_column"> 
					<li> 
					 <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="locator_id select_popup clickable">
						Locator Id : </label> 
					 <?php $f->text_field_ds('locator_id') ?>
					 <a name="show" href="form.php?class_name=locator" class="show locator_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li> 
					<li><label>Organization :</label>
					 <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>
					</li>
					<li><label>Sub Inventory :</label>
					 <?php echo form::select_field_from_object('subinventory_id', subinventory::find_all(), 'subinventory_id', 'subinventory', $$class->subinventory_id, 'subinventory_id', $readonly); ?>
					</li>
					<li><label>Locator Structure :</label>
					 <?php echo locator::locator_structure(); ?>
					</li>
					<li><label>Locator :</label>
					 <?php form::text_field_wid('locator'); ?>
					</li>
					<li><label>Alias :</label>
					 <?php form::text_field_wid('alias'); ?>
					</li>
					<li><label>Extra Field : </label>
					 <?php echo form::extra_field($locator->ef_id, '10', $readonly); ?>
					</li>
					<li><label>Status : </label>
					 <?php echo form::status_field($locator->status, $readonly); ?>
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
