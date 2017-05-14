<div id=gl_calendar_line_divId" class="pagination_page">
 <div class='row small-left-padding'>
  <div id="form_all">
   <div id="form_headerDiv"><span class="heading"><?php echo gettext('Financial Calendars') ?></span>
    <form  method="post" id="gl_calendar_line"  name="calendar_line">
     <div class='tabContainer'>
      <?php $f->l_select_field_from_object('option_line_code', gl_calendar::gl_calendar_names(), 'option_line_code', 'option_line_value', $option_line_code_h, 'option_line_code', 'action', 1, $readonly); ?>
      <a name="show" href="form.php?class_name=gl_calendar&<?php echo "mode=$mode"; ?>" class="show document_id gl_calendar_id">
       <i class='fa fa-refresh'></i></a> 
     </div>
     <div id ="form_line" class="gl_calendar"><span class="heading"><?php echo gettext('Calendar Period Details') ?> </span>
      <div id="tabsLine">
       <ul class="tabMain">
        <li><a href="#tabsLine-1"><?php echo gettext('Basic - View Only') ?></a></li>
        <li><a href="#tabsLine-2"><?php echo gettext('Effectivity') ?> </a></li>
       </ul>
       <div class="tabContainer"> 

        <div id="tabsLine-1" class="tabContent">
         <table class="form_table">
          <thead> 
           <tr>
            <th><?php echo gettext('Action') ?></th>
            <th><?php echo gettext('Id') ?>#</th>
            <th><?php echo gettext('Period Type') ?></th>
            <th><?php echo gettext('Prefix') ?>#</th>
            <th><?php echo gettext('Year') ?></th>
            <th><?php echo gettext('Quarter') ?></th>
            <th><?php echo gettext('Number') ?></th>
            <th><?php echo gettext('From Date') ?></th>
            <th><?php echo gettext('To Date') ?></th>
            <th><?php echo gettext('Name') ?></th>
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
              <?php
              echo ino_inline_action($$class->gl_calendar_id, array('option_line_code' => $option_line_code_h));
              ?>
             </td>
             <td><?php form::number_field_drs('gl_calendar_id') ?></td>
             <td><?php echo form::select_field_from_object('calendar_type', gl_calendar::period_types(), 'option_line_code', 'option_line_value', $$class->calendar_type, '', $readonly); ?></td>
             <td><?php form::text_field_widm('name_prefix'); ?></td>
             <td class="yearPicker"><?php form::number_field_wid('c_year'); ?></td>
             <td><?php form::number_field_wids('c_quarter'); ?></td>
             <td><?php form::number_field_wids('c_number'); ?></td>
             <td><?php echo $f->date_fieldAnyDay_m('from_date', $$class->from_date, ''); ?></td>
             <td><?php echo $f->date_fieldAnyDay_m('to_date', $$class->to_date, ''); ?></td>
             <td><?php $f->text_field_widr('name','always_readonly'); ?></td>
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
            <th><?php echo gettext('Adjusting Period') ?></th>
            <th><?php echo gettext('EF Id') ?>#</th>
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
 </div>
 <div class='row small-top-margin'>
  <div id="pagination">
   <?php echo $pagination->show_pagination(); ?>
  </div>
 </div>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <!--<li class="headerClassName" data-headerClassName="gl_calendar" ></li>-->
  <li class="primary_column_id" data-primary_column_id="option_line_code" ></li>
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