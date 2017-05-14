<div class="row small-left-padding">
 <div id="form_all">
  <div id="form_headerDiv">
   <form  method="post" id="hr_payslip_header"  name="hr_payslip_header">
    <span class="heading"><?php echo gettext('Employee Pay Slip') ?></span>
    <div class="tabContainer">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr('hr_payslip_header_id') ?> </li>
      <li><?php $f->l_text_field_dr('employee_name'); ?>
       <?php echo $f->hidden_field_withId('employee_id', $$class->hr_employee_id); ?>
      </li>
      <li><?php $f->l_text_field_dr('identification_id'); ?>  </li>
      <li><?php $f->l_select_field_from_object('period_name_id', hr_payroll_schedule::find_by_parent_id($payroll_id, 'scheduled_date', 'ASC'), 'hr_payroll_schedule_id', 'period_name', $$class->period_name_id, 'period_name_id', '', 1); ?> 
       <a name="show" href="form.php?class_name=hr_payslip_header&<?php echo "mode=$mode"; ?>" class="document_id payslipBy_periodName">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_dr('hr_payroll_process_id'); ?>  </li>
      <li><?php $f->l_text_field_dr('pay_date'); ?>  </li>
      <li><?php $f->l_text_field_dr('no_of_days'); ?>  </li>
      <li><?php $f->l_text_field_dr('mode_of_payment'); ?>  </li>
      <li><?php $f->l_text_field_dr('bank_account_id'); ?>  </li>
      <li><?php $f->l_text_field_dr('payment_ref_no'); ?>  </li>
      <li><?php $f->l_text_field_dr('social_ac_no'); ?>  </li>
      <li><?php $f->l_text_field_dr('tax_reg_number'); ?>  </li>
      <li><?php $f->l_text_field_dr('social_ac_no2'); ?>  </li>
      <li><?php $f->l_text_field_dr('job_name'); ?>  </li>
      <li><?php $f->l_text_field_dr('position_name'); ?>  </li>
      <li><?php $f->l_text_field_dr('status'); ?>  </li>
     </ul>
    </div>
   </form>
   <div id ="form_line" class="hr_payslip_line"><span class="heading"><?php echo gettext('Salary Details') ?></span>
    <form  method="post" id="hr_payslip_line"  name="hr_payslip_line">
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Details') ?></a></li>
      </ul>
      <div class="tabContainer"> 
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Id') ?></th>
           <th><?php echo gettext('Compensation Element') ?>#</th>
           <th><?php echo gettext('Amount') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody payslip_line_values" >
          <?php
          $count = 0;
          $hr_payslip_line_object_ai = new ArrayIterator($hr_payslip_line_object);
          $hr_payslip_line_object_ai->seek($position);
          while ($hr_payslip_line_object_ai->valid()) {
           $hr_payslip_line = $hr_payslip_line_object_ai->current();
           ?>         
           <tr class="hr_payslip_line<?php echo $count ?>">
            <td><?php $f->text_field_wid2sr('hr_payslip_line_id') ?></td>
            <td><?php echo $f->select_field_from_object('hr_compensation_element_id', hr_compensation_element::find_all(), 'hr_compensation_element_id', array('element_name', 'calculation_rule'), $$class_second->hr_compensation_element_id, '', '', 1, $readonly); ?></td>

            <td><?php $f->text_field_wid2s('element_value') ?></td>
           </tr>
           <?php
           $hr_payslip_line_object_ai->next();
           if ($hr_payslip_line_object_ai->key() == $position + $per_page) {
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
    </form>

   </div> 

  </div>
 </div>
</div>

<div class="row small-top-margin">
 <div id="pagination" style="clear: both;">
<?php echo $pagination->show_pagination(); ?>
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
