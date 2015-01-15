<div id ="form_header"> <?php $f = new inoform(); ?>
 <form action=""  method="post" id="fa_asset_category"  name="fa_asset_category"><span class="heading"> Asset Category </span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Attachments</a></li>
    <li><a href="#tabsHeader-3">Note</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label><img class="fa_asset_category_id select_popup clickable"  src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
         Category Id</label><?php $f->text_field_dsr('fa_asset_category_id'); ?><a name="show" href="form.php?class_name=fa_asset_category&<?php echo "mode=$mode"; ?>" class="show document_id fa_asset_category_id">
         <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a></li>
       <li><label>Category</label><?php $f->text_field_d('asset_category'); ?></li>               
       <li><label>Segment1</label><?php $f->text_field_d('segment1'); ?></li>
       <li><label>Segment2</label><?php $f->text_field_d('segment2'); ?></li>
       <li><label>Segment3</label><?php $f->text_field_d('segment3'); ?></li>
       <li><label>Type</label><?php echo $f->select_field_from_object('type', fa_asset_category::asset_category_type(), 'option_line_code', 'option_line_value', $$class->type, 'type', '', 1); ?></li>
       <li><label>Description</label><?php echo $f->text_field_dl('description'); ?></li>
       <li><label>Enabled</label><?php echo $f->checkBox_field_d('enabled_cb'); ?></li>
       <li><label>Capitalize</label><?php echo $f->checkBox_field_d('capitalize_cb'); ?></li>
       <li><label>In Physical</label><?php echo $f->checkBox_field_d('in_physical_inv_cb'); ?></li>
      </ul>
     </div>
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
<span class="heading"> Asset Book Category Association </span>
<div id ="form_line" class="form_line">
 <form action=""  method="post" id="fa_book_category_association"  name="fa_book_category_association">
  <div class="line_before_tab"> 
   <ul class="column five_column inline_list"> 
    <li><label>Asset Book Name: </label> 
     <?php echo $f->select_field_from_object('fa_asset_book_id', fa_asset_book::find_all(), 'fa_asset_book_id', 'asset_book_name', $$class_second->fa_asset_book_id, 'fa_asset_book_id'); ?>
     <a name="show2" href="form.php?class_name=fa_asset_category&<?php echo "mode=$mode"; ?>" class="show2 document_id fa_book_category_association_id">
      <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
    </li> 
    <li class="hidden"><?php echo form::hidden_field('fa_asset_category_id', $$class->fa_asset_category_id); ?>
     <?php echo form::hidden_field('fa_book_category_association_id', $$class_second->fa_book_category_association_id); ?>
    </li>
   </ul>
  </div>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Cost Accounts</a></li>
    <li><a href="#tabsLine-2">Depreciation Accounts</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <ul class="column five_column"> 
      <li><label>Cost Ac : </label><?php $f->ac_field_d2m('asset_cost_ac_id'); ?></li>
      <li><label>Clearing Ac : </label><?php $f->ac_field_d2m('asset_clearing_ac_id'); ?></li>
      <li><label>CIP Cost Ac : </label><?php $f->ac_field_d2m('cip_cost_ac_id'); ?></li>
      <li><label>CIP Clearing Ac : </label><?php $f->ac_field_d2m('cip_clearing_ac_id'); ?></li>
     </ul>
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <ul class="column five_column"> 
      <li><label>Depreciation Expense : </label><?php $f->ac_field_d2m('depreciation_expense_ac_id'); ?></li>
      <li><label>Accumulated Depreciation : </label><?php $f->ac_field_d2m('accumulated_depreciation_ac_id'); ?></li>
      <li><label>Bonus Expense : </label><?php $f->ac_field_d2('bonus_expense_ac_id'); ?></li>
      <li><label>Bonus Reserve : </label><?php $f->ac_field_d2('bonus_reserve_ac_id'); ?></li>
      <li><label>Revalue Reserve : </label><?php $f->ac_field_d2m('revalue_reserve_ac_id'); ?></li>
      <li><label>Unplanned Depreciation : </label><?php $f->ac_field_d2m('unplanned_depreciation_expense_ac_id'); ?></li>
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
  <li class="lineClassName" data-lineClassName="fa_book_category_association" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="fa_asset_category_id" ></li>
  <li class="form_header_id" data-form_header_id="fa_asset_category" ></li>
  <li class="line_key_field" data-line_key_field="fa_book_category_association_name" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="fa_book_category_association" ></li>
 </ul>

 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fa_asset_category_id" ></li>
  <li class="docLineId" data-docLineId="fa_book_category_association_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fa_asset_category" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="fa_book_category_association" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
 </ul>
</div>