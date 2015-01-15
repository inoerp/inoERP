<div id ="fp_minmax_header_divId">
 <form action=""  method="post" id="fp_minmax_header"  name="fp_minmax_header"><span class="heading">Min Max Planner </span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic Info</a></li>
     <li><a href="#tabsHeader-2">Attachments</a></li>
     <li><a href="#tabsHeader-3">Notes</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
         <ul class="column header_field"> 
    <li><label><img class="fp_minmax_header select_popup clickable" src="<?php echo HOME_URL; ?>themes/images/serach.png">
      MinMax Plan Id</label><?php echo $f->text_field_dr('fp_minmax_header_id'); ?>
      <a name="show" href="form.php?class_name=fp_minmax_header&<?php echo "mode=$mode"; ?>" class="show document_id fp_minmax_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
    </li>
    <li><label>Inventory Org (1)</label><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>    </li>
    <li><label>Plan Name (2)</label><?php $f->text_field_dm('plan_name'); ?></li>
    <li><label>Planning Horizon(Days)</label><?php echo $f->number_field('planning_horizon_days', $$class->planning_horizon_days); ?>    </li>
    <li><label>Description</label><?php $f->text_field_d('description'); ?></li>
    <li><label>Demand Source</label><?php echo $f->select_field_from_object('demand_source', fp_forecast_header::find_all(), 'fp_forecast_header_id', 'forecast', $$class->demand_source, '', '', 1, $readonly); ?>     </label>
    <li><label>Status</label><?php echo form::status_field($$class->status, $readonly); ?>    </li>
   </ul>
      </div>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'org';
         $reference_id = $$class->org_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
    </div>

   </div>
  </div>
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fp_minmax_header" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="fp_minmax_header_id" ></li>
  <li class="form_header_id" data-form_header_id="fp_minmax_header" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fp_minmax_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fp_minmax_header" ></li>
 </ul>
</div>