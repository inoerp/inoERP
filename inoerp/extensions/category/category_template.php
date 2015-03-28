<div id ="form_header"><?php $f = new inoform() ?>
 <span class="heading"><?php echo gettext('Category Header') ?></span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   <li><a href="#tabsHeader-2"><?php echo gettext('Images') ?></a></li>
  </ul>
  <div class="tabContainer">
   <form action=""  method="post" id="category"  name="category">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('category_id'); ?>
       <a name="show" href="form.php?class_name=category&<?php echo "mode=$mode"; ?>" class="show document_id category_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_checkBox_field_d('primary_cb'); ?></li>
      <li><label><?php echo gettext('Parent Name') ?></label><?php
       $cat = new category();
       echo $cat->all_child_category_select_option('parent_id', '', $$class->parent_id, 'parent_id', false)
       ?> 
      </li>
      <li><?php $f->l_text_field_dm('category'); ?></li>
      <li><?php $f->l_select_field_from_array('content_relation', category::$content_relation_a, $$class->content_relation); ?></li>
      <li><?php $f->l_select_field_from_object('category_type', category::category_types(), 'option_line_code', 'option_line_value', $$class->category_type, 'category_type'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> <?php echo extn_image::ino_images($class, $$class->category_id) ?> </div>
    </div>
   </form>		
  </div>
 </div>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="category" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="category_id" ></li>
  <li class="form_header_id" data-form_header_id="category" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="category_id" ></li>
  <li class="btn1DivId" data-btn1DivId="category_id" ></li>
 </ul>
</div>