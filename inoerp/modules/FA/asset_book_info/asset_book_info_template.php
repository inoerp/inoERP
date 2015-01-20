<form action=""  method="post" id="fa_asset_book_info"  name="fa_asset_book_info"><span class="heading">Asset Book Information</span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Depreciation</a></li>
    <li><a href="#tabsHeader-3">Attachments</a></li>
    <li><a href="#tabsHeader-4">Note</a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="fa_asset_book_info_id select_popup clickable">
         Asset Book Ref Id</label><?php $f->text_field_dsr('fa_asset_book_info_id') ?>
        <a name="show" href="form.php?class_name=fa_asset_book_info&<?php echo "mode=$mode"; ?>" class="show document_id fa_asset_book_info_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="fa_asset_book_id select_popup clickable">
         Book Name</label><?php echo $f->text_field_dm('asset_book_name'); ?>
          <?php echo $f->hidden_field_withId('fa_asset_book_id', $$class->fa_asset_book_id) ?></li>
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="fa_asset_id select_popup clickable">
         Asset Number</label><?php $f->text_field_dm('asset_number'); ?>
        <?php echo $f->hidden_field_withId('fa_asset_id', $$class->fa_asset_id) ?>
       </li>
       <li><label>Description</label><?php echo $f->text_field('description', $$class->description, '20', 'description'); ?></li>
       <li><label>Reference</label><?php  $f->text_field_d('referece') ?>        </li> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><label>Depr. Method
       </label><?php echo $f->select_field_from_object('fa_depreciation_method_id',  fa_depreciation_method::find_all(),'fa_depreciation_method_id','depreciation_method',$$class->fa_depreciation_method_id ,'fa_depreciation_method_id','',1,$readonly1); ?></li>
      <li><label>Life in Months</label><?php echo $f->number_field('life_months', $$class->life_months); ?></li>
      <li><label>Depreciate?</label><?php $f->checkBox_field_d('depriciation_cb'); ?></li>
      <li><label>Date in Service</label><?php echo $f->date_fieldAnyDay('date_in_service', $$class->date_in_service); ?></li>
      <li><label>Depr. Start Date</label><?php echo $f->date_fieldAnyDay('depriciation_start_date', $$class->depriciation_start_date); ?></li>
      <li><label>Depr. Limit Amnt</label><?php echo $f->number_field('depriciation_limit_amount', $$class->depriciation_limit_amount); ?></li>
      <li><label>Depr. Limit %</label><?php echo $f->number_field('depriciation_limit_percentage', $$class->depriciation_limit_percentage); ?></li>
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

 <div id ="form_line" class="form_line"><span class="heading"> Asset Book Information Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Class Controls</a></li>
    <li><a href="#tabsLine-2">Future</a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column four_column"> 
       <li><label>Current Cost</label><?php echo $f->number_field('current_cost', $$class->current_cost,'','current_cost','large',1); ?></li>
       <li><label>Original Cost</label><?php $f = new inoform(); echo $f->number_field('original_cost', $$class->original_cost,'','original_cost','large',1,1); ?></li>
       <li><label>YTD Depreciation</label><?php echo $f->text_field('ytd_depreciation', $$class->ytd_depreciation,'','','large','',1); ?></li>
      <li><label>Accum. Depreciation</label><?php echo $f->number_field('accumulated_depreciation', $$class->accumulated_depreciation,'','','large','',1); ?></li>
       <li><label>Salvage %</label><?php echo $f->number_field('salvage_value_percentage', $$class->salvage_value_percentage,'','salvage_value_percentage','large'); ?></li>
      <li><label>Salvage Amount</label><?php echo $f->number_field('salvage_value_amount', $$class->salvage_value_amount,'','salvage_value_amount','large'); ?></li>
     
      <li><label>Recoverable Amount</label><?php echo $f->number_field('recoverable_amount', $$class->recoverable_amount,'','recoverable_amount','large','',1); ?></li>
      <li><label>Recoverable Limit %</label><?php echo $f->number_field('recoverable_percentage', $$class->recoverable_percentage,'','','large','',1); ?></li>
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