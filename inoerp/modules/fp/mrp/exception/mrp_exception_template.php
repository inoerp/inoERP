<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="fp_mrp_exception_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header"><span class="heading">MRP Exception </span>
			 <form action=""  method="post" id="fp_mrp_exception"  name="fp_mrp_exception">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<li><label><img class="fp_mrp_exception select_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png">
						MRP Exception Id :</label> 
					 <?php echo form::text_field('fp_mrp_exception_id', $fp_mrp_exception->fp_mrp_exception_id, '10', '', '', 'System number', 'fp_mrp_exception_id', $readonly); ?>
					 <a name="show" href="form.php?class_name=fp_mrp_exception" class="show fp_mrp_exception_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li>
					<li><label>Type :</label> 
					 <?php echo form::select_field_from_object('exception_type', fp_mrp_exception::mrp_exception_types(), 'option_line_code', 'option_line_value', $$class->exception_type, '', $readonly); ?>
					</li>
					<li><label>Organization :</label> 
					 <?php $f->text_field_d('org') ?>
					</li>
					<li><label>MRP :</label> 
					 <?php $f->text_field_d('mrp_name') ?>
					</li>
					<li><label>Ref Type :</label> 
					 <?php $f->text_field_d('reference_type') ?>
					</li>
					<li><label>Ref Key :</label> 
					 <?php $f->text_field_d('reference_key_name') ?>
					</li>
					<li><label>Ref Value :</label> 
					 <?php $f->text_field_d('reference_key_value') ?>
					</li>
				 </ul>
				 <div class="single_line">
					<label>Message  :</label> 
					<?php echo $$class->exception_message ; ?>
				 </div>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Exception Details </span>
				 <?php echo $$class->detailed_message ; ?>
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
