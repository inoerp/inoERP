<ul id="js_files" class="none">
 <li class="hidden">modules/hr/timesheet_period/timesheet_period.js</li>
</ul>
<div id="hr_timesheet_period_divId">
 <div class="row" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
  <div id ="searchResult">
   <form  method="post" id="hr_timesheet_period"  name="hr_timesheet_period">
    <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('HR timesheet_period') ?></span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basics') ?></a></li>
      </ul>
      <div class="tabContainer">
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Id') ?></th>
           <th><?php echo gettext('From Date') ?></th>
           <th><?php echo gettext('To Date') ?></th>
           <th><?php echo gettext('Timesheet Period') ?></th>
           <th><?php echo gettext('Description') ?></th>
           <th><?php echo gettext('Max Work Hour') ?></th>
           <th><?php echo gettext('Max Billable Hour') ?></th>
           <th><?php echo gettext('Status') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $hr_timesheet_period) {
            ?>         
            <tr class="hr_timesheet_period_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($hr_timesheet_period->hr_timesheet_period_id); ?>"></li>           
              </ul>
             </td>
             <td><?php echo $f->text_field_widr('hr_timesheet_period_id', 'always_readonly'); ?></td>
             <td><?php echo $f->date_fieldAnyDay('from_date', $$class->from_date); ?></td>
             <td><?php echo $f->date_fieldAnyDay('to_date', $$class->to_date); ?></td>
             <td><?php echo $f->text_field_wid('timesheet_period'); ?></td>
             <td><?php echo $f->text_field_wid('description'); ?></td>
             <td><?php echo $f->number_field('max_work_hour', $$class->max_work_hour); ?></td>
             <td><?php echo $f->number_field('max_billable_hour', $$class->max_billable_hour); ?></td>
             <td><?php echo $f->select_field_from_array('status', hr_timesheet_period::$status_a, $$class->status, 'status', 'medium', 1); ?></td>
            </tr>
            <?php
            $count = $count + 1;
           }
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
 <!--END OF FORM HEADER-->
 <div class="row small-top-margin">
  <div id="pagination" style="clear: both;">
   <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
   ?>
  </div>
 </div>

</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="hr_timesheet_period" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="hr_timesheet_period" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="hr_timesheet_period"></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>
