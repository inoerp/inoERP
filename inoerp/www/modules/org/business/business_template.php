<div id ="form_header">
 <span class="heading"><?php echo gettext('Business Org') ?></span>
 <form action=""  method="post" id="business"  name="business">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field"> 
      <li><?php echo $f->l_text_field_dr_withSearch('business_id'); ?>
       <a name="show" href="form.php?class_name=business&<?php echo "mode=$mode"; ?>" class="show document_id business_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $$class->org_id, 'org', '', '', $readonly); ?>					</li>
      <li><?php $f->l_status_field_d('status'); ?></li>
      <li><?php $f->l_checkBox_field_d('rev_enabled'); ?></li>
      <li><?php $f->l_text_field_d('rev_number'); ?>    </li>
     </ul>
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
     <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('BO Details') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><label><?php echo gettext('Business Org Type') ?></label> 
         <input type="text" name="business_org_type" value="<?php
         echo (!empty($business->business_org_type)) ? htmlentities($business->business_org_type) : "";
         ?>" maxlength="50" id="business_org_type"> 
        </li> 
        <li><label><?php echo gettext('Manager') ?></label> 
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
        <li><label><?php echo gettext('Enterprise Name') ?></label> 
         <?php echo $f->select_field_from_object('enterprise_org_id', org::find_all_enterprise(), 'org_id', 'org', $$class->enterprise_org_id, 'enterprise_org_id', '', '', $readonly1); ?>
        </li>
        <li><label><?php echo gettext('Legal Org') ?></label> 
         <?php echo $f->select_field_from_object('legal_org_id', org::find_all_legal(), 'org_id', 'org', $$class->legal_org_id, 'legal_org_id', 'legal_org_id', '', $readonly1); ?></li>
        <li><?php $f->l_text_field_dr('ledger'); ?></li>
        <li><?php $f->l_ac_field_d('cash_ac_id'); ?></li>
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
