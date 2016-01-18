<div id ="form_header">
 <form action=""  method="post" id="hr_element_entry_header"  name="hr_element_entry_header">
  <span class="heading"><?php echo gettext('Employee Salary') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><label><?php echo gettext('Employee Name') ?></label><?php $f->text_field_d('employee_name'); ?>
        <?php echo $f->hidden_field_withId('hr_employee_id', $$class->hr_employee_id); ?>
        <a name="show" href="form.php?class_name=hr_employee_salary" class="show hr_employee_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_employee_id select_popup clickable">
         <?php echo gettext('Identification') ?></label><?php $f->text_field_d('identification_id'); ?>
       </li>
      </ul>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Salary Component Break Up') ?></span>
 <form action=""  method="post" id="hr_element_entry_line"  name="hr_element_entry_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Main</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th>Component Name</th>
        <th>Component Value</th>
        <th>Monetary Value</th>
        <th>Inactive Date</th>
        <th>Description</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hr_element_entry_line_object as $hr_element_entry_line) {
        ?>         
        <tr class="hr_element_entry_line<?php echo $count ?>">
         <td><?php echo $f->select_field_from_object('element_id', hr_compensation_element::find_all(), 'hr_compensation_element_id', 'element_name', $$class_second->element_id, '', '', 1, 1); ?></td>
         <td><?php $f->text_field_wid2r('element_value'); ?></td>
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
  <li class="btn1DivId" data-btn1DivId="hr_element_entry_header_id" ></li>
 </ul>
</div>