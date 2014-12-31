<div id ="form_header">
 <form action=""  method="post" id="transaction_type_form"  name="transaction_type_form"><span class="heading">Transaction Type </span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic Info</a></li>
     <li><a href="#tabsHeader-2">Note</a></li>
     <li><a href="#tabsHeader-3">Attachments</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column four_column"> 
        <li> 
         <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="transaction_type_id select_popup clickable">
          Type Id : </label> 
         <?php $f->text_field_dr('transaction_type_id') ?>
         <a name="show" href="form.php?class_name=transaction_type&<?php echo "mode=$mode"; ?>" class="show document_id transaction_type_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li> 
        <li><label>Trnx. Number :</label>
         <?php form::text_field_wid('transaction_type_number'); ?>
        </li>
        <li><label>Transaction Type :</label>
         <?php form::text_field_wid('transaction_type'); ?>
        </li>
        <li><label>Type Class :</label>
         <?php echo $f->select_field_from_object('type_class', transaction_type::transaction_type_class(), 'option_line_code', 'description', $$class->type_class, '', '', 1, $readonly1); ?>
        </li>
        <li><label>Action :</label>
         <?php echo $f->select_field_from_object('transaction_action', transaction_type::transaction_action(), 'option_line_code', 'description', $$class->transaction_action, '', '', 1, $readonly); ?>
        </li>

       </ul>
      </div>
     </div>


     <div id="tabsHeader-2" class="tabContent">
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'transaction_type';
        $reference_id = $$class->transaction_type_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
      <div> 
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
    </div>

   </div>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"> Transaction Type Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Main</a></li>
     <li><a href="#tabsLine-2">Future</a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="column four_column"> 
       <li><label>Description :</label>
        <?php $f->text_field_wid('description'); ?>
       </li>
       <li><label>Allow Negative Balance : </label>
        <?php echo form::checkBox_field_d('allow_negative_balance_cb'); ?>
       </li> 
       <li><label>Extra Field : </label>
        <?php echo form::extra_field($transaction_type->ef_id, '10', $readonly); ?>
       </li>
       <li><label>Status : </label>
        <?php echo form::status_field($transaction_type->status, $readonly); ?>
       </li>
       <li><label>Revision : </label>
        <?php echo form::revision_enabled_field($transaction_type->rev_enabled_cb, $readonly); ?>
       </li>
       <li><label>Revision No: </label>
        <?php echo form::text_field('rev_number', $transaction_type->rev_number, '10', '', '', '', '', $readonly); ?>
       </li>
      </ul> 
     </div> 
     <!--end of tab1-->
     <div id="tabsLine-2" class="tabContent">
     </div>
    </div>


   </div>
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="transaction_type" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="transaction_type_id" ></li>
  <li class="form_header_id" data-form_header_id="transaction_type_form" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="transaction_type_id" ></li>
  <li class="btn1DivId" data-btn1DivId="transaction_type_id" ></li>
 </ul>
</div>