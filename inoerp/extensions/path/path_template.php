<div id="structure">
 <div id="path_divId">
 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
 <!--    End of place for showing error messages-->
 <div id ="form_single">
  <form action="path.php" method="post" size="30" id="path" name="path"  >
   <div > 
    <ul class="two_column"> 
     <li><label><img src="<?php echo HOME_URL; ?>themes/default/images/serach.png" class="path_id select_popup clickable">
       Path Id :</label><?php $f->text_field_ds('path_id') ?>
      <a name="show" href="form.php?class_name=path" class="show path_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
     </li>
     <li><label>Parent Name :</label> 
      <?php echo $f->select_field_from_object('parent_id', path::find_all('name'), 'path_id', array('name', 'module_code'), $$class->parent_id, 'parent_id') ?>
     </li>
     <li><label>Path Value :</label>  
      <input type="text" required name="path_link[]" maxlength="500" id="path_link" size="60" 
             placeholder="Enter path relative to site home" value="<?php echo htmlentities($path->path_link); ?>">
      <!--validation message place for username-->
     </li>
     <li><label>Path Name :</label> 
      <input type="text" required name="name[]" id="name" maxlength="60" size="60"
             placeholder="Enter a valid path name" value="<?php echo htmlentities($path->name); ?>">
     </li>
     <li><label>Description  : </label> 
      <input type="text" required name="description[]" maxlength="100" id="description" size="60" 
             placeholder="Enter path descrip. Limit 100 characters" value="<?php echo htmlentities($path->description); ?>">
     </li>
     <li><label>Class/Obj Name  : </label> <?php $f->text_field_d('obj_class_name') ?></li>
     <li><label>Mode  : </label> <?php $f->text_field_ds('mode') ?></li>
     <li><label>Module : </label>
      <?php echo $f->select_field_from_object('module_code', option_header::modules(), 'option_line_code', 'option_line_value', $$class->module_code, 'module_code', '', 1) ?>
     </li>
     <li><label>ID Column name : </label>
      <Select name="id_column_name[]" id="id_column_name"> 
       <option value="" ></option>   
       <?php
       $coumn_name = view::find_all_idColumns_gen();
       foreach ($coumn_name as $key => $value) {
        echo '<option value="' . $value . '" ';
        echo $value == $path->id_column_name ? 'selected' : 'none ';
        echo '>' . $value . '</option>';
       }
       ?> 

      </select>
     </li>
     <li> <label>Path Type: </label>
      <?php echo $f->select_field_from_object('path_type', path::path_types(), 'option_line_code', 'option_line_value', $$class->path_type, 'path_type') ?></li>
     <li> <label>Search Path ? : </label><?php $f->checkBox_field_d('search_path_cb'); ?> </li>
     <li> <label>Display Weight: </label><?php echo $f->number_field('display_weight', $$class->display_weight); ?> </li>
    </ul>
   </div>
  </form> 
 </div>
</div>
</div>
