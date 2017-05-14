<div id="form_all">
 <form method="post" id="am_asset"  name="am_asset">
  <span class="heading"><?php echo gettext('Asset Numbers') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Tracking Info') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('References') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Address Details') ?></a></li>
     <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-6"><?php echo gettext('Note') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('am_asset_id') ?>
        <a name="show" href="form.php?class_name=am_asset&<?php echo "mode=$mode"; ?>" class="show document_id am_asset_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('org_id', $org->findAll_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?></li>
       <li><?php $f->l_text_field_d('asset_number'); ?></li>
       <li><label><?php echo gettext('Inv Item Number') ?></label><?php
        echo $f->hidden_field_withId('item_id_m', $$class->item_id_m);
        $f->text_field_dm('item_number', 'select_item_number_am_asset_item');
        echo $f->hidden_field_withCLass('am_asset_type', 'ASSET_ITEM', 'popup_value');
        ?><i class="select_item_number select_popup clickable fa fa-search"></i>
       </li>
       <li><?php $f->l_text_field_d('item_description'); ?></li>
       <li><?php $f->l_select_field_from_object('am_asset_category_id', fa_asset_category::find_all(), 'fa_asset_category_id', 'asset_category', $$class->am_asset_category_id, 'am_asset_category_id', '', 1); ?></li>
       <li><?php $f->l_select_field_from_array('status', am_asset::$status_a, $$class->status, 'status'); ?></li>
       <li><?php $f->l_text_field_dm('serial_number'); ?></li>
       <li><?php $f->l_select_field_from_array('type', am_asset::$type_a, $$class->type, '', '', 1, 1, 1); ?></li>
       <li><?php $f->l_text_field_d('parent_asset_id'); ?></li>
       <li><label><?php echo gettext('Accounting Group') ?></label><?php echo $f->select_field_from_object('wip_accounting_group_id', wip_accounting_group::find_by_woType('NON_STANDARD'), 'wip_accounting_group_id', ['wip_accounting_group','org_id'], $$class->wip_accounting_group_id, 'wip_accounting_group_id', '', 1, 'readonly1' , '' ,'','','org_id'); ?>         </li>
       <li><?php $f->l_text_field_d('description'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_d('tag_number'); ?></li>
       <li><?php $f->l_select_field_from_object('owning_department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class->owning_department_id, '', $readonly, '', '', 1); ?></li>
       <li><?php
        echo $f->l_val_field_d('employee_name', 'hr_employee_v', 'employee_name', '', 'vf_select_employee_name employee_name');
        echo $f->hidden_field_withIdClass('owning_employee_id', $$class->owning_employee_id ,'hr_employee_id');
        ?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
       <li><?php $f->l_select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->subinventory_id, '', 'subinventory_id', '', $readonly); ?>       </li>
       <li><?php $f->l_select_field_from_object('locator_id', locator::find_all_of_subinventory($$class->subinventory_id), 'locator_id', 'locator', $$class->locator_id, '', 'locator_id', '', $readonly); ?>       </li>
       <li><?php $f->l_checkBox_field_d('maintainable_cb'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_d('equipment_item_id_m'); ?></li>
       <li><?php $f->l_text_field_d('fa_asset_id'); ?></li>
       <li><?php $f->l_text_field_d('production_org_id'); ?></li>
       <li><?php $f->l_text_field_d('manufacturer'); ?></li>
       <li><?php $f->l_text_field_d('model_number'); ?></li>
       <li><?php $f->l_text_field_d('warranty_number'); ?></li>
       <li><?php $f->l_date_fieldAnyDay('warranty_exp_date', $$class->warranty_exp_date); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div class="assign_address"><?php $f->address_field_d('address_id'); ?></div>
     </div>
     <div id="tabsHeader-5" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-6" class="tabContent">
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'am_asset';
        $reference_id = $$class->am_asset_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
      <div> 
      </div>
     </div>
    </div>
   </div>
  </div>

  <div id ="form_line" class="form_line">
   <span class="heading"><?php echo gettext('Asset Activities') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Activity Reference') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Reference2') ?> </a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Other Details') ?> </a></li>
     <li><a href="#tabsLine-4"><?php echo gettext('Secondary') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('Line Id') ?></th>
         <th><?php echo gettext('Activity Item') ?></th>
         <th><?php echo gettext('Start Date') ?></th>
         <th><?php echo gettext('End Date') ?></th>
         <th><?php echo gettext('Type') ?></th>
         <th><?php echo gettext('Cause') ?></th>
         <th><?php echo gettext('Source') ?></th>
         <th><?php echo gettext('Description') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody am_activity_reference_values" >
        <?php
        $count = 0;
        $am_activity_reference_object_ai = new ArrayIterator($am_activity_reference_object);
        $am_activity_reference_object_ai->seek($position);
        while ($am_activity_reference_object_ai->valid()) {
         $am_activity_reference = $am_activity_reference_object_ai->current();
         if (!empty($am_activity_reference->hr_employe_id)) {
          $emp_details_l = hr_employee::find_by_id($am_activity_reference->hr_employe_id);
          $am_activity_reference->employee_name = $emp_details_l->first_name . ' ' . $emp_details_l->last_name;
         } else {
          $am_activity_reference->employee_name = null;
         }
         if (!empty($$class_second->activity_item_id_m)) {
          $activity_item_i = item::find_by_item_id_m($$class_second->activity_item_id_m);
          $$class_second->activity_item_number = !empty($activity_item_i->item_number) ? $activity_item_i->item_number : '';
         } else {
          $$class_second->activity_item_number = '';
         }
         ?>         
         <tr class="am_activity_reference<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_second->am_activity_reference_id, array('am_asset_id' => $$class->am_asset_id));
           ?>
          </td>
          <td><?php $f->seq_field_d($count) ?></td>
          <td><?php $f->text_field_wid2sr('am_activity_reference_id'); ?></td>
          <td><?php
           echo $f->hidden_field_withCLass('activity_item_id_m', $$class_second->activity_item_id_m, 'item_id_m');
           $f->text_field_wid2('activity_item_number', 'select_item_number_am_asset_activity');
           echo $f->hidden_field_withCLass('am_asset_type', 'ASSET_ACTIVITY', 'popup_value');
           ?><i class="select_item_number select_popup clickable fa fa-search"></i>
          </td>
          <td><?php echo $f->date_fieldAnyDay('start_date', $$class_second->start_date); ?></td>
          <td><?php echo $f->date_fieldAnyDay('end_date', $$class_second->end_date); ?></td>
          <td><?php echo $f->select_field_from_object('activity_cause', am_asset_activity::activity_cause(), 'option_line_code', 'option_line_value', $$class_second->activity_cause); ?></td>
          <td><?php echo $f->select_field_from_object('activity_type', am_asset_activity::activity_type(), 'option_line_code', 'option_line_value', $$class_second->activity_type); ?></td>
          <td><?php echo $f->select_field_from_object('activity_source', am_asset_activity::activity_source(), 'option_line_code', 'option_line_value', $$class_second->activity_source); ?></td>
          <td><?php $f->text_field_wid2('description'); ?></td>
         </tr>
         <?php
         $am_activity_reference_object_ai->next();
         if ($am_activity_reference_object_ai->key() == $position + $per_page) {
          break;
         }
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
      <!--end of tab1 div three_column-->
     </div> 
     <div id="tabsLine-2" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('Priority') ?></th>
         <th><?php echo gettext('Shutdown Type') ?>#</th>
         <th><?php echo gettext('Accounting Class') ?></th>
         <th><?php echo gettext('Owning Department') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody am_activity_reference_values" >
        <?php
        $count = 0;
        $am_activity_reference_object_ai = new ArrayIterator($am_activity_reference_object);
        $am_activity_reference_object_ai->seek($position);
        while ($am_activity_reference_object_ai->valid()) {
         $am_activity_reference = $am_activity_reference_object_ai->current();
         if (!empty($am_activity_reference->hr_employe_id)) {
          $emp_details_l = hr_employee::find_by_id($am_activity_reference->hr_employe_id);
          $am_activity_reference->employee_name = $emp_details_l->first_name . ' ' . $emp_details_l->last_name;
         } else {
          $am_activity_reference->employee_name = null;
         }
         ?>         
         <tr class="am_activity_reference<?php echo $count ?>">
          <td><?php $f->seq_field_d($count) ?></td>
          <td><?php echo $f->number_field('priority', $$class_second->priority, '', '', 'priority small'); ?></td>
          <td><?php $f->text_field_wid2('shutdown_type'); ?></td>
          <td><?php $f->text_field_wid2('accounting_class_id'); ?></td>
          <td><?php $f->text_field_wid2('owning_department_id'); ?></td>
         </tr>
         <?php
         $am_activity_reference_object_ai->next();
         if ($am_activity_reference_object_ai->key() == $position + $per_page) {
          break;
         }
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
      <!--end of tab1 div three_column-->
     </div> 
     <div id="tabsLine-3" class="tabContent">
      <ul class='column four_column'>
       <li>      <button type="button" class="btn btn-primary btn-lg disabled">
         <span class="glyphicon glyphicon-list-alt" aria-hidden="true"></span> <?php echo gettext('Activity Meter') ?>
        </button>
       </li>

       <li>      <button type="button" class="btn btn-primary btn-lg disabled">
         <span class="glyphicon glyphicon-list-alt" aria-hidden="true"></span> <?php echo gettext('Maintenance Schedules') ?>
        </button>
       </li>

      </ul>

     </div>
     <div id="tabsLine-4" class="tabContent">
      <?php echo!empty($secondary_field_stmt) ? $secondary_field_stmt : null; ?>
     </div>
    </div>


   </div>



  </div> 
 </form>
 <div id="pagination" style="clear: both;">
  <?php echo ($total_count > 9 ) ? $pagination->show_pagination() : ''; ?>
 </div>
</div>




<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="am_asset" ></li>
  <li class="lineClassName" data-lineClassName="am_activity_reference" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="am_asset_id" ></li>
  <li class="form_header_id" data-form_header_id="am_asset" ></li>
  <li class="line_key_field" data-line_key_field="line_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="am_activity_reference" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="am_asset_id" ></li>
  <li class="docLineId" data-docLineId="am_activity_reference_id" ></li>
  <li class="btn1DivId" data-btn1DivId="am_asset" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="am_activity_reference" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
