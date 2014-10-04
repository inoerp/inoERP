<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="inv_abc_assignment_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
       echo (!empty($show_message)) ? $show_message : "";
       $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <span class="heading">Lot Number Details </span>
       <div id="tabsHeader">
        <ul class="tabMain">
         <li><a href="#tabsHeader-1">Basic Info</a></li>
         <li><a href="#tabsHeader-2">lot Details</a></li>
        </ul>
        <div class="tabContainer">
         <div id="tabsHeader-1" class="tabContent">
          <div class="large_shadow_box"> 
           <ul class="column five_column">
            <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="inv_lot_transaction_header_id select_popup clickable">
              Lot Number : </label> 
             <?php echo $f->hidden_field_withId('inv_lot_number_id_h', $inv_lot_number_id_h); ?>
             <?php echo $f->text_field('lot_number', $lot_number_h,'','lot_number') ?>
             <a name="show" class="show inv_lot_number_id clickable"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a></li>
           <li><label>Generation : </label> <?php echo $f->text_field_dr('generation'); ?></li>
           <li><label>Origination  : </label> <?php echo $f->text_field_dr('origination_type'); ?></li>
           <li><label>Origination Date : </label> <?php echo $f->text_field_dr('origination_date'); ?></li>
           <li><label>Activation Date : </label> <?php echo $f->text_field_dr('activation_date'); ?></li>
           </ul>
          </div>
         </div>
         <div id="tabsHeader-2" class="tabContent">
          <div class="large_shadow_box"> 
           <ul class="column five_column">
           <li><label>Current Org Id : </label> <?php echo $f->text_field_dr('current_org_id'); ?></li>
           <li><label>Current Sub Inventory Id : </label> <?php echo $f->text_field_dr('current_org_id'); ?></li>
           <li><label>Current Locator Id : </label> <?php echo $f->text_field_dr('current_org_id'); ?></li>
           </ul>
          </div>
         </div>
        </div>
       </div>

      </div>

      <div id ="form_line" class="form_line"><span class="heading">Lot Transactions </span>
       <div id="tabsLine">
        <ul class="tabMain">
         <li><a href="#tabsLine-1">Info-1 </a></li>
         <li><a href="#tabsLine-2">Info-2 </a></li>
        </ul>
        <div class="tabContainer"> 
         <form action=""  method="post" id="inv_lot_transaction_entries_line"  name="inv_lot_transaction_entries_line">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_table">
            <thead> 
             <tr>
              <th>lot Number</th>
              <th>Item Number</th>
              <th>Item Description</th>
              <th>Org Id</th>
              <th>Transaction Type</th>
              <th>From Sub Inventory </th>
              <th>From Locator </th>
              <th>Item Id M </th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody inv_lot_transaction_entries_values" >
             <?php
              $count = 0;
              foreach ($inv_lot_transaction_object as $inv_lot_transaction_v) {
               ?>         
               <tr class="inv_lot_transaction_entries<?php echo $count ?>">
                <td><?php $f->text_field_widr('lot_number'); ?></td>
                <td><?php $f->text_field_widr('item_number'); ?></td>
                <td><?php $f->text_field_widr('item_description'); ?></td>
                <td><?php $f->text_field_widsr('org_id'); ?></td>
                <td><?php $f->text_field_widr('transaction_type'); ?></td>
                <td><?php $f->text_field_widr('from_subinventory'); ?></td>
                <td><?php $f->text_field_widr('from_locator'); ?></td>
                <td><?php $f->text_field_widr('item_id_m'); ?></td>
               </tr>
               <?php
               $count = $count + 1;
              }
             ?>
            </tbody>
           </table>
          </div>
          <div id="tabsLine-2" class="tabContent">
           <table class="form_table">
            <thead> 
             <tr>
              <th>To Sub Inventory </th>
              <th>To Locator </th>
              <th>Transaction Id</th>
              <th>Transaction Type Id</th>
              <th>From Sub Inventory Id</th>
              <th>From Locator Id</th>
              <th>To Sub Inventory Id</th>
              <th>To Locator Id</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody inv_lot_transaction_entries_values" >
             <?php
              $count = 0;
              foreach ($inv_lot_transaction_object as $inv_lot_transaction_v) {
               ?>         
               <tr class="inv_lot_transaction_entries<?php echo $count ?>">
                <td><?php $f->text_field_widr('to_subinventory'); ?></td>
                <td><?php $f->text_field_widr('to_locator'); ?></td>
                <td><?php $f->text_field_widsr('inv_transaction_id'); ?></td>
                <td><?php $f->text_field_widsr('transaction_type_id'); ?></td>

                <td><?php $f->text_field_widr('from_subinventory_id'); ?></td>
                <td><?php $f->text_field_widr('from_locator_id'); ?></td>
                <td><?php $f->text_field_widr('to_subinventory_id'); ?></td>
                <td><?php $f->text_field_widr('to_locator_id'); ?></td>
               </tr>
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
      <div id="pagination" style="clear: both;">
       <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
       ?>
      </div>
      <!--END OF FORM -->
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