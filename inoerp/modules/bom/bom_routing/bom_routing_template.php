<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="bom_routing_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
       echo (!empty($show_message)) ? $show_message : "";
       $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header"><span class="heading">Routing </span>
       <form action=""  method="bom_routingst" id="bom_routing_header"  name="bom_routing_header">
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Common Routing</a></li>
          <li><a href="#tabsHeader-3">Notes</a></li>
          <li><a href="#tabsHeader-4">Files</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column five_column">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bom_routing_header_id select_popup clickable">
               Routing Id : </label><?php $f->text_field_dsr('bom_routing_header_id') ?>
              <a name="show" class="show bom_routing_header_id clickable"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label>Org Name(1) : </label>
              <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $bom_routing_header->org_id, 'org_id', '', 1, $readonly1, '', ''); ?>
             </li>
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="item_id_m select_popup clickable">
               Item Number(2) : </label> 
              <?php echo $f->hidden_field_withId('item_id_m', $$class->item_id_m); ?>
              <?php $f->text_field_dm('item_number', 'select_item_number_allowedBOM'); ?>
             </li>
             <li><label>UOM : </label>
              <?php echo $f->select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, '', '', '', $readonly); ?>
             </li>
             <li><label>Description: </label>       <?php form::text_field_widr('item_description'); ?>     </li>
             <li><label>Revision : </label>               <?php form::text_field_d('routing_revision'); ?>              </li>
             <li><label>Effective Date : </label>               <?php echo form::date_fieldAnyDay_m('effective_date', $$class->effective_date); ?>              </li>
            </ul>
           </div>
          </div>
          <div id="tabsHeader-2" class="tabContent">
           <div> 
            <ul class="column five_column">
             <li><label>Item Number : </label>
              <?php echo $f->hidden_field_withIdClass('common_routing_item_id_m', $$class->common_routing_item_id_m, 'item_id_m'); ?>
              <?php $f->text_field_d('commonRouting_item_number', 'select_item_number'); ?>  </li>
             <li><label>Description: </label><?php $f->text_field_d('commonRouting_item_description', 'commonRouting_item_description'); ?>  </li>
            </ul>
           </div>
          </div>
          <div id="tabsHeader-3" class="tabContent">
           <div id="comments">
            <div id="comment_list">
             <?php echo!(empty($comments)) ? $comments : ""; ?>
            </div>
            <div id ="display_comment_form">
             <?php
              $reference_table = 'bom_routing_header';
              $reference_id = $$class->bom_routing_header_id;
             ?>
            </div>
            <div id="new_comment">
            </div>
           </div>
          </div>
          <div id="tabsHeader-4" class="tabContent">
           <div> <?php echo ino_attachement($file) ?> </div>
          </div>
         </div>
        </div>
       </form>
      </div>

      <div id="form_line" class="form_line"><span class="heading">Operation & Resource Details </span>
       <form action=""  method="bom_routingst" id="bom_routing_site"  name="bom_routing_line">
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Basic</a></li>
          <li><a href="#tabsLine-2">WIP</a></li>
          <li><a href="#tabsLine-3">Effectivity</a></li>
          <li><a href="#tabsLine-4">Data Collection</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>Seq #</th>
              <th>Line Id</th>
              <th>Routing Seq</th>
              <th>Standard Op</th>
              <th>Referenced</th>
              <th>Department</th>

              <th>Operation Details</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($bom_routing_line_object as $bom_routing_line) {
               ?>         
               <tr class="bom_routing_line<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($bom_routing_line->bom_routing_line_id); ?>"></li>           
                  <li><?php echo form::hidden_field('bom_routing_header_id', $bom_routing_header->bom_routing_header_id); ?></li>
                 </ul>
                </td>
                <td><?php $f->seq_field_d($count) ?></td>
                <td><?php form::text_field_wid2sr('bom_routing_line_id'); ?></td>
                <td><?php $f->text_field_d2s('routing_sequence', 'lines_number'); ?></td>
                <td><?php echo form::select_field_from_object('standard_operation_id', bom_standard_operation::find_all(), 'bom_standard_operation_id', 'standard_operation', $$class_second->standard_operation_id, '', $readonly); ?></td>
                <td><?php echo form::checkBox_field('referenced_cb', $$class_second->referenced_cb); ?></td>
                <td><?php echo form::select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class_second->department_id, '', $readonly, '', '', 1); ?></td>
                <td class="add_detail_values"><img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
                 <!--</td></tr>-->	
                 <?php
                 $bom_routing_line_id = $bom_routing_line->bom_routing_line_id;
                 if (!empty($bom_routing_line_id)) {
                  $bom_routing_detail_object = bom_routing_detail::find_by_routing_lineId($bom_routing_line_id);
                 } else {
                  $bom_routing_detail_object = array();
                 }
                 if (count($bom_routing_detail_object) == 0) {
                  $bom_routing_detail = new bom_routing_detail();
                  $bom_routing_detail_object = array();
                  array_push($bom_routing_detail_object, $bom_routing_detail);
                 }
                 ?>
         <!--						 <tr><td>-->
                 <div class="class_detail_form">
                  <fieldset class="form_detail_data_fs"><legend>Detail Data</legend>
                   <div class="tabsDetail">
                    <ul class="tabMain">
                     <li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>">Resource</a></li>
                     <li class="tabLink"><a href="#tabsDetail-2-<?php echo $count ?>">Future</a></li>

                    </ul>
                    <div class="tabContainer">
                     <div id="tabsDetail-1-<?php echo $count ?>" class="tabContent">
                      <table class="form form_detail_data_table detail">
                       <thead>
                        <tr>
                         <th>Action</th>
                         <th>Detail Id</th>
                         <th>Resource Seq</th>
                         <th>Resource</th>
                         <th>Basis</th>
                         <th>Usage</th>
                         <th>Schedule</th>
                         <th>Units</th>
                         <th>24 Hours</th>
                         <th>Rate</th>
                         <th>Charge Type</th>
                        </tr>
                       </thead>
                       <tbody class="form_data_detail_tbody">
                        <?php
                        $detailCount = 0;
                        foreach ($bom_routing_detail_object as $bom_routing_detail) {
                         $class_third = 'bom_routing_detail';
                         $$class_third = &$bom_routing_detail;
                         ?>
                         <tr class="bom_routing_detail<?php echo $count . '-' . $detailCount; ?>">
                          <td>   
                           <ul class="inline_action">
                            <li class="add_row_detail_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                            <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                            <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($bom_routing_detail->bom_routing_detail_id); ?>"></li>           
                            <li><?php echo form::hidden_field('bom_routing_line_id', $bom_routing_line->bom_routing_line_id); ?></li>
                            <li><?php echo form::hidden_field('bom_routing_header_id', $bom_routing_header->bom_routing_header_id); ?></li>
                           </ul>
                          </td>
                          <td><?php form::text_field_wid3sr('bom_routing_detail_id'); ?></td>
                          <td><?php $f->text_field_d3s('resource_sequence', 'detail_number'); ?></td>
                          <td><?php echo form::select_field_from_object('resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_third->resource_id, '', $readonly, 'resource_id', '', 1); ?></td>
                          <td><?php echo form::select_field_from_object('charge_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_third->charge_basis, '', $readonly, 'default_basis', '', 1); ?></td>
                          <td><?php form::number_field_wid3sm('resource_usage') ?></td>
                          <td><?php echo form::select_field_from_object('resource_schedule', bom_header::bom_schedule_option(), 'option_line_code', 'option_line_value', $$class_third->resource_schedule, '', $readonly, '', '', 1); ?></td>
                          <td><?php form::number_field_wid3s('assigned_units') ?></td>
                          <td><?php echo form::checkBox_field('twenty_four_hr_cb', $$class_third->twenty_four_hr_cb); ?></td>
                          <td><?php echo form::checkBox_field('standard_rate_cb', $$class_third->standard_rate_cb); ?></td>
                          <td><?php echo form::select_field_from_object('charge_type', bom_resource::charge_type(), 'option_line_code', 'option_line_value', $$class_third->charge_type, '', $readonly, '', '', 1); ?></td>
                         </tr>
                         <?php
                         $detailCount++;
                        }
                        ?>
                       </tbody>
                      </table>
                     </div>
                     <div id="tabsDetail-2-<?php echo $count ?>" class="tabContent">

                     </div>
                    </div>
                   </div>
                  </fieldset>

                 </div>

                </td></tr>
               <?php
               $count = $count + 1;
              }
             ?>
            </tbody>
           </table>
          </div>
          <div id="tabsLine-2" class="scrollElement tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Seq #</th>
              <th>Description</th>
              <th>Count Point</th>
              <th>Auto Charge</th>
              <th>Back flush</th>
              <th>MTQ</th>
              <th>Lead Time % </th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($bom_routing_line_object as $bom_routing_line) {
               ?>         
               <tr class="bom_routing_line<?php echo $count ?>">
                <td><?php $f->seq_field_d($count) ?></td>
                <td><?php form::text_field_wid2('description'); ?></td>
                <td><?php echo form::checkBox_field('count_point_cb', $$class_second->count_point_cb); ?></td>
                <td><?php echo form::checkBox_field('auto_charge_cb', $$class_second->auto_charge_cb); ?></td>
                <td><?php echo form::checkBox_field('backflush_cb', $$class_second->backflush_cb); ?></td>
                <td><?php form::number_field_wid2s('minimum_transfer_quantity'); ?></td>
                <td><?php form::number_field_wid2s('lead_time_percentage'); ?></td>
               </tr>
               <?php
               $count = $count + 1;
              }
             ?>
            </tbody>
            <!--                  Showing a blank form for new entry-->
           </table>
          </div>
          <div id="tabsLine-3" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Seq #</th>
              <th>Start Date</th>
              <th>End Date</th>
              <th>ECO Implemented</th>
              <th>ECO Number</th>

              <th>Roll up</th>
              <th>Yield</th>
              <th>Cumm. Yield</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($bom_routing_line_object as $bom_routing_line) {
               ?>         
               <tr class="bom_routing_line<?php echo $count ?>">
                <td><?php $f->seq_field_d($count) ?></td>
                <td><?php echo form::date_fieldAnyDay('effective_start_date', $$class_second->effective_start_date); ?></td>
                <td><?php echo form::date_fieldAnyDay('effective_end_date', $$class_second->effective_end_date); ?></td>
                <td><?php echo form::checkBox_field('eco_implemented_cb', $$class_second->eco_implemented_cb, 'eco_implemented_cb', $readonly); ?></td>
                <td><?php form::text_field_wid2('eco_number'); ?></td>

                <td><?php echo form::checkBox_field('include_in_rollup_cb', $$class_second->include_in_rollup_cb); ?></td>
                <td><?php form::number_field_wid2s('yield'); ?></td>
                <td><?php form::number_field_wid2s('cumm_yield'); ?></td>
               </tr>
               <?php
               $count = $count + 1;
              }
             ?>
            </tbody>
            <!--                  Showing a blank form for new entry-->
           </table>
          </div>

          <div id="tabsLine-4" class="tabContent">
           <?php
            $extra_element_label = 'Data Collection Element';
            $class_name_object = $bom_routing_line_object;
            $ef_refer_key = 'bom_routing_line';
            $ef_refer_value = 'bom_routing_line_id';
            $tr_class= 'bom_routing_line';
            include_once 'modules/sys/extra_field/form/add_field_template.php';
           ?>

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

<?php include_template('footer.inc') ?>
