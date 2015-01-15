<div id ="form_all"><span class="heading">Unit Of Measure </span>
 <form action=""  method="post" id="uom"  name="uom">
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
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="uom_id select_popup clickable">
          UOM Id</label><?php $f->text_field_ds('uom_id') ?>
         <a name="show" href="form.php?class_name=uom&<?php echo "mode=$mode"; ?>" class="show document_id uom_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li> 
        <li><label>UOM</label><?php $f->text_field_d('uom_name'); ?></li>
        <li><label>Class</label><?php echo form::select_field_from_object('class', uom::uom_class(), 'option_line_code', 'option_line_code', $$class->class, 'class', $readonly); ?></li>
        <li><label>Description</label><?php $f->text_field_d('description'); ?></li>
        <li><label>Primary</label><?php $f->checkBox_field_d('primary_cb'); ?></li>
        <li><label>Status</label><?php echo form::status_field($uom->status, $readonly); ?></li>
        <li><label>Revision</label><?php echo form::revision_enabled_field($uom->rev_enabled_cb, $readonly); ?></li>
        <li><label>Revision No</label><?php echo form::text_field('rev_number', $uom->rev_number, '10', '', '', '', '', $readonly); ?></li>
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
         $reference_table = 'uom';
         $reference_id = $$class->uom_id;
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

  <div id ="form_line" class="form_line"><span class="heading">UOM Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Relationship</a></li>
     <li><a href="#tabsLine-2">Future</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div > 
       <ul class="column four_column" > 
        <li><label>Primary UOM Id : </label>
         <?php $f->text_field_dsr('primary_uom_id'); ?>
        </li>
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="primary_uom_id select_popup clickable">
          Primary UOM : </label>
         <?php $f->text_field_d('primary_uom'); ?>
        </li>
        <li><label> Operator : </label>
         <input type="image"  src="<?php echo HOME_URL; ?>themes/images/multiply.png" alt="multiply"/> 
        </li> 
        <li><label>Primary Relation : </label>
         <?php $f->text_field_d('primary_relation'); ?>
        </li> 
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div> 
      </div> 
      <!--                end of tab2 div three_column-->
     </div>
     <!--end of tab5-->
    </div>

   </div> 
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="uom" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="uom_id" ></li>
  <li class="form_header_id" data-form_header_id="uom" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="uom_id" ></li>
  <li class="btn1DivId" data-btn1DivId="uom" ></li>
 </ul>
</div>