<div id ="form_header">
 <form method="post" id="ar_transaction_source"  name="ar_transaction_source">
  <span class="heading"><?php echo gettext('Receivable Transaction Source') ?></span>
  <div class="tabContainer">
   <ul class="column header_field"> 
    <li><?php $f->l_text_field_dr_withSearch('ar_transaction_source_id') ?>
     <a name="show" href="form.php?class_name=ar_transaction_source&<?php echo "mode=$mode"; ?>" class="show document_id ar_transaction_source_id">
      <i class='fa fa-refresh'> </i></a> 
    </li>
    <li><?php $f->l_text_field_d('transaction_source'); ?> </li>
    <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>					</li>
    <li><?php $f->l_select_field_from_object('legal_org_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->legal_org_id, 'legal_org_id', '', 1, $readonly1); ?>					</li>
    <li><?php $f->l_select_field_from_array('source_type', ar_transaction_source::$source_type_a, $$class->source_type, 'source_type', '', 1, $readonly1); ?>					</li>
    <li><?php $f->l_text_field_d('description'); ?> 					</li>
    <li><?php $f->l_status_field_d('status'); ?></li>
   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading">
    <?php echo gettext('Transaction Source Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Future') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_object('invoice_type_id', ar_transaction_type::find_all(), 'ar_transaction_type_id', 'ar_transaction_type', $$class->invoice_type_id, 'invoice_type_id'); ?>        </li>
        <li><?php $f->l_select_field_from_object('cm_type_id', ar_transaction_type::find_all(), 'ar_transaction_type_id', 'ar_transaction_type', $$class->cm_type_id, 'cm_type_id'); ?>        </li>
        <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'payment_term_id', 1, $readonly1); ?>        </li>
        <li><?php $f->l_checkBox_field_d('create_clearing_cb'); ?></li>
       </ul> 
      </div> 
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div> 

      </div> 
     </div>
    </div>
   </div> 
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="ar_transaction_source" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="ar_transaction_source_id" ></li>
  <li class="form_header_id" data-form_header_id="ar_transaction_source" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ar_transaction_source_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ar_transaction_source_id" ></li>
 </ul>
</div>
