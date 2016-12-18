<!--    End of place for showing error messages-->
<div id ="form_header">
 <form  method="post" id="hr_element_entry_header"  name="hr_element_entry_header">
  <span class="heading"><?php echo gettext('Compensation Element Entry') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('hr_element_entry_header_id') ?>
        <a name="show" href="form.php?class_name=hr_element_entry_header&<?php echo "mode=$mode"; ?>" class="show document_id hr_element_entry_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php 
//       $reado_c = !empty($$class->hr_element_entry_header_id) ? ' always_readonly ' : ' ' ;
//       $div_Class = 'vf_select_employee_name employee_name '. $reado_c;
        echo $f->l_val_field_d('employee_name', 'hr_employee_v', 'employee_name', '','vf_select_employee_name employee_name ' );
        echo $f->hidden_field_withCLass('hr_employee_id', $$class->hr_employee_id, 'hr_employee_id claim_emplyee_id');
        ?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
       <li><?php $f->l_text_field_dr('identification_id'); ?> </li>
       <li><?php $f->l_checkBox_field_d('archive_data_cb'); ?> </li>
      </ul>
     </div>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Element Entry Lines') ?></span>
 <form method="post" id="hr_element_entry_line"  name="hr_element_entry_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Element Name') ?>#</th>
        <th><?php echo gettext('Element Value') ?></th>
        <th><?php echo gettext('Monetary Value') ?></th>
        <th><?php echo gettext('Inactive Date') ?></th>
        <th><?php echo gettext('Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hr_element_entry_line_object as $hr_element_entry_line) {
        ?>         
        <tr class="hr_element_entry_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->hr_element_entry_line_id, array('hr_element_entry_header_id' => $$class->hr_element_entry_header_id));
          ?>
         </td>
         <td><?php $f->text_field_wid2sr('hr_element_entry_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('element_id', hr_compensation_element::find_all(), 'hr_compensation_element_id', array('element_name', 'calculation_rule'), $$class_second->element_id, '', '', 1, $readonly); ?></td>
         <td><?php $f->text_field_wid2m('element_value'); ?></td>
         <td><?php
          $mon_val = hr_element_entry_line::find_monetary_value_by_id($$class_second->hr_element_entry_line_id);
          echo $f->text_field('monetary_value', $mon_val, '', '', '', '', 1);
          ?></td>
         <td><?php echo $f->date_fieldFromToday('end_date', $$class_second->end_date); ?></td>
         <td><?php $f->text_field_wid2l('description'); ?></td>

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
  <li class="headerClassName" data-headerClassName="hr_element_entry_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_element_entry_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_element_entry_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_element_entry_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_element_entry_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_element_entry_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_element_entry_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>
