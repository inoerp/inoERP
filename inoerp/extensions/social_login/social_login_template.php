<div id="path_divId">
 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
 <!--    End of place for showing error messages-->
 <div id ="form_header">
  <form  method="post" id="extn_social_login" name="extn_social_login"  >
   <span class="heading"><?php echo gettext('Social Log In') ?></span>
   <div class="tabContainer"> 
    <ul class="column header_field two_column_form"> 
     <li><?php $f->l_text_field_dr_withSearch('extn_social_login_id') ?>
      <a name="show" href="form.php?class_name=extn_social_login&<?php echo "mode=$mode"; ?>" class="show document_id extn_social_login_id">
       <i class="fa fa-refresh"></i></a> 
     </li>
     <li><?php $f->l_text_field_dm('provider_name'); ?></li>
     <li><?php $f->l_text_field_d('description'); ?></li>
     <li><?php $f->l_text_field_d('sl_key'); ?></li>
     <li><?php $f->l_text_field_d('slid'); ?></li>
     <li><?php $f->l_text_field_d('sl_secret'); ?></li>
     <li><?php $f->l_text_field_d('sl_scope'); ?></li>
     <li><?php $f->l_checkBox_field_d('enabled_cb'); ?> </li>
     <li><?php $f->l_number_field_d('display_weight'); ?> </li>
    </ul>
   </div>
  </form> 
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="extn_social_login" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="extn_social_login_id" ></li>
  <li class="form_header_id" data-form_header_id="extn_social_login" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="extn_social_login_id" ></li>
  <li class="btn1DivId" data-btn1DivId="extn_social_login_id" ></li>
 </ul>
</div>