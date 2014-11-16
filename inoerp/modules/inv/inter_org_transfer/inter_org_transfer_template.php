<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="inv_interorg_transfer_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
       echo (!empty($show_message)) ? $show_message : "";
//       $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->

      <div id ="form_header"><span class="heading">Inter-Org Transfer Header </span>

       <div id="tabsHeader">
        <ul class="tabMain">
         <li><a href="#tabsHeader-1">Basic Info</a></li>
         <li><a href="#tabsHeader-2">Attachments</a></li>
         <li><a href="#tabsHeader-3">Notes</a></li>
         <li><a href="#tabsHeader-4">Actions</a></li>
        </ul>
        <div class="tabContainer">
         <form action=""  method="post" id="inv_interorg_transfer_header"  name="inv_interorg_transfer_header">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column six_column">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="inv_interorg_transfer_header_id select_popup clickable">
               Header Id </label><?php echo form::text_field_dsr('inv_interorg_transfer_header_id'); ?><a name="show" href="form.php?class_name=inv_interorg_transfer_header" class="show inv_interorg_transfer_header clickable">
               <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label>From Inventory </label>
              <?php echo $f->select_field_from_object('from_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->from_org_id, 'from_org_id', '', 1, $readonly1); ?>
             </li>
             <li><label>To Inventory </label>
              <?php echo $f->select_field_from_object('to_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->to_org_id, 'to_org_id', '', 1, $readonly1); ?>
             </li>
             <li><label>Number </label> <?php echo $f->text_field('order_number', $$class->order_number, '8', '', '', '', $readonly1); ?> </li>
             <li><label>Date </label>
              <?php echo $f->date_fieldFromToday_d('transaction_date', ino_date($$class->transaction_date), $readonly1); ?></li>
             <li><label>Transaction Type </label>
              <?php echo $f->select_field_from_array('transaction_type_id', inv_interorg_transfer_header::$transaction_type_id_a, $$class->transaction_type_id, 'transaction_type_id', '', 1, $readonly1, $readonly1); ?>
             </li>
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
              $reference_table = 'inv_interorg_transfer_header';
              $reference_id = $$class->inv_interorg_transfer_header_id;
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
               <option value="ADD_LINES" >Add Interorg transfer Lines</option>
               <option value="PRINT_TRAVELLER" >Interorg_transfer Traveler</option>
              </select>
             </li>
            </ul>
           </div>
          </div>
         </form>		

        </div>
       </div>

      </div>
      <div id="form_line" class="form_line"><span class="heading">Inter-Org Transfer Lines</span>
       <form action=""  method="inv_interorg_transfer_line_form" id="inv_interorg_transfer_line_form"  name="inv_interorg_transfer_line">
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">General Info</a></li>
          <li><a href="#tabsLine-2">Transfer </a></li>
          <li><a href="#tabsLine-3">Lot Serial </a></li>
          <li><a href="#tabsLine-4">On hand </a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>Line Id</th>
              <th>Item Number</th>
              <th>Revision</th>
              <th>Item Description</th>
              <th>UOM</th>
              <th>Quantity</th>
              <th>Reason</th>

             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($inv_interorg_transfer_line_object as $inv_interorg_transfer_line) {
               ?>    
               <tr class="inv_interorg_transfer_line<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->inv_interorg_transfer_header_id); ?>">
                   <?php echo form::hidden_field('from_org_id', $$class->from_org_id); ?>
                   <?php echo form::hidden_field('to_org_id', $$class->to_org_id); ?>
                   <?php echo form::hidden_field('inv_interorg_transfer_header_id', $$class->inv_interorg_transfer_header_id); ?>
                   <?php echo form::hidden_field('transaction_type_id', $$class->transaction_type_id); ?>
                  </li>           
                 </ul>
                </td>
                <td><?php $f->text_field_d2sr('inv_interorg_transfer_line_id', 'lineId'); ?></td>
                <td><?php
                 echo $f->hidden_field('item_id_m', $$class_second->item_id_m);
                 $f->text_field_wid2('item_number', 'select_item_number');
                 ?><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></td>
                <td><?php $f->text_field_wid2sr('revision_name'); ?></td>
                <td><?php $f->text_field_wid2l('item_description'); ?></td>
                <td><?php echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, 'uom_id', $readonly); ?>  </td>
                <td><?php echo $f->number_field('transaction_quantity', $$class_second->transaction_quantity, '', '', '', '', $f->readonly2); ?></td>
                <td><?php $f->text_field_wid2('reason'); ?>							</td>

               </tr>
               <?php
               $count = $count + 1;
              }
             ?>
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
              <th>Description</th>

              <th>Ref Type</th>
              <th>Ref Name</th>
              <th>Ref Value</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($inv_interorg_transfer_line_object as $inv_interorg_transfer_line) {
               ?>   
               <tr class="inv_interorg_transfer_line<?php echo $count ?>">
                <td>
                 <?php echo $f->select_field_from_object('from_subinventory_id', subinventory::find_all_of_org_id($$class->from_org_id), 'subinventory_id', 'subinventory', $$class_second->from_subinventory_id, '', 'subinventory_id', ''); ?>
                </td>
                <td>
                 <?php echo $f->select_field_from_object('from_locator_id', locator::find_all_of_subinventory($$class_second->from_subinventory_id), 'locator_id', 'locator', $$class_second->from_locator_id, '', 'from_locator_id', ''); ?>
                </td>
                <td>
                 <?php echo $f->select_field_from_object('to_subinventory_id', subinventory::find_all_of_org_id($$class->to_org_id), 'subinventory_id', 'subinventory', $$class_second->to_subinventory_id, '', 'subinventory_id', ''); ?>
                </td>
                <td>
                 <?php echo $f->select_field_from_object('to_locator_id', locator::find_all_of_subinventory($$class_second->to_subinventory_id), 'locator_id', 'locator', $$class_second->to_locator_id, '', 'to_locator_id', ''); ?>
                </td>
                <td><?php $f->text_field_wid2l('description'); ?>							</td>

                <td><?php $f->text_field_wid2s('reference_type'); ?>							</td>
                <td><?php $f->text_field_wid2('reference_key_name'); ?>							</td>
                <td><?php $f->text_field_wid2('reference_key_value'); ?>							</td>
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
              <th>Lot Number</th>
              <th>Serial Number</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($inv_interorg_transfer_line_object as $inv_interorg_transfer_line) {
               $inv_trnx = inv_transaction::find_by_refName_refValue('inv_interorg_transfer_line', $$class_second->inv_interorg_transfer_line_id);
               ?>    
               <tr class="inv_interorg_transfer_line<?php echo $count ?>">
                <td class="add_detail_values0">	<?php
                 echo !empty($$class_second->lot_number_id) ? $f->hidden_field('lot_number_id', $$class_second->lot_number_id) : $f->hidden_field('lot_number_id','');
                  echo !empty($$class_second->lot_generation) ? $f->hidden_field('lot_generation', $$class_second->lot_generation) : $f->hidden_field('lot_generation','');
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
                           echo !empty($$class_second->lot_generation) ? $f->hidden_field('lot_generation', $$class_second->lot_generation) : null;
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
                  echo !empty($$class_second->serial_number_id) ? $f->hidden_field('serial_number_id', $$class_second->serial_number_id) :  $f->hidden_field('serial_number_id', '');;
                  echo !empty($$class_second->serial_generation) ? $f->hidden_field('serial_generation', $$class_second->serial_generation) : $f->hidden_field('serial_generation', '');
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
                        if (!empty($inv_trnx->inv_transaction_id)) {
                         $serial_object = [];
                         $serial_trnxs = inv_serial_transaction::find_by_invTransactionId($inv_trnx->inv_transaction_id);
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
                             echo !empty($$class_second->serial_generation) ? $f->hidden_field('serial_generation', $$class_second->serial_generation) : null;
                           
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
           </table>
          </div>
          <div id="tabsLine-4" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>From Current Onhand</th>
              <th>From Future Onhand </th>
              <th>To Current Onhand</th>
              <th>To Future Onhand</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($inv_interorg_transfer_line_object as $inv_interorg_transfer_line) {
               ?>   
               <tr class="inv_interorg_transfer_line<?php echo $count ?>">
                <td><?php $f->text_field_wid2r('from_current_onhand', 'onhand'); ?>							</td>
                <td><?php $f->text_field_wid2r('from_future_onhand', 'onhand'); ?>							</td>
                <td><?php $f->text_field_wid2r('to_current_onhand', 'onhand'); ?>							</td>
                <td><?php $f->text_field_wid2r('to_future_onhand', 'onhand'); ?>							</td>
               </tr>
               <?php
               $count = $count + 1;
              }
             ?>
            </tbody>
           </table>
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
