<div id ="fp_forecast_group_divId">
 <form method="post" id="fp_forecast_group"  name="fp_forecast_group">
  <span class="heading"><?php echo gettext('Forecast Group') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_dr_withSearch('fp_forecast_group_id') ?>
         <a name="show" href="form.php?class_name=fp_forecast_group&<?php echo "mode=$mode"; ?>" class="show document_id fp_forecast_group_id">
                    <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>        </li>
        <li><?php $f->l_text_field_d('forecast_group'); ?></li>
        <li><?php $f->l_text_field_d('description'); ?> 					</li>
        <li><?php $f->l_status_field_d('status'); ?>  </li>
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
         $reference_table = 'fp_forecast_group';
         $reference_id = $$class->fp_forecast_group_id;
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

  <div id ="form_line" class="form_line form_header_l"><span class="heading"><?php echo gettext('Forecast Group Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Forecasts') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_object('bucket_type', fp_forecast_header::fp_bucket(), 'option_line_code', 'option_line_value', $$class->bucket_type, 'bucket_type', '', 1, $readonly); ?></li>
        <li><?php $f->l_checkBox_field_d('consume_cb'); ?>  </li>
        <li><?php $f->l_number_field_d('backward_days'); ?> </li>
        <li><?php  $f->l_number_field_d('forward_days', $$class->forward_days); ?> </li>
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