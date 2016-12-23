<div id ="form_header">
 <form method="post" id="hr_payroll_payment_method"  name="hr_payroll_payment_method">
  <span class="heading"><?php echo gettext('Payroll Payment Method') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>

    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_dr_withSearch('hr_payroll_payment_method_id') ?>
         <a name="show" href="form.php?class_name=hr_payroll_payment_method&<?php echo "mode=$mode"; ?>" class="show document_id hr_payroll_payment_method_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_text_field_d('payment_method'); ?> 					</li>
        <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', '', 1, $readonly) ?>        </li> 
        <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->currency, 'currency', '', 1, $readonly1); ?>        </li>
        <li><?php $f->l_select_field_from_object('payment_type', hr_payroll_payment_method::payment_method_type(), 'option_line_code', 'option_line_value', $$class->payment_type, 'payment_type', '', 1, $readonly1); ?>        </li>
        <li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date); ?> 	</li>
        <li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date); ?> 	</li>
        <li><?php $f->l_text_field_d('description'); ?> 					</li>
       </ul>
      </div>
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
         $reference_table = 'hr_payroll_payment_method';
         $reference_id = $$class->hr_payroll_payment_method_id;
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
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Accounts') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Bank Details') ?> </a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Costing') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div>            
       <ul class="column four_column"> 
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="mdm_bank_account_id select_popup clickable">
          Bank Account Id</label> <?php $f->text_field_d('bank_account_id') ?>
        </li> 
        <li><?php $f->l_ac_field_d('cash_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('clearing_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('bank_charge_ac_id'); ?></li>
        <li><?php $f->l_ac_field_d('salary_payable_ac_id'); ?></li>
       </ul> 
      </div> 
     </div> 
     <div id="tabsLine-2" class="tabContent">
      <div>            
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_dr('bank_name') ?>	</li>
        <li><?php $f->l_text_field_dr('branch_name') ?> </li>
        <li><?php $f->l_text_field_dr('account_number') ?>	</li>
        <li><?php $f->l_select_field_from_array('account_usage', mdm_bank_account::$account_usage_a, $$class->account_usage, 'account_usage', '', '', 1, 1) ?>	</li>
        <li><?php $f->l_select_field_from_object('account_type', mdm_bank_account::bank_account_type(), 'option_line_code', 'option_line_value', $$class->account_type, 'account_type', '', '', 1) ?>	</li>
        <li><?php $f->l_text_field_dr('account_description') ?>	</li>
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
     <div id="tabsLine-3"  class="tabContent">
      <div>
       <ul class="column header_field"> 
        <li><?php $f->l_checkBox_field_d('costed_cb'); ?></li>
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
  <li class="headerClassName" data-headerClassName="hr_payroll_payment_method" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_payroll_payment_method_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_payroll_payment_method" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_payroll_payment_method_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_payroll_payment_method_id" ></li>
 </ul>
</div>