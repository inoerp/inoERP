<div id="form_all">
 <div id="form_headerDiv">
  <form method="post" id="hr_leave_balance_line"  name="leave_balance_line">
   <span class="heading"><?php echo gettext('Leave Details') ?></span>
   <table class="form_table">
    <tr> 
     <td><?php $f->l_text_field_d('employee_name'); ?> </td>
     <td><?php $f->l_text_field_d('identification_id'); ?> </td>
    </tr>
   </table>
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
          <th><?php echo gettext('Seq') ?></th>
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
         foreach ($leave_balance_object as $hr_leave_balance_user) {
          $leave_used = hr_leave_transaction::usage_sum_by_employeeId_leaveType($$class->leave_type);
          $total_leave_used = !empty($leave_used) ? $leave_used : null;
          ?>         
          <tr class="leave_balance_line<?php echo $count ?>">
           <td><?php echo $count ?></td>
           <td><?php echo $f->select_field_from_object('leave_type', hr_leave_type::find_all(), 'hr_leave_type_id', 'leave_type', $$class->leave_type, '', 'leave_type', '', 1); ?></td>
           <td><?php echo $$class->leave_per_year; ?></td>
           <td><?php echo ($$class->total_available); ?></td>
           <td><?php echo $total_leave_used; ?></td>
           <td><?php echo $$class->total_available + $$class->total_used; ?></td>
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