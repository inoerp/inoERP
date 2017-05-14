<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id="wip_wol_transaction_divId">
 <?php echo (!empty($hidden_stmt)) ? $hidden_stmt : ""; ?>
 <!--    End of place for showing error messages-->


 <!--create empty form or a single id when search is not clicked and the id is referred from other page -->
 <div id ="form_header"> <span class="heading"><?php echo gettext('Work Order Less Transaction') ?></span> 
  <form method="post" id="wip_wol_transaction"  name="wip_wol_transaction">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Others') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <div>
       <ul class="column header_field">
        <li><?php $f->l_text_field_dr_withSearch('wip_wol_transaction_id'); ?>
         <a name="show" href="form.php?class_name=wip_wol_transaction&<?php echo "mode=$mode"; ?>" class="show document_id wip_wol_transaction_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>        </li>
        <li><label><?php echo gettext('Item Number') ?></label><?php echo $f->hidden_field_withId('item_id_m', $$class->item_id_m); ?>
         <?php $f->text_field_dm('item_number', 'select_item_number'); ?>        
        <i class="select_item_number select_popup clickable fa fa-search"></i>
        </li>
        <li><?php $f->l_select_field_from_object('revision_name', $revision_name_a, 'revision_name', 'revision_name', $$class->revision_name, 'revision_name', 'small'); ?>        </li>
        <li><?php $f->l_number_field_d('quantity'); ?></li>
        <li><?php $f->l_select_field_from_array('transaction_type_id', wip_wol_transaction::$transaction_type_id_a, $$class->transaction_type_id, 'transaction_type_id', '', 1); ?>
         <a name="show" href="form.php?class_name=wip_wol_transaction&<?php echo "mode=$mode"; ?>" class="show2 document_id wip_wol_transaction_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><?php $f->l_text_field_d('description'); ?></li>
        <li><?php $f->l_select_field_from_object('wip_accounting_group_id', wip_accounting_group::find_by_orgId($$class->org_id), 'wip_accounting_group_id', 'wip_accounting_group', $$class->wip_accounting_group_id, 'wip_accounting_group_id', '', 1, 'readonly1'); ?>
        <li><?php $f->l_select_field_from_object('completion_sub_inventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->completion_sub_inventory, '', 'subinventory_id', '', $readonly); ?>        </li>
        <li><?php $f->l_select_field_from_object('completion_locator', locator::find_all_of_subinventory($$class->completion_sub_inventory), 'locator_id', 'locator', $$class->completion_locator, '', 'locator_id', '', $readonly); ?>        </li>
        <li><?php $f->l_date_fieldFromToday('completion_date', $$class->completion_date) ?></li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'wip_wol_transaction';
        $reference_id = $$class->wip_wol_transaction_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
    </div>
   </div>
  </form>
 </div>

 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('WOL Transaction Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('General Info') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Transfer Info') ?></a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Reference Info') ?></a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Lot & Serial') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <form action=""  method="post" id="wip_wol_transaction_line"  name="wip_wol_transaction_line">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('BOM Seq') ?></th>
         <th><?php echo gettext('Item Id') ?></th>
         <th><?php echo gettext('Item Number') ?></th>
         <th><?php echo gettext('Item Description') ?></th>
         <th><?php echo gettext('UOM') ?></th>
         <th><?php echo gettext('Quantity') ?></th>
        </tr>
       </thead>
       <tbody class="wip_wol_transaction_values form_data_line_tbody">
        <?php
        $count = 0;
        foreach ($wip_wo_bom_object as $wip_wo_bom) {
         if ($wip_wo_bom->component_item_id_m) {
          $item_i = item::find_by_id($wip_wo_bom->component_item_id_m);
         } else {
          $item_i = new item();
         }
         ?> 
         <tr class="wip_wol_transaction_line<?php echo $count ?>">
          <td><?php
           echo ino_inline_action($$class->bom_sequence, array('transaction_type_id' => $$class->transaction_type_id,
            'wip_wol_transaction_id' => $$class->wip_wol_transaction_id, 'org_id' => $$class->org_id));
           ?></td>
          <td><?php echo!empty($bom_sequence_stament) ? $bom_sequence_stament : form::text_field_wids('bom_sequence'); ?></td>
          <td><?php echo $f->text_field('item_id_m', $wip_wo_bom->component_item_id_m, '', '', 'item_id_m', '', 1); ?></td>
          <td><?php echo $f->text_field('component_item_number', $item_i->item_number, '20', '', 'select_item_number', '', $readonly); ?>
           <i class="select_item_number select_popup clickable fa fa-search"></i></td>
          <td><?php echo $f->text_field('component_description', $item_i->item_description, '20', '', 'item_description', '', $readonly); ?></td>
          <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $item_i->uom_id, '', 'uom_id', '', $readonly); ?></td>
          <td><?php
           echo $f->number_field('quantity', $wip_wo_bom->usage_quantity, '', '', 'final_quantity', 1);
           echo $f->hidden_field('usage_quantity', $wip_wo_bom->usage_quantity);
           ?></td>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </div>
     <div id = "tabsLine-2" class = "tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('On Hand') ?></th>
         <th><?php echo gettext('Supply Type') ?></th>
         <th><?php echo gettext('Subinventory') ?></th>
         <th><?php echo gettext('Locator') ?></th>
        </tr>
       </thead>
       <tbody class="wip_wol_transaction_values form_data_line_tbody" >
        <?php
        $count = 0;
        foreach ($wip_wo_bom_object as $wip_wo_bom) {
//         $wip_wo_bom->open_quantity = $wip_wo_bom->required_quantity - $wip_wo_bom->issued_quantity;
         ?>         
         <tr  class="wip_wol_transaction_line<?php echo $count ?>">
          <td></td>
          <td><?php echo $f->select_field_from_object('wip_supply_type', bom_header::wip_supply_type(), 'option_line_code', 'option_line_value', $wip_wo_bom->wip_supply_type, '', 'wip_supply_type', '', $readonly); ?></td>
          <td><?php echo $f->select_field_from_object('supply_sub_inventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $wip_wo_bom->supply_sub_inventory, '', 'subinventory_id', '', $readonly); ?></td>
          <td><?php echo $f->select_field_from_object('supply_locator', locator::find_all_of_subinventory($wip_wo_bom->supply_sub_inventory), 'locator_id', 'locator', $wip_wo_bom->supply_locator, '', 'locator_id', '', $readonly); ?></td>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-3" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Document Type') ?></th>
         <th><?php echo gettext('Doc. Id') ?></th>
         <th><?php echo gettext('Ref Type') ?></th>
         <th><?php echo gettext('Ref Name') ?></th>
         <th><?php echo gettext('Ref Value') ?></th>
         <th><?php echo gettext('Ref Doc') ?></th>
        </tr>
       </thead>
       <tbody class="wip_wol_transaction_values form_data_line_tbody" >
        <?php
        $count = 0;
        foreach ($wip_wo_bom_object as $wip_wo_bom) {
//         $wip_wo_bom->open_quantity = $wip_wo_bom->required_quantity - $wip_wo_bom->issued_quantity;
         ?>         
         <tr  class="wip_wol_transaction_line<?php echo $count ?>">
          <td><?php $f->text_field_widr('document_type'); ?>							</td>
          <td><?php echo $f->text_field('document_id', $$class->wip_wol_transaction_id, '8'); ?>							</td>
          <td><?php $f->text_field_widr('reference_type'); ?>							</td>
          <td><?php echo $f->text_field('reference_key_name', 'wip_wol_transaction', '20', '', '', 1, 1); ?>							</td>
          <td><?php echo $f->text_field('reference_key_value', $$class->wip_wol_transaction_id, '8', '', 'wip_wol_transaction_id', 1, 1); ?>							</td>
          <td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : ''; ?></td>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-4" class="tabContent scrollElement">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Add Lot Numbers') ?></th>
         <th><?php echo gettext('Add Serial Numbers') ?></th>
        </tr>
       </thead>
       <tbody class="wip_wol_transaction_values form_data_line_tbody" >
        <?php
        $count = 0;
        foreach ($wip_wo_bom_object as $wip_wo_bom) {
//         $wip_wo_bom->open_quantity = $wip_wo_bom->required_quantity - $wip_wo_bom->issued_quantity;
         ?>         
         <tr  class="wip_wol_transaction_line<?php echo $count ?>">
          <td class="add_detail_values0">	<?php
           echo!empty($$class_second->lot_number_id) ? $f->hidden_field('lot_number_id', $$class_second->lot_number_id) : $f->hidden_field('lot_number_id', '');
           echo!empty($$class_second->lot_generation) ? $f->hidden_field('lot_generation', $$class_second->lot_generation) : $f->hidden_field('lot_generation', '');
           ?> 
           <img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
           <div class="class_detail_form">
            <fieldset class="form_detail_data_fs"><legend><?php echo gettext('Lot') ?></legend>
             <div class="tabsDetail">
              <ul class="tabMain">
               <li class="tabLink"><a href="#tabsDetail-1-1"> <?php echo gettext('Numbers') ?></a></li>
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
                  if (!empty($inv_trnx->inv_transaction_id)) {
                   $lot_object = [];
//                         pa($inv_trnx);
                   $lot_trnxs = inv_lot_transaction::find_by_invTransactionId($inv_trnx->inv_transaction_id);
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
                     </ul>
                    </td>
                    <td><?php
                     echo $f->text_field('lot_number', $lot_no->lot_number, '25');
                     echo!empty($$class_second->lot_generation) ? $f->hidden_field('lot_generation', $$class_second->lot_generation) : null;
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
           echo!empty($$class_second->serial_number_id) ? $f->hidden_field('serial_number_id', $$class_second->serial_number_id) : $f->hidden_field('serial_number_id', '');
           echo!empty($$class_second->serial_generation) ? $f->hidden_field('serial_generation', $$class_second->serial_generation) : $f->hidden_field('serial_generation', '');
           ?>
           <img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
           <div class="class_detail_form">
            <fieldset class="form_detail_data_fs"><legend><?php echo gettext('Serial') ?></legend>
             <div class="tabsDetail">
              <ul class="tabMain">
               <li class="tabLink"><a href="#tabsDetail-2-1"> <?php echo gettext('Numbers') ?></a></li>
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
                 <tbody class="form_data_detail_tbody">
                  <?php
                  $detailCount = 0;
                  if (!empty($$class_second->inv_transaction_id)) {
                   $serial_object = [];
                   $serial_trnxs = inv_serial_transaction::find_by_invTransactionId($$class_second->inv_transaction_id);
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
                     </ul>
                    </td>
                    <td><?php
                     echo $f->text_field('serial_number', $serial_no->serial_number, '25');
                     echo!empty($$class_second->serial_generation) ? $f->hidden_field('serial_generation', $$class_second->serial_generation) : $f->hidden_field('serial_generation', '');
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
          <?php
          $count = $count + 1;
         }
         ?>
       </tbody>
      </table>
     </div>
    </form>
   </div>

  </div>
 </div>


</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="wip_wol_transaction" ></li>
  <li class="lineClassName" data-lineClassName="wip_wol_transaction_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="allLineTogether" data-allLineTogether="true" ></li>
  <li class="primary_column_id" data-primary_column_id="wip_wol_transaction_id" ></li>
  <li class="form_header_id" data-form_header_id="wip_wol_transaction" ></li>
  <li class="line_key_field" data-line_key_field="item_id_m" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="wip_wol_transaction_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="wip_wol_transaction_id" ></li>
  <li class="docLineId" data-docLineId="inv_transaction_id" ></li>
  <li class="btn1DivId" data-btn1DivId="wip_wol_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trClass="wip_wol_transaction" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="4" ></li>
 </ul>
</div>
