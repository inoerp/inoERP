<div id="form_all">
 <form method="post" id="am_maintenance_schedule"  name="am_maintenance_schedule">
  <span class="heading"><?php echo gettext('Maintenance Schedule') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Planning') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('am_maintenance_schedule_id') ?>
        <a name="show" href="form.php?class_name=am_maintenance_schedule&<?php echo "mode=$mode"; ?>" class="show document_id am_maintenance_schedule_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('org_id', $org->findAll_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?></li>
       <li><?php $f->l_text_field_dm('schedule_name'); ?></li>
       <li><?php $f->l_text_field_d('schedule_number'); ?></li>
       <li><label>
         <!--<i class="select_item_number select_popup clickable fa fa-search"></i>-->
        <?php echo gettext('Inv Item Number') ?>
        </label><?php
        echo $f->hidden_field_withId('item_id_m', $$class->item_id_m);
        $f->text_field_dr('item_number', 'select_item_number_am_asset_item');
        echo $f->hidden_field_withCLass('am_asset_type', 'ASSET_ITEM', 'popup_value');
        ?>
       </li>
       <li><label><i class="select_am_asset_number select_popup clickable fa fa-search"></i>
         <?php echo gettext('Asset Number') ?></label><?php
        $f->text_field_d('am_asset_number');
        echo $f->hidden_field_withId('am_asset_id', $$class->am_asset_id);
        ?>
       </li>
       <li><?php $f->l_date_fieldAnyDay('effective_start_date', $$class->effective_start_date); ?></li>
       <li><?php $f->l_date_fieldAnyDay('effective_end_date', $$class->effective_end_date); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_array('schedule_basis', am_maintenance_schedule::$schedule_basis_a, $$class->schedule_basis,'schedule_basis','',1); ?></li>
       <li><?php $f->l_date_fieldAnyDay('schedule_basis_date', $$class->schedule_basis_date); ?></li>
       <li><?php $f->l_select_field_from_array('schedule_method', am_maintenance_schedule::$schedule_method_a, $$class->schedule_method,'schedule_method','',1); ?></li>
       <li><?php $f->l_number_field_d('intervals_per_cycle'); ?></li>
       <li><?php $f->l_number_field_d('current_cycle'); ?></li>
       <li><?php $f->l_number_field_d('current_cycle_interval'); ?></li>
       <li><?php $f->l_checkBox_field_d('create_wo_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('reschedule_wo_cb'); ?></li>
        <li><?php $f->l_select_field_from_array('status', am_maintenance_schedule::$status_a, $$class->status,'status'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'am_maintenance_schedule';
        $reference_id = $$class->am_maintenance_schedule_id;
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
   <span class="heading"><?php echo gettext('Maintenance Schedule Activities') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Activities') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Rules') ?> </a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Ref Id') ?></th>
         <th><?php echo gettext('Activity') ?></th>
         <th><?php echo gettext('Interval Multiple') ?></th>
         <th><?php echo gettext('Repeat in Cycle') ?></th>
         <th><?php echo gettext('Last Date') ?></th>
         <th><?php echo gettext('Description') ?></th>
         <th><?php echo gettext('Consolidate') ?></th>
         <th><?php echo gettext('Last Service') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
        foreach ($am_ms_activity_reference_object as $am_ms_activity_reference) {
         if (!empty($$class_second->activity_item_id_m)) {
          $activity_item_i = item::find_by_item_id_m($$class_second->activity_item_id_m);
          $$class_second->activity_item_number = !empty($activity_item_i->item_number) ? $activity_item_i->item_number : '';
         } else {
          $$class_second->activity_item_number = '';
         }
         ?>         
         <tr class="am_ms_activity_reference<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_second->am_ms_activity_reference_id, array('am_maintenance_schedule_id' => $$class->am_maintenance_schedule_id));
           ?>
          </td>
          <td><?php $f->text_field_wid2sr('am_ms_activity_reference_id'); ?></td>
          <td><?php
           $f->text_field_wid2('activity_item_number', 'select_item_number_am_asset_activity');
           echo $f->hidden_field_withCLass('activity_item_id_m', $$class_second->activity_item_id_m, 'item_id_m');
           echo $f->hidden_field_withCLass('am_asset_type', 'ASSET_ACTIVITY', 'popup_value');
           ?><i class="fa fa-search select_item_number select_popup"></i></td>
          <td><?php echo $f->number_field('interval_multiple', $$class_second->interval_multiple); ?></td>
          <td><?php $f->checkBox_field_wid2('repeat_in_cycle_cb'); ?></td>
          <td><?php echo $f->date_fieldAnyDay_r('last_date', $$class_second->last_date, 1); ?></td>
          <td><?php $f->text_field_wid2('description'); ?></td>
          <td></td>
          <td></td>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-2" class="tabContent">
      <ul class='column four_column'>
       <li><a class="popup popup-form view-date-rule btn btn-default btn-lg" id="date_rule" role="button"
              href="form.php?class_name=am_ms_date_rule&mode=9&window_type=popup&am_maintenance_schedule_id=<?php echo $$class->am_maintenance_schedule_id ?>">
         <i class="fa fa-list-alt"></i> <?php echo gettext('Date Rule') ?></a>
       </li>
       <li><a class="popup popup-form view-meter-rule btn btn-default btn-lg" id="meter_rule" role="button"
              href="form.php?class_name=am_ms_meter_rule&mode=9&window_type=popup&am_maintenance_schedule_id=<?php echo $$class->am_maintenance_schedule_id ?>">
         <i class="fa fa-bar-chart-o"></i> <?php echo gettext('Meter Rule') ?></a>
       </li>
       <li><a class="popup popup-form view-calendar-date btn btn-default btn-lg" id="calendar-date" role="button"
              href="form.php?class_name=am_ms_calendar_date&mode=9&window_type=popup&am_maintenance_schedule_id=<?php echo $$class->am_maintenance_schedule_id ?>">
         <i class="fa fa-calendar"></i> <?php echo gettext('Calendar Date') ?></a>
       </li>
      </ul>
     </div>
    </div>
   </div>
  </div> 
 </form>
</div>




<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="am_maintenance_schedule" ></li>
  <li class="lineClassName" data-lineClassName="am_ms_activity_reference" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="am_maintenance_schedule_id" ></li>
  <li class="form_header_id" data-form_header_id="am_maintenance_schedule" ></li>
  <li class="line_key_field" data-line_key_field="line_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="am_ms_activity_reference" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="am_maintenance_schedule_id" ></li>
  <li class="docLineId" data-docLineId="am_ms_activity_reference_id" ></li>
  <li class="btn1DivId" data-btn1DivId="am_maintenance_schedule" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="am_ms_activity_reference" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>
