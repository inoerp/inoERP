<?php
if (empty($access_level) || ($access_level < 2 )) {
 echo '<div><div id="structure">' . access_denied("You can only view & update your own user details") . '</div></div>';
 return;
}
?>
<div id ="form_header">
 <form method="post" id="user_header" name="user_header">
  <span class="heading"><?php echo gettext('User Details') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Preference') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Association') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Control') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-7"><?php echo gettext('Profile Picture') ?></a></li>
    <li><a href="#tabsHeader-8"><?php echo gettext('Addresses') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr('ino_user_id'); ?></li>
      <li><?php $f->l_text_field('username', $$class->username, '', '', '', 1, $readonly1); ?></li>
      <li><label><?php echo gettext('Password') ?></label><input type="password" name="enteredPassword[]" value='' maxlength="50" id="enteredPassword" size="20" pattern="(?=^.{8,}$)((?=.*\d)|(?=.*\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$" >       </li>
      <li><label><?php echo gettext('Retype Password') ?></label><input type="password" name="enteredRePassword[]" value=''  maxlength="50" id="enteredRePassword" size="20" pattern="(?=^.{8,}$)((?=.*\d)|(?=.*\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$" >       </li>
      <li><?php $f->l_text_field_dm('first_name'); ?> </li>
      <li><?php $f->l_text_field_dm('last_name'); ?>	 </li>
      <li><?php $f->l_text_field_dm('email'); ?> </li>
      <li><?php $f->l_text_field_d('phone'); ?> </li>
			<li><label><?php echo gettext('Notify User') ?></label><?php echo $f->checkBox_field('notify_user_cb', 1); ?> </li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_select_field_from_object('user_language', ino_user::all_languages(), 'option_line_code', 'description', $$class->user_language, 'user_language'); ?>  </li>
      <li><?php $f->l_select_field_from_object('default_theme', extn_theme::find_all_enabled_theme(), 'theme_name', 'theme_name', $$class->default_theme, 'default_theme'); ?>  </li>
      <li><?php $f->l_checkBox_field_d('use_personal_db_cb'); ?>  </li>
      <li><?php $f->l_checkBox_field_d('use_personal_color_cb'); ?>  </li>
      <li><?php $f->l_checkBox_field_d('show_bg_image_cb'); ?> </li>
			<li><?php $f->l_number_field_d('bg_opacity'); ?> </li> 
      <li><?php $f->l_color_field_d('mandatory_field_color'); ?> </li> 
      <li><?php $f->l_color_field_d('heading_color'); ?> </li> 
      <li><?php $f->l_color_field_d('content_color'); ?> </li> 


     </ul>
     <div class="bg-image-field"><label><?php echo gettext('Background Image'); ?></label><?php echo $f->image_field('bg_image_file_id', $$class->bg_image_file_id, '', '', 'img-vs'); ?></div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <ul class="column header_field">
      <li><?php
					echo $f->l_val_field_d('employee_name', 'hr_employee_v', 'employee_name', '', 'vf_select_employee_name employee_name');
					echo $f->hidden_field_withId('hr_employee_id', $$class->hr_employee_id);
					?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>

      <li><label><?php echo gettext('Supplier Name') ?></label><?php $f->text_field_d('supplier_name'); ?>
					<?php echo $f->hidden_field_withId('supplier_id', $$class->supplier_id); ?>
       <i class="fa fa-search supplier_id select_popup clickable"></i>
      </li>
      <li><label><?php echo gettext('Customer Name') ?></label><?php $f->text_field_d('customer_name'); ?>
					<?php echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id); ?>
       <i class="fa fa-search ar_customer_id select_popup clickable"></i>
      </li>

			<li><?php
					echo $f->l_val_field_d('first_name', 'lms_student', 'first_name', '', 'vf_select_lms_student first_name');
					echo $f->hidden_field_withId('lms_student_id', $$class->lms_student_id);
					?><i class="generic g_select_lms_student select_popup clickable fa fa-search" data-class_name="lms_student"></i></li>
     </ul>
    </div>
    <div id="tabsHeader-4" class="tabContent">
		 <ul class="column header_field">
			<li><?php $f->l_select_field_from_array('block_notif_count', dbObject::$position_array, $$class->block_notif_count); ?>  </li>
      <li><?php $f->l_select_field_from_array('debug_mode', ino_user::$debug_mode_a, $$class->debug_mode); ?>  </li>
			<li><label></label><a  href="form.php?class_name=extn_uprofile&mode=9&user_id=<?php echo $$class->ino_user_id; ?>" class="button btn btn-info"><?php echo gettext('User Profile') ?></a></li>
      <li><label></label><a  href="form.php?class_name=user_favourite&mode=9&user_id=<?php echo $$class->ino_user_id; ?>" class="button btn btn-info"> &nbsp; <i class="fa fa-edit"></i> <?php echo gettext('Favourite') ?></a></li>
     </ul>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
					 <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
					 <?php
					 $reference_table = 'ino_user';
					 $reference_id = $$class->ino_user_id;
					 ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-7" class="tabContent">
     <div class="image"> <?php
				 echo $f->image_field('image_file_id', $$class->image_file_id, '', '', 'img-medium');
				 ?> </div>
    </div>
    <div id="tabsHeader-8" class="tabContent">
     <div class="existing-address col-md-6">
      <label><?php echo gettext('Existing Addresses'); ?></label>
			<?php echo!empty($existing_address_arr) ? address_reference::show_address($existing_address_arr) : ''; ?>
     </div>
     <div class="new-address col-md-6"><label><?php echo gettext('Add New Address'); ?></label>
				 <?php
				 $existing_address_c = !empty($existing_address_arr) ? count($existing_address_arr) : 0;
				 echo $f->add_new_address();
				 ?>
     </div>
     <!--end of tab1 div three_column-->
    </div> 
   </div>
  </div>
 </form>
</div>

<span class="heading"><?php echo gettext('User Access Details') ?></span>
<div id="tabsLine">
 <ul class="tabMain">
  <li><a href="#tabsLine-1"><?php echo gettext('Role Control') ?></a></li>
  <li><a href="#tabsLine-2"><?php echo gettext('User Group Assignment') ?></a></li>
 </ul>
 <div class="tabContainer"> 
  <div id="tabsLine-1" class="tabContent">
   <div id ="form_line" class="form_line">
    <form action=""  method="post" id="user_role"  name="user_role">
     <table id="form_line_data_table" class="form">
      <thead>
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('User Role Access Id') ?>#</th>
        <th><?php echo gettext('Role Name') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody user_role_assignment_values">
					<?php
					$linecount = 0;
					if ($access_level >= 9) {
					 foreach ($user_role_object as $form_line_array) {
						?>
				 <tr class="user_role<?php echo $linecount; ?>">
					<td>
							<?php
							echo ino_inline_action($form_line_array->user_role_id, array('ino_user_id' => $$class->ino_user_id));
							?>
					</td>
					<td><?php echo form::text_field('user_role_id', $form_line_array->user_role_id, '8', '12', '', '', '', '1'); ?></td>
					<td><?php echo $f->select_field_from_object('role_code', option_header::find_options_byName('USER_ROLES'), 'option_line_code', 'option_line_value', $form_line_array->role_code, '', ' large', '', $readonly); ?> 					 </td>
				 </tr>
				 <?php
				 $linecount++;
				}
			 } else {
				foreach ($user_role_object as $form_line_array) {
				 ?>
				 <tr class="user_role<?php echo $linecount; ?>">
					<td>   
					 <ul class="inline_action">
						<li class="remove_row_img"><?php echo gettext('No Access') ?> </li>
						<li><?php echo form::hidden_field('ino_user_id', $$class->ino_user_id); ?></li>
					 </ul>
					</td>
					<td><?php echo $form_line_array->user_role_id; ?></td>
					<td><?php echo $form_line_array->role_code; ?>  </td>
				 </tr>
				 <?php
				 $linecount++;
				}
			 }
			 ?>
      </tbody>
     </table>


    </form> 
   </div>   
  </div> 

  <div id="tabsLine-2" class="tabContent">
   <div id ="form_line2" class="form_line2">
    <form   method="post" id="user_group_line"  name="user_group_line">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Group Access Id') ?>#</th>
        <th><?php echo gettext('Group Name') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody2 user_group_values" >
					<?php
					$count = 0;
					foreach ($user_group_object as $user_group) {
					 ?>         
 			 <tr class="user_group<?php echo $count ?>">
 				<td>
						 <?php
						 echo ino_inline_action($user_group->user_group_id, array('ino_user_id' => $$class->ino_user_id));
						 ?>
 				</td>
 				<td><?php echo $f->text_field_ap(array('name' => 'user_group_id', 'value' => $user_group->user_group_id, 'readonly' => 1)); ?></td>
 				<td><?php echo $f->select_field_from_object('user_group_code', option_header::find_options_byName('USER_GROUPS'), 'option_line_code', 'option_line_value', $user_group->user_group_code, '', 'large', '', $readonly); ?></td>
 			 </tr>
				<?php
				$count = $count + 1;
			 }
			 ?>
      </tbody>
     </table>
    </form>
   </div>
  </div>

 </div>

</div>



<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="ino_user" ></li>
  <li class="lineClassName" data-lineClassName="user_role" ></li>
  <li class="lineClassName2" data-lineClassName2="user_group" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="ino_user_id" ></li>
  <li class="form_header_id" data-form_header_id="user_header" ></li>
  <li class="line_key_field" data-line_key_field="ino_user_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="user_role" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ino_user_id" ></li>
  <li class="docLineId" data-docLineId="user_role_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ino_user" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="ino_user" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>
