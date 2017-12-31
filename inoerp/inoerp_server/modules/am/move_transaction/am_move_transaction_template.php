<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<form  method="post" id="am_move_transaction"  name="am_move_transaction">
 <span class="heading"><?php echo gettext('Maintenance Move Transaction') ?></span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Tracking') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('am_wo_header_id'); ?>
        <a name="show" href="form.php?class_name=am_move_transaction&<?php echo "mode=$mode"; ?>" class="show document_id am_wo_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('wo_number'); ?></li>
       <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>       </li>
       <li><?php $f->l_date_fieldFromToday_m('transaction_date', ($$class->transaction_date)); ?>       </li>
       <li><?php $f->l_select_field_from_array('transaction_type', am_move_transaction::$transaction_type_a,  $$class->transaction_type, 'transaction_type', '', 1, $readonly1); ?>       </li> 
       <li><?php $f->l_text_field_dr('am_move_transaction_id'); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_d('sales_order_header_id'); ?></li>               
       <li><?php $f->l_text_field_d('sales_order_line_id'); ?></li>
      </ul>
     </div>
    </div>
   </div>
  </div>
 </div>
 <div id ="form_line" class="form_line"><span class="heading"> <?php echo gettext('Operation Details') ?> </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Operation') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Scrap') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('BOM (View Only)') ?> </a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr('item_id_m'); ?></li>
       <li><?php $f->l_text_field_dr('item_number'); ?></li>
       <li><?php $f->l_text_field_dr('item_description'); ?></li>
       <li><?php $f->l_select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom_id', '', '', 1); ?> </li>
       <li><?php $f->l_number_field_dr('total_quantity'); ?></li>
       <li><?php $f->l_number_field('completed_quantity', $$class_second->completed_quantity); ?></li>
      </ul>
      <span class="heading"><?php echo gettext('Quantity Status') ?></span>

      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Sequence') ?></th>
         <th><?php echo gettext('Department') ?></th>
         <th><?php echo gettext('Description') ?></th>
         <th><?php echo gettext('Queue') ?></th>
         <th><?php echo gettext('Running') ?></th>
         <th><?php echo gettext('Rejected') ?></th>
         <th><?php echo gettext('Scrapped') ?></th>
         <th><?php echo gettext('To Move') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody am_wo_routing_line_values" >
        <?php
        $count = 0;
        foreach ($am_wo_routing_line_object as $am_wo_routing_line) {
         ?>         
         <tr class="am_wo_routing<?php echo $count ?>">
          <td><?php form::number_field_wid2sr('routing_sequence'); ?></td>
          <td><?php echo $f->select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class_second->department_id, '', '', '', 1); ?></td>
          <td><?php form::text_field_wid2r('description'); ?></td>
          <td><?php form::number_field_wid2sr('queue_quantity'); ?></td>
          <td><?php form::number_field_wid2sr('running_quantity'); ?></td>
          <td><?php form::number_field_wid2sr('rejected_quantity'); ?></td>
          <td><?php form::number_field_wid2sr('scrapped_quantity'); ?></td>
          <td><?php form::number_field_wid2sr('tomove_quantity'); ?></td>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </div>
     <div class="second_rowset">

      <div class="panel panel-success">
       <div class="panel-heading">
        <h3 class="panel-title"><?php echo gettext('Move Material') ?></h3>
       </div>
       <div class="panel-body">
        <ul class="column header_field"> 
         <li><label><?php echo gettext('From Seq') ?></label>
          <?php echo!empty($routing_line_details) ? form::select_field_from_object('from_routing_sequence', $routing_line_details, 'routing_sequence', 'routing_sequence', $$class->from_routing_sequence, 'from_routing_sequence', $readonly, '', '', 1) : form::text_field_ds('from_routing_sequence'); ?>
         </li>
         <li><label><?php echo gettext('To Seq') ?></label>
          <?php echo!empty($routing_line_details) ? form::select_field_from_object('to_routing_sequence', $routing_line_details, 'routing_sequence', 'routing_sequence', $$class->to_routing_sequence, 'to_routing_sequence', $readonly, '', '', 1) : form::text_field_ds('from_routing_sequence'); ?>
         </li>
         <li><label><?php echo gettext('Available Qty') ?></label>
          <?php form::number_field_drs('available_quantity'); ?>
         </li>
         <li><label><?php echo gettext('From Step') ?> </label>
          <?php echo $f->select_field_from_array('from_operation_step', am_move_transaction::$am_move_step, $$class->from_operation_step, 'from_operation_step', '' , 1, $readonly1); ?>
         </li>
         <li><label><?php echo gettext('To Step') ?></label>
          <?php echo $f->select_field_from_array('to_operation_step', am_move_transaction::$am_move_step, $$class->to_operation_step, 'to_operation_step', '', 1 , $readonly1); ?>
         </li>

         <li><label><?php echo gettext('Move Qty') ?></label>
          <?php form::number_field_dm('move_quantity'); ?>
         </li>


        </ul>
       </div>
      </div>
     </div>
     <!--end of tab1 div three_column-->
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_d('reason'); ?></li>
       <li><?php $f->l_text_field_d('reference'); ?></li>
       <li><?php $f->l_ac_field_d('scrap_account_id'); ?></li>
      </ul>
     </div>
     <div class="second_rowset">

     </div> 
     <!--                end of tab2 div three_column-->
    </div>

    <div id="tabsLine-3" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('BOM Sequence') ?></th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('Serial Generation') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Required') ?></th>
        <th><?php echo gettext('Issued') ?></th>
        <th><?php echo gettext('Supply Type') ?></th>
        <th><?php echo gettext('Subinventory') ?></th>
        <th><?php echo gettext('Locator') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody2 am_wo_bom_values" >
       <?php
       $count = 0;
       foreach ($am_wo_bom_object as $am_wo_bom) {
        ?>         
        <tr class="am_wo_bom<?php echo $count ?>">
         <td><?php echo $f->hidden_field('am_wo_bom_id', $$class_third->am_wo_bom_id); ?>
          <?php $f->text_field_wid3sr('bom_sequence'); ?></td>
         <td><?php echo $f->hidden_field('component_item_id_m', $$class_third->component_item_id_m); ?>
          <?php echo $f->text_field_wid3r('component_item_number'); ?></td>
         <td><?php echo $f->text_field_wid3r('component_description'); ?></td>
         <td><?php echo $f->text_field_wid3r('serial_generation'); ?></td>
         <td><?php form::number_field_wid3sr('usage_quantity'); ?></td>
         <td><?php form::number_field_wid3sr('required_quantity'); ?></td>
         <td><?php form::number_field_wid3sr('issued_quantity'); ?></td>
         <td><?php echo $f->select_field_from_object('wip_supply_type', bom_header::wip_supply_type(), 'option_line_code', 'option_line_value', $$class_third->wip_supply_type, '', 'wip_supply_type', '', 1); ?></td>
         <td><?php echo $f->select_field_from_object('supply_sub_inventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_third->supply_sub_inventory, '', 'subinventory_id', '', 1); ?></td>
         <td><?php echo $f->select_field_from_object('supply_locator', locator::find_all_of_subinventory($$class_third->supply_sub_inventory), 'locator_id', 'locator', $$class_third->supply_locator, '', 'locator_id', '', 1); ?></td>
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
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="am_wo_work_bench" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="am_move_transaction_id" ></li>
  <li class="form_header_id" data-form_header_id="am_move_transaction" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="am_move_transaction_id" ></li>
  <li class="btn1DivId" data-btn1DivId="am_move_transaction" ></li>
 </ul>
</div>
