<div id="form_all">
 <div id="form_headerDiv"><span class="heading">Financial Calendars</span>
  <form action=""  method="post" id="gl_calendar_line"  name="calendar_line">
   <div id="form_serach_header">
    <label>Calendar :</label>
    <?php echo form::select_field_from_object('option_line_code', gl_calendar::gl_calendar_names(), 'option_line_code', 'option_line_value', $option_line_code_h, 'option_line_code', $readonly); ?>
    <a name="show" href="form.php?class_name=gl_calendar&<?php echo "mode=$mode"; ?>" class="show document_id gl_calendar_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
   </div>
   <div id ="form_line" class="gl_calendar"><span class="heading">Calendar Period Details </span>
    <div id="tabsLine">
     <ul class="tabMain">
      <li><a href="#tabsLine-1">Basics - View Only </a></li>
      <li><a href="#tabsLine-2">Effectivity </a></li>
     </ul>
     <div class="tabContainer"> 

      <div id="tabsLine-1" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th>Action</th>
          <th>Id</th>
          <th>Period Type</th>
          <th>Prefix</th>
          <th>Year</th>
          <th>Quarter</th>
          <th>Number</th>
          <th>From Date</th>
          <th>To Date</th>
          <th>Name</th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody calendar_values" >
         <?php
         $count = 0;
         $calendar_object_ai = new ArrayIterator($calendar_object);
         $calendar_object_ai->seek($position);
         while ($calendar_object_ai->valid()) {
          $gl_calendar = $calendar_object_ai->current();
          ?>         
          <tr class="gl_calendar<?php echo $count ?>">
           <td>    
            <ul class="inline_action">
             <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
             <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
             <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->gl_calendar_id); ?>"></li>           
             <li><?php echo form::hidden_field('option_line_code', $$class->option_line_code); ?></li>
            </ul>
           </td>
           <td><?php form::number_field_drs('gl_calendar_id') ?></td>
           <td><?php echo form::select_field_from_object('calendar_type', gl_calendar::period_types(), 'option_line_code', 'option_line_value', $$class->calendar_type, '', $readonly); ?></td>
           <td><?php form::text_field_widsm('name_prefix'); ?></td>
           <td class="yearPicker"><?php form::number_field_widsm('year'); ?></td>
           <td><?php form::number_field_widsm('quarter'); ?></td>
           <td><?php form::number_field_widsm('number'); ?></td>
           <td><?php echo form::date_fieldAnyDay_m('from_date', $$class->from_date, 1, 'date'); ?></td>
           <td><?php echo form::date_fieldAnyDay_m('to_date', $$class->to_date, 1, 'date'); ?></td>
           <td><?php form::text_field_widsrm('name'); ?></td>
          </tr>
          <?php
          $calendar_object_ai->next();
          if ($calendar_object_ai->key() == $position + $per_page) {
           break;
          }
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>
      <div id="tabsLine-2" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th>Adjusting Period</th>
          <th>EF id</th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody calendar_values" >
         <?php
         $count = 0;
         $calendar_object_ai = new ArrayIterator($calendar_object);
         $calendar_object_ai->seek($position);
         while ($calendar_object_ai->valid()) {
          $gl_calendar = $calendar_object_ai->current();
          ?>         
          <tr class="gl_calendar<?php echo $count ?>">
           <td><?php echo form::checkBox_field_d('adjustment_period_cb'); ?></td>
           <td><?php echo form::number_field_wids('ef_id'); ?></td>
          </tr>
          <?php
          $calendar_object_ai->next();
          if ($calendar_object_ai->key() == $position + $per_page) {
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
   </div> 
  </form>
 </div>
</div>

<div id="pagination" style="clear: both;">
 <?php echo $pagination->show_pagination(); ?>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="gl_calendar" ></li>
  <li class="line_key_field" data-line_key_field="name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="gl_calendar" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="gl_calendar_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="calendar_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>