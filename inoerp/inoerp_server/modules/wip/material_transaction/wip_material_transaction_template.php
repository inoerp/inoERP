<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id="wip_material_transaction_divId">
 <?php echo (!empty($hidden_stmt)) ? $hidden_stmt : ""; ?> 
 <!--    End of place for showing error messages-->


 <!--create empty form or a single id when search is not clicked and the id is referred from other page -->
 <div id ="form_header"><span class="heading"><?php echo gettext('WIP Material Transaction') ?></span> 
  <div id="form_serach_header" class="tabContainer">
   <div class="tabContent">
    <ul class="column header_field">
     <li><?php
      $f->l_val_field_d('wo_number', 'wip_wo_header', 'wo_number', 'org_id', '');
      echo $f->hidden_field_withId('wip_wo_header_id', $$class->wip_wo_header_id);
      echo $f->hidden_field_withCLass('wo_status', 'RELEASED', 'popup_value');
      ?>
      <i class="generic g_select_wo_number select_popup clickable fa fa-search" data-class_name="wip_wo_header"></i>
     </li>
     <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>    </li>
     <li><?php $f->l_select_field_from_array('transaction_type_id', wip_material_transaction::$transaction_type_id_a, $$class->transaction_type_id, 'transaction_type_id', '', 1); ?>
      <a name="show" href="form.php?class_name=wip_material_transaction&<?php echo "mode=$mode"; ?>" class="show2 document_id wip_material_transaction_id">          
       <i class="fa fa-refresh"></i></a> 
     </li>
    </ul>
   </div>
  </div>
 </div>
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Transaction Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('General Info') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Transfer Info') ?></a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Reference Info') ?></a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Finance Info') ?></a></li>
    <li><a href="#tabsLine-5"><?php echo gettext('Lot & Serial') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <form action=""  method="post" id="wip_material_transaction"  name="wip_material_transaction">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('BOM Seq') ?></th>
         <th><?php echo gettext('BOM Id') ?></th>
         <th><?php echo gettext('Item Id') ?></th>
         <th><?php echo gettext('Item Number') ?></th>
         <th><?php echo gettext('Item Description') ?></th>
         <th><?php echo gettext('UOM') ?></th>
         <th><?php echo gettext('Quantity') ?></th>
         <th><?php echo gettext('Transaction Id') ?></th>
        </tr>
       </thead>
       <tbody class="inv_transaction_values form_data_line_tbody">
        <tr class="wip_material_transaction0" id="tab1_1">
         <td>
          <?php
          echo ino_inline_action($$class->bom_sequence, array('org_id' => $$class->org_id,
           'wip_wo_header_id' => $$class->wip_wo_header_id, 'transaction_type_id' => $$class->transaction_type_id));
          ?>
         </td>
         <td><?php echo!empty($bom_sequence_stament) ? $bom_sequence_stament : form::text_field_wids('bom_sequence'); ?></td>
         <td><?php form::text_field_widsm('wip_wo_bom_id'); ?></td>
         <td><?php $f->text_field_widrm('item_id_m'); ?></td>
         <td><?php form::text_field_drm('item_number'); ?></td>
         <td><?php form::text_field_dr('item_description'); ?></td>
         <td><?php echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, '', $readonly); ?></td>
         <td><?php form::text_field_widsm('quantity'); ?></td>
         <td><?php echo form::text_field_dsr('inv_transaction_id'); ?></td>
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
       <tbody class="inv_transaction_values form_data_line_tbody">
        <tr class="wip_material_transaction0" id="tab2_1">
         <td><?php echo $f->select_field_from_object('from_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->from_subinventory_id, '', 'subinventory_id medium', '', $readonly); ?>  </td>
         <td><?php echo $f->select_field_from_object('from_locator_id', locator::find_all_of_subinventory($$class->from_subinventory_id), 'locator_id', 'locator', $$class->from_locator_id, '', 'from_locator_id medium', '', $readonly); ?>        </td>
         <td><?php echo $f->select_field_from_object('to_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->to_subinventory_id, '', 'subinventory_id medium', '', $readonly); ?>       </td>
         <td><?php echo $f->select_field_from_object('to_locator_id', locator::find_all_of_subinventory($$class->to_subinventory_id), 'locator_id', 'locator', $$class->to_locator_id, '', 'to_locator_id medium', '', $readonly); ?>        </td>
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
        <tr class="wip_material_transaction0" id="tab3_1">
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
        <tr class="wip_material_transaction0" id="tab4_1">
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
      $ls_trclass = 'wip_material_transaction';
      $line_object_ls = array($$class);
      $each_line_ls = $class;
      $line_class_name_sl = &$class;
      $ref_key_name = 'inv_transaction';
      $ref_key_val = 'inv_transaction_id';
      include_once HOME_DIR . '/includes/template/lot_serial_template.inc'
      ?>
     </div>
    </form>
   </div>

  </div>
 </div>
 <!--                 complete Showing a blank form for new entry-->


</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="wip_material_transaction" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="line_key_field" data-line_key_field="item_id_m" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="wip_material_transaction" ></li>
  <li class="before_save_function" data-before_save_function="beforeSave" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="inv_transaction_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="5" ></li>
 </ul>
</div>