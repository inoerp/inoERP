<div id="adm_task_type_divId">
 <div class="row small-top-margin" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>

  <div id="searchResult">
   <form  method="post" id="adm_task_type"  name="adm_task_type">
    <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Task Type') ?></span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
       <li><a href="#tabsLine-2"><?php echo gettext('Details') ?></a></li>
      </ul>
      <div class="tabContainer">
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Task Type Id') ?></th>
           <th><?php echo gettext('Task Type') ?></th>
           <th><?php echo gettext('Description') ?></th>
           <th><?php echo gettext('Access Level') ?></th>
           <th><?php echo gettext('From Date') ?></th>
           <th><?php echo gettext('To Date') ?></th>
           <th><?php echo gettext('Process Flow') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $adm_task_type) {
            ?>         
            <tr class="adm_task_type_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($adm_task_type->adm_task_type_id); ?>"></li>           
              </ul>
             </td>
             <td><?php form::text_field_widsr('adm_task_type_id'); ?></td>
             <td><?php form::text_field_wid('task_type'); ?></td>
             <td><?php form::text_field_wid('description'); ?></td>
             <td><?php echo $f->select_field_from_array('access_level', option_header::$access_level_a, $$class->access_level, 'access_level', '', '', $readonly); ?></td>
             <td><?php echo $f->date_fieldAnyDay('from_date', $$class->from_date); ?></td>
             <td><?php echo $f->date_fieldAnyDay('to_date', $$class->to_date); ?></td>
             <td><?php echo $f->select_field_from_object('process_flow_header_id', sys_process_flow_header::find_all(), 'sys_process_flow_header_id', 'process_flow', $$class->process_flow_header_id, 'process_flow_header_id'); ?></td>
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
           <th><?php echo gettext('Task Type Id') ?></th>
           <th><?php echo gettext('Auto Notification') ?></th>
           <th><?php echo gettext('Schedule') ?></th>
           <th><?php echo gettext('Effort UOM') ?></th>
           <th><?php echo gettext('Effort Value') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $adm_task_type) {
            ?>         
            <tr class="adm_task_type_line<?php echo $count ?>">
             <td><?php echo $$class->adm_task_type_id; ?></td>
             <td><?php $f->checkBox_field_d('send_notification_cb'); ?></td>
             <td><?php $f->checkBox_field_d('schedule_cb'); ?></td>
             <td><?php echo $f->select_field_from_object('effort_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->effort_uom_id, 'effort_uom_id'); ?></td>
             <td><?php $f->text_field_d('effort_value'); ?></td>
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
  <li class="lineClassName" data-lineClassName="adm_task_type" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="adm_task_type" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="adm_task_type"></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>

