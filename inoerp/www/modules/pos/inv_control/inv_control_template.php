<div id ="form_header">
 <form action=""  method="post" id="pos_inv_control"  name="pos_inv_control">
  <span class="heading"><?php echo gettext('POS Inventory Control') ?></span>
  <div class="tabContainer">
   <ul class="column header_field"> 
    <?php echo form::hidden_field('pos_inv_control_id', $$class->pos_inv_control_id);    ?>
    <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>
     <a name="show" href="form.php?class_name=pos_inv_control&<?php echo "mode=$mode"; ?>" class="show document_id pos_inv_control_id">
      <i class="fa fa-refresh"></i></a> 
    </li>
   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Heading') ?> </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Future') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_object('transaction_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->transaction_subinventory_id, '', 'subinventory_id', '', $readonly); ?>        </li>
        <li><?php $f->l_select_field_from_object('transaction_locator_id', locator::find_all_of_subinventory($$class->transaction_subinventory_id), 'locator_id', 'locator', $$class->transaction_locator_id, '', 'locator_id', '', $readonly); ?>        </li>
        <li><?php $f->l_select_field_from_object('return_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->return_subinventory_id, '', 'subinventory_id', '', $readonly); ?>        </li>
        <li><?php $f->l_select_field_from_object('return_locator_id', locator::find_all_of_subinventory($$class->transaction_subinventory_id), 'locator_id', 'locator', $$class->return_locator_id, '', 'locator_id', '', $readonly); ?>        </li>
        <li><?php $f->l_checkBox_field_d('allow_negative_onhand_cb') ?>       </li>
        <li><?php $f->l_ac_field_d('cogs_ac_id'); ?></li>
        <li><?php $f->l_select_field_from_object('ar_transaction_type_id', ar_transaction_type::find_all(), 'ar_transaction_type_id', 'ar_transaction_type', $$class->ar_transaction_type_id, 'transaction_type', '', 1) ?>        </li>
        <li><label><?php echo gettext('Item Number') ?></label><?php echo $f->hidden_field_withId('item_id_m', $$class->item_id_m); ?>
         <?php $f->text_field_dm('item_number', 'select_item_number'); ?>
         <i class="select_item_number select_popup clickable fa fa-search"></i>
        </li>
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
  <li class="headerClassName" data-headerClassName="pos_inv_control" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="org_id" ></li>
  <li class="form_header_id" data-form_header_id="pos_inv_control" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="pos_inv_control_id" ></li>
  <li class="btn1DivId" data-btn1DivId="pos_inv_control_id" ></li>
 </ul>
</div>
