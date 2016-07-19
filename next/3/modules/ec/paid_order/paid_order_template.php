<form method="post" id="ec_paid_order"  name="ec_paid_order"><span class="heading">eCommerce Paid Order </span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('ec_paid_order_id') ?>
       <a name="show" href="form.php?class_name=ec_paid_order&<?php echo "mode=$mode"; ?>" class="show document_id ec_paid_order_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_dr('payment_method_id'); ?></li>
      <li><?php $f->l_text_field_dr('doc_currency'); ?></li>
      <li><?php $f->l_text_field_dr('total_amount'); ?></li>
      <li><?php $f->l_text_field_dr('service_provider'); ?></li>
      <li><?php $f->l_text_field_dr('sp_transaction_id'); ?></li>
      <li><?php $f->l_text_field_dr('user_id'); ?></li>
      <li><?php $f->l_text_field_dr('email'); ?></li>
      <li><?php $f->l_text_field_dr('status'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'ec_paid_order';
       $reference_id = $$class->ec_paid_order_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
     <div> 
     </div>
    </div>
   </div>
  </div>
 </div>
 <div id ="form_line" class="form_line"><span class="heading"> Paid Order Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Order Details') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Service Provider Data') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
    <?php echo form::text_area('confirm_order_details', $$class->confirm_order_details, '10', '150', '', 'Maximum 255 Characters', '', 1); ?>
    </div>
    <div id="tabsLine-2" class="tabContent">
      <?php echo form::text_area('sp_return_data', $$class->sp_return_data, '10', '150', '', 'Maximum 255 Characters', '', 1); ?>
    </div>
   </div>


  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="ec_paid_order" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="ec_paid_order_id" ></li>
  <li class="form_header_id" data-form_header_id="ec_paid_order" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ec_paid_order_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ec_paid_order" ></li>
 </ul>
</div>