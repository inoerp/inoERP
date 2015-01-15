<div id ="form_all"><span class="heading">Sub Inventory </span>
 <form action=""  method="post" id="subinventory"  name="subinventory">
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic Info</a></li>
     <li><a href="#tabsHeader-2">Attachments</a></li>
     <li><a href="#tabsHeader-3">Notes</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="subinventory_id select_popup clickable">
          Sub Inventory Id</label><?php $f->text_field_dsr('subinventory_id') ?>
         <a name="show" href="form.php?class_name=subinventory&<?php echo "mode=$mode"; ?>" class="show document_id subinventory_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li> 
        <li><label>Organization</label><?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $subinventory->org_id, 'org_id', $readonly); ?>   </li>
        <li><label>Type</label><?php echo form::select_field_from_object('type', subinventory::subinventory_type(), 'option_line_code', 'option_line_value', $$class->type, 'type', $readonly); ?>    </li>
        <li><label>Sub Inventory</label><?php form::text_field_wid('subinventory'); ?></li>
        <li><label>Description</label><?php form::text_field_wid('description'); ?></li>
        <li><label>Status</label><?php echo form::status_field($subinventory->status, $readonly); ?></li>
        <li><label>Revision</label><?php echo form::revision_enabled_field($subinventory->rev_enabled_cb, $readonly); ?></li>
        <li><label>Revision No</label><?php echo form::text_field('rev_number', $subinventory->rev_number, '10', '', '', '', '', $readonly); ?></li>
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

  <div id ="form_line" class="form_line"><span class="heading">Subinventory Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Basic Info</a></li>
     <li><a href="#tabsLine-2">Accounts</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div > 
       <ul class="column four_column"> 
        <li><label>Locator Control : </label>
         <?php echo form::select_field_from_object('locator_control', subinventory::locator_control(), 'option_line_code', 'option_line_code', $$class->locator_control, 'locator_control', $readonly); ?>	 
        </li>
        <li><label>Allow Negative Balance : </label>
         <?php echo form::checkBox_field_d('allow_negative_balance_cb'); ?>
        </li> 
        <li><label>Cost Group : </label>
         <?php form::text_field_wid('default_cost_group'); ?>
        </li> 
        <li><label>Shipment Picking Priority : </label>
         <?php echo form::number_field('shipment_pick_priority', $$class->shipment_pick_priority); ?>
        </li>
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div> 
       <ul class="column four_column">
        <li><label>Material Ac: </label><?php $f->ac_field_d('material_ac_id'); ?></li>  
        <li><label>Over Head Ac: </label><?php $f->ac_field_d('overhead_ac_id'); ?></li> 
        <li><label>Material OH Ac: </label><?php $f->ac_field_d('material_oh_ac_id'); ?></li> 
        <li><label>Resource Ac : </label><?php $f->ac_field_d('resource_ac_id'); ?></li>  
        <li><label>OSP Ac : </label><?php $f->ac_field_d('osp_ac_id'); ?></li>  
        <li><label>Expense Ac : </label><?php $f->ac_field_d('expense_ac_id'); ?></li>  
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
  <li class="btn1DivId" data-btn1DivId="subinventory ></li>
 </ul>
</div>