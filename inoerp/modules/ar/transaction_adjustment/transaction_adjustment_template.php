<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Transaction Adjustment') ?></span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   <li><a href="#tabsHeader-2"><?php echo gettext('Other Details') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <div id="tabsHeader-1" class="tabContent">
    <ul class="column header_field">
     <li><?php 
      $f->l_val_field_dm('transaction_number', 'ar_transaction_header', 'transaction_number', '', 'vf_select_transaction_number');
      echo $f->hidden_field_withId('ar_transaction_header_id', $$class->ar_transaction_header_id);
      echo $f->hidden_field_withCLass('bu_org_id', $$class->org_id, 'popup_value');
//      echo $f->hidden_field_withCLass('status', 'COMPLETED', 'popup_value');
      ?>
      <i class="generic g_select_transaction_number select_popup clickable fa fa-search" data-class_name="ar_transaction_header"></i></li>
     <li><?php $f->l_select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>       </li>
     <li><?php $f->l_date_fieldFromToday_m('transaction_date', ($$class->transaction_date)); ?>       </li>
     <li><?php $f->l_select_field_from_array('transaction_type', ar_transaction_adjustment::$transaction_type_a, $$class->transaction_type ,  'transaction_type', 'always_readonly'); ?>       
      <a name="show2" href="form.php?class_name=ar_transaction_adjustment&<?php echo "mode=$mode"; ?>" class="show2 document_id extn_uprofile">
       <i class="fa fa-refresh"></i></a> 
     </li> 
    </ul>
   </div>
   <div id="tabsHeader-2" class="tabContent">
    <div class="large_shadow_box"> 
     <ul class="column header_field"> 
      <li><?php $f->l_text_field_dr('item_id_m'); ?></li>
      <li><?php $f->l_text_field_dr('item_number'); ?></li>
      <li><?php $f->l_text_field_dr('item_description'); ?></li>
      <li><?php $f->l_select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom_id', '', '', 1); ?> </li>
      <li><?php $f->l_number_field_dr('total_quantity'); ?></li>
      <li><?php $f->l_number_field_dr('completed_quantity'); ?></li>
      <li><?php $f->l_text_field_dr('sales_order_header_id'); ?></li>
      <li><?php $f->l_text_field_dr('sales_order_line_id'); ?></li>
     </ul>
    </div>
   </div>
  </div>
 </div>
</div>
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Transaction Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('General Info') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Reference Info') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <form  method="post" id="pm_material_transaction"  name="pm_material_transaction">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('Resource') ?></th>
         <th><?php echo gettext('Op Detail Id') ?></th>
         <th><?php echo gettext('Step') ?>#</th>
         <th><?php echo gettext('Qty') ?></th>
         <th><?php echo gettext('Trnx. Qty') ?></th>
         <th><?php echo gettext('Op Line Id') ?></th>
         <th><?php echo gettext('Op Routing Id') ?></th>
         <th><?php echo gettext('Activity Code') ?></th>
         <th><?php echo gettext('Activity Factor') ?></th>
         <th><?php echo gettext('Trnx. Id') ?></th>
        </tr>
       </thead>
       <tbody class="inv_transaction_values form_data_line_tbody">
        <tr class="ar_transaction_adjustment">
         <td>
          <?php
          $count = 0; $f = new inoform();
          echo ino_inline_action($$class->pm_batch_ingredient_id, array('org_id' => $$class->org_id,
           'ar_transaction_header_id' => $$class->ar_transaction_header_id, 'transaction_type' => $$class->transaction_type, 'transaction_date' => $$class->transaction_date));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo !empty($bom_sequence_stament) ? $bom_sequence_stament : form::text_field_wid('bom_sequence'); ?></td>
         <td><?php $f->text_field_widsr('pm_batch_operation_detail_id'); ?></td>
         <td><?php $f->text_field_widsr('step_no', 'always_readonly'); ?></td>
         <td><?php $f->text_field_widsr('process_quantity', 'always_readonly'); ?></td>
         <td><?php echo $f->number_field('transaction_quantity' , $$class->transaction_quantity); ?></td>
         <td><?php $f->text_field_widsr('pm_batch_operation_line_id', 'always_readonly'); ?></td>
         <td><?php $f->text_field_widsr('pm_process_routing_header_id', 'always_readonly'); ?></td>
         <td><?php $f->text_field_widr('activity_code', 'always_readonly'); ?></td>
         <td><?php $f->text_field_widsr('activity_factror', 'always_readonly'); ?></td>
         <td><?php echo form::text_field_dsr('inv_transaction_id'); ?></td>
        </tr>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-2" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('Document Type') ?></th>
         <th><?php echo gettext('Doc. Number') ?></th>
         <th><?php echo gettext('Doc. Id') ?></th>
         <th><?php echo gettext('Ref Type') ?></th>
         <th><?php echo gettext('Ref Name') ?></th>
         <th><?php echo gettext('Ref Value') ?></th>
         <th><?php echo gettext('Ref Doc') ?></th>
         <!--<th><?php // echo gettext('WO BOM Line Id')    ?></th>-->
        </tr>
       </thead>
       <tbody class="inv_transaction_values form_data_line_tbody">
        <tr class="ar_transaction_adjustment">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_widr('document_type', 'copyValue'); ?>							</td>
         <td><?php echo $f->text_field('document_number', $$class->transaction_number, '8', '', 'copyValue', 1, 1); ?>							</td>
         <td><?php echo $f->text_field('document_id', $$class->ar_transaction_header_id, '8', '', 'copyValue', 1, 1); ?>							</td>
         <td><?php $f->text_field_widr('reference_type', 'copyValue'); ?>							</td>
         <td><?php echo $f->text_field('reference_key_name', 'ar_transaction_header', '20', '', 'copyValue', 1, 1); ?>							</td>
         <td><?php echo $f->text_field('reference_key_value', $$class->ar_transaction_header_id, '8', '', 'copyValue', 1, 1); ?>							</td>
         <td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : ''; ?></td>
         <!--<td><?php // $f->text_field_widsr('pm_wo_bom_id','copyValue');    ?></td>-->
        </tr>
       </tbody>
      </table>
     </div>
    </form>
   </div>

  </div>
 </div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="ar_transaction_adjustment" ></li>
  <li class="lineClassName" data-lineClassName="ar_transaction_adjustment" ></li>
  <li class="line_key_field" data-line_key_field="pm_batch_operation_detail_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="ar_transaction_adjustment" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="extn_uprofile" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="ar_transaction_adjustment" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>