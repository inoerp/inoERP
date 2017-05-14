<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id="wip_wo_divId">
 <div id="form_all">
  <div id ="form_header">	 <span class="heading"><?php echo gettext('Work Order Header') ?></span>
   <form method="post" id="wip_wo_header"  name="wip_wo_header">
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
        <li><?php $f->l_text_field_dr_withSearch('wip_wo_header_id'); ?>
         <a name="show" href="form.php?class_name=wip_wo_header&<?php echo "mode=$mode"; ?>" class="show document_id wip_wo_header_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', 'popup_value', '', $readonly); ?>         </li>
        <li><?php $f->l_text_field_d('wo_number', 'primary_column2'); ?> </li>
        <li><?php $f->l_select_field_from_object('wo_type', wip_wo_header::wip_wo_type(), 'option_line_code', 'option_line_value', $$class->wo_type, 'wo_type', '', '', $readonly); ?>         </li>
        <li><label><?php echo gettext('Accounting Group') ?></label><?php echo $f->select_field_from_object('wip_accounting_group_id', wip_accounting_group::find_by_woType(), 'wip_accounting_group_id', ['wip_accounting_group','org_id'], $$class->wip_accounting_group_id, 'wip_accounting_group_id', '', 1, 'readonly1' , '' ,'','','org_id'); ?>         </li>
        <li><?php
         echo $f->hidden_field_withId('item_id_m', $$class->item_id_m);
         echo $f->hidden_field_withId('processing_lt', $$class->processing_lt);
         echo $f->hidden_field_withCLass('build_in_wip_cb', '1', 'popup_value');
         echo $f->l_val_field_dm('item_number', 'item', 'item_number', 'org_id', 'vf_select_item_number');
         ?>
         <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i>
        </li>
        <li><?php $f->l_text_field_d('item_description'); ?></li>
        <li><?php $f->l_select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom_id', 'uom_id', '', $readonly1); ?>         </li>
        <li><?php $f->l_select_field_from_object('revision_name', $revision_name_a, 'revision_name', 'revision_name', $$class->revision_name, 'revision_name', ''); ?> </li>
        <li><label><?php echo gettext('Status') ?></label>                      
         <?php echo!empty($$class->wo_status) ? $$class->wo_status : ""; ?>
        </li>
       </ul>
      </div>
      <div id="tabsHeader-2" class="tabContent">
       <div> 
        <ul class="column header_field">
         <li id="document_status"><?php  $f = new inoform();
         $f->l_select_field_from_object('wo_status', wip_wo_header::wip_wo_status(), 'option_line_code', 'option_line_value', $$class->wo_status, 'set_wo_status', '', '', $readonly); ?>         </li>
         <li><?php $f->l_date_fieldFromToday_dm('start_date', $$class->start_date, 'start_date', 'default_date') ?></li>
         <li><?php $f->l_date_fieldFromToday_d('completion_date', $$class->completion_date, 'completion_date') ?></li>
         <li><?php $f->l_number_field_d('quantity'); ?> </li>
         <li><?php $f->l_number_field_d('nettable_quantity'); ?> </li>
         <li><?php $f->l_text_field_d('schedule_group'); ?> </li>
         <li><?php $f->l_number_field_d('build_sequence'); ?> </li>
         <li><?php $f->l_text_field_d('line'); ?> </li>
         <li><?php $f->l_number_field_d('scheduling_priority'); ?> </li>
        </ul>
       </div>
      </div>
      <div id="tabsHeader-3" class="tabContent">
       <div> 
        <ul class="column header_field">
         <li><?php $f->l_number_field_dr('remaining_quantity'); ?> </li>
         <li><?php $f->l_number_field_dr('completed_quantity'); ?> </li>
         <li><?php $f->l_number_field_dr('scrapped_quantity'); ?> </li>
         <li><?php $f->l_text_field_dr('released_date', 'always_readonly') ?></li>
         <li><?php $f->l_text_field_dr('first_unit_completed_date', 'always_readonly') ?></li>
         <li><?php $f->l_text_field_dr('last_unit_completed_date', 'always_readonly') ?></li>
        </ul>
       </div>
      </div>
      <div id="tabsHeader-4" class="tabContent">
       <div> 
        <ul class="column header_field">
         <li><?php $f->l_text_field_d('reference_bom_item_id_m'); ?> </li>
         <li><?php $f->l_text_field_d('reference_routing_item_id_m'); ?> </li>
         <li><?php $f->l_checkBox_field_dr('bom_exploded_cb'); ?> </li>
         <li><?php $f->l_checkBox_field_dr('routing_exploded_cb'); ?> </li>
         <li><?php $f->l_select_field_from_object('completion_sub_inventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->completion_sub_inventory, 'completion_sub_inventory', 'subinventory_id', '', $readonly); ?>         </li>
         <li><?php $f->l_select_field_from_object('completion_locator', locator::find_all_of_subinventory($$class->completion_sub_inventory), 'locator_id', 'locator', $$class->completion_locator, 'completion_locator', 'locator_id', '', $readonly); ?>         </li>
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
         $reference_table = 'wip_wo_header';
         $reference_id = $$class->wip_wo_header_id;
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
  <span class="heading"><?php echo gettext('Work Order Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Routing') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Routing-2') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Routing - Data Collection') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('BOM') ?></a></li>
    <li><a href="#tabsLine-5"><?php echo gettext('BOM-2') ?> </a></li>
   </ul>
   <div class="tabContainer"> 
    <form  method="post" id="wip_wo_routing_line"  name="wip_wo_routing_line">
     <div id ="form_line" class="form_line">
      <div id="tabsLine-1" class="tabContent">
       <table class="form_line_data_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('Seq') ?> #</th>
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
        <tbody class="form_data_line_tbody wip_wo_routing_line_values" >
         <?php
         $count = 0;
         foreach ($wip_wo_routing_line_object as $wip_wo_routing_line) {
          ?>         
          <tr class="wip_wo_routing_line<?php echo $count ?>">
           <td>
            <?php
            echo ino_inline_action($wip_wo_routing_line->wip_wo_routing_line_id, array('wip_wo_header_id' => $$class->wip_wo_header_id));
            ?>
           </td>
           <td><?php $f->seq_field_d($count); ?></td>
           <td><?php $f->text_field_wid2sr('wip_wo_routing_line_id'); ?></td>
           <td><?php form::number_field_wid2('routing_sequence'); ?></td>
           <td><?php echo $f->select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class_second->department_id, 'department_id', 'medium'); ?></td>
           <td><?php $f->text_field_wid2('description' ,'large'); ?></td>
           <td><?php echo form::checkBox_field('count_point_cb', $$class_second->count_point_cb); ?></td>
           <td><?php echo form::checkBox_field('auto_charge_cb', $$class_second->auto_charge_cb); ?></td>
           <td><?php echo form::checkBox_field('backflush_cb', $$class_second->backflush_cb); ?></td>
           <td><?php form::number_field_wid2('minimum_transfer_quantity'); ?></td>
           <td class="add_detail_values"><i class="fa fa-arrow-circle-down add_detail_values_img"></i>
            <!--</td></tr>-->	
            <?php
            $wip_wo_routing_line_id = $wip_wo_routing_line->wip_wo_routing_line_id;
            if (!empty($wip_wo_routing_line_id)) {
             $wip_wo_routing_detail_object = wip_wo_routing_detail::find_by_wipWo_lineId($wip_wo_routing_line_id);
            } else {
             $wip_wo_routing_detail_object = array();
            }
            if (count($wip_wo_routing_detail_object) == 0) {
             $wip_wo_routing_detail = new wip_wo_routing_detail();
             $wip_wo_routing_detail_object = array();
             array_push($wip_wo_routing_detail_object, $wip_wo_routing_detail);
            }
            ?>
            <div class="class_detail_form">
             <fieldset class="form_detail_data_fs">
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
                   $detailCount = 0; $f = new inoform();
                   foreach ($wip_wo_routing_detail_object as $wip_wo_routing_detail) {
                    $class_third = 'wip_wo_routing_detail';
                    $$class_third = &$wip_wo_routing_detail;
                    ?>
                    <tr class="wip_wo_routing_detail<?php echo $count . '-' . $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
                     <td><?php
                      echo ino_inline_action($$class_third->wip_wo_routing_detail_id, array('wip_wo_header_id' => $$class->wip_wo_header_id,
                       'wip_wo_routing_line_id' => $$class_second->wip_wo_routing_line_id), 'add_row_detail_img', 'detail_id_cb');
                      ?>                       </td>
                     <td><?php $f->text_field_wid3sr('wip_wo_routing_detail_id'); ?></td>
                     <td><?php $f->text_field_wid3sm('resource_sequence', 'seq_number'); ?></td>
                     <td><?php echo $f->select_field_from_object('resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_third->resource_id, '', '', 1, $readonly); ?></td>
                     <td><?php echo $f->select_field_from_object('charge_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_third->charge_basis, '', 'small', 1, $readonly); ?></td>
                     <td><?php echo $f->number_field('resource_usage',  $$class_third->resource_usage) ?></td>
                     <td><?php echo form::select_field_from_object('resource_schedule', bom_header::bom_schedule_option(), 'option_line_code', 'option_line_value', $$class_third->resource_schedule, '', $readonly, 'default_basis', '', 1); ?></td>
                     <td><?php echo $f->number_field('assigned_units',  $$class_third->assigned_units) ?></td>
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
                   foreach ($wip_wo_routing_detail_object as $wip_wo_routing_detail) {
                    $class_third = 'wip_wo_routing_detail';
                    $$class_third = &$wip_wo_routing_detail;
                    $$class_third->open_quantity = $$class_third->required_quantity - $$class_third->applied_quantity;
                    ?>
                    <tr class="wip_wo_routing_detail<?php echo $count . '-' . $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
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
          <th><?php echo gettext('Seq') ?> #</th>
          <th><?php echo gettext('Queue') ?></th>
          <th><?php echo gettext('Running') ?></th>
          <th><?php echo gettext('Rejected') ?></th>
          <th><?php echo gettext('Scrapped') ?></th>
          <th><?php echo gettext('To Move') ?></th>
          <th><?php echo gettext('Start Date') ?></th>
          <th><?php echo gettext('Completion Date') ?></th>
          <th><?php echo gettext('Progress') ?>%</th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody wip_wo_routing_line_values" >
         <?php $f = new inoform();
         $count = 0;
         foreach ($wip_wo_routing_line_object as $wip_wo_routing_line) {
          ?>         
          <tr class="wip_wo_routing_line<?php echo $count ?>">
           <td><?php $f->seq_field_d($count); ?></td>
           <td><?php $f->text_field_wid2r('queue_quantity', 'always_readonly'); ?></td>
           <td><?php $f->text_field_wid2r('running_quantity', 'always_readonly'); ?></td>
           <td><?php $f->text_field_wid2r('scrapped_quantity', 'always_readonly'); ?></td>
           <td><?php $f->text_field_wid2r('queue_quantity', 'always_readonly'); ?></td>
           <td><?php $f->text_field_wid2r('tomove_quantity', 'always_readonly'); ?></td>
           <td><?php echo $f->date_fieldFromToday_r('start_date', ino_date($$class_second->start_date), 1); ?></td>
           <td><?php echo $f->date_fieldFromToday_r('completion_date', ino_date($$class_second->completion_date), 1); ?></td>
           <td><?php $f->text_field_wid2r('completed_quantity', 'always_readonly'); ?></td>
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
       $class_name_object = $wip_wo_routing_line_object;
       $ef_refer_key = 'wip_wo_routing_line';
       $ef_refer_value = 'wip_wo_routing_line_id';
       $tr_class = 'wip_wo_routing_line';
       include_once __DIR__ . '/../../sys/extra_field/form/add_field_template.php';
       ?>
      </div>

     </div>
    </form>

    <div id ="form_line2" class="form_line2">
     <form action=""  method="post" id="wip_wo_bom_line"  name="wip_wo_bom_line">
      <div id="tabsLine-4" class="tabContent">
       <table class="form_line_data_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('BOM Seq') ?> #</th>
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
        <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
         <?php
         $count = 0;
         foreach ($wip_wo_bom_object as $wip_wo_bom) {
          if (!empty($wip_wo_bom->component_item_id_m)) {
           $item = item::find_by_id($wip_wo_bom->component_item_id_m);
           $$class_fourth->component_item_number = $item->item_number;
           $$class_fourth->component_description = $item->item_description;
           $$class_fourth->component_uom = $item->uom_id;
          }
          ?>         
          <tr class="wip_wo_bom<?php echo $count ?>">
           <td>    
            <ul class="inline_action">
             <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
             <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
             <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($wip_wo_bom->wip_wo_bom_id); ?>"></li>           
             <li><?php echo form::hidden_field('wip_wo_header_id', $$class->wip_wo_header_id); ?></li>
            </ul>
           </td>
           <td><?php $f->seq_field_d($count); ?></td>
           <td><?php $f->text_field_wid4sr('wip_wo_bom_id', 'always_readonly'); ?></td>
           <td><?php $f->text_field_wid4('bom_sequence'); ?></td>
           <td><?php echo!empty($routing_line_details) ? $f->select_field_from_object('routing_sequence', $routing_line_details, 'routing_sequence', 'routing_sequence', $$class_fourth->routing_sequence, '', 'routing_sequence medium') : $f->text_field_wid4s('routing_sequence'); ?></td>
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
           <td><?php echo $f->text_field('component_description', $$class_fourth->component_description, '20', '', 'item_description xlarge', '', $readonly); ?></td>
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
          <th><?php echo gettext('BOM Seq') ?> #</th>
          <th><?php echo gettext('Required') ?></th>
          <th><?php echo gettext('Issued') ?></th>
          <th><?php echo gettext('Open') ?></th>
          <th><?php echo gettext('On Hand') ?></th>
          <th><?php echo gettext('Supply Type') ?></th>
          <th><?php echo gettext('Subinventory') ?></th>
          <th><?php echo gettext('Locator') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
         <?php
         $count = 0;
         foreach ($wip_wo_bom_object as $wip_wo_bom) {
          $wip_wo_bom->open_quantity = $wip_wo_bom->required_quantity - $wip_wo_bom->issued_quantity;
          ?>         
          <tr class="wip_wo_bom<?php echo $count ?>">
           <td><?php $f->seq_field_d($count); ?></td>
           <td><?php echo $f->number_field('required_quantity' , $$class_fourth->required_quantity); ?></td>
           <td><?php $f->text_field_wid4r('issued_quantity', 'always_readonly'); ?></td>
           <td><?php $f->text_field_wid4r('open_quantity', 'always_readonly'); ?></td>
           <td></td>
           <td><?php echo $f->select_field_from_object('wip_supply_type', bom_header::wip_supply_type(), 'option_line_code', 'option_line_value', $$class_fourth->wip_supply_type, '', 'wip_supply_type medium', '', $readonly); ?></td>
           <td><?php echo $f->select_field_from_object('supply_sub_inventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_fourth->supply_sub_inventory, '', 'subinventory_id medium', '', $readonly); ?></td>
           <td><?php echo $f->select_field_from_object('supply_locator', locator::find_all_of_subinventory($$class_fourth->supply_sub_inventory), 'locator_id', 'locator', $$class_fourth->supply_locator, '', 'locator_id medium', '', $readonly); ?></td>
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
  <li class="headerClassName" data-headerClassName="wip_wo_header" ></li>
  <li class="lineClassName" data-lineClassName="wip_wo_routing_line" ></li>
  <li class="detailClassName" data-detailClassName="wip_wo_routing_detail" ></li>
  <li class="lineClassName2" data-lineClassName2="wip_wo_bom" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="wip_wo_header_id" ></li>
  <li class="form_header_id" data-form_header_id="wip_wo_header" ></li>
  <li class="line_key_field" data-line_key_field="routing_sequence" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="wip_wo_routing_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="wip_wo_header_id" ></li>
  <li class="docLineId" data-docLineId="wip_wo_routing_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="wip_wo_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trClass="wip_wo_routing" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
