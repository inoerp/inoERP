<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="forecast_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
       echo (!empty($show_message)) ? $show_message : "";
       $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->

      <div id ="form_header"><span class="heading">Forecast  </span>
       <form action=""  method="post" id="forecast_header"  name="forecast_header">
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column five_column">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="forecast_header_id select_popup clickable">
               Forecast Id : </label>
              <?php $f->text_field_dr('fp_forecast_header_id'); ?>
              <a name="show" href="form.php?class_name=fp_forecast_header" class="show fp_forecast_header_id">	
               <img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
             </li>
             <li><label>Inventory Org (1)</label>
              <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>
             </li>
             <li><label>Forecast (2): </label> 	<?php form::text_field_dm('forecast'); ?>  </li>
             <li><label>Forecast Group : </label> 	
              <?php echo $f->select_field_from_object('forecast_group_id', fp_forecast_group::find_all(), 'fp_forecast_group_id', 'forecast_group', $$class->forecast_group_id, 'forecast_group_id', '', '', $readonly) ?>  </li>
             <li><label>Status : </label> <?php echo form::status_field($$class->status, $readonly); ?> </li>
             <li><label>Demand Class: </label> 	<?php $f->text_field_d('demand_class'); ?> </li>
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ar_customer_id select_popup">
               Customer Id : </label>
              <?php echo $f->text_field_dr('ar_customer_id'); ?>
             </li>
             <li><label class="auto_complete">Customer Name : </label>
              <?php echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', '', $readonly); ?></li>
             <li><label>Description: </label> 	<?php $f->text_field_dl('description'); ?>  </li>
            </ul>
           </div>              

          </div>
         </div>

        </div>
       </form>
      </div>

      <div id="form_line" class="form_line"><span class="heading">Forecast Lines </span>
       <form action=""  method="post" id="forecast_line"  name="forecast_line">
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Main</a></li>
          <li><a href="#tabsLine-2">Quantity</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>Seq#</th>
              <th>Line Id</th>
              <th>Item Number</th>
              <th>Description</th>
              <th>UOM</th>
              <th>Bucket</th>
              <th>Start Date</th>
              <th>End Date</th>
              <th>No Of Bucket</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($fp_forecast_line_object as $fp_forecast_line) {
               ?>         
               <tr class="forecast_line<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->fp_forecast_line_id); ?>"></li>           
                  <li><?php echo form::hidden_field('fp_forecast_header_id', $$class->fp_forecast_header_id); ?></li>
                 </ul>
                </td>
                <td><?php $f->seq_field_d($count); ?></td>
                <td><?php form::text_field_wid2sr('fp_forecast_line_id'); ?></td>
                <td><?php echo $f->hidden_field('item_id_m', $$class_second->item_id_m); ?> 
                 <?php form::text_field_wid2('item_number', 'select_item_number'); ?>
                 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup clickable"></td>
                <td><?php form::text_field_wid2r('item_description'); ?></td>
                <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small', '', 1); ?></td>
                <td><?php echo $f->select_field_from_object('bucket_type', fp_forecast_header::fp_bucket(), 'option_line_code', 'option_line_value', $$class_second->bucket_type, '', '', 1, $readonly); ?></td>
                <td><?php echo $f->date_fieldAnyDay('start_date', $$class_second->start_date); ?></td>
                <td><?php echo $f->date_fieldAnyDay('end_date', $$class_second->end_date); ?></td>
                <td><?php $f->text_field_wid2s('no_of_bucket'); ?></td>
               </tr>
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
              <th>Seq#</th>
              <th>Current</th>
              <th>Original</th>
              <th>Total Current</th>
              <th>Total Original</th>
              <th>Consumption Id</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($fp_forecast_line_object as $fp_forecast_line) {
               ?>         
               <tr class="forecast_line<?php echo $count ?>">
                <td><?php $f->seq_field_d($count); ?></td>
                <td><?php echo $f->number_field('current', $$class_second->current); ?></td>
                <td><?php echo $f->number_field('original', $$class_second->original); ?></td>
                <td><?php echo $f->number_field('total_current', $$class_second->total_current); ?></td>
                <td><?php echo $f->number_field('total_original', $$class_second->total_original); ?></td>
                <td><?php $f->text_field_d2('fp_consumption_id'); ?></td>
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

<?php include_template('footer.inc') ?>
