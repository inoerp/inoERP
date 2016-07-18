<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Purchasing Control') ?></span>
 <form  method="post" id="po_purchasing_control"  name="po_purchasing_control">
  <div class="tabContainer">
   <ul class="column header_field">
    <?php echo form::hidden_field('po_purchasing_control_id', $$class->po_purchasing_control_id); ?>
    <li><?php $f->l_select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $$class->org_id, 'org_id', 'action', 1, $readonly1); ?>
     <a name="show" href="form.php?class_name=po_purchasing_control&<?php echo "mode=$mode"; ?>" class="show org_id"><i class="fa fa-refresh"></i></a> 
    </li>
    <li><?php $f->l_checkBox_field_d('rev_enabled'); ?></li>
    <li><?php $f->l_text_field_d('rev_number'); ?> </li>
   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Purchasing Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Address') ?> </a></li>      
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'medium', 1, $readonly); ?>        </li>
        <li><?php $f->l_select_field_from_array('po_approval_hierarchy', po_purchasing_control::$approval_hierarchy_a, $$class->po_approval_hierarchy) ?> 						</li>
        <li><?php $f->l_select_field_from_array('req_approval_hierarchy', po_purchasing_control::$approval_hierarchy_a, $$class->req_approval_hierarchy) ?> 						</li>
        <li><?php $f->l_ac_field_d('tax_ac_id'); ?></li> 
        <li><?php $f->l_select_field_from_object('default_inv_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->default_inv_org_id, 'default_inv_org_id', '', 1, $readonly); ?> </li>
        <li><?php $f->l_select_field_from_object('default_line_type', po_line::po_line_types(), 'option_line_code', 'option_line_value', $$class->default_line_type, 'default_line_type', 'copyValue', 1, $readonly); ?></li>
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <!--              end of tab1-->

     <div id="tabsLine-2" class="tabContent">
      <div class="shipto_address"><?php $f->address_field_d('ship_to_id'); ?></div>
      <div class="billto_address"><?php $f->address_field_d('bill_to_id'); ?></div>
     </div>
    </div>

   </div> 
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="po_purchasing_control" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="org_id" ></li>
  <li class="form_header_id" data-form_header_id="po_purchasing_control" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="po_purchasing_control_id" ></li>
  <li class="btn1DivId" data-btn1DivId="po_purchasing_control" ></li>
 </ul>
</div>