<div id="path_divId">
 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
 <!--    End of place for showing error messages-->
 <div id ="form_header">
  <form  method="post" id="extn_subscribe" name="extn_subscribe"  >
   <span class="heading"><?php echo gettext('Subscription Details') ?></span>
   <div class="tabContainer"> 
    <ul class="column header_field two_column_form"> 
     <li><?php $f->l_text_field_dr_withSearch('extn_subscribe_id') ?>
      <a name="show" href="form.php?class_name=extn_subscribe&<?php echo "mode=$mode"; ?>" class="show document_id extn_subscribe_id">
       <i class="fa fa-refresh"></i></a> 
     </li>
     <li><?php $f->l_text_field_dm('reference_key_name'); ?></li>
     <li><?php $f->l_text_field_d('reference_key_value'); ?></li>
     <li><?php $f->l_text_field_d('user_email'); ?></li>
     <li><?php $f->l_text_field_d('user_id'); ?></li>
     <li><?php $f->l_text_field_d('username'); ?></li>
     <li><?php $f->l_text_field_d('unsubscribe_reason'); ?></li>
     <li><?php $f->l_checkBox_field_d('enabled_cb'); ?> </li>
    </ul>
   </div>
  </form> 
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="extn_subscribe" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="extn_subscribe_id" ></li>
  <li class="form_header_id" data-form_header_id="extn_subscribe" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="extn_subscribe_id" ></li>
  <li class="btn1DivId" data-btn1DivId="extn_subscribe_id" ></li>
 </ul>
</div>