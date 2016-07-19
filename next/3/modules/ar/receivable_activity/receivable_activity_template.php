<div id ="form_header">
 <form  method="post" id="ar_receivable_activity"  name="ar_receivable_activity">

  <span class="heading"><?php
   echo gettext('Receivable Activity')
   ?></span>

  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field"> 
      <li><?php $f->l_text_field_dr_withSearch('ar_receivable_activity_id') ?>
       <a name="show" href="form.php?class_name=ar_receivable_activity&<?php echo "mode=$mode"; ?>" class="show document_id ar_receivable_activity_id">
        <i class='fa fa-refresh'></i></a> 
      </li>
      <li><?php $f->l_text_field_d('activity_name'); ?></li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>    </li>
      <li><?php $f->l_select_field_from_array('activity_type', ar_receivable_activity::AR_ACTIVITY_TYPE_A, $$class->activity_type); ?>    </li>
      <li><?php $f->l_checkBox_field_d('active_cb'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?> 					</li>

     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'ar_receivable_activity_id';
       $reference_id = $$class->ar_receivable_activity_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>

  </div>

  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Activity Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basics') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div class="first_rowset"> 
       <ul class="column header_field two_column_form"> 
        <li><?php $f->l_select_field_from_array('account_source', ar_receivable_activity::AR_ACCOUNT_SOURCE_A, $$class->account_source); ?>    </li>
        <li><?php $f->l_text_field_d('tax_code_source'); ?></li>
        <li><?php $f->l_select_field_from_object('tax_code_id', mdm_tax_code::find_all_outTax_by_bu_org_id($$class->bu_org_id), 'mdm_tax_code_id', 'tax_code', $$class->tax_code_id, '', 'output_tax medium', '', $readonly, '', '', '', 'percentage') ?></li>
        <li><?php $f->l_ac_field_d('activity_ac_id'); ?></li>
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
  <li class="headerClassName" data-headerClassName="ar_receivable_activity" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="ar_receivable_activity_id" ></li>
  <li class="form_header_id" data-form_header_id="ar_receivable_activity" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ar_receivable_activity_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ar_receivable_activity_id" ></li>
 </ul>
</div>