<div id ="form_header">
 <form method="post" id="bc_static_label"  name="bc_static_label">
  <span class="heading"><?php echo gettext('Static Labels') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Notes') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Generate Label') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column one_column"> 
        <li><?php $f->l_text_field_dr_withSearch('bc_static_label_id') ?>
         <a name="show" href="form.php?class_name=bc_static_label&<?php echo "mode=$mode"; ?>" class="show document_id bc_static_label_id">
          <i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_select_field_from_object('sys_printer_id', sys_printer::find_all(), 'sys_printer_id', 'printer_name', $$class->sys_printer_id, 'sys_printer_id'); ?> 					</li>
        <li><?php $f->l_select_field_from_array('label_type', bc_static_label::$label_type_a, $$class->label_type); ?>              </li>
        <li><?php $f->l_select_field_from_object('bc_label_format_header_id', bc_label_format_header::find_all(), 'bc_label_format_header_id', 'format_name', $$class->bc_label_format_header_id, 'bc_label_format_header_id'); ?>              </li>
        <li><?php $f->l_text_field_d('status'); ?> 					</li>
        <li><label><?php echo gettext('No Of Copies') ?></label><?php echo $f->text_field_ap(array('name' => 'no_of_copies', 'value' => '', 'id' => 'no_of_copies')); ?> 					</li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'bc_static_label';
         $reference_id = $$class->bc_static_label_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div id="print_tab"> 
       <?php
       if (empty($$class->bc_static_label_id)) {
        echo "<br>No Label found. Save/Requery the form!";
       } else {
        echo $$class->print_label_inputParameters();
        echo '<span class=" btn btn-info active" id="print_static_label">Print</span>';
       }
       ?>
      </div>
     </div>
    </div>

   </div>
  </div>
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="bc_static_label" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="bc_static_label_id" ></li>
  <li class="form_header_id" data-form_header_id="bc_static_label" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bc_static_label_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bc_static_label_id" ></li>
 </ul>
</div>