<div id ="form_header">
 <form  method="post" id="ap_payment_process"  name="ap_payment_process">
  <span class="heading"><?php echo gettext('Payment Process') ?></span>
  <div class="tabContainer">
   <ul class="column header_field"> 
    <li><?php $f->l_text_field_dr_withSearch('ap_payment_process_id') ?>
     <a name="show" href="form.php?class_name=ap_payment_process&<?php echo "mode=$mode"; ?>" class="show document_id ap_payment_process_id">
      <i class='fa fa-refresh'></i></a> 
    </li>
    <li><?php $f->l_text_field_dm('payment_process'); ?></li>
    <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>    </li>
    <li><?php $f->l_select_field_from_object('payment_type', ar_receipt_header::receipt_types(), 'option_line_code', 'option_line_value', $$class->payment_type, 'receipt_type', '', 1, $readonly1); ?>    </li>
    <li><?php $f->l_status_field_d('status'); ?></li>
    <li><?php $f->l_text_field_d('description'); ?> 					</li>

   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Payment Source Details') ?> </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Bank Account') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_d('format_class_name'); ?>        </li>
        <li><?php $f->l_text_field_d('format_method_name'); ?>        </li>
        <li><?php $f->l_ac_field_dm('cash_ac_id'); ?>        </li>
        <li><?php $f->l_checkBox_field_d('sync_payment_number_cb'); ?></li>
				<li><?php $f->l_select_field_from_array('clearing_method', ap_payment_process::$clearing_method_a, $$class->clearing_method, 'clearing_method'); ?>        </li>
       </ul> 
      </div> 
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><?php
         echo $f->l_val_field_dm('account_number', 'mdm_bank_account', 'account_number', '', 'account_number', 'vf_select_account_number');
         echo $f->hidden_field_withId('mdm_bank_account_id', $$class->mdm_bank_account_id);
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
  <li class="headerClassName" data-headerClassName="ap_payment_process" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="ap_payment_process_id" ></li>
  <li class="form_header_id" data-form_header_id="ap_payment_process" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ap_payment_process_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ap_payment_process_id" ></li>
 </ul>
</div>