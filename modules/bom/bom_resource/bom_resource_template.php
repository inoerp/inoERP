<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="bom_resource_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
       
			<form action=""  method="post" id="bom_resource"  name="bom_resource"><span class="heading">Resources</span>
			 <div id ="form_header">
				<div id="tabsHeader">
				 <div class="large_shadow_box">
					<ul class="column five_column">
					 <li>
						<label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bom_resource_id select_popup clickable">
						 Resource Id : </label>
						<?php $f->text_field_dsr('bom_resource_id'); ?>
						<a name="show" class="show bom_resource_id_show clickable"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					 </li>
					 <li><label>Inventory : </label>
						<?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly1); ?>
					 </li>
					 <li><label>Resource : </label>
						<?php echo form::text_field_d('resource'); ?>
					 </li>
					 <li><label>Description : </label>
						<?php echo form::text_field_d('description'); ?>
					 </li>
					 <li><label>Resource Type : </label>
						<?php echo $f->select_field_from_object('resource_type', bom_resource::resource_type(), 'option_line_code', 'option_line_code', $$class->resource_type, '', '', 1, $readonly1); ?>
					 </li>
					 <li><label>Charge Type : </label>
						<?php echo $f->select_field_from_object('charge_type', bom_resource::charge_type(), 'option_line_code', 'option_line_code', $$class->charge_type, '', '', 1, $readonly); ?>
					 </li> 
					 <li><label>UOM : </label>
						<?php echo $f->select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom', '', 1, $readonly1); ?>
					 </li>
					 <li><label>Ef Id : </label>
						<?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
					 </li>
					 <li><label>Status : </label>                      
						<?php echo form::status_field($$class->status, $readonly); ?>
					 </li>
					</ul>
				 </div>

        </div>
			 </div>
			 <div id ="form_line" class="form_line"><span class="heading"> Resource Details </span>
				<div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Costing</a></li>
          <li><a href="#tabsLine-2">OSP</a></li>
          <li><a href="#tabsLine-3">Employee</a></li>
          <li><a href="#tabsLine-4">Equipment</a></li>
          <li><a href="#tabsLine-5">Setup</a></li>
          <li><a href="#tabsLine-6">Others</a></li>
				 </ul>
				 <div class="tabContainer"> 
					<div id="tabsLine-1" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column four_column"> 
						 <li><label>Costed : </label>
							<?php echo form::checkBox_field('costed_cb', $$class->costed_cb, 'costed_cb', $readonly); ?>
						 </li>
						 <li><label>Absorption Ac: </label><?php
							$f = new inoform();
							$f->ac_field_d('absorption_ac_id');
							?></li>
						 <li><label>Variance Ac: </label><?php $f->ac_field_d('variance_ac_id'); ?></li>
						 <li><label>Standard Rate : </label>
							<?php echo form::checkBox_field('standard_rate_cb', $$class->standard_rate_cb, 'standard_rate_cb', $readonly); ?>
						 </li>
						</ul>
					 </div>
					 <div class="second_rowset">
						<ul class="three_column">

						</ul>
					 </div>
					 <!--end of tab1 div three_column-->
					</div> 
					<!--end of tab1-->
					<div id="tabsLine-2" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>OSP Resource : </label> 
							<?php echo form::checkBox_field('osp_cb', $$class->osp_cb, '', $readonly); ?>
						 </li>
						 <li><label>Item Id : </label><?php $f->text_field_wids('osp_item_id', 'item_id'); ?></li>
						 <li><label>Item Number : </label>
							<?php $f->text_field_wid('osp_item_number', 'select_item_number'); ?>
							<img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup">
						 </li>
						 <li><label>Description: </label><?php $f->text_field_wid('osp_item_description', 'item_description'); ?></li>
						</ul>
					 </div>
					 <div class="second_rowset">

					 </div> 
					 <!--                end of tab2 div three_column-->
					</div>
					<!--end of tab2 (purchasing)!!!! start of sales tab-->
					<div id="tabsLine-3" class="tabContent">
					 <div class="first_rowset"> 
					 </div>
					 <div class="second_rowset">
					 </div>
					</div> 
					<!--                end of tab3 div three_column-->
					<!--end of tab3 (sales)!!!!start of purchasing tab-->
					<div id="tabsLine-4" class="tabContent">
					 <div class="first_rowset"> 

					 </div>
					 <div class="second_rowset">

					 </div> 
					</div>
					<!--end of tab4(purchasing)!!! start of MFG tab-->
					<div id="tabsLine-5" class="tabContent">
					 <div class="first_rowset"> 
					 </div>
					 <div class="second_rowset">
					 </div> 
					</div>
					<!--end of tab5 (Manufacturing)!! start of planning -->
					<div id="tabsLine-6" class="tabContent">
					 <div class="first_rowset"> 

					 </div>
					 <div class="second_rowset">

					 </div> 
					</div>
					<!--end of tab6 (planning)...start of lead times-->
				 </div>

        </div>
			 </div> 
			</form>

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
