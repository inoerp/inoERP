<div id ="form_header">
 <span class="heading"><?php echo gettext('Inventory Org Header') ?></span>
 <form action=""  method="post" id="inventory"  name="inventory">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field"> 
      <li><?php $f->l_text_field_dr_withSearch('inventory_id') ?>
       <a name="show" href="form.php?class_name=inventory&<?php echo "mode=$mode"; ?>" class="show document_id inventory_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org', '', '', $readonly); ?>					</li>
      <li><?php $f->l_status_field_d('status'); ?></li>
      <li><?php $f->l_checkBox_field_d('rev_enabled'); ?></li>
      <li><?php $f->l_text_field_d('rev_number'); ?>    </li>
     </ul>
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
        $reference_table = 'inventory';
        $reference_id = $$class->inventory_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
   </div>

  </div>

  <div id ="form_line" class="form_line"><span class="heading">Inventory Org Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Item Attribute') ?> </a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Sourcing') ?> </a></li>
     <li><a href="#tabsLine-4"><?php echo gettext('Costing Details') ?> </a></li>
     <li><a href="#tabsLine-5"><?php echo gettext('Accounts') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div><ul class="column header_field"> 
        <li><?php $f->l_select_field_from_object('type', inventory::inventory_org_types(), 'option_line_code', 'option_line_code', $inventory->type, 'type', '', '', $readonly); ?>        </li> 
        <li><?php $f->l_text_field_d('code'); ?>    </li>
        <li><?php $f->l_checkBox_field_d('item_master_cb'); ?></li>
        <li><?php
         $org = new org();
         $f->l_select_field_from_object('master_org_id', $org->findAll_item_master(), 'org_id', 'org', $inventory->master_org_id, 'master_org_id', '', '', $readonly1);
         ?>
        </li>
        <li><?php $f->l_text_field_d('calendar'); ?>    </li>
        <li><?php $f->l_text_field_d('locator_control'); ?>    </li>
        <li><?php $f->l_checkBox_field_d('allow_negative_balance_cb'); ?></li>
        <li><?php $f->l_select_field_from_object('pos_price_list_header_id', mdm_price_list_header::find_all(), 'mdm_price_list_header_id', 'price_list', $$class->pos_price_list_header_id, 'pos_price_list_header_id'); ?>        </li> 
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <!--              end of tab1-->

     <div id="tabsLine-2"  class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><?php $f->l_checkBox_field_d('item_rev_enabled_cb'); ?></li>
        <li><?php $f->l_text_field_d('rev_start_number'); ?>    </li>
        <li><?php $f->l_select_field_from_array('lot_uniqueness', item::$ls_uniqueness_a, $$class->lot_uniqueness); ?>   </li>
        <li><?php $f->l_select_field_from_array('lot_generation', item::$ls_generation_a, $$class->lot_generation); ?></li> 
        <li><?php $f->l_text_field_d('lot_prefix'); ?></li> 
        <li><?php $f->l_text_field_d('lot_starting_number'); ?></li>
        <li><?php $f->l_select_field_from_array('serial_uniqueness', item::$ls_uniqueness_a, $$class->serial_uniqueness); ?>         </li>
        <li><?php $f->l_select_field_from_array('serial_generation', item::$ls_generation_a, $$class->serial_generation); ?>         </li> 
        <li><?php $f->l_text_field_d('serial_prefix'); ?></li> 
        <li><?php $f->l_text_field_d('serial_starting_number'); ?></li>
       </ul>

      </div> 
      <!--                end of tab2 div three_column-->
     </div>
     <!--end of tab2-->

     <div id="tabsLine-3"  class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><?php $f->l_text_field_d('atp'); ?></li>
        <li><?php $f->l_text_field_d('picking_rule'); ?></li>
       </ul>

      </div> 
      <!--                end of tab2 div three_column-->
     </div>
     <!--end of tab3-->

     <div id="tabsLine-4"  class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><?php $f->l_select_field_from_object('costing_org', org::find_all_inventory(), 'org', 'org', $inventory->costing_org, 'costing_org', '', '', $readonly); ?>        </li>
        <li><?php $f->l_select_field_from_object('costing_method', inventory::costing_methods(), 'option_line_code', 'option_line_code', $inventory->costing_method, 'costing_method','', '', $readonly); ?>        </li>
        <li><?php $f->l_checkBox_field_d('transfer_to_gl_cb'); ?></li>
        <li><?php $f->l_text_field_d('default_cost_group'); ?></li>
        <li><?php $f->l_ac_field_d('material_ac_id', 'A'); ?></li> 
        <li><?php $f->l_ac_field_d('material_oh_ac_id', 'A'); ?></li>
        <li><?php $f->l_ac_field_d('overhead_ac_id', 'A'); ?></li>
        <li><?php $f->l_ac_field_d('resource_ac_id', 'A'); ?></li>
        <li><?php $f->l_ac_field_d('expense_ac_id', 'X'); ?></li> 
        <li><?php $f->l_ac_field_d('costupdate_ac_id', 'X'); ?></li> 
       </ul>
      </div> 
      <!--                end of tab2 div three_column-->
     </div>
     <!--end of tab4-->

     <div id="tabsLine-5"  class="tabContent">
      <div> 
       <ul class="column four_column">
        <li><?php $f->l_ac_field_d('inter_org_receivable_ac_id', 'A'); ?></li>  
        <li><?php $f->l_ac_field_d('inter_org_ppv_ac_id', 'X'); ?></li> 
        
        <li><?php $f->l_ac_field_d('inter_org_payable_ac_id', 'L'); ?></li>  
        <li><?php $f->l_ac_field_d('inter_org_intransit_ac_id', 'A'); ?></li>  
        <li><?php $f->l_ac_field_d('inv_ap_accrual_ac_id', 'L'); ?></li>  
        <li><?php $f->l_ac_field_d('inv_ap_exp_accrual_ac_id', 'L'); ?></li> 
        <li><?php $f->l_ac_field_d('inv_ppv_ac_id', 'X'); ?></li>  
        <li><?php $f->l_ac_field_d('inv_ipv_ac_id', 'X'); ?></li>  
        <li><?php $f->l_ac_field_d('sales_ac_id', 'I'); ?></li>  
        <li><?php $f->l_ac_field_d('cogs_ac_id', 'X'); ?></li>  
        <li><?php $f->l_ac_field_d('deferred_cogs_ac_id', 'A'); ?></li>  
       </ul>
      </div> 
      <!--                end of tab2 div three_column-->
     </div>
     <!--end of tab5-->
    </div>

   </div> 
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="inventory" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="inventory_id" ></li>
  <li class="form_header_id" data-form_header_id="inventory" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="inventory_id" ></li>
  <li class="btn1DivId" data-btn1DivId="inventory" ></li>
 </ul>
</div>