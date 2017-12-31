<div id ="form_header">
 <form method="post" id="fa_asset_category"  name="fa_asset_category">
  <span class="heading"><?php echo gettext('Asset Category') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('fa_asset_category_id'); ?><a name="show" href="form.php?class_name=fa_asset_category&<?php echo "mode=$mode"; ?>" class="show document_id fa_asset_category_id">
         <i class="fa fa-refresh"></i></a></li>
       <li><?php $f->l_text_field_d('asset_category'); ?></li>               
       <li><?php $f->l_text_field_d('segment1'); ?></li>
       <li><?php $f->l_text_field_d('segment2'); ?></li>
       <li><?php $f->l_text_field_d('segment3'); ?></li>
       <li><?php $f->l_select_field_from_object('type', fa_asset_category::asset_category_type(), 'option_line_code', 'option_line_value', $$class->type, 'type', '', 1); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_checkBox_field_d('enabled_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('capitalize_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('in_physical_inv_cb'); ?></li>
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
       $reference_table = 'fa_asset_category';
       $reference_id = $$class->fa_asset_category_id;
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
 </form>
</div>

<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Asset Book Category Association') ?></span>
 <form  method="post" id="fa_book_category_assoc"  name="fa_book_category_assoc">
  <div id="line_before_tab" class="ino-well"> 
   <ul class="column header_field "> 
    <li><?php $f->l_select_field_from_object('fa_asset_book_id', fa_asset_book::find_all(), 'fa_asset_book_id', 'asset_book_name', $$class_second->fa_asset_book_id, 'fa_asset_book_id' ,'action medium' ); ?>
     <a name="show1" href="form.php?class_name=fa_asset_category&<?php echo "mode=$mode"; ?>" class="show1 document_id fa_book_category_assoc_id">
      <i class="fa fa-refresh"></i></a> 
    </li> 
    <li class="hidden"><?php echo form::hidden_field('fa_asset_category_id', $$class->fa_asset_category_id); ?>
     <?php echo form::hidden_field('fa_book_category_assoc_id', $$class_second->fa_book_category_assoc_id); ?>
    </li>
   </ul>
  </div>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Cost Accounts') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Depreciation Accounts') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <ul class="column header_field two_column_form"> 
      <li><label><?php echo gettext('Cost Ac') ?></label><?php $f->ac_field_d2m('asset_cost_ac_id'); ?></li>
      <li><label><?php echo gettext('Clearing Ac') ?></label><?php $f->ac_field_d2m('asset_clearing_ac_id'); ?></li>
      <li><label><?php echo gettext('CIP Cost Ac') ?></label><?php $f->ac_field_d2m('cip_cost_ac_id'); ?></li>
      <li><label><?php echo gettext('CIP Clearing Ac') ?></label><?php $f->ac_field_d2m('cip_clearing_ac_id'); ?></li>
     </ul>
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <ul class="column header_field two_column_form"> 
      <li><label><?php echo gettext('Depreciation Expense') ?></label><?php $f->ac_field_d2m('depreciation_expense_ac_id'); ?></li>
      <li><label><?php echo gettext('Accumulated Depreciation') ?></label><?php $f->ac_field_d2m('accumulated_depreciation_ac_id'); ?></li>
      <li><label><?php echo gettext('Bonus Expense') ?></label><?php $f->ac_field_d2('bonus_expense_ac_id'); ?></li>
      <li><label><?php echo gettext('Bonus Reserve') ?></label><?php $f->ac_field_d2('bonus_reserve_ac_id'); ?></li>
      <li><label><?php echo gettext('Revalue Reserve') ?></label><?php $f->ac_field_d2m('revalue_reserve_ac_id'); ?></li>
      <li><label><?php echo gettext('Retirement Gain/Loss') ?></label><?php $f->ac_field_d2('retirement_gl_ac_id'); ?></li>
      <li><label><?php echo gettext('Unplanned Depreciation') ?></label><?php $f->ac_field_d2m('unplanned_depreciation_expense_ac_id'); ?></li>
     </ul>
     <!--end of tab1 div three_column-->
    </div> 
   </div>
  </div>
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fa_asset_category" ></li>
  <li class="lineClassName" data-lineClassName="fa_book_category_assoc" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="fa_asset_category_id" ></li>
  <li class="form_header_id" data-form_header_id="fa_asset_category" ></li>
  <li class="line_key_field" data-line_key_field="fa_book_category_assoc_name" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="fa_book_category_assoc" ></li>
 </ul>

 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fa_asset_category_id" ></li>
  <li class="docLineId" data-docLineId="fa_book_category_assoc_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fa_asset_category" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="fa_book_category_assoc" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
 </ul>
</div>