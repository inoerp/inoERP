<div id ="form_header"><span class="heading">Business Org Header </span>
 <form action=""  method="post" id="business"  name="business">
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
       <li><label><img class="business select_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png">
         Business Org Id</label><?php echo $f->text_field_dsr('business_id'); ?>
        <a name="show" href="form.php?class_name=business&<?php echo "mode=$mode"; ?>" class="show document_id business_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Organization</label><?php echo form::select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $business->org_id, 'org', $readonly1); ?>    </li>
       <li><label>Extra Field</label><?php echo form::extra_field($business->ef_id, '10', $readonly); ?></li>
       <li><label>Status</label><?php echo form::status_field($business->status, $readonly); ?></li>
       <li><label>Revision</label><?php echo form::revision_enabled_field($business->rev_enabled, $readonly); ?></li>
       <li><label>Revision No</label><?php echo form::text_field('rev_number', $business->rev_number, '10', '', '', '', '', $readonly); ?></li>
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
        $reference_table = 'business';
        $reference_id = $$class->business_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
   </div>

  </div>

  <div id ="form_line" class="form_line"><span class="heading">Business Org Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Basic Info</a></li>
     <li><a href="#tabsLine-2">Org Details</a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column three_column"> 
        <li><label>Type of Business Org : </label> 
         <input type="text" name="business_org_type" value="<?php
         echo (!empty($business->business_org_type)) ? htmlentities($business->business_org_type) : "";
         ?>" maxlength="50" id="business_org_type"> 
        </li> 
        <li><label>Manager : </label> 
         <input type="text" name="manager" value="<?php
         echo (!empty($business->manager)) ? htmlentities($business->manager) : "";
         ?>" maxlength="50" id="manager"> 
        </li>
       </ul> 
      </div> 
      <!--end of tab1 div three_column-->
     </div> 
     <!--              end of tab1-->

     <div id="tabsLine-2" class="tabContent">
      <div> 
       <ul class="column three_column"> 
        <li><label>Enterprise Name : </label> 
         <?php echo $f->select_field_from_object('enterprise_org_id', org::find_all_enterprise(), 'org_id', 'org', $$class->enterprise_org_id, 'enterprise_org_id', '', '', $readonly1); ?>
        </li>
        <li><label>Legal Org : </label> 
         <?php echo $f->select_field_from_object('legal_org_id', org::find_all_legal(), 'org_id', 'org', $$class->legal_org_id, 'legal_org_id', 'legal_org_id', '', $readonly1); ?></li>
        <li><label>Ledger: </label> <?php echo $f->text_field_dr('ledger'); ?></li>
        <li><label>Cash Ac: </label> <?php $f->ac_field_d('cash_ac_id'); ?></li>
       </ul>
      </div> 
     </div>
    </div>
   </div> 
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="business" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="business_id" ></li>
  <li class="form_header_id" data-form_header_id="business" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="business" ></li>
  <li class="btn1DivId" data-btn1DivId="business" ></li>
 </ul>
</div>