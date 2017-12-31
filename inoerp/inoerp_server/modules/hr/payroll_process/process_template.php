<div id="form_all">
 <form method="post" id="hr_payroll_process"  name="hr_payroll_process">
	<span class="heading"><?php echo gettext('Payroll Process') ; ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ; ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Action') ; ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ; ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('hr_payroll_process_id') ?>
        <a name="show" href="form.php?class_name=hr_payroll_process&<?php echo "mode=$mode"; ?>" class="show document_id hr_payroll_process_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><label>Process Name</label><?php echo $f->text_field_d('proces_name'); ?> </li>
       <li><label>Payroll Id</label><?php echo $f->text_field_dr('hr_payroll_id'); ?> </li>
       <li><label>Schedule Id</label><?php echo $f->text_field_dr('hr_payroll_schedule_id'); ?> </li>
       <li><label>Description</label><?php echo $f->text_field_dl('description'); ?></li>
       <li><label>Status </label><?php echo $f->text_field_dr('status'); ?></li>
       <li><label>Journal Header Id</label><?php echo $f->text_field_dr('gl_journal_header_id'); ?></li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> 
       <ul class="column four_column">
        <li><a href="<?php HOME_URL ?>program.php?class_name=hr_payroll_process&program_name=prg_confirm_payroll_process&hr_payroll_process_id=<?php echo $$class->hr_payroll_process_id ?>" class="button">Confirm Payroll Process</a></li>
        <li><a href="<?php HOME_URL ?>program.php?class_name=hr_payroll_process&program_name=prg_cancel_payroll_process&hr_payroll_process_id=<?php echo $$class->hr_payroll_process_id ?>" class="button">Cancel Payroll Process</a></li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'hr_payroll_process';
        $reference_id = $$class->hr_payroll_process_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
   </div>
  </div>
 </form>
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Line Details') ; ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Schedules') ; ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <form action=""  method="post" id="hr_payslip_header_line"  name="hr_payslip_header_line">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th>Action</th>
         <th>Payslip Id</th>
         <th>Employee</th>
         <th>Period Name</th>
         <th>Pay Date</th>
         <th>Status</th>
         <th>Description</th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody hr_payslip_header_values" >
        <?php
        $count = 0;
        $hr_payslip_header_object_ai = new ArrayIterator($hr_payslip_header_object);
        $hr_payslip_header_object_ai->seek($position);
        while ($hr_payslip_header_object_ai->valid()) {
         $hr_payslip_header = $hr_payslip_header_object_ai->current();
         ?>
         <tr class="hr_payslip_header<?php echo $count ?>">
          <td>    
           <ul class="inline_action">
            <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
            <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
            <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($hr_payslip_header->hr_payslip_header_id); ?>"></li>           
            <li><?php echo form::hidden_field('hr_payroll_process_id', $$class->hr_payroll_process_id); ?></li>
           </ul>
          </td>
          <td><?php $f->text_field_d2sr('hr_payslip_header_id'); ?></td>
          <td><?php $f->text_field_wid2r('employee_id'); ?></td>
          <td><?php $f->text_field_wid2r('period_name_id'); ?></td>
          <td><?php $f->text_field_wid2r('pay_date'); ?></td>
          <td><?php form::text_field_wid2('status'); ?></td>
          <td><?php form::text_field_wid2l('description'); ?></td>
         </tr>
         <?php
         $count = $count + 1;
         $hr_payslip_header_object_ai->next();
         if ($hr_payslip_header_object_ai->key() == $position + $per_page) {
          break;
         }
        }
        ?>
       </tbody>
      </table>
     </div>
    </form>
   </div>

  </div>
 </div> 
 <div id="pagination" style="clear: both;">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_payroll_process" ></li>
  <li class="lineClassName" data-lineClassName="hr_payslip_header_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_payroll_process_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_payroll_process" ></li>
  <li class="line_key_field" data-line_key_field="hr_payslip_header_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_payslip_header_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_payroll_process_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_payroll_process" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>
