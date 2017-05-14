<form method="post" id="inv_transaction"  name="inv_transaction">
 <?php  echo (!empty($hidden_stmt)) ? $hidden_stmt : "";  ?> 
 <div id ="form_header"><span class="heading"><?php echo gettext('Inventory Transaction') ?> </span> 
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field"> 
      <li>
       <?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>  </li>
      <li>
       <?php
       echo!(empty($id_array)) ? $f->l_select_field_from_object('transaction_type_id', transaction_type::find_some_byIdArray($id_array), 'transaction_type_id', 'transaction_type', $$class->transaction_type_id, 'transaction_type_id', '', 1, $readonly1) :
        $f->l_select_field_from_object('transaction_type_id', transaction_type::find_all(), 'transaction_type_id', 'transaction_type', $$class->transaction_type_id, 'transaction_type_id', '', 1, $readonly1);
       ?>
      </li>
     </ul>
    </div>
   </div>

  </div>
 </div>


 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Transaction Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('General Info') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Transfer') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Reference') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsLine-5"><?php echo gettext('Lot & Serial') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Transaction Id') ?></th>
        <th><?php echo gettext('Item Id') ?></th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Revision') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Kit Item') ?></th>
        <th><?php echo gettext('Kit Config') ?></th>
        <th><?php echo gettext('Config Id') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <tr class="inv_transaction_line0" id="tab1_1">
        <td>
         <?php
         echo ino_inline_action($$class->inv_transaction_id, array('org_id' => $$class->org_id,
          'transaction_type_id' => $$class->transaction_type_id));
         ?>
        </td>
        <td><?php $f->seq_field_d(99); ?></td>
        <td><?php echo $f->text_field_widsr('inv_transaction_id', 'lineId line_id'); ?></td>
        <td><?php $f->text_field_widsr('item_id_m'); ?></td>
        <td><?php
         $f->val_field_widm('item_number', 'item', 'item_number', '', 'vf_select_item_number');
         echo $f->hidden_field_withCLass('transactable_cb', '1', 'popup_value');
         ?>
         <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
        <td><?php $f->text_field_widsr('revision_name'); ?></td>
        <td><?php $f->text_field_wid('item_description'); ?></td>
        <td>
         <?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, ' ', 'uom_id medium', 1, 1); ?>
        </td>
        <td><?php form::text_field_widsm('quantity'); ?></td>
        <td><?php echo $f->checkBox_field('kit_cb', $$class->kit_cb, '', 'dontCopy '); ?></td>
        <td><a class="popup popup-form view-item-config medium" href="form.php?class_name=bom_config_header&mode=9&window_type=popup"> <i class="fa fa-edit medium"></i></a></td>
        <td><?php $f->text_field_widr('bom_config_header_id'); ?></td>
       </tr>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="tabContent">
     <table class="form_line_data_table">
      <thead>
       <th><?php echo gettext('Seq') ?>#</th>
      <th><?php echo gettext('From SubInv') ?></th>
      <th><?php echo gettext('From Locator') ?></th>
      <th><?php echo gettext('To SubInv') ?></th>
      <th><?php echo gettext('To Locator') ?></th>
      <th><?php echo gettext('Description') ?></th>
      <th><?php echo gettext('Reason') ?></th>
      <th><?php echo gettext('On Hand') ?></th>
      <th><?php echo gettext('Res. On Hand') ?></th>

      </thead>
      <tbody class="form_data_line_tbody">
       <tr class="inv_transaction_line0" id="tab2_1">
        <td><?php $f->seq_field_d(99); ?></td>
        <td><?php echo $f->select_field_from_object('from_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->from_subinventory_id, '', 'subinventory_id medium', '', $readonly); ?>  </td>
        <td><?php echo $f->select_field_from_object('from_locator_id', locator::find_all_of_subinventory($$class->from_subinventory_id), 'locator_id', 'locator', $$class->from_locator_id, '', 'from_locator_id medium', '', $readonly); ?>        </td>
        <td><?php echo $f->select_field_from_object('to_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->to_subinventory_id, '', 'subinventory_id medium', '', $readonly); ?>        </td>
        <td><?php echo $f->select_field_from_object('to_locator_id', locator::find_all_of_subinventory($$class->to_subinventory_id), 'locator_id', 'locator', $$class->to_locator_id, '', 'to_locator_id medium', '', $readonly); ?>        </td>
        <td><?php form::text_field_wid('description'); ?>							</td>
        <td><?php form::text_field_wid('reason'); ?>							</td>
        <td><?php echo $f->text_field_widr('onhand', 'always_readonly'); ?></td>
        <td><?php echo $f->text_field_widr('reservable_onhand', 'always_readonly'); ?></td>

       </tr>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-3" class="tabContent">
     <table class="form_line_data_table">
      <thead>
       <th><?php echo gettext('Seq') ?>#</th>
      <th><?php echo gettext('Document Type') ?></th>
      <th><?php echo gettext('Doc. Number') ?></th>
      <th><?php echo gettext('Doc. Id') ?></th>
      <th><?php echo gettext('Ref Type') ?></th>
      <th><?php echo gettext('Ref Name') ?></th>
      <th><?php echo gettext('Ref Value') ?></th>
      <th><?php echo gettext('Ref Doc') ?></th>
      <th><?php echo gettext('WO BOM Line Id') ?></th>
      <th><?php echo gettext('PO Detail Id') ?></th>
      <th><?php echo gettext('SO Line Id') ?></th>
      <th><?php echo gettext('IR Detail Id') ?></th>
      </thead>
      <tbody class="form_data_line_tbody">
       <tr class="inv_transaction_line0" id="tab3_1">
        <td><?php $f->seq_field_d(99); ?></td>
        <td><?php form::text_field_wids('document_type'); ?>							</td>
        <td><?php form::text_field_wid('document_number'); ?> 							</td>
        <td><?php form::text_field_wids('document_id'); ?>							</td>
        <td><?php form::text_field_wids('reference_type'); ?>							</td>
        <td><?php form::text_field_wid('reference_key_name'); ?>							</td>
        <td><?php form::text_field_wid('reference_key_value'); ?>							</td>
        <td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : ''; ?></td>
        <td><?php form::text_field_wids('wip_wo_bom_id'); ?>							</td>
        <td><?php form::text_field_wid('po_detail_id'); ?>							</td>
        <td><?php form::text_field_wid('sd_so_line_id'); ?>							</td>
        <td><?php form::text_field_wid('po_requisition_detail_id'); ?>							</td>
       </tr>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-4" class="tabContent">
     <table class="form_line_data_table">
      <thead>
       <th><?php echo gettext('Seq') ?>#</th>
      <th><?php echo gettext('Account') ?></th>
      <th><?php echo gettext('Unit Cost') ?></th>
      <th><?php echo gettext('Costed Amount') ?></th>
      <th><?php echo gettext('Journal Header Id') ?></th>
      </thead>
      <tbody class="form_data_line_tbody">
       <tr class="inv_transaction_line0" id="tab4_1">
        <td><?php $f->seq_field_d(99); ?></td>
        <td><?php $f->ac_field_widm('account_id'); ?></td>
        <td><?php form::text_field_wid('unit_cost'); ?></td>
        <td><?php form::text_field_wid('costed_amount'); ?></td>
        <td><?php form::text_field_wid('gl_journal_header_id'); ?></td>
       </tr>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-5" class="tabContent scrollElement">
     <?php
     $ls_trclass = 'inv_transaction_line';
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
 <!--                 complete Showing a blank form for new entry-->
</form>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="inv_transaction" ></li>
  <li class="lineClassName" data-lineClassName="inv_transaction" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="line_key_field" data-line_key_field="item_id_m" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="before_save_function" data-before_save_function="beforeSave" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="inv_transaction_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="5" ></li>
 </ul>
</div>

