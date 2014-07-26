<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="inv_abc_assignment_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <form action=""  method="post" id="inv_count_header"  name="inv_count_header"><span class="heading">Count Header </span>
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Variance Limit/Approval</a></li>
          <li><a href="#tabsHeader-3">Count Frequence</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column four_column">
             <li>
              <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="inv_count_header_id select_popup clickable">
               Count Header Id : </label>
              <?php echo form::number_field_drs('inv_count_header_id'); ?>
              <a name="show" class="show inv_count_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label>Count Name : </label><?php echo form::text_field_dm('count_name'); ?></li>
             <li><label>Count Type: </label>
              <?php echo $f->select_field_from_array('count_type', inv_count_header::$count_type_a, $$class->count_type, 'count_type', '', 1, $readonly1); ?>
             </li>
             <li> <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="inv_abc_assignment_header_id select_popup clickable">
               ABC Assignment : </label> <?php
              $f = new inoform();
              echo $f->hidden_field_withId('inv_abc_assignment_header_id', $$class->inv_abc_assignment_header_id);
              $f->text_field_dm('abc_assignment_name');
              ?> </li>
             <li><label>Inventory: </label>
              <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>
             </li>
             <li><label>Adjustment A/C : </label> <?php echo $f->ac_field_dm('adjustment_ac_id'); ?></li>
             <li><label>Description : </label> <?php echo $f->text_field_dl('description'); ?></li>
            </ul>
           </div>
          </div>
          <div id="tabsHeader-2" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column three_column">
             <li> <label> Quantity(+) : </label> <?php $f->text_field_d('quantity_variance_positive'); ?> </li>
             <li> <label> Quantity(-) : </label><?php $f->text_field_d('quantity_variance_negative'); ?> </li>
             <li> <label> Value(+) : </label><?php $f->text_field_d('value_variance_positive'); ?> </li>
             <li> <label> Value(-) : </label><?php $f->text_field_d('value_variance_negative'); ?> </li>
             <li> <label> Approval Required :</label>  
              <?php echo $f->select_field_from_array('approval_required', inv_count_header::$approval_required_a, $$class->approval_required, 'approval_required'); ?> </li>
             </u>
           </div>
          </div>
          <div id="tabsHeader-3" class="tabContent">
           <div class="large_shadow_box"> 
            <div id="data_table">
             <ul class="column three_column">
              <li> <label> Action : 
                <?php echo $f->select_field_from_array('count_action', inv_count_header::$count_action_a, ''); ?> </label></li>
             </ul>
             <table class="form_table">
              <thead> 
               <tr>
                <th>ABC Class</th>
                <th>Count Per Year</th>
               </tr>
              </thead>
              <tbody class="form_data_line_tbody inv_count_class_ref_values" >
               <?php
               $count = 0;
               $all_abc_codes = inv_abc_assignment_header::inv_abc_codes();
               $no_of_class_codes = count($all_abc_codes);
               foreach ($all_abc_codes as $abc_code) {
                ?>   
                <tr class="inv_abc_assignment_header<?php echo $count ?>">
                 <td><?php echo $f->text_field('assign_abc_class_value', $abc_code->option_line_code, '8', '', '', '', 1); ?></td>
                 <td><?php
                  $count_per_year = inv_count_abc_ref::find_by_parentId_abcCode($$class->inv_count_header_id, $abc_code->option_line_code);
                  $count_per_year_v = ($count_per_year) ? $count_per_year->count_per_year : null;
                  echo $f->number_field('count_per_year', $count_per_year_v);
                  ?></td>
                </tr>
                <?php
                $count++;
               }
               ?>
              </tbody>
             </table>
            </div>
           </div>
          </div>
         </div>
        </div>
       </form>
      </div>

      <div id ="form_line" class="form_line"><span class="heading">Count Schedules </span>
       <div id="tabsLine">
        <ul class="tabMain">
         <li><a href="#tabsLine-1">Schedule </a></li>
        </ul>
        <div class="tabContainer"> 
         <form action=""  method="post" id="inv_count_schedule_line"  name="inv_count_schedule_line">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>Count Id</th>
              <th>Master Item Id </th>
              <th>Item Number</th>
              <th>Item Description</th>
              <th>Schedule Date</th>
              <th>Status</th>
              <th>Code On Count</th>
              <th>Subinventory</th>
              <th>Locator</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody inv_count_schedule_values" >
             <?php
             $count = 0;
             foreach ($inv_count_schedule_object as $inv_count_schedule) {
              ?>         
              <tr class="inv_count_schedule<?php echo $count ?>">
               <td>    
                <ul class="inline_action">
                 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($inv_count_schedule->inv_count_schedule_id); ?>"></li>           
                 <li><?php echo form::hidden_field('inv_count_header_id', $$class->inv_count_header_id); ?>
                 <?php echo form::hidden_field('org_id', $$class->org_id); ?>
                 </li>
                </ul>
               </td>
               <td><?php form::number_field_wid2sr('inv_count_schedule_id'); ?></td>
               <td><?php $f->text_field_d2r('item_id_m'); ?></td>
               <td><?php $f->text_field_wid2('item_number', 'select_item_number'); ?> <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number_only select_popup"></td>
               <td><?php $f->text_field_wid2l('item_description'); ?></td>
               <td><?php echo $f->date_fieldAnyDay('schedule_date', $$class_second->schedule_date); ?></td>
               <td><?php echo $f->select_field_from_array('status', inv_count_schedule::$status_a, $$class_second->status, '','','','',1); ?></td>
               <td><?php $f->text_field_wid2s('abc_code'); ?></td>
               <td><?php $f->text_field_wid2s('subinventory_id'); ?></td>
               <td><?php $f->text_field_wid2s('locator_id'); ?></td>
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