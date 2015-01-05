<div id="wip_wol_transaction_divId">
 <?php echo (!empty($hidden_stmt)) ? $hidden_stmt : ""; ?> 
 <!--    End of place for showing error messages-->


 <!--create empty form or a single id when search is not clicked and the id is referred from other page -->
 <div id ="form_header"> <span class="heading">Work Order Less Transaction </span> 
  <div id="form_serach_header"><ul class="inline_list">
    <li><label>Inventory Org : </label>
     <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>
    </li>
    <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup clickable">
      Item Number(2) : </label> 
     <?php echo $f->hidden_field_withId('item_id_m', $$class->item_id_m); ?>
     <?php $f->text_field_dm('item_number', 'select_item_number'); ?>
    </li>
    <li><label>Revision</label>
     <?php echo $f->select_field_from_object('revision_name', $revision_name_a, 'revision_name', 'revision_name', $$class->revision_name, 'revision_name', 'small'); ?>
    </li>
    <li><label>Transaction Type : </label>
     <?php echo $f->select_field_from_array('transaction_type_id', wip_wol_transaction::$transaction_type_id_a, $$class->transaction_type_id, 'transaction_type_id', '', 1); ?>
     <a name="show" href="form.php?class_name=wip_wol_transaction&<?php echo "mode=$mode"; ?>" class="show2 document_id wip_wol_transaction_id">          <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
    </li>
   </ul>
  </div>
 </div>
 <div id ="form_line" class="form_line"><span class="heading">Transaction Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">General Info</a></li>
    <li><a href="#tabsLine-2">Transfer Info</a></li>
    <li><a href="#tabsLine-3">Reference Info</a></li>
    <li><a href="#tabsLine-4">Finance Info</a></li>
    <li><a href="#tabsLine-5">Lot & Serial </a></li>
   </ul>
   <div class="tabContainer"> 
    <form action=""  method="post" id="wip_wol_transaction"  name="wip_wol_transaction">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th>Action</th>
         <th>BOM Seq</th>
         <th>BOM Id</th>
         <th>Item Id</th>
         <th>Item Number</th>
         <th>Item Description</th>
         <th>UOM</th>
         <th>Quantity</th>
         <th>Transaction Id</th>
        </tr>
       </thead>
       <tbody class="inv_transaction_values form_data_line_tbody">
        <tr class="wip_wol_transaction0" id="tab1_1">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo!empty($$class_second->bom_sequence) ? $$class_second->bom_sequence : '' ?>">
            <?php echo form::hidden_field('org_id', $$class->org_id); ?>
            <?php echo form::hidden_field('wip_wo_header_id', $$class->wip_wo_header_id); ?>
            <?php echo form::hidden_field('transaction_type_id', $$class->transaction_type_id); ?></li>           
          </ul>
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
         <th>From SubInv</th>
         <th>From Locator </th>
         <th>To SubInv</th>
         <th>To Locator</th>
         <th>Ef Id</th>
        </tr>
       </thead>
       <tbody class="inv_transaction_values form_data_line_tbody">
        <tr class="wip_wol_transaction0" id="tab2_1">
         <td>
          <?php echo form::select_field_from_object('from_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->from_subinventory_id, '', $readonly, 'subinventory_id'); ?>
         </td>
         <td>
          <?php echo form::select_field_from_object('from_locator_id', locator::find_all_of_subinventory($$class->from_subinventory_id), 'locator_id', 'locator', $$class->from_locator_id, '', $readonly, 'subinventory_id'); ?>
         </td>
         <td>
          <?php echo form::select_field_from_object('to_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->to_subinventory_id, '', $readonly, 'subinventory_id'); ?>
         </td>
         <td>
          <?php echo form::select_field_from_object('to_locator_id', locator::find_all_of_subinventory($$class->to_subinventory_id), 'locator_id', 'locator', $$class->to_locator_id, '', $readonly, 'subinventory_id'); ?>
         </td>
         <td>
          <?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
         </td>
        </tr>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-3" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th>Document Type</th>
         <th>Doc. Number</th>
         <th>Doc. Id</th>
         <th>Ref Type</th>
         <th>Ref Name</th>
         <th>Ref Value</th>
         <th>Ref Doc</th>
         <th>WO BOM Line Id</th>
        </tr>
       </thead>
       <tbody class="inv_transaction_values form_data_line_tbody">
        <tr class="wip_wol_transaction0" id="tab3_1">
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
         <th>Account</th>
         <th>Unit Cost</th>
         <th>Costed Amount</th>
         <th>Journal Id<th>
        </tr>
       </thead>
       <tbody class="inv_transaction_values form_data_line_tbody">
        <tr class="wip_wol_transaction0" id="tab4_1">
         <td><?php $f->ac_field_wid('account_id'); ?></td>
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
        <tr>
         <th>Lot</th>
         <th>Add Serial Numbers</th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <tr class="wip_wol_transaction0" id="tab4_1">
         <td class="add_detail_values0">	<?php
          echo!empty($$class->lot_number_id) ? $f->hidden_field('lot_number_id', $$class->lot_number_id) : $f->hidden_field('lot_number_id', '');
          echo!empty($$class->lot_generation) ? $f->hidden_field('lot_generation', $$class->lot_generation) : $f->hidden_field('lot_generation', '');
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
                  <th>Action</th>
                  <th>Lot Number</th>
                  <th>Quantity</th>
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
                    echo!empty($$class_second->lot_generation) ? $f->hidden_field('lot_generation', $$class->lot_generation) : null;
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
                  <th>Action</th>
                  <th>Serial Number</th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
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
    </form>
   </div>

  </div>
 </div>
 <!--                 complete Showing a blank form for new entry-->


</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="wip_wol_transaction" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="line_key_field" data-line_key_field="item_id_m" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="wip_wol_transaction" ></li>
  <li class="before_save_function" data-before_save_function="beforeSave" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="inv_transaction_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="5" ></li>
 </ul>
</div>
