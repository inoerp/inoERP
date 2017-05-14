<form  method="post" id="fa_asset_book"  name="fa_asset_book">
 <span class="heading"><?php echo gettext('Asset Book') ?></span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Tracking Info') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('fa_asset_book_id') ?>
        <a name="show" href="form.php?class_name=fa_asset_book&<?php echo "mode=$mode"; ?>" class="show document_id fa_asset_book_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('bu_org_id', $org->findAll_business(), 'org_id', 'org', $$class->bu_org_id, 'org_id', '', 1, $readonly1); ?></li>
       <li><?php $f->l_text_field_d('asset_book_name'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_select_field_from_object('type', fa_asset_book::asset_book_type(), 'option_line_code', 'option_line_value', $$class->type, 'type', '', 1); ?></li>
       <li><?php $f->select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, '', '', '', $readonly) ?>        </li>
       <li><?php $f->l_checkBox_field_d('allow_gl_posting_cb'); ?></li>
      </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
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

 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Asset Book Details') ?> </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Class Controls') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Natural Accounts') ?> </a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field form_header_l two_column_form"> 
       <li><?php $f->l_checkBox_field_d('revalue_accum_depriciation_cb'); ?></li> 
       <li><?php $f->l_checkBox_field_d('retire_revaluation_reserve_cb'); ?></li> 
       <li><?php $f->l_checkBox_field_d('revalue_ytd_depriciation_cb'); ?></li> 
       <li><?php $f->l_text_field_d('rev_number'); ?></li> 
       <li><?php $f->l_status_field_d('status'); ?></li> 
      </ul>
     </div>
    </div> 
    <!--end of tab6 (planning)...start of lead times-->
    <div id="tabsLine-2" class="tabContent">
     <ul class="column header_field form_header_l two_column_form">
      <li><?php $f->l_ac_field_d('default_ac_id');   ?></li>
      <li><?php $f->l_select_field_from_object('sale_proceeds_gain_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->sale_proceeds_gain_id, 'sale_proceeds_gain_id', 'medium'); ?> </li>
      <li><?php $f->l_select_field_from_object('sale_proceeds_loss_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->sale_proceeds_loss_id, 'sale_proceeds_loss_id', 'medium'); ?>      </li>
      <li><?php $f->l_select_field_from_object('sale_proceeds_clearing_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->sale_proceeds_clearing_id, 'sale_proceeds_clearing_id', 'medium'); ?>      </li>
      <li><?php $f->l_select_field_from_object('removal_cost_gain_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->removal_cost_gain_id, 'removal_cost_gain_id', 'medium'); ?>      </li>
      <li><?php $f->l_select_field_from_object('removal_cost_loss_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->removal_cost_loss_id, 'removal_cost_loss_id', 'medium'); ?>      </li>      
      <li><?php $f->l_select_field_from_object('removal_cost_clearing_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->removal_cost_clearing_id, 'removal_cost_clearing_id', 'medium'); ?>      </li>
      <li><?php $f->l_select_field_from_object('nbv_retired_gain_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->nbv_retired_gain_id, 'nbv_retired_gain_id', 'medium'); ?>      </li>
      <li><?php $f->l_select_field_from_object('nbv_retired_loss_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->nbv_retired_loss_id, 'nbv_retired_loss_id', 'medium'); ?>      </li>
      <li><?php $f->l_select_field_from_object('reval_reserve_retired_gain_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->reval_reserve_retired_gain_id, 'reval_reserve_retired_gain_id', 'medium'); ?>      </li>
      <li><?php $f->l_select_field_from_object('reval_reserve_retired_loss_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->reval_reserve_retired_loss_id, 'reval_reserve_retired_loss_id', 'medium'); ?>      </li>
      <li><?php $f->l_select_field_from_object('nbv_retired_loss_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->nbv_retired_loss_id, 'nbv_retired_loss_id', 'medium'); ?>      </li>
      <li><?php $f->l_select_field_from_object('nbv_retired_loss_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->nbv_retired_loss_id, 'nbv_retired_loss_id', 'medium'); ?>      </li>
      <li><?php $f->l_select_field_from_object('deff_depriciation_reserve_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->deff_depriciation_reserve_id, 'deff_depriciation_reserve_id', 'medium'); ?>      </li>
      <li><?php $f->l_select_field_from_object('deff_depriciation_expense_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->deff_depriciation_expense_id, 'deff_depriciation_expense_id', 'medium'); ?>      </li>
      <li><?php $f->l_select_field_from_object('deff_depriciation_adjustment_id', sys_value_group_line::find_by_parent_id('4'), 'sys_value_group_line_id', array('code', 'description'), $$class->deff_depriciation_adjustment_id, 'deff_depriciation_adjustment_id', 'medium'); ?>      </li>
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
