<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id="am_wo_divId">
 <div id="form_all">
  <div id ="form_header"><span class="heading"><?php
    echo gettext('Maintenance Work Order')
    ?></span>
   <form  method="post" id="am_wo_header"  name="am_wo_header">
    <div id="tabsHeader">
     <ul class="tabMain">
      <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
      <li><a href="#tabsHeader-2"><?php echo gettext('Planning') ?></a></li>
      <li><a href="#tabsHeader-3"><?php echo gettext('History') ?></a></li>
      <li><a href="#tabsHeader-4"><?php echo gettext('BOM & Routing') ?></a></li>
      <li><a href="#tabsHeader-5"><?php echo gettext('Notes') ?></a></li>
      <li><a href="#tabsHeader-6"><?php echo gettext('Attachments') ?></a></li>
     </ul>
     <div class="tabContainer">
      <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field">
        <li><?php $f->l_text_field_dr_withSearch('am_wo_header_id'); ?>
         <a name="show" href="form.php?class_name=am_wo_header&<?php echo "mode=$mode"; ?>" class="show document_id am_wo_header_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', '', $readonly); ?>         </li>
        <li><?php $f->l_text_field_d('wo_number', 'primary_column2'); ?> </li>
        <li><?php $f->l_select_field_from_object('wo_type', am_wo_header::am_wo_type(), 'option_line_code', 'option_line_value', $$class->wo_type, 'wo_type', '', 1, $readonly); ?>         </li>
        <li><label><?php echo gettext('Accounting Group') ?></label><?php echo $f->select_field_from_object('wip_accounting_group_id', wip_accounting_group::find_by_woType('NON_STANDARD'), 'wip_accounting_group_id', ['wip_accounting_group', 'org_id'], $$class->wip_accounting_group_id, 'wip_accounting_group_id', '', 1, 'readonly1', '', '', '', 'org_id'); ?>         </li>
        <li><label><?php echo gettext('Asset Number') ?></label><?php
         $f->text_field_dm('am_asset_number');
         echo $f->hidden_field_withId('am_asset_id', $$class->am_asset_id);
         echo $f->hidden_field_withId('item_id_m', $$class->item_id_m);
         ?><i class="select_am_asset_number select_popup clickable fa fa-search"></i>
        </li>
        <li><?php
         $f->l_text_field_dm('activity_item_number', 'select_item_number_am_asset_activity');
         echo $f->hidden_field_withId('activity_item_id_m', $$class->activity_item_id_m);
         echo $f->hidden_field_withCLass('am_asset_type', 'ASSET_ACTIVITY', 'popup_value');
         ?><i class="fa fa-search select_item_number select_popup"></i></li>
        <li><label><?php echo gettext('Owning Department') ?></label><?php echo $f->select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class->department_id, 'department_id', '', '', $readonly); ?></li>
        <li><label><?php echo gettext('Status') ?></label>                      
         <span class="button"><?php echo!empty($$class->wo_status) ? $$class->wo_status : "NA"; ?></span>
        </li>
       </ul>
      </div>
      <div id="tabsHeader-2" class="tabContent">
       <div> 
        <ul class="column header_field">
         <li id="document_status">
          <?php $f->l_select_field_from_array('wo_status', am_wo_header::$wo_status_a, $$class->wo_status, 'wo_status', '', '', 1); ?>         </li>
         <li><?php $f->l_date_fieldFromToday_m('start_date', $$class->start_date) ?></li>
         <li><?php $f->l_date_fieldFromToday('completion_date', $$class->completion_date) ?></li>
         <li><?php $f->l_number_field('quantity', $$class->quantity); ?> </li>
         <li><?php $f->l_text_field_d('schedule_group'); ?> </li>
         <li><?php $f->l_text_field_d('line'); ?> </li>
         <li><?php $f->l_number_field_d('scheduling_priority'); ?> </li>
        </ul>
       </div>
      </div>
      <div id="tabsHeader-3" class="tabContent">
       <div> 
        <ul class="column header_field">
         <li><?php $f->l_text_field_d('released_date', $$class->released_date) ?></li>
         <li><?php $f->l_text_field_dr('cycle'); ?> </li>
         <li><?php $f->l_text_field_dr('cycle_interval'); ?> </li>
         <li><?php $f->l_text_field_dr('am_maintenance_schedule_id'); ?> </li>
        </ul>
       </div>
      </div>
      <div id="tabsHeader-4" class="tabContent">
       <div> 
        <ul class="column header_field">
         <li><?php $f->l_text_field_d('reference_bom_item_id_m'); ?> </li>
         <li><?php $f->l_text_field_d('reference_routing_item_id_m'); ?> </li>
         <li><?php $f->l_checkBox_field_d('bom_exploded_cb'); ?> </li>
         <li><?php $f->l_checkBox_field_d('routing_exploded_cb'); ?> </li>
         <li><?php $f->l_select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class->department_id, '', $readonly, '', '', 1); ?></li>
        </ul>
       </div>
      </div>
      <div id="tabsHeader-5" class="tabContent">
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'am_wo_header';
         $reference_id = $$class->am_wo_header_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
      <div id="tabsHeader-6" class="tabContent">
       <div> <?php echo ino_attachement($file) ?> </div>
      </div>

     </div>

    </div>
   </form>
  </div>
  <span class="heading"><?php echo gettext('Work Order Details') ?> </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Routing') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Routing-2') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Routing - Data Collection') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('BOM') ?></a></li>
    <li><a href="#tabsLine-5"><?php echo gettext('BOM-2') ?> </a></li>
   </ul>
   <div class="tabContainer"> 
    <form action=""  method="post" id="am_wo_routing_line"  name="am_wo_routing_line">
     <div id ="form_line" class="form_line">
      <div id="tabsLine-1" class="tabContent">
       <table class="form_line_data_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('WO Routing Id') ?></th>
          <th><?php echo gettext('BOM Sequence') ?></th>
          <th><?php echo gettext('Department') ?></th>
          <th><?php echo gettext('Description') ?></th>
          <th><?php echo gettext('Count Point') ?></th>
          <th><?php echo gettext('Auto Charge') ?></th>
          <th><?php echo gettext('Back flush') ?></th>
          <th><?php echo gettext('MTQ') ?></th>
          <th><?php echo gettext('Resource Details') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody am_wo_routing_line_values" >
         <?php
         $count = 0;
         foreach ($am_wo_routing_line_object as $am_wo_routing_line) {
          ?>         
          <tr class="am_wo_routing_line<?php echo $count ?>">
           <td>
            <?php
            echo ino_inline_action($am_wo_routing_line->am_wo_routing_line_id, array('am_wo_header_id' => $$class->am_wo_header_id));
            ?>
           </td>
           <td><?php $f->text_field_wid2sr('am_wo_routing_line_id'); ?></td>
           <td><?php form::number_field_wid2s('routing_sequence'); ?></td>
           <td><?php echo form::select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class_second->department_id, 'department_id', $readonly); ?></td>
           <td><?php $f->text_field_wid2('description'); ?></td>
           <td><?php echo form::checkBox_field('count_point_cb', $$class_second->count_point_cb); ?></td>
           <td><?php echo form::checkBox_field('auto_charge_cb', $$class_second->auto_charge_cb); ?></td>
           <td><?php echo form::checkBox_field('backflush_cb', $$class_second->backflush_cb); ?></td>
           <td><?php form::number_field_wid2('minimum_transfer_quantity'); ?></td>
           <td class="add_detail_values"><i class="fa fa-arrow-circle-down add_detail_values_img"></i>
            <!--</td></tr>-->	
            <?php
            $am_wo_routing_line_id = $am_wo_routing_line->am_wo_routing_line_id;
            if (!empty($am_wo_routing_line_id)) {
             $am_wo_routing_detail_object = am_wo_routing_detail::find_by_wipWo_lineId($am_wo_routing_line_id);
            } else {
             $am_wo_routing_detail_object = array();
            }
            if (count($am_wo_routing_detail_object) == 0) {
             $am_wo_routing_detail = new am_wo_routing_detail();
             $am_wo_routing_detail_object = array();
             array_push($am_wo_routing_detail_object, $am_wo_routing_detail);
            }
            ?>
            <div class="class_detail_form">
             <fieldset class="form_detail_data_fs"><legend><?php echo gettext('Detail Data') ?></legend>
              <div class="tabsDetail">
               <ul class="tabMain">
                <li class="tabLink"><a href="#tabsDetail-1-1"><?php echo gettext('Resource') ?></a></li>
                <li class="tabLink"><a href="#tabsDetail-2-1"><?php echo gettext('Quantities') ?></a></li>
               </ul>
               <div class="tabContainer">
                <div id="tabsDetail-1-1" class="tabContent">
                 <table class="form form_detail_data_table detail">
                  <thead>
                   <tr>
                    <th><?php echo gettext('Action') ?></th>
                    <th><?php echo gettext('DetailId') ?></th>
                    <th><?php echo gettext('Resource Sequence') ?></th>
                    <th><?php echo gettext('Resource') ?></th>
                    <th><?php echo gettext('Usage Basis') ?></th>
                    <th><?php echo gettext('Usage') ?></th>
                    <th><?php echo gettext('Schedule') ?></th>
                    <th><?php echo gettext('Units') ?></th>
                    <th><?php echo gettext('Rate') ?></th>
                    <th><?php echo gettext('Charge Type') ?></th>
                   </tr>
                  </thead>
                  <tbody class="form_data_detail_tbody">
                   <?php
                   $detailCount = 0;
                   foreach ($am_wo_routing_detail_object as $am_wo_routing_detail) {
                    $class_third = 'am_wo_routing_detail';
                    $$class_third = &$am_wo_routing_detail;
                    ?>
                    <tr class="am_wo_routing_detail<?php echo $count . '-' . $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
                     <td><?php
                      echo ino_inline_action($$class_third->am_wo_routing_detail_id, array('am_wo_header_id' => $$class->am_wo_header_id,
                       'am_wo_routing_line_id' => $$class_second->am_wo_routing_line_id), 'add_row_detail_img', 'detail_id_cb');
                      ?>                       </td>
                     <td><?php $f->text_field_wid3sr('am_wo_routing_detail_id'); ?></td>
                     <td><?php $f->text_field_wid3sm('resource_sequence', 'seq_number'); ?></td>
                     <td><?php echo $f->select_field_from_object('resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_third->resource_id, '', '', 1, $readonly); ?></td>
                     <td><?php echo $f->select_field_from_object('charge_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_third->charge_basis, '', 'small', 1, $readonly); ?></td>
                     <td><?php form::number_field_wid3sm('resource_usage') ?></td>
                     <td><?php echo form::select_field_from_object('resource_schedule', bom_header::bom_schedule_option(), 'option_line_code', 'option_line_value', $$class_third->resource_schedule, '', $readonly, 'default_basis', '', 1); ?></td>
                     <td><?php form::number_field_wid3s('assigned_units') ?></td>
                     <td><?php echo form::checkBox_field('standard_rate_cb', $$class_third->standard_rate_cb); ?></td>
                     <td><?php echo form::select_field_from_object('charge_type', bom_resource::charge_type(), 'option_line_code', 'option_line_value', $$class_third->charge_type, '', $readonly, '', '', 1); ?></td>
                    </tr>
                    <?php
                    $detailCount++;
                   }
                   ?>
                  </tbody>
                 </table>
                </div>
                <div id="tabsDetail-2-1" class="tabContent">
                 <table class="form form_detail_data_table detail">
                  <thead>
                   <tr>
                    <th><?php echo gettext('Required Qty') ?></th>
                    <th><?php echo gettext('Applied Qty') ?></th>
                    <th><?php echo gettext('Open Qty') ?></th>
                   </tr>
                  </thead>
                  <tbody class="form_data_detail_tbody">
                   <?php
                   $detailCount = 0;
                   foreach ($am_wo_routing_detail_object as $am_wo_routing_detail) {
                    $class_third = 'am_wo_routing_detail';
                    $$class_third = &$am_wo_routing_detail;
                    $$class_third->open_quantity = $$class_third->required_quantity - $$class_third->applied_quantity;
                    ?>
                    <tr class="am_wo_routing_detail<?php echo $count . '-' . $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
                     <td><?php form::number_field_wid3s('required_quantity'); ?></td>
                     <td><?php form::number_field_wid3sr('applied_quantity'); ?></td>
                     <td><?php form::number_field_wid3sr('open_quantity'); ?></td>

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

      <div id="tabsLine-2" class="tabContent">
       <table class="form_line_data_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Queue') ?></th>
          <th><?php echo gettext('Running') ?></th>
          <th><?php echo gettext('Rejected') ?></th>
          <th><?php echo gettext('To Move') ?></th>
          <th><?php echo gettext('Start Date') ?></th>
          <th><?php echo gettext('Completion Date') ?></th>
          <th><?php echo gettext('Progress') ?>%</th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody am_wo_routing_line_values" >
         <?php
         $count = 0;
         foreach ($am_wo_routing_line_object as $am_wo_routing_line) {
          ?>         
          <tr class="am_wo_routing_line<?php echo $count ?>">
           <td><?php form::text_field_wid2sr('queue_quantity'); ?></td>
           <td><?php form::number_field_wid2sr('running_quantity'); ?></td>
           <td><?php form::text_field_wid2sr('rejected_quantity'); ?></td>
           <td><?php form::number_field_wid2sr('tomove_quantity'); ?></td>
           <td><?php echo form::date_fieldFromToday('start_date', ino_date($$class_second->start_date)); ?></td>
           <td><?php echo form::date_fieldFromToday('completion_date', ino_date($$class_second->completion_date)); ?></td>
           <td><?php form::text_field_wid2sr('completed_quantity'); ?></td>
          </tr>
          <?php
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>

      <div id="tabsLine-3" class="tabContent">
       <?php
       $extra_element_label = 'Data Collection Element';
       $class_name_object = $am_wo_routing_line_object;
       $ef_refer_key = 'am_wo_routing_line';
       $ef_refer_value = 'am_wo_routing_line_id';
       $tr_class = 'am_wo_routing_line';
       include_once __DIR__ . '/../../sys/extra_field/form/add_field_template.php';
       ?>
      </div>

     </div>
    </form>

    <div id ="form_line2" class="form_line2">
     <form action=""  method="post" id="am_wo_bom_line"  name="am_wo_bom_line">
      <div id="tabsLine-4" class="tabContent">
       <table class="form_line_data_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('WO BOM Id') ?></th>
          <th><?php echo gettext('BOM Sequence') ?></th>
          <th><?php echo gettext('Routing Seq') ?></th>
          <th><?php echo gettext('Item Id') ?></th>
          <th><?php echo gettext('Item Number') ?></th>
          <th><?php echo gettext('Revision') ?></th>
          <th><?php echo gettext('Item Description') ?></th>
          <th><?php echo gettext('UOM') ?></th>
          <th><?php echo gettext('Usage Basis') ?></th>
          <th><?php echo gettext('Quantity') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody2 am_wo_bom_values" >
         <?php
         $count = 0;
         foreach ($am_wo_bom_object as $am_wo_bom) {
          if (!empty($am_wo_bom->component_item_id_m)) {
           $item = item::find_by_id($am_wo_bom->component_item_id_m);
           $$class_fourth->component_item_number = $item->item_number;
           $$class_fourth->component_description = $item->item_description;
           $$class_fourth->component_uom = $item->uom_id;
          }
          ?>         
          <tr class="am_wo_bom<?php echo $count ?>">
           <td>    
            <ul class="inline_action">
             <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
             <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
             <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($am_wo_bom->am_wo_bom_id); ?>"></li>           
             <li><?php echo form::hidden_field('am_wo_header_id', $$class->am_wo_header_id); ?></li>
            </ul>
           </td>
           <td><?php form::text_field_wid4s('am_wo_bom_id'); ?></td>
           <td><?php form::text_field_wid4sm('bom_sequence'); ?></td>
           <td><?php echo!empty($routing_line_details) ? form::select_field_from_object('routing_sequence', $routing_line_details, 'routing_sequence', 'routing_sequence', $$class_fourth->routing_sequence, 'routing_sequence') : form::text_field_wid4s('routing_sequence'); ?></td>
           <td><?php echo $f->text_field('component_item_id_m', $$class_fourth->component_item_id_m, '8', '', 'item_id_m', 1, $readonly); ?></td>
           <td><?php echo $f->text_field('component_item_number', $$class_fourth->component_item_number, '20', '', 'select_item_number', '', $readonly); ?>
            <i class="select_item_number select_popup clickable fa fa-search"></i></td>
           <td><?php
            if (!empty($$class_fourth->component_item_id_m) && !empty($$class->org_id)) {
             $revision_name_a = inv_item_revision::find_by_itemIdM_orgId($$class_fourth->component_item_id_m, $$class->org_id);
            } else {
             $revision_name_a = array();
            }
            echo $f->select_field_from_object('component_revision', $revision_name_a, 'revision_name', 'revision_name', $$class_fourth->component_revision, '', 'small');
            ?></td>
           <td><?php echo $f->text_field('component_description', $$class_fourth->component_description, '20', '', 'item_description', '', $readonly); ?></td>
           <td><?php echo $f->select_field_from_object('component_uom', uom::find_all(), 'uom_id', 'uom_name', $$class_fourth->component_uom, '', 'uom_id', '', $readonly); ?></td>
           <td><?php echo form::select_field_from_object('usage_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_fourth->usage_basis, '', $readonly, 'usage_basis', '', 1); ?></td>
           <td><?php form::number_field_wid4sm('usage_quantity'); ?></td>
          </tr>
          <?php
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>
      <div id="tabsLine-5" class="tabContent">
       <table class="form_line_data_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Required') ?></th>
          <th><?php echo gettext('Issued') ?></th>
          <th><?php echo gettext('Open') ?></th>
          <th><?php echo gettext('On Hand') ?></th>
          <th><?php echo gettext('Supply Type') ?></th>
          <th><?php echo gettext('Subinventory') ?></th>
          <th><?php echo gettext('Locator') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody2 am_wo_bom_values" >
         <?php
         $count = 0;
         foreach ($am_wo_bom_object as $am_wo_bom) {
          $am_wo_bom->open_quantity = $am_wo_bom->required_quantity - $am_wo_bom->issued_quantity;
          ?>         
          <tr class="am_wo_bom<?php echo $count ?>">
           <td><?php form::number_field_wid4s('required_quantity'); ?></td>
           <td><?php form::number_field_wid4sr('issued_quantity'); ?></td>
           <td><?php form::number_field_wid4sr('open_quantity'); ?></td>
           <td></td>
           <td><?php echo $f->select_field_from_object('wip_supply_type', bom_header::wip_supply_type(), 'option_line_code', 'option_line_value', $$class_fourth->wip_supply_type, '', 'wip_supply_type', '', $readonly); ?></td>
           <td><?php echo $f->select_field_from_object('supply_sub_inventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_fourth->supply_sub_inventory, '', 'subinventory_id', '', $readonly); ?></td>
           <td><?php echo $f->select_field_from_object('supply_locator', locator::find_all_of_subinventory($$class_fourth->supply_sub_inventory), 'locator_id', 'locator', $$class_fourth->supply_locator, '', 'locator_id', '', $readonly); ?></td>
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

 </div>
 <!--END OF FORM -->
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="am_wo_header" ></li>
  <li class="lineClassName" data-lineClassName="am_wo_routing_line" ></li>
  <li class="detailClassName" data-detailClassName="am_wo_routing_detail" ></li>
  <li class="lineClassName2" data-lineClassName2="am_wo_bom" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="am_wo_header_id" ></li>
  <li class="form_header_id" data-form_header_id="am_wo_header" ></li>
  <li class="line_key_field" data-line_key_field="routing_sequence" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="am_wo_routing_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="am_wo_header_id" ></li>
  <li class="docLineId" data-docLineId="am_wo_routing_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="am_wo_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trClass="am_wo_routing" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
