<div id ="form_header">
 <form  method="post" id="inv_count_header"  name="inv_count_header">
  <span class="heading"><?php echo gettext('Count Entry Header') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Line Defaults') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f = new inoform(); echo $f->l_date_fieldFromToday_dm('count_date', $$class->count_date, 'count_date', 'action') ?></li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', 'action', 1, $readonly1); ?>       </li>
      <li><?php
       echo $f->l_val_field_dm('count_name', 'inv_count_header', 'count_name', 'count_name', 'vf_select_count_name action');
       echo $f->hidden_field_withId('inv_count_header_id', $$class->inv_count_header_id);
       echo $f->hidden_field_withCLass('org_id', $$class->org_id, 'popup_value');
       ?><i class="generic g_select_count_name select_popup clickable fa fa-search" data-class_name="inv_count_header"></i>
       <a name="show" href="form.php?class_name=inv_count_entries&<?php echo "mode=$mode"; ?>" class="show2 document_id inv_count_entries_id"><i class="fa fa-refresh"></i></a>
      </li>
      <li><?php $f->l_text_field_d('description'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     
      <ul class="column header_field">
       <li><?php $f->l_ac_field_dm('adjustment_ac_id'); ?></li>
       <li><?php $f->l_text_field_d('counted_by'); ?></li>
      </ul>
     
    </div>
   </div>
  </div>
 </form>
</div>

<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Count Entries') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Schedule') ?></a></li>
   <li><a href="#tabsLine-2"><?php echo gettext('Reference') ?> </a></li>
   <li><a href="#tabsLine-3"><?php echo gettext('Adjustments') ?> </a></li>
  </ul>
  <div class="tabContainer"> 
   <form action=""  method="post" id="inv_count_entries_line"  name="inv_count_entries_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Count Id') ?></th>
        <th><?php echo gettext('Master Item Id') ?></th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Schedule Date') ?></th>
        <th><?php echo gettext('Subinventory') ?></th>
        <th><?php echo gettext('Locator') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody inv_count_schedule_values" >
       <?php
       $count = 0;
       $inv_count_schedule_object_ai = new ArrayIterator($inv_count_schedule_object);
       $inv_count_schedule_object_ai->seek($position);
       while ($inv_count_schedule_object_ai->valid()) {
        $inv_count_schedule = $inv_count_schedule_object_ai->current();
        ?>         
        <tr class="inv_count_entries<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->inv_count_schedule_id, array('inv_count_header_id' => $inv_count_header_id_h, 'org_id' => $$class->org_id));
          ?>
         </td>
         <td><?php $f->text_field_d2srm('inv_count_schedule_id'); ?></td>
         <td><?php $f->text_field_d2sr('item_id_m'); ?></td>
         <td><?php $f->text_field_wid2('item_number', 'select_item_number'); ?><i class="select_item_number select_popup clickable fa fa-search"></i></td>
         <td><?php $f->text_field_wid2('item_description'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small', '', 1); ?></td>
         <td><?php echo $f->date_fieldAnyDay('schedule_date', $$class_second->schedule_date); ?></td>
         <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->subinventory_id, '', 'subinventory_id medium', '', 1); ?></td>
         <td><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_second->subinventory_id), 'locator_id', 'locator', $$class_second->locator_id, '', 'locator_id medium', '', 1); ?></td>
        </tr>
        <?php
        $inv_count_schedule_object_ai->next();
        if ($inv_count_schedule_object_ai->key() == $position + $per_page) {
         break;
        }
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Count Id') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Lot Number') ?></th>
        <th><?php echo gettext('Serial Number') ?></th>
        <th><?php echo gettext('Count By') ?></th>
        <th><?php echo gettext('Count Date') ?></th>
        <th><?php echo gettext('Adjustment AC') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody inv_count_schedule_values" >
       <?php
       $count = 0;
       $inv_count_schedule_object_ai = new ArrayIterator($inv_count_schedule_object);
       $inv_count_schedule_object_ai->seek($position);
       while ($inv_count_schedule_object_ai->valid()) {
        $inv_count_schedule = $inv_count_schedule_object_ai->current();
        ?>         
        <tr class="inv_count_entries<?php echo $count ?>">
         <td class="text_not_tobe_copied"><?php echo $$class_second->inv_count_schedule_id; ?></td>
         <td><?php $f->text_field_wid2('description'); ?></td>
         <td><?php $f->text_field_wid2('lot_number'); ?></td>
         <td><?php $f->text_field_wid2('serial_number'); ?></td>
         <td><?php echo $f->text_field('counted_by', '' ,'' ,'', 'required', 1); ?></td>
         <td><?php echo $f->date_fieldFromToday_d('count_date', ''); ?></td>
         <td><?php $f->ac_field_wid('adjustment_ac_id'); ?></td>
        </tr>
        <?php
        $inv_count_schedule_object_ai->next();
        if ($inv_count_schedule_object_ai->key() == $position + $per_page) {
         break;
        }
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-3" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Count Id') ?></th>
        <th><?php echo gettext('System Quantity') ?></th>
        <th><?php echo gettext('Counted Quantity') ?></th>
        <th><?php echo gettext('Adjusted Quantity') ?></th>
        <th><?php echo gettext('Adjustment Amount') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody inv_count_schedule_values" >
       <?php
       $count = 0;
       $inv_count_schedule_object_ai = new ArrayIterator($inv_count_schedule_object);
       $inv_count_schedule_object_ai->seek($position);
       while ($inv_count_schedule_object_ai->valid()) {
        $inv_count_schedule = $inv_count_schedule_object_ai->current();
        ?>         
        <tr class="inv_count_entries<?php echo $count ?>">
         <td class="text_not_tobe_copied"><?php echo $$class_second->inv_count_schedule_id; ?></td>
         <td><?php echo $f->text_field_ap(array('name' => 'system_qty', 'value' => '', 'readonly' => 1)); ?></td>
         <td><?php echo $f->text_field('count_qty', ''); ?></td>
         <td><?php echo $f->text_field_ap(array('name' => 'adjusted_qty', 'value' => '', 'readonly' => 1)); ?></td>
         <td><?php echo $f->text_field_ap(array('name' => 'adjusted_value', 'value' => '', 'readonly' => 1)); ?></td>
        </tr>
        <?php
        $inv_count_schedule_object_ai->next();
        if ($inv_count_schedule_object_ai->key() == $position + $per_page) {
         break;
        }
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

<div class="row small-top-margin" >
 <div id="pagination" style="clear: both;">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="inv_count_entries" ></li>
  <li class="line_key_field" data-line_key_field="item_id_m" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="inv_count_entries" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="inv_count_entries_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="inv_count_entries" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
