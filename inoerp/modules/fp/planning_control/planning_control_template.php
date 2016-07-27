<div id="fp_planning_control_divId">
 <span class="heading"><?php echo gettext('Planning Control Header') ?></span>
 <form method="post" id="fp_planning_control"  name="fp_planning_control">
  <div class="tabContainer">
   <ul class="column header_field">
    <?php echo form::hidden_field('fp_planning_control_id', $$class->fp_planning_control_id); ?>
    <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', 'action medium', 1, $readonly1); ?>
     <a name="show" href="form.php?class_name=fp_planning_control&<?php echo "mode=$mode"; ?>" class="show document_id fp_planning_control_id">
      <i class="fa fa-refresh"></i></a> 
    </li>
   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Planning Control Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Planning Info') ?></a></li>
     
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field two_column_form form_header_l"> 
        <li><?php $f->l_select_field_from_object('auto_consumed_group_id', fp_forecast_group::find_all(), 'fp_forecast_group_id', 'forecast_group', $$class->auto_consumed_group_id, 'forecast_group_id', '', '', $readonly) ?>  </li>
        <li><?php $f->l_number_field_d('auto_consumed_frwd_days') ?> </li>
        <li><?php $f->l_number_field_d('auto_consumed_backwd_days') ?> </li>
        <li><?php $f->l_text_field_d('default_abc') ?>   </li>
        <li><?php $f->l_checkBox_field_d('net_wip_cb') ?>   </li>
        <li><?php $f->l_checkBox_field_d('net_po_cb') ?>   </li>
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 

    </div>

   </div> 
  </div> 
 </form>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fp_planning_control" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="org_id" ></li>
  <li class="form_header_id" data-form_header_id="fp_planning_control" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fp_planning_control_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fp_planning_control_id" ></li>
 </ul>
</div>
