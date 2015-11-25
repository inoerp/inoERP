<div id ="form_header">
 <form  method="post" id="ar_receipt_source"  name="ar_receipt_source">
  <span class="heading"><?php echo gettext('Receipt Source') ?></span>
  <div class="tabContainer">
   <ul class="column header_field"> 
    <li><?php $f->l_text_field_dr_withSearch('ar_receipt_source_id') ?>
     <a name="show" href="form.php?class_name=ar_receipt_source&<?php echo "mode=$mode"; ?>" class="show document_id ar_receipt_source_id">
      <i class='fa fa-refresh'></i></a> 
    </li>
    <li><?php $f->l_text_field_d('receipt_source'); ?></li>
    <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>    </li>
    <li><?php $f->l_select_field_from_object('receipt_type', ar_receipt_header::receipt_types(), 'option_line_code', 'option_line_value', $$class->receipt_type, 'receipt_type', '', 1, $readonly1); ?>    </li>
    <li><?php $f->l_status_field_d('status'); ?></li>
    <li><?php $f->l_text_field_d('description'); ?> 					</li>

   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading">Receipt Source Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Bank Account') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_array('creation_method', ar_receipt_source::$creation_method_a, $$class->creation_method, 'creation_method', '', 1, $readonly1); ?>        </li>
        <li><?php $f->l_select_field_from_array('remittance', ar_receipt_source::$remittance_method_a, $$class->remittance, 'remittance', '', 1, $readonly1); ?>        </li>
        <li><?php $f->l_select_field_from_array('clearance', ar_receipt_source::$clearance_method_a, $$class->clearance, 'clearance', '', 1, $readonly1); ?>        </li>
        <li><?php $f->l_checkBox_field_d('sync_receipt_number_cb'); ?></li>
       </ul> 
      </div> 
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><?php
         echo $f->l_val_field_dm('account_number', 'mdm_bank_account', 'account_number', '', 'account_number', 'vf_select_account_number');
         echo $f->hidden_field_withId('bank_account_id', $$class->bank_account_id);
         ?><i class="generic g_select_bank_account select_popup clickable fa fa-search" data-class_name="mdm_bank_account"></i></li>
        <li><?php $f->l_text_field_d('bank_number'); ?></li> 
        <li><?php $f->l_text_field_dr('branch_number'); ?></li> 
        <li><?php $f->l_text_field_dr('bank_name_short'); ?></li> 
        <li><?php $f->l_text_field_dr('bank_name_alt'); ?></li> 
        <li><?php $f->l_text_field_dr('ifsc_code'); ?></li> 
        <li><?php $f->l_text_field_dr('swift_code'); ?></li> 
        <li><?php $f->l_text_field_dr('routing_number'); ?></li> 
        <li><?php $f->l_text_field_dr('iban_code'); ?></li> 
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
  <li class="headerClassName" data-headerClassName="ar_receipt_source" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="ar_receipt_source_id" ></li>
  <li class="form_header_id" data-form_header_id="ar_receipt_source" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ar_receipt_source_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ar_receipt_source_id" ></li>
 </ul>
</div>