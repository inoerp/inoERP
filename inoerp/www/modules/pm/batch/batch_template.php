<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php
  $f = new inoform();
  echo gettext('Production Batch')
  ?></span>
 <form method="post" id="pm_batch_header"  name="pm_batch_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Planning') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('pm_batch_header_id') ?>
       <a name="show" href="form.php?class_name=pm_batch_header&<?php echo "mode=$mode"; ?>" class="show document_id pm_batch_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_dm('batch_name'); ?></li>
      <li><?php
       echo $f->l_val_field_dm('recipe_name', 'pm_recipe_all_v', 'recipe_name', '', 'vf_select_recipe_name');
       echo $f->hidden_field_withId('pm_recipe_header_id', $$class->pm_recipe_header_id);
       ?><i class="generic g_select_recipe_name select_popup clickable fa fa-search" data-class_name="pm_recipe_all_v"></i></li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly1, '', ''); ?>						 </li>
      <li><label><?php echo gettext('Accounting Group') ?></label><?php echo $f->select_field_from_object('wip_accounting_group_id', wip_accounting_group::find_by_woType('PROCESS'), 'wip_accounting_group_id', ['wip_accounting_group','org_id'], $$class->wip_accounting_group_id, 'wip_accounting_group_id', '', 1, 'readonly1' , '' ,'','','org_id'); ?>         </li>
      <li><?php $f->l_text_field_d('revision'); ?></li>
      <li><?php $f->l_select_field_from_array('status', pm_batch_header::$status_a, $$class->status, '', 'always_readonly', '', 1); ?></li>
      <li><label><?php echo gettext('Owner') ?></label><?php $f->text_field_d('pm_employee_name', 'employee_name'); ?>
       <?php echo $f->hidden_field_withId('owner_employee_id', $$class->owner_employee_id); ?>
       <i class="select_employee_name select_popup clickable fa fa-search"></i>
      </li>
      <li><?php $f->l_text_field_d('routing_name') ?></li>
      <li><?php $f->l_text_field_d('formula_name') ?></li>
      <li><?php $f->l_text_field_d('description') ?></li>
      <li><label></label><a target="_new" href="form.php?class_name=pm_batch_operation_header&mode=9&pm_batch_header_id=<?php echo $$class->pm_batch_header_id; ?>" class="button btn btn-info ajax-link"><?php echo gettext('Operation Details') ?></a></li>
     </ul> 
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_date_fieldFromToday_d('planned_start_date', $$class->planned_start_date) ?></li>
      <li><?php $f->l_date_fieldFromToday_d('planned_completion_date', $$class->planned_completion_date) ?></li>
      <li><?php $f->l_date_fieldFromToday_dm('required_completion_date', $$class->required_completion_date) ?></li>
      <li><?php $f->l_date_fieldFromToday_d('actual_completion_date', $$class->actual_completion_date) ?></li>
      <li><?php $f->l_date_fieldFromToday_d('actual_start_date', $$class->actual_start_date) ?></li>
      <li><?php $f->l_text_field_d('terminate_reason') ?></li>
      <li><?php $f->l_checkBox_field_dr('batch_exploded_cb'); ?> </li>
      <li><?php $f->l_text_field_d('comment'); ?></li>
     </ul> 
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'pm_batch_header';
        $reference_id = $$class->pm_batch_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>

    <div id="tabsHeader-5" class="tabContent">
     <ul class="column header_field">
      <li id="document_status"><label><?php echo gettext('Action') ?></label>
       <?php echo $f->select_field_from_array('action', $$class->action_a, '', 'action'); ?>
      </li>
     </ul>
    </div>
   </div>
  </div>
 </form>
</div>
<span class="heading"><?php echo gettext('Production Details') ?></span>
<div id="tabsLine">
 <ul class="tabMain">
  <li><a href="#tabsLine-1"><?php echo gettext('Products') ?></a></li>
  <li><a href="#tabsLine-2"><?php echo gettext('Ingredients') ?></a></li>
  <li><a href="#tabsLine-3"><?php echo gettext('By Products') ?> </a></li>
 </ul>
 <div class="tabContainer">
  <form method="post" id="pm_batch_line"  name="pm_batch_line" class="m-margin-top-20">
   <div id="form_line" class="form_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line') ?> #</th>
        <th><?php echo gettext('Item') ?> #</th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Planned Qty') ?></th>
        <th><?php echo gettext('Actual Qty') ?></th>
        <th><?php echo gettext('Yield Type') ?></th>
        <th><?php echo gettext('Scale Type') ?></th>
        <th><?php echo gettext('Step') ?> #</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       $pm_batch_line_object_ai = new ArrayIterator($pm_batch_line_object);
       $pm_batch_line_object_ai->seek($position);
       while ($pm_batch_line_object_ai->valid()) {
        $pm_batch_line = $pm_batch_line_object_ai->current();
        if (!empty($pm_batch_line->item_id_m)) {
         $item_f = item::find_by_item_id_m($pm_batch_line->item_id_m);
         $$class_second->item_number = $item_f->item_number;
         $$class_second->item_description = $item_f->item_description;
        } else {
         $$class_second->item_number = $$class_second->item_description = null;
        }
        ?>         
        <tr class="pm_batch_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($pm_batch_line->pm_batch_line_id, array('pm_batch_header_id' => $pm_batch_header->pm_batch_header_id));
          ?>
         </td>
         <td><?php $f->text_field_wid2sr('pm_batch_line_id', 'line_id'); ?></td>
         <td><?php echo $f->number_field('line_no', $$class_second->line_no, '', '', 'lines_number small ', 1, $readonly); ?></td>
         <td><?php
          $f->val_field_wid2('item_number', 'item', 'item_number', 'receving_org_id');
          echo $f->hidden_field_withCLass('item_id_m', $$class_second->item_id_m, 'dont_copy_r');
          ?>
          <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
         <td><?php form::text_field_wid2('item_description'); ?></td>
         <td><?php echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom_id'); ?></td>
         <td><?php echo $f->number_field('planned_quantity', $$class_second->planned_quantity, '', '', 'allow_change'); ?></td>
         <td><?php echo $f->number_field('actual_quantity', $$class_second->actual_quantity, '', '', 'always_readonly', '', 1); ?></td>
         <td><?php echo $f->select_field_from_array('yield_type', pm_batch_line::$yield_type_a, $$class_second->yield_type, '', 'medium'); ?></td>
         <td><?php echo $f->select_field_from_array('scale_type', pm_formula_line::$scale_type_a, $$class_second->scale_type, '', 'medium') ?></td>
         <td><?php echo $f->number_field('step_no', $$class_second->step_no, '', 'always_readonly', 'small ', '', 1); ?></td>
        </tr>
        <?php
        $pm_batch_line_object_ai->next();
        if ($pm_batch_line_object_ai->key() == $position + $per_page) {
         break;
        }
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </div>
  </form>
  <div id ="form_line2" class="form_line2">
   <form  method="post" id="pm_batch_ingredient"  name="pm_batch_ingredient">
    <div id="tabsLine-2" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line') ?>#</th>
        <th><?php echo gettext('Ingredient') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Planned') ?></th>
        <th><?php echo gettext('Actual') ?></th>
        <th><?php echo gettext('Scale Type') ?></th>
        <th><?php echo gettext('Yield') ?></th>
        <th><?php echo gettext('Consumption') ?></th>
        <th><?php echo gettext('Sub') ?></th>
        <th><?php echo gettext('Locator') ?></th>
        <th><?php echo gettext('Step') ?> #</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
       <?php
       $count = 0;
       foreach ($pm_batch_ingredient_object as $pm_batch_ingredient) {
        if (!empty($pm_batch_ingredient->item_id_m)) {
         $item_ig = item::find_by_item_id_m($pm_batch_ingredient->item_id_m);
         $$class_third->item_number = $item_ig->item_number;
         $$class_third->item_description = $item_ig->item_description;
        } else {
         $$class_third->item_number = $$class_third->item_description = null;
        }
        ?>         
        <tr class="pm_batch_ingredient<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
           <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($pm_batch_ingredient->pm_batch_ingredient_id); ?>"></li>           
           <li><?php echo form::hidden_field('pm_batch_header_id', $$class->pm_batch_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid3sr('pm_batch_ingredient_id'); ?></td>
         <td><?php echo $f->number_field('line_no', $$class_third->line_no, '', '', 'lines_number small ', 1, $readonly); ?></td>
         <td><?php
          $f->val_field_wid3('item_number', 'item', 'item_number', 'org_id');
          echo $f->hidden_field_withCLass('item_id_m', $$class_third->item_id_m, 'dont_copy_r');
          echo $f->hidden_field_withCLass('purchased_cb', '1', 'popup_value');
          ?>
          <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
         <td><?php form::text_field_wid3('item_description'); ?></td>
         <td><?php echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_third->uom_id, '', '', 'uom_id'); ?></td>
         <td><?php echo $f->number_field('planned_quantity', $$class_third->planned_quantity, '', '', 'allow_change small'); ?></td>
         <td><?php echo $f->number_field('actual_quantity', $$class_third->actual_quantity, '', '', 'always_readonly small', '', 1); ?></td>
         <td><?php echo $f->select_field_from_array('scale_type', pm_formula_line::$scale_type_a, $$class_third->scale_type, '', 'medium') ?></td>
         <td><?php echo $f->checkBox_field('contribute_yield_cb', $$class_third->contribute_yield_cb); ?></td>
         <td><?php echo $f->select_field_from_array('consumption_type', pm_formula_ingredient::$consumption_type_a, $$class_third->consumption_type, '', 'medium'); ?></td>
         <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_third->subinventory_id, '', 'subinventory_id'); ?></td>
         <td><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_third->subinventory_id), 'locator_id', 'locator', $$class_third->locator_id, '', 'locator_id medium'); ?></td>
         <td><?php echo $f->number_field('step_no', $$class_third->step_no, '', 'always_readonly', 'small ', '', 1); ?></td>
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
  <div id ="form_line3" class="form_line3">
   <div id="tabsLine-3" class="tabContent">
    <form  method="post" id="pm_batch_byproduct"  name="pm_batch_byproduct">
     <table class="form_line_data_table3">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line') ?>#</th>
        <th><?php echo gettext('By Product') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Planned Qty') ?></th>
        <th><?php echo gettext('Allocated Qty') ?></th>
        <th><?php echo gettext('Scale Type') ?></th>
        <th><?php echo gettext('Yield Type') ?></th>
        <th><?php echo gettext('Byproduct Type') ?></th>
        <th><?php echo gettext('Step') ?> #</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody3 wip_wo_bom_values" >
       <?php
       $count = 0;
       foreach ($pm_batch_byproduct_object as $pm_batch_byproduct) {
        if (!empty($pm_batch_byproduct->item_id_m)) {
         $item_bp = item::find_by_item_id_m($pm_batch_byproduct->item_id_m);
         $$class_fourth->item_number = $item_bp->item_number;
         $$class_fourth->item_description = $item_bp->item_description;
        } else {
         $$class_fourth->item_number = $$class_fourth->item_description = null;
        }
        ?>         
        <tr class="pm_batch_byproduct<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
           <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($pm_batch_byproduct->pm_batch_byproduct_id); ?>"></li>           
           <li><?php echo form::hidden_field('pm_batch_header_id', $$class->pm_batch_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid4sr('pm_batch_byproduct_id'); ?></td>
         <td><?php echo $f->number_field('line_no', $$class_third->line_no, '', '', 'lines_number small ', 1, $readonly); ?></td>
         <td><?php
          $f->val_field_wid4('item_number', 'item', 'item_number', 'org_id');
          echo $f->hidden_field_withCLass('item_id_m', $$class_fourth->item_id_m, 'dont_copy_r');
          echo $f->hidden_field('processing_lt', '');
          ?>
          <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
         <td><?php form::text_field_wid4('item_description'); ?></td>
         <td><?php echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_fourth->uom_id, '', '', 'uom_id'); ?></td>
         <td><?php echo $f->number_field('planned_quantity', $$class_fourth->planned_quantity, '', '', 'allow_change small'); ?></td>
         <td><?php echo $f->number_field('allocated_quantity', $$class_fourth->allocated_quantity, '', '', 'allow_change small'); ?></td>
         <td><?php echo $f->select_field_from_array('scale_type', pm_formula_line::$scale_type_a, $$class_fourth->scale_type, '', 'medium') ?></td>
         <td><?php echo $f->select_field_from_array('yield_type', pm_batch_line::$yield_type_a, $$class_fourth->yield_type, '', 'medium'); ?></td>
         <td><?php echo $f->select_field_from_array('byproduct_type', pm_formula_byproduct::$byproduct_type_a, $$class_fourth->byproduct_type, '', 'medium'); ?></td>
         <td><?php echo $f->number_field('step_no', $$class_fourth->step_no, '', 'always_readonly', 'small ', '', 1); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </form>
   </div>
  </div>
 </div>
</div>

<div class="row small-top-margin">
 <div id="pagination" style="clear: both;">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="pm_batch_header" ></li>
  <li class="lineClassName" data-lineClassName="pm_batch_line" ></li>
  <li class="lineClassName2" data-lineClassName2="pm_batch_ingredient" ></li>
  <li class="lineClassName3" data-lineClassName3="pm_batch_byproduct" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="pm_batch_header_id" ></li>
  <li class="form_header_id" data-form_header_id="pm_batch_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="pm_batch_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="pm_batch_header_id" ></li>
  <li class="docLineId" data-docLineId="pm_batch_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="pm_batch_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="6" ></li>
 </ul>
</div>
