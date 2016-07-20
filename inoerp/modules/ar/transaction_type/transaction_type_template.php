<div id ="form_header">
 <form  method="post" id="ar_transaction_type"  name="ar_transaction_type">
  <span class="heading"><?php echo gettext('AR Transaction Type') ?></span>
  <div class="tabContainer">
   <ul class="column header_field"> 
    <li><?php $f->l_text_field_dr_withSearch('ar_transaction_type_id') ?>
     <a name="show" href="form.php?class_name=ar_transaction_type&<?php echo "mode=$mode"; ?>" class="show document_id ar_transaction_type_id">
      <i class='fa fa-refresh'></i></a></li>
    <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>					 </li>
    <li><?php $f->l_select_field_from_object('legal_org_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->legal_org_id, 'legal_org_id', '', '', $readonly1, 1); ?>					</li>
    <li><?php $f->l_select_field_from_object('transaction_class', ar_transaction_header::transaction_class(), 'option_line_code', 'option_line_value', $$class->transaction_class, 'transaction_class', '', 1, $readonly1); ?>					</li>
    <li><?php $f->l_text_field_d('ar_transaction_type'); ?></li>
    <li><?php $f->l_text_field_d('description'); ?> 					</li>
    <li><?php $f->l_status_field_d('status'); ?></li>
   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Transaction Type Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Finance') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_object('invoice_type_id', ar_transaction_type::find_all(), 'ar_transaction_type_id', 'ar_transaction_type', $$class->invoice_type_id, 'invoice_type_id'); ?>        </li>
        <li><?php $f->l_select_field_from_object('cm_type_id', ar_transaction_type::find_all(), 'ar_transaction_type_id', 'ar_transaction_type', $$class->cm_type_id, 'cm_type_id'); ?>        </li>
        <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'payment_term_id', 1, $readonly1); ?>        </li>
        <li><?php $f->l_select_field_from_object('ar_revenue_rule_header_id', ar_revenue_rule_header::find_all(), 'ar_revenue_rule_header_id', 'rule_name', $$class->ar_revenue_rule_header_id, 'ar_revenue_rule_header_id'); ?>        </li>
        <li><?php $f->l_select_field_from_array('receivable_rule', ar_transaction_header::$receivable_rule_a, $$class->receivable_rule, 'receivable_rule'); ?>        </li>

       </ul> 
      </div> 
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_ac_field_dm('receivable_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('revenue_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('tax_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('freight_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('clearing_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('unbilled_receivable_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('unearned_revenue_ac_id'); ?></li>
        
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
  <li class="headerClassName" data-headerClassName="ar_transaction_type" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="ar_transaction_type_id" ></li>
  <li class="form_header_id" data-form_header_id="ar_transaction_type" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ar_transaction_type_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ar_transaction_type_id" ></li>
 </ul>
</div>