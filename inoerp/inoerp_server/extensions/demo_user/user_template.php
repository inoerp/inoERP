<div id ="form_header">
 <form action="" method="post" id="user_header" name="user_header">
  <span class="heading"><?php echo gettext('User Details') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Preference') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Employee') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Supplier') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Notes') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('user_id'); ?>
       <a name="show" href="form.php?class_name=user&<?php echo "mode=$mode"; ?>" class="show document_id user_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field('username', $$class->username, '', '', '', 1, $readonly1); ?></li>
      <li><label><?php echo gettext('Password') ?></label><input type="password" name="enteredPassword[]" value='' maxlength="50" id="enteredPassword" size="20" pattern="(?=^.{8,}$)((?=.*\d)|(?=.*\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$" >       </li>
      <li><label><?php echo gettext('Retype Password') ?></label><input type="password" name="enteredRePassword[]" value=''  maxlength="50" id="enteredRePassword" size="20" pattern="(?=^.{8,}$)((?=.*\d)|(?=.*\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$" >       </li>
      <li><?php $f->l_text_field_dm('first_name'); ?> </li>
      <li><?php $f->l_text_field_dm('last_name'); ?>	 </li>
      <li><?php $f->l_text_field_dm('email'); ?> </li>
      <li><?php $f->l_text_field_d('phone'); ?> </li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_object('user_language', user::all_languages(), 'option_line_code', 'description', $$class->user_language, 'user_language'); ?>  </li>
       <li><?php $f->l_select_field_from_array('block_notif_count', dbObject::$position_array, $$class->block_notif_count); ?>  </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_employee_id select_popup clickable">
         <?php echo gettext('Employee Name') ?></label><?php $f->text_field_d('employee_name'); ?>
        <?php echo $f->hidden_field_withId('hr_employee_id', $$class->hr_employee_id); ?>
       </li>
       <li><label><?php echo gettext('Identification') ?></label><?php $f->text_field_dr('identification_id'); ?>  </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_employee_id select_popup clickable">
         <?php echo gettext('Employee Name') ?></label><?php $f->text_field_d('employee_name'); ?>
        <?php echo $f->hidden_field_withId('hr_employee_id', $$class->hr_employee_id); ?>
       </li>
       <li><label><?php echo gettext('Identification') ?></label><?php $f->text_field_dr('identification_id'); ?>  </li>
       <li><?php $f->l_select_field_from_array('block_notif_count', dbObject::$position_array, $$class->block_notif_count); ?>  </li>
      </ul>
     </div>
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
        $reference_table = 'user';
        $reference_id = $$class->user_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
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
           echo ino_inline_action($form_line_array->user_role_id, array('user_id' => $$class->user_id));
           ?>
          </td>
          <td><?php echo form::text_field('user_role_id', $form_line_array->user_role_id, '8', '12', '', '', '', '1'); ?></td>
          <td><?php echo $f->select_field_from_object('role_code', role_access::roles(), 'option_line_code', 'option_line_value', $form_line_array->role_code, '', '', '', $readonly); ?> 					 </td>
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
            <li class="remove_row_img">No Access </li>
            <li><?php echo form::hidden_field('user_id', $$class->user_id); ?></li>
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
    <form action=""  method="post" id="user_group_line"  name="user_group_line">
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
          echo ino_inline_action($user_group->user_group_id, array('user_id' => $$class->user_id));
          ?>
         </td>
         <td><?php echo $f->text_field_ap(array('name' => 'user_group_id', 'value' => $user_group->user_group_id, 'readonly' => 1)); ?></td>
         <td><?php echo $f->select_field_from_object('user_group_code', user_group_access::user_groups(), 'option_line_code', 'option_line_value', $user_group->user_group_code, '', '', 1, $readonly); ?></td>
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
  <li class="headerClassName" data-headerClassName="user" ></li>
  <li class="lineClassName" data-lineClassName="user_role" ></li>
  <li class="lineClassName2" data-lineClassName2="user_group" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="user_id" ></li>
  <li class="form_header_id" data-form_header_id="user_header" ></li>
  <li class="line_key_field" data-line_key_field="user_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="user_role" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="user_id" ></li>
  <li class="docLineId" data-docLineId="user_role_id" ></li>
  <li class="btn1DivId" data-btn1DivId="user" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="user" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>