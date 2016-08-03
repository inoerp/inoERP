<div id ="fp_kanban_planner_header_divId">
 <form  method="post" id="fp_kanban_planner_header"  name="fp_kanban_planner_header">
  <span class="heading"><?php echo gettext('Kanban Planner') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field two_column_form"> 
        <li><?php $f->l_text_field_dr_withSearch('fp_kanban_planner_header_id'); ?>
         <a name="show" href="form.php?class_name=fp_kanban_planner_header&<?php echo "mode=$mode"; ?>" class="show document_id fp_kanban_planner_header_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>    </li>
        <li><?php $f->l_text_field_dm('plan_name'); ?></li>
        <li><?php $f->l_number_field('planning_horizon_days', $$class->planning_horizon_days); ?>    </li>
        <li><?php $f->l_number_field('size_roundup', $$class->size_roundup); ?>    </li>
        <li><?php $f->l_text_field_d('description'); ?></li>
        <li><?php $f->l_select_field_from_object('demand_source', fp_forecast_header::find_all(), 'fp_forecast_header_id', 'forecast', $$class->demand_source, '', '', 1, $readonly); ?>     </label>
        <li><?php $f->l_status_field_d('status'); ?>    </li>
       </ul>
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
  <li class="headerClassName" data-headerClassName="fp_kanban_planner_header" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="fp_kanban_planner_header_id" ></li>
  <li class="form_header_id" data-form_header_id="fp_kanban_planner_header" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fp_kanban_planner_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fp_kanban_planner_header" ></li>
 </ul>
</div>