<ul id="js_files" class="none">
 <li class="hidden">modules/lms/attendance/attendance.js</li>
</ul>
<div id="lms_attendance_divId">
 <div class="row" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
  <div id ="searchResult">
   <form  method="post" id="lms_attendance"  name="lms_attendance">
    <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('LMS Attendance') ?></span>
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
           <th><?php echo gettext('Date') ?></th>
           <th><?php echo gettext('Punch In') ?></th>
           <th><?php echo gettext('Punch In Note') ?></th>
           <th><?php echo gettext('Punch Out') ?></th>
           <th><?php echo gettext('Punch Out Note') ?></th>
           <th><?php echo gettext('Description') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php 
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $lms_attendance) {
            ?>         
            <tr class="lms_attendance_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($lms_attendance->lms_attendance_id); ?>"></li>           
              </ul>
             </td>
             <td><?php echo $f->text_field_widr('lms_attendance_id', 'always_readonly'); ?></td>
             <td><?php $f->date('date', $$class->date); ?></td>
             <td><?php echo $f->dateTime_field('punch_in', $$class->punch_in);?></td>
             <td><?php $f->l_text_field_d('punch_in_note'); ?></td>
             <td><?php echo $f->dateTime_field('punch_out', $$class->punch_out); ?></td>
             <td><?php $f->l_text_field_d('punch_out_note'); ?></td>
             <td><?php $f->l_text_field_d('employee_name'); ?></td>            
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
  <li class="lineClassName" data-lineClassName="lms_attendance" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="lms_attendance" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="lms_attendance"></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>
