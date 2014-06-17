<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="sd_delivery_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<div id ="form_header"><span class="heading">Category Header </span>

			 <div id="tabsHeader">
				<ul class="tabMain">
				 <li><a href="#tabsHeader-1">Basic Info</a></li>
				 <li><a href="#tabsHeader-2">Future</a></li>
				</ul>
				<div class="tabContainer">
				 <form action=""  method="post" id="category"  name="category">
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column three_column">
						 <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="category_id select_popup clickable">
							 Categort Id 
							</label><?php echo form::text_field_dsr('category_id'); ?><a name="show" href="form.php?class_name=category" class="show category_id clickable">
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label>Primary </label>
							<?php
							$f = new inoform();
							echo $f->checkBox_field_d('primary_cb');
							?>
						 </li>
						 <li><label>Parent Name :</label> 
							<?php  $cat = new category();
							echo $cat->all_child_category_select_option('parent_id', '', $$class->parent_id, 'parent_id', false) ?> 
             </li>
						 <li><label>Category </label><?php $f->text_field_d('category'); ?></li>
						 <li><label>Description </label><?php $f->text_field_d('description'); ?></li>
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-2" class="tabContent">
					 <div> 
						<div id="show_attachment" class="show_attachment">
						</div>
					 </div>
					</div>
				 </form>		
				</div>
			 </div>

			</div>
			<!--END OF FORM HEADER-->
		 </div>
		</div>
		<!--   end of structure-->
	 </div>
	 <div id="content_bottom"></div>
	</div>
	<!--<div id="content_right_right"></div>-->
 </div>

</div>

<?php include_template('footer.inc') ?>
