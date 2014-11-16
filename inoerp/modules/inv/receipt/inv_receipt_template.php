<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="inv_receipt_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <!--    End of place for showing error messages-->

      <div id ="form_header"><span class="heading">Receipt Header </span>

       <div id="tabsHeader">
        <ul class="tabMain">
         <li><a href="#tabsHeader-1">Basic Info</a></li>
         <li><a href="#tabsHeader-2">Attachments</a></li>
         <li><a href="#tabsHeader-3">Notes</a></li>
         <li><a href="#tabsHeader-4">Actions</a></li>

        </ul>
        <div class="tabContainer">
         <form action=""  method="post" id="inv_receipt_header"  name="inv_receipt_header">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column five_column">
             <li><label> <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="inv_receipt_header_id select_popup clickable">
               Receipt Header Id </label><?php echo form::text_field_dsr('inv_receipt_header_id'); ?><a name="show" href="form.php?class_name=inv_receipt_header" class="show inv_receipt_header clickable">
               <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label>Inventory </label>
              <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly1); ?>
             </li>
             <li><label>Transaction Type </label>
              <?php echo form::select_field_from_object('transaction_type_id', transaction_type::find_by_transactionClass('PO'), 'transaction_type_id', 'transaction_type', $$class->transaction_type_id, 'transaction_type_id', $readonly1); ?>
             </li>
             <li><label>Number </label>
              <?php
               echo $f->text_field('receipt_number', $$class->receipt_number, '8', '', 'primary_column2', '', $readonly1);
              ?>
             </li>
             <li><label>Date </label>
              <?php echo $f->date_fieldFromToday('receipt_date', ino_date($$class->receipt_date), $readonly1); ?></li>
            </ul>
           </div>
          </div>
          <div id="tabsHeader-2" class="tabContent">
           <div> <?php echo ino_attachement($file) ?> </div>
          </div>
          <div id="tabsHeader-3" class="tabContent">
           <div id="comments">
            <div id="comment_list">
             <?php echo!(empty($comments)) ? $comments : ""; ?>
            </div>
            <div id ="display_comment_form">
             <?php
              $reference_table = 'inv_receipt_header';
              $reference_id = $$class->inv_receipt_header_id;
             ?>
            </div>
           </div>
          </div>
          <div id="tabsHeader-4" class="tabContent">
           <div> 
            <ul class="column five_column">
             <li><label>Action</label>
              <select name="transaction_action[]" class=" select  transaction_action" id="transaction_action" >
               <option value="" ></option>
               <option value="CREATE_ACCOUNT" >Create Accounting</option>
               <option value="ADD_LINES" >Add Receipt Lines</option>
               <option value="PRINT_TRAVELLER" >Receipt Traveller</option>
              </select>
             </li>
            </ul>
           </div>
          </div>
         </form>		

        </div>
       </div>

      </div>
      <div id="form_line" class="form_line"><span class="heading">Receipt Lines</span>
       <form action=""  method="post" id="po_site"  name="inv_receipt_line">
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">PO Info</a></li>
          <li><a href="#tabsLine-2">Receipt</a></li>
          <li><a href="#tabsLine-3">Serial & Lot </a></li>
          <li><a href="#tabsLine-4">Supplier</a></li>
          <li><a href="#tabsLine-5">Finance</a></li>

         </ul>
         <div class="tabContainer">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>Receipt Line Id</th>
              <th>Line#</th>
              <th>Header Id</th>
              <th>PO #</th>
              <th>PO Line #</th>
              <th>Line Id</th>
              <th>Shipment #</th>
              <th>Detail Id</th>
              <th>Shipment Qty</th>
              <th>Received Qty</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($inv_receipt_line_object as $inv_receipt_line) {
               $f->readonly2 = !empty($inv_receipt_line->inv_receipt_line_id) ? true : false;
               ?>         
               <tr class="inv_receipt_line<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($inv_receipt_line->line_number); ?>"></li>           
                  <?php echo form::hidden_field('inv_receipt_header_id', $$class->inv_receipt_header_id); ?>
                  <?php echo form::hidden_field('org_id', $$class->org_id); ?>
                  <?php echo form::hidden_field('transaction_type_id', $$class->transaction_type_id); ?>
                 </ul>
                </td>
                <td><?php form::text_field_wid2sr('inv_receipt_line_id'); ?></td>
                <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
                <td><?php $f->text_field_wid2sr('po_header_id'); ?></td>
                <td><?php $f->text_field_wid2s('po_number', 'select_po_number'); ?>
                 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_po_number select_popup clickable"></td>
                <td><?php $f->text_field_wid2sr('po_line_number'); ?></td>
                <td><?php $f->text_field_wid2s('po_line_id'); ?></td>
                <td><?php $f->text_field_wid2sr('shipment_number'); ?></td>
                <td><?php $f->text_field_wid2s('po_detail_id'); ?></td>
                <td><?php echo $f->number_field('quantity', $inv_receipt_line->quantity, '8', '', '', '', 1); ?></td>
                <td><?php echo $f->number_field('received_quantity', $inv_receipt_line->received_quantity, '8', '', '', '', 1); ?></td>

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
              <th>Item id</th>
              <th>Item Number</th>
              <th>Revision</th>
              <th>Item Description</th>
              <th>UOM</th>
              <th>New Received Qty</th>
              <th>Sub inventory</th>
              <th>Locator</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($inv_receipt_line_object as $inv_receipt_line) {
               ?>         
               <tr class="inv_receipt_line<?php echo $count ?>">
                <td><?php $f->text_field_wid2sr('item_id_m'); ?></td>
                <td><?php $f->text_field_d2('item_number', 'select_item_number'); ?></td>
                <td><?php $f->text_field_wid2sr('revision_name'); ?></td>
                <td><?php $f->text_field_d2('item_description'); ?></td>
                <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $inv_receipt_line->uom_id, '', '', '', $readonly1); ?></td>
                <td><?php echo $f->number_field('transaction_quantity', $$class_second->transaction_quantity, '8', '', '', 1, $readonly1); ?></td>
                <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->subinventory_id, '', 'subinventory_id', '', $readonly1); ?></td>
                <td><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_second->subinventory_id), 'locator_id', 'locator', $$class_second->locator_id, '', 'locator_id', '', $readonly1); ?></td>
               </tr>
               <?php
               $count = $count + 1;
              }
             ?>
            </tbody>
            <!--                  Showing a blank form for new entry-->
           </table>
          </div>
          <div id="tabsLine-3" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Lot Number</th>
              <th>Serial Number</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($inv_receipt_line_object as $inv_receipt_line) {
               ?>    
               <tr class="inv_receipt_line<?php echo $count ?>">
                <td class="add_detail_values0">	<?php
                 echo!empty($$class_second->lot_number_id) ? $f->hidden_field('lot_number_id', $$class_second->lot_number_id) : $f->hidden_field('lot_number_id', '');
                 echo!empty($$class_second->lot_generation) ? $f->hidden_field('lot_generation', $$class_second->lot_generation) : $f->hidden_field('lot_generation', '');
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
                        if (!empty($$class_second->inv_receipt_line_id)) {
                         $serial_object = [];
                         $inv_trnx_i = inv_transaction::find_by_refName_refValue('inv_receipt_line', $$class_second->inv_receipt_line_id);
                         if (!empty($inv_trnx_i->inv_transaction_id)) {
                          $serial_trnxs = inv_serial_transaction::find_by_invTransactionId($inv_trnx_i->inv_transaction_id);
                           if (!empty($serial_trnxs)) {
                           foreach ($serial_trnxs as $serial_trnx) {
                            $serial_no = new inv_serial_number();
                            $serial_no->findBy_id($serial_trnx->inv_serial_number_id);
                            array_push($serial_object, $serial_no);
                           }
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
                            <li><input type="checkbox" name="detail_id_cb" value="<?php echo ($serial_no->inv_serial_number_id); ?>"></li>           

                           </ul>
                          </td>
                          <td><?php
                           
                           echo !empty($serial_no->serial_number) ?  $f->text_field('serial_number', $serial_no->serial_number, '25') : $f->text_field('serial_number','', '25');
                           echo !empty($serial_no->serial_generation) ? $f->hidden_field('serial_generation', $serial_no->serial_generation) : null;
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
               <?php
               $count = $count + 1;
              }
             ?>
            </tbody>
            <!--                  Showing a blank form for new entry-->

           </table>
          </div>

          <div id="tabsLine-4" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Supplier Id</th>
              <th>Supplier #</th>
              <th>Supplier</th>
              <th>Site Id</th>
              <th>Site #</th>
              <th>Site </th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($inv_receipt_line_object as $inv_receipt_line) {
               ?>         
               <tr class="inv_receipt_line<?php echo $count ?>">
                <td><?php form::text_field_wid2('supplier_id'); ?></td>
                <td><?php form::text_field_wid2('supplier_number'); ?></td>
                <td><?php form::text_field_wid2('supplier_name'); ?></td>
                <td><?php form::text_field_wid2('supplier_site_id'); ?></td>
                <td><?php form::text_field_wid2('supplier_site_number'); ?></td>
                <td><?php form::text_field_wid2('supplier_site_name'); ?></td>
               </tr>
               <?php
               $count = $count + 1;
              }
             ?>
            </tbody>
            <!--                  Showing a blank form for new entry-->

           </table>
          </div>

          <div id="tabsLine-5" class="form_data_line_tbody">

          </div>

         </div>
        </div>
       </form>

      </div>

      <!--END OF FORM HEADER-->
     </div>
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <!--<div id="content_right_right"></div>-->
 </div>

</div>

<?php include_template('footer.inc') ?>
