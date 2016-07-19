<div id ="form_all"><span class="heading"><?php echo gettext('RFID Interface') ?></span>
 <form  method="post" id="sys_rfid_interface"  name="sys_rfid_interface">
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
       <li><?php $f->l_text_field_dr_withSearch('sys_rfid_interface_id') ?>
        <a name="show" href="form.php?class_name=sys_rfid_interface&<?php echo "mode=$mode"; ?>" class="show document_id sys_rfid_interface_id"><i class='fa fa-refresh'></i></a> 
       </li>
       <li><?php $f->l_text_field_d('epc'); ?></li>
       <li><?php $f->l_text_field_d('tag_number'); ?></li>
       <li><?php $f->l_text_field_d('antena_number'); ?></li>
       <li><?php $f->l_text_field_d('time_stamp'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
       <li><?php $f->l_text_field_d('readcount'); ?></li>
       <li><?php $f->l_text_field_d('org_id'); ?></li>
       <li><?php $f->l_text_field_d('item_id_m'); ?></li>
       <li><?php $f->l_text_field_d('from_subinventory_id'); ?></li>
       <li><?php $f->l_text_field_d('from_subinventory'); ?></li>
       <li><?php $f->l_text_field_d('transaction_type_id'); ?></li>
       <li><?php $f->l_text_field_d('transaction_type'); ?></li>
       <li><?php $f->l_text_field_d('quantity'); ?></li>
       <li><?php $f->l_text_field_d('item_description'); ?></li>
       <li><?php $f->l_text_field_d('status'); ?></li>
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
         $reference_table = 'sys_rfid_interface';
         $reference_id = $$class->sys_rfid_interface_id;
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
 </form>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_rfid_interface" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_rfid_interface_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_rfid_interface" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_rfid_interface_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_rfid_interface"></li>
 </ul>
</div>