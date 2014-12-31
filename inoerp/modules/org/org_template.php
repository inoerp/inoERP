<div id ="form_all">
 <form action=""  method="post" id="org"  name="org"><span class="heading">Organization </span>
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
        <li> 
         <label><img src="<?php echo HOME_URL; ?>themes/default/images/serach.png" class="org_id select_popup clickable">
          Org Id</label><?php $f->text_field_ds('org_id') ?>
         <a name="show" href="form.php?class_name=org&<?php echo "mode=$mode"; ?>" class="show document_id org_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li> 
        <li><label>Org Type</label><?php echo $f->select_field_from_object('type', org::org_types(), 'option_line_code', 'option_line_value', $$class->type, 'type', '', 1, $readonly1); ?>        </li> 
        <li><label>Org</label><?php $f->text_field_dm('org'); ?> </li> 
        <li><label>Code</label><?php $f->text_field_dm('code'); ?> </li> 
        <li><label>Enterprise</label><?php echo $f->select_field_from_object('enterprise_org_id', $$class->findAll_enterprise(), 'org_id', 'org', $$class->enterprise_org_id, 'enterprise_org_id', '', '', $readonly1); ?></li>
        <li><label>Legal Org</label><?php echo $f->select_field_from_object('legal_org_id', $$class->findAll_legal(), 'org_id', 'org', $$class->legal_org_id, 'legal_org_id', '', '', $readonly1); ?></li>
        <li><label>Business Org</label><?php echo $f->select_field_from_object('business_org_id', $$class->findAll_business(), 'org_id', 'org', $$class->business_org_id, 'business_org_id', '', '', $readonly1); ?></li> 
        <li><label>Description</label><?php $f->text_field_dm('description'); ?> </li> 
        <li><label>Status</label><?php echo form::status_field($$class->status, $readonly); ?></li>
        <li><label>Revision</label><?php echo form::revision_enabled_field($$class->rev_enabled, $readonly); ?></li>
        <li><label>Revision No</label><?php echo form::text_field('rev_number', $$class->rev_number, '10', '', '', '', '', $readonly); ?></li>
        <li><label>Address Id<img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_id select_popup clickable">
         </label><input type="text"  name="address_id[]" value="<?php echo htmlentities($org->address_id);
         ?>" maxlength="50" id="address_id"> 
        </li> 
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
  <span class="heading">Other Details </span>
  <div id ="form_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Address</a></li>
     <li><a href="#tabsLine-2">Contacts</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="address inline_list">
       <li><label>Phone  : </label> <?php $f->text_field_d2r('phone'); ?></li>
       <li><label>Email  : </label> <?php $f->text_field_d2r('website'); ?></li>
       <li><label>Web-site  : </label><?php $f->text_field_d2r('website'); ?></li>
       <li><label>Country  : </label><?php $f->text_field_d2r('country'); ?></li>
       <li><label>Postal Code  : </label> <?php $f->text_field_d2r('postal_code'); ?></li>
       <li><label>Address :</label>  
        <textarea readonly name="address" id="address" cols="22" rows="3" placeholder="Select address Id"><?php echo trim(htmlentities($address->address)); ?></textarea>
       </li>
      </ul>
     </div>
     <div id="tabsLine-2" class="tabContent">
      <?php
      if (!empty($all_contacts)) {
       include_once HOME_DIR . '/extensions/contact/view/contact_view_template.php';
      }
      ?>
      <div>
       <ul id="new_contact_reference">
        <li class='new_object1'><label><img class="extn_contact_id select_popup clickable"  src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
          Associate Contact : </label>  
         <?php
         echo $f->hidden_field('extn_contact_id_new', '');
         echo $f->text_field('contact_name_new', '', '20', '', 'select_contact');
         ?>  </li>
        <li class='flaticon-add182 clickable' id='add_new_contact' title='New contact reference field'></li>
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
  <li class="headerClassName" data-headerClassName="org" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="org_id" ></li>
  <li class="form_header_id" data-form_header_id="org" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedadeId" data-docHedadeId="org_id" ></li>
  <li class="btn1DivId" data-btn1DivId="org_id" ></li>
 </ul>
</div>