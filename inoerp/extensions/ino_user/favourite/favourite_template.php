<div id ="form_header"><span class="heading"><?php echo gettext('User Favourite') ?></span>
 <div class="tabContainer">
  <ul class="column header_field">
   <li><label><?php echo gettext('User Name') ?></label><?php echo $f->text_field_ap(array('name' => 'username', 'value' => $user->username, 'readonly' => 1)); ?></li>
   <li><label><?php echo gettext('First Name') ?></label><?php echo $f->text_field_ap(array('name' => 'first_name', 'value' => $user->first_name, 'readonly' => 1)); ?></li>
   <li><label><?php echo gettext('Last Name') ?></label><?php echo $f->text_field_ap(array('name' => 'last_name', 'value' => $user->last_name, 'readonly' => 1)); ?></li>
  </ul>
 </div>
</div>
<form  method="post" id="user_favourite"  name="user_favourite">
 <!--END OF FORM HEADER-->
 <div id ="form_line" class="user_favourite"><span class="heading"><?php echo gettext('Favourite Links') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Details') ?> </a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Id') ?></th>
        <th><?php echo gettext('Path') ?></th>
        <th><?php echo gettext('External Link') ?></th>
        <th><?php echo gettext('Name') ?></th>
        <th><?php echo gettext('Group') ?></th>
        <th><?php echo gettext('Priority') ?></th>
        
       </tr>
      </thead>
      <tbody class="form_data_line_tbody user_favourite_values" >
       <?php
       $count = 0;
       foreach ($user_favourite_object as $user_favourite) {
        ?>         
        <tr class="user_favourite<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class->user_favourite_id, array('user_id' => $$class->user_id));
          ?>
         </td>
         <td><?php $f->text_field_widsr('user_favourite_id') ?></td>
         <td><?php echo $f->select_field_from_object('path_id', path::find_all(), 'path_id', array('module_code', 'name'), $$class->path_id, '', 'large', '', '', 1); ?></td>
         <td><?php $f->text_field_widlr('external_link') ?></td>
         <td><?php $f->text_field_widl('fav_name') ?></td>
         <td><?php echo $f->select_field_from_object('fav_group', user_favourite::favourite_group(), 'option_line_code', 'option_line_value', $$class->fav_group); ?></td>
         <td><?php echo $f->select_field_from_array('priority', dbObject::$position_array, $$class->priority, '', 'medium'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </div>

  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="user_favourite" ></li>
  <li class="line_key_field" data-line_key_field="fav_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="user_favourite" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="user_favourite_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="user_favourite" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>