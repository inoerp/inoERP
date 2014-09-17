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
       <form action=""  method="post" id="inv_count_header"  name="inv_count_header"><span class="heading">Count Entry Header </span>
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Line Defaults</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column four_column">
             <li><label>Count Date : </label>
              <?php echo $f->date_fieldFromToday_d('count_date', $$class->count_date, 1) ?>
             </li>
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="inv_count_header_id select_popup clickable">
               Inventory Count Name : </label> <?php echo $f->hidden_field_withId('inv_count_header_id', $inv_count_header_id_h); ?>
              <?php $f->text_field_dm('count_name'); ?>
              <a name="show" class="show inv_count_header_id clickable"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a></li>
             <li><label>Inventory: </label>
              <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>
             </li>
             <li><label>Description : </label> <?php echo $f->text_field_dl('description'); ?></li>
            </ul>
           </div>
          </div>
          <div id="tabsHeader-2" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column three_column">
             <li><label>Adjustment A/C : </label> <?php echo $f->ac_field_dm('adjustment_ac_id'); ?></li>
             <li><label>Counted By : </label> <?php $f->text_field_d('counted_by'); ?></li>
             </u>
           </div>
          </div>
         </div>
        </div>
       </form>
      </div>

      <div id ="form_line" class="form_line"><span class="heading">Count Entries </span>
       <div id="tabsLine">
        <ul class="tabMain">
         <li><a href="#tabsLine-1">Schedule </a></li>
         <li><a href="#tabsLine-2">Reference </a></li>
         <li><a href="#tabsLine-3">Adjustments </a></li>
        </ul>
        <div class="tabContainer"> 
         <form action=""  method="post" id="inv_count_entries_line"  name="inv_count_entries_line">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>Count Id</th>
              <th>Master Item Id </th>
              <th>Item Number</th>
              <th>Item Description</th>
              <th>UOM</th>
              <th>Schedule Date</th>
              <th>Subinventory</th>
              <th>Locator</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody inv_count_entries_values" >
             <?php
             $count = 0;
             foreach ($inv_count_schedule_object as $inv_count_schedule) {
              ?>         
              <tr class="inv_count_entries<?php echo $count ?>">
               <td>    
                <ul class="inline_action">
                 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($inv_count_schedule->inv_count_schedule_id); ?>"></li>           
                 <li><?php echo form::hidden_field('inv_count_header_id', $inv_count_header_id_h); ?>
                  <?php echo form::hidden_field('org_id', $$class->org_id); ?>
                 </li>
                </ul>
               </td>
               <td><?php $f->text_field_d2srm('inv_count_schedule_id'); ?></td>
               <td><?php $f->text_field_d2sr('item_id_m'); ?></td>
               <td><?php $f->text_field_wid2('item_number', 'select_item_number'); ?> <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number_only select_popup"></td>
               <td><?php $f->text_field_wid2('item_description'); ?></td>
               <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small','',1); ?></td>
               <td><?php echo $f->date_fieldAnyDay('schedule_date', $$class_second->schedule_date); ?></td>
               <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->subinventory_id, '', 'subinventory_id', '', 1); ?></td>
               <td><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_second->subinventory_id), 'locator_id', 'locator', $$class_second->locator_id, '', 'locator_id', '', 1); ?></td>
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
              <th>Count Id</th>
              <th>Description</th>
              <th>Lot Number </th>
              <th>Serial Number</th>
              <th>Count By</th>
              <th>Count Date</th>
              <th>Adjustment Ac</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody inv_count_entries_values" >
             <?php
             $count = 0;
             foreach ($inv_count_schedule_object as $inv_count_schedule) {
              ?>         
              <tr class="inv_count_entries<?php echo $count ?>">
               <td class="text_not_tobe_copied"><?php echo $$class_second->inv_count_schedule_id; ?></td>
               <td><?php $f->text_field_wid2('description'); ?></td>
               <td><?php $f->text_field_wid2('lot_number'); ?></td>
               <td><?php $f->text_field_wid2('serial_number'); ?></td>
               <td><?php echo $f->text_field('counted_by', ''); ?></td>
               <td><?php echo $f->date_fieldFromToday_d('count_date', ''); ?></td>
               <td><?php $f->ac_field_wid('adjustment_ac_id'); ?></td>
              </tr>
              <?php
              $count = $count + 1;
             }
             ?>
            </tbody>
           </table>
          </div>
          <div id="tabsLine-3" class="tabContent">
           <table class="form_table">
            <thead> 
             <tr>
              <th>Count Id</th>
              <th>System Quantity</th>
              <th>Counted Quantity</th>
              <th>Adjusted Quantity</th>
              <th>Adjustment Amount</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody inv_count_entries_values" >
             <?php
             $count = 0;
             foreach ($inv_count_schedule_object as $inv_count_schedule) {
              ?>         
              <tr class="inv_count_entries<?php echo $count ?>">
               <td class="text_not_tobe_copied"><?php echo $$class_second->inv_count_schedule_id; ?></td>
               <td><?php echo $f->text_field_ap(array('name'=>'system_qty', 'value'=>'', 'readonly'=>1)); ?></td>
               <td><?php echo $f->text_field('count_qty', ''); ?></td>
               <td><?php echo $f->text_field_ap(array('name'=>'adjusted_qty', 'value'=>'', 'readonly'=>1)); ?></td>
               <td><?php echo $f->text_field_ap(array('name'=>'adjusted_value', 'value'=>'', 'readonly'=>1)); ?></td>
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