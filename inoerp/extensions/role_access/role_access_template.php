<div id ="form_header"><span class="heading">Role Details </span>
 <div class="large_shadow_box">
  <ul class="column four_column">
   <li><label> Select Role : </label>
    <?php echo $f->select_field_from_object('role_code', role_access::roles(), 'option_line_code', 'option_line_value', $role_code_h, 'role_code'); ?>
    <a name="show" href="form.php?class_name=role_access&<?php echo "mode=$mode"; ?>" class="show document_id role_access_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
   </li>						
   <li><label>Role Code : </label>
    <?php echo $f->text_field('role_code', $role_code_h, '', '', '', '', 1) ?>
   </li>
   <li><label>Description : </label>
    <?php echo $f->text_field('description', $role_code_description, '50', '', '', '', 1); ?>
   </li>
  </ul>
 </div>
</div>
<form action=""  method="post" id="role_access"  name="role_access">
 <!--END OF FORM HEADER-->
 <div id ="form_line" class="role_access"><span class="heading">Class & Access Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Class Access </a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th>Action</th>
        <th>Role Access Id</th>
        <th>Class/Object Name </th>
        <th>Access Level</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody role_access_values" >
       <?php
       $count = 0;
       foreach ($role_access_object as $role_access) {
        ?>         
        <tr class="role_access<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->role_access_id); ?>"></li>           
           <li><?php echo form::hidden_field('role_code', $role_code_h); ?></li>
          </ul>
         </td>
         <td><?php form::number_field_drs('role_access_id') ?></td>
         <td><?php echo $f->select_field_from_object('obj_class_name', engine::find_all(), 'obj_class_name', 'obj_class_name', $$class->obj_class_name, '', '', 1); ?></td>
         <td><?php echo $f->select_field_from_array('access_level', role_access::$access_map, $$class->access_level); ?></td>
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

<div id="pagination" style="clear: both;">
 <?php echo $pagination->show_pagination(); ?>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="role_access" ></li>
  <li class="line_key_field" data-line_key_field="obj_class_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="role_access" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="role_access_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="role_access" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>