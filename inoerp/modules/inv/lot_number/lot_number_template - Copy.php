<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="inv_lot_number_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <div class="show_loading_small"></div>
      <?php echo (!empty($show_message)) ? $show_message : "" ?> 
      <!--    End of place for showing error messages-->

      <form action=""  method="post" id="inv_lot_number"  name="inv_lot_number"><span class="heading"><?php echo gettext('Lot Number') ?> </span>
       <div id ="form_header">
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
          <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
          <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column four_column"> 
             <li> <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="inv_lot_number_id select_popup clickable">
               lot Id : </label><?php $f->text_field_dsr('inv_lot_number_id') ?>
              <a name="show" href="form.php?class_name=inv_lot_number" class="show inv_lot_number_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
             </li>
             <li><label><?php echo gettext('Inventory Org') ?> </label>
              <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>
             </li>
             <li><label> <?php
                if (empty($$class->inv_lot_number_id)) {
                 echo "<img src='" . HOME_URL . "themes/images/serach.png' class='select_item_number select_popup clickable'>";
                }
               ?> <?php echo gettext('Item Number') ?>(2) : </label>
              <?php echo $f->hidden_field_withId('item_id_m', $$class->item_id_m); ?>
              <?php
               if (empty($$class->inv_lot_number_id)) {
                $f->text_field_d('item_number', 'select_item_number');
               } else {
                $f->text_field_dr('item_number');
               }
              ?>
             </li>
             <li><label><?php echo gettext('Item Description') ?>: </label>
              <?php $f->text_field_dr('item_description'); ?>
             </li>
             <li><label><?php echo gettext('Lot Number') ?> :</label><?php $f->text_field_d('lot_number'); ?></li>
             <li><label><?php echo gettext('Status') ?> </label>
              <?php echo $f->select_field_from_array('status', inv_lot_number::$lot_status, $$class->status, 'status', '', 1, $readonly1); ?>
             </li>
             <li><label><?php echo gettext('Generation') ?> : </label> 
              <?php echo $f->select_field_from_array('generation', item::$ls_generation_a, $$class->generation, '', 'generation', '', 1, 1); ?>
             </li> 
             <li><label><?php echo gettext('Description') ?> :</label><?php $f->text_field_d('description'); ?> 					</li>
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
              $reference_table = 'inv_lot_number';
              $reference_id = $$class->inv_lot_number_id;
             ?>
            </div>
            <div id="new_comment">
            </div>
           </div>
           <div> 
           </div>
          </div>

         </div>

        </div>
       </div>
       <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Lot Number Details') ?> </span>
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1"><?php echo gettext('Current') ?></a></li>
          <li><a href="#tabsLine-2"><?php echo gettext('References') ?></a></li>
          <li><a href="#tabsLine-3"><?php echo gettext('Transactions') ?></a></li>
          <li><a href="#tabsLine-4"><?php echo gettext('Relations') ?></a></li>          
         </ul>
         <div class="tabContainer"> 
          <div id="tabsLine-1" class="tabContent">
           <div> 
            <ul class="column four_column"> 
             <li><label><?php echo gettext('Origination Type') ?> : </label>
              <?php echo $f->select_field_from_array('origination_type', inv_lot_number::$origination_type_a, $$class->origination_type, 'origination_type', '', 1, 1, 1); ?>             </li>
             <li><label><?php echo gettext('Origination Date') ?> : </label>
              <?php echo $f->date_fieldAnyDay_r('origination_date', $$class->origination_date, 1); ?>
             </li>
             <li><label><?php echo gettext('Activation Date') ?> : </label>
              <?php echo $f->date_fieldAnyDay_r('activation_date', $$class->activation_date, 1); ?>
             </li>
             <li><label><?php echo gettext('Expiration Date') ?> : </label>
              <?php echo $f->date_fieldFromToday('expiration_date', $$class->expiration_date); ?>
             </li>
                          <li><label><?php echo gettext('Expiration Action') ?> </label>
              <?php echo $f->select_field_from_array('expiration_action', inv_lot_number::$expiration_action_a, $$class->expiration_action, 'expiration_action', '', '', $readonly); ?>
             </li>
             <li><label><?php echo gettext('Supplier S/N') ?> : </label> <?php $f->text_field_d('supplier_sn'); ?>             </li>
             <li><label><?php echo gettext('COO') ?> : </label> <?php $f->text_field_d('country_of_origin'); ?>             </li>
             <li><label><?php echo gettext('Parent Id') ?> : </label> <?php $f->text_field_dr('parent_lot_number_id'); ?>             </li>
            </ul> 
           </div> 
          </div> 
          <div id="tabsLine-2" class="tabContent">
           <div> 
            <ul class="column four_column"> 
             <li><label><?php echo gettext('Supplier Site Id') ?> : </label> <?php $f->text_field_dr('supplier_site_id'); ?>             </li>
             <li><label><?php echo gettext('PO Header Id') ?> : </label> <?php $f->text_field_dr('po_header_id'); ?>             </li>
             <li><label><?php echo gettext('Supplier L/N') ?> : </label> <?php $f->text_field_dr('supplier_ln'); ?>             </li>
             <li><label><?php echo gettext('First Trnx Id') ?> : </label> <?php $f->text_field_dr('first_inv_transaction_id'); ?>             </li>
             <li><label><?php echo gettext('Last Trnx Id') ?> : </label> <?php $f->text_field_dr('last_inv_transaction_id'); ?>             </li>
             <li><label><?php echo gettext('Customer Site Id') ?> : </label> <?php $f->text_field_dr('ar_customer_site_id'); ?>             </li>
             <li><label><?php echo gettext('Original WO Id') ?> : </label> <?php $f->text_field_dr('original_wip_wo_header_id'); ?>             </li>

            </ul> 
           </div> 
          </div> 
          <div id="tabsLine-3"  class="tabContent">
           <div> 
            <div id ="form_line" class="form_line">
             <div id="tabsDetail">
              <ul class="tabMain">
               <li><a href="#tabsDetail-1"><?php echo gettext('Info-1') ?> </a></li>
               <li><a href="#tabsDetail-2"><?php echo gettext('Info-2') ?> </a></li>
              </ul>
              <div class="tabContainer"> 
               <div id="tabsDetail-1" class="tabContent">
                <table class="form_table">
                 <thead> 
                  <tr>
                   <th><?php echo gettext('Lot Number') ?></th>
                   <th><?php echo gettext('Item Number') ?></th>
                   <th><?php echo gettext('Item Description') ?></th>
                   <th><?php echo gettext('Org Id') ?></th>
                   <th><?php echo gettext('Transaction Type') ?></th>
                   <th><?php echo gettext('From Subinventory') ?> </th>
                   <th><?php echo gettext('From Locator') ?> </th>
                   <th><?php echo gettext('Transaction Details') ?> </th>
                  </tr>
                 </thead>
                 <tbody class="form_data_line_tbody inv_lot_transaction_entries_values" >
                  <?php
                   $count = 0;

                   foreach ($inv_lot_transaction_object as $inv_lot_transaction) {
                    $class_second = 'inv_lot_transaction';
                    ?>         
                    <tr class="inv_lot_transaction_entries<?php echo $count ?>">
                     <td><?php $f->text_field_wid2r('lot_number'); ?></td>
                     <td><?php $f->text_field_wid2r('item_number'); ?></td>
                     <td><?php $f->text_field_wid2r('item_description'); ?></td>
                     <td><?php $f->text_field_wid2sr('org_id'); ?></td>
                     <td><?php $f->text_field_wid2r('transaction_type'); ?></td>
                     <td><?php $f->text_field_wid2r('from_subinventory'); ?></td>
                     <td><?php $f->text_field_wid2r('from_locator'); ?></td>
                     <td><a class="button" href="form.php?class_name=inv_transaction&mode=2&inv_transaction_id=<?php echo $$class_second->inv_transaction_id; ?>"><?php echo gettext('View Inv Transaction') ?></a></td>
                    </tr>
                    <?php
                    $count = $count + 1;
                   }
                  ?>
                 </tbody>
                </table>
               </div>
               <div id="tabsDetail-2" class="tabContent">
                <table class="form_table">
                 <thead> 
                  <tr>
                   <th><?php echo gettext('To Subinventory') ?> </th>
                   <th><?php echo gettext('To Locator') ?> </th>
                   <th><?php echo gettext('Transaction Id') ?></th>
                   <th><?php echo gettext('Transaction Type Id') ?></th>
                   <th><?php echo gettext('From Subinventory Id') ?></th>
                   <th><?php echo gettext('From Locator Id') ?></th>
                   <th><?php echo gettext('To Subinventory Id') ?></th>
                   <th><?php echo gettext('To Locator Id') ?></th>
                  </tr>
                 </thead>
                 <tbody class="form_data_line_tbody inv_lot_transaction_entries_values" >
                  <?php
                   $count = 0;
                   foreach ($inv_lot_transaction_object as $inv_lot_transaction) {
                    $class_second = 'inv_lot_transaction';
                    ?>         
                    <tr class="inv_lot_transaction_entries<?php echo $count ?>">
                     <td><?php $f->text_field_wid2r('to_subinventory'); ?></td>
                     <td><?php $f->text_field_wid2r('to_locator'); ?></td>
                     <td><?php $f->text_field_wid2sr('inv_transaction_id'); ?></td>
                     <td><?php $f->text_field_wid2sr('transaction_type_id'); ?></td>

                     <td><?php $f->text_field_wid2sr('from_subinventory_id'); ?></td>
                     <td><?php $f->text_field_wid2sr('from_locator_id'); ?></td>
                     <td><?php $f->text_field_wid2sr('to_subinventory_id'); ?></td>
                     <td><?php $f->text_field_wid2sr('to_locator_id'); ?></td>
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
            </div> 
            <div id="pagination" style="clear: both;">
             <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
             ?>
            </div>
            <!--END OF FORM -->

           </div> 
          </div>
          <div id="tabsLine-4" class="tabContent">
           <div> 
            <ul> 
             <li class="simple_box parent full_width"><label><?php echo gettext('Parent') ?> </label> 
              <?php
               if (!empty($parent_lot)) {
                echo gettext('Lot Number') . " : <a class='button' href=\"form.php?class_name=inv_lot_number&mode=9&inv_lot_number_id=$parent_lot->inv_lot_number_id\"> $parent_lot->lot_number </a> & Item Id :  $parent_lot->item_id_m <br>";
               } else {
                echo "No Parent";
               }
              ?>            
             </li>
             <li class="simple_box current full_width"><label><?php echo gettext('Current') ?> </label> 
<?php echo!empty($$class->lot_number) ? " " . gettext('Lot Number') . " : " . $$class->lot_number . "& Item Id :  " . $$class->item_id_m : 'No lot'; ?>            
             </li>
             <li class="simple_box child full_width"><label><?php echo gettext('Child') ?> </label> 
              <?php
               if (!empty($child_lot)) {
                foreach ($child_lot as $child) {
                 echo " " . gettext('Lot Number') . " : <a class='button' href=\"form.php?class_name=inv_lot_number&mode=9&inv_lot_number_id=$child->inv_lot_number_id\"> $child->lot_number </a> & Item Id :  $child->item_id_m <br>";
                }
               } else {
                echo 'No Child';
               }
              ?>            
             </li>
            </ul> 
           </div> 
          </div> 
         </div>
        </div> 
       </div> 
      </form>

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
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="inv_lot_number" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="inv_lot_number_id" ></li>
  <li class="form_header_id" data-form_header_id="inv_lot_number" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="inv_lot_number_id" ></li>
  <li class="btn1DivId" data-btn1DivId="inv_lot_number_id" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>
