<div class="row small-left-padding">
 <div id ="form_header">
  <form  method="post" id="inv_count_header"  name="inv_count_header">
   <span class="heading"><?php echo gettext('Count Header') ?></span>
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Variance Limit/Approval') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Count Frequence') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('inv_count_header_id') ?>
        <a name="show" href="form.php?class_name=inv_count_header&<?php echo "mode=$mode"; ?>" class="show document_id inv_count_header_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('count_name'); ?></li>
       <li><?php $f->l_select_field_from_array('count_type', inv_count_header::$count_type_a, $$class->count_type, 'count_type', '', 1, $readonly1); ?>       </li>
       <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>       </li>
       <li><?php 
        echo $f->l_val_field_dm('abc_assignment_name', 'inv_abc_assignment_header', 'abc_assignment_name', 'org_id');
        echo $f->hidden_field_withId('inv_abc_assignment_header_id', $$class->inv_abc_assignment_header_id);
        echo $f->hidden_field_withCLass('org_id', $$class->org_id, 'popup_value');
        ?><i class="generic g_select_abc_assignment_name select_popup clickable fa fa-search" data-class_name="inv_abc_assignment_header"></i></li>
       <li><?php $f->l_ac_field_dm('adjustment_ac_id'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <ul class="column header_field">
       <li><label><?php echo gettext('Quantity') ?>(+)</label> <?php $f->text_field_d('quantity_variance_positive'); ?> </li>
       <li><label><?php echo gettext('Quantity') ?>(-)</label><?php $f->text_field_d('quantity_variance_negative'); ?> </li>
       <li><label><?php echo gettext('Value') ?>(+)</label><?php $f->text_field_d('value_variance_positive'); ?> </li>
       <li><label><?php echo gettext('Value') ?>(-)</label><?php $f->text_field_d('value_variance_negative'); ?> </li>
       <li><?php $f->l_select_field_from_array('approval_required', inv_count_header::$approval_required_a, $$class->approval_required, 'approval_required'); ?> </li>
      </ul>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div id="data_table">
       <ul class="column three_column">
        <li><label><?php echo gettext('Action') ?> 
          <?php echo $f->select_field_from_array('count_action', inv_count_header::$count_action_a, ''); ?> </label></li>
       </ul>
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('ABC Class') ?></th>
          <th><?php echo gettext('Count Per Year') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody inv_count_class_ref_values" >
         <?php
         $count = 0;
         $all_abc_codes = inv_abc_assignment_header::inv_abc_codes();
         $no_of_class_codes = count($all_abc_codes);
         foreach ($all_abc_codes as $abc_code) {
          ?>   
          <tr class="inv_abc_assignment_header<?php echo $count ?>">
           <td><?php echo $f->text_field('assign_abc_class_value', $abc_code->option_line_code, '8', '', '', '', 1); ?></td>
           <td><?php
            $count_per_year = inv_count_abc_ref::find_by_parentId_abcCode($$class->inv_count_header_id, $abc_code->option_line_code);
            $count_per_year_v = ($count_per_year) ? $count_per_year->count_per_year : null;
            echo $f->number_field('count_per_year', $count_per_year_v);
            ?></td>
          </tr>
          <?php
          $count++;
         }
         ?>
        </tbody>
       </table>
      </div>
     </div>
    </div>
   </div>
  </form>
 </div>

 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Count Schedules') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Schedule') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <form action=""  method="post" id="inv_count_schedule_line"  name="inv_count_schedule_line">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Count Id') ?></th>
         <th><?php echo gettext('Master Item Id') ?></th>
         <th><?php echo gettext('Item Number') ?></th>
         <th><?php echo gettext('Item Description') ?></th>
         <th><?php echo gettext('Schedule Date') ?></th>
         <th><?php echo gettext('StatusStatus') ?></th>
         <th><?php echo gettext('Code On Count') ?></th>
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
         <tr class="inv_count_schedule<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_second->inv_count_schedule_id, array('inv_count_header_id' => $$class->inv_count_header_id));
           ?>
          </td>
          <td><?php form::number_field_wid2sr('inv_count_schedule_id' , 'always_readonly'); ?></td>
          <td><?php $f->text_field_d2sr('item_id_m'); ?></td>
          <td><?php $f->text_field_wid2('item_number', 'select_item_number'); ?><i class="select_item_number select_popup clickable fa fa-search"></i></td>
          <td><?php $f->text_field_wid2('item_description'); ?></td>
          <td><?php echo $f->date_fieldAnyDay('schedule_date', $$class_second->schedule_date); ?></td>
          <td><?php echo $f->select_field_from_array('status', inv_count_schedule::$status_a, $$class_second->status, '', '', '', '', 1); ?></td>
          <td><?php $f->text_field_wid2s('abc_code'); ?></td>
          <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->subinventory_id, '', 'subinventory_id medium', '', $readonly); ?></td>
          <td><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_second->subinventory_id), 'locator_id', 'locator', $$class_second->locator_id, '', 'locator_id medium', '', $readonly); ?></td>
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
</div>

<div class="row small-top-margin" >
 <div id="pagination" style="clear: both;">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="inv_count_header" ></li>
  <li class="lineClassName" data-lineClassName="inv_count_schedule" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="inv_count_header_id" ></li>
  <li class="form_header_id" data-form_header_id="inv_count_header" ></li>
  <li class="line_key_field" data-line_key_field="code" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="inv_count_schedule" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="inv_count_header_id" ></li>
  <li class="docLineId" data-docLineId="inv_count_schedule_id" ></li>
  <li class="btn1DivId" data-btn1DivId="inv_count_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>