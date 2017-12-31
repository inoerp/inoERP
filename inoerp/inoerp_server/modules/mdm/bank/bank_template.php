<div id ="form_header">
 <span class="heading"><?php echo gettext('Bank Names') ?></span>
 <form method="post" id="mdm_bank_header"  name="mdm_bank_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Address Details') ?> </a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('mdm_bank_header_id'); ?>
       <a name="show" href="form.php?class_name=mdm_bank_header&<?php echo "mode=$mode"; ?>" class="show document_id mdm_bank_header_id">
        <i class='fa fa-refresh'></i></a> 
      </li>
      <li><?php $f->l_text_field('bank_name', $$class->bank_name, '20', 'bank_name', 'select_bank_name', 1, $readonly); ?></li>
      <li><?php $f->l_text_field_d('bank_number'); ?></li>               
      <li><?php $f->l_select_field_from_object('country', mdm_tax_region::country(), 'option_line_code', 'option_line_value', $$class->country, 'country', '', 1, $readonly1); ?>       </li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php $f->l_text_field_d('bank_name_short'); ?></li>
      <li><?php $f->l_text_field_d('bank_name_alt'); ?></li>
      <li><?php $f->l_text_field_d('tax_reg_no'); ?> </li>
      <li><?php $f->l_text_field_d('tax_payer_id'); ?> </li>
      <li><?php $f->l_status_field_d('status'); ?> </li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
		 <div class="header_address"><?php $f->address_field_d('address_id', 1, 'suplier_header'); ?></div>

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

<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext("Bank Branches") ?></span>
 <form method="post" id="mdm_bank_site"  name="mdm_bank_site">
  <div id='line_before_tab' class="ino-well"> 
   <ul class="column header_field "> 
    <li><?php $f->l_select_field_from_array('mdm_bank_site_id', mdm_bank_site::find_all_sitesOfHeader_array($$class->mdm_bank_header_id), $$class_second->mdm_bank_site_id, 'mdm_bank_site_id', ' medium'); ?>
     <a name="show" href="form.php?class_name=mdm_bank_header&<?php echo "mode=$mode"; ?>" class="show document_id mdm_bank_site_id" data-search_field='mdm_bank_site_id'>
      <i class='fa fa-refresh'></i></a> 
    </li> 
    <?php echo form::hidden_field('mdm_bank_header_id', $$class->mdm_bank_header_id); ?>
    <li><?php $f->l_text_field('branch_name', $$class_second->branch_name); ?> </li>
    <li><?php $f->l_text_field('branch_number', $$class_second->branch_number); ?>	</li>
   </ul>
  </div>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Transaction') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Site Address') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Contact') ?> </a></li>
    <li><a href="#tabsLine-5"><?php echo gettext('Notes') ?> </a></li>
    <li><a href="#tabsLine-6"><?php echo gettext('Secondary') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><?php $f->l_select_field_from_object('country', option_header::COUNTRIES(), 'option_line_code', 'option_line_code', $$class_second->country, 'country'); ?>       </li>
       <li><?php $f->l_text_field('description', $$class_second->description); ?>	</li>
       <li><?php $f->l_text_field('branch_name_short', $$class_second->branch_name_short); ?>	</li>
       <li><?php $f->l_text_field('branch_name_alt', $$class_second->branch_name_alt); ?>	</li>
       <li><?php $f->l_text_field('tax_reg_no', $$class_second->tax_reg_no); ?>	</li>
       <li><?php $f->l_text_field('tax_payer_id', $$class_second->tax_payer_id); ?>	</li>
       <li><label><?php echo gettext('Status') ?></label> <?php echo form::status_field($$class_second->status, $readonly); ?> </li>
      </ul>
     </div>
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <ul class="column header_field"> 
      <li><?php $f->l_text_field('routing_number', $$class_second->routing_number); ?>	</li>
      <li><?php $f->l_text_field('ifsc_code', $$class_second->ifsc_code); ?>	</li>
      <li><?php $f->l_text_field('swift_code', $$class_second->swift_code); ?>	</li>
      <li><?php $f->l_text_field('iban_code', $$class_second->iban_code); ?>	</li>
     </ul>
    </div> 
    <div id="tabsLine-3" class="tabContent">
		  <div class="site_address"><?php $f->address_field_d('site_address_id', 1, 'site_address'); ?></div>
    </div> 
    <div id="tabsLine-4" class="tabContent">
     <?php echo $f->contact_field('mdm_bank_site_id', $$class_second->mdm_bank_site_id, $all_contacts); ?>
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
    <div id="tabsLine-5" class="tabContent">
     <?php echo!empty($secondary_field_stmt) ? $secondary_field_stmt : null; ?>
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