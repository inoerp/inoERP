<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="program_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<span class="heading">Program Details </span>
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="program"  name="program">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<li> 
					 <label><img src="<?php echo HOME_URL; ?>themes/default/images/serach.png" class="program_id select_popup clickable">
						Program Id : </label> 
					 <?php $f->text_field_ds('sys_program_id') ?>
					 <a name="show" href="form.php?class_name=program" class="show program_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li> 
					<li><label>Program : </label> <?php $f->text_field_dm('program_name'); ?> </li> 
					<li><label>Status : </label> <?php $f->text_field_d('status'); ?> </li> 
					<li><label>Module : </label> <?php $f->text_field_d('module_name'); ?> </li> 
					<li><label>Class : </label> <?php $f->text_field_d('class'); ?> </li> 
					<li><label>Description : </label> <?php $f->text_field_d('description'); ?> </li> 
				 </ul> 
				</div>
			 </form>
			</div>

			<!--END OF FORM HEADER-->
			<div id ="form_line" class="form_line">
			 <span class="heading">Output </span><?php
			 if (!empty($$class->output_path)) {
				echo "<a href='" . HOME_URL_WOS . $$class->output_path . "' target='new'> View </a> ";
			 }
			 ?>
			 <span class="heading">Parameters </span>
			 <?php
			 echo '<pre>';
			 print_r(unserialize($$class->parameters));
			 echo '</pre>';
			 ?>
			 <span class="heading">Message Details </span><?php echo $$class->message; ?>
			</div>     
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
