<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('HR Control') ?></span>
 <form method="post" id="hr_control"  name="hr_control">
  <div class="tabContainer">
   <ul class="column header_field">
    <?php echo form::hidden_field('hr_control_id', $$class->hr_control_id); ?>
    <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', 'action', 1, $readonly1); ?>
     <a name="show" href="form.php?class_name=hr_control&<?php echo "mode=$mode"; ?>" class="show bu_org_id"><i class="fa fa-refresh"></i></a> 
    </li>
   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Future') ?> </a></li>      
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_object('default_job_id', hr_job::find_all(), 'hr_job_id', 'job_code', $$class->default_job_id, '', 'medium'); ?>        </li>
        <li><?php $f->l_select_field_from_object('default_grade_id', hr_grade::find_all(), 'hr_grade_id', 'grade', $$class->default_grade_id, '', 'medium'); ?>        </li>
        <li><?php $f->l_select_field_from_array('expense_claim_approval', hr_control::$expense_claim_approval_a, $$class->expense_claim_approval, 'expense_claim_approval', '', 1) ?> 						</li>
        <li><?php $f->l_ac_field_d('salary_cash_ac_id'); ?></li> 
        <li><?php $f->l_ac_field_d('expense_claim_ac_id'); ?></li> 
        <li><?php $f->l_ac_field_d('salary_exp_ac_id'); ?></li> 
        <li><?php 
         echo $f->l_val_field_dm('expense_claim_supplier', 'supplier', 'supplier_name', '', 'expense_claim_supplier', 'vf_select_supplier_name');
         echo $f->hidden_field_withId('supplier_id', $$class->supplier_id);
         ?><i class="generic g_select_supplier_name select_popup clickable fa fa-search" data-class_name="supplier"></i></li>
        <li><label><?php echo gettext('Expense Claim Supplier Site') ?></label><?php
         $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
         echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
         ?> </li>
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <!--              end of tab1-->

     <div id="tabsLine-2"  class="tabContent">

     </div>
    </div>

   </div> 
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_control" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="bu_org_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_control" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_control_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_control" ></li>
 </ul>
</div>