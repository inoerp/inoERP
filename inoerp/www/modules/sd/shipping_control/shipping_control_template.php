<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Shipping Control') ?></span>
 <form method="post" id="sd_shipping_control"  name="sd_shipping_control">
  <div class="tabContainer">
   <ul class="column header_field">
    <?php echo form::hidden_field('sd_shipping_control_id', $$class->sd_shipping_control_id); ?>
    <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', 'action', 1, $readonly1); ?>
     <a name="show" href="form.php?class_name=sd_shipping_control&<?php echo "mode=$mode"; ?>" class="show document_id sd_shipping_control_id">
      <i class="fa fa-refresh"></i></a> 
    </li>
    <li><?php $f->l_checkBox_field_d('rev_enabled'); ?></li>
    <li><?php $f->l_text_field_d('rev_number'); ?> </li>
   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Details') ?> </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Shipping Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Future') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_object('staging_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->staging_subinventory_id, '', 'subinventory_id', '', $readonly); ?>        </li>
        <li><?php $f->l_select_field_from_object('staging_locator_id', locator::find_all_of_subinventory($$class->staging_subinventory_id), 'locator_id', 'locator', $$class->staging_locator_id, '', 'locator_id', '', $readonly); ?>        </li>
        <li><?php $f->l_text_field_d('default_picking_rule_id') ?></li>
        <li><?php $f->l_checkBox_field_d('delivery_onpicking_cb') ?> </li>
        <li><?php $f->l_checkBox_field_d('autosplit_onpicking_cb') ?></li>
        <li><?php $f->l_checkBox_field_d('deffer_invoicing_cb') ?> </li>
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
  <li class="headerClassName" data-headerClassName="sd_shipping_control" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="org_id" ></li>
  <li class="form_header_id" data-form_header_id="sd_shipping_control" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sd_shipping_control_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sd_shipping_control_id" ></li>
 </ul>
</div>