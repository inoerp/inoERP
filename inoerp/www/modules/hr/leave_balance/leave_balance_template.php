<div class='row small-left-padding'>
 <div id="form_all">
  <div id="form_headerDiv">
   <span class="heading"><?php echo gettext('Leave Details') ?></span>
   <form method="post" id="hr_leave_balance_line"  name="hr_leave_balance_line">
    <div class='tabContainer' id="form_header">
     <ul class="inline_list">
			<li><label><?php echo gettext('Employee Name') ?></label><?php
					echo $f->val_field('employee_name', $$class->employee_name, '', '', 'vf_select_member_employee_name employee_name', '', '', 'hr_employee_v', 'employee_name');
					echo $f->hidden_field_withCLass('hr_employee_id', $$class->hr_employee_id, 'employee_id');
					?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i>
			 <a name="show" href="form.php?class_name=hr_leave_balance&<?php echo "mode=$mode"; ?>" class="show document_id employee_id">
        <i class="fa fa-refresh"></i></a></li>
     </ul>
    </div>
    <div id ="form_line" class="hr_leave_balance">
     <span class="heading"><?php echo gettext('Current Balance') ?> </span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Details') ?></a></li>
      </ul>
      <div class="tabContainer"> 

       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Id') ?></th>
           <th><?php echo gettext('Type') ?>#</th>
           <th><?php echo gettext('Leave/Year') ?></th>
           <th><?php echo gettext('Available Balance') ?></th>
           <th><?php echo gettext('Total Used') ?></th>
           <th><?php echo gettext('Total Leave') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody leave_balance_values" >
						 <?php
						 $count = 0;
						 foreach ($leave_balance_object as $hr_leave_balance) {
							$leave_used = hr_leave_transaction::usage_sum_by_employeeId_leaveType($$class->leave_type);
							$total_leave_used = !empty($leave_used) ? $leave_used : null;
							?>         
 					<tr class="hr_leave_balance<?php echo $count ?>">
 					 <td>
								<?php
								echo ino_inline_action($$class->hr_leave_balance_id, array('employee_id' => $employee_id_h));
								?>
 					 </td>
 					 <td><?php $f->text_field_widsr('hr_leave_balance_id', 'always_readonly') ?></td>
 					 <td><?php echo $f->select_field_from_object('leave_type', hr_leave_type::find_all(), 'hr_leave_type_id', 'leave_type', $$class->leave_type, '', 'leave_type', 1, $readonly1); ?></td>
 					 <td><?php echo $f->number_field('leave_per_year', $$class->leave_per_year); ?></td>
 					 <td><?php echo $f->number_field('total_available', $$class->total_available); ?></td>
 					 <td><?php echo $f->number_field('total_used', $total_leave_used, '', '', 'always_readonly', '', 1); ?></td>
 					 <td><?php echo $f->number_field('total_available', $$class->total_available + $$class->total_used, '', '', 'always_readonly', '', 1); ?></td>
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
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_leave_balance" ></li>
  <li class="primary_column_id" data-primary_column_id="employee_id" ></li>
  <li class="lineClassName" data-lineClassName="hr_leave_balance" ></li>
  <li class="line_key_field" data-line_key_field="employee_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="hr_leave_balance" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="hr_leave_balance_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="hr_leave_balance" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>