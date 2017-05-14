<div id ="form_header">
 <form action=""  method="post" id="address"  name="address"><span class="heading"><?php echo gettext('Address Header') ?> </span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><label><img class="address select_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png">
          <?php echo gettext('Address Id') ?></label><?php echo form::text_field('address_id', $address->address_id, '10', '', '', 'System number', 'address_id', $readonly); ?>
         <a name="show" href="form.php?class_name=address&<?php echo "mode=$mode"; ?>" class="show document_id address_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label><?php echo gettext('Type') ?></label><?php echo form::select_field_from_object('type', address::address_types(), 'option_line_code', 'option_line_code', $address->type, 'type', $readonly); ?>    </li>
        <li><label><?php echo gettext('Address Name') ?></label><?php echo form::text_field('address_name', $address->address_name, '20', '', '', 'Enter a valid address name', 'address_name', $readonly); ?>    </li>
        <li><label><img class="tax_region_id select_popup clickable" src="<?php echo HOME_URL; ?>themes/images/serach.png">
          <?php echo gettext('Tax Region') ?></label><?php $f->text_field_d('tax_region_name') ?></li>
        <li><label><?php echo gettext('Description') ?></label><?php echo form::text_field('description', $address->description, '20', '250', '', 'Limit to 100 characters', 'description', $readonly); ?>    </li>
        <li><label><?php echo gettext('Status') ?></label><?php echo form::status_field($address->status, $readonly); ?></li>
        <li><label><?php echo gettext('Revision') ?></label><?php echo form::revision_enabled_field($address->rev_enabled, $readonly); ?></li>
        <li><label><?php echo gettext('Revision No') ?></label><?php echo form::text_field('rev_number', $address->rev_number, '10', '', '', '', '', $readonly); ?>    </li>
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
         $reference_table = 'address';
         $reference_id = $$class->address_id;
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
  <span class="heading"><?php echo gettext('Address Details') ?> </span>
  <div id ="form_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Address') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="address inline_list">
       <li><label><?php echo gettext('Phone') ?>  : </label>
        <?php echo form::text_field('phone', $address->phone, '30', '', '', 'Enter a valid number', 'phone', $readonly); ?>
       </li>
       <li><label><?php echo gettext('Email') ?>  : </label> 
        <?php echo form::text_field('email', $address->email, '30', '', '', 'Enter a valid email', 'email', $readonly); ?>
       </li>
       <li><label><?php echo gettext('Website') ?>  : </label> 
        <?php echo form::text_field('website', $address->website, '30', '', '', 'Enter a valid website', 'website', $readonly); ?>
       </li>
       <li><label><?php echo gettext('Country') ?>  : </label>
        <?php echo form::text_field('country', $address->country, '30', '', '', 'Enter a valid country', 'country', $readonly); ?>
       </li>
       <li><label><?php echo gettext('Postal Code') ?>  : </label>
        <?php echo form::text_field('postal_code', $address->postal_code, '30', '', '', 'Enter a postal_code', 'postal_code', $readonly); ?>
       </li>
       <li><label><?php echo gettext('Address') ?> :</label>  
        <?php echo form::text_area('address', $address->address, '3', '22', '', 'Complete Address', 'address', $readonly); ?>
       </li>
      </ul>
     </div>
    </div>

   </div>
  </div>
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="address" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="address_id" ></li>
  <li class="form_header_id" data-form_header_id="address" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedadeId" data-docHedadeId="address_id" ></li>
  <li class="btn1DivId" data-btn1DivId="address_id" ></li>
 </ul>
</div>
