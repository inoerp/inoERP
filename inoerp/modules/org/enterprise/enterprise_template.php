<div id ="form_header"><span class="heading">Enterprise Header </span>


 <form action=""  method="post" id="enterprise"  name="enterprise">
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
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="enterprise_id select_popup clickable">
         Enterprise Id</label><?php echo form::text_field('enterprise_id', $enterprise->enterprise_id, '10', '', '', 'System number', 'enterprise_id', $readonly); ?>
        <a name="show" href="form.php?class_name=enterprise&<?php echo "mode=$mode"; ?>" class="show document_id enterprise_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Organization</label><?php echo form::select_field_from_object('org_id', org::find_all_enterprise(), 'org_id', 'org', $enterprise->org_id, 'org', $readonly1); ?> </li>
       <li><label>Status</label><?php echo form::status_field($enterprise->status, $readonly); ?></li>
       <li><label>Revision</label><?php echo form::revision_enabled_field($enterprise->rev_enabled, $readonly); ?></li>
       <li><label>Revision No</label><?php echo form::text_field('rev_number', $enterprise->rev_number, '10', '', '', '', '', $readonly); ?></li>
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
        $reference_table = 'enterprise';
        $reference_id = $$class->enterprise_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
   </div>

  </div>


  <span class="heading">Other Details </span>
  <div id ="form_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Enterprise</a></li>
     <li><a href="#tabsLine-2">Future</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="address inline_list">
       <li><label>Designation Option  : </label>
        <?php echo form::text_field('designation_option_header_id', $enterprise->designation_option_header_id, '30', '', '', 'Enter a valid number', 'designation_option_header_id', $readonly); ?>
       </li>
       <li><label>Type Option  : </label> 
        <?php echo form::text_field('type_option_header_id', $enterprise->type_option_header_id, '30', '', '', '', 'type_option_header_id', $readonly); ?>
       </li>
      </ul>
     </div>
     <div id="tabsLine-2" class="tabContent">
     </div>
    </div>

   </div>
  </div>

 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="enterprise" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="enterprise_id" ></li>
  <li class="form_header_id" data-form_header_id="enterprise" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedadeId" data-docHedadeId="enterprise_id" ></li>
  <li class="btn1DivId" data-btn1DivId="enterprise_id" ></li>
 </ul>
</div>