<div id="form_all">
 <div id ="form_header">
  <form action=""  method="post" id="block_header"  name="block_content_header">
   <!--create empty form or a single id when search is not clicked and the id is referred from other block_content -->
   <?php
   echo $f->hidden_field_withId('block_id', $$class->block_id);
   ?>	
   <?php echo $f->hidden_field_withId('block_content_id', $$class_second->block_content_id); ?>	
   <table>
    <tr>
     <td><label>Block Title : </label>
      <input type="text"  name="title" value="<?php echo htmlentities($$class->title); ?>" 
             size="40"  maxlength="250" class="subject" placeholder="title of the block"> 
     </td>
     <td><label>Show Title : </label><?php echo form::checkBox_field('show_title_cb', $$class->show_title_cb); ?></td>
    </tr>
    <tr>
     <td><label>Weight : </label>
      <?php echo form::select_field_from_array('weight', dbObject::$position_array, $$class->weight); ?></td>
     <td><label>Position : </label>
      <?php echo form::select_field_from_array('position', block::$position_array, $$class->position); ?></td>
    </tr>
    <tr>
     <td><label>Cache Content : </label><?php echo $f->checkBox_field('cached_cb', $block->cached_cb); ?></td>
     <td><label>Restrict to Role : </label>
      <?php echo $f->select_field_from_object('restrict_to_role', role_access::roles(), 'option_line_code', 'option_line_value', $block->restrict_to_role, 'role_code'); ?></td>
    </tr>
    <tr>
     <td><label>Reference Table : </label><?php echo $f->text_field_ap(array('name' => 'reference_table', 'value' => $$class->reference_table,
       'readonly' => $readonly_id));
      ?></td>
     <td><label>Block Name: </label>
      <?php $readonly_b = ($block->reference_table == 'block_content' || empty($$class->block_id)) ? false : true;
      echo $f->text_field('name', $block->name, '', '', '', '', $readonly_b);
      ?></td>
    </tr>
    <!--Start of  block content-->
<?php if ($$class->reference_table == 'block_content') { ?>
     <tr><td colspan="2"><label>Block Content : </label>
       <textarea required name="content[]" class="noformat" rows="8" cols="80" placeholder=' '><?php echo $$class_second->content; ?></textarea>
      </td></tr>
     <tr> <td>	<label>Block Info : </label><?php form::text_field_d2('info'); ?> </td>
      <td><label>Block content contains PHP Code : </label> <?php echo $f->checkBox_field('content_php_cb', $$class_second->content_php_cb); ?></td>
     </tr>
     <?php
    }
    ?>
    <!--End of  block content-->
    <tr>
     <td><label>Enabled : </label><?php echo form::checkBox_field('enabled_cb', $$class->enabled_cb); ?></td>
     <td><label> Visibility Option : </label>
<?php echo form::select_field_from_array('visibility_option', block::$visibility_option_array, $$class->visibility_option); ?></td>
    </tr>
    <tr>
     <td colspan="2">
      <div id="visibility"><label> Visibility : </label>
       <textarea name="visibility" class="noformat" rows="4" cols="80"><?php echo base64_decode($block->visibility); ?></textarea>
      </div>
     </td>
    </tr>
   </table>
  </form>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="block" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="block_id" ></li>
  <li class="form_header_id" data-form_header_id="block_header" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="block_id" ></li>
  <li class="btn1DivId" data-btn1DivId="block_id" ></li>
 </ul>
</div>