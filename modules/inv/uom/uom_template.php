<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="uom_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header"><span class="heading">UOM </span>
			 <form action=""  method="post" id="uom"  name="uom">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="uom_id select_popup clickable">
						UOM Id : </label> 
					 <?php $f->text_field_ds('uom_id') ?>
					 <a name="show" href="form.php?class_name=uom" class="show uom_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li> 
					<li><label>UOM :</label>
					 <?php $f->text_field_d('uom_name'); ?>
					</li>
					<li><label>Class :</label>
					 <?php echo form::select_field_from_object('class', uom::uom_class(), 'option_line_code', 'option_line_code', $$class->class, 'class', $readonly); ?>
					</li>
					<li><label>Description :</label>
					 <?php $f->text_field_d('description'); ?>
					</li>
					<li><label>Primary :</label>
					 <?php $f->checkBox_field_d('primary_cb'); ?>
					</li>
					<li><label>Extra Field : </label>
					 <?php echo form::extra_field($uom->ef_id, '10', $readonly); ?>
					</li>
					<li><label>Status : </label>
					 <?php echo form::status_field($uom->status, $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::revision_enabled_field($uom->rev_enabled_cb, $readonly); ?>
					</li>
					<li><label>Revision No: </label>
					 <?php echo form::text_field('rev_number', $uom->rev_number, '10', '', '', '', '', $readonly); ?>
					</li>
				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">UOM Details </span>
				 <div id="tabsLine">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Relationship</a></li>
					 <li><a href="#tabsLine-2">Future</a></li>
					</ul>
					<div class="tabContainer"> 
					 <div id="tabsLine-1" class="tabContent">
						<div class="three_column"> 
						 <ul> 
							<li><label>Primary UOM Id : </label>
							 <?php $f->text_field_dsr('primary_uom_id'); ?>
							</li>
							<li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="primary_uom_id select_popup clickable">
								Primary UOM : </label>
							 <?php $f->text_field_d('primary_uom'); ?>
							</li>
							<li><label> Operator : </label>
							 <input type="image"  src="<?php echo HOME_URL; ?>themes/images/multiply.png" alt="multiply"/> 
							</li> 
							<li><label>Primary Relation : </label>
							 <?php $f->text_field_d('primary_relation'); ?>
							</li> 
						 </ul> 
						</div> 
						<!--end of tab1 div three_column-->
					 </div> 
					 <div id="tabsLine-2"  class="tabContent">
						<div> 
						</div> 
						<!--                end of tab2 div three_column-->
					 </div>
					 <!--end of tab5-->
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
