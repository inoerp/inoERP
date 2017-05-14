<form  method="post" id="inv_serial_number"  name="inv_serial_number"><span class="heading"><?php echo gettext('Serial Number') ?></span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field"> 
      <li><?php $f->l_text_field_dr('inv_serial_number_id') ?>
       <a name="show" href="form.php?class_name=inv_serial_number&<?php echo "mode=$mode"; ?>" class="show document_id inv_serial_number_id"><i class="fa fa-refresh"></i></a> 
       <i class="select_serial_number_1 generic select_popup clickable fa fa-search" data-class_name="inv_serial_number"></i>
      </li>
      <li><?php echo $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>       </li>
      <li><label> <?php
        if (empty($$class->inv_serial_number_id)) {
         echo '<i class="select_item_number select_popup clickable fa fa-search"></i>';
        }
        ?> <?php echo gettext('Item Number') ?></label>
       <?php echo $f->hidden_field_withId('item_id_m', $$class->item_id_m); ?>
       <?php
       if (empty($$class->inv_serial_number_id)) {
        $f->text_field_d('item_number', 'select_item_number');
       } else {
        $f->text_field_dr('item_number');
       }
       ?>
      </li>
      <li><?php $f->l_text_field_dr('item_description'); ?></li>
      <li><?php $f->l_text_field_d('serial_number'); ?></li>
      <li><?php $f->l_select_field_from_object('status', inv_serial_number::serail_status(), 'option_line_code', 'option_line_value', $$class->status, 'status', '', 1, 1); ?>       </li>
      <li><?php $f->l_select_field_from_array('generation', item::$ls_generation_a, $$class->generation, '', 'generation', '', 1, 1); ?>       </li> 
      <li><?php $f->l_text_field_d('description'); ?> 					</li>
     </ul>
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
       $reference_table = 'inv_serial_number';
       $reference_id = $$class->inv_serial_number_id;
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
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Serial Number Details') ?> </span>
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
      <ul class="column header_field"> 
       <li><?php $f->l_select_field_from_array('origination_type', inv_serial_number::$origination_type_a, $$class->origination_type, 'origination_type', '', 1, 1, 1); ?>             </li>
       <li><?php $f->l_date_fieldAnyDay_r('origination_date', $$class->origination_date, 1); ?></li>
       <li><?php $f->l_date_fieldAnyDay_r('activation_date', $$class->activation_date, 1); ?>       </li>
       <li><?php $f->l_select_field_from_object('current_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->current_org_id, 'current_org_id', '', '', 1); ?>       </li>
       <li><?php $f->l_select_field_from_object('current_subinventory_id', subinventory::find_all_of_org_id($$class->current_org_id), 'subinventory_id', 'subinventory', $$class->current_subinventory_id, 'current_subinventory_id', 'subinventory_id', '', 1); ?>			</li>
       <li><?php $f->l_select_field_from_object('current_locator_id', locator::find_all_of_subinventory($$class->current_subinventory_id), 'locator_id', 'locator', $$class->current_locator_id, '', 'locator_id', '', 1); ?>       </li>
       <li><?php $f->l_text_field_dr('inv_lot_number_id'); ?>             </li>
       <li><?php $f->l_text_field_d('country_of_origin'); ?>             </li>
       <li><?php $f->l_text_field_dr('parent_serial_number_id'); ?>             </li>
      </ul> 
     </div> 
    </div> 
    <div id="tabsLine-2" class="tabContent">
     <div> 
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr('supplier_site_id'); ?>             </li>
       <li><?php $f->l_text_field_dr('po_header_id'); ?>             </li>
       <li><?php $f->l_text_field_dr('supplier_sn'); ?>             </li>
       <li><?php $f->l_text_field_dr('supplier_ln'); ?>             </li>
       <li><?php $f->l_text_field_dr('first_inv_transaction_id'); ?>             </li>
       <li><?php $f->l_text_field_dr('last_inv_transaction_id'); ?>             </li>
       <li><?php $f->l_text_field_dr('ar_customer_site_id'); ?>             </li>
       <li><?php $f->l_text_field_dr('original_wip_wo_header_id'); ?>             </li>
       <li><?php $f->l_text_field_dr('current_wip_wo_header_id'); ?>             </li>
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
             <th><?php echo gettext('Serial Number') ?></th>
             <th><?php echo gettext('Item Number') ?></th>
             <th><?php echo gettext('Item Description') ?></th>
             <th><?php echo gettext('Org Id') ?></th>
             <th><?php echo gettext('Transaction Type') ?></th>
             <th><?php echo gettext('From Subinventory') ?></th>
             <th><?php echo gettext('From Locator') ?></th>
             <th><?php echo gettext('Transaction Details') ?></th>
            </tr>
           </thead>
           <tbody class="form_data_line_tbody inv_serial_transaction_entries_values" >
            <?php
            $count = 0;
            foreach ($inv_serial_transaction_object as $inv_serial_transaction_v) {
             $class_second = 'inv_serial_transaction_v';
             ?>         
             <tr class="inv_serial_transaction_entries<?php echo $count ?>">
              <td><?php $f->text_field_wid2r('serial_number'); ?></td>
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
             <th><?php echo gettext('To SubInv') ?></th>
             <th><?php echo gettext('To Locator') ?></th>
             <th><?php echo gettext('Transaction Id') ?></th>
             <th><?php echo gettext('Transaction Type Id') ?></th>
             <th><?php echo gettext('From SubInv Id') ?></th>
             <th><?php echo gettext('From Locator Id') ?> </th>
             <th><?php echo gettext('To SubInv Id') ?></th>
             <th><?php echo gettext('To Locator Id') ?> </th>
            </tr>
           </thead>
           <tbody class="form_data_line_tbody inv_serial_transaction_entries_values" >
            <?php
            $count = 0;
            foreach ($inv_serial_transaction_object as $inv_serial_transaction_v) {
             $class_second = 'inv_serial_transaction_v';
             ?>         
             <tr class="inv_serial_transaction_entries<?php echo $count ?>">
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
        if (!empty($parent_serial)) {
         echo "Serial Number : <a class='button' href=\"form.php?class_name=inv_serial_number&mode=9&inv_serial_number_id=$parent_serial->inv_serial_number_id\"> $parent_serial->serial_number </a> & Item Id :  $parent_serial->item_id_m <br>";
        } else {
         echo "No Parent";
        }
        ?>            
       </li>
       <li class="simple_box current full_width"><label><?php echo gettext('Current') ?> </label> 
        <?php echo!empty($$class->serial_number) ? " Serial Number : " . $$class->serial_number . "& Item Id :  " . $$class->item_id_m : 'No Serial'; ?>            
       </li>
       <li class="simple_box child full_width"><label><?php echo gettext('Child') ?> </label> 
        <?php
        if (!empty($child_serial)) {
         foreach ($child_serial as $child) {
          echo " Serial Number : <a class='button' href=\"form.php?class_name=inv_serial_number&mode=9&inv_serial_number_id=$child->inv_serial_number_id\"> $child->serial_number </a> & Item Id :  $child->item_id_m <br>";
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
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="inv_serial_number" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="inv_serial_number_id" ></li>
  <li class="form_header_id" data-form_header_id="inv_serial_number" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="inv_serial_number_id" ></li>
  <li class="btn1DivId" data-btn1DivId="inv_serial_number_id" ></li>
 </ul>
</div>
