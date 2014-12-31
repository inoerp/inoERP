<form action=""  method="post" id="wip_wo_work_bench"  name="wip_wo_work_bench"><span class="heading"> Work Order Work Bench </span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Tracking</a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column four_column">
       <li>
        <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="wip_wo_header_id select_popup clickable">
         WO Header Id(1)</label><?php echo $f->text_field_dsr('wip_wo_header_id'); ?>
        <a name="show" href="form.php?class_name=wip_wo_work_bench&<?php echo "mode=$mode"; ?>" class="show document_id wip_wo_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>WO Number</label><?php echo form::text_field_d('wo_number'); ?></li>
       <li><label>Inventory Org</label><?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly, '', '', 1); ?>       </li>
       <li><label>Date(2)</label><?php echo $f->text_field('transaction_date', ($$class->transaction_date), '', '', 'dateTime'); ?>       </li>
       <li><label>Transaction Type</label><?php echo form::select_field_from_object('transaction_type', wip_move_transaction::wip_transactions(), 'option_line_code', 'option_line_value', $$class->transaction_type, 'transaction_type', $readonly, '', '', 1); ?>       </li> 
       <li><label>Move Transaction Id</label><?php echo form::text_field_dsr('wip_move_transaction_id'); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column five_column">
       <li><label>SO Number : </label><?php echo form::text_field_d('sales_order_header_id'); ?></li>               
       <li><label>Line Number : </label><?php echo form::text_field_d('sales_order_line_id'); ?></li>
      </ul>
     </div>
    </div>
   </div>
  </div>
 </div>

 <div id ="form_line" class="form_line"><span class="heading"> Operation Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Operation</a></li>
    <li><a href="#tabsLine-2">Data Collection</a></li>
    <li><a href="#tabsLine-3">Scrap</a></li>
    <li><a href="#tabsLine-4">BOM (View Only)</a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column six_column"> 
       <li><label>Item Id : </label>
        <?php form::text_field_drm('item_id_m'); ?>
       </li>
       <li><label>Item Number : </label>
        <?php form::text_field_dr('item_number'); ?>
       </li>
       <li><label>Description: </label>
        <?php form::text_field_widr('item_description'); ?>
       </li>
       <li><label>UOM : </label>
        <?php echo $f->select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom_id', 'uom_id'); ?>
       </li>
       <li><label>Total Quantity : </label>
        <?php form::number_field_dr('total_quantity'); ?>
       </li>
       <li><label>Completed Quantity : </label>
        <?php form::number_field_wid2s('completed_quantity'); ?>
       </li>

      </ul>
     </div>
     <div class="second_rowset"><span class="heading">Quantity Status</span>

      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th>Sequence</th>
         <th>Department</th>
         <th>Description</th>
         <th>Queue</th>
         <th>Running</th>
         <th>Rejected</th>
         <th>Scrapped</th>
         <th>To Move</th>

        </tr>
       </thead>
       <tbody class="form_data_line_tbody wip_wo_routing_line_values" >
        <?php
        $count = 0;
        foreach ($wip_wo_routing_line_object as $wip_wo_routing_line) {
         ?>         
         <tr class="wip_wo_routing<?php echo $count ?>">
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
     <ul class="column six_column"> 
      <li><label>From Seq : </label>
       <?php echo!empty($routing_line_details) ? form::select_field_from_object('from_routing_sequence', $routing_line_details, 'routing_sequence', 'routing_sequence', $$class->from_routing_sequence, 'from_routing_sequence') : form::text_field_ds('from_routing_sequence'); ?>
      </li>
      <li><label>From Step : </label>
       <?php echo form::select_field_from_object('from_operation_step', bom_routing_header::wip_move_step(), 'option_line_code', 'option_line_value', $$class->from_operation_step, 'from_operation_step'); ?>
      </li>
      <li><label>Available Qty: </label>
       <?php form::number_field_drs('available_quantity'); ?>
      </li>
      <li><label>Move Qty: </label>
       <?php form::number_field_d('move_quantity'); ?>
      </li>
      <li><label>To Seq : </label>
       <?php echo!empty($routing_line_details) ? form::select_field_from_object('to_routing_sequence', $routing_line_details, 'routing_sequence', 'routing_sequence', $$class->to_routing_sequence, 'to_routing_sequence') : form::text_field_ds('from_routing_sequence'); ?>
      </li>
      <li><label>To Step : </label>
       <?php echo form::select_field_from_object('to_operation_step', bom_routing_header::wip_move_step(), 'option_line_code', 'option_line_value', $$class->to_operation_step, 'to_operation_step'); ?>
      </li>
     </ul>
     <!--end of tab1 div three_column-->
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">

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
        echo "<div id=\"tabsVertical-$tab_count\" class='tabContent'><div class='large_shadow_box'> ";
        echo '<ul class="column five_column">';
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
         $ef_table = 'extra_field_' . $ef->sys_field_name;
         $ef_all_value = sys_extra_field_instance::find_by_fieldName_referenceDetails($ef->sys_field_name, 'wip_wo_routing_line', $routing_line->wip_wo_routing_line_id);
         if ($ef_all_value) {
          $ef_value_key = $ef_table . '_value';
          $ef_value = $ef_all_value->$ef_value_key;
         } else {
          $ef_value = null;
         }

         $lable = !empty($ef->label) ? $ef->label : $ef->sys_field_name;
         echo "<li><label>$lable : </label>";
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
           $file_routing = file::find_by_fieldName_referenceTable_and_id($ef->sys_field_name, 'wip_wo_routing_line', $routing_line->wip_wo_routing_line_id);
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
    <div id="tabsLine-3" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column five_column"> 
       <li><label>Reason : </label> <?php form::text_field_d('reason'); ?>  </li>
       <li><label>Reference : </label> <?php form::text_field_d('reference'); ?> </li>
       <li><label>Scrap Ac: </label><?php echo $f->ac_field_d('scrap_account_id'); ?></li>
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
        <th>BOM Seq</th>
        <th>Item Number</th>
        <th>Item Desc</th>
        <th>Serial Generation</th>
        <th>Quantity</th>
        <th>Required</th>
        <th>Issued</th>
        <th>Supply Type</th>
        <th>Sub inventory</th>
        <th>Locator</th>
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
  <li class="headerClassName" data-headerClassName="wip_move_transaction" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="wip_move_transaction_id" ></li>
  <li class="form_header_id" data-form_header_id="wip_wo_work_bench" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedadeId" data-docHedadeId="wip_move_transaction_id" ></li>
  <li class="btn1DivId" data-btn1DivId="wip_move_transaction_id" ></li>
 </ul>
</div>