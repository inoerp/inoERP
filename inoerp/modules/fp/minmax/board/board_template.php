<div id="all_contents">
 <div id="content_left1">
  <div id="block_for_system_transaction" class="block content_left urgent_cards block_100">
   <div class="headerBgColor title system_trnx"> <span  class="hideDiv"> </span>System Transaction </div>
   <div class="content system_trnx_cotent">
    <div class="system_trnx_block hideDiv_element">
     <span class="info"><label>Transaction Type</label>
      <?php
      $f = new inoform();
      $trnx_a = ['SUB_INV' => 'Subinventory Transfer', 'PUR_REQ' => 'Purchase Requisition'];
      echo $f->select_field_from_array('transaction_type', $trnx_a, '', 'transaction_type', 'medium');
      ?>
     </span>
     <span class="button" id="save_system_trnx">Save</span>
     <ul id="mmb_transaction_block"></ul>
    </div> 
   </div>
  </div>
  <div id="block_for_urgent_card" class="block content_left urgent_cards block_99">
   <div class="headerBgColor title urgent_cards_header"> <span  class="hideDiv"> </span>Urgent Cards </div>
   <div class="content urgent_card">
    <div class="urgent_card_block hideDiv_element">
     <span class="info">Drag the urgent cards to here<br>Double click to remove it</span>
     <span class="button" id="save_urgent_card">Save</span>
     <?php
     $existing_data = fp_urgent_card::find_current_cardList();
     if ($existing_data) {
      echo '<ul id="urgent_card_block">';
      echo $existing_data;
      echo '</ul>';
     } else {
      echo '<ul id="urgent_card_block">';
      echo '</ul>';
     }
     ?>
    </div> 
   </div>
  </div>
 </div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top">

   </div>
   <div id="content">
    <div id="structure">
     <div id="minmax_header_divId">
      <div id="form_top">
      </div>
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <div class="show_loading_small"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?>  
      

      <!--    End of place for showing error messages-->
      <div id ="form_header"><span class="heading">Min Max Board </span>

       <ul id="form_top_ul" class="inRow asperWidth headerBgColor">
        <li><label>Inventory Org </label>
         <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $org_id, 'org_id'); ?>
        </li>
        <li><label>Sub Inventory </label>
         <?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($org_id), 'subinventory_id', 'subinventory', $subinventory_id, 'subinventory_id'); ?>
        </li>
        <li>              <a name="show" href="form.php?class_name=fp_minmax_board_v" class="show onhand_id">	
          <img src="<?php echo HOME_URL; ?>themes/images/refresh.png" alt="Refresh" title="Refresh" class="clickable"></a> </li>
       </ul>
       <div id="min_max_boardId">
        <ul>
         <?php
         if ($mm_details) {
          foreach ($mm_details as $recod) {
           $height_p = round(($recod->onhand / $recod->minmax_min_quantity) * 100);
           $height_p = $height_p >= 100 ? 100 : $height_p;
           if (empty($recod->open_po)) {
            $bgcolor = ($recod->onhand_delta >= 0 ) ? 'bgGreen' : 'bgRed';
           } else if ($recod->onhand_delta >= 0) {
            $bgcolor = 'bgGreen';
           } else {
            $bgcolor = ($recod->onhand_delta + $recod->open_po >= 0 ) ? 'bgPurple' : 'bgRed';
           }
           echo "<li class='{$bgcolor} parent draggable_element' ><ul class='child' title='{$height_p} %' data-height='{$height_p}' >";
           echo '<li class="item_number">' . $recod->item_number . '</li>';
           echo '<li>' . $recod->subinventory . '</li>';
           echo '<li>Min : ' . round($recod->minmax_min_quantity) . ' Max : ' . round($recod->minmax_max_quantity) . ' </li>';
           echo '<li>Min Delta :' . round($recod->onhand_delta) . '</li><li>Max Delta :' . round($recod->minmax_max_quantity - $recod->onhand) . '</li>';
           echo '<li>Onhand :' . round($recod->onhand) . '</li>';
           echo '<li>Open PO :' . round($recod->open_po) . '</li>';
           echo '</ul></li>';
          }
         }
         ?>
        </ul>
       </div>
      </div>
      <!--END OF FORM HEADER-->

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
