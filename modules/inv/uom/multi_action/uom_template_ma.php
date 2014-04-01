<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="uom_divId">
			<div id="uom_search">
			 <?php
			 if (empty($readonly)) {
				if (property_exists($$class, 'option_lists')) {
				 $s->option_lists = $$class->option_lists;
				}
				$s->setProperty('_search_order_by', filter_input(INPUT_GET, 'search_order_by'));
				$s->setProperty('_search_asc_desc', filter_input(INPUT_GET, 'search_asc_desc'));
				$s->setProperty('_per_page', filter_input(INPUT_GET, 'per_page'));
				$s->setProperty('_searching_class', $class);
				$s->setProperty('_initial_search_array', $$class->initial_search);
				$search_form = $search->search_form($$class);
				if (!empty($pagination)) {
				 $pagination_statement = $pagination->show_pagination($pagination, 'uom', $pageno, $query_string);
				}
				echo!(empty($search_form)) ? $search_form : "";
			 }
			 ?>
			</div>
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="uom"  name="uom">
				<div id ="form_line" class="form_line"><span class="heading">Unit Of Measure Details </span>
				 <div id="tabsLine">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Basic Info</a></li>
					 <li><a href="#tabsLine-2">UOM Relation</a></li>

					</ul>
					<div class="tabContainer">
					 <div id="tabsLine-1" class="tabContent">
						<table class="form_table">
						 <tr>
							<th>Action</th>
							<th>UOM Id</th>
							<th>UOM</th>
							<th>Class</th>
							<th>Description</th>
							<th>Primary</th>
							<th>EF Id</th>
							<th>Status</th>
							<th>Rev Enabled</th>
							<th>Rev#</th>
						 </tr>
						 <tbody class="form_data_line_tbody">
							<?php
							$count = 0;
							if (!empty($search_result)) {
							 foreach ($search_result as $uom) {
								?>         
								<tr class="uom_line<?php echo $count ?>">
								 <td>    
									<ul class="inline_action">
									 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
									 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
									 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($uom->uom_id); ?>"></li>           
									</ul>
								 </td>
								 <td><?php form::text_field_widsr('uom_id'); ?></td>
								 <td><?php form::text_field_wid('uom_name'); ?></td>
								 <td><?php echo form::select_field_from_object('class', uom::uom_class(), 'option_line_code', 'option_line_code', $$class->class, 'class', $readonly); ?></td>
								 <td><?php form::text_field_wid('description'); ?></td>
								 <td><?php $f->checkBox_field_d('primary_cb'); ?></td>
								 <td><?php form::text_field_wid('ef_id'); ?></td>
								 <td><?php echo form::status_field($$class->status, $readonly); ?></td>
								 <td><?php echo form::checkBox_field('rev_enabled_cb' . $count, $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?></td> 
								 <td><?php form::text_field_wids('rev_number'); ?></td> 
								</tr>
								<?php
								$count = $count + 1;
							 }
							}
							?>
						 </tbody>
						</table>
					 </div>
					 <div id="tabsLine-2" class="scrollElement" class="tabContent">
						<table class="form_table">
						 <tr>
							<th> Primary UOM Id</th>
							<th> Primary UOM</th>
							<th> Operator </th>
							<th> Primary Relation </th>
						 </tr>
						 <tbody class="form_data_line_tbody">
							<?php
							$count = 0;
							if (!empty($search_result)) {
							 foreach ($search_result as $uom) {
								if (!empty($uom->primary_uom_id)) {
								 $primar_uom_i = uom::find_by_id($uom->primary_uom_id);
								 $uom->primary_uom = $primar_uom_i->uom_name;
								}
								?>         
								<tr class="uom_line<?php echo $count ?>">
								 <td><?php $f->text_field_widsr('primary_uom_id'); ?></td>
								 <td><?php $f->text_field_wid('primary_uom'); ?>
									<img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="primary_uom_id select_popup clickable">
								 </td>
								 <td><input type="image"  src="<?php echo HOME_URL; ?>themes/images/multiply.png" alt="multiply"/> 
								 </td> 
								 <td>	<?php $f->text_field_wid('primary_relation'); ?> </td> 
								</tr>
								<?php
								$count = $count + 1;
							 }
							}
							?>
						 </tbody>
						 <!--                  Showing a blank form for new entry-->

						</table>
					 </div>
					</div>
				 </div>
				</div> 
			 </form>
			</div>
			<!--END OF FORM HEADER-->
			<div id="pagination" style="clear: both;">
			 <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
			 ?>
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
<script type=text/javascript>
 function setValFromSelectPage(uom_id, uom_name) {
	this.uom_id = uom_id;
	this.uom_name = uom_name;
 }

 setValFromSelectPage.prototype.setVal = function() {
	var uom_id = this.uom_id;
	var uom_name = this.uom_name;
	var primaryUom_fieldClass = '.' + localStorage.getItem("primaryUom_fieldClass");
	primaryUom_fieldClass = primaryUom_fieldClass.replace(/\s+/g, '.');

	if (uom_id) {
	 if (primaryUom_fieldClass) {
		$('#content').find(primaryUom_fieldClass).find('.primary_uom').val(uom_name);
		$('#content').find(primaryUom_fieldClass).find('.primary_uom_id').val(uom_id);
		localStorage.removeItem("primaryUom_fieldClass");
	 }
	}
 };

 $(document).ready(function() {
	var classSave = new saveMainClass();
	classSave.json_url = 'form.php?class_name=uom';
	classSave.line_key_field = 'uom_name';
	classSave.single_line = false;
	classSave.savingOnlyHeader = false;
	classSave.lineClassName = 'uom';
	classSave.saveMain();

	//selecting primary UOM Id on multi action
	$("#content").on("click", '.primary_uom_id.select_popup',function() {
	 var primaryUom_fieldClass = $(this).closest('tr').prop('class');
	 localStorage.setItem("primaryUom_fieldClass", primaryUom_fieldClass);
	 void window.open('select.php?class_name=uom', '_blank',
					 'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	});

	//add new row in multi action template
	$("#content").on("click", ".add_row_img", function() {
	 var addNewRow = new add_new_rowMain();
	 addNewRow.trClass = 'uom_line';
	 addNewRow.tbodyClass = 'form_data_line_tbody';
	 addNewRow.noOfTabs = 2;
	 addNewRow.removeDefault = true;
	 addNewRow.add_new_row();
	});
 });

</script>
<?php include_template('footer.inc') ?>
