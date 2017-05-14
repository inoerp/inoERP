<div id="adm_task_type_divId">
 <div class="row small-top-margin" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>

  <div id="searchResult">
   <form  method="post" id="adm_task_status"  name="adm_task_status">
    <div id ="form_line" class="form_line"><span class="heading">Task status</span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
       <li><a href="#tabsLine-2"><?php echo gettext('Details') ?></a></li>
      </ul>
      <div class="tabContainer">
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Task Status Id') ?></th>
           <th><?php echo gettext('Task Status') ?></th>
           <th><?php echo gettext('Description') ?></th>
           <th><?php echo gettext('Access Level') ?></th>
           <th><?php echo gettext('From Date') ?></th>
           <th><?php echo gettext('To Date') ?></th>
           <th><?php echo gettext('Start By') ?></th>
           <th><?php echo gettext('Due Date') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $adm_task_status) {
            ?>         
            <tr class="adm_task_status_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input status="checkbox" name="line_id_cb" value="<?php echo htmlentities($adm_task_status->adm_task_status_id); ?>"></li>           
              </ul>
             </td>
             <td><?php form::text_field_widsr('adm_task_status_id'); ?></td>
             <td><?php form::text_field_wid('status'); ?></td>
             <td><?php form::text_field_wid('description'); ?></td>
             <td><?php echo $f->select_field_from_array('access_level', option_header::$access_level_a, $$class->access_level, 'access_level', '', '', $readonly); ?></td>
             <td><?php echo $f->date_fieldAnyDay('from_date', $$class->from_date); ?></td>
             <td><?php echo $f->date_fieldAnyDay('to_date', $$class->to_date); ?></td>
             <td><?php echo $f->select_field_from_array('start_by', adm_task_status::$start_by_a, $$class->start_by, 'start_by'); ?></td>
             <td><?php echo $f->l_select_field_from_array('due_date', adm_task_status::$due_date_a, $$class->due_date, 'due_date'); ?></td>
            </tr>
            <?php
            $count = $count + 1;
           }
          }
          ?>
         </tbody>
        </table>
       </div>
       <div id="tabsLine-2" class="scrollElement" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Task Status Id') ?></th>
           <th><?php echo gettext('Auto Notification') ?></th>
           <th><?php echo gettext('Schedule') ?></th>
           <th><?php echo gettext('Primary Task Type') ?></th>
           <th><?php echo gettext('Usage') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $adm_task_status) {
            ?>         
            <tr class="adm_task_status_line<?php echo $count ?>">
             <td><?php echo $$class->adm_task_status_id; ?></td>
             <td><?php $f->checkBox_field_d('send_notification_cb'); ?></td>
             <td><?php $f->checkBox_field_d('schedule_cb'); ?></td>
             <td><?php $f->l_select_field_from_object('primary_task_type', adm_task_status::primary_task_status(), 'option_line_code', 'option_line_value', $$class->primary_task_type, 'primary_task_type'); ?></td>
             <td><?php $f->l_text_field_d('usage'); ?></td>
            </tr>
            <?php
            $count = $count + 1;
           }
          }
          ?>
         </tbody>
         <!--                  Showing a blank form for new entry-->

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
  <li class="lineClassName" data-lineClassName="adm_task_status" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="adm_task_status" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="adm_task_status"></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>

