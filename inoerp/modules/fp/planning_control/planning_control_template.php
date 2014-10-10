<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="fp_planning_control_divId">
      <div id="form_top">
      </div>
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <div class="show_loading_small"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header"><span class="heading">Planning Control </span>
       <form action=""  method="post" id="fp_planning_control"  name="fp_planning_control">
        <div class="large_shadow_box">
         <ul class="column five_column"> 
          <?php echo form::hidden_field('fp_planning_control_id', $$class->fp_planning_control_id); ?>
          <li><label>Inventory Org :</label>
           <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>
           <a name="show" href="form.php?class_name=fp_planning_control" class="show org_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
          </li>
         </ul>
        </div>
        <div id ="form_line" class="form_line"><span class="heading">Planning Control Details </span>
         <div id="tabsLine">
          <ul class="tabMain">
           <li><a href="#tabsLine-1">Planning Info</a></li>
           <li><a href="#tabsLine-2">Future</a></li>
          </ul>
          <div class="tabContainer"> 
           <div id="tabsLine-1" class="tabContent">
            <div> 
             <ul class="column five_column"> 
              <li><label>Auto Consumption : </label> 	
               <?php echo $f->select_field_from_object('auto_consumed_group_id', fp_forecast_group::find_all(), 'fp_forecast_group_id', 'forecast_group', $$class->auto_consumed_group_id, 'forecast_group_id', '', '', $readonly) ?>  </li>
              <li><label>Forward Days : </label>  <?php $f->text_field_d('auto_consumed_frwd_days') ?> </li>
              <li><label>Backward Days : </label> <?php $f->text_field_d('auto_consumed_backwd_days') ?> </li>
              <li><label>ABC Group: </label> <?php $f->text_field_d('default_abc') ?>   </li>
              <li><label>Net WIP : </label> <?php $f->checkBox_field_d('net_wip_cb', $$class->net_wip_cb ) ?>   </li>
              <li><label>Net Purchasing : </label> <?php $f->checkBox_field_d('net_po_cb', $$class->net_po_cb ) ?>   </li>
             </ul> 
            </div> 
            <!--end of tab1 div three_column-->
           </div> 
           <!--              end of tab1-->

           <div id="tabsLine-2"  class="tabContent">

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
  <li class="headerClassName" data-headerClassName="fp_planning_control" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="fp_planning_control_id" ></li>
  <li class="form_header_id" data-form_header_id="fp_planning_control" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fp_planning_control_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fp_planning_control_id" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>