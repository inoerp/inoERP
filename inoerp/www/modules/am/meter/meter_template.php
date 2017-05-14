<div id ="form_all"><span class="heading"><?php echo gettext('Meter') ?></span>
 <form method="post" id="am_meter"  name="am_meter">
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_dr_withSearch('am_meter_id') ?>
         <a name="show" href="form.php?class_name=am_meter&<?php echo "mode=$mode"; ?>" class="show document_id am_meter_id">
          <i class='fa fa-refresh'></i></a> 
        </li> 
        <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $am_meter->org_id, 'org_id', '', 1, $readonly); ?>   </li>
        <li><?php $f->l_select_field_from_array('type', am_meter::$type_a, $$class->type, 'type', '', 1, $readonly1); ?>    </li>
        <li><?php $f->l_text_field_d('name'); ?></li>
        <li><?php $f->l_text_field_d('description'); ?></li>
        <li><?php $f->l_select_field_from_array('value_change', am_meter::$value_change_a, $$class->value_change, 'value_change', '', 1, $readonly1); ?>    </li>
        <li><?php $f->l_select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, 'uom_id', '', 1, $readonly1); ?></li>
        <li><?php $f->l_date_fieldAnyDay('from_date', $$class->from_date); ?></li>
        <li><?php $f->l_date_fieldAnyDay('to_date', $$class->to_date); ?></li>
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
         $reference_table = 'am_meter';
         $reference_id = $$class->am_meter_id;
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

  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Meter Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Readings') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div > 
       <ul class="column header_field form_header_l"> 
        <li><?php $f->l_number_field('initial_reading', $$class->initial_reading); ?></li>
        <li><?php $f->l_date_fieldAnyDay('initial_reading_date', $$class->initial_reading_date); ?></li>
        <li><?php $f->l_number_field('rate_per_day', $$class->rate_per_day,'','','',1); ?></li>
        <li><?php $f->l_number_field('no_of_past_readings', $$class->no_of_past_readings,'','','',1); ?></li>
        </li>
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
  <li class="headerClassName" data-headerClassName="am_meter" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="am_meter_id" ></li>
  <li class="form_header_id" data-form_header_id="am_meter" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="am_meter_id" ></li>
  <li class="btn1DivId" data-btn1DivId="am_meter" ></li>
 </ul>
</div>