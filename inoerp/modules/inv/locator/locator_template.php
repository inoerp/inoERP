<form action=""  method="post" id="locator"  name="locator">
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
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="locator_id select_popup clickable">
         Locator Id</label><?php $f->text_field_ds('locator_id') ?>
        <a name="show" href="form.php?class_name=locator&<?php echo "mode=$mode"; ?>" class="show document_id locator_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li> 
       <li><label>Organization</label><?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>    </li>
       <li><label>Sub Inventory</label><?php echo form::select_field_from_object('subinventory_id', subinventory::find_all(), 'subinventory_id', 'subinventory', $$class->subinventory_id, 'subinventory_id', $readonly); ?>    </li>
       <li><label>Locator Structure</label><?php echo locator::locator_structure(); ?></li>
       <li><label>Locator</label><?php form::text_field_wid('locator'); ?></li>
       <li><label>Alias</label><?php form::text_field_wid('alias'); ?></li>
       <li><label>Status</label><?php echo form::status_field($locator->status, $readonly); ?></li>
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
        $reference_table = 'locator';
        $reference_id = $$class->locator_id;
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


</form>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="locator" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="locator_id" ></li>
  <li class="form_header_id" data-form_header_id="locator" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedadeId" data-docHedadeId="locator_id" ></li>
  <li class="btn1DivId" data-btn1DivId="locator_id" ></li>
 </ul>
</div>