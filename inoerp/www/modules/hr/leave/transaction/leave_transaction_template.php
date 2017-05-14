<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="bom_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php  echo (!empty($show_message)) ? $show_message : "";      ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <form action=""  method="post" id="hr_leave_transaction_header"  name="hr_leave_transaction_header"><span class="heading"><?php echo gettext('Leave Application') ?> </span>
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column four_column">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_leave_transaction_header_id select_popup clickable">
               <?php echo gettext('Header Id') ?> : </label><?php $f->text_field_dsr('hr_leave_transaction_header_id') ?>
              <a name="show" href="form.php?class_name=hr_leave_transaction_header_id" class="show hr_leave_transaction_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_employee_id select_popup clickable">
               <?php echo gettext('Employee Name') ?> : </label><?php $f->text_field_d('employee_name'); ?>
              <?php echo $f->hidden_field_withId('employee_id', $$class->employee_id); ?>
             </li>
             <li><label>  <?php echo gettext('Identification') ?> # : </label><?php $f->text_field_dr('identification_id'); ?>  </li>
             <li><label>  <?php echo gettext('Requested Date') ?> : </label><?php echo $f->date_fieldFromToday('requsted_date', $$class->requsted_date); ?>  </li>
             <li><label>  <?php echo gettext('Approved Date') ?> : </label><?php  echo $f->date_fieldFromToday('approved_date', $$class->approved_date, 1); ?>  </li>
             <li><label>  <?php echo gettext('Approved By') ?> : </label><?php $f->text_field_dr('approved_by'); ?>  </li>
             <li><label>  <?php echo gettext('Leave Status') ?> : </label><?php $f->text_field_dr('leave_status'); ?>  </li>
            </ul>
           </div>
          </div>
         </div>
        </div>
       </form>
      </div>

      <div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Dates') ?> </span>
       <form action=""  method="post" id="hr_leave_transaction_line"  name="hr_leave_transaction_line">
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th><?php echo gettext('Action') ?></th>
              <th><?php echo gettext('Leave Type') ?></th>
              <th><?php echo gettext('From Date') ?></th>
              <th><?php echo gettext('To Date') ?></th>
              <th><?php echo gettext('Reason') ?></th>
              <th><?php echo gettext('Contact') ?></th>
              <th><?php echo gettext('Number Of Days') ?></th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($hr_leave_transaction_line_object as $hr_leave_transaction_line) {
               ?>         
               <tr class="hr_leave_transaction_line<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="<?php echo gettext('add new line') ?>" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="<?php echo gettext('remove this line') ?>" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->hr_leave_transaction_line_id); ?>"></li>           
                  <li><?php echo form::hidden_field('hr_leave_transaction_header_id', $hr_leave_transaction_header->hr_leave_transaction_header_id); ?></li>
                 </ul>
                </td>
                <td><?php echo $f->select_field_from_object('leave_type', hr_leave_type::find_all(), 'hr_leave_type_id', 'leave_type', $$class->leave_type, '', '', 1, $readonly); ?></td>
                <td><?php echo $f->date_fieldFromToday('from_date', $$class->from_date); ?></td>
                <td><?php echo $f->date_fieldFromToday('to_date', $$class->to_date); ?></td>
                <td><?php $f->text_field_dl('reason'); ?></td>
                <td><?php $f->text_field_dl('contact_details'); ?></td>
                <td><?php $f->text_field_dr('leave_quantity'); ?></td>
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

      <!--END OF FORM HEADER-->
     </div>
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_leave_transaction_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_leave_transaction_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_leave_transaction_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_leave_transaction_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_leave_transaction_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_leave_transaction_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_leave_transaction_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>
