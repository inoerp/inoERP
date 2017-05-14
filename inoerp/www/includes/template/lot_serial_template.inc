<table class="form_line_data_table lot_serial_data_table">
 <thead> 
  <tr>
   <th><?php echo gettext('Seq') ?>#</th>
   <th><?php echo gettext('Add Lot Numbers') ?></th>
   <th><?php echo gettext('Add Serial Numbers') ?></th>
  </tr>
 </thead>
 <tbody class="form_data_line_tbody">
  <?php
  $count = 0;
  if(empty($ls_trclass)){
   $ls_trclass='inv_receipt_line';
  }
  foreach ($line_object_ls as $each_line_ls) {
   if (empty($inv_trnx) && !empty($ref_key_name)) {
    $inv_trnx = inv_transaction::find_by_refName_refValue($ref_key_name, $$line_class_name_sl->$ref_key_val);
   } else if (empty($inv_trnx)) {
    $inv_trnx = new inv_transaction();
   }
   ?>    
   <tr class="<?php echo $ls_trclass . $count ?>">
    <td><?php $f->seq_field_d($count) ?></td>
    <td class="add_detail_values0">	<?php
     echo!empty($$line_class_name_sl->lot_number_id) ? $f->hidden_field('lot_number_id', $$line_class_name_sl->lot_number_id) : $f->hidden_field('lot_number_id', '');
     echo!empty($$line_class_name_sl->lot_generation) ? $f->hidden_field('lot_generation', $$line_class_name_sl->lot_generation) : $f->hidden_field('lot_generation', '');
     ?>
     <i class="fa fa-arrow-circle-down add_detail_values_img" alt="View/Add Lot Numbers"></i>
     <div class="class_detail_form lot_serial_form">
      <fieldset class="form_detail_data_fs">
       <div class="tabsDetail">
        <ul class="tabMain">
         <li class="tabLink"><a href="#tabsDetail-1-1">Lot Numbers</a></li>
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
                <li class="add_row_detail_img1"><i class="fa fa-plus-circle clickable" alt="add new line"></i></li>
                <li class="remove_row_img"><i class="fa fa-minus-circle clickable" alt="remove this line"></i></li>
                <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($lot_no->inv_lot_number_id); ?>"></li>           
               </ul>
              </td>
              <td><?php
               echo $f->text_field('lot_number', $lot_no->lot_number, '25');
               echo!empty($$line_class_name_sl->lot_generation) ? $f->hidden_field('lot_generation', $$line_class_name_sl->lot_generation) : null;
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
     echo!empty($$line_class_name_sl->serial_number_id) ? $f->hidden_field('serial_number_id', $$line_class_name_sl->serial_number_id) : $f->hidden_field('serial_number_id', '');
     echo!empty($$line_class_name_sl->serial_generation) ? $f->hidden_field('serial_generation', $$line_class_name_sl->serial_generation) : $f->hidden_field('serial_generation', '');
     ?>
     <i class="fa fa-arrow-circle-down add_detail_values_img" alt="View/Add Serial Numbers"></i>
     <div class="class_detail_form lot_serial_form">
      <fieldset class="form_detail_data_fs">
       <div class="tabsDetail">
        <ul class="tabMain">
         <li class="tabLink"><a href="#tabsDetail-2-1">Serial Numbers</a></li>
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
            if (!empty($$line_class_name_sl->$ref_key_val)) {
             $serial_object = [];
             if($class != 'inv_transaction'){
              $inv_trnx_i = inv_transaction::find_by_refName_refValue($ref_key_name, $$line_class_name_sl->$ref_key_val);
             }else{
              $inv_trnx_i = $$class;
             }
//             pa($inv_trnx_i);
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
                <li class="add_row_detail_img"><i class="fa fa-plus-circle clickable" alt="add new line"></i></li>
                <li class="remove_row_img"><i class="fa fa-minus-circle clickable" alt="remove this line"></i></li>
                <li><input type="checkbox" name="detail_id_cb" value="<?php echo ($serial_no->inv_serial_number_id); ?>"></li>           

               </ul>
              </td>
              <td><?php
               echo!empty($serial_no->serial_number) ? $f->text_field('serial_number', $serial_no->serial_number, '25') : $f->text_field('serial_number', '', '25');
               echo!empty($serial_no->serial_generation) ? $f->hidden_field('serial_generation', $serial_no->serial_generation) : null;
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