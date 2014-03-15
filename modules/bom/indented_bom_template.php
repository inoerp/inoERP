<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="indentedBom_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<div id ="form_header">
			 <div id="tabsHeader">
				<ul class="tabMain">
				 <li><a href="#tabsHeader-1">Basic Info</a></li>
				 <li><a href="#tabsHeader-2">Details</a></li>
				 <li><a href="#tabsHeader-3">Common BOM</a></li>
				</ul>
				<div class="tabContainer">
				 <div id="tabsHeader-1" class="tabContent">
					<div class="large_shadow_box"> 
					 <ul class="column four_column">
						<li><label>Org Name(1) : </label>
						 <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $bom_header->org_id, 'org_id', $readonly, '', ''); ?>
						</li>
						<li><label>BOM Id : </label>
						 <?php echo form::text_field('bom_header_id', $bom_header->bom_header_id, '15', '25', '', 'System Number', 'bom_header_id', $readonly) ?>
						 <a name="show" href="bom.php?bom_header_id=" class="show bom_header_id">
							<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						</li>
						<li><label>Item Id : </label>
						 <?php form::text_field_drm('item_id'); ?>
						</li>
						<li><label>Item Number(2) : </label>
						 <?php form::text_field_dm('item_number'); ?>
						</li>
						<li><label>Description: </label>
						 <?php form::text_field_widr('item_description'); ?>
						</li>
						<li><label>UOM : </label>
						 <?php echo form::select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom', $$class->uom, 'uom'); ?>
						</li>
					 </ul>
					</div>
				 </div>
				 <div id="tabsHeader-2" class="tabContent">
					<div> 
					 <ul class="column five_column">
						<li><label>Alternate Bom : </label>
						 <?php echo form::text_field_d('alternate_bom'); ?>
						</li>
						<li><label>Revision : </label>
						 <?php form::text_field_dm('bom_revision'); ?>
						</li>
						<li><label>Effective Date : </label>
						 <?php echo form::date_fieldAnyDay_m('effective_date', $$class->effective_date); ?>
						</li>
					 </ul>
					</div>
				 </div>
				 <div id="tabsHeader-3" class="tabContent">
					<div> 
					 <ul class="column five_column">
						<li><label>Common BOM Item Id: </label>
						 <?php form::text_field_widsr('item_id'); ?>
						</li>
						<li><label>Item Number : </label>
						 <?php form::text_field_wid('commonBom_item_number'); ?>
						</li>
						<li><label>Description: </label>
						 <?php form::text_field_wid('commonBom_item_description'); ?>
						</li>
					 </ul>
					</div>
				 </div>
				</div>

			 </div>
			</div>

			<div id="form_line" class="form_line"><span class="heading">BOM Lines </span>
			 <div id="tabsLine">
				<ul class="tabMain">
				 <li><a href="#tabsLine-1">Main</a></li>
				 <li><a href="#tabsLine-2">Effectivity</a></li>
				 <li><a href="#tabsLine-3">Control</a></li>
				</ul>
				<div class="tabContainer">
				 <div id="tabsLine-1" class="tabContent">
					<table class="form_line_data_table">
					 <thead> 
						<tr>
						 <th>Row#</th>
						 <th>Level</th>
						 <th>BOM Line Id</th>
						 <th>BOM Sequence</th>
						 <th>Op. Sequence</th>
						 <th>Item Id</th>
						 <th>Item Number</th>
						 <th>Item Description</th>
						 <th>UOM</th>
						 <th>Usage Basis</th>
						 <th>Quantity</th>
						</tr>
					 </thead>
					 <tbody class="form_data_line_tbody">
						<?php
						global $rowCount;
						$rowCount = 0;
						foreach ($bom_line_object as $indented_bom_lines0) {
						 $level = 0;
						 ?>         
 						<tr class="bom_line<?php echo $rowCount ?>">
 						 <td> <?php echo $rowCount; ?> </td>
 						 <td class="<?php echo 'L' . $level; ?>"> <?php echo 'L: ' . $level; ?> </td>
							<?php
							$indented_bom_statment = indentedBom_tab1($indented_bom_lines0);
							echo $indented_bom_statment;
							?>
 						</tr>
 						<!--end of BOM Level 0 and Beginning of Indented BOM Levels -->
						 <?php
						 show_indentedBom($indented_bom_lines0, 'tab1', 1);
						 ?>
						 <?php
//							 End of check of indented BOM Level 1
						 $rowCount = $rowCount + 1;
						}
						?>
					 </tbody>
					</table>
				 </div>
				 <div id="tabsLine-2" class="scrollElement tabContent">
					<table class="form_line_data_table">
					 <thead> 
						<tr>
						 <th>Row#</th>
						 <th>Level</th>
						 <th>Start Date</th>
						 <th>End Date</th>
						 <th>ECO Number</th>
						 <th>ECO implemented</th>
						</tr>
					 </thead>
					 <tbody class="form_data_line_tbody">
						<?php
						global $rowCount;
						$rowCount = 0;
						foreach ($bom_line_object as $indented_bom_lines0) {
						 $level = 0;
						 ?>         
 						<tr class="bom_line<?php echo $rowCount ?>">
 						 <td> <?php echo $rowCount; ?> </td>
 						 <td class="<?php echo 'L' . $level; ?>"> <?php echo 'L: ' . $level; ?> </td>
							<?php
							$indented_bom_statment = indentedBom_tab2($indented_bom_lines0);
							echo $indented_bom_statment;
							?>
 						</tr>
 						<!--end of BOM Level 0 and Beginning of Indented BOM Levels -->
						 <?php
						 show_indentedBom($indented_bom_lines0, 'tab2', 1);
						 ?>
						 <?php
//							 End of check of indented BOM Level 1
						 $rowCount = $rowCount + 1;
						}
						?>
					 </tbody>
					</table>
				 </div>
				 <div id="tabsLine-3" class="tabContent">
					<table class="form_line_data_table">
					 <thead> 
						<tr>
						 <th>Row#</th>
						 <th>Level</th>
						 <th>Planning %</th>
						 <th>Yield</th>
						 <th>WIP Supply Type</th>
						 <th>Sub inventory</th>
						 <th>Locator</th>
						 <th>In cost rollup</th>
						</tr>
					 </thead>
					 <tbody class="form_data_line_tbody">
						<?php
						global $rowCount;
						$rowCount = 0;
						foreach ($bom_line_object as $indented_bom_lines0) {
						 $level = 0;
						 ?>         
 						<tr class="bom_line<?php echo $rowCount ?>">
 						 <td> <?php echo $rowCount; ?> </td>
 						 <td class="<?php echo 'L' . $level; ?>"> <?php echo 'L: ' . $level; ?> </td>
							<?php
							$indented_bom_statment = indentedBom_tab3($indented_bom_lines0);
							echo $indented_bom_statment;
							?>
 						</tr>
 						<!--end of BOM Level 0 and Beginning of Indented BOM Levels -->
						 <?php
						 show_indentedBom($indented_bom_lines0, 'tab3', 1);
						 ?>
						 <?php
//							 End of check of indented BOM Level 1
						 $rowCount = $rowCount + 1;
						}
						?>
					 </tbody>

					</table>
				 </div>
				</div>
			 </div>

			 <ul class="inline download_action">
				<li class="export_to_excel"><img  src="<?php echo HOME_URL; ?>themes/images/excel_16.png"  alt="export to excel" /></li>
			 </ul>
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
