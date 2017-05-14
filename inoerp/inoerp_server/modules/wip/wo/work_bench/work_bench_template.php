<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<form  method="post" id="wip_wo_work_bench"  name="wip_wo_work_bench">
 <span class="heading"><?php echo gettext('Work Order Work Bench') ?></span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Tracking') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php
       $f->l_val_field_d('wo_number', 'wip_wo_header', 'wo_number', 'org_id', '');
       echo $f->hidden_field_withId('wip_wo_header_id', $$class->wip_wo_header_id);
       echo $f->hidden_field_withCLass('wo_status', 'RELEASED', 'popup_value');
       ?>
       <i class="generic g_select_wo_number select_popup clickable fa fa-search" data-class_name="wip_wo_header"></i>
       <a name="show2" href="form.php?class_name=wip_wo_work_bench&<?php echo "mode=$mode"; ?>" class="show2 document_id wip_wo_header_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>       </li>
      <li><?php $f->l_date_fieldFromToday_m('transaction_date', ($$class->transaction_date)); ?>       </li>
      <li><?php $f->l_select_field_from_object('transaction_type', wip_move_transaction::wip_transactions(), 'option_line_code', 'option_line_value', $$class->transaction_type, 'transaction_type', 'always_readonly action', 1, $readonly1); ?>       </li> 
      <li><?php $f->l_text_field_dr('wip_move_transaction_id'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_d('sales_order_header_id'); ?></li>               
      <li><?php $f->l_text_field_d('sales_order_line_id'); ?></li>
     </ul>
    </div>
   </div>
  </div>
 </div>

 <div id ="form_line_ws" class="form_line_ws"><span class="heading"><?php echo gettext('Operation Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Operation') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Data Collection') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Scrap') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('BOM (View Only)') ?> </a></li>
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
       <tbody class="form_data_line_tbody wip_wo_routing_line_values" >
        <?php
        $count = 0;
        foreach ($wip_wo_routing_line_object as $wip_wo_routing_line) {
         ?>         
         <tr class="wip_wo_routing<?php echo $count ?>">
          <td><?php $f->text_field_wid2r('routing_sequence'); ?></td>
          <td><?php echo $f->select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class_second->department_id, '', '', '', 1); ?></td>
          <td><?php $f->text_field_wid2r('description'); ?></td>
          <td><?php $f->text_field_wid2r('queue_quantity'); ?></td>
          <td><?php $f->text_field_wid2r('running_quantity'); ?></td>
          <td><?php $f->text_field_wid2r('rejected_quantity'); ?></td>
          <td><?php $f->text_field_wid2r('scrapped_quantity'); ?></td>
          <td><?php $f->text_field_wid2r('tomove_quantity'); ?></td>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </div>
     <div class="second_rowset">

      <div class="panel panel-success ino-simple-panel">
       <div class="panel-heading ino-simple-heading">
        <h3 class="panel-title"><?php echo gettext('Move Material') ?></h3>
       </div>
       <div class="panel-body">
        <ul class="column header_field"> 
         <li><label><?php echo gettext('From Seq') ?></label>
          <?php echo!empty($routing_line_details) ? $f->select_field_from_object('from_routing_sequence', $routing_line_details, 'routing_sequence', 'routing_sequence', $$class->from_routing_sequence, 'from_routing_sequence', 'medium', 1, $readonly1) : form::text_field_d('from_routing_sequence'); ?>
         </li>
         <li><label><?php echo gettext('To Seq') ?></label>
          <?php echo!empty($routing_line_details) ? $f->select_field_from_object('to_routing_sequence', $routing_line_details, 'routing_sequence', 'routing_sequence', $$class->to_routing_sequence, 'to_routing_sequence', 'medium', 1, $readonly1) : form::text_field_d('to_routing_sequence'); ?>
         </li>
         <li><label><?php echo gettext('Available Qty') ?></label>
          <?php form::number_field_drs('available_quantity'); ?>
         </li>
         <li><label><?php echo gettext('From Step') ?> </label>
          <?php echo $f->select_field_from_object('from_operation_step', bom_routing_header::wip_move_step(), 'option_line_code', 'option_line_value', $$class->from_operation_step, 'from_operation_step', 'medium', 1, $readonly1); ?>
         </li>
         <li><label><?php echo gettext('To Step') ?></label>
          <?php echo $f->select_field_from_object('to_operation_step', bom_routing_header::wip_move_step(), 'option_line_code', 'option_line_value', $$class->to_operation_step, 'to_operation_step', 'medium', 1, $readonly1); ?>
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
     <div id ="form_line" class="form_line">
      <div id="tabsVertical">
       <ul class="tabVerticalMain">
        <?php
        $tab_count = 0;
        foreach ($wip_wo_routing_line_object as $routing_line) {
         $tab_count++;
         echo "<li><a href='#tabsVertical-$tab_count'>$routing_line->routing_sequence";
         if (!empty($routing_line->department_id)) {
          echo " - " . bom_department::find_by_id($routing_line->department_id)->department;
         }
         echo "<br>$routing_line->description";
         echo "</a></li>";
        }
        ?>
       </ul>
       <div class="tabContainer_v"> 
        <?php
        $tab_count = 0;
        foreach ($wip_wo_routing_line_object as $routing_line) {
         $tab_count++;
         echo "<div id=\"tabsVertical-$tab_count\" class='tabContent form_header_l'><div class='large_shadow_box'> ";
         echo '<ul class="column header_field">';
         echo $f->hidden_field('wip_wo_header_id', $routing_line->wip_wo_header_id);
         echo $f->hidden_field('routing_sequence', $routing_line->routing_sequence);
         echo $f->hidden_field('wip_wo_routing_line_id', $routing_line->wip_wo_routing_line_id);
         if (!empty($routing_line->wip_wo_routing_line_id)) {
          $extra_field_object = sys_extra_field_instance::find_by_referenceKeyValue('wip_wo_routing_line', $routing_line->wip_wo_routing_line_id);
         }
         if (empty($extra_field_object)) {
          $extra_field_object = array(new sys_extra_field_instance());
         }
         foreach ($extra_field_object as $ef) {
          if (empty($ef->field_name)) {
           continue;
          }
          $ef_table = 'ef_' . $ef->sys_field_name;
          $ef_all_value = sys_extra_field_instance::find_by_fieldName_referenceDetails($ef->sys_field_name, 'wip_wo_routing_line', $routing_line->wip_wo_routing_line_id);
          if ($ef_all_value) {
           $ef_value_key = $ef_table . '_value';
           $ef_value = $ef_all_value->$ef_value_key;
          } else {
           $ef_value = null;
          }

          $lable_x = !empty($ef->label) ? $ef->label : $ef->sys_field_name;
          $lable = ucwords(str_replace('_', ' ', $lable_x));
          echo "<li><label>$lable </label>";
          switch ($ef->field_type) {
           case 'LIST':
            if (!empty($ef->list_values)) {
             $arr = unserialize($ef->list_values);
             echo $f->select_field_from_array($ef->sys_field_name, $arr, $ef_value);
            } else {
             echo $f->text_field($ef->sys_field_name, $ef_value);
            }
            break;

           case 'BOOLEAN' :
            echo $f->checkBox_field($ef->sys_field_name, $ef_value);
            break;

           case 'FILE' :
            $ef_file_name = $ef->sys_field_name . '_file';
            $file_routing = extn_file::find_by_fieldName_referenceTable_and_id($ef->sys_field_name, 'wip_wo_routing_line', $routing_line->wip_wo_routing_line_id);
            echo ino_attachement($file_routing, $ef_file_name);
            echo $f->hidden_field($ef->sys_field_name, $ef_value);
            break;

           case 'OPTION_LIST' :
            if (!empty($ef->list_value_option_type)) {
             echo $f->select_field_from_object($ef->sys_field_name, option_line::find_by_parent_id($ef->list_value_option_type), 'option_line_code', 'option_line_value', $ef_value);
            } else {
             echo $f->text_field($ef->sys_field_name, $ef_value);
            }
            break;
           default :
            echo $f->text_field($ef->sys_field_name, $ef_value);
            break;
          }

          echo '</li>';
         }
         echo "</ul></div></div>";
        }
        ?>
       </div>
      </div>
     </div>
    </div>
    <div id="tabsLine-3" class="tabContent">
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

    <div id="tabsLine-4" class="tabContent">
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
      <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
       <?php
       $count = 0;
       foreach ($wip_wo_bom_object as $wip_wo_bom) {
        ?>         
        <tr class="wip_wo_bom<?php echo $count ?>">
         <td><?php echo $f->hidden_field('wip_wo_bom_id', $$class_third->wip_wo_bom_id); ?>
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
  <li class="headerClassName" data-headerClassName="wip_wo_work_bench" ></li>
  <li class="lineClassName" data-lineClassName="wip_wo_work_bench_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="wip_move_transaction_id" ></li>
  <li class="form_header_id" data-form_header_id="wip_wo_work_bench" ></li>
  <li class="save_vertical_tab" data-save_vertical_tab="true" ></li>
  <li class="single_line" data-single_line="false" ></li>

 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="wip_move_transaction_id" ></li>
  <li class="btn1DivId" data-btn1DivId="wip_move_transaction" ></li>
 </ul>
</div>
