<div id ="form_all"><span class="heading"><?php  echo gettext('Expenditure Type') ?></span>
 <form action=""  method="post" id="prj_expenditure_type"  name="prj_expenditure_type">
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
       <li><?php $f->l_text_field_dr_withSearch('prj_expenditure_type_id') ?>
        <a name="show" href="form.php?class_name=prj_expenditure_type&<?php echo "mode=$mode"; ?>" class="show document_id prj_expenditure_type_id"><i class='fa fa-refresh'></i></a> 
       </li>
       <li><?php $f->l_text_field_d('expenditure_type'); ?></li>
       <li><?php $f->l_select_field_from_object('expenditure_category', prj_expenditure_type::prj_expenditure_category(), 'option_line_code', 'option_line_value', $$class->expenditure_category, 'expenditure_category', '', '', $readonly1); ?>    </li>
       <li><?php $f->l_select_field_from_object('revenue_category', prj_expenditure_type::prj_revenue_category(), 'option_line_code', 'option_line_value', $$class->revenue_category, 'revenue_category', '', '', $readonly1); ?>    </li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_date_fieldAnyDay('effective_from' , $$class->effective_from); ?></li>
       <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li>
       <li><?php $f->l_select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, 'uom_id', 'uom_id', '', $readonly1); ?>         </li>
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
         $reference_table = 'prj_expenditure_type';
         $reference_id = $$class->prj_expenditure_type_id;
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

  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Expenditure Type Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Control Options') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div > 
       <ul class="column header_field"> 
        <li><?php $f->l_checkBox_field_d('inventory_cb'); ?></li> 
        <li><?php $f->l_checkBox_field_d('burden_cb'); ?></li> 
        <li><?php $f->l_checkBox_field_d('expense_reports_cb'); ?></li> 
        <li><?php $f->l_checkBox_field_d('misc_transaction_cb'); ?></li> 
        <li><?php $f->l_checkBox_field_d('over_time_cb'); ?></li> 
        <li><?php $f->l_checkBox_field_d('invoice_cb'); ?></li> 
        <li><?php $f->l_checkBox_field_d('usages_cb'); ?></li> 
        <li><?php $f->l_checkBox_field_d('wip_cb'); ?></li> 
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
  <li class="headerClassName" data-headerClassName="prj_expenditure_type" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_expenditure_type_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_expenditure_type" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_expenditure_type_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_expenditure_type"></li>
 </ul>
</div>