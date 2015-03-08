<div id ="form_all">
 <form action=""  method="post" id="org"  name="org">
  <span class="heading"><?php echo gettext('Organization') ?></span>
  <span class="heading"> </span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('org_id') ?>
        <a name="show" href="form.php?class_name=org&<?php echo "mode=$mode"; ?>" class="show document_id org_id">
         <i class="fa fa-refresh"></i></a> 
       </li> 
       <li><?php $f->l_select_field_from_object('type', org::org_types(), 'option_line_code', 'option_line_value', $$class->type, 'type', '', 1, $readonly1); ?>        </li> 
       <li><?php $f->l_text_field_dm('org'); ?> </li> 
       <li><?php $f->l_text_field_dm('code'); ?> </li> 
       <li><?php $f->l_select_field_from_object('enterprise_org_id', $$class->findAll_enterprise(), 'org_id', 'org', $$class->enterprise_org_id, 'enterprise_org_id', '', '', $readonly1); ?></li>
       <li><?php $f->l_select_field_from_object('legal_org_id', $$class->findAll_legal(), 'org_id', 'org', $$class->legal_org_id, 'legal_org_id', '', '', $readonly1); ?></li>
       <li><?php $f->l_select_field_from_object('business_org_id', $$class->findAll_business(), 'org_id', 'org', $$class->business_org_id, 'business_org_id', '', '', $readonly1); ?></li> 
       <li><?php $f->l_text_field_dm('description'); ?> </li> 
       <li><?php $f->l_status_field_d('status'); ?></li>
       <li><?php $f->l_checkBox_field_d('rev_enabled'); ?></li>
       <li><?php $f->l_text_field_d('rev_number') ?></li>
       <li><label><?php echo gettext('Address Id') ?><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_id select_popup clickable">
        </label><input type="text"  name="address_id[]" value="<?php echo htmlentities($org->address_id);
?>" maxlength="50" id="address_id"> 
       </li> 
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
  <span class="heading"><?php echo gettext('Other Details') ?></span>
  <div id ="form_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Address') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Contacts') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="column header_field address">
       <li><label><?php echo gettext('Phone') ?></label> <?php $f->text_field_d2r('phone'); ?></li>
       <li><label><?php echo gettext('Email') ?></label> <?php $f->text_field_d2r('website'); ?></li>
       <li><label><?php echo gettext('Web-site') ?></label><?php $f->text_field_d2r('website'); ?></li>
       <li><label><?php echo gettext('Country') ?></label><?php $f->text_field_d2r('country'); ?></li>
       <li><label><?php echo gettext('Postal Code') ?></label> <?php $f->text_field_d2r('postal_code'); ?></li>
       <li><label><?php echo gettext('Address') ?></label>  
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
          <?php echo gettext('Associate Contact') ?></label>  
         <?php
         echo $f->hidden_field('extn_contact_id_new', '');
         echo $f->text_field('contact_name_new', '', '20', '', 'select_contact');
         ?>  </li>
        <li class='clickable' id='add_new_contact' title='New contact reference field'><i class="fa fa-plus-circle"></i></li>
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
  <li class="docHedaderId" data-docHedaderId="org_id" ></li>
  <li class="btn1DivId" data-btn1DivId="org" ></li>
 </ul>
</div>