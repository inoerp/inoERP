<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="mdm_price_list_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
      echo (!empty($show_message)) ? $show_message : "";
      $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->
      <div id="form_all">
       <form action=""  method="post" id="hr_payroll_process"  name="hr_payroll_process"><span class="heading">Payroll Process </span>
        <div id ="form_header">
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1">Basic Info</a></li>
           <li><a href="#tabsHeader-2">Action</a></li>
           <li><a href="#tabsHeader-3">Notes</a></li>
          </ul>
          <div class="tabContainer">
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column four_column">
              <li>
               <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_payroll_process_id select_popup clickable">
                Process Id : </label><?php echo form::number_field_drs('hr_payroll_process_id'); ?>
               <a name="show" class="show hr_payroll_process_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
              </li>
              <li><label>Process Name : </label> <?php echo $f->text_field_d('proces_name'); ?> </li>
              <li><label>Payroll Id : </label> <?php echo $f->text_field_dr('hr_payroll_id'); ?> </li>
              <li><label>Schedule Id : </label> <?php echo $f->text_field_dr('hr_payroll_schedule_id'); ?> </li>
              <li><label>Description : </label><?php echo $f->text_field_dl('description'); ?></li>
              <li><label>Status : </label><?php echo $f->text_field_dr('status'); ?></li>
              <li><label>Journal Header Id : </label><?php echo $f->text_field_dr('gl_journal_header_id'); ?></li>
             </ul>
            </div>
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
       <div id ="form_line" class="form_line"><span class="heading">Line Details </span>
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Schedules</a></li>
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
      <!--END OF FORM -->
     </div>
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>