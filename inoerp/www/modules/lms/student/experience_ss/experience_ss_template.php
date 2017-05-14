<div id="form_all">
 <div id="form_headerDiv">
  <form  method="post" id="hr_employee_experience_line"  name="employee_experience_line">
   <span class="heading"><?php echo gettext('Employee Experience') ?></span>
   <div id="tabsLine">
    <div id="form_serach_header" class="tabContainer">
     <?php $f->l_select_field_from_object('employee_id', $hr_emp_list, 'hr_employee_id', array('first_name', 'last_name'), $employee_id_h, 'employee_id', $readonly1); ?>
     <a name="show" href="form.php?class_name=hr_employee_experience&<?php echo "mode=$mode"; ?>" class="show document_id employee_id">
      <i class="fa fa-refresh"></i></a> 
    </div>
    <div id ="form_line" class="hr_employee_experience">
     <ul class="tabMain">
      <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
      <li><a href="#tabsLine-2"><?php echo gettext('Details Info') ?></a></li>
     </ul>
     <div class="tabContainer"> 
      <div id="tabsLine-1" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Line Id') ?></th>
          <th><?php echo gettext('Organization Name') ?>#</th>
          <th><?php echo gettext('Designation') ?></th>
          <th><?php echo gettext('Start Date') ?></th>
          <th><?php echo gettext('End Date') ?></th>
          <th><?php echo gettext('Employee') ?>#</th>
          <th><?php echo gettext('Department') ?></th>
          <th><?php echo gettext('Last Manager') ?>#</th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody employee_experience_values" >
         <?php
         $count = 0;
         $employee_experience_object_ai = new ArrayIterator($employee_experience_object);
         $employee_experience_object_ai->seek($position);
         while ($employee_experience_object_ai->valid()) {
          $hr_employee_experience = $employee_experience_object_ai->current();
          ?>         
          <tr class="hr_employee_experience<?php echo $count ?>">
           <td><?php
            echo ino_inline_action($$class->hr_employee_experience_id, array('employee_id' => $employee_id_h));
            ?>
           </td>
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php $f->text_field_widsr('hr_employee_experience_id','always_readonly') ?></td>
           <td><?php $f->text_field_widm('organization_name'); ?></td>
           <td><?php $f->text_field_widm('designation'); ?></td>
           <td><?php echo $f->date_fieldAnyDay('work_start_date', $$class->work_start_date); ?></td>
           <td><?php echo $f->date_fieldAnyDay('work_end_date', $$class->work_end_date); ?></td>
           <td><?php $f->text_field_wid('employee_number'); ?></td>
           <td><?php $f->text_field_wids('department'); ?></td>
           <td><?php $f->text_field_wids('last_manager'); ?></td>
          </tr>
          <?php
          $employee_experience_object_ai->next();
          if ($employee_experience_object_ai->key() == $position + $per_page) {
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
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Last Salary') ?></th>
          <th><?php echo gettext('Communication Details') ?></th>
          <th><?php echo gettext('Projects') ?>#</th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody employee_experience_values" >
         <?php
         $count = 0;
         $employee_experience_object_ai = new ArrayIterator($employee_experience_object);
         $employee_experience_object_ai->seek($position);
         while ($employee_experience_object_ai->valid()) {
          $hr_employee_experience = $employee_experience_object_ai->current();
          ?>         
          <tr class="hr_employee_experience<?php echo $count ?>">
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php $f->text_field_wid('last_drawn_salary'); ?></td>
           <td><?php echo $f->text_area_ap(array('name' => 'communication_details', 'value' => $$class->communication_details, 'row_size' => '1', 'column_size' => '40')); ?> 	
           </td>
           <td><?php echo $f->text_area_ap(array('name' => 'project_details', 'value' => $$class->project_details, 'row_size' => '1', 'column_size' => '40')); ?> 	
           </td> 
          </tr>
          <?php
          $employee_experience_object_ai->next();
          if ($employee_experience_object_ai->key() == $position + $per_page) {
           break;
          }
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
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="primary_column_id" data-primary_column_id="employee_id" ></li>
  <li class="lineClassName" data-lineClassName="hr_employee_experience" ></li>
  <li class="line_key_field" data-line_key_field="organization_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="hr_employee_experience" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="hr_employee_experience_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="hr_employee_experience" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>