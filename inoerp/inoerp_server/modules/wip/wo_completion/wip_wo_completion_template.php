<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<!--create empty form or a single id when search is not clicked and the id is referred from other page -->
<div id ="form_all"> 
 <form  method="post" id="wip_wo_completion"  name="wip_wo_completion">
  <span class="heading"><?php echo gettext('Work Order Completion/Return') ?></span> 
  <div id ="form_header"> 
   <div id="form_serach_header" class="tabContainer">
    <ul class="column header_field tabContent">
     <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', 'popup_value', 1, $readonly1); ?>    </li>
     <li><?php
      echo $f->l_val_field_dm('wo_number', 'wip_wo_header', 'wo_number', 'org_id', 'vf_select_wo_number');
      echo $f->hidden_field_withId('wip_wo_header_id', $$class->wip_wo_header_id);
      echo $f->hidden_field_withIdClass('wo_status', 'RELEASED', 'popup_value');
      ?><i class="generic g_select_wo_number select_popup clickable fa fa-search" data-class_name="wip_wo_header"></i></li>
     <li><?php $f->l_select_field_from_array('transaction_type_id', wip_wo_completion::$transaction_type_id_a, $$class->transaction_type_id, 'transaction_type_id', '', 1); ?>
      <a name="show" href="form.php?class_name=wip_wo_completion&<?php echo "mode=$mode"; ?>" class="show2 document_id wip_wo_completion_id">          
       <i class="fa fa-refresh"></i></a> 
     </li>
    </ul>
   </div>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Work Order Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('General Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Transfer Info') ?></a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Reference Info') ?></a></li>
     <li><a href="#tabsLine-4"><?php echo gettext('Finance Info') ?></a></li>
     <li><a href="#tabsLine-5"><?php echo gettext('Lot & Serial') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Item Id') ?></th>
         <th><?php echo gettext('Item Number') ?></th>
         <th><?php echo gettext('Item Description') ?></th>
         <th><?php echo gettext('UOM') ?></th>
         <th><?php echo gettext('Document Qty') ?></th>
         <th><?php echo gettext('Available Qty') ?></th>
         <th><?php echo gettext('Transaction Qty') ?></th>
         <th><?php echo gettext('Transaction Id') ?></th>
        </tr>
       </thead>
       <tbody class="inv_transaction_values">
        <tr class="inv_transaction_row0" id="tab1_1">
         <td>    
          <ul class="inline_action">
           <li class="remove_row_img"><i  class="fa fa-minus-circle" alt="remove this line" ></i></li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->item_id_m); ?>">
            <?php echo form::hidden_field('org_id', $$class->org_id); ?>
            <?php echo form::hidden_field('wip_wo_header_id', $$class->wip_wo_header_id); ?>
            <?php echo form::hidden_field('transaction_type_id', $$class->transaction_type_id); ?></li>  
          </ul>
         </td>
         <td><?php $f->text_field_widr('item_id_m', 'always_readonly'); ?></td>
         <td><?php $f->text_field_widr('item_number', 'always_readonly'); ?></td>
         <td><?php $f->text_field_widr('item_description', 'always_readonly'); ?></td>
         <td><?php echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, '', $readonly); ?></td>
         <td><?php $f->text_field_widr('total_quantity', 'always_readonly'); ?></td>
         <td><?php $f->text_field_widr('available_quantity', 'always_readonly'); ?></td>
         <td><?php form::number_field_widsm('quantity'); ?></td>
         <td><?php $f->text_field_widr('inv_transaction_id', 'always_readonly'); ?></td>
        </tr>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-2" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('From SubInv') ?></th>
         <th><?php echo gettext('From Locator') ?></th>
         <th><?php echo gettext('To SubInv') ?></th>
         <th><?php echo gettext('To Locator') ?></th>
        </tr>
       </thead>
       <tbody class="inv_transaction_values">
        <tr class="inv_transaction_row0" id="tab2_1">
<td><?php echo $f->select_field_from_object('from_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->from_subinventory_id, '', 'subinventory_id large', '', $readonly); ?>  </td>
        <td><?php echo $f->select_field_from_object('from_locator_id', locator::find_all_of_subinventory($$class->from_subinventory_id), 'locator_id', 'locator', $$class->from_locator_id, '', 'from_locator_id large', '', $readonly); ?>        </td>
        <td><?php echo $f->select_field_from_object('to_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->to_subinventory_id, '', 'subinventory_id large', '', $readonly); ?>        </td>
        <td><?php echo $f->select_field_from_object('to_locator_id', locator::find_all_of_subinventory($$class->to_subinventory_id), 'locator_id', 'locator', $$class->to_locator_id, '', 'to_locator_id large', '', $readonly); ?>        </td>
        </tr>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-3" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Document Type') ?></th>
         <th><?php echo gettext('Doc. Number') ?></th>
         <th><?php echo gettext('Doc. Id') ?></th>
         <th><?php echo gettext('Ref Type') ?></th>
         <th><?php echo gettext('Ref Name') ?></th>
         <th><?php echo gettext('Ref Value') ?></th>
         <th><?php echo gettext('Ref Doc') ?></th>
         <th><?php echo gettext('WO BOM Line Id') ?></th>
        </tr>
       </thead>
       <tbody class="inv_transaction_values form_data_line_tbody">
        <tr class="inv_transaction_row0" id="tab3_1">
         <td><?php $f->text_field_widr('document_type'); ?>							</td>
         <td><?php echo $f->text_field('document_number', $$class->wo_number, '8', '', '', 1, 1); ?>							</td>
         <td><?php echo $f->text_field('document_id', $$class->wip_wo_header_id, '8', '', '', 1, 1); ?>							</td>
         <td><?php $f->text_field_widr('reference_type'); ?>							</td>
         <td><?php echo $f->text_field('reference_key_name', 'wip_wo_header', '20', '', '', 1, 1); ?>							</td>
         <td><?php echo $f->text_field('reference_key_value', $$class->wip_wo_header_id, '8', '', '', 1, 1); ?>							</td>
         <td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : ''; ?></td>
         <td><?php $f->text_field_widsr('wip_wo_bom_id'); ?></td>
        </tr>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-4" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Account') ?></th>
         <th><?php echo gettext('Unit Cost') ?></th>
         <th><?php echo gettext('Costed Amount') ?></th>
         <th><?php echo gettext('Journal Id') ?></th>
        </tr>
       </thead>
       <tbody class="inv_transaction_values form_data_line_tbody">
        <tr class="inv_transaction_row0" id="tab4_1">
         <td><?php $f->ac_field_wid('account_id'); ?></td>
         <td><?php form::text_field_wid('unit_cost'); ?></td>
         <td><?php form::text_field_wid('costed_amount'); ?></td>
         <td><?php form::text_field_wid('gl_journal_header_id'); ?></td>
        </tr>
       </tbody>
      </table>
     </div>

     <div id="tabsLine-5" class="tabContent scrollElement">

      <?php
      $ls_trclass = 'inv_transaction_row';
      $line_object_ls = array($$class);
      $each_line_ls = $class;
      $line_class_name_sl = &$class;
      $ref_key_name = 'inv_transaction';
      $ref_key_val = 'inv_transaction_id';
      include_once HOME_DIR . '/includes/template/lot_serial_template.inc'
      ?>
     </div>
    </div>

   </div>
  </div>
 </form>
</div>

<!--                 complete Showing a blank form for new entry-->



<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="wip_wo_completion" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="wip_wo_completion_id" ></li>
  <li class="form_header_id" data-form_header_id="wip_wo_completion" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="inv_transaction_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="5" ></li>
 </ul>
</div>