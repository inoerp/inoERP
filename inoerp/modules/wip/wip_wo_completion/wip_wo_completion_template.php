<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="inv_transaction_divId">
      <div id="inv_transaction_searchId">
      </div>
      <div id="form_top">
      </div>
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <div class="show_loading_small"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <form action=""  method="post" id="wip_wo_completion"  name="wip_wo_completion">
        <!--create empty form or a single id when search is not clicked and the id is referred from other page -->
        <span class="heading">WIP Work Order Transaction </span> 
        <table class="form_table">
         <tr>
          <td><label>Inventory Org </label>
           <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>
          </td>
          <td> <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="wip_wo_header_id select_popup clickable">
            WO Header Id(1) : </label> <?php $f->text_field_drm('wip_wo_header_id'); ?>
          </td>
          <td><label>WO Number : </label>  <?php $f->text_field_dr('wo_number'); ?> </td>
          <td><label>Transaction Type </label>
           <?php echo $f->select_field_from_array('transaction_type_id', wip_wo_completion::$transaction_type_id_a, $$class->transaction_type_id, 'transaction_type_id', '', 1); ?>
           <a name="show" class="show wip_wo_headerid_show"> <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
          </td>
         </tr>
        </table>
        <div id ="form_line" class="form_line"><span class="heading">Work Order Details </span>
         <div id="tabsLine">
          <ul class="tabMain">
           <li><a href="#tabsLine-1">General Info</a></li>
           <li><a href="#tabsLine-2">Transfer Info</a></li>
           <li><a href="#tabsLine-3">Reference Info</a></li>
           <li><a href="#tabsLine-4">Finance Info</a></li>
           <li><a href="#tabsLine-5">Lot & Serial </a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsLine-1" class="tabContent">
            <table class="form_line_data_table">
             <thead> 
              <tr>
               <th>Action</th>
               <th>Item Id</th>
               <th>Item Number</th>
               <th>Item Description</th>
               <th>UOM</th>
               <th>Document Qty</th>
               <th>Available Qty</th>
               <th>Transaction Qty</th>
               <th>Transaction Id</th>
              </tr>
             </thead>
             <tbody class="inv_transaction_values">
              <tr class="inv_transaction_row0" id="tab1_1">
               <td>    
                <ul class="inline_action">
                 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->item_id_m); ?>">
                  <?php echo form::hidden_field('org_id', $$class->org_id); ?>
                  <?php echo form::hidden_field('wip_wo_header_id', $$class->wip_wo_header_id); ?>
                  <?php echo form::hidden_field('transaction_type_id', $$class->transaction_type_id); ?></li>  
                </ul>
               </td>
               <td>
                <?php form::text_field_widsr('item_id_m'); ?>
               </td>
               <td>
                <?php form::text_field_drm('item_number'); ?> 
               </td>
               <td>
                <?php form::text_field_dr('item_description'); ?>
               </td>
               <td>
                <?php echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, '', $readonly); ?>
               </td>
               <td><?php form::number_field_widsr('total_quantity'); ?></td>
               <td><?php form::number_field_widsr('available_quantity'); ?></td>
               <td><?php form::number_field_widsm('quantity'); ?></td>
               <td><?php form::number_field_widsr('inv_transaction_id'); ?></td>
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
             <tbody class="inv_transaction_values">
              <tr class="inv_transaction_row0" id="tab2_1">
               <td>
                <?php echo form::select_field_from_object('from_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->from_subinventory_id, '', $readonly, 'subinventory_id'); ?>
               </td>
               <td>
                <?php echo form::select_field_from_object('from_locator_id', locator::find_all_of_subinventory($$class->from_subinventory_id), 'locator_id', 'locator', $$class->from_locator_id, '', $readonly, 'locator_id'); ?>
               </td>
               <td>
                <?php echo form::select_field_from_object('to_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->to_subinventory_id, '', $readonly, 'subinventory_id'); ?>
               </td>
               <td>
                <?php echo form::select_field_from_object('to_locator_id', locator::find_all_of_subinventory($$class->to_subinventory_id), 'locator_id', 'locator', $$class->to_locator_id, '', $readonly, 'locator_id'); ?>
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
               <th>Account</th>
               <th>Unit Cost</th>
               <th>Costed Amount</th>
               <th>Journal Id<th>
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
            <table class="form_line_data_table">
             <thead> 
              <tr>
               <th>Lot</th>
               <th>Add Serial Numbers</th>
              </tr>
             </thead>
             <tbody class="form_data_line_tbody">
              <tr class="inv_transaction_row0" id="tab4_1">
               <td>	<?php
                 $f->text_field_wid('lot_number');
                 echo $f->hidden_field('lot_number_id', $$class->lot_number_id);
                 echo $f->hidden_field('lot_generation', $$class->lot_generation);
                ?> </td>
               <td class="add_detail_values">
                <?php
                 echo $f->hidden_field('serial_number_id', $$class->serial_number_id);
                 echo $f->hidden_field('serial_generation', $$class->serial_generation);
                ?>
                <img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
                <div class="class_detail_form">
                 <fieldset class="form_detail_data_fs"><legend>Serial</legend>
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

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="wip_wo_completion" ></li>
  <li class="lineClassName" data-lineClassName="wip_wo_completion" ></li>
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

<?php include_template('footer.inc') ?>
