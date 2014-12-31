<form action=""  method="post" id="coa"  name="coa"><span class="heading">Chart Of Account</span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Notes</a></li>
    <li><a href="#tabsHeader-3">Attachments</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="coa_id select_popup clickable">
         COA Id</label><?php echo form::number_field_drs('coa_id'); ?>
        <a name="show" href="form.php?class_name=coa&<?php echo "mode=$mode"; ?>" class="show document_id coa_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Structure</label><?php echo form::select_field_from_object('coa_structure_id', coa::coa_structures(), 'option_header_id', 'option_type', $$class->coa_structure_id, 'coa_structure_id', $readonly1); ?>
        <a name="show" class="show_diff coa_structure_show"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Name</label><?php $f->text_field_d('coa_name'); ?></li>
       <li><label>Description</label><?php $f->text_field_d('description'); ?></li>
       <li><label>Status</label><?php echo form::status_field($$class->status, $readonly); ?></li>
       <li><label>Allow Rev</label><?php echo form::revision_enabled_field('rev_enabled_cb'); ?></li>
       <li><label>Revision No</label><?php echo form::number_field_drs('rev_number'); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'coa';
       $reference_id = $$class->coa_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>
  </div>

 </div>
 <div id ="form_line" class="form_line"><span class="heading"> Chart of Account Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Qualifiers</a></li>
    <li><a href="#tabsLine-2">Display</a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column five_column"> 
       <li><label>Balancing Segment : </label>
        <?php echo $f->select_field_from_object('balancing', coa::coa_segments_by_optionHeaderId($$class->coa_structure_id), 'option_line_code', 'option_line_value', $$class->balancing, 'balancing', 'coa_qualifier',1, $readonly1); ?>
       </li>
       <li><label>Cost Center : </label>
        <?php echo $f->select_field_from_object('cost_center', coa::coa_segments_by_optionHeaderId($$class->coa_structure_id), 'option_line_code', 'option_line_value', $$class->cost_center, 'cost_center', 'coa_qualifier',1, $readonly1); ?>
       </li>
       <li><label>Account : </label>
        <?php echo $f->select_field_from_object('natural_account', coa::coa_segments_by_optionHeaderId($$class->coa_structure_id), 'option_line_code', 'option_line_value', $$class->natural_account, 'natural_account', 'coa_qualifier',1, $readonly1); ?>
       </li>
       <li><label>Inter company : </label>
        <?php echo $f->select_field_from_object('inter_company', coa::coa_segments_by_optionHeaderId($$class->coa_structure_id), 'option_line_code', 'option_line_value', $$class->inter_company, 'inter_company', 'coa_qualifier',1, $readonly1); ?>
       </li>
      </ul>
     </div>
     <!--end of tab1 div three_column-->
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <?php echo $dispaly_statement; ?>
    </div>
    <!--end of tab2 (purchasing)!!!! start of sales tab-->
   </div>
  </div>
 </div> 
</form>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="coa" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="coa_id" ></li>
  <li class="form_header_id" data-form_header_id="coa" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="coa_id" ></li>
  <li class="btn1DivId" data-btn1DivId="coa_id" ></li>
 </ul>
</div>