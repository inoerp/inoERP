<div class="row small-left-padding">
 <div id="form_all">
  <div id="form_headerDiv">
   <form method="post" id="mdm_discount_value_line"  name="mdm_discount_value">
		<span class="heading"><?php echo gettext('Discount Values') ?></span>
		<div class="tabContainer">
		 <div id="tabsHeader-1" class="tabContent">
			<ul class="column header_field">
			 <li><?php
					 $f->l_val_field_d('po_number', 'po_all_v', 'po_number', '', $readonly1_class . ' enable_update');
					 echo $f->hidden_field_withCLass('po_status', 'approved', 'popup_value');
					 echo $f->hidden_field_withCLass('po_header_id', '', 'popup_value po_header_id');
					 echo $f->hidden_field_withCLass('po_line_id', '', 'popup_value po_line_id');
					 ?><i class="generic select_po_number select_popup clickable fa fa-search enable_update <?php echo $readonly1_class ?>" data-class_name="po_all_v"></i></li>
			 <li><?php
					 $f->l_val_field_d('so_number', 'sd_so_all_v', 'so_number', '', $readonly1_class . ' enable_update');
					 echo $f->hidden_field_withCLass('sd_so_header_id', '', 'popup_value sd_so_header_id');
					 echo $f->hidden_field_withCLass('sd_so_line_id', '', 'popup_value sd_so_line_id');
					 ?><i class="generic select_po_number select_popup clickable fa fa-search enable_update <?php echo $readonly1_class ?>" data-class_name="po_all_v"></i></li>
				<a name="show" href="form.php?class_name=sd_so_line&<?php echo "mode=$mode"; ?>" class="show document_id sd_so_line_id"><i class="fa fa-refresh"></i></a> 
			 </li>			</ul>
		 </div>
		</div>
    <div id ="form_line" class="mdm_discount_value"><span class="heading"><?php echo gettext('Discount Details') ?> </span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
      </ul>
      <div class="tabContainer"> 
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Id') ?></th>
           <th><?php echo gettext('Reference Type') ?></th>
           <th><?php echo gettext('Reference Key') ?></th>
           <th><?php echo gettext('Reference Value') ?></th>
           <th><?php echo gettext('Discount Id') ?></th>
           <th><?php echo gettext('Percentage') ?></th>
           <th><?php echo gettext('Amount') ?></th>
           <th><?php echo gettext('Formula') ?></th>
           <th><?php echo gettext('Manual') ?>?</th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody item_relation_values" >
						 <?php
						 $count = 0;
						 $f = new inoform();
						 $item_relation_object_ai = new ArrayIterator($item_relation_object);
						 $item_relation_object_ai->seek($position);
						 while ($item_relation_object_ai->valid()) {
							$mdm_discount_value = $item_relation_object_ai->current();
							?>         
 					<tr class="mdm_discount_value<?php echo $count ?>">
 					 <td><?php
								echo ino_inline_action($$class->mdm_discount_value_id, array('relation_type_h' => $relation_type_h));
								?>    
 					 </td>
 					 <td><?php form::number_field_drs('mdm_discount_value_id', 'always_readonly') ?></td>
 					 <td><?php echo $f->text_field_dr('reference_type'); ?></td>
 					 <td><?php echo $f->text_field_dr('reference_key_name'); ?></td>
 					 <td><?php echo $f->text_field_dr('reference_key_value'); ?></td>
 					 <td><?php echo $f->text_field_dr('mdm_discount_line_id'); ?></td>
 					 <td><?php echo $f->text_field_dr('discount_percentage'); ?></td>
 					 <td><?php echo $f->text_field_dr('discount_amount'); ?></td>
 					 <td><?php echo $f->text_field_dr('discount_formula'); ?></td>
 					 <td><?php $f->checkBox_field_d('manual_cb'); ?></td>
 					</tr>
					 <?php
					 $item_relation_object_ai->next();
					 if ($item_relation_object_ai->key() == $position + $per_page) {
						break;
					 }
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
 </div>
</div>

<div class="row small-top-margin">
 <div id="pagination" style="clear: both;">
		 <?php echo $pagination->show_pagination(); ?>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="mdm_discount_value" ></li>
  <li class="primary_column_id" data-primary_column_id="mdm_discount_value_id" ></li>
  <li class="lineClassName" data-lineClassName="mdm_discount_value" ></li>
  <li class="line_key_field" data-line_key_field="relation_type" ></li>
  <li class="no_headerid_check" data-no_headerid_check="9" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="mdm_discount_value" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="mdm_discount_value_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="mdm_discount_value" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>