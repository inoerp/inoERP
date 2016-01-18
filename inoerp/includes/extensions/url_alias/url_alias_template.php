<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="ext_url_alias_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<span class="heading">URL Alias </span>
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="ext_url_alias"  name="ext_url_alias">
				<div class="large_shadow_box">
				 <ul class="column three_column"> 
					<li> 
					 <label><img src="<?php echo HOME_URL; ?>themes/default/images/serach.png" class="ext_url_alias_id select_popup clickable">
						URL Alias Id : </label> 
					 <?php $f->text_field_ds('ext_url_alias_id') ?>
					 <a name="show" href="form.php?class_name=ext_url_alias" class="show ext_url_alias_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li>
					<li><label>Content Id : </label> <?php echo $f->text_field_dm('content_id'); ?> </li> 
					<li><label>Original Path : </label> 
					 <?php echo $f->text_field('original_url', $$class->original_url, '60' , 'original_url', '',1); ?> </li> 
					<li><label>Alias : </label> 
					<?php echo $f->text_field('alias', $$class->alias, '100' , 'alias', '',1); ?> </li> 
					
				 </ul> 
				</div>
			 </form>
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
