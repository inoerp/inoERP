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
				 <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
				 <li><a href="#tabsHeader-2"><?php echo gettext('Details') ?></a></li>
				 <li><a href="#tabsHeader-3"><?php echo gettext('Common BOM') ?></a></li>
				</ul>
				<div class="tabContainer">
				 <div id="tabsHeader-1" class="tabContent">
					<div class="large_shadow_box"> 
					 <ul class="column four_column">
						<li><label><?php echo gettext('Org Name') ?>(1) : </label>
						 <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly, '', ''); ?>
						</li>
						<li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bom_header_id select_popup clickable">
							<?php echo gettext('BOM Id') ?> : </label>
						 <?php echo form::text_field_d('bom_header_id') ?><a name="show" href="bom.php?bom_header_id=" class="show bom_header_id">
							<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						</li>
						<li><label><?php echo gettext('Item Id') ?> : </label>
						 <?php form::text_field_drm('item_id_m'); ?>
						</li>
						<li><label><?php echo gettext('Item Number') ?>(2) : </label>
						 <?php form::text_field_dm('item_number'); ?>
						</li>
						<li><label><?php echo gettext('Description') ?>: </label>
						 <?php form::text_field_widr('item_description'); ?>
						</li>
						<li><label><?php echo gettext('UOM') ?> : </label>
						 <?php echo form::select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom'); ?>
						</li>
					 </ul>
					</div>
				 </div>
				 <div id="tabsHeader-2" class="tabContent">
					<div> 
					 <ul class="column five_column">
						<li><label><?php echo gettext('Alternate Bom') ?> : </label>
						 <?php echo form::text_field_d('alternate_bom'); ?>
						</li>
						<li><label><?php echo gettext('Revision') ?> : </label>
						 <?php form::text_field_dm('bom_revision'); ?>
						</li>
						<li><label><?php echo gettext('Effective Date') ?> : </label>
						 <?php echo form::date_fieldAnyDay_m('effective_date', $$class->effective_date); ?>
						</li>
					 </ul>
					</div>
				 </div>
				 <div id="tabsHeader-3" class="tabContent">
					<div> 
					 <ul class="column five_column">
						<li><label><?php echo gettext('Common BOM Item Id') ?>: </label>
						 <?php form::text_field_widsr('item_id_m'); ?>
						</li>
						<li><label><?php echo gettext('Item Number') ?> : </label>
						 <?php form::text_field_wid('commonBom_item_number'); ?>
						</li>
						<li><label><?php echo gettext('Description') ?>: </label>
						 <?php form::text_field_wid('commonBom_item_description'); ?>
						</li>
					 </ul>
					</div>
				 </div>
				</div>

			 </div>
			</div>

			<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('BOM Lines') ?> </span>
			 <div id="tabsLine">
				<ul class="tabMain">
				 <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
				 <li><a href="#tabsLine-2"><?php echo gettext('Effectivity') ?></a></li>
				 <li><a href="#tabsLine-3"><?php echo gettext('Control') ?></a></li>
				</ul>
				<div class="tabContainer">
				 <div id="tabsLine-1" class="tabContent">
					<table class="form_line_data_table">
					 <thead> 
						<tr>
						 <th><?php echo gettext('Row') ?>#</th>
						 <th><?php echo gettext('Level') ?></th>
						 <th><?php echo gettext('BOM Line Id') ?></th>
						 <th><?php echo gettext('BOM Sequence') ?></th>
						 <th><?php echo gettext('Op. Sequence') ?></th>
						 <th><?php echo gettext('Item Id') ?></th>
						 <th><?php echo gettext('Item Number') ?></th>
						 <th><?php echo gettext('Item Description') ?></th>
						 <th><?php echo gettext('UOM') ?></th>
						 <th><?php echo gettext('Usage Basis') ?></th>
						 <th><?php echo gettext('Quantity') ?></th>
						</tr>
					 </thead>
					 <tbody class="form_data_line_tbody">
						<?php
						global $rowCount;
						$rowCount = 0;
						foreach ($bom_line_object as &$indented_bom_lines0) {
						 if (!empty($indented_bom_lines0->component_item_id_m)) {
							$item = item::find_by_id($indented_bom_lines0->component_item_id_m);
							$indented_bom_lines0->component_item_number = $item->item_number;
							$indented_bom_lines0->component_description = $item->item_description;
							$indented_bom_lines0->component_uom = $item->uom_id;
						 }
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
						 <th><?php echo gettext('Row') ?>#</th>
						 <th><?php echo gettext('Level') ?></th>
						 <th><?php echo gettext('Start Date') ?></th>
						 <th><?php echo gettext('End Date') ?></th>
						 <th><?php echo gettext('ECO Number') ?></th>
						 <th><?php echo gettext('ECO implemented') ?></th>
						</tr>
					 </thead>
					 <tbody class="form_data_line_tbody">
						<?php
						global $rowCount;
						$rowCount = 0;
						foreach ($bom_line_object as &$indented_bom_lines0) {
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
						 <?php
						 show_indentedBom($indented_bom_lines0, 'tab2', 1);
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
						 <th><?php echo gettext('Row') ?>#</th>
						 <th><?php echo gettext('Level') ?></th>
						 <th><?php echo gettext('Planning') ?> %</th>
						 <th><?php echo gettext('Yield') ?></th>
						 <th><?php echo gettext('WIP Supply Type') ?></th>
						 <th><?php echo gettext('Subinventory') ?></th>
						 <th><?php echo gettext('Locator') ?></th>
						 <th><?php echo gettext('In cost Rollup') ?></th>
						</tr>
					 </thead>
					 <tbody class="form_data_line_tbody">
						<?php
						global $rowCount;
						$rowCount = 0;
						foreach ($bom_line_object as &$indented_bom_lines0) {
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
						 <?php
						 show_indentedBom($indented_bom_lines0, 'tab3', 1);
						 $rowCount = $rowCount + 1;
						}
						?>
					 </tbody>

					</table>
				 </div>
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
 	<div id="content_right_right"></div>
 </div>

</div>

<script type="text/javascript">
 function setValFromSelectPage(bom_header_id, item_id_m, item_number, item_description, uom_id) {
	this.bom_header_id = bom_header_id;
	this.item_id_m = item_id_m;
	this.item_number = item_number;
	this.item_description = item_description;
	this.uom_id = uom_id;
 }

 setValFromSelectPage.prototype.setVal = function() {
	var bom_header_id = this.bom_header_id;
	$("#bom_header_id").val(bom_header_id);
	var rowClass = '.' + localStorage.getItem("row_class");
	rowClass = rowClass.replace(/\s+/g, '.');

	var item_obj = [{id: 'item_id_m', data: this.item_id_m},
	 {id: 'item_number', data: this.item_number},
	 {id: 'item_description', data: this.item_description},
	 {id: 'uom', data: this.uom_id}
	];

	$(item_obj).each(function(i, value) {
	 if (value.data) {
		var fieldClass = '.' + value.id;
		$('#content').find(rowClass).find(fieldClass).val(value.data);
	 }
	});

	localStorage.removeItem("row_class");
	localStorage.removeItem("field_class");
 };
 $(document).ready(function() {
	//Popup for selecting bom
	$(".bom_header_id.select_popup").click(function() {
	 void window.open('select.php?class_name=bom_header', '_blank',
					 'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	 return false;
	});

	//Get the bom_id on find button click
	$('#form_header a.show.bom_header_id').click(function() {
	 var headerId = $('#bom_header_id').val();
	 $(this).attr('href', modepath() + 'bom_header_id=' + headerId);
	});
 });</script>
<?php include_template('footer.inc') ?>
