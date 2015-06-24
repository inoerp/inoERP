<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="fp_forecast_group_divId">

      <?php        echo (!empty($show_message)) ? $show_message : "";  ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <form action=""  method="post" id="fp_forecast_group"  name="fp_forecast_group"><span class="heading">Forecast Group </span>
        <div class="large_shadow_box tabContainer">
         <ul class="column four_column"> 
          <li> <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="fp_forecast_group_id select_popup clickable">
            Group Id : </label><?php $f->text_field_dr('fp_forecast_group_id') ?>
           <a name="show" href="form.php?class_name=fp_forecast_group" class="show fp_forecast_group_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
          </li>
          <li><label>Inventory Org (1)</label>
           <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>
          </li>
          <li><label>Group Name :</label><?php $f->text_field_d('forecast_group'); ?></li>
          <li><label>Description :</label><?php $f->text_field_d('description'); ?> 					</li>
          <li><label>Status : </label><?php echo form::status_field($$class->status, $readonly); ?>  </li>
         </ul>
        </div>
        <div id ="form_line" class="form_line"><span class="heading">Forecast Group Details </span>
         <div id="tabsLine">
          <ul class="tabMain">
           <li><a href="#tabsLine-1">Basic Info</a></li>
           <li><a href="#tabsLine-2">Forecasts</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsLine-1" class="tabContent">
            <div> 
             <ul class="column four_column"> 
              <li><label>Bucket Type: </label>
               <?php echo $f->select_field_from_object('bucket_type', fp_forecast_header::fp_bucket(), 'option_line_code', 'option_line_value', $$class->bucket_type, '', '', 1, $readonly); ?></li>
              <li><label>Auto Consume :</label><?php echo $f->checkBox_field('consume_cb', $$class->consume_cb); ?>  </li>
              <li><label>Backward Days :</label><?php echo $f->number_field('forward_days', $$class->forward_days); ?> </li>
              <li><label>Forward Days :</label><?php echo $f->number_field('forward_days', $$class->forward_days); ?> </li>
             </ul> 
            </div> 
           </div> 
           <div id="tabsLine-2"  class="tabContent">
            <div> 
             <ul class="column five_column">

             </ul>
            </div> 
           </div>
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
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fp_forecast_group" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="fp_forecast_group_id" ></li>
  <li class="form_header_id" data-form_header_id="fp_forecast_group" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fp_forecast_group_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fp_forecast_group_id" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>