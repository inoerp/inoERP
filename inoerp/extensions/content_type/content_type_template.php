<span class="heading">Content Type </span>
<form action=""  method="post" id="content_type_header"  name="content_type_header" class="content_type_header">
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Comments</a></li>
    <li><a href="#tabsHeader-3">Categories</a></li>
    <li><a href="#tabsHeader-4">Actions</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li class="content_type_id">
        <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="content_type_id select_popup clickable">
         Type ID</label><?php form::number_field_drs('content_type_id'); ?>
        <a name="show" href="form.php?class_name=content_type&<?php echo "mode=$mode"; ?>" class="show document_id content_type_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li class="content_type_label"><label>Content Type</label><?php form::text_field_dm('content_type'); ?></li>
       <li class="description"><label>Description</label><?php form::text_field_dm('description'); ?></li>
       <li class="has_subject_vb"> <label>Allow Subject</label><?php echo form::checkBox_field('has_subject_cb', $$class->has_subject_cb); ?></li>
       <li class="subject_label"><label>Subject Label</label><?php form::text_field_d('subject_label'); ?></li>
       <li class="allow_file_cb"> <label>Allow Attachment</label><?php echo form::checkBox_field('allow_file_cb', $$class->allow_file_cb); ?></li>
       <li class="role"><label>Read Role</label><?php echo $f->select_field_from_object('read_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->read_role, 'read_role'); ?></li>
       <li class="role"><label>Write Role</label><?php echo $f->select_field_from_object('write_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->write_role, 'write_role'); ?></li>
       <li class="role"> <label>Update Role</label><?php echo $f->select_field_from_object('update_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->update_role, 'update_role'); ?></li>
       <li class="allow_file_cb"> <label>Auto URL Alias</label><?php echo form::checkBox_field('auto_url_alias_cb', $$class->auto_url_alias_cb); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div > 
      <ul class="column header_field">
       <li class="allow_comment_cb"><label>Enable Comments ?</label><?php echo form::checkBox_field('allow_comment_cb', $$class->allow_comment_cb); ?></li>
       <li class="role"><label>Read Role</label><?php echo $f->select_field_from_object('comment_read_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->comment_read_role, 'comment_read_role'); ?></li>
       <li class="role"><label>Write Role</label><?php echo $f->select_field_from_object('comment_write_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->comment_write_role, 'comment_write_role'); ?></li>
       <li class="role"> <label>Update Role</label><?php echo $f->select_field_from_object('comment_update_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->comment_update_role, 'comment_update_role'); ?></li>
       <li class="subject_label"><label>Comment Listing</label><?php echo $f->select_field_from_array('comment_order_by', content_type::$comment_order_by_a, $$class->comment_order_by); ?></li>
       <li class="allow_file_cb"><label>Comments Per Page</label><?php echo $f->select_field_from_array('comments_perpage', select_per_page_array(), $$class->comments_perpage); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <ul class="column five_column">
       <li class="show_category_onsummary_cb"> <label>Show Category on Summary List Page? : </label>    
        <?php echo form::checkBox_field('show_category_onsummary_cb', $$class->show_category_onsummary_cb); ?></li>

       <?php
       if ((isset($category)) && (count($category) > 0)) {
        foreach ($category as $obj) {
         echo '<li><label><span class="clickable delete_category" title="Delete Category"><i class="fa fa-trash-o"></i></span></label>';
         echo $f->select_field_from_object('category_id', category::major_categories(), 'category_id', 'category', $obj->category_id, '', 'category_id', '', 1);
         echo '</li>';
        }
       }
       echo '<li><label>Category : </label>';
       echo $f->select_field_from_object('category_id', category::major_categories(), 'category_id', 'category', 'category_id', '', '', 'category_id');
       echo '</li>';
       ?> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> 
      <ul class="column four_column">
       <li><input type="button" class="button drop_table" name="drop_table" id="drop_table" value="Delete Content Type"></li>
      </ul>
     </div>
    </div>
   </div>
  </div>
 </div>
 <span class="heading">Content Type Fields/Columns </span>
 <div id="form_line" class="form_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Main</a></li>
    <li><a href="#tabsLine-2">Future</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
       <tr>
        <th>Action</th>
        <th>Field Label</th>
        <th>Position</th>
        <th>Required</th>
        <th>Field Name</th>
        <th>Field Type</th>
        <th>Number</th>
        <th>enum Values</th>
        <th>Option List</th>
       </tr>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody field_values_list">
       <?php
       $count = 0;
       foreach ($new_content_type_object as $new_content_type) {
        $content_type_reference = content_type_reference::find_by_contentTypeId_fieldName($$class->content_type_id, $$class_second->field_name);
        if (($content_type_reference) == false) {
         $content_type_reference = new content_type_reference;
        }
        $class_third = 'content_type_reference';
        $$class_third = &$content_type_reference;
        ?>   
        <tr class="content_type<?php echo $count ?>">
         <td>
          <?php
          $content_type_reference_id = !empty($content_type_reference) ? $$class_third->content_type_reference_id : '';
          echo ino_inline_action($$class_second->Field, array('content_type_reference_id' => $content_type_reference_id));
          ?>
         </td>
         <td><?php form::text_field_wid3('field_label') ?></td>
         <td><?php echo form::select_field_from_array('field_position', dbObject::$position_array, $$class_third->field_position); ?></td>
         <td><?php echo form::checkBox_field('required_cb', $$class_third->required_cb); ?></td>
         <td><?php
          !empty($$class_second->field_name) ? $fielNamereadonly = 1 : $fielNamereadonly = '';
          echo form::text_field('field_name', $$class_second->field_name, 20, 50, 1, 'use small letters', '', $fielNamereadonly, 'field_name')
          ?></td>
         <td>
          <?php echo $f->select_field_from_object('field_type', content_type::content_field_type(), 'option_line_code', 'option_line_value', $$class_second->field_type, '', '', 1, $readonly, 'field_type', '') ?>
         </td>
         <td><?php form::number_field_wid2s('field_num'); ?></td>    
         <td><?php form::text_field_wid2('field_enum'); ?></td>  
         <td><?php echo $f->select_field_from_object('option_type', option_header::find_all(), 'option_header_id', 'option_type', $$class_third->option_type, '', 'medium') ?></td>  
        </tr>
        <?php
        $count++;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="scrollElement tabContent">
    </div>
   </div>
  </div>
 </div>
</form>   

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="content_type" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="content_type_id" ></li>
  <li class="form_header_id" data-form_header_id="content_type_header" ></li>
  <li class="lineClassName" data-lineClassName="content_type" ></li>
  <li class="no_headerid_check" data-no_headerid_check="9" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="content_type_id" ></li>
  <li class="btn1DivId" data-btn1DivId="content_type_id" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>

 </ul>
</div>