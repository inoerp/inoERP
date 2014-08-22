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
      <?php      echo (!empty($show_message)) ? $show_message : "";        $f = new inoform();       ?> 
      <!--    End of place for showing error messages-->
      <div id="form_all">
       <form action=""  method="post" id="hr_payroll"  name="hr_payroll"><span class="heading">Payroll </span>
        <div id ="form_header">
         <div id="tabsHeader">
          <ul class="tabMain">
           <li><a href="#tabsHeader-1">Basic Info</a></li>
           <li><a href="#tabsHeader-2">Action</a></li>
          </ul>
          <div class="tabContainer">
           <div id="tabsHeader-1" class="tabContent">
            <div class="large_shadow_box"> 
             <ul class="column four_column">
              <li>
               <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_payroll_id select_popup clickable">
                Payroll Id : </label><?php echo form::number_field_drs('hr_payroll_id'); ?>
               <a name="show" class="show hr_payroll_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
              </li>
              <li><label>Payroll : </label> <?php echo $f->text_field_dm('payroll'); ?> </li>
              <li><label>Period Type : </label>
               <?php echo $f->select_field_from_object('period_type', option_header::period_types(), 'option_line_code', 'option_line_value', $$class->period_type, 'period_type', '', 1, $readonly); ?>
              </li>
              <li><label>Payment Method: </label>
               <?php echo $f->select_field_from_object('payment_method_id', hr_payroll_payment_method::find_all(), 'hr_payroll_payment_method_id', 'payment_method', $$class->payment_method_id, 'payment_method_id','', 1, $readonly); ?>
              </li>
              <li><label>Start Date : </label><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?></li>
              <li><label>End Date : </label><?php echo $f->date_fieldAnyDay('end_date', $$class->end_date); ?></li>
              <li><label>Description : </label><?php echo $f->text_field_dl('description'); ?></li>
             </ul>
            </div>
           </div>
           <div id="tabsHeader-2" class="tabContent">
            <div> 
             <ul class="column four_column">
              <li><label>Generate Schedule : </label><?php echo $f->checkBox_field_d('schedule_payroll_cb'); ?></li>
             </ul>
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
          <form action=""  method="post" id="hr_payroll_schedule_line"  name="hr_payroll_schedule_line">
           <div id="tabsLine-1" class="tabContent">
            <table class="form_table">
             <thead> 
              <tr>
               <th>Action</th>
               <th>Line Id</th>
               <th>Scheduled Date</th>
               <th>Start Date</th>
               <th>End Date</th>
               <th>Status</th>
               <th>Description</th>
              </tr>
             </thead>
             <tbody class="form_data_line_tbody hr_payroll_schedule_values" >
              <?php
               $count = 0;
               foreach ($hr_payroll_schedule_object as $hr_payroll_schedule) {
                ?>         
                <tr class="hr_payroll_schedule<?php echo $count ?>">
                 <td>    
                  <ul class="inline_action">
                   <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                   <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                   <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($hr_payroll_schedule->hr_payroll_schedule_id); ?>"></li>           
                   <li><?php echo form::hidden_field('hr_payroll_id', $$class->hr_payroll_id); ?></li>
                  </ul>
                 </td>
                 <td><?php $f->text_field_d2sr('hr_payroll_schedule_id'); ?></td>
                 <td><?php echo $f->date_fieldAnyDay('scheduled_date', $$class_second->scheduled_date); ?></td>
                 <td><?php echo $f->date_fieldAnyDay('start_date', $$class_second->start_date); ?></td>
                 <td><?php echo $f->date_fieldAnyDay('end_date', $$class_second->end_date); ?></td>
                 <td><?php form::text_field_wid2('status'); ?></td>
                 <td><?php form::text_field_wid2l('description'); ?></td>
                </tr>
                <?php
                $count = $count + 1;
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
        <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
        ?>
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