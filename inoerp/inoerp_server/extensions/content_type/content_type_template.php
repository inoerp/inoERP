<span class="heading"><?php echo gettext('Content Type') ?></span>
<form action=""  method="post" id="content_type_header"  name="content_type_header" class="content_type_header">
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Comments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Categories') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer" >
    <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li class="content_type_id"><?php $f->l_text_field_dr_withSearch('content_type_id'); ?>
        <a name="show" href="form.php?class_name=content_type&<?php echo "mode=$mode"; ?>" class="show document_id content_type_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li class="content_type_label"><?php $f->l_text_field_dm('content_type'); ?></li>
       <li class="description"><?php $f->l_text_field_d('description'); ?></li>
       <li class="has_subject_vb"><?php $f->l_checkBox_field_d('has_subject_cb'); ?></li>
       <li class="subject_label"><?php $f->l_text_field_d('subject_label'); ?></li>
       <li class="allow_file_cb"><?php $f->l_checkBox_field_d('allow_file_cb'); ?></li>
       <li class="role"><?php $f->l_select_field_from_object('read_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->read_role, 'read_role'); ?></li>
       <li class="role"><?php $f->l_select_field_from_object('write_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->write_role, 'write_role'); ?></li>
       <li class="role"><?php $f->l_select_field_from_object('update_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->update_role, 'update_role'); ?></li>
       <li class="allow_file_cb"><?php $f->l_checkBox_field_d('auto_url_alias_cb'); ?></li>
      </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div > 
      <ul class="column header_field">
       <li class="allow_comment_cb"><?php $f->l_checkBox_field_d('allow_comment_cb'); ?></li>
       <li class="role"><?php $f->l_select_field_from_object('comment_read_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->comment_read_role, 'comment_read_role'); ?></li>
       <li class="role"><?php $f->l_select_field_from_object('comment_write_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->comment_write_role, 'comment_write_role'); ?></li>
       <li class="role"><?php $f->l_select_field_from_object('comment_update_role', role_access::roles(), 'option_line_code', 'option_line_value', $$class->comment_update_role, 'comment_update_role'); ?></li>
       <li class="subject_label"><?php $f->l_select_field_from_array('comment_order_by', content_type::$comment_order_by_a, $$class->comment_order_by); ?></li>
       <li class="allow_file_cb"><?php $f->l_select_field_from_array('comments_perpage', select_per_page_array(), $$class->comments_perpage); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li class="show_category_onsummary_cb"><?php $f->l_checkBox_field_d('show_category_onsummary_cb'); ?></li>
       <?php
       if ((isset($category)) && (count($category) > 0)) {
        foreach ($category as $obj) {
         echo '<li><label><span class="clickable delete_category" title="' . gettext('Delete Category') . '"><i class="fa fa-trash-o"></i></span></label>';
         echo $f->select_field_from_object('category_id', category::major_categories(), 'category_id', 'category', $obj->category_id, '', 'category_id', '', 1);
         echo '</li>';
        }
       }
       echo '<li><label>' . gettext('Category') . ' : </label>';
       echo $f->select_field_from_object('category_id', category::major_categories(), 'category_id', 'category', 'category_id', '', '', 'category_id');
       echo '</li>';
       ?> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><input type="button" class="button drop_table btn btn-danger" role="button" name="drop_table" id="drop_table" value="<?php echo gettext('Delete Content Type') ?>"></li>
      </ul>
     </div>
    </div>
   </div>
  </div>
 </div>
 <span class="heading"><?php echo gettext('Content Type Fields/Columns') ?></span>
 <div id="form_line" class="form_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Future') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Field Label') ?></th>
        <th><?php echo gettext('Position') ?>#</th>
        <th><?php echo gettext('Required') ?></th>
        <th><?php echo gettext('Field Name') ?></th>
        <th><?php echo gettext('Field Type') ?></th>
        <th><?php echo gettext('Number') ?></th>
        <th><?php echo gettext('enum Values') ?></th>
        <th><?php echo gettext('Option List') ?></th>
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
          echo ino_inline_action($$class_second->field, array('content_type_reference_id' => $content_type_reference_id));
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
