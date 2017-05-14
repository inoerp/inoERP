	<?php
	if (!empty($_GET['ref_class_name']) && ($_GET['ref_class_name'] == 'ec_confirm_order')) {
	 $show_id = false;
	 $$class->address_name = current_time(1) . ' - ' . $_SESSION['user_id'];
	 include_once __DIR__.'/templates/ec_confirm_order_template.php';
	 return;
	}
	if(empty($$class->address_category)){
	 $$class->address_category = 'GEN';
	}
	?>

<div id ="form_headerDiv">
 <form  method="post" id="address"  name="address">
  <span class="heading"><?php echo gettext('Address Header') ?></span>
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
					<?php if ($show_id) { ?>
 			 <li><?php $f->l_text_field_dr_withSearch('address_id'); ?>
 				<a name="show2" href="form.php?class_name=address&<?php echo "mode=$mode"; ?>" class="show2 address_id document_id">
 				 <i class="fa fa-refresh"></i></a> 
 			 </li>			 
			 <?php } ?>
			 <li><?php $f->l_select_field_from_object('type', address::address_types(), 'option_line_code', 'option_line_code', $address->type, 'type', '', '', $readonly); ?>    </li>
			 <li><?php $f->l_select_field_from_array('address_category', address::$address_category_a, $$class->address_category, 'address_category', 'always_Readonly'); ?>    </li>
			 <li><?php $f->l_text_field_dm('address_name'); ?>    </li>
			 <li><label><?php echo gettext('Tax Region') ?></label><?php $f->text_field_d('tax_region_name') ?>
        <i class="fa fa-search tax_region_id select_popup clickable"></i></li>
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
						$reference_table = 'address';
						$reference_id = $$class->address_id;
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
  <span class="heading"><?php echo gettext('Address Details') ?></span>
  <div id ="form_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Address') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <ul class="column header_field address">
       <li><?php $f->l_text_field_d('phone'); ?></li>
       <li><?php $f->l_text_field_d('email'); ?></li>
       <li><?php $f->l_text_field_d('website'); ?></li>
       
       <li><?php $f->l_text_field_d('country'); ?></li>
       <li><?php $f->l_text_field_d('postal_code'); ?></li>
			 <li></li>
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