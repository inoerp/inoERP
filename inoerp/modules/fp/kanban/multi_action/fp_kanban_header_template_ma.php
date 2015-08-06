<div id="fp_kanban_header_divId">
 <div class="row small-top-margin" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
  <div id ="searchResult">
   <form  method="post" id="fp_kanban_header"  name="fp_kanban_header">
    <div id ="form_line" class="form_line"><span class="heading">Kanban Strategy </span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1">Basics</a></li>
       <li><a href="#tabsLine-2">Planning</a></li>
       <li><a href="#tabsLine-3">Supply</a></li>
      </ul>
      <div class="tabContainer">
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th>Action</th>
           <th>Seq</th>
           <th>Kanban Id</th>
           <th>Org Id</th>
           <th>Item Number</th>
           <th>Item Description</th>
           <th>Description</th>
           <th>Subinventory</th>
           <th>Locator</th>
           <th>Source Type</th>
           <th>Calculate</th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          $f = new inoform();
          if (!empty($search_result)) {
           foreach ($search_result as $fp_kanban_header) {
            if (!empty($$class->item_id_m)) {
             $item_i = item::find_by_item_id_m($$class->item_id_m);
             $$class->item_number = $item_i->item_number;
             $$class->item_description = $item_i->item_description;
            } else {
             $$class->item_number = null;
             $$class->item_description = null;
            }
            ?>         
            <tr class="fp_kanban_header_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($fp_kanban_header->fp_kanban_header_id); ?>"></li>           
              </ul>
             </td>
             <td><?php $f->seq_field_d($count); ?></td>
             <td><?php $f->text_field_widsr('fp_kanban_header_id') ?></td>
             <td><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', '', ''); ?>         </td>
             <td><?php
              $f->val_field_widm('item_number', 'item', 'item_number', 'org_id');
              echo $f->hidden_field_withCLass('item_id_m', $$class->item_id_m, 'dont_copy_r');
              echo $f->hidden_field_withCLass('stockable_cb', '1', 'popup_value');
              ?>
              <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
             <td><?php $f->text_field_d('item_description'); ?></td>
             <td><?php $f->text_field_d('description'); ?></td>
             <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->subinventory_id, 'kanban_subinventory_id', 'kanban_subinventory_id', '', $readonly); ?>         </td>
             <td><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class->subinventory_id), 'locator_id', 'locator', $$class->locator_id, 'locator_id', 'locator_id kanban_subinventory_id', '', $readonly); ?>         </td>
             <td><?php echo $f->select_field_from_array('source_type', fp_kanban_header::$source_type_a, $$class->source_type, 'source_type', 'medium'); ?></td>
             <td><?php echo $f->select_field_from_array('calculate', fp_kanban_header::$calculate_a, $$class->calculate, 'calculate', 'medium'); ?></td>
             <?php
             $count = $count + 1;
            }
           }
           ?>
         </tbody>
        </table>
       </div>
       <div id="tabsLine-2" class="scrollElement" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th>Seq</th>
           
           <th>Card Size</th>
           <th># of Cards</th>
           <th>MOQ</th>
           <th>Lead Time</th>
           <th>Allocation %</th>
           <th>FLM</th>
           <th>SSD</th>
           <th>Planning Only</th>
           <th>Auto Request</th>
           
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $fp_kanban_header) {
            ?>         
            <tr class="fp_kanban_header_line<?php echo $count ?>">
             <td><?php $f->seq_field_d($count); ?></td>
             
             <td><?php $f->number_field_d('card_size'); ?></td> 
             <td><?php $f->number_field_d('noof_card'); ?></td> 
             <td><?php $f->number_field_d('moq'); ?></td> 
             <td><?php $f->number_field_d('lead_time'); ?></td> 
             <td><?php $f->number_field_d('allocation_per'); ?></td> 
             <td><?php $f->number_field_d('flm'); ?></td> 
             <td><?php $f->number_field_d('ssd'); ?></td> 
             <td><?php $f->checkBox_field_d('planning_only_cb'); ?></td> 
             <td><?php $f->checkBox_field_d('auto_request_cb'); ?></td> 
             
            </tr>
            <?php
            $count = $count + 1;
           }
          }
          ?>
         </tbody>
         <!--                  Showing a blank form for new entry-->

        </table>
       </div>
       <div id="tabsLine-3" class="scrollElement" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th>Seq</th>
           <th>From Org</th>
           <th>From SubInv</th>
           <th>From Locator</th>
           <th>Supplier</th>
           <th>Supplier Site</th>
           <th>RFID Reference</th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $fp_kanban_header) {
                       if (!empty($$class->supplier_id)) {
            $supplier_i = supplier::find_by_id($$class->supplier_id);
            $$class->supplier_name = $supplier_i->supplier_name;
           } else {
            $$class->supplier_name = null;
           }
            ?>         
            <tr class="fp_kanban_header_line<?php echo $count ?>">
             <td><?php $f->seq_field_d($count); ?></td>
             <td><?php echo $f->select_field_from_object('from_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->from_org_id, 'from_org_id', 'org_id', '', $readonly); ?>         </td>
             <td><?php echo $f->select_field_from_object('from_subinventory_id', subinventory::find_all_of_org_id($$class->from_org_id), 'from_subinventory_id', 'subinventory', $$class->from_subinventory_id, 'from_subinventory_id', 'from_subinventory_id', '', $readonly); ?>         </td>
             <td><?php echo $f->select_field_from_object('from_locator_id', locator::find_all_of_subinventory($$class->from_subinventory_id), 'locator_id', 'locator', $$class->from_locator_id, 'from_locator_id', 'locator_id from_subinventory_id', '', $readonly); ?>         </td>
             <td><?php
              echo $f->val_field_d('supplier_name', 'supplier', 'supplier_name', '', 'supplier_name', 'vf_select_supplier_name');
              echo $f->hidden_field_withId('supplier_id', $$class->supplier_id);
              ?><i class="generic g_select_supplier_name select_popup clickable fa fa-search" data-class_name="supplier"></i></td>
             <td><?php
              $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
              echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id');
              ?> </td>
             <td><?php $f->text_field_d('rfid_reference'); ?></td>
            </tr>
            <?php
            $count = $count + 1;
           }
          }
          ?>
         </tbody>
         <!--                  Showing a blank form for new entry-->

        </table>
       </div>
      </div>
     </div>
    </div> 
   </form>
  </div>
 </div>
 <!--END OF FORM HEADER-->
 <div class="row small-top-margin">
  <div id="pagination" style="clear: both;">
   <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
   ?>
  </div>
 </div>

</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fp_kanban_header" ></li>
  <li class="lineClassName" data-lineClassName="fp_kanban_header" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="fp_kanban_header" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="fp_kanban_header"></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
