<div id ="form_all"><span class="heading"><?php echo gettext('Budget Entry Method') ?></span>
 <form  method="post" id="prj_bem"  name="prj_bem">
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
       <li><?php $f->l_text_field_dr_withSearch('prj_bem_id') ?>
        <a name="show" href="form.php?class_name=prj_bem&<?php echo "mode=$mode"; ?>" class="show document_id prj_bem_id"><i class='fa fa-refresh'></i></a> 
       </li>
       <li><?php $f->l_text_field_d('bem'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></li>
       <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li>
       <li><?php $f->l_select_field_from_array('budget_entry_level', prj_bem::$budget_entry_level_a, $$class->budget_entry_level, 'budget_entry_level'); ?></li>
       <li><?php $f->l_select_field_from_array('time_phased_by', prj_bem::$time_phased_by_a, $$class->time_phased_by, 'time_phased_by'); ?></li>
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
         $reference_table = 'prj_bem';
         $reference_id = $$class->prj_bem_id;
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

  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Cost & Revenue') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Controls') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div class='col-md-3'>
       <span class='heading bg-primary text-muted'><?php echo gettext('Revenue Controls') ?></span>
       <ul class="column header_field"> 
        <li><?php $f->l_checkBox_field_d('revenue_cb'); ?></li> 
        <li><?php $f->l_checkBox_field_d('quantity_revenue_cb'); ?></li> 
       </ul>
      </div>
      <div class='col-md-9'>
       <span class='heading bg-primary'><?php echo gettext('Cost Controls') ?></span>
       <ul class="column header_field"> 
        <li><?php $f->l_checkBox_field_d('quantity_cost_cb'); ?></li> 
        <li><?php $f->l_checkBox_field_d('raw_cost_cb'); ?></li> 
        <li><?php $f->l_checkBox_field_d('burdened_cost_cb'); ?></li> 
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <!--end of tab5-->
    </div>

   </div> 
  </div> 
 </form>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="prj_bem" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_bem_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_bem" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_bem_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_bem"></li>
 </ul>
</div>