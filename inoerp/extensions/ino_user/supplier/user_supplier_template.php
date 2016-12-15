<div class="row small-left-padding">
 <div id ="form_header"><h1 class="error"><?php echo gettext('Not availabe for your product. Use supplier @ user level') ?></h1>
  <span class="heading"><?php echo gettext('Supplier User Details') ?></span>
  <div class="tabContainer">
	 <ul class="column header_field">
		<li><?php
				echo $f->l_val_field_d('username', 'ino_user', 'username', '', 'vf_select_user username');
				echo $f->hidden_field_withId('ino_user_id', $user_id_h);
				?><i class="generic g_select_lead_employee_name select_popup clickable fa fa-search" data-class_name="ino_user"></i>
		 <i class="fa fa-refresh"></i></li>
		<li><label><?php echo gettext('First Name') ?></label>	<?php echo $f->text_field_d('first_name'); ?> </li>
		<li><label><?php echo gettext('Last Name') ?></label><?php echo $f->text_field_d('last_name'); ?>	 </li> 
	 </ul>
  </div>
 </div>
 <form method="post" id="user_supplier"  name="user_supplier">
  <!--END OF FORM HEADER-->
  <div id ="form_line" class="user_supplier">
   <span class="heading"><?php echo gettext('Class & Access Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Class Access') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
			 <thead> 
				<tr>
				 <th><?php echo gettext('Action') ?></th>
				 <th><?php echo gettext('Seq') ?>#</th>
				 <th><?php echo gettext('User Supplier Id') ?></th>
				 <th><?php echo gettext('Supplier Name') ?></th>
				 <th><?php echo gettext('Supplier Site') ?></th>
				</tr>
			 </thead>
			 <tbody class="form_data_line_tbody user_supplier_values" >
					 <?php
					 $count = 0;
					 foreach ($user_supplier_object as $user_supplier) {
						if (!empty($$class->supplier_id)) {
						 $sup = new supplier();
						 $sup->findBy_id($$class->supplier_id);
						 $$class->supplier_name = $sup->supplier_name;
						 $supplier_site = supplier_site::find_by_id($$class->supplier_site_id);
						 $supplier_site_obj = [];
						 if ($supplier_site) {
							array_push($supplier_site_obj, $supplier_site);
							$supplier_site_name_statement = $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, '', 'supplier_site_id xlarge', '', $readonly);
						 } else {
							$supplier_site_obj = supplier_site::find_by_parent_id($$class->supplier_id);
							$supplier_site_name_statement = $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, '', 'supplier_site_id xlarge', '', $readonly);
						 }
						} else {
						 $$class->supplier_name = null;
						 $supplier_site_name_statement = form::text_field('supplier_site_id', $$class->supplier_site_id);
						}
						?>         
 				<tr class="user_supplier_line<?php echo $count ?>">
 				 <td><?php echo ino_inline_action($$class->user_supplier_id, array('user_id' => $user_id_h)); ?>  </td>
 				 <td><?php $f->seq_field_d($count) ?></td>
 				 <td><?php $f->text_field_widsr('user_supplier_id') ?></td>
 				 <td><?php
							echo $f->val_field_dm('supplier_name', 'supplier', 'supplier_name', '', 'vf_select_supplier_name xlarge');
							echo $f->hidden_field_withId('supplier_id', $$class->supplier_id);
							?><i class="generic g_select_supplier_name select_popup clickable fa fa-search" data-class_name="supplier"></i></td>

 				 <td><?php echo $supplier_site_name_statement; ?></td>
 				</tr>
				 <?php
				 $count = $count + 1;
				}
				?>
			 </tbody>
			</table>
     </div>
    </div>

   </div>
  </div> 
 </form>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="primary_column_id" data-primary_column_id="user_supplier_id" ></li>
  <li class="lineClassName" data-lineClassName="user_supplier" ></li>
  <li class="line_key_field" data-line_key_field="supplier_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="user_supplier" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="user_supplier_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="user_supplier" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>