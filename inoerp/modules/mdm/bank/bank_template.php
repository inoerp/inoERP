<div id ="form_header"><span class="heading"> Bank Names </span>
 <form action=""  method="post" id="mdm_bank_header"  name="mdm_bank_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Address Details</a></li>
    <li><a href="#tabsHeader-3">Attachments</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li>
        <label><img class="mdm_bank_header_id_popup select_popup clickable"  src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
         Bank Id</label><?php $f->text_field_ds('mdm_bank_header_id'); ?>
        <a name="show" href="form.php?class_name=mdm_bank_header&<?php echo "mode=$mode"; ?>" class="show document_id mdm_bank_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Bank Name</label><?php echo $f->text_field('bank_name', $$class->bank_name, '20', 'bank_name', 'select_bank_name', 1, $readonly); ?></li>
       <li><label>Bank Number</label><?php $f->text_field_d('bank_number'); ?></li>               
       <li><label>Country</label><?php echo $f->select_field_from_object('country', mdm_tax_region::country(), 'option_line_code', 'option_line_value', $$class->country, 'country', '', 1, $readonly1); ?>       </li>
       <li><label>Description</label><?php $f->text_field_d('description'); ?></li>
       <li><label>Short Name</label><?php $f->text_field_d('bank_name_alt'); ?></li>
       <li><label>Alt Name</label><?php $f->text_field_d('bank_name_alt'); ?></li>
       <li><label>Tax Reg No</label><?php echo form::text_field_d('tax_reg_no'); ?> </li>
       <li><label>Tax Payer Id</label><?php echo form::text_field_d('tax_payer_id'); ?> </li>
       <li><label>Status</label><?php echo form::status_field($$class->status, $readonly); ?> </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="header_address"> 
      <ul class="column two_column">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup select_popup clickable">
         Corporate Address : </label>
        <?php $f->text_field_d('address_id'); ?>
       </li>
       <li><label>Address Name : </label><?php $f->text_field_dr('header_address_name', 'address_name'); ?></li>
       <li><label>Address :</label> <?php $f->text_field_dr('header_address', 'address'); ?></li>
       <li><label>Country  : </label> <?php $f->text_field_dr('header_country', 'country'); ?></li>
       <li><label>Postal Code  : </label><?php echo $f->text_field_dr('header_postal_code', 'postal_code'); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <?php echo ino_attachement($file); ?>
     </div>
    </div>
   </div>

  </div>
 </form>
</div>

<div id ="form_line" class="form_line"><span class="heading"> Bank Branches </span>
 <form action=""  method="post" id="mdm_bank_site"  name="mdm_bank_site">
  <div class="line_before_tab"> 
   <ul class="column five_column inline_list"> 
    <li><label>Site Id : </label> 
     <?php echo $f->select_field_from_array('mdm_bank_site_id', mdm_bank_site::find_all_sitesOfHeader_array($$class->mdm_bank_header_id), $$class_second->mdm_bank_site_id, 'mdm_bank_site_id'); ?>
     <a name="show" href="form.php?class_name=mdm_bank_header&<?php echo "mode=$mode"; ?>" class="show document_id mdm_bank_site_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
    </li> 
    <?php echo form::hidden_field('mdm_bank_header_id', $$class->mdm_bank_header_id); ?>
    <li><label>Branch Name : </label> <?php $f->text_field_d2m('branch_name'); ?> </li>
    <li><label>Branch Number : </label>  <?php $f->text_field_d2('branch_number'); ?>	</li>
   </ul>
  </div>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Main</a></li>
    <li><a href="#tabsLine-2">Transaction</a></li>
    <li><a href="#tabsLine-3">Site Address</a></li>
    <li><a href="#tabsLine-4">Contact</a></li>
    <li><a href="#tabsLine-5">Notes</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column four_column"> 
       <li><label>Country : </label>
        <?php echo $f->select_field_from_object('country', option_header::COUNTRIES(), 'option_line_code', 'option_line_code', $$class_second->country, 'country'); ?>
       </li>
       <li><label>Description : </label><?php $f->text_field_d2('description'); ?></li>
       <li><label>Short Name : </label><?php $f->text_field_d2('branch_name_short'); ?></li>
       <li><label>Alt Name : </label><?php $f->text_field_d2('branch_name_alt'); ?></li>
       <li><label>Tax Reg No : </label> <?php echo form::text_field_d2('tax_reg_no'); ?> </li>
       <li><label>Tax Payer Id : </label>	<?php echo form::text_field_d2('tax_payer_id'); ?> </li>
       <li><label>Status : </label> <?php echo form::status_field($$class_second->status, $readonly); ?> </li>
      </ul>
     </div>
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <ul class="column four_column"> 
      <li><label>Routing : </label><?php $f->text_field_d2('routing_number'); ?></li>
      <li><label>IFSC Code : </label><?php $f->text_field_d2('ifsc_code'); ?></li>
      <li><label>SWIFT Code : </label><?php $f->text_field_d2('swift_code'); ?></li>
      <li><label>IBAN  : </label> <?php echo form::text_field_d2('iban_code'); ?> </li>
     </ul>
    </div> 
    <div id="tabsLine-3" class="tabContent">
     <div class="first_rowset"> 
      <div class="site_address"> 
       <ul class="column two_column">
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup select_popup clickable">
          Branch Address : </label>
         <?php $f->text_field_d2('site_address_id', 'address_id'); ?>
        </li>
        <li><label>Address Name : </label><?php $f->text_field_d2r('site_address_name', 'address_name'); ?></li>
        <li><label>Address :</label> <?php $f->text_field_d2r('site_address', 'address'); ?></li>
        <li><label>Country  : </label> <?php $f->text_field_d2r('site_country', 'country'); ?></li>
        <li><label>Postal Code  : </label><?php echo $f->text_field_d2r('site_postal_code', 'postal_code'); ?></li>
       </ul>
      </div>
     </div>
    </div> 
    <div id="tabsLine-4" class="tabContent">
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
       <li class='clickable' id='add_new_contact' title='New contact reference field'><i class="fa fa-plus-circle"></i></li>
      </ul>
     </div>
    </div>
    <div id="tabsLine-5" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <?php
      $reference_table = 'mdm_bank_site';
      $reference_id = $$class_second->mdm_bank_site_id;
      require_once HOME_DIR . '/comment.php';
      ?>
      <div id="new_comment">
      </div>
     </div>
    </div>
   </div>

  </div>
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="mdm_bank_header" ></li>
  <li class="lineClassName" data-lineClassName="mdm_bank_site" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="mdm_bank_header_id" ></li>
  <li class="form_header_id" data-form_header_id="mdm_bank_header" ></li>
  <li class="line_key_field" data-line_key_field="branch_name" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="mdm_bank_site" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="mdm_bank_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="mdm_bank_header_id" ></li>
 </ul>
</div>
