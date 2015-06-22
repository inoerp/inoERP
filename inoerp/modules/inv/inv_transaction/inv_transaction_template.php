<form action=""  method="post" id="inv_transaction"  name="inv_transaction">
 <?php echo (!empty($hidden_stmt)) ? $hidden_stmt : ""; ?> 
 <!--create empty form or a single id when search is not clicked and the id is referred from other page -->
 <span class="heading"><?php   echo gettext('Inventory Transaction ')   ?></span> 
 <div class='tabContainer'>
  <ul class='column header_field'>
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

 <div id ="form_line" class="form_line"><span class="heading">Transaction Details </span>
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
        <td>
         <?php echo $f->text_field_dsr('inv_transaction_id', 'lineId'); ?>
        </td>
        <td><?php $f->text_field_widsr('item_id_m'); ?></td>
        <td><?php $f->text_field_widm('item_number', 'select_item_number'); ?>
         <i class="select_item_number select_popup clickable fa fa-search"></i></td>
        <td><?php $f->text_field_widsr('revision_name'); ?></td>
        <td><?php $f->text_field_wid('item_description'); ?></td>
        <td>
         <?php echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, 'uom_id', $readonly); ?>
        </td>
        <td><?php form::text_field_widsm('quantity'); ?></td>
        <td><?php echo $f->checkBox_field('kit_cb', $$class->kit_cb, '', 'dontCopy'); ?></td>
        <td> <a class="popup popup-form view-item-config medium" href="form.php?class_name=bom_config_header&mode=9&window_type=popup"> <i class="fa fa-edit"></i></a></td>
        <td><?php $f->text_field_widsr('bom_config_header_id'); ?></td>
       </tr>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="tabContent">
     <table class="form_line_data_table">
      <thead>
      <th><?php echo gettext('From SubInv') ?></th>
      <th><?php echo gettext('From Locator') ?></th>
      <th><?php echo gettext('To SubInv') ?></th>
      <th><?php echo gettext('To Locator') ?></th>
      <th><?php echo gettext('Description') ?></th>
      <th><?php echo gettext('Reason') ?></th>
      </thead>
      <tbody class="form_data_line_tbody">
       <tr class="inv_transaction_line0" id="tab2_1">
        <td>
         <?php echo $f->select_field_from_object('from_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->from_subinventory_id, '', 'subinventory_id', '', $readonly); ?>
        </td>
        <td>
         <?php echo $f->select_field_from_object('from_locator_id', locator::find_all_of_subinventory($$class->from_subinventory_id), 'locator_id', 'locator', $$class->from_locator_id, '', 'from_locator_id', '', $readonly); ?>
        </td>
        <td>
         <?php echo $f->select_field_from_object('to_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->to_subinventory_id, '', 'subinventory_id', '', $readonly); ?>
        </td>
        <td>
         <?php echo $f->select_field_from_object('to_locator_id', locator::find_all_of_subinventory($$class->to_subinventory_id), 'locator_id', 'locator', $$class->to_locator_id, '', 'to_locator_id', '', $readonly); ?>
        </td>
        <td><?php form::text_field_wid('description'); ?>							</td>
        <td><?php form::text_field_wid('reason'); ?>							</td>
       </tr>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-3" class="tabContent">
     <table class="form_line_data_table">
      <thead>
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
      </thead>
      <tbody class="form_data_line_tbody">
       <tr class="inv_transaction_line0" id="tab3_1">
        <td><?php form::text_field_wids('document_type'); ?>							</td>
        <td><?php form::text_field_wid('document_number'); ?> 							</td>
        <td><?php form::text_field_wids('document_id'); ?>							</td>
        <td><?php form::text_field_wids('reference_type'); ?>							</td>
        <td><?php form::text_field_wid('reference_key_name'); ?>							</td>
        <td><?php form::text_field_wid('reference_key_value'); ?>							</td>
        <td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : ''; ?></td>
        <td><?php form::text_field_wids('wip_wo_bom_id'); ?>							</td>
        <td><?php form::text_field_wids('po_detail_id'); ?>							</td>
        <td><?php form::text_field_wids('sd_so_line_id'); ?>							</td>
       </tr>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-4" class="tabContent">
     <table class="form_line_data_table">
      <thead>
      <th><?php echo gettext('Account') ?></th>
      <th><?php echo gettext('Unit Cost') ?></th>
      <th><?php echo gettext('Costed Amount') ?></th>
      <th><?php echo gettext('Journal Header Id') ?></th>
      </thead>
      <tbody class="form_data_line_tbody">
       <tr class="inv_transaction_line0" id="tab4_1">
        <td><?php $f->ac_field_widm('account_id'); ?></td>
        <td><?php form::text_field_wid('unit_cost'); ?></td>
        <td><?php form::text_field_wid('costed_amount'); ?></td>
        <td><?php form::text_field_wid('gl_journal_header_id'); ?></td>
       </tr>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-5" class="tabContent scrollElement">
     <table class="form_line_data_table">
      <thead>
      <th><?php echo gettext('Add Lot Numbers') ?></th>
      <th><?php echo gettext('Add Serial Numbers') ?></th>
      </thead>
      <tbody class="form_data_line_tbody">
       <tr class="inv_transaction_line0" id="tab4_1">
        <td class="add_detail_values0">	<?php
         echo $f->hidden_field('lot_number_id', $$class->lot_number_id);
         echo $f->hidden_field('lot_generation', $$class->lot_generation);
         ?> 
         <img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
         <div class="class_detail_form">
          <fieldset class="form_detail_data_fs"><legend>lot</legend>
           <div class="tabsDetail">
            <ul class="tabMain">
             <li class="tabLink"><a href="#tabsDetail-1-1"> Numbers</a></li>
            </ul>
            <div class="tabContainer">
             <div id="tabsDetail-1-1" class="tabContent">
              <table class="form form_detail_data_table detail">
               <thead>
                <tr>
                 <th><?php echo gettext('Action') ?></th>
                 <th><?php echo gettext('Lot Number') ?></th>
                 <th><?php echo gettext('Quantity') ?></th>
                </tr>
               </thead>
               <tbody class="form_data_detail_tbody_ln">
                <?php
                $detailCount = 0;
                if (!empty($$class->inv_transaction_id)) {
                 $lot_object = [];
                 $lot_trnxs = inv_lot_transaction::find_by_invTransactionId($$class->inv_transaction_id);
                 if (!empty($lot_trnxs)) {
                  foreach ($lot_trnxs as $lot_trnx) {
                   $lot_no = new inv_lot_number();
                   $lot_no->findBy_id($lot_trnx->inv_lot_number_id);
                   $lot_no->lot_quantity = $lot_trnx->lot_quantity;
                   array_push($lot_object, $lot_no);
                  }
                 }
                }
                if (empty($lot_object)) {
                 $lot_object = array(new inv_lot_number());
                }
                foreach ($lot_object as $lot_no) {
                 ?>
                 <tr class="inv_lot_number<?php echo $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
                  <td>   
                   <ul class="inline_action">
                    <li class="add_row_detail_img1"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                    <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                    <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($lot_no->inv_lot_number_id); ?>"></li>           
                    <li><?php echo form::hidden_field('inv_transaction_id', $$class->inv_transaction_id); ?></li>
                   </ul>
                  </td>
                  <td><?php
                   echo $f->text_field('lot_number', $lot_no->lot_number, '25');
                   echo $f->hidden_field('lot_generation', $$class->lot_generation);
                   ?>
                  </td>
                  <td><?php echo $f->number_field('lot_quantity', $lot_no->lot_quantity, '25'); ?>
                  </td>
                 </tr>
                 <?php
                 $detailCount++;
                }
                ?>
               </tbody>
              </table>
             </div>
            </div>
           </div>


          </fieldset>

         </div>
        </td>
        <td class="add_detail_values1">
         <?php
         echo $f->hidden_field('serial_number_id', $$class->serial_number_id);
         echo $f->hidden_field('serial_generation', $$class->serial_generation);
         ?>
         <img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
         <div class="class_detail_form">
          <fieldset class="form_detail_data_fs"><legend>Serial</legend>
           <div class="tabsDetail">
            <ul class="tabMain">
             <li class="tabLink"><a href="#tabsDetail-2-1"> Numbers</a></li>
            </ul>
            <div class="tabContainer">
             <div id="tabsDetail-2-1" class="tabContent">
              <table class="form form_detail_data_table detail">
               <thead>
                <tr>
                 <th><?php echo gettext('Action') ?></th>
                 <th><?php echo gettext('Serial Number') ?></th>
                </tr>
               </thead>
               <tbody class="form_data_detail_tbody_sn">
                <?php
                $detailCount = 0;
                if (!empty($$class->inv_transaction_id)) {
                 $serial_object = [];
                 $serial_trnxs = inv_serial_transaction::find_by_invTransactionId($$class->inv_transaction_id);
                 if (!empty($serial_trnxs)) {
                  foreach ($serial_trnxs as $serial_trnx) {
                   $serial_no = new inv_serial_number();
                   $serial_no->findBy_id($serial_trnx->inv_serial_number_id);
                   array_push($serial_object, $serial_no);
                  }
                 }
                }
                if (empty($serial_object)) {
                 $serial_object = array(new inv_serial_number());
                }
                foreach ($serial_object as $serial_no) {
                 ?>
                 <tr class="inv_serial_number<?php echo $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
                  <td>   
                   <ul class="inline_action">
                    <li class="add_row_detail_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                    <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                    <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($serial_no->inv_serial_number_id); ?>"></li>           
                    <li><?php echo form::hidden_field('inv_transaction_id', $$class->inv_transaction_id); ?></li>
                   </ul>
                  </td>
                  <td><?php
                   echo $f->text_field('serial_number', $serial_no->serial_number, '25');
                   echo $f->hidden_field('serial_generation', $$class->serial_generation);
                   ?>
                  </td>

                 </tr>
                 <?php
                 $detailCount++;
                }
                ?>
               </tbody>
              </table>
             </div>
            </div>
           </div>


          </fieldset>

         </div>

        </td>
       </tr>
      </tbody>
     </table>
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

