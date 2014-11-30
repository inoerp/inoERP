<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="coa_structure_id">
     <div id="payslip_line_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
      echo (!empty($show_message)) ? $show_message : "";
      $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->
      <div id="form_all">
       <div id="form_headerDiv">
        <form action=""  method="post" id="hr_payslip_header"  name="hr_payslip_header"><span class="heading">Employee Pay Slip  </span>
         <table class="document_table">
          <tr> 
           <td><label> <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_payslip_header_id select_popup clickable">
             Pay Slip Id # : </label><?php $f->text_field_dr('hr_payslip_header_id'); ?> 
            <a name="show" href="form.php?class_name=hr_payslip_header" class="show hr_payslip_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
           </td>
           <td><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_employee_id select_popup clickable">
             Employee Name : </label><?php $f->text_field_d('employee_name'); ?>
            <?php echo $f->hidden_field_withId('employee_id', $$class->employee_id); ?>

            <?php echo $f->hidden_field('hr_payroll_process_id', $$class->hr_payroll_process_id); ?>
           </td>
          </tr>
          <tr>
           <td><label> Period Name  : </label>
            <?php echo $f->select_field_from_object('period_name_id', hr_payroll_schedule::find_by_parent_id($payroll_id, 'scheduled_date', 'ASC'), 'hr_payroll_schedule_id', 'period_name', $$class->period_name_id, 'period_name_id', '', 1); ?> 
            <a name="show" href="form.php?class_name=hr_payslip_header" class="show period_name_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> </td>
           <td><label> Identification # : </label><?php $f->text_field_d('identification_id'); ?> </td>
          </tr>
          <tr> <td><label>Pay Day : </label><?php $f->text_field_d('pay_date'); ?> </td>
           <td><label> No Of Days  : </label><?php $f->text_field_d('no_of_days'); ?> </td>
          </tr>
          <tr> <td><label>Mode of Payment : </label><?php $f->text_field_d('mode_of_payment'); ?> </td>
           <td><label> Bank A/C # : </label><?php $f->text_field_d('bank_account_id'); ?> </td>
          </tr>
          <tr> <td><label>Payment Ref# : </label><?php $f->text_field_d('payment_ref_no'); ?> </td>
           <td><label> Social AC#1 : </label><?php $f->text_field_d('social_ac_no'); ?> </td>
          </tr>
          <tr> <td><label>Tax Registration : </label><?php $f->text_field_d('tax_reg_number'); ?> </td>
           <td><label> Social AC#2 : </label><?php $f->text_field_d('social_ac_no2'); ?> </td>
          </tr>
          <tr> <td><label>Job : </label><?php $f->text_field_d('job_name'); ?> </td>
           <td><label>Position : </label><?php $f->text_field_d('position_name'); ?> </td>
          </tr>
          <tr> <td><label>Status : </label>
            <?php echo $$class->status; ?> </td><td> </td>
          </tr>
         </table>

        </form>
        <div id ="form_line" class="hr_payslip_line"><span class="heading"> Details  </span>
         <form action=""  method="post" id="hr_payslip_line"  name="hr_payslip_line">
          <div id="tabsLine">
           <ul class="tabMain">
            <li><a href="#tabsLine-1">Details </a></li>
           </ul>
           <div class="tabContainer"> 
            <div id="tabsLine-1" class="tabContent">
             <table class="form_table">
              <thead> 
               <tr>
                <th>Action</th>
                <th>Id</th>
                <th>Compensation ELement</th>
                <th>Amount</th>
               </tr>
              </thead>
              <tbody class="form_data_line_tbody payslip_line_values" >
               <?php
               $count = 0;
               foreach ($hr_payslip_line_object as $hr_payslip_line) {
//                $leave_used = hr_leave_transaction::usage_sum_by_employeeId_leaveType($$class->leave_type);
//                $total_leave_used = !empty($leave_used) ? $leave_used : null;
                ?>         
                <tr class="payslip_line_line<?php echo $count ?>">
                 <td>    
                  <ul class="inline_action">
                   <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                   <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                   <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($hr_payslip_line->hr_payslip_line_id); ?>"></li>           
                   <li><?php echo form::hidden_field('hr_payslip_header_id', $$class->hr_payslip_header_id); ?></li>
                  </ul>
                 </td>
                 <td><?php $f->text_field_wid2sr('hr_payslip_line_id') ?></td>
                 <td><?php echo $f->select_field_from_object('hr_compensation_element_id', hr_compensation_element::find_all(), 'hr_compensation_element_id', array('element_name', 'calculation_rule'), $$class_second->hr_compensation_element_id, '', '', 1, $readonly); ?></td>

                 <td><?php $f->text_field_wid2s('element_value') ?></td>
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

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_payslip_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_payslip_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_payslip_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_payslip_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_payslip_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_payslip_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_payslip_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>
<?php include_template('footer.inc') ?>