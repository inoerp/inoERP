<?php $existing_address_arr = address_reference::find_by_reference_detailts('ino_user', $ino_user->ino_user_id); ?>
<div id ="form_header">
 <form  method="post" id="address"  name="address">
  <span class="heading"><?php $f = new inoform(); echo gettext('Address Header') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
			<ul class="column header_field">
			 <li><?php $f->l_select_field_from_object('existing_address', $existing_address_arr, 'address_id', 'address_name', '', 'existing_address','','','','','','address'); ?>    </li>
			 <li><?php $f->l_text_field('address_category', 'USER', '', 'address_category', 'always_readonly', 1, 1); ?>    </li>
			 <li><?php $f->l_select_field_from_object('type', address::address_types(), 'option_line_code', 'option_line_code', $address->type, 'type', '', '', $readonly); ?>    </li>
			 <li><?php $f->l_text_field_dm('address_name'); ?>    </li>
			 <li><?php $f->l_text_field_d('description'); ?>    </li>
			 <li><?php $f->l_status_field_d('status'); ?></li>
			 <li><?php $f->l_checkBox_field_d('default_cb'); ?></li>
			 <li><?php $f->l_select_field_from_object('usage_type', address::address_usage_type(), 'option_line_code', 'option_line_value', $address->usage_type, 'usage_type', '', '', $readonly); ?>    </li>
			 <?php
			 if ((!empty($_GET) && isset($_GET['window_type']) && $_GET['window_type'] == 'popup')) {
				echo $f->hidden_field_withId('window_type', 'popup');
				echo '<li><label></label><button  class="quick_select button btn btn-success">Select Address</button></li>';
			 }
			 ?>
			 <?php  ?>
			 <?php echo $f->hidden_field_withId('address_id', $$class->address_id); ?>
			 <?php echo $f->hidden_field_withId('address_user_id', $_SESSION['user_id']); ?>
			</ul>
     </div>
    </div>

   </div>
  </div>
  <span class="heading"><?php echo gettext('Address Details') ?></span>
  <div id ="form_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Address') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="column header_field address">
			 <li><?php $f->l_text_field_d('tax_region_name') ?> </li>
       <li><?php $f->l_text_field_d('phone'); ?></li>
       <li><?php $f->l_text_field_d('email'); ?></li>
       <li><?php $f->l_text_field_d('website'); ?></li>
       <li><?php $f->l_text_field_d('phone'); ?></li>
       <li><?php $f->l_text_field_d('country'); ?></li>
       <li><?php $f->l_text_field_d('postal_code'); ?></li>
       <li><label><?php echo gettext('Address') ?></label>  
					 <?php echo form::text_area('address', $address->address, '3', '22', '', 'Complete Address', 'address', $readonly); ?>
       </li>
      </ul>
     </div>
    </div>

   </div>
  </div>
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="address" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="address_id" ></li>
  <li class="form_header_id" data-form_header_id="address" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="address_id" ></li>
  <li class="btn1DivId" data-btn1DivId="address" ></li>
 </ul>
</div>