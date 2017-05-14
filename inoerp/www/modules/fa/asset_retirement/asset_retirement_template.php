<form  method="post" id="fa_asset_retirement"  name="fa_asset_retirement">
 <span class="heading"><?php echo gettext('Asset Retirement') ?></span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Action') ?></a></li>

   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('fa_asset_retirement_id') ?>
        <a name="show" href="form.php?class_name=fa_asset_retirement&<?php echo "mode=$mode"; ?>" class="show document_id fa_asset_retirement_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php
        echo $f->l_val_field_dm('asset_book_name', 'fa_asset_book', 'asset_book_name', '', 'asset_book_name', 'vf_select_asset_book_name');
        echo $f->hidden_field_withId('fa_asset_book_id', $$class->fa_asset_book_id);
        ?><i class="generic g_select_asset_book_name select_popup clickable fa fa-search" data-class_name="fa_asset_book"></i>
       </li>
       <li><?php
        echo $f->l_val_field_dm('asset_number', 'fa_asset', 'asset_number', '', 'asset_number', 'vf_select_asset_number');
        echo $f->hidden_field_withId('fa_asset_id', $$class->fa_asset_id);
        ?><i class="generic g_select_asset_number select_popup clickable fa fa-search" data-class_name="fa_asset"></i>
        <a name="show" href="form.php?class_name=fa_asset_retirement&<?php echo "mode=$mode"; ?>" class="show2 action document_id fa_asset_retirement_with_asset_book"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_dr('asset_description', 'description'); ?></li>
       <li><?php $f->l_text_field_dr('status', 'always_readonly'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
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
       $reference_table = 'fa_asset_retirement';
       $reference_id = $$class->fa_asset_retirement_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
     <div> 
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr('gl_journal_header_id', 'always_readonly'); ?></li>
       <li><label>Action</label>
        <?php
        echo $f->select_field_from_array('action', fa_asset_retirement::$action_a, '', 'action')
        ?>
       </li>
      </ul>
     </div>
    </div>

   </div>
  </div>
 </div>

 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Asset Retirement Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basics') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field two_column_form"> 
       <li><?php $f->l_date_fieldFromToday_m('retire_date', $$class->retire_date); ?></li>
       <li><?php $f->l_text_field_d('source_type'); ?></li>
       <li><?php $f->l_text_field_dr('original_cost'); ?></li>
       <li><?php $f->l_text_field_dr('current_cost'); ?></li>
       <li><?php $f->l_text_field_dr('ytd_depreciation'); ?></li>
       <li><?php $f->l_text_field_dr('accumulated_depreciation'); ?></li>
       <li><?php $f->l_text_field_d('reference'); ?></li>
       <li><?php $f->l_text_field_d('retirement_convention'); ?></li>
       <li><?php $f->l_number_field_d('retired_units'); ?></li>
       <li><?php $f->l_number_field_dm('retired_cost'); ?></li>
       <li><?php $f->l_number_field_d('proceed_of_sales'); ?></li>
       <li><?php $f->l_number_field_d('cost_of_removals'); ?></li>
       <li><?php $f->l_number_field_dr('adjustment_amount' ,'always_readonly'); ?></li>
      </ul>
     </div>
    </div> 
   </div>
  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fa_asset_retirement" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="fa_asset_retirement_id" ></li>
  <li class="form_header_id" data-form_header_id="fa_asset_retirement" ></li>
 </ul>

 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fa_asset_retirement_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fa_asset_retirement" ></li>
 </ul>
</div>