<div id ="form_header">
 <span class="heading"><?php echo gettext('Date Rules [For Maintenace Schedule]') ?></span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Schedule Info') ?></a></li>
   <li><a href="#tabsHeader-2"><?php echo gettext('Future') ?></a></li>
  </ul>
  <div class="tabContainer">
   <div id="tabsHeader-1" class="tabContent">
    <ul class="column header_field">
     <li><label><i class="am_maintenance_schedule_id select_popup clickable fa fa-search"></i>
       <?php echo gettext('Schedule Id') ?></label><?php 
       echo $f->text_field('am_maintenance_schedule_id', $maint_sch->am_maintenance_schedule_id, '', 'am_maintenance_schedule_id', '', '', 1) ?>
      <a name="show" href="form.php?class_name=am_ms_date_rule&<?php echo "mode=$mode"; ?>" class="show document_id am_maintenance_schedule_id"><i class="fa fa-refresh"></i></a> 
     </li>
     <li><?php $f->l_select_field_from_object('org_id', $org->findAll_inventory(), 'org_id', 'org', $maint_sch->org_id, 'org_id', '', 1, 1); ?></li>
     <li><?php $f->l_text_field('schedule_name', $maint_sch->schedule_name, '', '', '', '', 1); ?></li>
     <li><?php $f->l_text_field('schedule_number', $maint_sch->schedule_number, '', '', '', '', 1); ?></li>
     <li><label><?php echo gettext('Inv Item Number') ?>
      </label><?php echo $f->text_field('item_number', $maint_sch->item_number, '', '', '', '', 1); ?>    </li>
     <li><label><?php echo gettext('Asset Number') ?></label><?php echo $f->text_field('am_asset_number', $maint_sch->am_asset_number, '', '', '', '', 1); ?>  </li>
          <li><?php $f->l_date_fieldAnyDay_r('effective_start_date', $maint_sch->effective_start_date); ?></li>
     <li><?php $f->l_date_fieldAnyDay_r('effective_end_date', $maint_sch->effective_end_date); ?></li>
     <li><?php $f->l_number_field('intervals_per_cycle', $maint_sch->intervals_per_cycle, '', 'intervals_per_cycle', '', '', 1); ?></li>
     
    </ul>
   </div>
   <div id="tabsHeader-2" class="tabContent">
    <div class="large_shadow_box"> 

    </div>
   </div>
  </div>
 </div>
</div>

<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Date Rules') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Date Rules') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <form action=""  method="post" id="am_ms_date_rule_line"  name="am_ms_date_rule_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Rule Id') ?></th>
        <th><?php echo gettext('Base Interval Days') ?></th>
        <th><?php echo gettext('Cycle Interval Days') ?></th>
        <th><?php echo gettext('From Date') ?></th>
        <th><?php echo gettext('To Date') ?></th>
        <th><?php echo gettext('Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody am_ms_date_rule_values" >
       <?php
       $count = 0;
       foreach ($am_ms_date_rule_object as $am_ms_date_rule) {
        ?>         
        <tr class="am_ms_date_rule<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class->am_ms_date_rule_id, array('am_maintenance_schedule_id' => $am_maintenance_schedule_id_h));
          ?>
         </td>
         <td><?php $f->text_field_widr('am_ms_date_rule_id'); ?></td>
         <td><?php echo $f->number_field('base_interval_days', $$class->base_interval_days); ?></td>
         <td><?php echo $f->number_field('cycle_interval_days', $$class->cycle_interval_days,'','','','',1); ?></td>
         <td><?php echo $f->date_fieldAnyDay('from_date', $$class->from_date); ?></td>
         <td><?php echo $f->date_fieldAnyDay('to_date', $$class->to_date); ?></td>
         <td><?php $f->text_field_wid('description'); ?></td>
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

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="am_ms_date_rule" ></li>
  <li class="primary_column_id" data-primary_column_id="am_maintenance_schedule_id" ></li>
  <li class="lineClassName" data-lineClassName="am_ms_date_rule" ></li>
  <li class="line_key_field" data-line_key_field="item_id_m" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="am_ms_date_rule" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="am_ms_date_rule_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="am_ms_date_rule" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
