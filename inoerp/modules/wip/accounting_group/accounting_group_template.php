<div id ="form_header"><span class="heading">WIP Accounting Group </span>
 <form action=""  method="post" id="wip_accounting_group"  name="wip_accounting_group">
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
       <li><label><img class="wip_accounting_group select_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png">
         Account Group Id</label><?php $f->text_field_dsr('wip_accounting_group_id'); ?>
        <a name="show" href="form.php?class_name=wip_accounting_group&<?php echo "mode=$mode"; ?>" class="show document_id wip_accounting_group_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Organization</label><?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>    </li>
       <li><label>Account Group</label><?php form::text_field_wid('wip_accounting_group'); ?></li>
       <li><label>WO Type (2)</label><?php echo form::select_field_from_object('wo_type', wip_wo_header::wip_wo_type(), 'option_line_id', 'option_line_code', $$class->wo_type, 'wo_type', $readonly, 'wo_type'); ?>    </li>
       <li><label>Status</label><?php echo form::status_field($wip_accounting_group->status, $readonly); ?></li>
       <li><label>Revision</label><?php echo form::revision_enabled_field($wip_accounting_group->rev_enabled, $readonly); ?></li>
       <li><label>Revision No</label><?php echo form::text_field('rev_number', $wip_accounting_group->rev_number, '10', '', '', '', '', $readonly); ?>    </li>
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
        $reference_table = 'wip_accounting_group';
        $reference_id = $$class->wip_accounting_group_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
   </div>

  </div>

  <div id ="form_line" class="form_line"><span class="heading">Accounting Group Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Actual Accounts</a></li>
     <li><a href="#tabsLine-2">Variance Accounts</a></li>
    </ul>
    <div class="tabContainer">

     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column four_column"> 
        <li><label>Material : </label> <?php echo $f->ac_field_d('material_ac_id'); ?></li>
        <li><label>Mat OH : </label> <?php $f->ac_field_d('material_oh_ac_id'); ?></li>
        <li><label>Over Head : </label> <?php echo $f->ac_field_d('overhead_ac_id'); ?></li>
        <li><label>Resource : </label> <?php $f->ac_field_d('resource_ac_id'); ?></li>
        <li><label>OSP : </label> <?php echo $f->ac_field_d('osp_ac_id'); ?></li>
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <!--              end of tab1-->

     <div id="tabsLine-2" class="tabContent">
      <div> 
       <ul class="column four_column">
        <li><label>Material : </label> <?php echo $f->ac_field_d('var_material_ac_id'); ?></li>
        <li><label>Mat OH : </label> <?php $f->ac_field_d('var_material_oh_ac_id'); ?></li>
        <li><label>Over Head : </label> <?php echo $f->ac_field_d('var_overhead_ac_id'); ?></li>
        <li><label>Resource : </label> <?php $f->ac_field_d('var_resource_ac_id'); ?></li>
        <li><label>OSP : </label> <?php echo $f->ac_field_d('var_osp_ac_id'); ?></li>
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
  <li class="headerClassName" data-headerClassName="wip_accounting_group" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="wip_accounting_group_id" ></li>
  <li class="form_header_id" data-form_header_id="wip_accounting_group" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="wip_accounting_group_id" ></li>
  <li class="btn1DivId" data-btn1DivId="wip_accounting_group" ></li>
 </ul>
</div>