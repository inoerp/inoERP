<div id ="form_header">
 <form action=""  method="post" id="hr_employee"  name="hr_employee">
  <span class="heading"><?php echo gettext('Employee Header') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Personal') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Contact') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-5"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('hr_employee_id') ?>
        <a name="show" href="form.php?class_name=hr_employee&<?php echo "mode=$mode"; ?>" class="show document_id hr_employee_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('first_name'); ?> 					</li>
       <li><?php $f->l_text_field_d('last_name'); ?> 					</li>
       <li><?php $f->l_text_field_d('title'); ?> 					</li>
       <li><?php $f->l_select_field_from_object('gender', hr_employee::gender(), 'option_line_code', 'option_line_value', $$class->gender, '', 'gender', '', $readonly); ?>              </li>
       <li><?php $f->l_select_field_from_object('person_type', hr_employee::person_type(), 'option_line_code', 'option_line_value', $$class->person_type, '', 'person_type', '', $readonly); ?>              </li>
       <li><?php $f->l_select_field_from_object('identification_type', hr_employee::identification_type(), 'option_line_code', 'option_line_value', $$class->identification_type, '', 'identification_type', '', $readonly); ?>              </li>
       <li><?php $f->l_text_field_d('identification_id'); ?> 					</li>
       <li><?php $f->l_text_field_d('citizen_number'); ?> 					</li>
       <li><?php $f->l_select_field_from_object('org_id', org::find_all_enterprise(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>             </li>
       <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', $readonly, '', '', 1); ?>        </li>
       <li><?php $f->l_status_field_d('status'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_date_fieldFromToday('date_of_birth', $$class->date_of_birth); ?> </li>
       <li><?php $f->l_select_field_from_object('country_of_birth', mdm_tax_region::country(), 'option_line_code', 'option_line_value', $$class->country_of_birth, '', 'country_code', '', $readonly); ?>              </li>
       <li><?php $f->l_text_field_d('city_of_birth'); ?> 					</li>
       <li><?php $f->l_text_field_d('nationality'); ?> 					</li>
       <li><?php $f->l_text_field_d('disability_code'); ?> 					</li>
       <li><?php $f->l_select_field_from_object('marital_status', hr_employee::marital_status(), 'option_line_code', 'option_line_value', $$class->marital_status, '', 'marital_status', '', $readonly); ?>              </li>
       <li><?php $f->l_text_field_d('no_of_children'); ?> 					</li>
       <li><?php $f->l_text_field_d('passport_number'); ?> 					</li>
      </ul>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_d('home_phone_number'); ?> 					</li>
       <li><?php $f->l_text_field_d('phone'); ?> 					</li>
       <li><?php $f->l_text_field_d('mobile_number'); ?> 					</li>
       <li><?php $f->l_text_field_d('email'); ?> 					</li>
       <li><?php $f->l_text_field_d('other_email'); ?> 					</li>
       <li><?php $f->l_text_field_d('home_address'); ?> 					</li>
       <li><?php $f->l_text_field_d('permanent_address'); ?> 					</li>
       <li><?php $f->l_text_field_d('location_id'); ?> 					</li>
      </ul>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-5" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'hr_employee';
         $reference_id = $$class->hr_employee_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
    </div>
   </div>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Employee Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Assignments') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Financial Info') ?> </a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Education') ?> </a></li>
     <li><a href="#tabsLine-4"><?php echo gettext('Work Experience') ?> </a></li>
     <li><a href="#tabsLine-5"><?php echo gettext('On Boarding') ?></a></li>
     <li><a href="#tabsLine-6"><?php echo gettext('Exit') ?> </a></li>
     <li><a href="#tabsLine-7"><?php echo gettext('Job History') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_object('job_id', hr_job::find_all(), 'hr_job_id', 'job_name', $$class->job_id, 'job_id'); ?> 	</li>
        <li><?php $f->l_select_field_from_object('position_id', hr_position::find_all(), 'hr_position_id', 'position_name', $$class->position_id, 'position_id'); ?>  </li>
        <li><?php $f->l_select_field_from_object('grade_id', hr_grade::find_all(), 'hr_grade_id', 'grade', $$class->grade_id, 'grade_id'); ?></li>
        <li><?php $f->l_select_field_from_object('payroll_id', hr_payroll::find_all(), 'hr_payroll_id', 'payroll', $$class->payroll_id, 'payroll_id'); ?>  </li>
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="supervisor_employee_id select_popup clickable">
          <?php echo gettext('Supervisor') ?></label><?php
         $f->text_field_d('supervisor_employee_name');
         echo $f->hidden_field_withId('supervisor_employee_id', $$class->supervisor_employee_id);
         ?> 					</li>
       </ul> 
      </div> 
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_d('tax_reg_number'); ?> 					</li>
        <li><?php $f->l_text_field_d('social_ac_no'); ?> 					</li>
        <li><?php $f->l_text_field_d('social_ac_no2'); ?> 					</li>
        <li><?php $f->l_text_field_d('bank_account_id'); ?> 					</li>
        <li><?php $f->l_ac_field_d('expense_ac_id'); ?> 					</li>
        <li><?php $f->l_ac_field_d('salary_ac_id'); ?> 					</li>
       </ul> 
      </div> 
     </div>
     <div id="tabsLine-3"  class="tabContent">
      <div class="tabsDetail">
       <ul class="tabMain">
        <li><a href="#tabsLine-11"><?php echo gettext('Basic Info') ?></a></li>
        <li><a href="#tabsLine-12"><?php echo gettext('Details Info') ?></a></li>
       </ul>
       <div class="tabContainer"> 
        <div id="tabsLine-11" class="tabContent">
         <table class="form_table">
          <thead> 
           <tr>
            <th><?php echo gettext('Action') ?></th>
            <th><?php echo gettext('Seq') ?>#</th>
            <th><?php echo gettext('Line Id') ?></th>
            <th><?php echo gettext('Degree Name') ?>#</th>
            <th><?php echo gettext('University') ?></th>
            <th><?php echo gettext('Start Date') ?></th>
            <th><?php echo gettext('End Date') ?></th>
            <th><?php echo gettext('Mode') ?></th>
            <th><?php echo gettext('Percentage') ?></th>
            <th><?php echo gettext('Grade') ?></th>
           </tr>
          </thead>
          <tbody class="form_data_line_tbody employee_education_values" >
           <?php
           $count = 0;
           $employee_education_object1 = hr_employee_education::find_by_employeeId($$class->hr_employee_id);
           $employee_education_object = empty($employee_education_object1) ? array(new hr_employee_education()) : $employee_education_object1;
           foreach ($employee_education_object as $hr_employee_education) {
            ?>         
            <tr class="employee_education_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img1 clickable"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i> </li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->hr_employee_education_id); ?>"></li> 
               <li><?php echo $f->hidden_field('education_line_id_cb', ''); ?>
                <?php echo form::hidden_field('employee_id', $$class->hr_employee_id); ?></li>
              </ul>
             </td>
             <td><?php $f->seq_field_d($count) ?></td>
             <td><?php $f->text_field_wid2sr('hr_employee_education_id') ?></td>
             <td><?php $f->text_field_wid2m('degree_name'); ?></td>
             <td><?php $f->text_field_wid2m('university'); ?></td>
             <td><?php echo $f->date_fieldAnyDay('edu_start_date', $$class_second->edu_start_date); ?></td>
             <td><?php echo $f->date_fieldAnyDay('edu_end_date', $$class_second->edu_end_date); ?></td>
             <td><?php $f->text_field_wid2('mode_of_education'); ?></td>
             <td><?php $f->text_field_wid2s('marks_percentage'); ?></td>
             <td><?php $f->text_field_wid2s('grade'); ?></td>

            </tr>
            <?php
            $count = $count + 1;
           }
           ?>
          </tbody>
         </table>
        </div>
        <div id="tabsLine-12" class="tabContent">
         <table class="form_table">
          <thead> 
           <tr>
            <th><?php echo gettext('Seq') ?>#</th>
            <th><?php echo gettext('Specialization') ?></th>
            <th><?php echo gettext('University Address') ?>#</th>
            <th><?php echo gettext('Notes') ?></th>
           </tr>
          </thead>
          <tbody class="form_data_line_tbody employee_education_values" >
           <?php
           $count = 0;
           foreach ($employee_education_object as $employee_education) {
            ?>         
            <tr class="employee_education_line<?php echo $count ?>">
             <td><?php $f->seq_field_d($count) ?></td>
             <td><?php $f->text_field_wid2('specialization'); ?></td>
             <td><?php $f->text_field_wid2l('university_address'); ?></td>
             <td><?php
              echo $f->text_area_ap(array('name' => 'comments', 'value' => $$class_second->comments,
               'row_size' => '1', 'column_size' => '60'));
              ?> 	
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
     <div id="tabsLine-4"  class="tabContent">
      <div class="tabsDetail">
       <ul class="tabMain">
        <li><a href="#tabsLine-21"><?php echo gettext('Basic') ?></a></li>
        <li><a href="#tabsLine-22"><?php echo gettext('Details') ?></a></li>
       </ul>
       <div class="tabContainer"> 
        <div id="tabsLine-21" class="tabContent">
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
          <tbody class="form_data_line_tbody2 employee_experience_values" >
           <?php
           $count = 0;
           $employee_experience_object1 = hr_employee_experience::find_by_employeeId($$class->hr_employee_id);
           $employee_experience_object = empty($employee_experience_object1) ? array(new hr_employee_experience()) : $employee_experience_object1;
           foreach ($employee_experience_object as $hr_employee_experience) {
            ?>         
            <tr class="employee_experience_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img1 clickable"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_third->hr_employee_experience_id); ?>"></li> 
               <li><?php echo $f->hidden_field('experience_line_id_cb', ''); ?>
                <?php echo form::hidden_field('employee_id', $$class->hr_employee_id); ?></li>

              </ul>
             </td>
             <td><?php $f->seq_field_d($count) ?></td>
             <td><?php $f->text_field_wid3sr('hr_employee_experience_id') ?></td>
             <td><?php $f->text_field_wid3('organization_name'); ?></td>
             <td><?php $f->text_field_wid3('designation'); ?></td>
             <td><?php echo $f->date_fieldAnyDay('work_start_date', $$class_third->work_start_date); ?></td>
             <td><?php echo $f->date_fieldAnyDay('work_end_date', $$class_third->work_end_date); ?></td>
             <td><?php $f->text_field_wid3('employee_number'); ?></td>
             <td><?php $f->text_field_wid3s('department'); ?></td>
             <td><?php $f->text_field_wid3('last_manager'); ?></td>
            </tr>
            <?php
            $count = $count + 1;
           }
           ?>
          </tbody>
         </table>
        </div>
        <div id="tabsLine-22" class="tabContent">
         <table class="form_table">
          <thead> 
           <tr>
            <th><?php echo gettext('Seq') ?>#</th>
            <th><?php echo gettext('Last Salary') ?></th>
            <th><?php echo gettext('Communication Details') ?></th>
            <th><?php echo gettext('Projects') ?>#</th>
           </tr>
          </thead>
          <tbody class="form_data_line_tbody2 employee_experience_values" >
           <?php
           $count = 0;
           foreach ($employee_experience_object as $employee_experience) {
            ?>         
            <tr class="employee_experience_line<?php echo $count ?>">
             <td><?php $f->seq_field_d($count) ?></td>
             <td><?php $f->text_field_wid3('last_drawn_salary'); ?></td>
             <td><?php echo $f->text_area_ap(array('name' => 'communication_details', 'value' => $$class_third->communication_details, 'row_size' => '1', 'column_size' => '40')); ?> 	
             </td>
             <td><?php echo $f->text_area_ap(array('name' => 'project_details', 'value' => $$class_third->project_details, 'row_size' => '1', 'column_size' => '40')); ?> 	
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
     <div id="tabsLine-5"  class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_d('probation_period_uom'); ?> 					</li>
        <li><?php $f->l_text_field_d('probation_period'); ?> 					</li>
        <li><?php $f->l_text_field_d('notice_period_uom'); ?> 					</li>
        <li><?php $f->l_text_field_d('notice_period'); ?> 					</li>
        <li><?php $f->l_ac_field_d('vehicle_number'); ?> 					</li>
        <li><?php $f->l_ac_field_d('asset_numbers'); ?> 					</li>
       </ul> 
      </div> 
     </div>
     <div id="tabsLine-6"  class="tabContent">
      <div> 
       <ul class="column four_column"> 
        <li><?php $f->l_date_fieldAnyDay('date_of_notification', $$class_fourth->date_of_notification); ?></li>
        <li><?php $f->l_text_field('reason', $$class_fourth->projected_last_date); ?></li>
        <li><?php $f->l_date_fieldAnyDay('projected_last_date', $$class_fourth->projected_last_date); ?></li>
        <li><?php $f->l_date_fieldAnyDay('accpeted_date', $$class_fourth->accpeted_date); ?></li>
        <li><?php $f->l_date_fieldAnyDay('actual_last_date', $$class_fourth->actual_last_date); ?></li>
        <li><?php $f->l_date_fieldAnyDay('accpeted_by_employee_id', $$class_fourth->accpeted_by_employee_id); ?></li>
       </ul> 
      </div> 
     </div>
    </div>
   </div> 
  </div> 
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_employee" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_employee_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_employee" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_employee_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_employee_id" ></li>
 </ul>
</div>