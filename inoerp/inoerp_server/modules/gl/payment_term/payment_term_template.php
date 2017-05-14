<div id ="form_header"><span class="heading"><?php echo gettext('Payment Term') ?></span>
 <form  method="post" id="payment_term"  name="payment_term">
  <div class="tabContainer">
   <ul class="column header_field">
    <li><?php $f->l_text_field_dr_withSearch('payment_term_id'); ?>
     <a name="show" href="form.php?class_name=payment_term&<?php echo "mode=$mode"; ?>" class="show document_id payment_term_id">
      <i class="fa fa-refresh"></i></a> 
    </li>
    <li><?php $f->l_text_field_d('payment_term'); ?></li>         
    <li><?php $f->l_text_field_d('description'); ?></li>         
    <li><?php $f->l_checkBox_field_d('prepayment_cb'); ?></li> 
    <li><?php $f->l_status_field_d('status'); ?></li>
    <li><?php $f->checkBox_field_d('rev_enabled_cb'); ?></li> 
    <li><?php $f->l_text_field_d('rev_number'); ?></li>         
   </ul>
  </div>
 </form>
</div>

<div id ="mix_form" class="mix_form"><span class="heading"><?php echo gettext('Schedule & Discount Lines') ?></span>

 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Schedule') ?></a></li>
   <li><a href="#tabsLine-2"><?php echo gettext('Discount') ?> </a></li>
  </ul>
  <div class="tabContainer">
   <div id ="form_line" class="form_line">
    <form action=""  method="post" id="payment_term_schedule_line"  name="payment_term_schedule_line">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Schedule Id') ?></th>
         <th><?php echo gettext('Seq Number') ?></th>
         <th><?php echo gettext('Percentage') ?></th>
         <th><?php echo gettext('Due Days') ?></th>
         <th><?php echo gettext('Due Dates') ?></th>
         <th><?php echo gettext('Date of Month') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody payment_term_schedule_values" >
        <?php
        $count = 0;
        foreach ($payment_term_schedule_object as $payment_term_schedule) {
         ?>         
         <tr class="payment_term_schedule<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($payment_term_schedule->payment_term_schedule_id, array('payment_term_id' => $$class->payment_term_id));
           ?>
          </td>
          <td><?php form::text_field_wid2('payment_term_schedule_id'); ?></td>
          <td><?php form::text_field_wid2('seq_number'); ?></td>
          <td><?php form::text_field_wid2('amount_percentage'); ?></td>
          <td><?php form::text_field_wid2('due_days'); ?></td>
          <td><?php echo $f->date_fieldFromToday('due_dates', $$class_second->due_dates); ?></td>
          <td><?php form::text_field_wid2('due_date_of_month'); ?></td>
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
   <div id ="form_line2" class="form_line2">
    <form action=""  method="post" id="payment_term_discount_line"  name="payment_term_discount_line">
     <div id="tabsLine-2" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Discount Id') ?></th>
         <th><?php echo gettext('Seq Number') ?></th>
         <th><?php echo gettext('Percentage') ?></th>
         <th><?php echo gettext('Due Days') ?></th>
         <th><?php echo gettext('Due Dates') ?></th>
         <th><?php echo gettext('Date of Month') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody2 payment_term_discount_values">
        <?php
        $count = 0;
        foreach ($payment_term_discount_object as $payment_term_discount) {
         ?>         
         <tr class="payment_term_discount<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($payment_term_schedule->payment_term_schedule_id, array('payment_term_id' => $$class->payment_term_id));
           ?>
          </td>
          <td><?php form::text_field_wid3('payment_term_discount_id'); ?></td>
          <td><?php form::text_field_wid3('seq_number'); ?></td>
          <td><?php form::text_field_wid3('discount_percentage'); ?></td>
          <td><?php form::text_field_wid3('due_days'); ?></td>
          <td><?php echo $f->date_fieldFromToday('due_dates', $$class_third->due_dates); ?></td>
          <td><?php form::text_field_wid3('due_date_of_month'); ?></td>
         </tr>
         <?php
         $count = $count + 1;
        }
        ?>
       </tbody>
       <!--                  Showing a blank form for new entry-->

      </table>
     </div>
    </form>
   </div>
  </div>
 </div>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="payment_term" ></li>
  <li class="lineClassName" data-lineClassName="payment_term_schedule" ></li>
  <li class="lineClassName2" data-lineClassName2="payment_term_discount" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="payment_term_id" ></li>
  <li class="form_header_id" data-form_header_id="payment_term" ></li>
  <li class="line_key_field" data-line_key_field="amount_percentage" ></li>
  <li class="single_line" data-single_line="false" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="payment_term_id" ></li>
  <li class="docLineId" data-docLineId="payment_term_discount" ></li>
  <li class="btn1DivId" data-btn1DivId="payment_term" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="payment_term" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>