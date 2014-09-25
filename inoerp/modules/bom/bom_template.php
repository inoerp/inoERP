<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="bom_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
       echo (!empty($show_message)) ? $show_message : "";
       $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->

      <div id ="form_header">
       <form action=""  method="post" id="bom_header"  name="bom_header"><span class="heading">BOM Header </span>
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Details</a></li>
          <li><a href="#tabsHeader-3">Common BOM</a></li>
          <li><a href="#tabsHeader-4">Notes</a></li>
          <li><a href="#tabsHeader-5">Attachment</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column four_column">
             <li><label>Org Name(1) : </label>
              <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $bom_header->org_id, 'org_id', $readonly, '', ''); ?>
             </li>
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bom_header_id select_popup clickable">
               Item Number(2) : </label> 
              <?php echo $f->hidden_field_withId('bom_header_id', $$class->bom_header_id); ?> 
              <?php echo $f->hidden_field_withId('item_id_m', $$class->item_id_m); ?>
              <?php $f->text_field_dm('item_number', 'select_item_number_allowedBOM'); ?>
              <a name="show" class="show item_id_m clickable"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label>UOM : </label>
              <?php echo $f->select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom_id','uom_id'); ?>
             </li>
             <li><label>Description: </label>
              <?php $f->text_field_dr('item_description'); ?>
             </li>
            </ul>
           </div>
          </div>
          <div id="tabsHeader-2" class="tabContent">
           <div> 
            <ul class="column five_column">
             <li><label>Alternate Bom : </label>  <?php echo $f->text_field_d('alternate_bom'); ?>   </li>
             <li><label>Revision : </label>    <?php echo $f->text_field_ap(array('name' => 'bom_revision', 
              'value' => $$class->bom_revision, 'readonly' => $readonly1)); ?>     </li>
             <li><label>Effective Date : </label>
              <?php echo $f->date_fieldAnyDay_r('effective_date', $$class->effective_date, $readonly1); ?>
             </li>
             <li><label>BOM Header Id : </label>  <?php echo $f->text_field_dsr('bom_header_id'); ?>   </li>
            </ul>
           </div>
          </div>
          <div id="tabsHeader-3" class="tabContent">
           <div> 
            <ul class="column five_column">
             <li><label>Org Name : </label>
              <?php echo $f->select_field_from_object('common_bom_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->common_bom_org_id, 'common_bom_org_id', '', '', $readonly); ?>
             </li>
             <li><label>Item Number : </label>
              <?php echo $f->hidden_field_withIdClass('common_bom_item_id_m', $$class->common_bom_item_id_m, 'item_id_m'); ?>
              <?php $f->text_field_d('commonBom_item_number', 'select_item_number'); ?>  </li>
             <li><label>Description: </label><?php $f->text_field_d('commonBom_item_description', 'item_description'); ?>  </li>
            </ul>
           </div>
          </div>
          <div id="tabsHeader-4" class="tabContent">
           <div id="comments">
            <div id="comment_list">
             <?php echo!(empty($comments)) ? $comments : ""; ?>
            </div>
            <div id ="display_comment_form">
             <?php
              $reference_table = 'bom_header';
              $reference_id = $$class->bom_header_id;
             ?>
            </div>
            <div id="new_comment">
            </div>
           </div>
          </div>
          <div id="tabsHeader-5" class="tabContent">
           <div> <?php echo ino_attachement($file) ?> </div>
          </div>
         </div>

        </div>
       </form>
      </div>

      <div id="form_line" class="form_line"><span class="heading">BOM Lines </span>
       <form action=""  method="post" id="bom_line"  name="bom_line">
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Main</a></li>
          <li><a href="#tabsLine-2">Effectivity</a></li>
          <li><a href="#tabsLine-3">Control</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>BOM Line Id</th>
              <th>BOM Sequence</th>
              <th>Routing Sequence</th>
              <th>Item Id</th>
              <th>Item Number</th>
              <th>Item Description</th>
              <th>UOM</th>
              <th>Usage Basis</th>
              <th>Quantity</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($bom_line_object as $bom_line) {
//							echo $count . ' is         : <pre>';
//							print_r($bom_line);
               ?>         
               <tr class="bom_line<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->bom_line_id); ?>"></li>           
                  <li><?php echo form::hidden_field('bom_header_id', $bom_header->bom_header_id); ?></li>
                  <li><?php echo $f->hidden_field('bom_commonbom_line_id', $$class_second->bom_commonbom_line_id); ?></li>
                 </ul>
                </td>
                <td><?php form::text_field_wid2sr('bom_line_id'); ?></td>
                <td><?php $f->text_field_d2s('bom_sequence', 'lines_number'); ?></td>
                <td><?php echo!empty($routing_line_details) ? form::select_field_from_object('routing_sequence', $routing_line_details, 'bom_routing_line_id', 'routing_sequence', $$class_second->routing_sequence, '', $readonly, 'usage_basis', '', 1) : form::text_field_wid2sm('routing_sequence'); ?></td>
                <td><?php $f->text_field_wid2sr('component_item_id_m', 'item_id_m'); ?></td>
                <td><?php $f->text_field_wid2('component_item_number', 'select_item_number'); ?>
                 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></td>
                <td><?php $f->text_field_wid2('component_description', 'item_description'); ?></td>
                <td><?php
                 echo $f->select_field_from_object('component_uom', uom::find_all(), 'uom_id', 'uom_name', $$class_second->component_uom, '', '', '', $readonly);
                 ?></td>
                <td><?php echo form::select_field_from_object('usage_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_second->usage_basis, '', $readonly, 'usage_basis', '', 1); ?></td>
                <td><?php form::number_field_wid2s('usage_quantity'); ?></td>

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
              <th>Start Date</th>
              <th>End Date</th>
              <th>ECO Number</th>
              <th>ECO implemented</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($bom_line_object as $bom_line) {
               ?>         
               <tr class="bom_line<?php echo $count ?>">
                <td><?php echo form::date_fieldAnyDay('effective_start_date', $$class_second->effective_start_date); ?></td>
                <td><?php echo form::date_fieldAnyDay('effective_end_date', $$class_second->effective_end_date); ?></td>
                <td><?php form::text_field_wid2('eco_number'); ?></td>
                <td>
                 <?php echo form::checkBox_field('eco_implemented_cb', $$class_second->eco_implemented_cb, 'eco_implemented_cb', $readonly); ?>
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
          <div id="tabsLine-3" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Planning %</th>
              <th>Yield</th>
              <th>WIP Supply Type</th>
              <th>Sub inventory</th>
              <th>Locator</th>
              <th>In cost rollup</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($bom_line_object as $bom_line) {
               ?>         
               <tr class="bom_line<?php echo $count ?>">
                <td><?php form::text_field_wid2('planning_percentage'); ?></td>
                <td><?php form::text_field_wid2('yield'); ?></td>
                <td><?php echo form::select_field_from_object('wip_supply_type', bom_header::wip_supply_type(), 'option_line_code', 'option_line_value', $$class_second->wip_supply_type, '', $readonly, '', '', ''); ?></td>
                <td><?php echo form::select_field_from_object('supply_sub_inventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->supply_sub_inventory, '', $readonly, 'subinventory_id', '', ''); ?></td>
                <td><?php echo form::select_field_from_object('supply_locator', locator::find_all_of_subinventory($$class_second->supply_sub_inventory), 'locator_id', 'locator', $$class_second->supply_locator, '', $readonly, 'locator_id', '', ''); ?></td>
                <td>
                 <?php echo form::checkBox_field('include_in_cost_rollup_cb', $$class_second->include_in_cost_rollup_cb, 'include_in_cost_rollup_cb', $readonly); ?>
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
  <div id="content_right_right"></div>
 </div>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="bom_header" ></li>
  <li class="lineClassName" data-lineClassName="bom_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="bom_header_id" ></li>
  <li class="form_header_id" data-form_header_id="bom_header" ></li>
  <li class="line_key_field" data-line_key_field="component_item_id_m" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="bom_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bom_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bom_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>
