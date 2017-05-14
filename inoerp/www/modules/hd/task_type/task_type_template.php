<div id ="form_all"><span class="heading"><?php echo gettext('Subinventory') ?></span>
 <form action=""  method="post" id="subinventory"  name="subinventory">
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
        <li><?php $f->l_text_field_dr_withSearch('subinventory_id') ?>
         <a name="show" href="form.php?class_name=subinventory&<?php echo "mode=$mode"; ?>" class="show document_id subinventory_id"><i class='fa fa-refresh'></i></a> 
        </li> 
        <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $subinventory->org_id, 'org_id', '', '', $readonly); ?>   </li>
        <li><?php $f->l_select_field_from_object('type', subinventory::subinventory_type(), 'option_line_code', 'option_line_value', $$class->type, 'type', '', '', $readonly); ?>    </li>
        <li><?php $f->l_text_field_d('subinventory'); ?></li>
        <li><?php $f->l_text_field_d('description'); ?></li>
        <li><?php $f->l_status_field_d('status'); ?></li>
        <li><?php $f->l_checkBox_field_d('rev_enabled_cb'); ?></li>
        <li><?php $f->l_text_field_d('rev_number'); ?></li>
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
         $reference_table = 'subinventory';
         $reference_id = $$class->subinventory_id;
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

  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Subinventory Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Accounts') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div > 
       <ul class="column four_column"> 
        <li><?php $f->l_select_field_from_object('locator_control', subinventory::locator_control(), 'option_line_code', 'option_line_code', $$class->locator_control, 'locator_control', $readonly); ?>	         </li>
        <li><?php $f->l_checkBox_field_d('allow_negative_balance_cb'); ?></li> 
        <li><?php $f->l_text_field_d('default_cost_group'); ?></li> 
        <li><?php $f->l_number_field('shipment_pick_priority', $$class->shipment_pick_priority); ?>
        </li>
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div> 
       <ul class="column four_column">
        <li><?php $f->l_ac_field_d('material_ac_id', '', 'A'); ?></li>  
        <li><?php $f->l_ac_field_d('overhead_ac_id', '', 'A'); ?></li> 
        <li><?php $f->l_ac_field_d('material_oh_ac_id', '', 'A'); ?></li> 
        <li><?php $f->l_ac_field_d('resource_ac_id', '', 'A'); ?></li>  
        <li><?php $f->l_ac_field_d('osp_ac_id', '', 'A'); ?></li>  
        <li><?php $f->l_ac_field_d('expense_ac_id', '', 'X'); ?></li>  
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
  <li class="headerClassName" data-headerClassName="subinventory" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="subinventory_id" ></li>
  <li class="form_header_id" data-form_header_id="subinventory" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="subinventory_id" ></li>
  <li class="btn1DivId" data-btn1DivId="subinventory"></li>
      </ul>
      </div>
