<form method="post" id="mdm_bank_account"  name="mdm_bank_account">
 <div id ="form_header"><span class="heading"><?php echo gettext('Bank Account') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Bank Details') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Org Assignment') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Customer') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Supplier') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-7"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('mdm_bank_account_id'); ?>
       <a name="show" href="form.php?class_name=mdm_bank_account&<?php echo "mode=$mode"; ?>" class="show document_id mdm_bank_account_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><label class="auto_complete"><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="mdm_bank_header_id select_popup clickable">
        <?php echo gettext('Bank Name') ?></label><?php echo $f->hidden_field_withId('mdm_bank_header_id', $$class->mdm_bank_header_id); ?>
       <?php $f->text_field_d('bank_name') ?>	</li>
      <li><label class="auto_complete"><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="mdm_bank_site_id select_popup clickable">
        <?php echo gettext('Branch Name') ?></label><?php echo $f->hidden_field_withId('mdm_bank_site_id', $$class->mdm_bank_site_id); ?>
       <?php $f->text_field_d('branch_name') ?>	</li>
      <li><?php $f->l_text_field_d('account_number') ?>	</li>
      <li><?php $f->l_select_field_from_array('account_usage', mdm_bank_account::$account_usage_a, $$class->account_usage, 'account_usage', '', 1, $readonly1) ?>	</li>
			<li><?php $f->l_select_field_from_object('currency_code', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency_code, 'currency_code', '', 1, $readonly1); ?></li>
      <li><?php $f->l_select_field_from_object('account_type', mdm_bank_account::bank_account_type(), 'option_line_code', 'option_line_value', $$class->account_type, 'account_type', '', 1, $readonly1) ?>	</li>
      <li><?php $f->l_text_field_d('description') ?>	</li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div>
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr('bank_number'); ?></li> 
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
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <ul class="column four_column">
       <li>
        <?php echo $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', '', $readonly1); ?>
       </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php
        echo $f->l_val_field_d('customer_name', 'ar_customer', 'customer_name', '', 'customer_name', 'vf_select_customer_name');
        echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id);
        ?><i class="generic g_select_customer_name select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
       <li><?php
        echo $f->l_val_field_d('customer_number', 'ar_customer', 'customer_number', '', '', 'vf_select_customer_number');
        ?><i class="generic g_select_customer_number select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
       <li><?php $f->l_select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id'); ?> </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php
        echo $f->l_val_field_d('supplier_name', 'supplier', 'supplier_name', '', 'supplier_name', 'vf_select_supplier_name');
        echo $f->hidden_field_withId('supplier_id', $$class->supplier_id);
        ?><i class="generic g_select_supplier_name select_popup clickable fa fa-search" data-class_name="supplier"></i></li>
       <li><?php
        echo $f->l_val_field_d('supplier_number', 'supplier', 'supplier_number', '', '', 'vf_select_supplier_number');
        ?><i class="generic g_select_supplier_number select_popup clickable fa fa-search" data-class_name="supplier"></i></li>
       <li><label><?php echo gettext('Supplier Site') ?></label><?php
        $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
        echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
        ?> </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <?php
      $reference_table = 'mdm_bank_account_id';
      $reference_id = $$class->mdm_bank_account_id;
      include_once HOME_DIR . '/comment.php';
      ?>
      <div id="new_comment">
      </div>
     </div>
    </div>
    <div id="tabsHeader-7" class="tabContent">
     <?php echo ino_attachement($file) ?>
    </div>
   </div>

  </div>
  <span class="heading"><?php echo gettext('Bank Account Details'); ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Receivable'); ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Payable'); ?></a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('HR'); ?></a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Secondary') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div> 
      <ul class="column header_field"> 
       <li><?php $f->l_ac_field_d('cash_ac_id'); ?></li>
       <li><?php $f->l_ac_field_d('cash_clearing_ac_id'); ?></li>
       <li><?php $f->l_ac_field_d('bank_charge_ac_id'); ?></li>
       <li><?php $f->l_ac_field_d('exchange_gl_ac_id'); ?></li>
      </ul> 
     </div> 
     <!--end of tab1 div three_column-->
    </div> 
    <div id="tabsLine-2"  class="tabContent">
     <div> 
      <ul class="column header_field"> 
       <li><?php echo $f->l_checkBox_field_d('netting_ac_cb'); ?></li> 
       <li><?php echo $f->l_text_field_d('minimum_payment'); ?></li>
       <li><?php echo $f->l_text_field_d('maximum_payment'); ?></li>
      </ul>
     </div> 
    </div>
    <div id="tabsLine-3" class="tabContent">
     <div> 
      <ul class="column header_field"> 
       <li><?php $f->l_ac_field_d('hr_cash_ac_id'); ?></li>
       <li><?php $f->l_ac_field_d('hr_cash_clearing_ac_id'); ?></li>
       <li><?php $f->l_ac_field_d('hr_bank_charge_ac_id'); ?></li>
       <li><?php $f->l_ac_field_d('hr_exchange_gl_ac_id'); ?></li>
      </ul> 
     </div> 
     <div id="tabsLine-4" class="tabContent">
      <?php echo!empty($secondary_field_stmt) ? $secondary_field_stmt : null; ?>
     </div>
     <!--end of tab1 div three_column-->
    </div> 
   </div>
  </div> 
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="mdm_bank_account" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="mdm_bank_account_id" ></li>
  <li class="form_header_id" data-form_header_id="mdm_bank_account" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="mdm_bank_account_id" ></li>
  <li class="btn1DivId" data-btn1DivId="mdm_bank_account_id" ></li>
 </ul>
</div>