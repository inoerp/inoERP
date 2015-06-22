<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="inv_transaction_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <div class="show_loading_small"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <?php echo (!empty($hidden_stmt)) ? $hidden_stmt : ""; ?> 
      <!--start of hidden data-->
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <form action=""  method="post" id="inv_transaction"  name="inv_transaction">
        <!--create empty form or a single id when search is not clicked and the id is referred from other page -->
        <span class="heading">Inventory Transaction </span> 
        <ul id="form_top_ul" class="inRow asperWidth headerBgColor">
         <li><lable>Inventory Org </lable>
         <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>
         </li>
         <li><lable>Transaction Type </lable>
         <?php
          echo!(empty($id_array)) ? form::select_field_from_object('transaction_type_id', transaction_type::find_some_byIdArray($id_array), 'transaction_type_id', 'transaction_type', $$class->transaction_type_id, 'transaction_type_id', $readonly) :
            form::select_field_from_object('transaction_type_id', transaction_type::find_all(), 'transaction_type_id', 'transaction_type', $$class->transaction_type_id, 'transaction_type_id', 1);
         ?>
         </li>
        </ul>
        <div id ="form_line" class="form_line"><span class="heading">Transaction Details </span>
         <div id="tabsLine">
          <ul class="tabMain">
           <li><a href="#tabsLine-1">General Info</a></li>
           <li><a href="#tabsLine-2">Transfer </a></li>
           <li><a href="#tabsLine-3">Reference </a></li>
           <li><a href="#tabsLine-4">Finance </a></li>
           <li><a href="#tabsLine-5">Transaction </a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsLine-1" class="tabContent">
            <table class="form_table">
             <thead> 
              <tr>
               <th>Action</th>
               <th>Transaction Id</th>
               <th>Item Id</th>
               <th>Item Number</th>
               <th>Item Description</th>
               <th>UOM</th>
               <th>Quantity</th>

              </tr>
             </thead>
             <tbody class="form_data_line_tbody">
              <tr class="inv_transaction_line0" id="tab1_1">
               <td>    
                <ul class="inline_action">
                 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->inv_transaction_id); ?>">
                  <?php echo form::hidden_field('org_id', $$class->org_id); ?>
                  <?php echo form::hidden_field('transaction_type_id', $$class->transaction_type_id); ?>
                 </li>           
                </ul>
               </td>
               <td>
                <?php echo $f->text_field_dsr('inv_transaction_id', 'lineId'); ?>
               </td>
               <td><?php $f->text_field_widsr('item_id_m'); ?></td>
               <td><?php $f->text_field_widm('item_number', 'select_item_number'); ?>
                <i class="select_item_number select_popup clickable fa fa-search"></i></td>
               <td><?php $f->text_field_wid('item_description'); ?></td>
               <td>
                <?php echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, 'uom_id', $readonly); ?>
               </td>
               <td><?php form::text_field_widsm('quantity'); ?></td>
              </tr>
             </tbody>
            </table>
           </div>
           <div id="tabsLine-2" class="tabContent">
            <table class="form_table">
             <thead> 
             <th>From SubInv</th>
             <th>From Locator </th>
             <th>To SubInv</th>
             <th>To Locator</th>
             <th>Ef Id</th>
             <th>Description</th>
             <th>Reason</th>
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
               <td><?php echo form::extra_field($$class->ef_id, '10', $readonly); ?></td>
               <td><?php form::text_field_wid('description'); ?>							</td>
               <td><?php form::text_field_wid('reason'); ?>							</td>
              </tr>
             </tbody>
            </table>
           </div>
           <div id="tabsLine-3" class="tabContent">
            <table class="form_table">
             <thead> 
             <th>Document Type</th>
             <th>Doc. Number</th>
             <th>Doc. Id</th>
             <th>Ref Type</th>
             <th>Ref Name</th>
             <th>Ref Value</th>
             <th>Ref Doc</th>
             <th>WO BOM Line Id</th>
             <th>PO Detail Id</th>
             <th>SO Line Id</th>
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
            <table class="form_table">
             <thead> 
             <th>Account</th>
             <th>Unit Cost</th>
             <th>Costed Amount</th>
             <th>Journal Header Id<th>
              </thead>
             <tbody class="form_data_line_tbody">
              <tr class="inv_transaction_line0" id="tab4_1">
               <td><?php $f->ac_field_wid('account_id'); ?></td>
               <td><?php form::text_field_wid('unit_cost'); ?></td>
               <td><?php form::text_field_wid('costed_amount'); ?></td>
               <td><?php form::text_field_wid('gl_journal_header_id'); ?></td>
              </tr>
             </tbody>
            </table>
           </div>
           <div id="tabsLine-5" class="tabContent scrollElement">
            <table class="form_table">
             <thead> 
             <th>Lot</th>
             <th>Serial</th>
             </thead>
             <tbody class="form_data_line_tbody">
              <tr class="inv_transaction_line0" id="tab4_1">
               <td>	<?php
                 $f = new inoform();
                 $f->text_field_wid('lot_number');
                 echo $f->hidden_field('lot_number_id', $$class->lot_number_id);
                 echo $f->hidden_field('lot_generation', $$class->lot_generation);
                ?> </td>
               <td class="tdBlock">
                   <?php
                    echo $f->text_field('serial_number', $$class->serial_number, '14');
                    echo $f->hidden_field('serial_number_id', $$class->serial_number_id);
                    echo $f->hidden_field('serial_generation', $$class->serial_generation);
                   ?>
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

      </div>
      <!--END OF FORM HEADER-->
      <div id="pagination" style="clear: both;">
       <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
       ?>
      </div>
     </div>
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
