<form action=""  method="post" id="fa_asset_book"  name="fa_asset_book"><span class="heading">Asset Book </span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Calendar</a></li>
    <li><a href="#tabsHeader-3">Attachments</a></li>
    <li><a href="#tabsHeader-4">Note</a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="fa_asset_book_id select_popup clickable">
         Book Id</label><?php $f->text_field_dsr('fa_asset_book_id') ?>
        <a name="show" href="form.php?class_name=fa_asset_book&<?php echo "mode=$mode"; ?>" class="show document_id fa_asset_book_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>BU Org</label><?php
        echo $f->select_field_from_object('bu_org_id', $org->findAll_business(), 'org_id', 'org', $$class->bu_org_id, 'org_id', '', 1, $readonly1);
        ?></li>
       <li><label>Book Name</label><?php echo $f->text_field_d('asset_book_name'); ?></li>
       <li><label>Description</label><?php echo $f->text_field('description', $$class->description, '20', 'description'); ?></li>
       <li><label>Type</label><?php echo $f->select_field_from_object('type', fa_asset_book::asset_book_type(), 'option_line_code', 'option_line_value', $$class->type, 'type', '', 1); ?></li>
       <li><label>Ledger Id</label><?php echo form::select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, '', $readonly) ?>        </li> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><label>Allow Posting</label><?php echo $f->checkBox_field_d('allow_gl_posting_cb'); ?></li>
      <li><label>FA Calendar</label> <?php echo $f->select_field_from_object('fa_calendar_code', gl_calendar::gl_calendar_names(), 'option_line_code', 'option_line_value', $$class->fa_calendar_code, 'fa_calendar_code','',1); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'fa_asset_book';
       $reference_id = $$class->fa_asset_book_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
     <div> 
     </div>
    </div>
   </div>
  </div>
 </div>

 <div id ="form_line" class="form_line"><span class="heading"> Asset Book Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Class Controls</a></li>
    <li><a href="#tabsLine-2">Natural Accounts</a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column four_column"> 
       <li><label>Revalue Acc. Depreciation : </label><?php echo $f->checkBox_field('revalue_accum_depriciation_cb', $$class->revalue_accum_depriciation_cb); ?></li> 
       <li><label>Ret. Revalue Reservation : </label><?php echo $f->checkBox_field('retire_revaluation_reserve_cb', $$class->retire_revaluation_reserve_cb); ?></li> 
       <li><label>Revalue YTD Depreciation : </label><?php echo $f->checkBox_field('revalue_ytd_depriciation_cb', $$class->revalue_ytd_depriciation_cb); ?></li> 
       <li><label>Revision : </label><?php echo $f->text_field_d('rev_number'); ?></li> 
       <li><label>Status : </label><?php echo $f->text_field_d('status'); ?></li> 
      </ul>
     </div>
    </div> 
    <!--end of tab6 (planning)...start of lead times-->
    <div id="tabsLine-2" class="tabContent">
     <ul class="column three_column">
      <li><label>Default Ac: </label><?php
       $f = new inoform();
       $f->ac_field_d('default_ac_id');
       ?></li>
      <li><label>Sales Proceed Gain: </label>
       <?php echo $f->select_field_from_object('sale_proceeds_gain_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->sale_proceeds_gain_id, 'sale_proceeds_gain_id', 'medium'); ?>
      </li>
      <li><label>Sales Proceed Loss: </label>
       <?php echo $f->select_field_from_object('sale_proceeds_loss_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->sale_proceeds_loss_id, 'sale_proceeds_loss_id', 'medium'); ?>
      </li>
      <li><label>Sales Proceed Clearing: </label>
       <?php echo $f->select_field_from_object('sale_proceeds_clearing_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->sale_proceeds_clearing_id, 'sale_proceeds_clearing_id', 'medium'); ?>
      </li>
      <li><label>Removal Cost Gain: </label>
       <?php echo $f->select_field_from_object('removal_cost_gain_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->removal_cost_gain_id, 'removal_cost_gain_id', 'medium'); ?>
      </li>
      <li><label>Removal Cost Loss: </label>
       <?php echo $f->select_field_from_object('removal_cost_loss_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->removal_cost_loss_id, 'removal_cost_loss_id', 'medium'); ?>
      </li>
      <li><label>Removal Cost Clearing: </label>
       <?php echo $f->select_field_from_object('removal_cost_clearing_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->removal_cost_clearing_id, 'removal_cost_clearing_id', 'medium'); ?>
      </li>
      <li><label>NBV Retired Gain: </label>
       <?php echo $f->select_field_from_object('nbv_retired_gain_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->nbv_retired_gain_id, 'nbv_retired_gain_id', 'medium'); ?>
      </li>
      <li><label>NBV Retired Loss: </label>
       <?php echo $f->select_field_from_object('nbv_retired_loss_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->nbv_retired_loss_id, 'nbv_retired_loss_id', 'medium'); ?>
      </li>
      <li><label>Reval Reserve Retired Gain: </label>
       <?php echo $f->select_field_from_object('reval_reserve_retired_gain_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->reval_reserve_retired_gain_id, 'reval_reserve_retired_gain_id', 'medium'); ?>
      </li>
      <li><label>Reval Reserve Retired Loss: </label>
       <?php echo $f->select_field_from_object('reval_reserve_retired_loss_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->reval_reserve_retired_loss_id, 'reval_reserve_retired_loss_id', 'medium'); ?>
      </li>
      <li><label>NBV Retired Loss: </label>
       <?php echo $f->select_field_from_object('nbv_retired_loss_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->nbv_retired_loss_id, 'nbv_retired_loss_id', 'medium'); ?>
      </li>
      <li><label>NBV Retired Loss: </label>
       <?php echo $f->select_field_from_object('nbv_retired_loss_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->nbv_retired_loss_id, 'nbv_retired_loss_id', 'medium'); ?>
      </li>
      <li><label>Deff. Depreciation Reserve: </label>
       <?php echo $f->select_field_from_object('deff_depriciation_reserve_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->deff_depriciation_reserve_id, 'deff_depriciation_reserve_id', 'medium'); ?>
      </li>
      <li><label>Deff. Depreciation Expense: </label>
       <?php echo $f->select_field_from_object('deff_depriciation_expense_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->deff_depriciation_expense_id, 'deff_depriciation_expense_id', 'medium'); ?>
      </li>
      <li><label>Deff. Depreciation Adjust: </label>
       <?php echo $f->select_field_from_object('deff_depriciation_adjustment_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->deff_depriciation_adjustment_id, 'deff_depriciation_adjustment_id', 'medium'); ?>
      </li>
     </ul>
    </div>
   </div>
  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fa_asset_book" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="fa_asset_book_id" ></li>
  <li class="form_header_id" data-form_header_id="fa_asset_book" ></li>
 </ul>

  <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fa_asset_book_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fa_asset_book" ></li>
 </ul>
</div>