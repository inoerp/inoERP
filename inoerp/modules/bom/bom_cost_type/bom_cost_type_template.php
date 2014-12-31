<form action=""  method="post" id="bom_cost_type"  name="bom_cost_type"><span class="heading"> Cost Type Header </span>
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
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bom_cost_type_id select_popup clickable">
         Cost Type Id</label><?php echo $f->text_field_dsr('bom_cost_type_id'); ?>
        <a name="show" href="form.php?class_name=bom_cost_type&<?php echo "mode=$mode"; ?>" class="show document_id bom_cost_type_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Inventory</label><?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?></li>
       <li><label>Cost Type Code</label><?php echo $f->text_field('cost_type_code', $$class->cost_type_code, '12', '', '', 1, $readonly1); ?></li>     
       <li><label>Cost Type</label><?php echo form::text_field_dm('cost_type'); ?></li>
       <li><label>Description</label><?php echo form::text_field_dm('description'); ?></li>
       <li><label>Status</label><?php echo form::status_field($$class->status, $readonly); ?></li>
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
        $reference_table = 'org';
        $reference_id = $$class->org_id;
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
 <div id ="form_line" class="form_line"><span class="heading"> Cost Type Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Details</a></li>
    <li><a href="#tabsLine-2">Future</a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column five_column"> 
       <li><label>Multi Inventory : </label>
        <?php echo form::checkBox_field('multi_org_cb', $$class->multi_org_cb, 'multi_org_cb', $readonly); ?>
       </li>
       <li><label>Default Cost Type : </label>
        <?php echo form::select_field_from_object('default_cost_type', bom_cost_type::find_all(), 'bom_cost_type_id', 'cost_type', $$class->default_cost_type, 'default_cost_type', $readonly); ?>
       </li>
      </ul>
     </div>
     <div class="second_rowset">
      <ul class="three_column">

      </ul>
     </div>
     <!--end of tab1 div three_column-->
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column five_column"> 
      </ul>
     </div>
     <div class="second_rowset">

     </div> 
     <!--                end of tab2 div three_column-->
    </div>
    <!--end of tab2 (purchasing)!!!! start of sales tab-->

   </div>

  </div>
 </div> 
</form>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="bom_cost_type" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="bom_cost_type_id" ></li>
  <li class="form_header_id" data-form_header_id="bom_cost_type" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedadeId" data-docHedadeId="bom_cost_type_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bom_cost_type_id" ></li>
 </ul>
</div>