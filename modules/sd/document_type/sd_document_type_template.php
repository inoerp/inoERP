<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="sd_document_type_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="sd_document_type_form"  name="sd_document_type_form"><span class="heading">Document Type </span>
				<div class="large_shadow_box tabContainer">
				 <ul class="column five_column"> 
					<li> 
					 <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sd_document_type_id select_popup clickable">
						Document Type Id : </label><?php $f->text_field_ds('sd_document_type_id') ?>
					 <a name="show" href="form.php?class_name=sd_document_type" class="show sd_document_type_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li> 
					<li><label>Document Type :</label><?php form::text_field_wid('document_type_name'); ?></li>
					<li><label>Description :</label> 					 <?php $f->text_field_wid('description'); ?> 					</li>
										<li><label>Restrict to BU : </label>
					 <?php echo form::select_field_from_object('bu_org_id_r', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id_r, 'bu_org_id_r', $readonly, '', ''); ?>
					</li>
					<li><label>Level :</label>
					 <?php echo $f->select_field_from_array('level', sd_document_type::$level_a, $$class->level); ?></li>

				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Document Type Details </span>
				 <div id="tabs">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Basic Info</a></li>
					 <li><a href="#tabsLine-2">Defaults</a></li>
					</ul>
					<div class="tabContainer"> 
					 <div id="tabsLine-1" class="tabContent">
						<div> 
						 <ul class="column four_column"> 
							<li><label>Type :</label>
							 <?php echo $f->select_field_from_array('type', sd_document_type::$type_a, $$class->type); ?>
							</li>
							<li><label>Category :</label>
							 <?php echo $f->select_field_from_array('category', sd_document_type::$category_a, $$class->category); ?>
							</li>
							<li><label>Entity : </label>
							 <?php echo $f->select_field_from_array('entity', sd_document_type::$entity_a, $$class->entity); ?>							 
							</li>
							<li><label>Process Flow :</label>
							 <?php $f->text_field_wid('process_flow_id'); ?>
							</li>
						 </ul> 
						</div> 
						<!--end of tab1 div three_column-->
					 </div> 
					 <div id="tabsLine-2"  class="tabContent">
						<div> 
						 <ul class="column four_column"> 
							<li><label>Default Line :</label>
							 <?php echo $f->select_field_from_object('default_line_document', sd_document_type::find_all(), 'sd_document_type_id', 'document_type_name', $$class->default_line_document); ?>
							</li>
							<li><label>Price List :</label> 
							 <?php echo $f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?>
							</li>
							<li><label>Ship From Org :</label> 
							 <?php echo $f->select_field_from_object('default_shipfrom_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->default_shipfrom_org_id, '', '', '', $readonly); ?>
							</li>
							<li><label>AR Transaction Type :</label> <?php $f->text_field_wid('ar_transaction_type'); ?>	</li>
							<li><label>AR Transaction Source :</label> <?php $f->text_field_wid('ar_transaction_source'); ?>	</li>
						 </ul> 
						</div> 
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
