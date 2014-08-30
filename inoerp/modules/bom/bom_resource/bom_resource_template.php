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


			<div id ="form_header">
			 <form action=""  method="post" id="bom_resource"  name="bom_resource"><span class="heading">Resources</span>
				<div id="tabsHeader">
				 <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Costing</a></li>
					<li><a href="#tabsHeader-3">OSP</a></li>
          <li><a href="#tabsHeader-4">Employee</a></li>
          <li><a href="#tabsHeader-5">Equipment</a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsHeader-1" class="tabContent">
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

					<div id="tabsHeader-2" class="tabContent">
					 <div class="large_shadow_box">
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
					</div>

					<div id="tabsHeader-3" class="tabContent">
					 <div class="large_shadow_box">
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
					</div>
					<div id="tabsHeader-4" class="tabContent">
					 <div class="large_shadow_box">

					 </div>
					</div>
					<div id="tabsHeader-5" class="tabContent">
					 <div class="large_shadow_box">

					 </div>
					</div>
				 </div>


        </div>
			 </form>
			</div>

			<div id="form_line" class="form_line"><span class="heading">Resource Cost Lines </span>
			 <form action=""  method="post" id="bom_resource_cost_line"  name="bom_resource_cost_line">
				<div id="tabsLine">
				 <div class="tabContainer">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>Action</th>
              <th>Seq#</th>
							<th>Resource Cost Id</th>
							<th>Cost Type</th>
							<th>Description</th>
							<th>Rate</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($bom_resource_cost_object as $bom_resource_cost) {
							if(!empty($bom_resource_cost->bom_cost_type)){
							 $bcy = new bom_cost_type();
							 $bcy_i = $bcy->find_by_keyColumn($bom_resource_cost->bom_cost_type);
							 $bom_resource_cost->bom_cost_type_description = $bcy_i->description;
							}else{
							 $bom_resource_cost->bom_cost_type_description = null;
							}
							?>         
 						 <tr class="bom_resource_cost_line<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->bom_resource_cost_id); ?>"></li>           
 								<li><?php echo form::hidden_field('bom_resource_id', $$class->bom_resource_id); ?></li>
 							 </ul>
 							</td>
              <td><?php $f->seq_field_d($count) ?></td>
 							<td><?php form::text_field_wid2sr('bom_resource_cost_id'); ?></td>
							<td><?php echo $f->select_field_from_object('bom_cost_type', bom_cost_type::find_all(), 'cost_type_code', 'cost_type', $$class_second->bom_cost_type, '', '', 1, $readonly); ?></td>
							<td><?php $f->text_field_wid2r('bom_cost_type_description'); ?></td>
							<td><?php echo $f->number_field('resource_rate', $$class_second->resource_rate); ?></td>
						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
					 </table>
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
