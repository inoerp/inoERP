<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id="po_divId">
 <!--    START OF FORM HEADER-->

 <!--    End of place for showing error messages-->

 <div id ="form_header">
  <span class="heading"><?php echo gettext('Purchase Order') ?></span>
  <form  method="post" id="po_header"  name="po_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Finance') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Address Details') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
     <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-6"><?php echo gettext('Actions') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('po_header_id') ?>
        <a name="show" href="form.php?class_name=po_header&<?php echo "mode=$mode"; ?>" class="show document_id po_header_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>        </li>
       <li><?php $f->l_select_field_from_array('po_type', po_header::$po_type_a, $$class->po_type, 'po_type', '', 1, $readonly1, $readonly1); ?>        </li>
       <li><?php $f->l_text_field_d('po_number', 'primary_column2'); ?> </li>
       <li><?php $f->l_text_field_dd('release_number'); ?>
					 <?php echo $f->hidden_field_withId('ref_po_header_id', $$class->ref_po_header_id); ?>
       </li>
       <li><?php $f->l_select_field_from_object('status', po_header::po_status(), 'option_line_code', 'option_line_value', $$class->po_status, 'po_status', 'dont_copy', '', 1); ?></li>
       <li><?php
					 echo $f->l_val_field_dm('supplier_name', 'supplier', 'supplier_name', '', 'supplier_name', 'vf_select_supplier_name');
					 echo $f->hidden_field_withId('supplier_id', $$class->supplier_id);
					 ?><i class="generic g_select_supplier_name select_popup clickable fa fa-search" data-class_name="supplier"></i></li>
       <li><?php
					 echo $f->l_val_field_d('supplier_number', 'supplier', 'supplier_number', '', '', 'vf_select_supplier_number');
					 ?><i class="generic g_select_supplier_number select_popup clickable fa fa-search" data-class_name="supplier"></i></li>
       <li><label><?php echo gettext('Supplier Site') ?></label><?php
					 $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
					 echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
					 ?> </li>
       <li><?php $f->l_text_field_d('rev_number'); ?></li> 
       <li><?php $f->l_checkBox_field_d('multi_bu_cb'); ?></li> 
       <li><?php
					 echo $f->l_val_field_d('buyer', 'hr_employee_v', 'employee_name', '', 'vf_select_document_owner employee_name');
					 echo $f->hidden_field_withId('hr_employee_id', $$class->hr_employee_id);
					 ?><i class="generic g_select_document_owner select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
       <li><?php $f->l_text_field_d('description'); ?></li> 
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><?php $f->l_date_fieldFromToday('agreement_start_date', $$class->agreement_start_date) ?></li>
        <li><?php $f->l_date_fieldFromToday('agreement_end_date', $$class->agreement_start_date) ?></li>
        <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
        <li><?php $f->l_select_field_from_object('ledger_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', 'currency', 1, 1); ?></li>
        <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
        <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate', '', 1, $readonly); ?> </li>
        <li><?php $f->l_select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_purchasing_pl(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?></li>
        <li><?php $f->l_number_field('header_amount', $$class->header_amount, '15', 'header_amount'); ?></li>
        <li><?php $f->l_number_field('tax_amount', $$class->tax_amount, '15', 'tax_amount'); ?></li>
        <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id', '', 1, $readonly1); ?></li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div class="shipto_address"><?php $f->address_field_d('ship_to_id'); ?></div>
      <div class="billto_address"><?php $f->address_field_d('bill_to_id'); ?></div>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div id="comments">
       <div id="comment_list">
					 <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
					 <?php
					 $reference_table = 'po_header';
					 $reference_id = $$class->po_header_id;
					 ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
     <div id="tabsHeader-5" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-6" class="tabContent">
      <div> 
       <ul class="column four_column">
        <li id="document_print"><label><?php echo gettext('Document Print') ?></label>
         <a class="button" target="_blank"
            href="<?php echo HOME_URL ?>form.php?class_name=po_header&amp;router=pdf_print&amp;po_header_id=<?php echo!(empty($$class->po_header_id)) ? $$class->po_header_id : ""; ?>" >Print PO</a>
        </li>
        <li><label><?php echo gettext('Action') ?></label>
						<?php
						echo $f->select_field_from_array('action', $$class->action_a, '', 'action', '', '', $action_readonly, $action_readonly)
						?>
        </li>
       </ul>

       <div id="comment" class="shoe_comments">
       </div>
      </div>
     </div>
    </div>

   </div>
  </form>
 </div>
 <?php
 if ($$class->po_type == 'CONTRACT') {
	echo '</div></div>  </div>     <div id="content_bottom"></div>   </div>   <div id="content_right_right"></div>  </div> </div>';
	include_template('footer.inc');
	return;
 }
 ?>
 <div id="form_line" class="form_line"><span class="heading"><?php echo gettext('PO Lines & Shipments') ?></span>
  <form  method="post" id="po_line"  name="po_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Finance') ?> </a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Agreement Details') ?> </a></li>
     <li><a href="#tabsLine-4"><?php echo gettext('Other Info') ?> </a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('Line Id') ?></th>
         <th><?php echo gettext('Line') ?>#</th>
         <th><?php echo gettext('Receiving') ?></th>
         <th><?php echo gettext('Type') ?></th>
         <th><?php echo gettext('Item Number') ?></th>
         <th><?php echo gettext('Revision') ?></th>
         <th><?php echo gettext('Description') ?></th>
         <th><?php echo gettext('Quantity') ?></th>
         <th><?php echo gettext('UOM') ?></th>
         <th><?php echo gettext('Shipments') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
					 <?php
					 $count = 0;
					 foreach ($po_line_object as $po_line) {
						?>         
 				<tr class="line_rows po_line<?php echo $count ?>">
 				 <td>
							<?php
							echo ino_inline_action($$class_second->po_line_id, array('po_header_id' => $$class->po_header_id));
							?>
 				 </td>
 				 <td><?php $f->seq_field_d($count) ?></td>
 				 <td><?php $f->text_field_wid2sr('po_line_id', 'always_readonly line_id'); ?></td>
 				 <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
 				 <td><?php echo $f->select_field_from_object('receving_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->receving_org_id, '', 'org_id copyValue', 1, $readonly); ?></td>
 				 <td><?php echo $f->select_field_from_object('line_type', po_line::po_line_types(), 'option_line_code', 'option_line_value', $$class_second->line_type, '', 'copyValue', 1, $readonly); ?></td>
 				 <td><?php
							$f->val_field_wid2('item_number', 'item', 'item_number', 'receving_org_id');
							echo $f->hidden_field_withCLass('item_id_m', $$class_second->item_id_m, 'dont_copy_r');
							echo $f->hidden_field_withCLass('purchased_cb', '1', 'popup_value');
							echo $f->hidden_field('processing_lt', '');
							?>
 					<i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
 				 <td><?php
							if (!empty($$class_second->item_id_m) && !empty($$class_second->receving_org_id)) {
							 $revision_name_a = inv_item_revision::find_by_itemIdM_orgId($$class_second->item_id_m, $$class_second->receving_org_id);
							} else {
							 $revision_name_a = array();
							}
							echo $f->select_field_from_object('revision_name', $revision_name_a, 'revision_name', 'revision_name', $$class_second->revision_name, '', 'small');
							?></td>
 				 <td><?php form::text_field_wid2('item_description'); ?></td>
 				 <td><?php echo $f->number_field('line_quantity', $$class_second->line_quantity, '', '', 'allow_change'); ?></td>
 				 <td><?php
							echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom_id');
							?></td>
 				 <td class="add_detail_values"><i class="fa fa-arrow-circle-down add_detail_values_img"></i><?php include 'detail/po_detail_template.php'; ?>          </td>
 				</tr>
				 <?php
				 $count = $count + 1;
				}
				?>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-2" class="scrollElement tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('Price List') ?></th>
         <th><?php echo gettext('Price Date') ?></th>
         <th><?php echo gettext('Unit Price') ?>#</th>
         <th><?php echo gettext('Line Price') ?>#</th>
         <th><?php echo gettext('Tax Code') ?></th>
         <th><?php echo gettext('Tax Amount') ?></th>
         <th><?php echo gettext('GL Line Price') ?></th>
         <th><?php echo gettext('GL Tax Amount') ?></th>
         <th><?php echo gettext('Line Description') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
					 <?php
					 $count = 0;
					 foreach ($po_line_object as $po_line) {
						?>         
 				<tr class="po_line<?php echo $count ?>">
 				 <td><?php $f->seq_field_d($count) ?></td>
 				 <td><?php echo $f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_purchasing_pl(), 'mdm_price_list_header_id', 'price_list', $$class_second->price_list_header_id, '', 'medium copyValue'); ?>
 				 </td>
 				 <td><?php echo $f->date_fieldAnyDay('price_date', $$class_second->price_date, 'copyValue') ?></td>
 				 <td><?php echo $f->number_field('unit_price', $$class_second->unit_price); ?></td>
 				 <td><?php echo $f->number_field('line_price', $$class_second->line_price); ?></td>
 				 <td><?php echo $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_inTax_by_bu_org_id($$class->bu_org_id), 'mdm_tax_code_id', 'tax_code', $$class_second->tax_code_id, '', 'input_tax medium', '', $readonly, '', '', '', 'percentage') ?></td>
 				 <td><?php form::number_field_wid2('tax_amount'); ?></td>
 				 <td><?php $f->text_field_d2sr('gl_line_price', 'always_readonly'); ?></td>
 				 <td><?php $f->text_field_d2sr('gl_tax_amount', 'always_readonly'); ?></td>
 				 <td><?php form::text_field_wid2('line_description'); ?></td>

 				</tr>
				 <?php
				 $count = $count + 1;
				}
				?>
       </tbody>
       <!--                  Showing a blank form for new entry-->
      </table>
     </div>
     <div id="tabsLine-3" class="scrollElement tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('Agreed Quantity') ?></th>
         <th><?php echo gettext('Released Quantity') ?></th>
         <th><?php echo gettext('Agreed Amount') ?></th>
         <th><?php echo gettext('Released Amount') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
					 <?php
					 $count = 0;
					 foreach ($po_line_object as $po_line) {
						if (($$class->po_type == 'BLANKET') && !empty($$class_second->po_line_id)) {
						 $agrrement_details = po_line::find_agreement_details_by_lineId($$class_second->po_line_id);
						 if ($agrrement_details) {
							$$class_second->agreed_quantity = $agrrement_details->agreed_quantity;
							$$class_second->agreed_amount = $agrrement_details->agreed_amount;
							$$class_second->released_quantity = $agrrement_details->released_quantity;
							$$class_second->released_amount = $agrrement_details->released_amount;
						 } else {
							$$class_second->agreed_quantity = $$class_second->agreed_amount = $$class_second->released_quantity = $$class_second->released_amount = null;
						 }
						} else {
						 $$class_second->agreed_quantity = $$class_second->agreed_amount = $$class_second->released_quantity = $$class_second->released_amount = null;
						}
						?>         
 				<tr class="po_line<?php echo $count ?>">
 				 <td><?php $f->seq_field_d($count) ?></td>
 				 <td><?php $f->text_field_wid2r('agreed_quantity'); ?></td>
 				 <td><?php $f->text_field_wid2r('agreed_amount'); ?></td>
 				 <td><?php $f->text_field_wid2r('released_quantity'); ?></td>
 				 <td><?php $f->text_field_wid2r('released_amount'); ?></td>
 				</tr>
				 <?php
				 $count = $count + 1;
				}
				?>
       </tbody>
       <!--                  Showing a blank form for new entry-->
      </table>
     </div>

     <div id="tabsLine-4" class="scrollElement tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('On Hold') ?></th>
         <th><?php echo gettext('Hold Details') ?></th>
         <th><?php echo gettext('Kit') ?>?</th>
         <th><?php echo gettext('Configured') ?>?</th>
         <th><?php echo gettext('Configuration') ?></th>
         <th><?php echo gettext('Ref Doc Type') ?></th>
         <th><?php echo gettext('Ref Number') ?></th>
				 <th><?php echo gettext('Discount');  ?></th>
				 <th><?php echo gettext('Discount Amount');  ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
					 <?php
					 $count = 0;
					 foreach ($po_line_object as $po_line) {
						?>         
 				<tr class="po_line<?php echo $count ?>">
 				 <td><?php $f->seq_field_d($count) ?></td>
 				 <td><?php $f->checkBox_field_wid2('hold_cb'); ?></td>
 				 <td><?php $f->text_field_wid2r('po_line_id'); ?></td>
 				 <td><?php echo $f->checkBox_field('kit_cb', $$class_second->kit_cb, '', 'dontCopy'); ?></td>
 				 <td><?php echo $f->checkBox_field('kit_configured_cb', $$class_second->kit_configured_cb, '', 'dontCopy'); ?></td>
 				 <td><a class="popup popup-form view-item-config medium" href="form.php?class_name=bom_config_header&mode=9&window_type=popup"> <i class="fa fa-edit"></i></a></td>
 				 <td><?php form::text_field_wid2('reference_doc_type'); ?></td>
 				 <td><?php form::text_field_wid2('reference_doc_number'); ?></td>
				 				 <td><?php echo $f->select_field_from_object('mdm_discount_header_id', mdm_discount_header::find_all(), 'mdm_discount_header_id', 'discount_name', $$class_second->mdm_discount_header_id, '', 'medium') ?></td>
				 <td><?php form::number_field_wid2('discount_amount'); ?></td>
 				</tr>
				 <?php
				 $count = $count + 1;
				}
				?>
       </tbody>
       <!--                  Showing a blank form for new entry-->
      </table>
     </div>
    </div>
   </div>
  </form>

 </div>

 <!--END OF FORM HEADER-->
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="po_header" ></li>
  <li class="lineClassName" data-lineClassName="po_line" ></li>
  <li class="detailClassName" data-detailClassName="po_detail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="po_header_id" ></li>
  <li class="form_header_id" data-form_header_id="po_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <!--<li class="single_line" data-enable_select="true" ></li>-->
  <li class="form_line_id" data-form_line_id="po_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="po_header_id" ></li>
  <li class="docLineId" data-docLineId="po_line_id" ></li>
  <li class="docDetailId" data-docDetailId="po_detail_id" ></li>
  <li class="btn1DivId" data-btn1DivId="po_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="po_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="4" ></li>
 </ul>
</div>

