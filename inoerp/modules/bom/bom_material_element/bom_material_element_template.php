<div id="form_all"><span class="heading">Material Element</span>
 <form action=""  method="post" id="bom_material_element"  name="bom_material_element">
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
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bom_material_element_id select_popup clickable">
          Material Element Id</label><?php echo $f->text_field_dsr('bom_material_element_id'); ?>
         <a name="show" href="form.php?class_name=bom_material_element&<?php echo "mode=$mode"; ?>" class="show document_id bom_material_element_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label>Inventory</label><?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>      </li>
        <li><label>Material Element</label><?php echo form::text_field_d('material_element'); ?> </li>
        <li><label>Description</label><?php echo form::text_field_d('description'); ?></li>
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

  <div id ="form_line" class="form_line"><span class="heading"> Material Element Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Details</a></li>
     <li><a href="#tabsLine-2">Future</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div class="first_rowset"> 
       <ul class="column five_column"> 
        <li><label>Default Basis : </label>
         <?php echo form::select_field_from_object('default_basis', bom_header::bom_charge_basis(), 'option_line_id', 'option_line_code', $$class->default_basis, 'default_basis', $readonly); ?>
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
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="bom_material_element" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="bom_material_element_id" ></li>
  <li class="form_header_id" data-form_header_id="bom_material_element" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bom_material_element_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bom_material_element" ></li>
 </ul>
</div>