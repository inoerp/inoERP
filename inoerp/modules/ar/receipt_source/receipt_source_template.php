<div id ="form_header">
 <form action=""  method="post" id="ar_receipt_source"  name="ar_receipt_source"><span class="heading">Receipt Source </span>
  <div class="large_shadow_box tabContainer">
   <ul class="column five_column"> 
    <li> <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ar_receipt_source_id select_popup clickable">
      Receipt Source Id : </label><?php $f->text_field_ds('ar_receipt_source_id') ?>
    <a name="show" href="form.php?class_name=ar_receipt_source&<?php echo "mode=$mode"; ?>" class="show document_id ar_receipt_source_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
    </li>
    <li><label>Receipt Source :</label><?php $f->text_field_d('receipt_source'); ?></li>
    <li><label>BU Name : </label>
     <?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>
    </li>
    <li><label>Receipt Type : </label>
     <?php echo $f->select_field_from_object('receipt_type', ar_receipt_header::receipt_types(), 'option_line_code', 'option_line_value', $$class->receipt_type, 'receipt_type', '', 1, $readonly1); ?>
    </li>
    <li><label>Status : </label><?php echo form::status_field($$class->status, $readonly); ?></li>
    <li><label>Description :</label><?php $f->text_field_d('description'); ?> 					</li>

   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading">Receipt Source Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Basic Info</a></li>
     <li><a href="#tabsLine-2">Bank Account</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column four_column"> 
        <li><label>Creation Method :</label>
         <?php echo $f->select_field_from_array('creation_method', ar_receipt_source::$creation_method_a, $$class->creation_method, 'creation_method', '', 1, $readonly1); ?>
        </li>
        <li><label>Remittance :</label>
         <?php echo $f->select_field_from_array('remittance', ar_receipt_source::$remittance_method_a, $$class->remittance, 'remittance', '', 1, $readonly1); ?>
        </li>
        <li><label>Clearance :</label>
         <?php echo $f->select_field_from_array('clearance', ar_receipt_source::$clearance_method_a, $$class->clearance, 'clearance', '', 1, $readonly1); ?>
        </li>
        <li><label>Sync Receipt# ? :</label><?php $f->checkBox_field_d('sync_receipt_number_cb'); ?></li>
       </ul> 
      </div> 
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div> 
       <ul class="column four_column">
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="mdm_bank_account_id select_popup clickable">
          <?php echo $f->hidden_field_withId('bank_account_id', $$class->bank_account_id); ?>
          Account Number : </label> <?php $f->text_field_d('account_number') ?>	</li>
        <li><label>Bank Number : </label><?php $f->text_field_dr('bank_number'); ?></li> 
        <li><label>Branch Number : </label><?php $f->text_field_dr('branch_number'); ?></li> 
        <li><label>Short Name: </label><?php $f->text_field_dr('bank_name_short'); ?></li> 
        <li><label>Alt Name : </label><?php $f->text_field_dr('bank_name_alt'); ?></li> 
        <li><label>IFSC : </label><?php $f->text_field_dr('ifsc_code'); ?></li> 
        <li><label>SWIFT : </label><?php $f->text_field_dr('swift_code'); ?></li> 
        <li><label>Routing : </label><?php $f->text_field_dr('routing_number'); ?></li> 
        <li><label>IBAN: </label><?php $f->text_field_dr('iban_code'); ?></li> 
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
  <li class="headerClassName" data-headerClassName="ar_receipt_source" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="ar_receipt_source_id" ></li>
  <li class="form_header_id" data-form_header_id="ar_receipt_source" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ar_receipt_source_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ar_receipt_source_id" ></li>
 </ul>
</div>