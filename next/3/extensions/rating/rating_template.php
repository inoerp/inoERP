<div id ="form_header">
 <span class="heading"><?php echo gettext('Rating Values Header') ?></span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
  </ul>
  <div class="tabContainer">
   <form action=""  method="post" id="extn_rating_values"  name="extn_rating_values">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('extn_rating_values_id'); ?>
       <a name="show" href="form.php?class_name=extn_rating_values&<?php echo "mode=$mode"; ?>" class="show document_id extn_rating_values_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_dm('reference_table'); ?></li>
      <li><?php $f->l_text_field_dm('reference_id'); ?></li>
      <li><?php $f->l_text_field_dm('rating'); ?></li>
      <li><?php $f->l_text_field_dm('vote_time'); ?></li>
      <li><?php $f->l_text_field_d('ip_address'); ?></li>
      <li><?php $f->l_text_field_d('created_by'); ?></li>
     </ul>
    </div>
   </form>		
  </div>
 </div>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="extn_rating_values" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="extn_rating_values_id" ></li>
  <li class="form_header_id" data-form_header_id="extn_rating_values" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="extn_rating_values_id" ></li>
  <li class="btn1DivId" data-btn1DivId="extn_rating_values_id" ></li>
 </ul>
</div>