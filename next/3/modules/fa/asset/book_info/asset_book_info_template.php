<form  method="post" id="fa_asset_book_info"  name="fa_asset_book_info">
 <span class="heading"><?php echo gettext('Asset Book Information') ?></span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Depreciation') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>

   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('fa_asset_book_info_id') ?>
        <a name="show" href="form.php?class_name=fa_asset_book_info&<?php echo "mode=$mode"; ?>" class="show document_id fa_asset_book_info_id">
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
       </li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_text_field_d('referece') ?>        </li> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_select_field_from_object('fa_depreciation_method_id', fa_depreciation_method::find_all(), 'fa_depreciation_method_id', 'depreciation_method', $$class->fa_depreciation_method_id, 'fa_depreciation_method_id', '', 1, $readonly1); ?></li>
      <li><?php $f->l_number_field_d('life_months'); ?></li>
      <li><?php $f->l_checkBox_field_d('depriciation_cb'); ?></li>
      <li><?php $f->l_date_fieldAnyDay('date_in_service', $$class->date_in_service); ?></li>
      <li><?php $f->l_date_fieldAnyDay('depriciation_start_date', $$class->depriciation_start_date); ?></li>
      <li><?php $f->l_number_field('depriciation_limit_amount', $$class->depriciation_limit_amount); ?></li>
      <li><?php $f->l_number_field('depriciation_limit_percentage', $$class->depriciation_limit_percentage); ?></li>
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
       $reference_table = 'fa_asset_book_info';
       $reference_id = $$class->fa_asset_book_info_id;
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

 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Asset Book Information Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Class Controls') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Future') ?> </a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><?php $f->l_number_field_d('current_cost'); ?></li>
       <li><?php $f->l_number_field_dr('original_cost' , 'always_readonly'); ?></li>
       <li><?php $f->l_number_field_dr('ytd_depreciation' ,'always_readonly'); ?></li>
       <li><?php $f->l_number_field_dr('accumulated_depreciation' ,'always_readonly'); ?></li>
       <li><?php $f->l_number_field_d('salvage_value_percentage'); ?></li>
       <li><?php $f->l_number_field_d('salvage_value_amount'); ?></li>
       <li><?php $f->l_number_field_d('recoverable_amount'); ?></li>
       <li><?php $f->l_number_field_d('recoverable_percentage'); ?></li>
      </ul>
     </div>
    </div> 
    <!--end of tab6 (planning)...start of lead times-->
    <div id="tabsLine-2" class="tabContent">

    </div>
   </div>
  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fa_asset_book_info" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="fa_asset_book_info_id" ></li>
  <li class="form_header_id" data-form_header_id="fa_asset_book_info" ></li>
 </ul>

 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fa_asset_book_info_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fa_asset_book_info" ></li>
 </ul>
</div>