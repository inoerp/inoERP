<div id="form_all">
 <div id ="form_header">
  <span class="heading"><?php echo gettext('Block Information') ?></span>
  <form method="post" id="block_header"  name="block_content_header">
   <!--create empty form or a single id when search is not clicked and the id is referred from other block_content -->
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Block Content') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Visibility') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field two_column_form">
       <li><?php $f->l_text_field_dr_withSearch('block_id') ?>
        <a name="show" href="form.php?class_name=block&<?php echo "mode=$mode"; ?>" class="show document_id block_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <?php echo $f->hidden_field_withId('block_content_id', $$class_second->block_content_id); ?>	
       <li><?php $f->l_text_field_dm('title'); ?> </li> 
       <li><?php $f->l_checkBox_field_d('show_title_cb'); ?> </li> 
       <li><?php $f->l_select_field_from_array('weight', dbObject::$position_array, $$class->weight); ?></li>
       <li><?php $f->l_select_field_from_array('position', block::$position_array, $$class->position); ?></li>
       <li><?php $f->l_checkBox_field_d('cached_cb'); ?> </li> 
       <li><?php $f->l_select_field_from_object('restrict_to_role', role_access::roles(), 'option_line_code', 'option_line_value', $block->restrict_to_role, 'role_code'); ?></li>
       <li><label><?php echo gettext('Reference Table') ?></label><?php
        $f->text_field_dr('reference_table');
        ?></li>
       <li><label><?php echo gettext('Block Name') ?></label>
        <?php
        $readonly_b = ($block->reference_table == 'block_content' || empty($$class->block_id)) ? false : true;
        echo $f->text_field('name', $block->name, '', '', '', '', $readonly_b);
        ?></li>
       <li><?php $f->l_checkBox_field_d('enabled_cb'); ?></li>
      </ul> 
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div class="first_rowset"> 
       <ul class="column two_column"> 
        <!--Start of  block content-->
        <?php if ($$class->reference_table == 'block_content') { ?>
         <li><label><?php echo gettext('Block Info') ?></label><?php form::text_field_d2('info'); ?> </li>
         <li><label>Block content contains PHP Code</label> <?php echo $f->checkBox_field('content_php_cb', $$class_second->content_php_cb); ?></li>
         <li><label><?php echo gettext('Block Content') ?></label>
          <textarea required name="content[]" class="noformat" rows="15" cols="160" placeholder=' '><?php echo $$class_second->content; ?></textarea>
         </li>
         </li>
         <?php
        }
        ?>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div class="first_rowset"> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_array('visibility_option', block::$visibility_option_array, $$class->visibility_option); ?></li>
        <li><div id="visibility"><label><?php echo gettext('Visibility') ?></label>
          <textarea name="visibility" class="noformat" rows="4" cols="80"><?php echo base64_decode($block->visibility); ?></textarea>
        </li>
       </ul>
      </div>
     </div>
    </div>
   </div>
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