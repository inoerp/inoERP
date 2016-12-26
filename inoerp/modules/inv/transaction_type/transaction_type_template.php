<div id ="form_header">
 <form  method="post" id="transaction_type_form"  name="transaction_type_form">
  <span class="heading"><?php echo gettext('Transaction Type') ?></span>
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
       <li><?php $f->l_text_field_dr_withSearch('transaction_type_id') ?>
        <a name="show" href="form.php?class_name=transaction_type&<?php echo "mode=$mode"; ?>" class="show document_id transaction_type_id">
         <i class='fa fa-refresh'></i></a> 
       </li> 
       <li><?php $f->l_text_field_d('transaction_type_number') ?></li>
       <li><?php $f->l_text_field_d('transaction_type') ?></li>
       <li><?php $f->l_select_field_from_object('type_class', transaction_type::transaction_type_class(), 'option_line_code', 'description', $$class->type_class, '', '', 1, $readonly1); ?>        </li>
       <li><?php $f->l_select_field_from_object('transaction_action', transaction_type::transaction_action(), 'option_line_code', 'description', $$class->transaction_action, '', '', 1, $readonly); ?>        </li>
      </ul>
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
     <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
     <li><a href="#tabsLine-1"><?php echo gettext('Future') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="column four_column"> 
       <li><?php $f->l_checkBox_field_d('allow_negative_balance_cb'); ?></li>
       <li><?php $f->l_status_field_d('status'); ?></li>
       <li><?php $f->l_checkBox_field_d('rev_enabled_cb'); ?></li>
       <li><?php $f->l_text_field_d('rev_number') ?></li>
       <li><?php // $f->l_text_field_d('transaction_type_number') ?></li>
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