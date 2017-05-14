<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Payable Control') ?></span>
 <form method="post" id="ap_payable_control"  name="ap_payable_control">
  <div class="tabContainer">
   <ul class="column header_field">
    <?php echo form::hidden_field('ap_payable_control_id', $$class->ap_payable_control_id); ?>
    <li><?php $f->l_select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $$class->org_id, 'org_id', 'action', 1, $readonly1); ?>
     <a name="show" href="form.php?class_name=ap_payable_control&<?php echo "mode=$mode"; ?>" class="show org_id"><i class="fa fa-refresh"></i></a> 
    </li>
   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Control Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Payable Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Accounts') ?> </a></li>      
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'medium', 1, $readonly); ?>        </li>
        <li><?php $f->l_select_field_from_array('inv_approval_hierarchy', ap_payable_control::$approval_hierarchy_a, $$class->inv_approval_hierarchy) ?> 						</li>
        <li><?php $f->l_select_field_from_array('payment_approval_hierarchy', ap_payable_control::$approval_hierarchy_a, $$class->payment_approval_hierarchy) ?> 						</li>
        <li><?php $f->l_select_field_from_object('expense_pay_group', option_header::find_options_byName('AP_PAY_GROUP'), 'option_line_code', 'option_line_value', $$class->expense_pay_group, '', 'medium', '', $readonly); ?>        </li>
        <li><?php $f->l_text_field_d('expense_template_id'); ?></li> 
        <li><?php $f->l_select_field_from_array('expense_payment_priority', dbObject::$position_array, $$class->expense_payment_priority); ?></li>
        <li><?php $f->l_address_field_d('ship_to_id') ?> </li>
        <li><?php $f->l_address_field_d('bill_to_id') ?> </li>
       </ul> 
      </div> 
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_ac_field_d('tax_ac_id'); ?></li> 
       <li><?php $f->l_ac_field_d('liability_ac_id'); ?></li> 
       <li><?php $f->l_ac_field_d('pre_payment_ac_id'); ?></li> 
       <li><?php $f->l_ac_field_d('discount_ac_id'); ?></li> 
       <li><?php $f->l_ac_field_d('rate_gain_ac_id'); ?></li> 
       <li><?php $f->l_ac_field_d('rate_loss_ac_id'); ?></li> 
      </ul>
     </div>
    </div>

   </div> 
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="ap_payable_control" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="org_id" ></li>
  <li class="form_header_id" data-form_header_id="ap_payable_control" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ap_payable_control_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ap_payable_control" ></li>
 </ul>
</div>