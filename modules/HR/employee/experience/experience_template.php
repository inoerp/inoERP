<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="coa_structure_id">
     <div id="employee_experience_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
       echo (!empty($show_message)) ? $show_message : "";
       $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->
      <div id="form_all">
       <div id="form_headerDiv">
        <form action=""  method="post" id="hr_employee_experience_line"  name="employee_experience_line"><span class="heading">Employee experience </span>
         <div id="tabsLine">
          <table class="form_table">
           <tr><td>
             <label>Employee Name :</label>
             <?php echo $f->select_field_from_object('employee_id', hr_employee::find_all(), 'hr_employee_id', array('first_name', 'last_name'), $employee_id_h, 'employee_id', $readonly1); ?>
             <a name="show" class="show hr_employee_experience clickable">
              <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
            </td></tr>
          </table>
          <div id ="form_line" class="hr_employee_experience">
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
                <th>Organization Name</th>
                <th>Designation</th>
                <th>Start Date </th>
                <th>End Date</th>
                <th>Employee#</th>
                <th>Department</th>
                <th>Last Manager</th>
               </tr>
              </thead>
              <tbody class="form_data_line_tbody employee_experience_values" >
               <?php
                $count = 0;
                foreach ($employee_experience_object as $hr_employee_experience) {
                 ?>         
                 <tr class="employee_experience_line<?php echo $count ?>">
                  <td>    
                   <ul class="inline_action">
                    <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                    <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                    <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->hr_employee_experience_id); ?>"></li> 
                    <li><?php echo form::hidden_field('employee_id', $employee_id_h); ?></li>

                   </ul>
                  </td>
                  <td><?php $f->seq_field_d($count) ?></td>
                  <td><?php $f->text_field_widsr('hr_employee_experience_id') ?></td>
                  <td><?php $f->text_field_widm('organization_name'); ?></td>
                  <td><?php $f->text_field_widm('designation'); ?></td>
                  <td><?php echo $f->date_fieldAnyDay('work_start_date', $$class->work_start_date); ?></td>
                  <td><?php echo $f->date_fieldAnyDay('work_end_date', $$class->work_end_date); ?></td>
                  <td><?php $f->text_field_wid('employee_number'); ?></td>
                  <td><?php $f->text_field_wids('department'); ?></td>
                  <td><?php $f->text_field_wids('last_manager'); ?></td>
                 </tr>
                 <?php
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
                <th>Last Salary</th>
                <th>Communication Details</th>
                <th>Projects</th>
               </tr>
              </thead>
              <tbody class="form_data_line_tbody employee_experience_values" >
               <?php
                $count = 0;
                foreach ($employee_experience_object as $employee_experience) {
                 ?>         
                 <tr class="employee_experience_line<?php echo $count ?>">
                  <td><?php $f->seq_field_d($count) ?></td>
                  <td><?php $f->text_field_wid('last_drawn_salary'); ?></td>
                  <td><?php
                   echo $f->text_area_ap(array('name' => 'communication_details', 'value' => $$class->communication_details, 'row_size' => '1', 'column_size' => '40'));                   ?> 	
                  </td>
                                    <td><?php
                   echo $f->text_area_ap(array('name' => 'project_details', 'value' => $$class->project_details, 'row_size' => '1', 'column_size' => '40'));                   ?> 	
                  </td> 
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
         </div> 
        </form>
       </div>
      </div>

      <div id="pagination" style="clear: both;">
       <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
       ?>
      </div>
      <!--END OF FORM -->
     </div>
    </div>
    <!--   end of coa_structure_id-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>