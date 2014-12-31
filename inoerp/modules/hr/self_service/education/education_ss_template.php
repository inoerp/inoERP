<div id="form_all">
 <div id="form_headerDiv">
  <form action=""  method="post" id="hr_employee_education_line"  name="employee_education_line"><span class="heading">Employee Education </span>
   <div id="tabsLine">
    <div id="form_serach_header">
     <label>Employee Name :</label>
     <?php echo $f->select_field_from_object('employee_id',$hr_emp_list, 'hr_employee_id', array('first_name', 'last_name'), $employee_id_h, 'employee_id', $readonly1); ?>
     <a name="show" href="form.php?class_name=hr_employee_education_ss&<?php echo "mode=$mode"; ?>" class="show document_id employee_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
    </div>
    <div id ="form_line" class="hr_employee_education">
      <ul class="tabMain">
       <li><a href="#tabsLine-1">Basic </a></li>
       <li><a href="#tabsLine-2">Details </a></li>
      </ul>
      <div class="tabContainer"> 
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th>Action</th>
           <th>Seq#</th>
           <th>Line Id</th>
           <th>Degree Name</th>
           <th>University</th>
           <th>Start Date </th>
           <th>End Date</th>
           <th>Mode</th>
           <th>Percentage</th>
           <th>Grade</th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody employee_education_values" >
          <?php
          $count = 0;
          $employee_education_object_ai = new ArrayIterator($employee_education_object);
          $employee_education_object_ai->seek($position);
          while ($employee_education_object_ai->valid()) {
           $hr_employee_education_ss = $employee_education_object_ai->current();
           ?>         
           <tr class="hr_employee_education<?php echo $count ?>">
            <td>    
             <ul class="inline_action">
              <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
              <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
              <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->hr_employee_education_id); ?>"></li> 
              <li><?php echo form::hidden_field('employee_id', $employee_id_h); ?></li>

             </ul>
            </td>
            <td><?php $f->seq_field_d($count) ?></td>
            <td><?php $f->text_field_widsr('hr_employee_education_id') ?></td>
            <td><?php $f->text_field_widm('degree_name'); ?></td>
            <td><?php $f->text_field_widm('university'); ?></td>
            <td><?php echo $f->date_fieldAnyDay('edu_start_date', $$class->edu_start_date); ?></td>
            <td><?php echo $f->date_fieldAnyDay('edu_end_date', $$class->edu_end_date); ?></td>
            <td><?php $f->text_field_wid('mode_of_education'); ?></td>
            <td><?php $f->text_field_wids('marks_percentage'); ?></td>
            <td><?php $f->text_field_wids('grade'); ?></td>
           </tr>
           <?php
           $employee_education_object_ai->next();
           if ($employee_education_object_ai->key() == $position + $per_page) {
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
           <th>Seq#</th>
           <th>Specialization</th>
           <th>University Address</th>
           <th>Notes</th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody employee_education_values" >
          <?php
          $count = 0;
          $employee_education_object_ai = new ArrayIterator($employee_education_object);
          $employee_education_object_ai->seek($position);
          while ($employee_education_object_ai->valid()) {
           $hr_employee_education_ss = $employee_education_object_ai->current();
           ?>         
           <tr class="hr_employee_education<?php echo $count ?>">
            <td><?php $f->seq_field_d($count) ?></td>
            <td><?php $f->text_field_wid('specialization'); ?></td>
            <td><?php $f->text_field_widl('university_address'); ?></td>
            <td><?php
             echo $f->text_area_ap(array('name' => 'comments', 'value' => $$class->comments,
              'row_size' => '1', 'column_size' => '60'));
             ?> 	
            </td> 
           </tr>
           <?php
           $employee_education_object_ai->next();
           if ($employee_education_object_ai->key() == $position + $per_page) {
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
  <li class="lineClassName" data-lineClassName="hr_employee_education" ></li>
  <li class="line_key_field" data-line_key_field="degree_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="hr_employee_education" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="hr_employee_education_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="hr_employee_education" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>