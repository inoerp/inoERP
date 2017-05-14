<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id="form_header"><span class="heading"><?php echo gettext('Batch Operation') ?></span>
 
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Accounts') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php
       $f->l_val_field_dm('pm_batch_header_id', 'pm_batch_header', 'pm_batch_header_id', '', 'vf_select_batch_name');
       echo $f->hidden_field_withCLass('org_id', $$class->org_id, 'popup_value');
       ?>
       <i class="generic g_select_batch_name select_popup clickable fa fa-search" data-class_name="pm_batch_header"></i>
       <a name="show" href="form.php?class_name=pm_batch_operation_header&<?php echo "mode=$mode"; ?>" class="show document_id pm_batch_header_id"><i class="fa fa-refresh"></i></a> </li>
      <li><?php
       $f->l_val_field_dm('batch_name', 'pm_batch_header', 'batch_name', '', 'vf_select_batch_name');
       echo $f->hidden_field_withCLass('org_id', $$class->org_id, 'popup_value');
       ?>
       <i class="generic g_select_batch_name select_popup clickable fa fa-search" data-class_name="pm_batch_header"></i></li>
      <li><?php
       echo $f->l_val_field_dm('recipe_name', 'pm_recipe_all_v', 'recipe_name', '', 'vf_select_recipe_name');
       echo $f->hidden_field_withId('pm_recipe_header_id', $$class->pm_recipe_header_id);
       ?><i class="generic g_select_recipe_name select_popup clickable fa fa-search" data-class_name="pm_recipe_all_v"></i></li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', 'always_readonly'); ?>						 </li>
      <li><?php $f->l_select_field_from_object('wip_accounting_group_id', wip_accounting_group::find_by_woType('PROCESS'), 'wip_accounting_group_id', 'wip_accounting_group', $$class->wip_accounting_group_id, 'wip_accounting_group_id', 'always_readonly'); ?>         </li>
      <li><?php $f->l_text_field_dr('revision'); ?></li>
      <li><?php $f->l_text_field_dr('comment'); ?></li>
      <li><label><?php echo gettext('Owner') ?></label><?php $f->text_field_d('pm_employee_name', 'employee_name'); ?>
<?php echo $f->hidden_field_withId('owner_employee_id', $$class->owner_employee_id); ?>
       <i class="select_employee_name select_popup clickable fa fa-search"></i>
      </li>
      <li><?php $f->l_text_field_dr('routing_name') ?></li>
      <li><?php $f->l_text_field_dr('formula_name') ?></li>
      <li><?php $f->l_text_field_dr('description') ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_ac_field_d('material_ac_id', '', 'A'); ?></li>  
      <li><?php $f->l_ac_field_d('overhead_ac_id', '', 'A'); ?></li> 
      <li><?php $f->l_ac_field_d('material_oh_ac_id', '', 'A'); ?></li> 
      <li><?php $f->l_ac_field_d('resource_ac_id', '', 'A'); ?></li>  
      <li><?php $f->l_ac_field_d('osp_ac_id', '', 'A'); ?></li>  
      <li><?php $f->l_ac_field_d('expense_ac_id', '', 'X'); ?></li>  
     </ul>
    </div>
   </div>
  </div>

</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Batch Operation Line & Details') ?></span>
 <form method="post" id="pm_batch_operation_line"  name="pm_batch_operation_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Batch Steps') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Step') ?> #</th>
        <th><?php echo gettext('Activity') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Factor') ?></th>
        <th><?php echo gettext('Seq Dependency') ?>?</th>
        <th><?php echo gettext('Breakable') ?>?</th>
        <th><?php echo gettext('Material Scheduled') ?>?</th>
        <th><?php echo gettext('Release Type') ?></th>
        <th><?php echo gettext('Line Action') ?></th>
        <th><?php echo gettext('Status') ?></th>
        <th><?php echo gettext('Details') ?></th>
        
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($pm_batch_operation_line_object as $pm_batch_operation_line) {
        $pm_batch_operation_line->line_action = null;
        $line_action_class = !empty($pm_batch_operation_line->status) ? ' always_readonly ' : null;
        ?>         
        <tr class="pm_batch_operation_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($pm_batch_operation_line->pm_batch_operation_line_id, array('pm_batch_header_id' => $$class->pm_batch_header_id));
          ?>
         </td>

         <td><?php form::text_field_wid2sr('pm_batch_operation_line_id'); ?></td>
         <td><?php echo $f->number_field('step_no', $$class_second->step_no, '', '', 'small ', '', 1); ?></td>
         <td><?php echo $f->select_field_from_object('activity_code', option_header::find_options_byName('PM_OPERATION_ACTIVITY'), 'option_line_code', 'option_line_value', $$class_second->activity_code, '', 'medium'); ?></td>
         <td><?php $f->text_field_wid2('description'); ?></td>
         <td><?php $f->text_field_wid2s('activity_factror'); ?></td>
         <td><?php $f->checkBox_field_wid2('sequence_dependency_cb'); ?></td>
         
         <td><?php $f->checkBox_field_wid2('breakable_cb'); ?></td>
         <td><?php $f->checkBox_field_wid2('material_scheduled_cb'); ?></td>
         <td><?php echo $f->select_field_from_array('release_type', pm_process_routing_line::$release_type_a, $$class_second->release_type, '', 'uom_id medium'); ?></td>
         <td><?php echo $f->select_field_from_array('line_action', pm_batch_operation_line::$line_action_a, $$class_second->line_action, '', $line_action_class); ?></td>
         <td><?php $f->text_field_wid2sr('status','always_readonly'); ?></td>
         <td class="add_detail_values"><i class="fa fa-arrow-circle-down add_detail_values_img"></i>
          <?php
          $pm_batch_operation_line_id = $pm_batch_operation_line->pm_batch_operation_line_id;
          if (!empty($pm_batch_operation_line_id)) {
           $pm_batch_operation_detail_object = pm_batch_operation_detail::find_by_parent_id($pm_batch_operation_line_id);
          } else {
           $pm_batch_operation_detail_object = [new pm_batch_operation_detail()];
          }
          if (empty($pm_batch_operation_detail_object) || count($pm_batch_operation_detail_object) == 0) {
           $pm_batch_operation_detail_object = [new pm_batch_operation_detail()];
          }
          ?>
          <div class="class_detail_form">
           <fieldset class="form_detail_data_fs">
            <div class="tabsDetail">
             <ul class="tabMain">
              <li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>"><?php echo gettext('Resource') ?></a></li>
              <li class="tabLink"><a href="#tabsDetail-2-<?php echo $count ?>"><?php echo gettext('Resource - II') ?></a></li>
             </ul>
             <div class="tabContainer">
              <div id="tabsDetail-1-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th><?php echo gettext('Action') ?></th>
                  <th><?php echo gettext('Detail Id') ?></th>
                  <th><?php echo gettext('Resource Seq') ?></th>
                  <th><?php echo gettext('Resource') ?></th>
                  <th><?php echo gettext('Batch UOM') ?></th>
                  <th><?php echo gettext('Quantity') ?></th>
                  <th><?php echo gettext('Applied Quantity') ?></th>
                  <th><?php echo gettext('UOM') ?></th>
                  <th><?php echo gettext('Usage') ?></th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($pm_batch_operation_detail_object as $pm_batch_operation_detail) {
                  $class_third = 'pm_batch_operation_detail';
                  $$class_third = &$pm_batch_operation_detail;
                  ?>
                  <tr class="pm_batch_operation_detail<?php echo $count . '-' . $detailCount; ?>">
                   <td>   
                    <ul class="inline_action">
                     <li class="add_row_detail_img"><i class="fa fa-plus-circle clickable"></i></li>
                     <li class="remove_row_img"><i class="fa fa-minus-circle clickable"></i></li>
                     <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($pm_batch_operation_detail->pm_batch_operation_detail_id); ?>"></li>           
                     <li><?php echo form::hidden_field('pm_batch_operation_line_id', $pm_batch_operation_line->pm_batch_operation_line_id); ?></li>
                     <li><?php echo form::hidden_field('pm_batch_header_id', $$class->pm_batch_header_id); ?></li>
                    </ul>
                   </td>
                   <td><?php form::text_field_wid3r('pm_batch_operation_detail_id'); ?></td>
                   <td><?php $f->text_field_d3('resource_sequence', 'detail_number'); ?></td>
                   <td><?php echo form::select_field_from_object('bom_resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_third->bom_resource_id, '', $readonly, 'resource_id', '', 1); ?></td>
                   <td><?php echo $f->select_field_from_object('batch_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_third->batch_uom_id); ?></td>
                   <td><?php form::number_field_wid3sm('process_quantity') ?></td>
                   <td><?php $f->text_field_d3r('applied_quantiy', 'always_readonly'); ?></td>
                   <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_third->uom_id); ?></td>
                   <td><?php form::number_field_wid3sm('resource_usage') ?></td>
                  </tr>
                  <?php
                  $detailCount++;
                 }
                 ?>
                </tbody>
               </table>
              </div>
              <div id="tabsDetail-2-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th><?php echo gettext('Detail Id') ?></th>
                  <th><?php echo gettext('Resource Count') ?></th>
                  <th><?php echo gettext('Offset Interval') ?></th>
                  <th><?php echo gettext('Scale Type') ?></th>
                  <th><?php echo gettext('Component Class') ?></th>
                  <th><?php echo gettext('Cost Code') ?></th>
                  <th><?php echo gettext('Plan Type') ?></th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($pm_batch_operation_detail_object as $pm_batch_operation_detail) {
                  $class_third = 'pm_batch_operation_detail';
                  $$class_third = &$pm_batch_operation_detail;
                  ?>
                  <tr class="pm_batch_operation_detail<?php echo $count . '-' . $detailCount; ?>">
                   <td><?php form::text_field_wid3sr('pm_batch_operation_detail_id'); ?></td>
                   <td><?php form::text_field_wid3('resource_count') ?></td>
                   <td><?php form::text_field_wid3('offset_interval') ?></td>
                   <td><?php form::text_field_wid3('scale_type') ?></td>
                   <td><?php form::text_field_wid3('component_class') ?></td>
                   <td><?php form::text_field_wid3('cost_analysis_code') ?></td>
                   <td><?php form::text_field_wid3('plan_type') ?></td>
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
   </div>
  </div>
 </form>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="pm_batch_operation_header" ></li>
  <li class="lineClassName" data-lineClassName="pm_batch_operation_line" ></li>
  <li class="detailClassName" data-detailClassName="pm_batch_operation_detail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="pm_batch_operation_header_id" ></li>
  <li class="form_header_id" data-form_header_id="pm_batch_operation_header" ></li>
  <li class="line_key_field" data-line_key_field="step_no" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="pm_batch_operation_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="pm_batch_operation_header_id" ></li>
  <li class="docLineId" data-docLineId="pm_batch_operation_line_id" ></li>
  <li class="docDetailId" data-docDetailId="pm_batch_operation_detail_id" ></li>
  <li class="btn1DivId" data-btn1DivId="pm_batch_operation_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>